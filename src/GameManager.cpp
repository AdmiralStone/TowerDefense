// src/GameManager.cpp
#include "GameManager.h"
#include "raylib.h"
#include <iostream>

GameManager::GameManager(){
    // Constructor logic if needed
    map = new Map(25,18); // Example map of 25x18 tiles
    
}

GameManager::~GameManager(){
    // Destructor logic if needede
    delete map;
}

void GameManager::Init(){
    // Initialize Raylib and any other necessary systems
    InitWindow(800,600, "Tower Defense");

    // Load map from a fle with .map extension
    map->LoadMap("levels/level1.map");

     // Add one enemy for testing
    std::vector<Vector2>enemyPath = map->GetEnemyPath();

    // Create an enemy path from the map
    if(!enemyPath.empty()){
        enemies.push_back(Enemy(100,50.0f,enemyPath));
    }

    // Create a tower for testing
    towers.push_back(Tower(Vector2{200,200} , 100.0f, 10, 1.0f));
}

void GameManager::Update(){
    float deltaTime = GetFrameTime(); // Time between frames

    // Update enemies
    for(auto& enemy:enemies){
        if(enemy.IsAlive()){
            enemy.Move(deltaTime);
        }
    }

    // Update towers
    for(auto& tower: towers){
        tower.Update(deltaTime,enemies);
    }
}

void GameManager::Draw(){
    BeginDrawing();
    ClearBackground(RAYWHITE);

    // Draw game elements
    map->DrawMap();

    // Draw Enemies
    for(auto enemy:enemies){
        if(enemy.IsAlive()){
            enemy.Draw();
        }
    }

    // Draw towers
    for(const auto& tower: towers){
        tower.Draw();
    }

    EndDrawing();
}

void GameManager::Run(){
    Init();
    
    // Main game loop
    while(!WindowShouldClose()){
        Update();
        Draw();
    }
    

    CloseWindow();

}