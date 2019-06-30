#include "RecourceMng.h"
#include <string>

using namespace std;
using namespace sf;

RecourceMng::RecourceMng()
{

}

void RecourceMng::Init()
{
    std::pair<EnumTexture, string> files[] =
    {
        {EnumTexture::Background,   "textures/char_sex.png"},
        {EnumTexture::Ice1,         "textures/ice_01.png"},
        {EnumTexture::Ice2,         "textures/ice_02.png"},
        {EnumTexture::Ice3,         "textures/ice_03.png"},
        {EnumTexture::Road,         "textures/char_road.png"},
        {EnumTexture::Player,       "textures/char_hero.png"},
        {EnumTexture::Ball,         "textures/ball.png"},
        {EnumTexture::IceWithGnom1, "textures/gnom_ice_01.png"},
        {EnumTexture::IceWithGnom2, "textures/gnom_ice_02.png"},
        {EnumTexture::IceWithGnom3, "textures/gnom_ice_03.png"},
        {EnumTexture::Gnom1,        "textures/gnom_ice_04.png"},
        {EnumTexture::Gnom2,        "textures/gnom_ice_05.png"},
        {EnumTexture::Gnom3,        "textures/gnom_ice_06.png"},
    };

    for(int i = 0; i < sizeof(files)/sizeof(files[0]); i++)
    {
        Texture* texture = new Texture();
        texture->loadFromFile(files[i].second);
        textures[files[i].first] = texture;
    }

    ///Загрузка звуков
    std::pair<EnumSound , string> soundfiles[] =
    {
        {EnumSound::SoundKnock,        "sounds/knock.wav"},
        {EnumSound::SoundIceKnock,     "sounds/IceKnock.wav"},
        {EnumSound::SoundReflectIce,   "sounds/Ice01.wav"},
        {EnumSound::SoundIceDestroyed, "sounds/ice02.wav"},
        {EnumSound::SoundPlayer,       "sounds/iron.wav"}
    };

    for(int i = 0; i < sizeof(soundfiles)/sizeof(soundfiles[0]); i++)
    {
        SoundBuffer* buffer = new SoundBuffer(); // this buffer is local to the function, it will be destroyed...
        buffer->loadFromFile(soundfiles[i].second);
        sounds[soundfiles[i].first] = buffer;
    }
}

const Texture& RecourceMng::GetTexture(EnumTexture texture)
{
    return *(textures[texture]);
}
const SoundBuffer& RecourceMng::GetSound(EnumSound sound)
{
    return *(sounds[sound]);
}