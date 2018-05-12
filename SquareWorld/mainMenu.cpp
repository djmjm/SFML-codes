#include "MainMenu.h"

// constructor
MainMenu::MainMenu(){

    //initializing
    FTitulo = new sf::Font;
    TTitulo = new sf::Text;
    TPlay = new sf::Text;
    TQuit = new sf::Text;
    TWalk = new sf::Text;
    TchooseColors = new sf::Text;
    TchooseColorCurrent = new sf::Text;
    TchooseColorNext = new sf::Text;
    square = new pixel[1000];
    auxWalking = 0;
    
    //set fontTitulo
    FTitulo->loadFromFile("fonts/titulo.otf");
    
    //set Ttitulo
    TTitulo->setFont(*FTitulo);
    TTitulo->setFillColor(sf::Color::Yellow);
    TTitulo->setPosition(85, 100);
    TTitulo->setCharacterSize(72);
    TTitulo->setString("Square World");
    
    //set Tplay
    TPlay->setFont(*FTitulo);
    TPlay->setFillColor(sf::Color::Yellow);
    TPlay->setPosition(720/2, 300);
    TPlay->setCharacterSize(32);
    TPlay->setString("Play");
    
    //set TQuit
    TQuit->setFont(*FTitulo);
    TQuit->setFillColor(sf::Color::Yellow);
    TQuit->setPosition(720/2, 350);
    TQuit->setCharacterSize(32);
    TQuit->setString("Quit");
    
    //set TWalk
    TWalk->setFont(*FTitulo);
    TWalk->setFillColor(sf::Color::Yellow);
    TWalk->setPosition(80, 190);
    TWalk->setCharacterSize(22);
    TWalk->setString("Walk");
    
    //set TchooseColors
    TchooseColors->setFont(*FTitulo);
    TchooseColors->setFillColor(sf::Color::Yellow);
    TchooseColors->setPosition(260, 75);
    TchooseColors->setCharacterSize(25);
    TchooseColors->setString("Choose the colors");
    
    //set TchooseColorCurrent
    TchooseColorCurrent->setFont(*FTitulo);
    TchooseColorCurrent->setFillColor(sf::Color::Yellow);
    TchooseColorCurrent->setPosition(430, 130);
    TchooseColorCurrent->setCharacterSize(22);
    TchooseColorCurrent->setString("Skin");
    
    //set TchooseColorNext
    TchooseColorNext->setFont(*FTitulo);
    TchooseColorNext->setFillColor(sf::Color::Yellow);
    TchooseColorNext->setPosition(430, 160);
    TchooseColorNext->setCharacterSize(22);
    TchooseColorNext->setString("Next");

    srand(time(NULL));
    
    //set random squares
    for(int k = 0; k < 1000; ++k){
        int aux = rand() % 256, aux2 = rand() % 256, aux3 = rand() % 256;
       
        square[k].setColor(aux, aux2, aux3, 50);
        aux = rand() % 725;
        aux2 = rand() % 525;
        aux += 25;
        aux2 += 25;
        square[k].setPosition(aux, aux2);
        square[k].setSize(25, 25);
        
        
        int xDir = (rand() % 20) - 10;
        int yDir = (rand() % 20) - 10;
        square[k].setDir(xDir, yDir);
        
        if (k % 10 == 0)
            square[k].setMove(false);
        else square[k].setMove(true);
    
    }
    
}


//destructor
MainMenu::~MainMenu(){
    delete FTitulo;
    delete TTitulo;
    //delete square;
}

//to shown
void MainMenu::show(sf::RenderWindow &window){
    for(int i = 0; i < 1000; ++i)
            square[i].show(window);
    if (menu == 1){
        window.draw(*TTitulo);
        window.draw(*TPlay);
        window.draw(*TQuit);
        
    }else if(menu == 2){
        window.draw(*TWalk);
        for(auto x: menuChooseColor)
            x.show(window);
        for(auto x: menuChooseColorColors)
            x.show(window);
        for(auto x: menuChooseColorColors2)
            x.show(window);
        for(auto x: menuChooseColorColors3)
            x.show(window);
            
        barraMenuChooseColor.show(window);
        barraMenuChooseColor2.show(window);
        barraMenuChooseColor3.show(window);
        
        if(!walking)
            for(auto x: Oplayer1)
                x.show(window);
        else{
            ++auxWalking;
            if(auxWalking < 15)
                for(auto x: Oplayer1Walking)
                    x.show(window);
            else for(auto x: Oplayer1)
                    x.show(window);
            if(auxWalking == 30)
                auxWalking = 0;
        }
        window.draw(*TchooseColors);
        window.draw(*TchooseColorCurrent);
        window.draw(*TchooseColorNext);
        getPositionScroll();
    }
     for(auto x: squareHand)
            x.show(window);
}

