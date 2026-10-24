class IndexedContainer {
public:
    virtual int &operator[](int index) = 0;

    // Without this virtual destructor, `delete c` below would skip ~IntArray() and leak data
    virtual ~IndexedContainer() {}
};

class IntArray : public IndexedContainer {
    int size;
    int *data;

public:
    IntArray(int size) : size(size), data(new int[size]) {
    }

    virtual ~IntArray() override {
        delete[] this->data;
    }

    virtual int &operator[](int index) override {
        return data[index];
    }
};

int main() {
    // the original demo looped forever to show memory growing; bounded so the program terminates
    for (int i = 0; i < 1000000; i++) {
        IndexedContainer *c = new IntArray(10);
        delete c;
    }

    return 0;
}
