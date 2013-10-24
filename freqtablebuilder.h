#ifndef FREQTABLEBUILDER_H_INCLUDED
#define FREQTABLEBUILDER_H_INCLUDED

#include <map>
#include "streamreader.h"

class CFreqTable;

class CFreqTableBuilder{
  protected:
    map<char, unsigned __int64> Table;
  public:
    CFreqTableBuilder();
    void add( char );
    CFreqTable makeTable( CStreamReader& );
    CFreqTable makeTableFromFile( CStreamReader& cStreamReader );
    map<char, unsigned __int64> getTable();
    ~CFreqTableBuilder();
};
#endif // FREQTABLEBUILDER_H_INCLUDED
