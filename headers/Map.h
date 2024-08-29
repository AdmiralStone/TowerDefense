// headers/Map.h
#ifndef MAP_H
#define MAP_H

#include <vector>
#include <string>
#include "raylib.h"

class Map{
    public:
        Map(int width, int height);
        ~Map();

        void LoadMap(const std::string& fileName);
        bool IsValidPlacement(int x, int y)const;
        void DrawMap() const;

        std::vector<Vector2> GetEnemyPath() const;

    private:
        int width;
        int height;
        std::vector<std::vector<int>> grid;

        void LoadDefaultMap(); // Fallback if file loading failed

};


#endif