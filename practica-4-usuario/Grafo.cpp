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

       if(adyacencia_[u][v]!=0)	return true;
       return false;
  }




void ed::Grafo::insertVetice(double x,double y){
     ed::Vertice vertice;
     vertice.setX(x);
     vertice.setY(y);
     for(unsigned int i=0;i<vertices_.size();i++){
          if(vertice==vertices_[i]){
                      return;
                         }
              }
     vertice.setLabel(vertices_.size());
     vertices_.push_back(vertice);
     adyacencia_.resize(vertices_.size());
     for(unsigned int i=0;i<adyacencia_.size();i++){
           adyacencia_[i].resize(adyacencia_.size());
      }
      vertice_cursor_=vertices_.size()-1;
      }





void ed::Grafo::insertLado(int u,int v,int peso){
      #ifndef NDEBUG
          assert(!adjacent(u,v));
          assert(peso>0);
      #endif 
      ed::Lado lado(u,v,peso);
      lados_.push_back(lado);
      adyacencia_[u][v]=1;
      adyacencia_[v][u]=1;
     lado_cursor_=lados_.size()-1;
    }


void ed::Grafo::removeLado(){
      #ifndef NDEBUG
          assert(hasCurrentLado());
      #endif
      adyacencia_[lados_[lado_cursor_].first()][lados_[lado_cursor_].second()]=0;
      adyacencia_[lados_[lado_cursor_].second()][lados_[lado_cursor_].first()]=0;
      lados_[lado_cursor_]=lados_[(lados_.size()-1)];
      lados_.erase(lados_.end()-1);
}







}
