#include "UI.h"


bool UI::CheckButton(Rectangle Check)
{
	return CheckCollisionPointRec(GetMousePosition(), Check) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON);
}

bool UI::CheckHover(Rectangle LookHover)
{
	return CheckCollisionPointRec(GetMousePosition(), LookHover);
}

Color UI::CheckGreen(Color TrueColor, Color FalseColor, Rectangle RT)
{
	if (CheckHover(RT))
		return TrueColor;
	else
		return FalseColor;
}