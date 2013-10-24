#include <string>
#include "snode.h"

bool SNode :: isLeaf(){
  return ( nLeft == -1 ) && ( nRight == -1 );
}
