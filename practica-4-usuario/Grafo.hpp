/*! 
   \file Grafo.hpp
   \brief Fichero de la clase Grafo
*/
#ifndef GRAFO_HPP
#define GRAFO_HPP

#include <vector>
#include "Vertice.hpp"
#include "Lado.hpp"
#include <cassert>


namespace ed{

//!  Definición de la clase Grafo
class Grafo{
    //! \name Atributos privados de la clase Grafo
   private:
        std::vector<std::vector<int> > adyacencia_;//!< Matriz de adyacencia
        std::vector<ed::Lado> lados_;//!< Vector de lados
        std::vector<ed::Vertice> vertices_;//!< Vector de vertices
        int vertice_cursor_;//!< Cursor del vertice
        int lado_cursor_;//!< Cursor del lado


    //! \name Funciones privadas de la clase

        /*! 
		\brief     Función que borra la matriz de adyacencia
		\note      Función inline
		\pre       Ninguna
		\post      adyacencia_.empty()==verdadero
	*/       
        void dropAdyacencia(){
                             for(unsigned int i=0;i<adyacencia_.size();i++) 
                                                            adyacencia_[i].clear();
                             adyacencia_.clear();
                              }

        /*! 
		\brief     Función que crea de nuevo la matriz de adyacencia
		\pre       adyacencia_.empty()==verdadero
		\post      adyacencia_.empty()==falso
	*/  
        void createAdyacencia();
        
        static bool sortLados(Lado i,Lado j){return i.getPeso()<j.getPeso();}
       
   public:
    //! \name Constructor de la clase

	/*! 
		\brief     Constructor de la clase Grafo
		\note      Función inline
                \pre       Ninguna
		\post      Los cursores tienen valores nulos
	*/
         Grafo(){
             vertice_cursor_=-1;
             lado_cursor_=-1;
                }
 
    //! \name Observadores: funciones de consulta de la clase Grafo

	/*! 
		\brief     Función que comprueba si el grafo está vacio
		\attention Se utiliza el modificador const en la definición de la función 
		\note      Función inline
		\return    True si esta vacio, false si no
		\pre       Ninguna
		\post      Ninguna
	*/
        bool isEmpty()const{
                         return vertices_.empty();}

  
        int size()const{
                         return vertices_.size();}
	/*! 
		\brief     Función que comprueba si dos vertices son adyacentes o no
		\attention Se utiliza el modificador const en la definición de la función 
		\return    True si existe un lado que una los vertices u y v, false si no
                \param     u: Vertice del lado
                \param     v: El otro vertice del lado
		\pre       Deben existir en el grafo tanto u como v
		\post      Ninguna
	*/
        bool adjacent(int u, int v)const;

 	/*! 
		\brief     Función que comprueba si el cursor del vertice existe
		\attention Se utiliza el modificador const en la definición de la función 
		\note      Función inline
		\return    True si existe el cursor, false si no
		\pre       Ninguna
		\post      Ninguna
	*/
        bool hasCurrentVertice()const{
                          if(vertice_cursor_==-1) return false;
                          return true; 
                                    }

	/*! 
		\brief     Función que devuelve el vertice apuntado por el cursor
		\attention Se utiliza el modificador const en la definición de la función 
		\note      Función inline
		\return    vertices_[vertice_cursor_]
		\pre       hasCurrentVertice()==true
		\post      Ninguna
	*/
        ed::Vertice currentVertice()const{
                            #ifndef NDEBUG
                               assert(hasCurrentVertice());
                            #endif
                             return vertices_[vertice_cursor_];}

  	/*! 
		\brief     Función que comprueba si el cursor del lado existe
		\attention Se utiliza el modificador const en la definición de la función 
		\note      Función inline
		\return    True si existe el cursor, false si no
		\pre       Ninguna
		\post      Ninguna
	*/
        bool hasCurrentLado()const{
                          if(lado_cursor_==-1) return false;
                          return true; 
                                    }

        /*! 
		\brief     Función que devuelve el lado apuntado por el cursor
		\attention Se utiliza el modificador const en la definición de la función 
		\note      Función inline
		\return    lados_[lado_cursor_]
		\pre       hasCurrentLado()==true
		\post      Ninguna
	*/
        ed::Lado currentLado()const{
                            #ifndef NDEBUG
                               assert(hasCurrentLado());
                            #endif
                             return lados_[lado_cursor_];}       
       
        bool estanUnidos(int i,int j)const{
                             std::vector<std::vector <int> > unidos=warshall();
                             if(unidos[i][j]==0)return false;
                             else return true;
                             }
        
        bool todosUnidos()const{
                             std::vector<std::vector <int> > unidos=warshall();
                             for(int i=0;i<size();i++){
                                  for(int j=0;j<size();j++){
                                       if(unidos[i][j]==0)return false;
                                   }
                             }
                             return true;}
    //! \name Modificadores de los vectores: funciones de modificación de la clase Grafo, sin tener en cuenta los modificadores de cursores, que irían aparte    
       
