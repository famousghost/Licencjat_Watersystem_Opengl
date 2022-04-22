#pragma once
#include <glad.h>

enum class VaoType : unsigned int
{
    VAO_STANDARD = 0,
    VAO_PICTURE = 1,
    VAO_WATER = 2,
};

struct VerticiesCoords
{
    float xVert;
    float yVert;
    float zVert;
};

struct TextCoords
{
    float textCorX;
    float textCorY;
};

struct NormalCoords
{
    float nCorX;
    float nCorY;
    float nCorZ;
};
