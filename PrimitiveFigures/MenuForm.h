#pragma once
// MenuForm form view

class CPrimitiveFiguresDoc;

class MenuForm : public CFormView
{
    DECLARE_DYNCREATE(MenuForm)

    CPrimitiveFiguresDoc* GetDocument() const;

protected:
    MenuForm();           // protected constructor used by dynamic creation
    virtual ~MenuForm();

public:
#ifdef AFX_DESIGN_TIME
    enum { IDD = IDD_MenuForm };
#endif

protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

    DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnBnClickedButton1();
    CMFCColorButton CCForeground;
    CMFCColorButton CCBackground;
    virtual void OnInitialUpdate();
    afx_msg void OnBnClickedMfccolorbutton1();
    afx_msg void OnBnClickedMfccolorbutton2();
    int thickness;
    afx_msg void OnDeltaposSpin2(NMHDR* pNMHDR, LRESULT* pResult);
    afx_msg void OnBnClickedButton2();
    afx_msg void OnBnClickedButton3();
    afx_msg void OnBnClickedButton4();
    int rectCount;
    int triangCount;
    int circleCount;
    int squareCount;
    afx_msg void OnBnClickedButton5();
    virtual void OnUpdate(CView* /*pSender*/, LPARAM /*lHint*/, CObject* /*pHint*/);
};


