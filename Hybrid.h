/*
	William Stump && Adam Rucker
	Lab 10/Hybrid ADT
	3/30/17
*/
#if !defined (HYBRID_H)
#define HYBRID_H

#include "QueueLinked.h"
using CSC2110::QueueLinked;
#include "SortedListDoublyLinked.h"

//	These were for testing purposes
/*#include <iostream>
using namespace std;
*/

template < class T >
class Hybrid
{

   private:
	  //QueueLinked<T>* q; //for first implementation
      QueueLinked<DoubleNode <T> >* q;//for second implementation
      SortedListDoublyLinked<T>* sldl;

   public:
      Hybrid(int (*comp_items) (T* item_1, T* item_2), int (*comp_keys) (String* key, T* item));
      ~Hybrid();

      bool isEmpty();//returns boolean from queue isEmpty

      //pre: receives a T* item
      //post: adds reference to T* in the ADT
      void enqueue(T* item);

      //pre: nothing
      //post: removes an item from ADT and returns it
      T* dequeue();
      ListDoublyLinkedIterator<T>* iterator();

};

template < class T >
Hybrid<T>::Hybrid(int (*comp_items) (T* item_1, T* item_2), int (*comp_keys) (String* key, T* item))
{
   q = new QueueLinked<DoubleNode <T> >();
   sldl = new SortedListDoublyLinked<T>(comp_items, comp_keys);
}

template < class T >
Hybrid<T>::~Hybrid()
{
   delete q;
   delete sldl;
}

//DO THIS
//complete the implementation for the Hybrid ADT in two different ways
//as outlined in the Lab 10 description
//simply comment the first implementation out when working on the second implementation
//use the getKey method to dequeue/remove
template < class T >
bool Hybrid<T>::isEmpty()
{
	//this line was for testing to make sure all of the data was deleted.
	//cout<<sldl->size()<<endl;
	return q->isEmpty();
}

/*template < class T >
void Hybrid<T>::enqueue(T* item)
{
	q->enqueue(item);
	sldl->add(item);
}

*/
/*template < class T >
T* Hybrid<T>::dequeue()
{
	T* item = q->dequeue();
	sldl->remove(item->getKey());
}
*/
template <class T>
void Hybrid<T>::enqueue(T* item)
{
	q->enqueue(sldl->addDN(item));
}
template <class T>
T* Hybrid<T>::dequeue()
{
	DoubleNode<T>* item = q->dequeue();
	return sldl->remove(item);
}

template < class T >
ListDoublyLinkedIterator<T>* Hybrid<T>::iterator()
{
	ListDoublyLinkedIterator<T>* iterator =  sldl->iterator();
	return iterator;
}

#endif
