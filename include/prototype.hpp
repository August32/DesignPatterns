//
// Created by 12865 on 2022/9/12.
//

#ifndef DESIGNPATTERNS_PROTOTYPE_HPP
#define DESIGNPATTERNS_PROTOTYPE_HPP


class AbstractProto {
public:
    virtual ~AbstractProto() = default;

    virtual AbstractProto *clone() = 0;
};

class ConcreteProto : public AbstractProto {
public:
    ConcreteProto() {
        m_value = 0;
    };

    ~ConcreteProto() override = default;

    ConcreteProto &operator=(const ConcreteProto &) = delete;

private:
    ConcreteProto(const ConcreteProto &) = default;

public:
    AbstractProto *clone() override {
        return new ConcreteProto(*this);  // 根据实际情况(浅/深拷贝) 编写 拷贝构造函数
    }

    int get_value() const {
        return m_value;
    }

private:
    int m_value;
};

// **********************************************************************


void prototype_test() {
    AbstractProto *c4 = new ConcreteProto();
    AbstractProto *c5 = c4->clone();

    delete c4;
    delete c5;
}


#endif //DESIGNPATTERNS_PROTOTYPE_HPP
