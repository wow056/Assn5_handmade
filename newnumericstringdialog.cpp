#include "newnumericstringdialog.h"

NewNumericStringDialog::NewNumericStringDialog(QWidget *parent)
	: QDialog(parent)
{
	setWindowTitle("New Matrix");
	setFixedSize(320, 240);
	createMainLayout();
}

NewNumericStringDialog::~NewNumericStringDialog()
{
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
}

NewNumericDialog::NewNumericDialog(QWidget * parent)
	:NewNumericStringDialog(parent)
{
}

NewNumericDialog::~NewNumericDialog()
{
}

NewStringDialog::NewStringDialog(QWidget * parent)
	:NewNumericStringDialog(parent)
{
}

NewStringDialog::~NewStringDialog()
{
}
