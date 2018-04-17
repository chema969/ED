/*! 
   \file Medicion.hpp
   \brief Fichero de la clase Medicion: medición de una estación meteorológica 
*/

#ifndef _MEDICION_HPP_
#define _MEDICION_HPP_

// Entrada y salida 
#include <iostream>

// Para controlar las precondiciones y postcondiciones mediante asertos
#include <cassert>

// Definición de la clase Fecha
#include "Fecha.hpp"


// Para la sobrecarga de los operadores de flujo: << y >>
using std::istream;
using std::ostream;

#define COTA_ERROR   1.0e-6 //!< Cota de error para la comparación de números reales


// Se incluye la clase Medicion dentro del espacio de nombres de la asigantura: ed
namespace ed {

//!  Definición de la clase Medicion 
class Medicion
{
  //! \name Atributos privados de la clase Medicion
   private: 
            
	     ed::Fecha _fecha;//!< Fecha de la medicion
             float _precipitaciones;//!< Cantidad de precipitaciones

   //! \name Funciones o métodos públicos de la clase Medicion
   public:

	//! \name Constructor de la clase Medicion


	     Medicion(ed::Fecha fecha=Fecha(1,1,1), float precipitaciones=0.0):_fecha(fecha){
                            
                           setPreticipitacion(precipitaciones);
                            }




 	     Medicion(ed::Medicion med){

		           setFecha(med.getFecha());
                           setPreticipitacion(med.getPrecipitacion());
                         }                    
	//! \name Observadores: funciones de consulta de la clase Medicion

            ed::Fecha getFecha(){ return _fecha;}


            float getPrecipitacion{ return _precipitacion;} 


	//! \name Funciones de modificación de la clase Medicion

            void setFecha(ed::Fecha fecha){_fecha(fecha));}
       
            void setPrecipitacion(float precipitacion){
                             #define NDEBUG
                                 assert(precipitacion>=0.0);
                             #endif
                        _precipitaciones=precipitacion;
                           }
	//! \name Operadores
   
            bool operator==(ed:: Medición);


	//! \name Funciones de lectura y escritura de la clase Medicion

		// COMPLETAR EL CÓDIGO E INCLUIR LOS COMENTARIOS DE DOXYGEN



}; // Fin de la definición de la clase Medicion


   //! \name Funciones externas de la clase Medicion: sobrecarga de los operadores de flujo

		// COMPLETAR EL CÓDIGO E INCLUIR LOS COMENTARIOS DE DOXYGEN



} // \brief Fin de namespace ed.

//  _MEDICION_HPP_
#endif 
