#pragma once

#include "Base.h"
#include <raylib.h>
#include <unordered_map>

struct ShaderSRC
{
    std::string vertexPath;
    std::string fragmentPath;

};

class AssetManager
{
public:
    static Texture* GetTexture(const char* name);
    static Music* GetAudio(const char* name);
    static Shader* GetShader(const char* name);

    static void LoadTexture(const char* name, const char* path);
    static void LoadAudio(const char* name, const char* path);
    static void LoadShader(const char* name, ShaderSRC& src);

    static void DropTexture(const char* name);
    static void DropAudio(const char* name);
    static void DropShader(const char* name);

    static void Clean();
private:
    static std::unordered_map<std::string, Texture*> s_textures;
    static std::unordered_map<std::string, Music*> s_audio;
    static std::unordered_map<std::string, Shader*> s_shaders;
};