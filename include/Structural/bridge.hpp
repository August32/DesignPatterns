//
// Created by 12865 on 2022/10/4.
//

/*
 * Decouple an abstraction from its implementation
 * so that the two can vary independently.
 *
 * 将抽象和实现解耦，使它们可以独立变化。
 */

#ifndef DESIGNPATTERNS_BRIGE_HPP
#define DESIGNPATTERNS_BRIGE_HPP


// 实现者类接口 (Implementor)
class IColor {
public:
    virtual ~IColor() = default;

    virtual std::string coloring() = 0;

protected:
    std::string m_color;
};

// 具体实现者类 - 1 (ConcreteImplementor)
class RedColor : public IColor {
public:
    RedColor() {
        m_color = "red";
    }

    std::string coloring() override {
        std::cout << "Making red paint..." << std::endl;

        return m_color;
    }
};

// 具体实现者类 - 2
class GreenColor : public IColor {
public:
    GreenColor() {
        m_color = "green";
    }

    std::string coloring() override {
        std::cout << "Making green paint..." << std::endl;

        return m_color;
    }
};

// 具体实现者类 - 3
class BlueColor : public IColor {
public:
    BlueColor() {
        m_color = "blue";
    }

    std::string coloring() override {
        std::cout << "Making blue paint..." << std::endl;

        return m_color;
    }
};


// 抽象类接口 (Abstraction)
class IShape {
public:
    // “实现者对象”参数 可以在构造时传入，也可以在调用其他方法时传入
    explicit IShape(IColor *color) : m_color(color) {};

    virtual ~IShape() = default;

    virtual void produce() = 0;

protected:
    IColor *m_color;
};

// 扩充抽象类 - 1 (RefinedAbstraction)
class Circle : public IShape {
public:
    explicit Circle(IColor *color) : IShape(color) {};

    void produce() override {
        std::string s_color = m_color->coloring();
        
        std::cout << "The " << s_color << " circle!" << std::endl;
    }
};

// 扩充抽象类 - 2
class Square : public IShape {
public:
    explicit Square(IColor *color) : IShape(color) {};

    void produce() override {
        std::string s_color = m_color->coloring();
        
        std::cout << "The " << s_color << " square!" << std::endl;
    }
};

// 扩充抽象类 - 3
class Triangle : public IShape {
public:
    explicit Triangle(IColor *color) : IShape(color) {};

    void produce() override {
        std::string s_color = m_color->coloring();

        std::cout << "The " << s_color << " triangle!" << std::endl;
    }
};

// **********************************************************************


void bridge_test() {
    IColor *red_color = new RedColor();

    IShape *red_circle = new Circle(red_color);

    red_circle->produce();

    delete red_circle;
    delete red_color;
}


#endif //DESIGNPATTERNS_BRIGE_HPP
