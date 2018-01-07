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
#ifdef __ANDROID__

#include "qonesignal.h"
#include <jni.h>
#include <QtAndroidExtras>

const QString activityClass(".QOneSignalBinding");
const QString packageName("org.pwf.qtonesignal");

void QOneSignal::sendTag(QString key, QString value)
{
    QAndroidJniObject jkey = QAndroidJniObject::fromString(key);
    QAndroidJniObject jvalue = QAndroidJniObject::fromString(value);

    QByteArray className = QString(packageName + activityClass).toLatin1();
    QAndroidJniObject::callStaticMethod<void>(
        className, "sendTag", "(Ljava/lang/String;Ljava/lang/String;)V",
        jkey.object<jstring>(),
        jvalue.object<jstring>());
}

void QOneSignal::deleteTag(QString key)
{
    QAndroidJniObject jkey = QAndroidJniObject::fromString(key);

    QByteArray className = QString(packageName + activityClass).toLatin1();
    QAndroidJniObject::callStaticMethod<void>(
        className, "deleteTag", "(Ljava/lang/String;)V",
        jkey.object<jstring>());
}

static void cppNotificationReceived(JNIEnv *, jclass /*clazz*/, jstring s)
{
    QAndroidJniObject javaRetObj = (QAndroidJniObject)s;

    QString javastring = javaRetObj.toString();
    emit QOneSignal::instance()->setNotificationReceive(javastring);
}

static void cppNotificationOpened(JNIEnv *, jclass /*clazz*/, jstring s)
{
    QAndroidJniObject javaRetObj = (QAndroidJniObject)s;

    QString javastring = javaRetObj.toString();
    emit QOneSignal::instance()->setNotificationOpen(javastring);
}

static JNINativeMethod methods[] = {
    {"notificationReceive", "(Ljava/lang/String;)V", (void *)cppNotificationReceived},
    {"notificationOpen", "(Ljava/lang/String;)V", (void *)cppNotificationOpened},
};

jint JNICALL JNI_OnLoad(JavaVM *vm, void *)
{
    JNIEnv *env;
    if (vm->GetEnv(reinterpret_cast<void **>(&env), JNI_VERSION_1_4) != JNI_OK)
        return JNI_FALSE;

    QString qnativeClass = packageName + activityClass;
    qnativeClass = qnativeClass.replace(".", "/");
    QByteArray ba = qnativeClass.toLatin1();
    const char *pzsNativeClass = ba.data();

    jclass clazz = env->FindClass(pzsNativeClass);
    if (env->RegisterNatives(clazz, methods, sizeof(methods) / sizeof(methods[0])) < 0)
        return JNI_FALSE;

    return JNI_VERSION_1_4;
}

#endif
