/*!
  \file   funcionesAuxiliares.cpp
  \brief  Código de las funciones auxiliares para el programa principal de la práctica 1
  \author Jose Manuel Cuevas Muñoz
  \date 22-04-2018
*/


#include <iostream>

#include <cstdlib>

#include <fstream>

#include <string>

#include "funcionesAuxiliares.hpp"
          
#include "MonticuloMediciones.hpp"

#include "Medicion.hpp"

#include "macros.hpp"



int ed::menu()
{
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
	std::cout << "[1] Comprobar si el monticulo esta vacio";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout << "[2] Cargar el monticulo desde un fichero";

	PLACE(posicion++,10);
	std::cout << "[3] Grabar el monticulo en un fichero";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;
 
	PLACE(posicion++,10);
	std::cout << "[4] Mostrar el monticulo de mediciones";

	PLACE(posicion++,10);
	std::cout <<  "[5] Mostrar el dia mas lluvioso " ;

	PLACE(posicion++,10);
	std::cout << "[6] Modificar la cabeza del monticulo";

	PLACE(posicion++,10);
	std::cout <<"[7] Borrar todas las mediciones del monticulo";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout << "[8] Consultar una fecha";

	PLACE(posicion++,10);
	std::cout << "[9] Insertar una medicion";

	PLACE(posicion++,10);
	std::cout << "[10] Borrar un municipio";

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


void ed::comprobarMonticuloVacio(ed::MonticuloMediciones &m)
{
     if(!m.isEmpty())
	std::cout <<BIGREEN<< "El monticulo tiene "<<m.size()<<" mediciones " <<RESET<< std::endl;
     else
        std::cout <<BIRED<< "El monticulo no tiene mediciones" << RESET<<std::endl;

	return;
}

void ed::cargarMonticuloDeFichero(std::string const & nombreFichero, ed::MonticuloMediciones & monticulo) 
{       
       std::ifstream fichero(nombreFichero.c_str());
       if(!fichero.good())
             std::cout<<BIRED<<"No se pudo cargar el fichero de entrada"<<RESET<<std::endl;
       else {
             std::string dia,mes,agno,prec;
             while(std::getline(fichero,dia,'-')){
                   std::getline(fichero,mes,'-');
                   std::getline(fichero,agno,' ');
                   ed::Fecha f(atoi(dia.c_str()),atoi(mes.c_str()),atoi(agno.c_str()));//Leo el fichero hasta obtener los datos de la fecha y los meto en una Fecha auxiliar f
                   std::getline(fichero,prec,'\n');
                   ed::Medicion m(f,atof(prec.c_str()));
                   monticulo.insert(m);
                     }
                 
               }
      return;
}


void ed::grabarMonticuloEnFichero(std::string const & nombreFichero, 
							      ed::MonticuloMediciones const & monticulo)
{
std::ofstream fichero(nombreFichero.c_str());
       if(!fichero.good())
             std::cout<<BIRED<<"No se pudo cargar el fichero de salida"<<RESET<<std::endl;
       else {
             ed::MonticuloMediciones m=monticulo;//creo un monticulo igual al que quiero introducir
             while(!m.isEmpty()){
                    fichero<<m.top()<<std::endl;
                    m.remove();
                    }
             }
      return;
}


void ed::modificarCabeza(ed::MonticuloMediciones &m){
    if(!m.isEmpty()){
     std::cout<<BIBLUE<<"Introduce la nueva medición\n"<<BIYELLOW<<"Formato: dd-mm-aaaa precipitacion"<<RESET<<std::endl;
     ed::Medicion aux;
     std::cin>>aux;
     m.modify(aux);
       }
    else
      std::cout<<BIRED<<"El monticulo esta vacio por lo que no se puede modificar la cabeza"<<RESET<<std::endl;
     }

 
void ed::buscarElemento(ed::MonticuloMediciones &m){
      std::cout<<BIBLUE<<"Introduce una fecha a buscar\n"<<BIYELLOW<<"Formato: dd-mm-aaaa y un espacio al final"<<RESET<<std::endl;
      ed::Fecha fecha;
      std::cin>>fecha;
      std::cin.ignore();
      ed::Medicion aux(fecha);
      ed::MonticuloMediciones med=m;
      while(!med.isEmpty()){
          if(med.top()==aux){
              std::cout<<BIGREEN<<"Se ha encontrado la medicion"<<std::endl;
              std::cout<<BICYAN<<med.top()<<RESET<<std::endl;
              return;
              }
           med.remove();
           }
      std::cout<<BIRED<<"No se ha encontrado la medición"<<std::endl;
    }
  


