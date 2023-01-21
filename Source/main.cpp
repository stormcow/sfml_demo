#include "../Header/Game.h"

int main() {

  Game game;
  while (game.isWindowOpen()) {
    game.update();
    game.render();
  }
}
