
#ifndef THREATS_OBJECT_H_
#define THREATS_OBJECT_H_

#include "Common_Function.h"
#include "BaseObject.h"
#include "AmoObject.h"
#include <vector>

#define WIDTH_THREAT 80
#define HEIGHT_THREAT 33
const int UNDER_LIMIT_THREAT = 200;


class ThreatObject : public BaseObject
{
public:
	ThreatObject();
	~ThreatObject();

	void HandleMove(const int& x_border, const int& y_border);//phuong thuc xu ly di chuyen
	void HandleInputAction(SDL_Event events);

	//get set thiet lap va truy xuat gia tri di chuyen
	void set_x_val(const int& val) {
		x_val_ = val;
	}
	void set_y_val(const int& val) {
		y_val_ = val;
	}
	int get_x_val() const {
		return x_val_;
	}
	int get_y_val() const {
		return y_val_;
	}

	//phuong thuc SetAmoList quan ly danh sach dan
	void SetAmoList(std::vector<AmoObject*> amo_list)
	{
		p_amo_list_ = amo_list;
	}
	std::vector<AmoObject*> GetAmoList() const {
		return p_amo_list_;
	}

	void InitAmo(AmoObject* p_amo);//khoi tao dan
	void MakeAmo(SDL_Surface* des, const int& _limit, const int& y_limit);//dan ban tu doi tuong de doa

	//xu ly va cham dan
	void Reset(const int& xboder);
	void ResetAmo(AmoObject* p_amo);
	//

private:
	int x_val_;
	int y_val_;


	std::vector<AmoObject*> p_amo_list_;

};




#endif // !THREATS_OBJECT_H_
