#pragma once
#include "raylib.h"
#include "GameState.h"


class Animatronic
{
public:
	bool Jumpscare();
	bool IsActive();
	bool IsOnOffice();
	bool KillPlayer();
};

//TODO: Give the functions LIFES! if not, The spirits will never get REST