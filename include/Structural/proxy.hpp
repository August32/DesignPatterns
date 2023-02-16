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
        std::cout << "Play the video!" << std::endl;
    };
};

// 产品代理类
class VideoPlayerProxy : public IVideoPlayer {
public:
    explicit VideoPlayerProxy(int user_id)
        : m_user_id(user_id) {}

    ~VideoPlayerProxy() override = default;

    VideoPlayerProxy(const VideoPlayerProxy &) = delete;

    VideoPlayerProxy &operator=(const VideoPlayerProxy &) = delete;

public:
    void play_video() override {
        if (m_user_id > 10000) {  // not VIP
            std::cout << "Play a commercial!" << std::endl;  // 播放视频前先播放一段广告
        }

        video_player.play_video();
    };

private:
    VideoPlayer video_player;

    unsigned int m_user_id;
};

// **********************************************************************


void proxy_test() {
    VideoPlayerProxy video_player(1);

    video_player.play_video();
}


#endif //DESIGNPATTERNS_PROXY_HPP
