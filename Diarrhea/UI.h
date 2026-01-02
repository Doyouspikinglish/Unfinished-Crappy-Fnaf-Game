#include "raylib.h"



class UI
{
	public:
		void AddButton(int length, int width, int posX, int posY);
		bool IsCameraActive = false;
		bool CheckButton(Rectangle Check);
		bool CheckHover(Rectangle LookHover);
		Color CheckGreen(Color TrueColor, Color FalseColor, Rectangle RT);
};

