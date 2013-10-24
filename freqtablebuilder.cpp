#include "streamreader.h"
#include "freqtablebuilder.h"
#include "freqtable.h"

CFreqTableBuilder :: CFreqTableBuilder(){
  Table.clear();
}

void CFreqTableBuilder :: add( char c ){
  Table[c]++;
}

map<char, unsigned __int64> CFreqTableBuilder :: getTable(){
  return Table;
}

CFreqTable CFreqTableBuilder :: makeTable( CStreamReader& cStreamReader ){
  cStreamReader.reset();
  char c;
  while( true ){
    c = cStreamReader.getNext();
    if ( cStreamReader.isFinished() ) break;
    add( c );
  }
  return *(new CFreqTable( &Table ));
}

CFreqTable CFreqTableBuilder :: makeTableFromFile( CStreamReader& cStreamReader ){
  unsigned __int64 n = cStreamReader.getNumber();
  char c;
  unsigned __int64 freq;
  for( int i = 0; i < n; ++i ){
    c = cStreamReader.getNext();
    cStreamReader.getNext();
    freq = cStreamReader.getNumber();
    Table[c] = freq;
  }
  return *(new CFreqTable( &Table ));
}


CFreqTableBuilder :: ~CFreqTableBuilder(){
  Table.clear();
}

