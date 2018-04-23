/*!
	\file MonticuloMedicionesInterfaz.hpp
	\brief Se define la interfaz del TAD MonticuloMediciones.
	\author Jose Manuel Cuevas Muñoz
	\date  21-04-2018
*/

#ifndef _MONTICULO_MEDICIONES_INTERFAZ_HPP
#define _MONTICULO_MEDICIONES_INTERFAZ_HPP

#include "Medicion.hpp"


namespace ed
{

	
	class MonticuloMedicionesInterfaz
	{
           //! \name Métodos públicos de la clase MonticuloMediciones
		public:

			//! \name Observadores
                        virtual bool isEmpty() const=0;

                        virtual ed::Medicion top()const=0;
           //! \name Operaciones de modificación
                        virtual void insert(const ed::Medicion &m)=0;
 
                        virtual void remove()=0;
                  
	}; // Clase MonticuloMedicionesInterfaz

} // Espacio de nombres ed

#endif //  _MONTICULO_MEDICIONES_INTERFAZ_HPP
