#include <bitset/bitset.hpp>
#include <iostream>
#include <stdexcept>

#define SIZE 32
#define MAX 2147483648

BitSet::BitSet(const std::int32_t size)
    : size_(size) {
}

BitSet::BitSet(const BitSet& bts) {
    size_ = bts.size_;
    bits_ = bts.bits_;
}

//BiA& operator=(BiA&& rhs) noexcept {
//    
//}


//BitSet::BiA BitSet::operator[](const int32_t idx) {
//  if (idx < 0) {
//    throw std::out_of_range("BitSet::operator[] index is negative");
//  }
//  if (std::ssize(bits_) <= idx) {
//    throw std::out_of_range("BitSet::operator[] index exceeds the maximum allowable value");
//  }
//  return {*this, idx};
//}

BitSet& BitSet::operator=(const BitSet& bts) {
    if (this != &bts) {
        size_ = bts.size_;
        bits_ = bts.bits_;
    }
    return *this;
}

bool BitSet::operator==(const BitSet& rhs) const noexcept {
    return (this == &rhs);
}

bool BitSet::Get(const int32_t idx) const {
    if (size_ > 0 && idx < size_ * SIZE && idx * SIZE >= 0) {
        throw std::out_of_range("List index out of range");
    }
    else {
        std::int32_t num_of_num = idx / SIZE;
        std::int32_t num_in_num = idx - num_of_num * SIZE;
        std::int32_t num = MAX >> num_in_num;
        bool bit = false;
        bit = bits_[num_of_num] & num;
        return bit;
    }
}

void BitSet::Set(const int32_t idx, const bool val) {
    if (size_ > 0 && idx < size_ * SIZE && idx * SIZE >= 0) {
        std::int32_t num_of_num = idx / SIZE;
        std::int32_t num_in_num = idx - num_of_num * SIZE;
        std::uint32_t num = MAX >> num_in_num;;
        if (val == true) {
            num = MAX >> num_in_num;
            bits_[num_of_num] = bits_[num_of_num] | num;
        }
        else {
            bits_[num_of_num] = bits_[num_of_num] & ~num;
        }
    }
    else {
        throw std::out_of_range("List index out of range.");
    }
}

void BitSet::Resize(const int32_t size) {
    if (size < 0) {
        throw std::invalid_argument("Size should be a positive number");
    }
    else {
        size_ = size;
    }
}

void BitSet::Fill(const bool val) noexcept {
    if (val) {
        for (int32_t i = 0; i < size_; i++) {
            bits_[i] = 4294967295;
        }
    } else {
        for (int32_t i = 0; i < size_; i++) {
            bits_[i] = 0;
        }
    }
}

BitSet BitSet::operator~() {
	BitSet new_bs(size_);
	for (int i = 0; i < size_; i++) {
		new_bs.bits_[i] = ~bits_[i];
	}
	return new_bs;
}



BitSet& BitSet::operator&=(const BitSet& rhs) {
	if (size_ != rhs.size_) {
		throw std::invalid_argument("Bitsets must have the same sizes.");
	}
	else {
		for (int i = 0; i < size_; i++) {
			bits_[i] = bits_[i] & rhs.bits_[i];
		}
		return *this;
	}
}


BitSet& BitSet::operator|=(const BitSet& rhs) {
	if (size_ != rhs.size_) {
		throw std::invalid_argument("Bitsets must have the same sizes.");
	}
	else {
		for (int i = 0; i < size_; i++) {
			bits_[i] = bits_[i] | rhs.bits_[i];
		}
		return *this;
	}
}


BitSet& BitSet::operator^=(const BitSet& rhs) {
	if (size_ != rhs.size_) {
		throw std::invalid_argument("Bitsets must have the same sizes.");
	}
	else {
		for (int i = 0; i < size_; i++) {
			bits_[i] = bits_[i] ^ rhs.bits_[i];
		}
		return *this;
	}
}


BitSet operator&(const BitSet& lhs, const BitSet& rhs) {
	if (lhs.Size() != rhs.Size()) {
		throw std::invalid_argument("Bitsets must have the same sizes.");
	}
	else {
		BitSet result(lhs);
		return result &= rhs;
	}
}


BitSet operator|(const BitSet& lhs, const BitSet& rhs) {
	if (lhs.Size() != rhs.Size()) {
		throw std::invalid_argument("Bitsets must have the same sizes.");
	}
	else {
		BitSet result(lhs);
		return result |= rhs;
	}
}


BitSet operator^(const BitSet& lhs, const BitSet& rhs) {
	if (lhs.Size() != rhs.Size()) {
		throw std::invalid_argument("Bitsets must have the same sizes.");
	}
	else {
		BitSet result(lhs);
		return result ^= rhs;
	}
}

BitSet operator&(const BitSet& lhs, const BitSet& rhs) {
	BitSet res(lhs);
	res &= rhs;
	return res;
}

BitSet operator|(const BitSet& lhs, const BitSet& rhs) {
	BitSet res(lhs);
	res |= rhs;
	return res;
}

BitSet operator^(const BitSet& lhs, const BitSet& rhs) {
	BitSet res(lhs);
	res ^= rhs;
	return res;
}

BitSet::BiA::operator bool() const {
	return bst_.Get(idx_);
}

BitSet::BiA BitSet::operator[](const std::int32_t idx) {
	if (idx >= 0 && idx < size_) {
		BiA bia(*this, idx);
		return bia;
	}
	throw(std::logic_error("Wrong idx\n"));
}

BitSet::BiA& BitSet::BiA::operator=(const BiA rhs) {
	bst_.Set(idx_, rhs.bst_.Get(rhs.idx_));
	return *this;
}

BitSet::BiA& BitSet::BiA::operator=(const bool val) {
	bst_.Set(idx_, val);
	return *this;
}

const bool BitSet::operator[](const std::int32_t idx) const {
	if (idx >= 0 && idx < size_) {
		return Get(idx);
	}
	throw(std::logic_error("Wrong idx\n"));
}


