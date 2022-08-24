/*CG Final Project

Topic - A Lighthouse over the dockside

Submitted by-

Name: Fakrul Ibne Hassan

ID: CSE 066 07714

Batch: 66(C)

*/
#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include<math.h>
#define PI 3.1416
#include <stdlib.h>
static float cx=0,cy=0,ca=0,cr=1,cg=0,cb=0;
static float llx = 77.6, lly = 70, llr = 0.97, llg = 0.99, llb = 0.21; // Light House Colors
static float s1r = 0, s1g = 0, s1b = 0; // colors for dock master
static float s2r = 0, s2g = 0, s2b = 0; // colors for fish
static float s3r = 0, s3g = 0, s3b = 0; // colors for food
static float s4r = 0, s4g = 0, s4b = 0; // colors for imports
static float x1 = 0; // Cruise Ship Movement
static float c1 = 0.0; // Cloud 1
static float c2 = 0.0; // Cloud 2
static float c3 = 0.0; // Cloud 3
static float c4 = 0.0; // Cloud 4
static float bs1 = 0; // Background ship 1
static float bs2 = 0; // Background ship 2
static float l1r = 0;
static float l1g = 0;
static float l1b = 0;
static float l2r = 0;
static float l2g = 0;
static float l2b = 0;
static float l3r = 0;
static float l3g = 0;
static float l3b = 0;
static float ld1r = 0.5;
static float ld1g = 0.28;
static float ld1b = 0.04;
static float ld2r = 0;
static float ld2g = 0;
static float ld2b = 0;
static float dx1 = -63;
static float dy1 = -45;
static float dx2 = -53;
static float dy2 = -45;
static float dr1 = 0.003;
static float dg1 = 0.74;
static float db1 = 1;
static float dr2 = 0.003;
static float dg2 = 0.74;
static float db2 = 1;

void circle(float radiusX,float radiusY){
    int i;
    float angle=0.0;
    glBegin(GL_POLYGON);
        for(i=0;i<100;i++){
            angle= 2*PI*i/100;
            glVertex2f(radiusX*cos(angle),radiusY*sin(angle));

        }
    glEnd();

}

void docsignboard(int dsbx, int dsby, float dsbr, float dsbg, float dsbb, void* dsfont, char *stringds)
{
    glColor3f(dsbr, dsbg, dsbb);
    glRasterPos2f(dsbx, dsby);
    int len,i;
    len = (int)strlen(stringds);
    for (i=0; i<len; i++){
        glutBitmapCharacter(dsfont, stringds[i]);
    }
}

void storesign1(int dsbx, int dsby, float dsbr, float dsbg, float dsbb, void* dsfont, char *stringds)
{
    glColor3f(dsbr, dsbg, dsbb);
    glRasterPos2f(dsbx, dsby);
    int len,i;
    len = (int)strlen(stringds);
    for (i=0; i<len; i++){
        glutBitmapCharacter(dsfont, stringds[i]);
    }
}

void storesign2(int dsbx, int dsby, float dsbr, float dsbg, float dsbb, void* dsfont, char *stringds)
{
    glColor3f(dsbr, dsbg, dsbb);
    glRasterPos2f(dsbx, dsby);
    int len,i;
    len = (int)strlen(stringds);
    for (i=0; i<len; i++){
        glutBitmapCharacter(dsfont, stringds[i]);
    }
}

void storesign3(int dsbx, int dsby, float dsbr, float dsbg, float dsbb, void* dsfont, char *stringds)
{
    glColor3f(dsbr, dsbg, dsbb);
    glRasterPos2f(dsbx, dsby);
    int len,i;
    len = (int)strlen(stringds);
    for (i=0; i<len; i++){
        glutBitmapCharacter(dsfont, stringds[i]);
    }
}

void moveship()
{
    x1 += 1;
    glutPostRedisplay();
}

void moveshipback()
{
    x1 -= 1;
    glutPostRedisplay();
}

void movebgobjects(){
        c1 += 0.001;
        c2 += 0.002;
        c3 += 0.001;
        c4 += 0.001;
        bs1 += 0.003;
        bs2 += 0.002;
        glutPostRedisplay();
}

void init(){
  glClearColor(1,1,1,0);
  glOrtho(-100,100,-100,100,-1,1);

}

