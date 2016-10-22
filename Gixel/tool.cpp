#include "tool.h"

Tool::Tool(QPen line, QBrush fill, QColor color){
    painter = new QPainter();
    line.setColor(color);
    painter->setBrush(fill);
    painter->setPen(line);

}
