/*!
  \file   funcionesAuxiliares.cpp
  \brief  Código de las funciones auxiliares del programa principal del grafo
  \author Jose Manuel Cuevas Muñoz
  \date   24-05-2018
*/

#include "Grafo.hpp"
#include "funcionesAuxiliares.hpp"
#include "Lado.hpp"
#include "macros.hpp"
#include <iostream>
#include <cassert>
#include <algorithm>
#include <vector>
#include <fstream>
#include <string>
#include <limits>
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

   //Prueba si el fichero se abrió bien
     if(!fichero.good()){
             std::cout<<BIRED<<"No se pudo cargar el fichero de entrada"<<RESET<<std::endl;
             return;}


     ed::Vertice aux;
     while(fichero>>aux){
          if(!grafo.findVertice(aux.getX(),aux.getY())){

             grafo.insertVertice(aux.getX(),aux.getY());
             for(int i=0;i<grafo.size()-1;i++){

               //Une cada vertice con el resto
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

   //Prueba si el fichero se abrió bien
     if(!fichero.good()){
             std::cout<<BIRED<<"No se pudo cargar el fichero de entrada"<<RESET<<std::endl;
             return;}
     
   //Mientras existan vertices, los mete en un fichero
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

     //Comprueba que sean valores validos
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
 
    //Comprueba que no exista el vertice 
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

    //Comprueba que exista el vertice 
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

   //Antes de añadirlo, hace multiples validaciones a los valores pasados por teclado
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

   //Antes de eliminarlo, hace multiples validaciones a los valores pasados por teclado
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
     if( camino.distancias[destino]!=std::numeric_limits<double>::infinity()){
       std::cout<<"\n\n"<<BICYAN<<"El camino minimo es ";

       escrituraRecursiva(camino,destino,origen);
       std::cout<<"con un peso de "<<camino.distancias[destino]<<RESET<<std::endl;}
     else
       std::cout<<BIRED<<"\n\nNo existe camino que una a esos dos nodos"<<RESET<<std::endl;
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





ed::Grafo ed::primPrueba(Grafo &grafo){
      #ifndef NDEBUG
         assert(!grafo.isEmpty());
      #endif


      ed::Grafo coste_minimo;
      std::vector<int> vistos;
      std::vector<int> por_ver;
      grafo.gotoFirstVertice();
      do{
          coste_minimo.insertVertice(grafo.currentVertice().getX(),grafo.currentVertice().getY()); //Insertamos todos los vertices en el arbol abarcador de coste minimo
        }while(grafo.gotoNextVertice());


      vistos.push_back(0);//Inserto el nodo origen, 0, en el vector de vistos

      
      //Añado el resto de vertices al vector por_ver
      for(int i=1;i<grafo.size();i++)
          por_ver.push_back(i);


      while(!por_ver.empty()){
      
          //Inicializo las variables temporales
          int from_old=-1;//Vertice del vector de vistos que pertenece al lado
          std::vector<int>::iterator erase;//Elemento del vector por_ver que se borrará en la siguiente iteración
          int from_new=-1;//Vertice del vector de por_ver que pertenece al lado
          double peso=std::numeric_limits<double>::infinity();//Menor peso de los vectores con respecto al 


          for(std::vector<int>::iterator it=por_ver.begin();it!=por_ver.end();it++){
              for(std::vector<int>::iterator jt=vistos.begin();jt!=vistos.end();jt++){
                 
                 if(grafo.adjacent(*it,*jt)){
                     grafo.findLado(*it,*jt);
   
                     if(grafo.currentLado().getPeso()<peso){
                          peso=grafo.currentLado().getPeso();
                          from_old=*jt;
                          erase=it;
                          from_new=*it;
                          } 
                  }
              }            
           }
       
           if((from_old!=-1)&&(from_new!=-1)){
              coste_minimo.insertLado(from_old,from_new);
              por_ver.erase(erase);
              vistos.push_back(from_new);
              }

         //Si el primer elemento del vector es 0 
           else{
              vistos.push_back(por_ver[0]);
              por_ver.erase(por_ver.begin());
              }
      }

      #ifndef NDEBUG
        if(grafo.todosUnidos()) assert(coste_minimo.todosUnidos());
      #endif

   return coste_minimo;
   }










ed::Grafo ed::kruskalPrueba(Grafo &grafo){
      #ifndef NDEBUG
         assert(!grafo.isEmpty());
      #endif

     //Ordena los lados en orden ascendente

      std::vector<Lado> lados_;
      grafo.gotoFirstLado();
      do{
        lados_.push_back(grafo.currentLado());
        }while(grafo.gotoNextLado());

      std::sort(lados_.begin(),lados_.end(),sortLado);


      ed::Grafo coste_minimo;
      std::vector<bool> prueba;
      prueba.resize(grafo.size(),false);

      grafo.gotoFirstVertice();
      do{
          coste_minimo.insertVertice(grafo.currentVertice().getX(),grafo.currentVertice().getY()); //Insertamos todos los vertices en el arbol abarcador de coste minimo
        }while(grafo.gotoNextVertice());


      //Si aún uno de los vertices no esta unido, se une (para eso sirve el vector prueba
      for(unsigned int i=0;i<lados_.size();i++){
           if((prueba[lados_[i].first()]==false)||(prueba[lados_[i].second()]==false)){
                coste_minimo.insertLado(lados_[i].first(),lados_[i].second());
                prueba[lados_[i].first()]=true;
                prueba[lados_[i].second()]=true;
                }

      //Si no, se prueban si pertenecen a arboles distintos y se añade en caso afirmativo
            else{
                 if(!coste_minimo.estanUnidos(lados_[i].first(),lados_[i].second())){
                                     coste_minimo.insertLado(lados_[i].first(),lados_[i].second());  }
                    
                 else if(coste_minimo.todosUnidos())return coste_minimo;
                 }
      }



      #ifndef NDEBUG
        if(grafo.todosUnidos()) assert(coste_minimo.todosUnidos());
      #endif


      return coste_minimo;
}