// menu actions
void MainMenu::actionMenu(KEYBOARD &keyboard, sf::RenderWindow &window){
    
    // move the squareHand
    if(menu == 1){
        if( (!keyboard.activeUp) && (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) && (firstMenuOp < 1) ){
                for(int i = 0; i < 5; ++i){
                    pixel *aux = &squareHand.at(i);
                    aux->sumPosition(0, -50);
                }
            
                ++firstMenuOp;
                keyboard.activeUp = true;
            }
        if( (!keyboard.activeDown) && (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) && (firstMenuOp > 0) ){
                for(int i = 0; i < 5; ++i){
                    pixel *aux = &squareHand.at(i);
                    aux->sumPosition(0, +50);
                }
                --firstMenuOp;
                keyboard.activeDown = true;
        }
        if( (!keyboard.activeEnter) && (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) && (firstMenuOp == 0) ){
            window.close();
        }
        
        if( (!keyboard.activeEnter) && (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) && (firstMenuOp == 1) ){
            menu = 2;
            setPositionSquareHand(sf::Vector2f(30, 190));
            keyboard.activeEnter = true;
        }
    }else if(menu == 2){
        if(SecondMenuOp == 1){
            if( (!walking) && (!keyboard.activeEnter) && (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) ){
                walking = true;
                keyboard.activeEnter = true;
                TWalk->setFillColor(sf::Color::Green);
            } else if ( (!keyboard.activeEnter) && (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) ){
                walking = false;
                keyboard.activeEnter = true;
                TWalk->setFillColor(sf::Color::Yellow);
            }
            if( (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) && (!keyboard.activeRight) ){
                keyboard.activeRight = true;
                SecondMenuOp = 2;
            }
            setPositionSquareHand(sf::Vector2f(30, 190));
        }
        if(SecondMenuOp == 2){
            setDownRed();
            setPositionSquareHand(sf::Vector2f(210, 190));
            if( (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) && (!keyboard.activeRight) ){
                keyboard.activeRight = true;
                SecondMenuOp = 4;
            }
            if( (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) && (!keyboard.activeUp) ){
                keyboard.activeUp = true;
                SecondMenuOp = 3;
            }
            if( (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) && (!keyboard.activeLeft) ){
                keyboard.activeLeft = true;
                SecondMenuOp = 1;
            }
        }
        if(SecondMenuOp == 3){
            setUpRed();
            setPositionSquareHand(sf::Vector2f(210, 110));
            if( (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) && (!keyboard.activeRight) ){
                keyboard.activeRight = true;
                SecondMenuOp = 5;
            }
            if( (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) && (!keyboard.activeUp) ){
                keyboard.activeDown = true;
                SecondMenuOp = 2;
            }
            if( (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) && (!keyboard.activeLeft) ){
                keyboard.activeLeft = true;
                SecondMenuOp = 1;
            }
        }
        if(SecondMenuOp == 4){
            setDownGreen();
            setPositionSquareHand(sf::Vector2f(250, 190));
            if( (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) && (!keyboard.activeRight) ){
                keyboard.activeRight = true;
                SecondMenuOp = 6;
            }
            if( (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) && (!keyboard.activeUp) ){
                keyboard.activeUp = true;
                SecondMenuOp = 5;
            }
            if( (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) && (!keyboard.activeLeft) ){
                keyboard.activeLeft = true;
                SecondMenuOp = 2;
            }
        }
        if(SecondMenuOp == 5){
            setUpGreen();
            setPositionSquareHand(sf::Vector2f(250, 110));
            if( (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) && (!keyboard.activeRight) ){
                keyboard.activeRight = true;
                SecondMenuOp = 7;
            }
            if( (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) && (!keyboard.activeUp) ){
                keyboard.activeDown = true;
                SecondMenuOp = 4;
            }
            if( (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) && (!keyboard.activeLeft) ){
                keyboard.activeLeft = true;
                SecondMenuOp = 3;
            }
        }
        if(SecondMenuOp == 6){
            setDownBlue();
            setPositionSquareHand(sf::Vector2f(290, 190));
            if( (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) && (!keyboard.activeUp) ){
                keyboard.activeUp = true;
                SecondMenuOp = 7;
            }
            if( (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) && (!keyboard.activeLeft) ){
                keyboard.activeLeft = true;
                SecondMenuOp = 4;
            }
            if( (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) && (!keyboard.activeRight) ){
                keyboard.activeRight = true;
                SecondMenuOp = 8;
            }
        }
        if(SecondMenuOp == 7){
            setUpBlue();
            setPositionSquareHand(sf::Vector2f(290, 110));
            if( (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) && (!keyboard.activeUp) ){
                keyboard.activeDown = true;
                SecondMenuOp = 6;
            }
            if( (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) && (!keyboard.activeLeft) ){
                keyboard.activeLeft = true;
                SecondMenuOp = 5;
            }
            if( (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) && (!keyboard.activeRight) ){
                keyboard.activeRight = true;
                SecondMenuOp = 8;
            }
        }
        
        if(SecondMenuOp == 8){
            if( (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) && (!keyboard.activeLeft) ){
                keyboard.activeLeft = true;
                SecondMenuOp = 6;
            }
            setPositionSquareHand(sf::Vector2f(380, 170));
            
            if( (!keyboard.activeEnter) && (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) ){
                keyboard.activeEnter = true;
                countChooseColorNext = 10;
                ++changeColor;
                if(changeColor > 4)
                    changeColor = 0;
                setStringChooseColor();
            }
            
            if(countChooseColorNext > 0){
                --countChooseColorNext;
                TchooseColorNext->setColor(sf::Color::Green);
            }
            if(countChooseColorNext == 0){
                TchooseColorNext->setColor(sf::Color::Yellow);
            }
            
        }
    }
        
}

