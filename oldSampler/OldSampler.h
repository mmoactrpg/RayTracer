//
// Created by 诸谦 on 15/12/24.
//

#ifndef RAYTRACER_SAMPLER_H
#define RAYTRACER_SAMPLER_H
#include <vector>
#include "global.h"
#include "geometry.h"

using namespace std;
/**
 * 采样器基类
 */
class OldSampler {
public:
    static const int DEFAULT_SET_NUM;
protected:
    int mSampleNum;//采样点个数
    int mSetNum;//采样组个数
    vector<Point> mSamples; //采样点容器
    vector<Point> mSamplesDisk; //映射到disk的采样点
    vector<Vector> mSamplesHemi; //映射到半球的采样点
    int mJump; //跳转索引
    unsigned long mCount; //采样点索引

    bool mIsDiskMapped;
    bool mIsHemiMapped;

public:
    OldSampler( int _sampleNum, int _setNum=DEFAULT_SET_NUM);
    virtual void generateSamples()=0;//生成采样点
    Point sampleUnitSquare();//从单位平方中获得一个采样点
    Point sampleUnitDisk();  //从disk获得一个采样点
    Vector sampleHemi();  //从半球获得一个采样点
    void mapSamples2UnitDisk();
    void mapSamples2Hemisphere(const float& e);

    int getSampleNum() const;
    int getSetNum() const;

};


#endif //RAYTRACER_SAMPLER_H
