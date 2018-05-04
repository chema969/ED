/*!
  \file   funcionesAuxiliares.hpp
  \brief  Funciones auxiliares para el programa principal de la práctica 3
  \author 
  \date  
*/

#ifndef _FuncionesAuxiliares_HPP_
#define _FuncionesAuxiliares_HPP_

#include "MonticuloMediciones.hpp"

// SE DEBEN INCLUIR LOS COMENTARIOS DE DOXYGEN

namespace ed
{
    /*! 
		\brief   Muestra el menú del programa principal 
		\return  Devuelve el número de opción elegido
	*/
    int menu();

/*!
		\brief Comprueba si el monticulo esta vacia
        \param m: Monticulo a evaluar

                Imprime si la provicia tiene municipios o no
    */
    void comprobarMonticuloVacio(ed::MonticuloMediciones &m);

/*!
		\brief Carga al monticulo el contenido de un fichero de mediciones
        \param monticulo: Monticulo en el que se cargará el fichero
        \param nombreFichero: Nombre del fichero del que se cargará el montículo 
    */
	void cargarMonticuloDeFichero(std::string const & nombreFichero, ed::MonticuloMediciones & monticulo); 

/*!
		\brief   Graba en un fichero el contenido del monticulo 
        \param   monticulo: Monticulo el cual se guardará el fichero
        \param   nombreFichero: Nombre del fichero en el que se guardará el monticulo 
    */
	void grabarMonticuloEnFichero (std::string const & nombreFichero, ed::MonticuloMediciones const & monticulo); 

/*!
		\brief   Modifica la cabeza del montículo
        \pre     m.isEmpty()==false
        \param   m: Monticulo del cual se modificará la cabeza
    */
    void modificarCabeza(ed::MonticuloMediciones &m);

/*!
		\brief   Busca un elemento pasado por teclado dentro del montículo
        \param   m: Monticulo en el que se buscara el elemento 
    */
    void buscarElemento(ed::MonticuloMediciones const &m);

/*!
		\brief   Inserta un elemento en el monticulo 
        \param   m: Monticulo en el que se insertará el elemento
        \post m.isEmpty()==false
    */
        void insertarElemento(ed::MonticuloMediciones &m);

} // Fin del espacio de nombre de la asignatura: ed

// Fin de _FuncionesAuxiliares_HPP_
#endif

