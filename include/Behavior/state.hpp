//
// Created by DELL on 2023/1/5.
//

#ifndef DESIGNPATTERNS_STATE_HPP
#define DESIGNPATTERNS_STATE_HPP

#include <iostream>


enum MarioState {
    SMALL,
    SUPER,
    CAPE,
    FIRE
};

class MarioStateMachine;

// 马里奥抽象类
class IMario {
public:
    virtual ~IMario() = default;

    virtual MarioState get_name() = 0;

    virtual void obtain_mush_room(MarioStateMachine &state_machine) = 0;

    virtual void obtain_cape(MarioStateMachine &state_machine) = 0;

    virtual void obtain_fire_flower(MarioStateMachine &state_machine) = 0;

    virtual void meet_monster(MarioStateMachine &state_machine) = 0;
};

// 马里奥具体类 - SMALL
class SmallMario : public IMario {
private:
    SmallMario() = default;

public:
    MarioState get_name() override {
        return MarioState::SMALL;
    }

    void obtain_mush_room(MarioStateMachine &state_machine) override;

    void obtain_cape(MarioStateMachine &state_machine) override;

    void obtain_fire_flower(MarioStateMachine &state_machine) override;

    void meet_monster(MarioStateMachine &state_machine) override;

public:
    static SmallMario &get_instance() {
        static SmallMario instance = SmallMario();  // 局部静态变量，注意生命周期

        return instance;
    }
};

// 马里奥具体类 - SUPER
class SuperMario : public IMario {
private:
    SuperMario() = default;

public:
    MarioState get_name() override {
        return MarioState::SUPER;
    }

    void obtain_mush_room(MarioStateMachine &state_machine) override;

    void obtain_cape(MarioStateMachine &state_machine) override;

    void obtain_fire_flower(MarioStateMachine &state_machine) override;

    void meet_monster(MarioStateMachine &state_machine) override;

public:
    static SuperMario &get_instance() {
        static SuperMario instance = SuperMario();  // 局部静态变量，注意生命周期

        return instance;
    }
};

// 马里奥具体类 - CAPE
class CapeMario : public IMario {
private:
    CapeMario() = default;

public:
    MarioState get_name() override {
        return MarioState::CAPE;
    }

    void obtain_mush_room(MarioStateMachine &state_machine) override;

    void obtain_cape(MarioStateMachine &state_machine) override;

    void obtain_fire_flower(MarioStateMachine &state_machine) override;

    void meet_monster(MarioStateMachine &state_machine) override;

public:
    static CapeMario &get_instance() {
        static CapeMario instance = CapeMario();  // 局部静态变量，注意生命周期

        return instance;
    }
};

// 马里奥具体类 - FIRE
class FireMario : public IMario {
private:
    FireMario() = default;

public:
    MarioState get_name() override {
        return MarioState::FIRE;
    }

    void obtain_mush_room(MarioStateMachine &state_machine) override;

    void obtain_cape(MarioStateMachine &state_machine) override;

    void obtain_fire_flower(MarioStateMachine &state_machine) override;

    void meet_monster(MarioStateMachine &state_machine) override;

public:
    static FireMario &get_instance() {
        static FireMario instance = FireMario();  // 局部静态变量，注意生命周期

        return instance;
    }
};

// 马里奥状态机
class MarioStateMachine {
public:
    MarioStateMachine() {
        m_score = 0;
        m_current_state = &SmallMario::get_instance();
    };

    ~MarioStateMachine() = default;

public:
    void obtain_mush_room() {
        m_current_state->obtain_mush_room(*this);
    }

    void obtain_cape() {
        m_current_state->obtain_cape(*this);
    }

    void obtain_fire_flower() {
        m_current_state->obtain_fire_flower(*this);
    }

    void meet_monster() {
        m_current_state->meet_monster(*this);
    }

    int get_score() const {
        return m_score;
    }

    MarioState get_current_state() {
        return m_current_state->get_name();
    }

    void set_score(int score) {
        m_score = score;
    }

    void set_current_state(IMario *current_state) {
        m_current_state = current_state;
    }

private:
    int m_score;

