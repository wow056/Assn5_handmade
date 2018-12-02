#include "editvaluedialog.h"

#include <qsizepolicy.h>

EditValueDialog::EditValueDialog(QWidget *parent)
	: QDialog(parent)
{
	calc = Calculator::GetInstance();
	setWindowTitle("Edit Value");
	createMainLayout();
	connectSlots();
}

EditValueDialog::~EditValueDialog()
{
}

QString EditValueDialog::changed_variable() const
{
	return _changed_varriable
}

void EditValueDialog::createMainLayout()
{
	main_layout = new QVBoxLayout(this);
	
	for (int i = 0; i < 3; i++)
	{
		input_layout[i] = new QVBoxLayout(this);
		label[i] = new QLabel(this);
		input_line[i] = new QLineEdit(this);
		input_layout[i]->addWidget(label[i]);
		input_layout[i]->addWidget(input_line[i]);
	}
	label[Row]->setText("Row");
	input_line[Row]->setValidator(new QIntValidator(this));
	label[Col]->setText("Col");
	input_line[Col]->setValidator(new QIntValidator(this));
	label[Value]->setText("Value");

	select_widget = new QWidget(this);
	select_layout = new QVBoxLayout(select_widget);
	select_label = new QLabel("Select Edit Value", this);
	select_combobox = new QComboBox(this);
	select_info = new QLabel(this);

	select_layout->addWidget(select_label);
	select_layout->addWidget(select_combobox);
	select_layout->addWidget(select_info);

	matrix_widget = new QWidget(this);
	matrix_layout = new QHBoxLayout(matrix_widget);
	matrix_layout->addLayout(input_layout[Row]);
	matrix_layout->addLayout(input_layout[Col]);

	value_widget = new QWidget(this);
	value_widget->setLayout(input_layout[Value]);
	
	button_box = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this);

	main_layout->addWidget(select_widget);
	main_layout->addWidget(matrix_widget);
	main_layout->addWidget(value_widget);
	main_layout->addWidget(button_box);

	matrix_widget->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
	value_widget->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
	select_widget->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);

	validator = new QDoubleValidator(this);

	matrix_widget->hide();
	value_widget->hide();
	select_combobox->addItems(calc->getVariableNameList());
}

void EditValueDialog::connectSlots()
{
	QObject::connect(select_combobox, SIGNAL(activated(const QString&)), this, SLOT(variable_selected(const QString&)));
	QObject::connect(button_box, SIGNAL(accepted()), this, SLOT(OK_button_clicked()));
	QObject::connect(button_box, SIGNAL(rejected()), this, SLOT(reject()));
}

void EditValueDialog::changeToMatrixLayout()
{
	value_widget->show();
	input_line[Value]->setValidator(validator);
	matrix_widget->show();
}

void EditValueDialog::changeToStringLayout()
{
	value_widget->show();
	input_line[Value]->setValidator(nullptr);
	matrix_widget->hide();
}

void EditValueDialog::changeToNumericLayout()
{
	value_widget->show();
	input_line[Value]->setValidator(validator);
	matrix_widget->hide();
}

void EditValueDialog::OK_button_clicked()
{
	std::string key = select_combobox->currentText().toStdString();
	switch (calc->getVariableType(key))
	{
	case Calculator::MATRIX:
		int row = input_line[Row]->text().toInt();
		int col = input_line[Col]->text().toInt();
		float value = input_line[Value]->text().toFloat();
		if (calc->EditValue(key, row, col, value))
		{
			_changed_varriable = select_combobox->currentText();
			accept();
		}
		else
		{
			QMessageBox::critical(this, "Error", "Rows or Cols must be integer(>=1)");
			return;
		}
		break;
	case Calculator::NUMERIC:
		float value = input_line[Value]->text().toFloat();
		calc->EditValue(key, value);
		accept();
		break;
	case Calculator::STRING:
		std::string value = input_line[Value]->text().toStdString();
		calc->EditValue(key, value);
		accept();
		break;
	}
}

void EditValueDialog::variable_selected(const QString &s)
{
	select_info->setText(calc->getVariableInfo(s.toStdString()));
	switch (calc->getVariableType(s.toStdString()))
	{
	case Calculator::MATRIX:
		changeToMatrixLayout();
		break;
	case Calculator::NUMERIC:
		changeToStringLayout();
		break;
	case Calculator::STRING:
		changeToNumericLayout();
		break;
	default:
		break;
	}
}
