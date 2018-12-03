#include "variablelabel.h"

VariableLabel::VariableLabel(QWidget *parent)
	: QLabel(parent), calc(Calculator::GetInstance())
{
}

VariableLabel::~VariableLabel()
{
}

void VariableLabel::variable_selected(const QString &s)
{
	setText(calc->getVariableInfo(s.toStdString()));
}
