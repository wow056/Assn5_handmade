#ifndef OPERATIONDIALOG_H
#define OPERATIONDIALOG_H

#include <QDialog>
#include <QHBoxLayout>
#include <QLabel>
#include <QComboBox>
#include <QDialogButtonBox>
#include <QMessageBox>
#include "Calculator.h"
#include "variablelabel.h"

class OperationDialog : public QDialog
{
	Q_OBJECT
private:
	QVBoxLayout *main_layout;
	QLabel *select_label[2];
	VariableLabel *select_info[2];
	QComboBox *select_combobox[2];
	QVBoxLayout *select_layout[2];
	QDialogButtonBox *button_box;
	Calculator *calc;
	int calculate_type;

	void createMainLayout();
//	void connectSlots();

private slots:
	void OK_button_clicked();

public:
	enum {Add, Sub, Mul, Div};
	OperationDialog(QWidget *parent, int type);
	~OperationDialog();
};


#endif