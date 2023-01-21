#pragma once
#include "SFML/Graphics.hpp"
#include "Tile.h"
#include <string>
class Entity {
private:
  std::string name{};
  unsigned int health{};
  sf::RectangleShape shape{};

public:
  virtual sf::FloatRect getBoundingBox() {
    return this->shape.getGlobalBounds();
  }
  virtual std::string const getName() { return this->name; };
  virtual void move(){};
  virtual void attack(){};
  virtual sf::RectangleShape const getShape() { return this->shape; };
  virtual unsigned int const getHealth() { return this->health; };
  virtual void animation(){};
};
