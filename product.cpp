#include <GL/freeglut.h>
#include <GL/gl.h>
#include <GL/glext.h>
#include <GL/glut.h>
#include <GL/glcorearb.h>
#include <cstdio>
#include <iostream>
#include "product.hpp"
#include "conveyor.hpp"

GLint textureCold = 0;
GLint textureHot  = 0;

void drawDevice() {
    glBegin(GL_QUADS);

    glColor3d(0.6f, 0.6f, 0.6f);

    // top
    glNormal3d(1, 0, 0);
    glVertex3d(0.3f, 0.f, -LINK_HEIGHT * 3.f);
    glVertex3d(-0.3f, 0.f, -LINK_HEIGHT * 3.f);
    glVertex3d(-0.3f, 0.6f, -LINK_HEIGHT * 3.f);
    glVertex3d(0.3f, 0.6f, -LINK_HEIGHT * 3.f);

    // sides
    glNormal3d(0, 0, -1);
    glVertex3d(0.3f, 0.6f, -LINK_HEIGHT * 3.f);
    glVertex3d(0.3f, 0.6f, LINK_HEIGHT);
    glVertex3d(0.3f, 0.f, LINK_HEIGHT);
    glVertex3d(0.3f, 0.f, -LINK_HEIGHT * 3.f);

    glNormal3d(0, 0, 1);
    glVertex3d(-0.3f, 0.6f, -LINK_HEIGHT * 3.f);
    glVertex3d(-0.3f, 0.6f, LINK_HEIGHT);
    glVertex3d(-0.3f, 0.f, LINK_HEIGHT);
    glVertex3d(-0.3f, 0.f, -LINK_HEIGHT * 3.f);

    // out/in-lets
    glNormal3d(1, 0, 0);
    glVertex3d(0.25f, 0.f, -LINK_HEIGHT * 3.f);
    glVertex3d(0.25f, 0.f, LINK_HEIGHT);
    glVertex3d(0.3f, 0.f, LINK_HEIGHT);
    glVertex3d(0.3f, 0.f, -LINK_HEIGHT * 3.f);

    glVertex3d(-0.25f, 0.f, -LINK_HEIGHT * 3.f);
    glVertex3d(-0.25f, 0.f, LINK_HEIGHT);
    glVertex3d(-0.3f, 0.f, LINK_HEIGHT);
    glVertex3d(-0.3f, 0.f, -LINK_HEIGHT * 3.f);

    glVertex3d(-0.25f, 0.f, -LINK_HEIGHT * 3.f + 0.05f);
    glVertex3d(-0.25f, 0.f, -LINK_HEIGHT * 3.f);
    glVertex3d(0.25f, 0.f, -LINK_HEIGHT * 3.f);
    glVertex3d(0.25f, 0.f, -LINK_HEIGHT * 3.f + 0.05f);

    glNormal3d(-1, 0, 0);
    glVertex3d(0.25f, 0.6f, -LINK_HEIGHT * 3.f);
    glVertex3d(0.25f, 0.6f, LINK_HEIGHT);
    glVertex3d(0.3f, 0.6f, LINK_HEIGHT);
    glVertex3d(0.3f, 0.6f, -LINK_HEIGHT * 3.f);

    glVertex3d(-0.25f, 0.6f, -LINK_HEIGHT * 3.f);
    glVertex3d(-0.25f, 0.6f, LINK_HEIGHT);
    glVertex3d(-0.3f, 0.6f, LINK_HEIGHT);
    glVertex3d(-0.3f, 0.6f, -LINK_HEIGHT * 3.f);

    glVertex3d(-0.25f, 0.6f, -LINK_HEIGHT * 3.f + 0.05f);
    glVertex3d(-0.25f, 0.6f, -LINK_HEIGHT * 3.f);
    glVertex3d(0.25f, 0.6f, -LINK_HEIGHT * 3.f);
    glVertex3d(0.25f, 0.6f, -LINK_HEIGHT * 3.f + 0.05f);

    glNormal3d(1, 0, 0);
    glColor3d(0.f, 0.f, 0.f);
    glVertex3d(-0.25f, 0.f, -LINK_HEIGHT * 3.f + 0.05f);
    glVertex3d(-0.25f, 0.f, LINK_HEIGHT);
    glVertex3d(0.25f, 0.f, LINK_HEIGHT);
    glVertex3d(0.25f, 0.f, -LINK_HEIGHT * 3.f + 0.05f);

    glNormal3d(-1, 0, 0);
    glVertex3d(-0.25f, 0.6f, -LINK_HEIGHT * 3.f + 0.05f);
    glVertex3d(-0.25f, 0.6f, LINK_HEIGHT);
    glVertex3d(0.25f, 0.6f, LINK_HEIGHT);
    glVertex3d(0.25f, 0.6f, -LINK_HEIGHT * 3.f + 0.05f);

    glEnd();
}

