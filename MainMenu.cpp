#include "precomp.h"
#include "MainMenu.h"

#include <iostream>


void MainMenu::Enter() {
    std::cout << "Entering Main Menu State\n";
}

void MainMenu::Update(float deltaTime) {
    std::cout << "Updating Main Menu State\n";
}

void MainMenu::Exit() {
    std::cout << "Exiting Main Menu State\n";
}