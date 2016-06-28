#ifndef BALA_AZUL_H
#define BALA_AZUL_H
#include "proyectil_estatico.h"

class bala_azul: public proyectil_estatico
{
    public:
        bala_azul();

        bala_azul(sf::Texture* , sf::Vector2f coordenadas,sf::Vector2f,sf::Clock*,float);

        virtual ~bala_azul();
    protected:
    private:
};

#endif // BALA_AZUL_H
