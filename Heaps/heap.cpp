//Intro to heaps

#include<bits/stdc++.h>
using namespace std;

class BinaryHeap{
    public:

    int capacity; //the max no of elements that can be stored in a heap

    int size; //the current no of elements in the heap

    int* arr; //array for the storing the keys

    //BinaryHeap is a class you can use in C++
    BinaryHeap(int cap){

        capacity=cap; //assigning the capacity

        size=0; //initially size of heap is zero

        arr=new int[capacity]; //Creating an array

    }

    //To find the parent of the ith node
    int parent(int i){
        return (i-1)/2;
    }

    //To find the left child of the ith node
    int left(int i){
        return 2*i+1;
    }

    //To return the right child of the ith node
    int right(int i){
        return 2*i+2;
    }
    
    //Inserting a new key
    void Insert(int x){
        //when size==capacity, there is an overflow

        if(size==capacity){
            cout<<"Binary Heap Overflow" <<endl;
            return;
        }
        
        //Insert new element at the end
        arr[size]=x;

        //Store the index to check for heap's property
        int k=size;

        //Increase the size
        size++;

        //Fixing the min heap property
        while(k!=0 && arr[parent(k)]>arr[k]){
            swap(arr[parent(k)],arr[k]);
            k=parent(k);
        }
    }

    //This is for minheap
    void Heapify(int ind){

        //Right child
        int ri=right(ind);

        //Left child
        int li=left(ind);

        //Initially assume the minheap property is violated
        int smallest=ind;

        if(li<size && arr[li]<arr[smallest])
            smallest=li;

        if(ri<size && arr[ri]<arr[smallest])
            smallest=ri;

        //If the minimum among three nodes is not the parents itself, then swap and call heapify recursively
        if(smallest!=ind){
            swap(arr[ind],arr[smallest]);
            Heapify(smallest);
        }



    }

    //To return the minimum value in a minheap, the root node is the minimum value
    int getMin(){
        return arr[0];
    }

    //To remove the minimum element from the heap
    int ExtractMin(){
        if(size<=0)
            return INT_MAX;
        if(size==1){
            size--;
            return arr[0];
        }

        int mini=arr[0];

        //Copy the last Node value to the root node
        arr[0]=arr[size-1];
        size--;

        //Call heapify on root node
        Heapify(0);

        return mini;
        
    }

    //Decreasekey-Used to update the value at an index with a given value
    void DecreaseKey(int i,int val){

        //Updating the new val;
        arr[i]=val;

        //Fixing the min heap
        while(i!=0 && arr[parent(i)]>arr[i]){
            swap(arr[parent(i)],arr[i]);
            i=parent(i);
        }

    }

    void Delete(int i){
        DecreaseKey(i,INT_MIN);
        ExtractMin();
    }

    void print(){
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
    }




};