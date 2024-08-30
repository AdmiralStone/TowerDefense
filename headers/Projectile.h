// headers/Projectile.h
#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "raylib.h"
#include "Enemy.h"


class Projectile
{
private:
    Vector2 position; // Current position of the projectile
    float speed;      // Speed of the projectile
    int damage;       // Damage delt by projectile
    Enemy* target;    // Pointer to the target enemy
    bool active;      // Whether the projectile is active

    bool IsCollidingWithTarget()const; // Check if the projectile has hit the target in the current frame

public:
    Projectile(Vector2 position, float speed, int damage, Enemy* target);
    ~Projectile();

    void Update(float deltaTime);
    void Draw()const;
    bool IsActive()const; // Check if the projctile is still active
    
};

#endif