#pragma once

class CPrimitiveFiguresDoc;

class CPrimitiveFiguresView : public CView
{
protected: // create from serialization only
    CPrimitiveFiguresView() noexcept;
    DECLARE_DYNCREATE(CPrimitiveFiguresView)

// Attributes
public:
    CPrimitiveFiguresDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
    virtual void OnDraw(CDC* pDC);  // overridden to draw this view
    virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
    virtual ~CPrimitiveFiguresView();

protected:

// Generated message map functions
protected:
    DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnMouseMove(UINT nFlags, CPoint point);
    afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};