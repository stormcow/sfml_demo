#include "../Header/Level.h"
#include <iostream>
Level::Level(sf::Vector2i mapLocation) : mapLocation(mapLocation) {
  this->initFileName();
  this->initLoader();
  this->initFloor();
  this->initTile();
};

void Level::initLoader() { this->loader = new Loader(this->fileName); }

void Level::initFileName() {
  this->fileName = std::to_string(this->mapLocation.x) + '_' +
                   std::to_string(this->mapLocation.y) + ".map";
}

void Level::initTile() {
  delete (this->tile);
  for (size_t i = 0; i < this->loader->getTable().size(); i++) {
    for (size_t j = 0; j < this->loader->getTable().at(i).size(); j++) {
      this->tile = new Tile(this->loader->getTable().at(i).at(j));
      this->floor->tiles.at(i).at(j) = *this->tile;
    }
  }
}

void Level::initFloor() {
  delete (this->tile);
  this->tile = new Tile('0');
  this->floor = new Floor(*this->tile);
  // delete (this->tile);
}

void Level::debug() {
  for (auto &sentence : this->loader->getTable()) {
    std::cout << sentence << '\n';
  }
}
Level::~Level() {
  delete (this->tile);
  delete (this->floor);
  delete (this->loader);
}
