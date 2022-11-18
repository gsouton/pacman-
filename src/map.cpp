#include "map.h"

Map::Map() {}

void Map::set(u32 width, u32 height, char *char_map) {
    m_food_amount = 0;
    u32 size = width * height;
    m_width = width;
    m_height = height;
    m_data = new MAP_SLOT[size];
    for (u32 i = 0; i < size; ++i) {
        m_data[i] = char_to_map_slot(char_map[i]);
        m_food_amount = m_data[i] == FOOD ? ++m_food_amount : m_food_amount;
    }
}

MAP_SLOT char_to_map_slot(char c) {
    switch (c) {
    case '#':
        return WALL;
    case ' ':
        return EMPTY;
    case '.':
        return FOOD;
    default:
        return UNDEFINED;
    }
}

char map_slot_to_char(MAP_SLOT slot){
    switch (slot) {
    case WALL:
        return '#';
    case EMPTY:
        return ' ';
    case FOOD:
        return '.';
    default:
        return '0';
    }

}

bool Map::has_food(){
    return m_food_amount > 0;
}

u32 Map::width() const {
    return m_width;
}

u32 Map::height() const {
    return m_height;
}

char Map::get(u32 x, u32 y){
    MAP_SLOT slot = m_data[y * m_width + x];
    return map_slot_to_char(slot);
}



