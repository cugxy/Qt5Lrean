#include "imageprocessor.h"
#include <QFileDialog>
#include <QTextStream>
#include <qcolordialog.h>
#include <qcolor.h>
ImageProcessor::ImageProcessor(QWidget *parent)
	: QMainWindow(parent)
{
	setWindowTitle(tr("Esay World"));

	m_pShowWidget = new ShowWidget(this);
	setCentralWidget(m_pShowWidget);

	m_pFontLabel1 = new QLabel(tr("font : "));
	m_pFontComboBox = new QFontComboBox();
	m_pFontComboBox->setFontFilters(QFontComboBox::ScalableFonts);

	m_pFontLabel2 = new QLabel(tr("font size : "));
	m_pSizeComboBox = new QComboBox();
	QFontDatabase db;
	foreach(int size, db.standardSizes())
	{
		m_pSizeComboBox->addItem(QString::number(size));
	}

	m_pBoldBtn = new QToolButton();
	m_pBoldBtn->setCheckable(true);
	m_pItalicBtn = new QToolButton();
	m_pItalicBtn->setCheckable(true);
	m_pUnderLineBtn = new QToolButton();
	m_pUnderLineBtn->setCheckable(true);
	m_pColorBtn = new QToolButton();
	m_pColorBtn->setCheckable(true);
	
	connect(m_pFontComboBox, SIGNAL(activated(QString)), this, SLOT(ShowFontComboBox(QString)));
	connect(m_pSizeComboBox, SIGNAL(activated(QString)), this, SLOT(ShowSizeSpinBox(QString)));
	connect(m_pBoldBtn, SIGNAL(clicked()), this, SLOT(ShowBoldBtn()));
	connect(m_pItalicBtn, SIGNAL(clicked()), this, SLOT(ShowItalicBtn()));
	connect(m_pUnderLineBtn, SIGNAL(clicked()), this, SLOT(ShowUnderLineBtn()));
	connect(m_pColorBtn, SIGNAL(clicked()), this, SLOT(ShowColorBtn()));

	connect(m_pShowWidget->m_pText, SIGNAL(currentCharFormatChanged(QTextCharFormat&)), this, SLOT(ShowCurrentCharFormatChanged(QTextCharFormat&)));





	creatActions();
	creatMenus();
	creatToolBars();

	if (m_Img.load("E:/code/Qt_Vs2015/ImageProcessor/x64/Debug/image.png"))
	{
		m_pShowWidget->m_pImageLabel->setPixmap(QPixmap::fromImage(m_Img));
	}

	


}

ImageProcessor::~ImageProcessor()
{

}

