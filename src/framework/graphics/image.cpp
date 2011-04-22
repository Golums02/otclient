/* The MIT License
 *
 * Copyright (c) 2010 OTClient, https://github.com/edubart/otclient
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */


#include <prerequisites.h>
#include <graphics/image.h>
#include <graphics/graphics.h>
#include <graphics/textures.h>

Image::Image(TexturePtr texture)
    : m_texture(texture)
{
    m_textureCoords = Rect(0, 0, m_texture->getSize());
}

Image::Image(const std::string& texture)
{
    m_texture = g_textures.get(texture);
    m_textureCoords = Rect(0, 0, m_texture->getSize());
}

Image::Image(const std::string& texture, Rect textureCoords) :
    m_textureCoords(textureCoords)
{
    m_texture = g_textures.get(texture);
}

void Image::draw(const Rect& screenCoords)
{
    g_graphics.drawTexturedRect(screenCoords, m_texture, m_textureCoords);
}


