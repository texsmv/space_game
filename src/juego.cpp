#include "juego.h"

juego::juego()
{
    vector<sf::Texture*> *nave_prueba=new vector<sf::Texture*>;
}

juego::~juego()
{
    //dtor
}

float distancia(sf::Vector2f a, sf::Vector2f b){
    float dist=sqrt(pow((b.x-a.x),2)+pow((b.y-a.y),2));
    return dist;
}


int numero_aleatorio2(sf::Clock*reloj ,int m, int n){
        int num= m + int (reloj->getElapsedTime().asMicroseconds())%(n+1) ;

        return num;
}



bool calc_probabilidad(int prob,int total,sf::Clock* reloj){
    int temp=numero_aleatorio2(reloj,0,total);
    if(temp<prob){
        return true;
    }
    return false;
}

juego::juego(sf::RenderWindow * win,sf::Event*evento){
    this->win=win;
    this->reloj= new sf::Clock;
    this->evento=evento;
    this->objetos=new vector<objeto*>;
    this->enemigos=new vector<objeto*>;
    this->proyectiles=new vector<objeto*>;
    this->texturas_animaciones=new map<string,vector<sf::Texture*>*>;
    this->texturas=new map<string,sf::Texture*>;

    //--------------------------nave_creacion
    string dir_1="img/nave_principal/movimiento/";
    vector<string> nave_principal={"1.png","2.png","3.png","4.png","5.png","6.png","7.png","8.png"};
    crear_direcciones(nave_principal,dir_1);
    (*texturas_animaciones)["nave_principal"]=generar_texturas(nave_principal);
    nave_jugador= new nave((*texturas_animaciones)["nave_principal"],sf::Vector2f(100,100),this->reloj,this->evento,this->proyectiles,this->texturas_animaciones,this->texturas,this->enemigos);

    //--------------------------asteroides pequeños----------------
    string dir_ast_peq_1="img/asteroides/small/1/";
    vector<string> ast_peq_1={"a10000.png","a10001.png","a10002.png","a10003.png","a10004.png","a10005.png","a10006.png","a10007.png","a10008.png",
                            "a10009.png","a10010.png","a10011.png","a10012.png","a10013.png","a10014.png","a10015.png"
                            };
    crear_direcciones(ast_peq_1,dir_ast_peq_1);
    (*texturas_animaciones)["asteroides pequeños 1"]=generar_texturas(ast_peq_1);


    string dir_ast_peq_2="img/asteroides/small/2/";
    vector<string> ast_peq_2={"a30000.png","a30001.png","a30002.png","a30003.png","a30004.png","a30005.png","a30006.png","a30007.png","a30008.png",
                            "a30009.png","a30010.png","a30011.png","a30012.png","a30013.png","a30014.png","a30015.png"
                            };
    crear_direcciones(ast_peq_2,dir_ast_peq_2);
    (*texturas_animaciones)["asteroides pequeños 2"]=generar_texturas(ast_peq_2);


    string dir_ast_peq_3="img/asteroides/small/3/";
    vector<string> ast_peq_3={"a40000.png","a40001.png","a40002.png","a40003.png","a40004.png","a40005.png","a40006.png","a40007.png","a40008.png",
                            "a40009.png","a40010.png","a40011.png","a40012.png","a40013.png","a40014.png","a40015.png"
                            };
    crear_direcciones(ast_peq_3,dir_ast_peq_3);
    (*texturas_animaciones)["asteroides pequeños 3"]=generar_texturas(ast_peq_3);


    //--------------------------asteroides medianos----------------
    string dir_ast_med_1="img/asteroides/medium/1/";
    vector<string> ast_med_1={"a10000.png","a10001.png","a10002.png","a10003.png","a10004.png","a10005.png","a10006.png","a10007.png","a10008.png",
                            "a10009.png","a10010.png","a10011.png","a10012.png","a10013.png","a10014.png","a10015.png"
                            };
    crear_direcciones(ast_med_1,dir_ast_med_1);
    (*texturas_animaciones)["asteroides medianos 1"]=generar_texturas(ast_med_1);


    string dir_ast_med_2="img/asteroides/medium/2/";
    vector<string> ast_med_2={"a30000.png","a30001.png","a30002.png","a30003.png","a30004.png","a30005.png","a30006.png","a30007.png","a30008.png",
                            "a30009.png","a30010.png","a30011.png","a30012.png","a30013.png","a30014.png","a30015.png"
                            };
    crear_direcciones(ast_med_2,dir_ast_med_2);
    (*texturas_animaciones)["asteroides medianos 2"]=generar_texturas(ast_med_2);


    string dir_ast_med_3="img/asteroides/medium/3/";
    vector<string> ast_med_3={"a40000.png","a40001.png","a40002.png","a40003.png","a40004.png","a40005.png","a40006.png","a40007.png","a40008.png",
                            "a40009.png","a40010.png","a40011.png","a40012.png","a40013.png","a40014.png","a40015.png"
                            };
    crear_direcciones(ast_med_3,dir_ast_med_3);
    (*texturas_animaciones)["asteroides medianos 3"]=generar_texturas(ast_med_3);




//--------------------------asteroides grandes----------------
    string dir_ast_gra_1="img/asteroides/large/1/";
    vector<string> ast_gra_1={"a10000.png","a10001.png","a10002.png","a10003.png","a10004.png","a10005.png","a10006.png","a10007.png","a10008.png",
                            "a10009.png","a10010.png","a10011.png","a10012.png","a10013.png","a10014.png","a10015.png"
                            };
    crear_direcciones(ast_gra_1,dir_ast_gra_1);
    (*texturas_animaciones)["asteroides grandes 1"]=generar_texturas(ast_gra_1);

    string dir_ast_gra_2="img/asteroides/large/2/";
    vector<string> ast_gra_2={"a30000.png","a30001.png","a30002.png","a30003.png","a30004.png","a30005.png","a30006.png","a30007.png","a30008.png",
                            "a30009.png","a30010.png","a30011.png","a30012.png","a30013.png","a30014.png","a30015.png"
                            };
    crear_direcciones(ast_gra_2,dir_ast_gra_2);
    (*texturas_animaciones)["asteroides grandes 2"]=generar_texturas(ast_gra_2);


    string dir_ast_gra_3="img/asteroides/large/7/";
    vector<string> ast_gra_3={"c40000.png","c40001.png","c40002.png","c40003.png","c40004.png","c40005.png","c40006.png","c40007.png","c40008.png",
                            "c40009.png","c40010.png","c40011.png","c40012.png","c40013.png","c40014.png","c40015.png"
                            };
    crear_direcciones(ast_gra_3,dir_ast_gra_3);
    (*texturas_animaciones)["asteroides grandes 3"]=generar_texturas(ast_gra_3);


    //---------------------------   --bala roja---------------------
    sf::Texture * textura_bala_roja= new sf::Texture;
    textura_bala_roja->loadFromFile("img/proyectiles/estaticos/bullet.png");
    (*texturas)["bala roja"]=textura_bala_roja;

    //---------------------------bala azul------------------------
    sf::Texture * textura_bala_azul= new sf::Texture;
    textura_bala_azul->loadFromFile("img/proyectiles/estaticos/bala_azul.png");
    (*texturas)["bala azul"]=textura_bala_azul;

    //-----------------------------estacion--------------------
    sf::Texture * textura_estacion= new sf::Texture;
    textura_estacion->loadFromFile("img/proyectiles/estaticos/station.png");
    (*texturas)["estacion"]=textura_estacion;

    //----------------------------bala electrica---------------------

    string dir_bal_elec="img/proyectiles/bala_electrica/";
    vector<string> bal_elec={"ball_0.png","ball_1.png","ball_2.png","ball_3.png"
                            };
    crear_direcciones(bal_elec,dir_bal_elec);
    (*texturas_animaciones)["bala electrica"]=generar_texturas(bal_elec);

}

