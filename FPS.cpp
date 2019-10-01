#include "FPS.hpp"

FPS::FPS(int fps_value)
{
	this->value = fps_value;
	this->drawValue = 0;
	this->calcStartTime = 0;
	this->calcEndTime = 0;
	this->flameCount = 0;
	this->calcAverage = (double)value;

	return;
}
VOID FPS::Wait(VOID)
{
	DWORD nowTime = GetTickCount();
	DWORD keikaTime = nowTime - this->calcStartTime;
	if (this->value > 0)
	{
		int wait_tm = (this->flameCount * 1000 / this->value) - (keikaTime);

		if (wait_tm > 0)
		{
			
			Sleep(wait_tm);
		}
	}
	return;
}

VOID FPS::Update(VOID)
{
	if (this->flameCount == 0)
	{
		this->calcStartTime = GetTickCount();
	}
	if (this->flameCount == this->calcAverage)
	{
		this->calcEndTime = GetTickCount();
		this->drawValue = 1000.0f / ((this->calcEndTime - this->calcStartTime) / this->calcAverage);
		this->calcStartTime = this->calcEndTime;
		this->flameCount = 0;
	}
	this->flameCount++;
	return;
}
VOID FPS::Draw(int drawX, int drawY)
{
	DrawFormatString(drawX, drawY, GetColor(255, 255, 255), "FPS:%.1f", this->drawValue);
	return;
}
int FPS::Getvalue(VOID)
{
	return this->value;
}
FPS::~FPS()
{
	return;
}