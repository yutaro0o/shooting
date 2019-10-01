#pragma once

#include "DxLib.h"
#include <string>
#include <vector>

#define MY_ANIME_DIR_BAKU R"(.\MY_ANIME\bakuhatsu\)"

#define MY_ANIME_NAME_BAKU_1 R"(bakuhatsu_01.png)"
#define BAKU_1_WIDTH 70
#define BAKU_1_HEIGHT 64

#define ANIMATION_ERROR_TITLE "ANIMATION_ERROR"
#define ANIMATION_ERROR_MSG "アニメーションを読み込めませんでした"

class ANIMATION
{
private:
	std::string FilePath;
	std::string FileName;

	std::vector<int> Handle;

	std::vector<int>::iterator Handle_itr;

	int X;
	int Y;
	int Width;
	int Height;

	double NextChangeSpeed;
	int ChangeMaxCnt;
	int ChangeCnt;

	bool IsAnimeLoop;
	bool IsLoad;
	bool IsDraw;

public:
	ANIMATION(const char *, const char *, int, int, int, int, int, double, bool);
	virtual ~ANIMATION();

	std::string GetFileName(void);

	void SetX(int);
	void SetY(int);
	int GetX(void);
	int GetY(void);
	int GetWidth(void);
	int GetHeight(void);

	bool GetIsLoad(void);
	void Draw(void);
};