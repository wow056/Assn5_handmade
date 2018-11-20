#include "dialog.h"

using namespace std;

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
	createMainLayout();
	setWindowTitle("Qt Calculator");
    setFixedSize(480,800);
    setSizeGripEnabled(false);
}

Dialog::~Dialog()
{
	for (int i = 0; i < 10; i++)
		delete buttons[i];
	for (int i = 0; i < 4; i++)
		delete button_layout_row[i];
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
	defalut:
		return string();
	}
}

void Dialog::createMainLayout()
{

    main_layout = new QVBoxLayout(this);
	createOutputLayout();
	createButtonLayout();
}

void Dialog::createOutputLayout()
{
	result_label = new QLabel("[RESULT]", this);
	main_layout->addWidget(result_label);
	result_output = new QTextBrowser(this);
	main_layout->addWidget(result_output);
}

void Dialog::createButtonLayout()
{
	button_layout = new QVBoxLayout(this);
	for (int i = 0; i < 4; i++)
	{
		button_layout_row[i] = new QHBoxLayout(this);
		button_layout->addLayout(button_layout_row[i]);
	}
	for (int i = 0; i < 10; i++)
	{
		buttons[i] = new QPushButton(QString::fromStdString(getButtonNames(i)), this);
		button_layout_row[i / 3]->addWidget(buttons[i]);
	}
	main_layout->addLayout(button_layout);
}
