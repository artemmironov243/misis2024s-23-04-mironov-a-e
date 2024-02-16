#pragma once
#ifndef STACKLST_STACKLST_HPP_20240203
#define STACKLST_STACKLST_HPP_20240203

#include <cstddef>
#include <complex/complex.hpp>

class StackLst {
public:
	StackLst();

	StackLst(const StackLst& lst);

	~StackLst();

	void Pop();
	 
	void Push(const Complex& val);

	Complex& Top();

	StackLst& operator=(const StackLst& lst);

	bool IsEmpty();

	void Clear();
	

private:
	struct Node {
		Complex value;
		Node* next = nullptr;	
	};


	Node* head_ = nullptr;
	std::ptrdiff_t size_ = 0;
};

#endif