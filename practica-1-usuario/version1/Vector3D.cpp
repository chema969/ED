/*! 
   \file Vector3D.cpp
   \brief Fichero que contiene el código de las funciones de la clase Vector3D
*/


// Ficheros de cabecera
#include <iostream>

// Para usar sqrt, acos
#include <cmath>

// Para controlar las pre y post condiciones mediante asertos
#include <cassert>

#include "Vector3D.hpp"

// OBSERVADORES




////////////////////////////////////////////////////////////////

// MODIFICADORES

void ed::Vector3D::sumConst(double k){
      set1(get1() + k);
      set2(get2() + k);
      set3(get3() + k);
    }

void ed::Vector3D::sumVect(Vector3D v){
      set1(get1()+v.get1());
      set2(get2()+v.get2());
      set3(get3()+v.get3());
    }

void ed::Vector3D::multConst(int k){
      set1(get1() * k);
      set2(get2() * k);
      set3(get3() * k);
    }

void ed::Vector3D::multVect(Vector3D v){
      set1(get1()*v.get1());
      set2(get2()*v.get2());
      set3(get3()*v.get3());
    }

////////////////////////////////////////////////////////////////////////////////

// OPERADORES

// COMPLETAR



////////////////////////////////////////////////////////////////////////////////

// FUNCIONES DE LECTURA Y ESCRITURA

void ed::Vector3D::leerVector3D(){
    double aux;
    std::cout<<"Introduce v1:";
    std::cin>>aux;
    set1(aux);
    std::cout<<"Introduce v2:";
    std::cin>>aux;
    set2(aux);
    std::cout<<"Introduce v3:";
    std::cin>>aux;
    set3(aux);}


void ed::Vector3D::escribirVector3D(){
    std::cout<<"("<<get1()<<","<<get2()<<","<<get3()<<")"<<std::endl;}
////////////////////////////////////////////////////////////////////////////////


// Se incluyen los operadores sobrecargados dentro del espacio de nombres de ed

namespace ed{


// Producto "por un" escalar (prefijo): k * v
ed::Vector3D & operator* (double k, ed::Vector3D const & objeto)
{
	ed::Vector3D *vectorResultado = new ed::Vector3D();

	// COMPLETAR

	return *vectorResultado;
}


// Sobrecarga del operador de salida
// Se escriben por pantalla las coordenadas del vector 3D  de la forma (v1, v2, v3)
ostream &operator<<(ostream &stream, ed::Vector3D const &objeto)
{
	// COMPLETAR

  return stream;
}

// Sobrecarga del operador de entrada
istream &operator>>(istream &stream, ed::Vector3D &objeto)
{
  // COMPLETAR

  return stream;
} 

} // Fin del espacio de nombres ed
