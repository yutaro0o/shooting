#include "IMAGE.hpp"

IMAGE::IMAGE(const char *dir, const char *name)
{
	this->FilePath = "";
	this->FileName = "";

	this->Handle = -1;

	this->X = 0;
	this->Y = 0;
	this->Width = 0;
	this->Height = 0;

	this->IsLoad = false;
	this->IsDraw = false;

	std::string LoadfilePath;
	LoadfilePath += dir;
	LoadfilePath += name;

	this->Handle = LoadGraph(LoadfilePath.c_str());

	if (this->Handle == -1)
	{
		std::string ErrorMsg(IMAGE_ERROR_MSG);
		ErrorMsg += TEXT('\n');
		ErrorMsg += LoadfilePath;

		MessageBox(
			NULL,
			ErrorMsg.c_str(),
			TEXT(IMAGE_ERROR_TITLE),
			MB_OK);
		return;
	}

	this->FilePath = LoadfilePath;
	this->FileName = name;

	GetGraphSize(
		this->Handle,
		&this->Width,
		&this->Height
	);

	this->IsLoad = true;
	this->IsDraw = true;

	return;
}

IMAGE::~IMAGE()
{
	DeleteGraph(this->Handle);
	return;
}

std::string IMAGE::GetFileName(void)
{
	return this->FileName;
}

void IMAGE::SetX(int numX)
{
	this->X = numX; return;
}
void IMAGE::SetY(int numY)
{
	this->Y = numY; return;
}
int IMAGE::GetX(void)
{
	return this->X;
}
int IMAGE::GetY(void)
{
	return this->Y;
}
int IMAGE::GetWidth(void)
{
	return this->Width;
}
int IMAGE::GetHeight(void)
{
	return this->Height;
}
bool IMAGE::GetIsLoad(void)
{
	return this->IsLoad;
}
void IMAGE::Draw(void)
{
	if (this->IsDraw == true)
	{
		DrawGraph(this->X, this->Y, this->Handle, TRUE);
	}
	return;
}