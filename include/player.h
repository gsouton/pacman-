#pragma once
#include "types.h"

enum Direction {
    NORTH,
    SOUTH,
    EAST,
    WEST
};

class Player {
    public:
        Player();
        bool is_alive();

    private:
        u32 m_lives;
        Direction m_direction;
        Position m_position;
};
