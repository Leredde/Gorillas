#include <QtGui/QApplication>
#include <QtGui/QIcon>
#include "qmlapplicationviewer.h"
#include "gamewindow.h"

Q_DECL_EXPORT int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GameWindow game;
    //QIcon banana;

    //QScopedPointer<QApplication> app(createApplication(argc, argv));

    /*QmlApplicationViewer viewer;
    viewer.setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
    viewer.setMainQmlFile(QLatin1String("qml/Gorillas/main.qml"));
    viewer.showExpanded();
*/

    //banana.addFile(QString("banana.ico"),QSize(7,13),QIcon::Normal,QIcon::On);

    //game.setWindowIcon(banana);
    game.setWindowTitle("Gorillas");
    //game.showFullScreen();
    game.show();

    //return app->exec();
    return a.exec();
}
