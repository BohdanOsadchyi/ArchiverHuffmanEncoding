#include <cstdio>
#include <string>
#include <vector>

#include "snode.h"
#include "encode.h"
#include "huffmantree.h"

CHuffmanTree :: CHuffmanTree(){
  Vertex.clear();
  Root = 0;
}

CHuffmanTree :: CHuffmanTree( vector <SNode> vTemp ){
  Vertex = vTemp;
  Root = ( unsigned __int64 )( vTemp.size() - 1 );
}

void CHuffmanTree :: makeCode( unsigned __int64 nChild, vector<bool> ParentCode ){
  vector<bool> :: iterator it;
  if( Vertex[nChild].isLeaf() ){
    mTableCode[ Vertex[nChild].nName ] = ParentCode;
  }
  if( Vertex[nChild].nLeft != -1 ){
    ParentCode.push_back( 1 );
    makeCode( Vertex[nChild].nLeft, ParentCode );
    ParentCode.erase( ParentCode.end() );
  }
  if( Vertex[nChild].nRight != -1 ){
    ParentCode.push_back( 0 );
    makeCode( Vertex[nChild].nRight, ParentCode );
    ParentCode.erase( ParentCode.end() );
  }
}

SNode CHuffmanTree :: getRootNode(){
  return Vertex[Root];
}

SNode CHuffmanTree :: getNode( unsigned __int64 x ){
  return Vertex[x];
}

void CHuffmanTree :: makeTableCode(){
    vector<bool> Bool;
    Bool.clear();
    makeCode( Root, Bool );
}

void CHuffmanTree :: outTableCode(){
  if( mTableCode.empty() ){
    printf( "You haven't makeTableCode\n" );
    return;
  }
  map<unsigned __int64, vector<bool> > :: iterator it;
  vector<bool> :: iterator itBool;
  for( it = mTableCode.begin(); it != mTableCode.end(); ++it ){
    printf( "(int)char = %llu\tchar = %c : ", it -> first,(char) it -> first );
    for( itBool = (it -> second).begin(); itBool != (it -> second).end(); ++itBool )
      printf( "%d", (int)( *itBool ));
    printf("\n");
  }
}

vector < bool > CHuffmanTree :: getCode( char c ){
  return mTableCode[c];
}

CEncode CHuffmanTree :: encode( CEncode cEncode, char c ){
  cEncode.AddRange( mTableCode[c] );
  return cEncode;
}

