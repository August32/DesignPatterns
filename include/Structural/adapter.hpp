//
// Created by 12865 on 2022/10/5.
//

#ifndef DESIGNPATTERNS_ADAPTER_HPP
#define DESIGNPATTERNS_ADAPTER_HPP


/* 适配器模式：
 * 1.类适配器
 * 2.对象适配器
 */


// 共享类

// 目标接口
class ITarget {
public:
    virtual ~ITarget() = default;

    virtual void f1() = 0;

    virtual void f2() = 0;

    virtual void f3() = 0;
};

// 被适配类（一个或多个）
class Adaptee {
public:
    Adaptee() = default;

    ~Adaptee() = default;

    Adaptee(Adaptee &) = delete;

    Adaptee &operator=(Adaptee &) = delete;

private:
    int value = 0;

public:
    void fa() const { std::cout << "fa" << value << std::endl; };

    void fb() const { std::cout << "fb" << value << std::endl; };

    void fc() const { std::cout << "fc" << value << std::endl; };
};

// **********************************************************************


// 1.类适配器，通过继承关系实现

class ClassAdapter : public ITarget, private Adaptee {
public:
    ClassAdapter() = default;

    ~ClassAdapter() override = default;

    ClassAdapter(ClassAdapter &) = delete;

    ClassAdapter &operator=(ClassAdapter &) = delete;

public:
    void f1() override {
        fa();
    }

    void f2() override {
        fb();
    }

    void f3() override {
        fc();
    }
};

// **********************************************************************


// 2.对象适配器，通过组合关系实现

class ObjectAdapter : public ITarget {
public:
    ObjectAdapter() = default;

    ~ObjectAdapter() override = default;

    ObjectAdapter(ObjectAdapter &) = delete;

    ObjectAdapter &operator=(ObjectAdapter &) = delete;

private:
    Adaptee m_adaptee;

public:
    void f1() override {
        m_adaptee.fa();
    }

    void f2() override {
        m_adaptee.fb();
    }

    void f3() override {
        m_adaptee.fc();
    }

    // 也可以增加 fc() 方法，保留原接口
    void fc() {
        m_adaptee.fc();
    }
};

// **********************************************************************


void adapter_test() {
    ClassAdapter class_adapter;
    class_adapter.f2();

    ObjectAdapter object_adapter;
    object_adapter.f3();
}


#endif //DESIGNPATTERNS_ADAPTER_HPP
