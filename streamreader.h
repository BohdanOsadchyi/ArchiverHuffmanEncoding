#ifndef STREAMREADER_H_INCLUDED
#define STREAMREADER_H_INCLUDED

#include <fstream>
#include <string>
using namespace std;

class CStreamReader{
  public:
    virtual char getNext() = 0;
    virtual unsigned __int64 getNumber() = 0;
    virtual bool isFinished() = 0;
    virtual void reset() = 0;
    virtual void close() = 0;
};

#endif //STREAMREADER_H_INCLUDED
