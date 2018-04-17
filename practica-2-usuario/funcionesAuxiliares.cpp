/*!
  \file   funcionesAuxiliares.cpp
  \brief  Código de las funciones auxiliares del programa principal de la provincia
  \author 
  \date   
*/

#include <iostream>
#include <string>  

// Para usar atoi
#include <stdlib.h>

#include "Provincia.hpp"

#include "Municipio.hpp"

#include "funcionesAuxiliares.hpp"


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
	std::cout <<  "[1] Comprobar si la provincia tiene municipios";

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


//////////////////////////////////////////////////////////////////////////////

void ed::comprobarProvinciaVacia(ed::Provincia &provincia)
{
     if(provincia.hayMunicipios())
	std::cout <<BIGREEN<< "La provincia tiene municipios" <<RESET<< std::endl;
     else
        std::cout <<BIRED<< "La provincia no tiene municipios" << RESET<<std::endl;

	return;
}

//////////////////////////////////////////////////////////////////////////////

void ed::cargarProvincia(ed::Provincia &provincia)
{
	 std::cout <<BIYELLOW<< "Indique el nombre del fichero" <<RESET<< std::endl;
         std::string aux;
         std::cin>>aux;
         if(provincia.cargarFichero(aux))
         	std::cout <<BIGREEN<< "Fichero cargado correctamente" <<RESET<< std::endl;
        else std::cout <<BIRED<< "Error al cargar el fichero" <<RESET<< std::endl;
	return;
}

void ed::grabarProvincia(ed::Provincia  &provincia)
{
	std::cout <<BICYAN<< "Indique el nombre del fichero(Uno que actualmente no exista en la carpeta)" <<RESET<< std::endl;
        std::string aux;
         std::cin>>aux;
         if(provincia.grabarFichero(aux))
         	std::cout <<BIGREEN<< "Fichero grabado correctamente" <<RESET<< std::endl;
        else std::cout <<BIRED<< "Error al grabar el fichero" <<RESET<< std::endl;
	return;
}

//////////////////////////////////////////////////////////////////////

void ed::consultarDatosDeProvincia(ed::Provincia &provincia)
{
	std::cout <<BICYAN<< "NOMBRE|CODIGO|N HOMBRES|N MUJERES|N PERSONAS|N MUNICIPIOS" <<RESET<< std::endl;
        std::cout<<provincia.getNombre()<<" "<<provincia.getCodigo()<<"   "<<provincia.getTotalHombres()<<"    "<<provincia.getTotalMujeres()<<"     "<<provincia.getTotalHabitantes()<<"     "<<provincia.getNumeroMunicipios()<<std::endl;
}     


//
void ed::mostrarMunicipiosDeProvincia(ed::Provincia & provincia)
{
	std::cout <<BICYAN<< "CODIGO POSTAL|NOMBRE|N HOMBRES|N MUJERES" <<RESET<< std::endl;
        provincia.escribirMunicipios();
	return;
}


////////////////////////////////////////////////////////////////////////
void ed::modificarDatosDeProvincia(ed::Provincia &provincia)
{



	int opcion, codigo;
	std::string nombre; 

	do{
		std::cout << BIYELLOW  << "Nombre de la provincia: "  << RESET 
				  << provincia.getNombre() << std::endl; 
		std::cout << BIYELLOW << "Código de la provincia: " << RESET
				  << provincia.getCodigo() << std::endl  << std::endl;

		std::cout << "Indique qué dato desea modificar: " << std::endl;
		std::cout << BIBLUE << "(1) Nombre " << std::endl;
		std::cout << BIBLUE << "(2) Código" << std::endl  << std::endl;
		std::cout << BIRED << "(0) Salir" << std::endl << std::endl  << std::endl;
		std::cout << BIGREEN;
		std::cout << "Opción: ";
		std::cout << RESET;

		// Se lee el número de opción
		std::cin >> opcion;

    	// Se elimina el salto de línea del flujo de entrada
	    std::cin.ignore();

		std::cout << std::endl;
			
		switch(opcion)
		{
			case 0: 
					// Fin de las modificaciones
					break;
			case 1:
					std::cout << BIGREEN;
					std::cout << "Nuevo nombre de la provincia: ";
					std::cout << RESET;
					std::getline(std::cin,nombre);
					provincia.setNombre(nombre);
					break;

			case 2:
					std::cout << BIGREEN;
					std::cout << "Nuevo código de la provincia: ";
					std::cout << RESET;
					std::cin >> codigo;
					provincia.setCodigo(codigo);
					break;
			default:
					std::cout << BIRED << "Opción incorrecta:" << RESET 
							  << opcion << std::endl;
		}
	}while (opcion != 0);

	return;
}


