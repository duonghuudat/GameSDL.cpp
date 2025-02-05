

#ifndef AMO_OBJECT_H_
#define AMO_OBJECT_H_

#include "BaseObject.h"

#define WIDTH_LASER 35
#define HEIGHT_LASER 5
#define WIDTH_SPHERE 28
#define HEIGHT_SPHERE 36


class AmoObject : public BaseObject
{
public:
	enum AmoType {
		NONE = 0,
		LASER = 1,
		SPHERE = 2

	};

	AmoObject();
	~AmoObject();
	void HandleInputAction(SDL_Event events);//phuong thu xu ly sk vao tu ban phim va chuot
	void HandleMove(const int& x_border, const int& y_border);//cap nhat lai vi tri cua dan tren gioi han mh
	void HandleMoveRightToLeft();//di chuyen dan tu phai qua trai

	int get_type() const {
		return amo_type_;
	}
	void set_type(const int& type) {
		amo_type_ = type;
	}
	bool get_is_move() const {
		return is_move_;
	}
	void set_is_move(bool is_move) {
		is_move_ = is_move;
	}
	void SetWidthHeight(const int& width, const int& height) {
		rect_.w = width;
		rect_.h = height;
	}


	void Set_x_val(const int& val) {
		x_val_ = val;
	}
	void Set_y_val(const int& val) {
		y_val_ = val;
	}
	int get_x_val() const {
		return x_val_;
	}
	int get_y_val() const {
		return y_val_;
	}
private:
	int x_val_;
	int y_val_;
	bool is_move_;
	int amo_type_;

};





#endif
