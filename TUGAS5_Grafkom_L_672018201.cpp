#include "windows.h"
#include "stdlib.h"
#include "gl/glut.h"

int w=600, h=600, z=0;
int x1=0, y1=0, sudut=0, z1=0;	//sumbu
float sX=1, sY=1, sZ=1;			//skala

float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
bool mouseDown = false;
int is_depth;

//keyboard
void keyboard(unsigned char key, int x, int y){
 if (key =='a') z+=5;				//zoom in
 else if (key == 'd') z-=5;			//zoom out
 else if (key == 'q') sX+=0.5;	//melebar kiri-kanan
 else if (key == 'w') sX-=0.5;	//menciut kiri-kanan
 else if (key == 'e') sY+=0.5;	//melebar atas-bawah
 else if (key == 'r') sY-=0.5;	//menciut atas-bawah
 else if (key == 't') sZ+=0.5;	//melebar depan-belakang
 else if (key == 'u') sZ-=0.5;	//melebar depan-belakang
 else if (key == 'x') {x1=1; y1=0; z1=0; sudut+=10;}		//sebagai fungsi rotate x
 else if (key == 'y') {y1=1; x1=0; z1=0; sudut+=-10;}		//sebagai fungsi rotate y
 else if (key == 'z') {y1=0; x1=0; z1=1; sudut+=-10;}		//sebagai fungsi rotate z
}

//mouse
void idle()
{
 if (!mouseDown)
 {
	xrot +=0.3f;
	yrot +=0.4f;
 }
glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{
 if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
  {
   mouseDown = true;
   xdiff = x - yrot;
   ydiff = -y + xrot;
  }
  else
  mouseDown = false;
}

void mouseMotion(int x, int y)
{
 if (mouseDown)
 {
  yrot = x - xdiff;
  xrot = y + ydiff;
  
  glutPostRedisplay();
 }
}

void init(){
 glShadeModel(GL_SMOOTH);
 glClearColor(0.0f,0.0f,0.0f,0.5f);
 glClearDepth(1.0f);
 glEnable(GL_DEPTH_TEST);
 glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
 glEnable(GL_LIGHT0);
 glEnable(GL_COLOR_MATERIAL);
 glEnable(GL_LIGHTING);
 glEnable(GL_DEPTH_TEST);
 is_depth=1;

 GLfloat ambientLight[] = { 0.2f, 0.2f, 0.2f, 1.0f };
 GLfloat diffuseLight[] = { 0.8f, 0.8f, 0.8, 1.0f };
 GLfloat specularLight[] = { 0.5f, 0.5f, 0.5f, 1.0f };
 GLfloat position[] = { 1.5f, 1.0f, 4.0f, 1.0f };

 glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
 glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
 glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight);
 glLightfv(GL_LIGHT0, GL_POSITION, position);
 return;

}

void pagar(){
 //pagar
 glPushMatrix();
 glEnable(GL_COLOR_MATERIAL);
 glTranslatef(3,-1,1);
 glColor3f(0.8,0.8,0.8);

 glPushMatrix();
 glTranslatef(-1,0.2,0);
 glScalef(5.4,0.2,0.1);
 glutSolidCube(1);
 glPopMatrix();

 glPushMatrix();
 glTranslatef(-1,-0.2,0);
 glScalef(5.4,0.2,0.1);
 glutSolidCube(1);
 glPopMatrix();

 glScalef(0.2,1,0.1);
 glTranslatef(2,0,0);
 glutSolidCube(1);
 glTranslatef(2,0,0);
 glutSolidCube(1);
 glTranslatef(2,0,0);
 glutSolidCube(1);
 glTranslatef(2,0,0);
 glTranslatef(2,0,0);
 glTranslatef(2,0,0);
 glTranslatef(2,0,0);
 glTranslatef(-12,0,0);
 glutSolidCube(1);
 glTranslatef(-2,0,0);
 glutSolidCube(1);
 glTranslatef(-2,0,0);
 glutSolidCube(1);
 glTranslatef(-2,0,0);
 glutSolidCube(1);
 glTranslatef(-2,0,0);
 glutSolidCube(1);
 glTranslatef(-2,0,0);
 glutSolidCube(1);
 glTranslatef(-2,0,0);
 glutSolidCube(1);
 glTranslatef(-2,0,0);
 glutSolidCube(1);
 glTranslatef(-2,0,0);
 glutSolidCube(1);
 glTranslatef(-2,0,0);
 glutSolidCube(1);

 glDisable(GL_COLOR_MATERIAL);
 glPopMatrix();

}

