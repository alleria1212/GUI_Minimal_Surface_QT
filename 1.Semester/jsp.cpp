#include <iostream>
#include <cassert>
#include <cmath>

using namespace std;

class jsp_long_long {
private:
public:
	static long long mask;
	double v;
	long long assoc_mask;
	long long dep;

	jsp_long_long();
	bool get_dep_from(const jsp_long_long &x);

	friend jsp_long_long sin(const jsp_long_long&);
	friend jsp_long_long cos(const jsp_long_long&);
	friend jsp_long_long exp(const jsp_long_long&);
	friend jsp_long_long operator*(const jsp_long_long &l, const jsp_long_long &r);
};

jsp_long_long operator*(const jsp_long_long &l, const jsp_long_long &r);

