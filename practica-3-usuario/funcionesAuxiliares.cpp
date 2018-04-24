/*!
  \file   funcionesAuxiliares.cpp
  \brief  Código de las funciones auxiliares para el programa principal de la práctica 1
  \author Jose Manuel Cuevas Muñoz
  \date 22-04-2018
*/


#include <iostream>

#include <cstdlib>

#include <fstream>

#include <string>

#include "funcionesAuxiliares.hpp"
          
#include "MonticuloMediciones.hpp"

#include "Medicion.hpp"

#include "macros.hpp"

void ed::cargarMonticuloDeFichero(std::string const & nombreFichero, ed::MonticuloMediciones & monticulo) 
{       
       std::ifstream fichero(nombreFichero.c_str());
       if(!fichero.good())
             std::cout<<BIRED<<"No se pudo cargar el fichero de entrada"<<RESET<<std::endl;
       else {
             std::string dia,mes,agno,prec;
             while(std::getline(fichero,dia,'-')){
                   std::getline(fichero,mes,'-');
                   std::getline(fichero,agno,' ');
                   ed::Fecha f(atoi(dia.c_str()),atoi(mes.c_str()),atoi(agno.c_str()));//Leo el fichero hasta obtener los datos de la fecha y los meto en una Fecha auxiliar f
                   std::getline(fichero,prec,'\n');
                   ed::Medicion m(f,atof(prec.c_str()));
                   monticulo.insert(m);

                   }
                   monticulo.print();
                   monticulo.heapsort();
                   std::cout<<"Ahora ordenado"<<std::endl<<std::endl<<std::endl;
                   monticulo.print();
               }
      return;
}


void ed::grabarMonticuloEnFichero(std::string const & nombreFichero, 
							      ed::MonticuloMediciones const & monticulo)
{
std::ofstream fichero(nombreFichero.c_str());
       if(!fichero.good())
             std::cout<<BIRED<<"No se pudo cargar el fichero de salida"<<RESET<<std::endl;
       else {
             ed::MonticuloMediciones m=monticulo;//creo un monticulo igual al que quiero introducir
             while(!m.isEmpty()){
                    fichero<<m.top()<<std::endl;
                    m.remove();
                    }
             }
      return;
}

 


