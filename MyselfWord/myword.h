#ifndef MYWORD_H
#define MYWORD_H

#include <QtWidgets/QMainWindow>
#include "ui_myword.h"

class QMdiArea;
class QAction;
class QMenu;

class MyWord : public QMainWindow
{
	Q_OBJECT

public:
	MyWord(QWidget *parent = 0);
	~MyWord();

private:
	Ui::MyWordClass ui;

	QMdiArea * m_pMdiArea;

	QMenu * m_pFileMenu;

	QMenu * m_pEditMenu;

	QMenu * m_pFormatMenu;
	QMenu * m_pFontMenu;
	QMenu * m_pAlignMenu;

	QMenu * m_pWindowMenu;

	QMenu * m_pAboutMenu;

	QAction * m_pNewAct;
	QAction * m_pOpenAct;
	QAction * m_pSaveAct;
	QAction * m_pSaveAsAct;
	QAction * m_pPrintAct;
	QAction * m_pPrintPreviewAct;
	QAction * m_pExitAct;

	QAction * m_pUndoAct;
	QAction * m_pRedoAct;
	QAction * m_pCutAct;
	QAction * m_pCopyAct;
	QAction * m_pPasteAct;

	QAction * m_pBoldAct;
	QAction * m_pItalicAct;
	QAction * m_pUnderlineAct;
	QAction * m_pLeftAlignAct;
	QAction * m_pCenterAct;
	QAction * m_pRightAlignAct;
	QAction * m_pJustifyAct;
	QAction * m_pColorAct;

	QAction * m_pCloseAct;
	QAction * m_pCloseAllAct;
	QAction * m_pTileAct;
	QAction * m_pCascadeAct;
	QAction * m_pNextAct;
	QAction * m_pPreviousAct;
	QAction * m_pSeparatorAct;

	QAction * m_pAboutAct;
	QAction * m_pAboutQtAct;

private:
	void createActions();
	void createMenus();
	private slots:
	void textAligen(QAction*);
	void updateWindowMenu();
	void about();
};

#endif // MYWORD_H
