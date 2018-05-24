#include "Vertice.hpp"
#include <iostream>
#include <string>

namespace ed{
 ostream &operator<<(ostream &stream,ed::Vertice const & vertice){
    stream<<vertice.getX();
    stream<<" ";
    stream<<vertice.getY();

    return stream;
    }

 istream &operator>>(istream &stream,ed::Vertice & vertice){
    std::string x,y;
    std::getline(stream,x,' ');
    std::getline(stream,y,'\n');
    vertice.setX(atof(x.c_str()));
    vertice.setY(atof(y.c_str()));

    return stream;
    }
}

