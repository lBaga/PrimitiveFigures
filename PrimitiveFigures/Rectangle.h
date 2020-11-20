#pragma once
#include "Shape.h"

namespace primitives
{
    class Rectangle : public Shape
    {
    public:
        Rectangle();
        Rectangle(int x, int y, int w, int h);
        Rectangle(const CRect& rect);

    public:
        void draw(CDC* pDC, const RECT& rect) const override;

    private:
        CRect m_data;
    };
}

