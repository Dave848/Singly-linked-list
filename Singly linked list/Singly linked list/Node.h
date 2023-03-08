#ifndef _NODE
#define _NODE

#include <memory>
#include <iostream>

template<typename T>
class Node
{
public: 
	T data;
	std::shared_ptr<Node> next;

	Node(T dat) : data(dat), next(nullptr) {}
};

#endif