// set position square handle
void MainMenu::setPositionSquareHand(sf::Vector2f pos){
    pixel *aux = &squareHand.at(0);
    aux->setPosition(pos.x, pos.y);
    aux = &squareHand.at(1);
    aux->setPosition(pos.x + 30, pos.y);
    aux = &squareHand.at(2);
    aux->setPosition(pos.x + 20, pos.y + 10);
    aux = &squareHand.at(3);
    aux->setPosition(pos.x + 20, pos.y + 17);
    aux = &squareHand.at(4);
    aux->setPosition(pos.x + 20, pos.y + 24);
}

void MainMenu::setDownRed(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){
        if(changeColor == 0){
            auto x = &Oplayer1.at(0);
            auto x2 = &Oplayer1Walking.at(0);
            if(rRosto > 1){
                x->setColor(--rRosto, gRosto, bRosto, 255);
                x2->setColor(--rRosto, gRosto, bRosto, 255);
            }
        }
        
        if(changeColor == 1){
            auto x = &Oplayer1.at(1);
            auto x3 = &Oplayer1.at(2);
            auto x4 = &Oplayer1.at(3);
            auto x2 = &Oplayer1Walking.at(1);
            auto x5 = &Oplayer1Walking.at(2);
            auto x6 = &Oplayer1Walking.at(3);
            if(rCabelo > 1){
                x->setColor(--rCabelo, gCabelo, bCabelo, 255);
                x2->setColor(--rCabelo, gCabelo, bCabelo, 255);
                x3->setColor(--rCabelo, gCabelo, bCabelo, 255);
                x4->setColor(--rCabelo, gCabelo, bCabelo, 255);
                x5->setColor(--rCabelo, gCabelo, bCabelo, 255);
                x6->setColor(--rCabelo, gCabelo, bCabelo, 255);
            }
        }
        
        if(changeColor == 2){
            auto x = &Oplayer1.at(4);
            auto x6 = &Oplayer1Walking.at(4);
            if(rCamisa > 1){
                x->setColor(--rCamisa, gCamisa, bCamisa, 255);
                x6->setColor(--rCamisa, gCamisa, bCamisa, 255);
            }
        }
    }
}

void MainMenu::setUpRed(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){
        if(changeColor == 0){
            auto x = &Oplayer1.at(0);
            auto x2 = &Oplayer1Walking.at(0);
            if(rRosto < 254){
                x->setColor(++rRosto, gRosto, bRosto, 255);
                x2->setColor(++rRosto, gRosto, bRosto, 255);
            }
        }
        
        if(changeColor == 1){
            auto x = &Oplayer1.at(1);
            auto x3 = &Oplayer1.at(2);
            auto x4 = &Oplayer1.at(3);
            auto x2 = &Oplayer1Walking.at(1);
            auto x5 = &Oplayer1Walking.at(2);
            auto x6 = &Oplayer1Walking.at(3);
            if(rCabelo < 250){
                x->setColor(++rCabelo, gCabelo, bCabelo, 255);
                x2->setColor(++rCabelo, gCabelo, bCabelo, 255);
                x3->setColor(++rCabelo, gCabelo, bCabelo, 255);
                x4->setColor(++rCabelo, gCabelo, bCabelo, 255);
                x5->setColor(++rCabelo, gCabelo, bCabelo, 255);
                x6->setColor(++rCabelo, gCabelo, bCabelo, 255);
            }
        }
        
        if(changeColor == 2){
            auto x = &Oplayer1.at(4);
            auto x6 = &Oplayer1Walking.at(4);
            if(rCamisa < 253){
                x->setColor(++rCamisa, gCamisa, bCamisa, 255);
                x6->setColor(++rCamisa, gCamisa, bCamisa, 255);
            }
        }
    }
}

