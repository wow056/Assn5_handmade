#include "deletedialog.h"

void DeleteDialog::createMainLayout()
{
	main_layout = new QVBoxLayout(this);
	setLayout(main_layout);
	select_layout = new QVBoxLayout(this);
	select_label = new QLabel(this);
	select_combobox = new QComboBox(this);
	select_info = new VariableLabel(this);
	select_layout->addWidget(select_label);
	select_layout->addWidget(select_combobox);
	select_layout->addWidget(select_info);

	main_layout->addLayout(select_layout);
	QObject::connect(select_combobox, SIGNAL(currentTextChanged(const QString&)), select_info, SLOT(variable_selected(const QString&)));
	select_combobox->addItems(calc->getVariableNameList());
	
	button_box = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this);
	main_layout->addWidget(button_box);
	main_layout->setSpacing(10);
	QObject::connect(button_box, SIGNAL(accepted()), this, SLOT(OK_button_clicked()));
	QObject::connect(button_box, SIGNAL(rejected()), this, SLOT(reject()));
}

//void DeleteDialog::connectSlots()
//{
//	QObject::connect(select_combobox, SIGNAL(currentTextChanged(const QString&)), select_info, SLOT(variable_selected(const QString&)));
//	QObject::connect(button_box, SIGNAL(accepted()), this, SLOT(OK_button_clicked()));
//	QObject::connect(button_box, SIGNAL(rejected()), this, SLOT(reject()));
//}


void DeleteDialog::OK_button_clicked()
{
	std::string key;
	key = select_combobox->currentText().toStdString();
	calc->deleteVariable(key);
	accept();
}

DeleteDialog::DeleteDialog(QWidget *parent)
	: QDialog(parent), calc(Calculator::GetInstance())
{
//	connectSlots();
	createMainLayout();
}

DeleteDialog::~DeleteDialog()
{
}
