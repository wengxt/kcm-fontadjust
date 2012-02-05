
#include <KLocalizedString>

#include "fontadjustwizard.h"
#include "antialiasingpage.h"
#include "hintpage.h"
#include "subpixelpage.h"
#include "fontadjustpage.h"

#define PAGE_ANTIALIASING_ID "Antialiasing"
#define PAGE_HINTING_ID "Hinting"
#define PAGE_SUBPIXEL_ID "SubPixel"

KFontAdjustWizard::KFontAdjustWizard(QWidget* parent, Qt::WFlags flags): KAssistantDialog(parent, flags),
    antiAliasingPage(new AntiAliasingPage(this)),
    hintPage(new HintPage(this)),
    subPixelPage(new SubPixelPage(this))
{
    KPageWidgetItem* page, *firstpage;
    page = new KPageWidgetItem(antiAliasingPage, QLatin1String(PAGE_ANTIALIASING_ID));
    addPage(page);
    firstpage = page;
    
    page = new KPageWidgetItem(subPixelPage, QLatin1String(PAGE_SUBPIXEL_ID));
    addPage(page);
    
    page = new KPageWidgetItem(hintPage, QLatin1String(PAGE_HINTING_ID));
    addPage(page);
    
    connect(this, SIGNAL(currentPageChanged(KPageWidgetItem*,KPageWidgetItem*)),
            SLOT(currentPageChanged_slot(KPageWidgetItem*,KPageWidgetItem*)));

    currentPageChanged_slot(firstpage, NULL);
}

void KFontAdjustWizard::currentPageChanged_slot(KPageWidgetItem* current, KPageWidgetItem* before)
{
    //Page changed
 
    enableButton(KDialog::Cancel, true);
 
    //Save data of the previous page
    if (before) {
        KFontAdjustPage* beforePage = dynamic_cast<KFontAdjustPage*>(before->widget());
        beforePage->aboutToHide();
    }
 
    //Load data of the current(new) page
    if (current) {
        KFontAdjustPage* currentPage = dynamic_cast<KFontAdjustPage*>(current->widget());
        currentPage->aboutToShow();
    }
}

KXftConfig::FontStyle& KFontAdjustWizard::getStyle()
{
    return style;
}
