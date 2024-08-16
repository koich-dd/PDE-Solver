#ifndef HEATMAPWIDGET_H
#define HEATMAPWIDGET_H

#include <QWidget>
#include <vector>

class HeatmapWidget : public QWidget {
    Q_OBJECT
public:
    explicit HeatmapWidget(QWidget *parent = nullptr);
    void reloadData();

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    std::vector<std::vector<double>> gridData;
    void loadGridData(const std::string &filename);
    QColor getColorForValue(double value);
};

#endif // HEATMAPWIDGET_H
