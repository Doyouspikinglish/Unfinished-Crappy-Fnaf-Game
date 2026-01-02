#pragma once
#include "raylib.h"

class Animatronic
{
public:
	bool Jumpscare();
	bool IsActive();
	bool IsOnOffice();
	void KillPlayer();
};

//TODO: Give the functions LIFES! if not, The spirits will never get REST