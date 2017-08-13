#ifndef SHOWWIDGET_H
#define SHOWWIDGET_H

#include <QWidget>
#include <qlabel.h>
#include <QTextEdit>
#include <qimage.h>

class ShowWidget : public QWidget
{
	Q_OBJECT

public:
	explicit ShowWidget(QWidget *parent);
	~ShowWidget();
	QImage m_img;
	QLabel * m_pImageLabel;
	QTextEdit * m_pText;
signals:

	public slots:

private:
	
};

#endif // SHOWWIDGET_H
