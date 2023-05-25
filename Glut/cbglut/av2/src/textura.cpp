#include "textura.h"
#include "stb_image.h"
#include <windows.h>
#include<gl/GL.h>
#include<iostream>
using namespace std;

textura::textura()
{
int m_id(0), m_largura(0),m_altura(0),m_canais(0);
}

textura::~textura()
{
    glDeleteTextures(1,&m_id);
}

void textura::Bind()
{
    glBindTexture(GL_TEXTURE_2D, m_id);
}

void textura::unBind(){

    glBindTexture(GL_TEXTURE_2D,0);

}

void textura::load(string filePath)
{

    unsigned char* imgData;
   // int largura,altura,canais;
    stbi_set_flip_vertically_on_load(true);
    imgData=stbi_load(filePath.c_str(),&m_largura,&m_altura,&m_canais,4);
    if(imgData)
    {
        glGenTextures(1,&m_id);
        glBindTexture(GL_TEXTURE_2D, m_id);
        glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA8, m_largura,m_altura,0,GL_RGBA, GL_UNSIGNED_BYTE,imgData);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

        glBindTexture(GL_TEXTURE_2D, 0);
        stbi_image_free(imgData);

    }
    else{
        cout<<"ERRO:Nao foi possivel carregar a textura!"<< filePath.c_str()<<endl;

    }
}

