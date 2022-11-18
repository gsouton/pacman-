#pragma once
#include "player.h"
#include "world.h"

class Game {
  public:
    Game();
    ~Game();
    void run();
    bool game_over();
    void render();
    void clear();

  private:
    World m_world;
    Player m_player;
};
