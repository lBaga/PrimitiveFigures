// MenuForm.cpp : implementation file
//

#include "pch.h"
#include <map>
#include "PrimitiveFigures.h"

#include "PrimitiveFiguresDoc.h"
#include "MenuForm.h"
#include "Shape.h"

// MenuForm

IMPLEMENT_DYNCREATE(MenuForm, CFormView)

MenuForm::MenuForm()
    : CFormView(IDD_MenuForm)
    , thickness(10)
    , rectCount(0)
    , triangCount(0)
    , circleCount(0)
    , squareCount(0)
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
    DDX_Text(pDX, IDC_EDIT1, thickness);
    DDV_MinMaxInt(pDX, thickness, 0, 100);
    DDX_Text(pDX, IDC_EDIT2, rectCount);
    DDX_Text(pDX, IDC_EDIT3, triangCount);
    DDX_Text(pDX, IDC_EDIT4, circleCount);
    DDX_Text(pDX, IDC_EDIT5, squareCount);
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
    ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN2, &MenuForm::OnDeltaposSpin2)
    ON_BN_CLICKED(IDC_BUTTON2, &MenuForm::OnBnClickedButton2)
    ON_BN_CLICKED(IDC_BUTTON3, &MenuForm::OnBnClickedButton3)
    ON_BN_CLICKED(IDC_BUTTON4, &MenuForm::OnBnClickedButton4)
    ON_BN_CLICKED(IDC_BUTTON5, &MenuForm::OnBnClickedButton5)
END_MESSAGE_MAP()


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


void MenuForm::OnDeltaposSpin2(NMHDR* pNMHDR, LRESULT* pResult)
{
    LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
    
    UpdateData(true);
    CPrimitiveFiguresDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc); if (!pDoc) return;

    pDoc->setThickness(thickness);
    *pResult = 0;
}

void MenuForm::OnBnClickedButton1()
{
    CPrimitiveFiguresDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc); if (!pDoc) return;

    pDoc->makeRectangle();
}

void MenuForm::OnBnClickedButton2()
{
    CPrimitiveFiguresDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc); if (!pDoc) return;

    pDoc->makeTriangle();
}


void MenuForm::OnBnClickedButton3()
{
    CPrimitiveFiguresDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc); if (!pDoc) return;

    pDoc->makeCircle();
}


void MenuForm::OnBnClickedButton4()
{
    CPrimitiveFiguresDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc); if (!pDoc) return;

    pDoc->makeSquare();
}


void MenuForm::OnBnClickedButton5()
{
    CPrimitiveFiguresDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc); if (!pDoc) return;

    pDoc->deleteAllShapes();
}


void MenuForm::OnUpdate(CView* /*pSender*/, LPARAM /*lHint*/, CObject* /*pHint*/)
{
    CPrimitiveFiguresDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc); if (!pDoc) return;

    rectCount = 0;
    triangCount = 0;
    circleCount = 0;
    squareCount = 0;

    std::map<primitives::ShapeType, int> figures;
    for (auto& shape : pDoc->shapes())
    {
        figures[shape->type()]++;
    }

    for (auto& shape : figures)
    {
        switch (shape.first)
        {
        case primitives::ShapeType::Triangle:
            triangCount = shape.second;
            break;
        case primitives::ShapeType::Circle:
            circleCount = shape.second;
            break;
        case primitives::ShapeType::Rectangle:
            rectCount = shape.second;
            break;
        case primitives::ShapeType::Square:
            squareCount = shape.second;
            break;
        default:
            break;
        }
    }

    UpdateData(false);
}
