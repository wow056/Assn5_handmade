#include "newnumericstringdialog.h"

NewNumericStringDialog::NewNumericStringDialog(QWidget *parent)
	: QDialog(parent), calc(Calculator::GetInstance())
{
	setWindowTitle("New Matrix");
	setFixedSize(320, 240);
	createMainLayout();
	connectSlots();
}

NewNumericStringDialog::~NewNumericStringDialog()
{
}

QString NewNumericStringDialog::made_name()
{
	return name_of_variable;
}

void NewNumericStringDialog::createMainLayout()
{
	main_layout = new QVBoxLayout(this);

	main_layout->insertStretch(-1, 10);
	for (int i = 0; i < 2; i++)
	{
		input_layout[i] = new QVBoxLayout(this);
		label[i] = new QLabel(this);
		input_line[i] = new QLineEdit(this);
		input_layout[i]->addWidget(label[i]);
		input_layout[i]->addWidget(input_line[i]);
		main_layout->addLayout(input_layout[i]);
		main_layout->insertStretch(-1, 20);
	}
	label[Name]->setText("Variable Name");
	label[Init]->setText("Initial Value");

	button_box = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this);
	main_layout->addWidget(button_box);
	main_layout->setSpacing(10);
}

void NewNumericStringDialog::connectSlots()
{
	connect(button_box, SIGNAL(accepted()), this, SLOT(OK_button_clicked()));
	connect(button_box, SIGNAL(rejected()), this, SLOT(reject()));
}

NewNumericDialog::NewNumericDialog(QWidget * parent)
	:NewNumericStringDialog(parent)
{
	input_line[Init]->setValidator(new QDoubleValidator());
}

NewNumericDialog::~NewNumericDialog()
{
}

void NewNumericDialog::OK_button_clicked()
{
	std::string name;
	float init_value;

	name = input_line[Name]->text().toStdString();
	if (input_line[Init]->hasAcceptableInput())
	{
		init_value = input_line[Init]->text().toDouble();
	}
	else
	{
		QMessageBox::critical(this, "Error", "Invalid Initial value");
		return;
	}

	switch (calc->NewVariable(name, init_value))
	{
	case Calculator::AlreadyExistError:
		QMessageBox::critical(this, "Error", "The variable name already exist");
		break;
	case Calculator::ReservedWordError:
		QMessageBox::critical(this, "Error", "The variable name(\"result\") is not available");
		break;
	case 0:
		name_of_variable = QString::fromStdString(name);
		accept();
		break;
	}
}

NewStringDialog::NewStringDialog(QWidget * parent)
	:NewNumericStringDialog(parent)
{
}

NewStringDialog::~NewStringDialog()
{
}

void NewStringDialog::OK_button_clicked()
{
	std::string name;
	std::string init_value;

	name = input_line[Name]->text().toStdString();
	init_value = input_line[Init]->text().toStdString();

	switch (calc->NewVariable(name, init_value))
	{
	case Calculator::AlreadyExistError:
		QMessageBox::critical(this, "Error", "The variable name already exist");
		break;
	case Calculator::ReservedWordError:
		QMessageBox::critical(this, "Error", "The variable name(\"result\") is not available");
		break;
	case 0:
		name_of_variable = QString::fromStdString(name);
		accept();
		break;
	}
}
