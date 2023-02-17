//
// Created by DELL on 2023/1/6.
//

#ifndef DESIGNPATTERNS_ITERATOR_HPP
#define DESIGNPATTERNS_ITERATOR_HPP

#include <iostream>
#include <vector>


template<typename T>
class MyVector;

// 迭代器抽象类
template<typename T>
class AbstractIterator {
public:
    virtual ~AbstractIterator() = default;

    virtual bool has_next() = 0;

    virtual void next() = 0;

    virtual T current_item() = 0;
};

// 迭代器具体类
template<typename T>
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

// 容器类
template<typename T>
class MyVector : public std::vector<T> {
public:
    ~MyVector() = default;

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

    // 实例化迭代器对象
    VectorIterator<int> vi = v.my_iterator();

    // 迭代器遍历
    while (vi.has_next()) {
        std::cout << vi.current_item() << std::endl;
        vi.next();
    }
}


#endif //DESIGNPATTERNS_ITERATOR_HPP
