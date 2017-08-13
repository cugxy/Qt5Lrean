#include <qcolor.h>
#include <QLinearGradient>
#include <QRadialGradient>
#include <QConicalGradient>
#include <QColorDialog>
#include <QPen>
#include <QHBoxLayout>
#include "mainwidget.h"
#include "paintarea.h"

MainWidget::MainWidget(QWidget *parent)
	: QWidget(parent)
{
	m_pPaintArea = new PaintArea();

	m_pShapeLabel = new QLabel(tr("Shape:"));
	m_pShapeComboBox = new QComboBox();
	m_pShapeComboBox->addItem(tr("Line"), PaintArea::EnuLine);
	m_pShapeComboBox->addItem(tr("Rectangle"), PaintArea::EnuRectangle);
	m_pShapeComboBox->addItem(tr("RoundedRect"), PaintArea::EnuRoundRect);
	m_pShapeComboBox->addItem(tr("Ellipse"), PaintArea::EnuEllipse);
	m_pShapeComboBox->addItem(tr("Polygon"), PaintArea::EnuPolygon);
	m_pShapeComboBox->addItem(tr("Polyline"), PaintArea::EnuPolyLine);
	m_pShapeComboBox->addItem(tr("Points"), PaintArea::EnuPoint);
	m_pShapeComboBox->addItem(tr("Arc"), PaintArea::EnuArc);
	m_pShapeComboBox->addItem(tr("Path"), PaintArea::EnuPath);
	m_pShapeComboBox->addItem(tr("Text"), PaintArea::EnuText);
	m_pShapeComboBox->addItem(tr("Pixmap"), PaintArea::EnuPixmap);
	connect(m_pShapeComboBox, SIGNAL(activated(int)), this, SLOT(ShowShape(int)));

	m_pPenColorLabel = new QLabel(tr("Pen Color:"));
	m_pPenColorFrame = new QFrame();
	m_pPenColorFrame->setFrameStyle(QFrame::Panel | QFrame::Sunken);
	m_pPenColorFrame->setAutoFillBackground(true);
	m_pPenColorFrame->setPalette(QPalette(Qt::blue));
	m_pPenColorBtn = new QPushButton(tr("Change"));
	connect(m_pPenColorBtn, SIGNAL(clicked()), this, SLOT(ShowPenColor()));

	m_pPenWidthLabel = new QLabel(tr("Pen Width"));
	m_pPenWidthSpinBox = new QSpinBox();
	m_pPenWidthSpinBox->setRange(0, 20);
	connect(m_pPenWidthSpinBox, SIGNAL(valueChanged(int)), this, SLOT(ShowPenWidth(int)));

	m_pPenStyleLabel = new QLabel(tr("Pen Style"));
	m_pPenStyleComboBox = new QComboBox();
	m_pPenStyleComboBox->addItem(tr("SolidLine"), static_cast<int>(Qt::SolidLine));
	m_pPenStyleComboBox->addItem(tr("DashLine"), static_cast<int>(Qt::DashLine));
	m_pPenStyleComboBox->addItem(tr("DotLine"), static_cast<int>(Qt::DotLine));
	m_pPenStyleComboBox->addItem(tr("DashDotLine"), static_cast<int>(Qt::DashDotLine));
	m_pPenStyleComboBox->addItem(tr("DashDotDotLine"), static_cast<int>(Qt::DashDotDotLine));
	m_pPenStyleComboBox->addItem(tr("CustomDashLine"), static_cast<int>(Qt::CustomDashLine));
	connect(m_pPenStyleComboBox, SIGNAL(activated(int)), this, SLOT(ShowPenStyle(int)));

	m_pPenCapLabel = new QLabel(tr("Pen Cap:"));
	m_pPenCapComboBox = new QComboBox();
	m_pPenCapComboBox->addItem(tr("Square Cap"), Qt::SquareCap);
	m_pPenCapComboBox->addItem(tr("Flat Cap"), Qt::FlatCap);
	m_pPenCapComboBox->addItem(tr("Round Cap"), Qt::RoundCap);
	connect(m_pPenCapComboBox, SIGNAL(activated(int)), this, SLOT(ShowPenCap(int)));

	m_pPenJoinLabel = new QLabel(tr("Pen Join:"));
	m_pPenJoinComboBox = new QComboBox();
	m_pPenJoinComboBox->addItem(tr("Bevel Join"), Qt::BevelJoin);
	m_pPenJoinComboBox->addItem(tr("Miter Join"), Qt::MiterJoin);
	m_pPenJoinComboBox->addItem(tr("Round Join"), Qt::RoundJoin);
	connect(m_pPenJoinComboBox, SIGNAL(activated(int)), this, SLOT(ShowPenJoin(int)));

	m_pFillRuleLabel = new QLabel(tr("Fill Rule:"));
	m_pFillRuleComboBox = new QComboBox();
	m_pFillRuleComboBox->addItem(tr("odd Even"), Qt::OddEvenFill);
	m_pFillRuleComboBox->addItem(tr("Winding"), Qt::WindingFill);
	connect(m_pFillRuleComboBox, SIGNAL(activated(int)), this, SLOT(ShowFillRule(int)));

	m_pSpreadLabel = new QLabel(tr("Spread style:"));
	m_pSpreadComboBox = new QComboBox();
	m_pSpreadComboBox->addItem(tr("Pad Spread"), QGradient::PadSpread);
	m_pSpreadComboBox->addItem(tr("Repeat Spread"), QGradient::RepeatSpread);
	m_pSpreadComboBox->addItem(tr("Reflect Spread"), QGradient::ReflectSpread);
	connect(m_pSpreadComboBox, SIGNAL(activated(int)), this, SLOT(ShowSpreadStyle(int)));
	 
	m_pBrushColorLabel = new QLabel(tr("Brush Color:"));
	m_pBrushColorFrame = new QFrame();
	m_pBrushColorFrame->setFrameStyle(QFrame::Panel | QFrame::Sunken);
	m_pBrushColorFrame->setAutoFillBackground(true);
	m_pBrushColorFrame->setPalette(QPalette(Qt::green));
	m_pBrushColorBtn = new QPushButton(tr("Change"));
	connect(m_pBrushColorBtn, SIGNAL(clicked()), this, SLOT(ShowBrushColor()));

	m_pBrushStyleLabel = new QLabel(tr("Brush style:"));
	m_pBrushStyleComboBox = new QComboBox();
	m_pBrushStyleComboBox->addItem(tr("SolidPattern"), static_cast<int>(Qt::SolidPattern));
	m_pBrushStyleComboBox->addItem(tr("Dense1Pattern"), static_cast<int>(Qt::Dense1Pattern));
	m_pBrushStyleComboBox->addItem(tr("Dense2Pattern"), static_cast<int>(Qt::Dense2Pattern));
	m_pBrushStyleComboBox->addItem(tr("Dense3Pattern"), static_cast<int>(Qt::Dense3Pattern));
	m_pBrushStyleComboBox->addItem(tr("Dense4Pattern"), static_cast<int>(Qt::Dense4Pattern));
	m_pBrushStyleComboBox->addItem(tr("Dense5Pattern"), static_cast<int>(Qt::Dense5Pattern));
	m_pBrushStyleComboBox->addItem(tr("Dense6Pattern"), static_cast<int>(Qt::Dense6Pattern));
	m_pBrushStyleComboBox->addItem(tr("Dense7Pattern"), static_cast<int>(Qt::Dense7Pattern));
	m_pBrushStyleComboBox->addItem(tr("HorPattern"), static_cast<int>(Qt::HorPattern));
	m_pBrushStyleComboBox->addItem(tr("VerPattern"), static_cast<int>(Qt::VerPattern));
	m_pBrushStyleComboBox->addItem(tr("CrossPattern"), static_cast<int>(Qt::CrossPattern));
	m_pBrushStyleComboBox->addItem(tr("BDiagPattern"), static_cast<int>(Qt::BDiagPattern));
	m_pBrushStyleComboBox->addItem(tr("DiagCrossPattern"), static_cast<int>(Qt::DiagCrossPattern));
	m_pBrushStyleComboBox->addItem(tr("LinearGradientPattern"), static_cast<int>(Qt::LinearGradientPattern));
	m_pBrushStyleComboBox->addItem(tr("ConicalGradientPattern"), static_cast<int>(Qt::LinearGradientPattern));
	m_pBrushStyleComboBox->addItem(tr("RadialGradientPattern"), static_cast<int>(Qt::RadialGradientPattern));
	m_pBrushStyleComboBox->addItem(tr("TexturePattern"), static_cast<int>(Qt::TexturePattern));
	connect(m_pBrushStyleComboBox, SIGNAL(activated(int)), this, SLOT(ShowBrush(int)));

	m_pRightLayout = new QGridLayout();
	m_pRightLayout->addWidget(m_pShapeLabel, 0, 0);
	m_pRightLayout->addWidget(m_pShapeComboBox, 0, 1);
	m_pRightLayout->addWidget(m_pPenColorLabel, 1, 0);
	m_pRightLayout->addWidget(m_pPenColorFrame, 1, 1);
	m_pRightLayout->addWidget(m_pPenColorBtn, 1, 2);
	m_pRightLayout->addWidget(m_pPenWidthLabel, 2, 0);
	m_pRightLayout->addWidget(m_pPenWidthSpinBox, 2, 1);
	m_pRightLayout->addWidget(m_pPenStyleLabel, 3, 0);
	m_pRightLayout->addWidget(m_pPenStyleComboBox, 3, 1);
	m_pRightLayout->addWidget(m_pPenCapLabel, 4, 0);
	m_pRightLayout->addWidget(m_pPenCapComboBox, 4, 1);
	m_pRightLayout->addWidget(m_pPenJoinLabel, 5, 0);
	m_pRightLayout->addWidget(m_pPenJoinComboBox, 5, 1);
	m_pRightLayout->addWidget(m_pFillRuleLabel, 6, 0);
	m_pRightLayout->addWidget(m_pFillRuleComboBox, 6, 1);
	m_pRightLayout->addWidget(m_pSpreadLabel, 7, 0);
	m_pRightLayout->addWidget(m_pSpreadComboBox, 7, 1);
	m_pRightLayout->addWidget(m_pBrushColorLabel, 8, 0);
	m_pRightLayout->addWidget(m_pBrushColorFrame, 8, 1);
	m_pRightLayout->addWidget(m_pBrushColorBtn, 8, 2);
	m_pRightLayout->addWidget(m_pBrushStyleLabel, 9, 0);
	m_pRightLayout->addWidget(m_pBrushStyleComboBox, 9, 1);

	QHBoxLayout * mainLayout = new QHBoxLayout(this);
	mainLayout->addWidget(m_pPaintArea);
	mainLayout->addLayout(m_pRightLayout);
	mainLayout->setStretchFactor(m_pPaintArea, 1);
	mainLayout->setStretchFactor(m_pRightLayout, 0);

	ShowShape(m_pShapeComboBox->currentIndex());
}

