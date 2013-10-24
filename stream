#include <iostream>
#include <fstream>
#include "stream.h"

CStream :: CStream(char* in, char* out){
  fi.close(); fo.close();
  fi.open(in, ios :: binary);
  if (!fi) printf("Not found file : %s\n",in);
  fo.open(out, ios :: binary);
}

char CStream :: getNext(){
  char c;
  fi.get(c);
  return c;
}

unsigned __int64 CStream :: getNumber(){
  unsigned __int64 x;
  fi >> x;
  char c;
  fi.get(c);
  return x;
}

bool CStream :: isFinished(){
  return fi.eof();
}

void CStream :: reset(){
  fi.clear();
  fi.seekg(0,ios :: beg);
}

void CStream :: resetout(){
  fo.seekp(0,ios :: beg);
}
void CStream :: out(){
  char c;
  while(1){
    c = getNext();
    if (isFinished()) return;
    fo.put(c);
  }
}

void CStream :: put(char c){
  fo.put(c);
}

void CStream :: put(unsigned char c){
  fo.put(c);
}

void CStream :: put(unsigned __int64 x){
  fo << x << endl;
}
void CStream :: close(){
  fi.close();
  fo.close();
}

