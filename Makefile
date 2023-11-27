bin/testTableEntry: tableEntry.h testTableEntry.cpp
	mkdir -p bin
	g++ -o bin/testTableEntry testTableEntry.cpp tableEntry.h
clean:
	rm -r *gch bin *o
