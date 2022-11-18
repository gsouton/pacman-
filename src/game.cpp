#include "game.h"
#include "spdlog/spdlog.h"
#include <iostream>
#include <iterator>

Game::Game() : m_world(World("assets/map.txt")), m_player(Player()) {
}
Game::~Game() {}

void Game::run() {
    spdlog::info("Start game...");
    while(!game_over() && m_player.is_alive()){
        render();
        std::cin.get();
    }
}

// returns true if game_over()
bool Game::game_over(){
    return !m_world.has_food();
}

void Game::render(){
    for(u32 y = 0; y < m_world.height(); ++y){
        for(u32 x = 0; x < m_world.width(); ++x){
            std::cout << m_world.at(x, y);
        }
        std::cout << std::endl;
    }
}

void Game::clear(){
    for(u32 y = 0; y < m_world.height(); ++y){
        std::cout << "\r";
    }
}


