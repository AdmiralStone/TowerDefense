// headers/Tower
#ifndef TOWER_H
#define TOWER_H

#include "raylib.h"
#include <vector>
#include "Enemy.h"

class Tower{
    public:
        Tower(Vector2 position, float range, int damage, float fireRate);
        ~Tower();

        void Update(float deltaTime, std::vector<Enemy>& enemies);
        void Draw() const;


    private:
        Vector2 position; // Position of tower
        float range;      // Range within which the tower can target enemies
        int damage;       // Damage delt to enemies per shot
        float fireRate;   // Number of shots per second
        float cooldown;   // Time remaining until the next shot

        bool IsInRange(const Enemy& enemy)const; // Check if an enemy is in range
        void Shoot(Enemy& enemy);                // Shoot at enemy

};

#endif