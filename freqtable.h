#ifndef FREQTABLE_H_INCLUDED
#define FREQTABLE_H_INCLUDED

#include <map>

class CStreamWriter;

class CFreqTable{
  protected:
    map<char, unsigned __int64> *pTable;
  public:
    CFreqTable();
    CFreqTable( map<char, unsigned __int64> *);
    unsigned __int64 getFreq( char c );
    void outTable();
    void outTableFile( CStreamWriter& );
    ~CFreqTable();
};
#endif //FREQTABLE_H_INCLUDED
