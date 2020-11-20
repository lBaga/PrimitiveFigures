// MenuForm.cpp : implementation file
//

#include "pch.h"
#include "PrimitiveFigures.h"

#include "PrimitiveFiguresDoc.h"
#include "MenuForm.h"


// MenuForm

IMPLEMENT_DYNCREATE(MenuForm, CFormView)

MenuForm::MenuForm()
    : CFormView(IDD_MenuForm)
{

}

MenuForm::~MenuForm()
{
}

void MenuForm::DoDataExchange(CDataExchange* pDX)
{
    CFormView::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_MFCCOLORBUTTON1, CCForeground);
    DDX_Control(pDX, IDC_MFCCOLORBUTTON2, CCBackground);
}

CPrimitiveFiguresDoc* MenuForm::GetDocument() const // встроена неотлаженная версия
{
    ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPrimitiveFiguresDoc)));
    return (CPrimitiveFiguresDoc*)m_pDocument;
}

BEGIN_MESSAGE_MAP(MenuForm, CFormView)
    ON_BN_CLICKED(IDC_BUTTON1, &MenuForm::OnBnClickedButton1)
    ON_BN_CLICKED(IDC_MFCCOLORBUTTON1, &MenuForm::OnBnClickedMfccolorbutton1)
    ON_BN_CLICKED(IDC_MFCCOLORBUTTON2, &MenuForm::OnBnClickedMfccolorbutton2)
END_MESSAGE_MAP()

void MenuForm::OnBnClickedButton1()
{
    CPrimitiveFiguresDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc); if (!pDoc) return;

    pDoc->makeRectangle();
    //pDoc->UpdateAllViews(nullptr);
}

void MenuForm::OnInitialUpdate()
{
    CFormView::OnInitialUpdate();

    CCForeground.SetColor(RGB(0, 0, 0));
    CCBackground.SetColor(RGB(255, 255, 255));
}

void MenuForm::OnBnClickedMfccolorbutton1()
{
    CPrimitiveFiguresDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc); if (!pDoc) return;

    pDoc->setForegroundColor(CCForeground.GetColor());
}

void MenuForm::OnBnClickedMfccolorbutton2()
{
    CPrimitiveFiguresDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc); if (!pDoc) return;

    pDoc->setBackgroundColor(CCBackground.GetColor());
}
