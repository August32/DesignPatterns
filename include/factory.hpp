//
// Created by 12865 on 2022/7/24.
//

#ifndef DESIGNPATTERNS_FACTORY_HPP
#define DESIGNPATTERNS_FACTORY_HPP

#include <map>


/* 工厂模式：
 * 1.简单工厂
 * 2.工厂方法（* 1 *）
 * 3.抽象工厂（* 2 *）
 * 4.模板工厂
 */


// 共享类

// 抽象产品类
class IWaferFile {
public:
    virtual ~IWaferFile() = default;

    virtual int get_size_mm() = 0;  // 纯虚函数，使该类变为抽象类
};

// 具体产品类 - 1
class TwelveIncWaferFile : public IWaferFile {
public:
    int get_size_mm() override {
        std::cout << "12 Inc Wafer: " << m_size_mm << " mm" << std::endl;
        return m_size_mm;
    }

private:
    const int m_size_mm = 300;
};

// 具体产品类 - 2
class EightIncWaferFile : public IWaferFile {
public:
    int get_size_mm() override {
        std::cout << "8 Inc Wafer: " << m_size_mm << " mm" << std::endl;
        return m_size_mm;
    }

private:
    const int m_size_mm = 200;
};

// **********************************************************************


// 1.简单工厂

#if 0

// 简单工厂1：每次调用时创建新对象
class WaferFileEasyFactory {
private:
    WaferFileEasyFactory() = default;

    ~WaferFileEasyFactory() = default;

public:
    WaferFileEasyFactory(const WaferFileEasyFactory &) = delete;

    WaferFileEasyFactory &operator=(const WaferFileEasyFactory &) = delete;

public:
    static IWaferFile *create_wafer_file(int size_inc) {
        IWaferFile *wafer_file = nullptr;

        if (size_inc == 12) {
            wafer_file = new TwelveIncWaferFile();
        } else if (size_inc == 8) {
            wafer_file = new EightIncWaferFile();
        }

        return wafer_file;
    }
};

#else

// 简单工厂2：先创建好对象缓存，每次调用时直接取出使用，利用单例模式
class WaferFileEasyFactory {
private:
    WaferFileEasyFactory() = default;

    ~WaferFileEasyFactory() = default;

public:
    WaferFileEasyFactory(const WaferFileEasyFactory &) = delete;

    WaferFileEasyFactory &operator=(const WaferFileEasyFactory &) = delete;

private:
    static std::map<int, IWaferFile *> m_cached_wafer_file;
    static IWaferFile *m_twelve_inc_wafer_file;
    static IWaferFile *m_eight_inc_wafer_file;

public:
    static IWaferFile *create_wafer_file(int size_inc) {
        IWaferFile *wafer_file = nullptr;

        if (m_cached_wafer_file.find(size_inc) != m_cached_wafer_file.end()) {
            wafer_file = m_cached_wafer_file[size_inc];
        }

        return wafer_file;
    }

    static void delete_instance() {
        delete m_twelve_inc_wafer_file;
        m_twelve_inc_wafer_file = nullptr;

        delete m_eight_inc_wafer_file;
        m_eight_inc_wafer_file = nullptr;
    }
};

IWaferFile *WaferFileEasyFactory::m_twelve_inc_wafer_file = new TwelveIncWaferFile();

IWaferFile *WaferFileEasyFactory::m_eight_inc_wafer_file = new EightIncWaferFile();

std::map<int, IWaferFile *> WaferFileEasyFactory::m_cached_wafer_file = {
        {12, m_twelve_inc_wafer_file},
        {8,  m_eight_inc_wafer_file}
};

#endif

// **********************************************************************


// 2.工厂方法：先创建具体工厂，再通过具体工厂去创建具体产品，利用多态的特性

// 抽象工厂类
class IWaferFileFactory {
public:
    virtual ~IWaferFileFactory() = default;

    virtual IWaferFile *create_wafer_file() = 0;  // 纯虚函数，使该类变为抽象类
};

// 具体工厂类 - 1
class TwelveIncWaferFileFactory : public IWaferFileFactory {
public:
    IWaferFile *create_wafer_file() override {
        return new TwelveIncWaferFile();
    };
};

// 具体工厂类 - 2
class EightIncWaferFileFactory : public IWaferFileFactory {
public:
    IWaferFile *create_wafer_file() override {
        return new EightIncWaferFile();
    };
};

// **********************************************************************


// 共享类

// 抽象产品类
class IDesktop {};
class ILaptop {};

// 具体产品类 - 1
class DELLDesktop : public IDesktop {};
class DELLLaptop : public ILaptop {};

// 具体产品类 - 2
class HuaweiDesktop : public IDesktop {};
class HuaweiLaptop : public ILaptop {};

// **********************************************************************


// 3.抽象工厂：工厂可以生产各种产品，能够满足双分类的需求

// 抽象工厂类（总厂）
class IComputerFactory {
public:
    virtual ~IComputerFactory() = default;

    virtual IDesktop *create_desktop() = 0;
    
    virtual ILaptop *create_laptop() = 0;
};

// 具体工厂类 - 1
class DELLFactory : public IComputerFactory {
public:
     IDesktop *create_desktop() override {
         return new DELLDesktop();
     };

     ILaptop *create_laptop() override {
         return new DELLLaptop();
     };
};

// 具体工厂类 - 2
class HuaweiFactory : public IComputerFactory {
public:
    IDesktop *create_desktop() override {
        return new HuaweiDesktop();
    };

    ILaptop *create_laptop() override {
        return new HuaweiLaptop();
    };
};

// **********************************************************************


// 4.模板工厂

// 抽象模板工厂类
template <class AbstractProduct_t>
class AbstractFactory {
public:
    virtual ~AbstractFactory() = default;

    virtual AbstractProduct_t *create_product() = 0;
};

// 具体模板工厂类
template <class AbstractProduct_t, class ConcreteProduct_t>
class ConcreteFactory : public AbstractFactory<AbstractProduct_t> {
public:
    AbstractProduct_t *create_product() override {
        return new ConcreteProduct_t();
    }
};

// **********************************************************************


// 注：合理利用 “简单工厂2” 的缓存机制（单例模式），可以在初始化时建立所有缓存，也可以通过注册的方式按需添加


// TODO: 依赖注入容器（DI）


#endif //DESIGNPATTERNS_FACTORY_HPP
