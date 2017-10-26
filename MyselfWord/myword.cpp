#include "myword.h"
#include "mychild.h"
#include <QtWidgets>
#include <QMdiSubWindow>
#include <QSignalMapper>

MyWord::MyWord(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	move(200, 150);
	resize(800, 500);
	setWindowTitle(tr("My Word"));
	m_pMdiArea = new QMdiArea;
	m_pMdiArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
	m_pMdiArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
	setCentralWidget(m_pMdiArea);
	createActions();
	createMenus();
	connect(m_pMdiArea, SIGNAL(subWindowActivated(QMdiSubWindow*)), this, SLOT(slotUpdateMenu()));
	slotUpdateMenu();
	m_pWindowMapper = new QSignalMapper(this);
	connect(m_pWindowMapper, SIGNAL(mapped(QWidget*)), this, SLOT(slotSetActiveSubWindow(QWidget*)));

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
	connect(m_pNewAct, SIGNAL(triggered()), this, SLOT(slotFileNew()));

	m_pOpenAct = new QAction(tr("Open"), this);
	m_pOpenAct->setShortcut(QKeySequence::Open);
	m_pOpenAct->setToolTip(tr("Open"));
	m_pOpenAct->setStatusTip(tr("Open an file"));
	connect(m_pOpenAct, SIGNAL(triggered()), this, SLOT(slotFileOpen()));

	m_pSaveAct = new QAction(tr("Save"), this);
	m_pSaveAct->setShortcut(QKeySequence::Save);
	m_pSaveAct->setToolTip(tr("Save"));
	m_pSaveAct->setStatusTip(tr("Save file"));
	connect(m_pSaveAct, SIGNAL(triggered()), this, SLOT(slotFileSave()));

	m_pSaveAsAct = new QAction(tr("Save As"), this);
	m_pSaveAsAct->setShortcut(QKeySequence::SaveAs);
	m_pSaveAsAct->setToolTip(tr("Save as"));
	m_pSaveAsAct->setStatusTip(tr("Save an file"));
	connect(m_pSaveAsAct, SIGNAL(triggered()), this, SLOT(slotFileSaveAs()));

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
	QObject::connect(m_pUndoAct, SIGNAL(trigged()), this, SLOT(slotUndo()));

	m_pRedoAct = new QAction(tr("Redo"), this);
	m_pRedoAct->setShortcut(QKeySequence::Redo);
	m_pRedoAct->setToolTip(tr("Redo"));
	m_pRedoAct->setStatusTip(tr("Redo"));
	QObject::connect(m_pRedoAct, SIGNAL(trigged()), this, SLOT(slotRedo()));

	m_pCutAct = new QAction(tr("Cut"), this);
	m_pCutAct->setShortcut(QKeySequence::Cut);
	m_pCutAct->setToolTip(tr("Cut"));
	m_pCutAct->setStatusTip(tr("Cut"));
	QObject::connect(m_pCutAct, SIGNAL(trigged()), this, SLOT(slotCut()));

	m_pCopyAct = new QAction(tr("Copy"), this);
	m_pCopyAct->setShortcut(QKeySequence::Copy);
	m_pCopyAct->setToolTip(tr("Copy"));
	m_pCopyAct->setStatusTip(tr("Copy"));
	QObject::connect(m_pCopyAct, SIGNAL(trigged()), this, SLOT(slotCopy()));

	m_pPasteAct = new QAction(tr("Paste"), this);
	m_pPasteAct->setShortcut(QKeySequence::Paste);
	m_pPasteAct->setToolTip(tr("Paste"));
	m_pPasteAct->setStatusTip(tr("Paste"));
	QObject::connect(m_pPasteAct, SIGNAL(trigged()), this, SLOT(slotPaste()));


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

void MyWord::createToolBars()
{
	m_pFileToolBar = addToolBar(tr("File"));
	m_pFileToolBar->addAction(m_pNewAct);
}

void MyWord::createStatusBar()
{
	statusBar()->showMessage(tr("OK"));
}

MyChild * MyWord::createMyChild()
{
	MyChild *pChild = new MyChild();
	m_pMdiArea->addSubWindow(pChild);
	connect(pChild, SIGNAL(copyAvailable(bool)), m_pCutAct, SLOT(setEnabled(bool)));
	connect(pChild, SIGNAL(copyAvailable(bool)), m_pCopyAct, SLOT(setEnabled(bool)));
	return pChild;
}

void MyWord::enabledText()
{
	m_pBoldAct->setEnabled(true);
	m_pItalicAct->setEnabled(true);
	m_pUnderlineAct->setEnabled(true);
	m_pLeftAlignAct->setEnabled(true);
	m_pCenterAct->setEnabled(true);
	m_pRightAlignAct->setEnabled(true);
	m_pJustifyAct->setEnabled(true);
	m_pColorAct->setEnabled(true);
}

MyChild * MyWord::activeChild()
{
	if (QMdiSubWindow * pActSubWindow = m_pMdiArea->activeSubWindow())
		return qobject_cast<MyChild *>(pActSubWindow->widget());
	return nullptr;
}

QMdiSubWindow * MyWord::findMyChild(const QString & strFileName)
{
	QString strFilePath = QFileInfo(strFileName).canonicalFilePath();
	foreach (QMdiSubWindow* pWindow, m_pMdiArea->subWindowList())
	{
		MyChild* pChild = qobject_cast<MyChild*>(pWindow->widget());
		if (pChild->currentFile() == strFilePath)
			return pWindow;
	}
	return nullptr;
}

void MyWord::closeEvent(QCloseEvent * event)
{
	m_pMdiArea->closeAllSubWindows();
	if (m_pMdiArea->currentSubWindow())
	{
		event->ignore();
	}
	else
	{
		event->accept();
	}
}

void MyWord::slotFileNew()
{
	MyChild* pChild = createMyChild();
	pChild->newFile();
	pChild->show();
	enabledText();
}

void MyWord::slotFileOpen()
{
	QString strFileName = QFileDialog::getOpenFileName(this, tr("Open"), QString(), tr("Html(*.html|*.htm); All(*.*)"));
	if (!strFileName.isEmpty())
	{
		QMdiSubWindow * pExisting = findMyChild(strFileName);
		if (pExisting)
		{
			m_pMdiArea->setActiveSubWindow(pExisting);
			return;
		}
		MyChild* pChild = createMyChild();
		if (pChild->loadFile(strFileName))
		{
			statusBar()->showMessage(tr("load file"), 2000);
			pChild->show();
		}
		else
			pChild->close();
	}
}

void MyWord::slotFileSave()
{
	if (activeChild() && activeChild()->save())
		statusBar()->showMessage(tr("save success"), 2000);
}

void MyWord::slotFileSaveAs()
{
	if (activeChild() && activeChild()->saveAs())
		statusBar()->showMessage(tr("save success"), 2000);
}

void MyWord::slotUndo()
{
	if (activeChild())
		activeChild()->undo();
}

void MyWord::slotRedo()
{
	if (activeChild())
		activeChild()->redo();
}

void MyWord::slotCut()
{
	if (activeChild())
		activeChild()->cut();
}

void MyWord::slotCopy()
{
	if (activeChild())
		activeChild()->copy();
}

void MyWord::slotPaste()
{
	if (activeChild())
		activeChild()->paste();
}

void MyWord::updateWindowMenu()
{
	m_pWindowMenu->clear();
	m_pWindowMenu->addAction(m_pCloseAct);
	m_pWindowMenu->addAction(m_pCloseAllAct);
	m_pWindowMenu->addSeparator();
	m_pWindowMenu->addAction(m_pTileAct);
	m_pWindowMenu->addAction(m_pCascadeAct);
	m_pWindowMenu->addSeparator();
	m_pWindowMenu->addAction(m_pNextAct);
	m_pWindowMenu->addAction(m_pPreviousAct);
	m_pWindowMenu->addAction(m_pSeparatorAct);

	QList<QMdiSubWindow* > lstSubWindow = m_pMdiArea->subWindowList();
	m_pSeparatorAct->setVisible(!lstSubWindow.isEmpty());
	auto it = lstSubWindow.begin();
	int i = 0;
	for (; it != lstSubWindow.end(); ++it)
	{
		MyChild * pChild = qobject_cast<MyChild*>((*it)->widget());
		QString strText = tr("%1 %2").arg(++i).arg(pChild->userFriendlyCurrentFile());
		QAction * pAct = m_pWindowMenu->addAction(strText);
		pAct->setCheckable(true);
		pAct->setChecked(pChild == activeChild());
		connect(pAct, SIGNAL(triggered()), m_pWindowMapper, SLOT(map()));
		m_pWindowMapper->setMapping(pAct, (*it));
	}
	enabledText();
} 
 
void MyWord::about()
{
	QMessageBox::about(this, tr("About"), tr("My Word1.0"));
}

void MyWord::slotUpdateMenu()
{
	bool bHasChild = (activeChild() != nullptr);
	m_pSaveAct->setEnabled(bHasChild);
	m_pSaveAsAct->setEnabled(bHasChild);
	m_pPrintAct->setEnabled(bHasChild);
	m_pPrintPreviewAct->setEnabled(bHasChild);
	m_pPasteAct->setEnabled(bHasChild);
	m_pCloseAct->setEnabled(bHasChild);
	m_pCloseAllAct->setEnabled(bHasChild);
	m_pTileAct->setEnabled(bHasChild);
	m_pCascadeAct->setEnabled(bHasChild);
	m_pNextAct->setEnabled(bHasChild);
	m_pPreviousAct->setEnabled(bHasChild);
	m_pSeparatorAct->setEnabled(bHasChild);
	bool bHasSelection = (activeChild() && activeChild()->textCursor().hasSelection());

	m_pCutAct->setEnabled(bHasSelection);
	m_pCopyAct->setEnabled(bHasSelection);
	m_pBoldAct->setEnabled(bHasSelection);
	m_pItalicAct->setEnabled(bHasSelection);
	m_pUnderlineAct->setEnabled(bHasSelection);
	m_pLeftAlignAct->setEnabled(bHasSelection);
	m_pCenterAct->setEnabled(bHasSelection);
	m_pRightAlignAct->setEnabled(bHasSelection);
	m_pJustifyAct->setEnabled(bHasSelection);
	m_pColorAct->setEnabled(bHasSelection);

}

void MyWord::slotSetActiveSubWindow()
{
}

void MyWord::textAligen(QAction* pAct)
{

}