
// Lop co so

#ifndef BASE_OBJECT_H_
#define BASE_OBJECT_H_
#include "Common_Function.h"


class BaseObject {
public:
	BaseObject();
	~BaseObject();

	

	void Show(SDL_Surface* des); //hien thi doi tuong len mh
	bool LoadImg(const char* file_name); // tai hinh anh tu file len

	//thiet lap vi tri cua doi tuong len mh
	void SetRect(const int& x, const int&y) {
		rect_.x = x, rect_.y = y;
	}
	SDL_Rect GetRect() const {
		return rect_;
	}

	// ham tra ve hinh anh doi tuong
	SDL_Surface* GetObject() {
		return p_object_;
	}


protected:   //Cac lop con ke thua moi su dung dc

	SDL_Rect rect_; // thong tin vi tri va kich thuoc doi tuong
	SDL_Surface* p_object_; // con tro luu tru hih anh doi tuong

};






#endif 
