#include "operationdialog.h"

void OperationDialog::createMainLayout()
{
	main_layout = new QVBoxLayout(this);
	setLayout(main_layout);

	for (int i = 0; i < 2; i++)
	{
		select_layout[i] = new QVBoxLayout();
		select_label[i] = new QLabel(this);
		select_combobox[i] = new QComboBox(this);
		select_info[i] = new VariableLabel(this);
		select_label[i]->setText(QString("Operand %1").arg(i));

		select_layout[i]->addWidget(select_label[i]);
		select_layout[i]->addWidget(select_combobox[i]);
		select_layout[i]->addWidget(select_info[i]);

		main_layout->addLayout(select_layout[i]);
		QObject::connect(select_combobox[i], SIGNAL(currentTextChanged(const QString&)), select_info[i], SLOT(variable_selected(const QString&)));
		select_combobox[i]->addItems(calc->getVariableNameList());
	}
	button_box = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this);
	QObject::connect(button_box, SIGNAL(accepted()), this, SLOT(OK_button_clicked()));
	QObject::connect(button_box, SIGNAL(rejected()), this, SLOT(reject()));
	main_layout->addWidget(button_box);
	main_layout->setSpacing(10);
}

//void OperationDialog::connectSlots()
//{
//	QObject::connect(select_combobox[0], SIGNAL(currentTextChanged(const QString&)), select_info[0], SLOT(variable_selected(const QString&)));
//	QObject::connect(select_combobox[1], SIGNAL(currentTextChanged(const QString&)), select_info[1], SLOT(variable_selected(const QString&)));
//	QObject::connect(button_box, SIGNAL(accepted()), this, SLOT(OK_button_clicked()));
//	QObject::connect(button_box, SIGNAL(rejected()), this, SLOT(reject()));
//}


void OperationDialog::OK_button_clicked()
{
	std::string key[2];
	for (int i = 0; i < 2; i++)
	{
		key[i] = select_combobox[i]->currentText().toStdString();
	}
	switch (calculate_type)
	{
	case Add:
		switch (calc->Add(key[0], key[1]))
		{
		case 0:
			accept();
			break;
		case CannotCalculateError:
			QMessageBox::critical(this, "Error", "Cannot Calculate!");
			break;
		}
		break;
	case Sub:
		switch (calc->Sub(key[0], key[1]))
		{
		case 0:
			accept();
			break;
		case CannotCalculateError:
			QMessageBox::critical(this, "Error", "Cannot Calculate!");
			break;
		}
		break;
	case Mul:
		switch (calc->Mul(key[0], key[1]))
		{
		case 0:
			accept();
			break;
		case CannotCalculateError:
			QMessageBox::critical(this, "Error", "Cannot Calculate!");
			break;
		}
		break;
	case Div:
		switch (calc->Div(key[0], key[1]))
		{
		case 0:
			accept();
			break;
		case CannotCalculateError:
			QMessageBox::critical(this, "Error", "Cannot Calculate!");
			break;
		}
		break;
	}
}

OperationDialog::OperationDialog(QWidget *parent, int type)
    : QDialog(parent), calc(Calculator::GetInstance()), calculate_type(type)
{
	//connectSlots();
	createMainLayout();
}

OperationDialog::~OperationDialog()
{
}
