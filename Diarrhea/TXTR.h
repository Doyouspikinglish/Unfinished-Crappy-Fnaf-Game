#pragma once
#include "raylib.h"
#include <vector>



class TEXTURE
{
	public:
		std::vector<Texture2D> images;
		
		~TEXTURE()
		{
			for (auto& img : images)
			{
				UnloadTexture(img);
			}
		}

};

class SOUND
{
	public:
		std::vector<Sound> sounds;

		~SOUND()
		{
			for (auto& snd : sounds)
			{
				UnloadSound(snd);
			}
		}
 
};

class FONT
{
	public:
		std::vector<Font> font;
		
		~FONT()
		{
			for (auto& ft : font)
			{
				UnloadFont(ft);
			}
		}

};

class MUSIC
{
	public:
		std::vector<Music> msc;

		void Update()
		{
			for (auto& Mc : msc)
			{
				UpdateMusicStream(Mc);
			}
		}

		~MUSIC()
		{
			for (auto& music : msc)
			{
				UnloadMusicStream(music);
			}
		}
};