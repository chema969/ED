/*! 
   \file Vertice.hpp
   \brief Fichero de la clase Vertice
*/

#ifndef VERTICE_HPP
#define VERTICE_HPP

using std::istream;
using std::ostream;

namespace ed {
//!  Definición de la clase Vertice
class Vertice{
    //! \name Atributos privados de la clase Vertice
    private:
       double x_;//!<Cordenada x de la clase  
       double y_;//!<Cordenada y de la clase  
       int label_;//!<Etiqueta de la clase

    public:

//! \name Observadores: funciones de consulta de la clase Vertice
       double getX()const{return x_;}
       double getY()const{return y_;}
       double getLabel()const{return label_;}


//! \name Modificadores: funciones de modificación de la clase Vertice
       void setX(double x){x_=x;}
       void setY(double y){y_=y;}
       void setLabel(int label){label_=label;}



};
    ostream &operator<<(ostream &stream, Vertice const &fecha);
    istream &operator>>(istream &stream, Vertice &fecha);
}

// \brief Fin de namespace ed.







#endif
