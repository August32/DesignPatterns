//
// Created by 12865 on 2023/1/1.
//

#ifndef DESIGNPATTERNS_TEMPLATE_METHOD_HPP
#define DESIGNPATTERNS_TEMPLATE_METHOD_HPP

#include <iostream>


// 抽象类 TM_AbstractClass，表示模板模式的抽象类
class TMAbstractClass {
public:
    virtual ~TMAbstractClass() = default;

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

// 具体类 TM_ConcreteClassA，表示模板模式的具体子类
class TMConcreteClassA : public TMAbstractClass {
protected:
    void primitive_operation_1() override {
        std::cout << "TMConcreteClassA: PrimitiveOperation1" << std::endl;
    }

    void primitive_operation_2() override {
        std::cout << "TMConcreteClassA: PrimitiveOperation2" << std::endl;
    }
};

// 具体类 TM_ConcreteClassB，表示模板模式的具体子类
class TMConcreteClassB : public TMAbstractClass {
protected:
    void primitive_operation_1() override {
        std::cout << "TMConcreteClassB: PrimitiveOperation1" << std::endl;
    }

    void primitive_operation_2() override {
        std::cout << "TMConcreteClassB: PrimitiveOperation2" << std::endl;
    }
};

// **********************************************************************


void template_method_test() {
    // 使用具体子类 TMConcreteClassA
    TMAbstractClass *class1 = new TMConcreteClassA;
    class1->template_method();
    delete class1;

    std::cout << std::endl;

    // 使用具体子类 TMConcreteClassB
    TMAbstractClass *class2 = new TMConcreteClassB;
    class2->template_method();
    delete class2;
}


#endif //DESIGNPATTERNS_TEMPLATE_METHOD_HPP
