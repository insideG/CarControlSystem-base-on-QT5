#include "vdoplayer.h"
#include "ui_vdoplayer.h"
#include <QBoxLayout>
#include    <QMouseEvent>
#include <QDebug>
vdoplayer::vdoplayer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::vdoplayer),
    m_playerState(QMediaPlayer::StoppedState)
{
    ui->setupUi(this);
    //MainWindow自带layout，所以需要自定义layout并把它设置成中心layout
    //否则将会出现不能设置layout错误
    QWidget *widget = new QWidget;
    this->setCentralWidget(widget);

    //设置播放器组件
    player = new QMediaPlayer;
    Playlist = new QMediaPlaylist();
    player->setPlaylist(Playlist);

    //设置播放器的显示组件
    videoWidget = new QVideoWidget(widget);
    player->setVideoOutput(videoWidget);
    ui->ProgressBar->setRange(0, player->duration() / 1000);

    //水平布局，控制按钮
    QBoxLayout *ctlLayout = new QHBoxLayout;
    ctlLayout->addWidget(ui->OpenFileBtn);
    ctlLayout->addWidget(ui->PlayBtn);
    ctlLayout->addWidget(ui->StopBtn);
    ctlLayout->addWidget(ui->FullScrBtn);
    ctlLayout->addWidget(ui->BtnBackHome);
    ctlLayout->addWidget(ui->SoundBtn);
    ctlLayout->addWidget(ui->SliderVolumn);

    //主布局
    QBoxLayout *CurLayout = new QHBoxLayout;
    CurLayout->addWidget(ui->LabRatio);
    CurLayout->addWidget(ui->ProgressBar);

    //垂直布局：视频播放器、进度条、控制按钮布局
    QBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(videoWidget);
    mainLayout->addLayout(ctlLayout);
    mainLayout->addLayout(CurLayout);

    //设置布局
    widget->setLayout(mainLayout);

    //按键添加图片
    QIcon play_icon;
    play_icon.addFile(tr(":/resources/play.png"));
    ui->PlayBtn->setIcon(play_icon);

    QIcon stop_icon;
    stop_icon.addFile(tr(":/resources/stop.png"));
    ui->StopBtn->setIcon(stop_icon);

    QIcon addmsc_icon;
    addmsc_icon.addFile(tr(":/resources/add.png"));
    ui->OpenFileBtn->setIcon(addmsc_icon);

    QIcon back_icon;
    back_icon.addFile(tr(":/resources/back.png"));
    ui->BtnBackHome->setIcon(back_icon);

    QIcon vol_icon;
    vol_icon.addFile(tr(":/resources/vol.png"));
    ui->SoundBtn->setIcon(vol_icon);

    QIcon fullscr_icon;
    fullscr_icon.addFile(tr(":/resources/fullscr.png"));
    ui->FullScrBtn->setIcon(fullscr_icon);


    //按键信号槽
    QObject::connect(ui->OpenFileBtn,SIGNAL(clicked()),this,SLOT(OpenFile()));
    QObject::connect(ui->PlayBtn,SIGNAL(clicked()),this,SLOT(PlayVideo()));
    QObject::connect(ui->StopBtn,SIGNAL(clicked()),this,SLOT(StopVideo()));
    QObject::connect(ui->FullScrBtn,SIGNAL(clicked()),this,SLOT(FullScr()));

    //进度条和音量条的信号槽
    connect(player,SIGNAL(durationChanged(qint64)),this, SLOT(onDurationChanged(qint64)));
    connect(player,SIGNAL(positionChanged(qint64)),this, SLOT(onPositionChanged(qint64)));
    connect(ui->ProgressBar,SIGNAL(sliderMoved(int)),this,SLOT(onprogressBarvalueChanged(int)));

    //设置初始音量
    player->setVolume(50);
    ui->SliderVolumn->setValue(50);
}

