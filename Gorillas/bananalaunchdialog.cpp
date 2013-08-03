#include "bananalaunchdialog.h"

BananaLaunchDialog::BananaLaunchDialog(QWidget *parent) :
    QDeclarativeView(QUrl("qml/bananaLaunchDialogBox.qml"),parent)
{
    // Set up the QML.
    //this = new QDeclarativeView(QUrl("qml/bananaLaunchDialogBox.qml"), parent);
    this->setResizeMode(QDeclarativeView::SizeRootObjectToView);
    qmlObject = this->rootObject();

    // Connect
    connect(qmlObject, SIGNAL(sendBananaLaunchData(QString, QString)),
            this, SLOT(receiveBananaLaunchData(QString, QString)));
}
/*
void BananaLaunchDialog::keyPressEvent(QKeyEvent *pKeyEvent)
{
}
*/
BananaLaunchDialog::~BananaLaunchDialog()
{
}

void BananaLaunchDialog::receiveBananaLaunchData(QString pAngle, QString pVelocity)
{
    ;
}
