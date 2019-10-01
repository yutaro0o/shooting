#include "ANIMATION.hpp"
#include "FPS.hpp"

ANIMATION::ANIMATION(const char *dir, const char *name, int SplitNumALL, int SpritNumX, int SpritNumY, int SpritWidth, int SpritHeight, double changeSpeed, bool IsLoop)
{
	this->FilePath = "";
	this->FileName = "";

	this->Handle.resize(SplitNumALL);
	this->Handle_itr = this->Handle.begin();

	this->X = 0;
	this->Y = 0;
	this->Width = 0;
	this->Height = 0;
	this->NextChangeSpeed = 0.0;

	this->ChangeMaxCnt = (int)(changeSpeed * fps->Getvalue());
	this->ChangeCnt = 0;

	this->IsAnimeLoop = IsLoop;

	this->IsLoad = false;
	this->IsDraw = false;

	std::string LoadfilePath;
	LoadfilePath += dir;
	LoadfilePath += name;

	LoadDivGraph(LoadfilePath.c_str(), SplitNumALL, SpritNumX, SpritNumY, SpritWidth, SpritHeight, &this->Handle[0]);

	if (this->Handle[0] == -1)
	{
		std::string ErrorMsg(ANIMATION_ERROR_MSG);
		ErrorMsg += TEXT('\n');
		ErrorMsg += LoadfilePath;

		MessageBox(
			NULL,
			ErrorMsg.c_str(),
			TEXT(ANIMATION_ERROR_TITLE),
			MB_OK);

		return;
	}

	this->FilePath = LoadfilePath;
	this->FileName = name;

	GetGraphSize(
		this->Handle[0],
		&this->Width,
		&this->Height
	);

	this->NextChangeSpeed = changeSpeed;

	this->IsLoad = true;
	this->IsDraw = true;
	return;
}

ANIMATION::~ANIMATION()
{
	for (int handle : this->Handle)
	{
		DeleteGraph(handle);
	}

	std::vector<int> v;
	this->Handle.swap(v);
	return;
}
std::string ANIMATION::GetFileName(void)
{
	return this->FileName;
}
void ANIMATION::SetX(int numX)
{
	this->X = numX; return;
}
void ANIMATION::SetY(int numY)
{
	this->Y = numY; return;
}
int ANIMATION::GetX(void)
{
	return this->X;
}
int ANIMATION::GetY(void)
{
	return this->Y;
}
int ANIMATION::GetWidth(void)
{
	return this->Width;
}
int ANIMATION::GetHeight(void)
{
	return this->Height;
}
bool ANIMATION::GetIsLoad(void)
{
	return this->IsLoad;
}

void ANIMATION::Draw(void)
{
	if (this->IsDraw == true)
	{
		DrawGraph(this->X, this->Y, *this->Handle_itr, TRUE);

		if (this->ChangeCnt == this->ChangeMaxCnt)
		{
			if (this->Handle_itr == this->Handle.end() - 1)
			{
				if (this->IsAnimeLoop == false)
				{
					this->IsDraw = false;
				}
				this->Handle_itr = this->Handle.begin();
			}
			else
			{
				this->Handle_itr++;
			}
			this->ChangeCnt = 0;
		}
		else
		{
			this->ChangeCnt++;
		}
	}
	return;
}