#include "newmatrixdialog.h"

NewMatrixDialog::NewMatrixDialog(QWidget *parent)
	: QDialog(parent)
{
	setWindowTitle("New Matrix");
	setFixedSize(320, 240);
	createMainLayout();
}

NewMatrixDialog::~NewMatrixDialog()
{
	for (int i = 0; i < 4; i++)
	{
		delete input_line[i];
		delete label[i];
		delete input_layout[i];
	}
	delete button_box;
	delete main_layout;
}

void NewMatrixDialog::createMainLayout()
{
	main_layout = new QGridLayout(this);
	
	for (int i = 0; i < 4; i++)
	{
		input_layout[i] = new QVBoxLayout(this);
		label[i] = new QLabel(this);
		input_line[i] = new QLineEdit(this);
		input_layout[i]->addWidget(label[i]);
		input_layout[i]->addWidget(input_line[i]);
	}
	label[Name]->setText("Variable Name");
	label[Rows]->setText("Rows");
	label[Cols]->setText("Cols");
	label[Init]->setText("Initial Value");

	main_layout->setHorizontalSpacing(10);
	main_layout->setVerticalSpacing(15);
	main_layout->addLayout(input_layout[Name], 0, 0, 1, 2);
	main_layout->addLayout(input_layout[Rows], 1, 0, 1, 1);
	main_layout->addLayout(input_layout[Cols], 1, 1, 1, 1);
	main_layout->addLayout(input_layout[Init], 2, 0, 1, 2);

	button_box = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this);
	main_layout->addWidget(button_box, 3, 0, 1, 2);
}
