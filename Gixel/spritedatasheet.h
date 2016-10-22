#ifndef SPRITEDATASHEET_H
#define SPRITEDATASHEET_H


class SpriteDataSheet
{
public:
    SpriteDataSheet();
    std::vector<std::vector<std::tuple<int, int, int, int>>> totalData;
};

#endif // SPRITEDATASHEET_H
