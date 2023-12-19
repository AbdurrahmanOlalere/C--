#include <iostream>
#include <fstream>
#include <string>
#include "logic.h"

using std::cout, std::endl, std::ifstream, std::string;

/**
 * TODO: Student implement this function
 * Load representation of the dungeon level from file into the 2D map.
 * Calls createMap to allocate the 2D array.
 * @param   fileName    File name of dungeon level.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @param   maxCol      Number of columns in the dungeon table (aka width).
 * @param   player      Player object by reference to set starting position.
 * @return  pointer to 2D dynamic array representation of dungeon map with player's location., or nullptr if loading fails for any reason
 * @updates  maxRow, maxCol, player
 */

char** loadLevel(const string& fileName, int& maxRow, int& maxCol, Player& player) {
    ifstream file(fileName);
    bool isDoororExit = false;
    if (!file.is_open())
    {
        return nullptr;
    }

    if (!(file >> maxRow >> maxCol)) {
       // cout << "Invalid or missing dimensions in the input file." << endl;
        return nullptr;
    }

    if (maxRow <= 0 || maxCol <= 0 || maxRow >= 999999 || maxCol > 999999) {

        return nullptr;
    }
     
    if (maxRow > (INT32_MAX/maxCol) && (maxCol > 0) && (maxRow > 0))
    {
        return nullptr;
    } else if ( maxRow < (INT32_MAX/maxCol) && (maxCol < 0) && (maxCol < 0)){
        return nullptr;
    }
    else if (maxCol > (INT32_MIN/maxRow)&& (maxCol > 0) && (maxRow < 0))
    {
        return nullptr;
    }
    else if (maxCol < (INT32_MIN/maxRow)&& (maxCol < 0) && (maxRow > 0))
    {
        return nullptr;
    }

    

    char** map = new char*[maxRow];
    for (int i = 0; i < maxRow; ++i)
    {
        map[i] = new char[maxCol];
    }
    
    if (!(file >> player.row >> player.col))
    {
        for (int i = 0; i < maxRow; ++i) {
            delete[] map[i];
        }
        delete[] map;
        return nullptr;
    }
    
    if (player.row/player.col > 0 || player.row/player.col >= maxRow/maxCol)
    {
        for (int i = 0; i < maxRow; ++i) {
            delete[] map[i];
        }
        delete[] map;
        return nullptr;
    }
    

    
    

    for (int row = 0; row < maxRow; ++row)
    {
        for (int col = 0; col < maxCol; ++col)
        {
            char tile;
            if (file.fail())
            {
                for (int i = 0; i < maxRow; ++i)
                {
                    delete[] map[i];
                }
                delete[] map;
                return nullptr;
            }
            
            if (file.eof())
            {
                for (int i = 0; i < maxRow; ++i)
                {
                    delete[] map[i];
                }
                delete[] map;
                return nullptr;
            }
            
            if (!(file >> tile))
            {
                for (int i = 0; i < maxRow; ++i)
                {
                    delete[] map[i];
                }
                delete[] map;
                return nullptr;
                
            }
            if (tile == TILE_PLAYER)
            {
                for (int i = 0; i < maxRow; ++i)
                {
                    delete[] map[i];
                }
                delete[] map;
                return nullptr;
                
            }
            if (tile == TILE_DOOR || tile == TILE_EXIT){
                isDoororExit = true;
            }
            else if (isDoororExit == false)
            {
                for (int i = 0; i < maxRow; ++i)
                {
                    delete[] map[i];
                }
                delete[] map;
                return nullptr;
            }
            
            if (tile != TILE_AMULET || tile != TILE_DOOR || tile != TILE_EXIT || tile != TILE_MONSTER || tile != TILE_OPEN || tile != TILE_PILLAR || tile != TILE_TREASURE)
            {
                for (int i = 0; i < maxRow; ++i)
                {
                    delete[] map[i];
                }
                delete[] map;
                return nullptr;
            }
            
            map[row][col] = tile;
            //cout << player.row << " " << player.col << endl; //used to test for player position.
            map[player.row][player.col] = TILE_PLAYER;
            
            
        }
        
    }
    if (!file.eof())
    {
        for (int i = 0; i < maxRow; ++i)
            {
                delete[] map[i];
            }
        delete[] map;
        return nullptr;
    }


    
    
    
    
    return map;
}

/**
 * TODO: Student implement this function
 * Translate the character direction input by the user into row or column change.
 * That is, updates the nextRow or nextCol according to the player's movement direction.
 * @param   input       Character input by the user which translates to a direction.
 * @param   nextRow     Player's next row on the dungeon map (up/down).
 * @param   nextCol     Player's next column on dungeon map (left/right).
 * @updates  nextRow, nextCol
 */
void getDirection(char input, int& nextRow, int& nextCol) {
    if (input == MOVE_UP)
    {
        nextRow--;
    } else if (input == MOVE_DOWN)
    {
        nextRow++;
    } else if (input == MOVE_LEFT)
    {
        nextCol--;
    } else if (input == MOVE_RIGHT)
    {
        nextCol++;
    }
    
}

