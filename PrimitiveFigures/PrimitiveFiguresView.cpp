#include "pch.h"

#include "PrimitiveFiguresDoc.h"
#include "PrimitiveFiguresView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CPrimitiveFiguresView, CView)

BEGIN_MESSAGE_MAP(CPrimitiveFiguresView, CView)
END_MESSAGE_MAP()

CPrimitiveFiguresView::CPrimitiveFiguresView() noexcept
{
}

// CPrimitiveFiguresView drawing
void CPrimitiveFiguresView::OnDraw(CDC* pDC)
{
    CPrimitiveFiguresDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);
    if (!pDoc)
        return;

    RECT windowRect{};
    GetClientRect(&windowRect);

    for (auto& shape : pDoc->shapes())
    {
        shape->draw(pDC, windowRect);
    }
}

///////////////////////
CPrimitiveFiguresDoc* CPrimitiveFiguresView::GetDocument() const // non-debug version is inline
{
    ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPrimitiveFiguresDoc)));
    return (CPrimitiveFiguresDoc*)m_pDocument;
}

CPrimitiveFiguresView::~CPrimitiveFiguresView()
{
}

BOOL CPrimitiveFiguresView::PreCreateWindow(CREATESTRUCT& cs)
{
    return CView::PreCreateWindow(cs);
}