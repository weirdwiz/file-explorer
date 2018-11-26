#include "mainwindow.h"

#include <QCoreApplication>
#include <QFileInfo>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
  for (QFileInfo info : dir.drives()) {
    char *filePath = info.absoluteFilePath().toLocal8Bit().data();
    new QListWidgetItem(tr(filePath), &listWidget);
  }
  connect(&listWidget, SIGNAL(itemDoubleClicked(QListWidgetItem *)), this,
          SLOT(handleClick(QListWidgetItem *)));
}

void MainWindow::handleClick(QListWidgetItem *item) {
  dir.setPath(item->text());
  refresh();
}

void MainWindow::refresh() {
  listWidget.clear();
  for (QFileInfo info : dir.entryInfoList()) {
    char *filePath = info.absoluteFilePath().toLocal8Bit().data();
    new QListWidgetItem(tr(filePath), &listWidget);
  }
}