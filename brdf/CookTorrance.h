//
// Created by 诸谦 on 16/1/19.
//

#ifndef RAYTRACER_COOKTORRANCE_H
#define RAYTRACER_COOKTORRANCE_H


#include "BRDF.h"

class CookTorrance : public BRDF{
private :
    RGB mCSpecular;//入射光线在法线位置时候的光线反射强度
    float mScaleFactor;
    double mM;//光滑因子

    double _NDF(const Vector & N, const Vector & H);//法线分布函数
    double _G(const Vector & N, const Vector & H, const Vector & wi, const Vector & wo);//几何衰减因子
    RGB _Fresnel(const Vector & wo, const Vector & H);
public:


    CookTorrance(const RGB &mF0=RGB(1, 1, 1), double mM=1.0, float mScaleFactor=1.0);

    virtual RGB f(const Intersection &sr, const Vector &wi, const Vector &wo);

    virtual RGB rho(const Intersection &sr, const Vector &wo);

    void scale(float _f);
    void setSpecularColor(const RGB& _cs);
    void setGlossy(const double m);//设置光滑度
};


#endif //RAYTRACER_COOKTORRANCE_H
