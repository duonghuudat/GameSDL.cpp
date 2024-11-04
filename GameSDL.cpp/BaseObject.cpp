
#include "BaseObject.h"
#include "Common_Function.h"

// goi ham constructor
BaseObject::BaseObject() 
{
	// khoi tao cac gia tri vi tri x va y
	rect_.x = 0;
	rect_.y = 0;
	p_object_ = NULL; //hinh anh
}

// goi ham destructor
BaseObject::~BaseObject() 
{
	if (p_object_ != NULL) {
		SDL_FreeSurface(p_object_);
	}
}

//phuong thuc  LoadImg
//tai hinh anh tu file
bool BaseObject::LoadImg(const char* file_name) {
	p_object_ = SDLCommonFunc::LoadImage(file_name);
	if (p_object_ == NULL)
		return false;
	return true;
}

//phuong thuc show
//hien thi hinh anh doi tuong duoc truyen vao tu des
void BaseObject::Show(SDL_Surface* des) {
	if (p_object_ != NULL) {
		SDLCommonFunc::ApplySurface(p_object_, des, rect_.x, rect_.y);
	}
}