#ifndef TOOL_H
#define TOOL_H
#include "QPainter"

#include <QPainter>

class Tool
{
public:

    Tool();
    QPainter* painter;
    QPen line;
    QBrush fill;
    QColor color;

    Tool(QPen, QBrush, QColor); //Inherits publically from QPainter, empty implementation
};

#endif // TOOL_H
