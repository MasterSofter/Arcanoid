#ifndef ARCANOID_RECOURCEMNG_H
#define ARCANOID_RECOURCEMNG_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Audio.hpp>
#include "EnumTexture.h"
#include "EnumSound.h"
#include <map>

using namespace sf;

class RecourceMng {
private:
    RecourceMng();

    std::map<EnumTexture, Texture*> textures;
    std::map<EnumSound, SoundBuffer*> sounds;
public:
    static RecourceMng& Instance()
    {
        static RecourceMng inst;
        return inst;
    }

    void Init();
    const Texture& GetTexture(EnumTexture texture);
    const SoundBuffer& GetSound(EnumSound sound);
};


#endif //ARCANOID_RECOURCEMNG_H
