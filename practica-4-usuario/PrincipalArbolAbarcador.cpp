/*!

	\file principalArbolAbarcador.cpp
	\brief Programa principal de la práctica 4 de ED: Grafo y arbol abarcador del coste minimo
	\author Jose Manuel Cuevas Muñoz
	\date 28/04/2018
	\version 1.0
*/

#include <iostream>
#include "funcionesAuxiliares.hpp"
#include "Grafo.hpp"
/*! 
	\brief   Programa principal de la práctica 4: Grafo y arbol abarcador del coste mínimo
	\return  int
*/
int main(){

	ed::Grafo grafo;

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
					std::cout << "[1] Comprobar si el grafo tiene vertices" << std::endl;
                    ed::estaVacio(grafo);
					break;

			//////////////////////////////////////////////////////////////////////////////
			case 2: 
					std::cout << "[2] Cargar la provincia desde un fichero" << std::endl;
				break;

			case 3: 
					std::cout << "[3] Grabar la provincia en un fichero" << std::endl;
					break;

			//////////////////////////////////////////////////////////////////////////////
			case 4: 
				  	std::cout << "[4] Consultar datos de la provincia: " << std::endl; 
					break;

			case 5: 
				  	std::cout << "[5] Mostrar municipios de la provincia: " << std::endl; 
					break;


			//////////////////////////////////////////////////////////////////////////////
			case 6: 
					std::cout << "[6] Modificar datos de la provincia: código o nombre" << std::endl;
					break;


			case 7: 
					std::cout << "[7] Borrar todos los municipios de una provincia" << std::endl;
					break;

			//////////////////////////////////////////////////////////////////////////////
			case 8: 
					std::cout << "[8] Consultar un municipio" << std::endl;
					break;

			case 9: 
					std::cout << "[9] Insertar un municipio" << std::endl;
					break;

			case 10: 
					std::cout << "[10] Borrar un municipio" << std::endl;
					break;
                        
            case 11: 
                    std::cout << "[11] Mostrar las provincias que empiecen por una letra" << std::endl;
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
