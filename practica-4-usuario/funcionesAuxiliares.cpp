/*!
  \file   funcionesAuxiliares.cpp
  \brief  Código de las funciones auxiliares del programa principal del grafo
  \author Jose Manuel Cuevas Muñoz
  \date   24-05-2018
*/

#include "Grafo.hpp"
#include "funcionesAuxiliares.hpp"
#include "macros.hpp"
#include <iostream>
#include <fstream>
#include <string>
int ed::menu(){

	int opcion;
	int posicion;

	// Se muestran las opciones del menú
	posicion=2;

	// Se borra la pantalla
	std::cout << CLEAR_SCREEN;

	PLACE(1,10);
	std::cout << BIBLUE;
	std::cout << "Programa principial | Opciones del menú";
	std::cout << RESET;

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout <<  "[1] Comprobar si el grafo esta vacio";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout << "[2] Cargar el grafo desde un fichero";

	PLACE(posicion++,10);
	std::cout << "[3] Grabar los vertices del grafo en un fichero";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;
 
	PLACE(posicion++,10);
	std::cout << "[4] Imprimir el grafo";

	PLACE(posicion++,10);
	std::cout <<  "[5] Mostrar el arbol abarcador de coste minimo:prim";

	PLACE(posicion++,10);
	std::cout << "[6] Mostrar el arbol abarcador de coste minimo:kruskal";

	PLACE(posicion++,10);
	std::cout << "[7] Mostrar si dos nodos están unidos";

        PLACE(posicion++,10);
	std::cout << "[8] Mostrar si todos los nodos estan unidos";
	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	

	PLACE(posicion++,10);
	std::cout << "[9] Insertar un vertice en el grafo";

	PLACE(posicion++,10);
	std::cout << "[10] Borrar un vertice en el grafo";

        PLACE(posicion++,10);
	std::cout << "[11] Insertar un lado en el grafo";

        PLACE(posicion++,10);
	std::cout << "[12] Borrar un lado del grafo";
        //////////////////////////////////////////////////////////////////////////////
	posicion++;

         PLACE(posicion++,10);
	std::cout << "[13] Calcular el camino minimo con dijkstra";        

	posicion++;

	PLACE(posicion++,10);
	std::cout << BIRED << "[0] Salir";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout << BIGREEN;
	std::cout << "Opción: ";
	std::cout << RESET;

	// Se lee el número de opción
	std::cin >> opcion;

    // Se elimina el salto de línea del flujo de entrada
    std::cin.ignore();

	return opcion;
}


void ed::estaVacio(const ed::Grafo  &grafo){
    if(grafo.isEmpty())
       std::cout<<BIRED<<"El grafo está vacio"<<RESET<<std::endl;
    
    else
       std::cout<<BIGREEN<<"El grafo tiene "<<grafo.size()<<" vertices"<<RESET<<std::endl;
}




void ed::leeFichero(std::string nombre, ed::Grafo &grafo){
     std::ifstream fichero;
     fichero.open(nombre.c_str());
     if(!fichero.good()){
             std::cout<<BIRED<<"No se pudo cargar el fichero de entrada"<<RESET<<std::endl;
             return;}
     ed::Vertice aux;
     while(fichero>>aux){
          if(!grafo.findVertice(aux.getX(),aux.getY())){
             grafo.insertVertice(aux.getX(),aux.getY());
             for(int i=0;i<grafo.size()-1;i++){
                grafo.insertLado(i,grafo.size()-1);
             }
     }
     }
     fichero.close();
     std::cout<<BIGREEN<<"Se ha realizado correctamente"<<RESET<<std::endl;
 }



void ed::escribeFichero(std::string nombre, ed::Grafo &grafo){
     std::ofstream fichero;
     fichero.open(nombre.c_str());
     if(!fichero.good()){
             std::cout<<BIRED<<"No se pudo cargar el fichero de entrada"<<RESET<<std::endl;
             return;}
     grafo.gotoFirstVertice();
     do{
        fichero<<grafo.currentVertice().getX()<<" "<<grafo.currentVertice().getY()<<"\n";
     }while(grafo.gotoNextVertice());
     fichero.close();
     std::cout<<BIGREEN<<"Se ha realizado correctamente"<<RESET<<std::endl;
 }





void ed::unidos(ed::Grafo const &grafo){
     if(grafo.isEmpty()){std::cout<<BIRED<<"El grafo esta vacio"<<RESET<<std::endl;return;}
     std::cout<<BIBLUE<<"Escribe los dos lados separados por espacios"<<RESET<<std::endl;
     int lado1,lado2;
     std::cin>>lado1>>lado2;
     std::cin.ignore();
     if((lado1<0)||(lado2<0)||(lado1>=grafo.size())||(lado2>=grafo.size())){
           std::cout<<BIRED<<"Al menos uno de los valores fue erroneo"<<RESET<<std::endl;
           return;
     }
     if(grafo.estanUnidos(lado1,lado2))std::cout<<BICYAN<<"Se puede llegar desde el vertice "<<lado1<<" hasta el vertice "<<lado2<<" y viceversa"<<RESET<<std::endl;
     else std::cout<<BIRED<<"No se puede llegar desde el vertice "<<lado1<<" hasta el vertice "<<lado2<<" y viceversa"<<RESET<<std::endl;
 }







