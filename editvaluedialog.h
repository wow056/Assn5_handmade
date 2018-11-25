#ifndef EDITVALUEDIALOG_H
#define EDITVALUEDIALOG_H

#include <QDialog>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QWidget>
#include <QDialogButtonBox>


class EditValueDialog : public QDialog
{
	Q_OBJECT

private slots:
	void changeToMatrixLayout();
	void changeToStringLayout();

public:
	EditValueDialog(QWidget *parent);
	~EditValueDialog();

private:
	enum {Row=0, Col, Value};
	QVBoxLayout *main_layout;
	QLabel *select_label;
	QComboBox *select_combobox;
	QVBoxLayout *select_layout;
	QLabel *select_info;
	QWidget *select_widget;
	QWidget *matrix_widget;
	QWidget *value_widget;
	QHBoxLayout *matrix_layout;
	QVBoxLayout *input_layout[3];
	QLabel *label[3];
	QLineEdit *input_line[3];
	QDialogButtonBox *button_box;

	void createMainLayout();
	void connectSlots();
};

#endif // !EDITVALUEDIALOG_H
