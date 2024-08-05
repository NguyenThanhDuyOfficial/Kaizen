#include <QDebug>
#include <QFile>
#include <QPainter>
#include <QPalette>
#include <QStringList>
#include <QSvgRenderer>

#include <QTextStream>
#include <qlogging.h>

#include "styleManager.hpp"

StyleManager::StyleManager() {}
void StyleManager::createStyleSheet(QString templatePath,
                                    QString newThemePath) {
  QStringList *paletteList = StyleManager::getPalette();

  QFile file(templatePath);
  if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
    qDebug() << "Failed to open stylesheet file:" << templatePath;
    return;
  }
  QTextStream in(&file);

  QString styleSheet = in.readAll();
  styleSheet = styleSheet.arg(paletteList->at(0))
                   .arg(paletteList->at(1))
                   .arg(paletteList->at(2))
                   .arg(paletteList->at(3))
                   .arg(paletteList->at(4))
                   /*.arg(paletteList->at(5))*/
                   /*.arg(paletteList->at(6))*/
                   /*.arg(paletteList->at(7))*/
                   /*.arg(paletteList->at(8))*/
                   /*.arg(paletteList->at(9))*/
                   .arg(paletteList->at(10))
      /*.arg(paletteList->at(11))*/
      /*.arg(paletteList->at(12))*/
      /*.arg(paletteList->at(13))*/
      /*.arg(paletteList->at(14))*/
      /*.arg(paletteList->at(15))*/
      ;

  QFile newTheme(newThemePath);
  if (!newTheme.open(QIODevice::WriteOnly | QIODevice::Text)) {
    qDebug() << "Can't create theme:" << newTheme.errorString();
    return;
  }
  QTextStream out(&newTheme);
  out << styleSheet;
  newTheme.close();
}

QStringList *StyleManager::paletteList = nullptr;
QStringList *StyleManager::getPalette() {
  QStringList exampleList = {"#eff1f5", "#dce0e8", "#ccd0da", "#bcc0cc",
                             "#acb0be", "#9ca0b0", "#8c8fa1", "#7c7f93",
                             "#6c6f85", "#5c5f77", "#4c4f69", "#1e66f5",
                             "#40a02b", "#df8e1d", "#d20f39", "#dc8a78"};
  paletteList = new QStringList();
  for (const QString &color : exampleList) {
    paletteList->append(color);
  }
  return paletteList;
}
QIcon StyleManager::changeIconColor(const QString &svgFilePath, int width,
                                    int height, const QColor &color) {
  QSvgRenderer svgRenderer(svgFilePath);
  QPixmap pixmap(width, height);
  pixmap.fill(Qt::transparent);

  QPainter painter(&pixmap);
  svgRenderer.render(&painter);

  painter.setCompositionMode(QPainter::CompositionMode_SourceIn);
  painter.fillRect(pixmap.rect(), color);
  painter.end();

  return QIcon(pixmap);
}
