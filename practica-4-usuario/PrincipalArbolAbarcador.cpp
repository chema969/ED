/*!

	\mainpage PRACTICA 4:Implementación de un grafo para conseguir el arbol abarcador de coste minimo
	\brief Programa principal de la práctica 4 de ED: Grafo y arbol abarcador del coste minimo
	\author Jose Manuel Cuevas Muñoz
	\date 28/04/2018
	\version 1.0
*/

/*! 
        \file    PrincipalArbolAbarcador.cpp
	\brief   Programa principal de la práctica 4: Grafo y arbol abarcador del coste mínimo
*/
#include <string>
#include <iostream>
#include "funcionesAuxiliares.hpp"
#include "Grafo.hpp"
/*! 
	\brief   Función principal de la práctica 4
	\return  int
*/
int main(){

	ed::Grafo grafo;

	int opcion;

	do{
		// Se elige la opción del menú
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
			case 2: {
					std::cout << "[2] Cargar el grafo desde un fichero" << std::endl;
                     std::string fichero;
                     std::cout<<BIBLUE<<"Introduce el nombre del fichero a cargar"<<RESET<<std::endl;
                     std::cin>>fichero;
                     std::cin.ignore();
                     ed::leeFichero(fichero,grafo);
				break;
                                  }
			case 3: {
					std::cout << "[3] Grabar el grafo en un fichero" << std::endl;
                        if(grafo.isEmpty()) std::cout<<BIRED<<"El grafo esta vacio"<<RESET<<std::endl;
		        else{
      	                     std::string fichero;
                             std::cout<<BIBLUE<<"Introduce el nombre del fichero a cargar"<<RESET<<std::endl;
                             std::cin>>fichero;
                             std::cin.ignore();
                             ed::escribeFichero(fichero,grafo);
                             }
                		break;
                        }
			//////////////////////////////////////////////////////////////////////////////
			case 4: 
				  	std::cout << "[4] Consultar datos del grafo: " << std::endl; 
                             if(grafo.isEmpty())
                             std::cout<<BIRED<<"El grafo está vacio"<<RESET<<std::endl;
                                     
                             else           grafo.imprimir();
					break;

			
			//////////////////////////////////////////////////////////////////////////////
			case 5: {
					std::cout << "[5] Mostrar el arbol abarcador de coste minimo:prim" << std::endl;
                                         if(grafo.isEmpty()) std::cout<<BIRED<<"El grafo esta vacio"<<RESET<<std::endl;
                                         else{
                                         ed::Grafo aux=ed::primPrueba(grafo);
                                         aux.imprimir();
                                         std::cout<<"El peso total del arbol abarcador de coste minimo es "<<aux.getPesoTotal()<<std::endl;}
					break;
                                    }

			case 6: {
					std::cout << "[6] Mostrar el arbol abarcador de coste minimo:kruskal" << std::endl;
                                       if(grafo.isEmpty()) std::cout<<BIRED<<"El grafo esta vacio"<<RESET<<std::endl;  
                                        else{
                                        ed::Grafo aux=ed::kruskalPrueba(grafo);
                                        aux.imprimir();
                                        std::cout<<"El peso total del arbol abarcador de coste minimo es "<<aux.getPesoTotal()<<std::endl;}
					break;
                                 }
                        case 7: 
				  	std::cout << "[7] Mostrar si dos nodos estan unidos: " << std::endl; 
                                        ed::unidos(grafo);
					break;


			//////////////////////////////////////////////////////////////////////////////
			case 8: {
					std::cout << "[8] Mostrar si todos los nodos estan unidos" << std::endl;
                                        if(grafo.isEmpty()) std::cout<<BIRED<<"El grafo esta vacio"<<RESET<<std::endl;
                                        else{
                                           if(grafo.todosUnidos())std::cout<<BICYAN<<"Se pueden acceder a todos los nodos del grafo desde cualquier nodo"<<RESET<<std::endl;
                                           else std::cout<<BIRED<<"Hay nodos que son inaccesible desde algunos otros nodos"<<RESET<<std::endl;
                                            }
					break;
                                    }
			case 9: 
					std::cout << "[9] Insertar un vertice en el grafo" << std::endl;
                                        ed::insertarVertice(grafo);
					break;

			case 10: 
					std::cout << "[10] Borrar un vertice en el grafo" << std::endl;
                                        ed::borrarVertice(grafo);
					break;
                        
            		case 11: 
                   		        std::cout << "[11] Insertar un lado en el grafo" << std::endl;
                                        ed::insertarLado(grafo);
					break;
                          
                        case 12: 
                   		        std::cout << "[12] Borrar un lado del grafo" << std::endl;
                                        ed::borrarLado(grafo);
					break;           

                          
                        case 13: 
                   		        std::cout << "[13] Calcular el camino minimo con Dijkstra" << std::endl;
                                        ed::caminoMinimo(grafo);
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
