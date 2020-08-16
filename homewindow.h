#ifndef HOMEWINDOW_H
#define HOMEWINDOW_H

#include    <QMainWindow>
#include    <QMediaPlayer>
#include    <QMediaPlaylist>
#include    <QVideoWidget>
namespace Ui {
class homewindow;
}

class homewindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit homewindow(QWidget *parent = 0);
    ~homewindow();
signals:
    ShowMscInterface();

    ShowVdoInterface();
private slots:

    void GetShowHomeInterface();

    void on_ShowMscBtn_clicked();

    void on_ShowVdoBtn_clicked();


private:
    Ui::homewindow *ui;
};

#endif // HOMEWINDOW_H
