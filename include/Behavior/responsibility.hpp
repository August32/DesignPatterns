//
// Created by DELL on 2023/1/4.
//

#ifndef DESIGNPATTERNS_RESPONSIBILITY_HPP
#define DESIGNPATTERNS_RESPONSIBILITY_HPP


#include <iostream>
#include <vector>


// 定义抽象类，表示处理请求的对象
class IHandler {
public:
    virtual ~IHandler() = default;

    virtual bool handle(int request) = 0;
};

// 具体的处理对象1，能够处理 1~10 的请求
class ConcreteHandler1 : public IHandler {
public:
    bool handle(int request) override {
        bool handled = false;

        if (request >= 1 && request <= 10) {
            std::cout << "ConcreteHandler1: request " << request << " handled." << std::endl;
            handled = true;
        }

        return handled;
    };
};

// 具体的处理对象2，能够处理 11~20 的请求
class ConcreteHandler2 : public IHandler {
public:
    bool handle(int request) override {
        bool handled = false;

        if (request >= 11 && request <= 20) {
            std::cout << "ConcreteHandler2: request " << request << " handled." << std::endl;
            handled = true;
        }

        return handled;
    };
};

// 具体的处理对象3，能够处理 21~30 的请求
class ConcreteHandler3 : public IHandler {
public:
    bool handle(int request) override {
        bool handled = false;

        if (request >= 21 && request <= 30) {
            std::cout << "ConcreteHandler3: request " << request << " handled." << std::endl;
            handled = true;
        }

        return handled;
    };
};

// 职责链
class HandlerChain {
public:
    HandlerChain() = default;

    ~HandlerChain() = default;

    HandlerChain(const HandlerChain &) = delete;

    HandlerChain &operator=(const HandlerChain &) = delete;

public:
    void add_handle(IHandler *handler) {
        m_handlers.emplace_back(handler);
    }

    void handle(int request) {
        for (const auto &i : m_handlers) {
            bool handled = i->handle(request);

            if (handled) return;
        }

        std::cout << "HandlerChain: request error!" << std::endl;
    }

private:
    std::vector<IHandler *> m_handlers;
};

// **********************************************************************


void chain_of_responsibility_test() {
    // 创建职责链
    HandlerChain handler_chain;
    IHandler *h1 = new ConcreteHandler1();
    IHandler *h2 = new ConcreteHandler2();
    IHandler *h3 = new ConcreteHandler3();

    // 添加具体的处理对象
    handler_chain.add_handle(h1);
    handler_chain.add_handle(h2);
    handler_chain.add_handle(h3);

    // 发送请求
    handler_chain.handle(15);
    handler_chain.handle(25);
    handler_chain.handle(35);

    delete h1;
    delete h2;
    delete h3;
}


#endif //DESIGNPATTERNS_RESPONSIBILITY_HPP
