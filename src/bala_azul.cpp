#include "bala_azul.h"

bala_azul::bala_azul()
{
    //ctor
}

bala_azul::~bala_azul()
{
    //dtor
}

bala_azul::bala_azul(sf::Texture* textura, sf::Vector2f coordenadas,sf::Vector2f velocidad,sf::Clock*reloj,float t_vida){
    this->setTexture(*textura);
    this->setOrigin(this->dimensiones.x/2,this->dimensiones.y/2);
    this->velocidad=velocidad;
    this->reloj=reloj;
    this->creacion=reloj->getElapsedTime();
    this->t_vida=sf::seconds(t_vida);
    this->setPosition(coordenadas.x+80,coordenadas.y-9);
    this->coordenadas=this->getPosition();
    this->damage=10;
    this->radio=5;
    this->vida=1;
}
