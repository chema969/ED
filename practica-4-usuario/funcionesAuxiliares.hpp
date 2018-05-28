/*!
  \file   funcionesAuxiliares.hpp
  \brief  Código de las funciones auxiliares del programa principal del grafo
  \author Jose Manuel Cuevas Muñoz
  \date   24-05-2018
*/

#ifndef FUNCIONESAUXILIARES_HPP
#define FUNCIONESAUXILIARES_HPP

#include "Grafo.hpp"
namespace ed{
 
       /*! 
		\brief     Menu del programa principal de la practica 3
                \return    Un entero con la opcion escogida
		\pre       Ninguna
		\post      Ninguna
	*/ 
       int menu();

        /*! 
		\brief     Función que imprime por pantalla si el grafo esta vacio o no
                \param     grafo: grafo a evaluar
		\pre       Ninguna
		\post      Niguna
	*/ 
       void estaVacio(ed::Grafo const &grafo);

        /*! 
		\brief     Función que lee un fichero con vertices y lo guarda en el grafo
                \param     nombre: Nombre del fichero
                \param     grafo: grafo a evaluar
		\pre       Existe el fichero
		\post      Niguna
	*/ 
       void leeFichero(std::string nombre, ed::Grafo &grafo);

        /*! 
		\brief     Función que escribe un fichero con los vertices 
                \param     nombre: Nombre del fichero
                \param     grafo: grafo a evaluar
		\pre       El fichero es válido
		\post      Niguna
	*/ 
       void escribeFichero(std::string nombre, ed::Grafo &grafo);

        /*! 
		\brief     Función que evalua si dos elementos del grafo son accesibles entre si
                \param     grafo: grafo a evaluar
		\pre       Ninguna
		\post      Niguna
	*/ 
       void unidos(ed::Grafo const &grafo);

        /*! 
		\brief     Función que permite insertar un vertice que no estubiera anteriormente en un grafo
                \param     grafo: grafo donde se insertara
		\pre       Ninguna
		\post      Niguna
	*/ 
       void insertarVertice(ed::Grafo &grafo);


        /*! 
		\brief     Función que borra un vertice que estubiera en el grafo
                \param     grafo: grafo de donde borrar
		\pre       Ninguna
		\post      Niguna
	*/ 
       void borrarVertice(ed::Grafo &grafo);

        /*! 
		\brief     Función que inserta un lado que no estubiera insertado anteriormente
                \param     grafo: grafo en el que se inserta
		\pre       Ninguna
		\post      Niguna
	*/ 
       void insertarLado(ed::Grafo &grafo);

        /*! 
		\brief     Función que borra un lado existente
                \param     grafo: grafo donde se borra el lado
		\pre       Ninguna
		\post      Niguna
	*/ 
       void borrarLado(ed::Grafo &grafo);

        /*! 
		\brief     Función que recibe un elemento de la estructura Dijkstra e imprime el camino minimo entre un origen que has dado tú y un destino
                \param     grafo: grafo del que se sacará el camino mínimo
		\pre       Ninguna
		\post      Niguna
	*/ 
       void caminoMinimo(ed::Grafo &grafo);

        /*! 
		\brief     Función que imprime por pantalla el recorrido mínimo entre un origen y un destino
                \param     camino: Objeto de la estructura dijkstra del que se sacará el camino mínimo
                \param     destino: Destino a donde se pretende llegar
                \param     origen: Parametro que no varía y que es el origen de donde se sale
		\pre       Ninguna
		\post      Niguna
	*/ 
       void escrituraRecursiva(ed::Dijkstra camino,int destino,int origen);

        /*! 
		\brief     Función que calcula el arbol abarcador de coste minimo mediante el algoritmo de prim
                \return    Un objeto de la clase grafo que representa el arbol abararcador de coste minimo
		\pre       isEmpty()==false
		\post      if(todosUnidos==true) retval.todosUnidos==true
	*/ 
       ed::Grafo primPrueba(Grafo &grafo);

        /*! 
		\brief     Función que calcula el arbol abarcador de coste minimo mediante el algoritmo de prim
                \return    Un objeto de la clase grafo que representa el arbol abararcador de coste minimo
		\pre       isEmpty()==false
		\post      if(todosUnidos==true) retval.todosUnidos==true
	*/ 
       ed::Grafo kruskalPrueba(Grafo &grafo);
       
        /*! 
		\brief     Función que compara dos lados del grafo
                \note      Función static
                \param     i: Primer lado a comparar
                \param     j: Segundo lado a comparar
                \return    True si el peso i es menor que j, false si j es menor o igual
		\pre       Ninguna
		\post      Ninguna
	*/  
       static bool sortLado(Lado i,Lado j){return i.getPeso()<j.getPeso();}

}






#endif
