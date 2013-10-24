#ifndef DECODE_H_INCLUDED
#define DECODE_H_INCLUDED

using namespace std;

class CHuffmanTree;

class CDecode{
  protected:
    CHuffmanTree *pHuffmanTree;
  public:
    CDecode( CHuffmanTree* );
    void decode( CStreamReader&, CStreamWriter&, unsigned __int64);
    bool getBit( int, int );
};

#endif //DECODE_H_INCLUDED
