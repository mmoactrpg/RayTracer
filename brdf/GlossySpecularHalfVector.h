//
// Created by 诸谦 on 15/12/29.
//

#ifndef RAYTRACER_HALFVECTORSPECULAR_H
#define RAYTRACER_HALFVECTORSPECULAR_H


#include "GlossySpecular.h"

class GlossySpecularHalfVector: public GlossySpecular{

public:
    virtual RGB f(const Intersection &sr, const Vector &wi, const Vector &wo);
};


#endif //RAYTRACER_HALFVECTORSPECULAR_H
