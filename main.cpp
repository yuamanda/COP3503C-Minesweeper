#include <iostream>
#include <SFML/Graphics.hpp>
#include <fstream>
#include <vector>
#include "TextureManager.h"
#include "Random.h"
using namespace std;
using namespace sf;

// recursive function to reveal tiles on the board
void revealTiles(vector<Sprite>& tileHiddenVector, vector<int>& tileType, vector<int>& numbers, vector<Sprite>& flagVector, int tileIndex, int numCol, int numRow)
{
    tileHiddenVector.at(tileIndex).setTexture(TextureManager::GetTexture("tile_revealed"));
    tileType.at(tileIndex) = 2;

    // get the value of numbers at tileIndex
    // change the texture of flag vector accordingly

    // if count is equal to 1, then set texture to number_1
    if(numbers.at(tileIndex) == 1)
    {
        flagVector.at(tileIndex).setTexture(TextureManager::GetTexture("number_1"));
    }

    // if count is equal to 2, then set texture to number_2
    else if(numbers.at(tileIndex) == 2)
    {
        flagVector.at(tileIndex).setTexture(TextureManager::GetTexture("number_2"));
    }

    // if count is equal to 3, then set texture to number_3
    else if(numbers.at(tileIndex) == 3)
    {
        flagVector.at(tileIndex).setTexture(TextureManager::GetTexture("number_3"));
    }

    // if count is equal to 4, then set texture to number_4
    else if(numbers.at(tileIndex) == 4)
    {
        flagVector.at(tileIndex).setTexture(TextureManager::GetTexture("number_4"));
    }

    // if count is equal to 5, then set texture to number_5
    else if(numbers.at(tileIndex) == 5)
    {
        flagVector.at(tileIndex).setTexture(TextureManager::GetTexture("number_5"));
    }

    // if count is equal to 6, then set texture to number_6
    else if(numbers.at(tileIndex) == 6)
    {
        flagVector.at(tileIndex).setTexture(TextureManager::GetTexture("number_6"));
    }

    // if count is equal to 7, then set texture to number_7
    else if(numbers.at(tileIndex) == 7)
    {
        flagVector.at(tileIndex).setTexture(TextureManager::GetTexture("number_7"));
    }

    // if count is equal to 8, then set texture to number_8
    else if(numbers.at(tileIndex) == 8)
    {
        flagVector.at(tileIndex).setTexture(TextureManager::GetTexture("number_8"));
    }

    // recursion implemented here
    else
    {
        // checks top left corner of board
        if(tileIndex == 0)
        {
            if(tileType.at(tileIndex + 1) != 1 && tileType.at(tileIndex + 1) != 2)
            {
                revealTiles(tileHiddenVector, tileType, numbers, flagVector, tileIndex + 1, numCol, numRow);
            }

            // checks tile bottom right
            if(tileType.at(tileIndex + numCol + 1) != 1 && tileType.at(tileIndex + numCol + 1) != 2)
            {
                revealTiles(tileHiddenVector, tileType, numbers, flagVector, tileIndex + numCol + 1, numCol, numRow);
            }

            // checks tile below
            if(tileType.at(tileIndex + numCol) != 1 && tileType.at(tileIndex + numCol) != 2)
            {
                revealTiles(tileHiddenVector, tileType, numbers, flagVector, tileIndex + numCol, numCol, numRow);
            }
        }

        // checks top right corner of board
        else if(tileIndex == numCol - 1)
        {
            // checks tile to the left
            if(tileType.at(tileIndex - 1) != 1 && tileType.at(tileIndex - 1) != 2)
            {
                revealTiles(tileHiddenVector, tileType, numbers, flagVector, tileIndex - 1, numCol, numRow);
            }

            // checks tile bottom left
            if(tileType.at(tileIndex + numCol - 1) != 1 && tileType.at(tileIndex + numCol - 1) != 2)
            {
                revealTiles(tileHiddenVector, tileType, numbers, flagVector, tileIndex + numCol - 1, numCol, numRow);
            }

            // checks tile below
            if(tileType.at(tileIndex + numCol) != 1 && tileType.at(tileIndex + numCol) != 2)
            {
                revealTiles(tileHiddenVector, tileType, numbers, flagVector, tileIndex + numCol, numCol, numRow);
            }
        }

        // checks bottom left corner of board
        else if(tileIndex == (numRow * numCol) - numCol)
        {
            // checks tile above
            if(tileType.at(tileIndex - numCol) != 1 && tileType.at(tileIndex - numCol) != 2)
            {
                revealTiles(tileHiddenVector, tileType, numbers, flagVector, tileIndex - numCol, numCol, numRow);
            }

            // checks tile top right
            if(tileType.at(tileIndex - numCol + 1) != 1 && tileType.at(tileIndex - numCol + 1) != 2)
            {
                revealTiles(tileHiddenVector, tileType, numbers, flagVector, tileIndex - numCol + 1, numCol, numRow);
            }

            // checks tile to the right
            if(tileType.at(tileIndex + 1) != 1 && tileType.at(tileIndex + 1) != 2)
            {
                revealTiles(tileHiddenVector, tileType, numbers, flagVector, tileIndex + 1, numCol, numRow);
            }
        }

        // check bottom right corner of board
        else if(tileIndex == (numCol * numRow) - 1)
        {
            // checks tile above
            if(tileType.at(tileIndex - numCol) != 1 && tileType.at(tileIndex - numCol) != 2)
            {
                revealTiles(tileHiddenVector, tileType, numbers, flagVector, tileIndex - numCol, numCol, numRow);
            }

            // checks tile top left
            if(tileType.at(tileIndex - numCol - 1) != 1 && tileType.at(tileIndex - numCol - 1) != 2)
            {
                revealTiles(tileHiddenVector, tileType, numbers, flagVector, tileIndex - numCol - 1, numCol, numRow);
            }

            // checks tile to the left
            if(tileType.at(tileIndex - 1) != 1 && tileType.at(tileIndex - 1) != 2)
            {
                revealTiles(tileHiddenVector, tileType, numbers, flagVector, tileIndex - 1, numCol, numRow);
            }
        }

        // check if tile is in top row of board
        else if(tileIndex > 0 && tileIndex < numCol - 1)
        {
            // checks tile to the left
            if(tileType.at(tileIndex - 1) != 1 && tileType.at(tileIndex - 1) != 2)
            {
                revealTiles(tileHiddenVector, tileType, numbers, flagVector, tileIndex - 1, numCol, numRow);
            }

            // checks tile bottom left
            if(tileType.at(tileIndex + numCol - 1) != 1 && tileType.at(tileIndex + numCol - 1) != 2)
            {
                revealTiles(tileHiddenVector, tileType, numbers, flagVector, tileIndex + numCol - 1, numCol, numRow);
            }

            // checks tile below
            if(tileType.at(tileIndex + numCol) != 1 && tileType.at(tileIndex + numCol) != 2)
            {
                revealTiles(tileHiddenVector, tileType, numbers, flagVector, tileIndex + numCol, numCol, numRow);
            }

            // checks tile bottom right
            if(tileType.at(tileIndex + numCol + 1) != 1 && tileType.at(tileIndex + numCol + 1) != 2)
            {
                revealTiles(tileHiddenVector, tileType, numbers, flagVector, tileIndex + numCol + 1, numCol, numRow);
            }

            // checks tile to the right
            if(tileType.at(tileIndex + 1) != 1 && tileType.at(tileIndex + 1) != 2)
            {
                revealTiles(tileHiddenVector, tileType, numbers, flagVector, tileIndex + 1, numCol, numRow);
            }
        }

        // check if tile is in bottom row of board
        else if(tileIndex > (numCol * numRow) - numCol && tileIndex < (numCol * numRow) - 1)
        {
            // checks tile to the left
            if(tileType.at(tileIndex - 1) != 1 && tileType.at(tileIndex - 1) != 2)
            {
                revealTiles(tileHiddenVector, tileType, numbers, flagVector, tileIndex - 1, numCol, numRow);
            }

            // checks tile top left
            if(tileType.at(tileIndex - numCol - 1) != 1 && tileType.at(tileIndex - numCol - 1) != 2)
            {
                revealTiles(tileHiddenVector, tileType, numbers, flagVector, tileIndex - numCol - 1, numCol, numRow);
            }

            // checks tile above
            if(tileType.at(tileIndex - numCol) != 1 && tileType.at(tileIndex - numCol) != 2)
            {
                revealTiles(tileHiddenVector, tileType, numbers, flagVector, tileIndex - numCol, numCol, numRow);
            }

            // checks tile top right
            if(tileType.at(tileIndex - numCol + 1) != 1 && tileType.at(tileIndex - numCol + 1) != 2)
            {
                revealTiles(tileHiddenVector, tileType, numbers, flagVector, tileIndex - numCol + 1, numCol, numRow);
            }

            // checks tile to the right
            if(tileType.at(tileIndex + 1) != 1 && tileType.at(tileIndex + 1) != 2)
            {
                revealTiles(tileHiddenVector, tileType, numbers, flagVector, tileIndex + 1, numCol, numRow);
            }
        }

        // check if tile is in left column of board
        else if(tileIndex % numCol == 0)
        {
            // checks tile above
            if(tileType.at(tileIndex - numCol) != 1 && tileType.at(tileIndex - numCol) != 2)
            {
                revealTiles(tileHiddenVector, tileType, numbers, flagVector, tileIndex - numCol, numCol, numRow);
            }

            // checks tile top right
            if(tileType.at(tileIndex - numCol + 1) != 1 && tileType.at(tileIndex - numCol + 1) != 2)
            {
                revealTiles(tileHiddenVector, tileType, numbers, flagVector, tileIndex - numCol + 1, numCol, numRow);
            }

            // checks tile to the right
            if(tileType.at(tileIndex + 1) != 1 && tileType.at(tileIndex + 1) != 1)
            {
                revealTiles(tileHiddenVector, tileType, numbers, flagVector, tileIndex + 1, numCol, numRow);
            }

            // checks tile bottom right
            if(tileType.at(tileIndex + numCol + 1) != 1 && tileType.at(tileIndex + numCol + 1) != 2)
            {
                revealTiles(tileHiddenVector, tileType, numbers, flagVector, tileIndex + numCol + 1, numCol, numRow);
            }

            // checks tile below
            if(tileType.at(tileIndex + numCol) != 1 && tileType.at(tileIndex + numCol) != 2)
            {
                revealTiles(tileHiddenVector, tileType, numbers, flagVector, tileIndex + numCol, numCol, numRow);
            }
        }

        // check if tile is in right column of board
        else if(tileIndex % numCol - numCol + 1 == 0)
        {
            // checks tile above
            if(tileType.at(tileIndex - numCol) != 1 && tileType.at(tileIndex - numCol) != 2)
            {
                revealTiles(tileHiddenVector, tileType, numbers, flagVector, tileIndex - numCol, numCol, numRow);
            }

            // checks tile top left
            if(tileType.at(tileIndex - numCol - 1) != 1 && tileType.at(tileIndex - numCol - 1) != 2)
            {
                revealTiles(tileHiddenVector, tileType, numbers, flagVector, tileIndex - numCol - 1, numCol, numRow);
            }

            // checks tile to the left
            if(tileType.at(tileIndex - 1) != 1 && tileType.at(tileIndex - 1) != 2)
            {
                revealTiles(tileHiddenVector, tileType, numbers, flagVector, tileIndex - 1, numCol, numRow);
            }

            // checks tile bottom left
            if(tileType.at(tileIndex + numCol - 1) != 1 && tileType.at(tileIndex + numCol - 1) != 2)
            {
                revealTiles(tileHiddenVector, tileType, numbers, flagVector, tileIndex + numCol - 1, numCol, numRow);
            }

            // checks tile below
            if(tileType.at(tileIndex + numCol) != 1 && tileType.at(tileIndex + numCol) != 2)
            {
                revealTiles(tileHiddenVector, tileType, numbers, flagVector, tileIndex + numCol, numCol, numRow);
            }
        }

        // if not a corner and not a side, then check all sides
        else
        {
            // checks tile to the right
            if(tileType.at(tileIndex + 1) != 1 && tileType.at(tileIndex + 1) != 2)
            {
                revealTiles(tileHiddenVector, tileType, numbers, flagVector, tileIndex + 1, numCol, numRow);
            }

            // checks tile to the left
            if(tileType.at(tileIndex - 1) != 1 && tileType.at(tileIndex - 1) != 2)
            {
                revealTiles(tileHiddenVector, tileType, numbers, flagVector, tileIndex - 1, numCol, numRow);
            }

            // checks tile above
            if(tileType.at(tileIndex - numCol) != 1 && tileType.at(tileIndex - numCol) != 2)
            {
                revealTiles(tileHiddenVector, tileType, numbers, flagVector, tileIndex - numCol, numCol, numRow);
            }

            // checks tile below
            if(tileType.at(tileIndex + numCol) != 1 && tileType.at(tileIndex + numCol) != 2)
            {
                revealTiles(tileHiddenVector, tileType, numbers, flagVector, tileIndex + numCol, numCol, numRow);
            }

            // checks tile top left
            if(tileType.at(tileIndex - numCol - 1) != 1 && tileType.at(tileIndex - numCol - 1) != 2)
            {
                revealTiles(tileHiddenVector, tileType, numbers, flagVector, tileIndex - numCol - 1, numCol, numRow);
            }

            // checks tile top right
            if(tileType.at(tileIndex - numCol + 1) != 1 && tileType.at(tileIndex - numCol + 1) != 2)
            {
                revealTiles(tileHiddenVector, tileType, numbers, flagVector, tileIndex - numCol + 1, numCol, numRow);
            }

            // checks tile bottom left
            if(tileType.at(tileIndex + numCol - 1) != 1 && tileType.at(tileIndex + numCol - 1) != 2)
            {
                revealTiles(tileHiddenVector, tileType, numbers, flagVector, tileIndex + numCol - 1, numCol, numRow);
            }

            // checks tile bottom right
            if(tileType.at(tileIndex + numCol + 1) != 1 && tileType.at(tileIndex + numCol + 1) != 2)
            {
                revealTiles(tileHiddenVector, tileType, numbers, flagVector, tileIndex + numCol + 1, numCol, numRow);
            }
        }
    }
}

