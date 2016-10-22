#ifndef TOOL_H
#define TOOL_H
#include "QPainter"

#include <QPainter>

class Tool : public QPainter
{
public:

    Tool();
    QPen line;
    QBrush fill;
    QColor color;

    Tool(); //Inherits publically from QPainter, empty implementation
};

#endif // TOOL_H
