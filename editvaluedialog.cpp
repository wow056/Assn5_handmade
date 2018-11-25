#include "editvaluedialog.h"

#include <qsizepolicy.h>

EditValueDialog::EditValueDialog(QWidget *parent)
	: QDialog(parent)
{
	setWindowTitle("Edit Value");
	setFixedSize(320, 320);
	createMainLayout();
	connectSlots();
}

EditValueDialog::~EditValueDialog()
{
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
	label[Col]->setText("Col");
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
//	matrix_widget->setLayout(matrix_layout);

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

	matrix_widget->hide();
	value_widget->hide();
}

void EditValueDialog::connectSlots()
{
	QObject::connect(button_box, SIGNAL(accepted()), this, SLOT(changeToMatrixLayout()));
	QObject::connect(button_box, SIGNAL(rejected()), this, SLOT(changeToStringLayout()));
}

void EditValueDialog::changeToMatrixLayout()
{
	value_widget->show();
	matrix_widget->show();
}

void EditValueDialog::changeToStringLayout()
{
	value_widget->show();
	matrix_widget->hide();
}
