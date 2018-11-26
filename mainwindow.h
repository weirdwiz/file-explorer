#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDir>
#include <QListWidget>
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
  Q_OBJECT
public:
  explicit MainWindow(QWidget *parent = 0);
  void refresh();
private slots:
  void handleClick(QListWidgetItem *item);

private:
  QDir dir;
  QListWidget listWidget;
};

#endif // MAINWINDOW_H