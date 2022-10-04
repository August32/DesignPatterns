//
// Created by 12865 on 2022/10/4.
//

#ifndef DESIGNPATTERNS_BRIGE_HPP
#define DESIGNPATTERNS_BRIGE_HPP


class IColor {
public:
    virtual ~IColor() = default;

    virtual std::string coloring() = 0;

protected:
    std::string m_color;
};

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


class IShape {
public:
    explicit IShape(IColor *color) : m_color(color) {};

    virtual ~IShape() = default;

    virtual void produce() = 0;

protected:
    IColor *m_color;
};

class Circle : public IShape {
public:
    explicit Circle(IColor *color) : IShape(color) {};

    void produce() override {
        std::string s_color = m_color->coloring();
        
        std::cout << "The " << s_color << " circle!" << std::endl;
    }
};

class Square : public IShape {
public:
    explicit Square(IColor *color) : IShape(color) {};

    void produce() override {
        std::string s_color = m_color->coloring();
        
        std::cout << "The " << s_color << " square!" << std::endl;
    }
};

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
