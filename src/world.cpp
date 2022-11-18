#include "world.h"
#include "spdlog/spdlog.h"
#include <cerrno>
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <string>

World::World(const char *pathname) {
    spdlog::info("Creating world...");
    load_map_from_file(pathname);
}

void World::load_map_from_file(const char *pathname) {
    spdlog::debug(std::string("Opening file: ") + pathname);

    FILE *file_pointer = fopen(pathname, "r");
    if (file_pointer == NULL) {
        spdlog::error(std::string("Could not open file") + pathname);
        perror("error");
        exit(-1);
    }
    spdlog::debug("File opened with sucess!");

    u32 width, height;
    if(fscanf(file_pointer,"%d %d\n", &width, &height) == EOF){
        spdlog::error(std::string("Could not read world dimension from: ") + pathname);
        exit(-1);
    }
    spdlog::debug(std::string("Retriving world dimension: ") + std::to_string(width) + std::string("x") + std::to_string(height));
    
    u32 buffer_size = height*width; 
    char char_map[buffer_size];

    spdlog::debug("Reading map file...");
    for(u32 y = 0; y < height; ++y){
        fgets(char_map+width*y, width, file_pointer);// read entire line 
        fgetc(file_pointer); // skip break line \n
    }
    for(u32 i = 0; i < buffer_size; i++){
        if(i > 0 && i % width == 0) std::cout << std::endl;
        std::cout << char_map[i];
    }
    std::cout << std::endl;

    spdlog::debug("Setting map of the world...");
    m_map.set(width, height, char_map);
    fclose(file_pointer);
}

bool World::has_food(){
    return m_map.has_food();
}

u32 World::width() const{
    return m_map.width();
}

u32 World::height() const{
    return m_map.height();
}

char World::at(u32 x, u32 y){
    return m_map.get(x, y);

}