void MainMenu::setDownGreen(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){
        if(changeColor == 0){
            auto x = &Oplayer1.at(0);
            auto x2 = &Oplayer1Walking.at(0);
            if(gRosto > 1){
                x->setColor(rRosto, --gRosto, bRosto, 255);
                x2->setColor(rRosto, --gRosto, bRosto, 255);
            }
        }
        if(changeColor == 1){
            auto x = &Oplayer1.at(1);
            auto x3 = &Oplayer1.at(2);
            auto x4 = &Oplayer1.at(3);
            auto x2 = &Oplayer1Walking.at(1);
            auto x5 = &Oplayer1Walking.at(2);
            auto x6 = &Oplayer1Walking.at(3);
            if(gCabelo > 1){
                x->setColor(rCabelo, --gCabelo, bCabelo, 255);
                x2->setColor(rCabelo, --gCabelo, bCabelo, 255);
                x3->setColor(rCabelo, --gCabelo, bCabelo, 255);
                x4->setColor(rCabelo, --gCabelo, bCabelo, 255);
                x5->setColor(rCabelo, --gCabelo, bCabelo, 255);
                x6->setColor(rCabelo, --gCabelo, bCabelo, 255);
            }
        }
        if(changeColor == 2){
            auto x = &Oplayer1.at(4);
            auto x6 = &Oplayer1Walking.at(4);
            if(gCamisa > 1){
                x->setColor(rCamisa, --gCamisa, bCamisa, 255);
                x6->setColor(rCamisa, --gCamisa, bCamisa, 255);
            }
        }
    }
}

void MainMenu::setUpGreen(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){
        if(changeColor == 0){
            auto x = &Oplayer1.at(0);
            auto x2 = &Oplayer1Walking.at(0);
            if(gRosto < 254){
                x->setColor(rRosto, ++gRosto, bRosto, 255);
                x2->setColor(rRosto, ++gRosto, bRosto, 255);
            }
        }
        if(changeColor == 1){
            auto x = &Oplayer1.at(1);
            auto x3 = &Oplayer1.at(2);
            auto x4 = &Oplayer1.at(3);
            auto x2 = &Oplayer1Walking.at(1);
            auto x5 = &Oplayer1Walking.at(2);
            auto x6 = &Oplayer1Walking.at(3);
            if(gCabelo < 250){
                x->setColor(rCabelo, ++gCabelo, bCabelo, 255);
                x2->setColor(rCabelo, ++gCabelo, bCabelo, 255);
                x3->setColor(rCabelo, ++gCabelo, bCabelo, 255);
                x4->setColor(rCabelo, ++gCabelo, bCabelo, 255);
                x5->setColor(rCabelo, ++gCabelo, bCabelo, 255);
                x6->setColor(rCabelo, ++gCabelo, bCabelo, 255);
            }
        }
        if(changeColor == 2){
            auto x = &Oplayer1.at(4);
            auto x6 = &Oplayer1Walking.at(4);
            if(gCamisa < 253){
                x->setColor(rCamisa, ++gCamisa, bCamisa, 255);
                x6->setColor(rCamisa, ++gCamisa, bCamisa, 255);
            }
        }
    }
}

