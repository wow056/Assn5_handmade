#ifndef VARIALBELABEL_H
#define VARIALBELABEL_H

#include "Calculator.h"
#include <QLabel>

class VariableLabel : public QLabel
{
	Q_OBJECT

private:
	Calculator *calc;
public:
	VariableLabel(QWidget *parent);
	~VariableLabel();

public slots:
	void variable_selected(const QString&);
};

#endif // !VARIALBELABEL_H
