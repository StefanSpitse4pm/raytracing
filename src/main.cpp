#include "color.h"
#include "ray.h"
#include "vec3.h"
#include <iostream>

color ray_color(const ray& r)
{
    return color(0, 0, 0);
}

int main()
{
    const auto aspectRatio = 16.0 / 9.0;
    const int imageWidth = 400;
    int imageHeight = int(imageWidth / aspectRatio);
    imageHeight = (imageHeight < 1) ? 1 : imageHeight;

    auto focalLenght = 1.0;
    auto viewportHeight = 2.0;
    auto viewportWidth = viewportHeight * (double(imageWidth) / double(imageHeight));
    auto cameraCenter = point3(0, 0, 0);

    auto viewportU = vec3(viewportWidth, 0, 0);
    auto viewportV = vec3(0, -viewportWidth, 0);

    auto pixelDeltaU = viewportU / imageWidth;
    auto pixelDeltaV = viewportV / imageHeight;

    auto viewportUpperLeft = cameraCenter - vec3(0, 0, focalLenght) - viewportU / 2 - viewportV / 2;
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