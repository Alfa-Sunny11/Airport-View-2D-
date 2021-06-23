#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include<math.h>>

# define PI           3.14159265358979323846


GLfloat i = 0.0f;
GLfloat kk=0.0f;


void Idle()
{
    glutPostRedisplay();
}



void update(int value) {



	glutPostRedisplay();


	glutTimerFunc(100,update,0);
}

void Wheel(GLfloat a, GLfloat b, GLfloat rad){
	int g;
	int triangleAmount = 20;
	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);

		glVertex2f(a, b); // center of circle
		glColor3ub(252, 252, 252);
		for(g = 0; g <= triangleAmount;g++) {
			glVertex2f(
		            a + (rad * cos(g *  twicePi / triangleAmount)),
			    b + (rad * sin(g * twicePi / triangleAmount))
			);

		}
	glEnd();
}

void Shape(GLfloat a, GLfloat b, GLfloat rad){
	int g;
	int triangleAmount = 20;
	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);

		glVertex2f(a, b); // center of circle
		glColor3ub(230, 20, 5);
		for(g = 0; g <= triangleAmount;g++) {
			glVertex2f(
		            a + (rad * cos(g *  twicePi / triangleAmount)),
			    b + (rad * sin(g * twicePi / triangleAmount))
			);

		}
	glEnd();
}


void Tree(GLfloat a, GLfloat b, GLfloat rad){
	int j;
	int triangleAmount = 20;
	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(11, 189, 35);

		glVertex2f(a, b); // center of circle
		for(j = 0; j <= triangleAmount;j++) {
			glVertex2f(
		            a + (rad * cos(j *  twicePi / triangleAmount)),
			    b + (rad * sin(j * twicePi / triangleAmount))
			);

		}
	glEnd();
}

void Cloud(GLfloat a, GLfloat b, GLfloat rad){
	int j;
	int triangleAmount = 20;
	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(245, 246, 247);

		glVertex2f(a, b); // center of circle
		for(j = 0; j <= triangleAmount;j++) {
			glVertex2f(
		            a + (rad * cos(j *  twicePi / triangleAmount)),
			    b + (rad * sin(j * twicePi / triangleAmount))
			);

		}
	glEnd();
}

void Wheel1(GLfloat o, GLfloat p, GLfloat rad){
	int k;
	int triangleAmount = 20;
	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(10,10,10);

		glVertex2f(o, p); // center of circle
		for(k = 0; k <= triangleAmount;k++) {
			glVertex2f(
		            o + (rad * cos(k *  twicePi / triangleAmount)),
			    p + (rad * sin(k * twicePi / triangleAmount))
			);

		}
	glEnd();
}

GLfloat position1 = 0.0f;
GLfloat position = 0.0f;
GLfloat position2 = 0.0f;

GLfloat speed1 = 0.02f;
GLfloat speed2 = 0.02f;
GLfloat speed = 0.0f;

void CloudMove(int value) {

    if(position1 <-1.0)
        position1 = 1.0f;
    position1 -= speed1;
	glutPostRedisplay();
	glutTimerFunc(100, CloudMove, 0);
}

void PlaneMove(int value) {

    if(position >1.0)
        position = 0;
    position += speed;
	glutPostRedisplay();
	glutTimerFunc(100, PlaneMove, 0);
}

void Birds(int value) {

    if(position2 >1.0)
        position2 = -1.0f;
    position2 += speed2;
	glutPostRedisplay();
	glutTimerFunc(100, Birds, 0);
}

//Cloud
void handleMouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON){
			speed1 += 0.08f;
			}
			if (button == GLUT_RIGHT_BUTTON)
	{speed1 -= 0.04f;
			}
	glutPostRedisplay();
	}


//Plane
void SpecialInput(int key, int x, int y){
switch(key)
{case GLUT_KEY_UP:
speed=.08;
break;
case GLUT_KEY_DOWN:
speed=.02;
break;
case GLUT_KEY_LEFT:

break;
case GLUT_KEY_RIGHT:
break;}
glutPostRedisplay();}


//Day View
void display() {
	glClearColor(0.5f, 1.0f, 1.0f, 1.0f); // Set background color to black and opaque
	glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)

	glLoadIdentity();
	//background Color
	glBegin(GL_QUADS);
    glColor3ub(78, 220, 245);
    glVertex2f(-1.0f,1.0f);
    glVertex2f(-1.0f,0.1f);
    glVertex2f(1.0f,0.1f);
    glVertex2f(1.0f,1.0f);
    glEnd();

	int t;

	GLfloat x=.8f; GLfloat y=.8f; GLfloat radius =.08f;
    int triangleAmount = 20; //# of triangles used to draw circle

	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(252, 248, 3);
		glVertex2f(x, y); // center of circle
		for(t = 0; t <= triangleAmount;t++) {
			glVertex2f(
		            x + (radius * cos(t *  twicePi / triangleAmount)),
			    y + (radius * sin(t * twicePi / triangleAmount))
			);
		}
	glEnd();


	//sun



		//cloud;

	glPushMatrix();
    glTranslatef(position1,0.0f, 0.0f);
	Cloud(0.5f,0.9f,0.1f);
	Cloud(0.4f,0.8f,0.1f);
	Cloud(0.4f,0.9f,0.1f);
	glPopMatrix();
