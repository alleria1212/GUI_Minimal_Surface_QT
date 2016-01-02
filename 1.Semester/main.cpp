/*
   Loesung mit Datentyp 'long long' der laut Standard nicht kleiner als 64 bit sein darf.
*/

#include <iostream>
#include <cmath>
#include <cassert>
#include <cstdlib>
#include <ctime>
#include "jsp_long_long.hpp"

using namespace std;


void f(const int n, jsp_long_long *x, const int m, jsp_long_long *y)
{
	#include "f.c"
}


int main()
{
	const int n = 3;
	const int m = 3;
	jsp_long_long x[n];
	jsp_long_long y[m];

	f(n, x, m, y);

	cout << "Abhaengigkeiten:\n";
	for(int j=0;j<m;j++) {
		cout << "y["<<j<<"]: " ;
		for(int i=0;i<n;i++) {
			cout << y[j].get_dep_from(x[i]) << "    ";
		}
		cout << endl;
	}

}