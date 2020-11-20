#include "pch.h"

#include <memory>

#include "PrimitiveFiguresDoc.h"
#include "PrimitiveFiguresView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CPrimitiveFiguresView, CView)

BEGIN_MESSAGE_MAP(CPrimitiveFiguresView, CView)
    ON_WM_MOUSEMOVE()
    ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

CPrimitiveFiguresView::CPrimitiveFiguresView() noexcept
{
}

// CPrimitiveFiguresView drawing
void CPrimitiveFiguresView::OnDraw(CDC* pDC)
{
    CPrimitiveFiguresDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc); if (!pDoc) return;

    RECT windowRect{};
    GetClientRect(&windowRect);
    //Double buff
    CBitmap bitmap;
    bitmap.CreateCompatibleBitmap(pDC, windowRect.right, windowRect.bottom);
    auto pMemDC = std::make_unique<CDC>();
    pMemDC->CreateCompatibleDC(pDC);
    CBitmap* pOldBitmap;
    pOldBitmap = pMemDC->SelectObject(&bitmap);
    ///
    //Background 
    pMemDC->FillSolidRect(0, 0, windowRect.right, windowRect.bottom, RGB(255, 255, 255));

    //drawing shapes
    for (auto& shape : pDoc->shapes())
    {
        shape->draw(pMemDC.get(), windowRect);
    }
    //drawing temp shape
    pDoc->tempShape()->draw(pMemDC.get(), windowRect);

    //swap bitmaps for double buff
    pDC->BitBlt(0, 0, windowRect.right, windowRect.bottom, pMemDC.get(), 0, 0, SRCCOPY);
    pMemDC->SelectObject(pOldBitmap);
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

void CPrimitiveFiguresView::OnMouseMove(UINT nFlags, CPoint point)
{
    CPrimitiveFiguresDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc); if (!pDoc) return;

    if (pDoc->mouseMove(nFlags, point)) Invalidate(false);
    CView::OnMouseMove(nFlags, point);
}


void CPrimitiveFiguresView::OnLButtonDown(UINT nFlags, CPoint point)
{
    CPrimitiveFiguresDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc); if (!pDoc) return;

    if (pDoc->mousePress(nFlags, point)) Invalidate(false);
    CView::OnLButtonDown(nFlags, point);
}
