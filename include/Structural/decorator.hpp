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

    ImageViewer(const ImageViewer &) = delete;

    ImageViewer &operator=(const ImageViewer &) = delete;

public:
    void show_image() override {
        std::cout << "Show the image!" << std::endl;
    };
};

// 产品装饰器类
class ImageViewerDecorator : public IImageViewer {
public:
    explicit ImageViewerDecorator(IImageViewer *image_viewer)
            : m_image_viewer(image_viewer) {};

    ~ImageViewerDecorator() override = default;

    ImageViewerDecorator(const ImageViewerDecorator &) = delete;

    ImageViewerDecorator &operator=(const ImageViewerDecorator &) = delete;

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

// **********************************************************************


void decorator_test() {
    IImageViewer *image_viewer_origin = new ImageViewer();

    IImageViewer *imgae_viewer_decorator = new ImageViewerDecorator(image_viewer_origin);

    imgae_viewer_decorator->show_image();

    delete imgae_viewer_decorator;
    delete image_viewer_origin;
}


#endif //DESIGNPATTERNS_DECORATOR_HPP
