#ifndef IMAGEPROCESSOR_H
#define IMAGEPROCESSOR_H

#include <QtWidgets/QMainWindow>
#include <QImage>
#include <QLabel>
#include <QMenu>
#include <QMenuBar>
#include <qaction.h>
#include <QComboBox>
#include <QSpinBox>
#include <qtoolbar.h>
#include <QFontComboBox>
#include <QToolButton>
#include <QTextCharFormat>
#include "showwidget.h"

class ImageProcessor : public QMainWindow
{
	Q_OBJECT

public:
	ImageProcessor(QWidget *parent = 0);
	~ImageProcessor();

public:
	void creatActions();
	void creatMenus();
	void creatToolBars();

	void loadFiles(QString filename);
	void mergeFormat(QTextCharFormat);

	protected slots:
	void ShowNewFile();
	void ShowOpenFile();

	void ShowFontComboBox(QString strCombo);
	void ShowSizeSpinBox(QString strSpin);
	void ShowBoldBtn();
	void ShowItalicBtn();
	void ShowUnderLineBtn();
	void ShowColorBtn();

	void ShowCurrentCharFormatChanged(QTextCharFormat&);
private:
	QMenu * m_pFileMenu;
	QMenu * m_pZoomMenu;
	QMenu * m_pRotateMenu;
	QMenu * m_pMirrorMenu;

	QImage  m_Img;
	QString m_fileName;
	ShowWidget * m_pShowWidget;

	QAction * m_pOpenFileAction;
	QAction * m_pNewFileAction;
	QAction * m_pPrintTextAction;
	QAction * m_pPrintImgAction;
	QAction * m_pExitAction;

	QAction * m_pCopyAction;
	QAction * m_pCutAction;
	QAction * m_pPasteAction;
	QAction * m_pAboutAction;
	QAction * m_pZoomInAction;
	QAction * m_pZoomOutAction;

	QAction * m_pRotate90Action;
	QAction * m_pRotate180Action;
	QAction * m_pRotate270Action;
	
	QAction * m_pMirrorVAction;
	QAction * m_pMirrorHAction;
	
	QAction * m_pUndoHAction;
	QAction * m_pRedoHAction;

	QToolBar * m_pFileTool;
	QToolBar * m_pZoomTool;
	QToolBar * m_pRotateTool;
	QToolBar * m_pMirrorTool;

	QToolBar * m_pDoTool;

	QLabel * m_pFontLabel1;
	QFontComboBox * m_pFontComboBox;
	QLabel * m_pFontLabel2;
	QComboBox * m_pSizeComboBox;
	QToolButton * m_pBoldBtn;
	QToolButton * m_pItalicBtn;
	QToolButton * m_pUnderLineBtn;
	QToolButton * m_pColorBtn;

	QToolBar * m_pFontToolBar;

};

#endif // IMAGEPROCESSOR_H
