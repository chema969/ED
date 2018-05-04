/*!
	\file MonticuloMediciones.hpp
	\brief Se define el TAD MonticuloMediciones.
	\author Jose Manuel Cuevas Muñoz
	\date 18/04/2018
*/

#ifndef _MONTICULO_MEDICIONES_HPP
#define _MONTICULO_MEDICIONES_HPP

#include <vector>

#include <cassert>

#include "macros.hpp"

#include "Medicion.hpp"

#include "MonticuloMedicionesInterfaz.hpp"


// COMPLETAR EL CÓDIGO E INCLUIR LOS COMENTARIOS DE DOXYGEN

namespace ed
{

// COMPLETAR EL CÓDIGO E INCLUIR LOS COMENTARIOS DE DOXYGEN

class MonticuloMediciones : public MonticuloMedicionesInterfaz
{
	private:

		//! \name Atributos privados de la clase MonticuloMediciones

		std::vector<Medicion> _vector; //!<vector de la stl donde se almacena el monticulo 


		//! \name Métodos privados de la clase MonticuloMediciones

/*!
		\brief  Retorna un elemento del monticulo
                \param i: Elemento referenciado para retornar
		\note   Función inline
		\note   Función privada
                \pre (i>=0) y (i< size())
                \return Retorna el elemento referenciado por i dentro del monticulo
    */
        inline ed::Medicion getElement(int i) const{
                   #ifndef NDEBUG
                     assert(i>=0);
                     assert(i< size());
                   #endif
               return _vector[i];
                 }

/*!
		\brief  Modifica un elemento del monticulo
                \param i: Elemento referenciado para modificar
                \param m: Medicion que se asignará en el sitio i
		\note   Función inline
		\note   Función privada
                \pre (i>=0) y (i< size())
                \post getElement(i) == m
    */
         inline void setElement(int i,Medicion m){
                   #ifndef NDEBUG
                     assert(i>=0);
                     assert(i< size());
                   #endif
                 _vector[i]=m;
                 }

/*!
		\brief  Retorna el hijo izquierdo de un valor en el monticulo
                \param i: Elemento del que se sacara el hijo izquierdo
		\note   Función inline
		\note   Función privada
                \pre (i>=0) 
                \post valorDevuelto == 2 * i + 1
                \return Hijo izquierdo
    */ 
         inline int getLeftChild(int i)const{
                   #ifndef NDEBUG
                     assert(i>=0);
                   #endif
                  return 2*i+1;
                  }

/*!
		\brief Retorna el hijo derecho de un valor en el monticulo
                \param i: Elemento del que se sacara el hijo izquierdo
		\note   Función inline
		\note   Función privada
                \pre (i>=0) 
                \post valorDevuelto == 2 * i + 2
                \return Hijo derecho
    */ 
         inline int getRightChild(int i)const{
                   #ifndef NDEBUG
                     assert(i>=0);
                   #endif
                  return 2*i+2;
                  }


/*!
		\brief Retorna el padre de un valor en el monticulo
                \param i: Elemento del que se sacara el padre
		\note   Función inline
		\note   Función privada
                \pre (i>=0) 
                \post valorDevuelto ==(i-1)/2
                \return Padre
    */ 
         inline int getParent(int i)const{
                   #ifndef NDEBUG
                     assert(i>=1);
                   #endif
                  return (i-1)/2;
                  }

/*!
		\brief El elemento indicado por el índice es subido en el montículo hasta que se verifica la ordenación de máximos.
                \param i: Indice
		\note   Función privada
                \pre i>=0 y i<size()
                \post Si no es la cima, el elemento actual es menor o igual que su padre
                \post Si tiene hijo izquierdo, el elemento actual es mayor o igual que él y, además, si tiene hijo derecho, es mayor o igual que él.         
    */
          void shiftUp(int i);

/*!
		\brief El elemento indicado por el índice es bajado en el montículo hasta que se verifica la ordenación de máximos.
                \param i: Indice
		\note   Función privada
                \pre i>=0 y i<size()
                \post Si no es la cima, el elemento actual es menor o igual que su padre
                \post Si tiene hijo izquierdo, el elemento actual es mayor o igual que él y, además, si tiene hijo derecho, es mayor o igual que él.         
    */
          void shiftDown(int i);

/*!
		\brief Busca si existe un elemento en el vector
                \param m: Elemento que se buscará dentro del monticulo
		\note   Función privada
                \return true si existe el elememto, false si no              
    */ 
          bool has(ed::Medicion m);

/*!
		\brief Intercambia dos elementos dentro del vector
                \param a: Elemento uno a intercambiar
                \param b: Elemento dos a intercambiar
		\note   Función inline
		\note   Función privada
                \pre (a>=0) y (a<size())
                \pre (b>=0) y (b<size())
                \post _vector[a]=old._vector[b]
                \post _vector[b]=old._vector[a]              
    */ 
          void swap(int a, int b){
               #ifndef NDEBUG
                     assert(a>=0);
                     assert(a< size());
                     assert(b>=0);
                     assert(b< size());
                   #endif
                ed::Medicion aux(getElement(a));
                setElement(a,getElement(b));
                setElement(b,aux);
                }
	  /////////////////////////////////////////////////////////////////////////////////////

