//
// Created by DELL on 2023/1/16.
//

/*
 * Interpreter pattern is used to defines a grammatical representation for
 * a language and provides an interpreter to deal with this grammar.
 *
 * 解释器模式用于定义一种语言的语法表示，并提供一个解释器来处理这种语法。
 */

#ifndef DESIGNPATTERNS_INTERPRETER_HPP
#define DESIGNPATTERNS_INTERPRETER_HPP

#include <iostream>
#include <map>
#include <memory>
#include <string>


// 表达式抽象类
class Expression {
public:
    virtual ~Expression() = default;

    virtual double interpret(std::map<std::string, double> variables) = 0;
};

// 数字类
class Number : public Expression {
public:
    explicit Number(double value)
            : m_value(value) {}

    double interpret(std::map<std::string, double> variables) override {
        return m_value;
    }

private:
    double m_value;
};

// 变量类
class Variable : public Expression {
public:
    explicit Variable(std::string name)
            : m_name(std::move(name)) {}

    double interpret(std::map<std::string, double> variables) override {
        return variables[m_name];
    }

private:
    std::string m_name;
};

// “加” 操作类
class Add : public Expression {
public:
    Add(std::shared_ptr<Expression> left, std::shared_ptr<Expression> right) {
        m_left = std::move(left);
        m_right = std::move(right);
    }

    double interpret(std::map<std::string, double> variables) override {
        return m_left->interpret(variables) + m_right->interpret(variables);
    }

private:
    std::shared_ptr<Expression> m_left, m_right;
};

// “减” 操作类
class Subtract : public Expression {
public:
    Subtract(std::shared_ptr<Expression> left, std::shared_ptr<Expression> right) {
        m_left = std::move(left);
        m_right = std::move(right);
    }

    double interpret(std::map<std::string, double> variables) override {
        return m_left->interpret(variables) - m_right->interpret(variables);
    }

private:
    std::shared_ptr<Expression> m_left, m_right;
};

// “乘” 操作类
class Multiply : public Expression {
public:
    Multiply(std::shared_ptr<Expression> left, std::shared_ptr<Expression> right) {
        m_left = std::move(left);
        m_right = std::move(right);
    }

    double interpret(std::map<std::string, double> variables) override {
        return m_left->interpret(variables) * m_right->interpret(variables);
    }

private:
    std::shared_ptr<Expression> m_left, m_right;
};

// “除” 操作类
class Divide : public Expression {
public:
    Divide(std::shared_ptr<Expression> left, std::shared_ptr<Expression> right) {
        m_left = std::move(left);
        m_right = std::move(right);
    }

    double interpret(std::map<std::string, double> variables) override {
        return m_left->interpret(variables) / m_right->interpret(variables);
    }

private:
    std::shared_ptr<Expression> m_left, m_right;
};

// **********************************************************************


void interpreter_test() {
    std::map<std::string, double> variables{
            {"x", 2},
            {"y", 3},
            {"z", 4}
    };

    // (3 / x + y * z)
    std::shared_ptr<Expression> expression =
            std::make_shared<Add>(
                    std::make_shared<Divide>(
                            std::make_shared<Number>(3),
                            std::make_shared<Variable>("x")),
                    std::make_shared<Multiply>(
                            std::make_shared<Variable>("y"),
                            std::make_shared<Variable>("z")));

    double result = expression->interpret(variables);
    std::cout << "result: " << result << std::endl;
}


#endif //DESIGNPATTERNS_INTERPRETER_HPP
