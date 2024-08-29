// header/Enemy.h
#ifndef ENEMY_H
#define ENEMY_H

#include <vector>
#include "raylib.h"

class Enemy{
    public:
        Enemy(int health, float speed, const std::vector<Vector2>&path);
        ~Enemy();

        void Move(float deltaTime);
        void TakeDamage(int damage);
        bool IsAlive() const;
        void Draw() const;

        Vector2 AdjustPositionToCenter(const Vector2& cellPosition)const;


    private:
        int health;
        float speed;
        Vector2 position;
        std::vector<Vector2>path; // The path the enemy will follow
        size_t currentPathIndex; // Index of the current target point in the path


};

#endif