#include <KPluginFactory>

#include "fontadjust.h"
#include "helper.h"


K_PLUGIN_FACTORY(FontAdjustFactory, registerPlugin<KFontAdjust>(); )
K_EXPORT_PLUGIN(FontAdjustFactory("kcmfonts"))

KFontAdjust::KFontAdjust(QWidget* parent, const QVariantList& args):
    KCModule(
        FontAdjustFactory::componentData(),
        parent,
        args
    ),
    wizard(new KFontAdjustWizard(this))
{
}

void KFontAdjust::load()
{
    wizard->show();
}
