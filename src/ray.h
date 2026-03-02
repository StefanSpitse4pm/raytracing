//
// Created by stefanspitse on 3/2/26.
//

#ifndef RAYTRACING_RAY_H
#define RAYTRACING_RAY_H
#include "vec3.h"

class ray
{
    public:
        ray(){}
        ray(const point3& origin, const vec3& direction) : origin(origin), direction(direction) {}
        [[nodiscard]] const point3& getOrigin() const { return origin; }
        [[nodiscard]] const point3& getDirection() const { return direction; }


    private:
        point3 origin;
        vec3 direction;
};


#endif // RAYTRACING_RAY_H
