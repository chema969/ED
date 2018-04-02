/*!
	\file   ListaDoblementeEnlazadaOrdenadaMunicipios.hpp
	\brief  Clase de una lista doblemente enlazada y ordenada de Municipios
	\author  
	\date  
	\version 1.0

*/

#ifndef __ListaDoblementeEnlazadaOrdenadaMunicipios_HPP__
#define __ListaDoblementeEnlazadaOrdenadaMunicipios_HPP__

// Para comprobar las pre y post-condiciones
#include <cassert>

#include "ListaOrdenadaMunicipiosInterfaz.hpp"

#include "NodoDoblementeEnlazadoMunicipio.hpp"

#include "Municipio.hpp"

// DEBES ESPECIFICAR LAS FUNCIONES DE LA CLASE ListaDoblementeEnlazadaOrdenadaMunicipios


/*!	
	\namespace ed
	\brief Espacio de nombres para la asignatura Estructuras de Datos

*/ 
namespace ed {
 
/*!	
  \class ListaDoblementeEnlazadaOrdenadaMunicipios 
  \brief Definición de la clase ListaDoblementeEnlazadaOrdenadaMunicipios
	  	\n Lista doblemente enlazada de nodos de municipios ordenados alfabéticamente de forma ascendente 
*/
  class ListaDoblementeEnlazadaOrdenadaMunicipios:public ed::ListaOrdenadaMunicipiosInterfaz
  {
	//! \name  Atributos y métodos privados 

	private:
		ed::NodoDoblementeEnlazadoMunicipio *_head;    //!< \brief puntero al primer nodo de la lista
		ed::NodoDoblementeEnlazadoMunicipio *_current; //!< \brief puntero al nodo current de la lista
                int _nItems;
    // \name Observadores privados 

    inline ed::NodoDoblementeEnlazadoMunicipio * getHead() const
	{
		return this->_head;
	}

	inline ed::NodoDoblementeEnlazadoMunicipio * getCurrent() const
	{
		return this->_current;
	}

    //! \name Modificadores privados 

	inline void setHead(ed::NodoDoblementeEnlazadoMunicipio *head) 
	{
		this->_head = head;

		#ifndef NDEBUG
			// Se comprueba la postcondición
			assert(this->getHead() == head);
		#endif //NDEBUG		
	}

    inline void setCurrent(ed::NodoDoblementeEnlazadoMunicipio *current) 
	{
		this->_current = current;

		#ifndef NDEBUG
			// Se comprueba la postcondición
			assert(this->getCurrent() == current);
		#endif //NDEBUG		
	}

    inline void insertLast(ed::NodoDoblementeEnlazadoMunicipio *nodo){
         _current->setNext(nodo);
             nodo->setPrevious(_current);}


    inline void insertFirst(ed::NodoDoblementeEnlazadoMunicipio *nodo){
         _current->setPrevious(nodo);
               nodo->setNext(_current);
               setHead(nodo);}

    inline void insertBetween(ed::NodoDoblementeEnlazadoMunicipio *nodo){
          ed::NodoDoblementeEnlazadoMunicipio *aux=_current->getPrevious();
               aux->setNext(nodo);
               _current->setPrevious(nodo);
               nodo->setPrevious(aux);
               nodo->setNext(_current);}
	//! \name  Métodos públicos

	public:

	//! \name Constructores

    /*! 
		\brief Construye una lista vacía
		\note  Función inline
		\post  isEmpty() == true
	*/
	inline ListaDoblementeEnlazadaOrdenadaMunicipios()
    {
        _nItems=0;
	_head=NULL;
        _current=NULL;
		 #ifndef NDEBUG
			// Se comprueba la postcondición
			assert(isEmpty());
		#endif //NDEBUG		
	}
	
  
	//! \name Destructor 

    /*! 
		\brief Destruye una lista liberando la memoria de sus nodos
		\note Función codificada en el fichero cpp
		\post isEmpty() == true
	*/
	~ListaDoblementeEnlazadaOrdenadaMunicipios ()
     {
       removeAll();
     }


	//! \name Observadores públicos 

	/*!
		\brief  Comprueba si la lista está vacía
		\note   Función inline
		\note   Función de tipo "const": no puede modificar al objeto actual
        \return true, si la lista está vacía; false, en caso contrario
    */
	inline bool isEmpty() const
	{
  		if(getHead()==NULL) return true;
		return false;
	}

	int nItems() const;
        inline bool isFirstItem() const{	 
                #ifndef NDEBUG
			assert(!isEmpty());
		#endif //NDEBUG	
                if(_current->getItem()==_head->getItem())return true;
		return false;
          }
        bool isLastItem() const;
        inline ed::Municipio const & getCurrentItem() const{
                 #ifndef NDEBUG
			assert(!isEmpty());
		#endif //NDEBUG	
		return _current->getItem();
        }
        ed::Municipio const &getPreviousItem()const;
        ed::Municipio const &getNextItem()const;
    //! \name Modificadores públicos

 
          void gotoLast();
         inline void gotoPrevious(){       
         #ifndef NDEBUG
		assert(!isEmpty());
		assert(!isFirstItem());
	#endif //NDEBUG
        setCurrent(_current->getPrevious());
       }

	inline void gotoHead(){
              #ifndef NDEBUG
			assert(!isEmpty());
		#endif
               setCurrent(getHead());
              #ifndef NDEBUG
			assert(isFirstItem());
		#endif
    }

        inline void gotoNext(){       
         #ifndef NDEBUG
		assert(!isEmpty());
		assert(!isLastItem());
	#endif //NDEBUG
        setCurrent(_current->getNext());
       }
        bool find(const ed::Municipio &item);
        void insert(const ed::Municipio &item);
        void remove();
        void removeAll(){
                setCurrent(_head);
        while(_current!=NULL) remove();
        #ifndef NDEBUG
			assert(isEmpty());
		#endif 
            }
	// COMPLETAR EL RESTO DE MODIFICADORES PÚBLICOS



	

}; // Fin de la clase ListaDoblementeEnlazadaOrdenadaMunicipios
 
} //namespace ed
 
#endif // __ListaDoblementeEnlazadaOrdenadaMunicipios_HPP__
