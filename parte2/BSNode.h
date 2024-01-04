#ifndef BSNODE_H
#define BSNODE_H

#include <ostream>

template <typename T> 
class BSNode {
            public:
                   // Atributos

                   //El elemento de tipo T almacenado en el nodo.
                   T elem;

                   //Puntero al nodo sucesor izquierdo.
                   BSNode<T>* left;

                   //Puntero al nodo sucesor derecho.
                   BSNode<T>* right;
                   
                   //Métodos

                   //Método constructor que crea un BSNode con el elemento elem y 
                   //los punteros a los nodos sucesores left y  right proporcionados (nulos por defecto). 
                   BSNode(T elem, BSNode<T>* left=nullptr, BSNode<T>* right=nullptr){
                        this->elem = elem;
                        this->right = right;
                        this->left = left;
                   }

                   //Sobrecarga global del operador << para imprimir el nodo por pantalla. 
                   //Por simplicidad, puedes limitarte a imprimir el atributo elem. Recuerda incluir la cabecera <ostream> en el .h.
                   friend std::ostream& operator<<(std::ostream &out, const BSNode<T> &bsn){
                        out << bsn.elem << std::endl;
                        return out;
                   }
};

#endif