//Hill;
	glBegin(GL_TRIANGLES);
	glColor3ub(48, 99, 55);
	glVertex2f(-1.0f,0.1f);
	glVertex2f(-0.9f,0.1f);
	glVertex2f(-1.0f,0.3f);

	glVertex2f(-0.9f,0.1f);
	glVertex2f(-0.8f,0.1f);
	glVertex2f(-0.8f,0.3f);

	glVertex2f(1.0f,0.1f);
	glVertex2f(0.9f,0.1f);
	glVertex2f(1.0f,0.3f);

	glVertex2f(0.95f,0.1f);
	glVertex2f(0.8f,0.1f);
	glVertex2f(0.8f,0.3f);

	glEnd();


	glBegin(GL_QUADS);
	//Road;
	glColor3ub(128,128,128);
	glVertex2f(-1.0f,0.1f);
	glVertex2f(-1.0f,-0.8f);
	glVertex2f(1.0f,-0.8f);
	glVertex2f(1.0f,0.1f);

	// building 1;
	glColor3ub(204, 108, 82);
	glVertex2f(-0.8f,0.6f);
	glVertex2f(-0.8f,0.1f);
	glVertex2f(-0.4f,0.1f);
	glVertex2f(-0.4f,0.6f);

	//mid building;
	glColor3ub(153, 207, 72);
	glVertex2f(-0.4f,0.6f);
	glVertex2f(-0.4f,0.1f);
	glVertex2f(0.4f,0.1f);
	glVertex2f(0.4f,0.6f);

	glColor3ub(66, 69, 227);
	glVertex2f(-0.15f,0.2f);
	glVertex2f(0.15f,0.2f);
	glVertex2f(0.15f,0.1f);
	glVertex2f(-0.15f,0.1f);


	//3rd Building;
	glColor3ub(34, 143, 245);
	glVertex2f(0.4f,0.6f);
	glVertex2f(0.4f,0.1f);
	glVertex2f(0.8f,0.1f);
	glVertex2f(0.8f,0.6f);

	//window;
	glColor3ub(166, 171, 227);
	glVertex2f(-0.8f,0.5f);
	glVertex2f(-0.8f,0.4f);
	glVertex2f(0.8f,0.4f);
	glVertex2f(0.8f,0.5f);

	glVertex2f(-0.8f,0.3f);
	glVertex2f(-0.8f,0.2f);
	glVertex2f(0.8f,0.2f);
	glVertex2f(0.8f,0.3f);

	//Grass field;
	glColor3ub(5, 92, 17);
	glVertex2f(-1.0f,-0.8f);
	glVertex2f(-1.0f,-1.0f);
	glVertex2f(1.0f,-1.0f);
	glVertex2f(1.0f,-0.8f);

	//ATC Tower;
	glColor3ub(255, 156, 36);
	glVertex2f(0.7f,-0.9f);
	glVertex2f(0.8f,-0.9f);
	glVertex2f(0.8f,-0.4f);
	glVertex2f(0.7f,-0.4f);

	glColor3ub(189, 121, 40);
	glVertex2f(0.73f,-0.9f);
	glVertex2f(0.77f,-0.9f);
	glVertex2f(0.77f,-0.4f);
	glVertex2f(0.73f,-0.4f);

	glColor3ub(252, 148, 23);
	glVertex2f(0.65f,-0.4f);
	glVertex2f(0.85f,-0.4f);
	glVertex2f(0.85f,-0.38f);
	glVertex2f(0.65f,-0.38f);

	glColor3ub(191, 240, 31);
	glVertex2f(0.68f,-0.38f);
	glVertex2f(0.82f,-0.38f);
	glVertex2f(0.84f,-0.25f);
	glVertex2f(0.66f,-0.25f);

	glColor3ub(208, 212, 197);
	glVertex2f(0.74f,-0.25f);
	glVertex2f(0.76f,-0.25f);
	glVertex2f(0.76f,-0.22f);
	glVertex2f(0.74f,-0.22f);

	glEnd();

	//mid building's top;;
	glBegin(GL_POLYGON);
	glColor3ub(171, 34, 245);
	glVertex2f(-0.1f,0.78f);
	glVertex2f(0.0f,0.8f);
	glVertex2f(-0.15f,0.75f);
	glVertex2f(-0.2f,0.73f);
	glVertex2f(-0.25f,0.7f);
	glVertex2f(-0.3f,0.65f);
	glVertex2f(-0.35f,0.67f);
	glVertex2f(-0.4f,0.6f);
	glVertex2f(0.4f,0.6f);
	glVertex2f(0.1f,0.78f);
	glVertex2f(0.15f,0.75f);
	glVertex2f(0.2f,0.73f);
	glVertex2f(0.25f,0.7f);
	glVertex2f(0.3f,0.65f);
	glVertex2f(0.35f,0.67f);

	glEnd();



	glBegin(GL_LINES);

	glColor3ub(255, 255, 255);

	glVertex2f(-0.9f,-0.15f);
	glVertex2f(-0.85f,-0.15f);

	glVertex2f(-0.9f,-0.4f);
	glVertex2f(-0.85f,-0.4f);

	glVertex2f(-0.9f,-0.65f);
	glVertex2f(-0.85f,-0.65f);

	glVertex2f(-0.7f,-0.15f);
	glVertex2f(-0.65f,-0.15f);

	glVertex2f(-0.7f,-0.4f);
	glVertex2f(-0.65f,-0.4f);

	glVertex2f(-0.7f,-0.65f);
	glVertex2f(-0.65f,-0.65f);

	glVertex2f(-0.5f,-0.15f);
	glVertex2f(-0.45f,-0.15f);

	glVertex2f(-0.5f,-0.4f);
	glVertex2f(-0.45f,-0.4f);

	glVertex2f(-0.5f,-0.65f);
	glVertex2f(-0.45f,-0.65f);

	glVertex2f(-0.3f,-0.15f);
	glVertex2f(-0.25f,-0.15f);

	glVertex2f(-0.3f,-0.4f);
	glVertex2f(-0.25f,-0.4f);

	glVertex2f(-0.3f,-0.65f);
	glVertex2f(-0.25f,-0.65f);

	glVertex2f(-0.1f,-0.15f);
	glVertex2f(-0.05f,-0.15f);

	glVertex2f(-0.1f,-0.4f);
	glVertex2f(-0.05f,-0.4f);

	glVertex2f(-0.1f,-0.65f);
	glVertex2f(-0.05f,-0.65f);

	glVertex2f(0.1f,-0.15f);
	glVertex2f(0.05f,-0.15f);

	glVertex2f(0.1f,-0.4f);
	glVertex2f(0.05f,-0.4f);

	glVertex2f(0.1f,-0.65f);
	glVertex2f(0.05f,-0.65f);

	glVertex2f(0.3f,-0.15f);
	glVertex2f(0.25f,-0.15f);

	glVertex2f(0.3f,-0.4f);
	glVertex2f(0.25f,-0.4f);

	glVertex2f(0.3f,-0.65f);
	glVertex2f(0.25f,-0.65f);

	glVertex2f(0.5f,-0.15f);
	glVertex2f(0.45f,-0.15f);

	glVertex2f(0.5f,-0.4f);
	glVertex2f(0.45f,-0.4f);

	glVertex2f(0.5f,-0.65f);
	glVertex2f(0.45f,-0.65f);

	glVertex2f(0.7f,-0.15f);
	glVertex2f(0.65f,-0.15f);

	glVertex2f(0.7f,-0.4f);
	glVertex2f(0.65f,-0.4f);

	glVertex2f(0.7f,-0.65f);
	glVertex2f(0.65f,-0.65f);

	glVertex2f(0.9f,-0.15f);
	glVertex2f(0.85f,-0.15f);

	glVertex2f(0.9f,-0.4f);
	glVertex2f(0.85f,-0.4f);

	glVertex2f(0.9f,-0.65f);
	glVertex2f(0.85f,-0.65f);

	glEnd();


	glLoadIdentity();
	//Antenna;
	glPushMatrix();
    glTranslatef(0.75f,-0.18f,0.0f);
    glRotatef(i,0.0f,0.5f,0.0f);
	Wheel(0.0f,-0.0f,0.04f);
	glPopMatrix();
    i += 0.1f;

	glLoadIdentity();

	glBegin(GL_QUADS);
	glColor3ub(130, 5, 5);
	glVertex2f(-0.92f,0.1f);
	glVertex2f(-0.89f,0.1f);
	glVertex2f(-0.89f,0.4f);
	glVertex2f(-0.92f,0.4f);
	glEnd();

	glTranslatef(1.82f,0.0f,0.0f);

	glBegin(GL_QUADS);
	glColor3ub(130, 5, 5);
	glVertex2f(-0.92f,0.1f);
	glVertex2f(-0.89f,0.1f);
	glVertex2f(-0.89f,0.4f);
	glVertex2f(-0.92f,0.4f);
	glEnd();

	glLoadIdentity();

	glLoadIdentity();
	glTranslatef(-0.91f,0.4f,0);
	Tree(0,0,0.1f);

	glScalef(0,0.3f,0);

	glLoadIdentity();
	glTranslatef(-0.91f,0.52f,0);
	Tree(0,0,0.05f);

	glLoadIdentity();

    glPushMatrix();
    glTranslatef(0.913f,0.4f,0.0f);
    glRotatef(i,0.0f,0.0f,0.8f);
