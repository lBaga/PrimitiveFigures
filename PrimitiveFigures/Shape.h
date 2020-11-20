#pragma once
#include "BaseShape.h"

namespace primitives
{
    class Shape : public BaseShape
    {
    public:
        explicit Shape();

        void setForegroundColor(COLORREF color);
        void setBackgroundColor(COLORREF color);
        void setThickness(int thickness);

        COLORREF foregroundColor() const;
        COLORREF backgroundColor() const;
        int thickness() const;

    public:
        //void draw(CDC* pDC, const RECT& rect) const override = 0;

    private:
        COLORREF m_backgroundColor;
        COLORREF m_foregroundColor;
        int m_thickness;
    };
}
