#include "estacion.h"

estacion::estacion()
{
    //ctor
}

estacion::~estacion()
{
    //dtor
}

float distancia2(sf::Vector2f a, sf::Vector2f b){
    float dist=sqrt(pow((b.x-a.x),2)+pow((b.y-a.y),2));
    return dist;
}

estacion::estacion(sf::Texture* textura, sf::Vector2f coordenadas,sf::Vector2f velocidad,sf::Clock*reloj,float t_vida,vector<objeto*>* enemigos,vector<objeto*>*proyectiles,map<string,vector<sf::Texture*>*>* texturas_animaciones){

    this->textura_actual=textura;
    this->setTexture(*textura_actual);
    this->scale(0.3,0.3);
    this->dimensiones=this->textura_actual->getSize();
    this->setOrigin(this->dimensiones.x/2,this->dimensiones.y/2);
    this->velocidad=velocidad;
    this->reloj=reloj;
    this->creacion=reloj->getElapsedTime();
    this->t_vida=sf::seconds(t_vida);
    this->setPosition(coordenadas.x+80,coordenadas.y);
    this->coordenadas=this->getPosition();
    this->enemigos=enemigos;
    this->proyectiles=proyectiles;
    this->damage=100;
    this->radio=40;
    this->vida=2;
    this->texturas_animaciones=texturas_animaciones;
    this->t_last_disparo=this->reloj->getElapsedTime();
    this->frec_disparo=0.3;
    this->rango=500;
}

void estacion::fix_coordenadas(){
    this->coordenadas=sf::Vector2f(this->getPosition().x,this->getPosition().y-10);
}



void estacion::detalles(){
    if(this->vida==1){
        this->velocidad=sf::Vector2f(0,0);
        this->disparar();

    }
}

void estacion::disparar(){
    if(t_last_disparo.asSeconds()<=reloj->getElapsedTime().asSeconds()-frec_disparo){
        for (auto it:*this->enemigos){
            if( distancia2(this->getPosition(),it->getPosition())<=this->rango ){
                objeto* temp=new bala_electrica((*this->texturas_animaciones)["bala electrica"], this->getPosition(),      sf::Vector2f(   (it->getPosition().x-this->getPosition().x)/30   ,  (it->getPosition().y-this->getPosition().y)/30   )     , this->reloj,this->evento,5);
                this->proyectiles->push_back(temp);
                t_last_disparo=reloj->getElapsedTime();
                break;
            }
        }


    }
}
