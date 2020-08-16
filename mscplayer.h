#ifndef MSCPLAYER_H
#define MSCPLAYER_H

#include <QWidget>
#include <QMediaPlayer>
#include <QMediaPlaylist>
namespace Ui {
class MscPlayer;
}

class MscPlayer : public QWidget
{
    Q_OBJECT

public:
    explicit MscPlayer(QWidget *parent = 0);
    void Btn_Style();
    ~MscPlayer();

private:
    QMediaPlayer    *player;//播放器
    QMediaPlaylist  *playlist;//播放列表
    QString  durationTime;//总长度
    QString  positionTime;//当前播放到位置
signals:
    void ShowHomeInterface();
private slots:
    void onStateChanged(QMediaPlayer::State state);

    void onPlaylistChanged(int position);

    void onDurationChanged(qint64 duration);

    void onPositionChanged(qint64 position);

    void on_AddMscBtn_clicked();

    void on_DelMscBtn_clicked();

    void on_ClsMscBtn_clicked();

    void on_BackHomeBtn_clicked();

    void on_verticalSlider_valueChanged(int value);

    //void on_PauseBtn_clicked();

    void on_PreviousBtn_clicked();

    void on_NextBtn_clicked();

    void on_StopBtn_clicked();

    void on_VolBtn_clicked();

    void on_listWidget_doubleClicked(const QModelIndex &index);

    void GetShowMscInterface();

    void onSliderPositionvalueChanged(int value);

    void on_PlayBtn_clicked();

private:
    Ui::MscPlayer *ui;
};

#endif // MSCPLAYER_H
