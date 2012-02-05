#include "kxftconfig.h"
class Helper
{
public:
    static QString drawFontImage(KXftConfig::FontStyle style, const QString& name);
    static void runRdb(KXftConfig& xft);
};