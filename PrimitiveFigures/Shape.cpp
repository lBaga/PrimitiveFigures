#include "pch.h"
#include "Shape.h"

primitives::Shape::Shape()
    : m_backgroundColor(RGB(255, 255, 255))
    , m_foregroundColor(RGB(0, 0, 0))
    , m_thickness(1)
{
}

void primitives::Shape::setForegroundColor(COLORREF color)
{
    m_foregroundColor = color;
}

void primitives::Shape::setBackgroundColor(COLORREF color)
{
    m_backgroundColor = color;
}

void primitives::Shape::setThickness(int thickness)
{
    m_thickness = (thickness < 1 ? 1 : thickness);
}

COLORREF primitives::Shape::foregroundColor() const
{
    return m_foregroundColor;
}

COLORREF primitives::Shape::backgroundColor() const
{
    return m_backgroundColor;
}

int primitives::Shape::thickness() const
{
    return m_thickness;
}

void primitives::Shape::draw(CDC* pDC, const RECT& rect) const
{
}
