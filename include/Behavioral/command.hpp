//
// Created by DELL on 2023/1/16.
//

/*
 * The command pattern encapsulates a request as an object, thereby
 * letting us parameterize other objects with different requests, queue or
 * log requests, and support undoable operations.
 *
 * 命令模式将请求（命令）封装为一个对象，这样可以使用不同的请求参数化其他对象（将不同的请求
 * 依赖注入到其他对象），并且能够支持请求（命令）的排队执行、记录日志、撤销等（附加控制）功能。
 */

#ifndef DESIGNPATTERNS_COMMAND_HPP
#define DESIGNPATTERNS_COMMAND_HPP

#include <iostream>
#include <vector>
#include <memory>
#include <string>


// 抽象命令类
class Command {
public:
    virtual ~Command() = default;

    virtual void execute() = 0;
};

// 具体命令类
class PrintCommand : public Command {
public:
    explicit PrintCommand(std::string message)
            : m_message(std::move(message)) {}

    void execute() override {
        std::cout << m_message << std::endl;
    }

private:
    std::string m_message;
};

// 命令队列类
class CommandQueue {
public:
    void add_command(const std::shared_ptr<Command> &command) {
        m_commands.push_back(command);
    }

    void execute_commands() {
        for (const auto &command : m_commands) {
            command->execute();
        }
        m_commands.clear();
    }

private:
    std::vector<std::shared_ptr<Command>> m_commands;
};

// **********************************************************************


void command_test() {
    CommandQueue queue;

    queue.add_command(std::make_shared<PrintCommand>("Hello, World!"));
    queue.add_command(std::make_shared<PrintCommand>("This is a command pattern example."));
    queue.execute_commands();
}


#endif //DESIGNPATTERNS_COMMAND_HPP
