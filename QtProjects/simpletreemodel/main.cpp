/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "treemodel.h"

#include <QApplication>
#include <QFile>
#include <QTreeView>
#include <QList>
#include <QString>
#include <QTextStream>
#include <QFile>
#include <QDebug>

void GetData(QVector<QVariant> &headerData, QMap<QString,TreeGroupData> &treeGroupData);


int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(simpletreemodel);

    QApplication app(argc, argv);
    QVector<QVariant>  headerData;
    QMap<QString,TreeGroupData> treeGroupData;
    GetData(headerData, treeGroupData);

    QStringList data;

    TreeModel model(headerData, treeGroupData);
    //file.close();

    QTreeView view;
    view.setModel(&model);
    view.setWindowTitle(QObject::tr("Simple Tree Model"));
    view.show();
    return app.exec();
}

void GetData(QVector<QVariant> &headerData, QMap<QString,TreeGroupData> &treeGroupData)
{


    QFile file("/Users/mac/Desktop/IAH512__Chamber1.csv");
    if (!file.open(QIODevice::ReadOnly))
    {
        qDebug() << "fail to open file";
        return;
    }
     QTextStream data(&file);

    QString line;
    //QStringList headerData;
    //QMap<QString,TreeGroupData> treeGroupData;
    if(!data.atEnd())
    {
        line = data.readLine();
//        QStringList list = line.split(",");
//        headerData << list; //获取Title
        headerData << "TID"<<"DESCRIPTION"<<"FUNCTION"<<"TIMEOUT"
                   <<"PARAM1"<<"PARAM2"<<"UNIT"<<"LOW"<<"HIGH"<<"KEY"<<"VAL";
    }

    while (!data.atEnd())
    {
        line = data.readLine();
        QStringList list = line.split(",");
        QString groupName;

         groupName = list[0];
         QVector<QVariant> lineData;
        for(int i = 1 ; i < list.size() ; ++i) //skip group data
        {
            lineData << list[i];
        }
         treeGroupData[groupName].push_back(lineData);

    }
    qDebug() << "read all file";
}
