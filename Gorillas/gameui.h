#ifndef GAMEUI_H
#define GAMEUI_H

#include <QWidget>
#include <QDebug>

namespace Ui {
    class GameUi;
}

class GameUi : public QWidget
{
    Q_OBJECT
public:
    explicit GameUi(QWidget *parent = 0);
    ~GameUi();

signals:
    void gameStarted();

public slots:

private:
    Ui::GameUi *ui;
    
};

#endif // GAMEUI_H
