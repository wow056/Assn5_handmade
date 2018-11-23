#ifndef NEWMATRIXDIALOG_H
#define NEWMATRIXDIALOG_H

#include <QDialog>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QDialogButtonBox>

class NewMatrixDialog : public QDialog
{
	Q_OBJECT

public:
	NewMatrixDialog(QWidget *parent);
	~NewMatrixDialog();

private:
	enum { Name = 0, Rows, Cols, Init };

	QGridLayout *main_layout;
	QDialogButtonBox *button_box;
	QVBoxLayout *input_layout[4];
	QLabel *label[4];
	QLineEdit *input_line[4];

	void createMainLayout();
};


#endif // !NEWMATRIXDIALOG_H
