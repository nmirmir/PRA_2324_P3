#ifndef BSTREE_H
#define BSTREE_H

#include <ostream>
#include <stdexcept>
#include "BSNode.h"

template <typename T> 
class BSTree {
            private:
                    //Número de elementos almacenados en el ABB.
                    int nelem;

                    //Nodo raíz del ABB
                    BSNode<T> *root;

                    
            public:
                    // Creación y tamaño

                    //Método constructor. Crea un ABB vacío.
                    BSTree(){
                        
                    }

                    //Devuelve el número de elementos nelem del ABB.
                    int size() const;
                    
                    //Búsqueda de elementos

                    //Busca y devuelve el elemento  e de tipo T en el ABB.  
                    //Actúa como método lanzadera del método privado recursivo search(BSNode<T>* n, T e).  
                    //Notar que deberá devolver el elemento contenido por el nodo devuelto por el método privado.
                    T search(T e) const;

                    //Método recursivo para la búsqueda elementos en el ABB. 
                    //Busca y devuelve el elemento e de tipo T si se encuentra en el (sub-)árbol cuya raíz es n, de lo contrario lanza una std::runtime_error. 
                    BSNode<T>* search(BSNode<T>* n, T e) const;

                    //Sobrecarga del operador[]. Actúa como interfaz al método search(T e).
                    T operator[](T e) const;


 };

#endif
