#include "raylib.h"
#include "TXTR.h"
#include "UI.h"
#include "GameState.h"
#include <iostream>



bool IsHovered(Rectangle R)
{
	return CheckCollisionPointRec(GetMousePosition(), R);
}

bool OnClick(Rectangle M)
{
	return IsHovered(M) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON);
}

bool GiveChance()
{
	int chance = GetRandomValue(1, 15000);
	
	if (chance == GetRandomValue(1, 15000)) 
		return true;
	else 
		return false;

}

Color DoGreen(Rectangle F)
{
	if (IsHovered(F))
		return GREEN;
	else
		return WHITE;
}


int main()
{
	InitWindow(600, 600, "Five nights at the OGs");
	InitAudioDevice();
	SetTargetFPS(60);

	/*debug purpose*/ std::cout << "\033]0;GAME\007"; /*debug purpose*/


	TEXTURE tex;
	FONT Arcadefont;
	SOUND sound;

	Rectangle CheckHover = {230, 230, 200, 50};
	Rectangle MenuCheckHover = { 230, 230, 200, 50 };
	Rectangle CameraCheckHover = { 170, 550, 270, 40 };

	Rectangle CAM1 = { 470, 500, 21, 20 };
	Rectangle CAM2 = { 490, 500, 21, 20 };
	Rectangle CAM3 = { 470, 550, 21, 20 };
	Rectangle CAM4 = { 490, 550, 21, 20 };

	int CurrentCamera = 1;

	STATE state = MENU;
	UI OnCam;
	 
	bool IsOnPauseMenu = false;
	bool IsOnCamera = false;

	tex.images.push_back(LoadTexture("FNAF office.png"));    //office -> 0
	tex.images.push_back(LoadTexture("Group 1.png"));        //camera button -> 1
	tex.images.push_back(LoadTexture("FNAF Jumpscare.png")); // -> Easter egg -> 2

	tex.images.push_back(LoadTexture("GroupCamera1.png")); //->3
	tex.images.push_back(LoadTexture("GroupCamera2.png")); //->4
	tex.images.push_back(LoadTexture("GroupCamera3.png"));  //->5
	tex.images.push_back(LoadTexture("GroupCamera4.png")); //->6

	tex.images.push_back(LoadTexture("FIXEDstatic.png")); //-> 7

	tex.images.push_back(LoadTexture("CameraRoom1.png")); //->8
	tex.images.push_back(LoadTexture("CameraRoom2.png")); //->9
	tex.images.push_back(LoadTexture("CameraRoom3.png")); //->10
	tex.images.push_back(LoadTexture("CameraRoom4.png")); //->11

	Arcadefont.font.push_back(LoadFont("ARCADE_I.TTF"));     

	sound.sounds.push_back(LoadSound("SmallBlip.wav")); //->0
	sound.sounds.push_back(LoadSound("OpenCamera.wav")); //->1
	sound.sounds.push_back(LoadSound("CameraClick.wav")); //->2
	sound.sounds.push_back(LoadSound("OfficeAmbiance.wav")); //->3

	
	
	auto FastDrawCamera = [&]()
	{
		DrawTexture(tex.images[3], 470, 500, DoGreen(CAM1));
		DrawTexture(tex.images[4], 490, 500, DoGreen(CAM2));
		DrawTexture(tex.images[5], 470, 550, DoGreen(CAM3));
		DrawTexture(tex.images[6], 490, 550, DoGreen(CAM4));
	};

	auto FastDrawCameraButton = [&]()
	{
		DrawTexture(tex.images[1], 170, 550, DoGreen(CameraCheckHover));
	};

	PlaySound(sound.sounds[3]);

	while (!WindowShouldClose())
	{

		if (!IsSoundPlaying(sound.sounds[3]))
			PlaySound(sound.sounds[3]);

		BeginDrawing();
		ClearBackground(BLACK);

		if (state == MENU) {
			
			bool Hovered = IsHovered(CheckHover);

			Color TextColor = Hovered ? GREEN : RED;

			DrawTextEx(Arcadefont.font[0], "PLAY", { 230, 230 }, 25, 10, TextColor);

			if (OnClick(CheckHover))
			{
				state = GAME;

			}
			 
		}

		if (state == GAME)
		{

			DrawTexture(tex.images[0], 0, 0, WHITE);

			bool Easter_Egg = GiveChance();

			if (!IsHovered(CameraCheckHover))
			{
				DrawTexture(tex.images[1], 170, 550, WHITE);
			}

			else
			{
				DrawTexture(tex.images[1], 170, 550, GREEN);
			}

			if (OnClick(CameraCheckHover))
			{
				IsOnCamera = !IsOnCamera;
				PlaySound(sound.sounds[2]);
			}

			if (IsOnCamera)
			{
				if (!IsHovered(CameraCheckHover))
				{
					DrawTexture(tex.images[8], 0, 0, WHITE);
					DrawTexture(tex.images[1], 170, 550, WHITE);
				    /*CAMERA*/

					FastDrawCamera();

					if (OnClick(CAM1))
					{
						CurrentCamera = 1;
						FastDrawCamera();
						PlaySound(sound.sounds[0]);

					}


					if (OnClick(CAM2))
					{
						CurrentCamera = 2;
						FastDrawCamera();
						PlaySound(sound.sounds[0]);
					}

					if (OnClick(CAM3))
					{
						CurrentCamera = 3;
						FastDrawCamera();
						PlaySound(sound.sounds[0]);
					}

					if (OnClick(CAM4))
					{
						CurrentCamera = 4;
						FastDrawCamera();
						PlaySound(sound.sounds[0]);
					}


					if (CurrentCamera == 1)
					{
						DrawTexture(tex.images[8], 0, 0, WHITE);
						FastDrawCameraButton();
						FastDrawCamera();
					}

					if (CurrentCamera == 2)
					{
						DrawTexture(tex.images[9], 0, 0, WHITE);
						FastDrawCameraButton();
						FastDrawCamera();

					}

					if (CurrentCamera == 3)
					{
						DrawTexture(tex.images[10], 0, 0, WHITE);
						FastDrawCameraButton();
						FastDrawCamera();
					}

					if (CurrentCamera == 4)
					{
						DrawTexture(tex.images[11], 0, 0, WHITE);
						FastDrawCameraButton();
						FastDrawCamera(); /*Just checking if it is the issue*/
					}


					/*CAMERA*/
					DrawTexture(tex.images[7], 0, 0, WHITE);
				}

				else
				{
					if(CurrentCamera == 1) 
						DrawTexture(tex.images[8], 0, 0, WHITE);
						DrawTexture(tex.images[1], 170, 550, GREEN);
						FastDrawCamera();
					if (CurrentCamera == 2)
						DrawTexture(tex.images[9], 0, 0, WHITE);
						DrawTexture(tex.images[1], 170, 550, GREEN);
						FastDrawCamera();

					if (CurrentCamera == 3)
						DrawTexture(tex.images[10], 0, 0, WHITE);
						DrawTexture(tex.images[1], 170, 550, GREEN);
						FastDrawCamera();
					if (CurrentCamera == 4) 
						DrawTexture(tex.images[11], 0, 0, WHITE);
						DrawTexture(tex.images[1], 170, 550, GREEN);


					/*BUTTONS*/

					FastDrawCamera();

					/*BUTTONS*/

					DrawTexture(tex.images[7], 0, 0, WHITE);
				}

			}

			/*CAMERA*/

			if (Easter_Egg)
			{
				
				ClearBackground(WHITE);
				DrawTexture(tex.images[2], 0, 0, WHITE);
				state = GAME;

			}

			if (IsKeyPressed(KEY_M))
			{
				IsOnPauseMenu = !IsOnPauseMenu;

			}


			if (IsOnPauseMenu)
			{
				bool PauseMenu_Hovered = IsHovered(MenuCheckHover);

				Color PauseMenu_Color = PauseMenu_Hovered ? GREEN : RED;

				DrawTextEx(Arcadefont.font[0], "RETURN ?", { 230, 230 }, 20, 10, PauseMenu_Color);

			if (OnClick(MenuCheckHover))
				{
					IsOnPauseMenu = false;
					state = MENU;
				}


			}
		}

		EndDrawing();
	}

	CloseWindow();
	CloseAudioDevice();
}