//wind mile fan;
	glBegin(GL_TRIANGLES);
	glColor3ub(25, 105, 12);
	glVertex2f(0.0f,0.0f);
	glVertex2f(-0.18f,0.12f);
	glVertex2f(-0.2f,0.08f);

	glVertex2f(0.0f,0.0f);
	glVertex2f(0.07f,0.22f);
	glVertex2f(0.12f,0.2f);

	glVertex2f(0.0f,0.0f);
	glVertex2f(-0.05f,-0.2f);
	glVertex2f(-0.0f,-0.2f);

    glEnd();

    glPopMatrix();
    i += 0.2f;



    glTranslatef(position2,0.0f, 0.0f);

	//Birds
	glBegin(GL_QUADS);
	glColor3ub(7, 184, 19);
	glVertex2f(0.0f,0.9f);
	glVertex2f(-0.08f,0.9f);
	glVertex2f(-0.08f,0.88f);
	glVertex2f(-0.0f,0.87f);

	glEnd();

	Tree(0.01f,0.89f,0.02);
	glBegin(GL_TRIANGLES);
	glColor3ub(184, 16, 7);
	glVertex2f(0.02f,0.9f);
	glVertex2f(0.02f,0.88f);
	glVertex2f(0.04f,0.89f);

	glColor3ub(7, 184, 19);
	glVertex2f(0.0f,0.9f);
	glVertex2f(-0.06f,0.92f);
	glVertex2f(-0.07f,0.9f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(7, 184, 19);
	glVertex2f(0.0f,0.95f);
	glVertex2f(-0.08f,0.95f);
	glVertex2f(-0.08f,0.93f);
	glVertex2f(-0.0f,0.93f);

	glEnd();

	Tree(0.01f,0.94f,0.02);
	glBegin(GL_TRIANGLES);
	glColor3ub(184, 16, 7);
	glVertex2f(0.02f,0.95f);
	glVertex2f(0.02f,0.93f);
	glVertex2f(0.04f,0.94f);

	glColor3ub(7, 184, 19);
	glVertex2f(0.0f,0.95f);
	glVertex2f(-0.06f,0.97f);
	glVertex2f(-0.07f,0.95f);

	glEnd();

	glPopMatrix();



	 glLoadIdentity();
	//plane
	glPushMatrix();
    glTranslatef(position,position,0.0f );

    Wheel1(-0.235f,-0.54f,0.01f);
	Wheel1(-0.525f,-0.56f,0.02f);

	glBegin(GL_QUADS);
	glColor3ub(247, 247, 242);
	glVertex2f(-0.6f,-0.4f);
	glVertex2f(-0.58f,-0.52f);
	glVertex2f(-0.2f,-0.42f);
	glVertex2f(-0.22f,-0.28f);

	glVertex2f(-0.28f,-0.3f);
	glVertex2f(-0.36f,-0.2f);
	glVertex2f(-0.39f,-0.22f);
	glVertex2f(-0.34f,-0.38f);

	glVertex2f(-0.26f,-0.4f);
	glVertex2f(-0.34f,-0.45f);
	glVertex2f(-0.4f,-0.65f);
	glVertex2f(-0.32f,-0.6f);

	glVertex2f(-0.62f,-0.34f);
	glVertex2f(-0.64f,-0.35f);
	glVertex2f(-0.62f,-0.48f);
	glVertex2f(-0.58f,-0.44f);

	glEnd();

	//airplane front & back;
	glBegin(GL_TRIANGLES);
	glColor3ub(247, 247, 242);
	glVertex2f(-0.22f,-0.28f);
	glVertex2f(-0.2f,-0.42f);
	glVertex2f(-0.08f,-0.37f);

	glVertex2f(-0.6f,-0.4f);
	glVertex2f(-0.58f,-0.52f);
	glVertex2f(-0.66f,-0.53f);

	glEnd();

	glBegin(GL_LINES);
	//wheel line;
	glColor3ub(10,10,10);
	glVertex2f(-0.25f,-0.44f);
	glVertex2f(-0.24f,-0.54f);

	glVertex2f(-0.24f,-0.44f);
	glVertex2f(-0.23f,-0.54f);

	glVertex2f(-0.52f,-0.5f);
	glVertex2f(-0.52f,-0.56f);

	glVertex2f(-0.53f,-0.5f);
	glVertex2f(-0.53f,-0.56f);
	glEnd();

	glPopMatrix();

	glLoadIdentity();



glPushMatrix();
glScalef(kk,kk, 0.0f);
	glBegin(GL_QUADS);
	glColor3ub(230, 20, 5);
	glVertex2f(0.0f,-0.03f);
	glVertex2f(0.0f,-0.08f);
	glVertex2f(0.08f,-0.08f);
	glVertex2f(0.06f,-0.03f);

glEnd();

glPopMatrix();

	glFlush();  // Render now
}

//evening View
void display1() {
	glClearColor(0.5f, 1.0f, 1.0f, 1.0f); // Set background color to black and opaque
	glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)

	glLoadIdentity();
	//background Color
	glBegin(GL_QUADS);
    glColor3ub(252, 161, 33);
    glVertex2f(1.0f,1.0f);
    glVertex2f(-1.0f,1.0f);
    glColor3ub(245, 208, 479);
    glVertex2f(-1.0f,0.1f);
    glVertex2f(1.0f,0.1f);
    glEnd();

	int t;

	GLfloat x=.85f; GLfloat y=.4f; GLfloat radius =.08f;
    int triangleAmount = 20; //# of triangles used to draw circle

	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(247, 109, 17);
		glVertex2f(x, y); // center of circle
		for(t = 0; t <= triangleAmount;t++) {
			glVertex2f(
		            x + (radius * cos(t *  twicePi / triangleAmount)),
			    y + (radius * sin(t * twicePi / triangleAmount))
			);
		}
	glEnd();


	//sun



		//cloud;

	glPushMatrix();
    glTranslatef(position1,0.0f, 0.0f);
	Cloud(0.5f,0.9f,0.1f);
	Cloud(0.4f,0.8f,0.1f);
	Cloud(0.4f,0.9f,0.1f);
	glPopMatrix();
