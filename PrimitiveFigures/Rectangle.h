#pragma once
#include "Shape.h"

namespace primitives
{
    class Rectangle : public Shape
    {
    public:
        Rectangle();
        Rectangle(LONG x, LONG y, LONG w, LONG h);
        Rectangle(const CRect& rect);

        void setStartPoint(CPoint point);
        void setEndPoint(CPoint point);
        void setWidth(LONG w);
        void setHeight(LONG h);

        CPoint startPoint() const;
        LONG width() const;
        LONG height() const;
        CRect rect() const;
    public:
        void draw(CDC* pDC, const RECT& rect) const override;

    private:
        CRect m_data;
    };
}