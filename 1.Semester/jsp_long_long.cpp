#include "jsp_long_long.hpp"

jsp_long_long::jsp_long_long(): v(0.), dep(0)  
{ 
	dep = assoc_mask = mask; 
	mask <<= 1;
}

bool jsp_long_long::get_dep_from(const jsp_long_long &x)
{
	return dep & x.assoc_mask; 
}

jsp_long_long 
sin(const jsp_long_long &x) 
{ 
	jsp_long_long tmp;
	tmp.v = sin(x.v); 
	tmp.dep = x.dep; 
	return tmp;
}

jsp_long_long 
cos(const jsp_long_long &x) 
{ 
	jsp_long_long tmp;
	tmp.v = cos(x.v); 
	tmp.dep = x.dep; 
	return tmp;
}

jsp_long_long 
exp(const jsp_long_long &x) 
{ 
	jsp_long_long tmp;
	tmp.v = exp(x.v); 
	tmp.dep = x.dep; 
	return tmp;
}

jsp_long_long 
operator*(const jsp_long_long &l, const jsp_long_long &r)
{
	jsp_long_long tmp;
	tmp.v = l.v*r.v;
	tmp.dep = l.dep | r.dep;
	return tmp;
}

long long jsp_long_long::mask = 1;
