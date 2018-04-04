/*!	

	\file  Provincia.cpp
	\brief Definición de la clase Provincia
	\author  
	\date  
	\version 1.0

*/
//Para los flujos de entrada/salida en ficheros.
#include <fstream>  
#include <iostream>

// Para comprobar las pre y post condiciones
#include <cassert>

#include "Provincia.hpp"


// DEBES CODIFICAR LAS FUNCIONES DE LA CLASE Provincia

///////////////////////////////////////////////////////////////////////////////

// OSBSERVADORES
int ed::Provincia::getTotalHombres(){
    ed::Municipio aux;
    int sum=0;
   _listaMunicipios.gotoHead();
      while(!_listaMunicipios.isLastItem()){
          aux=_listaMunicipios.getCurrentItem();
          sum=sum+aux.getHombres();
          _listaMunicipios.gotoNext();
           }
   aux=_listaMunicipios.getCurrentItem();
   sum=sum+aux.getHombres();
   return sum;
 }

int ed::Provincia::getTotalMujeres(){
    ed::Municipio aux;
    int sum=0;
   _listaMunicipios.gotoHead();
      while(!_listaMunicipios.isLastItem()){
          aux=_listaMunicipios.getCurrentItem();
          sum=sum+aux.getMujeres();
          _listaMunicipios.gotoNext();
           }
   aux=_listaMunicipios.getCurrentItem();
   sum=sum+aux.getMujeres();
   return sum;
 }

/////////////////////////////////////////////////////////////////////////////////////////

// MODIFICADORES
void ed::Provincia::insertarMunicipio(ed::Municipio municipio){
   #ifndef NDEBUG
		assert(!existeMunicipio(municipio.getNombre()));
	#endif
   _listaMunicipios.insert(municipio);
   #ifndef NDEBUG
		assert(existeMunicipio(municipio.getNombre()));
	#endif
}

void ed::Provincia::borrarMunicipio(std::string nombre){
	if(existeMunicipio(nombre)) _listaMunicipios.remove();
	#ifndef NDEBUG
		assert(!existeMunicipio(nombre));
	#endif
}


///////////////////////////////////////////////////////////////////////////////////

// FUNCIÓN DE ESCRITUR
void ed::Provincia::escribirMunicipios(){
std::cout<<_nombre<<" "<<_codigo<<std::endl;
if(!_listaMunicipios.isEmpty()){
ed::Municipio aux;
_listaMunicipios.gotoHead();
   while(!_listaMunicipios.isLastItem()){
     aux=_listaMunicipios.getCurrentItem();
     std::cout<<aux<<std::endl;
     _listaMunicipios.gotoNext();}
aux=_listaMunicipios.getCurrentItem();
std::cout<<aux<<std::endl;
}
}
/////////////////////////////////////////////////////////////////////////////////////////

// OPERACIONES CON FICHEROS


