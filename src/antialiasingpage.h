#include "fontadjustpage.h"
#include "ui_antialiasing_page.h"
class AntiAliasingPage : public KFontAdjustPage, public Ui::AntiAliasingPage
{
    Q_OBJECT
public:
    explicit AntiAliasingPage(KFontAdjustWizard* wizard);
    virtual void aboutToShow();
    virtual void aboutToHide();
};