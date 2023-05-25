#ifndef TEXTURA_H
#define TEXTURA_H
#include<iostream>
using namespace std;
class textura
{

private:
    unsigned int m_id;
    int m_largura,m_altura,m_canais;
public:
        textura();
        virtual ~textura();
        void load(string filePath);
        void Bind();
        void unBind();

};

#endif // TEXTURA_H
