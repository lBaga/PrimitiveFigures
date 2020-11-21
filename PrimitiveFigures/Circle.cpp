#include "pch.h"
#include "Circle.h"

primitives::Circle::Circle()
    : m_center(CPoint())
    ,m_radius(0)
{
    setType(ShapeType::Circle);
}

primitives::Circle::Circle(LONG x, LONG y, LONG r)
    : m_center(CPoint(x, y))
    , m_radius(r)
{
    setType(ShapeType::Circle);
}

primitives::Circle::Circle(CPoint point, LONG r)
    : m_center(point)
    , m_radius(r)
{
    setType(ShapeType::Circle);
}

void primitives::Circle::setStartPoint(CPoint point)
{
    m_center = point;
}

void primitives::Circle::setRadius(LONG r)
{
    m_radius = r;
}

CPoint primitives::Circle::startPoint() const
{
    return m_center;
}

LONG primitives::Circle::radius() const
{
    return m_radius;
}

void primitives::Circle::draw(CDC* pDC, const RECT& rect) const
{
    CPen pen(PS_SOLID, thickness(), foregroundColor());
    pDC->SelectObject(pen);

    CBrush brush(PS_SOLID, backgroundColor());
    pDC->SelectObject(brush);

    LONG val_y = m_center.y;
    if (convert() == Convert::Y)
    {
        val_y = rect.bottom - val_y;
    }

    RECT place {
        m_center.x - m_radius,
        val_y - m_radius,
        m_center.x + m_radius,
        val_y + m_radius
    };

    pDC->Ellipse(&place);
}
