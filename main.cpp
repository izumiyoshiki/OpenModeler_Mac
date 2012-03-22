#include <QtGui/QApplication>
#include <QLayout>
#include <QLabel>
#include "script.h"
#include "opengl.h"

const int WIDGET_WIDTH  = 600;
const int WIDGET_HEIGHT = 600;
const int LABEL_WIDTH   = 600;
const int LABEL_HEIGHT  = 100;
const int GL_WIDTH      = 400;
const int GL_HEIGHT     = 400;
const int SPACE_WIDTH   = 100;
const int SPACE_HEIGHT  = 100;

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    //test.nutの前の部分は、自分の環境の絶対パスを入れて下さい。
    Script *script = new Script("/Users/yoshiki_izumi/github/local/OpenModeler_Mac/test.nut");
    QString text = script->getScript().c_str();

    QWidget *widget = new QWidget();
    widget->setGeometry(0, 0, WIDGET_WIDTH, WIDGET_HEIGHT);

    QLabel* label = new QLabel(text, widget , 0 );
    label->setGeometry(0, 0, LABEL_WIDTH,LABEL_HEIGHT);

    OpenGL *gl = new OpenGL(widget);
    gl->setGeometry(SPACE_WIDTH, SPACE_HEIGHT, GL_WIDTH, GL_HEIGHT);

    widget->show();

    return a.exec();
}
