#include <cmath>
#include <algorithm>
#include <functional>
using namespace std;
#include "jsp.hpp"

  inline jsp::jsp(const double& x): v(x) { nz.clear(); };
  inline jsp::jsp(): v(0) { nz.clear(); };

  inline jsp& jsp::operator=(const jsp& x) {
    if (this==&x) return *this;
    v=x.v; nz=x.nz;
    //std::cout << "operator= " << x.nz.size() << std::endl;
    return *this;
  }

  inline jsp& jsp::operator=(const double& a) {
    this->v=a; nz.clear(); 
    return *this;
  }
//#define OPT
#ifdef OPT
  inline jsp operator*(const jsp& x1, const jsp& x2) {
    jsp tmp;
    tmp.v=x1.v*x2.v;
    //std::cout << "operator* " << x1.nz.size() << " " << x2.nz.size() << std::endl;
    if (x2.v||!x2.nz.empty()) tmp.nz.insert(x1.nz.begin(),x1.nz.end());
    if (x1.v||!x1.nz.empty()) tmp.nz.insert(x2.nz.begin(),x2.nz.end());
    return tmp;
  }

  inline jsp operator*(const double& a1, const jsp& x2){
    jsp tmp;
    tmp.v=a1*x2.v; 
    tmp.nz = x2.nz;
    return tmp;
  }

  inline jsp operator*(const jsp& x1, const double& a2){
    jsp tmp;
    tmp.v=x1.v*a2; 
    tmp.nz = x1.nz;
    return tmp;
  }

  inline jsp operator+(const jsp& x1, const jsp& x2) {
    jsp tmp;
    tmp.v=x1.v+x2.v; 
    tmp.nz = x1.nz;
    tmp.nz.insert(x2.nz.begin(),x2.nz.end());
    //std::cout << "operator+ " << x1.nz.size() << " " << x2.nz.size() << std::endl;
    return tmp;
  }

  inline jsp operator+(const double& a1, const jsp& x2){
    jsp tmp;
    tmp.v=a1+x2.v; 
    tmp.nz = x2.nz;
    return tmp;
  }

  inline jsp operator+(const jsp& x1, const double& a2){
    jsp tmp;
    tmp.v=x1.v+a2; 
    tmp.nz = x1.nz;
    //std::cout << "operator+d " << x1.nz.size() << std::endl;
    return tmp;
  }

  inline jsp operator-(const jsp& x1, const jsp& x2) {
    jsp tmp;
    tmp.v=x1.v-x2.v; 
    tmp.nz = x1.nz;
    tmp.nz.insert(x2.nz.begin(),x2.nz.end());
    return tmp;
  }

  inline jsp operator-(const double& a1, const jsp& x2){
    jsp tmp;
    tmp.v=a1-x2.v; 
    tmp.nz = x2.nz;
    return tmp;
  }

  inline jsp operator-(const jsp& x1, const double& a2){
    jsp tmp;
    tmp.v=x1.v-a2; 
    tmp.nz = x1.nz;
    return tmp;
  }

  inline jsp operator/(const jsp& x1, const jsp& x2) {
    jsp tmp;
    tmp.v=x1.v/x2.v;
    tmp.nz = x1.nz;
    tmp.nz.insert(x2.nz.begin(),x2.nz.end());
    return tmp;
  }

  inline jsp operator/(const double& a1, const jsp& x2){
    jsp tmp;
    tmp.v=a1/x2.v;
    tmp.nz = x2.nz;
    return tmp;
  }

  inline jsp operator/(const jsp& x1, const double& a2){
    jsp tmp;
    tmp.v=x1.v/a2;
    tmp.nz = x1.nz;
    return tmp;
  }

  inline jsp pow(const jsp& x, const double& c) {
    jsp tmp;
    tmp.v=pow(x.v, c);
    tmp.nz=x.nz;
    return tmp;
  }
  inline jsp pow(const jsp& x1, const jsp& x2) {
    jsp tmp;
    tmp.v=pow(x1.v, x2.v);
    tmp.nz = x1.nz;
    tmp.nz.insert(x2.nz.begin(),x2.nz.end());
    return tmp;
  }
  inline jsp pow(const double& a1, const jsp& x2) {
    jsp tmp;
    tmp.v=pow(a1, x2.v);
    tmp.nz = x2.nz;
    return tmp;
  }
