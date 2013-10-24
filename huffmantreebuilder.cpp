#include <utility>
#include <vector>
#include "snode.h"

#include "freqtablebuilder.h"
#include "huffmantree.h"
#include "huffmantreebuilder.h"

CHuffmanTreeBuilder :: CHuffmanTreeBuilder( CFreqTableBuilder cFreqTableBuilder ){
  map<char, unsigned __int64> mTable;
  mTable = cFreqTableBuilder.getTable();
  map<char, unsigned __int64> :: iterator it;
  SNode sNodeTemp;
  unsigned __int64 count = 0;
  for( it = mTable.begin(); it != mTable.end(); ++it ){
    sNodeTemp.nName = int(it -> first);
    sNodeTemp.Freq = it -> second;
    sNodeTemp.nLeft = -1;
    sNodeTemp.nRight = -1;
    Vertex.push_back( sNodeTemp );
    count++;
    Top.insert(make_pair( it -> second, count - 1 ));
    Unique.insert( sNodeTemp.nName );
  }
}

void CHuffmanTreeBuilder :: out(){
  multiset<pair< unsigned __int64, unsigned __int64> > :: iterator itTop;
  set<unsigned __int64> :: iterator itUnique;
  vector<SNode> :: iterator itVertex;
  printf( "Top:\n" );
  for( itTop = Top.begin(); itTop != Top.end(); ++itTop )
    printf( "first = %llu\tsecond = %llu\n", itTop -> first, itTop -> second );
  printf( "Unique:\n" );
  for( itUnique = Unique.begin(); itUnique != Unique.end(); ++itUnique )
    printf( "Unique[i] = %llu\n", *itUnique );
  printf( "Vertex:\n" );
  for( itVertex = Vertex.begin(); itVertex != Vertex.end(); ++itVertex )
    printf( "nName = %llu\tFreq = %llu\tnLeft = %lld\tnRight = %lld\n", (*itVertex).nName,(*itVertex).Freq,(*itVertex).nLeft,(*itVertex).nRight);
}

CHuffmanTree CHuffmanTreeBuilder :: makeTree(){
  pair<unsigned __int64, unsigned __int64> pTemp;
  multiset<pair<unsigned __int64, unsigned __int64> > :: iterator it;
  set<unsigned __int64> :: iterator itUnique;

  unsigned __int64 m = (unsigned __int64)Vertex.size();
  while( Top.size() > 1 ){
    SNode sNodeTemp;
    it = Top.begin();
    sNodeTemp.nLeft = it -> second;
    sNodeTemp.Freq = it -> first;
    Top.erase( it );

    it = Top.begin();
    sNodeTemp.nRight = it -> second;
    sNodeTemp.Freq += it -> first;
    Top.erase( it );

    itUnique = Unique.end();
    itUnique--;
    unsigned __int64 name = *itUnique;
    name++;
    sNodeTemp.nName = name;
    Vertex.push_back( sNodeTemp );
    m++;
    pTemp.first = sNodeTemp.Freq;
    pTemp.second = m - 1;
    Unique.insert( name );
    Top.insert( pTemp );
  }
  return *(new CHuffmanTree( Vertex ));
}
