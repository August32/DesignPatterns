//
// Created by 12865 on 2022/8/23.
//

#ifndef DESIGNPATTERNS_BUILDER_HPP
#define DESIGNPATTERNS_BUILDER_HPP

#include <iostream>
#include <string>
#include <utility>
#include <memory>
#include <cassert>


// 产品类
class Car {
public:
    Car() {
        m_wheel_size = 0;
        m_shell_length = 0;
    };

    ~Car() = default;

    Car(const Car &) = delete;

    Car &operator=(const Car &) = delete;

public:
    void set_interior(const std::string &interior) {
        m_interior = interior;
    }

    void set_wheel_size(int wheel_size) {
        m_wheel_size = wheel_size;
    }

    void set_shell_length(int shell_length) {
        m_shell_length = shell_length;
    }

    std::string get_interior() {
        return m_interior;
    }

    int get_wheel_size() const {
        return m_wheel_size;
    }

    int get_shell_length() const {
        return m_shell_length;
    }

private:
    std::string m_interior;
    int m_wheel_size;
    int m_shell_length;
};

#if 0

// 抽象产品建造者类
class ICarBuilder {
public:
    virtual ~ICarBuilder() = default;

    virtual ICarBuilder *build_car_interior() = 0;

    virtual ICarBuilder *build_car_wheel() = 0;  // 车轮

    virtual ICarBuilder *build_car_shell() = 0;  // 外壳

    virtual Car *get_car() = 0;

    virtual void delete_car() = 0;
};

// 具体产品建造者类 - 1
class CarABuilder : public ICarBuilder {
public:
    CarABuilder() {
        m_car = new Car();
    }

public:
    ICarBuilder *build_car_interior() override {
        m_car->set_interior("A interior");

        return this;
    };

    ICarBuilder *build_car_wheel() override {
        m_car->set_wheel_size(8);

        return this;
    }

    ICarBuilder *build_car_shell() override {
        m_car->set_shell_length(50);

        return this;
    }

    Car *get_car() override {
        return m_car;
    };

    void delete_car() override {
        delete m_car;
        m_car = nullptr;
    }

private:
    Car *m_car;
};

// 具体产品建造者类 - 2
class CarBBuilder : public ICarBuilder {
public:
    CarBBuilder() {
        m_car = new Car();
    }

public:
    ICarBuilder *build_car_interior() override {
        m_car->set_interior("B interior");

        return this;
    };

    ICarBuilder *build_car_wheel() override {
        m_car->set_wheel_size(9);

        return this;
    }

    ICarBuilder *build_car_shell() override {
        m_car->set_shell_length(56);

        return this;
    }

    Car *get_car() override {
        return m_car;
    };

    void delete_car() override {
        delete m_car;
        m_car = nullptr;
    }

private:
    Car *m_car;
};

// 具体产品建造者类 - 3
class CarCBuilder : public ICarBuilder {
public:
    CarCBuilder() {
        m_car = new Car();
    }

public:
    ICarBuilder *build_car_interior() override {
        m_car->set_interior("C interior");

        return this;
    };

    ICarBuilder *build_car_wheel() override {
        m_car->set_wheel_size(10);

        return this;
    }

    ICarBuilder *build_car_shell() override {
        m_car->set_shell_length(58);

        return this;
    }

    Car *get_car() override {
        return m_car;
    };

    void delete_car() override {
        delete m_car;
        m_car = nullptr;
    }

private:
    Car *m_car;
};

// 产品指挥者类：负责执行建造过程
class CarDirector {
public:
    explicit CarDirector(ICarBuilder *car_builder) {
        m_car_builder = car_builder;
    }

    ~CarDirector() = default;

public:
    Car *build_logic() {
        m_car_builder->build_car_interior()
                ->build_car_wheel()
                ->build_car_shell();

        if (m_car_builder->get_car()->get_wheel_size() > m_car_builder->get_car()->get_shell_length() / 6.0) {
            std::cout << "Error: wheel too big or shell too small!" << std::endl;
            m_car_builder->delete_car();
        }

        return m_car_builder->get_car();
    }

private:
    ICarBuilder *m_car_builder;
};

// **********************************************************************


void builder_test(bool result) {
    ICarBuilder *car_builder = nullptr;

    if (result) {
        car_builder = new CarBBuilder();
    }
    else {
        car_builder = new CarCBuilder();
    }

    CarDirector car_director(car_builder);
    Car *car = car_director.build_logic();

    if (car == nullptr) {
        delete car_builder;
        return;
    }

    std::cout << "Car interior is " << car->get_interior() << std::endl;
    std::cout << "Car wheel size is " << car->get_wheel_size() << std::endl;
    std::cout << "Car shell length is " << car->get_shell_length() << std::endl;

    delete car;
    delete car_builder;
}

#else

// 产品配置基类
class CarConfig {
public:
    CarConfig() = default;

    ~CarConfig() = default;

    CarConfig(const CarConfig &) = delete;

    CarConfig &operator=(const CarConfig &) = delete;

public:
    std::string get_interior() {
        return m_interior;
    };

    int get_wheel_size() const {
        return m_wheel_size;
    };