MainWidget::~MainWidget()
{

}
void MainWidget::ShowShape(int n)
{
	PaintArea::Shape shape = PaintArea::Shape(m_pShapeComboBox->itemData(n, Qt::UserRole).toInt());
	m_pPaintArea->SetShape(shape);
}

void MainWidget::ShowPenWidth(int value)
{
	QColor color = m_pPenColorFrame->palette().color(QPalette::Window);
	Qt::PenStyle style = Qt::PenStyle(m_pPenStyleComboBox->itemData(m_pPenStyleComboBox->currentIndex(), Qt::UserRole).toInt());
	Qt::PenCapStyle cap = Qt::PenCapStyle(m_pPenCapComboBox->itemData(m_pPenCapComboBox->currentIndex(), Qt::UserRole).toInt());
	Qt::PenJoinStyle join = Qt::PenJoinStyle(m_pPenJoinComboBox->itemData(m_pPenJoinComboBox->currentIndex(), Qt::UserRole).toInt());
	m_pPaintArea->SetPen(QPen(color, value, style, cap, join));
}

void MainWidget::ShowPenColor()
{
	QColor color = QColorDialog::getColor(static_cast<int>(Qt::blue));
	m_pPenColorFrame->setPalette(QPalette(color));
	int value = m_pPenWidthSpinBox->value();
	Qt::PenStyle style = Qt::PenStyle(m_pPenStyleComboBox->itemData(m_pPenStyleComboBox->currentIndex(), Qt::UserRole).toInt());
	Qt::PenCapStyle cap = Qt::PenCapStyle(m_pPenCapComboBox->itemData(m_pPenCapComboBox->currentIndex(), Qt::UserRole).toInt());
	Qt::PenJoinStyle join = Qt::PenJoinStyle(m_pPenJoinComboBox->itemData(m_pPenJoinComboBox->currentIndex(), Qt::UserRole).toInt());
	m_pPaintArea->SetPen(QPen(color, value, style, cap, join));
}