//Hill;
	glBegin(GL_TRIANGLES);
	glColor3ub(48, 99, 55);
	glVertex2f(-1.0f,0.1f);
	glVertex2f(-0.9f,0.1f);
	glVertex2f(-1.0f,0.3f);

	glVertex2f(-0.9f,0.1f);
	glVertex2f(-0.8f,0.1f);
	glVertex2f(-0.8f,0.3f);

	glVertex2f(1.0f,0.1f);
	glVertex2f(0.9f,0.1f);
	glVertex2f(1.0f,0.3f);

	glVertex2f(0.95f,0.1f);
	glVertex2f(0.8f,0.1f);
	glVertex2f(0.8f,0.3f);

	glEnd();


	glBegin(GL_QUADS);
	//Road;
	glColor3ub(128,128,128);
	glVertex2f(-1.0f,0.1f);
	glVertex2f(-1.0f,-0.8f);
	glVertex2f(1.0f,-0.8f);
	glVertex2f(1.0f,0.1f);

	// building 1;
	glColor3ub(204, 108, 82);
	glVertex2f(-0.8f,0.6f);
	glVertex2f(-0.8f,0.1f);
	glVertex2f(-0.4f,0.1f);
	glVertex2f(-0.4f,0.6f);

	//mid building;
	glColor3ub(153, 207, 72);
	glVertex2f(-0.4f,0.6f);
	glVertex2f(-0.4f,0.1f);
	glVertex2f(0.4f,0.1f);
	glVertex2f(0.4f,0.6f);

	glColor3ub(66, 69, 227);
	glVertex2f(-0.15f,0.2f);
	glVertex2f(0.15f,0.2f);
	glVertex2f(0.15f,0.1f);
	glVertex2f(-0.15f,0.1f);


	//3rd Building;
	glColor3ub(34, 143, 245);
	glVertex2f(0.4f,0.6f);
	glVertex2f(0.4f,0.1f);
	glVertex2f(0.8f,0.1f);
	glVertex2f(0.8f,0.6f);

	//window;
	glColor3ub(166, 171, 227);
	glVertex2f(-0.8f,0.5f);
	glVertex2f(-0.8f,0.4f);
	glVertex2f(0.8f,0.4f);
	glVertex2f(0.8f,0.5f);

	glVertex2f(-0.8f,0.3f);
	glVertex2f(-0.8f,0.2f);
	glVertex2f(0.8f,0.2f);
	glVertex2f(0.8f,0.3f);

	//Grass field;
	glColor3ub(5, 92, 17);
	glVertex2f(-1.0f,-0.8f);
	glVertex2f(-1.0f,-1.0f);
	glVertex2f(1.0f,-1.0f);
	glVertex2f(1.0f,-0.8f);

	//ATC Tower;
	glColor3ub(255, 156, 36);
	glVertex2f(0.7f,-0.9f);
	glVertex2f(0.8f,-0.9f);
	glVertex2f(0.8f,-0.4f);
	glVertex2f(0.7f,-0.4f);

	glColor3ub(189, 121, 40);
	glVertex2f(0.73f,-0.9f);
	glVertex2f(0.77f,-0.9f);
	glVertex2f(0.77f,-0.4f);
	glVertex2f(0.73f,-0.4f);

	glColor3ub(252, 148, 23);
	glVertex2f(0.65f,-0.4f);
	glVertex2f(0.85f,-0.4f);
	glVertex2f(0.85f,-0.38f);
	glVertex2f(0.65f,-0.38f);

	glColor3ub(191, 240, 31);
	glVertex2f(0.68f,-0.38f);
	glVertex2f(0.82f,-0.38f);
	glVertex2f(0.84f,-0.25f);
	glVertex2f(0.66f,-0.25f);

	glColor3ub(208, 212, 197);
	glVertex2f(0.74f,-0.25f);
	glVertex2f(0.76f,-0.25f);
	glVertex2f(0.76f,-0.22f);
	glVertex2f(0.74f,-0.22f);

	glEnd();

	//mid building's top;;
	glBegin(GL_POLYGON);
	glColor3ub(171, 34, 245);
	glVertex2f(-0.1f,0.78f);
	glVertex2f(0.0f,0.8f);
	glVertex2f(-0.15f,0.75f);
	glVertex2f(-0.2f,0.73f);
	glVertex2f(-0.25f,0.7f);
	glVertex2f(-0.3f,0.65f);
	glVertex2f(-0.35f,0.67f);
	glVertex2f(-0.4f,0.6f);
	glVertex2f(0.4f,0.6f);
	glVertex2f(0.1f,0.78f);
	glVertex2f(0.15f,0.75f);
	glVertex2f(0.2f,0.73f);
	glVertex2f(0.25f,0.7f);
	glVertex2f(0.3f,0.65f);
	glVertex2f(0.35f,0.67f);

	glEnd();



	glBegin(GL_LINES);

	glColor3ub(255, 255, 255);

	glVertex2f(-0.9f,-0.15f);
	glVertex2f(-0.85f,-0.15f);

	glVertex2f(-0.9f,-0.4f);
	glVertex2f(-0.85f,-0.4f);

	glVertex2f(-0.9f,-0.65f);
	glVertex2f(-0.85f,-0.65f);

	glVertex2f(-0.7f,-0.15f);
	glVertex2f(-0.65f,-0.15f);

	glVertex2f(-0.7f,-0.4f);
	glVertex2f(-0.65f,-0.4f);

	glVertex2f(-0.7f,-0.65f);
	glVertex2f(-0.65f,-0.65f);

	glVertex2f(-0.5f,-0.15f);
	glVertex2f(-0.45f,-0.15f);

	glVertex2f(-0.5f,-0.4f);
	glVertex2f(-0.45f,-0.4f);

	glVertex2f(-0.5f,-0.65f);
	glVertex2f(-0.45f,-0.65f);

	glVertex2f(-0.3f,-0.15f);
	glVertex2f(-0.25f,-0.15f);

	glVertex2f(-0.3f,-0.4f);
	glVertex2f(-0.25f,-0.4f);

	glVertex2f(-0.3f,-0.65f);
	glVertex2f(-0.25f,-0.65f);

	glVertex2f(-0.1f,-0.15f);
	glVertex2f(-0.05f,-0.15f);

	glVertex2f(-0.1f,-0.4f);
	glVertex2f(-0.05f,-0.4f);

	glVertex2f(-0.1f,-0.65f);
	glVertex2f(-0.05f,-0.65f);

	glVertex2f(0.1f,-0.15f);
	glVertex2f(0.05f,-0.15f);

	glVertex2f(0.1f,-0.4f);
	glVertex2f(0.05f,-0.4f);

	glVertex2f(0.1f,-0.65f);
	glVertex2f(0.05f,-0.65f);

	glVertex2f(0.3f,-0.15f);
	glVertex2f(0.25f,-0.15f);

	glVertex2f(0.3f,-0.4f);
	glVertex2f(0.25f,-0.4f);

	glVertex2f(0.3f,-0.65f);
	glVertex2f(0.25f,-0.65f);

	glVertex2f(0.5f,-0.15f);
	glVertex2f(0.45f,-0.15f);

	glVertex2f(0.5f,-0.4f);
	glVertex2f(0.45f,-0.4f);

	glVertex2f(0.5f,-0.65f);
	glVertex2f(0.45f,-0.65f);

	glVertex2f(0.7f,-0.15f);
	glVertex2f(0.65f,-0.15f);

	glVertex2f(0.7f,-0.4f);
	glVertex2f(0.65f,-0.4f);

	glVertex2f(0.7f,-0.65f);
	glVertex2f(0.65f,-0.65f);

	glVertex2f(0.9f,-0.15f);
	glVertex2f(0.85f,-0.15f);

	glVertex2f(0.9f,-0.4f);
	glVertex2f(0.85f,-0.4f);

	glVertex2f(0.9f,-0.65f);
	glVertex2f(0.85f,-0.65f);

	glEnd();


	glLoadIdentity();
	//Antenna;
	glPushMatrix();
    glTranslatef(0.75f,-0.18f,0.0f);
    glRotatef(i,0.0f,0.5f,0.0f);
	Wheel(0.0f,-0.0f,0.04f);
	glPopMatrix();
    i += 0.1f;

	glLoadIdentity();

	glBegin(GL_QUADS);
	glColor3ub(130, 5, 5);
	glVertex2f(-0.92f,0.1f);
	glVertex2f(-0.89f,0.1f);
	glVertex2f(-0.89f,0.4f);
	glVertex2f(-0.92f,0.4f);
	glEnd();

	glTranslatef(1.82f,0.0f,0.0f);

	glBegin(GL_QUADS);
	glColor3ub(130, 5, 5);
	glVertex2f(-0.92f,0.1f);
	glVertex2f(-0.89f,0.1f);
	glVertex2f(-0.89f,0.4f);
	glVertex2f(-0.92f,0.4f);
	glEnd();

	glLoadIdentity();

	glLoadIdentity();
	glTranslatef(-0.91f,0.4f,0);
	Tree(0,0,0.1f);

	glScalef(0,0.3f,0);

	glLoadIdentity();
	glTranslatef(-0.91f,0.52f,0);
	Tree(0,0,0.05f);

	glLoadIdentity();

    glPushMatrix();
    glTranslatef(0.913f,0.4f,0.0f);
    glRotatef(i,0.0f,0.0f,0.8f);
//wind mile fan;
	glBegin(GL_TRIANGLES);
	glColor3ub(25, 105, 12);
	glVertex2f(0.0f,0.0f);
	glVertex2f(-0.18f,0.12f);
	glVertex2f(-0.2f,0.08f);

	glVertex2f(0.0f,0.0f);
	glVertex2f(0.07f,0.22f);
	glVertex2f(0.12f,0.2f);

	glVertex2f(0.0f,0.0f);
	glVertex2f(-0.05f,-0.2f);
	glVertex2f(-0.0f,-0.2f);

    glEnd();

    glPopMatrix();
    i += 0.2f;



    glTranslatef(position2,0.0f, 0.0f);

	//Birds
	glBegin(GL_QUADS);
	glColor3ub(7, 184, 19);
	glVertex2f(0.0f,0.9f);
	glVertex2f(-0.08f,0.9f);
	glVertex2f(-0.08f,0.88f);
	glVertex2f(-0.0f,0.87f);

	glEnd();

	Tree(0.01f,0.89f,0.02);
	glBegin(GL_TRIANGLES);
	glColor3ub(184, 16, 7);
	glVertex2f(0.02f,0.9f);
	glVertex2f(0.02f,0.88f);
	glVertex2f(0.04f,0.89f);

	glColor3ub(7, 184, 19);
	glVertex2f(0.0f,0.9f);
	glVertex2f(-0.06f,0.92f);
	glVertex2f(-0.07f,0.9f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(7, 184, 19);
	glVertex2f(0.0f,0.95f);
	glVertex2f(-0.08f,0.95f);
	glVertex2f(-0.08f,0.93f);
	glVertex2f(-0.0f,0.93f);

	glEnd();

	Tree(0.01f,0.94f,0.02);
	glBegin(GL_TRIANGLES);
	glColor3ub(184, 16, 7);
	glVertex2f(0.02f,0.95f);
	glVertex2f(0.02f,0.93f);
	glVertex2f(0.04f,0.94f);

	glColor3ub(7, 184, 19);
	glVertex2f(0.0f,0.95f);
	glVertex2f(-0.06f,0.97f);
	glVertex2f(-0.07f,0.95f);

	glEnd();

	glPopMatrix();

	 glLoadIdentity();
	//plane
	glPushMatrix();
    glTranslatef(position,position,0.0f );

    Wheel1(-0.235f,-0.54f,0.01f);
	Wheel1(-0.525f,-0.56f,0.02f);

	glBegin(GL_QUADS);
	glColor3ub(247, 247, 242);
	glVertex2f(-0.6f,-0.4f);
	glVertex2f(-0.58f,-0.52f);
	glVertex2f(-0.2f,-0.42f);
	glVertex2f(-0.22f,-0.28f);

	glVertex2f(-0.28f,-0.3f);
	glVertex2f(-0.36f,-0.2f);
	glVertex2f(-0.39f,-0.22f);
	glVertex2f(-0.34f,-0.38f);

	glVertex2f(-0.26f,-0.4f);
	glVertex2f(-0.34f,-0.45f);
	glVertex2f(-0.4f,-0.65f);
	glVertex2f(-0.32f,-0.6f);

	glVertex2f(-0.62f,-0.34f);
	glVertex2f(-0.64f,-0.35f);
	glVertex2f(-0.62f,-0.48f);
	glVertex2f(-0.58f,-0.44f);

	glEnd();

	//airplane front & back;
	glBegin(GL_TRIANGLES);
	glColor3ub(247, 247, 242);
	glVertex2f(-0.22f,-0.28f);
	glVertex2f(-0.2f,-0.42f);
	glVertex2f(-0.08f,-0.37f);

	glVertex2f(-0.6f,-0.4f);
	glVertex2f(-0.58f,-0.52f);
	glVertex2f(-0.66f,-0.53f);

	glEnd();

	glBegin(GL_LINES);
	//wheel line;
	glColor3ub(10,10,10);
	glVertex2f(-0.25f,-0.44f);
	glVertex2f(-0.24f,-0.54f);

	glVertex2f(-0.24f,-0.44f);
	glVertex2f(-0.23f,-0.54f);

	glVertex2f(-0.52f,-0.5f);
	glVertex2f(-0.52f,-0.56f);

	glVertex2f(-0.53f,-0.5f);
	glVertex2f(-0.53f,-0.56f);
	glEnd();

	glPopMatrix();

	glLoadIdentity();




	glLoadIdentity();

	glPushMatrix();

	glPushMatrix();
glScalef(kk,kk, 0.0f);
	glBegin(GL_QUADS);
	glColor3ub(230, 20, 5);
	glVertex2f(0.0f,-0.03f);
	glVertex2f(0.0f,-0.08f);
	glVertex2f(0.08f,-0.08f);
	glVertex2f(0.06f,-0.03f);

glEnd();

glPopMatrix();

	glFlush();  // Render now
}

