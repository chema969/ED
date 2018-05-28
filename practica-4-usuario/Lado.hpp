/*! 
   \file Lado.hpp
   \brief Fichero de la clase Lado
*/
#ifndef LADO_HPP
#define LADO_HPP

#include <cassert>

namespace ed{
//!  Definición de la clase Lado
class Lado{
    //! \name Atributos privados de la clase Lado
     private:
      double peso_;//!<Peso del vector
      int vertice1_;//!<Etiqueta del vertice 1 del lado
      int vertice2_;//!<Etiqueta del vertice 2 del lado
     public:
    //! \name Constructor de la clase lado
	/*! 
		\brief     Constructor de la clase lado
		\note      Función inline
                \param     vertice1: Parametro obligatorio el cual se le asignara al vertice 1
                \param     vertice2: Parametro obligatorio el cual se le asignara al vertice 2
                \param     peso: Parametro con 0 por defecto el cual se asignará al peso del lado
                \pre       Ninguna
		\post      vertice1_=vertice1,    vertice2_=vertice2,   peso_=peso
	*/
      Lado(int vertice1=-1,int vertice2=-1,double peso=0.0){
                          vertice1_=vertice1;
                          vertice2_=vertice2;
                          peso_=peso;
                            }
    //! \name Observadores: funciones de consulta de la clase Lado  

	/*! 
		\brief     Función que devuelve el peso del lado
		\attention Se utiliza el modificador const en la definición de la función 
		\note      Función inline
		\return    Valor del atributo peso, del tipo double
		\pre       Ninguna
		\post      Ninguna
	*/
      double getPeso()const{return peso_;}

	/*! 
		\brief     Función que verifica si el vertice pertenece al lado
		\attention Se utiliza el modificador const en la definición de la función 
		\note      Función inline
                \param     vertex: vertice a verificar
		\return    true en caso de que el vertice pertenezca, false si no
		\pre       Ninguna
		\post      Ninguna
	*/
      bool has(int vertex)const{
                   if((vertice1_==vertex) || (vertice2_==vertex)) 
                                   return true;
                    return false;                         
                    }

	/*! 
		\brief     Función que devuelve la etiqueta de uno de los extremos
		\attention Se utiliza el modificador const en la definición de la función 
		\note      Función inline
		\return    Etiqueta del vertice 1
		\pre       Ninguna
		\post      Ninguna
	*/
      int first() const{return vertice1_;}

	/*! 
		\brief     Función que devuelve la etiqueta del segundo extremo
		\attention Se utiliza el modificador const en la definición de la función 
		\note      Función inline
		\return    Etiqueta del vertice 2
		\pre       Ninguna
		\post      Ninguna
	*/
      int second()const{return vertice2_;}

	/*! 
		\brief     Función que devuelve la etiqueta del vertice contrario al que pasamos en caso de que este pertenezca al lado
		\attention Se utiliza el modificador const en la definición de la función 
                \param     i: vertice contrario al que se retornará
		\return    En caso de que sea uno de los vertices, el vertice contrario. En caso de que no sea, -1
		\pre       Ninguna
		\post      Ninguna
	*/
      int other(int i)const;     
 
    //! \name Modificadores: funciones de modificación de la clase Vertice

	/*! 
		\brief     Función que modifica el valor del peso
		\note      Función inline
                \param     i: valor a asignar al peso
		\pre       peso>=0
		\post      peso_==i
	*/
      void setPeso(double i){
                           #ifndef NDEBUG
                             assert(i>=0);
                           #endif
                         peso_=i;
                         }







   
     };
     }//! \brief Fin de namespace ed.

#endif
