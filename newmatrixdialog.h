#ifndef NEWMATRIXDIALOG_H
#define NEWMATRIXDIALOG_H

#include <QDialog>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QDialogButtonBox>
#include <QIntValidator>
#include <QDoubleValidator>
#include <QMessageBox>
#include "Calculator.h"

class NewMatrixDialog : public QDialog
{
	Q_OBJECT

public:
	NewMatrixDialog(QWidget *parent);
	~NewMatrixDialog();
	QString made_name();

private:
	enum { Name = 0, Rows, Cols, Init };

	QGridLayout *main_layout;
	QDialogButtonBox *button_box;
	QVBoxLayout *input_layout[4];
	QLabel *label[4];
	QLineEdit *input_line[4];
	Calculator* calc;

	void createMainLayout();
	void connectSlots();

	QString name_of_variable;
private slots:
	void OK_button_clicked();
};


#endif // !NEWMATRIXDIALOG_H
