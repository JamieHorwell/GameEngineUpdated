#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include "WindowsKeyInput.h"
#include "AbstractKeyMapper.h"
#include <iostream>

WindowsKeyInput::WindowsKeyInput()
{
}


WindowsKeyInput::~WindowsKeyInput()
{
}

bool WindowsKeyInput::initialize(AbstractKeyMapper * keyMapper, int maxActionValue)
{
	this->keyMapper = keyMapper;
	this->maxActionValue = maxActionValue;
	return true;
}

void WindowsKeyInput::update()
{
	actionsLastFrame = actionsThisFrame;
	actionsThisFrame = 0;
	int possibleAction = 1;
	while (possibleAction != maxActionValue) {
		int key = keyMapper->getAction(possibleAction);
		if (GetAsyncKeyState(key)) {
			
			actionsThisFrame |= possibleAction;
		}
		possibleAction <<= 1;
	}
}

bool WindowsKeyInput::actionsActive(int actions) const
{
	return (actionsThisFrame & actions) == actions;
}

bool WindowsKeyInput::actionsHeld(int actions) const
{
	return (actionsLastFrame & actionsThisFrame & actions) == actions;
}

bool WindowsKeyInput::firstInstanceAction(int actions) const
{
	return (~actionsLastFrame & actionsThisFrame & actions) == actions;
}
//needs implementing
bool WindowsKeyInput::actionsLetGo(int actions) const
{
	return false;
}



