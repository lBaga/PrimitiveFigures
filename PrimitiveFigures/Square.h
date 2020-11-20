#pragma once
#include "Shape.h"

namespace primitives
{
    class Square : public Shape
    {
    public:
        Square();
        Square(LONG x, LONG y, LONG s);

        void setStartPoint(CPoint point);
        void setSize(LONG s);

        CPoint startPoint() const;
        LONG size() const;
        CRect rect() const;
    public:
        void draw(CDC* pDC, const RECT& rect) const override;

    private:
        CRect m_data;
    };
}