void ImageProcessor::creatActions()
{
	//Open
	m_pOpenFileAction = new QAction( tr("Open"), this);
	m_pOpenFileAction->setShortcut(tr("Ctrl+O"));
	m_pOpenFileAction->setStatusTip(tr("Open a file"));
	connect(m_pOpenFileAction, SIGNAL(triggered()), this, SLOT(ShowOpenFile()));

	m_pNewFileAction = new QAction(tr("New"), this);
	m_pNewFileAction->setShortcut(tr("Ctrl+N"));
	m_pNewFileAction->setStatusTip(tr("New a file"));
	connect(m_pNewFileAction, SIGNAL(triggered()), this, SLOT(ShowNewFile()));

	m_pExitAction = new QAction(tr("Exit"), this);
	m_pExitAction->setShortcut(tr("Ctrl+Q"));
	m_pExitAction->setStatusTip(tr("Exit program"));
	connect(m_pExitAction, SIGNAL(triggered()), this, SLOT(close()));

	m_pCutAction = new QAction(tr("Cut"), this);
	m_pCutAction->setShortcut(tr("Ctrl+X"));
	m_pCutAction->setStatusTip(tr("Cut file"));
	connect(m_pCutAction, SIGNAL(triggered()), m_pShowWidget->m_pText, SLOT(cut()));

	m_pCopyAction = new QAction(tr("Copy"), this);
	m_pCopyAction->setShortcut(tr("Ctrl+C"));
	m_pCopyAction->setStatusTip(tr("Copy file"));
	connect(m_pCopyAction, SIGNAL(triggered()), m_pShowWidget->m_pText, SLOT(copy()));

	m_pPasteAction = new QAction(tr("Paste"), this);
	m_pPasteAction->setShortcut(tr("Ctrl+V"));
	m_pPasteAction->setStatusTip(tr("Paste file"));
	connect(m_pPasteAction, SIGNAL(triggered()), m_pShowWidget->m_pText, SLOT(paste()));

	m_pAboutAction = new QAction(tr("About"), this);
	connect(m_pAboutAction, SIGNAL(triggered()), this, SLOT(QApplication::aboutQt()));

	m_pPrintTextAction = new QAction(tr("Print Text"), this);
	m_pPrintTextAction->setStatusTip(tr("Print a text"));

	m_pPrintImgAction = new QAction(tr("Print Image"), this);
	m_pPrintImgAction->setStatusTip(tr("Print a image"));

	m_pZoomInAction = new QAction(tr("Zoom In"), this);
	m_pZoomInAction->setStatusTip(tr("Zoom in the image"));

	m_pZoomOutAction = new QAction(tr("Zoom Out"), this);
	m_pZoomOutAction->setStatusTip(tr("Zoom out the image"));

	m_pRotate90Action = new QAction(tr("Rotate 90"), this);
	m_pRotate90Action->setStatusTip(tr("Rotate 90"));

	m_pRotate180Action = new QAction(tr("Rotate 180"), this);
	m_pRotate180Action->setStatusTip(tr("Rotate 180"));

	m_pRotate270Action = new QAction(tr("Rotate 270"), this);
	m_pRotate270Action->setStatusTip(tr("Rotate 270"));

	m_pMirrorHAction = new QAction(tr("H Mirror"), this);

	m_pMirrorVAction = new QAction(tr("V Mirror"), this);

	m_pUndoHAction = new QAction(tr("undo"), this);
	connect(m_pUndoHAction, SIGNAL(triggered()), m_pShowWidget->m_pText, SLOT(undo()));

	m_pRedoHAction = new QAction(tr("redo"), this);
	connect(m_pRedoHAction, SIGNAL(triggered()), m_pShowWidget->m_pText, SLOT(redo()));
}

void ImageProcessor::creatMenus()
{
	m_pFileMenu = menuBar()->addMenu(tr("File"));
	m_pFileMenu->addAction(m_pOpenFileAction);
	m_pFileMenu->addAction(m_pNewFileAction);
	m_pFileMenu->addAction(m_pPrintTextAction);
	m_pFileMenu->addAction(m_pPrintImgAction);
	m_pFileMenu->addSeparator();
	m_pFileMenu->addAction(m_pExitAction);

	m_pZoomMenu = menuBar()->addMenu(tr("Edit"));
	m_pZoomMenu->addAction(m_pCopyAction);
	m_pZoomMenu->addAction(m_pCutAction);
	m_pZoomMenu->addAction(m_pPasteAction);
	m_pZoomMenu->addAction(m_pAboutAction);
	m_pFileMenu->addSeparator();
	m_pZoomMenu->addAction(m_pZoomInAction);
	m_pZoomMenu->addAction(m_pZoomOutAction);

	m_pRotateMenu = menuBar()->addMenu(tr("Rotate"));
	m_pRotateMenu->addAction(m_pRotate90Action);
	m_pRotateMenu->addAction(m_pRotate180Action);
	m_pRotateMenu->addAction(m_pRotate270Action);

	m_pMirrorMenu = menuBar()->addMenu(tr("Mirror"));
	m_pMirrorMenu->addAction(m_pMirrorVAction);
	m_pMirrorMenu->addAction(m_pMirrorHAction);
}

