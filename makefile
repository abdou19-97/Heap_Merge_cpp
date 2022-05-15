HeapMerge: HeapMerge.o main.o
	g++ -std=c++11 HeapMerge.o main.o -o Run

HeapMerge.o: HeapMerge.cpp HeapMerge.o
	g++ -std=c++11 -c HeapMerge.cpp

main.o: main.cpp HeapMerge.h
	g++ -c main.cpp

clean:
	rm -f*.o
	rm Run

run: buildHeap
	/Run
