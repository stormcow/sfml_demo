#include "../Header/Game.h"
#include <iostream>

Game::Game() {
  this->initWindow();
  this->initLevel();
}

void Game::initWindow() {
  this->videomode.height = 768;
  this->videomode.width = 1024;

  this->window = new sf::RenderWindow(videomode, "Final",
                                      sf::Style::Titlebar | sf::Style::Close);
  this->window->setFramerateLimit(30);
}

void Game::initLevel() {
  // this->level.reset(new Level(this->map.getPlayerLocation()));
  this->level = new Level(this->map.getPlayerLocation());
  this->map.changeToFalse();
}

void Game::update() {
  /*if (this->player->getShape().getPosition().x < 105) {
    this->map.updatePosition('w');
    this->player->setPosition('w');
  } else if (this->player->getShape().getPosition().x > 880) {
    this->map.updatePosition('e');
    this->player->setPosition('e');
  } else if (this->player->getShape().getPosition().y > 620) {
    this->map.updatePosition('s');
    this->player->setPosition('s');
  } else if (this->player->getShape().getPosition().y < 110) {
    this->map.updatePosition('n');
    this->player->setPosition('n');
  }*/
  while (this->window->pollEvent(this->event)) {
    if (this->event.type == sf::Event::Closed) {
      this->window->close();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
      player->setVelocity('a');
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
      player->setVelocity('s');
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
      player->setVelocity('d');
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
      player->setVelocity('w');
    else
      this->player->setVelocity(' ');
  }
  this->player->move();
}
// this->debug();

void Game::renderLevel() {
  char direction{};
  if (this->map.returnChanged()) {
    delete (this->level);
    this->initLevel();
  }
  sf::RectangleShape shape = this->level->getFloor().base.getShape();
  this->window->draw(shape);

  for (size_t i = 0; i < this->level->getFloor().tiles.size(); i++) {
    for (size_t j = 0; j < this->level->getFloor().tiles.at(i).size(); j++) {
      if (this->level->getFloor().tiles.at(i).at(j).getName() == "null")
        continue;
      else if (this->level->getFloor().tiles.at(i).at(j).getName() ==
               "DoorLeft") {
        shape = this->level->getFloor().tiles.at(i).at(j).getShape();
        shape.setPosition(sf::Vector2f(-3, 315));
      } else if (this->level->getFloor().tiles.at(i).at(j).getName() ==
                 "DoorRight") {
        shape = this->level->getFloor().tiles.at(i).at(j).getShape();
        shape.setPosition(sf::Vector2f(917, 315));
      } else if (this->level->getFloor().tiles.at(i).at(j).getName() ==
                 "DoorUp") {
        shape = this->level->getFloor().tiles.at(i).at(j).getShape();
        shape.setPosition(sf::Vector2f(443, 7));
      } else if (this->level->getFloor().tiles.at(i).at(j).getName() ==
                 "DoorDown") {
        shape = this->level->getFloor().tiles.at(i).at(j).getShape();
        shape.setPosition(sf::Vector2f(443, 650));
      }

      else {
        int x = (68 * (j - 1));
        int y = (77 * (i - 1));
        shape = this->level->getFloor().tiles.at(i).at(j).getShape();
        shape.setPosition(this->level->getFloor()
                                  .tiles.at(i)
                                  .at(j)
                                  .getShape()
                                  .getPosition()
                                  .x +
                              x,
                          this->level->getFloor()
                                  .tiles.at(i)
                                  .at(j)
                                  .getShape()
                                  .getPosition()
                                  .y +
                              y);
      }
      /*shape.setOutlineColor(sf::Color::Red);
      shape.setOutlineThickness(1.f);*/
      this->window->draw(shape);
      direction = this->player->collision(
          &this->level->getFloor().tiles.at(i).at(j), &shape);
      this->map.updatePosition(direction);
      this->player->setPosition(direction);
    }
  }

  this->window->draw(this->player->getShape());
}

void Game::render() {
  this->window->clear(sf::Color::Black);
  this->renderLevel();
  this->window->display();

  // this->level->getFloor().tiles.clear();
  //  delete (this->level);
}

void Game::debug() {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !this->keyPressed) {
    std::cout << keyPressed << '\n';
    this->keyPressed = true;
    this->map.debug();
  } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    this->keyPressed = false;
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !this->keyPressed) {
    this->map.updatePosition('w');
    this->keyPressed = true;
    //  this->initLevel();
  } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) && !this->keyPressed) {
    this->map.updatePosition('e');
    this->keyPressed = true;
    // this->initLevel();
  } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !this->keyPressed) {
    this->map.updatePosition('s');
    this->keyPressed = true;
    // this->initLevel();
  } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::N) && !this->keyPressed) {
    this->map.updatePosition('n');
    this->keyPressed = true;
    // this->initLevel();
  } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && !this->keyPressed) {
    this->level->debug();
    this->keyPressed = true;
  }
}
