//HeapMerge.cpp
#include <iostream>
#include "HeapMerge.h"
#include <math.h>
#include <utility> 
using namespace std;

LeftistHeap::LeftistHeap()  
{
    root = NULL;
}

LeftistHeap::LeftistHeap(LeftistHeap &rhs) 
{
    root = NULL;
    *this = rhs;
    cout <<"rhs: "<<endl;
}

LeftistHeap::~LeftistHeap()
{
    makeEmpty( );
   
}

void LeftistHeap::Merge(LeftistHeap &rhs) //merge the right heap into a priority queue
{
    if (this == &rhs)
        return;
    root = Merge(root, rhs.root);
    rhs.root = NULL;
   
}

LeftistNode *LeftistHeap::Merge(LeftistNode * h1, LeftistNode * h2) //merge heap1 with heap2
{
    if (h1 == NULL) //check if h1 is NULL
        return h2;  //return h2
    if (h2 == NULL) //check if h2 is null then return it
        return h1;
    if (h1->element < h2->element) //check if the key at the h1 less than key at h2
        return Merge1(h1, h2); //recursively call the merge function
    else
        return Merge1(h2, h1);
   cout<<"the merged heaps: " <<h1->element << endl;

}

LeftistNode *LeftistHeap::Merge1(LeftistNode * h1, LeftistNode * h2)
{
    if (h1->left == NULL) //check if h1 left node is null
        h1->left = h2;   //assign it to h2
    else
    {
        h1->right = Merge(h1->right, h2);  //otherwise merge from the right child
        if (h1->left->npl < h1->right->npl) //check if there is violation
            swapChildren(h1);  //if it's then swap childeren
        h1->npl = h1->right->npl + 1; //apply the property rule of leftist 
    }
    return h1;
}

void LeftistHeap::swapChildren(LeftistNode * t) //swap function
{
    LeftistNode *tmp = t->left;
    t->left = t->right;
    t->right = tmp;
   // cout<<"temp: " <<*tmp<<endl;
}

void LeftistHeap::Insert(int &x)    //insert
{
    root = Merge(new LeftistNode(x), root);
    cout <<x<<endl;
    
}


bool LeftistHeap::isEmpty() //check if heap is full
{
    return root == NULL;
}

bool LeftistHeap::isFull() //check if heap is full
{
    return false;
}

void LeftistHeap::makeEmpty() //empty the heap
{
    reclaimMemory(root);
    root = NULL;
}

LeftistHeap &LeftistHeap::operator=(LeftistHeap & rhs) //copy
{
    if (this != &rhs)
    {
        makeEmpty();
        root = clone(rhs.root);
    }
    return *this;
}

void LeftistHeap::reclaimMemory(LeftistNode * t) 
{
    if (t != NULL)
    {
        reclaimMemory(t->left);
        reclaimMemory(t->right);
        delete t;
    }
}

LeftistNode *LeftistHeap::clone(LeftistNode * t) //combine the merged heap
{
    if (t == NULL)
        return NULL;
    else
        return new LeftistNode(t->element, clone(t->left), clone(t->right), t->npl);
}


