#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <ostream>
#include <string>
#include <stdexcept>
#include "Dict.h"
#include "TableEntry.h"

#include "../PRA_2324_P1/ListArray.h" // actualizar para cuando acabe el ListLinked
template <typename V>
class HashTable: public Dict<V> {

            private:
                        //Número de elementos almacenados actualmente en la tabla hash.
                        int n;

                        //Tamaño de la tabla hash (número total de cubetas).
                        int max;

                        //Tabla de cubetas, representada por un array de punteros a listas enlazadas (tipo ListLinked<T>) que almacenan pares clave→valor (tipo TableEntry<V>).
                        ListArray<TableEntry<V>>* table; // Actualizar para cuando acabe el ListLinked
                            

            public:
                        //Función hash que devuelve la posición (cubeta) en la tabla hash de key.  Se calculará como el resto de la divisón entre la suma de los valores ASCII numéricos de los caracteres de la clave y el tamaño de la tabla hash (ver nota más abajo).
                        int h(std::string key){
                                int suma = 0;
                                int i = 0;
                                while(key.at(i) != '\0'){
                                        suma += int(key.at(i));
                                        i++;
                                }
                                int pos;
                                return pos = suma % n;
                        }
                        
                        //Método constructor. Reservará memoria dinámica para crear una tabla table de tamaño size, e inicializará los atributos n y max de la clase.
                        HashTable(int size){
                                int n = 0;
                                int max = size -1;
                                table = new V[size];
                        }

                        //Método destructor. Se encargará de liberar la memoria dinámica reservada al crear la tabla table.
                        ~HashTable(){
                                delete [] table;
                        }

                        //Devuelve el número total de cubetas de la tabla.
                        int capacity(){
                                return n;
                        }

                        //Sobrecarga global del operador << para imprimir el contenido de la tabla hash por pantalla. Recuerda incluir la cabecera <ostream> en el .h.
                        friend std::ostream& operator<<(std::ostream &out, const HashTable<V> &th){

                                for(int i = 0)

                        }

                        //Sobrecarga del operador []. Devuelve el valor correspondiente a key. Si no existe, lanza la excepción std::runtime_error.
                        V operator[](std::string key);

};

#endif

