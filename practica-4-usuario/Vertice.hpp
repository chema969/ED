/*! 
   \file Vertice.hpp
   \brief Fichero de la clase Vertice
*/

#ifndef VERTICE_HPP
#define VERTICE_HPP

#include <cstdlib>
#include <cassert>
#include "macros.hpp"

namespace ed {
//!  Definición de la clase Vertice
class Vertice{
    //! \name Atributos privados de la clase Vertice
    private:
       double x_;//!<Cordenada x de la clase  
       double y_;//!<Cordenada y de la clase  
       int label_;//!<Etiqueta del vertice, siempre positiva

    public:

//! \name Observadores: funciones de consulta de la clase Vertice

	/*! 
		\brief     Función que devuelve la cordenada X del vertice
		\attention Se utiliza el modificador const en la definición de la función 
		\note      Función inline
		\return    Valor del atributo que representa la cordenada X (tipo double)
		\pre       Ninguna
		\post      Ninguna
	*/
             double getX()const{return x_;}

	/*! 
		\brief     Función que devuelve la cordenada Y del vertice
		\attention Se utiliza el modificador const en la definición de la función
		\note      Función inline 
		\return    Valor del atributo que representa la cordenada Y (tipo double)
		\pre       Ninguna
		\post      Ninguna
	*/
            double getY()const{return y_;}
        /*! 
		\brief     Función que devuelve la etiqueta del vertice
		\attention Se utiliza el modificador const en la definición de la función
		\note      Función inline 
		\return    Valor del atributo que representa la etiqueta del vertice dentro del grafo(tipo int)
		\pre       Ninguna
		\post      Ninguna
	*/
            int getLabel()const{return label_;}


//! \name Modificadores: funciones de modificación de la clase Vertice
        
	/*! 
		\brief Función que asigna un nuevo valor a la cordenada x del vertice
		\note  Función inline
		\param x: nuevo valor de la cordenada x
		\pre   Ninguna
		\post  El valor de la cordenada x sera el que se ha pasado como argumento
	*/
            void setX(double x){
                           x_=x;
                           #ifndef NDEBUG
                                 assert(abs(x_-x)<COTA_ERROR);
                           #endif
                           }
       /*! 
		\brief Función que asigna un nuevo valor a la cordenada y del vertice
		\note  Función inline
		\param y: nuevo valor de la cordenada y
		\pre   Ninguna
		\post  El valor de la cordenada y sera el que se ha pasado como argumento
	*/
            void setY(double y){
                           y_=y;
                           #ifndef NDEBUG
                                 assert(abs(y_-y)<COTA_ERROR);
                           #endif
                           }

       /*! 
		\brief Función que asigna un nuevo valor a la etiqueta
		\note  Función inline
		\param label: nuevo valor de la etiqueta
		\pre   En el grafo se debe revisar que la etiqueta no se repita
		\post  El valor de la cordenada y sera el que se ha pasado como argumento
	*/
            void setLabel( int label){
                            label_=label;  
                           #ifndef NDEBUG
                                 assert(label_==label);
                           #endif
                            }
 
//! \name Operador de la clase Vertice     
     
       /*! 
		\brief  Operador que comprueba si dos vertices tienen la misma X y la misma Y
		\note   Función inline
		\param  vertice: Vertice pasado por referencia con el cual se comparará
                \return True si son iguales, false si no
		\pre    Ninguno
		\post   Ninguno
	*/
            bool operator==(const ed::Vertice &vertice){
                            if((abs(vertice.getX()-this->getX())<COTA_ERROR)&&(abs(vertice.getY()-this->getY())<COTA_ERROR)) return true;
                            return false;
                             }

};

}

// \brief Fin de namespace ed.







#endif
