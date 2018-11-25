#ifndef NEWNUMERICSTRINGDIALOG_H
#define NEWNUMERICSTRINGDIALOG_H

#include <QDialog>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QDialogButtonBox>
#include <QValidator>


class NewNumericStringDialog : public QDialog
{
	Q_OBJECT

public:
	NewNumericStringDialog(QWidget *parent);
	~NewNumericStringDialog();
protected:
	enum { Name = 0, Init };
	QVBoxLayout *main_layout;
	QVBoxLayout *input_layout[2];
	QLabel *label[2];
	QLineEdit *input_line[2];
	QDialogButtonBox *button_box;

	void createMainLayout();
};

class NewNumericDialog : public NewNumericStringDialog
{
public:
	NewNumericDialog(QWidget *parent);
	~NewNumericDialog();
};

class NewStringDialog : public NewNumericStringDialog
{
public:
	NewStringDialog(QWidget *parent);
	~NewStringDialog();
};

#endif