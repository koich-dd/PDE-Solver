#ifndef HEATMAPWIDGET_H
#define HEATMAPWIDGET_H

#include <QWidget>
#include <vector>

class HeatmapWidget : public QWidget {
    Q_OBJECT
public:
    explicit HeatmapWidget(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    std::vector<std::vector<double>> gridData;
    void loadGridData(const std::string &filename);
    QColor interpolateColor(const QColor &startColor, const QColor &endColor, double value);
};

#endif // HEATMAPWIDGET_H
