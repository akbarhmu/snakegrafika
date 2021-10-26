#pragma once
#include "snake.hpp"
#include "field.hpp"

class Painter;

class Game {
    public:
        int tick();
        void draw(Painter & ) const;
        void keyEvent(Snake::Direction);
        void cons();
        int nb();
        void setlevel1();
        void setlevel2();

    private:
        Field field_;
        Snake snake_;
};