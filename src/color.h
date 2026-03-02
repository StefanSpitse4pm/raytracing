//
// Created by stefanspitse on 3/2/26.
//

#ifndef RAYTRACING_COLOR_H
#define RAYTRACING_COLOR_H
#include "vec3.h"

using color = vec3;

void writeColor(std::ostream& out, const color& pixelColor)
{
    auto r = pixelColor.x();
    auto g = pixelColor.y();
    auto b = pixelColor.z();

    int redByte = static_cast<int>(255.99 * r);
    int greenByte = static_cast<int>(255.99 * g);
    int blueByte = static_cast<int>(255.99 * b);

    out << redByte << ' ' << greenByte << ' ' << blueByte << '\n';
}

#endif // RAYTRACING_COLOR_H


