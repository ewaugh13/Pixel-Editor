#ifndef TOOL_H
#define TOOL_H
#include "QPainter"


class Tool : public QPainter
{
public:
    Tool();
    QPen line;
    QBrush fill;
    QColor color;

};

#endif // TOOL_H
