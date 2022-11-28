#include "player.h"
#include "entity.h"
#include "map.h"
#include "spdlog/spdlog.h"
#include "types.h"
#include <iostream>
#include <iterator>

const static u32 default_number_lives = 3;
const static Direction default_direction = WEST;
const static Position default_position = Position(0, 0);

Player::Player(World& world) : Entity(world), m_lives(default_number_lives) {
    spdlog::info("Creating Player...");
    m_position.set(default_position);
    m_direction = default_direction;
}

bool Player::is_alive() { return m_lives > 0; }

void Player::update() {
    Position next_position = m_position.next(m_direction);
    if (m_world.is_position_walkable(next_position)){
        m_position.move(m_direction);
        m_world.updatePostion(m_position, PLAYER);
    }
}
