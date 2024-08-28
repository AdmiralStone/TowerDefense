// headers/GameManager.h
#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "Map.h"

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
};


#endif