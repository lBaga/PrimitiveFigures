#pragma once
#include "Shape.h"

namespace primitives
{
    class Square : public Shape
    {
    public:
        Square();
        Square(LONG x, LONG y, LONG s);
        Square(const CRect& rect);

        void setStartPoint(CPoint point);
        void setEndPoint(CPoint point);
        void setSize(LONG s);

        CPoint startPoint() const;
        LONG size() const;
    public:
        void draw(CDC* pDC, const RECT& rect) const override;

    private:
        CRect m_data;
    };
}