int main()
{
    // open config.cfg file
    ifstream currentFile;
    ifstream config;

    ifstream inFile("boards/config.cfg");

    string lineFromFile;

    getline(inFile, lineFromFile);
    int numCol = stoi(lineFromFile);

    getline(inFile, lineFromFile);
    int numRow = stoi(lineFromFile);

    getline(inFile, lineFromFile);
    int numMines = stoi(lineFromFile);

    int reset = numMines;
    int digits = numMines;
    int original = numMines;

    int revealWin = 0;

    // render window with the read in values
    sf::RenderWindow window(sf::VideoMode(numCol * 32, (numRow * 32) + 100), "Minesweeper");

    // makes blank texture
    TextureManager::CreateBlank();

    // makes tileHiddenVector and sets texture
    vector<Sprite> tileHiddenVector;
    for(int i = 0; i < numCol * numRow; i++)
    {
        Sprite tileHiddenSprite(TextureManager::GetTexture("tile_hidden"));
        tileHiddenVector.push_back(tileHiddenSprite);
    }

    // makes flagVector and sets texture
    vector<Sprite> flagVector;
    for(int i = 0; i < numCol * numRow; i++)
    {
        Sprite blankTilesSprite;
        flagVector.push_back(blankTilesSprite);
    }

    // KEY FOR TILE TYPE VECTOR
    // 0: tile is hidden and has no flag
    // 1: tile is hidden and has a flag
    // 2: tile is revealed
    // 3: tile is hidden and has a bomb
    // 4: tile is revealed and has a bomb
    // 5: tile is hidden and has a bomb and has a flag
    // 6: game over, can't press anything except face_lose and test buttons
    vector<int> tileType;
    for(int i = 0; i < numCol * numRow; i++)
    {
        tileType.push_back(0);
    }

    // makes faceHappySprite and sets texture
    Sprite faceHappySprite(TextureManager::GetTexture("face_happy"));

    // makes faceLoseSprite and sets texture
    Sprite faceLoseSprite(TextureManager::GetTexture("face_lose"));

    // makes faceWinSprite and sets texture
    Sprite faceWinSprite(TextureManager::GetTexture("face_win"));

    // makes debugSprite and sets texture
    Sprite debugSprite(TextureManager::GetTexture("debug"));

    // makes test1Sprite and sets texture
    Sprite test1Sprite(TextureManager::GetTexture("test_1"));

    // makes test2Sprite and sets texture
    Sprite test2Sprite(TextureManager::GetTexture("test_2"));

    // makes test3Sprite and sets texture
    Sprite test3Sprite(TextureManager::GetTexture("test_3"));

    // makes test3Sprite and sets texture
    Sprite tileRevealedSprite(TextureManager::GetTexture("tile_revealed"));

    // makes mineSprite and sets texture
    Sprite mineSprite(TextureManager::GetTexture("mine"));

    // makes onesPlaceSprite and sets texture
    Sprite negativePlaceSprite(TextureManager::GetTexture("digits"), IntRect(210, 0, 21, 32));

    // makes onesPlaceSprite and sets texture
    Sprite onesPlaceSprite(TextureManager::GetTexture("digits"), IntRect(0, 0, 21, 32));

    // makes tensPlaceSprite and sets texture
    Sprite tensPlaceSprite(TextureManager::GetTexture("digits"), IntRect(0, 0, 21, 32));

    // makes hundredsPlaceSprite and sets texture
    Sprite hundredsPlaceSprite(TextureManager::GetTexture("digits"), IntRect(0, 0, 21, 32));

    // random number generator to randomly place mines on board
    int totalTiles = numCol * numRow;
    for(int i = 0; i < numCol * numRow; i++)
    {
        int random = Random::Int(0, totalTiles);

        if(random <= numMines && numMines != 0)
        {
            tileType.at(i) = 3;
            numMines--;
        }

        totalTiles--;
    }
    numMines = reset;

    // makes number_1Sprite and sets texture
    Sprite number_1Sprite(TextureManager::GetTexture("number_1"));

    // makes number_2Sprite and sets texture
    Sprite number_2Sprite(TextureManager::GetTexture("number_2"));

    // makes number_3Sprite and sets texture
    Sprite number_3Sprite(TextureManager::GetTexture("number_3"));

    // makes number_4Sprite and sets texture
    Sprite number_4Sprite(TextureManager::GetTexture("number_4"));

    // makes number_5Sprite and sets texture
    Sprite number_5Sprite(TextureManager::GetTexture("number_5"));

    // makes number_6Sprite and sets texture
    Sprite number_6Sprite(TextureManager::GetTexture("number_6"));

    // makes number_7Sprite and sets texture
    Sprite number_7Sprite(TextureManager::GetTexture("number_7"));

    // makes number_8Sprite and sets texture
    Sprite number_8Sprite(TextureManager::GetTexture("number_8"));

    // place numbers 1-8 on the board next to the mines
    vector<int> numbers;
    for(int i = 0; i < tileType.size(); i++)
    {
        int count = 0;

        // if the tile is not a bomb
        if(tileType.at(i) != 3)
        {
            // checks top left corner of board
            if(i == 0)
            {
                if(tileType.at(i + 1) == 3)
                {
                    count++;
                }

                // checks tile bottom right
                if(tileType.at(i + numCol + 1) == 3)
                {
                    count++;
                }

                // checks tile below
                if(tileType.at(i + numCol) == 3)
                {
                    count++;
                }
            }

            // checks top right corner of board
            else if(i == numCol - 1)
            {
                // checks tile to the left
                if(tileType.at(i - 1) == 3)
                {
                    count++;
                }

                // checks tile bottom left
                if(tileType.at(i + numCol - 1) == 3)
                {
                    count++;
                }

                // checks tile below
                if(tileType.at(i + numCol) == 3)
                {
                    count++;
                }
            }

            // checks bottom left corner of board
            else if(i == (numRow * numCol) - numCol)
            {
                // checks tile above
                if(tileType.at(i - numCol) == 3)
                {
                    count++;
                }

                // checks tile top right
                if(tileType.at(i - numCol + 1) == 3)
                {
                    count++;
                }

                // checks tile to the right
                if(tileType.at(i + 1) == 3)
                {
                    count++;
                }
            }

            // check bottom right corner of board
            else if(i == (numCol * numRow) - 1)
            {
                // checks tile above
                if(tileType.at(i - numCol) == 3)
                {
                    count++;
                }

                // checks tile top left
                if(tileType.at(i - numCol - 1) == 3)
                {
                    count++;
                }

                // checks tile to the left
                if(tileType.at(i - 1) == 3)
                {
                    count++;
                }
            }

            // check if tile is in top row of board
            else if(i > 0 && i < numCol - 1)
            {
                // checks tile to the left
                if(tileType.at(i - 1) == 3)
                {
                    count++;
                }

                // checks tile bottom left
                if(tileType.at(i + numCol - 1) == 3)
                {
                    count++;
                }

                // checks tile below
                if(tileType.at(i + numCol) == 3)
                {
                    count++;
                }

                // checks tile bottom right
                if(tileType.at(i + numCol + 1) == 3)
                {
                    count++;
                }

                // checks tile to the right
                if(tileType.at(i + 1) == 3)
                {
                    count++;
                }
            }

            // check if tile is in bottom row of board
            else if(i > (numCol * numRow) - numCol && i < (numCol * numRow) - 1)
            {
                // checks tile to the left
                if(tileType.at(i - 1) == 3)
                {
                    count++;
                }

                // checks tile top left
                if(tileType.at(i - numCol - 1) == 3)
                {
                    count++;
                }

                // checks tile above
                if(tileType.at(i - numCol) == 3)
                {
                    count++;
                }

                // checks tile top right
                if(tileType.at(i - numCol + 1) == 3)
                {
                    count++;
                }

                // checks tile to the right
                if(tileType.at(i + 1) == 3)
                {
                    count++;
                }
            }

            // check if tile is in left column of board
            else if(i % numCol == 0)
            {
                // checks tile above
                if(tileType.at(i - numCol) == 3)
                {
                    count++;
                }

                // checks tile top right
                if(tileType.at(i - numCol + 1) == 3)
                {
                    count++;
                }

                // checks tile to the right
                if(tileType.at(i + 1) == 3)
                {
                    count++;
                }

                // checks tile bottom right
                if(tileType.at(i + numCol + 1) == 3)
                {
                    count++;
                }

                // checks tile below
                if(tileType.at(i + numCol) == 3)
                {
                    count++;
                }
            }

            // check if tile is in right column of board
            else if(i % numCol - numCol + 1 == 0)
            {
                // checks tile above
                if(tileType.at(i - numCol) == 3)
                {
                    count++;
                }

                // checks tile top left
                if(tileType.at(i - numCol - 1) == 3)
                {
                    count++;
                }

                // checks tile to the left
                if(tileType.at(i - 1) == 3)
                {
                    count++;
                }

                // checks tile bottom left
                if(tileType.at(i + numCol - 1) == 3)
                {
                    count++;
                }

                // checks tile below
                if(tileType.at(i + numCol) == 3)
                {
                    count++;
                }
            }

            // if not a corner and not a side, then check all sides
            else
            {
                // checks tile to the right
                if(tileType.at(i + 1) == 3)
                {
                    count++;
                }

                // checks tile to the left
                if(tileType.at(i - 1) == 3)
                {
                    count++;
                }

                // checks tile above
                if(tileType.at(i - numCol) == 3)
                {
                    count++;
                }

                // checks tile below
                if(tileType.at(i + numCol) == 3)
                {
                    count++;
                }

                // checks tile top left
                if(tileType.at(i - numCol - 1) == 3)
                {
                    count++;
                }

                // checks tile top right
                if(tileType.at(i - numCol + 1) == 3)
                {
                    count++;
                }

                // checks tile bottom left
                if(tileType.at(i + numCol - 1) == 3)
                {
                    count++;
                }

                // checks tile bottom right
                if(tileType.at(i + numCol + 1) == 3)
                {
                    count++;
                }
            }
        }

        numbers.push_back(count);
    }

    // makes debugVector and inserts "mine" textures where there are mines
    bool showMines = false;
    vector<Sprite> debugVector;
    for(int i = 0; i < numCol * numRow; i++)
    {
        Sprite newTile;

        if(tileType.at(i) == 3)
        {
            newTile.setTexture(TextureManager::GetTexture("mine"));
        }

        debugVector.push_back(newTile);
    }

    while(window.isOpen())
    {
        // DO NOT TOUCH
        Event event;

        while(window.pollEvent(event))
        {
            if(event.type == Event::Closed)
            {
                window.close();
            }

            // add or remove flags with right-click
            if(Mouse::isButtonPressed(Mouse::Right) && tileType.at(1) != 6)
            {
                int xPosition = 0;
                int yPosition = 0;
                int tileIndex = 0;

                xPosition = event.mouseButton.x / 32;
                yPosition = event.mouseButton.y / 32;

                tileIndex = (yPosition * numCol) + xPosition;

                if(yPosition >= numRow)
                {
                    // please don't crash
                }

                else if(tileType.at(tileIndex) == 0)
                {
                    flagVector.at(tileIndex).setTexture(TextureManager::GetTexture("flag"));
                    tileType.at(tileIndex) = 1;
                    digits--;
                }

                else if(tileType.at(tileIndex) == 1)
                {
                    flagVector.at(tileIndex).setTexture(TextureManager::GetTexture("blankTiles"));
                    tileType.at(tileIndex) = 0;
                    digits++;
                }

                else if(tileType.at(tileIndex) == 3)
                {
                    flagVector.at(tileIndex).setTexture(TextureManager::GetTexture("flag"));
                    tileType.at(tileIndex) = 5;
                    digits--;
                }

                else if(tileType.at(tileIndex) == 5)
                {
                    flagVector.at(tileIndex).setTexture(TextureManager::GetTexture("blankTiles"));
                    tileType.at(tileIndex) = 3;
                    digits++;
                }

                // debug tool
                cout << "Right Mouse Click: " << xPosition << ", " << yPosition << endl;
            }

            // left-click to reveal tiles and show either the mine, number, or empty tile underneath
            if(Mouse::isButtonPressed(Mouse::Left))
            {
                int xPosition = 0;
                int yPosition = 0;
                int tileIndex = 0;

                xPosition = event.mouseButton.x / 32;
                yPosition = event.mouseButton.y / 32;

                tileIndex = (yPosition * numCol) + xPosition;

                // program won't crash when button is clicked outside of board
                if(yPosition >= numRow)
                {
                    // debug buttons
                    if(xPosition >= numCol - 8 && xPosition <= numCol - 7 && yPosition < numRow + 2 && tileType.at(0) != 6)
                    {
                        // debug tool
                        cout << "Debug Button Toggled!" << endl;

                        // toggle on and off debug button
                        if(showMines == false)
                        {
                            showMines = true;
                        }

                        else if(showMines == true)
                        {
                            showMines = false;
                        }
                    }
                }

                // test button #1 is clicked
                if(yPosition >= numRow)
                {
                    if(xPosition >= numCol - 6 && xPosition <= numCol - 5 && yPosition < numRow + 2)
                    {
                        showMines = false;

                        // sets faceHappySprite texture back to face_happy
                        faceHappySprite.setTexture(TextureManager::GetTexture("face_happy"));

                        numMines = 0;
                        digits = 0;

                        ifstream currentFile;
                        ifstream testboard1;

                        ifstream inFile("boards/testboard1.brd");

                        string lineFromFile;
                        getline(inFile, lineFromFile);
                        string test1 = lineFromFile;

                        while(getline(inFile, lineFromFile))
                        {
                            test1 += lineFromFile;
                        }

                        cout << test1 << endl;

                        // resets tileType
                        for(int i = 0; i < numCol * numRow; i++)
                        {
                            tileType.at(i) = 0;
                        }

                        for(int i = 0; i < test1.length(); i++)
                        {
                            if(test1[i] - '0' == 0)
                            {
                                tileType.at(i) = 0;
                            }

                            else if(test1[i] - '0' == 1)
                            {
                                tileType.at(i) = 3;
                                numMines++;
                                digits++;
                            }
                        }

                        original = numMines;

                        // resets tileHiddenVector
                        for(int i = 0; i < numCol * numRow; i++)
                        {
                            tileHiddenVector.at(i).setTexture(TextureManager::GetTexture("tile_hidden"));
                        }

                        // resets flagVector
                        for(int i = 0; i < numCol * numRow; i++)
                        {
                            flagVector.at(i).setTexture(TextureManager::GetTexture("blankTiles"));
                        }

                        //resets debugVector
                        for(int i = 0; i < numCol * numRow; i++)
                        {
                            if (tileType.at(i) == 3)
                            {
                                debugVector.at(i).setTexture(TextureManager::GetTexture("mine"));
                            }
                            else
                            {
                                debugVector.at(i).setTexture(TextureManager::GetTexture("blankTiles"));
                            }
                        }

                        // reset numbers
                        for(int i = 0; i < numCol * numRow; i++)
                        {
                            numbers.at(i) = 0;

                            // if the tile is not a bomb
                            int count = 0;
                            if(tileType.at(i) != 3)
                            {
                                // checks top left corner of board
                                if(i == 0)
                                {
                                    if(tileType.at(i + 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile bottom right
                                    if(tileType.at(i + numCol + 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile below
                                    if(tileType.at(i + numCol) == 3)
                                    {
                                        count++;
                                    }
                                }

                                // checks top right corner of board
                                else if(i == numCol - 1)
                                {
                                    // checks tile to the left
                                    if(tileType.at(i - 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile bottom left
                                    if(tileType.at(i + numCol - 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile below
                                    if(tileType.at(i + numCol) == 3)
                                    {
                                        count++;
                                    }
                                }

                                // checks bottom left corner of board
                                else if(i == (numRow * numCol) - numCol)
                                {
                                    // checks tile above
                                    if(tileType.at(i - numCol) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile top right
                                    if(tileType.at(i - numCol + 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile to the right
                                    if(tileType.at(i + 1) == 3)
                                    {
                                        count++;
                                    }
                                }

                                // check bottom right corner of board
                                else if(i == (numCol * numRow) - 1)
                                {
                                    // checks tile above
                                    if(tileType.at(i - numCol) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile top left
                                    if(tileType.at(i - numCol - 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile to the left
                                    if(tileType.at(i - 1) == 3)
                                    {
                                        count++;
                                    }
                                }

                                // check if tile is in top row of board
                                else if(i > 0 && i < numCol - 1)
                                {
                                    // checks tile to the left
                                    if(tileType.at(i - 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile bottom left
                                    if(tileType.at(i + numCol - 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile below
                                    if(tileType.at(i + numCol) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile bottom right
                                    if(tileType.at(i + numCol + 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile to the right
                                    if(tileType.at(i + 1) == 3)
                                    {
                                        count++;
                                    }
                                }

                                // check if tile is in bottom row of board
                                else if(i > (numCol * numRow) - numCol && i < (numCol * numRow) - 1)
                                {
                                    // checks tile to the left
                                    if(tileType.at(i - 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile top left
                                    if(tileType.at(i - numCol - 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile above
                                    if(tileType.at(i - numCol) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile top right
                                    if(tileType.at(i - numCol + 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile to the right
                                    if(tileType.at(i + 1) == 3)
                                    {
                                        count++;
                                    }
                                }

                                // check if tile is in left column of board
                                else if(i % numCol == 0)
                                {
                                    // checks tile above
                                    if(tileType.at(i - numCol) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile top right
                                    if(tileType.at(i - numCol + 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile to the right
                                    if(tileType.at(i + 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile bottom right
                                    if(tileType.at(i + numCol + 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile below
                                    if(tileType.at(i + numCol) == 3)
                                    {
                                        count++;
                                    }
                                }

                                // check if tile is in right column of board
                                else if(i % numCol - numCol + 1 == 0)
                                {
                                    // checks tile above
                                    if(tileType.at(i - numCol) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile top left
                                    if(tileType.at(i - numCol - 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile to the left
                                    if(tileType.at(i - 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile bottom left
                                    if(tileType.at(i + numCol - 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile below
                                    if(tileType.at(i + numCol) == 3)
                                    {
                                        count++;
                                    }
                                }

                                // if not a corner and not a side, then check all sides
                                else
                                {
                                    // checks tile to the right
                                    if(tileType.at(i + 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile to the left
                                    if(tileType.at(i - 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile above
                                    if(tileType.at(i - numCol) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile below
                                    if(tileType.at(i + numCol) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile top left
                                    if(tileType.at(i - numCol - 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile top right
                                    if(tileType.at(i - numCol + 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile bottom left
                                    if(tileType.at(i + numCol - 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile bottom right
                                    if(tileType.at(i + numCol + 1) == 3)
                                    {
                                        count++;
                                    }
                                }
                            }

                            numbers.at(i) = count;
                        }
                    }
                }

                // test button #2 is clicked
                if(yPosition >= numRow)
                {
                    if(xPosition >= numCol - 4 && xPosition <= numCol - 3 && yPosition < numRow + 2)
                    {
                        showMines = false;

                        // sets faceHappySprite texture back to face_happy
                        faceHappySprite.setTexture(TextureManager::GetTexture("face_happy"));

                        numMines = 0;
                        digits = 0;

                        ifstream currentFile;
                        ifstream testboard2;

                        ifstream inFile("boards/testboard2.brd");

                        string lineFromFile;
                        getline(inFile, lineFromFile);
                        string test2 = lineFromFile;

                        while(getline(inFile, lineFromFile))
                        {
                            test2 += lineFromFile;
                        }

                        cout << test2 << endl;

                        // resets tileType
                        for(int i = 0; i < numCol * numRow; i++)
                        {
                            tileType.at(i) = 0;
                        }

                        for(int i = 0; i < test2.length(); i++)
                        {
                            if(test2[i] - '0' == 0)
                            {
                                tileType.at(i) = 0;
                            }

                            else if(test2[i] - '0' == 1)
                            {
                                tileType.at(i) = 3;
                                numMines++;
                                digits++;
                            }
                        }

                        original = numMines;

                        // resets tileHiddenVector
                        for(int i = 0; i < numCol * numRow; i++)
                        {
                            tileHiddenVector.at(i).setTexture(TextureManager::GetTexture("tile_hidden"));
                        }

                        // resets flagVector
                        for(int i = 0; i < numCol * numRow; i++)
                        {
                            flagVector.at(i).setTexture(TextureManager::GetTexture("blankTiles"));
                        }

                        //resets debugVector
                        for(int i = 0; i < numCol * numRow; i++)
                        {
                            if (tileType.at(i) == 3)
                            {
                                debugVector.at(i).setTexture(TextureManager::GetTexture("mine"));
                            }
                            else
                            {
                                debugVector.at(i).setTexture(TextureManager::GetTexture("blankTiles"));
                            }
                        }

                        // reset numbers
                        for(int i = 0; i < numCol * numRow; i++)
                        {
                            numbers.at(i) = 0;

                            // if the tile is not a bomb
                            int count = 0;
                            if(tileType.at(i) != 3)
                            {
                                // checks top left corner of board
                                if(i == 0)
                                {
                                    if(tileType.at(i + 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile bottom right
                                    if(tileType.at(i + numCol + 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile below
                                    if(tileType.at(i + numCol) == 3)
                                    {
                                        count++;
                                    }
                                }

                                    // checks top right corner of board
                                else if(i == numCol - 1)
                                {
                                    // checks tile to the left
                                    if(tileType.at(i - 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile bottom left
                                    if(tileType.at(i + numCol - 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile below
                                    if(tileType.at(i + numCol) == 3)
                                    {
                                        count++;
                                    }
                                }

                                    // checks bottom left corner of board
                                else if(i == (numRow * numCol) - numCol)
                                {
                                    // checks tile above
                                    if(tileType.at(i - numCol) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile top right
                                    if(tileType.at(i - numCol + 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile to the right
                                    if(tileType.at(i + 1) == 3)
                                    {
                                        count++;
                                    }
                                }

                                    // check bottom right corner of board
                                else if(i == (numCol * numRow) - 1)
                                {
                                    // checks tile above
                                    if(tileType.at(i - numCol) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile top left
                                    if(tileType.at(i - numCol - 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile to the left
                                    if(tileType.at(i - 1) == 3)
                                    {
                                        count++;
                                    }
                                }

                                    // check if tile is in top row of board
                                else if(i > 0 && i < numCol - 1)
                                {
                                    // checks tile to the left
                                    if(tileType.at(i - 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile bottom left
                                    if(tileType.at(i + numCol - 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile below
                                    if(tileType.at(i + numCol) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile bottom right
                                    if(tileType.at(i + numCol + 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile to the right
                                    if(tileType.at(i + 1) == 3)
                                    {
                                        count++;
                                    }
                                }

                                    // check if tile is in bottom row of board
                                else if(i > (numCol * numRow) - numCol && i < (numCol * numRow) - 1)
                                {
                                    // checks tile to the left
                                    if(tileType.at(i - 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile top left
                                    if(tileType.at(i - numCol - 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile above
                                    if(tileType.at(i - numCol) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile top right
                                    if(tileType.at(i - numCol + 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile to the right
                                    if(tileType.at(i + 1) == 3)
                                    {
                                        count++;
                                    }
                                }

                                    // check if tile is in left column of board
                                else if(i % numCol == 0)
                                {
                                    // checks tile above
                                    if(tileType.at(i - numCol) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile top right
                                    if(tileType.at(i - numCol + 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile to the right
                                    if(tileType.at(i + 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile bottom right
                                    if(tileType.at(i + numCol + 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile below
                                    if(tileType.at(i + numCol) == 3)
                                    {
                                        count++;
                                    }
                                }

                                    // check if tile is in right column of board
                                else if(i % numCol - numCol + 1 == 0)
                                {
                                    // checks tile above
                                    if(tileType.at(i - numCol) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile top left
                                    if(tileType.at(i - numCol - 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile to the left
                                    if(tileType.at(i - 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile bottom left
                                    if(tileType.at(i + numCol - 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile below
                                    if(tileType.at(i + numCol) == 3)
                                    {
                                        count++;
                                    }
                                }

                                    // if not a corner and not a side, then check all sides
                                else
                                {
                                    // checks tile to the right
                                    if(tileType.at(i + 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile to the left
                                    if(tileType.at(i - 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile above
                                    if(tileType.at(i - numCol) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile below
                                    if(tileType.at(i + numCol) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile top left
                                    if(tileType.at(i - numCol - 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile top right
                                    if(tileType.at(i - numCol + 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile bottom left
                                    if(tileType.at(i + numCol - 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile bottom right
                                    if(tileType.at(i + numCol + 1) == 3)
                                    {
                                        count++;
                                    }
                                }
                            }

                            numbers.at(i) = count;
                        }
                    }
                }

                // test button #3 is clicked
                if(yPosition >= numRow)
                {
                    if(xPosition >= numCol - 2 && xPosition <= numCol - 1 && yPosition < numRow + 2)
                    {
                        showMines = false;

                        // sets faceHappySprite texture back to face_happy
                        faceHappySprite.setTexture(TextureManager::GetTexture("face_happy"));

                        numMines = 0;
                        digits = 0;

                        ifstream currentFile;
                        ifstream testboard3;

                        ifstream inFile("boards/testboard3.brd");

                        string lineFromFile;
                        getline(inFile, lineFromFile);
                        string test3 = lineFromFile;

                        while(getline(inFile, lineFromFile))
                        {
                            test3 += lineFromFile;
                        }

                        cout << test3 << endl;

                        // resets tileType
                        for(int i = 0; i < numCol * numRow; i++)
                        {
                            tileType.at(i) = 0;
                        }

                        for(int i = 0; i < test3.length(); i++)
                        {
                            if(test3[i] - '0' == 0)
                            {
                                tileType.at(i) = 0;
                            }

                            else if(test3[i] - '0' == 1)
                            {
                                tileType.at(i) = 3;
                                numMines++;
                                digits++;
                            }
                        }

                        original = numMines;

                        // resets tileHiddenVector
                        for(int i = 0; i < numCol * numRow; i++)
                        {
                            tileHiddenVector.at(i).setTexture(TextureManager::GetTexture("tile_hidden"));
                        }

                        // resets flagVector
                        for(int i = 0; i < numCol * numRow; i++)
                        {
                            flagVector.at(i).setTexture(TextureManager::GetTexture("blankTiles"));
                        }

                        //resets debugVector
                        for(int i = 0; i < numCol * numRow; i++)
                        {
                            if (tileType.at(i) == 3) {
                                debugVector.at(i).setTexture(TextureManager::GetTexture("mine"));
                            }
                            else {
                                debugVector.at(i).setTexture(TextureManager::GetTexture("blankTiles"));
                            }
                        }

                        // reset numbers
                        for(int i = 0; i < numCol * numRow; i++)
                        {
                            numbers.at(i) = 0;

                            // if the tile is not a bomb
                            int count = 0;
                            if(tileType.at(i) != 3)
                            {
                                // checks top left corner of board
                                if(i == 0)
                                {
                                    if(tileType.at(i + 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile bottom right
                                    if(tileType.at(i + numCol + 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile below
                                    if(tileType.at(i + numCol) == 3)
                                    {
                                        count++;
                                    }
                                }

                                // checks top right corner of board
                                else if(i == numCol - 1)
                                {
                                    // checks tile to the left
                                    if(tileType.at(i - 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile bottom left
                                    if(tileType.at(i + numCol - 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile below
                                    if(tileType.at(i + numCol) == 3)
                                    {
                                        count++;
                                    }
                                }

                                // checks bottom left corner of board
                                else if(i == (numRow * numCol) - numCol)
                                {
                                    // checks tile above
                                    if(tileType.at(i - numCol) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile top right
                                    if(tileType.at(i - numCol + 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile to the right
                                    if(tileType.at(i + 1) == 3)
                                    {
                                        count++;
                                    }
                                }

                                    // check bottom right corner of board
                                else if(i == (numCol * numRow) - 1)
                                {
                                    // checks tile above
                                    if(tileType.at(i - numCol) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile top left
                                    if(tileType.at(i - numCol - 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile to the left
                                    if(tileType.at(i - 1) == 3)
                                    {
                                        count++;
                                    }
                                }

                                // check if tile is in top row of board
                                else if(i > 0 && i < numCol - 1)
                                {
                                    // checks tile to the left
                                    if(tileType.at(i - 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile bottom left
                                    if(tileType.at(i + numCol - 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile below
                                    if(tileType.at(i + numCol) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile bottom right
                                    if(tileType.at(i + numCol + 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile to the right
                                    if(tileType.at(i + 1) == 3)
                                    {
                                        count++;
                                    }
                                }

                                // check if tile is in bottom row of board
                                else if(i > (numCol * numRow) - numCol && i < (numCol * numRow) - 1)
                                {
                                    // checks tile to the left
                                    if(tileType.at(i - 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile top left
                                    if(tileType.at(i - numCol - 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile above
                                    if(tileType.at(i - numCol) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile top right
                                    if(tileType.at(i - numCol + 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile to the right
                                    if(tileType.at(i + 1) == 3)
                                    {
                                        count++;
                                    }
                                }

                                // check if tile is in left column of board
                                else if(i % numCol == 0)
                                {
                                    // checks tile above
                                    if(tileType.at(i - numCol) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile top right
                                    if(tileType.at(i - numCol + 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile to the right
                                    if(tileType.at(i + 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile bottom right
                                    if(tileType.at(i + numCol + 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile below
                                    if(tileType.at(i + numCol) == 3)
                                    {
                                        count++;
                                    }
                                }

                                // check if tile is in right column of board
                                else if(i % numCol - numCol + 1 == 0)
                                {
                                    // checks tile above
                                    if(tileType.at(i - numCol) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile top left
                                    if(tileType.at(i - numCol - 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile to the left
                                    if(tileType.at(i - 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile bottom left
                                    if(tileType.at(i + numCol - 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile below
                                    if(tileType.at(i + numCol) == 3)
                                    {
                                        count++;
                                    }
                                }

                                // if not a corner and not a side, then check all sides
                                else
                                {
                                    // checks tile to the right
                                    if(tileType.at(i + 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile to the left
                                    if(tileType.at(i - 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile above
                                    if(tileType.at(i - numCol) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile below
                                    if(tileType.at(i + numCol) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile top left
                                    if(tileType.at(i - numCol - 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile top right
                                    if(tileType.at(i - numCol + 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile bottom left
                                    if(tileType.at(i + numCol - 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile bottom right
                                    if(tileType.at(i + numCol + 1) == 3)
                                    {
                                        count++;
                                    }
                                }
                            }

                            numbers.at(i) = count;
                        }
                    }
                }

                // face happy is clicked, board is reset
                if(yPosition >= numRow)
                {
                    if(xPosition >= (numCol / 2) - 1 && xPosition <= (numCol / 2) + 1 && yPosition < numRow + 2)
                    {
                        showMines = false;

                        // sets faceHappySprite texture back to face_happy
                        faceHappySprite.setTexture(TextureManager::GetTexture("face_happy"));

                        // sets digits back to reset
                        digits = reset;

                        // resets tileType
                        for(int i = 0; i < numCol * numRow; i++)
                        {
                            tileType.at(i) = 0;
                        }

                        // random number generator to randomly place mines on board
                        totalTiles = numCol * numRow;
                        numMines = reset;
                        original = numMines;
                        for(int i = 0; i < numCol * numRow; i++)
                        {
                            int random = Random::Int(0, totalTiles);

                            if(random <= numMines && numMines != 0)
                            {
                                tileType.at(i) = 3;
                                numMines--;
                            }

                            totalTiles--;
                        }
                        numMines = reset;

                        // place numbers 1-8 on the board next to the mines
                        for(int i = 0; i < tileType.size(); i++)
                        {
                            int count = 0;

                            // if the tile is not a bomb
                            if(tileType.at(i) != 3)
                            {
                                // checks top left corner of board
                                if(i == 0)
                                {
                                    if(tileType.at(i + 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile bottom right
                                    if(tileType.at(i + numCol + 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile below
                                    if(tileType.at(i + numCol) == 3)
                                    {
                                        count++;
                                    }
                                }

                                // checks top right corner of board
                                else if(i == numCol - 1)
                                {
                                    // checks tile to the left
                                    if(tileType.at(i - 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile bottom left
                                    if(tileType.at(i + numCol - 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile below
                                    if(tileType.at(i + numCol) == 3)
                                    {
                                        count++;
                                    }
                                }

                                // checks bottom left corner of board
                                else if(i == (numRow * numCol) - numCol)
                                {
                                    // checks tile above
                                    if(tileType.at(i - numCol) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile top right
                                    if(tileType.at(i - numCol + 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile to the right
                                    if(tileType.at(i + 1) == 3)
                                    {
                                        count++;
                                    }
                                }

                                // check bottom right corner of board
                                else if(i == (numCol * numRow) - 1)
                                {
                                    // checks tile above
                                    if(tileType.at(i - numCol) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile top left
                                    if(tileType.at(i - numCol - 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile to the left
                                    if(tileType.at(i - 1) == 3)
                                    {
                                        count++;
                                    }
                                }

                                // check if tile is in top row of board
                                else if(i > 0 && i < numCol - 1)
                                {
                                    // checks tile to the left
                                    if(tileType.at(i - 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile bottom left
                                    if(tileType.at(i + numCol - 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile below
                                    if(tileType.at(i + numCol) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile bottom right
                                    if(tileType.at(i + numCol + 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile to the right
                                    if(tileType.at(i + 1) == 3)
                                    {
                                        count++;
                                    }
                                }

                                // check if tile is in bottom row of board
                                else if(i > (numCol * numRow) - numCol && i < (numCol * numRow) - 1)
                                {
                                    // checks tile to the left
                                    if(tileType.at(i - 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile top left
                                    if(tileType.at(i - numCol - 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile above
                                    if(tileType.at(i - numCol) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile top right
                                    if(tileType.at(i - numCol + 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile to the right
                                    if(tileType.at(i + 1) == 3)
                                    {
                                        count++;
                                    }
                                }

                                // check if tile is in left column of board
                                else if(i % numCol == 0)
                                {
                                    // checks tile above
                                    if(tileType.at(i - numCol) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile top right
                                    if(tileType.at(i - numCol + 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile to the right
                                    if(tileType.at(i + 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile bottom right
                                    if(tileType.at(i + numCol + 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile below
                                    if(tileType.at(i + numCol) == 3)
                                    {
                                        count++;
                                    }
                                }

                                // check if tile is in right column of board
                                else if(i % numCol - numCol + 1 == 0)
                                {
                                    // checks tile above
                                    if(tileType.at(i - numCol) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile top left
                                    if(tileType.at(i - numCol - 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile to the left
                                    if(tileType.at(i - 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile bottom left
                                    if(tileType.at(i + numCol - 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile below
                                    if(tileType.at(i + numCol) == 3)
                                    {
                                        count++;
                                    }
                                }

                                // if not a corner and not a side, then check all sides
                                else
                                {
                                    // checks tile to the right
                                    if(tileType.at(i + 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile to the left
                                    if(tileType.at(i - 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile above
                                    if(tileType.at(i - numCol) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile below
                                    if(tileType.at(i + numCol) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile top left
                                    if(tileType.at(i - numCol - 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile top right
                                    if(tileType.at(i - numCol + 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile bottom left
                                    if(tileType.at(i + numCol - 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile bottom right
                                    if(tileType.at(i + numCol + 1) == 3)
                                    {
                                        count++;
                                    }
                                }
                            }

                            numbers.push_back(count);
                        }

                        // resets tileHiddenVector
                        for(int i = 0; i < numCol * numRow; i++)
                        {
                            tileHiddenVector.at(i).setTexture(TextureManager::GetTexture("tile_hidden"));
                        }

                        // resets flagVector
                        for(int i = 0; i < numCol * numRow; i++)
                        {
                            flagVector.at(i).setTexture(TextureManager::GetTexture("blankTiles"));
                        }

                        //resets debugVector
                        showMines = false;
                        for(int i = 0; i < numCol * numRow; i++)
                        {
                            if(tileType.at(i) == 3)
                            {
                                debugVector.at(i).setTexture(TextureManager::GetTexture("mine"));
                            }
                            else
                            {
                                debugVector.at(i).setTexture(TextureManager::GetTexture("blankTiles"));
                            }
                        }

                        // reset numbers
                        for(int i = 0; i < numCol * numRow; i++)
                        {
                            numbers.at(i) = 0;

                            // if the tile is not a bomb
                            int count = 0;
                            if(tileType.at(i) != 3)
                            {
                                // checks top left corner of board
                                if(i == 0)
                                {
                                    if(tileType.at(i + 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile bottom right
                                    if(tileType.at(i + numCol + 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile below
                                    if(tileType.at(i + numCol) == 3)
                                    {
                                        count++;
                                    }
                                }

                                // checks top right corner of board
                                else if(i == numCol - 1)
                                {
                                    // checks tile to the left
                                    if(tileType.at(i - 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile bottom left
                                    if(tileType.at(i + numCol - 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile below
                                    if(tileType.at(i + numCol) == 3)
                                    {
                                        count++;
                                    }
                                }

                                // checks bottom left corner of board
                                else if(i == (numRow * numCol) - numCol)
                                {
                                    // checks tile above
                                    if(tileType.at(i - numCol) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile top right
                                    if(tileType.at(i - numCol + 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile to the right
                                    if(tileType.at(i + 1) == 3)
                                    {
                                        count++;
                                    }
                                }

                                // check bottom right corner of board
                                else if(i == (numCol * numRow) - 1)
                                {
                                    // checks tile above
                                    if(tileType.at(i - numCol) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile top left
                                    if(tileType.at(i - numCol - 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile to the left
                                    if(tileType.at(i - 1) == 3)
                                    {
                                        count++;
                                    }
                                }

                                // check if tile is in top row of board
                                else if(i > 0 && i < numCol - 1)
                                {
                                    // checks tile to the left
                                    if(tileType.at(i - 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile bottom left
                                    if(tileType.at(i + numCol - 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile below
                                    if(tileType.at(i + numCol) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile bottom right
                                    if(tileType.at(i + numCol + 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile to the right
                                    if(tileType.at(i + 1) == 3)
                                    {
                                        count++;
                                    }
                                }

                                // check if tile is in bottom row of board
                                else if(i > (numCol * numRow) - numCol && i < (numCol * numRow) - 1)
                                {
                                    // checks tile to the left
                                    if(tileType.at(i - 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile top left
                                    if(tileType.at(i - numCol - 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile above
                                    if(tileType.at(i - numCol) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile top right
                                    if(tileType.at(i - numCol + 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile to the right
                                    if(tileType.at(i + 1) == 3)
                                    {
                                        count++;
                                    }
                                }

                                // check if tile is in left column of board
                                else if(i % numCol == 0)
                                {
                                    // checks tile above
                                    if(tileType.at(i - numCol) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile top right
                                    if(tileType.at(i - numCol + 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile to the right
                                    if(tileType.at(i + 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile bottom right
                                    if(tileType.at(i + numCol + 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile below
                                    if(tileType.at(i + numCol) == 3)
                                    {
                                        count++;
                                    }
                                }

                                // check if tile is in right column of board
                                else if(i % numCol - numCol + 1 == 0)
                                {
                                    // checks tile above
                                    if(tileType.at(i - numCol) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile top left
                                    if(tileType.at(i - numCol - 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile to the left
                                    if(tileType.at(i - 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile bottom left
                                    if(tileType.at(i + numCol - 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile below
                                    if(tileType.at(i + numCol) == 3)
                                    {
                                        count++;
                                    }
                                }

                                // if not a corner and not a side, then check all sides
                                else
                                {
                                    // checks tile to the right
                                    if(tileType.at(i + 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile to the left
                                    if(tileType.at(i - 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile above
                                    if(tileType.at(i - numCol) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile below
                                    if(tileType.at(i + numCol) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile top left
                                    if(tileType.at(i - numCol - 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile top right
                                    if(tileType.at(i - numCol + 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile bottom left
                                    if(tileType.at(i + numCol - 1) == 3)
                                    {
                                        count++;
                                    }

                                    // checks tile bottom right
                                    if(tileType.at(i + numCol + 1) == 3)
                                    {
                                        count++;
                                    }
                                }
                            }

                            numbers.at(i) = count;
                        }
                    }
                }

                else if(tileType.at(tileIndex) == 0)
                {
                    // recursive function
                    revealTiles(tileHiddenVector, tileType, numbers, flagVector, tileIndex, numCol, numRow);
                }



                // all tiles with mines are revealed (display on top of any flags you may have placed)
                else if(tileType.at(tileIndex) == 3)
                {
                    showMines = true;
                    faceHappySprite.setTexture(TextureManager::GetTexture("face_lose"));
                    for(int i = 0; i < tileType.size(); i++)
                    {
                        if(tileType.at(i) == 3)
                        {
                            tileHiddenVector.at(i).setTexture(TextureManager::GetTexture("tile_revealed"));
                        }
                    }

                    for(int i = 0; i < tileType.size(); i++)
                    {
                        tileType.at(i) = 6;
                    }
                }

                revealWin = 0;
                for(int i = 0; i < tileType.size(); i++)
                {
                    if(tileType.at(i) == 2)
                    {
                        revealWin++;
                    }
                }

                // debug tool
                cout << "Left Mouse Click: " << xPosition << ", " << yPosition << endl;
            }
        }

        if(revealWin == ((numCol * numRow) - numMines))
        {
            faceHappySprite.setTexture(TextureManager::GetTexture("face_win"));
            showMines = false;

            for(int i = 0; i < tileType.size(); i++)
            {
                if(tileType.at(i) == 3)
                {
                    flagVector.at(i).setTexture(TextureManager::GetTexture("flag"));
                }
            }

            for(int i = 0; i < tileType.size(); i++)
            {
                tileType.at(i) = 6;
            }
        }

        window.clear();

        // print out board of hidden tiles
        Vector2f setPos(0.f, 0.f);
        window.draw(tileHiddenVector.at(0));
        for(int i = 1; i < tileHiddenVector.size(); i++)
        {
            if(tileType.at(0) != 6)
            {

            }
            if(i % numCol == 0)
            {
                setPos.x = 0;
                setPos.y += 32.f;
            }
            else
            {
                setPos.x += 32.f;
            }

            tileHiddenVector.at(i).setPosition(setPos);
            window.draw(tileHiddenVector.at(i));
        }

        // print out board of blank tiles for flags
        Vector2f setPosition(0.f, 0.f);
        window.draw(flagVector.at(0));
        for(int i = 1; i < flagVector.size(); i++)
        {
            if(i % numCol == 0)
            {
                setPosition.x = 0;
                setPosition.y += 32.f;
            }
            else
            {
                setPosition.x += 32.f;
            }

            flagVector.at(i).setPosition(setPosition);
            window.draw(flagVector.at(i));
        }

        // if debug button is toggled off, show the mines on the map
        if(showMines == true)
        {
            setPosition = Vector2f(0.f, 0.f);
            window.draw(debugVector.at(0));
            for(int i = 1; i < debugVector.size(); i++)
            {
                if(i % numCol == 0)
                {
                    setPosition.x = 0;
                    setPosition.y += 32.f;
                }
                else
                {
                    setPosition.x += 32.f;
                }

                debugVector.at(i).setPosition(setPosition);
                window.draw(debugVector.at(i));
            }
        }

        // prints out faceHappySprite
        faceHappySprite.setPosition((numCol - 2.0) / 2.0 * 32.0, numRow * 32.0);
        window.draw(faceHappySprite);

        // prints out debugSprite
        debugSprite.setPosition((numCol - 8.0) * 32.0, numRow * 32.0);
        window.draw(debugSprite);

        // prints out test1Sprite
        test1Sprite.setPosition((numCol - 6.0) * 32.0, numRow * 32.0);
        window.draw(test1Sprite);

        // prints out test2Sprite
        test2Sprite.setPosition((numCol - 4.0) * 32.0, numRow * 32.0);
        window.draw(test2Sprite);

        // prints out test3Sprite
        test3Sprite.setPosition((numCol - 2.0) * 32.0, numRow * 32.0);
        window.draw(test3Sprite);

        // figures out what the negativePlace is
        int tempNegativePlace = 0;
        tempNegativePlace = digits;
        if(tempNegativePlace < 0)
        {
            negativePlaceSprite.setTexture(TextureManager::GetTexture("digits"));
        }

        else
        {
            negativePlaceSprite.setTexture(TextureManager::GetTexture("blankTiles"));
        }

        // figures out what the onesPlace is
        int tempOnes = 0;
        tempOnes = digits;
        int onesPlace = tempOnes % 10;
        if(onesPlace == 0)
        {
            onesPlaceSprite.setTextureRect(IntRect(0, 0, 21, 32));
        }

        else if(onesPlace == 1 || onesPlace == -1)
        {
            onesPlaceSprite.setTextureRect(IntRect(21, 0, 21, 32));
        }

        else if(onesPlace == 2 || onesPlace == -2)
        {
            onesPlaceSprite.setTextureRect(IntRect(42, 0, 21, 32));
        }

        else if(onesPlace == 3 || onesPlace == -3)
        {
            onesPlaceSprite.setTextureRect(IntRect(63, 0, 21, 32));
        }

        else if(onesPlace == 4 || onesPlace == -4)
        {
            onesPlaceSprite.setTextureRect(IntRect(84, 0, 21, 32));
        }

        else if(onesPlace == 5 || onesPlace == -5)
        {
            onesPlaceSprite.setTextureRect(IntRect(105, 0, 21, 32));
        }

        else if(onesPlace == 6 || onesPlace == -6)
        {
            onesPlaceSprite.setTextureRect(IntRect(126, 0, 21, 32));
        }

        else if(onesPlace == 7 || onesPlace == -7)
        {
            onesPlaceSprite.setTextureRect(IntRect(147, 0, 21, 32));
        }

        else if(onesPlace == 8 || onesPlace == -8)
        {
            onesPlaceSprite.setTextureRect(IntRect(168, 0, 21, 32));
        }

        else if(onesPlace == 9 || onesPlace == -9)
        {
            onesPlaceSprite.setTextureRect(IntRect(189, 0, 21, 32));
        }

        // figures out what the tensPlace is
        int tempTens = 0;
        tempTens = digits;
        int tensPlace = tempTens / 10;
        if(tensPlace == 0)
        {
            tensPlaceSprite.setTextureRect(IntRect(0, 0, 21, 32));
        }

        else if(tensPlace == 1 || tensPlace == -1)
        {
            tensPlaceSprite.setTextureRect(IntRect(21, 0, 21, 32));
        }

        else if(tensPlace == 2 || tensPlace == -2)
        {
            tensPlaceSprite.setTextureRect(IntRect(42, 0, 21, 32));
        }

        else if(tensPlace == 3 || tensPlace == -3)
        {
            tensPlaceSprite.setTextureRect(IntRect(63, 0, 21, 32));
        }

        else if(tensPlace == 4 || tensPlace == -4)
        {
            tensPlaceSprite.setTextureRect(IntRect(84, 0, 21, 32));
        }

        else if(tensPlace == 5 || tensPlace == -5)
        {
            tensPlaceSprite.setTextureRect(IntRect(105, 0, 21, 32));
        }

        else if(tensPlace == 6 || tensPlace == -6)
        {
            tensPlaceSprite.setTextureRect(IntRect(126, 0, 21, 32));
        }

        else if(tensPlace == 7 || tensPlace == -7)
        {
            tensPlaceSprite.setTextureRect(IntRect(147, 0, 21, 32));
        }

        else if(tensPlace == 8 || tensPlace == -8)
        {
            tensPlaceSprite.setTextureRect(IntRect(168, 0, 21, 32));
        }

        else if(tensPlace == 9 || tensPlace == -9)
        {
            tensPlaceSprite.setTextureRect(IntRect(189, 0, 21, 32));
        }

        // figures out what the hundredPlace is
        int tempHundreds = 0;
        tempHundreds = digits;
        int hundredsPlace = tempHundreds / 100;
        if(hundredsPlace == 0)
        {
            hundredsPlaceSprite.setTextureRect(IntRect(0, 0, 21, 32));
        }

        else if(hundredsPlace == 1 || hundredsPlace == -1)
        {
            hundredsPlaceSprite.setTextureRect(IntRect(21, 0, 21, 32));
        }

        else if(hundredsPlace == 2 || hundredsPlace == -2)
        {
            hundredsPlaceSprite.setTextureRect(IntRect(42, 0, 21, 32));
        }

        else if(hundredsPlace == 3 || hundredsPlace == -3)
        {
            hundredsPlaceSprite.setTextureRect(IntRect(63, 0, 21, 32));
        }

        else if(hundredsPlace == 4 || hundredsPlace == -4)
        {
            hundredsPlaceSprite.setTextureRect(IntRect(84, 0, 21, 32));
        }

        else if(hundredsPlace == 5 || hundredsPlace == -5)
        {
            hundredsPlaceSprite.setTextureRect(IntRect(105, 0, 21, 32));
        }

        else if(hundredsPlace == 6 || hundredsPlace == -6)
        {
            hundredsPlaceSprite.setTextureRect(IntRect(126, 0, 21, 32));
        }

        else if(hundredsPlace == 7 || hundredsPlace == -7)
        {
            hundredsPlaceSprite.setTextureRect(IntRect(147, 0, 21, 32));
        }

        else if(hundredsPlace == 8 || hundredsPlace == -8)
        {
            hundredsPlaceSprite.setTextureRect(IntRect(168, 0, 21, 32));
        }

        else if(hundredsPlace == 9 || hundredsPlace == -9)
        {
            hundredsPlaceSprite.setTextureRect(IntRect(189, 0, 21, 32));
        }

        negativePlaceSprite.setPosition(0, numRow * 32.0);
        window.draw(negativePlaceSprite);

        onesPlaceSprite.setPosition(63.0, numRow * 32.0);
        window.draw(onesPlaceSprite);

        tensPlaceSprite.setPosition(42.0, numRow * 32.0);
        window.draw(tensPlaceSprite);

        hundredsPlaceSprite.setPosition(21.0, numRow * 32.0);
        window.draw(hundredsPlaceSprite);

        window.display();
    }

    // clear out any textures before the program ends
    TextureManager::Clear();

    return 0;
}
