#include <SFML/Graphics.hpp>
#include "objeto_estatico.h"
#include "juego.h"

int main()
{
    sf::RenderWindow *window=new sf::RenderWindow(sf::VideoMode(1280, 1024), "SFML works!");



    sf::Event ev;
    sf::Event* e=&ev;

    juego* j=new juego(window,e);

    while (window->isOpen())
    {
        sf::Event event;
        sf::Event* evento=&event;

        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed || ( (event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)) )
                window->close();
        }
        j->set_evento(evento);
        j->update();
    }

    return 0;
}
