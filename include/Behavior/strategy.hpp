//
// Created by 12865 on 2023/1/2.
//

#ifndef DESIGNPATTERNS_STRATEGY_HPP
#define DESIGNPATTERNS_STRATEGY_HPP

#include <iostream>


// 定义抽象策略类
class AbstractStrategy {
public:
    virtual ~AbstractStrategy() = default;

    virtual void execute() = 0;
};

// 定义具体策略类A
class ConcreteStrategyA : public AbstractStrategy {
public:
    void execute() override {
        std::cout << "Executing strategy A" << std::endl;
    }
};

// 定义具体策略类B
class ConcreteStrategyB : public AbstractStrategy {
public:
    void execute() override {
        std::cout << "Executing strategy B" << std::endl;
    }
};

// 注：可以搭配工厂模式来管理具体策略

// 定义上下文类
class StrategyContext {
public:
    explicit StrategyContext(AbstractStrategy *strategy) : m_strategy(strategy) {}

    void set_strategy(AbstractStrategy *strategy) {
        m_strategy = strategy;
    }

    void execute() {
        m_strategy->execute();
    }

private:
    AbstractStrategy *m_strategy;
};

// **********************************************************************


void strategy_test() {
    // 创建策略对象
    AbstractStrategy *strategyA = new ConcreteStrategyA();
    AbstractStrategy *strategyB = new ConcreteStrategyB();
    // 创建上下文对象
    auto *context = new StrategyContext(strategyA);

    // 执行策略A
    context->execute();
    // 更改策略
    context->set_strategy(strategyB);
    // 执行策略B
    context->execute();

    delete context;
    delete strategyA;
    delete strategyB;
}


#endif //DESIGNPATTERNS_STRATEGY_HPP
