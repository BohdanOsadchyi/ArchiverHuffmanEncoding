#include "streamwriter.h"
//#include "stream.h"
#include "freqtable.h"

CFreqTable :: CFreqTable(){}

CFreqTable :: CFreqTable( map<char, unsigned __int64> *_pTable ) : pTable( _pTable ){}

unsigned __int64 CFreqTable :: getFreq( char c ){
  return ( *pTable )[c];
}

void CFreqTable :: outTable(){
  if( pTable -> empty() ){
    printf( "You haven't makeTable\n" );
    return;
  }
  map <char, unsigned __int64> :: iterator it;
  for( it = pTable -> begin(); it != pTable -> end(); it++ )
    printf( "(int)c = %d count = %llu\n", (int)it->first, it->second );
}

void CFreqTable :: outTableFile( CStreamWriter& cStreamWriter ){
  cStreamWriter.put( (unsigned __int64) 0 );
  cStreamWriter.put( (unsigned __int64) pTable -> size() );
  map<char, unsigned __int64> :: iterator it;
  for( it = pTable -> begin(); it != pTable -> end(); it++ ){
    cStreamWriter.put( it->first );
    cStreamWriter.put( ' ' );
    cStreamWriter.put( it->second );
  }
}

CFreqTable :: ~CFreqTable(){
  pTable -> clear();
}
