#include "color.h"
#include "ray.h"
#include "vec3.h"
#include <iostream>
bool hit_sphere(const point3& center, double radius, const ray& r)
{
    vec3 oc = center - r.getOrigin();
    auto a = dot(r.getDirection(), r.getDirection());
    auto b = -2.0 * dot(r.getDirection(), oc);
    auto c = dot(oc, oc) - radius * radius;
    auto discriminant = b * b - 4*a*c;
    return discriminant >= 0;
}

color ray_color(const ray& r)
{
    if (hit_sphere(point3(0,0,-1), 0.5, r))
    {
        return color(1,0,0);
    }

    vec3 unit_direction = unit_vector(r.getDirection());
    auto a = 0.5*(unit_direction.y() + 1.0);
    return (1.0-a)*color(1.0, 1.0, 1.0) + a*color(0.5, 0.7, 1.0);
}

int main()
{
    const auto aspectRatio = 16.0 / 9.0;
    const int imageWidth = 400;
    int imageHeight = int(imageWidth / aspectRatio);
    imageHeight = (imageHeight < 1) ? 1 : imageHeight;

    auto focalLength = 1.0;
    auto viewportHeight = 2.0;
    auto viewportWidth = viewportHeight * (double(imageWidth) / double(imageHeight));
    auto cameraCenter = point3(0, 0, 0);

    auto viewportU = vec3(viewportWidth, 0, 0);
    auto viewportV = vec3(0, -viewportHeight, 0);

    auto pixelDeltaU = viewportU / imageWidth;
    auto pixelDeltaV = viewportV / imageHeight;

    auto viewportUpperLeft = cameraCenter - vec3(0, 0, focalLength) - viewportU / 2 - viewportV / 2;
    auto loc = viewportUpperLeft + 0.5 * (pixelDeltaU + pixelDeltaV);


    std::cout << "P3\n" << imageWidth << ' ' << imageHeight << "\n255\n";

    for (int j = 0; j < imageHeight; j++)
    {
        for (int i = 0; i < imageWidth; i++)
        {
            auto pixelCenter = loc + (i * pixelDeltaU) + (j * pixelDeltaV);
            auto rayDirection = pixelCenter - cameraCenter;
            ray r(cameraCenter, rayDirection);

            color pixelColor = ray_color(r);
            writeColor(std::cout, pixelColor);
        }
    }
}