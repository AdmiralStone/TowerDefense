// headers/Map.h
#ifndef MAP_H
#define MAP_H

#include <vector>
#include <string>

class Map{
    public:
        Map(int width, int height);
        ~Map();

        void LoadMap(const std::string& fileName);
        bool IsValidPlacement(int x, int y)const;
        void DrawMap() const;

    private:
        int width;
        int height;
        std::vector<std::vector<int>> grid;

        void LoadDefaultMap(); // Fallback if file loading failed

};


#endif