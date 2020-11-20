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

private:
    void buildFigures();
private:
    std::vector<std::unique_ptr<primitives::BaseShape>> m_shapes;
protected:
// Generated message map functions
protected:
    DECLARE_MESSAGE_MAP()
};