void MainMenu::setDownBlue(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){
        if(changeColor == 0){
            auto x = &Oplayer1.at(0);
            auto x2 = &Oplayer1Walking.at(0);
            if(bRosto > 1){
                x->setColor(rRosto, gRosto, --bRosto, 255);
                x2->setColor(rRosto, gRosto, --bRosto, 255);
            }
        }
        if(changeColor == 1){
            auto x = &Oplayer1.at(1);
            auto x3 = &Oplayer1.at(2);
            auto x4 = &Oplayer1.at(3);
            auto x2 = &Oplayer1Walking.at(1);
            auto x5 = &Oplayer1Walking.at(2);
            auto x6 = &Oplayer1Walking.at(3);
            if(bCabelo > 3){
                x->setColor(rCabelo, gCabelo, --bCabelo, 255);
                x2->setColor(rCabelo, gCabelo, --bCabelo, 255);
                x3->setColor(rCabelo, gCabelo, --bCabelo, 255);
                x4->setColor(rCabelo, gCabelo, --bCabelo, 255);
                x5->setColor(rCabelo, gCabelo, --bCabelo, 255);
                x6->setColor(rCabelo, gCabelo, --bCabelo, 255);
            }
        }
        if(changeColor == 2){
            auto x = &Oplayer1.at(4);
            auto x6 = &Oplayer1Walking.at(4);
            if(bCamisa > 3){
                x->setColor(rCamisa, gCamisa, --bCamisa, 255);
                x6->setColor(rCamisa, gCamisa, --bCamisa, 255);
            }
        }
    }
}

void MainMenu::setUpBlue(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){
        if(changeColor == 0){
            auto x = &Oplayer1.at(0);
            auto x2 = &Oplayer1Walking.at(0);
            if(bRosto < 254){
                x->setColor(rRosto, gRosto, ++bRosto, 255);
                x2->setColor(rRosto, gRosto, ++bRosto, 255);
            }
        }
        if(changeColor == 1){
            auto x = &Oplayer1.at(1);
            auto x3 = &Oplayer1.at(2);
            auto x4 = &Oplayer1.at(3);
            auto x2 = &Oplayer1Walking.at(1);
            auto x5 = &Oplayer1Walking.at(2);
            auto x6 = &Oplayer1Walking.at(3);
            if(bCabelo < 250){
                x->setColor(rCabelo, gCabelo, ++bCabelo, 255);
                x2->setColor(rCabelo, gCabelo, ++bCabelo, 255);
                x3->setColor(rCabelo, gCabelo, ++bCabelo, 255);
                x4->setColor(rCabelo, gCabelo, ++bCabelo, 255);
                x5->setColor(rCabelo, gCabelo, ++bCabelo, 255);
                x6->setColor(rCabelo, gCabelo, ++bCabelo, 255);
            }
        }
        if(changeColor == 2){
            auto x = &Oplayer1.at(4);
            auto x6 = &Oplayer1Walking.at(4);
            if(bCamisa < 253){
                x->setColor(rCamisa, gCamisa, ++bCamisa, 255);
                x6->setColor(rCamisa, gCamisa, ++bCamisa, 255);
            }
        }
    }
}

void MainMenu::getPositionScroll(){
    if(changeColor == 0){
        barraMenuChooseColor.setPosition(260, 205 - (rRosto/2.7));
        barraMenuChooseColor2.setPosition(300, 205 - (gRosto/2.7));
        barraMenuChooseColor3.setPosition(340, 205 - (bRosto/2.7));
    }
    if(changeColor == 1){
        barraMenuChooseColor.setPosition(260, 205 - (rCabelo/2.7));
        barraMenuChooseColor2.setPosition(300, 205 - (gCabelo/2.7));
        barraMenuChooseColor3.setPosition(340, 205 - (bCabelo/2.7));
    }
    if(changeColor == 2){
        barraMenuChooseColor.setPosition(260, 205 - (rCamisa/2.7));
        barraMenuChooseColor2.setPosition(300, 205 - (gCamisa/2.7));
        barraMenuChooseColor3.setPosition(340, 205 - (bCamisa/2.7));
    }
    if(changeColor == 3){
        barraMenuChooseColor.setPosition(260, 205 - (rCalca/2.7));
        barraMenuChooseColor2.setPosition(300, 205 - (gCalca/2.7));
        barraMenuChooseColor3.setPosition(340, 205 - (bCalca/2.7));
    }
    if(changeColor == 4){
        barraMenuChooseColor.setPosition(260, 205 - (rSapato/2.7));
        barraMenuChooseColor2.setPosition(300, 205 - (gSapato/2.7));
        barraMenuChooseColor3.setPosition(340, 205 - (bSapato/2.7));
    }
}

void MainMenu::setStringChooseColor(){
    if(changeColor == 0 )
        TchooseColorCurrent->setString("Skin");
    if(changeColor == 1 )
        TchooseColorCurrent->setString("Hair");
    if(changeColor == 2)
        TchooseColorCurrent->setString("Shirt");
    if(changeColor == 3)
        TchooseColorCurrent->setString("Pants");
    if(changeColor == 4)
        TchooseColorCurrent->setString("Shoes");
}
