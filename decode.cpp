#include "huffmantree.h"
#include "streamreader.h"
#include "streamwriter.h"
#include "decode.h"

const int BYTE_SIZE = 8;

CDecode :: CDecode( CHuffmanTree *_pHuffmanTree ) : pHuffmanTree( _pHuffmanTree ) {}

bool CDecode :: getBit( int n, int c ){
  int i = 0;
  while( i < n ){
    c >>= 1;
    i++;
  }
  return (c & 1);
}

void CDecode :: decode( CStreamReader& cStreamReader, CStreamWriter& cStreamWriter, unsigned __int64 tail ){
  bool flag = false;
  unsigned char cFirst, cSecond;
  int i, nByte, nSteps = BYTE_SIZE;
  SNode sTemp = pHuffmanTree -> getRootNode();
  cFirst = cStreamReader.getNext();
  while( !flag ){
    i = 0;
    cSecond = cStreamReader.getNext();
    nByte = (int)cFirst + ( (int)cFirst < 0 ) * BYTE_SIZE * BYTE_SIZE;
    if ( cStreamReader.isFinished() ){
      nSteps = tail + 1;
      flag = true;
    }
    while( i < nSteps ){
      if( sTemp.isLeaf() ) {
        //printf( "DECODE nName = %c\n", sTemp.nName );
        cStreamWriter.put( (unsigned char)sTemp.nName );
        sTemp = pHuffmanTree -> getRootNode();
      }
      if( getBit( BYTE_SIZE - 1 - i, nByte ) ) sTemp = pHuffmanTree -> getNode( sTemp.nLeft );
      else sTemp = pHuffmanTree -> getNode( sTemp.nRight );
      i++;
    }
    cFirst = cSecond;
  }
}
