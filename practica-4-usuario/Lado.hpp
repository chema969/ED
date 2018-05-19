/*! 
   \file Lado.hpp
   \brief Fichero de la clase Lado
*/
#ifndef LADO_HPP
#define LADO_HPP

namespace ed{
//!  Definición de la clase Lado
class Lado{
    //! \name Atributos privados de la clase Lado
     private:
      int peso_;//!<Peso del vector
      ed::Vertice *vertice1_;//!<Vertice 1 del lado
      ed::Vertice *vertice2_;//!<Vertice 2 del lado
     public:
    //! \name Observadores: funciones de consulta de la clase Lado  
      int getPeso()const{return peso_;}
      












   
     };
     }

#endif
