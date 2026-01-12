#pragma once

#include <cstdint>

enum ByteUnit : uint32_t
{
    BYTE,
    KILOBYTE,
    MEGABYTE,
    GIGABYTE,
    TERABYTE,
    PETABYTE
    // already a crazy future-proof
};

struct ByteUnitConverter
{
    uint64_t total_bytes;

    constexpr ByteUnitConverter(uint64_t total_bytes) : total_bytes(total_bytes) {}

    constexpr uint64_t AsInt(ByteUnit unit) const
    {
        return total_bytes >> (unit * 10);
    }

    constexpr float AsDecimal(ByteUnit unit) const
    {
        return total_bytes / (float)(1 << (unit * 10));
    }
};