
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
                            
                           setPrecipitacion(precipitaciones);
                            }




 	    Medicion(Medicion const &med){

		           setFecha(med.getFecha());
                           setPrecipitacion(med.getPrecipitacion());
                        }                    
	//! \name Observadores: funciones de consulta de la clase Medicion

            inline ed::Fecha getFecha() const{ return _fecha;}


            float getPrecipitacion() const{ return _precipitaciones;} 


	//! \name Funciones de modificación de la clase Medicion

            inline void setFecha(ed::Fecha fecha){_fecha=fecha;}
       
            inline void setPrecipitacion(float precipitacion){
                             #ifndef NDEBUG
                                 assert(precipitacion>=0.0);
                             #endif
                        _precipitaciones=precipitacion;
                           }
	//! \name Operadores
   
            inline bool operator==(ed::Medicion medicion) const{
                         if(this->getFecha()==medicion.getFecha()) 
                                 return true;
                         else
                                 return false;
                         }

           inline ed::Medicion operator=(ed::Medicion medicion){
                        this->setFecha(medicion.getFecha());
                        this->setPrecipitacion(medicion.getPrecipitacion());
                        return *this;                    
                           }
	//! \name Funciones de lectura y escritura de la clase Medicion

	   inline void leerMedicion(){  
          std::cout<<getFecha()<<" "<<getPrecipitacion()<<std::endl;   }
     
 
      inline void escribirMedicion(){std::cin>>_fecha;
                                     std::cout<<"introduce precipitaciones: ";
                                     std::cin>>_precipitaciones;}
                        



}; // Fin de la definición de la clase Medicion


   //! \name Funciones externas de la clase Medicion: sobrecarga de los operadores de flujo
         ostream &operator<<(ostream &stream, Medicion const &medicion);



         istream &operator>>(istream &stream, Medicion &medicion);
        


} // \brief Fin de namespace ed.

//  _MEDICION_HPP_
#endif 
