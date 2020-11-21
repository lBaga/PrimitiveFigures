#include "pch.h"
#include "PrimitiveFiguresDoc.h"
#include <propkey.h>

#include <random>
#include <cmath>
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
    buildFigures();
}

const std::vector<std::unique_ptr<primitives::Shape>>& CPrimitiveFiguresDoc::shapes() const
{
    return m_shapes;
}

const std::unique_ptr<primitives::Shape>& CPrimitiveFiguresDoc::tempShape() const
{
    return m_tempShape;
}

void CPrimitiveFiguresDoc::buildFigures()
{
    auto rand_color = []() -> COLORREF
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist(0, 255);
        return RGB(dist(gen), dist(gen), dist(gen));
    };

    // Rectangle
    auto pRect = std::make_unique<primitives::Rectangle>(CRect(0, 0, 200, 400));
    pRect->setConvert(primitives::Convert::Y);
    pRect->setForegroundColor(rand_color());
    pRect->setBackgroundColor(rand_color());
    pRect->setThickness(10);
    m_shapes.push_back(std::move(pRect));

    // Triangle
    CPoint points[3]{ {300, 0}, { 400, 300}, {500, 0} };
    auto pTriangle = std::make_unique<primitives::Triangle>(points);
    pTriangle->setConvert(primitives::Convert::Y);
    pTriangle->setForegroundColor(rand_color());
    pTriangle->setBackgroundColor(rand_color());
    pTriangle->setThickness(10);
    m_shapes.push_back(std::move(pTriangle));

    // Square
    auto pSquare = std::make_unique<primitives::Square>(600, 0, 200);
    pSquare->setConvert(primitives::Convert::Y);
    pSquare->setForegroundColor(rand_color());
    pSquare->setBackgroundColor(rand_color());
    pSquare->setThickness(10);
    m_shapes.push_back(std::move(pSquare));

    // Circle
    auto pCircle = std::make_unique<primitives::Circle>(CPoint(1000, 100), 100);
    pCircle->setConvert(primitives::Convert::Y);
    pCircle->setForegroundColor(rand_color());
    pCircle->setBackgroundColor(rand_color());
    pCircle->setThickness(10);
    m_shapes.push_back(std::move(pCircle));
}

void CPrimitiveFiguresDoc::makeRectangle()
{
    m_shapeType = primitives::ShapeType::Rectangle;
    m_createState = CreateState::Idle;
}

void CPrimitiveFiguresDoc::makeTriangle()
{
    m_shapeType = primitives::ShapeType::Triangle;
    m_createState = CreateState::Idle;
}

void CPrimitiveFiguresDoc::makeCircle()
{
    m_shapeType = primitives::ShapeType::Circle;
    m_createState = CreateState::Idle;
}

void CPrimitiveFiguresDoc::makeSquare()
{
    m_shapeType = primitives::ShapeType::Square;
    m_createState = CreateState::Idle;
}

void CPrimitiveFiguresDoc::deleteAllShapes()
{
    m_shapes.clear();
    UpdateAllViews(nullptr);
}

void CPrimitiveFiguresDoc::setForegroundColor(COLORREF color)
{
    m_commonForegroundColor = color;
}

void CPrimitiveFiguresDoc::setBackgroundColor(COLORREF color)
{
    m_commonBackgroundColor = color;
}

void CPrimitiveFiguresDoc::setThickness(int thickness)
{
    m_commonThickness = thickness;
}

COLORREF CPrimitiveFiguresDoc::foregroundColor() const
{
    return m_commonForegroundColor;
}

COLORREF CPrimitiveFiguresDoc::backgroundColor() const
{
    return m_commonBackgroundColor;
}

int CPrimitiveFiguresDoc::thickness() const
{
    return m_commonThickness;
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
    else if (m_shapeType == primitives::ShapeType::Triangle)
    {
        switch (m_createState)
        {
        case CreateState::ClickOne:
        {
            auto pTriangle = static_cast<primitives::Triangle*>(m_tempShape.get());
            pTriangle->setPoint2(point);
            pTriangle->setPoint3(point);
            return true;
        }
        break;
        case CreateState::ClickTwo:
        {
            auto pTriangle = static_cast<primitives::Triangle*>(m_tempShape.get());
            pTriangle->setPoint3(point);
            return true;
        }
        break;
        }
    }
    else if (m_shapeType == primitives::ShapeType::Square)
    {
        if (m_createState == CreateState::ClickOne)
        {
            auto pSquare = static_cast<primitives::Square*>(m_tempShape.get());
            pSquare->setEndPoint(point);
            return true;
        }
    }
    else if (m_shapeType == primitives::ShapeType::Circle)
    {
        if (m_createState == CreateState::ClickOne)
        {
            auto pCircle = static_cast<primitives::Circle*>(m_tempShape.get());
            int x = pCircle->startPoint().x - point.x;
            int y = pCircle->startPoint().y - point.y;
            int r = max(std::abs(x), std::abs(y));
            pCircle->setRadius(r);
            return true;
        }
    }
    return false;
}

