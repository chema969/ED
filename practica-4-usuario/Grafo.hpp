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
         
         Grafo(){
             vertice_cursor_=-1;
             lado_cursor_=-1;
                }
 
    //! \name Observadores: funciones de consulta de la clase Grafo

        bool isEmpty()const{
                         return vertices_.empty();}

        bool adjacent(int u, int v)const;
 
        bool hasCurrentVertice()const{
                          if(vertice_cursor_==-1) return false;
                          return true; 
                                    }
        ed::Vertice currentVertice()const{
                            #ifndef NDEBUG
                               assert(hasCurrentVertice());
                            #endif
                             return vertices_[vertice_cursor_];}

 
        bool hasCurrentLado()const{
                          if(lado_cursor_==-1) return false;
                          return true; 
                                    }

        
        ed::Lado currentLado()const{
                            #ifndef NDEBUG
                               assert(hasCurrentLado());
                            #endif
                             return lados_[lado_cursor_];}        


};

}
#endif
