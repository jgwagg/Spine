#include <QGraphicsItem>
#include <QMetaEnum>

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
    QBrush vertBrush(Vertebrae_Color, Qt::SolidPattern);
    QFont sansFont("Helvetica", 12, QFont::Bold);
    for(QMap<Vertebrae, QPolygonF>::iterator& kv = _vPolys.begin(); kv != _vPolys.end(); ++kv)
    {
        _scene.addPolygon(kv.value(), pen, vertBrush);
        auto gsti = _scene.addSimpleText(vertebraeToString(kv.key()));
        gsti->setPos(kv.value().boundingRect().center() - gsti->boundingRect().center());
        gsti->setFont(sansFont);
    }
    ui->graphicsView->setScene(&_scene);
    ui->graphicsView->show();
}

const char *MainWindow::vertebraeToString(MainWindow::Vertebrae v)
{
    const char* ret = QMetaEnum::fromType<MainWindow::Vertebrae>().valueToKey(v);
    return (ret ? ret : "invalid");
}

void MainWindow::showEvent(QShowEvent *)
{
    ui->graphicsView->fitInView(_scene.itemsBoundingRect(),Qt::KeepAspectRatio);    
}
