//
//  Util.h
//  ORB_SLAM2
//
//  Created by xhw on 11/3/16.
//
//

#ifndef Util_h
#define Util_h
#include <fstream>
#ifdef TEST
#include <opencv2/opencv.hpp>
#endif
#define DEBUG 1
#define ENABLE_BA 1  //是否Bundle Adjustment
#define ENABLE_LC 1  //是否LoopClosing
#define LOST_SENSOR 0 //丢失后是否使用传感器继续跟踪
//#define FUSE_SENSOR_ROT
//#define TEST_IMU_ONLY
#define CONSTANT_SIZE 1
//#define DO_NOT_SIGNAL_RESET
//#define TEST_GFTT

#if DEBUG
#ifdef ANDROID
#include <android/log.h>
#define LOG_TAG "SLAM"
#define LOG(...) __android_log_print(ANDROID_LOG_ERROR,LOG_TAG, __VA_ARGS__)
#else
#define LOG(format, ...) printf (format, ##__VA_ARGS__);printf("\n")
#endif//ANDROID
#else
#define LOG(...)
#endif//DEBUG

#ifdef ANDROID
#include <android/log.h>
#define LOG_TAG_D "SLAM"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG_D, __VA_ARGS__)
#else
#define LOGD(format, ...) printf (format, ##__VA_ARGS__);printf("\n")
#endif//ANDROID

#if DEBUG
#define TS(name) int64 t_##name = cv::getTickCount()
#define TE(name) LOG("TIMER_" #name ": %.2fms", \
1000.*((cv::getTickCount() - t_##name) / cv::getTickFrequency()))
#else
#define TS(name)
#define TE(name)
#endif

inline void Log2File(std::fstream &fs,const char* msg)
{
//    fs<<msg;
}


#define READ_MARKER 1
#define SAVE_MARKER 0

#define M_PI_3        1.0471975511966   /* pi/3             */
#define M_PI_5        0.62831853071796   /* pi/5            */
#define SQRT_2        1.4142135623730

//#define VOC_LEVLE 4

#ifdef TEST
inline void imshowAndSave(std::string name, const cv::Mat& m)
{
    cv::imshow(name, m);
    cv::imwrite("../../../Examples/Test/"+name + ".png", m);
    //cv::waitKey(25);
}
// Draw matches between two images
inline cv::Mat getMatchesImage(cv::Mat query, cv::Mat pattern, const std::vector<cv::KeyPoint>& queryKp, const std::vector<cv::KeyPoint>& trainKp, std::vector<cv::DMatch> matches, int maxMatchesDrawn)
{
    cv::Mat outImg;
    
    if (matches.size() > maxMatchesDrawn)
    {
        matches.resize(maxMatchesDrawn);
    }
    
    cv::drawMatches
    (
     query,
     queryKp,
     pattern,
     trainKp,
     matches,
     outImg,
     cv::Scalar(0,200,0,255),
     cv::Scalar::all(-1),
     std::vector<char>(),
     cv::DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS
     );
    
    return outImg;
}
#endif

#endif /* Util_h */
