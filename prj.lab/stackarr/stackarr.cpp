#include <stackarr/stackarr.hpp>

StackArr::StackArr() {
	size_ = 0; 
	i_top_ = -1;
	data_ = nullptr;
}

StackArr::StackArr(const StackArr& arr) {
	size_ = arr.size_;
	i_top_ = arr.i_top_;
	if (arr.data_) {
		data_ = new Complex[size_];
		for (int i = 0; i < i_top_; i++) {
			data_[i] = arr.data_[i];
		}
	}
	else {
		data_ = 0;
	}
}

StackArr& StackArr::operator=(const StackArr& arr) {
	delete[] data_;
	Complex* data_ = new Complex[size_];
	size_ = arr.size_;
	i_top_ = arr.i_top_;
	for (int i = 0; i < i_top_; i++) {
		data_[i] = arr.data_[i];
	}
	return *this;
}

StackArr::~StackArr() {
	if (data_) {
		delete []data_;
	}
}

