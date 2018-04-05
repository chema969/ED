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
#include <cstdlib>
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

bool ed::Provincia::grabarFichero(std::string nombre){
    std::ofstream fichero;
    fichero.open(nombre.c_str());
    if( (fichero.rdstate() & std::ofstream::failbit ) != 0 )return false;
    fichero<<_codigo<<" "<<_nombre<<"\n";
    _listaMunicipios.gotoHead();
   while(!_listaMunicipios.isLastItem()){
     fichero<<_listaMunicipios.getCurrentItem()<<"\n";
     _listaMunicipios.gotoNext();}
     fichero<<_listaMunicipios.getCurrentItem()<<"\n";
     fichero.close();
     return true;
}

bool ed::Provincia::cargarFichero(std::string nombre){
    std::ifstream fichero;
    fichero.open(nombre.c_str());
      std::string cadena;
      std::getline(fichero,cadena,' ');
      setCodigo(atoi(cadena.c_str()));
      std::getline(fichero,cadena,'\n');
      setNombre(cadena);
    if( (fichero.rdstate() & std::ifstream::failbit ) != 0 )return false;
    ed::Municipio aux;
   while(fichero>>aux){
        _listaMunicipios.insert(aux);     
     }
     return true;
}



