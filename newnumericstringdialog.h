#ifndef NEWNUMERICSTRINGDIALOG_H
#define NEWNUMERICSTRINGDIALOG_H

#include <QDialog>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QDialogButtonBox>
#include <QDoubleValidator>
#include <QMessageBox>
#include "Calculator.h"

class NewNumericStringDialog : public QDialog
{
	Q_OBJECT

public:
	NewNumericStringDialog(QWidget *parent);
	~NewNumericStringDialog();
	QString made_name();
protected:
	enum { Name = 0, Init };
	QVBoxLayout *main_layout;
	QVBoxLayout *input_layout[2];
	QLabel *label[2];
	QLineEdit *input_line[2];
	QDialogButtonBox *button_box;
	Calculator *calc;

	void createMainLayout();
	void connectSlots();
	QString name_of_variable;
protected slots:
	virtual void OK_button_clicked() = 0;
};

class NewNumericDialog : public NewNumericStringDialog
{
	Q_OBJECT
public:
	NewNumericDialog(QWidget *parent);
	~NewNumericDialog();
private slots:
	virtual void OK_button_clicked();
};

class NewStringDialog : public NewNumericStringDialog
{
	Q_OBJECT
public:
	NewStringDialog(QWidget *parent);
	~NewStringDialog();
private slots:
	virtual void OK_button_clicked();
};

#endif