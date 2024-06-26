#pragma once

#include <string>

namespace TenetEngine {

class Texture
{
public:
    Texture(const std::string& filePath);
    void bind();
    void unbind();
    unsigned int getTexturePositionID() const { return texturePositionID; }
private:
    unsigned int texture;
    unsigned int texturePositionID = -1;
};

}