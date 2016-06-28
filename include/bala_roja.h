#ifndef BALA_ROJA_H
#define BALA_ROJA_H
#include "bala_roja.h"
#include "proyectil_estatico.h"

class bala_roja: public proyectil_estatico
{
    public:
        bala_roja();
        bala_roja(sf::Texture* , sf::Vector2f coordenadas,sf::Vector2f,sf::Clock*,float);
        virtual ~bala_roja();
        void fix_coordenadas();
    protected:
    private:
};

#endif // BALA_ROJA_H
