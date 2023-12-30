#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <ostream>
#include <string>
#include <stdexcept>
#include "Dict.h"
#include "TableEntry.h"

#include "../PRA_2324_P1/ListLinked.h" 
template <typename V>
class HashTable: public Dict<V> {

            private:
                        //Número de elementos almacenados actualmente en la tabla hash.
                        int n;

                        //Tamaño de la tabla hash (número total de cubetas).
                        int max;

                        //Tabla de cubetas, representada por un array de punteros a listas enlazadas (tipo ListLinked<T>) que almacenan pares clave→valor (tipo TableEntry<V>).
                        ListLinked<TableEntry<V>>* table; 
                            

            public:
                        //Inserta el par key->value en el diccionario. Lanza una excepción std::runtime_error si key ya existe en el diccionario.
                        void insert(std::string key, V value){
                                int pos = h(key);
                                if((table[pos].search(key) == -1) && pos >= 0 && pos < max){
                                        TableEntry<V> nodo(key, value);
                                        table[pos].prepend(nodo);
                                        n++;
                                }else{
                                        throw ("error de insercción");
                                }
                        }

                        //Busca el valor correspondiente a key. Devuelve el valor value asociado si key está en el diccionario. Si no se encuentra, lanza una excepción std::runtime_error.
                        V search(std::string key){
                                int pos = h(key);
                                int p = table[pos].search(key);
                                if(p == -1){
                                        throw std::runtime_error("la clave no se encuentra");
                                }
                                TableEntry<V> nodo = table[pos].get(p);// Esto se hace porque como estás sacando un dato que está dentro d eun tipo TableEntry,, necesito guardalo en una variable de ese mismo tipo, para luego poder extraer sus atributos, y en este caso queremos el valor.
                                return nodo.value;
                        }

                        //Elimina el par key->value si se encuentra en el diccionario. Si no se encuentra, lanza una excepción std::runtime_error.
                        V remove(std::string key){
                                int pos = h(key);
                                int p = table[pos].search(key);
                                if(p == -1){
                                        throw std::runtime_error("la clave no se encuentra");
                                }
                                n--;
                                TableEntry<V> nodo = table[pos].remove(p);
                                return nodo.value;
                        }

                        //Devuelve el número de elementos que tiene el Diccionario.
                        int entries(){
                                return n;
                        }



                        //Función hash que devuelve la posición (cubeta) en la tabla hash de key.  Se calculará como el resto de la divisón entre la suma de los valores ASCII numéricos de los caracteres de la clave y el tamaño de la tabla hash (ver nota más abajo).
                        int h(std::string key){
                                int suma = 0;
                                int i = 0;
                                while(key.at(i)){
                                        suma += int(key.at(i));
                                        i++;
                                }
                                return suma % max;
                        }
                        
                        //Método constructor. Reservará memoria dinámica para crear una tabla table de tamaño size, e inicializará los atributos n y max de la clase.
                        
                        HashTable(int size){
                                int n = 0;
                                max = size;
                                table = new ListLinked<TableEntry<V>>[max];
                        }

                        //Método destructor. Se encargará de liberar la memoria dinámica reservada al crear la tabla table.
                        ~HashTable(){
                                delete [] table;
                        }

                        //Devuelve el número total de cubetas de la tabla.
                        int capacity(){
                                return max;
                        }

                        //Sobrecarga global del operador << para imprimir el contenido de la tabla hash por pantalla. Recuerda incluir la cabecera <ostream> en el .h.
                        friend std::ostream& operator<<(std::ostream &out, const HashTable<V> &th){

                                out << "HashTable [ entries: "<< th.n << ", capacity: "<< th.max << "]"<< '\n' <<"======="<< std::endl;

                                for(int i = 0; i < th.max ; i++){
                                        out << "== Cubeta " << i << " =="<< '\n'<< '\n' << "List => [" <<std::endl;
                                        for(int j = 0; j < th.table[i].size(); j++){

                                                out << th.table[i].get(j) <<std::endl; 

                                        }

                                        out << "]"<< '\n' <<std::endl;
                                }

                                out << "=========="<<std::endl;

                                return out;

                        }

                        //Sobrecarga del operador []. Devuelve el valor correspondiente a key. Si no existe, lanza la excepción std::runtime_error.
                        V operator[](std::string key){
                                return search(key);
                        }

};

#endif

