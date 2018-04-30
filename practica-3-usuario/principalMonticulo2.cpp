/*!

	\file principalMonticulo2.cpp
	\brief Programa principal de la práctica 3 de ED: Monticulo de previsiones
	\author Jose Manuel Cuevas Muñoz
	\date 28/04/2018
	\version 1.0
*/

/*!
 \mainpage Implementación de un heap o montículo de mediciones de una estación meteorológica.
 \author Jose Manuel Cuevas Muñoz
 \date 28/04/2018   
 \version  1.0
*/

// Para los flujos de entrada y salida y para usar locale
#include <iostream>


#include <string>

#include "funcionesAuxiliares.hpp"
          
#include "MonticuloMediciones.hpp"

#include "Medicion.hpp"

#include "macros.hpp"


/*! 
	\brief   Programa principal de la práctica 1: provincia y municipios
	\return  int
*/
int main(){

   ed::MonticuloMediciones m;

	int opcion;

	do{
		// Se elige la opción del menún
		opcion = ed::menu();		

		std::cout << CLEAR_SCREEN;
		PLACE(3,1);

		// Se ejecuta la opción del menú elegida
		switch(opcion)
		{
			case 0: 
					std::cout << INVERSE;
					std::cout << "Fin del programa" << std::endl;
					std::cout << RESET;
			break;

		   ///////////////////////////////////////////////////////////////////

			case 1: 
					std::cout << "[1] Comprobar si el monticulo esta vacio" << std::endl;
                    ed::comprobarMonticuloVacio(m);
					break;

			//////////////////////////////////////////////////////////////////////////////
			case 2: {
					std::cout << "[2] Cargar el monticulo desde un fichero" << std::endl;
                     std::cout<<BIBLUE<<"Introduce nombre del fichero: "<<RESET;
                     std::string nombre;
                     std::cin>>nombre;
                     ed::cargarMonticuloDeFichero(nombre,m);
 				break;}

			case 3:{ 
					std::cout << "[3] Grabar el monticulo en un fichero" << std::endl;
                     std::cout<<BIBLUE<<"Introduce nombre del fichero donde grabar: "<<RESET;
                     std::string nombre;
                     std::cin>>nombre;
                     ed::grabarMonticuloEnFichero(nombre,m);
					break;}

			//////////////////////////////////////////////////////////////////////////////
			case 4: {
				  	std::cout << "[4] Mostrar el monticulo de mediciones " << std::endl; 
                         if(!m.isEmpty())
                                  m.print();
			 else 	  std::cout <<BIRED<< "El monticulo no tiene mediciones" << RESET<<std::endl;
                	break;}

			case 5: 
				  	std::cout << "[5] Mostrar el dia mas lluvioso " << std::endl; 
                                        std::cout<<BICYAN<<m.top()<<std::endl;
					break;


			//////////////////////////////////////////////////////////////////////////////
			case 6: 
					std::cout << "[6] Modificar la cabeza del monticulo" 
							  << std::endl;
                                        ed::modificarCabeza(m);
					break;


			case 7: {
					std::cout << "[7] Borrar todas las mediciones del monticulo" << std::endl;
                                        m.removeAll();
                                        std::cout<<BIRED<<"Todos los elementos han sido borrados "<<std::endl;
					break;
                                      }
			//////////////////////////////////////////////////////////////////////////////
			case 8: 
					std::cout << "[8] Buscar una medición" << std::endl;
                                        ed::buscarElemento(m);
					break;

			case 9: 
					std::cout << "[9] Insertar una medicion" << std::endl;
					break;

			case 10: 
					std::cout << "[10] Borrar la cabeza" << std::endl;
                                        
					break;
                        

			//////////////////////////////////////////////////////////////////////////////
			default:
				std::cout << BIRED;
				std::cout << "Opción incorrecta ";
				std::cout << RESET;
				std::cout << "--> ";
			  	std::cout << ONIRED;
				std::cout << opcion << std::endl;
				std::cout << RESET;
     }
  
    if (opcion !=0)
    {
		PLACE(25,1);
		std::cout << "Pulse ";
		std::cout << BIGREEN;
		std::cout << "ENTER";
		std::cout << RESET;
		std::cout << " para mostrar el ";
		std::cout << INVERSE;
		std::cout << "menú"; 
		std::cout << RESET;

		// Pausa
		std::cin.ignore();

		std::cout << CLEAR_SCREEN;
    }
	  }while(opcion!=0);

	return 0;
}

