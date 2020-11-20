#pragma once

#include <vector>
#include <memory>

#include "BaseShape.h"

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

    const std::vector<std::unique_ptr<primitives::BaseShape>>& shapes() const;
    const std::unique_ptr<primitives::BaseShape>& tempShape() const;

    enum class CreateState {Idle, ClickOne, ClickTwo, ClickThree};
    void makeRectangle();
    void setForegroundColor(COLORREF color);
    void setBackgroundColor(COLORREF color);
    COLORREF foregroundColor() const;
    COLORREF backgroundColor() const;

    bool mouseMove(UINT nFlags, CPoint point);
    bool mousePress(UINT nFlags, CPoint point);
private:
    void buildFigures();

private:
    std::vector<std::unique_ptr<primitives::BaseShape>> m_shapes;
    std::unique_ptr<primitives::BaseShape> m_tempShape;
    primitives::ShapeType m_shapeType;

    CreateState m_createState = CreateState::Idle;
    COLORREF m_commonForegroundColor;
    COLORREF m_commonBackgroundColor;

    std::vector<CPoint> m_mousePos;

protected:
// Generated message map functions
protected:
    DECLARE_MESSAGE_MAP()
};
