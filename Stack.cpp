#ifndef STACK_CPP
#define STACK_CPP

#include "Stack.h"

namespace cs20 {

template <class Object>
Stack<Object>::Stack() {
	topNode = nullptr;
}

template <class Object>
Stack<Object>::Stack( const Stack<Object>& rhs ) {
	topNode = nullptr;
	*this = rhs;
}

template <class Object>
Stack<Object>::~Stack() {
	makeEmpty();
    delete topNode;
}

template <class Object>
bool Stack<Object>::isEmpty() const {
	return( (topNode == nullptr) );
}

template <class Object>
void Stack<Object>::makeEmpty() {
	while (!isEmpty()) {
		pop();
	}
}

template <class Object>
void Stack<Object>::push( const Object& data ) {
	StackNode<Object>* newNode = new StackNode<Object>( data, topNode );
	topNode = newNode;
}

template <class Object>
void Stack<Object>::pop() {
	if (isEmpty()) {
		throw EmptyStack();
	}
	StackNode<Object> *oldTop = topNode;
	topNode = topNode->getNext();
	delete oldTop;
}

template <class Object>
const Object& Stack<Object>::top( ) const {
	if (isEmpty()) {
		throw EmptyStack();
	}
	StackNode<Object> node = *topNode;
	return( node.getElement() );
}

template <class Object>
Object Stack<Object>::topAndPop( ) {
	Object o = top();
	pop();
	return( o );
}

// Deep copy of linked Stack
template <class Object>
const Stack<Object>& Stack<Object>::operator =( const Stack<Object>& rhs ) {
	if (this != &rhs) {
		makeEmpty();
		if (!(rhs.isEmpty())) {
			StackNode<Object> * rhsTopNode = rhs.topNode;
			StackNode<Object> * myTopNode = new StackNode<Object>( rhsTopNode->getElement() );
			topNode = myTopNode;

			rhsTopNode = rhsTopNode->getNext();
			while (rhsTopNode != nullptr) {
				myTopNode->setNext( new StackNode<Object>( rhsTopNode->getElement() ) );
				myTopNode = myTopNode->getNext();
				rhsTopNode = rhsTopNode->getNext();
			}
		}
	}
	return( *this );
}

template <class Object>	
std::ostream& Stack<Object>::printStack( std::ostream& outs ) const {
	if (isEmpty()) {
		outs << "Empty Stack";
	}
	else {
		outs << "TOP: ";
		StackNode<Object> * node = topNode;
		while (node != nullptr) {
			outs << node->getElement();
			outs << "\n     ";           /// for visual alignment
			node = node->getNext();
		}
	}
	return( outs );
}

template <class Object>
bool Stack<Object>::allSmaller( const Object & data ) const
{
	bool answer = true;
	StackNode<Object> * node = topNode;
	while (node != nullptr)
	{
		if(data <= node->getElement())
		{
			return false;
		}
		else
		{
			node = node->getNext();
		}
	}

	return answer;
}

template <class Object>
int Stack<Object>::count( const Object & data ) const
{
	int occurrences = 0;
	StackNode<Object> * node = topNode;
	while(node != nullptr)
	{
		if(data == node->getElement())
		{
			occurrences++;
			node = node->getNext();
		}
		else 
		{
			node = node->getNext();
		}
	}
	return occurrences;
}

}

#endif