#include "game.hpp"
#include "painter.hpp"
#include "field.hpp"

int Game::tick() {
    if (!snake_.tick(field_)) {
        return 1;
    } else
        return 0;
}
int Game::nb() {
    return field_.num_snake_block;
}

void Game::cons() {
    snake_ = Snake();
    field_ = Field();
}

void Game::draw(Painter & p) const {
    field_.draw(p);
}

void Game::setlevel1() {
    field_.newBricks();
    field_.levelWorm();
    field_.newFruit();
}

void Game::setlevel2() {

    field_.newBricks();
    field_.levelWorm();
    field_.levelKobra();
    field_.newFruit();
}

void Game::keyEvent(Snake::Direction d) {
    snake_.keyEvent(d);
}