void drawCube() {
    glBegin(GL_QUADS);
    glColor3d(0.8f, 0.8f, 0.8f);

    glNormal3d(-1.f, 0.f, 0.f);
    glVertex3d(0.1f, -0.1f, 0.1f);
    glVertex3d(0.1f, 0.1f, 0.1f);
    glVertex3d(0.1f, 0.1f, -0.1f);
    glVertex3d(0.1f, -0.1f, -0.1f);

    glNormal3d(1.f, 0.f, 0.f);
    glVertex3d(-0.1f, -0.1f, 0.1f);
    glVertex3d(-0.1f, 0.1f, 0.1f);
    glVertex3d(-0.1f, 0.1f, -0.1f);
    glVertex3d(-0.1f, -0.1f, -0.1f);

    glNormal3d(0.f, -1.f, 0.f);
    glVertex3d(-0.1f, 0.1f, 0.1f);
    glVertex3d(0.1f, 0.1f, 0.1f);
    glVertex3d(0.1f, 0.1f, -0.1f);
    glVertex3d(-0.1f, 0.1f, -0.1f);

    glNormal3d(0.f, 1.f, 0.f);
    glVertex3d(-0.1f, -0.1f, 0.1f);
    glVertex3d(0.1f, -0.1f, 0.1f);
    glVertex3d(0.1f, -0.1f, -0.1f);
    glVertex3d(-0.1f, -0.1f, -0.1f);

    glNormal3d(0.f, 0.f, -1.f);
    glVertex3d(-0.1f, -0.1f, 0.1f);
    glVertex3d(0.1f, -0.1f, 0.1f);
    glVertex3d(0.1f, 0.1f, 0.1f);
    glVertex3d(-0.1f, 0.1f, 0.1f);

    glNormal3d(0.f, 0.f, 1.f);
    glVertex3d(-0.1f, -0.1f, -0.1f);
    glVertex3d(0.1f, -0.1f, -0.1f);
    glVertex3d(0.1f, 0.1f, -0.1f);
    glVertex3d(-0.1f, 0.1f, -0.1f);

    glEnd();
}

void drawCubeHeated() {
    glBegin(GL_QUADS);
    glColor3d(1.f, 0.6f, 0.6f);

    glNormal3d(-1.f, 0.f, 0.f);
    glVertex3d(0.1f, -0.1f, 0.1f);
    glVertex3d(0.1f, 0.1f, 0.1f);
    glVertex3d(0.1f, 0.1f, -0.1f);
    glVertex3d(0.1f, -0.1f, -0.1f);

    glNormal3d(1.f, 0.f, 0.f);
    glVertex3d(-0.1f, -0.1f, 0.1f);
    glVertex3d(-0.1f, 0.1f, 0.1f);
    glVertex3d(-0.1f, 0.1f, -0.1f);
    glVertex3d(-0.1f, -0.1f, -0.1f);

    glNormal3d(0.f, -1.f, 0.f);
    glVertex3d(-0.1f, 0.1f, 0.1f);
    glVertex3d(0.1f, 0.1f, 0.1f);
    glVertex3d(0.1f, 0.1f, -0.1f);
    glVertex3d(-0.1f, 0.1f, -0.1f);

    glNormal3d(0.f, 1.f, 0.f);
    glVertex3d(-0.1f, -0.1f, 0.1f);
    glVertex3d(0.1f, -0.1f, 0.1f);
    glVertex3d(0.1f, -0.1f, -0.1f);
    glVertex3d(-0.1f, -0.1f, -0.1f);

    glNormal3d(0.f, 0.f, -1.f);
    glVertex3d(-0.1f, -0.1f, 0.1f);
    glVertex3d(0.1f, -0.1f, 0.1f);
    glVertex3d(0.1f, 0.1f, 0.1f);
    glVertex3d(-0.1f, 0.1f, 0.1f);

    glNormal3d(0.f, 0.f, 1.f);
    glVertex3d(-0.1f, -0.1f, -0.1f);
    glVertex3d(0.1f, -0.1f, -0.1f);
    glVertex3d(0.1f, 0.1f, -0.1f);
    glVertex3d(-0.1f, 0.1f, -0.1f);

    glEnd();
}

