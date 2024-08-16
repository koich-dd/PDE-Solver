#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>

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
    void on_runButton_clicked();
    void runSolver(int x, int y, const QString &solverType);

private:
    Ui::MainWindow *ui;

    // Declare pointers to the UI elements
    QLineEdit *xLineEdit;
    QLineEdit *yLineEdit;
    QComboBox *solverComboBox;
    QPushButton *runButton;
};
#endif // MAINWINDOW_H
