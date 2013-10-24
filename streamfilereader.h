#ifndef STREAMFILEREADER_H_INCLUDED
#define STREAMFILEREADER_H_INCLUDED

#include "streamreader.h"

#include <fstream>

class CStreamFileReader : public CStreamReader{
  protected:
    ifstream fi;
  public:
    CStreamFileReader( char* );
    char getNext();
    unsigned __int64 getNumber();
    bool isFinished();
    void reset();
    void close();
};

#endif //STREAMREADER_H_INCLUDED
