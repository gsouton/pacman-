#pragma once
#include "types.h"
#include "world.h"


class Entity {
    public:
        Entity(World& world);
        Direction direction();
        void direction(Direction direction);
        virtual void update();

    protected:
        Direction m_direction;
        Position m_position;
        World& m_world;
};
