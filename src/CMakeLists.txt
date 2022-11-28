cmake_minimum_required(VERSION 3.22)

set(sdl-lib ${PROJECT_BINARY_DIR}/SDL/src/SDL-build)
link_directories(sdl-lib)

set(src 
    main.cpp 
    game.cpp 
    world.cpp 
    map.cpp 
    screen.cpp
    entity.cpp
    enemy.cpp
    player.cpp )
add_executable(main ${src})
target_link_libraries(main SDL2-2.0)

