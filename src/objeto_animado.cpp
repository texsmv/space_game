#include "objeto_animado.h"

objeto_animado::objeto_animado()
{
    //ctor
}

objeto_animado::~objeto_animado()
{
    //dtor
}

objeto_animado::objeto_animado(vector<sf::Texture*>* animacion_actual, sf::Vector2f coordenadas, sf::Clock* reloj, sf::Event* evento){
    this->animacion_actual=animacion_actual;
    this->reloj=reloj;
    this->textura_actual=this->animacion_actual->at(0);
    this->tiempo= new sf::Time;
    this->evento=evento;

    *this->tiempo=reloj->getElapsedTime();

}



//----------------------------------control-------------------------------

void objeto_animado::update(){
    this->setTexture(*textura_actual);
    this->animar();
    this->fix_coordenadas();
    this->coordenadas=this->getPosition();

    this->detalles();
}

void objeto_animado::animar(){
    if (tiempo->asSeconds()<=reloj->getElapsedTime().asSeconds()-t_animacion){
        this->iterar_animacion();
        *this->tiempo=reloj->getElapsedTime();
    }
    this->textura_actual=animacion_actual->at(num_anim);
}

void objeto_animado::iterar_animacion(){
    int size_anim=this->animacion_actual->size()-1;
    if(num_anim>=size_anim){
        num_anim=0;
    }
    else{
        num_anim++;
    }
}
