#include "asteroide.h"

asteroide::asteroide()
{
    //ctor
}

asteroide::~asteroide()
{
    //dtor
}

int numero_aleatorio(sf::Clock*reloj ,int m, int n){
        int num= m + int (reloj->getElapsedTime().asMicroseconds())%(n+1) ;

        return num;
}


asteroide::asteroide(map<string,vector<sf::Texture*>*>* texturas_animaciones, map<string,sf::Texture*>* texturas,sf::Clock* reloj,sf::Event* evento){
    this->texturas_animaciones=texturas_animaciones;
    this->texturas=texturas;
    this->reloj=reloj;
    this->evento=evento;
    int tam_asteroide=numero_aleatorio(reloj,0,2);
    int tipo_asteroide=numero_aleatorio(reloj,0,2);

    string tip_ast;
    if(tipo_asteroide==0){
        tip_ast=" 1";
    }
    else if(tipo_asteroide==1){
        tip_ast=" 2";
    }
    else if(tipo_asteroide==2){
        tip_ast=" 3";
    }

    switch (tam_asteroide){
        case 0 :
            this->animacion_actual=(*texturas_animaciones)["asteroides pequeños" + tip_ast];
            this->radio=20;
            this->vida=10;
            break;
        case 1 :
            this->animacion_actual=(*texturas_animaciones)["asteroides medianos" + tip_ast];
            this->radio=50;
            this->vida=25;
            break;
        case 2 :
            this->animacion_actual=(*texturas_animaciones)["asteroides grandes" + tip_ast];
            this->radio=100;
            this->vida=70;
            break;

    }

    this->textura_actual=this->animacion_actual->at(0);
    this->coordenadas.x=1300;
    this->coordenadas.y=numero_aleatorio(reloj,0,1024);
    this->setPosition(this->coordenadas);
    this->velocidad.x=-numero_aleatorio(reloj,1,4);
    this->dimensiones=this->textura_actual->getSize();
    this->setOrigin(dimensiones.x/2,dimensiones.y/2);
    this->tiempo= new sf::Time;
    *this->tiempo=reloj->getElapsedTime();
    t_animacion=0.2;
}


void asteroide::update(){
    this->move(velocidad);
    this->setTexture(*textura_actual);
    this->animar();
    this->coordenadas=this->getPosition();
    this->verif_destruccion();


}

void asteroide::verif_destruccion(){
    if(this->vida<=0){
        this->destruir=true;
    }


}
