//
// Created by Amanda Yu on 4/17/22.
//

#include "TextureManager.h"
using namespace std;
using namespace sf;

// "redeclare" the variable, so this file knows it exists and can use
unordered_map<string, Texture> TextureManager::textures;

void TextureManager::LoadTexture(string fileName)
{
    string path = "images/";
    path += fileName + ".png";

    textures[fileName].loadFromFile(path);
}

Texture& TextureManager::GetTexture(string textureName)
{
    // if the texture DOESN'T exist
    // we didn't find it
    if(textures.find(textureName) == textures.end())
    {
        LoadTexture(textureName);
    }

    return textures[textureName];
}

void TextureManager::Clear()
{
    // get rid of all stored objects
    textures.clear();
}

void TextureManager::CreateBlank()
{
    textures["blankTiles"].create(32, 32);
}
