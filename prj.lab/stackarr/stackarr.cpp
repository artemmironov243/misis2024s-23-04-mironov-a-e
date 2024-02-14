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
		data_ = new Complex[arr.i_top_]{};
		for (int i = 0; i < arr.i_top_; i++) {
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
	size_ = arr.size_ * 2;
	if (size_ > 0) {
		data_ = new Complex[size_]{};
		for (int i = 0; i < size_; i++) {
			data_[i] = arr.data_[i];
		}
	}
	else {
		data_ = nullptr;
	}
	return *this;
}

StackArr::~StackArr() {
	if (data_) {
		delete[]data_;
	}
}

bool StackArr::IsEmpty() const noexcept {
	if (i_top_ > -1) {
		return false;
	}
	return true;
}

void StackArr::Pop() noexcept {
	i_top_ -= 1;
}

void StackArr::Push(const Complex& val) {
	if (i_top_ + 1 < size_ && size_ != 0) {
		data_[i_top_ + 1] = val;
		i_top_ += 1;
	}
	else if (size_ > 0 ) {
		std::ptrdiff_t new_size = size_ * 2;
		std::ptrdiff_t new_i_top = i_top_ + 1;
		Complex* new_data = new Complex[new_size]{};
		for (int i = 0; i < i_top_; i++) {
			new_data[i] = data_[i];
		}
		new_data[new_i_top] = val;
		i_top_ = new_i_top;
		size_ = new_size;
		delete[] data_;
		data_ = new_data;
	}
	else {
		size_ += 1;
		i_top_ += 1;
		Complex* data_ = new Complex[size_];
	}
}
Complex& StackArr::Top() {
	if (i_top_ > -1) {
		return data_[i_top_];
	}
	else {
		throw std::out_of_range("The StackArr is empty");
	}
}

void StackArr::Clear() noexcept {
	i_top_ = -1;
}

