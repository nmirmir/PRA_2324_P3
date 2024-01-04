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
                            nodo_aux = search(root,e); // r -> nodo raíz
                            return nodo_aux->elem;
                    }

            private:

                    //Método recursivo para la búsqueda de elementos en el ABB. 
                    //Busca y devuelve el elemento e de tipo T si se encuentra en el (sub-)árbol cuya raíz es n, de lo contrario lanza una std::runtime_error.
                    BSNode<T>* search(BSNode<T>* n, T e) const{
                        if(n == nullptr){
                                throw std::runtime_error("árbol vacío");        
                        }else if(n->elem > e){
                                return search(n->left,e);
                        }else if(n->elem < e){
                                return search(n->right,e);
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
                        }else if(n->elem == e){
                                throw std::runtime_error("el elemento ya existe");
                        }else if(n->elem > e){
                                return n->left = insert(n->left,e);               
                        }else{
                                return n->right = insert(n->right,e);
                        }
                        return n;
                    }

           public:
                    //Sobrecarga del operador << para mostrar a través de out los contenidos del ABB bst, realizando un recorrido inorden o simétrico del árbol para mostrar los elementos ordenados de menor a mayor. Delega en el método privado recursivo print_inorder(). 
                   friend std::ostream& operator<<(std::ostream &out, const BSTree<T> &bst){
                        out << print_inorder(&out, &bst) << std::endl;
                        return out;
                   }

           private:
                   //Recorrido inorden o simétrico del (sub-)árbol cuya raíz es n para mostrar a través de out los elementos ordenados de menor a mayor. Ver pseudocódigo abajo. 
                   void print_inorder(std::ostream &out, BSNode<T>* n) const{
                        if(n != nullptr){
                                if(n->left != nullptr ){
                                        n->left = print_inorder(&out, n->left);
                                        out << "nodo" << n->left << std::endl;
                                }else if(n->right != nullptr ){
                                        n->right = print_inorder(&out, n->right)
                                        out << "nodo" << n->right; 
                                }
                                out << n << std::endl;

                                for(int i = 0; i < n->size(); i++){
                                        print_inorder(&out, n);
                                }
                        }
                   }
           public:
                   //Elimina el elemento e de tipo T del ABB. Actúa como método lanzadera del método privado recursivo remove(BSNode<T>* n, T e).
                   void remove(T e){
                        BSNode<T> nodo;
                        nodo.elem = remove(nodo, e);
                   }
           private:
                   //Método recursivo para la eliminación de elementos. 
                   //Elimina el elemento e del (sub-)árbol cuya raíz es n. 
                   //Devuelve el nodo que encabeza dicho (sub-)árbol modificado. 
                   //En caso de eliminar un nodo con dos sucesores (izquierdo y derecho), 
                   //aplicará la politica de reemplazo por el elemento máximo del subárbol izquierdo.
                   //Para ello, se apoyará en los métodos privados auxiliares max() y remove_max(). 
                   //Si el elemento e no existe, lanza un std::runtime_error. Ver pseudocódigo abajo. 
                   BSNode<T>* remove(BSNode<T>* n, T e){
                        if(n == nullptr){
                                throw std::runtime_error("no hay elementos en el ABB");
                        // Ahora vamos a mirar hacia qué rama vamos a ir, si a la derecha o a la izquierda        
                        }else if(n->elem < e){
                                n->right = remove(n->right, e); // rama derecha
                        }else if(n->elem > e){
                                n->left = remove(n->left, e); // rama izquierda
                        }else{
                                //Una vez sabemos a qué rama nos dirigimos, valoramos el nº de descendientes
                                if(n->left != nullptr && n->right != nullptr){
                                        n->elem = max(n->left);
                                        n->left = remove_max(n->left);
                                }else{
                                // Este caso es para ver si tiene 1 o 0 descendientes
                                        if(n->left == nullptr){
                                                n = (n->left,e);
                                        }else if(n->left == nullptr){
                                                n = (n->right,e);
                                        }
                                }

                        }
                        return n;
                   }

                   //Método recursivo que devuelve el elemento de máximo valor contenido en el (sub-)árbol cuya raíz es n. 
                   T max(BSNode<T>* n) const{
                        if(n == nullptr){
                                throw std::runtime_error("no hay elementos en el ABB");
                        }else if(n->right != nullptr){
                                return max(n->right);
                        }else{
                                return n->elem;
                        }
                   }

                   //Método recursivo que elimina el elemento de máximo valor contenido en el (sub-)árbol cuya raíz es n. 
                   BSNode<T>* remove_max(BSNode<T>* n){
                        // Primero comprobamos si el nodo tiene descendientes a la derecha, para ver si él es el máximo o no, en caso de que no haber, se devuelve el hijo izquierdo para eliminar el máximo.  
                        if(n->right == nullptr){
                                return n->left;
                        }else{
                        // Todavía hay nodos mayores, así que se llamará de forma recursiva hasta llegar al caso base, en el que se encuentra el máximo.
                                n->right = remove_max(n->right);
                                return n;
                        }
                   }
           public:
                   //Método destructor. Delega en el método privado recursivo delete_cascade().
                   ~BSTree(){
                        BSNode<T> nodo;   
                        delete_cascade(nodo);
                   }

           private:
                   //Método recursivo para la liberación de la memoria dinámica ocupada por los objetos de tipo BSNode<T> que conforman el (sub)-árbol cuya raíz es n.
                   void delete_cascade(BSNode<T>* n){
                        if(n != nullptr){
                                remove(n,e);
                        }
                   }







 };

#endif
