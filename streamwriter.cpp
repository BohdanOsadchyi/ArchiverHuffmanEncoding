#include <iostream>
#include <fstream>
#include "streamreader.h"
#include "streamwriter.h"

CStreamWriter :: CStreamWriter( char* out ){
  fo.close();
  fo.open( out, ios :: binary );
}

void CStreamWriter :: resetout(){
  fo.seekp( 0, ios :: beg );
}

void CStreamWriter :: out( CStreamReader& cStreamReader ){
  char c;
  while(1){
    c = cStreamReader.getNext();
    if( cStreamReader.isFinished() ) return;
    fo.put( c );
  }
}

void CStreamWriter :: put( char c ){
  fo.put( c );
}

void CStreamWriter :: put( unsigned char c ){
  fo.put( c );
}

void CStreamWriter :: put( unsigned __int64 x ){
  fo << x << endl;
}

void CStreamWriter :: close(){
  fo.close();
}

