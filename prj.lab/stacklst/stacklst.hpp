#include <cstddef>
#include <complex/complex.hpp>
#include <cstddef> 

class StackLst {
public:
	StackLst();

	StackLst(const StackLst& lst) = default;

	~StackLst()

	void Pop();
	 
	void Push(const Complex& val);

	Complex& Top();

	StackLst& operator=(const StackLst& lst);

	bool IsEmpty();

	void Clear();

private:
	struct Node {
		Node() {
			next = nullptr;
		};
		Complex value;
		Node* next = nullptr;
		
	};

	Node* head_ = nullptr;
	std::ptrdiff_t size_ = 0;
};