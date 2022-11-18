#pragma once
#include "map.h"
#include "types.h"

class World {
  public:
    World(const char *pathname);
    bool has_food();
    u32 width() const;
    u32 height() const;
    char at(u32 x, u32 y);

  private:
    Map m_map;

  private:
    void load_map_from_file(const char *pathname);
};
