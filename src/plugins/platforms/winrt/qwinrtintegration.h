/****************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the plugins of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL3$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see http://www.qt.io/terms-conditions. For further
** information use the contact form at http://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 3 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPLv3 included in the
** packaging of this file. Please review the following information to
** ensure the GNU Lesser General Public License version 3 requirements
** will be met: https://www.gnu.org/licenses/lgpl.html.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 2.0 or later as published by the Free
** Software Foundation and appearing in the file LICENSE.GPL included in
** the packaging of this file. Please review the following information to
** ensure the GNU General Public License version 2.0 requirements will be
** met: http://www.gnu.org/licenses/gpl-2.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QWINRTINTEGRATION_H
#define QWINRTINTEGRATION_H

#include <qpa/qplatformintegration.h>

QT_BEGIN_NAMESPACE

class QAbstractEventDispatcher;
class QWinRTScreen;

class QWinRTIntegration : public QPlatformIntegration
{
private:
    explicit QWinRTIntegration();
public:
    ~QWinRTIntegration();

    static QWinRTIntegration *create()
    {
        QWinRTIntegration *integration = new QWinRTIntegration;
        return integration->m_success ? integration : 0;
    }

    bool hasCapability(QPlatformIntegration::Capability cap) const;
    QVariant styleHint(StyleHint hint) const;

    QPlatformWindow *createPlatformWindow(QWindow *window) const;
    QPlatformBackingStore *createPlatformBackingStore(QWindow *window) const;
    QPlatformOpenGLContext *createPlatformOpenGLContext(QOpenGLContext *context) const;
    QAbstractEventDispatcher *createEventDispatcher() const;
    QPlatformFontDatabase *fontDatabase() const;
    QPlatformInputContext *inputContext() const;
    QPlatformServices *services() const;
    Qt::KeyboardModifiers queryKeyboardModifiers() const;

    QStringList themeNames() const;
    QPlatformTheme *createPlatformTheme(const QString &name) const;
private:
    bool m_success;
    QWinRTScreen *m_screen;
    QPlatformFontDatabase *m_fontDatabase;
    QPlatformServices *m_services;
};

QT_END_NAMESPACE

#endif // QWINRTINTEGRATION_H
