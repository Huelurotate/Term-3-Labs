#include "businessman.h"



ostream& operator<<(ostream& stream_obj, const Businessman& bm_obj)
{
	bm_obj.print();
	return stream_obj;
}

istream& operator>>(istream& stream_obj, Businessman& bm_obj)
{


	return stream_obj;
}