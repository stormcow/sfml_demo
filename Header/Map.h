#pragma once
#include "SFML/System/Vector2.hpp"
#include <vector>
/*
        Map is a 6x6 table. Player starts on a 6th row and 3rd column.
        Map with a player has a value 1. Other maps have values 0.
*/

class Map {
private:
  std::vector<std::vector<int>> mapLocation;
  sf::Vector2i playerLocation{};

  bool hasChanged{};
  void initMap();
  void changeLocation(char direction);

public:
  Map();

  void const updatePosition(
      char direction); // based on char move either west/north/east/south

  void debug();

  void changeToFalse() { hasChanged = false; }
  bool  returnChanged() { return this->hasChanged; }

  sf::Vector2i const getPlayerLocation();
};
