/*#include <stacklst/stacklst.hpp>

StackLst::StackLst() {
	head_ = nullptr;
	size_ = 0;
}

StackLst::~StackLst() {
	delete[] head_;
	head_ = nullptr;
	size_ = 0;
}

bool StackLst::IsEmpty() {
	if (size_ == 0) {
		return true;
	}
	return false;
}

Complex& StackLst::Top() {
	if (head_ != nullptr) {
		return head_->value;
	}
}

void StackLst::Pop() {
	if (size_ > 1) {
		Node* data = head_;
		head_ = head_-> next;
		delete[] data;
		size_ -= 1;

	}
	else if(size_ = 1){
		delete[] head_;
		head_ = nullptr;
		size_ = 0;
	}
}

void StackLst::Push(const Complex& val) {
	StackLst::Node* head = new StackLst::Node[];
	head->value = val;
	if (size_ != 0) {
		head->next = head_;
	}
	head_ = head;
	size_ += 1;
}

StackLst& StackLst::operator=(const StackLst& lst) {
	StackLst time;
	Node* head = lst.head_;
	for (int i = 0; i < lst.size_; i++) {
		time.Push(head->value);
		head = head->next;
	}
	head = time.head_;
	for (int i = 0; i < lst.size_; i++) {
		*this->Push(head->value);
		head = head->next;
	}
	return *this;
}

void StackLst::Clear() {
	if (size > 0) {
		for (i = 0; i < size; i++)
			this->Pop();
	}
}

*/