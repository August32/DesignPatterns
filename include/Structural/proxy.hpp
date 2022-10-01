//
// Created by 12865 on 2022/10/1.
//

#ifndef DESIGNPATTERNS_PROXY_HPP
#define DESIGNPATTERNS_PROXY_HPP


// 产品抽象类
class IVideoPlayer {
public:
    virtual ~IVideoPlayer() = default;

    virtual void play_video() = 0;
};

// 产品原始类
class VideoPlayer : public IVideoPlayer {
public:
    VideoPlayer() = default;

    ~VideoPlayer() override = default;

    VideoPlayer(const VideoPlayer &) = delete;

    VideoPlayer &operator=(const VideoPlayer &) = delete;

public:
    void play_video() override {
        std::cout << "Play the video!" <<std::endl;
    };
};

// 产品代理类
class VedioPlayerProxy : public IVideoPlayer {
public:
    VedioPlayerProxy() = default;

    ~VedioPlayerProxy() override = default;

    VedioPlayerProxy(const VedioPlayerProxy &) = delete;

    VedioPlayerProxy &operator=(const VedioPlayerProxy &) = delete;

public:
    void play_video() override {
        std::cout << "Play a commercial!" <<std::endl;  // 播放视频前先播放一段广告

        viewer.play_video();
    };

private:
    VideoPlayer viewer;
};

// **********************************************************************


void proxy_test() {
    IVideoPlayer *viewer = new VedioPlayerProxy();

    viewer->play_video();

    delete viewer;
}


#endif //DESIGNPATTERNS_PROXY_HPP