void MainWidget::ShowPenStyle(int)
{
	QColor color = m_pPenColorFrame->palette().color(QPalette::Window);
	int value = m_pPenWidthSpinBox->value();
	Qt::PenStyle style = Qt::PenStyle(m_pPenStyleComboBox->itemData(m_pPenStyleComboBox->currentIndex(), Qt::UserRole).toInt());
	Qt::PenCapStyle cap = Qt::PenCapStyle(m_pPenCapComboBox->itemData(m_pPenCapComboBox->currentIndex(), Qt::UserRole).toInt());
	Qt::PenJoinStyle join = Qt::PenJoinStyle(m_pPenJoinComboBox->itemData(m_pPenJoinComboBox->currentIndex(), Qt::UserRole).toInt());
	m_pPaintArea->SetPen(QPen(color, value, style, cap, join));
}

void MainWidget::ShowPenCap(int)
{
	QColor color = m_pPenColorFrame->palette().color(QPalette::Window);
	int value = m_pPenWidthSpinBox->value();
	Qt::PenStyle style = Qt::PenStyle(m_pPenStyleComboBox->itemData(m_pPenStyleComboBox->currentIndex(), Qt::UserRole).toInt());
	Qt::PenCapStyle cap = Qt::PenCapStyle(m_pPenCapComboBox->itemData(m_pPenCapComboBox->currentIndex(), Qt::UserRole).toInt());
	Qt::PenJoinStyle join = Qt::PenJoinStyle(m_pPenJoinComboBox->itemData(m_pPenJoinComboBox->currentIndex(), Qt::UserRole).toInt());
	m_pPaintArea->SetPen(QPen(color, value, style, cap, join));
}

