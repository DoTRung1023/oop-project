#ifndef __BOARD_H__
#define __BOARD_H__

struct Board{
    static int index[7][9];

    static void loadIndex();
    static void saveIndex();
    static void makeNewBoard();
    static bool checkEmpty();
    static void clearIndex();
};

#endif