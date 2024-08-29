// src/Enemy.cpp
#include "Enemy.h"
#include "raylib.h"
#include "raymath.h" // Include Raymath for vector operations

Enemy::Enemy(int health, float speed, const std::vector<Vector2>& path)
    : health(health), speed(speed), currentPathIndex(0) {
    // Pre-calculate the centered path positions
    for (const auto& cellPosition : path) {
        this->path.push_back(AdjustPositionToCenter(cellPosition));
    }

    // Initialize the enemy at the start of the path
    if (!this->path.empty()) {
        position = this->path[0];
    }
}

Enemy::~Enemy() {
    // Destructor logic if needed
}

void Enemy::Move(float deltaTime) {
    if (currentPathIndex >= path.size()) {
        return; // If we've reached the end of the path, do nothing
    }

    // Calculate the direction towards the next point on the path
    Vector2 target = path[currentPathIndex]; // Use the pre-calculated centered position
    Vector2 direction = Vector2Subtract(target, position);
    float distanceToNextPoint = Vector2Length(direction);

    if (distanceToNextPoint < speed * deltaTime) {
        // If the enemy is close enough to the next point, snap to it and move to the next point
        position = target;
        currentPathIndex++;
    } else {
        // Otherwise, move towards the next point
        direction = Vector2Normalize(direction);
        position.x += direction.x * speed * deltaTime;
        position.y += direction.y * speed * deltaTime;
    }
}

void Enemy::TakeDamage(int damage) {
    health -= damage;
}

bool Enemy::IsAlive() const {
    return health > 0;
}

void Enemy::Draw() const {
    DrawCircleV(position, 10, RED); // Draw the enemy as a red circle for now
}

// Adjust the position to the center of the cell
Vector2 Enemy::AdjustPositionToCenter(const Vector2& cellPosition) const {
    int cellSize = 32; // Assuming each cell is 32x32 pixels
    return Vector2{
        cellPosition.x + cellSize / 2.0f,
        cellPosition.y + cellSize / 2.0f
    };
}
