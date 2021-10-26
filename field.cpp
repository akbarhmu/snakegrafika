#include "field.hpp"
#include "painter.hpp"
#include <cstdlib>
#include <cstdio>

Field::Field() {

  for (int y = 0; y < HEIGHT; ++y)
    for (int x = 0; x < WIDTH; ++x)
      m_[y][x] = EMPTY; 
  newBricks();
  newFruit();
  num_snake_block = 1;

}

void Field::setBlock(Type type, int x, int y) 
{
  m_[y][x] = type;
}

Field::Type Field::block(int x, int y) const	
{
  return m_[y][x];
}
void Field::draw(Painter & p) const {
  num_snake_block = 0;
  for (int y = 0; y < HEIGHT; ++y)
    for (int x = 0; x < WIDTH; ++x) {
      switch (m_[y][x]) {
      case EMPTY: 
        break;
      case SNAKE_BLOCK:
        p.bar(x * BLOCK_WIDTH, y * BLOCK_HEIGHT, (x + 1) * BLOCK_WIDTH - 1, (y + 1) * BLOCK_HEIGHT - 1); 
        num_snake_block++;
        break;
      case FRUIT:
        p.circle(x * BLOCK_WIDTH + BLOCK_WIDTH / 2, y * BLOCK_HEIGHT + BLOCK_HEIGHT / 2, BLOCK_WIDTH / 2 - 1); 
        ;
        break;
      case BRICK_BLOCK:
        p.brick_bar(x * BLOCK_WIDTH, y * BLOCK_HEIGHT, (x + 1) * BLOCK_WIDTH - 1, (y + 1) * BLOCK_HEIGHT - 1);
        break;
      }
    }
}

void Field::newBricks() {
  int x = 2;

  setBlock(BRICK_BLOCK, x + 4, HEIGHT - 3 - 10);
  setBlock(BRICK_BLOCK, x + 4, HEIGHT - 3 - 8);
  setBlock(BRICK_BLOCK, x + 4, HEIGHT - 3 - 9);
  setBlock(BRICK_BLOCK, x + 4, HEIGHT - 3 - 12);
  setBlock(BRICK_BLOCK, x + 4, HEIGHT - 3 - 13);
  setBlock(BRICK_BLOCK, x + 4, HEIGHT - 3 - 11);
  setBlock(BRICK_BLOCK, x + 5, HEIGHT - 3 - 15);
  setBlock(BRICK_BLOCK, x + 6, HEIGHT - 3 - 15);
  setBlock(BRICK_BLOCK, x + 4, HEIGHT - 3 - 14);
  setBlock(BRICK_BLOCK, x + 4, HEIGHT - 3 - 15);
  setBlock(BRICK_BLOCK, x + 4, HEIGHT - 3 - 7);
  setBlock(BRICK_BLOCK, x + 4, HEIGHT - 3 - 6);
  setBlock(BRICK_BLOCK, x + 5, HEIGHT - 3 - 6);
  setBlock(BRICK_BLOCK, x + 6, HEIGHT - 3 - 6);
  setBlock(BRICK_BLOCK, x + 7, HEIGHT - 3 - 6);
  setBlock(BRICK_BLOCK, x + 8, HEIGHT - 3 - 6);
  setBlock(BRICK_BLOCK, x + 9, HEIGHT - 3 - 6);
  setBlock(BRICK_BLOCK, x + 10, HEIGHT - 3 - 6);
  setBlock(BRICK_BLOCK, x + 11, HEIGHT - 3 - 6);
  setBlock(BRICK_BLOCK, x + 12, HEIGHT - 3 - 6);
  setBlock(BRICK_BLOCK, x + 13, HEIGHT - 3 - 6);
  setBlock(BRICK_BLOCK, x + 14, HEIGHT - 3 - 6);
  setBlock(BRICK_BLOCK, x + 15, HEIGHT - 3 - 6);
  setBlock(BRICK_BLOCK, x + 15, HEIGHT - 3 - 7);
  setBlock(BRICK_BLOCK, x + 15, HEIGHT - 3 - 8);
  setBlock(BRICK_BLOCK, x + 15, HEIGHT - 3 - 9);
  setBlock(BRICK_BLOCK, x + 15, HEIGHT - 3 - 9);
  setBlock(BRICK_BLOCK, x + 15, HEIGHT - 3 - 10);
  setBlock(BRICK_BLOCK, x + 15, HEIGHT - 3 - 11);
  setBlock(BRICK_BLOCK, x + 15, HEIGHT - 3 - 12);
  setBlock(BRICK_BLOCK, x + 15, HEIGHT - 3 - 13);
  setBlock(BRICK_BLOCK, x + 15, HEIGHT - 3 - 14);
  setBlock(BRICK_BLOCK, x + 15, HEIGHT - 3 - 15);
  setBlock(BRICK_BLOCK, x + 14, HEIGHT - 3 - 15);
  setBlock(BRICK_BLOCK, x + 13, HEIGHT - 3 - 15);
}

void Field::levelWorm() {

  setBlock(BRICK_BLOCK, 2, 2);
  setBlock(BRICK_BLOCK, 3, 2);
  setBlock(BRICK_BLOCK, 2, 3);
  setBlock(BRICK_BLOCK, 3, 3);
  setBlock(BRICK_BLOCK, 21, 21);
  setBlock(BRICK_BLOCK, 21, 22);
  setBlock(BRICK_BLOCK, 22, 21);
  setBlock(BRICK_BLOCK, 22, 22);

}

void Field::levelKobra() {

  setBlock(BRICK_BLOCK, 21, 2);
  setBlock(BRICK_BLOCK, 21, 3);
  setBlock(BRICK_BLOCK, 22, 2);
  setBlock(BRICK_BLOCK, 22, 3);
  setBlock(BRICK_BLOCK, 2, 21);
  setBlock(BRICK_BLOCK, 2, 22);
  setBlock(BRICK_BLOCK, 3, 21);
  setBlock(BRICK_BLOCK, 3, 22);

}

void Field::newFruit() 
{
  int x;
  int y;

  do {
    x = rand() % WIDTH;
    y = rand() % HEIGHT;
  } while (block(x, y) != EMPTY);
  setBlock(FRUIT, x, y);

}