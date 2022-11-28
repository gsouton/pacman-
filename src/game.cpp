#include "game.h"

Game::Game()
    : m_world(World("assets/map.txt")), m_player(Player(m_world)), m_screen(m_world) {}
Game::~Game() {}

void Game::run() {
    spdlog::info("Start game...");
    while(m_screen.is_open() && !game_over() && m_player.is_alive()){
        //update the game state, players and enemy
        update();
        // render on screen
        m_screen.update();
    }
}

// returns true if game_over()
bool Game::game_over() { return !m_world.has_food(); }

void Game::update(){
    m_player.update();
}
