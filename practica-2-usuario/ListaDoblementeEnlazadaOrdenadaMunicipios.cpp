/*!
	\file   ListaDoblementeEnlazadaOrdenadaMunicipios.cpp
	\brief  Clase de una lista doblemente enlazada y ordenada de Municipios
	\author  
	\date  
	\version 1.0
*/

// Para comprobar las pre y post-condiciones
#include <cassert>
#include <iostream>
#include <string>
#include "ListaDoblementeEnlazadaOrdenadaMunicipios.hpp"
#include "NodoMunicipioInterfaz.hpp"
#include "Municipio.hpp"
#include "NodoDoblementeEnlazadoMunicipio.hpp"

int ed::ListaDoblementeEnlazadaOrdenadaMunicipios::nItems() const{
    return _nItems;
}

bool ed::ListaDoblementeEnlazadaOrdenadaMunicipios::isLastItem() const{
        #ifndef NDEBUG
		assert(!isEmpty());
	#endif //NDEBUG
    if(_current->getNext()==NULL) return true;
    return false;
}

ed::Municipio const &ed::ListaDoblementeEnlazadaOrdenadaMunicipios::getPreviousItem() const{
         #ifndef NDEBUG
		assert(!isEmpty());
		assert(!isFirstItem());
	#endif //NDEBUG
       ed::NodoDoblementeEnlazadoMunicipio *it=_current->getPrevious();
       return it->getItem();
}

ed::Municipio const &ed::ListaDoblementeEnlazadaOrdenadaMunicipios::getNextItem() const{
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
      if(isEmpty())return false;
      ed::NodoDoblementeEnlazadoMunicipio *it=getHead();
      ed::Municipio aux;
      if(nItems()==1) {
          setCurrent(_head);
           if(_head->getItem()==item) return true;
           else return false;
           }
       if(item==it->getItem()){setCurrent(it);return true;}
       if(item<it->getItem()){
                             setCurrent(it);
                              return false; }
       it=it->getNext();
        while((it->getNext()!=NULL)){
           if(item==it->getItem()){
              setCurrent(it);
              return true;
             }
           if(item<it->getItem()){
                             setCurrent(it);
                              return false; }
             it=it->getNext();    
                          }
     setCurrent(it);
     if(_current->getItem()==item)return true;	
     return false;   
}


void ed::ListaDoblementeEnlazadaOrdenadaMunicipios::insert(const ed::Municipio &item){
       int n=nItems();
       ed::NodoDoblementeEnlazadoMunicipio *nodo= new ed::NodoDoblementeEnlazadoMunicipio(item,NULL,NULL);
       if(!find(item)){
       if(isEmpty())
          setHead(nodo); 
      else{     
       if(n==1){
           if(_head->getItem()<nodo->getItem())
             insertLast(nodo);
                
           else
            insertFirst(nodo);
              
          }
        else{
         if(n==2){
            ed::NodoDoblementeEnlazadoMunicipio *aux=_head->getNext();
            if(item<_head->getItem()) insertFirst(nodo);
            else if(item<aux->getItem()){setCurrent(_head->getNext()); insertBetween(nodo);}
            else insertLast(nodo);}
         else{    
          if(isLastItem()){
             if(item<_current->getItem())insertBetween(nodo);
             else insertLast(nodo);
           }
          else{
             if(isFirstItem()){
               insertFirst(nodo);
              }
             else{
               insertBetween(nodo);
             }
           }
         }
         }
        }
       setCurrent(nodo);
       _nItems=_nItems+1;
     #ifndef NDEBUG
		assert(n+1==nItems());
                assert(!isEmpty()); 
	#endif //NDEBUG
}
}

void ed::ListaDoblementeEnlazadaOrdenadaMunicipios::remove(){
    #ifndef NDEBUG
	assert(!isEmpty());
    #endif //NDEBUG 
    int n=nItems();
    if(n==1) { _head=NULL;_current=NULL;}
    else{
        if(isFirstItem()){
               ed::NodoDoblementeEnlazadoMunicipio *aux=_current->getNext();
               aux->setPrevious(NULL);
               delete _current;
                if(!isEmpty()){ setCurrent(aux); setHead(aux);}
              }
         else{
            if(isLastItem()){
               ed::NodoDoblementeEnlazadoMunicipio *aux=_current->getPrevious();
               aux->setNext(NULL);
               delete _current;
                 if(!isEmpty()) setCurrent(aux);
              }
            else{
                ed::NodoDoblementeEnlazadoMunicipio *auxP=_current->getPrevious();
                ed::NodoDoblementeEnlazadoMunicipio *auxN=_current->getNext();
                auxP->setNext(auxN);
                auxN->setPrevious(auxP);
                delete _current;
                setCurrent(auxN);
                 }
              }
         }
      _nItems=_nItems-1;
      #ifndef NDEBUG
	assert(n-1==nItems());
      #endif //NDEBUG
}
