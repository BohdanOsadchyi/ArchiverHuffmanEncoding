#ifndef STREAM_H_INCLUDED
#define STREAM_H_INCLUDED

//#include <iostream>
#include <fstream>

using namespace std;
///Розділити вхідний та вихідний потоки
class CStream{
  protected:
    ifstream fi;
    ofstream fo;
  public:
    CStream(char*,char*);
    char getNext();
    unsigned __int64 getNumber();
    bool getBit();
    bool isFinished();
    void reset();
    void resetout();
    void out();
    void put(char);
    void put(unsigned char);
    void put(unsigned __int64);
    void close();
};

#endif // STREAM_H_INCLUDED
