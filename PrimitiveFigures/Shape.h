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
        void setConvert(Convert c);

        COLORREF foregroundColor() const;
        COLORREF backgroundColor() const;
        int thickness() const;
        Convert convert() const;
        void setType(ShapeType type);
        ShapeType type() const;
        void draw(CDC* pDC, const RECT& rect) const override;

    private:
        COLORREF m_backgroundColor;
        COLORREF m_foregroundColor;
        int m_thickness;
        Convert m_convert = Convert::None;
        ShapeType m_type;
    };
}