    int get_shell_length() const {
        return m_shell_length;
    };

protected:
    std::string m_interior;
    int m_wheel_size{};
    int m_shell_length{};
};

// 具体产品配置类 - 1
class CarAConfig : public CarConfig {
public:
    CarAConfig() {
        m_interior = "A interior";
        m_wheel_size = 8;
        m_shell_length = 50;
    };

    ~CarAConfig() = default;

    CarAConfig(const CarAConfig &) = delete;

    CarAConfig &operator=(const CarAConfig &) = delete;
};

// 具体产品配置类 - 2
class CarBConfig : public CarConfig {
public:
    CarBConfig() {
        m_interior = "B interior";
        m_wheel_size = 9;
        m_shell_length = 56;
    };

    ~CarBConfig() = default;

    CarBConfig(const CarBConfig &) = delete;

    CarBConfig &operator=(const CarBConfig &) = delete;
};

// 具体产品配置类 - 3
class CarCConfig : public CarConfig {
public:
    CarCConfig() {
        m_interior = "C interior";
        m_wheel_size = 10;
        m_shell_length = 58;
    };

    ~CarCConfig() = default;

    CarCConfig(const CarCConfig &) = delete;

    CarCConfig &operator=(const CarCConfig &) = delete;
};

#if 1

// 产品建造者类
class CarBuilder {
public:
    explicit CarBuilder(CarConfig *car_config) {
        m_car = nullptr;
        m_car_config = car_config;
    }

    ~CarBuilder() = default;

    CarBuilder(const CarBuilder &) = delete;

    CarBuilder &operator=(const CarBuilder &) = delete;

private:
    CarBuilder *build_car_interior() {
        m_car->set_interior(m_car_config->get_interior());

        return this;
    };

    CarBuilder *build_car_wheel() {
        m_car->set_wheel_size(m_car_config->get_wheel_size());

        return this;
    }

    CarBuilder *build_car_shell() {
        m_car->set_shell_length(m_car_config->get_shell_length());

        return this;
    }

public:
    Car *build_logic() {
        m_car = new Car();

        this->build_car_interior()
                ->build_car_wheel()
                ->build_car_shell();

        if (m_car->get_wheel_size() > m_car->get_shell_length() / 6.0) {
            std::cout << "Error: wheel too big or shell too small!" << std::endl;
            delete m_car;
            m_car = nullptr;
        }

        return m_car;
    }

private:
    Car *m_car;
    CarConfig *m_car_config;
};

// **********************************************************************


void builder_test(bool result) {
    CarConfig *car_config = nullptr;

    if (result) {
        car_config = new CarBConfig();
    } else {
        car_config = new CarCConfig();
    }

    CarBuilder car_builder(car_config);
    Car *car = car_builder.build_logic();

    if (car == nullptr) {
        delete car_config;
        return;
    }

    std::cout << "Car interior is " << car->get_interior() << std::endl;
    std::cout << "Car wheel size is " << car->get_wheel_size() << std::endl;
    std::cout << "Car shell length is " << car->get_shell_length() << std::endl;

    delete car;
    delete car_config;
}

#else  // unique_ptr

class CarBuilderSmart {
public:
    explicit CarBuilderSmart(std::unique_ptr<CarConfig> car_config) {
        m_car = std::unique_ptr<Car>(nullptr);
        m_car_config = std::move(car_config);
    }

    ~CarBuilderSmart() = default;

    CarBuilderSmart(const CarBuilderSmart &) = delete;

    CarBuilderSmart &operator=(const CarBuilderSmart &) = delete;

private:
    CarBuilderSmart *build_car_interior() {
        m_car->set_interior(m_car_config->get_interior());

        return this;
    };

    CarBuilderSmart *build_car_wheel() {
        m_car->set_wheel_size(m_car_config->get_wheel_size());

        return this;
    }

    CarBuilderSmart *build_car_shell() {
        m_car->set_shell_length(m_car_config->get_shell_length());

        return this;
    }

public:
    std::unique_ptr<Car> build_logic() {
        m_car = std::make_unique<Car>();

        this->build_car_interior()
                ->build_car_wheel()
                ->build_car_shell();

        if (m_car->get_wheel_size() > m_car->get_shell_length() / 6.0) {
            std::cout << "Error: wheel too big or shell too small!" << std::endl;
            return std::move(std::unique_ptr<Car>(nullptr));
        }

        return std::move(m_car);
    }

private:
    std::unique_ptr<Car> m_car;
    std::unique_ptr<CarConfig> m_car_config;
};

// **********************************************************************


void builder_test_smart(bool result) {
    std::unique_ptr<CarConfig> car_config(nullptr);

    if (result) {
        car_config = std::make_unique<CarBConfig>();
    } else {
        car_config = std::make_unique<CarCConfig>();
    }

    CarBuilderSmart car_builder(std::move(car_config));
    std::unique_ptr<Car> car = car_builder.build_logic();

    if (car == nullptr) {
        return;
    }

    std::cout << "Car interior is " << car->get_interior() << std::endl;
    std::cout << "Car wheel size is " << car->get_wheel_size() << std::endl;
    std::cout << "Car shell length is " << car->get_shell_length() << std::endl;
}

#endif

#endif


#endif //DESIGNPATTERNS_BUILDER_HPP
