#ifndef STREAMWRITER_H_INCLUDES
#define STREAMWRITER_H_INCLUDES

#include <fstream>
using namespace std;

class CStreamReader;

class CStreamWriter{
  protected:
    ofstream fo;
  public:
    CStreamWriter( char* );
    void resetout();
    void out( CStreamReader& );
    void put( char );
    void put( unsigned char );
    void put( unsigned __int64 );
    void close();
};

#endif//STREAMWRITER_H_INCLUDES
