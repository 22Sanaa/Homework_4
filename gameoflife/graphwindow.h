#ifndef GRAPHWINDOW_H
#define GRAPHWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class GraphWindow; }
QT_END_NAMESPACE

class GraphWindow : public QMainWindow
{
    Q_OBJECT

public:
    GraphWindow(QWidget *parent = nullptr);
    ~GraphWindow();

private slots:
    void on_stepButton_clicked();

    void on_playButton_clicked();

    void on_pauseButton_clicked();

    void on_horizontalSlider_sliderPressed(); // Slider pressed

    void on_horizontalSlider_sliderReleased(); // Slider released

    void on_horizontalSlider_rangeChanged(float min, float max); // Change the range of the slider

private:
    Ui::GraphWindow *ui;
};
#endif // GRAPHWINDOW_H
