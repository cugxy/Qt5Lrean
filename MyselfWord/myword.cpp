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
}

MyWord::~MyWord()
{

}

void MyWord::createActions()
{
	m_pNewAct = new QAction(this);
	m_pNewAct->setShortcut(QKeySequence::New);
	m_pNewAct->setToolTip(tr("New"));
	m_pNewAct->setStatusTip(tr("New an file"));

	m_pOpenAct = new QAction(this);
	m_pOpenAct->setShortcut(QKeySequence::Open);
	m_pOpenAct->setToolTip(tr("Open"));
	m_pOpenAct->setStatusTip(tr("Open an file"));

	m_pSaveAct = new QAction(this);
	m_pSaveAct->setShortcut(QKeySequence::Save);
	m_pSaveAct->setToolTip(tr("Save"));
	m_pSaveAct->setStatusTip(tr("Save file"));

	m_pSaveAsAct = new QAction(this);
	m_pSaveAsAct->setShortcut(QKeySequence::SaveAs);
	m_pSaveAsAct->setToolTip(tr("Save as"));
	m_pSaveAsAct->setStatusTip(tr("Save an file"));

	m_pPrintAct = new QAction(this);
	m_pPrintAct->setShortcut(QKeySequence::Print);
	m_pPrintAct->setToolTip(tr("Print"));
	m_pPrintAct->setStatusTip(tr("Print"));
	
	m_pPrintPreviewAct = new QAction(this);
	m_pPrintPreviewAct->setShortcut(QKeySequence::New);
	m_pPrintPreviewAct->setToolTip(tr("Print Preview"));
	m_pPrintPreviewAct->setStatusTip(tr("Print preview"));

	m_pExitAct = new QAction(this);
	m_pExitAct->setShortcut(QKeySequence::Quit);
	m_pExitAct->setToolTip(tr("Exit"));
	m_pExitAct->setStatusTip(tr("Exit"));
	QObject::connect(m_pExitAct, SIGNAL(trigged()), this, SLOT(closeAllWindows()));


	m_pUndoAct = new QAction(this);
	m_pUndoAct->setShortcut(QKeySequence::New);
	m_pUndoAct->setToolTip(tr("Undo"));
	m_pUndoAct->setStatusTip(tr("Undo"));

	m_pRedoAct = new QAction(this);
	m_pRedoAct->setShortcut(QKeySequence::New);
	m_pRedoAct->setToolTip(tr("Redo"));
	m_pRedoAct->setStatusTip(tr("Redo"));

	m_pCutAct = new QAction(this);
	m_pCutAct->setShortcut(QKeySequence::New);
	m_pCutAct->setToolTip(tr("Cut"));
	m_pCutAct->setStatusTip(tr("Cut"));

	m_pCopyAct = new QAction(this);
	m_pCopyAct->setShortcut(QKeySequence::New);
	m_pCopyAct->setToolTip(tr("Copy"));
	m_pCopyAct->setStatusTip(tr("Copy"));

	m_pPasteAct = new QAction(this);
	m_pPasteAct->setShortcut(QKeySequence::New);
	m_pPasteAct->setToolTip(tr("Paste"));
	m_pPasteAct->setStatusTip(tr("Paste"));

}

void MyWord::createMenus()
{
	m_pFileMenu = menuBar()->addMenu(tr("File"));
	m_pFileMenu->addAction(m_pNewAct);
	m_pFileMenu->addAction(m_pOpenAct);
	m_pFileMenu->addAction(m_pSaveAct);
	m_pFileMenu->addAction(m_pSaveAsAct);
	m_pFileMenu->addAction(m_pPrintAct);
	m_pFileMenu->addAction(m_pPrintPreviewAct);
	m_pFileMenu->addAction(m_pExitAct);

	m_pEditMenu = menuBar()->addMenu(tr("Edit"));
	m_pEditMenu->addAction(m_pUndoAct);
	m_pEditMenu->addAction(m_pRedoAct);
	m_pEditMenu->addAction(m_pCutAct);
	m_pEditMenu->addAction(m_pCopyAct);
	m_pEditMenu->addAction(m_pPasteAct);
}										
