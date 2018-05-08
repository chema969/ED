
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

/*!	
	\brief   Constructor con parametros de defecto de la clase Medicion
        \note    Funcion inline
        \param   fecha: Fecha de la clase, si no se le da valor se asigna uno por defecto (1,1,1)
	\param   precipitaciones: Precipitaciones de la clase, en caso de no introducirse se pone 0.0 por defecto
  	\post    getPrecipitacion()==precipitaciones
        \post    getFecha()==fecha
*/
	     Medicion(ed::Fecha fecha=Fecha(1,1,1), float precipitaciones=0.0):_fecha(fecha){
                            
                           setPrecipitacion(precipitaciones);
                            }



/*!	
	\brief   Constructor de copia de la clase Medicion
        \note    Funcion inline
        \param   med: Medicion que se copiará
  	\post    *this==med
*/
 	    Medicion(Medicion const &med){

		           setFecha(med.getFecha());
                           setPrecipitacion(med.getPrecipitacion());
                        }                    
	//! \name Observadores: funciones de consulta de la clase Medicion


/*!	
	\brief   Observador que retorna la fecha
        \note    Funcion inline
        \return  La fecha de clase
*/
            inline ed::Fecha getFecha() const{ return _fecha;}

/*!	
	\brief   Observador que retorna las precipitaciones 
        \note    Funcion inline
        \return  La fecha de clase
*/
            float getPrecipitacion() const{ return _precipitaciones;} 


	//! \name Funciones de modificación de la clase Medicion

/*!	
	\brief   Modificador de la fecha
        \note    Funcion inline
        \param   fecha: Fecha que se va a asignar 
*/
            inline void setFecha(ed::Fecha fecha){_fecha=fecha;}

/*!	
	\brief   Modificador de la precipitacion 
        \note    Funcion inline
        \param   precipitacion: Precipitacion que se va a asignar 
*/       
            inline void setPrecipitacion(float precipitacion){
                             #ifndef NDEBUG
                                 assert(precipitacion>=0.0);
                             #endif
                        _precipitaciones=precipitacion;
                           }
	//! \name Operadores

/*!	
	\brief   Operador que compara dos mediciones 
        \note    Funcion inline
        \param   medicion: Medición con la que se va a comparar
        \return  True si son iguales, false si no  
*/          
            inline bool operator==(ed::Medicion medicion) const{
                         if(this->getFecha()==medicion.getFecha()) 
                                 return true;
                         else
                                 return false;
                         }

/*!	
	\brief   Operador que iguala una medición a otra
        \note    Funcion inline
        \param   medicion: Medición con la que se va a igualar
        \return  El objeto tras la igualación
*/          
           inline ed::Medicion operator=(ed::Medicion medicion){
                        this->setFecha(medicion.getFecha());
                        this->setPrecipitacion(medicion.getPrecipitacion());
                        return *this;                    
                           }
	//! \name Funciones de lectura y escritura de la clase Medicion

/*!	
	\brief   Función que imprime la medición 
        \note    Funcion inline
*/          
	   inline void leerMedicion(){  
          std::cout<<getFecha()<<" "<<getPrecipitacion()<<std::endl;   }
     
/*!	
	\brief   Función que lee la medición por teclado 
        \note    Funcion inline
*/    
      inline void escribirMedicion(){std::cin>>_fecha;
                                     std::cout<<"introduce precipitaciones: ";
                                     std::cin>>_precipitaciones;}
                        



}; // Fin de la definición de la clase Medicion


   //! \name Funciones externas de la clase Medicion: sobrecarga de los operadores de flujo
   
/*!	
	\brief   Operador de extracción  
        \param   stream: Flujo de salida donde se guarará la medición
        \param   medicion: Medición que se imprimirá
        \return  Flujo de salida
*/   
      ostream &operator<<(ostream &stream, Medicion const &medicion);


/*!	
	\brief   Operador de introducción
        \param   stream: Flujo de entrada que dará valor a los datos de la medición
        \param   medicion: Medición que se verá modificada por el flujo
        \return  Flujo de entrada
*/   
         istream &operator>>(istream &stream, Medicion &medicion);
        


} // \brief Fin de namespace ed.

//  _MEDICION_HPP_
#endif 
