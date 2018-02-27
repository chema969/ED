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
#include <cstdlib>
#include <string>
#include "Vector3D.hpp"

// OBSERVADORES

double ed::Vector3D::angulo( ed::Vector3D const &v) const{
assert(modulo()*v.modulo()>0)
;return acos( dotProduct(v) / (modulo() * v.modulo()) );
}

ed::Vector3D ed::Vector3D::crossProduct(ed::Vector3D const &v)const {
  Vector3D w(get2()*v.get3()-get3()*v.get2(),
            get3()*v.get1()-get1()*v.get3(),
            get1()*v.get2()-get2()*v.get1());
  assert(dotProduct(w) == 0); 
  assert(v.dotProduct(w) == 0);
  double a=abs(w.modulo()-(modulo()*v.modulo()*sin(angulo(v)))); 
  assert(a<=COTA_ERROR);

   return w;  }
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

ed::Vector3D ed::Vector3D::operator+(ed::Vector3D const &v)const{
      ed::Vector3D w;
      w.set1(get1()+v.get1());
      w.set2(get2()+v.get2());
      w.set3(get3()+v.get3());
      return w;
    }

ed::Vector3D ed::Vector3D::operator+()const{
     return *this;
     }

ed::Vector3D ed::Vector3D::operator-(ed::Vector3D const &v)const{
      ed::Vector3D w;
      w.set1(get1()-v.get1());
      w.set2(get2()-v.get2());
      w.set3(get3()-v.get3());
      return w;
    }

ed::Vector3D ed::Vector3D::operator-()const{
      ed::Vector3D w;
      w.set1(get1()*(-1));
      w.set2(get2()*(-1));
      w.set3(get3()*(-1));
      return w;
    }
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


void ed::Vector3D::escribirVector3D()const{
    std::cout<<"("<<get1()<<","<<get2()<<","<<get3()<<")"<<std::endl;}
////////////////////////////////////////////////////////////////////////////////


ed::Vector3D ed::Vector3D::operator* (double k)const
{
    ed::Vector3D *w = new ed::Vector3D();
    w->set1(get1()*k);
    w->set2(get2()*k);
    w->set3(get3()*k);
	return *w;
}
// Se incluyen los operadores sobrecargados dentro del espacio de nombres de ed

namespace ed{

           
// Producto "por un" escalar (prefijo): k * v
ed::Vector3D & operator* (double k, ed::Vector3D const & objeto)
{
	ed::Vector3D *vectorResultado = new ed::Vector3D();
    vectorResultado->set1(objeto.get1()*k);
    vectorResultado->set2(objeto.get2()*k);
    vectorResultado->set3(objeto.get3()*k);
	return *vectorResultado;
}


// Sobrecarga del operador de salida
// Se escriben por pantalla las coordenadas del vector 3D  de la forma (v1, v2, v3)
ostream &operator<<(ostream &stream, ed::Vector3D const &objeto)
{
    
  stream<<"("<<objeto.get1()<<","<<objeto.get2()<<","<<objeto.get3()<<")"<<std::endl;

  return stream;
}

// Sobrecarga del operador de entrada
istream &operator>>(istream &stream, ed::Vector3D &objeto)
{
  double aux1,aux2,aux3;
  stream>>aux1>>aux2>>aux3;
  objeto.set1(aux1);
  objeto.set2(aux2);
  objeto.set3(aux3);
  return stream;
} 

} // Fin del espacio de nombres ed
