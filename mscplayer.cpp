#include "mscplayer.h"
#include "ui_mscplayer.h"
#include <QFileDialog>
MscPlayer::MscPlayer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MscPlayer)
{
    ui->setupUi(this);
    player = new QMediaPlayer(this);
    playlist = new QMediaPlaylist(this);
    playlist->setPlaybackMode(QMediaPlaylist::Loop); //循环模式
    player->setPlaylist(playlist);

    connect(player,SIGNAL(stateChanged(QMediaPlayer::State)),
            this, SLOT(onStateChanged(QMediaPlayer::State)));

    connect(player,SIGNAL(positionChanged(qint64)),
            this, SLOT(onPositionChanged(qint64)));

    connect(player,SIGNAL(durationChanged(qint64)),
            this, SLOT(onDurationChanged(qint64)));

    connect(playlist,SIGNAL(currentIndexChanged(int)),
            this, SLOT(onPlaylistChanged(int)));
    connect(ui->SliderPosition,SIGNAL(sliderMoved(int)),
            this,SLOT(onSliderPositionvalueChanged(int)));

    player->setVolume(50);
    ui->verticalSlider->setValue(50);

}

MscPlayer::~MscPlayer()
{
    delete ui;
    ui->SliderPosition->setTracking(false);
}
void MscPlayer::onStateChanged(QMediaPlayer::State state)//播放器状态变化，更新按钮状态
{
    ui->PlayBtn->setEnabled(1);
    //ui->PauseBtn->setEnabled(state==QMediaPlayer::PlayingState);
    ui->StopBtn->setEnabled(state==QMediaPlayer::PlayingState);
}

void MscPlayer::onPlaylistChanged(int position)//播放文件名显示
{
    ui->listWidget->setCurrentRow(position);
    QListWidgetItem  *item=ui->listWidget->currentItem();
    if (item)
        ui->LabCurMedia->setText(item->text());
}

void MscPlayer::onDurationChanged(qint64 duration)//进度显示
{
    ui->SliderPosition->setMaximum(duration);

     int   secs=duration/1000;
     int   mins=secs/60;
     secs=secs % 60;
     durationTime=QString::asprintf("%d:%d",mins,secs);
     ui->LabRatio->setText(positionTime+"/"+durationTime);
}

void MscPlayer::onPositionChanged(qint64 position)//当前文件播放位置变化，更新进度显示
{
    if (ui->SliderPosition->isSliderDown())
        return;

    ui->SliderPosition->setSliderPosition(position);

    int   secs=position/1000;
    int   mins=secs/60;
    secs=secs % 60;
    positionTime=QString::asprintf("%d:%d",mins,secs);
    ui->LabRatio->setText(positionTime+"/"+durationTime);
}


void MscPlayer::on_AddMscBtn_clicked()//添加音乐按键
{
        QString curPath=QDir::homePath();
        QString dlgTitle="choose music file";
        QString filter="音频文件(*.mp3 *.wav *.wma);;mp3文件(*.mp3);;wav文件(*.wav);;wma文件(*.wma);;所有文件(*.*)"; //file filter
        QStringList fileList=QFileDialog::getOpenFileNames(this,dlgTitle,curPath,filter);

        if (fileList.count()<1)
            return;

        for (int i=0; i<fileList.count();i++)
        {
           QString aFile=fileList.at(i);
           playlist->addMedia(QUrl::fromLocalFile(aFile));//add file

           QFileInfo   fileInfo(aFile);
           ui->listWidget->addItem(fileInfo.fileName());
        }

        if (player->state()!=QMediaPlayer::PlayingState)
            playlist->setCurrentIndex(0);
        player->play();
}

void MscPlayer::on_DelMscBtn_clicked()//删除播放列表的音乐
{
    int pos=ui->listWidget->currentRow();
        QListWidgetItem *item=ui->listWidget->takeItem(pos);
        delete item;//从listWidget里删除

        if (playlist->currentIndex()==pos) //是当前播放的曲目
        {
            int nextPos=0;
            if (pos>=1)
                nextPos=pos-1;

            playlist->removeMedia(pos);//从播放列表里移除
            if (ui->listWidget->count()>0)
            {
                playlist->setCurrentIndex(nextPos);
                onPlaylistChanged(nextPos);
            }
            else
            {
                player->stop();
                ui->LabCurMedia->setText("no music");
            }
        }
        else
            playlist->removeMedia(pos);
}

void MscPlayer::on_ClsMscBtn_clicked()//清除播放列表
{
    playlist->clear();
    ui->listWidget->clear();
    player->stop();
}


void MscPlayer::on_verticalSlider_valueChanged(int value)//音量按键
{
        player->setVolume(value);
}


//void MscPlayer::on_PauseBtn_clicked()//暂停按键
//{
//    player->pause();
//}

void MscPlayer::on_PreviousBtn_clicked()//上一首按键
{
    playlist->previous();
}

void MscPlayer::on_NextBtn_clicked()//下一首按键
{
    playlist->next();
}

void MscPlayer::on_StopBtn_clicked()//停止按键
{
    player->stop();
}

void MscPlayer::on_VolBtn_clicked()//按键静音切换显示图片
{
    bool mute=player->isMuted();
    player->setMuted(!mute);
    if (mute)
    {
        ui->VolBtn->setIcon(QIcon(":/resources/vol.png"));
        ui->VolBtn->setIconSize(QSize(80, 60));
    }
    else
    {
        ui->VolBtn->setIcon(QIcon(":/resources/mute.png"));
        ui->VolBtn->setIconSize(QSize(80, 60));
    }
}

void MscPlayer::on_listWidget_doubleClicked(const QModelIndex &index)//双击播放列表音乐
{
    int rowNo=index.row();
    playlist->setCurrentIndex(rowNo);
    player->play();
}
void MscPlayer::on_BackHomeBtn_clicked()
{
    this->hide();
    emit ShowHomeInterface();
}
void MscPlayer::GetShowMscInterface()//显示music player界面
{
    this->show();
}

void MscPlayer::onSliderPositionvalueChanged(int value)//拖动进度条设置进度
{
        player->setPosition(value);
}

void MscPlayer::on_PlayBtn_clicked()//播放按键
{
    if(playlist->currentIndex()<0)
        playlist->setCurrentIndex(0);

    if(player->state() == QMediaPlayer::PlayingState)
    {
        player->pause();
        ui->PlayBtn->setIcon(QIcon(":/resources/pause.png"));
        ui->PlayBtn->setIconSize(QSize(80, 60));
    }

    else if(player->state() == (QMediaPlayer::PausedState))
    {
        player->play();
        ui->PlayBtn->setIcon(QIcon(":/resources/play.png"));
        ui->PlayBtn->setIconSize(QSize(80, 60));
    }

}
