#include "pch.h"
#include "Triangle.h"

primitives::Triangle::Triangle()
{
    setType(ShapeType::Triangle);
}

primitives::Triangle::Triangle(const CPoint(&points)[3])
{
    m_data[0] = points[0];
    m_data[1] = points[1];
    m_data[2] = points[2];
    setType(ShapeType::Triangle);
}

primitives::Triangle::Triangle(CPoint point1, CPoint point2, CPoint point3)
{
    m_data[0] = point1;
    m_data[1] = point2;
    m_data[2] = point3;
    setType(ShapeType::Triangle);
}

void primitives::Triangle::setPoint1(CPoint point)
{
    m_data[0] = point;
}

void primitives::Triangle::setPoint2(CPoint point)
{
    m_data[1] = point;
}

void primitives::Triangle::setPoint3(CPoint point)
{
    m_data[2] = point;
}

void primitives::Triangle::setPoints(const CPoint(&points)[3])
{
    m_data[0] = points[0];
    m_data[1] = points[1];
    m_data[2] = points[2];
}

CPoint primitives::Triangle::point1() const
{
    return m_data[0];
}

CPoint primitives::Triangle::point2() const
{
    return m_data[1];
}

CPoint primitives::Triangle::point3() const
{
    return m_data[2];
}

void primitives::Triangle::draw(CDC* pDC, const RECT& rect) const
{
    CPen pen(PS_SOLID, thickness(), foregroundColor());
    pDC->SelectObject(pen);

    CBrush brush(PS_SOLID, backgroundColor());
    pDC->SelectObject(brush);

    LONG val_y1 = m_data[0].y;
    LONG val_y2 = m_data[1].y;
    LONG val_y3 = m_data[2].y;

    if (convert() == Convert::Y)
    {
        val_y1 = rect.bottom - val_y1;
        val_y2 = rect.bottom - val_y2;
        val_y3 = rect.bottom - val_y3;
    }

    POINT points[3]
    {
        {m_data[0].x, val_y1},
        {m_data[1].x, val_y2},
        {m_data[2].x, val_y3}
    };

    pDC->Polygon(points, 3);
}
