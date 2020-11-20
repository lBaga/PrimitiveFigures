
// MainFrm.h : interface of the CMainFrame class
//

#pragma once

class CPrimitiveFiguresView;
class MenuForm;

class CMainFrame : public CFrameWnd
{
    
protected: // create from serialization only
    CMainFrame() noexcept;
    DECLARE_DYNCREATE(CMainFrame)

// Attributes
protected:
    CSplitterWnd m_wndSplitter;

private:
    CPrimitiveFiguresView* pPrimFigView;
    MenuForm* pMenuForm;
public:

// Operations
public:

// Overrides
public:
    virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
    virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implementation
public:
    virtual ~CMainFrame();
#ifdef _DEBUG
    virtual void AssertValid() const;
    virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // control bar embedded members
    CStatusBar        m_wndStatusBar;

// Generated message map functions
protected:
    afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
    afx_msg void OnApplicationLook(UINT id);
    afx_msg void OnUpdateApplicationLook(CCmdUI* pCmdUI);
    DECLARE_MESSAGE_MAP()

};


