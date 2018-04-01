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
        while((it->getNext()!=NULL)){
         aux=it->getItem(); 
           if(item<aux){ setCurrent(it); if(!isFirstItem())setCurrent(it->getPrevious()); return false; }
           if(item==aux){
              setCurrent(it);
              return true;
             }
           it=it->getNext();            }
     setCurrent(it);
     if(it->getItem()==item)return true;
	setCurrent(it->getPrevious());
		
     return false;
       
}


void ed::ListaDoblementeEnlazadaOrdenadaMunicipios::insert(const ed::Municipio &item){
      /*  #ifndef NDEBUG
		assert(!find(item));
	#endif //NDEBUG*/
       
       int n=nItems();
       ed::NodoDoblementeEnlazadoMunicipio *nodo= new ed::NodoDoblementeEnlazadoMunicipio(item,NULL,NULL);
       find(item);
       if(isEmpty())
          setHead(nodo); 
      else{     
       std::cout<<"current es ahora "<<_current->getItem()<<std::endl;     
       if(n==1){
           std::cout<<"Hay solo un elemento"<<std::endl;
           if(nodo->getItem()<_head->getItem()){
                  std::cout<<"se insertara al final"<<std::endl;
                  _head->setNext(nodo);
                  nodo->setPrevious(_head);
                }  
           else{std::cout<<"se insertara al principio"<<std::endl;
               _head->setPrevious(nodo);
               nodo->setNext(_head);
               setHead(nodo);
              }
          }
        else{      
          if(isLastItem()){
         std::cout<<"current es ahora "<<_current->getItem()<<",se inserta al final"<<std::endl;
             _current->setNext(nodo);
             nodo->setPrevious(_current);
          }
          else{
             if(isFirstItem()){
               std::cout<<"se insertara al principio"<<std::endl;
               _current->setPrevious(nodo);
               nodo->setNext(_current);
               setHead(nodo);
              }
             else{
               ed::NodoDoblementeEnlazadoMunicipio *aux=_current->getNext();
               aux->setPrevious(nodo);
               _current->setNext(nodo);
               nodo->setPrevious(_current);
               nodo->setNext(aux);
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
       

void ed::ListaDoblementeEnlazadaOrdenadaMunicipios::remove(){
    #ifndef NDEBUG
	assert(!isEmpty());
    #endif //NDEBUG 
    int n=nItems();
    if(n==1)  delete _current;
    else{
        if(isFirstItem()){
               ed::NodoDoblementeEnlazadoMunicipio *aux=_current->getNext();
               aux->setPrevious(NULL);
               delete _current;
                if(!isEmpty()) setCurrent(aux);
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