	//! \name Métodos públicos de la clase MonticuloMediciones
	public:

		//! \name Constructor
/*!
    \brief Constructor de de la clase 
    \note Funcion inline
    \post isEmpty()==true
  */
         MonticuloMediciones(){
           _vector.reserve(367);
             #ifndef NDEBUG
                     assert(isEmpty());
                   #endif
                 }

		//! \name Observadores

        bool isEmpty() const{ return _vector.empty();}
        



/*!
        \brief  Devuelve el número de elementos o ítems del monticulo
        \note   Funcion inline
        \note   Función de tipo "const": no puede modificar al objeto actual
        \return Número entero que representa el número de elementos o ítems del monticulo
    */
        int size() const{return _vector.size();}
       



        inline ed::Medicion top()const{  
                        #ifndef NDEBUG
                        assert(!isEmpty());//No puede estar vacia
                       #endif
                       return getElement(0);}
		////////////////////////////////////////////////////////////

		//! \name Operaciones de modificación

       inline void insert(const ed::Medicion &m){
                   _vector.push_back(m);
                   shiftUp(size()-1);
                   #ifndef NDEBUG
                    assert(!isEmpty());
                    assert(has(m));
                   #endif
                   }
        
       void remove();

/*!
        \brief  Elimina los elementos de la lista
        \note   Funcion inline
        \post   isEmpty()==true
    */
       inline void removeAll(){

                _vector.clear();//Usa la función clear del vector de la stl para vaciar el montículo
                #ifndef NDEBUG
                   assert(isEmpty());
                #endif
       }

/*!	
	\brief   Modificador que modifica la cabeza 
        \param   m: referencia constante a una medición la cual cambia la  cabeza
	\pre     isEmtpy() == falso
  	\post    has(m) == verdadero
*/
       void modify(ed::Medicion m);
       void heapsort();

     //! \name Operadores

/*!	
	\brief  Operador que asigna un monticulo a otro
        \param   m: referencia constante a un monticulo de mediciones el cual se asignara
	\pre     m_!=*this
  	\return Objeto cambiado
*/   
	inline MonticuloMediciones operator=(const MonticuloMediciones &m){
                          ed::MonticuloMediciones n(*this);
                          #ifndef NDEBUG
                                assert(m._vector!=n._vector);
                         #endif
                             removeAll();
                             this->_vector=m._vector;
                             return *this;
                            }



		////////////////////////////////////////////////////////////////////

		//! \name Función de escritura

/*!	
	\brief  Imprime el vector
*/   
        void print() {
           int i;
           for(i=0;i<size();i++){ std::cout<<_vector[i]<<std::endl;
                                      if((i+1)%22==0){
		                           std::cout << "Pulse ";
					   std::cout << BIGREEN;
					   std::cout << "ENTER";
					   std::cout << RESET;
              				   std::cin.ignore();}
                }

		
            }
	}; // Clase MonticuloMediciones

} // Espacio de nombres ed


#endif // _MONTICULO_MEDICIONES_HPP
