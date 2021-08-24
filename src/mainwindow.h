//    Recon Plotter
//    Copyright (C) 2021  Oleksandr Kolodkin <alexandr.kolodkin@gmail.com>
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <http://www.gnu.org/licenses/>.

#pragma once

#include <QList>
#include <QCloseEvent>
#include <QMainWindow>
#include <QProgressBar>
#include <QPrinter>
#include <QLocalServer>
#include "datafile.h"
#include "recontextfile.h"
#include "chartwindow.h"
#include "signalsmodel.h"
#include "colordelegate.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
	class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = nullptr);
	~MainWindow();

	void saveSession();
	void restoreSession();

public slots:
	bool openFile(const QString filename);

private slots:
	void closeEvent(QCloseEvent *event);
	bool importReconTextFile(QString filename);
	void updateFileMenu();
	void updatePlotMenu();
	void updateWindowMenu();
	void open();
	void import();
	void fullScreen(bool state);

private:
	Ui::MainWindow *ui;
	SignalsModel *mSignalsModel;
	QLocalServer *mServer;
    ColorDelegate *mColorDelegate;

	ChartWindow *activeMdiChild() const;
    bool isFileAlreadyOpen(const QString filename);
    QStringList filesFromSettings(QString option);
};
