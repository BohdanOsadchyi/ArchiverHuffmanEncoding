#include <fstream>

#include "streamstringreader.h"

CStreamStringReader :: CStreamStringReader( string s ){
  iss.str( s );
  if( !iss ) printf( "Problem with CStreamReader : %s\n", s.c_str() );
}

char CStreamStringReader :: getNext(){
  char c;
  iss.get( c );
  return c;
}

unsigned __int64 CStreamStringReader :: getNumber(){
  unsigned __int64 x;
  iss >> x;
  char c;
  iss.get( c );
  return x;
}

bool CStreamStringReader :: isFinished(){
  return iss.eof();
}

void CStreamStringReader :: reset(){
  iss.clear();
  iss.seekg( 0, ios :: beg );
}

void CStreamStringReader :: close(){
  iss.clear();
}
