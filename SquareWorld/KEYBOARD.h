#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <SFML/Graphics.hpp>

class KEYBOARD
{
public:
    KEYBOARD();
    ~KEYBOARD();
    
    bool KeyboardCheckPressed();
    
    bool activeEnter, activeQ, activeW, activeR, activeE, activeT, activeY, activeU, activeI, activeO, activeP, activeA, activeS, activeD, activeF, activeG, activeH, activeJ, activeK, activeL, activeZ, activeX, activeC, activeV, activeB, activeN, activeM, activeBackspace, activeSpace, activeUp, activeDown, activeRight, activeLeft;

};

#endif // KEYBOARD_H
