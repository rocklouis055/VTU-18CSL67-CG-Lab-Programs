#include<GL/glut.h>
float light_pos[]={2,2,2,1};
float ambient[]={1,1,1,1};
void align(){

    glRotatef(45,0,1,0);
    glRotatef(10,-1,0,0);
    glRotatef(10,0,0,-1);
}
void obj(float tx,float ty,float tz,float sx,float sy,float sz){
    align();
    glTranslatef(tx,ty,tz);
    glScalef(sx,sy,sz);
    glutSolidCube(1);
    glLoadIdentity();
}
void display(){
    // glClearColor(1,1,1,1);
glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
// WALLS
obj(0,0,0.5,1,1,0.04);
obj(-0.5,0,0,0.04,1,1);
obj(0,-0.5,0,1,0.04,1);
// LEGS
obj(0,-0.3,0,0.02,0.2,0.02);
obj(0.5,-0.3,0,0.02,0.2,0.02);
obj(0,-0.3,-0.5,0.02,0.2,0.02);
obj(0.5,-0.3,-0.5,0.02,0.2,0.02);
//TABLETOP
obj(0,-0.228,0,0.9,0.04,0.9);
//TEAPOT
glPushMatrix();
glTranslatef(0,-0.1,0);
glutSolidTeapot(0.15);
glPopMatrix();

glFlush();
}

int main(int argc,char **argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE|GLUT_DEPTH);
glutInitWindowSize(1000,1000);

glutCreateWindow("TEAPOT");
glutDisplayFunc(display);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0,GL_POSITION,light_pos);
    glMaterialfv(GL_FRONT,GL_AMBIENT,ambient);
glEnable(GL_DEPTH_TEST);
glutMainLoop();
return 0;
}
