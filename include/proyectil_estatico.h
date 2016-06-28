#ifndef PROYECTIL_ESTATICO_H
#define PROYECTIL_ESTATICO_H
#include "objeto_estatico.h"

class proyectil_estatico: public objeto_estatico
{
    public:
        proyectil_estatico();
        proyectil_estatico(sf::Texture* , sf::Vector2f coordenadas,sf::Vector2f,sf::Clock*,float);
        virtual ~proyectil_estatico();

        void update();
        void verif_autodestruccion();

    protected:
    private:

    friend class estacion;
    friend class bala_azul;
    friend class bala_roja;
};

#endif // PROYECTIL_ESTATICO_H