void ed::borrarTodosLosMunicipiosDeProvincia(ed::Provincia &provincia)
{
      int opcion=3;
	std::cout <<BICYAN<< "Se borraran todos los municipios ¿Estas seguro?" << RESET<<std::endl;
             while ((opcion!=2)&&(opcion!=1)){
                std::cout << BIRED << "(1) Borrar " << std::endl;
		std::cout << BIBLUE << "(2) No borrar" << std::endl  << std::endl;
                std::cin>>opcion;
                if(opcion==1)provincia.borrarTodosLosMunicipios();
                else if(opcion==2) return;
                else std::cout << BIRED << "Opción incorrecta" << RESET<< std::endl; 
                }
               
	return;
}


void ed::consultarMunicipioDeProvincia(ed::Provincia &provincia)
{
	 std::cout <<BIYELLOW<< "Indique el nombre del municipio" <<RESET<< std::endl;
         char aux2[200];
         std::cin.getline (aux2,200);
         std::string aux=aux2;
         if(provincia.existeMunicipio(aux)) std::cout << BIGREEN << "Existe el municipio" << RESET  << std::endl;
         else std::cout << BIPURPLE << "No existe el municipio" << RESET  << std::endl;
	return;
}

void ed::insertarMunicipioEnProvincia(ed::Provincia &provincia)
{
         ed::Municipio mun;
         std::cout <<BIYELLOW<< "Indique el codigo postal del municipio" <<RESET<< std::endl;
         int i;
         std::cin>>i;
         std::cin.ignore();
         mun.setCodigoPostal(i);
	 std::cout <<BIYELLOW<< "Indique el nombre del municipio" <<RESET<< std::endl;
         char aux2[200];
         std::cin.getline (aux2,200);
         std::string aux=aux2;
         mun.setNombre(aux);
         std::cout <<BIYELLOW<< "Indique el numero de hombres del municipio" <<RESET<< std::endl;
         std::cin>>i;
         std::cin.ignore();
         mun.setHombres(i);
         std::cout <<BIYELLOW<< "Indique el numero de mujeres del municipio" <<RESET<< std::endl;
         std::cin>>i;
         std::cin.ignore();
         mun.setMujeres(i);
         provincia.insertarMunicipio(mun);

	return;
}

  


void ed::borrarMunicipioDeProvincia(ed::Provincia &provincia)
{
	std::cout <<BIYELLOW<< "Indique el nombre del municipio" <<RESET<< std::endl;
         char aux2[200];
         std::cin.getline (aux2,200);
         std::string aux=aux2;
         provincia.borrarMunicipio(aux);

	return;
}




void ed::mostrarProvinciaLetra(ed::Provincia &provincia)
{
     std::cout<<BIPURPLE<<"Introduzca un solo caracter (en mayuscula)"<<RESET<<std::endl; 
     std::string a;
     std::cin>>a;
     std::cin.ignore();
     while(a.size()!=1){
        std::cout<<BIPURPLE<<"Introduzca "<<BIRED<<"un solo caracter "<<BIPURPLE"(en mayuscula)"<<RESET<<std::endl; 
        std::cin>>a;
        std::cin.ignore();
       }
     provincia.getMunicipiosPrimeraLetra(a);
    }


