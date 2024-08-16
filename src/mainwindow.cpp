#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include "Control.h"
#include "heatmapwidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Initialize UI elements
    xLineEdit = ui->lineEdit;
    yLineEdit = ui->lineEdit_2;
    solverComboBox = ui->comboBox;
    runButton = ui->pushButton;

    // Populate the solver combo box
    solverComboBox->addItem("Jacobi");
    solverComboBox->addItem("GaussSeidel");

    // Connect the run button to the slot
    connect(runButton, &QPushButton::clicked, this, &MainWindow::on_runButton_clicked);

    // Add the HeatmapWidget to the second tab
    HeatmapWidget *heatmapWidget = new HeatmapWidget(this);
    ui->tabWidget->addTab(heatmapWidget, "Heatmap");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_runButton_clicked() {

    // Read the input values
    int xNodes = xLineEdit->text().toInt();
    int yNodes = yLineEdit->text().toInt();
    QString solverType = solverComboBox->currentText();

    // Simple validation
    if (xNodes <= 0 || yNodes <= 0) {
        QMessageBox::warning(this, "Input Error", "Please enter valid positive integers for x and y.");
        return;
    }

    // Call function to run the solver
    runSolver(xNodes, yNodes, solverType);

    // Show a message box after running the solver
    QMessageBox::information(this, "Success", "Solver run successfully!");
}

void MainWindow::runSolver(int x, int y, const QString &solverType) {
    run(x, y, solverType.toStdString());

    // Here we just print the values for demonstration
    // qDebug() << "Running solver with x =" << x << ", y =" << y << ", solver =" << solverType;
}
