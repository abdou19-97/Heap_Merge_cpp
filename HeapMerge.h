//HeapMerge.h
#include <iostream>
#include <math.h>
#include <utility> 
#ifndef  HEAPMERGE_HEAP_EXISTS
using namespace std;

class LeftistNode   //Heap node class
{
    public:
        int element; //array of the element
        LeftistNode *left; //left node
        LeftistNode *right; //right node
        int npl; //the number of edges on thr shortest path from node to leaf

        LeftistNode(int & element, LeftistNode *lt = NULL, //leftist node constructor 
                    LeftistNode *rt = NULL, int np = 0)
        {
            this->element = element;
            right = rt;
            left = lt,
            npl =  np;
        }
};

class LeftistHeap   //CLASS DECLARATION
{
    public:
        LeftistHeap();//constructor
        LeftistHeap(LeftistHeap &rhs); 
        ~LeftistHeap();//destructor
        bool isEmpty();//cehck if the heap is empty
        bool isFull(); //check if it's full
        void Insert(int &x);//insertion
        void makeEmpty();//clear the heap 
        void Merge(LeftistHeap &rhs); //merge
        LeftistHeap & operator=(LeftistHeap &rhs);//copy
        LeftistNode *root; 
        LeftistNode *Merge(LeftistNode *h1, LeftistNode *h2);
        LeftistNode *Merge1(LeftistNode *h1, LeftistNode *h2);
        void swapChildren(LeftistNode * t);
        void reclaimMemory(LeftistNode * t);
        LeftistNode *clone(LeftistNode *t);
};

#endif
