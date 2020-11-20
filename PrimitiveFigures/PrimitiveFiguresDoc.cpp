#include "pch.h"
#include "PrimitiveFiguresDoc.h"
#include <propkey.h>

#include <random>
#include "Rectangle.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CPrimitiveFiguresDoc, CDocument)

BEGIN_MESSAGE_MAP(CPrimitiveFiguresDoc, CDocument)
END_MESSAGE_MAP()

////////////////////////

CPrimitiveFiguresDoc::CPrimitiveFiguresDoc() noexcept
{
    buildFigures();
}

const std::vector<std::unique_ptr<primitives::BaseShape>>& CPrimitiveFiguresDoc::shapes() const
{
    return m_shapes;
}

void CPrimitiveFiguresDoc::buildFigures()
{
    auto make_rect = [&container = m_shapes]
    (auto rect, auto bcolor, auto fcolor, auto thickness)
    {
        auto pRect = std::make_unique<primitives::Rectangle>(rect);
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

    for (int i = 0; i < 10; ++i)
    {
        make_rect(CRect(i * 100, i * 100, 200, 400), rand_color(), rand_color(), i);
    }
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
    { }
    else
    { }
}