#else
  inline jsp operator*(const jsp& x1, const jsp& x2) {
    jsp tmp;
    tmp.v=x1.v*x2.v;
    set<int>::iterator i;
    if (x2.v||!x2.nz.empty()) for (i=x1.nz.begin();i!=x1.nz.end();i++) tmp.nz.insert(*i);
    if (x1.v||!x1.nz.empty()) for (i=x2.nz.begin();i!=x2.nz.end();i++) tmp.nz.insert(*i);
    return tmp;
  }

  inline jsp operator*(const double& a1, const jsp& x2){
    jsp tmp;
    tmp.v=a1*x2.v;
    set<int>::iterator i;
    for (i=x2.nz.begin();i!=x2.nz.end();i++) tmp.nz.insert(*i);
    return tmp;
  }

  inline jsp operator*(const jsp& x1, const double& a2){
    jsp tmp;
    tmp.v=x1.v*a2;
    set<int>::iterator i;
    for (i=x1.nz.begin();i!=x1.nz.end();i++) tmp.nz.insert(*i);
    return tmp;
  }

  inline jsp operator+(const jsp& x1, const jsp& x2) {
    jsp tmp;
    tmp.v=x1.v+x2.v;
    set<int>::iterator i;
    for (i=x1.nz.begin();i!=x1.nz.end();i++) tmp.nz.insert(*i);
    for (i=x2.nz.begin();i!=x2.nz.end();i++) tmp.nz.insert(*i);
    return tmp;
  }

  inline jsp operator+(const double& a1, const jsp& x2){
    jsp tmp;
    tmp.v=a1+x2.v;
    set<int>::iterator i;
    for (i=x2.nz.begin();i!=x2.nz.end();i++) tmp.nz.insert(*i);
    return tmp;
  }

  inline jsp operator+(const jsp& x1, const double& a2){
    jsp tmp;
    tmp.v=x1.v+a2;
    set<int>::iterator i;
    for (i=x1.nz.begin();i!=x1.nz.end();i++) tmp.nz.insert(*i);
    return tmp;
  }

  inline jsp operator-(const jsp& x1, const jsp& x2) {
    jsp tmp;
    tmp.v=x1.v-x2.v;
    set<int>::iterator i;
    for (i=x1.nz.begin();i!=x1.nz.end();i++) tmp.nz.insert(*i);
    for (i=x2.nz.begin();i!=x2.nz.end();i++) tmp.nz.insert(*i);
    return tmp;
  }

  inline jsp operator-(const double& a1, const jsp& x2){
    jsp tmp;
    tmp.v=a1-x2.v;
    set<int>::iterator i;
    for (i=x2.nz.begin();i!=x2.nz.end();i++) tmp.nz.insert(*i);
    return tmp;
  }

  inline jsp operator-(const jsp& x1, const double& a2){
    jsp tmp;
    tmp.v=x1.v-a2;
    set<int>::iterator i;
    for (i=x1.nz.begin();i!=x1.nz.end();i++) tmp.nz.insert(*i);
    return tmp;
  }

  inline jsp operator/(const jsp& x1, const jsp& x2) {
    jsp tmp;
    tmp.v=x1.v/x2.v;
    set<int>::iterator i;
    for (i=x1.nz.begin();i!=x1.nz.end();i++) tmp.nz.insert(*i);
    for (i=x2.nz.begin();i!=x2.nz.end();i++) tmp.nz.insert(*i);
    return tmp;
  }

  inline jsp operator/(const double& a1, const jsp& x2){
    jsp tmp;
    tmp.v=a1/x2.v;
    set<int>::iterator i;
    for (i=x2.nz.begin();i!=x2.nz.end();i++) tmp.nz.insert(*i);
    return tmp;
  }

  inline jsp operator/(const jsp& x1, const double& a2){
    jsp tmp;
    tmp.v=x1.v/a2;
    set<int>::iterator i;
    for (i=x1.nz.begin();i!=x1.nz.end();i++) tmp.nz.insert(*i);
    return tmp;
  }

  inline jsp pow(const jsp& x, const double& c) {
    jsp tmp;
    tmp.v=pow(x.v, c);
    tmp.nz=x.nz;
    return tmp;
  }
  inline jsp pow(const jsp& x1, const jsp& x2) {
    jsp tmp;
    tmp.v=pow(x1.v, x2.v);
    set<int>::iterator i;
    for (i=x1.nz.begin();i!=x1.nz.end();i++) tmp.nz.insert(*i);
    for (i=x2.nz.begin();i!=x2.nz.end();i++) tmp.nz.insert(*i);
    return tmp;
  }
  inline jsp pow(const double& a1, const jsp& x2) {
    jsp tmp;
    tmp.v=pow(a1, x2.v);
    set<int>::iterator i;
    for (i=x2.nz.begin();i!=x2.nz.end();i++) tmp.nz.insert(*i);
    return tmp;
  }
