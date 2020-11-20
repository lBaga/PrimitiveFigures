#include "pch.h"
#include "Triangle.h"

primitives::Triangle::Triangle()
{
}

primitives::Triangle::Triangle(const CPoint(&points)[3])
{
    m_data[0] = points[0];
    m_data[1] = points[1];
    m_data[2] = points[2];
}

primitives::Triangle::Triangle(CPoint point1, CPoint point2, CPoint point3)
{
    m_data[0] = point1;
    m_data[1] = point2;
    m_data[2] = point3;
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

    POINT points[3]
    {
        {m_data[0].x, rect.bottom - m_data[0].y},
        {m_data[1].x, rect.bottom - m_data[1].y},
        {m_data[2].x, rect.bottom - m_data[2].y}
    };

    pDC->Polygon(points, 3);
}
