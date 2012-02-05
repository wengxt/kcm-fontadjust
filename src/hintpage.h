#include "fontadjustpage.h"
#include "ui_hint_page.h"
class HintPage : public KFontAdjustPage, public Ui::HintPage
{
    Q_OBJECT
public:
    explicit HintPage(KFontAdjustWizard* wizard);
    virtual void aboutToShow();
    virtual void aboutToHide();
    
};