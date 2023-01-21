#include "../Header/Map.h"
#include <iostream>

Map::Map() { this->initMap(); }

void Map::initMap() {
  this->playerLocation = sf::Vector2i(5, 2);
  this->mapLocation = std::vector<std::vector<int>>(6, std::vector<int>(6, 0));

  this->mapLocation.at(this->playerLocation.x).at(this->playerLocation.y) = 1;
}

void const Map::updatePosition(char direction) {
  this->changeLocation(direction);
}

void Map::changeLocation(char direction) {
  sf::Vector2i new_vector{};
  this->mapLocation.at(this->playerLocation.x).at(this->playerLocation.y) = 0;

  switch (direction) {
  case 'w':
    this->playerLocation =
        sf::Vector2i(this->playerLocation.x, this->playerLocation.y - 1);
    break;
  case 'n':
    this->playerLocation =
        sf::Vector2i(this->playerLocation.x - 1, this->playerLocation.y);
    break;
  case 'e':
    this->playerLocation =
        sf::Vector2i(this->playerLocation.x, this->playerLocation.y + 1);
    break;
  case 's':
    this->playerLocation =
        sf::Vector2i(this->playerLocation.x + 1, this->playerLocation.y);
    break;
  default:
    return;
    break;
  }
  this->mapLocation.at(this->playerLocation.x).at(this->playerLocation.y) = 1;

  this->hasChanged = true;
}

void Map::debug() {
  std::cout << '-' << '\n';
  for (size_t i = 0; i < this->mapLocation.size(); i++) {
    for (size_t j = 0; j < this->mapLocation.at(i).size(); j++) {
      std::cout << this->mapLocation.at(i).at(j);
    }
    std::cout << '\n';
  }
  std::cout << '-' << '\n';
}

sf::Vector2i const Map::getPlayerLocation() { return this->playerLocation; }
