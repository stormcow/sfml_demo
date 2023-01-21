#pragma once
#include "Level.h"
#include "Map.h"
#include "Player.h"
#include "SFML/Graphics.hpp"
#include <memory>
class Game {
private:
  sf::RenderWindow *window;
  sf::VideoMode videomode;
  sf::Event event;
  // std::unique_ptr<Player> player = std::make_unique<Player>(new Player());
  Player *player = new Player();
  Map map = Map();
  // std::unique_ptr<Level> level =
  //   std::make_unique<Level>(new Level(this->map.getPlayerLocation()));
  Level *level;
  bool keyPressed{};
  bool isLevelLoaded{};
  void initWindow();
  void debug();
  void initLevel();
  void renderLevel();

public:
  Game();
  bool const isWindowOpen() { return this->window->isOpen(); }
  void render();
  void update();
};
