#ifndef FONT_ADJUST_WIZARD_H
#define FONT_ADJUST_WIZARD_H

#include <KAssistantDialog>
#include "kxftconfig.h"

class AntiAliasingPage;
class HintPage;
class SubPixelPage;

class KFontAdjustWizard : public KAssistantDialog
{
    Q_OBJECT
public:
    explicit KFontAdjustWizard(QWidget* parent = 0, Qt::WFlags flags = 0);
    KXftConfig::FontStyle& getStyle();
    
protected Q_SLOTS:
    void currentPageChanged_slot(KPageWidgetItem* current, KPageWidgetItem* before);
    
private:
    
    AntiAliasingPage* antiAliasingPage;
    HintPage* hintPage;
    SubPixelPage* subPixelPage;
    
    KXftConfig::FontStyle style;
};

#endif