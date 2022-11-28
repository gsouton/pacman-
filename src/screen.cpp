#include "screen.h"
#include "SDL_rect.h"
#include "SDL_render.h"
#include "SDL_scancode.h"
#include "SDL_timer.h"
#include "map.h"
#include "spdlog/spdlog.h"
#include "types.h"

//TODO: Fix the width when reading from file in world.cpp
Screen::Screen(World &world)
    : m_running(true), m_width(1000), m_height(1000), m_sprite_size(32),
      m_world(world) {
    m_width = (m_world.width()-1) * m_sprite_size;
    m_height = m_world.height() * m_sprite_size;

    initialize();
}

Screen::~Screen() {
    spdlog::debug("Cleaning SDL...");
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}

bool Screen::is_open() { return m_running; }

void Screen::update() {
    handle_event();
    clear();
    render();
    SDL_Delay(1000 / 60);
}

void Screen::initialize() {
    // initialize SDL library
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO)) {
        spdlog::error("Could not initialize SDL, error: {}", SDL_GetError());
        exit(-1);
    }

    // initialize display (creating window)
    m_window = SDL_CreateWindow("Pacman++", SDL_WINDOWPOS_UNDEFINED,
                                SDL_WINDOWPOS_UNDEFINED, m_width, m_height,
                                SDL_WINDOW_OPENGL);
    if (m_window == nullptr) {
        spdlog::error("Could not create window, error: {}", SDL_GetError());
        exit(-1);
    }

    // create renderer to draw on screen
    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
    if (m_renderer == nullptr) {
        spdlog::error("Could not create a renderer, error: {}", SDL_GetError());
    }
}

void Screen::handle_event() {
    SDL_PollEvent(&m_event);
    switch (m_event.type) {
    case SDL_QUIT:
        spdlog::debug("Quit request!");
        m_running = false;
        break;
    case SDL_KEYDOWN:
        handle_key_event();
    }
}

void Screen::handle_key_event() {
    switch (m_event.key.keysym.scancode) {
    case SDL_SCANCODE_Q:
        spdlog::debug("Quit request!");
        m_running = false;
        break;
    case SDL_SCANCODE_UP:
        spdlog::debug("Set direction to north");
        break;
    case SDL_SCANCODE_LEFT:
        spdlog::debug("Set direction to west");
        break;
    case SDL_SCANCODE_RIGHT:
        spdlog::debug("Set direction to east");
        break;
    case SDL_SCANCODE_DOWN:
        spdlog::debug("Set direction to south");
        break;
    default:
        break;
    }
}

void Screen::clear() {
    SDL_SetRenderDrawColor(m_renderer, background.r, background.g, background.b,
                           background.a);
    SDL_RenderClear(m_renderer);
}

void Screen::render() {
    // draw map
    for (int y = 0; y < m_world.height(); ++y) {
        for (int x = 0; x < m_world.width(); ++x) {
            MAP_SLOT elem = m_world.at(x, y);
            int px_dim = 32;
            if (elem == WALL) {
                drawRect(x * px_dim, y * px_dim, px_dim - 2, px_dim - 2, cyan);
            } else if (elem == FOOD) {
                drawPoint(x * px_dim + px_dim / 2, y * px_dim + px_dim / 2,
                          white);
            } else if (elem == PLAYER){
                // drawRect(x * px_dim, int y, int width, int height, Color color)
            }
        }
    }
    SDL_RenderPresent(m_renderer);
}

void Screen::drawRect(int x, int y, int width, int height, Color color) {
    SDL_Rect rect = SDL_Rect{x, y, width, height};
    SDL_SetRenderDrawColor(m_renderer, color.r, color.g, color.b, color.a);
    SDL_RenderDrawRect(m_renderer, &rect);
}

void Screen::drawPoint(int x, int y, Color color) {
    SDL_SetRenderDrawColor(m_renderer, color.r, color.g, color.b, color.a);
    SDL_RenderDrawPoint(m_renderer, x, y);
}
