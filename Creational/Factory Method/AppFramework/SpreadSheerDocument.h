#pragma once
#include "Document.h"
class SpreadSheerDocument :
    public Document
{
    // Inherited via Document
    void Write() override;
    void Read() override;
};