vdoplayer::~vdoplayer()
{
    delete ui;
}

void vdoplayer::onDurationChanged(qint64 duration)//文件时长变化
{
    ui->ProgressBar->setMaximum(duration);

    int   secs=duration/1000;
    int   mins=secs/60;
    secs=secs % 60;
    durationTime=QString::asprintf("%d:%d",mins,secs);
    ui->LabRatio->setText(positionTime+"/"+durationTime);
}
void vdoplayer::onPositionChanged(qint64 position)//文件播放位置变化
{
    if (ui->ProgressBar->isSliderDown())
        return; //如果正在拖动滑条，退出

    ui->ProgressBar->setSliderPosition(position);//

    int   secs=position/1000;
    int   mins=secs/60;
    secs=secs % 60;
    positionTime=QString::asprintf("%d:%d",mins,secs);
    ui->LabRatio->setText(positionTime+"/"+durationTime);
}
void vdoplayer::GetShowVdoInterface()//显示视频界面
{
    this->show();
}

void vdoplayer::OpenFile()//打开文件
{
    QStringList fileNames = QFileDialog::getOpenFileNames(this, tr("Open Files"));
    addToPlaylist(fileNames);
}

void vdoplayer::PlayVideo()//播放视频
{
    m_playerState = QMediaPlayer::PlayingState;
    player->play();
}

void vdoplayer::StopVideo()//停止播放
{
    m_playerState = QMediaPlayer::StoppedState;
    player->stop();
}

void vdoplayer::FullScr()//按钮点击全屏
{
    if(m_playerState == QMediaPlayer::PlayingState)
    {
        videoWidget->setFullScreen(true);
//        videoWidget->setWindowFlags(Qt::Window);
//        videoWidget->showFullScreen();
//        this->resize(1200,1000);
//        this->maximumSize();
    }

}

void vdoplayer::addToPlaylist(const QStringList& fileNames)//添加视频
{
    foreach (QString const &argument, fileNames) {
        QFileInfo fileInfo(argument);
        if (fileInfo.exists()) {
            QUrl url = QUrl::fromLocalFile(fileInfo.absoluteFilePath());
            if (fileInfo.suffix().toLower() == QLatin1String("m3u")) {
                Playlist->load(url);
            } else
                Playlist->addMedia(url);
        } else {
            QUrl url(argument);
            if (url.isValid()) {
                Playlist->addMedia(url);
            }
        }
    }
    player->play();

}
void vdoplayer::mousePressEvent(QMouseEvent *event)//鼠标事件，单击控制暂停和继续播放
{
    if (event->button()==Qt::LeftButton)
    {
        if (player->state()==QMediaPlayer::PlayingState)
          player->pause();
        else
          player->play();
    }
    //QVideoWidget::mousePressEvent(event);

}

void vdoplayer::keyPressEvent(QKeyEvent *event)//按键事件，ESC退出全屏状态
{
    if ((event->key() == Qt::Key_Escape)&&(isFullScreen()))
    {
        videoWidget->setWindowFlags(Qt::SubWindow);
        this->move(300,500);
        resize(400,500);
        event->accept();
        //QVideoWidget::keyPressEvent(event);
    }
}

void vdoplayer::on_BtnBackHome_clicked()//回到主界面
{
    this->close();
    emit ShowHomeInterface();
}

void vdoplayer::onprogressBarvalueChanged(int value)//拖动进度条
{
    player->setPosition(value);
}

void vdoplayer::on_SoundBtn_clicked()//点击音量按键静音
{
    bool mute=player->isMuted();
    player->setMuted(!mute);
    if (mute)
        ui->SoundBtn->setIcon(QIcon(":/resources/vol.png"));
    else
        ui->SoundBtn->setIcon(QIcon(":/resources/mute.png"));
}

void vdoplayer::on_SliderVolumn_valueChanged(int value)//设置音量
{
    player->setVolume(value);
}
