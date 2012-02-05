#include <stdio.h>

#include <QApplication>
#include <QPainter>
#include <QImage>
#include <QImageWriter>

#include <KComponentData>
#include <KGlobal>
#include <KTemporaryFile>
#include <KLocale>
#include <KDebug>
#include <KStandardDirs>
#include <KGlobalSettings>

#define MARGIN 3

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    KComponentData("fontadjust_helper", "fontadjust");
    KGlobal::locale();
    
    if (argc != 2)
    {
        fprintf(stderr, "Usage: fontadjust_helper name\n");
        exit(1);
    }
    
    QString text = i18n("The quick brown fox jumps over the lazy dog\n"
        "The quick brown fox jumps over the lazy dog\n"
        "The quick brown fox jumps over the lazy dog\n"
        "The quick brown fox jumps over the lazy dog"
    );
    //QFont font = KGlobalSettings::generalFont();
    QFont font("AR PL UKai CN");
    QFontMetrics fm(font);
    QSize s = fm.size(0, text);
    
    QImage image(s + QSize(MARGIN * 2, MARGIN * 2), QImage::Format_RGB32);
    image.fill(app.palette().color(QPalette::Base));
    
    QPainter painter(&image);

    painter.setFont(font);
    painter.setPen(app.palette().color(QPalette::Text));
    painter.drawText(QRect(QPoint(MARGIN, MARGIN), s), Qt::AlignCenter, text);
    
    QString filename = KStandardDirs::locateLocal("tmp", QString::fromLocal8Bit(argv[1]).append(".png"));
    QImageWriter imageWriter(filename, "PNG");
    if (!imageWriter.canWrite()) {
        kDebug() << "Cannot write PNG format";
        exit(1);
    }
        
    imageWriter.write(image);
    return 0;
}