void ImageProcessor::creatToolBars()
{
	m_pFileTool = addToolBar("File");
	m_pFileTool->addAction(m_pOpenFileAction);
	m_pFileTool->addAction(m_pNewFileAction);
	m_pFileTool->addAction(m_pPrintTextAction);
	m_pFileTool->addAction(m_pPrintImgAction);
	m_pFileTool->setAllowedAreas(Qt::TopToolBarArea | Qt::RightToolBarArea);
	m_pFileTool->setMovable(true);

	m_pFontToolBar = addToolBar("Font");
	m_pFontToolBar->addWidget(m_pFontLabel1);
	m_pFontToolBar->addWidget(m_pFontComboBox);
	m_pFontToolBar->addWidget(m_pFontLabel2);
	m_pFontToolBar->addWidget(m_pSizeComboBox);
	m_pFontToolBar->addSeparator();
	m_pFontToolBar->addWidget(m_pBoldBtn);
	m_pFontToolBar->addWidget(m_pItalicBtn);
	m_pFontToolBar->addWidget(m_pUnderLineBtn);
	m_pFontToolBar->addSeparator();
	m_pFontToolBar->addWidget(m_pColorBtn);
}

void ImageProcessor::loadFiles(QString filename)
{
	printf("file name:%s\n", filename.data());

	QFile file(filename);
	if (file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		QTextStream textStream(&file);
		while (!textStream.atEnd())
		{
			m_pShowWidget->m_pText->append(textStream.readLine());
			printf("read line \n");
		}
		printf("end \n");
	}
}

void ImageProcessor::mergeFormat(QTextCharFormat format)
{
	QTextCursor cursor = m_pShowWidget->m_pText->textCursor();
	if (!cursor.hasSelection())
	{
		cursor.select(QTextCursor::WordUnderCursor);
	}
	cursor.mergeCharFormat(format);
	m_pShowWidget->m_pText->mergeCurrentCharFormat(format);
}

void ImageProcessor::ShowNewFile()
{
	ImageProcessor * it = new ImageProcessor();
	it->show();
}

void ImageProcessor::ShowOpenFile()
{
	m_fileName = QFileDialog::getOpenFileName(this);
	if (!m_fileName.isEmpty())
	{
		if (m_pShowWidget->m_pText->document()->isEmpty())
		{
			loadFiles(m_fileName);
		}
		else
		{
			ImageProcessor * it = new ImageProcessor();
			it->show();
			it->loadFiles(m_fileName);
		}
	}
}

void ImageProcessor::ShowFontComboBox(QString strCombo)
{
	QTextCharFormat fmt;
	fmt.setFontFamily(strCombo);
	mergeFormat(fmt);
}

void ImageProcessor::ShowSizeSpinBox(QString strSpin)
{
	QTextCharFormat fmt;
	fmt.setFontPointSize(strSpin.toFloat());
	m_pShowWidget->m_pText->mergeCurrentCharFormat(fmt);
}

void ImageProcessor::ShowBoldBtn()
{
	QTextCharFormat fmt;
	fmt.setFontWeight(m_pBoldBtn->isChecked() ? QFont::Bold : QFont::Normal);
	m_pShowWidget->m_pText->mergeCurrentCharFormat(fmt);
}

void ImageProcessor::ShowItalicBtn()
{
	QTextCharFormat fmt;
	fmt.setFontItalic(m_pItalicBtn->isChecked());
	m_pShowWidget->m_pText->mergeCurrentCharFormat(fmt);
}

void ImageProcessor::ShowUnderLineBtn()
{
	QTextCharFormat fmt;
	fmt.setFontUnderline(m_pUnderLineBtn->isChecked());
	m_pShowWidget->m_pText->mergeCurrentCharFormat(fmt);
}

void ImageProcessor::ShowColorBtn()
{
	QColor color = QColorDialog::getColor(Qt::red, this);
	if (color.isValid())
	{
		QTextCharFormat fmt;
		fmt.setForeground(color);
		m_pShowWidget->m_pText->mergeCurrentCharFormat(fmt);
	}
}

void ImageProcessor::ShowCurrentCharFormatChanged(QTextCharFormat &fmt)
{
	m_pFontComboBox->setCurrentIndex(m_pFontComboBox->findText(fmt.fontFamily()));
	m_pSizeComboBox->setCurrentIndex(m_pSizeComboBox->findText(QString::number(fmt.fontPointSize())));
	m_pBoldBtn->setChecked(fmt.font().bold());
	m_pItalicBtn->setChecked(fmt.fontItalic());
	m_pColorBtn->setChecked(fmt.fontUnderline());
}
