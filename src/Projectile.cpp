// src/Projectile.cpp
#include "Projectile.h"
#include "raylib.h"
#include "raymath.h"

Projectile::Projectile(Vector2 position, float speed, int damage, Enemy* target)
    :position(position), speed(speed), damage(damage), target(target), active(true){}

Projectile::~Projectile(){
    // Destructor logic if required
}

void Projectile::Update(float deltaTime){
    if(!active || !target || !target->IsAlive()){
        active = false;
        return; // If the projectile is not active or the target is dead, do nothing
    }

    // Calculate the direction toward the target
    Vector2 direction = Vector2Subtract(target->GetPosition(), position);
    float distanceToTarget = Vector2Length(direction);

    if(distanceToTarget < speed * deltaTime){
        // If the projectile is close enough to the target, hit the target
        if(IsCollidingWithTarget()){
            target->TakeDamage(damage);
            active = false; // Deactivate the projectile after hitting the target
        }
    }else{
        // Otherwise, move toward the target
        direction = Vector2Normalize(direction);
        position.x += direction.x * speed * deltaTime;
        position.y += direction.y * speed * deltaTime;
    }

}

void Projectile::Draw()const{
    if(active){
        DrawCircleV(position, 5, GREEN); //Draw the projectile as a small green circle
    }
}

bool Projectile::IsActive()const{
    return active;
}

bool Projectile::IsCollidingWithTarget()const{
    // Check if the projectile has collided with the target
    if(target){
        float distanceToTarget = Vector2Distance(position,target->GetPosition());
        return distanceToTarget <= 5.0f; // Collision radius of 5 units
    }

    return false;
}