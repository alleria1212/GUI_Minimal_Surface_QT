#include <cmath>
#include <algorithm>
#include <functional>
using namespace std;
#include "jsp.hpp"

  jsp::jsp(const double& x): v(x) { nz.clear(); };
  jsp::jsp(): v(0) { nz.clear(); };

  jsp& jsp::operator=(const jsp& x) {
    if (this==&x) return *this;
    v=x.v; nz=x.nz; 
    return *this;
  }

  jsp& jsp::operator=(const double& a) {
    this->v=a; nz.clear(); 
    return *this;
  }

  jsp operator*(const jsp& x1, const jsp& x2) {
    jsp tmp;
    tmp.v=x1.v*x2.v; 
    set<int>::iterator i;
    if (x2.v||!x2.nz.empty()) for (i=x1.nz.begin();i!=x1.nz.end();i++) tmp.nz.insert(*i);
    if (x1.v||!x1.nz.empty()) for (i=x2.nz.begin();i!=x2.nz.end();i++) tmp.nz.insert(*i);
    return tmp;
  }

  jsp operator*(const double& a1, const jsp& x2){
    jsp tmp;
    tmp.v=a1*x2.v; 
    set<int>::iterator i;
    for (i=x2.nz.begin();i!=x2.nz.end();i++) tmp.nz.insert(*i);
    return tmp;
  }

  jsp operator*(const jsp& x1, const double& a2){
    jsp tmp;
    tmp.v=x1.v*a2; 
    set<int>::iterator i;
    for (i=x1.nz.begin();i!=x1.nz.end();i++) tmp.nz.insert(*i);
    return tmp;
  }

  jsp operator+(const jsp& x1, const jsp& x2) {
    jsp tmp;
    tmp.v=x1.v+x2.v; 
    set<int>::iterator i;
    for (i=x1.nz.begin();i!=x1.nz.end();i++) tmp.nz.insert(*i);
    for (i=x2.nz.begin();i!=x2.nz.end();i++) tmp.nz.insert(*i);
    return tmp;
  }

  jsp operator+(const double& a1, const jsp& x2){
    jsp tmp;
    tmp.v=a1+x2.v; 
    set<int>::iterator i;
    for (i=x2.nz.begin();i!=x2.nz.end();i++) tmp.nz.insert(*i);
    return tmp;
  }

  jsp operator+(const jsp& x1, const double& a2){
    jsp tmp;
    tmp.v=x1.v+a2; 
    set<int>::iterator i;
    for (i=x1.nz.begin();i!=x1.nz.end();i++) tmp.nz.insert(*i);
    return tmp;
  }

  jsp operator-(const jsp& x1, const jsp& x2) {
    jsp tmp;
    tmp.v=x1.v-x2.v; 
    set<int>::iterator i;
    for (i=x1.nz.begin();i!=x1.nz.end();i++) tmp.nz.insert(*i);
    for (i=x2.nz.begin();i!=x2.nz.end();i++) tmp.nz.insert(*i);
    return tmp;
  }

  jsp operator-(const double& a1, const jsp& x2){
    jsp tmp;
    tmp.v=a1-x2.v; 
    set<int>::iterator i;
    for (i=x2.nz.begin();i!=x2.nz.end();i++) tmp.nz.insert(*i);
    return tmp;
  }

  jsp operator-(const jsp& x1, const double& a2){
    jsp tmp;
    tmp.v=x1.v-a2; 
    set<int>::iterator i;
    for (i=x1.nz.begin();i!=x1.nz.end();i++) tmp.nz.insert(*i);
    return tmp;
  }

  jsp operator/(const jsp& x1, const jsp& x2) {
    jsp tmp;
    tmp.v=x1.v/x2.v; 
    set<int>::iterator i;
    for (i=x1.nz.begin();i!=x1.nz.end();i++) tmp.nz.insert(*i);
    for (i=x2.nz.begin();i!=x2.nz.end();i++) tmp.nz.insert(*i);
    return tmp;
  }

  jsp operator/(const double& a1, const jsp& x2){
    jsp tmp;
    tmp.v=a1/x2.v; 
    set<int>::iterator i;
    for (i=x2.nz.begin();i!=x2.nz.end();i++) tmp.nz.insert(*i);
    return tmp;
  }

  jsp operator/(const jsp& x1, const double& a2){
    jsp tmp;
    tmp.v=x1.v/a2; 
    set<int>::iterator i;
    for (i=x1.nz.begin();i!=x1.nz.end();i++) tmp.nz.insert(*i);
    return tmp;
  }

  bool operator<(const jsp& x1, const jsp& x2) {
    return (x1.v < x2.v);
  }
  bool operator<(const double& a1, const jsp& x2) {
    return (a1 < x2.v);
  }
  bool operator<(const jsp& x1, const double& a2) {
    return (x1.v < a2);
  }

  bool operator<=(const jsp& x1, const jsp& x2) {
    return (x1.v <= x2.v);
  }
  bool operator<=(const double& a1, const jsp& x2) {
    return (a1 <= x2.v);
  }
  bool operator<=(const jsp& x1, const double& a2) {
    return (x1.v <= a2);
  }

  bool operator>(const jsp& x1, const jsp& x2) {
    return (x1.v > x2.v);
  }
  bool operator>(const double& a1, const jsp& x2) {
    return (a1 > x2.v);
  }
  bool operator>(const jsp& x1, const double& a2) {
    return (x1.v > a2);
  }

  bool operator>=(const jsp& x1, const jsp& x2) {
    return (x1.v >= x2.v);
  }
  bool operator>=(const double& a1, const jsp& x2) {
    return (a1 >= x2.v);
  }
  bool operator>=(const jsp& x1, const double& a2) {
    return (x1.v >= a2);
  }

  bool operator==(const jsp& x1, const jsp& x2) {
    return (x1.v == x2.v);
  }
  bool operator==(const double& a1, const jsp& x2) {
    return (a1 == x2.v);
  }
  bool operator==(const jsp& x1, const double& a2) {
    return (x1.v == a2);
  }

  bool operator!=(const jsp& x1, const jsp& x2) {
    return (x1.v != x2.v);
  }
  bool operator!=(const double& a1, const jsp& x2) {
    return (a1 != x2.v);
  }
  bool operator!=(const jsp& x1, const double& a2) {
    return (x1.v != a2);
  }

  jsp sin(const jsp& x) {
    jsp tmp;
    tmp.v=sin(x.v); 
    tmp.nz=x.nz;
    return tmp;
  }

  jsp cos(const jsp& x) {
    jsp tmp;
    tmp.v=cos(x.v); 
    tmp.nz=x.nz;
    return tmp;
  }

  jsp exp(const jsp& x) {
    jsp tmp;
    tmp.v=exp(x.v); 
    tmp.nz=x.nz;
    return tmp;
  }

  jsp atan(const jsp& x) {
    jsp tmp;
    tmp.v=atan(x.v); 
    tmp.nz=x.nz;
    return tmp;
  }

  jsp sqrt(const jsp& x) {
    jsp tmp;
    tmp.v=sqrt(x.v); 
    tmp.nz=x.nz;
    return tmp;
  }

  jsp pow(const jsp& x, const double& c) {
    jsp tmp;
    tmp.v=pow(x.v, c); 
    tmp.nz=x.nz;
    return tmp;
  }
  jsp pow(const jsp& x1, const jsp& x2) {
    jsp tmp;
    tmp.v=pow(x1.v, x2.v); 
    set<int>::iterator i;
    for (i=x1.nz.begin();i!=x1.nz.end();i++) tmp.nz.insert(*i);
    for (i=x2.nz.begin();i!=x2.nz.end();i++) tmp.nz.insert(*i);
    return tmp;
  }
  jsp pow(const double& a1, const jsp& x2) {
    jsp tmp;
    tmp.v=pow(a1, x2.v); 
    set<int>::iterator i;
    for (i=x2.nz.begin();i!=x2.nz.end();i++) tmp.nz.insert(*i);
    return tmp;
  }


