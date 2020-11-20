#include "pch.h"
#include "Rectangle.h"

primitives::Rectangle::Rectangle()
{
}

primitives::Rectangle::Rectangle(int x, int y, int w, int h)
    : m_data(CRect(x, y, w, h))
{
}

primitives::Rectangle::Rectangle(const CRect& rect)
    : m_data(rect)
{
}

void primitives::Rectangle::draw(CDC* pDC, const RECT& rect) const
{
    CPen pen(PS_SOLID, thickness(), foregroundColor());
    pDC->SelectObject(pen);

    CBrush brush(PS_SOLID, backgroundColor());
    pDC->SelectObject(brush);

    RECT place {
        m_data.left + thickness(),
        rect.bottom - m_data.top - thickness(),
        m_data.left + m_data.right - thickness(),
        rect.bottom - m_data.top - m_data.bottom + thickness()
    };

    pDC->Rectangle(&place);
}
