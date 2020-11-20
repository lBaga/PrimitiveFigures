#include "pch.h"
#include "Square.h"

primitives::Square::Square()
{
}

primitives::Square::Square(LONG x, LONG y, LONG s)
    : m_data(CRect(x, y, s, s))
{
}

void primitives::Square::setStartPoint(CPoint point)
{
    m_data.left = point.x;
    m_data.top = point.y;
}

void primitives::Square::setSize(LONG s)
{
    m_data.right = s;
    m_data.bottom = s;
}


CPoint primitives::Square::startPoint() const
{
    return CPoint(m_data.left, m_data.top);
}

LONG primitives::Square::size() const
{
    return m_data.right;
}

CRect primitives::Square::rect() const
{
    return m_data;
}

void primitives::Square::draw(CDC* pDC, const RECT& rect) const
{
    CPen pen(PS_SOLID, thickness(), foregroundColor());
    pDC->SelectObject(pen);

    CBrush brush(PS_SOLID, backgroundColor());
    pDC->SelectObject(brush);

    RECT place{
        m_data.left + thickness(),
        rect.bottom - m_data.top - thickness(),
        m_data.left + m_data.right - thickness(),
        rect.bottom - m_data.top - m_data.bottom + thickness()
    };

    pDC->Rectangle(&place);
}
