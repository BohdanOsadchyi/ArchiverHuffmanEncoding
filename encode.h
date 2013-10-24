#ifndef ENCODE_H_INCLUDED
#define ENCODE_H_INCLUDED

#include <vector>

using namespace std;

class CEncode{
  protected:
      vector<bool> Bool;
  public:
    CEncode();
    char ConvertToByte();
    void AddRange( vector<bool> );
    int Length();
};

#endif //ENDCODE_H_INCLUDED
