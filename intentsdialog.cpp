/*
 * <one line to give the library's name and an idea of what it does.>
 * Copyright (C) 2013  <copyright holder> <email>
 * 
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 * 
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 * 
 */

#include "intentsdialog.h"
#include "ui_intentsdialog.h"
#include <QSettings>
#include <QIcon>
#include <QListWidgetItem>
#include <QDebug>

IntentsDialog::IntentsDialog(QString configFile) : QDialog(NULL)
{
    ui = new Ui::IntentsDialog;
    ui->setupUi(this);
    
    // load config file
    QSettings settings(configFile, QSettings::IniFormat);
    QString str = settings.value("icon_theme").toString();
    QIcon::setThemeName(str.isEmpty() ? "oxygen" : str);
    setWindowTitle(settings.value("title").toString());
    setWindowIcon(QIcon::fromTheme(settings.value("icon", "application-x-executable").toString()));
    ui->label->setText(settings.value("message").toString());
    int iconSize = settings.value("icon_size", 32).toInt();
    ui->listWidget->setIconSize(QSize(iconSize, iconSize));

    Q_FOREACH(QString group, settings.childGroups()) {
      settings.beginGroup(group);
      QString title = settings.value("name").toString();
      if(!title.isEmpty()) {
	QString iconName = settings.value("icon", "application-x-executable").toString();
	QString exec = settings.value("exec").toString();
	QIcon icon = QIcon::fromTheme(iconName);
	QListWidgetItem* item = new QListWidgetItem(icon, title);
	ui->listWidget->addItem(item);
      }
      settings.endGroup();
    }
    
    ui->listWidget->setCurrentRow(0);
}

IntentsDialog::~IntentsDialog()
{
    delete ui;
}

#include "intentsdialog.moc"
