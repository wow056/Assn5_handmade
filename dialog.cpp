#include "dialog.h"

using namespace std;

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
	createMainLayout();
	setWindowTitle("Qt Calculator");
    setFixedSize(480,800);
    setSizeGripEnabled(false);
	connectSlots();
}

Dialog::~Dialog()
{
	for (int i = 0; i < 10; i++)
		delete buttons[i];
	delete button_layout;
	delete result_output;
	delete result_label;
	delete main_layout;
}

std::string Dialog::getButtonNames(int index)
{
	switch (index)
	{
	case Mat:
		return string("Matrix");
	case Add:
		return string("+");
	case Sub:
		return string("-");
	case Num:
		return string("Numeric");
	case Mul:
		return string("x");
	case Div:
		return string("/");
	case Str:
		return string("String");
	case Edit:
		return string("Edit Value");
	case Del:
		return string("Delete Variable");
	case Clear:
		return string("Clear");
	default:
		return string();
	}
}


void Dialog::createMainLayout()
{
    main_layout = new QVBoxLayout(this);

	//create Output widgets
	result_label = new QLabel("[RESULT]", this);
	result_output = new QTextBrowser(this);

	//create Button widgets
	button_layout = new QGridLayout(this);
	for (int i = 0; i < 10; i++)
	{
		buttons[i] = new QPushButton(QString::fromStdString(getButtonNames(i)), this);
		button_layout->addWidget(buttons[i], i / 3, i % 3, 1, 1);
	}
	buttons[Clear] = new QPushButton(QString::fromStdString(getButtonNames(Clear)), this);
	button_layout->addWidget(buttons[Clear], 3, 0, 1, 3);

	main_layout->addWidget(result_label);
	main_layout->addWidget(result_output);
	main_layout->addLayout(button_layout);
}

void Dialog::connectSlots()
{
	QObject::connect(buttons[Mat], SIGNAL(clicked()), this, SLOT(MatButtonClicked()));
	QObject::connect(buttons[Add], SIGNAL(clicked()), this, SLOT(AddButtonClicked()));
	QObject::connect(buttons[Sub], SIGNAL(clicked()), this, SLOT(SubButtonClicked()));
	QObject::connect(buttons[Num], SIGNAL(clicked()), this, SLOT(NumButtonClicked()));
	QObject::connect(buttons[Mul], SIGNAL(clicked()), this, SLOT(MulButtonClicked()));
	QObject::connect(buttons[Div], SIGNAL(clicked()), this, SLOT(DivButtonClicked()));
	QObject::connect(buttons[Str], SIGNAL(clicked()), this, SLOT(StrButtonClicked()));
	QObject::connect(buttons[Edit], SIGNAL(clicked()), this, SLOT(EditButtonClicked()));
	QObject::connect(buttons[Del], SIGNAL(clicked()), this, SLOT(DelButtonClicked()));
	QObject::connect(buttons[Clear], SIGNAL(clicked()), this, SLOT(ClearButtonClicked()));
}

void Dialog::AddButtonClicked()
{
}

void Dialog::MatButtonClicked()
{
}

void Dialog::SubButtonClicked()
{
}

void Dialog::NumButtonClicked()
{
}

void Dialog::MulButtonClicked()
{
}

void Dialog::DivButtonClicked()
{
}

void Dialog::StrButtonClicked()
{
}

void Dialog::EditButtonClicked()
{
}

void Dialog::DelButtonClicked()
{
}

void Dialog::ClearButtonClicked()
{
}
