

#ifndef COMMON_FUNCTION_H
#define COMMON_FUNCTION_H

#include <Windows.h>
#include <SDL.h>
#include <SDL_image.h>
#include <string>

//thiet lap cac thong so
const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 600;
const int SCREEN_BPP = 32;
const int NUM_THREATS = 3;


static SDL_Surface* g_screen = NULL; // man hinh chinh chua toan bo cac thanh phan
static SDL_Surface* g_bkground = NULL; //backround 
// SDL_Surface* g_object = NULL; dua vao lop doi tuong
static SDL_Event g_even; //xu ly su kien


namespace SDLCommonFunc {
	SDL_Surface* LoadImage(std::string file_path);
	void ApplySurface(SDL_Surface* src, SDL_Surface* des, int x, int y);
	void CleanUp();

	//xu ly va cham
	bool CheckCollision(const SDL_Rect& object1, const SDL_Rect& object2);
}



#endif