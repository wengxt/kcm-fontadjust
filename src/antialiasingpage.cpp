#include "antialiasingpage.h"
#include "helper.h"
#include "fontadjustwizard.h"

AntiAliasingPage::AntiAliasingPage(KFontAdjustWizard* wizard): KFontAdjustPage(wizard)
{
    setupUi(this);
    radioAntiAnliasing->setChecked(true);
}

void AntiAliasingPage::aboutToHide()
{
    wizard->getStyle().antiAliasing = radioAntiAnliasing->isChecked();
}

void AntiAliasingPage::aboutToShow()
{
    KXftConfig::FontStyle style;
    style.hint = KXftConfig::Hint::NotSet;
    QString noneAntiName = Helper::drawFontImage(style, "none_anti");
    
    style.antiAliasing = true;
    QString antiName = Helper::drawFontImage(style, "anti");
    
    labelNoAntiAnliasing->setPixmap(QPixmap(noneAntiName));
    labelAntiAnliasing->setPixmap(QPixmap(antiName));
}