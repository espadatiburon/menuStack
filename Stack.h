#ifndef STACK_H
#define STACK_H
#include <iostream>
#include "StackNode.h"
#include "EmptyStack.h"

namespace cs20 {

template <class Object>
class Stack {
public:
	Stack();
	Stack( const Stack& rhs );
	~Stack();

	bool isEmpty() const;
	void makeEmpty();
	void push( const Object& data );
	void pop();
	const Object& top() const;
	Object topAndPop();
	std::ostream& printStack( std::ostream& outs ) const;
	bool allSmaller( const Object & data ) const;
	int count( const Object & data ) const;
	
	const Stack& operator =( const Stack& rhs );

private:
	StackNode<Object> * topNode;
};

}

#endif