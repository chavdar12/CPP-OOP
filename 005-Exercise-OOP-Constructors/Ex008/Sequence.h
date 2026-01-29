#ifndef SEQ_H
#define SEQ_H

#include <vector>

template <typename T, typename Generator>
class Sequence
{
public:
    class Iterator
    {
    private:
        const std::vector<T>& seqEl;
        int indexInSeq;

        Iterator(const std::vector<T>& seqEl_, int indexInSeq_) : seqEl(seqEl_), indexInSeq(indexInSeq_)
        {
        }

        static bool isEndIndex(int index, const std::vector<T>& seqEl)
        {
            return index == -1 || index == seqEl.size();
        }

    public:
        static Iterator getBegin(const std::vector<T>& seqEl)
        {
            return Iterator(seqEl, 0);
        }

        static Iterator getEnd(const std::vector<T>& seqEl)
        {
            return Iterator(seqEl, -1);
        }

        const T& operator*() const
        {
            return this->seqEl.at(this->indexInSeq);
        }

        Iterator& operator++()
        {
            this->indexInSeq++;
            return *this;
        }

        bool operator!=(const Iterator& other) const
        {
            return !(*this == other);
        }

        bool operator==(const Iterator& other) const
        {
            bool seqMatch = (this->seqEl == other.seqEl);
            bool bothPosAreEnd = (isEndIndex(this->indexInSeq, this->seqEl) &&
                isEndIndex(other.indexInSeq, other.seqEl));
            bool posMatch = (this->indexInSeq == other.indexInSeq);

            return seqMatch && (bothPosAreEnd || posMatch);
        }
    };

private:
    Generator generator;
    std::vector<T> generated;

public:
    void generateNext(int n)
    {
        for (size_t i = 0; i < n; i++)
        {
            this->generated.push_back(this->generator());
        }
    }

    Iterator begin() const { return Iterator::getBegin(this->generated); };
    Iterator end() const { return Iterator::getEnd(this->generated); };
};


#endif
