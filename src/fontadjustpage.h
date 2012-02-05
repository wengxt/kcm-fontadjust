#ifndef FONT_ADJUST_PAGE_H
#define FONT_ADJUST_PAGE_H

#include <QWidget>

class KFontAdjustWizard;
class KFontAdjustPage : public QWidget
{
    Q_OBJECT
public:
    explicit KFontAdjustPage(KFontAdjustWizard* wizard);
    virtual void aboutToHide() = 0;
    virtual void aboutToShow() = 0;
    
protected:
    KFontAdjustWizard* wizard;
};

#endif