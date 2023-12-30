bin/testTableEntry: tableEntry.h testTableEntry.cpp
	mkdir -p bin
	g++ -o bin/testTableEntry testTableEntry.cpp tableEntry.h
bin/testHashTable: HashTable.h testHashTable.cpp
	mkdir -p bin
	g++ -o bin/testHashTable testHashTable.cpp tableEntry.h HashTable.h Dict.h
clean:
	rm -r *.gch bin *.o
