#include <QQuickWindow>
#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "license.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    License license;

    QObject *topLevel = engine.rootObjects().value(0);
    QQuickWindow *window = qobject_cast<QQuickWindow *>(topLevel);

    // Connections
    QObject::connect(window, SIGNAL(macAddressEntered(QString)),
                     &license, SLOT(setMacAddress(QString)));
    QObject::connect(window, SIGNAL(expiryDateEntered(QVariant)),
                     &license, SLOT(setExpiryDate(QVariant)));
    QObject::connect(window, SIGNAL(generateButtonClicked(QString)),
                     &license, SLOT(generateLicenseHash(QString)));

    return app.exec();
}