#endif

  inline bool operator<(const jsp& x1, const jsp& x2) {
    return (x1.v < x2.v);
  }
  inline bool operator<(const double& a1, const jsp& x2) {
    return (a1 < x2.v);
  }
  inline bool operator<(const jsp& x1, const double& a2) {
    return (x1.v < a2);
  }

  inline bool operator<=(const jsp& x1, const jsp& x2) {
    return (x1.v <= x2.v);
  }
  inline bool operator<=(const double& a1, const jsp& x2) {
    return (a1 <= x2.v);
  }
  inline bool operator<=(const jsp& x1, const double& a2) {
    return (x1.v <= a2);
  }

  inline bool operator>(const jsp& x1, const jsp& x2) {
    return (x1.v > x2.v);
  }
  inline bool operator>(const double& a1, const jsp& x2) {
    return (a1 > x2.v);
  }
  inline bool operator>(const jsp& x1, const double& a2) {
    return (x1.v > a2);
  }

  inline bool operator>=(const jsp& x1, const jsp& x2) {
    return (x1.v >= x2.v);
  }
  inline bool operator>=(const double& a1, const jsp& x2) {
    return (a1 >= x2.v);
  }
  inline bool operator>=(const jsp& x1, const double& a2) {
    return (x1.v >= a2);
  }

  inline bool operator==(const jsp& x1, const jsp& x2) {
    return (x1.v == x2.v);
  }
  inline bool operator==(const double& a1, const jsp& x2) {
    return (a1 == x2.v);
  }
  inline bool operator==(const jsp& x1, const double& a2) {
    return (x1.v == a2);
  }

  inline bool operator!=(const jsp& x1, const jsp& x2) {
    return (x1.v != x2.v);
  }
  inline bool operator!=(const double& a1, const jsp& x2) {
    return (a1 != x2.v);
  }
  inline bool operator!=(const jsp& x1, const double& a2) {
    return (x1.v != a2);
  }

  inline jsp sin(const jsp& x) {
    jsp tmp;
    tmp.v=sin(x.v); 
    tmp.nz=x.nz;
    return tmp;
  }

  inline jsp cos(const jsp& x) {
    jsp tmp;
    tmp.v=cos(x.v); 
    tmp.nz=x.nz;
    return tmp;
  }

  inline jsp exp(const jsp& x) {
    jsp tmp;
    tmp.v=exp(x.v); 
    tmp.nz=x.nz;
    return tmp;
  }

  inline jsp atan(const jsp& x) {
    jsp tmp;
    tmp.v=atan(x.v); 
    tmp.nz=x.nz;
    return tmp;
  }

  inline jsp sqrt(const jsp& x) {
    jsp tmp;
    tmp.v=sqrt(x.v); 
    tmp.nz=x.nz;
    return tmp;
  }


