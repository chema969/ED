
/*! 
   \file Grafo.cpp
   \brief Funciones de la clase Grafo
*/
#include "Grafo.hpp"
#include <vector>
#include "Vertice.hpp"
#include "Lado.hpp"
#include <cassert>
#include <iostream>

//Para hacer uso de la funcion sort en el algoritmo de kruskal
#include <algorithm>

//Para calcular la distancia entre dos puntos
#include <cmath>

//Para hacer uso del setprecision y poder imprimir sin problemas
#include <iomanip> 

//Para el numeric limits
#include <limits>

namespace ed{


void ed::Grafo::createAdyacencia(){
      #ifndef NDEBUG
        assert(adyacencia_.empty());
      #endif
        //Esta funcion solo se va a utilizar cuando no haya matriz de adyacencia alguna
        adyacencia_.resize(vertices_.size());

        for(unsigned int i=0;i<adyacencia_.size();i++)
                        adyacencia_[i].resize(vertices_.size(),0);//Se asigna 0 como valor por defecto

        for(unsigned int i=0;i<lados_.size();i++){
                        //La matriz de adyacencia tendrá 1 en caso de que esten unidos
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
                      //Si existe actualmente un vertice con esos valores, evita introducirlo retornando
                         }
              }

     vertice.setLabel(vertices_.size());
     vertices_.push_back(vertice);
     adyacencia_.resize(vertices_.size());

     for(unsigned int i=0;i<adyacencia_.size();i++){
           adyacencia_[i].resize(adyacencia_.size());
           //Modifica el tamaño de la matriz para que quepa el nuevo lado
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
      /*El lado consigue el peso de la distancia entre ambos vectores
      La distancia entre dos puntos es la raiz cuadrada del cuadrado de la diferencia entre cordenadas */
     
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
      //Pone a 0 los puntos de la matriz de adyacencia
      adyacencia_[lados_[lado_cursor_].first()][lados_[lado_cursor_].second()]=0;
      adyacencia_[lados_[lado_cursor_].second()][lados_[lado_cursor_].first()]=0;
        
      //Elimina el lado del vector de lados
      lados_[lado_cursor_]=lados_[(lados_.size()-1)];
      lados_.erase(lados_.end()-1);
      lado_cursor_=-1;
}



void ed::Grafo::removeVertice(){
    int curs=vertice_cursor_;

//Elimina los lados que contengan al vertice que se va a eliminar
    for(unsigned int i=0;i<lados_.size();i++){
             if(lados_[i].has(curs)){
                   lados_.erase(lados_.begin()+i);
                   i--;
                     }
      }

//Como se va a intercambiar el elemento del final por el que hay en el current, se cambian tambien sus lados para que ahora la etiqueta sea la nueva etiqueta
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




void ed::Grafo::imprimir(){


 //Primero se imprimen todos los vertices
   for(int i=0;i<size();i++){
      std::cout<<"Vertice "<<i<<": "<<vertices_[i].getX()<<" "<<vertices_[i].getY()<<std::endl;
      }

//Luego la matriz de adyacencias
   for(int i=0;i<size();i++){
      std::cout<<"|";
      for(int j=0;j<size();j++){
         if(adyacencia_[i][j]==1){

            //Debido a que mi matriz de adyacencias es de 1 y 0, uso esto para imprimirla con pesos
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
#ifndef NDEBUG
   assert(!isEmpty());
#endif

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



ed::Dijkstra ed::Grafo::dijkstra(int origen){
#ifndef NDEBUG
   assert(size()>1);
   assert((origen>=0)&&(origen<size()));
#endif
     Dijkstra solucion;//Se crea un item de la clase Dijkstra
     solucion.distancias.resize(size());
     solucion.predecesores.resize(size(),origen);
     std::vector<bool> visitados;
     visitados.resize(size(),false);

     //Al principio se inicializa el vector de distancias con el peso de ese vertice a la distancia final y con el origen como predecesor
     for(int i=0;i<size();i++){
         if(findLado(origen,i)){
           solucion.distancias[i]=currentLado().getPeso();
          }
          else solucion.distancias[i]=std::numeric_limits<double>::infinity();
      }

     visitados[origen]=true;
 
     for(int i=0;i<size();i++){
        double min=std::numeric_limits<double>::infinity();
        int x=0;
        for(int j=0;j<size();j++){
           
          //Se coje la distancia minima no visitada
           if((visitados[j]==false)&&(solucion.distancias[j]<min)){
              min=solucion.distancias[j];
              x=j;
           }
         }
         visitados[x]=true;
        for(int j=0;j<size();j++){
          if(findLado(x,j)){
             //Si uno de los nodos no visitados reduce el peso de uno de los nodos sin visitar, este nuevo nodo pasa a ser el predecesor y modifica su peso
             if((visitados[j]==false)&&(solucion.distancias[j]>solucion.distancias[x]+currentLado().getPeso())){
                     solucion.distancias[j]=solucion.distancias[x]+currentLado().getPeso();
                     solucion.predecesores[j]=x;
              }
          }
        }
      }
    solucion.distancias[origen]=0;
    return solucion;
}



//Funciones que podian haber sido implementadas dentro de la clase pero se implementaron fuera
/*
ed::Grafo ed::Grafo::kruskal(){
      #ifndef NDEBUG
         assert(!isEmpty());
      #endif

     //Ordena los lados en orden ascendente
      std::sort(lados_.begin(),lados_.end(),this->sortLados);


      ed::Grafo coste_minimo;
      std::vector<bool> prueba;
      prueba.resize(vertices_.size(),false);


      for(unsigned int i=0;i<vertices_.size();i++)
          coste_minimo.insertVertice(vertices_[i].getX(),vertices_[i].getY()); //Insertamos todos los vertices en el arbol abarcador de coste minimo
      

      //Si aún uno de los vertices no esta unido, se une (para eso sirve el vector prueba
      for(unsigned int i=0;i<lados_.size();i++){
           if((prueba[lados_[i].first()]==false)||(prueba[lados_[i].second()]==false)){
                coste_minimo.insertLado(lados_[i].first(),lados_[i].second());
                prueba[lados_[i].first()]=true;
                prueba[lados_[i].second()]=true;
                }

      //Si no, se prueban si pertenecen a arboles distintos y se añade en caso afirmativo
            else{
                 if(!coste_minimo.estanUnidos(lados_[i].first(),lados_[i].second())){
                                     coste_minimo.insertLado(lados_[i].first(),lados_[i].second());  }
                    
                 else if(coste_minimo.todosUnidos())return coste_minimo;
                 }
      }



      #ifndef NDEBUG
        if(todosUnidos()) assert(coste_minimo.todosUnidos());
      #endif


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
          coste_minimo.insertVertice(vertices_[i].getX(),vertices_[i].getY()); //Insertamos todos los vertices en el arbol abarcador de coste minimo

      vistos.push_back(0);//Inserto el nodo origen, 0, en el vector de vistos

      
      //Añado el resto de vertices al vector por_ver
      for(unsigned int i=1;i<vertices_.size();i++)
          por_ver.push_back(i);


      while(!por_ver.empty()){
      
          //Inicializo las variables temporales
          int from_old=-1;//
          std::vector<int>::iterator erase;//Elemento del vector por_ver que se borrará en la siguiente iteración
          int from_new=-1;
          double peso=std::numeric_limits<double>::infinity();//Menor peso de los vectores con respecto al 


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

      #ifndef NDEBUG
        if(todosUnidos()) assert(coste_minimo.todosUnidos());
      #endif

   return coste_minimo;
   }
*/




}
