#include "map.h"
#include <QJsonDocument>
#include <QJsonObject>

#include <QJsonArray>
#include <QFile>


QJsonArray Map::newMap(int numberOfMap) {
    if(numberOfMap == 1) {
        QString val;
        QFile file;
        file.setFileName(":/data/map.json");
        file.open(QIODevice::ReadOnly | QIODevice::Text);
        val = file.readAll();
        file.close();
        QJsonDocument d = QJsonDocument::fromJson(val.toUtf8());
        QJsonObject sett2 = d.object();
        QJsonValue value = sett2.value(QString("layers"));
        QJsonArray item = value[0].toObject().value(QString("data")).toArray();
        return (item);
    }
}
