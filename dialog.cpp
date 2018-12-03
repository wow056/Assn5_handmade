#include "dialog.h"

using namespace std;

Dialog::Dialog(QWidget *parent)
	: QDialog(parent)
{
	setWindowTitle("Qt Calculator");
	setFixedSize(480, 800);
	setSizeGripEnabled(false);
	createMainLayout();
	connectSlots();
	calc = Calculator::GetInstance();
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

Calculator * Dialog::getCalculator()
{
	return calc;
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

void Dialog::showVariable(QString name) const
{
	QString output;
	output += name + " =\n";
	switch (calc->getVariableType(name.toStdString()))
	{
	case Calculator::MATRIX:
		output += "{";
		output += calc->GetVariableValue(name.toStdString());
		output += "}\n";
		break;
	case Calculator::NUMERIC:
	case Calculator::STRING:
		output += QString("\t");
		output += calc->GetVariableValue(name.toStdString());
		output += QString("\n");
		break;
	}
	result_output->append(output);
}

void Dialog::AddButtonClicked()
{
	OperationDialog op_dialog(this, OperationDialog::Add);
	if (op_dialog.exec() == QDialog::Accepted)
	{
		showVariable("result");
	}
}

void Dialog::MatButtonClicked()
{
	NewMatrixDialog mat_dialog(this);
	if (mat_dialog.exec() == QDialog::Accepted)
	{
		showVariable(mat_dialog.made_name());
	}
}

void Dialog::SubButtonClicked()
{
	OperationDialog op_dialog(this, OperationDialog::Sub);
	if (op_dialog.exec() == QDialog::Accepted)
	{
		showVariable("result");
	}
}

void Dialog::NumButtonClicked()
{
	NewNumericDialog num_dialog(this);
	if (num_dialog.exec() == QDialog::Accepted)
	{
		showVariable(num_dialog.made_name());
	}
}

void Dialog::MulButtonClicked()
{
	OperationDialog op_dialog(this, OperationDialog::Mul);
	if (op_dialog.exec() == QDialog::Accepted)
	{
		showVariable("result");
	}
}

void Dialog::DivButtonClicked()
{
	OperationDialog op_dialog(this, OperationDialog::Div);
	if (op_dialog.exec() == QDialog::Accepted)
	{
		showVariable("result");
	}
}

void Dialog::StrButtonClicked()
{
	NewStringDialog str_dialog(this);
	if (str_dialog.exec() == QDialog::Accepted)
	{
		showVariable(str_dialog.made_name());
	}
}

void Dialog::EditButtonClicked()
{
	EditValueDialog edit_dialog(this);
	if (edit_dialog.exec() == QDialog::Accepted)
	{
		showVariable(edit_dialog.changed_variable());
	}
}

void Dialog::DelButtonClicked()
{
	DeleteDialog del_dialog(this);
	del_dialog.exec();
}

void Dialog::ClearButtonClicked()
{
	calc->Clear();
	result_output->clear();
}
