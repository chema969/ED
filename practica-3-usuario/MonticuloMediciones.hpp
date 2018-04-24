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

		std::vector<Medicion> _vector; //!<vector donde se almacena el monticulo 


		//! \name Métodos privados de la clase MonticuloMediciones

        inline ed::Medicion getElement(int i) const{
                   #ifndef NDEBUG
                     assert(i>=0);
                     assert(i< size());
                   #endif
               return _vector[i];
                 }


         inline void setElement(int i,Medicion m){
                   #ifndef NDEBUG
                     assert(i>=0);
                     assert(i< size());
                   #endif
                 _vector[i]=m;
                 }
 
         inline int getLeftChild(int i)const{
                   #ifndef NDEBUG
                     assert(i>=0);
                   #endif
                  return 2*i+1;
                  }

         inline int getRightChild(int i)const{
                   #ifndef NDEBUG
                     assert(i>=0);
                   #endif
                  return 2*i+2;
                  }


         inline int getParent(int i)const{
                   #ifndef NDEBUG
                     assert(i>=1);
                   #endif
                  return (i-1)/2;
                  }

          void shiftUp(int i);

          void shiftDown(int i);

          bool has(ed::Medicion m);

          void swap(int a, int b){
                ed::Medicion aux(getElement(a));
                setElement(a,getElement(b));
                setElement(b,aux);
                }
	  /////////////////////////////////////////////////////////////////////////////////////

	//! \name Métodos públicos de la clase MonticuloMediciones
	public:

		//! \name Constructor

         MonticuloMediciones(){
           _vector.reserve(367);
             #ifndef NDEBUG
                     assert(isEmpty());
                   #endif
                 }

		//! \name Observadores

        bool isEmpty() const{ return _vector.empty();}
        




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
       inline void removeAll(){

                _vector.clear();//Usa la función clear del vector de la stl para vaciar el montículo
                #ifndef NDEBUG
                   assert(isEmpty());
                #endif
       }
       void modify(ed::Medicion m);
       void heapsort();

     //! \name Operadores
   
	inline MonticuloMediciones operator=(const MonticuloMediciones &m){
                          ed::MonticuloMediciones n(*this);
                          #ifndef NDEBUG
                                assert(m!=n);
                         #endif
                             removeAll();
                             int i;
                             for(i=0;i<m.size();i++) _vector[i]=m._vector[i];
                             return *this;
                            }



          inline bool operator!=(const MonticuloMediciones &m) const{
                       int i;
                       if(m.size()!=size())return true;
                       for(i=0;i<m.size();i++)
                            if(!(m._vector[i]==_vector[i])) return true;
                       return false;
                        }
		////////////////////////////////////////////////////////////////////

		//! \name Función de escritura

        void print() {
           int i;
           for(i=0;i<size();i++) std::cout<<_vector[i]<<std::endl;
            }
	}; // Clase MonticuloMediciones

} // Espacio de nombres ed


#endif // _MONTICULO_MEDICIONES_HPP
