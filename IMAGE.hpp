#pragma once

#include "DxLib.h"
#include <string>

#define MY_IMG_DIR_JIKI R"(.\MY_IMG\JIKI\)"
#define MY_IMG_NAME_JIKI_1 R"(jiki_1_mini.png)"
#define MY_IMG_NAME_JIKI_2 R"(jiki_2_mini.png)"

#define IMAGE_ERROR_TITLE "IMAGE_ERROR"
#define IMAGE_ERROR_MSG "âÊëúÇ™ì«Ç›çûÇﬂÇ‹ÇπÇÒÇ≈ÇµÇΩ"

class IMAGE
{
private:
	std::string FilePath;
	std::string FileName;

	int Handle;

	int X;
	int Y;
	int Width;
	int Height;

	bool IsLoad;
	bool IsDraw;


public:
	IMAGE(const char *, const char *);
	~IMAGE();

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