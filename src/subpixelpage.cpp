#include "subpixelpage.h"
#include "kxftconfig.h"
#include "fontadjustwizard.h"
#include "helper.h"

SubPixelPage::SubPixelPage(KFontAdjustWizard* wizard): KFontAdjustPage(wizard)
{
    setupUi(this);
    radioSubPixelNone->setChecked(true);
}

void SubPixelPage::aboutToHide()
{
    if (radioSubPixelNone->isChecked()) {
        wizard->getStyle().subPixel = KXftConfig::SubPixel::None;
    } else if (radioSubPixelRgb->isChecked()) {
        wizard->getStyle().subPixel = KXftConfig::SubPixel::Rgb;
    } else if (radioSubPixelBgr->isChecked()) {
        wizard->getStyle().subPixel = KXftConfig::SubPixel::Bgr;
    } else if (radioSubPixelVRgb->isChecked()) {
        wizard->getStyle().subPixel = KXftConfig::SubPixel::Vrgb;
    } else if (radioSubPixelVBgr->isChecked()) {
        wizard->getStyle().subPixel = KXftConfig::SubPixel::Vbgr;
    }
}

void SubPixelPage::aboutToShow()
{
    KXftConfig::FontStyle style;
    style.antiAliasing = wizard->getStyle().antiAliasing;
    style.hint = KXftConfig::Hint::NotSet;
    style.subPixel = KXftConfig::SubPixel::None;
    QString noneNmae = Helper::drawFontImage(style, "subnone");
    
    style.subPixel = KXftConfig::SubPixel::Rgb;
    QString rgbName = Helper::drawFontImage(style, "subrgb");
    
    style.subPixel = KXftConfig::SubPixel::Bgr;
    QString bgrName = Helper::drawFontImage(style, "subbgr");
    
    style.subPixel = KXftConfig::SubPixel::Vrgb;
    QString vrgbName = Helper::drawFontImage(style, "subvrgb");
    
    style.subPixel = KXftConfig::SubPixel::Vbgr;
    QString vbgrName = Helper::drawFontImage(style, "subvbgr");
    
    labelSubPixelNone->setPixmap(QPixmap(noneNmae));
    labelSubPixelRgb->setPixmap(QPixmap(rgbName));
    labelSubPixelBgr->setPixmap(QPixmap(bgrName));
    labelSubPixelVRgb->setPixmap(QPixmap(vrgbName));
    labelSubPixelVBgr->setPixmap(QPixmap(vbgrName));
}
