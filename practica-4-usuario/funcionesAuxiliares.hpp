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
}






#endif