//morning View
void display2() {
	glClearColor(0.5f, 1.0f, 1.0f, 1.0f); // Set background color to black and opaque
	glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)

	glLoadIdentity();

		//background Color
	glBegin(GL_QUADS);
    glColor3ub(209, 228, 235);
    glVertex2f(-1.0f,1.0f);
    glVertex2f(-1.0f,0.1f);
    glVertex2f(1.0f,0.1f);
    glVertex2f(1.0f,1.0f);
    glEnd();

	int t;

	GLfloat x=.8f; GLfloat y=.8f; GLfloat radius =.08f;
    int triangleAmount = 20; //# of triangles used to draw circle

	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(240, 228, 14);
		glVertex2f(x, y); // center of circle
		for(t = 0; t <= triangleAmount;t++) {
			glVertex2f(
		            x + (radius * cos(t *  twicePi / triangleAmount)),
			    y + (radius * sin(t * twicePi / triangleAmount))
			);
		}
	glEnd();




//Hill;
	glBegin(GL_TRIANGLES);
	glColor3ub(48, 99, 55);
	glVertex2f(-1.0f,0.1f);
	glVertex2f(-0.9f,0.1f);
	glVertex2f(-1.0f,0.3f);

	glVertex2f(-0.9f,0.1f);
	glVertex2f(-0.8f,0.1f);
	glVertex2f(-0.8f,0.3f);

	glVertex2f(1.0f,0.1f);
	glVertex2f(0.9f,0.1f);
	glVertex2f(1.0f,0.3f);

	glVertex2f(0.95f,0.1f);
	glVertex2f(0.8f,0.1f);
	glVertex2f(0.8f,0.3f);

	glEnd();


	glBegin(GL_QUADS);
	//Road;
	glColor3ub(128,128,128);
	glVertex2f(-1.0f,0.1f);
	glVertex2f(-1.0f,-0.8f);
	glVertex2f(1.0f,-0.8f);
	glVertex2f(1.0f,0.1f);

	// building 1;
	glColor3ub(204, 108, 82);
	glVertex2f(-0.8f,0.6f);
	glVertex2f(-0.8f,0.1f);
	glVertex2f(-0.4f,0.1f);
	glVertex2f(-0.4f,0.6f);

	//mid building;
	glColor3ub(153, 207, 72);
	glVertex2f(-0.4f,0.6f);
	glVertex2f(-0.4f,0.1f);
	glVertex2f(0.4f,0.1f);
	glVertex2f(0.4f,0.6f);

	glColor3ub(66, 69, 227);
	glVertex2f(-0.15f,0.2f);
	glVertex2f(0.15f,0.2f);
	glVertex2f(0.15f,0.1f);
	glVertex2f(-0.15f,0.1f);


	//3rd Building;
	glColor3ub(34, 143, 245);
	glVertex2f(0.4f,0.6f);
	glVertex2f(0.4f,0.1f);
	glVertex2f(0.8f,0.1f);
	glVertex2f(0.8f,0.6f);

	//window;
	glColor3ub(166, 171, 227);
	glVertex2f(-0.8f,0.5f);
	glVertex2f(-0.8f,0.4f);
	glVertex2f(0.8f,0.4f);
	glVertex2f(0.8f,0.5f);

	glVertex2f(-0.8f,0.3f);
	glVertex2f(-0.8f,0.2f);
	glVertex2f(0.8f,0.2f);
	glVertex2f(0.8f,0.3f);

	//Grass field;
	glColor3ub(5, 92, 17);
	glVertex2f(-1.0f,-0.8f);
	glVertex2f(-1.0f,-1.0f);
	glVertex2f(1.0f,-1.0f);
	glVertex2f(1.0f,-0.8f);

	//ATC Tower;
	glColor3ub(255, 156, 36);
	glVertex2f(0.7f,-0.9f);
	glVertex2f(0.8f,-0.9f);
	glVertex2f(0.8f,-0.4f);
	glVertex2f(0.7f,-0.4f);

	glColor3ub(189, 121, 40);
	glVertex2f(0.73f,-0.9f);
	glVertex2f(0.77f,-0.9f);
	glVertex2f(0.77f,-0.4f);
	glVertex2f(0.73f,-0.4f);

	glColor3ub(252, 148, 23);
	glVertex2f(0.65f,-0.4f);
	glVertex2f(0.85f,-0.4f);
	glVertex2f(0.85f,-0.38f);
	glVertex2f(0.65f,-0.38f);

	glColor3ub(191, 240, 31);
	glVertex2f(0.68f,-0.38f);
	glVertex2f(0.82f,-0.38f);
	glVertex2f(0.84f,-0.25f);
	glVertex2f(0.66f,-0.25f);

	glColor3ub(208, 212, 197);
	glVertex2f(0.74f,-0.25f);
	glVertex2f(0.76f,-0.25f);
	glVertex2f(0.76f,-0.22f);
	glVertex2f(0.74f,-0.22f);

	glEnd();

	//mid building's top;;
	glBegin(GL_POLYGON);
	glColor3ub(171, 34, 245);
	glVertex2f(-0.1f,0.78f);
	glVertex2f(0.0f,0.8f);
	glVertex2f(-0.15f,0.75f);
	glVertex2f(-0.2f,0.73f);
	glVertex2f(-0.25f,0.7f);
	glVertex2f(-0.3f,0.65f);
	glVertex2f(-0.35f,0.67f);
	glVertex2f(-0.4f,0.6f);
	glVertex2f(0.4f,0.6f);
	glVertex2f(0.1f,0.78f);
	glVertex2f(0.15f,0.75f);
	glVertex2f(0.2f,0.73f);
	glVertex2f(0.25f,0.7f);
	glVertex2f(0.3f,0.65f);
	glVertex2f(0.35f,0.67f);

	glEnd();



	glBegin(GL_LINES);

	glColor3ub(255, 255, 255);

	glVertex2f(-0.9f,-0.15f);
	glVertex2f(-0.85f,-0.15f);

	glVertex2f(-0.9f,-0.4f);
	glVertex2f(-0.85f,-0.4f);

	glVertex2f(-0.9f,-0.65f);
	glVertex2f(-0.85f,-0.65f);

	glVertex2f(-0.7f,-0.15f);
	glVertex2f(-0.65f,-0.15f);

	glVertex2f(-0.7f,-0.4f);
	glVertex2f(-0.65f,-0.4f);

	glVertex2f(-0.7f,-0.65f);
	glVertex2f(-0.65f,-0.65f);

	glVertex2f(-0.5f,-0.15f);
	glVertex2f(-0.45f,-0.15f);

	glVertex2f(-0.5f,-0.4f);
	glVertex2f(-0.45f,-0.4f);

	glVertex2f(-0.5f,-0.65f);
	glVertex2f(-0.45f,-0.65f);

	glVertex2f(-0.3f,-0.15f);
	glVertex2f(-0.25f,-0.15f);

	glVertex2f(-0.3f,-0.4f);
	glVertex2f(-0.25f,-0.4f);

	glVertex2f(-0.3f,-0.65f);
	glVertex2f(-0.25f,-0.65f);

	glVertex2f(-0.1f,-0.15f);
	glVertex2f(-0.05f,-0.15f);

	glVertex2f(-0.1f,-0.4f);
	glVertex2f(-0.05f,-0.4f);

	glVertex2f(-0.1f,-0.65f);
	glVertex2f(-0.05f,-0.65f);

	glVertex2f(0.1f,-0.15f);
	glVertex2f(0.05f,-0.15f);

	glVertex2f(0.1f,-0.4f);
	glVertex2f(0.05f,-0.4f);

	glVertex2f(0.1f,-0.65f);
	glVertex2f(0.05f,-0.65f);

	glVertex2f(0.3f,-0.15f);
	glVertex2f(0.25f,-0.15f);

	glVertex2f(0.3f,-0.4f);
	glVertex2f(0.25f,-0.4f);

	glVertex2f(0.3f,-0.65f);
	glVertex2f(0.25f,-0.65f);

	glVertex2f(0.5f,-0.15f);
	glVertex2f(0.45f,-0.15f);

	glVertex2f(0.5f,-0.4f);
	glVertex2f(0.45f,-0.4f);

	glVertex2f(0.5f,-0.65f);
	glVertex2f(0.45f,-0.65f);

	glVertex2f(0.7f,-0.15f);
	glVertex2f(0.65f,-0.15f);

	glVertex2f(0.7f,-0.4f);
	glVertex2f(0.65f,-0.4f);

	glVertex2f(0.7f,-0.65f);
	glVertex2f(0.65f,-0.65f);

	glVertex2f(0.9f,-0.15f);
	glVertex2f(0.85f,-0.15f);

	glVertex2f(0.9f,-0.4f);
	glVertex2f(0.85f,-0.4f);

	glVertex2f(0.9f,-0.65f);
	glVertex2f(0.85f,-0.65f);

	glEnd();


	glLoadIdentity();
	//Antenna;
	glPushMatrix();
    glTranslatef(0.75f,-0.18f,0.0f);
    glRotatef(i,0.0f,0.5f,0.0f);
	Wheel(0.0f,-0.0f,0.04f);
	glPopMatrix();
    i += 0.1f;

	glLoadIdentity();

	glBegin(GL_QUADS);
	glColor3ub(130, 5, 5);
	glVertex2f(-0.92f,0.1f);
	glVertex2f(-0.89f,0.1f);
	glVertex2f(-0.89f,0.4f);
	glVertex2f(-0.92f,0.4f);
	glEnd();

	glTranslatef(1.82f,0.0f,0.0f);

	glBegin(GL_QUADS);
	glColor3ub(130, 5, 5);
	glVertex2f(-0.92f,0.1f);
	glVertex2f(-0.89f,0.1f);
	glVertex2f(-0.89f,0.4f);
	glVertex2f(-0.92f,0.4f);
	glEnd();

	glLoadIdentity();

	glLoadIdentity();
	glTranslatef(-0.91f,0.4f,0);
	Tree(0,0,0.1f);

	glScalef(0,0.3f,0);

	glLoadIdentity();
	glTranslatef(-0.91f,0.52f,0);
	Tree(0,0,0.05f);

	glLoadIdentity();

    glPushMatrix();
    glTranslatef(0.913f,0.4f,0.0f);
    glRotatef(i,0.0f,0.0f,0.8f);
