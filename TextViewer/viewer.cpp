
#include <QApplication>
#include <QPushButton>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QtDebug>
#include <QPlainTextEdit>
#include <QSize>
#include <QWidget>
#include <QHBoxLayout>
#include <QFont>


int main(int argc, char **argv)
{

    QApplication app (argc, argv);
    QFont font = app.font();
    font.setPointSize(20);
    app.setFont(font);
    QWidget window;
    QHBoxLayout layout;


    QString string;

    if ( argc != 1 ) {
        const char* filename = argv[1]; //This will be problem if no file is given
        QFile file(filename);
        if ( file.open( QFile::ReadOnly | QFile::Truncate ) ) {
            QTextStream out(&file);
            string = out.readAll();
        } else {
            string = QString("No file found at path!");
        }
    } else {
        string = QString("No file given as input!");
    }

    QPlainTextEdit text(string);
    layout.addWidget(&text);
    text.setReadOnly(true);
    window.setLayout(&layout);
    window.show();
    window.resize(1200,800);




    return app.exec();
}
