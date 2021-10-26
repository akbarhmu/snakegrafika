#pragma once

class Painter;

class Field {
  public:
    enum {
      WIDTH = 25, HEIGHT = 25
    };
  enum {
    BLOCK_WIDTH = 8, BLOCK_HEIGHT = 8
  };
  enum Type {
    EMPTY,
    SNAKE_BLOCK,
    FRUIT,
    BRICK_BLOCK
  };
  //enum Level {SLUG, WORM, KOBRA};
  Field();
  void setBlock(Type type, int x, int y);
  Type block(int x, int y) const;

  void draw(Painter & ) const;
  void newFruit();
  void levelWorm();
  void levelKobra();
  void newBricks();
  mutable int num_snake_block;
  private:
    Type m_[HEIGHT][WIDTH]; //Array for each field location
};