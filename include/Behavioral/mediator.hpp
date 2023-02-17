//
// Created by DELL on 2023/1/16.
//

/*
 * Mediator pattern defines a separate (mediator) object that
 * encapsulates the interaction between a set of objects and the objects
 * delegate their interaction to a mediator object instead of interacting
 * with each other directly.
 *
 * 中介模式定义了一个单独的（中介）对象，来封装一组对象之间的交互，
 * 这组对象将它们之间的交互委托给中介对象，以避免它们之间的直接交互。
 */

#ifndef DESIGNPATTERNS_MEDIATOR_HPP
#define DESIGNPATTERNS_MEDIATOR_HPP

#include <iostream>
#include <vector>
#include <string>


class IColleague;

// 中介类
class Mediator {
public:
    Mediator() = default;

    ~Mediator() = default;

public:
    void add_colleague(IColleague *colleague);

    void distribute(IColleague *sender, const std::string &message);

private:
    std::vector<IColleague *> m_colleagues;
};

// 同事抽象类
class IColleague {
public:
    explicit IColleague(Mediator *mediator)
            : m_mediator(mediator) {}

    virtual ~IColleague() = default;

    virtual void send(const std::string &message) = 0;

    virtual void receive(const std::string &message) = 0;

protected:
    Mediator *m_mediator;
};

// 同事具体类 - A
class ConcreteColleagueA : public IColleague {
public:
    explicit ConcreteColleagueA(Mediator *mediator)
            : IColleague(mediator) {}

    void send(const std::string &message) override {
        m_mediator->distribute(this, message);
    }

    void receive(const std::string &message) override {
        std::cout << "ConcreteColleagueA receive message: " << message << std::endl;
    }
};

// 同事具体类 - B
class ConcreteColleagueB : public IColleague {
public:
    explicit ConcreteColleagueB(Mediator *mediator)
            : IColleague(mediator) {}

    void send(const std::string &message) override {
        m_mediator->distribute(this, message);
    }

    void receive(const std::string &message) override {
        std::cout << "ConcreteColleagueB receive message: " << message << std::endl;
    }
};

// **********************************************************************


// 中介类方法定义
void Mediator::add_colleague(IColleague *colleague) {
    m_colleagues.push_back(colleague);
}

void Mediator::distribute(IColleague *sender, const std::string &message) {
    for (auto colleague : m_colleagues) {
        if (colleague != sender) {
            colleague->receive(message);
        }
    }
}

// **********************************************************************


void mediator_test() {
    auto *mediator = new Mediator;
    auto *colleague_A = new ConcreteColleagueA(mediator);
    auto *colleague_B = new ConcreteColleagueB(mediator);

    mediator->add_colleague(colleague_A);
    mediator->add_colleague(colleague_B);
    colleague_A->send("Hello, I am colleague_A.");
    colleague_B->send("Hello, I am colleague_B.");

    delete mediator;
    delete colleague_A;
    delete colleague_B;
}


#endif //DESIGNPATTERNS_MEDIATOR_HPP
