/*! 
   \file Vector3D.hpp
   \brief Fichero de definición de la clase Vector3D: vector libre de tres dimensiones
*/

#ifndef _VECTOR3D_HPP_
#define _VECTOR3D_HPP_

// Entrada y salida 
#include <iostream>

// Para usar abs
#include <cmath>

// Para controlar las pre y post condiciones mediante asertos
#include <cassert>

// COMPLETAR, SI ES PRECISO


// Para la sobrecarga de los operadores de flujo: << y >>
using std::istream;
using std::ostream;

#define COTA_ERROR   1.0e-6 //!< Cota de error para la comparación números reales


// Se incluye la clase Vector3D dentro del espacio de nombre de la asigantura: ed
namespace ed {

//!  Definición de la clase Vector3D:  \f$ \vec{v} = (v_1, v_2, v_3) = v_1 \vec{i} + v_2 \vec{j} + v_3 \vec{k} \f$ 
class Vector3D
{
  //! \name Atributos privados de la clase Vector3D
   private: 
       double x_,y_,z_;


   //! \name Funciones o métodos públicos de la clase Vector3D
   public:

	//! \name Constructores de la clase Vector3D
      Vector3D(){set1(0);set2(0);set3(0);}
      Vector3D(double v1, double v2, double v3){set1(v1);set2(v2);set3(v3);}
      Vector3D(  Vector3D const &v){set1(v.get1());set2(v.get2());set3(v.get3());}

	//! \name Observadores: funciones de consulta de Vector3D
      inline double get1() const{return x_;}
      inline double get2() const{return y_;}
      inline double get3() const{return z_;}      
      inline double modulo() const{return sqrt(get1()*get1()+get2()*get2()+get3()*get3());}
      inline double angulo( Vector3D const &v) const{assert(modulo()*v.modulo()>0);return acos( dotProduct(v) / (modulo() * v.modulo()) );}
      inline double dotProduct( Vector3D const &v) const{return get1() * v.get1()+get2()*v.get2()+get3()*v.get3();}
      inline double alfa() const{assert(modulo()>0); return angulo(Vector3D(1,0,0));}
      inline double beta() const{assert(modulo()>0); return angulo(Vector3D(0,1,0));}
      inline double gamma() const{assert(modulo()>0); return angulo(Vector3D(0,0,1));}
      inline Vector3D crossProduct(Vector3D const &v)const { Vector3D w(get2()*v.get3()-get3()*v.get2(),get3()*v.get1()-get1()*v.get3(),get1()*v.get2()-get2()*v.get1());
                                                              assert(dotProduct(w) == 0); assert(v.dotProduct(w) == 0);return w;}
      double productoMixto(Vector3D const &v, Vector3D const &w)const{return dotProduct(v.crossProduct(w));}
	//! \name Modificadores: funciones de modificación de Vector3D
      inline void set1(double x){x_=x;}
      inline void set2(double y){y_=y;}
      inline void set3(double z){z_=z;}
      void sumConst(double k);
      void sumVect(Vector3D v);
      void multConst(int k);
      void multVect(Vector3D v);
    //! \name Operadores de la clase
   
	// COMPLETAR COMENTARIOS DE DOXYGEN
	Vector3D & operator=(Vector3D const &objeto);

	// COMPLETAR COMENTARIOS DE DOXYGEN
	bool operator == (Vector3D const &objeto) const;

	// COMPLETAR EL RESTO DE OPERADORES
    

	//! \name Funciones lectura y escritura de la clase Vector3D

     void leerVector3D();
     void escribirVector3D();

}; // Fin de la definición de la clase Vector3D


//////////////////////////////////////////////////////////////////////////////////////

//! \name Funciones que utilizan un objetos de la clase Vector3D, pero que no pertenecen a la clase Vector3D

	// COMPLETAR COMENTARIOS DE DOXYGEN
    Vector3D & operator* (double k, Vector3D const & objeto);


	// COMPLETAR COMENTARIOS DE DOXYGEN
    istream &operator>>(istream &stream, Vector3D &objeto);

	// COMPLETAR COMENTARIOS DE DOXYGEN    
	ostream &operator<<(ostream &stream, Vector3D const &objeto);


} // \brief Fin de namespace ed.

//  _VECTOR3D_HPP_
#endif 
