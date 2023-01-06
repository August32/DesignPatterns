//
// Created by DELL on 2023/1/6.
//

#ifndef DESIGNPATTERNS_ITERATOR_HPP
#define DESIGNPATTERNS_ITERATOR_HPP


#include <iostream>
#include <vector>


template<class T>
class MyVector;

// ������������
template<class T>
class AbstractIterator {
public:
    virtual ~AbstractIterator() = default;

    virtual bool has_next() = 0;

    virtual void next() = 0;

    virtual T current_item() = 0;
};

// ������������
template<class T>
class VectorIterator : AbstractIterator<T> {
public:
    explicit VectorIterator(MyVector<T> &vector) {
        m_vector = vector;
        m_cursor = 0;
    };

    ~VectorIterator() override = default;

public:
    bool has_next() override {
        return m_cursor != m_vector.size();
    }

    void next() override {
        m_cursor++;
    }

    T current_item() override {
        return m_vector[m_cursor];
    }

public:
    MyVector<T> m_vector;
    int m_cursor;
};

// ������
template<class T>
class MyVector : public std::vector<T> {
public:
    VectorIterator<T> my_iterator() {
        return VectorIterator<T>(*this);
    }
};

// **********************************************************************


void iterator_test() {
    MyVector<int> v;
    v.emplace_back(25);
    v.emplace_back(58);
    v.emplace_back(39);
    v.emplace_back(84);

    // ʵ��������������
    VectorIterator<int> vi = v.my_iterator();

    // ����������
    while (vi.has_next()) {
        std::cout << vi.current_item() << std::endl;
        vi.next();
    }
}


#endif //DESIGNPATTERNS_ITERATOR_HPP
