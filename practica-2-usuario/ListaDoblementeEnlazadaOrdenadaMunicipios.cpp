/*!
	\file   ListaDoblementeEnlazadaOrdenadaMunicipios.cpp
	\brief  Clase de una lista doblemente enlazada y ordenada de Municipios
	\author  
	\date  
	\version 1.0
*/

// Para comprobar las pre y post-condiciones
#include <cassert>
#include <string>
#include "ListaDoblementeEnlazadaOrdenadaMunicipios.hpp"
#include "NodoMunicipioInterfaz.hpp"
#include "Municipio.hpp"
#include "NodoDoblementeEnlazadoMunicipio.hpp"

int ed::ListaDoblementeEnlazadaOrdenadaMunicipios::nItems(){
    ed::NodoDoblementeEnlazadoMunicipio *it=getHead();
    int cont=0;
       while(it->getNext()!=NULL){
	 cont++;
         it=it->getNext();}
    return cont;
}

bool ed::ListaDoblementeEnlazadaOrdenadaMunicipios::isLastItem(){
        #ifndef NDEBUG
		assert(!isEmpty());
	#endif //NDEBUG
    if(_current->getNext()!=NULL) return true;
    return false;
}

ed::Municipio const &ed::ListaDoblementeEnlazadaOrdenadaMunicipios::getPreviousItem(){
         #ifndef NDEBUG
		assert(!isEmpty());
		assert(!isFirstItem());
	#endif //NDEBUG
       ed::NodoDoblementeEnlazadoMunicipio *it=_current->getPrevious();
       return it->getItem();
}

ed::Municipio const &ed::ListaDoblementeEnlazadaOrdenadaMunicipios::getNextItem(){
         #ifndef NDEBUG
		assert(!isEmpty());
		assert(!isLastItem());
	#endif //NDEBUG
       ed::NodoDoblementeEnlazadoMunicipio *it=_current->getNext();
       return it->getItem();
}


void ed::ListaDoblementeEnlazadaOrdenadaMunicipios::gotoLast(){
       #ifndef NDEBUG
		assert(!isEmpty());
	#endif //NDEBUG
     ed::NodoDoblementeEnlazadoMunicipio *it=getCurrent();
       while(it->getNext()!=NULL) it=it->getNext();
     setCurrent(it);
    }


bool ed::ListaDoblementeEnlazadaOrdenadaMunicipios::find(const ed::Municipio &item){
      ed::NodoDoblementeEnlazadoMunicipio *it=getHead();
      ed::Municipio aux;
        while(it->getNext()!=NULL){
         aux=it->getItem();
           if(item.getNombre()==aux.getNombre()){
              setCurrent(it);
              return true;
             }
           it=it->getNext();
            }
     return false;
       
}


void ed::ListaDoblementeEnlazadaOrdenadaMunicipios::insert(const ed::Municipio &item){
       ed::NodoDoblementeEnlazadoMunicipio *nodo= new ed::NodoDoblementeEnlazadoMunicipio(item,NULL,NULL);
       ed::NodoDoblementeEnlazadoMunicipio *it=getHead();
       ed::NodoDoblementeEnlazadoMunicipio *it2=_head->getNext();
       bool he_insertado=false;
       ed::Municipio itItem, it2Item;   
       itItem=it->getItem();
         if(itItem.getNombre()>item.getNombre()){
           it->setPrevious(nodo);
           nodo->setNext(it);
           he_insertado=true;
           }
       while((!he_insertado)&&(it2->getNext()!=NULL)){
          itItem=it->getItem();
          it2Item=it2->getItem();
            if((itItem.getNombre()<item.getNombre())&&(it2Item.getNombre()>item.getNombre())){
               nodo->setNext(it2);
               nodo->setPrevious(it);
               it->setNext(nodo);
               it2->setPrevious(nodo);
               he_insertado=true;
            }
           it=it->getNext();
          it2=it2->getNext();
         }
}
       
