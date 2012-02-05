#include "hintpage.h"
#include "fontadjustwizard.h"
#include "helper.h"

HintPage::HintPage(KFontAdjustWizard* wizard): KFontAdjustPage(wizard)
{
    setupUi(this);
    radioHintMedium->setChecked(true);
}

void HintPage::aboutToHide()
{
    if (radioHintNone->isChecked()) {
        wizard->getStyle().hint = KXftConfig::Hint::None;
    } else if (radioHintSlight->isChecked()) {
        wizard->getStyle().hint = KXftConfig::Hint::Slight;
    } else if (radioHintMedium->isChecked()) {
        wizard->getStyle().hint = KXftConfig::Hint::Medium;
    } else if (radioHintFull->isChecked()) {
        wizard->getStyle().hint = KXftConfig::Hint::Full;
    }
}

void HintPage::aboutToShow()
{
    KXftConfig::FontStyle style;
    style.antiAliasing = wizard->getStyle().antiAliasing;
    style.subPixel = wizard->getStyle().subPixel;
    style.hint = KXftConfig::Hint::None;
    QString noneNmae = Helper::drawFontImage(style, "hintnone");
    
    style.hint = KXftConfig::Hint::Slight;
    QString slightName = Helper::drawFontImage(style, "hintslight");
    
    style.hint = KXftConfig::Hint::Medium;
    QString mediumName = Helper::drawFontImage(style, "hintmedium");
    
    style.hint = KXftConfig::Hint::Full;
    QString fullName = Helper::drawFontImage(style, "hintfull");
    
    labelHintNone->setPixmap(QPixmap(noneNmae));
    labelHintSlight->setPixmap(QPixmap(slightName));
    labelHintMedium->setPixmap(QPixmap(mediumName));
    labelHintFull->setPixmap(QPixmap(fullName));
}
