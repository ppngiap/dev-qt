#include <QCoreApplication>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QTemporaryFile>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QFile input("textstream.pro");
    if (!input.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qCritical() << "Cannot open " << input.fileName() << "for reading.  Got error: " << input.errorString() << ", Error code: " << input.error();
        return -1;
    }

#if (0)
    QFile output("out.txt");
    if (!output.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qCritical() << "Cannot open " << output.fileName() << "for writing.  Got error: " << output.errorString() << ", Error code: " << output.error();
        return -1;
    }
#else
    QTemporaryFile output;
    if (!output.open()) {
        qCritical() << "Cannot open " << output.fileName() << "for writing.  Got error: " << output.errorString() << ", Error code: " << output.error();
        return -1;
    }
    output.setAutoRemove(false);
    qDebug() << "Output filename : " << output.fileName();
#endif

    QTextStream instream(&input);
    QTextStream outstream(&output);
    outstream << instream.readAll();

    return 0;
}
