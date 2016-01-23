#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMap>
#include <QPolygonF>
#include <QGraphicsScene>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void drawSpine();
    enum Vertebrae { L1, L2, L3, L4, L5, S1 };
    void showEvent(QShowEvent *);
    
private:
    Ui::MainWindow *ui;
    QMap<Vertebrae, QPolygonF> _vPolys;
    QGraphicsScene _scene;
    static QMap<Vertebrae, QPolygonF> iVertPolys;
    static QMap<Vertebrae, QString> vertLabels;
};

#endif // MAINWINDOW_H
