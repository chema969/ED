/*!
  \file   funcionesAuxiliares.cpp
  \brief  Código de las funciones auxiliares del programa principal del grafo
  \author Jose Manuel Cuevas Muñoz
  \date   24-05-2018
*/

#include "Grafo.hpp"
#include "funcionesAuxiliares.hpp"
#include "macros.hpp"
#include <iostream>
#include <fstream>
#include <string>
int ed::menu(){

	int opcion;
	int posicion;

	// Se muestran las opciones del menú
	posicion=2;

	// Se borra la pantalla
	std::cout << CLEAR_SCREEN;

	PLACE(1,10);
	std::cout << BIBLUE;
	std::cout << "Programa principial | Opciones del menú";
	std::cout << RESET;

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout <<  "[1] Comprobar si el grafo esta vacio";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout << "[2] Cargar la provincia desde un fichero";

	PLACE(posicion++,10);
	std::cout << "[3] Grabar la provincia en un fichero";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;
 
	PLACE(posicion++,10);
	std::cout << "[4] Consultar datos de la provincia";

	PLACE(posicion++,10);
	std::cout <<  "[5] Mostrar municipios de la provincia";

	PLACE(posicion++,10);
	std::cout << "[6] Modificar datos de la provincia: código o nombre";

	PLACE(posicion++,10);
	std::cout << "[7] Borrar todos los municipios de una provincia";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout << "[8] Consultar un municipio";

	PLACE(posicion++,10);
	std::cout << "[9] Insertar un municipio";

	PLACE(posicion++,10);
	std::cout << "[10] Borrar un municipio";

        PLACE(posicion++,10);
	std::cout << "[11] Mostrar las provincias que empiecen por una letra";
        //////////////////////////////////////////////////////////////////////////////
	posicion++;
         
	PLACE(posicion++,10);
	std::cout << BIRED << "[0] Salir";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout << BIGREEN;
	std::cout << "Opción: ";
	std::cout << RESET;

	// Se lee el número de opción
	std::cin >> opcion;

    // Se elimina el salto de línea del flujo de entrada
    std::cin.ignore();

	return opcion;
}


void ed::estaVacio(const ed::Grafo  &grafo){
    if(grafo.isEmpty())
       std::cout<<BIRED<<"El grafo está vacio"<<RESET<<std::endl;
    
    else
       std::cout<<BIGREEN<<"El grafo tiene "<<grafo.size()<<" vertices"<<RESET<<std::endl;
}




void ed::leeFichero(std::string nombre, ed::Grafo &grafo){
     std::ifstream fichero;
     fichero.open(nombre.c_str());
     ed::Vertice aux;
     while(fichero>>aux){
          if(!grafo.findVertice(aux.getX(),aux.getY())){
             grafo.insertVertice(aux.getX(),aux.getY());
             for(int i=0;i<grafo.size()-1;i++){
                grafo.insertLado(i,grafo.size()-1);
             }
     }
     }
     fichero.close();
 }
