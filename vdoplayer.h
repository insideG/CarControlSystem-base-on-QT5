#ifndef VDOPLAYER_H
#define VDOPLAYER_H

#include <QWidget>
#include <QMainWindow>
#include <QVideoWidget>
#include <QMediaPlayer>
#include <QFileDialog>
#include <QMediaPlaylist>
namespace Ui {
class vdoplayer;
}

class vdoplayer : public QMainWindow
{
    Q_OBJECT

public:
    explicit vdoplayer(QWidget *parent = 0); 
    ~vdoplayer();
    void addToPlaylist(const QStringList& fileNames);

signals:
    void ShowHomeInterface();
private slots:
    void GetShowVdoInterface();

    void onDurationChanged(qint64 duration);

    void onPositionChanged(qint64 position);

    void OpenFile();

    void PlayVideo();

    void StopVideo();

    void FullScr();

    void on_BtnBackHome_clicked();

    void onprogressBarvalueChanged(int value);

    void on_SoundBtn_clicked();

    void on_SliderVolumn_valueChanged(int value);

protected:
    void mousePressEvent(QMouseEvent *event);

    void keyPressEvent(QKeyEvent *event);
private:

    Ui::vdoplayer *ui;

    QString  durationTime;

    QString  positionTime;

    QMediaPlayer *player;

    QVideoWidget *videoWidget;

    QMediaPlaylist *Playlist;

    QString m_fileName;

    QMediaPlayer::State  m_playerState;
};

#endif // VDOPLAYER_H
