#ifndef JSP_INCLUDED_
#define JSP_INCLUDED_

#ifdef FLAT
    //#include "boost_flat_set.hpp"
    //#include "../utils/boost_1_58_0/boost/container/flat_set.hpp"
    #include <flat_set.hpp>
    #include <iostream>
    #define MYSET boost::container::flat_set
#else
    #include<set>
    #include <iostream>
    #define MYSET set
#endif

using namespace std;

  class jsp {
    public :
      double v; 
      MYSET<int> nz;
      inline jsp(const double& x);
      inline jsp();
      inline jsp& operator=(const jsp& x);
      inline jsp& operator=(const double& a);
  };

  inline jsp operator*(const jsp& x1, const jsp& x2);
  inline jsp operator*(const double& a1, const jsp& x2);
  inline jsp operator*(const jsp& x1, const double& a2);

  inline jsp operator+(const jsp& x1, const jsp& x2);
  inline jsp operator+(const double& a1, const jsp& x2);
  inline jsp operator+(const jsp& x1, const double& a2);

  inline jsp operator-(const jsp& x1, const jsp& x2);
  inline jsp operator-(const double& a1, const jsp& x2);
  inline jsp operator-(const jsp& x1, const double& a2);

  inline jsp operator/(const jsp& x1, const jsp& x2);
  inline jsp operator/(const double& a1, const jsp& x2);
  inline jsp operator/(const jsp& x1, const double& a2);

  inline bool operator<(const jsp& x1, const jsp& x2);
  inline bool operator<(const double& a1, const jsp& x2);
  inline bool operator<(const jsp& x1, const double& a2);

  inline bool operator<=(const jsp& x1, const jsp& x2);
  inline bool operator<=(const double& a1, const jsp& x2);
  inline bool operator<=(const jsp& x1, const double& a2);

  inline bool operator>(const jsp& x1, const jsp& x2);
  inline bool operator>(const double& a1, const jsp& x2);
  inline bool operator>(const jsp& x1, const double& a2);

  inline bool operator>=(const jsp& x1, const jsp& x2);
  inline bool operator>=(const double& a1, const jsp& x2);
  inline bool operator>=(const jsp& x1, const double& a2);

  inline bool operator==(const jsp& x1, const jsp& x2);
  inline bool operator==(const double& a1, const jsp& x2);
  inline bool operator==(const jsp& x1, const double& a2);

  inline bool operator!=(const jsp& x1, const jsp& x2);
  inline bool operator!=(const double& a1, const jsp& x2);
  inline bool operator!=(const jsp& x1, const double& a2);

  inline jsp sin(const jsp& x);
  inline jsp cos(const jsp& x);
  inline jsp exp(const jsp& x);
  inline jsp atan(const jsp& x);
  inline jsp sqrt(const jsp& x);

  inline jsp pow(const jsp& x, const double& c);
  inline jsp pow(const jsp& x1, const jsp& x2);
  inline jsp pow(const double& a1, const jsp& x2);

  #include "jsp_impl.hpp" 

#endif