//wind mile fan;
	glBegin(GL_TRIANGLES);
	glColor3ub(25, 105, 12);
	glVertex2f(0.0f,0.0f);
	glVertex2f(-0.18f,0.12f);
	glVertex2f(-0.2f,0.08f);

	glVertex2f(0.0f,0.0f);
	glVertex2f(0.07f,0.22f);
	glVertex2f(0.12f,0.2f);

	glVertex2f(0.0f,0.0f);
	glVertex2f(-0.05f,-0.2f);
	glVertex2f(-0.0f,-0.2f);

    glEnd();

    glPopMatrix();
    i += 0.2f;



    glTranslatef(position2,0.0f, 0.0f);

	//Birds
	glBegin(GL_QUADS);
	glColor3ub(7, 184, 19);
	glVertex2f(0.0f,0.9f);
	glVertex2f(-0.08f,0.9f);
	glVertex2f(-0.08f,0.88f);
	glVertex2f(-0.0f,0.87f);

	glEnd();

	Tree(0.01f,0.89f,0.02);
	glBegin(GL_TRIANGLES);
	glColor3ub(184, 16, 7);
	glVertex2f(0.02f,0.9f);
	glVertex2f(0.02f,0.88f);
	glVertex2f(0.04f,0.89f);

	glColor3ub(7, 184, 19);
	glVertex2f(0.0f,0.9f);
	glVertex2f(-0.06f,0.92f);
	glVertex2f(-0.07f,0.9f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(7, 184, 19);
	glVertex2f(0.0f,0.95f);
	glVertex2f(-0.08f,0.95f);
	glVertex2f(-0.08f,0.93f);
	glVertex2f(-0.0f,0.93f);

	glEnd();

	Tree(0.01f,0.94f,0.02);
	glBegin(GL_TRIANGLES);
	glColor3ub(184, 16, 7);
	glVertex2f(0.02f,0.95f);
	glVertex2f(0.02f,0.93f);
	glVertex2f(0.04f,0.94f);

	glColor3ub(7, 184, 19);
	glVertex2f(0.0f,0.95f);
	glVertex2f(-0.06f,0.97f);
	glVertex2f(-0.07f,0.95f);

	glEnd();

	glPopMatrix();

	 glLoadIdentity();
	//plane
	glPushMatrix();
    glTranslatef(position,position,0.0f );

    Wheel1(-0.235f,-0.54f,0.01f);
	Wheel1(-0.525f,-0.56f,0.02f);

	glBegin(GL_QUADS);
	glColor3ub(247, 247, 242);
	glVertex2f(-0.6f,-0.4f);
	glVertex2f(-0.58f,-0.52f);
	glVertex2f(-0.2f,-0.42f);
	glVertex2f(-0.22f,-0.28f);

	glVertex2f(-0.28f,-0.3f);
	glVertex2f(-0.36f,-0.2f);
	glVertex2f(-0.39f,-0.22f);
	glVertex2f(-0.34f,-0.38f);

	glVertex2f(-0.26f,-0.4f);
	glVertex2f(-0.34f,-0.45f);
	glVertex2f(-0.4f,-0.65f);
	glVertex2f(-0.32f,-0.6f);

	glVertex2f(-0.62f,-0.34f);
	glVertex2f(-0.64f,-0.35f);
	glVertex2f(-0.62f,-0.48f);
	glVertex2f(-0.58f,-0.44f);

	glEnd();

	//airplane front & back;
	glBegin(GL_TRIANGLES);
	glColor3ub(247, 247, 242);
	glVertex2f(-0.22f,-0.28f);
	glVertex2f(-0.2f,-0.42f);
	glVertex2f(-0.08f,-0.37f);

	glVertex2f(-0.6f,-0.4f);
	glVertex2f(-0.58f,-0.52f);
	glVertex2f(-0.66f,-0.53f);

	glEnd();

	glBegin(GL_LINES);
	//wheel line;
	glColor3ub(10,10,10);
	glVertex2f(-0.25f,-0.44f);
	glVertex2f(-0.24f,-0.54f);

	glVertex2f(-0.24f,-0.44f);
	glVertex2f(-0.23f,-0.54f);

	glVertex2f(-0.52f,-0.5f);
	glVertex2f(-0.52f,-0.56f);

	glVertex2f(-0.53f,-0.5f);
	glVertex2f(-0.53f,-0.56f);
	glEnd();

	glPopMatrix();

	glLoadIdentity();




	glLoadIdentity();

	glPushMatrix();

		glPushMatrix();
glScalef(kk,kk, 0.0f);
	glBegin(GL_QUADS);
	glColor3ub(230, 20, 5);
	glVertex2f(0.0f,-0.03f);
	glVertex2f(0.0f,-0.08f);
	glVertex2f(0.08f,-0.08f);
	glVertex2f(0.06f,-0.03f);

glEnd();

glPopMatrix();


	glFlush();  // Render now
}

