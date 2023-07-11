#include<GL/glut.h>
#include<stdio.h>
float v[8][3]={{-1,-1,-1},{-1,1,-1},{1,1,-1},{1,-1,-1},{-1,-1,1},{-1,1,1},{1,1,1},{1,-1,1}};
int view[3]={0,0,5};
void draw(int a,int b,int c,int d){
	glBegin(GL_QUADS);
	glVertex3f(v[a][0],v[a][1],v[a][2]);
	glVertex3f(v[b][0],v[b][1],v[b][2]);
	glVertex3f(v[c][0],v[c][1],v[c][2]);
	glVertex3f(v[d][0],v[d][1],v[d][2]);
	glEnd();
}
void display(){
	glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(view[0],view[1],view[2],0,0,0,0,-1,0);
	glColor3f(1,0,0);
    draw(0,1,2,3);
    glColor3f(0,1,0);
    draw(5,6,7,4);
    glColor3f(0,0,1);
    draw(0,1,5,4); 
    glColor3f(1,1,0);
    draw(6,2,3,7);
    glColor3f(1,0,1);
    draw(0,4,7,3);
    glColor3f(0,1,1);
    draw(1,2,6,5);
    glutSwapBuffers();
    glFlush();
}
void keys(unsigned char ch,int x,int y){
	if(ch=='a') view[0]--;
	if(ch=='d') view[0]++;
	if(ch=='w') view[1]++;
	if(ch=='s') view[1]--;
	if(ch=='z') view[2]++;
	if(ch=='x') view[2]--;
	// glutPostRedisplay();
    display();
}
int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(1000,1000);
    glutCreateWindow("CAMERA_CUBE");
    glMatrixMode(GL_PROJECTION);
    glFrustum(-2,2,-2,2,2,20);
    glMatrixMode(GL_MODELVIEW);
    glutDisplayFunc(display);
    glutKeyboardFunc(keys);
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
    return 0;
}