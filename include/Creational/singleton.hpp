//
// Created by 12865 on 2022/7/24.
//

#ifndef DESIGNPATTERNS_SINGLETON_HPP
#define DESIGNPATTERNS_SINGLETON_HPP

#include <mutex>
#include <thread>


/* 单例模式：
 * 1.饿汉式
 * 2.懒汉式
 */


// 1.饿汉式：在类加载的时候就初始化单例，不支持延时加载

class SingletonHungry {
private:
    SingletonHungry() {
        m_no = 0;
    };

    ~SingletonHungry() = default;

    SingletonHungry(SingletonHungry &&) = default;

    SingletonHungry &operator=(SingletonHungry &&) = default;

public:
    SingletonHungry(const SingletonHungry &) = delete;

    SingletonHungry &operator=(const SingletonHungry &) = delete;

private:
    static SingletonHungry m_instance;
    int m_no;

public:
    static SingletonHungry &get_instance() {
        return m_instance;
    }

    int get_no() const {
        std::cout << this << std::endl;

        return m_no;
    }
};

SingletonHungry SingletonHungry::m_instance = SingletonHungry();  // 里面只有声明，要在外面定义

// **********************************************************************


// 2.懒汉式

#if 0

// 懒汉式1：第一次调用函数时才初始化单例，支持延迟加载，但需要加锁来保证多线程安全
// 直接加锁会导致并发度低，使用双重检测可以解决
std::mutex lazy_mutex;

class SingletonLazy {
private:
    SingletonLazy() {
        m_no = 0;
    };

    ~SingletonLazy() = default;

    SingletonLazy(SingletonLazy &&) = default;

    SingletonLazy &operator=(SingletonLazy &&) = default;

public:
    SingletonLazy(const SingletonLazy &) = delete;

    SingletonLazy &operator=(const SingletonLazy &) = delete;

private:
    static SingletonLazy *m_instance;

    int m_no;

public:
    static SingletonLazy *get_instance() {
        // 双重检测加锁
        if (m_instance == nullptr) {
            std::unique_lock<std::mutex> lock(lazy_mutex);
            if (m_instance == nullptr) {
                m_instance = new SingletonLazy;
            }
        }

        return m_instance;
    }

    static void delete_instance() {
        delete m_instance;
        m_instance = nullptr;
    }

    void set_no(int no) {
        m_no = no;
    }

    int get_no() const {
        return m_no;
    }
};

SingletonLazy *SingletonLazy::m_instance = nullptr;

#else

// 懒汉式2：使用局部静态变量，支持延迟加载，且多线程安全
class SingletonLazy {
private:
    SingletonLazy() {
        m_no = 0;
    };

    ~SingletonLazy() = default;

    SingletonLazy(SingletonLazy &&) = default;

    SingletonLazy &operator=(SingletonLazy &&) = default;

public:
    SingletonLazy(const SingletonLazy &) = delete;

    SingletonLazy &operator=(const SingletonLazy &) = delete;

private:
    int m_no;

public:
    static SingletonLazy &get_instance() {
        static SingletonLazy instance = SingletonLazy();  // 局部静态变量，注意生命周期

        return instance;
    }

    int get_no() const {
        std::cout << this << std::endl;

        return m_no;
    }
};

#endif

// **********************************************************************


// 单例模式测试
class SingletonTest {
private:
    SingletonTest() = default;

    ~SingletonTest() = default;

public:
    SingletonTest(const SingletonTest &) = delete;

    SingletonTest &operator=(const SingletonTest &) = delete;

private:
    static void singleton_task(bool mode) {
        if (mode) {
            SingletonHungry &instance = SingletonHungry::get_instance();

            instance.get_no();
        } else {  // !mode
            SingletonLazy &instance = SingletonLazy::get_instance();

            instance.get_no();
        }
    }

public:
    static void hungry_test() {
        std::thread t1(singleton_task, true);
        std::thread t2(singleton_task, true);
        std::thread t3(singleton_task, true);
        std::thread t4(singleton_task, true);
        std::thread t5(singleton_task, true);

        t1.join();
        t2.join();
        t3.join();
        t4.join();
        t5.join();
    }

    static void lazy_test() {
        std::thread t1(singleton_task, false);
        std::thread t2(singleton_task, false);
        std::thread t3(singleton_task, false);
        std::thread t4(singleton_task, false);
        std::thread t5(singleton_task, false);

        t1.join();
        t2.join();
        t3.join();
        t4.join();
        t5.join();
    }
};


#endif //DESIGNPATTERNS_SINGLETON_HPP