//Night View
void display3() {
	glClearColor(0.5f, 1.0f, 1.0f, 1.0f); // Set background color to black and opaque
	glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)

	glLoadIdentity();
	//background Color
	glBegin(GL_QUADS);
    glColor3ub(8, 8, 8);
    glVertex2f(1.0f,1.0f);
    glVertex2f(-1.0f,1.0f);
    glVertex2f(-1.0f,0.1f);
    glVertex2f(1.0f,0.1f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(247, 245, 245);
    glVertex2f(-0.9,0.9);
    glVertex2f(-0.9,0.89);

    glVertex2f(-0.85,0.9);
    glVertex2f(-0.85,0.89);

    glVertex2f(-0.75,0.8);
    glVertex2f(-0.75,0.79);

    glVertex2f(-0.8,0.75);
    glVertex2f(-0.8,0.74);

    glVertex2f(-0.85,0.8);
    glVertex2f(-0.85,0.79);

    glVertex2f(-0.75,0.75);
    glVertex2f(-0.75,0.74);

    glVertex2f(-0.55,0.8);
    glVertex2f(-0.55,0.79);

    glVertex2f(-0.45,0.9);
    glVertex2f(-0.45,0.89);

    glVertex2f(-0.50,0.9);
    glVertex2f(-0.5,0.89);

    glVertex2f(-0.4,0.8);
    glVertex2f(-0.4,0.79);

    glVertex2f(-0.35,0.75);
    glVertex2f(-0.35,0.74);

    glVertex2f(-0.37,0.8);
    glVertex2f(-0.37,0.79);

    glEnd();

	int t;

	GLfloat x=.85f; GLfloat y=.8f; GLfloat radius =.08f;
    int triangleAmount = 20; //# of triangles used to draw circle

	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(250, 252, 252);
		glVertex2f(x, y); // center of circle
		for(t = 0; t <= triangleAmount;t++) {
			glVertex2f(
		            x + (radius * cos(t *  twicePi / triangleAmount)),
			    y + (radius * sin(t * twicePi / triangleAmount))
			);
		}
	glEnd();


	//sun



		//cloud;

	glPushMatrix();
    glTranslatef(position1,0.0f, 0.0f);
	Cloud(0.5f,0.9f,0.1f);
	Cloud(0.4f,0.8f,0.1f);
	Cloud(0.4f,0.9f,0.1f);
	glPopMatrix();
//Hill;
	glBegin(GL_TRIANGLES);
	glColor3ub(48, 99, 55);
	glVertex2f(-1.0f,0.1f);
	glVertex2f(-0.9f,0.1f);
	glVertex2f(-1.0f,0.3f);

	glVertex2f(-0.9f,0.1f);
	glVertex2f(-0.8f,0.1f);
	glVertex2f(-0.8f,0.3f);

	glVertex2f(1.0f,0.1f);
	glVertex2f(0.9f,0.1f);
	glVertex2f(1.0f,0.3f);

	glVertex2f(0.95f,0.1f);
	glVertex2f(0.8f,0.1f);
	glVertex2f(0.8f,0.3f);

	glEnd();


	glBegin(GL_QUADS);
	//Road;
	glColor3ub(128,128,128);
	glVertex2f(-1.0f,0.1f);
	glVertex2f(-1.0f,-0.8f);
	glVertex2f(1.0f,-0.8f);
	glVertex2f(1.0f,0.1f);

	// building 1;
	glColor3ub(204, 108, 82);
	glVertex2f(-0.8f,0.6f);
	glVertex2f(-0.8f,0.1f);
	glVertex2f(-0.4f,0.1f);
	glVertex2f(-0.4f,0.6f);

	//mid building;
	glColor3ub(153, 207, 72);
	glVertex2f(-0.4f,0.6f);
	glVertex2f(-0.4f,0.1f);
	glVertex2f(0.4f,0.1f);
	glVertex2f(0.4f,0.6f);

	glColor3ub(66, 69, 227);
	glVertex2f(-0.15f,0.2f);
	glVertex2f(0.15f,0.2f);
	glVertex2f(0.15f,0.1f);
	glVertex2f(-0.15f,0.1f);


	//3rd Building;
	glColor3ub(34, 143, 245);
	glVertex2f(0.4f,0.6f);
	glVertex2f(0.4f,0.1f);
	glVertex2f(0.8f,0.1f);
	glVertex2f(0.8f,0.6f);

	//window;
	glColor3ub(166, 171, 227);
	glVertex2f(-0.8f,0.5f);
	glVertex2f(-0.8f,0.4f);
	glVertex2f(0.8f,0.4f);
	glVertex2f(0.8f,0.5f);

	glVertex2f(-0.8f,0.3f);
	glVertex2f(-0.8f,0.2f);
	glVertex2f(0.8f,0.2f);
	glVertex2f(0.8f,0.3f);

	//Grass field;
	glColor3ub(5, 92, 17);
	glVertex2f(-1.0f,-0.8f);
	glVertex2f(-1.0f,-1.0f);
	glVertex2f(1.0f,-1.0f);
	glVertex2f(1.0f,-0.8f);

	//ATC Tower;
	glColor3ub(255, 156, 36);
	glVertex2f(0.7f,-0.9f);
	glVertex2f(0.8f,-0.9f);
	glVertex2f(0.8f,-0.4f);
	glVertex2f(0.7f,-0.4f);

	glColor3ub(189, 121, 40);
	glVertex2f(0.73f,-0.9f);
	glVertex2f(0.77f,-0.9f);
	glVertex2f(0.77f,-0.4f);
	glVertex2f(0.73f,-0.4f);

	glColor3ub(252, 148, 23);
	glVertex2f(0.65f,-0.4f);
	glVertex2f(0.85f,-0.4f);
	glVertex2f(0.85f,-0.38f);
	glVertex2f(0.65f,-0.38f);

	glColor3ub(191, 240, 31);
	glVertex2f(0.68f,-0.38f);
	glVertex2f(0.82f,-0.38f);
	glVertex2f(0.84f,-0.25f);
	glVertex2f(0.66f,-0.25f);

	glColor3ub(208, 212, 197);
	glVertex2f(0.74f,-0.25f);
	glVertex2f(0.76f,-0.25f);
	glVertex2f(0.76f,-0.22f);
	glVertex2f(0.74f,-0.22f);

	glEnd();

	//mid building's top;;
	glBegin(GL_POLYGON);
	glColor3ub(171, 34, 245);
	glVertex2f(-0.1f,0.78f);
	glVertex2f(0.0f,0.8f);
	glVertex2f(-0.15f,0.75f);
	glVertex2f(-0.2f,0.73f);
	glVertex2f(-0.25f,0.7f);
	glVertex2f(-0.3f,0.65f);
	glVertex2f(-0.35f,0.67f);
	glVertex2f(-0.4f,0.6f);
	glVertex2f(0.4f,0.6f);
	glVertex2f(0.1f,0.78f);
	glVertex2f(0.15f,0.75f);
	glVertex2f(0.2f,0.73f);
	glVertex2f(0.25f,0.7f);
	glVertex2f(0.3f,0.65f);
	glVertex2f(0.35f,0.67f);

	glEnd();



	glBegin(GL_LINES);

	glColor3ub(255, 255, 255);

	glVertex2f(-0.9f,-0.15f);
	glVertex2f(-0.85f,-0.15f);

	glVertex2f(-0.9f,-0.4f);
	glVertex2f(-0.85f,-0.4f);

	glVertex2f(-0.9f,-0.65f);
	glVertex2f(-0.85f,-0.65f);

	glVertex2f(-0.7f,-0.15f);
	glVertex2f(-0.65f,-0.15f);

	glVertex2f(-0.7f,-0.4f);
	glVertex2f(-0.65f,-0.4f);

	glVertex2f(-0.7f,-0.65f);
	glVertex2f(-0.65f,-0.65f);

	glVertex2f(-0.5f,-0.15f);
	glVertex2f(-0.45f,-0.15f);

	glVertex2f(-0.5f,-0.4f);
	glVertex2f(-0.45f,-0.4f);

	glVertex2f(-0.5f,-0.65f);
	glVertex2f(-0.45f,-0.65f);

	glVertex2f(-0.3f,-0.15f);
	glVertex2f(-0.25f,-0.15f);

	glVertex2f(-0.3f,-0.4f);
	glVertex2f(-0.25f,-0.4f);

	glVertex2f(-0.3f,-0.65f);
	glVertex2f(-0.25f,-0.65f);

	glVertex2f(-0.1f,-0.15f);
	glVertex2f(-0.05f,-0.15f);

	glVertex2f(-0.1f,-0.4f);
	glVertex2f(-0.05f,-0.4f);

	glVertex2f(-0.1f,-0.65f);
	glVertex2f(-0.05f,-0.65f);

	glVertex2f(0.1f,-0.15f);
	glVertex2f(0.05f,-0.15f);

	glVertex2f(0.1f,-0.4f);
	glVertex2f(0.05f,-0.4f);

	glVertex2f(0.1f,-0.65f);
	glVertex2f(0.05f,-0.65f);

	glVertex2f(0.3f,-0.15f);
	glVertex2f(0.25f,-0.15f);

	glVertex2f(0.3f,-0.4f);
	glVertex2f(0.25f,-0.4f);

	glVertex2f(0.3f,-0.65f);
	glVertex2f(0.25f,-0.65f);

	glVertex2f(0.5f,-0.15f);
	glVertex2f(0.45f,-0.15f);

	glVertex2f(0.5f,-0.4f);
	glVertex2f(0.45f,-0.4f);

	glVertex2f(0.5f,-0.65f);
	glVertex2f(0.45f,-0.65f);

	glVertex2f(0.7f,-0.15f);
	glVertex2f(0.65f,-0.15f);

	glVertex2f(0.7f,-0.4f);
	glVertex2f(0.65f,-0.4f);

	glVertex2f(0.7f,-0.65f);
	glVertex2f(0.65f,-0.65f);

	glVertex2f(0.9f,-0.15f);
	glVertex2f(0.85f,-0.15f);

	glVertex2f(0.9f,-0.4f);
	glVertex2f(0.85f,-0.4f);

	glVertex2f(0.9f,-0.65f);
	glVertex2f(0.85f,-0.65f);

	glEnd();


	glLoadIdentity();
	//Antenna;
	glPushMatrix();
    glTranslatef(0.75f,-0.18f,0.0f);
    glRotatef(i,0.0f,0.5f,0.0f);
	Wheel(0.0f,-0.0f,0.04f);
	glPopMatrix();
    i += 0.1f;

	glLoadIdentity();

	glBegin(GL_QUADS);
	glColor3ub(130, 5, 5);
	glVertex2f(-0.92f,0.1f);
	glVertex2f(-0.89f,0.1f);
	glVertex2f(-0.89f,0.4f);
	glVertex2f(-0.92f,0.4f);
	glEnd();

	glTranslatef(1.82f,0.0f,0.0f);

	glBegin(GL_QUADS);
	glColor3ub(130, 5, 5);
	glVertex2f(-0.92f,0.1f);
	glVertex2f(-0.89f,0.1f);
	glVertex2f(-0.89f,0.4f);
	glVertex2f(-0.92f,0.4f);
	glEnd();

	glLoadIdentity();

	glLoadIdentity();
	glTranslatef(-0.91f,0.4f,0);
	Tree(0,0,0.1f);

	glScalef(0,0.3f,0);

	glLoadIdentity();
	glTranslatef(-0.91f,0.52f,0);
	Tree(0,0,0.05f);

	glLoadIdentity();

    glPushMatrix();
    glTranslatef(0.913f,0.4f,0.0f);
    glRotatef(i,0.0f,0.0f,0.8f);
//wind mile fan;
	glBegin(GL_TRIANGLES);
	glColor3ub(25, 105, 12);
	glVertex2f(0.0f,0.0f);
	glVertex2f(-0.18f,0.12f);
	glVertex2f(-0.2f,0.08f);

	glVertex2f(0.0f,0.0f);
	glVertex2f(0.07f,0.22f);
	glVertex2f(0.12f,0.2f);

	glVertex2f(0.0f,0.0f);
	glVertex2f(-0.05f,-0.2f);
	glVertex2f(-0.0f,-0.2f);

    glEnd();

    glPopMatrix();
    i += 0.2f;





	 glLoadIdentity();
	//plane
	glPushMatrix();
    glTranslatef(position,position,0.0f );

    Wheel1(-0.235f,-0.54f,0.01f);
	Wheel1(-0.525f,-0.56f,0.02f);

	glBegin(GL_QUADS);
	glColor3ub(247, 247, 242);
	glVertex2f(-0.6f,-0.4f);
	glVertex2f(-0.58f,-0.52f);
	glVertex2f(-0.2f,-0.42f);
	glVertex2f(-0.22f,-0.28f);

	glVertex2f(-0.28f,-0.3f);
	glVertex2f(-0.36f,-0.2f);
	glVertex2f(-0.39f,-0.22f);
	glVertex2f(-0.34f,-0.38f);

	glVertex2f(-0.26f,-0.4f);
	glVertex2f(-0.34f,-0.45f);
	glVertex2f(-0.4f,-0.65f);
	glVertex2f(-0.32f,-0.6f);

	glVertex2f(-0.62f,-0.34f);
	glVertex2f(-0.64f,-0.35f);
	glVertex2f(-0.62f,-0.48f);
	glVertex2f(-0.58f,-0.44f);

	glEnd();

	//airplane front & back;
	glBegin(GL_TRIANGLES);
	glColor3ub(247, 247, 242);
	glVertex2f(-0.22f,-0.28f);
	glVertex2f(-0.2f,-0.42f);
	glVertex2f(-0.08f,-0.37f);

	glVertex2f(-0.6f,-0.4f);
	glVertex2f(-0.58f,-0.52f);
	glVertex2f(-0.66f,-0.53f);

	glEnd();

	glBegin(GL_LINES);
	//wheel line;
	glColor3ub(10,10,10);
	glVertex2f(-0.25f,-0.44f);
	glVertex2f(-0.24f,-0.54f);

	glVertex2f(-0.24f,-0.44f);
	glVertex2f(-0.23f,-0.54f);

	glVertex2f(-0.52f,-0.5f);
	glVertex2f(-0.52f,-0.56f);

	glVertex2f(-0.53f,-0.5f);
	glVertex2f(-0.53f,-0.56f);
	glEnd();

	glPopMatrix();

	glLoadIdentity();




	glLoadIdentity();

	glPushMatrix();

		glPushMatrix();
glScalef(kk,kk, 0.0f);
	glBegin(GL_QUADS);
	glColor3ub(230, 20, 5);
	glVertex2f(0.0f,-0.03f);
	glVertex2f(0.0f,-0.08f);
	glVertex2f(0.08f,-0.08f);
	glVertex2f(0.06f,-0.03f);

glEnd();

glPopMatrix();

	glFlush();  // Render now
}

