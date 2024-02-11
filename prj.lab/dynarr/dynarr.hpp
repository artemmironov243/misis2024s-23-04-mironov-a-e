#pragma once
#ifndef DYNARR_DYNARR_HPP_20231203
#define DYNARR_DYNARR_HPP_20231203

#include <cstddef>
#include <sstream>


class DynArr {
public:
	DynArr();

	DynArr(const DynArr& arr);

	DynArr(const std::ptrdiff_t size);

	~DynArr();

	DynArr& operator=(const DynArr& arr);

	std::ptrdiff_t Size() const noexcept { return size_; }

	//! \param size - новый размер, 0 < size
	void Resize(const std::ptrdiff_t size);

	void Push_back(float val) noexcept;

	float& operator[](const std::ptrdiff_t idx);

	const float& operator[](const std::ptrdiff_t idx) const { return *(data_ + idx); }

private:
	std::ptrdiff_t size_ = 0; //!< число элементов в массиве
	float *data_ = nullptr;//!< элементы массива
	std::ptrdiff_t capasity = 0;
};

#endif