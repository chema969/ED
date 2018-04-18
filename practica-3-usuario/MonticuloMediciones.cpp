/*!
	\file MonticuloMediciones.cpp
	\brief Fichero que contiene el código de las funciones de la clase MonticuloMediciones.
	\author 
	\date 
*/

//#include <vector>
#include <algorithm>
#include <cassert>

#include "Medicion.hpp"

#include "MonticuloMediciones.hpp"

////////////////////////////////////////////////////////////////////

// Métodos privados de la clase MonticuloMediciones


void ed::MonticuloMediciones::shiftUp(int i){
        #ifndef NDEBUG
              assert(i>=0);
              assert(i< size());
          #endif
   int padre=getParent(i);
   if(getElement(padre).getPrecipitacion()>getElement(i).getPrecipitacion()){ 
             ed::Medicion aux(_vector[i]);
             _vector[i]=_vector[padre];
             _vector[padre]=aux;
             shiftUp(padre);
             }
    else{ 
        return;
   }
}
             
////////////////////////////////////////////////////////////////////////////////////7

// Métodos públicos de la clase MonticuloMediciones

		// COMPLETAR




