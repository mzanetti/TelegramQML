/*
    Copyright (C) 2014 Aseman
    http://aseman.co

    This project is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This project is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef TELEGRAMWALLPAPERSMODEL_H
#define TELEGRAMWALLPAPERSMODEL_H

#include "telegramqml_global.h"
#include "tgabstractlistmodel.h"

class TelegramQml;
class TelegramWallpapersModelPrivate;
class TELEGRAMQMLSHARED_EXPORT TelegramWallpapersModel : public TgAbstractListModel
{
    Q_OBJECT
    Q_ENUMS(WallpapersRoles)

    Q_PROPERTY(TelegramQml* telegram READ telegram WRITE setTelegram NOTIFY telegramChanged)
    Q_PROPERTY(int count READ count NOTIFY countChanged)
    Q_PROPERTY(bool initializing READ initializing NOTIFY initializingChanged)

public:
    enum WallpapersRoles {
        ItemRole = Qt::UserRole
    };

    TelegramWallpapersModel(QObject *parent = 0);
    ~TelegramWallpapersModel();

    TelegramQml *telegram() const;
    void setTelegram(TelegramQml *tg );

    qint64 id( const QModelIndex &index ) const;
    int rowCount(const QModelIndex & parent = QModelIndex()) const;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

    QHash<qint32,QByteArray> roleNames() const;

    int count() const;
    bool initializing() const;

Q_SIGNALS:
    void telegramChanged();
    void countChanged();
    void initializingChanged();

private Q_SLOTS:
    void recheck();
    void wallpapersChanged();

protected:
    TelegramWallpapersModelPrivate *p;
};

#endif // TELEGRAMWALLPAPERSMODEL_H
