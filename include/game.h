#pragma once
#include "player.h"
#include "screen.h"
#include "world.h"

#include "spdlog/spdlog.h"
#include <cstdio>
#include <iostream>
#include <iterator>
#include <stdio.h>
#include <unistd.h>

class Game {
  public:
    Game();
    ~Game();
    void run();
    bool game_over();

  private:
    World m_world;
    Player m_player;
    Screen m_screen;
    Entity *m_entities;

  private:
    void render();
    void update();
    void clear();
};
