#include "objeto_estatico.h"

objeto_estatico::objeto_estatico()
{
    //ctor
}

objeto_estatico::~objeto_estatico()
{
    //dtor
}

objeto_estatico::objeto_estatico(sf::Texture* textura, sf::Vector2f coordenadas){
    this->setTexture(*textura);
    this->coordenadas=coordenadas;
    this->setPosition(coordenadas);
    this->setOrigin(this->dimensiones.x/2,this->dimensiones.y/2);

}


