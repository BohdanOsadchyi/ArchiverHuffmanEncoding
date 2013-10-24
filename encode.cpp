#include "encode.h"
#include <cstdio>

const int BYTE_SIZE = 8;

CEncode :: CEncode(){
  Bool.clear();
}

char CEncode :: ConvertToByte(){
  char res = 0;
  for ( int i = BYTE_SIZE; i > 0; i--  )
    res += (int(Bool[BYTE_SIZE - i])) << (i - 1);
  if( Length() >= BYTE_SIZE ) Bool.erase( Bool.begin(), Bool.begin() + BYTE_SIZE );
  return res;
}

void CEncode :: AddRange( vector<bool> Code ){
  Bool.insert( Bool.end(), Code.begin(), Code.end() );
}

int CEncode :: Length(){
  return (int)Bool.size();
}

