#pragma once

#include <windef.h>

class CDC;

namespace primitives
{
    enum class ShapeType { None, Circle, Rectangle, Square, Triangle};

    class BaseShape
    {
    public:
        virtual ~BaseShape() = default;
        virtual void draw(CDC* pDC, const RECT& rect) const = 0;
    };
}

