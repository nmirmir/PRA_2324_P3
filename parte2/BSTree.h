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
                            int nelem = 0;
                            root = nullptr;
                    }


                    //Devuelve el número de elementos nelem del ABB.
                    int size() const{
                        return nelem;
                    }
                    
                    //Búsqueda de elementos

                    //Busca y devuelve el elemento  e de tipo T en el ABB.  
                    //Actúa como método lanzadera del método privado recursivo search(BSNode<T>* n, T e).  
                    //Notar que deberá devolver el elemento contenido por el nodo devuelto por el método privado.
                    T search(T e) const{
                            BSNode<T> nodo_aux; 
                            nodo_aux = search(root,e) const; // r -> nodo raíz
                            return nodo_aux.elem;
                    }

            private:

                    //Método recursivo para la búsqueda de elementos en el ABB. 
                    //Busca y devuelve el elemento e de tipo T si se encuentra en el (sub-)árbol cuya raíz es n, de lo contrario lanza una std::runtime_error.
                    BSNode<T>* search(BSNode<T>* n, T e) const{
                        if(n == nullptr){
                                throw runtime_error("árbol vacío");        
                        }else if(n.elem > e){
                                return search(n.left,e);
                        }else if(n.elem < e){
                                return search(n.right,e);
                        }else{
                                return n; // se hace porque ya se ha encontrado el elemento
                        }
                    }

            public:
                    //Sobrecarga del operador[]. Actúa como interfaz al método search(T e).
                    T operator[](T e) const{
                        return search(e);                            
                    }

                    //Inserta el elemento e de tipo T de manera ordenada en el  ABB. Actúa como método lanzadera del método privado recursivo insert(BSNode<T>* n, T e).
                    void insert(T e){
                        BSNode<T> root;
                        root = insert(root,e); // r-> nodo raíz
                    }

           private:
                    //Método recursivo para la inserción ordenada de elementos. Inserta el elemento e de tipo T de manera ordenada en el (sub-)árbol cuya raíz es n. Devuelve el nodo que encabeza dicho (sub-)árbol modificado. Si el elemento e ya existe, lanza un std::runtime_error. Ver pseudocódigo abajo. 
                    BSNode<T>* insert(BSNode<T>* n, T e){
                        if(n == nullptr){
                                return BSNode<T> nodo;
                        }else if(n.elem == e){
                                throw runtime_error("el elemento ya existe");
                        }else if(n.elem > e){
                                n.left = return insert(n.left,e);               
                        }else(n.elem < e){
                                n.right = return insert(n.right,e);
                        }
                        return n;
                    }

           public:
                    //Sobrecarga del operador << para mostrar a través de out los contenidos del ABB bst, realizando un recorrido inorden o simétrico del árbol para mostrar los elementos ordenados de menor a mayor. Delega en el método privado recursivo print_inorder(). 
                   friend std::ostream& operator<<(std::ostream &out, const BSTree<T> &bst){
                        out << print_inorder(&out, &bst) << std::endl;
                        return out;
                   }             
                   //Recorrido inorden o simétrico del (sub-)árbol cuya raíz es n para mostrar a través de out los elementos ordenados de menor a mayor. Ver pseudocódigo abajo. 
                   void print_inorder(std::ostream &out, BSNode<T>* n) const{
                        if(n != nullptr){
                                if(n.left != nullptr && (n.right != nullptr || n.right == nullptr)){
                                        n.left = print_inorden(&out, n.left);
                                        out << "nodo" << n.left << std::endl;
                                }else if(n.right != nullptr && (n.left != nullptr || n.left == nullptr)){
                                        out << "nodo" << print_inorden(&out, n.right); 
                                }
                                for(int i = 0; i < n.size(); i++){
                                        if(n.left != nullptr && (n.right != nullptr || n.right == nullptr)){
                                                out << print_inorden(&out, n.left); 
                                        }else if(n.right != nullptr && (n.left != nullptr || n.left == nullptr)){
                                                out << print_inorden(&out, n.right); 
                                        }
                                }

                        }
                   }







 };

#endif
