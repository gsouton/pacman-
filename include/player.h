#pragma once
#include "entity.h"
#include "types.h"

class Player: Entity {
    public:
        Player(World& world);
        bool is_alive();
        void update() override;

    private:
        u32 m_lives;
};
