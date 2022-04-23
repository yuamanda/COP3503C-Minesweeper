//
// Created by Amanda Yu on 4/17/22.
//

#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <string>
using std::unordered_map;
using std::string;
using namespace std;
using namespace sf;

class TextureManager
{
    // static == one and only one of these in memory, ever
    static unordered_map<string, Texture> textures;
    static void LoadTexture(string fileName);

public:
    static Texture& GetTexture(string textureName);

    // call this once, at the end of main()
    static void Clear();

    static void CreateBlank();
};
