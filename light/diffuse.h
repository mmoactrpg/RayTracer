/*
 * diffuse.h
 *
 *  Created on: 2016年7月26日
 *      Author: Administrator
 */

#ifndef LIGHT_DIFFUSE_H_
#define LIGHT_DIFFUSE_H_
#include "global.h"
#include "light.h"

//漫反射区域光

class DiffuseAreaLight: public AreaLight {
private:
	RGB mLemit; //自发光
	Reference<Shape> mShape; //光源形状
	float mArea;
public:
	DiffuseAreaLight(const Transform& l2w, const RGB& le, int ns,
			const Reference<Shape> shape) :
			AreaLight(l2w, ns) {
		mLemit = le;
		mShape = shape;
		mArea = mShape->Area();
	}

	virtual RGB L(const Point &p, const Normal &n, const Vector &w) const
			override {
		return Dot(n, w) > 0.f ? mLemit : RGB(0.0f,0.0f,0.0f);
	}
	virtual RGB Power(const Scene* scene) const override {
		return mLemit * mArea * M_PI;
	}
	virtual RGB Sample_L(const Point &p, float pEpsilon, const LightSample &ls,
			Vector *wi, float *pdf, VisibilityTester *vis) const override {
		Normal nn;
		Point pLight=mShape->Sample(p,ls.uPos[0],ls.uPos[1],&nn);
		*wi=Normalize(pLight-p);//得到p点到光源的射线
		*pdf=mShape->Pdf(p,*wi);
		vis->SetSegment(p,pEpsilon,pLight,1e-3f);
		return L(pLight,nn,-*wi);//-*wi是从光源往外射的方向
	}

	virtual bool IsDeltaLight() const override {
		return false;
	}

	virtual float Pdf(const Point &p, const Vector &wi) const override{
		return mShape->Pdf(p,wi);
	}
};

#endif /* LIGHT_DIFFUSE_H_ */
