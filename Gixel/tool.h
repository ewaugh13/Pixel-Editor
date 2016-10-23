#ifndef TOOL_H
#define TOOL_H
#include "QPainter"

class Tool
{
public:

    Tool();
    Tool(QPen, QBrush, QColor); //Inherits publically from QPainter, empty implementation

    QPainter* painter;
    QPen line;
    QColor color;
};
class Pen : public Tool
{
    public:
        Pen();
        //basic parameters

};

#endif // TOOL_H
