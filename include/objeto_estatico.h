#ifndef OBJETO_ESTATICO_H
#define OBJETO_ESTATICO_H
#include "objeto.h"

class objeto_estatico: public objeto
{
    public:
        objeto_estatico();
        objeto_estatico(sf::Texture* , sf::Vector2f coordenadas);
        virtual ~objeto_estatico();
    protected:
    private:

    friend class asteroide;
    friend class bala_roja;
    friend class bala_azul;
    friend class proyectil_estatico;

};

#endif // OBJETO_ESTATICO_H
