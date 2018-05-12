#include <SFML/Graphics.hpp>
#include "pixel.h"
#include "MainMenu.h"
#include "KEYBOARD.h"

#include <time.h>
#include <iostream>
#include <string.h>


int main()
{
    
    KEYBOARD keyboard;
    
    MainMenu mainMenu;
    
    sf::RenderWindow window(sf::VideoMode(800, 600), "Square World");
    window.setFramerateLimit(60);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        keyboard.KeyboardCheckPressed();
        
        window.clear(sf::Color(0,0,111,255));
        
        mainMenu.actionMenu(keyboard, window);
        mainMenu.show(window);
        
        //std::cout << "ok \n";
        window.display();
    }
    return 0;
}