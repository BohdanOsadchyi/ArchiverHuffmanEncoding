#ifndef HUFFMANTREEBUILDER_H_INCLUDED
#define HUFFMANTREEBUILDER_H_INCLUDED

#include "huffmantree.h"

#include <set>

class CFreqTableBuilder;

class CHuffmanTreeBuilder{
  protected:
    multiset< pair<unsigned __int64, unsigned __int64> > Top;
    set<unsigned __int64> Unique;
    vector<SNode> Vertex;
  public:
    CHuffmanTreeBuilder( CFreqTableBuilder );
    void out();
    CHuffmanTree makeTree();
};

#endif // HUFFMANTREEBUILDER_H_INCLUDED
