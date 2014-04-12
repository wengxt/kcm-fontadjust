#include <stdio.h>

#include <QApplication>
#include <QPainter>
#include <QPaintEvent>
#include <QImage>
#include <QImageWriter>
#include <QWidget>

#include <KComponentData>
#include <KGlobal>
#include <KTemporaryFile>
#include <KLocale>
#include <KDebug>
#include <KStandardDirs>
#include <KGlobalSettings>

#define MARGIN 3

class PaintWidget: public QWidget
{
    Q_OBJECT
    QString text;
    QSize s;
public:
    PaintWidget() : QWidget(0){

        text = i18n("The quick brown fox jumps over the lazy dog\n"
            "The quick brown fox jumps over the lazy dog\n"
            "The quick brown fox jumps over the lazy dog\n"
            "The quick brown fox jumps over the lazy dog"
        );
        QFontMetrics fm(qApp->font());
        s = fm.size(0, text);
        resize(s + QSize(MARGIN * 2, MARGIN * 2));
    }

protected:
    virtual void paintEvent(QPaintEvent*) {
        QPainter painter(this);

        painter.fillRect(rect(), qApp->palette().color(QPalette::Base));
        painter.setFont(qApp->font());
        painter.setPen(qApp->palette().color(QPalette::Text));
        painter.drawText(QRect(QPoint(MARGIN, MARGIN), s), Qt::AlignCenter, text);
    }
};

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

    PaintWidget widget;

    QImage image(widget.size(), QImage::Format_RGB32);
    image.fill(app.palette().color(QPalette::Base));
    widget.render(&image);
    
    QString filename = KStandardDirs::locateLocal("tmp", QString::fromLocal8Bit(argv[1]).append(".png"));
    qDebug() << filename;
    QImageWriter imageWriter(filename, "PNG");
    if (!imageWriter.canWrite()) {
        kDebug() << "Cannot write PNG format";
        exit(1);
    }
        
    imageWriter.write(image);
    return 0;
}

#include "main.moc"
