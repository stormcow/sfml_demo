#pragma once
#include "Entity.h"

class Player {
private:
  unsigned int health{};
  unsigned int animation{1};
  char direction{'w'};
  char blockedDirection{};
  std::string name{};
  sf::Texture texture{};
  sf::RectangleShape shape{};
  sf::Vector2f velocity{};
  sf::Vector2f oldPos{};
  void changePosition();
  void move_animation();
  void changeTexture(char &direction);

public:
  sf::FloatRect getBoundingBox() { return this->shape.getGlobalBounds(); };
  char collision(Tile *object, sf::RectangleShape *pos);
  Player();
  void move();
  void setVelocity(char direction);
  void attack(char direction);
  sf::RectangleShape const getShape() { return this->shape; };
  void setPosition(char direction);
};