    IMario *m_current_state;
};

// **********************************************************************


// SmallMario 函数实现
void SmallMario::obtain_mush_room(MarioStateMachine &state_machine) {
    state_machine.set_current_state(&SuperMario::get_instance());
    state_machine.set_score(state_machine.get_score() + 100);
}

void SmallMario::obtain_cape(MarioStateMachine &state_machine) {
    state_machine.set_current_state(&CapeMario::get_instance());
    state_machine.set_score(state_machine.get_score() + 200);
}

void SmallMario::obtain_fire_flower(MarioStateMachine &state_machine) {
    state_machine.set_current_state(&FireMario::get_instance());
    state_machine.set_score(state_machine.get_score() + 300);
}

void SmallMario::meet_monster(MarioStateMachine &state_machine) {
    state_machine.set_current_state(&SmallMario::get_instance());
    state_machine.set_score(0);
}

// SuperMario 函数实现
void SuperMario::obtain_mush_room(MarioStateMachine &state_machine) {
    state_machine.set_current_state(&SuperMario::get_instance());
    state_machine.set_score(state_machine.get_score() + 100);
}

void SuperMario::obtain_cape(MarioStateMachine &state_machine) {
    state_machine.set_current_state(&CapeMario::get_instance());
    state_machine.set_score(state_machine.get_score() + 200);
}

void SuperMario::obtain_fire_flower(MarioStateMachine &state_machine) {
    state_machine.set_current_state(&FireMario::get_instance());
    state_machine.set_score(state_machine.get_score() + 300);
}

void SuperMario::meet_monster(MarioStateMachine &state_machine) {
    state_machine.set_current_state(&SmallMario::get_instance());
    state_machine.set_score(0);
}

// CapeMario 函数实现
void CapeMario::obtain_mush_room(MarioStateMachine &state_machine) {
    state_machine.set_current_state(&SuperMario::get_instance());
    state_machine.set_score(state_machine.get_score() + 100);
}

void CapeMario::obtain_cape(MarioStateMachine &state_machine) {
    state_machine.set_current_state(&CapeMario::get_instance());
    state_machine.set_score(state_machine.get_score() + 200);
}

void CapeMario::obtain_fire_flower(MarioStateMachine &state_machine) {
    state_machine.set_current_state(&FireMario::get_instance());
    state_machine.set_score(state_machine.get_score() + 300);
}

void CapeMario::meet_monster(MarioStateMachine &state_machine) {
    state_machine.set_current_state(&SmallMario::get_instance());
    state_machine.set_score(0);
}

// FireMario 函数实现
void FireMario::obtain_mush_room(MarioStateMachine &state_machine) {
    state_machine.set_current_state(&SuperMario::get_instance());
    state_machine.set_score(state_machine.get_score() + 100);
}

void FireMario::obtain_cape(MarioStateMachine &state_machine) {
    state_machine.set_current_state(&CapeMario::get_instance());
    state_machine.set_score(state_machine.get_score() + 200);
}

void FireMario::obtain_fire_flower(MarioStateMachine &state_machine) {
    state_machine.set_current_state(&FireMario::get_instance());
    state_machine.set_score(state_machine.get_score() + 300);
}

void FireMario::meet_monster(MarioStateMachine &state_machine) {
    state_machine.set_current_state(&SmallMario::get_instance());
    state_machine.set_score(0);
}

// **********************************************************************


void output_state(MarioStateMachine &mario_state_machine) {
    std::cout << "state: " << mario_state_machine.get_current_state() << ", "
              << "score: " << mario_state_machine.get_score() << std::endl;
}

void state_test() {
    MarioStateMachine mario_state_machine;
    output_state(mario_state_machine);

    mario_state_machine.obtain_mush_room();
    output_state(mario_state_machine);

    mario_state_machine.obtain_cape();
    output_state(mario_state_machine);

    mario_state_machine.obtain_fire_flower();
    output_state(mario_state_machine);

    mario_state_machine.meet_monster();
    output_state(mario_state_machine);
}


#endif //DESIGNPATTERNS_STATE_HPP
