#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>

#include <QtWidgets/QApplication>
#include <QtQuick/QQuickView>
#include <QtCore/QDir>
#include <QtQml/QQmlEngine>


#include "engine.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QApplication app(argc, argv);


    QQmlApplicationEngine engine;

    //Engine cw;
    //engine.rootContext()->setContextProperty("Work", &cw);


    qmlRegisterType<Engine>("EngineModule", 1, 0, "Engine");
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;





//    QQuickView viewer;
//    // The following are needed to make examples run without having to install the module
//    // in desktop environments.
//#ifdef Q_OS_WIN
//    QString extraImportPath(QStringLiteral("%1/../../../../%2"));
//#else
//    QString extraImportPath(QStringLiteral("%1/../../../%2"));
//#endif
//    viewer.engine()->addImportPath(extraImportPath.arg(QGuiApplication::applicationDirPath(),
//                                      QString::fromLatin1("qml")));
//    QObject::connect(viewer.engine(), &QQmlEngine::quit, &viewer, &QWindow::close);

//    viewer.setTitle(QStringLiteral("QML Chart"));

//    viewer.setSource(QUrl("qrc:/main.qml"));
//    viewer.setResizeMode(QQuickView::SizeRootObjectToView);
//    viewer.show();

    return app.exec();
}
