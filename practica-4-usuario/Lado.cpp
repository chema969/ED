/*! 
   \file Lado.cpp
   \brief Funciones de la clase Lado
*/
#include "Lado.hpp"

namespace ed{


   int ed::Lado::other(int i)const{
               if(!has(i)) return -1;
               if(i==vertice1_){
                      return vertice2_;
                           }
               else
                      return vertice1_;
               }















}//!\brief Fin del espacio de nombres ed
