// src/UI.cpp
#include "UI.h"
#include "raylib.h"

UI::UI()
    :   playerResources(200),
        selectedTowerType(0),
        isPlacingTower(false){}

UI::~UI(){
    // Destructor logic for UI if required
}

void UI::Update(std::vector<Tower>& towers, int& playerResources){
    mousePosition = GetMousePosition();

    // Check for user input to select tower type
    if(IsKeyPressed(KEY_ONE) && playerResources >= 50){
        selectedTowerType = 0; // Example: select basic tower
        isPlacingTower = true;
    }

    // Handle placing of tower if the player is in placement node
    if(isPlacingTower){
        HandleTowerPlacement(towers, playerResources);
    }

    this->playerResources = playerResources;

}

void UI::Draw()const{
    // Draw UI elements (like resource counter, buttons, etc)
    DrawText(TextFormat("Resources:%d",playerResources), 10, 10, 20, BLACK);
    DrawText("Press 1 to select a basic tower", 10, 40, 20, DARKGRAY);

    // If the player is placing a tower, display visual indicator
    if(isPlacingTower){
        DrawCircleV(mousePosition, 15, Fade(BLUE, 0.5f)); // semi-transparant indicator
    }
}

void UI::HandleTowerPlacement(std::vector<Tower>& towers, int& playerResources) {
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && playerResources >= 50) { // Example cost of a tower
        // Place tower at mouse position and deduct cost
        towers.push_back(Tower(mousePosition, 100.0f, 10, 1.0f)); // Example tower parameters
        playerResources -= 50; // Deduct cost
        isPlacingTower = false; // Exit placement mode
    }
}

