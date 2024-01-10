#ifndef BSTREEDICT_H
#define BSTREEDICT_H

#include <ostream>
#include <stdexcept>
#include "Dict.h"
#include "BSTree.h"
#include "TableEntry.h"

template <typename V>
class BSTreeDict: public Dict<V> {

    private:
            BSTree<TableEntry<V>>* tree;

    public:
            //Constructor. Crea un ABB vacío con memoria dinámica.
            BSTreeDict(){
                tree = new BSTree<tableEntry<V>>;
            }

            //Método destructor. Se encargará de liberar la memoria dinámica ocupada por el ABB tree.
            ~BSTreeDict(){
                delete tree;
            }

            //Sobrecarga global del operador << para imprimir el contenido del Diccionario por pantalla. 
            friend std::ostream& operator<<(std::ostream &out, const BSTreeDict<V> &bs){
                tree->print_inorder();   
            }

            //Sobrecarga del operador[]. Actúa como interfaz al método de interfaz heredado search(std::string key).
            V operator[](std::string key){
                return tree->search(key);    
            }
        
};

#endif
