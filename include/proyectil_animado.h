#ifndef PROYECTIL_ANIMADO_H
#define PROYECTIL_ANIMADO_H
#include "objeto_animado.h"

class proyectil_animado: public objeto_animado
{
    public:
        proyectil_animado();
        proyectil_animado(vector<sf::Texture*>* animacion_actual, sf::Vector2f coordenadas,sf::Vector2f velocidad, sf::Clock* reloj, sf::Event* evento,float t_vida);
        virtual ~proyectil_animado();
        void verif_autodestruccion();
        void detalles();
    protected:
    private:
};

#endif // PROYECTIL_ANIMADO_H

