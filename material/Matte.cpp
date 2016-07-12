//
// Created by 诸谦 on 15/12/27.
//

#include "Matte.h"

#include <Scene.h>

Matte::Matte(const RGB& _albedo):
        mAmbientBrdf(_albedo),
        mDiffuseBrdf(_albedo){

}



RGB Matte::shade(const Intersection &sr){
    Point hitPoint=sr.ray(sr.distance);
    Vector wi;
    float pdf;
    VisibilityTester vt;
    RGB L(0,0,0);
    LightSample ls;
    unsigned long lignt_num=sr.scene.getLightNum();
    for(unsigned long i=0;i<lignt_num;++i){
        RGB l=sr.scene.getLight(i)->Sample_L(hitPoint,0,ls,&wi,&pdf,&vt);
        if(vt.Unoccluded(&sr.scene)) continue;
        double ndotl=Dot(sr.normal,wi);
        if(ndotl>0){
            L=L+l*ndotl;   //mDiffuseBrdf.f(sr,wi,wo)
        }
    }
    return L;
}

RGB Matte::areaLightShade(Intersection &sr) {
    return RGB(0,0,0);
}
