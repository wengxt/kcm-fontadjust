#include "fontadjustpage.h"
#include "ui_subpixel_page.h"
class SubPixelPage : public KFontAdjustPage, public Ui::SubPixelPage
{
    Q_OBJECT
public:
    explicit SubPixelPage(KFontAdjustWizard* wizard);
    virtual void aboutToShow();
    virtual void aboutToHide();
};