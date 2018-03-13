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
<<<<<<< HEAD
	#endif //NDEBUG
    if(_current->getNext()!=NULL) return true;
=======
	#endif //NDEBUG	
    ed::NodoDoblementeEnlazadoMunicipio *it=getHead();
       while(it->getNext()!=NULL)
         it=it->getNext();
    if(it==getCurrent()) return true;
>>>>>>> 56cd29cccf5c73c646bc18b9602f2057c0d09349
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

<<<<<<< HEAD
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
      const ed::Municipio aux;
        while(it->getNext()!=NULL){
         aux=it->getItem();
           if(item.getNombre()==aux.getNombre()){
              setCurrent(it);
              return true;
             }
           it=it->getNext();
            }
         
       
}
=======

void ed::ListaDoblementeEnlazadaOrdenadaMunicipios::gotoLast(){
               #ifndef NDEBUG
			assert(!isEmpty());
		#endif
               ed::NodoDoblementeEnlazadoMunicipio *it=getHead();
              while(it->getNext()!=NULL)
               it=it->getNext();
               setCurrent(it);
              #ifndef NDEBUG
			assert(_current==_head);
		#endif
    }
>>>>>>> 56cd29cccf5c73c646bc18b9602f2057c0d09349
