#include "heatmapwidget.h"
#include <QPainter>
#include <QColor>
#include <fstream>
#include <sstream>
#include <iostream>

HeatmapWidget::HeatmapWidget(QWidget *parent)
    : QWidget(parent) {
    // Load the grid data from the CSV file
    loadGridData("../build/2d_heat_equation.csv");
}

void HeatmapWidget::paintEvent(QPaintEvent *event) {
    QPainter painter(this);

    int rows = gridData.size();
    int cols = gridData[0].size();

    int cellWidth = width() / cols;
    int cellHeight = height() / rows;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            double value = gridData[i][j];

            // Use a color based on the value
            QColor color = getColorForValue(value);
            
            painter.fillRect(j * cellWidth, i * cellHeight, cellWidth, cellHeight, color);
        }
    }
}

#include <locale>

void HeatmapWidget::loadGridData(const std::string &filename) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return;
    }

    // Set the locale to "C" to ensure period as decimal separator
    std::locale::global(std::locale("C"));

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream lineStream(line);
        std::string cell;
        std::vector<double> row;

        while (std::getline(lineStream, cell, ' ')) {
            // Remove leading/trailing spaces
            cell.erase(0, cell.find_first_not_of(' '));
            cell.erase(cell.find_last_not_of(' ') + 1);

            std::cout << "  Cell value before conversion: '" << cell << "'" << std::endl;

            try {
                double value = std::stod(cell);
                std::cout << "  Converted to double: " << value << std::endl;
                row.push_back(value);
            } catch (const std::invalid_argument& e) {
                std::cerr << "Error: Invalid number in file. Cell: '" << cell << "'" << std::endl;
                row.push_back(0.0);
            } catch (const std::out_of_range& e) {
                std::cerr << "Error: Number out of range in file. Cell: '" << cell << "'" << std::endl;
                row.push_back(0.0);
            }
        }

        if (!row.empty()) {
            gridData.push_back(row);
        } else {
            std::cerr << "Warning: Empty row detected." << std::endl;
        }
    }

    if (gridData.empty()) {
        std::cerr << "Error: No valid data found in the file." << std::endl;
    } else {
        std::cout << "Grid data successfully loaded. Rows: " << gridData.size() 
                  << ", Cols: " << (gridData[0].size()) << std::endl;
    }
}

void HeatmapWidget::reloadData() {
    gridData.clear();  // Clear the existing data
    loadGridData("../build/2d_heat_equation.csv");  // Reload the data
    update();  // Repaint the widget
}



// Function to map a value between 0 and 1 to a color
QColor HeatmapWidget::getColorForValue(double value) {
    // Map value from 0.0 (blue) to 1.0 (red)
    int red = static_cast<int>(255 * value);
    int blue = static_cast<int>(255 * (1.0 - value));
    return QColor(red, 0, blue);
}
