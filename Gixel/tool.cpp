#include "tool.h"
Tool::Tool()//Abstract default tool. Black line, 1 pixel wide.
{
    painter = new QPainter();
    line.setWidth(1);
    line.setColor(Qt::black);
}

Tool::Tool(QPen line, QBrush fill, QColor color)//Specific Tool constructor for different tools
{
    painter = new QPainter();
    line.setColor(color);
    painter->setBrush(fill);
    painter->setPen(line);

}
