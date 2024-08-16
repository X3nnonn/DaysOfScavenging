#include "AssetManger.h"

std::unordered_map<std::string, Texture*> AssetManager::s_textures;
std::unordered_map<std::string, Music*> AssetManager::s_audio;
std::unordered_map<std::string, Shader*> AssetManager::s_shaders;

Texture* AssetManager::GetTexture(const char* name)
{
    auto texITR = s_textures.find(name);
    if (texITR == s_textures.end())
    {
        TraceLog(LOG_WARNING, "Texture %s was not found.", name);
        return NULL;
    }

    return s_textures[name];
}

Music* AssetManager::GetAudio(const char* name)
{
    auto audITR = s_audio.find(name);
    if (audITR == s_audio.end())
    {
        TraceLog(LOG_WARNING, "s_audio %s was not found.", name);
        return NULL;
    }
    
    return s_audio[name];

}   

Shader* AssetManager::GetShader(const char* name)
{
    auto ShadITR = s_shaders.find(name);
    if (ShadITR == s_shaders.end())
    {
        TraceLog(LOG_WARNING, "Shader %s was not found.", name);
        return NULL;
    }
    
    return s_shaders[name];
}


void AssetManager::LoadTexture(const char* name, const char* path)
{
    auto texITR = s_textures.find(name);
    if (texITR != s_textures.end())
    {
        TraceLog(LOG_WARNING, "Texture %s is already loaded", name);
        return;
    }

    Texture2D texture = ::LoadTexture(path);
    Texture* tex = new Texture;
    *tex = texture;
    s_textures[name] = tex;
}

void AssetManager::LoadAudio(const char* name, const char* path)
{
    auto audITR = s_audio.find(name);
    if (audITR != s_audio.end())
    {
        TraceLog(LOG_WARNING, "Audio %s is already loaded", name);
        return;
    }

    Music audio = LoadMusicStream(path);
    Music* aud = new Music;
    *aud = audio;
    s_audio[name] = aud;
}

void AssetManager::LoadShader(const char* name, ShaderSRC& src)
{
    auto shadITR = s_shaders.find(name);
    if (shadITR != s_shaders.end())
    {
        TraceLog(LOG_WARNING, "Shader %s is already loaded", name);
        return;
    }

    Shader shader = ::LoadShader(src.vertexPath.c_str(), src.fragmentPath.c_str());
    Shader* shad = new Shader;
    *shad = shader;
    s_shaders[name] = shad;
}

void AssetManager::DropTexture(const char* name)
{
    auto texITR = s_textures.find(name);
    if (texITR == s_textures.end())
    {
        TraceLog(LOG_WARNING, "Texture %s was not found.", name);
        return;
    }


    UnloadTexture(*s_textures[name]);
    delete s_textures[name];
    s_textures.erase(texITR);
}

void AssetManager::DropAudio(const char* name)
{
    auto audITR = s_audio.find(name);
    if (audITR == s_audio.end())
    {
        TraceLog(LOG_WARNING, "Audio %s was not found.", name);
        return;
    }


    UnloadMusicStream(*s_audio[name]);
    delete s_audio[name];
    s_audio.erase(audITR);
}

void AssetManager::DropShader(const char* name)
{
    auto shadITR = s_shaders.find(name);
    if (shadITR == s_shaders.end())
    {
        TraceLog(LOG_WARNING, "Shader %s was not found.", name);
        return;
    }


    UnloadShader(*s_shaders[name]);
    delete s_shaders[name];
    s_shaders.erase(shadITR);
}

void AssetManager::Clean()
{
    for (auto& [name, texture] : s_textures)
    {
        UnloadTexture(*s_textures[name]);
        delete s_textures[name];
    }

    for (auto& [name, audio] : s_audio)
    {
        UnloadMusicStream(*s_audio[name]);
        delete s_audio[name];
    }

    for (auto& [name, shader] : s_shaders)
    {
        UnloadMusicStream(*s_audio[name]);
        delete s_audio[name];
    }

    s_textures.clear();
    s_audio.clear();
    s_shaders.clear();
}