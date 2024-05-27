#pragma once
#ifndef BITSET_BITSET_HPP_20240318
#define BITSET_BITSET_HPP_20240318

#include <cstdint>
#include <iosfwd>
#include <vector>

class BitSet {
public:
    class BiA {
    public:
        BiA() = delete;
        BiA(BitSet& bst, const std::int32_t idx) noexcept : bst_(bst), idx_(idx) {}
        ~BiA() = default;
        BiA(const BiA& rhs) = delete;
        BiA(BiA&&) noexcept = default;
        BiA& operator=(const BiA rhs);
        BiA& operator=(BiA&& rhs) noexcept = default;
        BiA& operator=(const bool val);
        operator bool() const { return bst_.Get(idx_); }

    private:
        BitSet& bst_;
        const std::int32_t idx_ = -1;
    };
public:
    BitSet() = default;

    BitSet(const BitSet& bts);

    BitSet(BitSet&&) = default;

    BitSet(const std::int32_t size);

    BitSet& operator=(const BitSet& bts);

    BitSet& operator=(BitSet&&) = default;

    ~BitSet() = default;

    bool operator==(const BitSet& rhs) const noexcept;
    
    bool operator!=(const BitSet& rhs) const noexcept { return !(*this == rhs); }

    int32_t Size() const noexcept { return size_; }

    void Resize(const int32_t size); // 0 < size

    bool Get(const int32_t idx) const;

    void Set(const int32_t idx, const bool val);

    void Fill(const bool val) noexcept;

    BitSet& operator&=(const BitSet& rhs);

    BitSet& operator|=(const BitSet& rhs);

    BitSet& operator^=(const BitSet& rhs);

    BitSet operator~();

    BiA operator[](const int32_t idx) { return { *this, idx }; }

    const bool operator[](const std::int32_t idx) const;

    // std::ostream& WriteTxt(std::ostream&)
    // std::ostream& WriteBinary(std::ostream&)
    // std::istream& ReadTxt(std::istream&)
    // std::istream& RaadBinary(std::istream&)
private:
    std::int32_t size_ = 0;
    std::vector<uint32_t> bits_;
};

// std::ostream& operaror<<(std::ostream&, const BitSet&);
// std::istream& operaror>>(std::istream&, BitSet&);

BitSet operator&(const BitSet& lhs, const BitSet& rhs);

BitSet operator|(const BitSet& lhs, const BitSet& rhs);

BitSet operator^(const BitSet& lhs, const BitSet& rhs);

#endif