/* ************************************************************************
 * Copyright (c) 2017 blueorbitz                                          *
 *                                                                        *
 * This file is part of QtOneSignal                                       *
 *                                                                        *
 * QtOneSignal is free software: you can redistribute it and/or modify    *
 * it under the terms of the GNU General Public License as published by   *
 * the Free Software Foundation, either version 3 of the License, or      *
 * (at your option) any later version.                                    *
 *                                                                        *
 * This program is distributed in the hope that it will be useful,        *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of         *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.                   *
 * See the GNU General Public License for more details.                   *
 *                                                                        *
 * You should have received a copy of the GNU General Public License      *
 * along with this program. If not, see <http://www.gnu.org/licenses/>.   *
 * ********************************************************************** */

#include "qonesignal.h"
#include <QQmlEngine>
#include <QDebug>

QOneSignal::QOneSignal(QObject *parent )
	: QObject(parent) {
    qDebug() << "Creating QOneSignal singleton Instance";
}

QOneSignal::~QOneSignal() {
	// nothing to do
}

void QOneSignal::registerQMLTypes()
{
    qmlRegisterSingletonType<QOneSignal>("QOneSignal", 1, 0, "QOneSignal", qOneSignalProvider);
}

QObject* QOneSignal::qOneSignalProvider(QQmlEngine *engine, QJSEngine *scriptEngine) {
    Q_UNUSED(engine)
    Q_UNUSED(scriptEngine)
    return QOneSignal::instance();
}

QOneSignal* QOneSignal::instance() {
    static QOneSignal* onesignal = new QOneSignal();
    return onesignal;
}

QString QOneSignal::notificationReceive() {
    return m_notificationReceive;
}

void QOneSignal::setNotificationReceive(QString message) {
    if (message != m_notificationReceive) {
        m_notificationReceive = message;
        emit notificationReceiveChanged(m_notificationReceive);
    }
}

QString QOneSignal::notificationOpen() {
    return m_notificationOpen;
}

void QOneSignal::setNotificationOpen(const QString message) {
    if (message != m_notificationOpen) {
        m_notificationOpen = message;
        emit notificationOpenChanged(m_notificationOpen);
    }
}

