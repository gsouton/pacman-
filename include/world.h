#pragma once
#include "map.h"
#include "types.h"

class World {
  public:
    World(const char *pathname);
    bool has_food();
    bool is_position_walkable(const Position& position);
    bool valid_position(const Position& position);
    u32 width() const;
    u32 height() const;
    MAP_SLOT at(u32 x, u32 y);
    void update_position(Position position, MAP_SLOT slot);
    

  private:
    Map m_map;

  private:
    void load_map_from_file(const char *pathname);
    void set(u32 x, u32 y);
};
