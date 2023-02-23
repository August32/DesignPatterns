//
// Created by 12865 on 2022/10/3.
//

#ifndef DESIGNPATTERNS_DECORATOR_HPP
#define DESIGNPATTERNS_DECORATOR_HPP


// 产品抽象类
class IImageViewer {
public:
    virtual ~IImageViewer() = default;

    virtual void show_image() = 0;
};

// 产品原始类
class ImageViewer : public IImageViewer {
public:
    ImageViewer() = default;

    ~ImageViewer() override = default;

public:
    void show_image() override {
        std::cout << "Show the image!" << std::endl;
    };
};

// 产品装饰器类 - 1
class ImageViewerDecorator1 : public IImageViewer {
public:
    explicit ImageViewerDecorator1(IImageViewer *image_viewer)
            : m_image_viewer(image_viewer) {};

    ~ImageViewerDecorator1() override = default;

public:
    void show_image() override {
        if (m_image_viewer != nullptr) {
            std::cout << "Gaussian filtering!" << std::endl;  // 展示图像前先做一次高斯滤波

            m_image_viewer->show_image();
        }
    };

private:
    IImageViewer *m_image_viewer;
};

// 产品装饰器类 - 2
class ImageViewerDecorator2 : public IImageViewer {
public:
    explicit ImageViewerDecorator2(IImageViewer *image_viewer)
            : m_image_viewer(image_viewer) {};

    ~ImageViewerDecorator2() override = default;

public:
    void show_image() override {
        if (m_image_viewer != nullptr) {
            std::cout << "Improve the brightness!" << std::endl;  // 展示图像前先提升图像的亮度

            m_image_viewer->show_image();
        }
    };

private:
    IImageViewer *m_image_viewer;
};

// **********************************************************************


void decorator_test() {
    IImageViewer *image_viewer_origin = new ImageViewer();

    // 第一层装饰器
    IImageViewer *imgae_viewer_decorator1 = new ImageViewerDecorator1(image_viewer_origin);

    // 第二层装饰器
    IImageViewer *imgae_viewer_decorator2 = new ImageViewerDecorator2(imgae_viewer_decorator1);

    imgae_viewer_decorator2->show_image();

    delete imgae_viewer_decorator2;
    delete imgae_viewer_decorator1;
    delete image_viewer_origin;
}


#endif //DESIGNPATTERNS_DECORATOR_HPP
