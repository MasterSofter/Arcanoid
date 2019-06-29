#ifndef ARCANOID_RECOURCEMNG_H
#define ARCANOID_RECOURCEMNG_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include "EnumTexture.h"
#include <map>

using namespace sf;

class RecourceMng {
private:
    RecourceMng();

    std::map<EnumTexture, Texture*> textures;

public:
    static RecourceMng& Instance()
    {
        static RecourceMng inst;
        return inst;
    }

    void Init();
    const Texture& GetTexture(EnumTexture texture);

};


#endif //ARCANOID_RECOURCEMNG_H
