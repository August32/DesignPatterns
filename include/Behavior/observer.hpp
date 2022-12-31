//
// Created by 12865 on 2022/12/31.
//

#ifndef DESIGNPATTERNS_OBSERVER_HPP
#define DESIGNPATTERNS_OBSERVER_HPP


#include <iostream>
#include <vector>
#include <algorithm>


class Observer;

// 抽象类 Subject，表示被观察者（即发布者）
class Subject {
public:
    virtual ~Subject() = default;

    virtual void register_obs(Observer *obs) = 0;

    virtual void remove_obs(Observer *obs) = 0;

    virtual void notify_obs() = 0;
};

// 抽象类 Observer，表示观察者（即订阅者）
class Observer {
public:
    virtual ~Observer() = default;

    virtual void update(Subject *sub) = 0;
};

// 具体类 ConcreteSubject，表示具体的被观察者
class ConcreteSubject : public Subject {
public:
    void register_obs(Observer *obs) override {
        m_observers.push_back(obs);
    }

    void remove_obs(Observer *obs) override {
        auto iter = std::find(m_observers.begin(), m_observers.end(), obs);
        if (iter != m_observers.end())
            m_observers.erase(iter);
    }

    void notify_obs() override {
        for (Observer *obs : m_observers)
            obs->update(this);
    }

    int get_state() const {
        return m_state;
    }

    void set_state(int state) {
        m_state = state;
    }

private:
    std::vector<Observer *> m_observers;
    int m_state = 0;
};

// 具体类 ConcreteObserver，表示具体的观察者
class ConcreteObserver : public Observer {
public:
    explicit ConcreteObserver(ConcreteSubject *sub) : m_subject(sub) {
        m_subject->register_obs(this);
    }

    void update(Subject *sub) override {
        if (sub == m_subject) {
            std::cout << "ConcreteObserver: Reacted to the event." << std::endl;
        }
    }

private:
    ConcreteSubject *m_subject;
};

// **********************************************************************


void observer_test() {
    // 创建被观察者
    auto *subject = new ConcreteSubject;
    // 创建观察者
    Observer *obs1 = new ConcreteObserver(subject);
    Observer *obs2 = new ConcreteObserver(subject);

    // 改变被观察者的状态，此时应该会通知所有的观察者
    subject->set_state(42);
    subject->notify_obs();

    // 删除一个观察者
    subject->remove_obs(obs1);

    // 改变被观察者的状态，此时只会通知剩下的观察者
    subject->set_state(123);
    subject->notify_obs();

    delete obs1;
    delete obs2;
    delete subject;
}


#endif //DESIGNPATTERNS_OBSERVER_HPP
