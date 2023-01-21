#pragma once

#include "Loader.h"
#include "SFML/Graphics.hpp"
#include "Tile.h"
#include <string>
#include <vector>

struct Floor {
  Tile base;
  std::vector<std::vector<Tile>> doors{4};
  std::vector<std::vector<Tile>> tiles =
      std::vector<std::vector<Tile>>(9, std::vector<Tile>(14, 0));
  Floor(Tile base) : base(base){};
  Floor(){};
};

class Level {
private:
  sf::Vector2i mapLocation;
  std::string fileName;
  Floor *floor;
  Loader *loader;
  Tile *tile = new Tile;

  void initFloor();
  void initLoader();
  void initFileName();
  void initTile();

public:
  Level(sf::Vector2i mapLocation);
  Floor getFloor() { return *floor; };
  void debug();

  ~Level();
};
