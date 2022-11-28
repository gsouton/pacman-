#pragma once
#include "SDL.h"

#include "SDL_events.h"
#include "SDL_error.h"
#include "SDL_render.h"
#include "SDL_video.h"
#include "types.h"
#include "world.h"
class Screen {
    public:
        Screen(World& world);
        ~Screen();
        bool is_open(); 
        void update();
        
    private:
        bool m_running;
        u32 m_width;
        u32 m_height;
        u32 m_sprite_size;
        World& m_world;
        SDL_Window *m_window;
        SDL_Renderer *m_renderer;
        SDL_Event m_event;
    private:
        void initialize();
        void handle_event();
        void handle_key_event();
        void clear();
        void render();
        void drawRect(int x, int y, int width, int height, Color color);
        void drawPoint(int x, int y, Color color);
};
