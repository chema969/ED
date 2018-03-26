/*!	
	\file  Provincia.hpp
	\brief Definición de la clase Provincia
	\author  
	\date  
	\version 

*/

#ifndef _PROVINCIA_HPP_
#define _PROVINCIA_HPP_

// Para comprobar las pre y post condiciones
#include <cassert>

#include <string>


#include "ListaDoblementeEnlazadaOrdenadaMunicipios.hpp"


// DEBES COMPLETAR O MODIFICAR EL CÓDIGO DE LA CLASE Provincia

// DEBES COMPLETAR LOS COMENTARIOS DE DOXYGEN

// IMPORTANTE
// Se incluyen los prototipos de las funciones virtuales que hay que redefinir
// Hay que incluir los prototipos de las demás funciones


/*!	
	\namespace ed
	\brief Espacio de nombres para la Provincia Estructuras de Datos

*/
namespace ed{
/*!	

  \class Provincia
  \brief Definición de la clase Provincia

*/
class Provincia
{
	//!	\name Métodos públicos de la clase Provincia

	private:
		std::string      _nombre;     //!<  \brief Nombre de la Provincia
		int              _codigo;	  //!<  \brief Código de la Provincia

	  	ed::ListaDoblementeEnlazadaOrdenadaMunicipios _listaMunicipios; //!<  \brief Lista de municipios de la Provincia


	/////////////////////////////////////////////////////////////////////

	//!	\name  Métodos públicos de la clase Provincia

  public: 

	//!	\name Constructor
   /*! @fn Provincia()
       @brief Constructor de la clase Provincia
       @param nombre Nombre de la provincia
       @param codigo Codigo de la provincia*/
    Provincia(std::string nombre="ninguno",int codigo=0){_nombre=nombre;_codigo=codigo;} 
	/////////////////////////////////////////////////////////////////////

	//!	\name Observadores
    inline std::string getNombre()const{return _nombre;}
    inline int getCodigo()const{return _codigo;}
    inline bool hayMunicipios()const{
            if (_listaMunicipios.isEmpty())return false;
            return true;
            }                            
    inline int getNumeroMunicipios()const{return _listaMunicipios.nItems();}
    inline bool existeMunicipio(std::string cadena){ed::Municipio aux(cadena);
                                                   return _listaMunicipios.find(aux);}

    inline ed::Municipio getMunicipio(std::string cadena){
                                            #ifndef NDEBUG
			                           assert(existeMunicipio(cadena));
		                              #endif
                                                   return _listaMunicipios.getCurrentItem();}     
	/////////////////////////////////////////////////////////////////////

	//!	\name Modificadores



	/////////////////////////////////////////////////////////////////////

	//! \name Función de escritura de la clase Provincia



	/////////////////////////////////////////////////////////////////////

	//! Operaciones con ficheros


}; //Fin de la clase  Provincia


} // Fin del espacio de nombres ed

#endif // _PROVINCIA_HPP_
