/*!
	\file MonticuloMedicionesInterfaz.hpp
	\brief Se define la interfaz del TAD MonticuloMediciones.
	\author Jose Manuel Cuevas Muñoz
	\date  21-04-2018
*/

#ifndef _MONTICULO_MEDICIONES_INTERFAZ_HPP
#define _MONTICULO_MEDICIONES_INTERFAZ_HPP

#include "Medicion.hpp"

// Se incluye la clase MonticuloMedicionesInterfaz dentro del espacio de nombres de la asigantura: ed
namespace ed
{

//!  Definición de la clase virtual pura MonticuloMedicionesInterfaz	
	class MonticuloMedicionesInterfaz
	{
           //! \name Métodos públicos de la clase MonticuloMediciones
		public:

			//! \name Observadores

/*!	
	\brief   Método público que permite saber si el monticulo esta vacio o no
	\warning Función virtual pura: se debe redefinir en la clase heredera
        \note   Función de tipo "const": no puede modificar al objeto actual
	\pre     Ninguna
  	\post    Ninguna
        \return true si esta vacio, false si no
*/
          virtual bool isEmpty() const=0;

/*!	
	\brief   Método público que permite obtener la cabeza del monticulo
	\warning Función virtual pura: se debe redefinir en la clase heredera
        \note   Función de tipo "const": no puede modificar al objeto actual
	\pre     isEmpty() == falso
  	\post    valorDevuelto == getElement(0)
        \return La cabeza del monticulo
*/
          virtual ed::Medicion top()const=0;


           //! \name Operaciones de modificación

/*!	
	\brief   Modificador que inserta una medición
	\warning Función virtual pura: se debe redefinir en la clase heredera
        \param   m: referencia constante a una medición la cual se insertara
	\pre     Ninguna
  	\post    isEmtpy() == falso
  	\post    has(medición) == verdadero
*/
          virtual void insert(const ed::Medicion &m)=0;

/*!	
	\brief   Modificador que borra la cabeza de la lista
	\warning Función virtual pura: se debe redefinir en la clase heredera
	\pre     isEmpty() == falso
  	\post    size()==old.size()-1
*/ 
          virtual void remove()=0;
                  
	}; // Clase MonticuloMedicionesInterfaz

} // Espacio de nombres ed

#endif //  _MONTICULO_MEDICIONES_INTERFAZ_HPP
