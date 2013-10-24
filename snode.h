#ifndef SNODE_H_INCLUDED
#define SNODE_H_INCLUDED

#include <string>

struct SNode{
  unsigned __int64 nName;
  unsigned __int64 Freq;
  __int64 nLeft, nRight;
  bool isLeaf();
};

#endif //SNODE_H_INCLUDED
