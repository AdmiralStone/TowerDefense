// src/Tower.cpp
#include "Tower.h"
#include "raymath.h"
#include "raylib.h"

Tower::Tower(Vector2 position, float range, int damage, float fireRate):
    position(position), range(range), damage(damage), fireRate(fireRate), cooldown(0.0f){}

Tower::~Tower(){
    // Destructor logic if needed
}

void Tower::Update(float deltaTime, std::vector<Enemy>&enemies, std::vector<Projectile>& projectiles){
    // Reduce cooldown by the time elapsed
    cooldown -= deltaTime;

    // CHeck if tower can shoot
    if(cooldown <= 0.0f){
        for(auto& enemy: enemies){
            if(enemy.IsAlive() && IsInRange(enemy)){
                Shoot(enemy,projectiles);
                cooldown = 1.0f/fireRate; // Reset cooldown based on the fire rate
                break; // Shoot only one enemy per update
            }
        }
    }
}

void Tower::Draw()const{
    DrawCircleV(position,15,BLUE); // Draw the tower as a blue circle
    DrawCircleLines(position.x, position.y, range, GREEN); // Draw tower range
}

bool Tower::IsInRange(const Enemy& enemy)const{
    // Calculate the distance between the tower and the enemy
    float distance = Vector2Distance(position, enemy.GetPosition());
    return distance <= range;
}

void Tower::Shoot(Enemy& enemy, std::vector<Projectile>& projectiles){
    // Create a new projectile aimed at enemy
    projectiles.push_back(Projectile(position,300.0f,damage, &enemy));
}