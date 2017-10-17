#include "myword.h"
#include <QtWidgets>

MyWord::MyWord(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	m_pMdiArea = new QMdiArea;
	m_pMdiArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
	m_pMdiArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
	setCentralWidget(m_pMdiArea);
	move(200, 150);
	resize(800, 500);
	setWindowTitle(tr("My Word"));
	createActions();
	createMenus();
}

MyWord::~MyWord()
{

}

void MyWord::createActions()
{
	m_pNewAct = new QAction(tr("New"),this);
	m_pNewAct->setShortcut(QKeySequence::New);
	m_pNewAct->setToolTip(tr("New"));
	m_pNewAct->setStatusTip(tr("New an file"));

	m_pOpenAct = new QAction(tr("Open"), this);
	m_pOpenAct->setShortcut(QKeySequence::Open);
	m_pOpenAct->setToolTip(tr("Open"));
	m_pOpenAct->setStatusTip(tr("Open an file"));

	m_pSaveAct = new QAction(tr("Save"), this);
	m_pSaveAct->setShortcut(QKeySequence::Save);
	m_pSaveAct->setToolTip(tr("Save"));
	m_pSaveAct->setStatusTip(tr("Save file"));

	m_pSaveAsAct = new QAction(tr("Save As"), this);
	m_pSaveAsAct->setShortcut(QKeySequence::SaveAs);
	m_pSaveAsAct->setToolTip(tr("Save as"));
	m_pSaveAsAct->setStatusTip(tr("Save an file"));

	m_pPrintAct = new QAction(tr("Print"), this);
	m_pPrintAct->setShortcut(QKeySequence::Print);
	m_pPrintAct->setToolTip(tr("Print"));
	m_pPrintAct->setStatusTip(tr("Print"));
	
	m_pPrintPreviewAct = new QAction(tr("Print preview"), this);
	m_pPrintPreviewAct->setShortcut(QKeySequence::New);
	m_pPrintPreviewAct->setToolTip(tr("Print Preview"));
	m_pPrintPreviewAct->setStatusTip(tr("Print preview"));

	m_pExitAct = new QAction(tr("Exit"), this);
	m_pExitAct->setShortcut(QKeySequence::Quit);
	m_pExitAct->setToolTip(tr("Exit"));
	m_pExitAct->setStatusTip(tr("Exit"));
	QObject::connect(m_pExitAct, SIGNAL(trigged()), this, SLOT(closeAllWindows()));


	m_pUndoAct = new QAction(tr("Undo"), this);
	m_pUndoAct->setShortcut(QKeySequence::Undo);
	m_pUndoAct->setToolTip(tr("Undo"));
	m_pUndoAct->setStatusTip(tr("Undo"));

	m_pRedoAct = new QAction(tr("Redo"), this);
	m_pRedoAct->setShortcut(QKeySequence::Redo);
	m_pRedoAct->setToolTip(tr("Redo"));
	m_pRedoAct->setStatusTip(tr("Redo"));

	m_pCutAct = new QAction(tr("Cut"), this);
	m_pCutAct->setShortcut(QKeySequence::Cut);
	m_pCutAct->setToolTip(tr("Cut"));
	m_pCutAct->setStatusTip(tr("Cut"));

	m_pCopyAct = new QAction(tr("Copy"), this);
	m_pCopyAct->setShortcut(QKeySequence::Copy);
	m_pCopyAct->setToolTip(tr("Copy"));
	m_pCopyAct->setStatusTip(tr("Copy"));

	m_pPasteAct = new QAction(tr("Paste"), this);
	m_pPasteAct->setShortcut(QKeySequence::Paste);
	m_pPasteAct->setToolTip(tr("Paste"));
	m_pPasteAct->setStatusTip(tr("Paste"));


	m_pBoldAct = new QAction(tr("Bolb"), this);
	m_pBoldAct->setShortcut(QKeySequence::Bold);
	m_pBoldAct->setToolTip(tr("Bolb"));
	m_pBoldAct->setStatusTip(tr("Bolb"));
	QFont bfont;
	bfont.setBold(true);
	m_pBoldAct->setFont(bfont);

	m_pItalicAct = new QAction(tr("Italic"), this);
	m_pItalicAct->setShortcut(QKeySequence::Italic);
	m_pItalicAct->setToolTip(tr("Italic"));
	m_pItalicAct->setStatusTip(tr("Italic"));
	QFont ifont;
	ifont.setItalic(true);
	m_pItalicAct->setFont(ifont);

	m_pUnderlineAct = new QAction(tr("Underline"), this);
	m_pUnderlineAct->setShortcut(QKeySequence::Underline);
	m_pUnderlineAct->setToolTip(tr("Underline"));
	m_pUnderlineAct->setStatusTip(tr("Underline"));
	QFont ufont;
	ufont.setUnderline(true);
	m_pUnderlineAct->setFont(ufont);

	QActionGroup * pGrp = new QActionGroup(this);
	connect(pGrp, SIGNAL(triggered(QAction*)), this, SLOT(textAligen(QAction*)));

	if (QApplication::isLeftToRight())
	{
		m_pLeftAlignAct = new QAction(tr("Left(&L)"), this);
		m_pCenterAct = new QAction(tr("Center(&E)"), this);
		m_pRightAlignAct = new QAction(tr("Right(&R)"), this);
	}
	else
	{
		m_pRightAlignAct = new QAction(tr("Right(&R)"), this);
		m_pCenterAct = new QAction(tr("Center(&E)"), this);
		m_pLeftAlignAct = new QAction(tr("Left(&L)"), this);
	}
	m_pJustifyAct = new QAction(tr("Justify(&J)"), this);

	m_pLeftAlignAct->setShortcut(Qt::CTRL + Qt::Key_L);
	m_pLeftAlignAct->setCheckable(true);
	m_pLeftAlignAct->setToolTip(tr("LeftAlign"));
	m_pLeftAlignAct->setStatusTip(tr("LeftAlign"));

	m_pCenterAct->setShortcut(Qt::CTRL + Qt::Key_E);
	m_pCenterAct->setCheckable(true);
	m_pCenterAct->setToolTip(tr("Center"));
	m_pCenterAct->setStatusTip(tr("Center"));

	m_pRightAlignAct->setShortcut(Qt::CTRL + Qt::Key_R);
	m_pRightAlignAct->setCheckable(true);
	m_pRightAlignAct->setToolTip(tr("RightAlign"));
	m_pRightAlignAct->setStatusTip(tr("RightAlign"));

	m_pJustifyAct->setShortcut(Qt::CTRL + Qt::Key_J);
	m_pJustifyAct->setCheckable(true);
	m_pJustifyAct->setToolTip(tr("Justify"));
	m_pJustifyAct->setStatusTip(tr("Justify"));

	QPixmap pixMap(16, 16);
	pixMap.fill(Qt::red);
	m_pColorAct = new QAction(pixMap, tr("Color...(&C)"), this);
	m_pColorAct->setToolTip(tr("Color"));
	m_pColorAct->setStatusTip(tr("Set word color"));

	m_pCloseAct = new QAction(tr("Close(&O)"), this);
	m_pCloseAct->setStatusTip(tr("Close active subwindow"));
	connect(m_pCloseAct, SIGNAL(triggered()), this, SLOT(closeActiveSubWindows()));

	m_pCloseAllAct = new QAction(tr("Close All(&O)"), this);
	m_pCloseAllAct->setStatusTip(tr("Close all subwindow"));
	connect(m_pCloseAllAct, SIGNAL(triggered()), this, SLOT(closeAllSubWindows()));

	m_pTileAct = new QAction(tr("Tile(&O)"), this);
	m_pTileAct->setStatusTip(tr("Tile active subwindow"));
	connect(m_pTileAct, SIGNAL(triggered()), this, SLOT(tileSubWindows()));

	m_pCascadeAct = new QAction(tr("Cascade(&O)"), this);
	m_pCascadeAct->setStatusTip(tr("Cascade active subwindow"));
	connect(m_pCascadeAct, SIGNAL(triggered()), this, SLOT(cascadeSubWindows()));

	m_pNextAct = new QAction(tr("Next(&O)"), this);
	m_pNextAct->setShortcut(QKeySequence::NextChild);
	m_pNextAct->setStatusTip(tr("Next active subwindow"));
	connect(m_pNextAct, SIGNAL(triggered()), this, SLOT(activeNextSubWindows()));

	m_pPreviousAct = new QAction(tr("Previous(&O)"), this);
	m_pPreviousAct->setShortcut(QKeySequence::PreviousChild);
	m_pPreviousAct->setStatusTip(tr("Previous active subwindow"));
	connect(m_pPreviousAct, SIGNAL(triggered()), this, SLOT(activePreviousSubWindows()));

	m_pSeparatorAct = new QAction(this);
	m_pSeparatorAct->setSeparator(true);

	m_pAboutAct = new QAction(tr("About(&A)"), this);
	m_pAboutAct->setStatusTip(tr("About myword"));
	connect(m_pAboutAct, SIGNAL(triggered()), this, SLOT(about()));

	m_pAboutQtAct = new QAction(tr("About Qt(&Q)"), this);
	m_pAboutQtAct->setStatusTip(tr("About Qt"));
	connect(m_pAboutQtAct, SIGNAL(triggered()), this, SLOT(aboutQt()));
	
}

