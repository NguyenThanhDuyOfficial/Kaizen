#ifndef STYLEMANAGER_HPP
#define STYLEMANAGER_HPP

#include <QWidget>

class StyleManager {
public:
  StyleManager();
  static QIcon changeIconColor(const QString &svgFilePath, int width,
                               int height, const QColor &color);
  static QStringList *getPalette();
  static void createStyleSheet(QString templatePath, QString newThemePath);

private:
  static QStringList *paletteList;
};

#endif // !STYLEMANAGER_HPP
