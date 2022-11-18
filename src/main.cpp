#include <iostream>
#include "game.h"
#include "spdlog/common.h"
#include "spdlog/spdlog.h"

int main(int argc, char *argv[]) { 
    spdlog::set_level(spdlog::level::debug);
    Game game = Game();
    game.run();
    return 0; 
}
