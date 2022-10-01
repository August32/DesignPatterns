//
// Created by 12865 on 2022/10/1.
//

#ifndef DESIGNPATTERNS_PROXY_HPP
#define DESIGNPATTERNS_PROXY_HPP


// 抽象产品类
class IViewer {
public:
    virtual ~IViewer() = default;

    virtual void show() = 0;
};

// 实际产品类
class Viewer : public IViewer {
public:
    Viewer() = default;

    ~Viewer() override = default;

    Viewer(const Viewer &) = delete;

    Viewer &operator=(const Viewer &) = delete;

public:
    void show() override {
        std::cout << "Real show!" <<std::endl;
    };
};

// 产品代理类
class ViewerProxy : public IViewer {
public:
    ViewerProxy() = default;

    ~ViewerProxy() override = default;

    ViewerProxy(const ViewerProxy &) = delete;

    ViewerProxy &operator=(const ViewerProxy &) = delete;

public:
    void show() override {
        std::cout << "Proxy show start!" <<std::endl;

        viewer.show();

        std::cout << "Proxy show end!" <<std::endl;
    };

private:
    Viewer viewer;
};

// **********************************************************************


void proxy_test() {
    IViewer *viewer = new ViewerProxy();

    viewer->show();

    delete viewer;
}


#endif //DESIGNPATTERNS_PROXY_HPP
