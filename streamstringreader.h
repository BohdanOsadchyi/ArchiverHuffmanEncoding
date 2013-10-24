#ifndef STREAMSTRINGREADER_H_INCLUDED
#define STREAMSTRINGREADER_H_INCLUDED

#include "streamreader.h"

#include <sstream>
using namespace std;

class CStreamStringReader : public CStreamReader{
  protected:
    istringstream iss;
  public:
    CStreamStringReader( string );
    char getNext();
    unsigned __int64 getNumber();
    bool isFinished();
    void reset();
    void close();
};

#endif //STREAMREADER_H_INCLUDED
