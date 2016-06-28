#ifndef OBJETO_ANIMADO_H
#define OBJETO_ANIMADO_H
#include <vector>
#include "objeto.h"

using namespace std;

class objeto_animado: public objeto
{
    public:
        objeto_animado();
        objeto_animado(vector<sf::Texture*>*, sf::Vector2f, sf::Clock*, sf::Event* );

        virtual ~objeto_animado();

        //----------------------control------------------
        virtual void update();
        void animar();
        void iterar_animacion();


    protected:
    private:
        vector<sf::Texture*>* animacion_actual;
    friend class bala_electrica;
        int num_anim=0;
        float t_animacion=0.4;
        friend class proyectil_animado;
        friend class asteroide;
        friend class nave;
};

#endif // OBJETO_ANIMADO_H
