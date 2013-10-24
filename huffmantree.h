#ifndef HUFFMANTREE_H_INCLUDED
#define HUFFMANTREE_H_INCLUDED

#include "snode.h"
#include "encode.h"

#include <map>
#include <vector>

class CHuffmanTree{
  protected:
    map<unsigned __int64, vector<bool> > mTableCode;
    unsigned __int64 Root;
    vector<SNode> Vertex;
    void makeCode( unsigned __int64, vector<bool> );
  public:
    CHuffmanTree();
    CHuffmanTree( vector<SNode> );
    SNode getRootNode();
    SNode getNode( unsigned __int64 );
    bool isLeaf( SNode );
    void makeTableCode();
    void outTableCode();
    vector<bool> getCode( char );
    CEncode encode( CEncode, char );
};

#endif // HUFFMANTREEBUILDER_H_INCLUDED
