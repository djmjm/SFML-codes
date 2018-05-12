#include "pixel.h"

pixel::pixel(){
    srand(time(NULL));
    xDir = (rand() % 20) - 10;
    yDir = (rand() % 20) - 10;
    move = false;
    pixels = new pix;
    shape = new sf::RectangleShape;
}

pixel::pixel(int red, int green, int blue, int alpha, sf::Vector2f pos, sf::Vector2i size){
    move = false;
    pixels = new pix;
    shape = new sf::RectangleShape;
    xDir = pos.x;
    yDir = pos.y;
    setColor(red, green, blue, alpha);
    setSize(size.x, size.y);
    setPosition(pos.x, pos.y);
}

pixel::pixel(const pixel &that){
    move = false;
    pixels = new pix;
    shape = new sf::RectangleShape;
    this->pixels->blue = that.pixels->blue;
    this->pixels->red = that.pixels->red;
    this->pixels->green = that.pixels->green;
    this->pixels->alpha = that.pixels->alpha;
    this->shape->setFillColor(sf::Color(this->pixels->red, this->pixels->green, this->pixels->blue, this->pixels->alpha));
    this->height = that.height;
    this->width = that.width;
    shape->setSize(sf::Vector2f(this->width, this->height));
    this->x = that.x;
    this->y = that.y;
    shape->setPosition(this->x, this->y);
}

pixel::~pixel(){
    delete pixels;
    delete shape;
}

void pixel::setColor(int red, int green, int blue, int alpha){
    pixels->blue = blue;
    pixels->green = green;
    pixels->red = red;
    pixels->alpha = alpha;
    shape->setFillColor(sf::Color(pixels->red, pixels->green, pixels->blue, alpha));
}

void pixel::setSize(int width, int height){
    shape->setSize(sf::Vector2f(width, height));
    this->height = height;
    this->width = width;
}

void pixel::setPosition(int x, int y){
    this->x = x;
    this->y = y;
    shape->setPosition(x, y);
}

void pixel::show(sf::RenderWindow &window){
    window.draw(*shape);
    
    runMove();
}

void pixel::sumPosition(int x, int y){
    setPosition(this->x + x, this->y + y);
}

void pixel::setMove(bool move){
    this->move = move;
}

void pixel::runMove(){
    if(move){
        sumPosition(xDir, yDir);
    }
}

void pixel::setDir(int xDir, int yDir){
    this->xDir = xDir;
    this->yDir = yDir;
}

void pixel::describe(){
    std::cout << pixels->alpha << " " << pixels->blue << " " << pixels->red << " " << pixels->green << "\n";
}
