#pragma once

typedef unsigned u32;
typedef int i32;

enum Direction { NORTH, SOUTH, EAST, WEST };

typedef struct Position {
    Position(u32 x, u32 y) : x(x), y(y) {}
    u32 x;
    u32 y;

    void set(u32 x, u32 y) {
        this->x = x;
        this->y = y;
    }
    void set(Position pos) { set(pos.x, pos.y); }

    void left() { this->x += -1; }

    void right() { this->x += 1; }

    void up() { this->y += 1; }

    void down() { this->y -= 1; }

    void move(Direction dir) {
        switch (dir) {
        case NORTH:
            this->up();
            break;
        case SOUTH:
            this->down();
            break;
        case WEST:
            this->left();
            break;
        case EAST:
            this->left();
            break;
        default:
            break;
        }
    }
    Position next(Direction dir){
        Position position = Position(*this); 
        position.move(dir);
        return position;
    }

} Position;

typedef struct Color {
    char r, g, b, a;
    Color(char r, char g, char b, char a) : r(r), g(g), b(b), a(a) {}
    Color(char r, char g, char b) : r(r), g(g), b(b), a(0x00) {}
} Color;

const Color black = Color(0, 0, 0);
const Color cyan = Color(0x00, 0xFF, 0xFF);
const Color yellow = Color(0xFA, 0xFF, 0x00);
const Color green = Color(0x49, 0xDE, 0xB2);
const Color blue = Color(0x01, 0xFF, 0xFF);
const Color pink = Color(0xFF, 0x43, 0xFA);
const Color purple = Color(0x9D, 0x72, 0xFF);
const Color dark_blue = Color(0x0C, 0x0B, 0x27);
const Color white = Color(0xFF, 0xFF, 0xFF);
const Color background = black;
