#include "heatmapwidget.h"
#include <QPainter>
#include <QColor>
#include <fstream>
#include <sstream>
#include <iostream>

HeatmapWidget::HeatmapWidget(QWidget *parent)
    : QWidget(parent) {
    // Load the grid data from the CSV file
    loadGridData("../build/grid_data.csv");
}

void HeatmapWidget::paintEvent(QPaintEvent *event) {
    QPainter painter(this);

    // Set up the color gradient
    QColor startColor = Qt::blue;
    QColor endColor = Qt::red;

    int rows = gridData.size();
    int cols = gridData[0].size();
    
    int cellWidth = width() / cols;
    int cellHeight = height() / rows;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            double value = gridData[i][j];

            // Interpolate between startColor and endColor based on value
            QColor color = interpolateColor(startColor, endColor, value);
            
            painter.fillRect(j * cellWidth, i * cellHeight, cellWidth, cellHeight, color);
        }
    }
}

void HeatmapWidget::loadGridData(const std::string &filename) {
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream lineStream(line);
        std::string cell;
        std::vector<double> row;
        while (std::getline(lineStream, cell, ' ')) {
            row.push_back(std::stod(cell));
        }
        gridData.push_back(row);
    }
}

QColor HeatmapWidget::interpolateColor(const QColor &startColor, const QColor &endColor, double value) {
    int red = startColor.red() + value * (endColor.red() - startColor.red());
    int green = startColor.green() + value * (endColor.green() - startColor.green());
    int blue = startColor.blue() + value * (endColor.blue() - startColor.blue());
    return QColor(red, green, blue);
}
