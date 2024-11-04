
#ifndef MAIN_OBJECT_H_
#define MAIN_OBJECT_H_


#include "Common_Function.h"
#include "BaseObject.h"
#include "AmoObject.h"
#include <vector>

//khai bao hang so kich thuoc nhan vat
#define WIDTH_MAIN_OBJECT 64
#define HEIGHT_MAIN_OBJECT 91


class MainObject : public BaseObject
{
public:
	MainObject();
	~MainObject();

	void HandleInputAction(SDL_Event events);// xu ly su kien tu ban phim va chuot
	void HandleMove(); // xu ly di chuyen doi tuong

	//thiet lap danh sach dan
	void SetAmoList(std::vector<AmoObject*> amo_list)
	{
		p_amo_list_ = amo_list;
	}

	//tra ve danh sach dan
	std::vector<AmoObject*> GetAmoList() const {
		return p_amo_list_;
	}
	void MakeAmo(SDL_Surface* des);// tao dan moi va them vao danh sach
	void RemoveAmo(const int& idx);// xoa dan khoi danh sach

private:
	int x_val_;
	int y_val_;

	std::vector<AmoObject*> p_amo_list_; //danh sach cac doi tuong dan
};





#endif // !MAIN_OBJECT_H_

