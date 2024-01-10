bin/testBSTree: BSTree.h BSNode.h 
	mkdir -p bin
	g++ -o bin/testBSTree testBSTree.cpp BSTree.h BSNode.h
bin/testBSTreeDict: ../dict.h BSTree.h BSNode.h ../TableEntry.h 
	mkdir -p bin
	g++ -o bin/testBSTreeDict testBSTreeDict.cpp BSTree.h BSNode.h ../dict.h ../TableEntry.h
clean:
	rm -r *.gch bin *.o