void drawCubeBrushed() {
    glEnable(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, textureHot);
    glBegin(GL_QUADS);
    glColor3d(0.8f, 0.8f, 0.8f);

    glNormal3d(-1.f, 0.f, 0.f);
    glTexCoord2f(0.f, 0.f);
    glVertex3d(0.1f, -0.1f, 0.1f);
    glTexCoord2f(0.f, 1.f);
    glVertex3d(0.1f, 0.1f, 0.1f);
    glTexCoord2f(1.f, 1.f);
    glVertex3d(0.1f, 0.1f, -0.1f);
    glTexCoord2f(1.f, 0.f);
    glVertex3d(0.1f, -0.1f, -0.1f);

    glNormal3d(1.f, 0.f, 0.f);
    glVertex3d(-0.1f, 0.1f, 0.1f);
    glTexCoord2f(0.f, 0.f);
    glVertex3d(-0.1f, 0.1f, -0.1f);
    glTexCoord2f(0.f, 1.f);
    glVertex3d(-0.1f, -0.1f, -0.1f);
    glTexCoord2f(1.f, 1.f);
    glVertex3d(-0.1f, -0.1f, 0.1f);
    glTexCoord2f(1.f, 0.f);

    glNormal3d(0.f, -1.f, 0.f);
    glTexCoord2f(0.f, 0.f);
    glVertex3d(-0.1f, 0.1f, 0.1f);
    glTexCoord2f(0.f, 1.f);
    glVertex3d(0.1f, 0.1f, 0.1f);
    glTexCoord2f(1.f, 1.f);
    glVertex3d(0.1f, 0.1f, -0.1f);
    glTexCoord2f(1.f, 0.f);
    glVertex3d(-0.1f, 0.1f, -0.1f);

    glNormal3d(0.f, 1.f, 0.f);
    glTexCoord2f(0.f, 0.f);
    glVertex3d(-0.1f, -0.1f, 0.1f);
    glTexCoord2f(0.f, 1.f);
    glVertex3d(0.1f, -0.1f, 0.1f);
    glTexCoord2f(1.f, 1.f);
    glVertex3d(0.1f, -0.1f, -0.1f);
    glTexCoord2f(1.f, 0.f);
    glVertex3d(-0.1f, -0.1f, -0.1f);

    glNormal3d(0.f, 0.f, -1.f);
    glTexCoord2f(0.f, 0.f);
    glVertex3d(-0.1f, -0.1f, 0.1f);
    glTexCoord2f(0.f, 1.f);
    glVertex3d(0.1f, -0.1f, 0.1f);
    glTexCoord2f(1.f, 1.f);
    glVertex3d(0.1f, 0.1f, 0.1f);
    glTexCoord2f(1.f, 0.f);
    glVertex3d(-0.1f, 0.1f, 0.1f);

    glNormal3d(0.f, 0.f, 1.f);
    glTexCoord2f(0.f, 0.f);
    glVertex3d(-0.1f, -0.1f, -0.1f);
    glTexCoord2f(0.f, 1.f);
    glVertex3d(0.1f, -0.1f, -0.1f);
    glTexCoord2f(1.f, 1.f);
    glVertex3d(0.1f, 0.1f, -0.1f);
    glTexCoord2f(1.f, 0.f);
    glVertex3d(-0.1f, 0.1f, -0.1f);

    glEnd();

    glDisable(GL_TEXTURE_2D);
}

