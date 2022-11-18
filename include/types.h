#pragma once

typedef unsigned u32;
typedef int i32;

typedef struct Position {
    Position(u32 x, u32 y): x(x), y(y) {}
    u32 x;
    u32 y;
}Position;
