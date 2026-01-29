#pragma once

template <typename T, typename Compare>
struct ReverseComparer
{
    bool operator()(const T& lhs, const T& rhs) const
    {
        Compare compare;
        return compare(rhs, lhs);
    }
};

struct VectorLengthComparer
{
    bool operator()(const Vector& lhs, const Vector& rhs) const
    {
        return lhs.getLength() < rhs.getLength();
    }
};
