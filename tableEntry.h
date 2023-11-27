#ifndef TABLEENTRY_H
#define TABLEENTRY_H

#include <string>
#include <ostream>

template <typename V> 
class TableEntry {
            public:
                   //Atributos:
                   std::string key;
                   V value;

                   //Método constructor con el par clave->valor.
                   TableEntry(std::string key, V value): key{key}, value{value}{}

                   //Crea una entrada solo con clave (sin valor). 
                   TableEntry(std::string key): key{key}{}

                   //Crea una entrada con la clave "" (cadena vacía) y sin valor.
                   TableEntry(){}

                   //Sobrecarga global del operador == para determinar que dos instancias de TableEntry son iguales solo si comparten la misma clave (con independencia del valor).
                   friend bool operator==(const TableEntry<V> &te1, const TableEntry<V> &te2){
                        return te1.key == te2.key;
                   }

                   //Sobrecarga global del operador != para determinar que dos instancias de TableEntry son diferentes solo si sus claves son distintas (con independencia del valor).
                   friend bool operator!=(const TableEntry<V> &te1, const TableEntry<V> &te2){
                        return te1.key != te2.key;
                   }

                   //Sobrecarga global del operador << para imprimir el contenido de la entrada (par clave->valor) por pantalla. Recuerda incluir la cabecera <ostream> en el .h.
                   friend std::ostream& operator<<(std::ostream &out, const TableEntry<V> &te){
                        
                        out << "( " << te.key << "=>"  << "valor: " << te.value << ") " << std::endl; 
                        return out;
                   }

};

#endif
