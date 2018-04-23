/*!
	\file MonticuloMediciones.cpp
	\brief Fichero que contiene el código de las funciones de la clase MonticuloMediciones.
	\author Jose Manuel Cuevas Muñoz
	\date 18-04-2018
*/

//#include <vector>

#include <cassert>

#include "Medicion.hpp"

#include "MonticuloMediciones.hpp"

////////////////////////////////////////////////////////////////////

// Métodos privados de la clase MonticuloMediciones


void ed::MonticuloMediciones::shiftUp(int i){
        #ifndef NDEBUG
              assert(i>=0);
              assert(i< size());
          #endif
   if(i==0){std::cout<<"Soy la cabeza"<<std::endl; return;}//si es la cabeza, retorna
   int padre=getParent(i);
   if(getElement(padre).getPrecipitacion()<getElement(i).getPrecipitacion()){ //si se cumple la condición, se procede a realizar un swap
             swap(i,padre);
             shiftUp(padre);//Va a realizar esta funcion hasta que sea mayor que el nuevo padre
             return;
             }
    else{ 
        
        #ifndef NDEBUG
           assert(getElement(padre).getPrecipitacion()>=getElement(i).getPrecipitacion());    
           //if(getRightChild(i)>(size()-1)) assert(getElement(i).getPrecipitacion()>=getElement(getRightChild(i)).getPrecipitacion());
          // if(getLeftChild(i)>(size()-1))assert(getElement(i).getPrecipitacion()>=getElement(getLeftChild(i)).getPrecipitacion());
        #endif
        return;
   }
}






void ed::MonticuloMediciones::shiftDown(int i){
        #ifndef NDEBUG
              assert(i>=0);
              assert(i< size());
          #endif
   int hijoIzq=getLeftChild(i);
   int hijoDer=getRightChild(i);
   if((hijoIzq>(size()-1))&&(hijoDer>size()-1))return;//si no tiene hijos, termina la funcion
   if(hijoIzq==(size()-1)){         //Si su hijo izquierdo es el ultimo elemento introducido, puede pasar dos cosas, o que se intercambien el hijo izquierdo y el medicion o que salga de la funcion
           if(getElement(hijoIzq).getPrecipitacion()> getElement(i).getPrecipitacion()) {  
                   ed::Medicion aux(getElement(hijoIzq));
                   setElement(hijoIzq,getElement(i));
                   setElement(i,aux);
                   return;
           }  
            else{
               #ifndef NDEBUG
               if(!(getElement(i)==top())) assert(getElement(i).getPrecipitacion()<getElement(getParent(i)).getPrecipitacion());//Se debe evaluar que el elemento sea menor que su padre y mayor que sus hijos
               assert(getElement(i).getPrecipitacion()>getElement(getLeftChild(i)).getPrecipitacion());
          #endif
              return;}
         }
   if(getElement(hijoIzq).getPrecipitacion()>getElement(hijoDer).getPrecipitacion()) {
         if(getElement(hijoIzq).getPrecipitacion()> getElement(i).getPrecipitacion()) {  
                   ed::Medicion aux(getElement(hijoIzq));
                   setElement(hijoIzq,getElement(i));
                   setElement(i,aux);
                   shiftDown(hijoIzq);//se llama recursivamente a la funcion hasta que se cumpla la condicion
           }  
           else{
               #ifndef NDEBUG
               if(!(getElement(i)==top())) assert(getElement(i).getPrecipitacion()<getElement(getParent(i)).getPrecipitacion());//Se debe evaluar que el elemento sea menor que su padre y mayor que sus hijos
               assert(getElement(i).getPrecipitacion()>getElement(getLeftChild(i)).getPrecipitacion());
               assert(getElement(i).getPrecipitacion()>getElement(getRightChild(i)).getPrecipitacion());
          #endif
              return;}
   }
   else{
           if(getElement(hijoDer).getPrecipitacion()> getElement(i).getPrecipitacion()) {  
                   ed::Medicion aux(getElement(hijoDer));
                   setElement(hijoDer,getElement(i));
                   setElement(i,aux);
                   shiftDown(hijoDer);//se llama recursivamente a la funcion hasta que se cumpla la condicion
           }  
            else{
               #ifndef NDEBUG
               if(!(getElement(i)==top())) assert(getElement(i).getPrecipitacion()<getElement(getParent(i)).getPrecipitacion());//Se debe evaluar que el elemento sea menor que su padre y mayor que sus hijos
               assert(getElement(i).getPrecipitacion()>getElement(getLeftChild(i)).getPrecipitacion());
               assert(getElement(i).getPrecipitacion()>getElement(getRightChild(i)).getPrecipitacion());
          #endif
              return;}
      }

}











bool ed::MonticuloMediciones::has(ed::Medicion m){
     int i;
      for(i=0;i<size();i++){
       if(getElement(i)==m)
          return true;
       }
      return false;
}      
////////////////////////////////////////////////////////////////////////////////////7

// Métodos públicos de la clase MonticuloMediciones

void ed::MonticuloMediciones::remove(){
     #ifndef NDEBUG
       assert(!isEmpty());
     #endif
     int s=size();
     setElement(0,getElement(size()-1));
     _vector.resize(size()-1);
    // shiftDown(0);
    #ifndef NDEBUG
       assert(size()==s-1);
     #endif
}


void ed::MonticuloMediciones::modify(ed::Medicion m){
      setElement(0,m);
      int i;
      for(i=size()-1;i>0;i--){
	      ed::Medicion aux(_vector[0]);
	      _vector[0]=_vector[i];
	      _vector[i]=aux;
	      shiftDown(0);
      }
}


