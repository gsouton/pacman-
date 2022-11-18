#pragma once
#include "types.h"

enum MAP_SLOT { UNDEFINED, EMPTY, FOOD, WALL };

MAP_SLOT char_to_map_slot(char c);

class Map {
  public:
    Map();
    Map(unsigned width, unsigned height, char *char_map);
    void set(u32 width, u32 height, char *char_map);
    bool has_food();
    u32 width() const;
    u32 height() const;
    char get(u32 x, u32 y);

  private:
    u32 m_width;
    u32 m_height;
    MAP_SLOT *m_data;
    u32 m_food_amount;
};
