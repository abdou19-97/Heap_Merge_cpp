//main.cpp
#include <iostream>
#include "HeapMerge.h"

int main()
{
   // HeapMerge hm; 
    int a[] = {4, 19, 8, 27, 20, 12, 43, 15, 25};
    int b[] = {6, 8, 7, 14};
    LeftistHeap h;
    cout <<"merged heap: " <<endl;

    h.Insert(a[0]);
    h.Insert(a[1]);
    h.Insert(a[2]);
    h.Insert(a[3]);
    h.Insert(a[4]);
    h.Insert(a[5]);
    h.Insert(a[6]);
    h.Insert(a[7]);
    h.Insert(a[8]);

    h.Insert(b[0]);
    h.Insert(b[1]);
    h.Insert(b[2]);
    h.Insert(b[3]);
  
 
    return 0;
}
