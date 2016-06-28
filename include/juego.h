#ifndef JUEGO_H
#define JUEGO_H
#include <SFML/Graphics.hpp>
#include <algorithm>
#include <vector>
#include <map>
#include "objeto_animado.h"
#include "objeto_estatico.h"
#include "objeto.h"
#include "nave.h"
#include "proyectil_estatico.h"
#include "asteroide.h"


using namespace std;

class juego
{
    public:
        juego(sf::RenderWindow *,sf::Event*);
        juego();
        virtual ~juego();

        //----------------control--------------
        void update();
        void limpiar(){this->win->clear();};
        void update_objetos();
        void dibujar_objetos();
        void mostrar(){this->win->display();};
        void destruir_objetos();
        void crear_asteroides();
        void verif_colisiones();
        void verif_nave();
        //----------------procesos-------------
        void set_evento(sf::Event*);

        vector<sf::Texture*>* generar_texturas(vector<string>);
        void crear_direcciones(vector<string>&, string);


    protected:
    private:
        sf::RenderWindow *win;
        sf::Clock * reloj;
        sf::Event * evento;
        nave* nave_jugador;
        map<string,vector<sf::Texture*>*>* texturas_animaciones;
        map<string,sf::Texture*>* texturas;
        vector<objeto*>* objetos;
        vector<objeto*>* proyectiles;
        vector<objeto*>* enemigos;
        int probabilidad_inicial = 30;
        int probabilidad_total = 1000;


};

#endif // JUEGO_H
