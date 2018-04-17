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
   /*! 
       @brief Constructor de la clase Provincia
       @param nombre Nombre de la provincia
       @param codigo Codigo de la provincia
       \note   Función inline
       \post  _nombre==nombre, _codigo==codigo */
    Provincia(std::string nombre="ninguno",int codigo=0){_nombre=nombre;_codigo=codigo;} 
	/////////////////////////////////////////////////////////////////////

	//!	\name Observadores
     
    /*!
		\brief Observador que devuelve el nombre de la clase
                \note   Función inline
                \note   Función del tipo const
		\return _nombre, siendo este el nombre de la provincia
    */
    inline std::string getNombre()const{return _nombre;}



      /*!
		\brief Observador que devuelve el codigo de la clase
                \note   Función inline
                \note   Función del tipo const
		\return _codigo, siendo este el codigo de la provincia
    */
    inline int getCodigo()const{return _codigo;}


      /*!
		\brief Observador que indica si la provincia tiene municipios
                \note   Función inline
                \note   Función del tipo const
		\return true si hay municipios en la provincia,false si no
    */
    inline bool hayMunicipios()const{
            if (_listaMunicipios.isEmpty())return false;
            return true;
            }                            

   

   /*!
		\brief Observador que indica el numero de municipios de la provincia
                \note   Función inline
                \note   Función del tipo const
		\return Numero de municipios de la provincia
    */
    inline int getNumeroMunicipios()const{return _listaMunicipios.nItems();}


   /*!
		\brief Observador que indica si el municipio con el nombre indicado pertenece a la provincia
                \param cadena Nombre del municipio
                \note   Función inline
		\return true si está dentro de la provincia, false si no
    */
    inline bool existeMunicipio(std::string cadena){ed::Municipio aux(cadena);
                                                   return _listaMunicipios.find(aux);}
 


 /*!
		\brief Observador que devuelve el municipio con el nombre indicado
                \param cadena Nombre del municipio
                \pre La provincia tiene municipios
                 \note   Función inline
		\return Municipio buscado
    */
    inline ed::Municipio  getMunicipio(std::string cadena){
                                                   if(existeMunicipio(cadena))
                                                   return _listaMunicipios.getCurrentItem();} 


  /*!
		\brief Observador que devuelve el número total de hombres de la provincia
   		\return Número total de hombres de la provincia
    */
     int getTotalHombres(); 


  /*!
		\brief Observador que devuelve el número total de mujeres de la provincia
   		\return Número total de mujeres de la provincia
    */
     int getTotalMujeres();

  /*!
		\brief Observador que devuelve el número total de habitantes de la provincia
   		\return Número total de habitantes de la provincia
                \post getTotalHombres()+getTotalMujeres==getTotalHabitantes();
    */
     inline int getTotalHabitantes(){ return getTotalHombres()+getTotalMujeres();}

   
	/////////////////////////////////////////////////////////////////////

	//!	\name Modificadores

/*!
		\brief Asigna un nuevo nombre a la provincia
                \param nombre Nuevo nombre de la provincia
                \post getNombre()=nombre
                 \note   Función inline
    */
    inline void setNombre(std::string nombre){_nombre=nombre;}


/*!
		\brief Asigna un nuevo código a la provincia
                \param codigo Nuevo codigo de la provincia
                \post getCodigo()=codigo
                 \note   Función inline
    */
    inline void setCodigo(int codigo){_codigo=codigo;}

/*!
		\brief Insertar un municipio en la provincia.
                \param municipio Nuevo municipio a insertar
                \pre  existeMunicipio(municipio.getNombre()) == falso
                 \post   existeMunicipio(municipio.getNombre()) == verdadero
                \post getNumeroMunicipios() = old.getNumeroMunicipios() + 1
    */
    void insertarMunicipio(ed::Municipio municipio);


/*!
		\brief Borra de la provincia el municipio con el nombre indicado
                \param municipio Nuevo municipio a insertar
                \pre  existeMunicipio(municipio.getNombre()) == verdadero
                 \post   existeMunicipio(municipio.getNombre()) == falso
                 \post getNumeroMunicipios() = old.getNumeroMunicipios() - 1
    */
    void borrarMunicipio(std::string nombre);



/*!
		\brief Borra todos los municipios de la provincia.
                 \post   hayMunicipios() == falso
    */
    inline void borrarTodosLosMunicipios(){_listaMunicipios.removeAll();}
	/////////////////////////////////////////////////////////////////////

	//! \name Función de escritura de la clase Provincia

/*!
		\brief Escribe por pantalla la información de la provincia
               
                Escribe en el formato:codigo y nombre de la provincia y posteriormente los datos de cada municipio en el formato Código postal Nombre; Hombres; Mujeres;
    */
    void escribirMunicipios();

/*!
		\brief Escribe por pantalla el nombre de los municipios cuya primera letra sea la indicada por el parametro
                \param a Caracter que representa la primera letra del municipio(solo un caracter)
                
                 Los datos de cada municipio se muestran en el formato Código postal Nombre; Hombres; Mujeres;
    */
  void getMunicipiosPrimeraLetra(std::string a);
	/////////////////////////////////////////////////////////////////////

	//! Operaciones con ficheros


/*!
		\brief Carga los datos de una provincia desde un fichero
                \param nombre Nombre del fichero
                \return true si carga el fichero, false si no
                
                Escribe en el formato:codigo y nombre de la provincia y posteriormente los datos de cada municipio en el formato Código postal Nombre; Hombres; Mujeres;
    */
    bool cargarFichero(std::string nombre);


/*!
		\brief Graba los datos de una provincia en un fichero
                \param nombre Nombre del fichero
                \return true si graba en el fichero, false si no
                
                Escribe en el formato:codigo y nombre de la provincia y posteriormente los datos de cada municipio en el formato Código postal Nombre; Hombres; Mujeres;
    */
    bool grabarFichero(std::string nombre);
}; //Fin de la clase  Provincia


} // Fin del espacio de nombres ed

#endif // _PROVINCIA_HPP_