void MyWord::createMenus()
{
	m_pFileMenu = menuBar()->addMenu(tr("File(&F)")); 
	m_pFileMenu->addAction(m_pNewAct);
	m_pFileMenu->addAction(m_pOpenAct);
	m_pFileMenu->addAction(m_pSaveAct);
	m_pFileMenu->addAction(m_pSaveAsAct);
	m_pFileMenu->addAction(m_pPrintAct);
	m_pFileMenu->addAction(m_pPrintPreviewAct);
	m_pFileMenu->addAction(m_pExitAct);

	m_pEditMenu = menuBar()->addMenu(tr("Edit(&E)"));
	m_pEditMenu->addAction(m_pUndoAct);
	m_pEditMenu->addAction(m_pRedoAct);
	m_pEditMenu->addAction(m_pCutAct);
	m_pEditMenu->addAction(m_pCopyAct);
	m_pEditMenu->addAction(m_pPasteAct);

	m_pFormatMenu = menuBar()->addMenu(tr("Format(&O)"));
	m_pFontMenu = m_pFormatMenu->addMenu(tr("Font(&D)"));
	m_pAlignMenu = m_pFormatMenu->addMenu(tr("Aligen"));
	m_pFontMenu->addAction(m_pBoldAct);
	m_pFontMenu->addAction(m_pItalicAct);
	m_pFontMenu->addAction(m_pUnderlineAct);
	m_pAlignMenu->addAction(m_pLeftAlignAct);
	m_pAlignMenu->addAction(m_pCenterAct);
	m_pAlignMenu->addAction(m_pRightAlignAct);
	m_pAlignMenu->addAction(m_pJustifyAct);
	m_pAlignMenu->addAction(m_pColorAct);

	m_pWindowMenu = menuBar()->addMenu(tr("Window(&W)"));
	updateWindowMenu();
	connect(m_pWindowMenu, SIGNAL(aboutToShow()), this, SLOT(updateWindowMenu()));
	menuBar()->addSeparator();

	m_pAboutMenu = menuBar()->addMenu(tr("About(&A)"));
	m_pAboutMenu->addAction(m_pAboutAct);
	m_pAboutMenu->addAction(m_pAboutQtAct);
}

void MyWord::updateWindowMenu()
{
}

void MyWord::about()
{
	QMessageBox::about(this, tr("About"), tr("My Word1.0"));
}

void MyWord::textAligen(QAction* pAct)
{

}