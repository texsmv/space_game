#include "proyectil_animado.h"

proyectil_animado::proyectil_animado()
{
    //ctor
}

proyectil_animado::~proyectil_animado()
{
    //dtor
}


proyectil_animado::proyectil_animado(vector<sf::Texture*>* animacion_actual, sf::Vector2f coordenadas,sf::Vector2f velocidad, sf::Clock* reloj, sf::Event* evento,float t_vida){
    this->animacion_actual=animacion_actual;
    this->reloj=reloj;
    this->textura_actual=this->animacion_actual->at(0);
    this->setTexture(*textura_actual);
    this->tiempo= new sf::Time;
    this->evento=evento;
    this->velocidad=velocidad;
    this->dimensiones=this->textura_actual->getSize();
    this->setOrigin(this->dimensiones.x/2,this->dimensiones.y/2);
    this->coordenadas=coordenadas;
    this->setPosition(coordenadas);
    *this->tiempo=reloj->getElapsedTime();
    this->creacion=reloj->getElapsedTime();
    this->t_vida=sf::seconds(t_vida);
    this->vida=1;
    this->damage=10;
}




void proyectil_animado::detalles(){
    this->move(velocidad);
    this->verif_autodestruccion();
}

void proyectil_animado::verif_autodestruccion(){
    if ( (this->getPosition().x<0 || this->getPosition().x>1280 ) || ( this->getPosition().y<0 || this->getPosition().y>1024 ) || ( reloj->getElapsedTime().asSeconds()>=t_vida.asSeconds()+creacion.asSeconds() ) ){
        this->destruir=true;
    }
    if(this->vida<=0){
        this->destruir=true;
    }
}


