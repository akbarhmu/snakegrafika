#include "painter.hpp"
#include "game.hpp"
#include "GL/glut.h"

#include<iostream>
#include<cstring>
#include<cstdio>

#include <windows.h>
#include <mmsystem.h>
using namespace std;
Game game;

int flag,flag2,flag3, flag4,flag5,hsc,tm;
void printtext(int x, int y, string String);
enum level{
    SLUG, 
    WORM , 
    KOBRA
};
level l;

void display()
{
  int sc;
  double w = 200, h = 200, x = 0, y = 0;
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glColor3f(1.0f, 1.0f, 1.0f);				
  glBegin(GL_LINE_LOOP);
  glVertex2f(x+1, y+1);
  glVertex2f(x+1, y+h-1);
  glVertex2f(x+w-1, y+h-1);
  glVertex2f(x+w-1, y+1);
  glEnd();
  
  char str[64];
  sc = game.nb();		
  if(!sc)
	sc = 1;
  if(l == SLUG) {
		  sc = (sc-1)*30;
		  sprintf(str, "Level : 1");
	} else if (l == WORM) {
		  sc = 150 + (sc -1) * 50;
		  sprintf(str, "Level : 2");
	} else {
		  sc = 350 + (sc - 1) * 70;
		  sprintf(str, "Level : 3");
	}
  printtext(170,120,str);
  sprintf(str, "Skor Tertinggi : %d", hsc);
  printtext(170,80,str);
  sprintf(str, "Skor : %d ", sc);
  printtext(170,100,str);

  if (sc == 350 && !flag4) {
      flag4 = 1;
	    flag5 = 1;	
	    l = KOBRA;
	    tm = 125;

	    sprintf(str, "Selamat! Level 2 berhasil dilalui");
	    printtext(80,120,str);
	    game.cons();
	    game.setlevel2();
	} else if (sc == 150 && !flag3)	{
      flag3 =1;		
		  flag5  = 1;		
		  l = WORM;
		
	    game.cons(); 
      sprintf(str, "Selamat!  Level 1 berhasil dilalui");
	  	printtext(80,120,str);
	  	
		  game.setlevel1();
		  tm = 190;
	}    

  if (flag2==1) {
      PlaySound("sounds/lose.wav", NULL, SND_ASYNC|SND_FILENAME);
	    sprintf(str, "Skor : %d ", sc);
	    printtext(80,100,str);
	    if (sc > hsc ) {
          hsc = sc;
			    sprintf(str, "Selamat! Anda mempunyai skor tertinggi");
			    printtext(80,120,str);
		  } else {
			    sprintf(str, "Tekan 'e' atau 'E' untuk keluar dari game ");
			    printtext(80,120,str);
	    }
      flag3=flag4 = 0;			
      tm = 300;
      sc = 1;
      l = SLUG;
  }
  Painter p;
  game.draw(p);
  glutSwapBuffers();
}

void printtext(int x, int y, string String) {
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();

    glRasterPos2i(x,y);
    for (int i=0; i<String.size(); i++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, String[i]);
    }
    glPopAttrib();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();     
}

void timer(int x = 0) {
    flag2 =  game.tick();
    display();
    if (flag2 == 1) {
        game.cons();
        flag2 = 0; 
        sleep(2);       
    }
    if(flag5) {
        sleep(4);
        flag5 = 0;
    }
    if (flag == 0) glutTimerFunc(tm, timer, 0);
}


void keyEvent(int key, int, int) {
    switch (key) {
        case GLUT_KEY_LEFT:
          game.keyEvent(Snake::LEFT);
          break;
        case GLUT_KEY_UP:
          game.keyEvent(Snake::UP);
          break;
        case GLUT_KEY_RIGHT:
          game.keyEvent(Snake::RIGHT);
          break;
        case GLUT_KEY_DOWN:
          game.keyEvent(Snake::DOWN);
          break;
    }
}

void myKeyboard(unsigned char key, int mouseX, int mouseY) {		         
    switch(key) {
      case 'E':
      case 'e':  exit(-1);
          break;
      case 'p': flag = 1;					
          break;					
      default: if (flag) {
            flag = 0;					
            glutTimerFunc(tm, timer, 0);
          }
          break;
	  }
}

void Initialize(void) {
      glEnable(GL_COLOR_MATERIAL); 
      glEnable(GL_LIGHTING); 
      glEnable(GL_LIGHT0); 
      glEnable(GL_NORMALIZE);

      GLfloat lightColor0[] = {0.7f, 0.7f, 0.7f, 1.0f}; 
      GLfloat lightPos0[] = {100.0f, 100.0f, 30.0f, 1.0f}; 
      glLightfv(GL_LIGHT0, GL_SPECULAR, lightColor0);
      glLightfv(GL_LIGHT0, GL_POSITION, lightPos0); 
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); 
  glutInitWindowSize(Field::WIDTH * Field::BLOCK_WIDTH*8, Field::HEIGHT * Field::BLOCK_HEIGHT*4);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("Snake Game");
  glClearColor(0, 0, 0, 1.0); 
  glMatrixMode(GL_PROJECTION); 
  glLoadIdentity();
  glOrtho(0, Field::WIDTH * Field::BLOCK_WIDTH,  Field::HEIGHT * Field::BLOCK_HEIGHT, 0,-1.0, 1.0);
  glutDisplayFunc(display);
  glutSpecialFunc(keyEvent);
  glutKeyboardFunc(myKeyboard);
  Initialize();			
  l = SLUG;
  tm = 300;
  timer();
  glutMainLoop();
}
