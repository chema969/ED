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

	/*! 
		\brief     Función que comprueba si dos vertices son adyacentes o no
		\attention Se utiliza el modificador const en la definición de la función 
		\return    True si existe un lado que una los vertices u y v, false si no
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


    //! \name Modificadores: funciones de modificación de la clase Grafo, sin tener en cuenta los modificadores de cursores, que irían aparte    
       
        /*! 
		\brief     Función que inserta un vertice al grafo
		\pre       Ninguna
		\post      vectores_.size()==old(vectores_.size())+1
	*/  
       void insertVetice(double x,double y);

       
       void insertLado(int u, int v, int peso);


       void removeLado();
};

}
#endif