/**
 * TODO: [suggested] Student implement this function
 * Allocate the 2D map array.
 * Initialize each cell to TILE_OPEN.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @param   maxCol      Number of columns in the dungeon table (aka width).
 * @return  2D map array for the dungeon level, holds char type.
 */
char** createMap(int maxRow, int maxCol) {
    if (maxRow <= 0 || maxCol <= 0)
    {
        return nullptr;
    }

    char ** map = new char*[maxRow];

    for (int row = 0; row < maxRow; ++row)
    {
        map[row] = new char[maxCol];
    }

    for (int row = 0; row < maxRow; ++row)
    {
        for (int col = 0; col < maxCol; ++col)
        {
            map[row][col] = TILE_OPEN;
        }
        
    }
    
    
    
    
    return map;
}

/**
 * TODO: Student implement this function
 * Deallocates the 2D map array.
 * @param   map         Dungeon map.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @return None
 * @update map, maxRow
 */
void deleteMap(char**& map, int& maxRow) {
    if (map == nullptr) {
        maxRow =0;
        return;
    }

    for (int i = 0; i < maxRow; i++) {
        delete[] map[i];
    }
    maxRow = 0;
    delete[] map;

    map = nullptr;
    
}

/**
 * TODO: Student implement this function
 * Resize the 2D map by doubling both dimensions.
 * Copy the current map contents to the right, diagonal down, and below.
 * Do not duplicate the player, and remember to avoid memory leaks!
 * You can use the STATUS constants defined in logic.h to help!
 * @param   map         Dungeon map.
 * @param   maxRow      Number of rows in the dungeon table (aka height), to be doubled.
 * @param   maxCol      Number of columns in the dungeon table (aka width), to be doubled.
 * @return  pointer to a dynamically-allocated 2D array (map) that has twice as many columns and rows in size.
 * @update maxRow, maxCol
 */

char** resizeMap(char** map, int& maxRow, int& maxCol) {
    int newMaxRw = 2 * maxRow;
    int newMaxCl = 2 * maxCol;
    //int tempMaxrw = maxRow;

    if (map == nullptr || maxRow == 0 || maxCol == 0)
    {
        return nullptr;
    }
    //cout << "Creating new Map" << endl; // lowkey could have used createMap function
    char** rsizedMap = createMap(newMaxRw, newMaxCl);

    //first fill of the map with tile_open
    //cout << "Filling  Map with Empty Tiles" << endl;
    for (int row = 0; row < newMaxRw; ++row) {
        for (int col = 0; col < newMaxCl; ++col) {
            rsizedMap[row][col] = TILE_OPEN;
        }
    }

    //copying the orginal map to the top left corner quauter
    //cout << "Filling first Quarter Map" << endl;
    for (int row = 0; row < maxRow; ++row) {
        for (int col = 0; col < maxCol; ++col) {
            char tile = map[row][col];
            rsizedMap[row][col] = tile;
        }
    }

    //now copying the rest of map with the three additiona copies:
    //cout << "Filling other three Map" << endl;
    for (int row = 0; row < maxRow; ++row) {
        for (int col = 0; col < maxCol; ++col) {
            char tile = rsizedMap[row][col];
            if (tile != TILE_PLAYER) {
                rsizedMap[row][col + maxCol] = tile;
                rsizedMap[row + maxRow][col] = tile;
                rsizedMap[row + maxRow][col + maxCol] = tile;
            }
            else if(tile == TILE_PLAYER) {
                rsizedMap[row][col + maxCol] = TILE_OPEN;
                rsizedMap[row + maxRow][col] = TILE_OPEN;
                rsizedMap[row + maxRow][col + maxCol] = TILE_OPEN;
            }
        }
    }
    //delete old map
    
    deleteMap(map, maxRow);



    

    maxRow = newMaxRw;
    maxCol = newMaxCl;


    return rsizedMap;
}
/**
 * TODO: Student implement this function
 * Checks if the player can move in the specified direction and performs the move if so.
 * Cannot move out of bounds or onto TILE_PILLAR or TILE_MONSTER.
 * Cannot move onto TILE_EXIT without at least one treasure. 
 * If TILE_TREASURE, increment treasure by 1.
 * Remember to update the map tile that the player moves onto and return the appropriate status.
 * You can use the STATUS constants defined in logic.h to help!
 * @param   map         Dungeon map.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @param   maxCol      Number of columns in the dungeon table (aka width).
 * @param   player      Player object to by reference to see current location.
 * @param   nextRow     Player's next row on the dungeon map (up/down).
 * @param   nextCol     Player's next column on dungeon map (left/right).
 * @return  Player's movement status after updating player's position.
 * @update map contents, player
 */
