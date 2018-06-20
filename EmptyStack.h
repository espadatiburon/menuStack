#ifndef EMPTYSTACK_H
#define EMPTYSTACK_H
#include <iostream>
#include <string>

namespace cs20 {

class EmptyStack : public std::logic_error {
public:
	EmptyStack( const std::string& msg = "" );
};

}

#endif