void myDisplay(){
    glClear(GL_COLOR_BUFFER_BIT);

    //Sky Box - Medium Sky Blue

    glBegin(GL_POLYGON);
    glColor3f(0.51,0.87,0.94);
    glVertex2f(-100,100);
    glVertex2f(100,100);
    glVertex2f(100,25);
    glVertex2f(-100,25);
    glEnd();

    //Sun - Sun Yellow
    glPushMatrix();
    glTranslatef(-80,80,0);
    glColor3f(0.97,0.99,0.21);
    circle(8, 12.8);
    glPopMatrix();

    //Sunrays
    glBegin(GL_LINES);
    glColor3f(0.97,0.99,0.21);
    glVertex2f(-95,80);
    glVertex2f(-90,80);
    glVertex2f(-70,80);
    glVertex2f(-65,80);
    glVertex2f(-80,100);
    glVertex2f(-80,95);
    glVertex2f(-80,65);
    glVertex2f(-80,57);
    glVertex2f(-70,90);
    glVertex2f(-66,95);
    glVertex2f(-94,95);
    glVertex2f(-90,90);
    glVertex2f(-94,60);
    glVertex2f(-90,68);
    glVertex2f(-94,95);
    glVertex2f(-90,90);
    glVertex2f(-70,68);
    glVertex2f(-66,60);
    glEnd();

    //Cloud - 1
    glPushMatrix();
    glTranslatef(80+c1,80,0);
    glColor3f(1,1,1);
    circle(5, 5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(80+c1,75,0);
    glColor3f(1,1,1);
    circle(5, 5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(75+c1,75,0);
    glColor3f(1,1,1);
    circle(5, 5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(85+c1,80,0);
    glColor3f(1,1,1);
    circle(5, 5);
    glPopMatrix();

    //Cloud - 2
    glPushMatrix();
    glTranslatef(40+c2,90,0);
    glColor3f(1,1,1);
    circle(5, 5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(40+c2,85,0);
    glColor3f(1,1,1);
    circle(5, 5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(35+c2,90,0);
    glColor3f(1,1,1);
    circle(5, 5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(45+c2,84,0);
    glColor3f(1,1,1);
    circle(5, 5);
    glPopMatrix();

    //Cloud - 3
    glPushMatrix();
    glTranslatef(0+c3,70,0);
    glColor3f(1,1,1);
    circle(5, 5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0+c3,65,0);
    glColor3f(1,1,1);
    circle(5, 5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-5+c3,70,0);
    glColor3f(1,1,1);
    circle(5, 5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(5+c3,70,0);
    glColor3f(1,1,1);
    circle(5, 5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0+c3,73,0);
    glColor3f(1,1,1);
    circle(5, 5);
    glPopMatrix();

    //Cloud - 4
    glPushMatrix();
    glTranslatef(-40+c4,85,0);
    glColor3f(1,1,1);
    circle(5, 5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-40+c4,80,0);
    glColor3f(1,1,1);
    circle(5, 5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-45+c4,82,0);
    glColor3f(1,1,1);
    circle(5, 5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-35+c4,84,0);
    glColor3f(1,1,1);
    circle(5, 5);
    glPopMatrix();

    //Mountain - Green - 1
    glPushMatrix();
    glTranslatef(-46,22,0);
    glColor3f(0.3,0.47,0.25);
    circle(12, 10);
    glPopMatrix();

    //Mountain - Green - 2
    glPushMatrix();
    glTranslatef(43,22,0);
    glColor3f(0.2,0.8,0.2);
    circle(12, 10);
    glPopMatrix();

    //Ocean - Capri

    glBegin(GL_POLYGON);
    glColor3f(0.003,0.74,1);
    glVertex2f(-100,25);
    glVertex2f(100,25);
    glVertex2f(100,-100);
    glVertex2f(-100,-100);
    glEnd();

    //Horizon Line
    //Mountains

    //Mountain1 - Russet
    glBegin(GL_TRIANGLES);
    glColor3f(0.5,0.27,0.1);
    glVertex2f(-10,25);
    glVertex2f(10,25);
    glVertex2f(0,55);
    glEnd();

    //Mountain3 - Copper
    glBegin(GL_POLYGON);
    glColor3f(0.77,0.38,0.06);
    glVertex2f(-10,25);
    glVertex2f(-15.5,41);
    glVertex2f(-17,42);
    glVertex2f(-20,40);
    glVertex2f(-26,43);
    glVertex2f(-32,38);
    glVertex2f(-36,35);
    glVertex2f(-42,25);
    glEnd();

    //Mountain2 - Coffee Brown
    glBegin(GL_TRIANGLES);
    glColor3f(0.2,0.15,0.11);
    glVertex2f(-15,25);
    glVertex2f(1,25);
    glVertex2f(-10,40);
    glVertex2f(-8,30);
    glEnd();

    //Mountain3 - Copper
    glBegin(GL_POLYGON);
    glColor3f(0.52,0.4,0.22);
    glVertex2f(14,25);
    glVertex2f(15.5,41);
    glVertex2f(17,45);
    glVertex2f(20,40);
    glVertex2f(26,43);
    glVertex2f(32,38);
    glVertex2f(36,35);
    glVertex2f(42,25);
    glEnd();

    //Mountain3 - Copper
    glBegin(GL_TRIANGLES);
    glColor3f(0.72,0.45,0.2);
    glVertex2f(5,25);
    glVertex2f(16,25);
    glVertex2f(10,50);
    glEnd();

    // Background Ship - 2

    //Hull
    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    glVertex2f(-60+bs2,10);
    glVertex2f(-90+bs2,10);
    glVertex2f(-85+bs2,0);
    glVertex2f(-65+bs2,0);
    glEnd();

    //Layer 1
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex2f(-65+bs2,10);
    glVertex2f(-85+bs2,10);
    glVertex2f(-85+bs2,15);
    glVertex2f(-65+bs2,15);
    glEnd();

    //Pipe - 1
    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    glVertex2f(-70+bs2,15);
    glVertex2f(-74+bs2,15);
    glVertex2f(-74+bs2,23);
    glVertex2f(-70+bs2,23);
    glEnd();

    //Pipe - 2
    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    glVertex2f(-78+bs2,15);
    glVertex2f(-82+bs2,15);
    glVertex2f(-82+bs2,23);
    glVertex2f(-78+bs2,23);
    glEnd();

    // Window - 1

    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    glVertex2f(-68+bs2,11);
    glVertex2f(-73+bs2,11);
    glVertex2f(-73+bs2,13);
    glVertex2f(-68+bs2,13);
    glEnd();

    // Window - 2

    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    glVertex2f(-77+bs2,11);
    glVertex2f(-82+bs2,11);
    glVertex2f(-82+bs2,13);
    glVertex2f(-77+bs2,13);
    glEnd();

    // Background Ship - 1

    //Hull
    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    glVertex2f(60-bs1,5);
    glVertex2f(90-bs1,5);
    glVertex2f(85-bs1,-5);
    glVertex2f(65-bs1,-5);
    glEnd();

    //Layer 1
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex2f(65-bs1,5);
    glVertex2f(85-bs1,5);
    glVertex2f(85-bs1,10);
    glVertex2f(65-bs1,10);
    glEnd();

    //Pipe - 1
    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    glVertex2f(70-bs1,10);
    glVertex2f(74-bs1,10);
    glVertex2f(74-bs1,18);
    glVertex2f(70-bs1,18);
    glEnd();

    //Pipe - 2
    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    glVertex2f(78-bs1,10);
    glVertex2f(82-bs1,10);
    glVertex2f(82-bs1,18);
    glVertex2f(78-bs1,18);
    glEnd();

    // Window - 1

    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    glVertex2f(68-bs1,6);
    glVertex2f(73-bs1,6);
    glVertex2f(73-bs1,8);
    glVertex2f(68-bs1,8);
    glEnd();

    // Window - 2

    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    glVertex2f(77-bs1,6);
    glVertex2f(82-bs1,6);
    glVertex2f(82-bs1,8);
    glVertex2f(77-bs1,8);
    glEnd();




    //Light House

    //Base
    glBegin(GL_POLYGON);
    glColor3f(0.93,0.92,0.85);
    glVertex2f(68,20);
    glVertex2f(88,20);
    glVertex2f(88,0);
    glVertex2f(68,0);
    glEnd();

    //Base Door
    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    glVertex2f(76,0);
    glVertex2f(76,17);
    glVertex2f(80,17);
    glVertex2f(80,0);
    glEnd();

    //Cone
    glBegin(GL_POLYGON);
    glColor3f(1,0.27,0);
    glVertex2f(70,20);
    glVertex2f(73,60);
    glVertex2f(83,60);
    glVertex2f(86,20);
    glEnd();

    //Light House Windows

    //Window 1

    glBegin(GL_POLYGON);
    glColor3f(l1r,l1g,l1b);
    glVertex2f(77,50);
    glVertex2f(77,55);
    glVertex2f(79,55);
    glVertex2f(79,50);
    glEnd();

    //Window 1 window pane
    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(77,52.5);
    glVertex2f(79,52.5);
    glVertex2f(78,50);
    glVertex2f(78,55);

    glVertex2f(77,50);
    glVertex2f(77,55);
    glVertex2f(79,55);
    glVertex2f(79,50);

    glVertex2f(77,50);
    glVertex2f(79,50);
    glVertex2f(77,55);
    glVertex2f(79,55);

    glEnd();

    //Window 2

    glBegin(GL_POLYGON);
    glColor3f(l2r,l2g,l2b);
    glVertex2f(77,40);
    glVertex2f(77,45);
    glVertex2f(79,45);
    glVertex2f(79,40);
    glEnd();


    //Window 2 window pane
    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(77,42.5);
    glVertex2f(79,42.5);
    glVertex2f(78,40);
    glVertex2f(78,45);

    glVertex2f(77,40);
    glVertex2f(77,45);
    glVertex2f(79,45);
    glVertex2f(79,40);

    glVertex2f(77,40);
    glVertex2f(79,40);
    glVertex2f(77,45);
    glVertex2f(79,45);
    glEnd();

    //Window - 3

    glBegin(GL_POLYGON);
    glColor3f(l3r,l3g,l3b);
    glVertex2f(77,30);
    glVertex2f(77,35);
    glVertex2f(79,35);
    glVertex2f(79,30);
    glEnd();

    //Window 3 window pane

    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(77,32.5);
    glVertex2f(79,32.5);
    glVertex2f(78,30);
    glVertex2f(78,35);

    glVertex2f(77,30);
    glVertex2f(77,35);
    glVertex2f(79,35);
    glVertex2f(79,30);

    glVertex2f(77,30);
    glVertex2f(79,30);
    glVertex2f(77,35);
    glVertex2f(79,35);

    glEnd();

    //Top Base
    glBegin(GL_POLYGON);
    glColor3f(0.96,0.87,0.82);
    glVertex2f(72,60);
    glVertex2f(72,63);
    glVertex2f(84,63);
    glVertex2f(84,60);
    glEnd();

    //Top Roof
    glBegin(GL_POLYGON);
    glColor3f(0.96,0.87,0.82);
    glVertex2f(73,75);
    glVertex2f(73,78);
    glVertex2f(83,78);
    glVertex2f(83,75);
    glEnd();


    //Top Roof - 2
    glBegin(GL_POLYGON);
    glColor3f(0.93,0.92,0.85);
    glVertex2f(74,78);
    glVertex2f(74,81);
    glVertex2f(82,81);
    glVertex2f(82,78);
    glEnd();

    //Pillar - 1
    glBegin(GL_POLYGON);
    glColor3f(0.93,0.92,0.85);
    glVertex2f(73.5,63);
    glVertex2f(73.5,75);
    glVertex2f(74.5,75);
    glVertex2f(74.5,63);
    glEnd();

    //Pillar - 2
    glBegin(GL_POLYGON);
    glColor3f(0.93,0.92,0.85);
    glVertex2f(81.5,63);
    glVertex2f(81.5,75);
    glVertex2f(82.5,75);
    glVertex2f(82.5,63);
    glEnd();

    //Light House Light Stand
    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    glVertex2f(77.2,63);
    glVertex2f(77.2,71);
    glVertex2f(78.8,71);
    glVertex2f(78.8,63);
    glEnd();

    //Light House Light

    glPushMatrix();
    glTranslatef(78,70,0);
    glColor3f(0,0,0);
    circle(2, 3.2);
    glPopMatrix();

    //Light House Light - 2

    glPushMatrix();
    glTranslatef(llx,lly,0);
    glColor3f(llr,llg,llb);
    circle(1.6, 2.56);
    glPopMatrix();

    //Light House Light Cage

    //Bar - 1
    glBegin(GL_POLYGON);
    glColor3f(0.93,0.92,0.85);
    glVertex2f(75.5,63);
    glVertex2f(75.5,75);
    glVertex2f(76,75);
    glVertex2f(76,63);
    glEnd();

    //Bar - 2
    glBegin(GL_POLYGON);
    glColor3f(0.93,0.92,0.85);
    glVertex2f(77,63);
    glVertex2f(77,75);
    glVertex2f(77.5,75);
    glVertex2f(77.5,63);
    glEnd();

    //Bar - 3
    glBegin(GL_POLYGON);
    glColor3f(0.93,0.92,0.85);
    glVertex2f(78.5,63);
    glVertex2f(78.5,75);
    glVertex2f(79,75);
    glVertex2f(79,63);
    glEnd();

    //Bar - 4
    glBegin(GL_POLYGON);
    glColor3f(0.93,0.92,0.85);
    glVertex2f(80,63);
    glVertex2f(80,75);
    glVertex2f(80.5,75);
    glVertex2f(80.5,63);
    glEnd();

    // Light House Hill
    glBegin(GL_POLYGON);
    glColor3f(0.85,0.56,0);
    glVertex2f(100,10);
    glVertex2f(100,-100);
    glVertex2f(75,-100);
    glVertex2f(62,5);
    glVertex2f(64,12);
    glVertex2f(71,15);
    glVertex2f(75,9);
    glVertex2f(85,19);
    glEnd();

    //Cruise Ship

    //Ship Level 1
    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    glVertex2f(-40-x1,-35);
    glVertex2f(-35-x1,-25);
    glVertex2f(35-x1,-25);
    glVertex2f(35-x1,-35);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex2f(-30-x1,-32);
    glVertex2f(-30-x1,-28);
    glVertex2f(-20-x1,-28);
    glVertex2f(-20-x1,-32);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex2f(-15-x1,-32);
    glVertex2f(-15-x1,-28);
    glVertex2f(-5-x1,-28);
    glVertex2f(-5-x1,-32);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex2f(5-x1,-32);
    glVertex2f(5-x1,-28);
    glVertex2f(15-x1,-28);
    glVertex2f(15-x1,-32);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex2f(20-x1,-32);
    glVertex2f(20-x1,-28);
    glVertex2f(30-x1,-28);
    glVertex2f(30-x1,-32);
    glEnd();

    //Ship Level 2
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex2f(-30-x1,-25);
    glVertex2f(-25-x1,-15);
    glVertex2f(30-x1,-15);
    glVertex2f(30-x1,-25);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    glVertex2f(-20-x1,-22);
    glVertex2f(-20-x1,-18);
    glVertex2f(-12-x1,-18);
    glVertex2f(-12-x1,-22);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    glVertex2f(-2-x1,-22);
    glVertex2f(-2-x1,-18);
    glVertex2f(6-x1,-18);
    glVertex2f(6-x1,-22);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    glVertex2f(16-x1,-22);
    glVertex2f(16-x1,-18);
    glVertex2f(24-x1,-18);
    glVertex2f(24-x1,-22);
    glEnd();

    //Ship Level 3
    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    glVertex2f(-20-x1,-15);
    glVertex2f(-20-x1,-5);
    glVertex2f(25-x1,-5);
    glVertex2f(25-x1,-15);
    glEnd();

    glPushMatrix();
    glTranslatef(-12.5-x1,-10,0);
    glColor3f(1,1,1);
    circle(2, 3.2);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0-x1,-10,0);
    glColor3f(1,1,1);
    circle(2, 3.2);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(12.5-x1,-10,0);
    glColor3f(1,1,1);
    circle(2, 3.2);
    glPopMatrix();

    //Ship Pipes

    //Pipes - 1
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex2f(-15-x1,-5);
    glVertex2f(-15-x1,5);
    glVertex2f(-10-x1,5);
    glVertex2f(-10-x1,-5);
    glEnd();

    //Pipes - 2
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex2f(-2.5-x1,-5);
    glVertex2f(-2.5-x1,5);
    glVertex2f(2.5-x1,5);
    glVertex2f(2.5-x1,-5);
    glEnd();

    //Pipes - 3
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex2f(10-x1,-5);
    glVertex2f(10-x1,5);
    glVertex2f(15-x1,5);
    glVertex2f(15-x1,-5);
    glEnd();

    //Flag Pole

    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex2f(20-x1,-5);
    glVertex2f(20-x1,5);
    glEnd();

    //Flag
    glBegin(GL_POLYGON);
    glColor3f(0,1,0);
    glVertex2f(20-x1,0);
    glVertex2f(20-x1,5);
    glVertex2f(27-x1,5);
    glVertex2f(27-x1,0);
    glEnd();

    glPushMatrix();
    glTranslatef(23.5-x1,2.5,0);
    glColor3f(1,0,0);
    circle(1, 1.6);
    glPopMatrix();


    //Ship Hull
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex2f(50-x1,-35);
    glVertex2f(40-x1,-35);
    glVertex2f(25-x1,-50);
    glVertex2f(-35-x1,-50);
    glVertex2f(-40-x1,-35);
    glVertex2f(-50-x1,-35);
    glVertex2f(-46-x1,-50);
    glVertex2f(-30-x1,-80);
    glVertex2f(38-x1,-80);
    glVertex2f(38-x1,-60);
    glVertex2f(50-x1,-50);
    glEnd();

    glPushMatrix();
    glTranslatef(-38-x1,-43,0);
    glColor3f(0,0,0);
    circle(3, 4.8);
    glPopMatrix();

    //Ladder part 1
    glBegin(GL_POLYGON);
    glColor3f(ld1r,ld1g,ld1b);
    glVertex2f(50,-45);
    glVertex2f(50,-40);
    glVertex2f(65,-40);
    glVertex2f(65,-45);
    glEnd();

    //Ladder stick 1
    glBegin(GL_POLYGON);
    glColor3f(ld2r,ld2g,ld2b);
    glVertex2f(53,-40);
    glVertex2f(54,-40);
    glVertex2f(54,-65);
    glVertex2f(53,-65);
    glEnd();

    //Ladder stick 2
    glBegin(GL_POLYGON);
    glColor3f(ld2r,ld2g,ld2b);
    glVertex2f(62,-40);
    glVertex2f(61,-40);
    glVertex2f(61,-65);
    glVertex2f(62,-65);
    glEnd();

    //Step - 1
    glBegin(GL_POLYGON);
    glColor3f(ld2r,ld2g,ld2b);
    glVertex2f(54,-44);
    glVertex2f(61,-44);
    glVertex2f(61,-45);
    glVertex2f(54,-45);
    glEnd();

    //Step - 2
    glBegin(GL_POLYGON);
    glColor3f(ld2r,ld2g,ld2b);
    glVertex2f(54,-48);
    glVertex2f(61,-48);
    glVertex2f(61,-49);
    glVertex2f(54,-49);
    glEnd();

    //Step - 3
    glBegin(GL_POLYGON);
    glColor3f(ld2r,ld2g,ld2b);
    glVertex2f(54,-52);
    glVertex2f(61,-52);
    glVertex2f(61,-53);
    glVertex2f(54,-53);
    glEnd();

    //Step - 4
    glBegin(GL_POLYGON);
    glColor3f(ld2r,ld2g,ld2b);
    glVertex2f(54,-56);
    glVertex2f(61,-56);
    glVertex2f(61,-57);
    glVertex2f(54,-57);
    glEnd();

    //Step - 5
    glBegin(GL_POLYGON);
    glColor3f(ld2r,ld2g,ld2b);
    glVertex2f(54,-60);
    glVertex2f(61,-60);
    glVertex2f(61,-61);
    glVertex2f(54,-61);
    glEnd();

    //Dock walk
    glBegin(GL_POLYGON);
    glColor3f(0.5,0.28,0.04);
    glVertex2f(-100,-100);
    glVertex2f(-100,-65);
    glVertex2f(100,-65);
    glVertex2f(100,-100);
    glEnd();


    // Wood Planks - horizontal line
    glBegin(GL_LINES);
    glColor3f(0.72,0.54,0.38);
    glVertex2f(-100,-70);
    glVertex2f(100,-70);
    glVertex2f(-100,-75);
    glVertex2f(100,-75);
    glVertex2f(-100,-80);
    glVertex2f(100,-80);
    glVertex2f(-100,-85);
    glVertex2f(100,-85);
    glVertex2f(-100,-90);
    glVertex2f(100,-90);
    glVertex2f(-100,-95);
    glVertex2f(100,-95);
    glVertex2f(-100,-100);
    glVertex2f(100,-100);
    glEnd();

    // Wood Planks - Diagonal Lines
    glBegin(GL_LINES);
    glColor3f(0.72,0.54,0.38);
    glVertex2f(-90,-65);
    glVertex2f(-100,-100);
    glVertex2f(-60,-65);
    glVertex2f(-70,-100);
    glVertex2f(-30,-65);
    glVertex2f(-40,-100);
    glVertex2f(0,-65);
    glVertex2f(-10,-100);
    glVertex2f(30,-65);
    glVertex2f(20,-100);
    glVertex2f(60,-65);
    glVertex2f(50,-100);
    glVertex2f(90,-65);
    glVertex2f(80,-100);

    glEnd();

    //Dock House

    //Body
    glBegin(GL_POLYGON);
    glColor3f(0,0,1);
    glVertex2f(68,-70);
    glVertex2f(68,-40);
    glVertex2f(95,-40);
    glVertex2f(95,-70);
    glEnd();

    //Roof
    glBegin(GL_POLYGON);
    glColor3f(1,0,1);
    glVertex2f(66,-40);
    glVertex2f(66,-36);
    glVertex2f(97,-36);
    glVertex2f(97,-40);
    glEnd();

    //Dock Sign
    glBegin(GL_POLYGON);
    glColor3f(1,1,0);
    glVertex2f(70,-36);
    glVertex2f(70,-20);
    glVertex2f(93,-20);
    glVertex2f(93,-36);
    glEnd();

    docsignboard(71.5, -28, s1r, s1g, s1b, GLUT_BITMAP_TIMES_ROMAN_24, "DOCK MASTER");

    //Door
    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    glVertex2f(78,-70);
    glVertex2f(78,-50);
    glVertex2f(85,-50);
    glVertex2f(85,-70);
    glEnd();

    //Window

    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    glVertex2f(71,-55);
    glVertex2f(71,-45);
    glVertex2f(75,-45);
    glVertex2f(75,-55);
    glEnd();

    //Window Pane

    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(71,-55);
    glVertex2f(71,-45);
    glVertex2f(75,-45);
    glVertex2f(75,-55);

    glVertex2f(71,-55);
    glVertex2f(75,-55);
    glVertex2f(71,-45);
    glVertex2f(75,-45);

    glEnd();

    // Dock Master

    //Head
    glPushMatrix();
    glTranslatef(93,-50,0);
    glColor3f(0.94,0.76,0.49);
    circle(2, 3.2);
    glPopMatrix();

    //Face
    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex2f(92,-49);
    glVertex2f(92.5,-49);

    glVertex2f(92,-49.1);
    glVertex2f(92.5,-49.1);

    glVertex2f(92,-49.2);
    glVertex2f(92.5,-49.2);

    glVertex2f(92.,-49.3);
    glVertex2f(92.5,-49.3);

    glVertex2f(92,-49.4);
    glVertex2f(92.5,-49.5);

    glVertex2f(93.5,-49);
    glVertex2f(94,-49);

    glVertex2f(93.5,-49.1);
    glVertex2f(94,-49.1);

    glVertex2f(93.5,-49.2);
    glVertex2f(94,-49.2);

    glVertex2f(93.5,-49.3);
    glVertex2f(94,-49.3);

    glVertex2f(93.5,-49.4);
    glVertex2f(94,-49.5);

    glVertex2f(92,-51);
    glVertex2f(94,-51);
    glEnd();

    //Body

    glBegin(GL_POLYGON);
    glColor3f(1,0,0);
    glVertex2f(90,-63);
    glVertex2f(90,-53);
    glVertex2f(96,-53);
    glVertex2f(96,-63);
    glEnd();

    //Leg 1
    glBegin(GL_POLYGON);
    glColor3f(1,1,0);
    glVertex2f(91,-63);
    glVertex2f(92.5,-63);
    glVertex2f(92.5,-69);
    glVertex2f(91,-69);
    glEnd();

    //Boot 1
    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    glVertex2f(90.5,-69);
    glVertex2f(92.5,-69);
    glVertex2f(92.5,-71);
    glVertex2f(90.5,-71);
    glEnd();

    //Leg 2
    glBegin(GL_POLYGON);
    glColor3f(1,1,0);
    glVertex2f(93.5,-63);
    glVertex2f(95,-63);
    glVertex2f(95,-69);
    glVertex2f(93.5,-69);
    glEnd();

    //Boot 2
    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    glVertex2f(93.5,-69);
    glVertex2f(95.5,-69);
    glVertex2f(95.5,-71);
    glVertex2f(93.5,-71);
    glEnd();

    //Shopkeeper - 1

    //Head
    glPushMatrix();
    glTranslatef(20,-50,0);
    glColor3f(1,0.85,0.67);
    circle(2, 3.2);
    glPopMatrix();

    //Face
    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex2f(19,-49);
    glVertex2f(19.5,-49);

    glVertex2f(19,-49.1);
    glVertex2f(19.5,-49.1);

    glVertex2f(19,-49.2);
    glVertex2f(19.5,-49.2);

    glVertex2f(19.,-49.3);
    glVertex2f(19.5,-49.3);

    glVertex2f(19,-49.4);
    glVertex2f(19.5,-49.5);

    glVertex2f(20.5,-49);
    glVertex2f(21,-49);

    glVertex2f(20.5,-49.1);
    glVertex2f(21,-49.1);

    glVertex2f(20.5,-49.2);
    glVertex2f(21,-49.2);

    glVertex2f(20.5,-49.3);
    glVertex2f(21,-49.3);

    glVertex2f(20.5,-49.4);
    glVertex2f(21,-49.5);

    glVertex2f(19,-51);
    glVertex2f(21,-51);
    glEnd();

    //Body

    glBegin(GL_POLYGON);
    glColor3f(1,0,0);
    glVertex2f(17,-60);
    glVertex2f(17,-53);
    glVertex2f(23,-53);
    glVertex2f(23,-60);
    glEnd();

    //Store 1 - Fish

    //Store stand
    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    glVertex2f(10,-71);
    glVertex2f(10,-60);
    glVertex2f(30,-60);
    glVertex2f(30,-71);
    glEnd();

    //Table Top
    glBegin(GL_POLYGON);
    glColor3f(1,1,0);
    glVertex2f(8,-60);
    glVertex2f(8,-57);
    glVertex2f(32,-57);
    glVertex2f(32,-60);
    glEnd();

    //Sign
    glBegin(GL_POLYGON);
    glColor3f(1,1,0);
    glVertex2f(10,-47);
    glVertex2f(10,-38);
    glVertex2f(30,-38);
    glVertex2f(30,-47);
    glEnd();

    storesign1(11.5, -43.5, s2r, s2g, s2b, GLUT_BITMAP_TIMES_ROMAN_24, "FRESH FISH");

    //Pillar 1
    glBegin(GL_POLYGON);
    glColor3f(1,0,1);
    glVertex2f(12,-60);
    glVertex2f(12,-47);
    glVertex2f(14,-47);
    glVertex2f(14,-60);
    glEnd();

    //Pillar 2
    glBegin(GL_POLYGON);
    glColor3f(1,0,1);
    glVertex2f(26,-60);
    glVertex2f(26,-47);
    glVertex2f(28,-47);
    glVertex2f(28,-60);
    glEnd();

    //Customer - 1

    //Head
    glPushMatrix();
    glTranslatef(10,-50,0);
    glColor3f(1,0.85,0.67);
    circle(2, 3.2);
    glPopMatrix();

    //Body

    glBegin(GL_POLYGON);
    glColor3f(1,0,0);
    glVertex2f(7,-63);
    glVertex2f(7,-53);
    glVertex2f(13,-53);
    glVertex2f(13,-63);
    glEnd();

    //Leg 1
    glBegin(GL_POLYGON);
    glColor3f(1,0,1);
    glVertex2f(8,-63);
    glVertex2f(9.5,-63);
    glVertex2f(9.5,-69);
    glVertex2f(8,-69);
    glEnd();

    //Boot 1
    glBegin(GL_POLYGON);
    glColor3f(0.79,0.8,0.5);
    glVertex2f(7.5,-69);
    glVertex2f(9.5,-69);
    glVertex2f(9.5,-71);
    glVertex2f(7.5,-71);
    glEnd();

    //Leg 2
    glBegin(GL_POLYGON);
    glColor3f(1,0,1);
    glVertex2f(10.5,-63);
    glVertex2f(12,-63);
    glVertex2f(12,-69);
    glVertex2f(10.5,-69);
    glEnd();

    //Boot 2
    glBegin(GL_POLYGON);
    glColor3f(0.79,0.8,0.5);
    glVertex2f(10.5,-69);
    glVertex2f(12.5,-69);
    glVertex2f(12.5,-71);
    glVertex2f(10.5,-71);
    glEnd();

    //Customer - 2

    //Head
    glPushMatrix();
    glTranslatef(30,-50,0);
    glColor3f(1,0.85,0.67);
    circle(2, 3.2);
    glPopMatrix();

    //Body

    glBegin(GL_POLYGON);
    glColor3f(1,0,0);
    glVertex2f(27,-63);
    glVertex2f(27,-53);
    glVertex2f(33,-53);
    glVertex2f(33,-63);
    glEnd();

    //Leg 1
    glBegin(GL_POLYGON);
    glColor3f(1,0,1);
    glVertex2f(28,-63);
    glVertex2f(29.5,-63);
    glVertex2f(29.5,-69);
    glVertex2f(28,-69);
    glEnd();

    //Boot 1
    glBegin(GL_POLYGON);
    glColor3f(0.79,0.8,0.5);
    glVertex2f(27.5,-69);
    glVertex2f(29.5,-69);
    glVertex2f(29.5,-71);
    glVertex2f(27.5,-71);
    glEnd();

    //Leg 2
    glBegin(GL_POLYGON);
    glColor3f(1,0,1);
    glVertex2f(30.5,-63);
    glVertex2f(32,-63);
    glVertex2f(32,-69);
    glVertex2f(30.5,-69);
    glEnd();

    //Boot 2
    glBegin(GL_POLYGON);
    glColor3f(0.79,0.8,0.5);
    glVertex2f(30.5,-69);
    glVertex2f(32.5,-69);
    glVertex2f(32.5,-71);
    glVertex2f(30.5,-71);
    glEnd();


    //Shopkeeper - 2

    //Head
    glPushMatrix();
    glTranslatef(-20,-50,0);
    glColor3f(1,0.85,0.67);
    circle(2, 3.2);
    glPopMatrix();

    //Face
    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex2f(-21,-49);
    glVertex2f(-21.5,-49);

    glVertex2f(-21,-49.1);
    glVertex2f(-21.5,-49.1);

    glVertex2f(-21,-49.2);
    glVertex2f(-21.5,-49.2);

    glVertex2f(-21,-49.3);
    glVertex2f(-21.5,-49.3);

    glVertex2f(-21,-49.4);
    glVertex2f(-21.5,-49.5);

    glVertex2f(-19.5,-49);
    glVertex2f(-19,-49);

    glVertex2f(-19.5,-49.1);
    glVertex2f(-19,-49.1);

    glVertex2f(-19.5,-49.2);
    glVertex2f(-19,-49.2);

    glVertex2f(-19.5,-49.3);
    glVertex2f(-19,-49.3);

    glVertex2f(-19.5,-49.4);
    glVertex2f(-19,-49.5);

    glVertex2f(-21,-51);
    glVertex2f(-19,-51);
    glEnd();

    //Body

    glBegin(GL_POLYGON);
    glColor3f(0,1,0);
    glVertex2f(-23,-60);
    glVertex2f(-23,-53);
    glVertex2f(-17,-53);
    glVertex2f(-17,-60);
    glEnd();

    //Store 2 - Food

    //Store stand
    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    glVertex2f(-30,-71);
    glVertex2f(-30,-60);
    glVertex2f(-10,-60);
    glVertex2f(-10,-71);
    glEnd();

    //Table Top
    glBegin(GL_POLYGON);
    glColor3f(1,1,0);
    glVertex2f(-32,-60);
    glVertex2f(-32,-57);
    glVertex2f(-8,-57);
    glVertex2f(-8,-60);
    glEnd();

    //Sign
    glBegin(GL_POLYGON);
    glColor3f(1,1,0);
    glVertex2f(-30,-47);
    glVertex2f(-30,-38);
    glVertex2f(-10,-38);
    glVertex2f(-10,-47);
    glEnd();

    storesign2(-30, -43.5, s3r, s3g, s3b, GLUT_BITMAP_TIMES_ROMAN_24, "FRIED FOODS");

    //Pillar 1
    glBegin(GL_POLYGON);
    glColor3f(1,0,1);
    glVertex2f(-28,-60);
    glVertex2f(-28,-47);
    glVertex2f(-26,-47);
    glVertex2f(-26,-60);
    glEnd();

    //Pillar 2
    glBegin(GL_POLYGON);
    glColor3f(1,0,1);
    glVertex2f(-14,-60);
    glVertex2f(-14,-47);
    glVertex2f(-12,-47);
    glVertex2f(-12,-60);
    glEnd();

    //Customer - 3

    //Head
    glPushMatrix();
    glTranslatef(-30,-50,0);
    glColor3f(1,0.85,0.67);
    circle(2, 3.2);
    glPopMatrix();

    //Body

    glBegin(GL_POLYGON);
    glColor3f(1,0,0);
    glVertex2f(-33,-63);
    glVertex2f(-33,-53);
    glVertex2f(-27,-53);
    glVertex2f(-27,-63);
    glEnd();

    //Leg 1
    glBegin(GL_POLYGON);
    glColor3f(1,1,0);
    glVertex2f(-32,-63);
    glVertex2f(-30.5,-63);
    glVertex2f(-30.5,-69);
    glVertex2f(-32,-69);
    glEnd();

    //Boot 1
    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    glVertex2f(-32.5,-69);
    glVertex2f(-30.5,-69);
    glVertex2f(-30.5,-71);
    glVertex2f(-32.5,-71);
    glEnd();

    //Leg 2
    glBegin(GL_POLYGON);
    glColor3f(1,1,0);
    glVertex2f(-29.5,-63);
    glVertex2f(-28,-63);
    glVertex2f(-28,-69);
    glVertex2f(-29.5,-69);
    glEnd();

    //Boot 2
    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    glVertex2f(-29.5,-69);
    glVertex2f(-27.5,-69);
    glVertex2f(-27.5,-71);
    glVertex2f(-29.5,-71);
    glEnd();

    //Shopkeeper - 3

    //Head
    glPushMatrix();
    glTranslatef(-80,-50,0);
    glColor3f(1,0.85,0.67);
    circle(2, 3.2);
    glPopMatrix();

    //Face
    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex2f(-81,-49);
    glVertex2f(-80.5,-49);

    glVertex2f(-81,-49.1);
    glVertex2f(-80.5,-49.1);

    glVertex2f(-81,-49.2);
    glVertex2f(-80.5,-49.2);

    glVertex2f(-81,-49.3);
    glVertex2f(-80.5,-49.3);

    glVertex2f(-81,-49.4);
    glVertex2f(-80.5,-49.5);

    glVertex2f(-79.5,-49);
    glVertex2f(-79,-49);

    glVertex2f(-79.5,-49.1);
    glVertex2f(-79,-49.1);

    glVertex2f(-79.5,-49.2);
    glVertex2f(-79,-49.2);

    glVertex2f(-79.5,-49.3);
    glVertex2f(-79,-49.3);

    glVertex2f(-79.5,-49.4);
    glVertex2f(-79,-49.5);

    glVertex2f(-81,-51);
    glVertex2f(-79,-51);
    glEnd();

    //Body

    glBegin(GL_POLYGON);
    glColor3f(0,0,1);
    glVertex2f(-83,-60);
    glVertex2f(-83,-53);
    glVertex2f(-77,-53);
    glVertex2f(-77,-60);
    glEnd();

    //Store 3 - GOODS

    //Store stand
    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    glVertex2f(-90,-71);
    glVertex2f(-90,-60);
    glVertex2f(-70,-60);
    glVertex2f(-70,-71);
    glEnd();

    //Table Top
    glBegin(GL_POLYGON);
    glColor3f(1,1,0);
    glVertex2f(-92,-60);
    glVertex2f(-92,-57);
    glVertex2f(-68,-57);
    glVertex2f(-68,-60);
    glEnd();

    //Sign
    glBegin(GL_POLYGON);
    glColor3f(1,1,0);
    glVertex2f(-90,-47);
    glVertex2f(-90,-38);
    glVertex2f(-70,-38);
    glVertex2f(-70,-47);
    glEnd();

    storesign3(-87, -43.5, s4r, s4g, s4b, GLUT_BITMAP_TIMES_ROMAN_24, "IMPORTS");

    //Pillar 1
    glBegin(GL_POLYGON);
    glColor3f(1,0,1);
    glVertex2f(-88,-60);
    glVertex2f(-88,-47);
    glVertex2f(-86,-47);
    glVertex2f(-86,-60);
    glEnd();

    //Pillar 2
    glBegin(GL_POLYGON);
    glColor3f(1,0,1);
    glVertex2f(-74,-60);
    glVertex2f(-74,-47);
    glVertex2f(-72,-47);
    glVertex2f(-72,-60);
    glEnd();

    //NPC - 1

    //Head
    glPushMatrix();
    glTranslatef(-60,-50,0);
    glColor3f(1,0.85,0.67);
    circle(2, 3.2);
    glPopMatrix();

    //Eye
    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex2f(-59,-49);
    glVertex2f(-58.5,-49);
    glVertex2f(-59,-49.1);
    glVertex2f(-58.5,-49.1);
    glVertex2f(-59,-49.2);
    glVertex2f(-58.5,-49.2);
    glVertex2f(-59,-49.3);
    glVertex2f(-58.5,-49.3);
    glVertex2f(-59,-52);
    glVertex2f(-58,-52);
    glEnd();

    //Body
    glBegin(GL_POLYGON);
    glColor3f(1,0,1);
    glVertex2f(-62,-53);
    glVertex2f(-58,-53);
    glVertex2f(-58,-60);
    glVertex2f(-62,-60);
    glEnd();

    //Leg
    glBegin(GL_POLYGON);
    glColor3f(0.29,0.56,0.94);
    glVertex2f(-61,-60);
    glVertex2f(-59,-60);
    glVertex2f(-59,-66);
    glVertex2f(-61,-66);
    glEnd();

    //Boot
    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    glVertex2f(-61,-66);
    glVertex2f(-58,-66);
    glVertex2f(-58,-69);
    glVertex2f(-61,-69);
    glEnd();


    //NPC - 2

    //Head
    glPushMatrix();
    glTranslatef(-50,-50,0);
    glColor3f(1,0.85,0.67);
    circle(2, 3.2);
    glPopMatrix();

    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex2f(-52,-49);
    glVertex2f(-51.5,-49);
    glVertex2f(-52,-49.1);
    glVertex2f(-51.5,-49.1);
    glVertex2f(-52,-49.2);
    glVertex2f(-51.5,-49.2);
    glVertex2f(-52,-49.3);
    glVertex2f(-51.5,-49.3);
    glVertex2f(-52,-52);
    glVertex2f(-51,-52);
    glEnd();

    //Body
    glBegin(GL_POLYGON);
    glColor3f(1,0,1);
    glVertex2f(-52,-53);
    glVertex2f(-48,-53);
    glVertex2f(-48,-60);
    glVertex2f(-52,-60);
    glEnd();

    //Leg
    glBegin(GL_POLYGON);
    glColor3f(0.29,0.56,0.94);
    glVertex2f(-51,-60);
    glVertex2f(-49,-60);
    glVertex2f(-49,-66);
    glVertex2f(-51,-66);
    glEnd();

    //Boot
    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    glVertex2f(-52,-66);
    glVertex2f(-49,-66);
    glVertex2f(-49,-69);
    glVertex2f(-52,-69);
    glEnd();

    storesign3(dx1, dy1, dr1, dg1, db1, GLUT_BITMAP_TIMES_ROMAN_24, "Hello");
    storesign3(dx2, dy2, dr2, dg2, db2, GLUT_BITMAP_TIMES_ROMAN_24, "Hi");


    //Co-ordinate lines
    /*glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex2f(0.0,100);
    glVertex2f(0.0,-100);
    glVertex2f(100,0);
    glVertex2f(-100,0);
    glEnd();*/
    //glPushMatrix();
    //glTranslatef(cx,cy,0);
    //glScalef(2,0.5,1);
    //glRotatef(ca,0,0,-1);
    //glColor3f(cr,cg,cb);
    /*glBegin(GL_QUADS);
        glVertex2f(0,5);
        glVertex2f(5,5);
        glVertex2f(5,0);
        glVertex2f(0,0);
    glEnd();*/
    //circle(6,6);
    //glPopMatrix();
    glFlush();
    //glutSwapBuffers();
}
void spe_key(int key,int x, int y){
    switch(key){
        case GLUT_KEY_LEFT:
            x1 += 1;
            glutPostRedisplay();
            break;
        case GLUT_KEY_RIGHT:
            x1 += 1;
            glutPostRedisplay();
            break;
        case GLUT_KEY_UP:
            c1 += 0.001;
            c2 += 0.001;
            c3 += 0.001;
            c4 += 0.001;
            bs1 += 0.001;
            bs2 += 0.001;
            glutPostRedisplay();
            break;
        case GLUT_KEY_DOWN:
            c1 -= 0.001;
            c2 -= 0.001;
            c3 -= 0.001;
            c4 -= 0.001;
            bs1 -= 0.001;
            bs2 -= 0.001;
            glutPostRedisplay();
            break;
        default:
            break;

    }
}
void rotateC(){
        ca=ca+5;
        cx=cx+0.01;
        cr=0;
        cb=1;
        /*if(ca>=360){
            ca=0;
            glutIdleFunc(NULL);
        }*/
        glutPostRedisplay();

}


void normal_key(unsigned char key, int x, int y){
    switch(key){
    case 'q':
        llr = 1;
        llg = 0;
        llb = 0;
        glutPostRedisplay();
        break;

    case 'w':
        llr = 0.97;
        llg = 0.99;
        llb = 0.21;
        glutPostRedisplay();
        break;

    case 'e':
        llx = 78.6;
        lly = 70;
        glutPostRedisplay();
        break;

    case 'r':
        llx = 77.6;
        lly = 70;
        glutPostRedisplay();
        break;

    case 't':
        s1r = 0;
        s1g = 0;
        s1b = 0;

        s2r = 0;
        s2g = 0;
        s2b = 0;

        s3r = 0;
        s3g = 0;
        s3b = 0;

        s4r = 0;
        s4g = 0;
        s4b = 0;

        glutPostRedisplay();
        break;

    case 'y':
        s1r = 0.6;
        s1g = 0.3;
        s1b = 0.86;

        s2r = 1;
        s2g = 0;
        s2b = 0.43;

        s3r = 0.43;
        s3g = 0.87;
        s3b = 0;

        s4r = 0.5;
        s4g = 0.05;
        s4b = 0.07;

        glutPostRedisplay();
        break;

    case 'u':
        s1r = 0.5;
        s1g = 0.05;
        s1b = 0.07;

        s2r = 0.43;
        s2g = 0.87;
        s2b = 0.43;

        s3r = 1;
        s3g = 0;
        s3b = 0.43;

        s4r = 0.6;
        s4g = 0.3;
        s4b = 0.86;

        glutPostRedisplay();
        break;

    case 'i':
        s1r = 0.43;
        s1g = 0.87;
        s1b = 0;

        s2r = 0.5;
        s2g = 0.05;
        s2b = 0.07;

        s3r = 0.6;
        s3g = 0.3;
        s3b = 0.86;

        s4r = 1;
        s4g = 0;
        s4b = 0.43;

        glutPostRedisplay();
        break;

    case 'o':
        moveship();

        glutPostRedisplay();
        break;

    case 'p':
        moveshipback();

        glutPostRedisplay();
        break;

    case 'a':
        l1r = 0.0;
        l1g = 0.0;
        l1b = 0.0;

        glutPostRedisplay();
        break;

    case 's':
        l2r = 0.0;
        l2g = 0.0;
        l2b = 0.0;

        glutPostRedisplay();
        break;

    case 'd':
        l3r = 0.0;
        l3g = 0.0;
        l3b = 0.0;

        glutPostRedisplay();
        break;

    case 'f':
        l1r = 1.0;
        l1g = 1.0;
        l1b = 0.0;

        glutPostRedisplay();
        break;

    case 'g':
        l2r = 1.0;
        l2g = 1.0;
        l2b = 0.0;

        glutPostRedisplay();
        break;

    case 'h':
        l3r = 1.0;
        l3g = 1.0;
        l3b = 0.0;

        glutPostRedisplay();
        break;

    case 'j':
        ld1r = 0.5;
        ld1g = 0.28;
        ld1b = 0.04;

        glutPostRedisplay();
        break;

    case 'k':
        ld2r = 0.0;
        ld2g = 0.0;
        ld2b = 0.0;

        glutPostRedisplay();
        break;

    case 'l':
        ld1r = 0.003;
        ld1g = 0.74;
        ld1b = 1;

        glutPostRedisplay();
        break;

    case 'z':
        ld2r = 0.003;
        ld2g = 0.74;
        ld2b = 1;

        glutPostRedisplay();
        break;

    case 'x':
        dr1 = 0;
        dg1 = 0;
        db1 = 0;

        glutPostRedisplay();
        break;

    case 'c':
        dr1 = 0.003;
        dg1 = 0.74;
        db1 = 1;

        glutPostRedisplay();
        break;

    case 'v':
        dr2 = 0;
        dg2 = 0;
        db2 = 0;

        glutPostRedisplay();
        break;

    case 'b':
        dr2 = 0.003;
        dg2 = 0.74;
        db2 = 1;

        glutPostRedisplay();
        break;

    case 'm':
        glutIdleFunc(NULL);
        glutPostRedisplay();
	break;
    default:
        break;

    }
}

int main()
{
   glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
   glutInitWindowSize(1600,1000);
   glutInitWindowPosition(150,50);
   glutCreateWindow("CG FINAL LAB");
   init();
   glutDisplayFunc(myDisplay);
   glutIdleFunc(movebgobjects);
   glutSpecialFunc(spe_key);
   glutKeyboardFunc(normal_key);
   glutMainLoop();

   return 0;
}
