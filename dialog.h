#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QTextBrowser>
#include <string>

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);
    ~Dialog();
private:
    enum {
        Mat = 0, Add, Sub, Num, Mul, Div, Str, Edit, Del, Clear
    };
	
	std::string getButtonNames(int index);
    void createMainLayout();
	void createOutputLayout();
    void createButtonLayout();

    QVBoxLayout *main_layout;
    QTextBrowser *result_output;
    QVBoxLayout *button_layout;
    QHBoxLayout *button_layout_row[4];
    QPushButton *buttons[10];
};

#endif // DIALOG_H