void tampil(void){
 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 glClearColor(1,1,1,1);

 glLoadIdentity();
 glTranslatef(0,0,z);
 glRotatef(sudut,x1,y1,z1);
 glScalef(sX, sY, sZ);

 //tembok
 glPushMatrix();
 glEnable(GL_COLOR_MATERIAL);
 glColor3f(0,0.6,0.8);
 glRotatef(50,0,1,0);
 glutSolidCube(3);
 glDisable(GL_COLOR_MATERIAL);
 
 //pagar
 glPushMatrix();
 glTranslatef(-2,0,-3.5);
 pagar();
 glPopMatrix();

 glPushMatrix();
 glRotatef(-90,0,1,0);
 glTranslatef(-2,0,1.5);
 pagar();
 glPopMatrix();

 glPushMatrix();
 glRotatef(-90,0,1,0);
 glTranslatef(-2,0,-3.5);

 pagar();
 glPopMatrix();

 //pintu
 glPushMatrix();
 glEnable(GL_COLOR_MATERIAL);
 glColor3f(0.9,0.2,0.4);
 glTranslatef(-0.6,-1,1.46);
 glScalef(7,10,1);
 glutSolidCube(0.1);
 glDisable(GL_COLOR_MATERIAL);
 glPopMatrix();

 //jendela
 glPushMatrix();
 glEnable(GL_COLOR_MATERIAL);
 glColor3f(0.8,0.8,0.8);
 glTranslatef(0.5,0.1,1.46);
 glScalef(3,3,1);
 glutSolidCube(0.1);
 glDisable(GL_COLOR_MATERIAL);
 glPopMatrix();

 glPushMatrix();
 glEnable(GL_COLOR_MATERIAL);
 glColor3f(0.8,0.8,0.8);
 glTranslatef(0.9,0.1,1.46);
 glScalef(3,3,1);
 glutSolidCube(0.1);
 glDisable(GL_COLOR_MATERIAL);
 glPopMatrix();

 glPushMatrix();
 glEnable(GL_COLOR_MATERIAL);
 glColor3f(0.8,0.8,0.8);
 glTranslatef(0.9,-0.3,1.46);
 glScalef(3,3,1);
 glutSolidCube(0.1);
 glDisable(GL_COLOR_MATERIAL);
 glPopMatrix();

 glPushMatrix();
 glEnable(GL_COLOR_MATERIAL);
 glColor3f(0.8,0.8,0.8);
 glTranslatef(0.5,-0.3,1.46);
 glScalef(3,3,1);
 glutSolidCube(0.1);
 glDisable(GL_COLOR_MATERIAL);
 glPopMatrix();
 glPopMatrix();

 //atap
 glPushMatrix();
 glEnable(GL_COLOR_MATERIAL);
 glColor3f(0.3,0.5,0.8);
 glRotatef(5,0,1,0);
 glTranslatef(0,1.5,0);
 glScalef(3,1.3,3);
 glutSolidOctahedron();
 glDisable(GL_COLOR_MATERIAL);
 glPopMatrix();


 glutSwapBuffers();
}

void ukuran(int w1, int h1){
 glViewport(0,0,w1,h1);
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 gluPerspective(45.0,(float) w1/(float) h1, 1.0,300.0);
 glMatrixMode(GL_MODELVIEW);
 glLoadIdentity();
}

void timer(int value){
 glutPostRedisplay();
 glutTimerFunc(50,timer,0);
}

int main(int argc, char** argv){
 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);
 glutInitWindowPosition(100,100);
 glutInitWindowSize(w,h);
 glutCreateWindow("Natama Wanda Krisdian - 672018201");
 glutDisplayFunc(tampil);
 glutReshapeFunc(ukuran);
 glutKeyboardFunc(keyboard);
 glutMouseFunc(mouse);
 glutMotionFunc(mouseMotion);
 glutTimerFunc(1,timer,0);
 init();
 glutMainLoop();
 return 0;
}
