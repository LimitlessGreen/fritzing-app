/*******************************************************************

Part of the Fritzing project - http://fritzing.org
Copyright (c) 2007-2019 Fritzing

Fritzing is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Fritzing is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Fritzing.  If not, see <http://www.gnu.org/licenses/>.

********************************************************************/


#ifndef DEBUGDIALOG_H
#define DEBUGDIALOG_H

#include <QDialog>
#include <QEvent>
#include <QTextEdit>
#include <QFile>
#include <QPointer>

#include "utils/misc.h"

class DebugDialog : public QDialog
{
	Q_OBJECT

private:
	DebugDialog(QWidget *parent = 0);
	~DebugDialog();

public:
	enum DebugLevel {
		Debug,
		Info,
		Warning,
		Error
	};

public:
	static void debug(QString, const QPointF &point, DebugLevel = Debug, QObject * ancestor = 0);
	static void debug(QString, const QRectF &rect, DebugLevel = Debug, QObject * ancestor = 0);
	static void debug(QString, const QPoint &point, DebugLevel = Debug, QObject * ancestor = 0);
	static void debug(QString, const QRect &rect, DebugLevel = Debug, QObject * ancestor = 0);
	static void debug(QString, DebugLevel = Debug, QObject * ancestor = 0);
	static void hideDebug();
	static void showDebug();
	static void closeDebug();
	static bool visible();
	static bool connectToBroadcast(QObject * receiver, const char* slot);
	static void setDebugLevel(DebugLevel);
	static void cleanup();
	static void setEnabled(bool);
	static bool enabled();

	static QString createKeyTag(const QKeyEvent *event);
protected:
	bool event ( QEvent * e );
	void resizeEvent ( QResizeEvent * event );

protected:
	static DebugDialog* singleton;
	static QFile m_file;
	static bool m_enabled;

	QPointer<QTextEdit> m_textEdit;
	DebugLevel m_debugLevel;

Q_SIGNALS:
	void debugBroadcast(const QString & message, DebugDialog::DebugLevel, QObject * ancestor);
};

#endif
