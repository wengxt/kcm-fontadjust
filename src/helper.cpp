#include "helper.h"
#include <QProcess>

#include <KStandardDirs>
#include <KConfigGroup>
#include <KSharedConfig>
#include <KProcess>
#include <KTemporaryFile>
#include <KDebug>
#include <KGlobalSettings>

QString Helper::drawFontImage(KXftConfig::FontStyle style, const QString& n)
{
    QString name = n;
    KXftConfig xftConfig;
    KXftConfig::FontStyle oldStyle = xftConfig.getStyle();
    xftConfig.setStyle(style);
    runRdb(xftConfig);

    QString filename = KStandardDirs::locateLocal("tmp", name.append(".png"));
    QProcess process;
    process.start(KStandardDirs::findExe("fontadjust_helper"),
                  QStringList() << n);
    process.waitForFinished();

    xftConfig.setStyle(oldStyle);
    runRdb(xftConfig);

    QFileInfo info(filename);
    if (info.exists())
        return filename;
    return QString();
}


void Helper::runRdb(KXftConfig& xft)
{
    KXftConfig::FontStyle style = xft.getStyle();
    xft.apply();
    QString contents;

    KTemporaryFile tmpFile;
    if (!tmpFile.open())
    {
        kDebug() << "Couldn't open temp file";
        exit(0);
    }
    if (style.antiAliasing)
    {
        contents += "Xft.antialias: ";
        if (style.antiAliasing)
            contents += "1\n";
        else
            contents += "0\n";
    }

    if (style.hint != KXftConfig::Hint::NotSet)
    {
        QString hintStyle = KXftConfig::toStr(style.hint);
        contents += "Xft.hinting: ";
        if (hintStyle.isEmpty())
            contents += "-1\n";
        else
        {
            if (hintStyle!="hintnone")
                contents += "1\n";
            else
                contents += "0\n";
            contents += "Xft.hintstyle: " + hintStyle + '\n';
        }
    }

    QString subPixel = KXftConfig::toStr(style.subPixel);
    if (!subPixel.isEmpty())
        contents += "Xft.rgba: " + subPixel + '\n';

    if (contents.length() > 0)
        tmpFile.write( contents.toLatin1(), contents.length() );

    tmpFile.flush();

    KProcess proc;
#ifndef NDEBUG
    proc << "xrdb" << "-merge" << tmpFile.fileName();
#else
    proc << "xrdb" << "-quiet" << "-merge" << tmpFile.fileName();
#endif
    proc.execute();
    proc.waitForFinished();
}


