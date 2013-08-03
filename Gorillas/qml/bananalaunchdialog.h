#ifndef BANANALAUNCHDIALOG_H
#define BANANALAUNCHDIALOG_H

#include <QDialog>

namespace Ui {
class BananaLaunchDialog;
}

class BananaLaunchDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit BananaLaunchDialog(QWidget *parent = 0);
    ~BananaLaunchDialog();
    
private:
    Ui::BananaLaunchDialog *ui;
};

#endif // BANANALAUNCHDIALOG_H