bool CPrimitiveFiguresDoc::mousePress(UINT nFlags, CPoint point)
{

    if (nFlags == MK_LBUTTON)
    {
        if (m_shapeType == primitives::ShapeType::Rectangle)
        {
            switch (m_createState)
            {
            case CreateState::Idle:
            {
                m_createState = CreateState::ClickOne;
                m_tempShape = std::make_unique<primitives::Rectangle>();
                auto pRect = static_cast<primitives::Rectangle*>(m_tempShape.get());

                pRect->setBackgroundColor(m_commonBackgroundColor);
                pRect->setForegroundColor(m_commonForegroundColor);
                pRect->setThickness(m_commonThickness);
                pRect->setStartPoint(point);
                pRect->setEndPoint(point);
            }
            break;
            case CreateState::ClickOne:
                    m_shapes.push_back(std::move(m_tempShape));
                    m_tempShape = std::make_unique<primitives::Shape>();

            default:
                m_createState = CreateState::Idle;
                UpdateAllViews(nullptr);
                break;
            }
        }
        else if (m_shapeType == primitives::ShapeType::Triangle)
        {
            switch (m_createState)
            {
            case CreateState::Idle:
            {
                m_createState = CreateState::ClickOne;

                m_tempShape = std::make_unique<primitives::Triangle>();
                auto pTriangle= static_cast<primitives::Triangle*>(m_tempShape.get());

                pTriangle->setBackgroundColor(m_commonBackgroundColor);
                pTriangle->setForegroundColor(m_commonForegroundColor);
                pTriangle->setThickness(m_commonThickness);
                pTriangle->setPoint1(point);
                pTriangle->setPoint2(point);
                pTriangle->setPoint3(point);
            }
            break;

            case CreateState::ClickOne:
            {
                m_createState = CreateState::ClickTwo;
                auto pTriangle = static_cast<primitives::Triangle*>(m_tempShape.get());
                pTriangle->setPoint2(point);
                pTriangle->setPoint3(point);
            }
            break;
            case CreateState::ClickTwo:
                m_shapes.push_back(std::move(m_tempShape));
                m_tempShape = std::make_unique<primitives::Shape>();
            default:
                m_createState = CreateState::Idle;
                UpdateAllViews(nullptr);
                break;
            }
        }
        else if (m_shapeType == primitives::ShapeType::Square)
        {
            switch (m_createState)
            {
            case CreateState::Idle:
            {
                m_createState = CreateState::ClickOne;
                m_tempShape = std::make_unique<primitives::Square>();
                auto pSquare = static_cast<primitives::Square*>(m_tempShape.get());

                pSquare->setBackgroundColor(m_commonBackgroundColor);
                pSquare->setForegroundColor(m_commonForegroundColor);
                pSquare->setThickness(m_commonThickness);
                pSquare->setStartPoint(point);
                pSquare->setSize(0);
            }
            break;
            case CreateState::ClickOne:
                m_shapes.push_back(std::move(m_tempShape));
                m_tempShape = std::make_unique<primitives::Shape>();

            default:
                m_createState = CreateState::Idle;
                UpdateAllViews(nullptr);
                break;
            }
        }
        else if (m_shapeType == primitives::ShapeType::Circle)
        {
            switch (m_createState)
            {
            case CreateState::Idle:
            {
                m_createState = CreateState::ClickOne;
                m_tempShape = std::make_unique<primitives::Circle>();
                auto pCircle = static_cast<primitives::Circle*>(m_tempShape.get());

                pCircle->setBackgroundColor(m_commonBackgroundColor);
                pCircle->setForegroundColor(m_commonForegroundColor);
                pCircle->setThickness(m_commonThickness);
                pCircle->setStartPoint(point);
                pCircle->setRadius(0);
            }
            break;
            case CreateState::ClickOne:
                m_shapes.push_back(std::move(m_tempShape));
                m_tempShape = std::make_unique<primitives::Shape>();

            default:
                m_createState = CreateState::Idle;
                UpdateAllViews(nullptr);
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