#ifndef ESTACION_H
#define ESTACION_H
#include <vector>
#include "proyectil_estatico.h"
#include "bala_electrica.h"

using namespace std;

class estacion:public proyectil_estatico
{
    public:
        estacion();
        estacion(sf::Texture* , sf::Vector2f coordenadas,sf::Vector2f velocidad,sf::Clock* reloj,float,vector<objeto*>*enemigos,vector<objeto*>*proyectiles,map<string,vector<sf::Texture*>*>* texturas_animaciones);
        virtual ~estacion();
        void fix_coordenadas();
        void disparar();
        void detalles();
    protected:
    private:
        map<string,vector<sf::Texture*>*>* texturas_animaciones;
        vector<objeto*>* enemigos;
        vector<objeto*>*proyectiles;
        float frec_disparo;
        sf::Time t_last_disparo;
        float rango;
};

#endif // ESTACION_H
