#include "pch.h"
#include "PrimitiveFiguresDoc.h"
#include <propkey.h>

#include <random>
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"
#include "Square.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CPrimitiveFiguresDoc, CDocument)

BEGIN_MESSAGE_MAP(CPrimitiveFiguresDoc, CDocument)
END_MESSAGE_MAP()

////////////////////////

CPrimitiveFiguresDoc::CPrimitiveFiguresDoc() noexcept
    : m_tempShape(std::make_unique<primitives::Shape>())
{
    m_mousePos.emplace_back(0, 0);
    buildFigures();
}

const std::vector<std::unique_ptr<primitives::BaseShape>>& CPrimitiveFiguresDoc::shapes() const
{
    return m_shapes;
}

const std::unique_ptr<primitives::BaseShape>& CPrimitiveFiguresDoc::tempShape() const
{
    return m_tempShape;
}

void CPrimitiveFiguresDoc::buildFigures()
{
    auto make_triangle = [&container = m_shapes]
    (CPoint(&points)[3], auto bcolor, auto fcolor, auto thickness)
    {
        auto pRect = std::make_unique<primitives::Triangle>(points);
        pRect->setForegroundColor(fcolor);
        pRect->setBackgroundColor(bcolor);
        pRect->setThickness(thickness);
        container.push_back(std::move(pRect));
    };

    auto make_circle = [&container = m_shapes]
    (auto center, auto radius, auto bcolor, auto fcolor, auto thickness)
    {
        auto pRect = std::make_unique<primitives::Circle>(center, radius);
        pRect->setForegroundColor(fcolor);
        pRect->setBackgroundColor(bcolor);
        pRect->setThickness(thickness);
        container.push_back(std::move(pRect));
    };

    auto make_rect = [&container = m_shapes]
    (auto rect, auto bcolor, auto fcolor, auto thickness)
    {
        auto pRect = std::make_unique<primitives::Rectangle>(rect);
        pRect->setForegroundColor(fcolor);
        pRect->setBackgroundColor(bcolor);
        pRect->setThickness(thickness);
        container.push_back(std::move(pRect));
    };

    auto make_square = [&container = m_shapes]
    (auto point, auto s, auto bcolor, auto fcolor, auto thickness)
    {
        auto pRect = std::make_unique<primitives::Square>(point.x, point.y, s);
        pRect->setForegroundColor(fcolor);
        pRect->setBackgroundColor(bcolor);
        pRect->setThickness(thickness);
        container.push_back(std::move(pRect));
    };

    auto rand_color = []() -> COLORREF
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist(0, 255);
        return RGB(dist(gen), dist(gen), dist(gen));
    };

    for (int i = 0; i < 3; ++i)
    {
        make_rect(CRect(i * 100, i * 100, 200, 400), rand_color(), rand_color(), i);
    }


    for (int i = 0; i < 3; ++i)
    {
        make_circle(CPoint(i * 200, i * 100), i * 50, rand_color(), rand_color(), i);
    }

    for (int i = 0; i < 3; ++i)
    {
        CPoint points[3]{ CPoint(i * 300, i * 100) ,CPoint(i * 350, i * 200) ,CPoint(i * 400, i * 250) };
        make_triangle(points, rand_color(), rand_color(), i);
    }

    for (int i = 0; i < 3; ++i)
    {
        make_square(CPoint(i * 400, i * 100), 200, rand_color(), rand_color(), i);
    }
}

void CPrimitiveFiguresDoc::makeRectangle()
{
    m_shapeType = primitives::ShapeType::Rectangle;
}

void CPrimitiveFiguresDoc::setForegroundColor(COLORREF color)
{
    m_commonForegroundColor = color;
}

void CPrimitiveFiguresDoc::setBackgroundColor(COLORREF color)
{
    m_commonBackgroundColor = color;
}

COLORREF CPrimitiveFiguresDoc::foregroundColor() const
{
    return m_commonForegroundColor;
}

COLORREF CPrimitiveFiguresDoc::backgroundColor() const
{
    return m_commonBackgroundColor;
}

bool CPrimitiveFiguresDoc::mouseMove(UINT nFlags, CPoint point)
{
    if (m_shapeType == primitives::ShapeType::Rectangle)
    {
        if (m_createState == CreateState::ClickOne)
        {
            auto pRect = static_cast<primitives::Rectangle*>(m_tempShape.get());
            pRect->setEndPoint(point);
            return true;
        }
    }
    return false;
}

bool CPrimitiveFiguresDoc::mousePress(UINT nFlags, CPoint point)
{
    m_mousePos[0] = point;

    if (nFlags == MK_LBUTTON)
    {
        if (m_shapeType == primitives::ShapeType::Rectangle)
        {
            switch (m_createState)
            {
            case CreateState::Idle:
                m_createState = CreateState::ClickOne;
                if (m_shapeType == primitives::ShapeType::Rectangle)
                {
                    m_tempShape = std::make_unique<primitives::Rectangle>();
                    auto pRect = static_cast<primitives::Rectangle*>(m_tempShape.get());

                    pRect->setBackgroundColor(m_commonBackgroundColor);
                    pRect->setForegroundColor(m_commonForegroundColor);

                    pRect->setStartPoint(point);
                    pRect->setEndPoint(point);
                }
                break;

            case CreateState::ClickOne:
                if (m_shapeType == primitives::ShapeType::Rectangle)
                {
                    m_shapes.push_back(std::move(m_tempShape));
                    m_tempShape = std::make_unique<primitives::Rectangle>();

                    auto pRect = static_cast<primitives::Rectangle*>(m_tempShape.get());
                    pRect->setBackgroundColor(m_commonBackgroundColor);
                    pRect->setForegroundColor(m_commonForegroundColor);
                }
            default:
                m_createState = CreateState::Idle;
                break;
            }
        }
    }

    return true;
}


CPrimitiveFiguresDoc::~CPrimitiveFiguresDoc() {}

////////////////////////////

BOOL CPrimitiveFiguresDoc::OnNewDocument()
{
    if (!CDocument::OnNewDocument())
        return FALSE;

    return TRUE;
}

void CPrimitiveFiguresDoc::Serialize(CArchive& ar)
{
    if (ar.IsStoring())
    {
    }
    else
    {
    }
}