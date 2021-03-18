#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
float px,py;

void drawPlayer()
{
glColor3f(1,1,0);
glPointSize(6);
glBegin(GL_POINTS);
glVertex2i(px,py);
glEnd();
}

int mapX=8,mapY=8,mapS=64;
int map[]=
{
1,1,1,1,1,1,1,1,
1,0,0,0,0,0,0,1,
1,0,0,0,1,1,0,1,
1,0,0,0,0,1,0,1,
1,0,0,0,0,1,0,1,
1,0,1,0,1,1,0,1,
1,0,0,0,0,0,0,1,
1,1,1,1,1,1,1,1
};

void DrawMap2D()
{
	int x,y,xo,yo;
	for(y=0;y<mapY;y++)
	{
		for(x=0;x<mapX;x++)
			{
			if(map[y*mapX+x]==1){ glColor3f(1,1,1);}else{glColor3f(0,0,0);}
			xo=x*mapS; yo=y*mapS;
			glBegin(GL_QUADS);
			glVertex2i(xo	  +1,yo     +1);
			glVertex2i(xo	  +1,yo+mapS-1);
			glVertex2i(xo+mapS-1,yo+mapS-1);
			glVertex2i(xo+mapS-1,yo     +1);
			glEnd();
			}
		
		
	
	
	}


}




void buttons(unsigned char key,int x,int y)
{

if(key=='a'){px-=3;}
if(key=='d'){px+=3;}
if(key=='w'){py-=3;}
if(key=='s'){py+=3;}
glutPostRedisplay();

}

void display()
{
 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 DrawMap2D();
 drawPlayer();
 glutSwapBuffers();
}

void init()
{
	glClearColor(0.3,0.3,0.3,0);
	gluOrtho2D(0,1024,512,0);
	px=300; py=300;
}


int main(int argc, char** argv)
{ 
 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
 glutInitWindowSize(1024, 512);
 glutCreateWindow("OpenGL");
 init();
 glutDisplayFunc(display);
 glutKeyboardFunc(buttons);
 glutMainLoop();

 
 return 0;
}
