
#include"AmoObject.h"

AmoObject::AmoObject()
{

	rect_.x = 0;
	rect_.y = 0;
	x_val_ = 0;
	y_val_ = 0;
	is_move_ = false;
	amo_type_ = NONE;
}

AmoObject::~AmoObject()
{

}


//phuong thuc HandleMove
void AmoObject::HandleMove(const int& x_border, const int& y_border)
{
	
	rect_.x += + x_val_; //rect_.x tang len 1 luong bang  x_val_ dan di chuyen ve ben phai
	if (rect_.x  > x_border)
	{
		is_move_ = false;
	}
}


//phuong thuc HandleMoveRightToLeft
void AmoObject::HandleMoveRightToLeft() {
	rect_.x -= x_val_;//rect_.x giam di 1 luong x_val_, dan di chuyen ve ben trai
	if (rect_.x < 0) {
		is_move_ = false;
	}
}

void AmoObject::HandleInputAction(SDL_Event events)
{

}