void sound()
{

    PlaySound("AirplaneSound", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
    //PlaySound("a.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
}

void sound1()
{

    PlaySound("BirdSound", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
    //PlaySound("a.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
}

void sound2()
{

    PlaySound("NightSound", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
    //PlaySound("a.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
}




void handleKeypress(unsigned char key, int x, int y) {
	switch (key) {
case 'a':
    speed2 = 0.1f;
    break;
case 's':
    speed2 = 0.02f;
    break;
case 'm':
    speed=0;
    glutDisplayFunc(display2);
    sound1();

    break;
case 'd':
    glutDisplayFunc(display);
    speed=.02;
    sound();
         glutPostRedisplay();
    break;
case 'e':
    glutDisplayFunc(display1);
    break;
case 'n':
    sound2();
    glutDisplayFunc(display3);

    break;

glutPostRedisplay();
	}
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);

    glutInitWindowSize(780,380);
    glutInitWindowPosition(50, 50);


    glutCreateWindow("Airport");

    glutDisplayFunc(display);

    glutDisplayFunc(display3);
    glutDisplayFunc(display2);
    glutDisplayFunc(display1);

    glutIdleFunc(Idle);

    glutKeyboardFunc(handleKeypress);
    glutMouseFunc(handleMouse);
    glutSpecialFunc(SpecialInput);


    glutTimerFunc(100, CloudMove, 0);
    glutTimerFunc(100, PlaneMove, 0);
    glutTimerFunc(100, Birds, 0);
 //   sound();


    glutMainLoop();

    return EXIT_SUCCESS;
}
