#include <cstdio>
#include <string.h>

#include "streamreader.h"
#include "streamfilereader.h"
#include "streamstringreader.h"
#include "streamwriter.h"
#include "freqtable.h"
#include "freqtablebuilder.h"
#include "huffmantreebuilder.h"
#include "encode.h"
#include "facade.h"

using namespace std;

int main( int argc, char* argv[] ){
  string s = "BogdanOsadchiy";
  CFacade cFacade;
  if( argc == 1 )
    printf( "You must create command!!!\n" );
  else {
    if( strcmp( argv[1], "s" ) == 0 ){
      CStreamReader *pStreamReader = new CStreamStringReader( s );
      CStreamWriter cStreamWriter( argv[2] );
      cFacade.EncodeData( *pStreamReader, cStreamWriter );
      pStreamReader -> close();
      cStreamWriter.close();
    }
    else{
      if( strcmp( argv[1], "e" ) == 0 ){
        CStreamReader *pStreamReader = new CStreamFileReader( argv[2] );
        CStreamWriter cStreamWriter( argv[3] );
        cFacade.EncodeData( *pStreamReader, cStreamWriter );
        pStreamReader -> close();
        cStreamWriter.close();
      }
      else{
        if( strcmp(argv[1],"d") == 0 ){
          CStreamReader *pStreamReader = new CStreamFileReader( argv[2] );
          CStreamWriter cStreamWriter( argv[3] );
          cFacade.DecodeData( *pStreamReader, cStreamWriter );
          pStreamReader -> close();
          cStreamWriter.close();
        }
      }
    }
  }
  return 0;
}

