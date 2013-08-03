#ifndef BANANALAUNCHDIALOG_H
#define BANANALAUNCHDIALOG_H

#include <QDialog>
#include <QtDeclarative>
#include <QtEvents>

namespace Ui {
class bananaLaunchDialog;
}

class BananaLaunchDialog : public QDeclarativeView
{
    Q_OBJECT
    
public:
    explicit BananaLaunchDialog(QWidget *parent = 0);
   // void keyPressEvent(QKeyEvent *pKeyEvent);
    ~BananaLaunchDialog();

public slots:
    void receiveBananaLaunchData(QString pAngle, QString pVelocity);
    
private:
    // Ui::bananaLaunchDialog *ui;

    QObject *qmlObject;
};

#endif // BANANALAUNCHDIALOG_H
