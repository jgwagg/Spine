#include "MainWindow.h"
#include "ui_MainWindow.h"


namespace { 
static QColor Vertebrae_Color = QColor(212,212,212);
// starting values
QVector<QPointF> iL1{{820,142},{679,162},{700,278},{839,254}};
QVector<QPointF> iL2{{879,298},{706,301},{717,416},{866,409}};
QVector<QPointF> iL3{{875,461},{718,443},{705,558},{866,579}};
QVector<QPointF> iL4{{858,638},{713,584},{686,681},{824,746}};
QVector<QPointF> iL5{{794,794},{670,711},{616,801},{721,891}};
QVector<QPointF> iS1{{700,922},{607,819},{523,895},{616,998}};
}
QMap<MainWindow::Vertebrae, QPolygonF> MainWindow::iVertPolys{
    {L1,iL1}, {L2,iL2}, {L3,iL3}, {L4,iL4}, {L5,iL5}, {S1,iS1} };


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    _vPolys(iVertPolys),
    _scene(this)
{
    ui->setupUi(this);
    drawSpine();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::drawSpine()
{
    QPen pen(Qt::NoPen);    
    QBrush vertBrush;
    vertBrush.setColor(Vertebrae_Color);
    vertBrush.setStyle(Qt::SolidPattern);
    for(auto p : _vPolys)
    {
        _scene.addPolygon(p, pen, vertBrush);
    }
    ui->graphicsView->setScene(&_scene);
//    ui->graphicsView->fitInView(_scene.itemsBoundingRect(),Qt::KeepAspectRatio);
//    ui->graphicsView->fitInView(_scene.sceneRect(),Qt::KeepAspectRatio);
    ui->graphicsView->show();
    
}
