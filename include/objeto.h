#ifndef OBJETO_H
#define OBJETO_H
#include <iostream>
#include <tuple>
#include <SFML/Graphics.hpp>

class objeto : public sf::Sprite
{
    public:
        objeto();
        virtual ~objeto();
        virtual void update(){};
        void set_evento(sf::Event* evento){this->evento=evento;};
        virtual void verif_autodestruccion(){};
        virtual void detalles(){};
        virtual void fix_coordenadas(){};

    protected:
    private:
        sf::Vector2f coordenadas;
        sf::Vector2f punto_medio;
        sf::Vector2u dimensiones;
        sf::Texture* textura_actual;
        sf::Clock* reloj;
        sf::Time* tiempo;
        sf::Event* evento;
        sf::Vector2f velocidad;
        sf::Time creacion;
        sf::Time t_vida;
        int vida;
        int damage;
        float radio;
        bool destruir=false;
    friend class proyectil_animado;
    friend class bala_roja;
    friend class bala_electrica;
    friend class juego;
    friend class objeto_estatico;
    friend class objeto_animado;
    friend class nave;
    friend class proyectil_estatico;
    friend class bala_azul;
    friend class estacion;
    friend class asteroide;
};

#endif // OBJETO_H
