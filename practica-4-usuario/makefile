NAME=PrincipalArbolAbarcador

#
OBJECTS = $(NAME).o funcionesAuxiliares.o Grafo.o Vertice.o Lado.o

#
CPPFLAGS = -c -g -Wall -ansi -O2

INCLUDES = funcionesAuxiliares.hpp Grafo.hpp Vertice.hpp Lado.hpp macros.hpp

# Macros predefinidas
#
# $@: nombre del objetivo
# $^: todas las dependencias
# $<: primera dependencia
#

objetivo: $(NAME).exe

#Opciones para NO depurar los asertos
ndebug: CPPFLAGS += -DNDEBUG 
ndebug: objetivo

# Primer objetivo 
$(NAME).exe: $(OBJECTS)
			@echo "Generando " $@
			@g++-4.9 $^ -o $@
#
$(NAME).o: $(NAME).cpp $(INCLUDES)
			@echo "Compilando " $<
			@g++-4.9 $(CPPFLAGS) $<

#
funcionesAuxiliares.o: funcionesAuxiliares.cpp $(INCLUDES)
			@echo "Compilando " $<
			@g++-4.9 $(CPPFLAGS) $<

#
Grafo.o: Grafo.cpp Grafo.hpp 
			@echo "Compilando " $<
			@g++-4.9 $(CPPFLAGS) $<

#
Vertice.o: Vertice.cpp Vertice.hpp  
			@echo "Compilando " $<
			@g++-4.9 $(CPPFLAGS) $<


#
Lado.o: Lado.cpp Lado.hpp 
			@echo "Compilando " $<
			@g++-4.9 $(CPPFLAGS) $<





# Generación de la documentación
doc: Doxyfile 
	@echo "Generando la documentación con doxygen"
	@doxygen
  
# Borrado
.PHONY: clean  
clean:
	@echo "Borrando los ficheros superfluos"
	@rm -f $(OBJECTS) *~ 

