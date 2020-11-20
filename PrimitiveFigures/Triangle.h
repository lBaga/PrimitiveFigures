#pragma once
#include "Shape.h"

namespace primitives
{
    class Triangle : public Shape
    {
    public:
        Triangle();
        Triangle(const CPoint (&points)[3]);
        Triangle(CPoint point1, CPoint point2, CPoint point3);

        void setPoint1(CPoint point);
        void setPoint2(CPoint point);
        void setPoint3(CPoint point);
        void setPoints(const CPoint(&points)[3]);

        CPoint point1() const;
        CPoint point2() const;
        CPoint point3() const;

    public:
        void draw(CDC* pDC, const RECT& rect) const override;

    private:
        CPoint m_data[3];
    };
}
