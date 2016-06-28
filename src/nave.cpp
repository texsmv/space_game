#include "nave.h"

nave::nave()
{
    //ctor
}

nave::~nave()
{
    //dtor
}

nave::nave(vector<sf::Texture*>* animacion_actual, sf::Vector2f coordenadas, sf::Clock* reloj, sf::Event* evento,vector<objeto*>* proyectiles,map<string,vector<sf::Texture*>*>* texturas_animaciones,map<string,sf::Texture*>* texturas, vector<objeto*>* enemigos){
    this->animacion_actual=animacion_actual;
    this->reloj=reloj;
    this->textura_actual=this->animacion_actual->at(0);
    this->tiempo= new sf::Time;
    this->evento=evento;
    this->texturas_animaciones=texturas_animaciones;
    this->texturas=texturas;
    *this->tiempo=reloj->getElapsedTime();
    this->setPosition(coordenadas);
    this->scale(0.3,0.3);
    this->dimensiones=this->textura_actual->getSize();
    this->setOrigin(dimensiones.x/2,dimensiones.y/2);
    this->rotate(90);
    this->proyectiles=proyectiles;
    this->t_last_disparo=this->reloj->getElapsedTime();
    this->tipo_disparo="estacion";
    this->enemigos=enemigos;
    this->vida=3;
}

void nave::mover(){
    float velocidad_x, velocidad_y;
    velocidad_x=5;
    velocidad_y=15;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        this->move(0,-velocidad_y);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        this->move(0,velocidad_y);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        this->move(-velocidad_x,0);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        this->move(velocidad_x,0);
    }


    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
        this->disparar();
    }
}

void nave::disparar(){
    if(t_last_disparo.asSeconds()<=reloj->getElapsedTime().asSeconds()-frec_disparo){

        if(tipo_disparo=="normal"){
            this->frec_disparo=0.2;

            objeto* temp=new bala_azul((*texturas)["bala azul"] , this->getPosition(),sf::Vector2f(10,0),reloj,4);
            this->proyectiles->push_back(temp);
            t_last_disparo=reloj->getElapsedTime();
        }
        else if(tipo_disparo=="doble"){
            this->frec_disparo=0.7;

            objeto* temp1=new bala_roja((*texturas)["bala roja"] , this->getPosition(),sf::Vector2f(20,0),reloj,4);
            this->proyectiles->push_back(temp1);
            objeto* temp2=new bala_roja((*texturas)["bala roja"] , sf::Vector2f(this->getPosition().x,this->getPosition().y+70 ),sf::Vector2f(20,0),reloj,4);
            this->proyectiles->push_back(temp2);
            t_last_disparo=reloj->getElapsedTime();
        }

        else if(tipo_disparo=="estacion"){
            this->frec_disparo=0.2;
            objeto* temp=new estacion((*texturas)["estacion"] , this->getPosition(),sf::Vector2f(10,0),reloj,30,this->enemigos,this->proyectiles,this->texturas_animaciones);
            this->proyectiles->push_back(temp);
            t_last_disparo=reloj->getElapsedTime();
        }


        else if(tipo_disparo=="bala electrica"){
            this->frec_disparo=0.2;
            objeto* temp=new bala_electrica((*this->texturas_animaciones)["bala electrica"], this->getPosition(),sf::Vector2f(10,0), this->reloj,this->evento,5);
            this->proyectiles->push_back(temp);
            t_last_disparo=reloj->getElapsedTime();
        }
    }


}

void nave::update(){
    this->setTexture(*textura_actual);
    this->animar();
    this->mover();
    this->coordenadas=this->getPosition();

}
