#include "streamreader.h"
#include "streamwriter.h"
#include "freqtablebuilder.h"
#include "freqtable.h"
#include "huffmantreebuilder.h"
#include "huffmantree.h"
#include "decode.h"

#include "facade.h"

const int BYTE_SIZE = 8;

void CFacade :: EncodeData( CStreamReader& cStreamReader, CStreamWriter& cStreamWriter ){
  CFreqTableBuilder cFreqTableBuilder;
  CFreqTable cFreqTable = cFreqTableBuilder.makeTable( cStreamReader );
  CHuffmanTreeBuilder cHuffmanTreeBuilder( cFreqTableBuilder );
  CHuffmanTree cHuffmanTree = cHuffmanTreeBuilder.makeTree();
  cHuffmanTree.makeTableCode();
  //cHuffmanTree.outTableCode();
  cFreqTable.outTableFile( cStreamWriter );
  CEncode cEncode;
  cStreamReader.reset();
  char c;
  while( 1 ){
    c = cStreamReader.getNext();
    cEncode = cHuffmanTree.encode( cEncode, c );
    if( cEncode.Length() >= BYTE_SIZE )
      cStreamWriter.put( cEncode.ConvertToByte() );
    if( cStreamReader.isFinished() ){
      if( cEncode.Length() ) cStreamWriter.put( cEncode.ConvertToByte() );
      cStreamWriter.resetout();
      cStreamWriter.put( (unsigned __int64) cEncode.Length() );
      cStreamWriter.close();
      cStreamReader.close();
      return;
    }
  }
  cStreamWriter.close();
  cStreamReader.close();
}

void CFacade :: DecodeData( CStreamReader& cStreamReader, CStreamWriter& cStreamWriter ){
  unsigned __int64 tail = cStreamReader.getNumber();
  CFreqTableBuilder cFreqTableBuilder;
  CFreqTable cFreqTable = cFreqTableBuilder.makeTableFromFile( cStreamReader );
  CHuffmanTreeBuilder cHuffmanTreeBuilder( cFreqTableBuilder );
  CHuffmanTree cHuffmanTree = cHuffmanTreeBuilder.makeTree();
  cHuffmanTree.makeTableCode();
  //cHuffmanTree.outTableCode();
  CDecode cDecode( &cHuffmanTree );
  cDecode.decode( cStreamReader, cStreamWriter, tail );
}
