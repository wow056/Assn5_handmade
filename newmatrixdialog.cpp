#include "newmatrixdialog.h"
#include <climits>

NewMatrixDialog::NewMatrixDialog(QWidget *parent)
	: QDialog(parent), calc(Calculator::GetInstance())
{
	setWindowTitle("New Matrix");
	setFixedSize(320, 240);
	createMainLayout();
	connectSlots();
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
		input_layout[i] = new QVBoxLayout();
		label[i] = new QLabel(this);
		input_line[i] = new QLineEdit(this);
		input_layout[i]->addWidget(label[i]);
		input_layout[i]->addWidget(input_line[i]);
	}
	label[Name]->setText("Variable Name");
	label[Rows]->setText("Rows");
	input_line[Rows]->setValidator(new QIntValidator(1, INT_MAX, this));
	label[Cols]->setText("Cols");
	input_line[Cols]->setValidator(new QIntValidator(1, INT_MAX, this));
	label[Init]->setText("Initial Value");
	input_line[Init]->setValidator(new QDoubleValidator(this));

	main_layout->setHorizontalSpacing(10);
	main_layout->setVerticalSpacing(15);
	main_layout->addLayout(input_layout[Name], 0, 0, 1, 2);
	main_layout->addLayout(input_layout[Rows], 1, 0, 1, 1);
	main_layout->addLayout(input_layout[Cols], 1, 1, 1, 1);
	main_layout->addLayout(input_layout[Init], 2, 0, 1, 2);

	button_box = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this);
	main_layout->addWidget(button_box, 3, 0, 1, 2);
}

void NewMatrixDialog::connectSlots()
{
	QDialog::connect(button_box, SIGNAL(accepted()), this, SLOT(OK_button_clicked()));
	QDialog::connect(button_box, SIGNAL(rejected()), this, SLOT(reject()));
}

QString NewMatrixDialog::made_name()
{
	return name_of_variable;
}

void NewMatrixDialog::OK_button_clicked()
{
	std::string name;
	int cols;
	int rows;
	float init_value;

	name = input_line[Name]->text().toStdString();
	if (input_line[Cols]->hasAcceptableInput() && input_line[Rows]->hasAcceptableInput())
	{
		cols = input_line[Cols]->text().toInt();
		rows = input_line[Rows]->text().toInt();
	}
	else
	{
		QMessageBox::critical(this, "Error", "Rows or Cols must be integer(>=1)");
		return;
	}
	if (input_line[Init]->hasAcceptableInput())
	{
		init_value = input_line[Init]->text().toFloat();
	}
	else
	{
		QMessageBox::critical(this, "Error", "Invalid Initial value");
		return;
	}

	switch (calc->NewVariable(name, rows, cols, init_value))
	{
	case 0:
		name_of_variable = QString::fromStdString(name);
		accept();
		break;
	case MatrixGenerationError:
		QMessageBox::critical(this, "Error", "Invalid Matrix");
		break;
	case Calculator::AlreadyExistError:
		QMessageBox::critical(this, "Error", "The variable name already exist");
		break;
	case Calculator::ReservedWordError:
		QMessageBox::critical(this, "Error", "The variable name(\"result\") is not available");
		break;
	}

	/*try
	{
		calc->NewVariable(name, rows, cols, init_value);
		name_of_variable = QString::fromStdString(name);
		accept();
	}
	catch (int e)
	{
		switch (e)
		{
		default:
			QMessageBox::critical(this, "Error", "Unknown Error", QMessageBox::Ok);
			break;
		case MatrixGenerationError:
			QMessageBox::critical(this, "Error", "Invalid Matrix", QMessageBox::Ok);
			break;
		case Calculator::AlreadyExistError:
			QMessageBox::critical(this, "Error", "The variable name already exist", QMessageBox::Ok);
			break;
		case Calculator::ReservedWordError:
			QMessageBox::critical(this, "Error", "The variable name(\"result\") already exists", QMessageBox::Ok);
			break;
		}
	}*/
}
