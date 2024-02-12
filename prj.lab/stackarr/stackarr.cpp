#include <stackarr/stackarr.hpp>

StackArr::StackArr() {
	size_ = 0; 
	i_top_ = -1;
	data_ = nullptr;
}

StackArr::StackArr(const StackArr& arr) {
	i_top_ = arr.i_top_;
	size_ = arr.size_;
	if (arr.i_top_ != -1) {
		data_ = new Complex[arr.i_top_] {};
		for (int i = 0; i < size_; i++) {
			data_[i] = arr.data_[i];
		}
	}
	else {
		data_ = nullptr;
	}
}

StackArr& StackArr::operator=(const StackArr& arr) {
	delete[] data_;
	i_top_ = arr.i_top_;
	size_ = arr.i_top_;
	data_ = new Complex[arr.i_top_] {};
	for (int i = 0; i < size_; i++) {
		data_[i] = arr.data_[i];
	}
	return *this;
}

StackArr::~StackArr() {
	if (data_) {
		delete[] data_;
	}
}

bool StackArr::IsEmpty() const noexcept {
	if (i_top_ > -1) {
		return false;
	}
	return true;
}

void StackArr::Pop() noexcept {
	if (i_top_ > 0) {
		
	}
	else if (i_top_ == 0) {
		delete[] data_;
		size_ = 0;
		i_top_ = -1;
		data_ = nullptr;
	}
}

void StackArr::Push(const Complex& val) {
	if(size_ != 0){
		size_ += 1;
		i_top_ += 1;
		Complex* new_data_ = new Complex[size_]{};
		for (int i = 0; i < size_; i++) {
			new_data_[i] = data_[i];
		}
		delete[] data_;
		data_ = new_data_;
		data_[i_top_] = val;
	}
	else {
		size_ += 1;
		i_top_ += 1;
		data_ = new Complex[size_];
		data_[0] = val;
	}
}
Complex& StackArr::Top() {
	if (i_top_ > -1) {
		return data_[i_top_];
	}
	else {
		throw std::out_of_range("Stack is empty");
	}
}

void StackArr::Clear() noexcept {
	delete[] data_;
	data_ = nullptr;
	size_ = 0;
	i_top_ = -1;
}

