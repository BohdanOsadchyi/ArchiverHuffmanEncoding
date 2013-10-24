#include <fstream>

#include "streamfilereader.h"

CStreamFileReader :: CStreamFileReader( char* in ){
  fi.close();
  fi.open( in, ios :: binary );
  if( !fi ) printf( "Not found file : %s\n", in );
}

char CStreamFileReader :: getNext(){
  char c;
  fi.get( c );
  return c;
}

unsigned __int64 CStreamFileReader :: getNumber(){
  unsigned __int64 x;
  fi >> x;
  char c;
  fi.get( c );
  return x;
}

bool CStreamFileReader :: isFinished(){
  return fi.eof();
}

void CStreamFileReader :: reset(){
  fi.clear();
  fi.seekg( 0, ios :: beg );
}

void CStreamFileReader :: close(){
  fi.close();
}
