// src/GameManager.cpp
#include "GameManager.h"
#include "raylib.h"

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
}

void GameManager::Update(){
}

void GameManager::Draw(){
    BeginDrawing();
    ClearBackground(RAYWHITE);

    // Draw game elements
    map->DrawMap();

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