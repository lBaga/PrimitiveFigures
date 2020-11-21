#include "pch.h"
#include "Square.h"

primitives::Square::Square()
{
    setType(ShapeType::Square);
}

primitives::Square::Square(LONG x, LONG y, LONG s)
    : m_data(CRect(x, y, x + s, y + s))
{
    setType(ShapeType::Square);
}

primitives::Square::Square(const CRect& rect)
{
    setType(ShapeType::Square);
}

void primitives::Square::setStartPoint(CPoint point)
{
    m_data.left = point.x;
    m_data.top = point.y;
}

void primitives::Square::setEndPoint(CPoint point)
{
    int x = startPoint().x - point.x;
    int y = startPoint().y - point.y;
    int s = max(std::abs(x), std::abs(y));
    x = (x > 0 ? -s : s);
    y = (y > 0 ? -s : s);

    m_data.right = m_data.left + x;
    m_data.bottom = m_data.top + y;
}

void primitives::Square::setSize(LONG s)
{
    m_data.right = m_data.left + s;
    m_data.bottom = m_data.top + s;
}


CPoint primitives::Square::startPoint() const
{
    return CPoint(m_data.left, m_data.top);
}

LONG primitives::Square::size() const
{
    return std::abs(m_data.right - m_data.right);
}

void primitives::Square::draw(CDC* pDC, const RECT& rect) const
{
    CPen pen(PS_SOLID, thickness(), foregroundColor());
    pDC->SelectObject(pen);

    CBrush brush(PS_SOLID, backgroundColor());
    pDC->SelectObject(brush);

    LONG val_y1 = m_data.top;
    LONG val_y2 = m_data.bottom;
    if (convert() == Convert::Y)
    {
        val_y1 = rect.bottom - val_y1;
        val_y2 = rect.bottom - val_y2;
    }

    RECT place{
        m_data.left,
        val_y1,
        m_data.right,
        val_y2
    };

    pDC->Rectangle(&place);
}
