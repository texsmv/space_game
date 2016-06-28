#ifndef ASTEROIDE_H
#define ASTEROIDE_H
#include "objeto_animado.h"
#include <map>
#include <vector>
#include "funciones.h"

using namespace std;

class asteroide: public objeto_animado
{
    public:
        asteroide();
        asteroide( map<string,vector<sf::Texture*>*>* , map<string,sf::Texture*>*, sf::Clock*, sf::Event* );

        virtual ~asteroide();
        void verif_destruccion();
        void update();
    protected:
    private:
        map<string,vector<sf::Texture*>*>* texturas_animaciones;
        map<string,sf::Texture*>* texturas;

};

#endif // ASTEROIDE_H