void ed::insertarVertice(ed::Grafo &grafo){
     std::cout<<BIBLUE<<"Escribe los puntos (x,y) del vertice a añadir separados por espacios"<<RESET<<std::endl;
     double x,y;
     std::cin>>x>>y;
     std::cin.ignore();
     if(grafo.findVertice(x,y)){
       std::cout<<BIRED<<"Vertice actualmente dentro del grafo"<<RESET<<std::endl;
      }
     else{
       grafo.insertVertice(x,y);
       std::cout<<BIGREEN<<"Vertice introducido con exito en el grafo"<<RESET<<std::endl;
       for(int i=0;i<grafo.size()-1;i++)
           grafo.insertLado(i,grafo.size()-1);
     }
 }



void ed::borrarVertice(ed::Grafo &grafo){
     std::cout<<BIBLUE<<"Escribe los puntos (x,y) del vertice a borrar separados por espacios"<<RESET<<std::endl;      
     double x,y;
     std::cin>>x>>y;
     std::cin.ignore();
     if(!grafo.findVertice(x,y)){
       std::cout<<BIRED<<"No existe este vertice dentro del grafo"<<RESET<<std::endl;
      }
     else{
       grafo.removeVertice();
       std::cout<<BIGREEN<<"El vertice ha sido eliminado"<<RESET<<std::endl;
     }
}




void ed::insertarLado(ed::Grafo &grafo){
    if(grafo.isEmpty()){std::cout<<BIRED<<"El grafo esta vacio"<<RESET<<std::endl;return;}
     std::cout<<BIBLUE<<"Escribe los dos vertices del lado separados por espacios"<<RESET<<std::endl;
     int lado1,lado2;
     std::cin>>lado1>>lado2;
     std::cin.ignore();

     if((lado1<0)||(lado2<0)||(lado1>=grafo.size())||(lado2>=grafo.size())){
           std::cout<<BIRED<<"Al menos uno de los valores fue erroneo"<<RESET<<std::endl;
           return;
     }

     if(lado1==lado2){
           std::cout<<BIRED<<"No puedes unir un lado con si mismo"<<RESET<<std::endl;
           return;
     }

     if(grafo.adjacent(lado1,lado2)){
           std::cout<<BIRED<<"Ya existe un lado que une esos dos nodos"<<RESET<<std::endl;
           return;
     }

     grafo.insertLado(lado1,lado2);
     std::cout<<"\n\n"<<BIGREEN<<"EL lado ha sido correctamente insertado"<<RESET<<std::endl;
   }




void ed::borrarLado(ed::Grafo &grafo){
    if(grafo.isEmpty()){std::cout<<BIRED<<"El grafo esta vacio"<<RESET<<std::endl;return;}
     std::cout<<BIBLUE<<"Escribe los dos vertices del lado separados por espacios"<<RESET<<std::endl;
     int lado1,lado2;
     std::cin>>lado1>>lado2;
     std::cin.ignore();

     if((lado1<0)||(lado2<0)||(lado1>=grafo.size())||(lado2>=grafo.size())){
           std::cout<<BIRED<<"Al menos uno de los valores fue erroneo"<<RESET<<std::endl;
           return;
     }

     if(!grafo.adjacent(lado1,lado2)){
           std::cout<<BIRED<<"No existe ningun lado que una esos dos nodos"<<std::endl;
           return;
     }

     grafo.findLado(lado1,lado2);
     grafo.removeLado();
     std::cout<<"\n\n"<<BIGREEN<<"EL lado ha sido correctamente eliminado"<<RESET<<std::endl;
     }



void ed::caminoMinimo(ed::Grafo &grafo){
     if(grafo.isEmpty()){std::cout<<BIRED<<"El grafo esta vacio"<<RESET<<std::endl;return;}
     if(grafo.size()==1){std::cout<<BIRED<<"El grafo es demasiado pequeño para aplicar dikjstra"<<RESET<<std::endl;return;}
     std::cout<<BIBLUE<<"Escribe el vertice de origen"<<RESET<<std::endl;
     int origen,destino=-1;
     std::cin>>origen;
     std::cin.ignore();

     if((origen<0)||(origen>=grafo.size())){std::cout<<BIRED<<"Valor de origen erroneo"<<RESET<<std::endl;return;}

     ed::Dijkstra camino=grafo.dijkstra(origen);
     
     while(destino==-1){
       std::cout<<BIBLUE<<"Escribe el vertice destino"<<RESET<<std::endl;
       std::cin>>destino;
       std::cin.ignore();
       if((destino<0)||(destino>=grafo.size())){std::cout<<BIRED<<"Valor de destino erroneo,vuelve a introducir"<<RESET<<std::endl; destino=-1;}
     }
       std::cout<<"\n\n"<<BICYAN<<"El camino minimo es ";

       escrituraRecursiva(camino,destino,origen);
       std::cout<<"con un peso de "<<camino.distancias[destino]<<RESET<<std::endl;
}





void ed::escrituraRecursiva(ed::Dijkstra camino,int destino,int origen){
     if(destino==origen){
        std::cout<<origen<<", ";
        return;
     }
     else{
        ed::escrituraRecursiva(camino,camino.predecesores[destino],origen);
        std::cout<<destino<<", ";
     }
 }
