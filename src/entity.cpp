#include "entity.h"

Entity::Entity(World &world)
    : m_direction(NORTH), m_position(Position(0, 0)), m_world(world) {}

Direction Entity::direction() { return m_direction; }

void Entity::direction(Direction dir) { m_direction = dir; }

void Entity::update() {}
