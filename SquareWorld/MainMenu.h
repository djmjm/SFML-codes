#ifndef MainMenu_h
#define MainMenu_h

#include "KEYBOARD.h"
#include "pixel.h"

#include <vector>
#include <iostream>
#include <time.h>

class MainMenu{
    public:
        MainMenu();
        ~MainMenu();
        void show(sf::RenderWindow &window);
        void actionMenu(KEYBOARD &keyboard, sf::RenderWindow &window);
    
    private:
        
        //set position squareHand 
        void setPositionSquareHand(sf::Vector2f pos);
        
        //setDown and up colors;
        void setDownRed();
        void setUpRed();
        void setDownGreen();
        void setUpGreen();
        void setDownBlue();
        void setUpBlue();
        
        //get position of color scroll
        void getPositionScroll();
        
        //set text string of change color for text
        void setStringChooseColor();
        
        //define fonts
        sf::Font *FTitulo;
        
        //define texts
        sf::Text *TTitulo;
        sf::Text *TPlay;
        sf::Text *TQuit;
        
        sf::Text *TWalk;
        
        sf::Text *TchooseColors;
        sf::Text *TchooseColorCurrent;
        sf::Text *TchooseColorNext;
        int countChooseColorNext;
        
        //define squares
        pixel *square;
        
         //Square Hand
        std::vector <pixel> squareHand = {
            { 255, 255, 255, 255, sf::Vector2f(720/2 - 70, 310), sf::Vector2i(30, 30) },
            { 255, 255, 255, 255, sf::Vector2f(720/2 - 40, 310), sf::Vector2i(10, 10) },
            { 0, 0, 0, 255, sf::Vector2f(720/2 - 50, 320), sf::Vector2i(10, 3) },
            { 0, 0, 0, 255, sf::Vector2f(720/2 - 50, 327), sf::Vector2i(10, 3) },
            { 0, 0, 0, 255, sf::Vector2f(720/2 - 50, 334), sf::Vector2i(10, 3) }
        };
        
        //Menu choose color
        
        std::vector <pixel> menuChooseColor = {
            { 0, 0, 0, 122, sf::Vector2f(200, 50), sf::Vector2i(20, 20) },
            { 0, 0, 0, 122, sf::Vector2f(220, 50), sf::Vector2i(20 * 18, 20) },
            { 0, 0, 0, 122, sf::Vector2f(200, 70), sf::Vector2i(20, 20) },
            { 50, 50, 50, 255, sf::Vector2f(220, 70), sf::Vector2i(20 * 17, 20) },
            { 0, 0, 0, 122, sf::Vector2f(560, 70), sf::Vector2i(20, 20) },
            { 0, 0, 0, 122, sf::Vector2f(200, 90), sf::Vector2i(20, 20) },
            { 110, 110, 110, 255, sf::Vector2f(220, 90), sf::Vector2i(20 * 17, 20) },
            { 0, 0, 0, 122, sf::Vector2f(560, 90), sf::Vector2i(20, 20) },
            { 0, 0, 0, 122, sf::Vector2f(200, 110), sf::Vector2i(20, 20) },
            { 122, 122, 122, 255, sf::Vector2f(220, 110), sf::Vector2i(20 * 17, 20) },
            { 0, 0, 0, 122, sf::Vector2f(560, 110), sf::Vector2i(20, 20) },
            { 0, 0, 0, 122, sf::Vector2f(200, 130), sf::Vector2i(20, 20) },
            { 132, 132, 132, 255, sf::Vector2f(220, 130), sf::Vector2i(20 * 17, 20) },
            { 0, 0, 0, 122, sf::Vector2f(560, 130), sf::Vector2i(20, 20) },
            { 0, 0, 0, 122, sf::Vector2f(200, 150), sf::Vector2i(20, 20) },
            { 142, 142, 142, 255, sf::Vector2f(220, 150), sf::Vector2i(20 * 17, 20) },
            { 0, 0, 0, 122, sf::Vector2f(560, 150), sf::Vector2i(20, 20) },
            { 0, 0, 0, 122, sf::Vector2f(200, 170), sf::Vector2i(20, 20) },
            { 152, 152, 152, 255, sf::Vector2f(220, 170), sf::Vector2i(20 * 17, 20) },
            { 0, 0, 0, 122, sf::Vector2f(560, 170), sf::Vector2i(20, 20) },
            { 0, 0, 0, 122, sf::Vector2f(200, 190), sf::Vector2i(20, 20) },
            { 162, 162, 162, 255, sf::Vector2f(220, 190), sf::Vector2i(20 * 17, 20) },
            { 0, 0, 0, 122, sf::Vector2f(560, 190), sf::Vector2i(20, 20) },
            { 0, 0, 0, 122, sf::Vector2f(200, 210), sf::Vector2i(20, 20) },
            { 172, 172, 172, 255, sf::Vector2f(220, 210), sf::Vector2i(20 * 17, 20) },
            { 0, 0, 0, 122, sf::Vector2f(560, 210), sf::Vector2i(20, 20) },
            { 0, 0, 0, 122, sf::Vector2f(200, 230), sf::Vector2i(20, 20) },
            { 0, 0, 0, 122, sf::Vector2f(220, 230), sf::Vector2i(20 * 17, 20) },
            { 0, 0, 0, 122, sf::Vector2f(560, 230), sf::Vector2i(20, 20) },
        };
        
