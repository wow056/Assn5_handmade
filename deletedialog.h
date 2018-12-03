#ifndef DELETEDIALOG_H
#define DELETEDIALOG_H

#include <QDialog>
#include <QHBoxLayout>
#include <QLabel>
#include <QComboBox>
#include <QDialogButtonBox>
#include <QMessageBox>
#include "Calculator.h"
#include "variablelabel.h"


class DeleteDialog : public QDialog
{
	Q_OBJECT
private:
	QVBoxLayout *main_layout;
	QLabel *select_label;
	VariableLabel *select_info;
	QComboBox* select_combobox;
	QVBoxLayout *select_layout;
	QDialogButtonBox *button_box;
	Calculator *calc;

	void createMainLayout();
	//void connectSlots();

private slots:
	void OK_button_clicked();
public:
	DeleteDialog(QWidget *parent);
	~DeleteDialog();
};



#endif // !DELETEDIALOG_H
