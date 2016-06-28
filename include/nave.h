#ifndef NAVE_H
#define NAVE_H
#include "objeto_animado.h"
#include "proyectil_estatico.h"
#include "bala_azul.h"
#include "bala_roja.h"
#include "estacion.h"
#include "bala_electrica.h"
#include "proyectil_animado.h"

class nave: public objeto_animado
{
    public:
        nave();
        nave(vector<sf::Texture*>* animacion_actual, sf::Vector2f coordenadas, sf::Clock* reloj, sf::Event* evento,vector<objeto*>*,map<string,vector<sf::Texture*>*>* , map<string,sf::Texture*>* ,vector<objeto*>*);
        virtual ~nave();
        void mover();
        void update();
        void disparar();
    protected:
    private:
        vector<objeto*>* proyectiles;
        float frec_disparo;
        sf::Time t_last_disparo;
        string tipo_disparo="normal";
        map<string,vector<sf::Texture*>*>* texturas_animaciones;
        map<string,sf::Texture*>* texturas;
        vector<objeto*>* enemigos;
};

#endif // NAVE_H
