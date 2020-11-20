#pragma once

#include <windef.h>

class CDC;

namespace primitives
{
    class BaseShape
    {
    public:
        virtual ~BaseShape() = default;
        virtual void draw(CDC* pDC, const RECT& rect) const = 0;
    };
}

