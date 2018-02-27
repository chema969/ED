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
#include <vector>
#include <cstdlib>
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
       std::vector <double> v_;


   //! \name Funciones o métodos públicos de la clase Vector3D
   public:

	//! \name Constructores de la clase Vector3D
       /*!@fn Vector3D()
          @brief Constructor sin parametros,pone todos los puntos a cero 
           */       
      Vector3D(){v_.resize(3,0);}

      /*! @fn  Vector3D(double v1, double v2, double v3) 
          @brief Constructor con tres parametros
          @param v1 Punto x del vector   
          @param v2 Punto y del vector 
          @param v3 Punto z del vector 
        */
      Vector3D(double v1, double v2, double v3){v_.resize(3);set1(v1);set2(v2);set3(v3);}

     /*! @fn Vector3D(  Vector3D const &v)
          @brief Constructor en el que se copia una vector en otro
          @param v Vector que copia 
        */
      Vector3D(  Vector3D const &v){v_.resize(3);set1(v.get1());set2(v.get2());set3(v.get3());}

	//! \name Observadores: funciones de consulta de Vector3D
      /*! @fn double get1
          @brief Observador de la variable x de la clase
          @return X del vector
        */
      inline double get1() const{return v_[0];}

       /*! @fn double get2
          @brief Observador de la variable y de la clase
          @return Y del vector
        */
      inline double get2() const{return v_[1];}

       /*! @fn double get3
          @brief Observador de la variable z de la clase
          @return Z del vector
        */
      inline double get3() const{return v_[2];}

       /*! @fn double modulo
          @brief Devuelve el modulo del vector
          @return \f$ ||\vec{v}|| \f$

         \f$ ||\vec{v}||=\sqrt[2]{v_1^2+v_2^2+v_3^2} \f$
        */
      inline double modulo() const{return sqrt(get1()*get1()+get2()*get2()+get3()*get3());}

     /*! @fn double angulo
          @brief Devuelve el angulo de dos vectores
          @param v Vector con el cual se compara para conseguir el angulo entre ambos
          @return \f$\angle (\vec{u},\vec{v})\f$
          @pre \f$ ||\vec{u}||*||\vec{v}||>0 \f$

          \f$ \angle (\vec{u},\vec{v})=\arccos(\frac{\vec{u}*\vec{v}}{|\vec{u}||*|\vec{v}||} )\f$
        */
      double angulo( Vector3D const &v) const;
      
     /*! @fn double dotProduct
          @brief Devuelve el producto escalar entre dos vectores
          @param v Vector con el cual se multiplica para conseguir el producto escalar entre ambos
          @return \f$\vec{u}*\vec{v}\f$
      
          \f$ \vec{u}*\vec{v}=u_1*v_1+u_2*v_2+u_3*v_3\f$
        */
      inline double dotProduct( Vector3D const &v) const{return get1() * v.get1() + get2() * v.get2() + get3() * v.get3();}

     /*! @fn double alfa
          @brief Calcula el ángulo del vector con el eje X
          @pre \f$||\vec{u}||>0\f$
          @return Angulo con el eje X

          valorDevuelto == angulo(Vector3D(1,0,0))
        */
      inline double alfa() const{assert(modulo()>0); return angulo(Vector3D(1,0,0));}

     /*! @fn double beta
          @brief Calcula el ángulo del vector con el eje Y
          @pre \f$||\vec{u}||>0\f$
          @return Angulo con el eje Y

          valorDevuelto == angulo(Vector3D(0,1,0))
        */
      inline double beta() const{assert(modulo()>0); return angulo(Vector3D(0,1,0));}
      
     /*! @fn double gamma
          @brief Calcula el ángulo del vector con el eje Z
          @pre \f$||\vec{u}||>0\f$
          @return Angulo con el eje Z

          valorDevuelto == angulo(Vector3D(0,0,1))
        */
      inline double gamma() const{assert(modulo()>0); return angulo(Vector3D(0,0,1));}

     /*! @fn Vector3D crossProduct
          @brief Calcula el producto vectorial entre dos vectores
          @param v Vector con el cual se multiplica para conseguir el producto vectorial entre ambos
          @return \f$ \vec{w}\f$=Producto vectorial de \f$\vec{u}\f$ y \f$\vec{v} \f$
          
          \f$ \vec{w}=\vec{u}\f$^\f$\vec{v}=w_1\vec{i}+w_2\vec{j}+w_3\vec{k}\f$  donde\n
          \f$w_1=u_2*v_3-u_3*v_2\f$\n
          \f$w_2=-u_1*v_3+u_3*v_1\f$\n
          \f$w_3=u_1*v_2-u_2*v_1\f$
        */
      Vector3D crossProduct(Vector3D const &v)const;

     /*! @fn double productoMixto
          @brief Devuelve el resultado de calcular el producto escalar del vector actual con el vector obtenido al calcular el producto vectorial de otros dos vectores
          @param v Uno de los vectores para producto mixto
          @param w El otro vector para el producto mixto
          @return Producto mixto de \f$ (\vec{u},\vec{v},\vec{w}) \f$
          
          Producto mixto=\f$\vec{u}*(\vec{v}\f$^\f$\vec{w})\f$
        */
      inline double productoMixto(Vector3D const &v, Vector3D const &w)const{return dotProduct(v.crossProduct(w));}


 /*! @fn Vector3D vectorUnitario
          @brief Devuelve el vector unitario
          @pre \f$||\vec{u}||>0\f$ 
          @return Vector unitario de \f$ \vec{u} \f$
          
          Vector unitario=\f$\frac{\vec{u}}{||\vec{u}||}\f$
        */
      inline Vector3D vectorUnitario()const{assert(modulo()>0);Vector3D v(get1()/modulo(),get2()/modulo(),get3()/modulo()); return v;}     




	//! \name Modificadores: funciones de modificación de Vector3D

      /*! @fn void set1
          @brief Modificador de la variable X de la clase
          @param x Valor que se le quiere dar a la X de la clase
        */
      inline void set1(double x){v_[0]=x;}

      /*! @fn void set2
          @brief Modificador de la variable Y de la clase
          @param x Valor que se le quiere dar a la Y de la clase
        */
      inline void set2(double y){v_[1]=y;}

      /*! @fn void set3
          @brief Modificador de la variable Z de la clase
          @param x Valor que se le quiere dar a la Z de la clase
        */
      inline void set3(double z){v_[2]=z;}

      /*! @fn void sumConst
          @brief Suma una contaste al vector
          @param k Costante que se le sumara al vector

          \f$(u_1+k,u_2+k,u_3+k)\f$
        */
      void sumConst(double k);

      /*! @fn void sumVect
          @brief Suma un vector con otro
          @param v Vector que se le sumara 

          \f$(u_1+v_1,u_2+v_2,u_3+v_3)\f$
        */
      void sumVect(Vector3D v);

      /*! @fn void multConst
          @brief Multiplica una contaste al vector
          @param k Costante que multiplicara al vector

          \f$(u_1*k,u_2*k,u_3*k)\f$
        */
      void multConst(int k);

      /*! @fn void multVect
          @brief Multiplica un vector con otro
          @param v Vector que se le multiplicara 

          \f$(u_1*v_1,u_2*v_2,u_3*v_3)\f$
        */
      void multVect(Vector3D v);
    //! \name Operadores de la clase
   
	   /*! @fn Vector3D operator =(Vector3D const &objeto)
          @brief Iguala dos vectores
          @param objeto Vector al que se iguala 
          @return El vector igualado
        */
	Vector3D & operator=(Vector3D const &objeto){set1(objeto.get1());set2(objeto.get2());set3(objeto.get3());return *this;}

      /*! @fn bool operator==(Vector3D const &objeto)
          @brief Compara dos vectores
          @param objeto Vector con el que se compara
          @return True si son iguales, false si son distintos
        */
	bool operator == (Vector3D const &objeto) const{if((abs(objeto.get1()-get1())<=COTA_ERROR)&&(abs(objeto.get2()-get2())<=COTA_ERROR)&&(abs(objeto.get3()-get3())<=COTA_ERROR)) return true;return false;}
    
    /*! @fn Vector3D operator+(Vector3D const &v)const
          @brief Suma dos vectores
          @param v Vector con el que se suma
          @return El vector sumado

          \f$\vec{w}=(u_1+v_1,u_2+v_2,u_3+v_3)\f$
        */
    Vector3D operator+(Vector3D const &v)const;
   
        /*! @fn Vector3D operator+() const
          @brief Devuelve otro vector que es una copia del vector actual.
          @return La copia del vector
        */
    Vector3D operator+() const;

    /*! @fn V Vector3D operator-(Vector3D const &v)const;
          @brief Resta dos vectores
          @param v Vector con el que se resta
          @return La diferencia de ambos vectores

          \f$\vec{w}=(u_1-v_1,u_2-v_2,u_3-v_3)\f$
        */
    Vector3D operator-(Vector3D const &v)const;

        /*! @fn V Vector3D operator-()const;
          @brief Devuelve otro vector que es una copia negada del vector actual.
          @return La copia negada del vector
        */
    Vector3D operator-()const;

      /*! @fn Vector3D operator*(double k)const;
          @brief Multiplica una contaste al vector
          @param k Costante que multiplicara al vector
          @return La multiplicacion del vector por constantes
  
          \f$(u_1*k,u_2*k,u_3*k)\f$
        */
    Vector3D operator*(double k)const;

     /*! @fn double operator*(Vector3D const &v) const
          @brief Devuelve el producto escalar entre dos vectores
          @param v Vector con el cual se multiplica para conseguir el producto escalar entre ambos
          @return \f$\vec{u}*\vec{v}\f$
      
          \f$ \vec{u}*\vec{v}=u_1*v_1+u_2*v_2+u_3*v_3\f$
        */
    double operator*(Vector3D const &v) const{return dotProduct(v);}

     /*! @fn Vector3D operator^(Vector3D const &v)
          @brief Calcula el producto vectorial entre dos vectores
          @param v Vector con el cual se multiplica para conseguir el producto vectorial entre ambos
          @return \f$ \vec{w}\f$=Producto vectorial de \f$\vec{u}\f$ y \f$\vec{v} \f$
          
          \f$ \vec{w}=\vec{u}\f$^\f$\vec{v}=w_1\vec{i}+w_2\vec{j}+w_3\vec{k}\f$  donde\n
          \f$w_1=u_2*v_3-u_3*v_2\f$\n
          \f$w_2=-u_1*v_3+u_3*v_1\f$\n
          \f$w_3=u_1*v_2-u_2*v_1\f$
        */
    Vector3D operator^(Vector3D const &v) const{return crossProduct(v);}
	//! \name Funciones lectura y escritura de la clase Vector3D
 
     /*! @fn void leerVector3D
          @brief Lee por teclado los parametros del vector
        */
     void leerVector3D() ;

  /*! @fn void escribirVector3D
          @brief Imprime por pantalla los parametros del vector
        */
     void escribirVector3D() const;

}; // Fin de la definición de la clase Vector3D


