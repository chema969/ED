#include "Grafo.hpp"
#include <vector>
#include "Vertice.hpp"
#include "Lado.hpp"
#include <cassert>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip> 
namespace ed{


void ed::Grafo::createAdyacencia(){
      #ifndef NDEBUG
        assert(adyacencia_.empty());
      #endif
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




void ed::Grafo::insertVertice(double x,double y){
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





void ed::Grafo::insertLado(int u,int v){
      #ifndef NDEBUG
          assert(((unsigned int)u<vertices_.size())&&(u>=0));
          assert(((unsigned int)v<vertices_.size())&&(v>=0));
          assert(!adjacent(u,v));
      #endif 
      double x_value=pow(vertices_[u].getX()-vertices_[v].getX(),2);
      double y_value=pow(vertices_[u].getY()-vertices_[v].getY(),2);
      double peso=sqrt(x_value+y_value);
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
    for(unsigned int i=0;i<lados_.size();i++){
             if(lados_[i].has(curs)){
                   lados_.erase(lados_.begin()+i);
                   i--;
                     }
      }
    for(unsigned int i=0;i<lados_.size();i++){
          if(lados_[i].has(vertices_.size()-1)){
                  int first=lados_[i].first();
                  int second=lados_[i].second(); 
                  int peso=lados_[i].getPeso();
                  if((unsigned int)first==vertices_.size()-1) first=curs;
                  if((unsigned int)second==vertices_.size()-1) second=curs;
                  ed::Lado l(first,second,peso);
                  lados_.erase(lados_.begin()+i);
                  i--;
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
               if((lados_[i].has(u))&&(lados_[i].other(u)==v)){
                                         lado_cursor_=i;
                                         return true; 
                                           }  
              }
  
      return false;
    }   



ed::Grafo ed::Grafo::kruskal(){
      std::sort(lados_.begin(),lados_.end(),this->sortLados);
      ed::Grafo coste_minimo;
      std::vector<bool> prueba;
      prueba.resize(vertices_.size(),false);
      for(unsigned int i=0;i<vertices_.size();i++)
          coste_minimo.insertVertice(vertices_[i].getX(),vertices_[i].getY()); //Insertamos todos los vertices en el arbol abarcador de coste minimo
      

      #ifndef NDEBUG
          for(unsigned int i=0;i<prueba.size();i++) assert(prueba[i]==false);
          assert(prueba.size()==vertices_.size());
      #endif
   
      for(unsigned int i=0;i<lados_.size();i++){
           if((prueba[lados_[i].first()]==false)||(prueba[lados_[i].second()]==false)){
                coste_minimo.insertLado(lados_[i].first(),lados_[i].second());
                prueba[lados_[i].first()]=true;
                prueba[lados_[i].second()]=true;
                }
            else{
                 if(!coste_minimo.estanUnidos(lados_[i].first(),lados_[i].second())){
                                     coste_minimo.insertLado(lados_[i].first(),lados_[i].second());  }
                    
                 else if(coste_minimo.todosUnidos())return coste_minimo;
                 }
      }
      return coste_minimo;
}



ed::Grafo ed::Grafo::prim(){
      #ifndef NDEBUG
         assert(!isEmpty());
      #endif
      ed::Grafo coste_minimo;
      std::vector<int> vistos;
      std::vector<int> por_ver;
      for(unsigned int i=0;i<vertices_.size();i++)
          coste_minimo.insertVertice(vertices_[i].getX(),vertices_[i].getY()); //Insertamos todos los vertices en el arbol abarcador de coste minimo+

      vistos.push_back(0);
      for(unsigned int i=1;i<vertices_.size();i++)
          por_ver.push_back(i);

      while(!por_ver.empty()){
          int from_old=-1;
          std::vector<int>::iterator erase;
          int from_new=-1;
          double peso=9999999999;
          for(std::vector<int>::iterator it=por_ver.begin();it!=por_ver.end();it++){
              for(std::vector<int>::iterator jt=vistos.begin();jt!=vistos.end();jt++){
                  if(adjacent(*it,*jt)){
                     findLado(*it,*jt);
                     if(currentLado().getPeso()<peso){
                          peso=currentLado().getPeso();
                          from_old=*jt;
                          erase=it;
                          from_new=*it;
                          } 
                  }
              }            
           }
           if((from_old!=-1)&&(from_new!=-1)){
              coste_minimo.insertLado(from_old,from_new);
              por_ver.erase(erase);
              vistos.push_back(from_new);
              }
           else{
              vistos.push_back(por_ver[0]);
              por_ver.erase(por_ver.begin());
              }
      }
   return coste_minimo;
   }


void ed::Grafo::imprimir(){
   for(int i=0;i<size();i++){
      std::cout<<"Vertice "<<i<<": "<<vertices_[i].getX()<<" "<<vertices_[i].getY()<<std::endl;
      }
   for(int i=0;i<size();i++){
      std::cout<<"|";
      for(int j=0;j<size();j++){
         if(adyacencia_[i][j]==1){
            findLado(j,i);
            std::cout<<currentLado().getPeso();
           }
         else
            std::cout<<std::setprecision (5)<<0;
        std::cout<<"\t";
        }
    std::cout<<"|"<<std::endl;
   }
}


std::vector<std::vector<int> > ed::Grafo::warshall()const{
    std::vector< std::vector<int> > path = adyacencia_;
    for(int k = 0; k < size(); k++){
        for(int i = 0; i < size(); i++){
            for(int j = 0; j < size(); j++){
                if(path[i][j]==0){
                   path[i][j]=path[i][k]*path[k][j];
                 }
            }
         }
    }
    return path;
}




}
