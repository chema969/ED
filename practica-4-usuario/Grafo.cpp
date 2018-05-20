#include "Grafo.hpp"
#include <vector>
#include "Vertice.hpp"
#include "Lado.hpp"
#include <cassert>

namespace ed{

bool ed::Grafo::adjacent(int u, int v)const{
   #ifndef NDEBUG
     assert(((unsigned int)u<vertices_.size())&&(u>=0));
     assert(((unsigned int)v<vertices_.size())&&(v>=0));  
   #endif 
   unsigned int i;
      for(i=0;i<lados_.size();i++){
          if((lados_[i].has(u))&&(lados_[i].other(u)==v)) return true;
          }
       return false;
  }























}
