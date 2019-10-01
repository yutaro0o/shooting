#pragma once
#include "DxLib.h"

class FPS
{
private:
	int value;
	double drawValue;
	DWORD calcStartTime;
	DWORD calcEndTime;
	DWORD flameCount;
	double calcAverage;
public:
	FPS(int);
	VOID Wait(VOID);
	VOID Update(VOID);
	VOID Draw(int, int);
	int Getvalue(VOID);
	virtual ~FPS();
};
extern FPS *fps;