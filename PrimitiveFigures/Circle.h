#pragma once
#include "Shape.h"

namespace primitives
{
    class Circle : public Shape
    {
    public:
        Circle();
        Circle(LONG x, LONG y, LONG r);
        Circle(CPoint point, LONG r);

        void setStartPoint(CPoint point);
        void setRadius(LONG r);

        CPoint startPoint() const;
        LONG radius() const;

    public:
        void draw(CDC* pDC, const RECT& rect) const override;

    private:
        CPoint m_center;
        LONG m_radius;
    };
}