//////////////////////////////////////////////////////////////////////////////////////

//! \name Funciones que utilizan un objetos de la clase Vector3D, pero que no pertenecen a la clase Vector3D

	   /*! @fn  Vector3D & operator* (double k, Vector3D const & objeto);
          @brief Multiplica una contaste a un vector
          @param k Costante que multiplicara al vector
          @param objeto Vector a multiplicar
          @return La multiplicacion del vector por la constante
  
          \f$(u_1*k,u_2*k,u_3*k)\f$
        */
    Vector3D & operator* (double k, Vector3D const & objeto);


	 /*! @fn istream operator>>(istream &stream, Vector3D &objeto)
          @brief Lee por teclado los parametros del vector separados por espacios
          @param stream Buffer de entrada
          @objeto Vector del cual se incluiran los parametros
          @return Buffer de entrada
        */
    istream &operator>>(istream &stream, Vector3D &objeto);

		 /*! @fn ostream &operator<<(ostream &stream, Vector3D const &objeto);
          @brief Imprime por pantalla los parametros del vector
          @param stream Buffer de salida
          @objeto Vector del cual se leeran los parametros
          @return Buffer de salida
        */  
	ostream &operator<<(ostream &stream, Vector3D const &objeto);


} // \brief Fin de namespace ed.

//  _VECTOR3D_HPP_
#endif 
