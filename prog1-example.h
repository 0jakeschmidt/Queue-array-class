//
// Created by jake on 9/7/19.
//

#ifndef OSPROGRAM1TEST_QUEUE_ARRAY_H
#define OSPROGRAM1TEST_QUEUE_ARRAY_H

/*
  Here is some example code for Program 1.  You don't have to use any of
  it, but if you are having trouble, it might get you started.
  The etype used through this is the template class your need to create
  in this class, etype means Example TYPE
*/
#include <cstdlib>  //This is for the exit command.
#include <queue>
#include <iostream>

/*
 *  In the class below, it declares a "queue<etype>" array.
 *  you don't need to use the STL queue (but you can), choose a data structure
 * that you think works.   If you choose to write you own queue class, then
 * it has better follow all the requirements to a queue, to include the O time
 * minimum timing requirements of c++
*/


template <class etype>
class QueueArray
{
public:
    QueueArray(int =10 );
    ~QueueArray();
    int Asize();
    etype Dequeue();
    int Enqueue(const etype &item,const int index);
    int QAsize();
    int Qsize(int index) ;
    etype* Qstate(int index);

private:
    int size;      //size of the array
    std::queue <etype>* array;   //the array of queues.  It must be an array (NO not a vector)
    int totalItems; //total number of items stored in the queues

};

//Constructor for the queue array.  It sets the default size
//to 10, initializes the private variables size and totalItems
template <class etype>
QueueArray<etype>::QueueArray(int sz)
{
  this->size = sz;
  this->totalItems=0;
  array = new std::queue<etype>[size];
  if( array == NULL)
  {
    std::cout << "Not enough memory to create the array" << std::endl;
    exit(-1);
  }
}
template <class etype>
int QueueArray<etype>::Asize(){
  int Nsize = this->size;
  return Nsize;
}

template <class etype>
int QueueArray<etype>::Enqueue(const etype &item ,const int index){

  if(index > this->size){
    return -1;
  }else if(index<size && index >=0) {
    array[index].push(item);
    return 1;
  }

  return 0;
}

template <class etype>
etype QueueArray<etype>::Dequeue(){

  for (int i=0; i< size; i++){
    if(!array[i].empty()){
      etype temp = array[i].front();
      array[i].pop();
      return temp;
    }
  }
  return 0;
}

template <class etype>
int QueueArray<etype>::Qsize(int index){

  if(index> size || index < 0){
    return -1;
  }
  return array[index].size();
}

template <class etype>
int QueueArray<etype>::QAsize(){

  int total=0;
  for(int i=0; i< size; i++){
    total = total + array[i].size();
  }
  return total;
}

template <class etype>
etype* QueueArray<etype>::Qstate(int index){

  int qSize = Qsize(index);

  int space = sizeof(etype)*qSize;

  etype* arrayNew = NULL;

  arrayNew = new etype[space];

  for(int i=0; i< qSize; i++){

    arrayNew[i] = array[index].front();
    array[index].push(arrayNew[i]);
    array[index].pop();
  }
  return arrayNew;

}

template <class etype>
QueueArray<etype>::~QueueArray(){

}

#endif //OSPROGRAM1TEST_QUEUE_ARRAY_H