        /*! 
		\brief     Función que inserta un vertice al grafo
                \param     x: Valor del x del vertice
                \param     y: Valor del y del vertice
		\pre       existe(Vertice(x,y))==falso
		\post      vertices_.size()==old(vertices_.size())+1
	*/  
       void insertVertice(double x,double y);

        /*! 
		\brief     Función que inserta un vertice al grafo
                \param     u: Valor del primer vertice del lado
                \param     v: Valor del segundo vertice del lado
                \param     peso: Valor del peso del lado
		\pre       adjacent(u,v)==falso
		\pre       existe(vetices_[u])==verdadero
		\pre       existe(vertices_[v]))==verdadero
		\post      lados_.size()==old(lados_.size())+1
	*/       
       void insertLado(int u, int v);

        /*! 
		\brief     Función que borra un vertice del grafo
		\pre       Ninguna
                \post      findVertice(old.currentVertice)==false
		\post      vertices_.size()==old(vertices_.size())-1
	*/
       void removeVertice();

        /*! 
		\brief     Función que borra un lado del grafo
		\pre       Ninguna
                \post      findLado(old.currentLado)==false
		\post      lados_.size()==old(lados_.size())-1
	*/
       void removeLado();

   //! \name Modificadores de los cursores: funciones de modificación de los cursores de la clase Grafo

        /*! 
		\brief     Función que busca un vertice dentro del vector de vertice y pone el cursor sobre este vector
                \param     x: Valor del x del vertice
                \param     y: Valor del y del vertice
                \return    True si existe el vertice, false si no
		\pre       Ninguno
		\post      Si existe un vertice n que ocupa la posición i en el vector de vertices y tal que n.getX=x y n.getY=y, entonces cursor_vertices=i
	*/ 
       bool findVertice(double x,double y);

        /*! 
		\brief     Función que asigna el cursor a un vertice nuevo
		\note      Función inline
                \param     i: Vertice al que se dirigirá el cursor
		\pre       i esta dentro de los vertices existentes
		\post      vertice_cursor=i
	*/       
       void gotoVertice(int i){
                            #ifndef NDEBUG
                               assert(i>=0);
                               assert((unsigned int)i<vertices_.size());
                            #endif
                            vertice_cursor_=i;
                              } 

        /*! 
		\brief     Función que asigna el cursor al primer vertice
		\note      Función inline
		\pre       isEmpty==false
		\post      vertice_cursor=primer vertice
	*/      
       void gotoFirstVertice(){
                             #ifndef NDEBUG
                                assert(!isEmpty());
                             #endif
                             vertice_cursor_=0;
                               }            
       
	/*! 
		\brief     Función que asigna el cursor al siguiente vertice
		\note      Función inline
		\pre       hasCurrentVertice==true
                \pre       lastVertice==false
		\post      vertice_cursor=old(vertice_cursor)+1
	*/  
       bool gotoNextVertice(){
                            #ifndef NDEBUG
                               assert(hasCurrentVertice());
                            #endif
                             if((unsigned int)vertice_cursor_<vertices_.size()-1){
                                          vertice_cursor_++;
                                          return true;
                                          }
                              return false;
                              }

       /*! 
		\brief     Función que busca un lado dentro del vector de lados y pone el cursor sobre este lado
                \param     u: Vertice del lado
                \param     v: El otro vertice del lado
                \return    True si existe lado, false si no
		\pre       Ninguna
		\post      Si existe un lado n que ocupa la posición i en el vector de vertices y que enlace u y v, entonces cursor_vertices=i
	*/ 
      bool findLado(int u,int v);

        /*! 
		\brief     Función que asigna el cursor a un lado nuevo
		\note      Función inline
                \param     i: Lado al que se dirigirá el cursor
		\pre       i esta dentro de los lados existentes
		\post      lados_cursor=i
	*/      
      void gotoLado(int i){
                            #ifndef NDEBUG
                               assert(i>=0);
                               assert((unsigned int)i<lados_.size());
                            #endif
                            lado_cursor_=i;
                              }    

	/*! 
		\brief     Función que asigna el cursor al primer lado
		\note      Función inline
		\pre       lados_.empty==false
		\post      lados_cursor=primer lado
	*/     
       void gotoFirstLado(){
                             #ifndef NDEBUG
                                assert(!lados_.empty());
                             #endif
                             lado_cursor_=0;
                               }       

	/*! 
		\brief     Función que asigna el cursor al siguiente lado
		\note      Función inline
		\pre       hasCurrentLado
                \pre       !lastLado()
		\post      lados_cursor=old(lados_cursor)+1
	*/  
       bool gotoNextLado(){
                            #ifndef NDEBUG
                               assert(hasCurrentLado());
                            #endif
                             if((unsigned int)lado_cursor_<lados_.size()){ 
                                          lado_cursor_++;
                                          return true;}
                             return false;
                              }
                          
   //! \name Algoritmos que devuelven el arbol abarcador de coste mínimo
       ed::Grafo kruskal();
       ed::Grafo prim();
   //! \name Otros algoritmos
       std::vector< std::vector<int> > warshall()const;
   //! \name Funcion para imprimir el grafo
       void imprimir();
                              
};

}
#endif
