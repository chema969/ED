
/*!
  \file   funcionesAuxiliares.hpp
  \brief  Funciones auxiliares para el programa principal de la práctica 1
  \author 
  \date  
*/

#ifndef _FUNCIONESAUXILIARES_HPP_
#define _FUNCIONESAUXILIARES_HPP_

#include "Vector3D.hpp"


namespace ed
{
	/*! 
		\brief   Muestra el menú del programa principal 
		\return  Devuelve el número de opción elegido
	*/
	int menu();

	/*!    \fn void leerVectores(ed::Vector3D &u, ed::Vector3D &v, ed::Vector3D &w);
               \brief Rellena los vectores de la clase Vector3D
               \param u Vector  \f$\vec{u}\f$
               \param v Vector  \f$\vec{v}\f$
               \param w Vector  \f$\vec{w}\f$
             
               Para el vector \f$\vec{u}\f$, utiliza la funcion leerVector, para los otros dos utiliza el operador >>
	*/
	void leerVectores(ed::Vector3D &u, ed::Vector3D &v, ed::Vector3D &w);

	/*!    \fn void escribirVectores(ed::Vector3D const &u, ed::Vector3D const &v, ed::Vector3D const &w);
               \brief Imprime por pantalla los vectores
               \param u Vector  \f$\vec{u}\f$
               \param v Vector  \f$\vec{v}\f$
               \param w Vector  \f$\vec{w}\f$
             
               Para el vector \f$\vec{u}\f$, utiliza la funcion escribirVector, para los otros dos utiliza el operador <<
	*/
	void escribirVectores(ed::Vector3D const &u, ed::Vector3D const &v, ed::Vector3D const &w);

	/*!    \fn void observadoresDeVectores(ed::Vector3D const &u, ed::Vector3D const &v);
               \brief Imprime por pantalla los principales observadores de los vectores
               \param u Vector  \f$\vec{u}\f$
               \param v Vector  \f$\vec{v}\f$
             
               Imprime por pantalla los gets,el modulo y el angulo con respecto a cada cordenada de los vectores \f$\vec{u}\f$ y \f$\vec{v}\f$
	*/
	void observadoresDeVectores(ed::Vector3D const &u, ed::Vector3D const &v);

	/*!    \fn void modificarVector(ed::Vector3D &u, ed::Vector3D const &v, double k);
               \brief Modifica el vector \f$\vec{u}\f$ con los modificadores de la clase Vector3D
               \param u Vector  \f$\vec{u}\f$
               \param v Vector  \f$\vec{v}\f$
               \param k Costante para multiplicar y sumar
             
               Realiza la suma y multiplicación por costante de k con respecto a \f$\vec{u}\f$, tras eso, realiza la multiplicacion y suma de \f$\vec{u}\f$ sobre \f$\vec{v}\f$
	*/
	void modificarVector(ed::Vector3D &u, ed::Vector3D const &v, double k);

	/*!    \fn void mostrarProductoEscalar(ed::Vector3D const &u, ed::Vector3D const &v);
               \brief Muestra el producto escalar entre \f$\vec{u}\f$ y \f$\vec{v}\f$
               \param u Vector  \f$\vec{u}\f$
               \param v Vector  \f$\vec{v}\f$
             
               \f$ \vec{u}*\vec{v}=u_1*v_1+u_2*v_2+u_3*v_3\f$
	*/
	void mostrarProductoEscalar(ed::Vector3D const &u, ed::Vector3D const &v); 

	/*!    \fn void mostrarProductoVectorial(ed::Vector3D const &u, ed::Vector3D const &v);
               \brief Muestra el producto vectorial entre \f$\vec{u}\f$ y \f$\vec{v}\f$
               \param u Vector  \f$\vec{u}\f$
               \param v Vector  \f$\vec{v}\f$
             
               f$ \vec{w}=\vec{u}\f$^\f$\vec{v}=w_1\vec{i}+w_2\vec{j}+w_3\vec{k}\f$  donde\n
              \f$w_1=u_2*v_3-u_3*v_2\f$\n
              \f$w_2=-u_1*v_3+u_3*v_1\f$\n
              \f$w_3=u_1*v_2-u_2*v_1\f$
	*/
	void mostrarProductoVectorial(ed::Vector3D const &u, ed::Vector3D const &v);

	/*!    \fn void mostrarProductoMixto(ed::Vector3D const &u, ed::Vector3D const &v, ed::Vector3D const &w);
               \brief Muestra el producto mixto entre \f$\vec{u}\f$,\f$\vec{v}\f$ y \f$\vec{w}\f$
               \param u Vector  \f$\vec{u}\f$
               \param v Vector  \f$\vec{v}\f$
               \param v Vector  \f$\vec{v}\f$
            
              Producto mixto=\f$\vec{u}*(\vec{v}\f$^\f$\vec{w})\f$
	*/
	void mostrarProductoMixto(ed::Vector3D const &u, ed::Vector3D const &v, ed::Vector3D const &w);

	/*!    \fn void mostrarOperadores(ed::Vector3D const &u, ed::Vector3D const &v, ed::Vector3D &w,  double k);
               \brief Muestra el funcionamiento de los distintos operadores
               \param u Vector  \f$\vec{u}\f$
               \param v Vector  \f$\vec{v}\f$
               \param v Vector  \f$\vec{v}\f$
               \param k Costante para multiplicar y sumar
              
               Primero comprueba el operador == entre \f$\vec{u}\f$ y \f$\vec{v}\f$, luego asigna a \f$\vec{w}\f$ el valor de \f$\vec{u}\f$, luego la suma y resta unaria y binaria y por ultimo la multiplicacion con la k
	*/
	void mostrarOperadores(ed::Vector3D const &u, ed::Vector3D const &v, ed::Vector3D &w,  double k);

	/*!    \fn void mostrarUnitario(ed::Vector3D const &u,ed::Vector3D const &v);
               \brief Muestra el vector unitario de \f$\vec{u}\f$ y \f$\vec{v}\f$
               \param u Vector  \f$\vec{u}\f$
               \param v Vector  \f$\vec{v}\f$
             
               Vector unitario=\f$\frac{\vec{u}}{||\vec{u}||}\f$
	*/
        void mostrarUnitario(ed::Vector3D const &u,ed::Vector3D const &v);


} // Fin del espacio de nombre de la asignatura: ed

// Fin de _FUNCIONESAUXILIARES_HPP_
#endif

