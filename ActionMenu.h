#pragma once
#include "Button.h"
#include "Enemy.h"
#include "GameObject.h"
#include "PlayerSoul.h"
#include "Turn.h"

/// @brief Represents a healing item that restores a player's health.
class HealingItem
{
public:
    /// @brief Constructs a HealingItem.
    /// @param nameOfItem The name of the item.
    /// @param healingAmount The amount of health the item restores.
    HealingItem(std::string nameOfItem, int healingAmount) : itemName(nameOfItem), amountItHeals(healingAmount)
    {
        player_ = dynamic_cast<PlayerSoul*>(GameObjectManager::Get().GetGameObjectByName("PlayerSoul"));
    }
    /// @brief Heals the player when the item is used.
    void HealPlayer() const
    {
	    player_->Heal(amountItHeals);
        delete this;
    }

    std::string itemName;
private:
    int amountItHeals = 0;
    PlayerSoul* player_;
};

/// @brief Represents a rectangular character menu box.
struct CharacterBox
{
    /// @brief Constructs a CharacterBox with given dimensions.
    /// @param x1 Left boundary.
    /// @param y1 Top boundary.
    /// @param x2 Right boundary.
    /// @param y2 Bottom boundary.
    CharacterBox(float x1, float y1, float x2, float y2)
    {
        x1_ = x1;
        y1_ = y1;
        x2_ = x2;
        y2_ = y2;
    }
    float x1_ = 0;
    float y1_ = 0;
    float x2_ = 0;
    float y2_ = 0;
};

/// @brief Represents an in-game action menu for player choices.
class ActionMenu : public GameObject
{
public:
    /// @brief Constructs an ActionMenu.
    /// @param screen The rendering surface.
    /// @param enemy The enemy associated with this menu.
    /// @param pos The position of the menu.
    /// @param objSize The size of the menu.
    /// @param objName The name of the menu.
    ActionMenu(
        Surface* screen,
        Enemy* enemy,
        const glm::vec2& pos = { 0, 0 },
        const glm::vec2& objSize = { 1, 1 },
        const std::string& objName = "ActionMenu")
        : GameObject(
            screen,
            pos,
            1,
            objSize,
            "",
            objName), enemy_(enemy)
    {
        characterMenuPos = { position.x + size.x / 2 - 128, position.y, position.x + size.x / 2 + 128, position.y - 64 };

        float buttonPadding = 4.0f;

        float buttonWidth = 31.0f;

        buttons.push_back(new Button(
            screen,
            glm::vec2(characterMenuPos.x1_ + buttonPadding, characterMenuPos.y2_ + 32), // Padding applied
            glm::vec2(buttonWidth, 32),
            "assets/art/actionMenu/fight_inactive.png",
            "assets/art/actionMenu/fight_active.png",
            "fightButton",
            false
        ));

        buttons.push_back(new Button(
            screen,
            glm::vec2(characterMenuPos.x1_ + buttonPadding + (buttonWidth + buttonPadding), characterMenuPos.y2_ + 32),
            glm::vec2(buttonWidth, 32),
            "assets/art/actionMenu/act_inactive.png",
            "assets/art/actionMenu/act_active.png",
            "actButton",
            false
        ));

        buttons.push_back(new Button(
            screen,
            glm::vec2(characterMenuPos.x1_ + buttonPadding + (buttonWidth + buttonPadding) * 2, characterMenuPos.y2_ + 32),
            glm::vec2(buttonWidth, 32),
            "assets/art/actionMenu/item_inactive.png",
            "assets/art/actionMenu/item_active.png",
            "itemButton",
            false
        ));

        buttons.push_back(new Button(
            screen,
            glm::vec2(characterMenuPos.x1_ + buttonPadding + (buttonWidth + buttonPadding) * 3, characterMenuPos.y2_ + 32),
            glm::vec2(buttonWidth, 32),
            "assets/art/actionMenu/spare_inactive.png",
            "assets/art/actionMenu/spare_active.png",
            "spareButton",
            false
        ));

        buttons.push_back(new Button(
            screen,
            glm::vec2(characterMenuPos.x1_ + buttonPadding + (buttonWidth + buttonPadding) * 4, characterMenuPos.y2_ + 32),
            glm::vec2(buttonWidth, 32),
            "assets/art/actionMenu/defend_inactive.png",
            "assets/art/actionMenu/defend_active.png",
            "defendButton",
            false
        ));



        ButtonIndexState = buttons.size();

        healingItems.push_back(new HealingItem("Starfait", 70));
        healingItems.push_back(new HealingItem("Dark Candy", 40));
        healingItems.push_back(new HealingItem("Club Sandwichy", 60));
        healingItems.push_back(new HealingItem("Lemonade", 50));
    }

    /// @brief Renders the menu.
    void Render() override;

    //Buttons

	/// @brief Handles the "Fight" action.
    void Fight();

    /// @brief Handles the "Item" action.
    void Item();

    /// @brief Handles the "Spare" action.
    void Spare();

    /// @brief Handles the "Defend" action.
    void Defend();

    /// @brief Resets the menu state.
    void ResetMenu();

    /// @brief Toggles the menu's active state.
    /// @param shouldBeActive True to activate, false to deactivate.
    void SwitchActiveState(bool shouldBeActive);

    /// @brief Checks if an action has been performed.
    /// @return True if an action was taken, false otherwise.
    bool DidAction() const;

    /// @brief Resets the action state.
    void resetAction();

    /// @brief Renders the currently active menu.
    void RenderActiveMenu();

    /// @brief Updates the menu state.
    /// @param deltaTime Time elapsed since the last update.
    void Update(float deltaTime) override;

private:
    Enemy* enemy_;
    bool isMenuActive = false;
    bool isDone = false;
    CharacterBox characterMenuPos = { 0, 0, 0, 0 };
    std::vector<Button*> buttons;
    int ButtonIndexState = 0;
    int levelOfDeepness = 0;
    std::vector<HealingItem*> healingItems;
    int ItemIndexState = 0;

    bool enterPressed = false;
    bool backspacePressed = false;
    bool leftPressed = false;
    bool rightPressed = false;
};