void MainWidget::ShowPenJoin(int)
{
	QColor color = m_pPenColorFrame->palette().color(QPalette::Window);
	int value = m_pPenWidthSpinBox->value();
	Qt::PenStyle style = Qt::PenStyle(m_pPenStyleComboBox->itemData(m_pPenStyleComboBox->currentIndex(), Qt::UserRole).toInt());
	Qt::PenCapStyle cap = Qt::PenCapStyle(m_pPenCapComboBox->itemData(m_pPenCapComboBox->currentIndex(), Qt::UserRole).toInt());
	Qt::PenJoinStyle join = Qt::PenJoinStyle(m_pPenJoinComboBox->itemData(m_pPenJoinComboBox->currentIndex(), Qt::UserRole).toInt());
	m_pPaintArea->SetPen(QPen(color, value, style, cap, join));
}

void MainWidget::ShowSpreadStyle(int)
{
	m_pSpread = QGradient::Spread(m_pShapeComboBox->itemData(m_pShapeComboBox->currentIndex(), Qt::UserRole).toInt());
}

void MainWidget::ShowFillRule(int)
{
	Qt::FillRule rule = Qt::FillRule(m_pFillRuleComboBox->itemData(m_pFillRuleComboBox->currentIndex(), Qt::UserRole).toInt());
	m_pPaintArea->SetFillRule(rule);
}

void MainWidget::ShowBrushColor()
{
	QColor color = QColorDialog::getColor(static_cast<int>(Qt::blue));
	m_pBrushColorFrame->setPalette(QPalette(color));
	ShowBrush(m_pBrushStyleComboBox->currentIndex());
}

void MainWidget::ShowBrush(int)
{
	QColor color = m_pPenColorFrame->palette().color(QPalette::Window);
	Qt::BrushStyle style = Qt::BrushStyle(m_pBrushStyleComboBox->itemData(m_pBrushStyleComboBox->currentIndex(), Qt::UserRole).toInt());
	if (Qt::LinearGradientPattern == style)
	{
		QLinearGradient linear(0, 0, 400, 400);
		linear.setColorAt(0.0, Qt::white);
		linear.setColorAt(0.2, color);
		linear.setColorAt(1.0, Qt::black);
		linear.setSpread(m_pSpread);
		m_pPaintArea->SetBrush(linear);
	}
	else if (Qt::RadialGradientPattern == style)
	{
		QRadialGradient linear(200, 200, 150, 150, 100);
		linear.setColorAt(0.0, Qt::white);
		linear.setColorAt(0.2, color);
		linear.setColorAt(1.0, Qt::black);
		linear.setSpread(m_pSpread);
		m_pPaintArea->SetBrush(linear);
	}
	else if (Qt::ConicalGradientPattern == style)
	{
		QConicalGradient linear(200, 200, 30);
		linear.setColorAt(0.0, Qt::white);
		linear.setColorAt(0.2, color);
		linear.setColorAt(1.0, Qt::black);
		linear.setSpread(m_pSpread);
		m_pPaintArea->SetBrush(linear);
	}
	else if (Qt::TexturePattern == style)
	{
		m_pPaintArea->SetBrush(QBrush(QPixmap("")));
	}
	else
	{
		m_pPaintArea->SetBrush(QBrush(color, style));
	}

}
