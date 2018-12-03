#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QTextBrowser>
#include <string>

#include "newmatrixdialog.h"
#include "newnumericstringdialog.h"
#include "editvaluedialog.h"
#include "operationdialog.h"
#include "deletedialog.h"
#include "Calculator.h"

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);
    ~Dialog();
	Calculator* getCalculator();
private:
    enum {
        Mat = 0, Add, Sub, Num, Mul, Div, Str, Edit, Del, Clear
    };
	
	std::string getButtonNames(int index);
    void createMainLayout();
	void connectSlots();
	void showVariable(QString name) const;

    QVBoxLayout *main_layout;
	QLabel *result_label;
    QTextBrowser *result_output;
    QGridLayout *button_layout;
    QPushButton *buttons[10];
	Calculator *calc;
private slots:
	void MatButtonClicked();
	void AddButtonClicked();
	void SubButtonClicked();
	void NumButtonClicked();
	void MulButtonClicked();
	void DivButtonClicked();
	void StrButtonClicked();
	void EditButtonClicked();
	void DelButtonClicked();
	void ClearButtonClicked();
};

#endif // DIALOG_H
