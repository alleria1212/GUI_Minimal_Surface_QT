#include <cmath>
#include "dco_t1s_type.hpp"

  dco_t1s_type::dco_t1s_type(const double& x): v(x), t(0) { }
  dco_t1s_type::dco_t1s_type(): v(0), t(0) { }

  dco_t1s_type& dco_t1s_type::operator=(const dco_t1s_type& x) {
    if (this==&x) return *this;
    v=x.v; t=x.t; 
    return *this;
  }

  dco_t1s_type& dco_t1s_type::operator=(const double& x) {
    v=x; t=0; 
    return *this;
  }

  bool operator > (const dco_t1s_type& x1, const double& x2){
      return x1.v > x2;
  }

  dco_t1s_type operator*(const dco_t1s_type& x1, const dco_t1s_type& x2) {
    dco_t1s_type tmp;
    tmp.v=x1.v*x2.v; 
    tmp.t=x1.t*x2.v+x1.v*x2.t;
    return tmp;
  }

  dco_t1s_type operator+(const dco_t1s_type& x1, const dco_t1s_type& x2) {
    dco_t1s_type tmp;
    tmp.v=x1.v+x2.v; 
    tmp.t=x1.t+x2.t;
    return tmp;
  }

  dco_t1s_type operator-(const dco_t1s_type& x1, const dco_t1s_type& x2) {
    dco_t1s_type tmp;
    tmp.v=x1.v-x2.v; 
    tmp.t=x1.t-x2.t;
    return tmp;
  }

  dco_t1s_type operator/(const dco_t1s_type& x1, const dco_t1s_type& x2) {
    dco_t1s_type tmp;
    tmp.v = x1.v / x2.v;
    tmp.t = (x1.t*x2.v - x2.t*x1.v)/(x2.v*x2.v);
    return tmp;
  }

  dco_t1s_type sin(const dco_t1s_type& x) {
    dco_t1s_type tmp;
    tmp.v=std::sin(x.v);
    tmp.t=std::cos(x.v)*x.t;
    return tmp;
  }

  dco_t1s_type cos(const dco_t1s_type& x) {
    dco_t1s_type tmp;
    tmp.v=std::cos(x.v);
    tmp.t=-std::sin(x.v)*x.t;
    return tmp;
  }

  dco_t1s_type exp(const dco_t1s_type& x) {
    dco_t1s_type tmp;
    tmp.v=std::exp(x.v);
    tmp.t=tmp.v*x.t;
    return tmp;
  }

  dco_t1s_type sqrt(const dco_t1s_type& x){
    dco_t1s_type tmp;
    tmp.v = std::sqrt(x.v);
    tmp.t = 1/2 * x.t/std::sqrt(x.v);
    return tmp;
  }
