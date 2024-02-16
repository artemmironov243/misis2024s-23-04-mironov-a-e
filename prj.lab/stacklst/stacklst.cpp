#include <stacklst/stacklst.hpp>
#include <vector>
#include <iostream>

StackLst::StackLst() {
	head_ = nullptr;
	size_ = 0;
}

StackLst::StackLst(const StackLst& lst) {
	size_ = lst.size_;
	Node* head = lst.head_;
	std::vector<Complex> vec;
	for (int i = 0; i < size_; i++) {
		vec.push_back(head->value);
		head = head->next;
	}
	for (int i = size_ - 1; i >= 0; i--) {
		Push(vec[i]);
	}
}

StackLst::~StackLst() {
	delete head_;
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
		delete data;
		size_ -= 1;

	}
	else if (size_ == 1) {
		delete head_;
		head_ = nullptr;
		size_ = 0;
	}
}

void StackLst::Push(const Complex& val) {
	Node* head = new Node;
	head->value = val;
	if (size_ != 0) {
		head->next = head_;
	}
	else {
		head->next = nullptr;
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
		Push(head->value);
		head = head->next;
	}
	return *this;
}

void StackLst::Clear() {
	std::ptrdiff_t size = size_;
	for (int i = 0; i < size; i++) {
		Pop();
	}
}
