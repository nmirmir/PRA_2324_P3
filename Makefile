bin/testTableEntry: tableEntry.h testTableEntry.cpp
	mkdir -p bin
	g++ -o bin/testTableEntry testTableEntry.cpp tableEntry.h
bin/testHashTable: HashTable.h testHashTable.cpp
	mkdir -p bin
	g++ -o bin/testHashTable testHashTable.cpp tableEntry.h HashTable.h Dict.h
bin/testBSTree: BSTree.h BSNode.h 
	mkdir -p bin
	g++ -o bin/testBSTree testBSTree.cpp BSTree.h BSNode.h
bin/testBSTreeDict: ../dict.h BSTree.h BSNode.h ../TableEntry.h 
	mkdir -p bin
	g++ -o bin/testBSTreeDict testBSTreeDict.cpp BSTree.h BSNode.h ../dict.h ../TableEntry.h
clean:
	rm -rf *.gch bin *.o
