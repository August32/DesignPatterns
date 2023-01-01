//
// Created by 12865 on 2023/1/1.
//

#ifndef DESIGNPATTERNS_TEMPLATE_METHOD_HPP
#define DESIGNPATTERNS_TEMPLATE_METHOD_HPP


#include <iostream>


// 抽象类 AbstractClass，表示模板模式的抽象类
class AbstractClass {
public:
    virtual ~AbstractClass() = default;

    void template_method() {
        // 不变的部分
        std::cout << "Step 1" << std::endl;
        // 可变的部分
        primitive_operation_1();
        primitive_operation_2();
        // 不变的部分
        std::cout << "Step 3" << std::endl;
    }

protected:
    virtual void primitive_operation_1() = 0;

    virtual void primitive_operation_2() = 0;
};

// 具体类 ConcreteClassA，表示模板模式的具体子类
class ConcreteClassA : public AbstractClass {
protected:
    void primitive_operation_1() override {
        std::cout << "ConcreteClassA: PrimitiveOperation1" << std::endl;
    }

    void primitive_operation_2() override {
        std::cout << "ConcreteClassA: PrimitiveOperation2" << std::endl;
    }
};

// 具体类 ConcreteClassB，表示模板模式的具体子类
class ConcreteClassB : public AbstractClass {
protected:
    void primitive_operation_1() override {
        std::cout << "ConcreteClassB: PrimitiveOperation1" << std::endl;
    }

    void primitive_operation_2() override {
        std::cout << "ConcreteClassB: PrimitiveOperation2" << std::endl;
    }
};

// **********************************************************************


void template_method_test() {
    // 使用具体子类 ConcreteClassA
    AbstractClass *class1 = new ConcreteClassA;
    class1->template_method();
    delete class1;

    std::cout << std::endl;

    // 使用具体子类 ConcreteClassB
    AbstractClass *class2 = new ConcreteClassB;
    class2->template_method();
    delete class2;
}


#endif //DESIGNPATTERNS_TEMPLATE_METHOD_HPP
