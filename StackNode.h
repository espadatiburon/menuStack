#ifndef STACKNODE_H
#define STACKNODE_H
#include <iostream>

namespace cs20 {

template <class Object>
class StackNode {
public:
	StackNode( const Object& theElement = Object(), StackNode * node = nullptr );

	const Object& getElement() const;
	StackNode* getNext() const;
	void setNext( StackNode* node );
private:
	Object element;
	StackNode* next;

};

}
#endif