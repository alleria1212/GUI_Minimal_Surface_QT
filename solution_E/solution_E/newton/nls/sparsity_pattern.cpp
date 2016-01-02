#include<fstream>
#include<iostream>
using namespace std;

void SparsityPattern(const char* fname, int& n, int& m, pair<int,int>*& nz) {
  ifstream f(fname);
  double d;
  if(f.good()){
      // skip through header
      while(f.peek() == '%'){
          f.ignore(1024,'\n');
      }

      // read n,m from meta data line
      f >> n; f >> n; f >> m; // read n and m
      // also accept Uwe's file format with 4th number in meta line
      if(f.peek() != '\n')
          f >> d;

      nz=new pair<int,int>[m];

      // read first data line and
      // determine if 2 or 3 columns
      bool twoRowFile = true;
      f >> nz[0].first; nz[0].first--;
      f >> nz[0].second; nz[0].second--;
      if(f.peek() != '\n'){
          twoRowFile = false;
          f >> d;
          cout << "reading three row file " << endl;
      }else{
          cout << "reading two row file "   << endl;
      }

      // read reamining lines
      for (int i=1;i<m;i++) {
          f >> nz[i].first; nz[i].first--;
          f >> nz[i].second; nz[i].second--;
          if(!twoRowFile)
              f >> d;
      }
      f.close();
      cout << "n is " << n << " m is " << m << endl;
  }else{
      cout << "Error Opening File: " << fname << endl;
  }
}
