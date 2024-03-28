#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include "about.h"
#include "graphique.h"
#include "param.h"
#include "port.h"
#include <QMainWindow>
#include "option.h"
#include "console.h"
#include "qlabel.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void Traitement(const QString& data);
    void checkTrames();
private slots:
    void on_actionOptions_triggered();

    void on_actionQuitter_triggered();

    void on_actionConsole_triggered();
    void on_actionA_propos_triggered();

    void on_actionGraphique_triggered();

protected:
    void showEvent(QShowEvent *ev);
    void timerEvent(QTimerEvent *event);
private:
    Ui::MainWindow *ui;
    QLabel *StateLabel;
    Port com;
    option *Option;
    console *Console;
    about *About;
    bool isFirstConnexion;
    graphique *Graphique;
    Settings param;
    QTimer *checkTimer;
    bool trameRecue;
};
#endif // MAINWINDOW_H
