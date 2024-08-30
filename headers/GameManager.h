// headers/GameManager.h
#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <vector>
#include <memory>
#include "Map.h"
#include "Enemy.h"
#include "Tower.h"
#include "Projectile.h"

class GameManager{
    public:
        GameManager();
        ~GameManager();

        void Init();
        void Update();
        void Draw();
        void Run();

    private:
        std::unique_ptr<Map> map;            // unique_ptr to manage map
        std::vector<Enemy> enemies;          // List of enemies in the game
        std::vector<Tower> towers;           // List of towers in game
        std::vector<Projectile> projectiles; // List of projectiles in the game
        
};


#endif