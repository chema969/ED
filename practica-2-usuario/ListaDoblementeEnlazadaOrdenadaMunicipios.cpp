/*!
	\file   ListaDoblementeEnlazadaOrdenadaMunicipios.cpp
	\brief  Clase de una lista doblemente enlazada y ordenada de Municipios
	\author  
	\date  
	\version 1.0
*/

// Para comprobar las pre y post-condiciones
#include <cassert>

#include "ListaDoblementeEnlazadaOrdenadaMunicipios.hpp"
#include "NodoMunicipioInterfaz.hpp"
#include "Municipio.hpp"

int ed::ListaDoblementeEnlazadaOrdenadaMunicipios::nItems(){
    ed::NodoDoblementeEnlazadoMunicipio *it=getHead();
    int cont=0;
       while(it->getNext()!=NULL){
	 cont++;
         it=it->getNext()}
    return cont;
}

bool ed::ListaDoblementeEnlazadaOrdenadaMunicipios::isLastItem(){
        #ifndef NDEBUG
		assert(!isEmpty());
	#endif //NDEBUG	
    ed::NodoDoblementeEnlazadoMunicipio *it=getHead();
       while(it->getNext()!=NULL){
         it=it->getNext()}
    if(it==getCurrent()) return true;
    return false;
}

ed::Municipio ed::ListaDoblementeEnlazadaOrdenadaMunicipios::getPreviousItem(){
         #ifndef NDEBUG
		assert(!isEmpty());
		assert(!isFirstItem());
	#endif //NDEBUG
       ed::NodoDoblementeEnlazadoMunicipio *it=_current->getPrevious();
       return it->getItem();
}

ed::Municipio ed::ListaDoblementeEnlazadaOrdenadaMunicipios::getNextItem(){
         #ifndef NDEBUG
		assert(!isEmpty());
		assert(!isLastItem());
	#endif //NDEBUG
       ed::NodoDoblementeEnlazadoMunicipio *it=_current->getNext();
       return it->getItem();
}
