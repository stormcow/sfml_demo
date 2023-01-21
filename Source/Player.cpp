#include "../Header/Player.h"
#include <iostream>
Player::Player() {
  this->health = 6;
  this->name = "Player";
  this->texture.loadFromFile("../../../Textures/Player_top_move_1.png");
  this->shape.setTexture(&texture);
  this->shape.setSize(sf::Vector2f(55.f, 55.f));
  this->shape.setPosition(sf::Vector2f(480.f, 600.f));
};

void Player::move() {
  if (this->blockedDirection == this->direction)
    return;
  else if (this->shape.getPosition().x < 105 ||
           this->shape.getPosition().x > 880 ||
           this->shape.getPosition().y < 110 ||
           this->shape.getPosition().y > 620) {
    this->blockedDirection = this->direction;
    // return;
  }
  this->oldPos = this->shape.getPosition();
  this->changePosition();
  if (this->oldPos != this->shape.getPosition())
    this->move_animation();
  std::cout << this->shape.getPosition().x << ' ' << this->shape.getPosition().y
            << '\n';
}
void Player::setVelocity(char direction) {
  switch (direction) {
  case 'a':
    this->velocity = sf::Vector2f(-10.f, 0.f);
    break;
  case 's':
    this->velocity = sf::Vector2f(0.f, 10.f);
    break;
  case 'd':
    this->velocity = sf::Vector2f(10.f, 0.f);
    break;
  case 'w':
    this->velocity = sf::Vector2f(0.f, -10.f);
    break;
  case ' ':
    this->velocity = sf::Vector2f(0.f, 0.f);
  default:
    break;
  }
  this->direction = direction;
  if (this->direction != this->blockedDirection)
    this->blockedDirection = ' ';
  // this->move_animation(direction);
  //  this->changeTexture(direction);
}
char Player::collision(Tile *object, sf::RectangleShape *pos) {
  if (this->getBoundingBox().intersects(pos->getGlobalBounds()) &&
      !object->returnPass()) {
    std::cout << object->getName();
    this->velocity = sf::Vector2f(0.f, 0.f);
    this->blockedDirection = this->direction;
  } else if (this->getBoundingBox().intersects(pos->getGlobalBounds()) &&
             object->getName() == "DoorLeft")
    return 'w';
  else if (this->getBoundingBox().intersects(pos->getGlobalBounds()) &&
           object->getName() == "DoorRight")
    return 'e';
  else if (this->getBoundingBox().intersects(pos->getGlobalBounds()) &&
           object->getName() == "DoorUp")
    return 'n';
  else if (this->getBoundingBox().intersects(pos->getGlobalBounds()) &&
           object->getName() == "DoorDown")
    return 's';
  /*if (this->getBoundingBox().intersects(pos->getGlobalBounds()) &&
      (object->getName))*/
};

void Player::changeTexture(char &direction) {
  switch (direction) {
  case 'a':
    this->texture.loadFromFile("../../../Textures/Player_left_move_1.png");
    break;
  case 's':
    this->texture.loadFromFile("../../../Textures/Player_down_move_1.png");
    break;
  case 'd':
    this->texture.loadFromFile("../../../Textures/Player_right_move_1.png");
    break;
  case 'w':
    this->texture.loadFromFile("../../../Textures/Player_top_move_1.png");
    break;
  default:
    break;
  }
  this->shape.setTexture(&texture);
}

void Player::changePosition() { this->shape.move(velocity); }

void Player::move_animation() {
  std::string file{};
  switch (this->direction) {
  case 'a':
    file = "../../../Textures/Player_left_move_" +
           std::to_string(this->animation) + ".png";
    this->texture.loadFromFile(file);

    break;
  case 's':
    file = "../../../Textures/Player_down_move_" +
           std::to_string(this->animation) + ".png";
    this->texture.loadFromFile(file);

    break;
  case 'd':
    file = "../../../Textures/Player_right_move_" +
           std::to_string(this->animation) + ".png";
    this->texture.loadFromFile(file);

    break;
  case 'w':
    file = "../../../Textures/Player_top_move_" +
           std::to_string(this->animation) + ".png";
    this->texture.loadFromFile(file);

    break;
  default:
    break;
  }
  this->animation++;
  if (this->animation == 3)
    this->animation = 1;
}

void Player::setPosition(char direction) {
  switch (direction) {

  case 'w':
    this->shape.setPosition(sf::Vector2f(854.f, 352.f));
    break;
  case 'n':
    this->shape.setPosition(sf::Vector2f(480.f, 590.f));
    break;
  case 's':
    this->shape.setPosition(sf::Vector2f(488.f, 120.f));
    break;
  case 'e':
    this->shape.setPosition(sf::Vector2f(110.f, 352.f));
    break;
  }
}
