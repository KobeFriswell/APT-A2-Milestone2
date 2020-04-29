

class Board {
public:
    Board();

    Board getBoard();

    void setWallTile(int x, int y, char tile);
    int getWall();

    void setPatternTile(int x,int y, char tile);
    int getPatternLine();

    void dropTile(char tile);
    

private: 

    int wall[5][5];
    int PatternLine[5][5];
    //int scoreTrack;
    };

