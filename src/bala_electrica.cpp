#include "bala_electrica.h"

bala_electrica::bala_electrica()
{
    //ctor
}

bala_electrica::~bala_electrica()
{
    //dtor
}

bala_electrica::bala_electrica(vector<sf::Texture*>* animacion_actual, sf::Vector2f coordenadas,sf::Vector2f velocidad, sf::Clock* reloj, sf::Event* evento,float t_vida){
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
    this->t_animacion=0.1;
}
