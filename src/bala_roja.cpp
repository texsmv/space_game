#include "bala_roja.h"

bala_roja::bala_roja()
{
    //ctor
}

bala_roja::~bala_roja()
{
    //dtor
}

bala_roja::bala_roja(sf::Texture* textura, sf::Vector2f coordenadas,sf::Vector2f velocidad,sf::Clock*reloj,float t_vida){
    this->setTexture(*textura);
    this->setOrigin(this->dimensiones.x/2,this->dimensiones.y/2);
    this->velocidad=velocidad;
    this->reloj=reloj;
    this->creacion=reloj->getElapsedTime();
    this->t_vida=sf::seconds(t_vida);
    this->setPosition(coordenadas.x+100,coordenadas.y-80);
    this->coordenadas=this->getPosition();
    this->rotate(90);
    this->damage=25;
    this->radio=20;
    this->vida=1;
}

void bala_roja::fix_coordenadas(){
    this->coordenadas=sf::Vector2f(coordenadas.x-50,coordenadas.y+30);
}

