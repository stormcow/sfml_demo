#include "../Header/Tile.h"

Tile::Tile(char type) : type(type) {
  this->initTile(type);
  this->initShape();
}

void Tile::initTile(char type) {

  switch (type) {
  case '0':
    this->setBase();
    break;
  case 'b':
    this->setSquare();
    break;
  case 's':
    this->setStairs();
    break;
  case 'w':
    this->setWater();
    break;
  case 'p':
    this->setPuddle();
    break;
  case 'd':
    this->setBlueDragon();
    break;
  case 'D':
    this->setBlackDragon();
    break;
  case 'z':
    this->setBlueFrog();
    break;
  case 'Z':
    this->setBlackFrog();
    break;
  case 'n':
    this->setEmpty();
    break;
  case 'o':
    this->setFloorpane();
    break;
  case 'N':
    this->setDoorNorth();
    break;
  case 'S':
    this->setDoorSouth();
    break;
  case 'E':
    this->setDoorEast();
    break;
  case 'W':
    this->setDoorWest();
    break;
  default:
    this->name = "null";
    break;
  }
}

// void Tile::setSquare() {
//   /* this->square.loadFromFile("../../../Textures/Square.png");*/
//
//   this->tile.setTexture(&this->textures.squareTexture());
// }
// void Tile::setBase() {
//   // this->base.loadFromFile("../../../Textures/Default_floor.png");
//   this->tile.setTexture(&this->textures.baseTexture());
// }
// void Tile::setBlueDragon() {
//   /* this->blueDragon.loadFromFile("../../../Textures/Blue_dragon.png");*/
//   this->tile.setTexture(&this->textures.blueDragonTexture());
// }
// void Tile::setBlueFrog() {
//   /* this->blueFrog.loadFromFile("../../../Textures/Blue_frog.png");*/
//   this->tile.setTexture(&this->textures.blueFrogTexture());
// }
// void Tile::setBlackFrog() {
//   // this->blackFrog.loadFromFile("../../../Textures/Black_frog.png");
//   this->tile.setTexture(&this->textures.blackFrogTexture());
// }
// void Tile::setPuddle() {
//   /* this->puddle.loadFromFile("../../../Textures/Puddle.png");*/
//   this->tile.setTexture(&this->textures.puddleTexture());
// }
// void Tile::setWater() {
//   // this->water.loadFromFile("../../../Textures/Water.png");
//   this->tile.setTexture(&this->textures.waterTexture());
// }
// void Tile::setEmpty() {
//   /*this->empty.loadFromFile("../../../Textures/Empty.png");*/
//   this->tile.setTexture(&this->textures.emptyTexture());
// }
// void Tile::setStairs() {
//   // this->stairs.loadFromFile("../../../Textures/Stairs.png");
//   this->tile.setTexture(&this->textures.stairsTexture());
// }
// void Tile::setFloorpane() { this->tile.setFillColor(sf::Color(0, 0, 0, 0)); }
// void Tile::setBlackDragon() {
//   /*this->blackDragon.loadFromFile("../../../Textures/Black_dragon.png");*/
//   this->tile.setTexture(&this->textures.blackDragonTexture());
// }
void Tile::setDoorEast() {
  this->txtrptr->loadFromFile("../../../Textures/Door_right.png");
  this->canPass = true;
  this->name = "DoorRight";
}
void Tile::setDoorNorth() {
  this->txtrptr->loadFromFile("../../../Textures/Door_up.png");
  this->canPass = true;
  this->name = "DoorUp";
}
void Tile::setDoorSouth() {
  this->txtrptr->loadFromFile("../../../Textures/Door_down.png");
  this->canPass = true;
  this->name = "DoorDown";
}
void Tile::setDoorWest() {
  this->txtrptr->loadFromFile("../../../Textures/Door_left.png");
  this->canPass = true;
  this->name = "DoorLeft";
}

void Tile::setSquare() {
  this->txtrptr->loadFromFile("../../../Textures/Square.png");
  this->canPass = false;
  this->name = "Square";
}
void Tile::setFloorpane() {
  this->txtrptr->loadFromFile("../../../Textures/Floorpane.png");
  this->canPass = true;
  this->name = "Floorpane";
}
void Tile::setBase() {
  this->txtrptr->loadFromFile("../../../Textures/Default_floor.png");
  // this->tile.setSize(sf::Vector2f(800, 600));
  this->canPass = true;
  this->name = "Base";
}

void Tile::setStairs() {
  this->txtrptr->loadFromFile("../../../Textures/Stairs.png");
  this->canPass = false;
  this->name = "Stairs";
}

void Tile::setWater() {
  this->txtrptr->loadFromFile("../../../Textures/Water.png");
  this->canPass = false;
  this->name = "Water";
}

void Tile::setPuddle() {
  this->txtrptr->loadFromFile("../../../Textures/Puddle.png");
  this->canPass = true;
  this->name = "Puddle";
}

void Tile::setBlueDragon() {
  this->txtrptr->loadFromFile("../../../Textures/Blue_dragon.png");
  this->canPass = false;
  this->name = "BlueDragon";
}

void Tile::setBlackDragon() {
  this->txtrptr->loadFromFile("../../../Textures/Black_dragon.png");
  this->canPass = false;
  this->name = "BlackDragon";
}

void Tile::setBlueFrog() {
  this->txtrptr->loadFromFile("../../../Textures/Blue_frog.png");
  this->canPass = false;
  this->name = "BlueFrog";
}

void Tile::setBlackFrog() {
  this->txtrptr->loadFromFile("../../../Textures/Black_frog.png");
  this->canPass = false;
  this->name = "BlackFrog";
}

void Tile::setEmpty() {
  this->txtrptr->loadFromFile("../../../Textures/Empty.png");
  this->canPass = true;
  this->name = "Empty";
}
void Tile::initShape() {
  if (this->type == '0')
    this->tile.setSize(sf::Vector2f(1024, 768));
  else if (this->type == 'W' || this->type == 'E')
    this->tile.setSize(sf::Vector2f(110.f, 135.f));
  else if (this->type == 'N' || this->type == 'S')
    this->tile.setSize(sf::Vector2f(135.f, 110.f));
  else {
    this->tile.setSize(sf::Vector2f(68.f, 77.f));
    this->tile.setPosition(sf::Vector2f(105.f, 115.f));
  }
  this->tile.setTexture(this->txtrptr.get());
}

// Tile::~Tile() { delete (this->texture); }
