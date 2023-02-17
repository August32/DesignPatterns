//
// Created by DELL on 2023/1/13.
//

/*
 * Captures and externalizes an object's internal state so that it can be
 * restored later, all without violating encapsulation.
 *
 * 在不违背封装原则的前提下，捕获一个对象的内部状态，并在该对象之外保存这个状态，以便之后
 * 能够恢复对象为之前的状态。
 */

#ifndef DESIGNPATTERNS_MEMENTO_HPP
#define DESIGNPATTERNS_MEMENTO_HPP

#include <iostream>
#include <vector>


class InputTextSnapshot;

// 文本类
class InputText {
public:
    InputText() = default;

    ~InputText() = default;

    InputText(const InputText &) = delete;

    InputText &operator=(const InputText &) = delete;

public:
    std::string get_text() const {
        return m_text;
    }

    void append(const std::string &text) {
        m_text += text;
    }

    InputTextSnapshot create_snapshot() const;

    void restore_snapshot(const InputTextSnapshot &snapshot);

private:
    std::string m_text;
};

// 文本快照类
class InputTextSnapshot {
public:
    explicit InputTextSnapshot(const InputText &input_text)
            : m_text(input_text.get_text()) {}

    ~InputTextSnapshot() = default;

public:
    std::string get_text() const {
        return m_text;
    }

private:
    std::string m_text;
};

// **********************************************************************


// 文本类方法定义
InputTextSnapshot InputText::create_snapshot() const {
    return InputTextSnapshot(*this);
}

void InputText::restore_snapshot(const InputTextSnapshot &snapshot) {
    m_text = snapshot.get_text();
}

// **********************************************************************


[[noreturn]] void snapshot_text() {
    std::string string_temp;
    std::vector<InputTextSnapshot> snapshots;
    InputText input_text;

    while (true) {
        std::cout << ">>>";
        std::cin >> string_temp;

        if (string_temp == ":list") {  // 输出文本
            std::cout << input_text.get_text() << std::endl;
        } else if (string_temp == ":undo") {  // 使用快照进行回退
            if (snapshots.empty()) {
                std::cout << "Error: Snapshot does not exist!" << std::endl;
            } else {
                input_text.restore_snapshot(snapshots.back());
                snapshots.pop_back();
            }
        } else {  // 输入文本
            snapshots.emplace_back(InputTextSnapshot(input_text));
            input_text.append(string_temp);
        }
    }
}


#endif //DESIGNPATTERNS_MEMENTO_HPP
