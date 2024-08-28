// src/Map.cpp
#include "Map.h"
#include "raylib.h"
#include <fstream>
#include <iostream>

Map::Map(int width, int height){
    this->width = width;
    this->height = height;

    grid.resize(height, std::vector<int>(width,0));
}

Map::~Map(){};

void Map::LoadMap(const std::string& filename){
    std::ifstream file(filename);
    if(file.is_open()){
        for(int y = 0; y < height; ++y){
            for(int x = 0; x<width; ++x){
                file >> grid[y][x];
            }
        }

        file.close();
    }else{
        std::cerr<<"Failed to load map file:"<< filename <<std::endl;
        LoadDefaultMap();
    }
}

void Map::LoadDefaultMap(){
    //Create a simple default Map
    for(int y = 0; y < height; ++y){
        for(int x = 0; x < width; ++x){
            if(x == 0 || x == width -1 || y == 0 || y == height -1){
                grid[y][x] = 1; // Path
            }else{
                grid[y][x] = 0; // Open space
            }
        }
    }
}

bool Map::IsValidPlacement(int x, int y)const{
    return (x >=0 && x <= width-1 && y>=0 && y<= height-1 && grid[y][x] == 0);
}

void Map::DrawMap()const{
    for(int y = 0; y< height; ++y){
        for(int x = 0; x < width; ++x){
            Color color = (grid[y][x] == 1)?  DARKGRAY : LIGHTGRAY;
            DrawRectangle(x * 32, y * 32, 32, 32, color);
        }
    }
}