int doPlayerMove(char** map, int maxRow, int maxCol, Player& player, int nextRow, int nextCol) {
    if (nextRow < 0 || nextRow >= maxRow || nextCol < 0 || nextCol >= maxCol) {
        player.row = player.row; // staying still
        player.col = player.col;
        return STATUS_STAY;
    }

    char nextTile = map[nextRow][nextCol];  

    if (nextTile == TILE_PILLAR || nextTile == TILE_MONSTER) {
        player.row = player.row;
        player.col = player.col;
        return STATUS_STAY;
    }

    if (nextTile == TILE_TREASURE) {
        player.treasure++;
        map[nextRow][nextCol] = TILE_OPEN;// destroy treasure
        map[player.row][player.col] = TILE_OPEN;
        player.row = nextRow;
        player.col = nextCol;
        map[player.row][player.col] = TILE_PLAYER;
        return STATUS_TREASURE;
    }

    if (nextTile == TILE_AMULET) {
        // put the player to the new position
        map[player.row][player.col] = TILE_OPEN; 
        map[nextRow][nextCol] = TILE_PLAYER;     
        player.row = nextRow;
        player.col = nextCol;


        return STATUS_AMULET;
    }

    if (nextTile == TILE_EXIT) {
        if (player.treasure > 0) {
            map[nextRow][nextCol] = TILE_PLAYER;
            map[player.row][player.col] = TILE_OPEN;
            player.row = nextRow;
            player.col = nextCol;
            return STATUS_ESCAPE;
        } else {
            return STATUS_STAY;
        }
    }

    if (nextTile == TILE_DOOR)
    {
        map[nextRow][nextCol] = TILE_PLAYER;// destroy 
        map[player.row][player.col] = TILE_OPEN;
        player.row = nextRow;
        player.col = nextCol;
        //map[player.row][player.col] = TILE_PLAYER;
        return STATUS_LEAVE;
    }
    

    map[player.row][player.col] = TILE_OPEN; 
    map[nextRow][nextCol] = TILE_PLAYER;     
    player.row = nextRow;
    player.col = nextCol;

    return STATUS_MOVE;
}

/**
 * TODO: Student implement this function
 * Update monster locations:
 * We check up, down, left, right from the current player position.
 * If we see an obstacle, there is no line of sight in that direction, and the monster does not move.
 * If we see a monster before an obstacle, the monster moves one tile toward the player.
 * We should update the map as the monster moves.
 * At the end, we check if a monster has moved onto the player's tile.
 * @param   map         Dungeon map.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @param   maxCol      Number of columns in the dungeon table (aka width).
 * @param   player      Player object by reference for current location.
 * @return  Boolean value indicating player status: true if monster reaches the player, false if not.
 * @update map contents
 */
bool doMonsterAttack(char** map, int maxRow, int maxCol, const Player& player) {
    int playerRw = player.row;
    int playerCl = player.col;
    bool Killed = false;

    //check up
    for (int row = playerRw-1; row >= 0; --row)
    {
        char tile = map[row][playerCl];

        if (tile == TILE_MONSTER)
        {
            map[row][playerCl] = TILE_OPEN;
            map[row + 1][playerCl] = TILE_MONSTER;
            //cout << "Monster check up" << endl;
            
            if (row+1 == playerRw)
            {
                Killed = true;
            }
            
        }
        else if (tile == TILE_PILLAR)
        {
            break;
        }
        
    }
    //chek down
    for (int row = playerRw + 1; row < maxRow; ++row)
    {
        char tile = map[row][playerCl];

        if (tile == TILE_MONSTER)
        {
            map[row][playerCl] = TILE_OPEN;// forgot to set this to = rather than ==
            map[row - 1][playerCl] = TILE_MONSTER;
            //cout << "Monster check down" << endl;

            if (row - 1 == playerRw)
            {
                Killed = true;
            }
            
        } else if (tile == TILE_PILLAR)
        {
            break;
        }
        
    }
    //check left
    for (int col = playerCl - 1; col >= 0; --col) {
        char tile = map[playerRw][col];

        if (tile == TILE_MONSTER) {
            map[playerRw][col] = TILE_OPEN;
            map[playerRw][col + 1] = TILE_MONSTER;
            //cout << "Monster check left" << endl;

            if (col + 1 == playerCl) {
                Killed = true;
            }
        } else if (tile == TILE_PILLAR) {
            break;
        }
    }

    // Check right
    for (int col = playerCl + 1; col < maxCol; ++col) {
        char tile = map[playerRw][col];

        if (tile == TILE_MONSTER) {
            map[playerRw][col] = TILE_OPEN;
            map[playerRw][col - 1] = TILE_MONSTER;
            //cout << "Monster check right" << endl;

            if (col - 1 == playerCl) {
                Killed = true;
            }
        } else if (tile == TILE_PILLAR) {
            break;
        }
    }

    if (Killed) {
        map[playerRw][playerCl] = TILE_MONSTER;
        return true;
    } 
    return false;
}