//-----------------control----------------------

void juego::dibujar_objetos(){
    this->win->draw(*nave_jugador);
    for (auto it : *this->objetos){
        this->win->draw(*it);
    }

    for (auto it : *this->enemigos){
        this->win->draw(*it);
    }

    for (auto it : *this->proyectiles){
        this->win->draw(*it);
    }
}

void juego::crear_asteroides(){
    int tiempo_pasado=this->reloj->getElapsedTime().asSeconds()/3;

    if(calc_probabilidad(this->probabilidad_inicial+tiempo_pasado,this->probabilidad_total,this->reloj)==true){
        objeto * ast= new asteroide(this->texturas_animaciones,this->texturas,this->reloj,this->evento);
        this->enemigos->push_back(ast);

    }

}

void juego::destruir_objetos(){
    for(int i=0;i<this->proyectiles->size();i++){
        if (proyectiles->at(i)->destruir==true){
            delete this->proyectiles->at(i);
            this->proyectiles->erase(proyectiles->begin()+i);
            break;
        }
    }

    for(int i=0;i<this->enemigos->size();i++){
        if (enemigos->at(i)->destruir==true){
            delete this->enemigos->at(i);
            this->enemigos->erase(enemigos->begin()+i);
            break;
        }
    }

}

void juego::verif_colisiones(){
    for(auto it : *this->proyectiles){
        for(auto ite : *this->enemigos){

            if(ite->radio >= (distancia(sf::Vector2f(it->coordenadas.x,it->coordenadas.y+it->radio),ite->coordenadas))) {
                ite->vida-=it->damage;
                it->vida-=1;
                break;
            }

            else if(ite->radio >= (distancia(sf::Vector2f(it->coordenadas.x,it->coordenadas.y-it->radio),ite->coordenadas))) {
                ite->vida-=it->damage;
                it->vida-=1;
                break;
            }
            else if(ite->radio >= (distancia(sf::Vector2f(it->coordenadas.x,it->coordenadas.y),ite->coordenadas))) {
                ite->vida-=it->damage;
                it->vida-=1;
                break;
            }

        }
    }

}

void juego::verif_nave(){
    for(auto it:*this->enemigos){
        if(distancia(this->nave_jugador->getPosition(),it->getPosition())<=30){
            this->nave_jugador->vida-=1;
            it->destruir=true;
        }
    }

    if(this->nave_jugador->vida<=0){
        this->win->close();
    }
}

void juego::update_objetos(){
    this->nave_jugador->update();
    for (auto it : *this->objetos){
        it->set_evento(this->evento);
        it->update();
    }

    for (auto it : *this->enemigos){
        it->set_evento(this->evento);
        it->update();
    }

    for (auto it : *this->proyectiles){
        it->update();
    }
}

//-----------------procesos----------------

vector<sf::Texture*>* juego::generar_texturas(vector<string> direcciones){
    vector<sf::Texture*>* texturas=new vector<sf::Texture*>;
    for(auto it:direcciones){
        sf::Texture * temp= new sf::Texture;
        temp->loadFromFile(it);
        texturas->push_back(temp);


    }
    return texturas;
}

void juego::crear_direcciones(vector<string>& v, string dir){
    for_each(v.begin(),v.end(),[dir](string& str){
        str=dir+str;
    });
}

void juego::set_evento(sf::Event* evento){
    this->evento=evento;
}

void juego::update(){

    this->limpiar();
    this->crear_asteroides();
    this->update_objetos();
    this->destruir_objetos();
    this->verif_colisiones();
    this->verif_nave();
    this->dibujar_objetos();
    this->mostrar();
}
