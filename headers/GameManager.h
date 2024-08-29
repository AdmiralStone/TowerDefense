// headers/GameManager.h
#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <vector>
#include "Map.h"
#include "Enemy.h"

class GameManager{
    public:
        GameManager();
        ~GameManager();

        void Init();
        void Update();
        void Draw();
        void Run();

    private:
        Map* map; // Pointer to Map instance
        std::vector<Enemy> enemies; // List of enemies in the game
        
};


#endif