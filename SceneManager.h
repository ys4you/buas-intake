#pragma once
#include "SceneBaseState.h"

class SceneManager
{
private:
	std::unique_ptr<SceneBaseState> currentState;
public:
	void ChangeState(std::unique_ptr<SceneBaseState> newState);
	void Update(float deltaTime);
};

