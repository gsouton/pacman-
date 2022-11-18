#include "player.h"
#include "spdlog/spdlog.h"
#include "types.h"

const static u32 default_number_lives = 3;
const static Direction default_direction = WEST;
const static Position default_position = Position(0, 0);

Player::Player()
    : m_lives(default_number_lives), m_direction(default_direction),
      m_position(default_position) {
    spdlog::info("Creating Player...");
}

bool Player::is_alive(){
    return m_lives > 0;
}
