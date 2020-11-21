#pragma once

#include <vector>
#include <memory>

#include "Shape.h"

class CPrimitiveFiguresDoc : public CDocument
{
protected: // create from serialization only
    CPrimitiveFiguresDoc() noexcept;
    DECLARE_DYNCREATE(CPrimitiveFiguresDoc)

public:
    ~CPrimitiveFiguresDoc() override;

public:
    BOOL OnNewDocument() override;
    void Serialize(CArchive& ar) override;

    const std::vector<std::unique_ptr<primitives::Shape>>& shapes() const;
    const std::unique_ptr<primitives::Shape>& tempShape() const;

    enum class CreateState {Idle, ClickOne, ClickTwo, ClickThree};
    void makeRectangle();
    void makeTriangle();
    void makeCircle();
    void makeSquare();
    void deleteAllShapes();
    void setForegroundColor(COLORREF color);
    void setBackgroundColor(COLORREF color);
    void setThickness(int thickness);

    COLORREF foregroundColor() const;
    COLORREF backgroundColor() const;
    int thickness() const;

    bool mouseMove(UINT nFlags, CPoint point);
    bool mousePress(UINT nFlags, CPoint point);
private:
    void buildFigures();

private:
    std::vector<std::unique_ptr<primitives::Shape>> m_shapes;
    std::unique_ptr<primitives::Shape> m_tempShape;
    primitives::ShapeType m_shapeType;

    CreateState m_createState = CreateState::Idle;
    COLORREF m_commonForegroundColor;
    COLORREF m_commonBackgroundColor;
    int m_commonThickness = 10;

protected:
// Generated message map functions
protected:
    DECLARE_MESSAGE_MAP()
};