void drawCubeCooled() {
    glEnable(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, textureCold);
    glBegin(GL_QUADS);
    glColor3d(0.8f, 0.8f, 0.8f);

    glNormal3d(-1.f, 0.f, 0.f);
    glTexCoord2f(0.f, 0.f);
    glVertex3d(0.1f, -0.1f, 0.1f);
    glTexCoord2f(0.f, 1.f);
    glVertex3d(0.1f, 0.1f, 0.1f);
    glTexCoord2f(1.f, 1.f);
    glVertex3d(0.1f, 0.1f, -0.1f);
    glTexCoord2f(1.f, 0.f);
    glVertex3d(0.1f, -0.1f, -0.1f);

    glNormal3d(1.f, 0.f, 0.f);
    glVertex3d(-0.1f, 0.1f, 0.1f);
    glTexCoord2f(0.f, 0.f);
    glVertex3d(-0.1f, 0.1f, -0.1f);
    glTexCoord2f(0.f, 1.f);
    glVertex3d(-0.1f, -0.1f, -0.1f);
    glTexCoord2f(1.f, 1.f);
    glVertex3d(-0.1f, -0.1f, 0.1f);
    glTexCoord2f(1.f, 0.f);

    glNormal3d(0.f, -1.f, 0.f);
    glTexCoord2f(0.f, 0.f);
    glVertex3d(-0.1f, 0.1f, 0.1f);
    glTexCoord2f(0.f, 1.f);
    glVertex3d(0.1f, 0.1f, 0.1f);
    glTexCoord2f(1.f, 1.f);
    glVertex3d(0.1f, 0.1f, -0.1f);
    glTexCoord2f(1.f, 0.f);
    glVertex3d(-0.1f, 0.1f, -0.1f);

    glNormal3d(0.f, 1.f, 0.f);
    glTexCoord2f(0.f, 0.f);
    glVertex3d(-0.1f, -0.1f, 0.1f);
    glTexCoord2f(0.f, 1.f);
    glVertex3d(0.1f, -0.1f, 0.1f);
    glTexCoord2f(1.f, 1.f);
    glVertex3d(0.1f, -0.1f, -0.1f);
    glTexCoord2f(1.f, 0.f);
    glVertex3d(-0.1f, -0.1f, -0.1f);

    glNormal3d(0.f, 0.f, -1.f);
    glTexCoord2f(0.f, 0.f);
    glVertex3d(-0.1f, -0.1f, 0.1f);
    glTexCoord2f(0.f, 1.f);
    glVertex3d(0.1f, -0.1f, 0.1f);
    glTexCoord2f(1.f, 1.f);
    glVertex3d(0.1f, 0.1f, 0.1f);
    glTexCoord2f(1.f, 0.f);
    glVertex3d(-0.1f, 0.1f, 0.1f);

    glNormal3d(0.f, 0.f, 1.f);
    glTexCoord2f(0.f, 0.f);
    glVertex3d(-0.1f, -0.1f, -0.1f);
    glTexCoord2f(0.f, 1.f);
    glVertex3d(0.1f, -0.1f, -0.1f);
    glTexCoord2f(1.f, 1.f);
    glVertex3d(0.1f, 0.1f, -0.1f);
    glTexCoord2f(1.f, 0.f);
    glVertex3d(-0.1f, 0.1f, -0.1f);

    glEnd();

    glDisable(GL_TEXTURE_2D);
}

GLuint LoadTexture( const char * filename )
{
    GLuint texture;
    int width, height;
    unsigned char * data;

    FILE * file;
    file = fopen( filename, "rb" );

    if ( file == nullptr ) return 0;
    width = 1280;
    height = 1280;
    data = (unsigned char *)malloc( width * height * 3 );
    //int size = fseek(file,);
    fread( data, width * height * 3, 1, file );
    fclose( file );

    for(int i = 0; i < width * height ; ++i)
    {
        int index = i*3;
        unsigned char B,R;
        B = data[index];
        R = data[index+2];

        data[index] = R;
        data[index+2] = B;
    }

    glGenTextures( 1, &texture );
    glBindTexture( GL_TEXTURE_2D, texture );
    glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_MODULATE );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST );

    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,GL_REPEAT );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,GL_REPEAT );
    gluBuild2DMipmaps( GL_TEXTURE_2D, 3, width, height,GL_RGB, GL_UNSIGNED_BYTE, data );
    free( data );

    return texture;
}

void loadThings() {
    textureCold = LoadTexture("data/aluminum.bmp");
    textureHot = LoadTexture("data/aluminumHot.bmp");
    std::cout << textureCold << " " << textureHot << "\n";
}