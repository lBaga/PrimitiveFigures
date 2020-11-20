#include "pch.h"
#include "Rectangle.h"

primitives::Rectangle::Rectangle()
{
}

primitives::Rectangle::Rectangle(LONG x, LONG y, LONG w, LONG h)
    : m_data(CRect(x, y, w, h))
{
}

primitives::Rectangle::Rectangle(const CRect& rect)
    : m_data(rect)
{
}

void primitives::Rectangle::setStartPoint(CPoint point)
{
    m_data.left = point.x;
    m_data.top = point.y;
}

void primitives::Rectangle::setEndPoint(CPoint point)
{
    m_data.right = point.x;
    m_data.bottom = point.y;
}

void primitives::Rectangle::setWidth(LONG w)
{
    m_data.right = m_data.left + w;
}

void primitives::Rectangle::setHeight(LONG h)
{
    m_data.bottom = m_data.top + h;
}

CPoint primitives::Rectangle::startPoint() const
{
    return CPoint(m_data.left, m_data.top);
}

LONG primitives::Rectangle::width() const
{
    return m_data.right;
}

LONG primitives::Rectangle::height() const
{
    return m_data.bottom;
}

CRect primitives::Rectangle::rect() const
{
    return m_data;
}

void primitives::Rectangle::draw(CDC* pDC, const RECT& rect) const
{
    CPen pen(PS_SOLID, thickness(), foregroundColor());
    pDC->SelectObject(pen);

    CBrush brush(PS_SOLID, backgroundColor());
    pDC->SelectObject(brush);

    RECT place {
        m_data.left + thickness(),
        m_data.top - thickness(),
        m_data.right - thickness(),
        m_data.bottom + thickness()
    };

    pDC->Rectangle(&place);
}