         std::vector <pixel> menuChooseColorColors = {
             { 255, 0, 0, 255, sf::Vector2f(260, 110), sf::Vector2i(20, 20) },
            { 200, 0, 0, 255, sf::Vector2f(260, 130), sf::Vector2i(20, 20) },
            { 150, 0, 0, 255, sf::Vector2f(260, 150), sf::Vector2i(20, 20) },
            { 100, 0, 0, 255, sf::Vector2f(260, 170), sf::Vector2i(20, 20) },
            { 0, 0, 0, 255, sf::Vector2f(260, 190), sf::Vector2i(20, 20) },
         };
         
         std::vector <pixel> menuChooseColorColors2 = {
             { 0, 255, 0, 255, sf::Vector2f(300, 110), sf::Vector2i(20, 20) },
            { 0, 200, 0, 255, sf::Vector2f(300, 130), sf::Vector2i(20, 20) },
            { 0, 150, 0, 255, sf::Vector2f(300, 150), sf::Vector2i(20, 20) },
            { 0, 100, 0, 255, sf::Vector2f(300, 170), sf::Vector2i(20, 20) },
            { 0, 0, 0, 255, sf::Vector2f(300, 190), sf::Vector2i(20, 20) },
         };
         
         std::vector <pixel> menuChooseColorColors3 = {
             { 0, 0, 255, 255, sf::Vector2f(340, 110), sf::Vector2i(20, 20) },
            { 0, 0, 200, 255, sf::Vector2f(340, 130), sf::Vector2i(20, 20) },
            { 0, 0, 150, 255, sf::Vector2f(340, 150), sf::Vector2i(20, 20) },
            { 0, 0, 100, 255, sf::Vector2f(340, 170), sf::Vector2i(20, 20) },
            { 0, 0, 0, 255, sf::Vector2f(340, 190), sf::Vector2i(20, 20) },
         };
         
         pixel barraMenuChooseColor = pixel(205, 212, 22, 230, sf::Vector2f(260, 205), sf::Vector2i(20, 5) );
         pixel barraMenuChooseColor2 = pixel(205, 212, 22, 230, sf::Vector2f(260, 205), sf::Vector2i(20, 5) );
         pixel barraMenuChooseColor3 = pixel(205, 212, 22, 230, sf::Vector2f(260, 205), sf::Vector2i(20, 5) );
        
        int changeColor = 0;
        //player
        int rRosto = 226, gRosto = 222, bRosto = 109;
        int rCabelo = 36, gCabelo = 150, bCabelo = 44;
        int rCamisa = 26, gCamisa = 186, bCamisa = 227;
        int rCalca = 36, gCalca = 44, bCalca = 146;
        int rSapato = 0, gSapato = 0, bSapato = 0;
        
        std::vector <pixel> Oplayer1 = {
            { rRosto, gRosto, bRosto, 255, sf::Vector2f(80, 100), sf::Vector2i(15,15) }, 
            { rCabelo, gCabelo, bCabelo, 255, sf::Vector2f(80, 85), sf::Vector2i(15,15) },
            { rCabelo, gCabelo, bCabelo, 255, sf::Vector2f(65, 85), sf::Vector2i(15,15) }, 
            { rCabelo, gCabelo, bCabelo, 255, sf::Vector2f(65, 100), sf::Vector2i(15,15) },
            { rCamisa, gCamisa, bCamisa, 255, sf::Vector2f(80, 115), sf::Vector2i(15,15) },
            { rCalca, gCalca, bCalca, 255, sf::Vector2f(80, 130), sf::Vector2i(15,15) }, 
            { rSapato, gSapato, bSapato, 255, sf::Vector2f(80, 145), sf::Vector2i(15,15) }
        };
        
        std::vector <pixel> Oplayer1Walking = {
            { 226, 222, 109, 255, sf::Vector2f(80, 100), sf::Vector2i(15,15) }, 
            { 36, 150, 44, 255, sf::Vector2f(80, 85), sf::Vector2i(15,15) },
            { 36, 150, 44, 255, sf::Vector2f(65, 85), sf::Vector2i(15,15) }, 
            { 36, 150, 44, 255, sf::Vector2f(65, 100), sf::Vector2i(15,15) },
            { 26, 186, 227, 255, sf::Vector2f(80, 115), sf::Vector2i(15,15) },
            { 36, 44, 146, 255, sf::Vector2f(80, 130), sf::Vector2i(15,15) }, 
            { 0, 0, 0, 255, sf::Vector2f(95, 145), sf::Vector2i(15,15) },
            { 0, 0, 0, 255, sf::Vector2f(65, 145), sf::Vector2i(15,15) }
        };
        
        //menuOPs
        int firstMenuOp = 1;
        int SecondMenuOp = 1;
        int menu = 1;
        
        //booleans
        bool walking = false;
        
        //auxs
        int auxWalking;
        
};


#endif