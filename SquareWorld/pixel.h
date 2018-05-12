#ifndef pixel_h
#define pixel_h
#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>

typedef struct pix pix;

struct pix{
    int red, green, blue, alpha;
};

class pixel{
    public:
        pixel();
        pixel(int red, int green, int blue, int alpha, sf::Vector2f pos, sf::Vector2i size);
        pixel(const pixel&);
        ~pixel();
        
        
        
        //seting pixels
        void setColor(int red, int green, int blue, int alpha);
        void setSize(int width, int height);
        void setPosition(int x, int y);
        void setMove(bool move);
        void runMove();
        void setDir(int xDir, int yDir);
        
        void sumPosition(int x, int y);
        
        //show
        void show(sf::RenderWindow &window);
        void describe();
        
    private:
        pix *pixels;
        sf::RectangleShape *shape;
        int width, height, x, y, xDir, yDir;
        bool move;
        
        
};

//void operator =(pixel &aim, pixel &source);

#endif