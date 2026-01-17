
#include "Animatronic.h"


bool Animatronic::IsActive(bool check)
{
	return false;
}

bool Animatronic::Jumpscare() /*if IsActive is true && Jumpscare is true, return to the menu*/
{
	return false;
}

bool Animatronic::IsOnOffice()
{
	return false;
}

bool Animatronic::KillPlayer()
{
	if (IsActive(true) && Jumpscare())
		return true;
	else
		return false;
}

