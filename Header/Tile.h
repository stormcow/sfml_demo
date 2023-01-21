#pragma once

#include "SFML/Graphics.hpp"
#include <memory>
#include <string>

/*
o - floorpan - canPass
b - square - !canPass
s - stairs - !canPass
w - water - !canPass
p - puddle - canPass
d - blue dragon - !canPass
D - black dragon - !canPass
z - blue frog - !canPass
Z - black frog - !canPass
n - empty - canPass
N - north door
W - west door
E - east door
S - south door
*/

class Tile {
private:
  sf::RectangleShape tile;
  bool canPass{};
  char type{};
  std::string name{};
  //   sf::Texture *texture = new sf::Texture;
  /* sf::Texture texture = sf::Texture();*/
  std::shared_ptr<sf::Texture> txtrptr =
      std::make_shared<sf::Texture>(sf::Texture());
  void setFloorpane();
  void setSquare();
  void setStairs();
  void setWater();
  void setPuddle();
  void setBlueDragon();
  void setBlackDragon();
  void setBlueFrog();
  void setBlackFrog();
  void setEmpty();
  void setBase();
  void setDoorNorth();
  void setDoorEast();
  void setDoorSouth();
  void setDoorWest();
  void initTile(char type);
  void initShape();

public:
  //~Tile();

  sf::FloatRect getBoundingBox() { return this->tile.getGlobalBounds(); }
  bool returnPass() { return canPass; }
  sf::RectangleShape getShape() { return this->tile; }
  Tile(char type);
  std::string getName() { return name; }
  Tile(){};
};
