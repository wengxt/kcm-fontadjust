#include <KCModule>
#include "fontadjustwizard.h"

class KXftConfig;
class KFontAdjust : public KCModule
{
    Q_OBJECT
public:
    explicit KFontAdjust(QWidget* parent = 0, const QVariantList& args = QVariantList());
    
    virtual void load();
private:
    KFontAdjustWizard* wizard;
};