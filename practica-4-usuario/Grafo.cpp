#include "Grafo.hpp"
#include <vector>
#include "Vertice.hpp"
#include "Lado.hpp"
#include <cassert>

namespace ed{


void ed::Grafo::createAdyacencia(){
        adyacencia_.resize(vertices_.size());
        for(unsigned int i=0;i<adyacencia_.size();i++)
                        adyacencia_[i].resize(vertices_.size(),0);
        for(unsigned int i=0;i<lados_.size();i++){
                        adyacencia_[lados_[i].first()][lados_[i].second()]=1;
                        adyacencia_[lados_[i].second()][lados_[i].first()]=1;
                        }
         }
 


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
          assert(((unsigned int)u<vertices_.size())&&(u>=0));
          assert(((unsigned int)v<vertices_.size())&&(v>=0));
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
      lado_cursor_=-1;
}

void ed::Grafo::removeVertice(){
    int curs=vertice_cursor_;
    for(std::vector<ed::Lado>::iterator it=lados_.begin();it!=lados_.end();it++){
         if(it->has(curs))
                  lados_.erase(it);
           }
    for(std::vector<ed::Lado>::iterator it=lados_.begin();it!=lados_.end();it++){
          if(it->has(vertices_.size()-1)){
                  int first=it->first();
                  int second=it->second(); 
                  int peso=it->getPeso();
                  if((unsigned int)first==vertices_.size()-1) first=curs;
                  if((unsigned int)second==vertices_.size()-1) second=curs;
                  ed::Lado l(first,second,peso);
                  lados_.erase(it);
                  lados_.push_back(l);
                  }
              }           
    vertices_[curs]=vertices_[vertices_.size()-1];
    vertices_.resize(vertices_.size()-1);
    vertices_[curs].setLabel(curs);    
     
    dropAdyacencia();
    createAdyacencia();
}
 

bool ed::Grafo::findVertice(double x,double y){
      if(isEmpty())return false;
      ed::Vertice vertice;
      vertice.setX(x);
      vertice.setY(y); 
      for(unsigned int i=0;i<vertices_.size();i++){
           if(vertice==vertices_[i]){
                          vertice_cursor_=i;
                          return true;
                            }
              }
      vertice_cursor_=-1;
      return false;
    }   



bool ed::Grafo::findLado(int u,int v){
      if(lados_.empty())return false;
      if(!adjacent(u,v)){ 
                     lado_cursor_=-1;
                     return false;
                        }
      for(unsigned int i=0;i<lados_.size();i++){
               if((lados_[i].has(u))&&(lados_[i].other(v))){
                                         lado_cursor_=i;
                                         return true; 
                                           }  
              }
  
      return false;
    }   













}
