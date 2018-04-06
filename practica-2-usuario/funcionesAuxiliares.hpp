/*!
  \file   funcionesAuxiliares.hpp
  \brief  Funciones auxiliares para el programa principal de la práctica 2
  \author 
  \date  
*/

#ifndef _FUNCIONESAUXILIARES_HPP_
#define _FUNCIONESAUXILIARES_HPP_

#include "Provincia.hpp"


// SE DEBEN INCLUIR LOS COMENTARIOS DE DOXYGEN DE CADA FUNCIÓN

namespace ed
{

  int menu();

	///////////////////////////////////////////////////////////////////
 
/*!
		\brief Comprueva si la provincia esta vacia
                \param provincia Provincia a evaluar

                Inprime si la provicia tiene municipios o no
    */
	void comprobarProvinciaVacia(ed::Provincia & provincia);

	///////////////////////////////////////////////////////////////////

/*!
		\brief Carga un fichero pasado por teclado
                \param provincia Provincia a evaluar
    */
	void cargarProvincia(ed::Provincia & provincia);

/*!
		\brief Graba en un fichero pasado por teclado
                \param provincia Provincia a evaluar
    */
	void grabarProvincia(ed::Provincia & provincia);

	///////////////////////////////////////////////////////////////////

/*!
		\brief Consulta los datos de la provincia
                \param provincia Provincia a evaluar
           
                Se escribe de forma nombre|codigo|numero de hombres|numero de mujeres|numero de personas|numero de municipios
    */
	void consultarDatosDeProvincia(ed::Provincia & provincia);

/*!
		\brief Graba en un fichero pasado por teclado
                \param provincia Provincia a evaluar

                 Los datos de cada municipio se muestran en el formato Código postal Nombre; Hombres; Mujeres;
    */
	void mostrarMunicipiosDeProvincia(ed::Provincia & provincia);

	///////////////////////////////////////////////////////////////////

/*!
		\brief Modifica el nombre o el codigo de la provincia
                \param provincia Provincia a evaluar
    */
	void modificarDatosDeProvincia(ed::Provincia & provincia);

/*!
		\brief Borra todos los municipios de la provincia
                \param provincia Provincia a evaluar
    */
	void borrarTodosLosMunicipiosDeProvincia(ed::Provincia & provincia);


	///////////////////////////////////////////////////////////////////

/*!
		\brief Busca si un municipio esta en la provincia
                \param provincia Provincia a evaluar
    */
	void consultarMunicipioDeProvincia(ed::Provincia & provincia);

/*!
		\brief Inserta un municipio que no exista anteriormente en la provincia
                \param provincia Provincia a evaluar
    */
	void insertarMunicipioEnProvincia(ed::Provincia & provincia);

/*!
		\brief Borra un municipio que exista 
                \param provincia Provincia a evaluar
    */
	void borrarMunicipioDeProvincia(ed::Provincia & provincia);

/*!
		\brief Muestra los municipios cuyos nombres empiezan por la letra pasada por teclado
                \param provincia Provincia a evaluar
    */
        void mostrarProvinciaLetra(ed::Provincia &provincia);
} // Fin del espacio de nombre de la asignatura: ed

// Fin de _FUNCIONESAUXILIARES_HPP_
#endif

