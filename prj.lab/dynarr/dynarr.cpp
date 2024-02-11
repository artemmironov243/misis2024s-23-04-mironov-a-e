#include <dynarr/dynarr.hpp>
#include <iostream>

DynArr::DynArr() {
	size_ = 0;
	data_ = nullptr;
	capasity = 0;
}

DynArr::DynArr(const DynArr& arr) {
	size_ = arr.size_;
	capasity = arr.capasity;
	if (arr.size_ != 0) {
		data_ = new float[arr.size_];
		for (int i = 0; i < arr.size_; i++) {
			data_[i] = arr.data_[i];
		}
	}
	else {
		data_ = 0;
	}
}

DynArr::DynArr(const std::ptrdiff_t size) {
	capasity = 0;
	size_ = 0;
	if (size < 0) {
		throw std::overflow_error("Size can not be less than 0");
	}
	else if (size == 0) {
		capasity = 0;
		data_ = 0;
		size_ = 0;
	}
	else {
		capasity = size;
		size_ = size;
		data_ = new float[size_] {};
	}
}

void DynArr::Resize(const std::ptrdiff_t size) {
	if (capasity < size) {
		std::ptrdiff_t new_capacity = 0;
		if (size > size_ * 2) {
			new_capacity = size;
		}
		else {
			new_capacity = size_ * 2;
		}
		float* new_data = new float[new_capacity] {};
		for (int i = 0; i < size_; i++) {
			new_data[i] = data_[i];
		}
		delete[] data_;
		data_ = new_data;
		capasity = new_capacity;
	}
	size_ = size;
}

DynArr::~DynArr() {
	if (data_) {
		delete[] data_;
	}
}

DynArr& DynArr::operator=(const DynArr& arr) {
	delete[] data_;
	data_ = new float[arr.size_];
	size_ = arr.size_;
	return *this;
}

float& DynArr::operator[](std::ptrdiff_t idx) {
	if (idx >= size_ || 0 > idx) {
		throw std::out_of_range("index out of range");
	}
	return data_[idx];
}

void DynArr::Push_back(float val) noexcept {
	DynArr::Resize(size_ + 1);
	data_[size_ - 1] = val;
}
