#ifndef BALA_ELECTRICA_H
#define BALA_ELECTRICA_H
#include "proyectil_animado.h"

class bala_electrica: public proyectil_animado
{
    public:
        bala_electrica();
        bala_electrica(vector<sf::Texture*>* animacion_actual, sf::Vector2f coordenadas,sf::Vector2f velocidad, sf::Clock* reloj, sf::Event* evento,float t_vida);
        virtual ~bala_electrica();
    protected:
    private:
};

#endif // BALA_ELECTRICA_H
