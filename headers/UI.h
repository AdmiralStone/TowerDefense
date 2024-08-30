// headers/UI.h
#ifndef UI_H
#define UI_H

#include "raylib.h"
#include "Tower.h"
#include <vector>

class UI
{
private:
    int playerResources;    // Player's resources
    int selectedTowerType;  // Currently selected tower type for placement
    int isPlacingTower;     // Wether the player is currently placing a tower
    Vector2 mousePosition;  // Position of the mouse cursor

    void HandleTowerPlacement(std::vector<Tower>&towers, int& playerResources); //Handles logic for placing towers
public:
    UI();
    ~UI();

    void Update(std::vector<Tower>& towers, int& playerResources);
    void Draw()const;

};




#endif