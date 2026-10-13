#include "businessman.h"

Businessman::Businessman(std::string surname, int year, std::string address) :
	Human(surname, year), Entrepreneur(), Tourist(),
{
	this->adresses_arr[0] = address;
}

std::ostream& operator<<(std::ostream& stream_obj, const Businessman& bm_obj)
{
	bm_obj.print();
	return stream_obj;
}

std::istream& operator>>(std::istream& stream_obj, Businessman& bm_obj)
{


	return stream_obj;
}