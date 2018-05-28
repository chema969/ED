#ifndef FUNCIONESAUXILIARES_HPP
#define FUNCIONESAUXILIARES_HPP

#include "Grafo.hpp"
namespace ed{
int menu();
void estaVacio(ed::Grafo const &grafo);
void leeFichero(std::string nombre, ed::Grafo &grafo);
void escribeFichero(std::string nombre, ed::Grafo &grafo);
void unidos(ed::Grafo const &grafo);
void insertarVertice(ed::Grafo &grafo);
void borrarVertice(ed::Grafo &grafo);
void insertarLado(ed::Grafo &grafo);
void borrarLado(ed::Grafo &grafo);
void caminoMinimo(ed::Grafo &grafo);
void escrituraRecursiva(ed::Dijkstra camino,int destino,int origen);
}






#endif
