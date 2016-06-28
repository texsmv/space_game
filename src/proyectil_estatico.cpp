#include "proyectil_estatico.h"

proyectil_estatico::proyectil_estatico()
{
    //ctor
}

proyectil_estatico::~proyectil_estatico()
{
    //dtor
}

proyectil_estatico::proyectil_estatico(sf::Texture* textura, sf::Vector2f coordenadas,sf::Vector2f velocidad,sf::Clock*reloj,float t_vida){
    this->setTexture(*textura);
    this->coordenadas=coordenadas;
    this->setOrigin(this->dimensiones.x/2,this->dimensiones.y/2);
    this->velocidad=velocidad;
    this->reloj=reloj;
    this->creacion=reloj->getElapsedTime();
    this->t_vida=sf::seconds(t_vida);
    this->setPosition(coordenadas);
    this->rotate(90);
}


void proyectil_estatico::update(){
    this->move(velocidad);
    this->verif_autodestruccion();
    this->coordenadas= sf::Vector2f(this->getPosition().x+dimensiones.x,this->getPosition().y+dimensiones.y);
    this->fix_coordenadas();
    this->detalles();
}

void proyectil_estatico::verif_autodestruccion(){
    if ( (this->getPosition().x<0 || this->getPosition().x>1280 ) || ( this->getPosition().y<0 || this->getPosition().y>1024 ) || ( reloj->getElapsedTime().asSeconds()>=t_vida.asSeconds()+creacion.asSeconds() ) ){
        this->destruir=true;
    }
    if(this->vida<=0){
        this->destruir=true;
    }
}
