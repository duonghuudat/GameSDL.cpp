#include "Common_Function.h"
#include "MainObject.h"
#include "ThreatsObject.h"
#include <SDL.h>
#include <SDL_mixer.h>
#include <iostream>
#undef main



// tao doi tuong music
Mix_Music* g_background_music = nullptr;

// khoi tao SDL va mixer
bool Init() {
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {
		return false;
	}

	g_screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);

	if (g_screen == NULL)
		return false;
	// Kh?i t?o SDL_mixer
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) == -1) {
		std::cerr << "khong the khoi tao SDL_mixer: " << Mix_GetError() << std::endl;
		return false;
	}

	return true;

}


SDL_Surface* LoadImage(std::string file_path) {
	SDL_Surface* load_image = NULL;
	SDL_Surface* optimize_image = NULL;
	load_image = IMG_Load(file_path.c_str());
	if (load_image != NULL) {
		optimize_image = SDL_DisplayFormat(load_image);
		SDL_FreeSurface(load_image);

		if (optimize_image != NULL) {
			UINT32 color_key = SDL_MapRGB(optimize_image->format, 0, 0xFF, 0xFF);
			SDL_SetColorKey(optimize_image, SDL_SRCCOLORKEY, color_key);
		}

	}
	return optimize_image;
}


void ApplySurface(SDL_Surface* src, SDL_Surface* des, int x, int y) {
	SDL_Rect offset;
	offset.x = x;
	offset.y = y;
	SDL_BlitSurface(src, NULL, des, &offset);
}
 
//giai phong tai nguyen
void CleanUp() {
	SDL_FreeSurface(g_screen);
	SDL_FreeSurface(g_bkground);


	Mix_FreeMusic(g_background_music);
	Mix_CloseAudio();
}




int main(int arc, char* argv[]) {
	//di chuyen man hinh
	//bool is_run_screen = true;
	int bkgn_x = 0;
	//
	bool is_quit = false;

	//khoi tao he thong
	if (Init() == false)
		return 0;

	g_bkground = SDLCommonFunc::LoadImage("background2.png");
	if (g_bkground == NULL) {
		return 0;
	}


	// Load background music
	g_background_music = Mix_LoadMUS("music_background.wav");
	if (g_background_music == nullptr) {
		std::cerr << "khong tai duoc nhac nen: " << Mix_GetError() << std::endl;
		return 0;
	}
	Mix_PlayMusic(g_background_music, -1);
	//


	SDLCommonFunc::ApplySurface(g_bkground, g_screen, 0, 0);

	//Tao nhan vat va moi de doa
		//Make MainObject(nhan vat chinh)
	MainObject plane_object;
	plane_object.SetRect(200, 420);
	bool ret = plane_object.LoadImg("nhanvat_duck.png");
	if (!ret) {
		return 0;
	}


		//Make ThreatObject(cac moi de doa)
	ThreatObject* p_threats = new ThreatObject[NUM_THREATS];
	for (int t = 0; t < NUM_THREATS; t++)
	{
		ThreatObject* p_threat =  (p_threats + t);
		if (p_threat)
		{
			ret = p_threat->LoadImg("af1.png");
			if (ret == false)
			{
				return 0;
			}

			int rand_y = rand() % 400;
			if (rand_y > SCREEN_HEIGHT - 200)
			{
				rand_y = SCREEN_HEIGHT * 0.3;
			}

			p_threat->SetRect(SCREEN_WIDTH + t * 400, rand_y);
			p_threat->set_x_val(5);



			AmoObject* p_amo = new AmoObject();
			p_threat->InitAmo(p_amo);
		}
		
	}
	//
	



	// xu ly di chuyen
	while (!is_quit) {
		while (SDL_PollEvent(&g_even)) {
			if (g_even.type == SDL_QUIT) {
				is_quit = true;
				break;
			}
			plane_object.HandleInputAction(g_even);
		}

		//Apply background
		//SDLCommonFunc::ApplySurface(g_bkground, g_screen, 0, 0); // resest lai bground de cap nhat lien tuc

		//di chuyen man hinh
		bkgn_x -= 2;
		SDLCommonFunc::ApplySurface(g_bkground, g_screen, bkgn_x, 0); // resest lai bground de cap nhat lien tuc
		SDLCommonFunc::ApplySurface(g_bkground, g_screen, bkgn_x + SCREEN_WIDTH, 0);
		if (bkgn_x <= -SCREEN_WIDTH)
		{
			bkgn_x = 0;
		}
		//

	
		//Cap nhat vi tri va hien thi nhan vat
		plane_object.HandleMove();
		plane_object.Show(g_screen);
		plane_object.MakeAmo(g_screen);
		

		//Xu ly cac moi de doa
		for (int tt = 0; tt < NUM_THREATS; tt++)
		{
			ThreatObject* p_threat = (p_threats + tt);
			if (p_threat)
			{
				p_threat->HandleMove(SCREEN_WIDTH, SCREEN_HEIGHT);
				p_threat->Show(g_screen);
				p_threat->MakeAmo(g_screen, SCREEN_WIDTH, SCREEN_HEIGHT);
			
				// update screen
				if (SDL_Flip(g_screen) == -1)
					return 0;


				//xu ly va cham
				bool is_col = SDLCommonFunc::CheckCollision(plane_object.GetRect(), p_threat->GetRect());
				if (is_col)
				{
					//xu ly game over
					if (MessageBox(NULL, L"Game over", L"Info", MB_OK) == IDOK)
					{
						delete[] p_threats;

						SDLCommonFunc::CleanUp();
						SDL_Quit();
						return 1;
					}
					//
				}
				//

				//xu ly dan ban thi over game
				std::vector<AmoObject*> amo_list = plane_object.GetAmoList();
				for (int im = 0; im < amo_list.size(); im++)
				{
					AmoObject* p_amo = amo_list.at(im);
					if (p_amo != NULL)
					{
						bool ret_col = SDLCommonFunc::CheckCollision(p_amo->GetRect(), p_threat->GetRect());
						if (ret_col)
						{
							//xu ly dan
							p_threat->Reset(SCREEN_WIDTH + tt * 400);

							//
							plane_object.RemoveAmo(im);
						}
					}
				}


			}
		}
		
		// update screen
		if (SDL_Flip(g_screen) == -1)
			return 0;
	}

	delete[] p_threats;

	SDLCommonFunc::CleanUp();
	SDL_Quit();

	return 1;
}