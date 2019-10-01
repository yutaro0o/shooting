#include "DxLib.h"
#include "main.hpp"
#include "FPS.hpp"
//#include "KEYDOWN.hpp"
#include "IMAGE.hpp"
#include "ANIMATION.hpp"
//#include "CHARACTOR.hpp"

FPS *fps = new FPS(GAME_FPS_SPEED);
//KEYDOWN *keydown = new KEYDOWN();

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//ChangeWindowMode(GAME_WINDOW_MODECHANGE);
	SetGraphMode(GAME_WIDTH, GAME_HEIGHT, GAME_COLOR);

	SetWindowStyleMode(SET_WINDOW_ST_MODE_DEFAULT);

	SetMainWindowText(TEXT(GAME_WINDOW_NAME));

	if (DxLib_Init() == -1) { return -1; }

	SetDrawScreen(DX_SCREEN_BACK);
	
	IMAGE *jiki = new IMAGE(MY_IMG_DIR_JIKI, MY_IMG_NAME_JIKI_1);
	if (jiki->GetIsLoad() == false) { return -1; };
	
	ANIMATION *baku = new ANIMATION(MY_ANIME_DIR_BAKU, MY_ANIME_NAME_BAKU_1, 16, 16, 1, BAKU_1_HEIGHT, BAKU_1_HEIGHT, 0.05, true);
	if (baku->GetIsLoad() == false) { return -1; };

	CHARACTOR * chara = new CHARACTOR();
	if (chara->GetIsCreate() == false) { return -1; };

	while (TRUE)
	{
		if (ProcessMessage() != 0) { break; }
		if (ClearDrawScreen() != 0) { break; }

		//keydown->KeyDownUpdate();
		fps->Update();
		//keydown->IsKeyDown(KEY_INPUT_LEFT);
		//keydown->IsKeyDown(KEY_INPUT_UP);
		jiki->Draw();
		baku->Draw();
		fps->Draw(0, 0);
		ScreenFlip();
		fps->Wait();
	}
	delete jiki;

	delete baku;
	//delete chara;
	delete fps;
	//delete keydown;

	DxLib_End();
	return 0;
}