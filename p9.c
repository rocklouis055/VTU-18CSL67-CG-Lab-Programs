#include<GL/glut.h>
#include<stdlib.h>
#include<math.h>
int flag=0,th=0;
int fact(int k){
	int s=1;
	for(;k>=1;k--)s*=k;
	return(s);
}
float combination(int n,int i){
	return(fact(n)/((fact(n-i)*fact(i))));
}
void curve(float cp[4][2]){
	int n=3,x,y,i;
	float tp,t;
	glBegin(GL_LINE_STRIP);
	for(t=0;t<=1;t+=0.001){
		x=0,y=0;
		for(i=0;i<4;i++){
			tp=combination(n,i)*pow(t,i)*pow(1-t,n-i);
			x+=cp[i][0]*tp;
			y+=cp[i][1]*tp;
		}
		glVertex2f(x,y);
	}
	glEnd();
}
void display(){
	float cp[4][2]={{100,400},{150,350},{200,450},{250,400}};
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT);
	if(flag){
		cp[1][0]+=10*sin(th*3.14/180);
		cp[1][1]+=10*sin(th*3.14/180);
		cp[2][0]+=10*sin(th*3.14/180);
		cp[2][1]+=10*sin(th*3.14/180);
		cp[3][0]+=10*sin(th*3.14/180);
		cp[3][1]+=10*sin(th*3.14/180);
		th+=5;
	}
	glPushMatrix();
	glColor3f(1,0.5,0);
	for(int i=0;i<20;i++){
		glTranslated(0,-1,0);
		curve(cp);
	}glColor3f(0,0,0);
	for(int i=0;i<20;i++){
		glTranslated(0,-1,0);
	}glColor3f(0,1,0);
	for(int i=0;i<20;i++){
		glTranslated(0,-1,0);
		curve(cp);
	}
	glPopMatrix();
	glLineWidth(5);
	glColor3f(0,0,0);
	glBegin(GL_LINES);
	glVertex2d(100,400);
	glVertex2d(100,100);
	glEnd();
	glFlush();
	glutSwapBuffers();
	glutPostRedisplay();
}
void menu(int i){
	flag=i;
	if (i==2)exit(0);
}
void main(int argc,char **argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Bezier Curve");
	glutDisplayFunc(display);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0,500,0,500);
	glMatrixMode(GL_MODELVIEW);
	glutCreateMenu(menu);
	glutAddMenuEntry("Start",1);
	glutAddMenuEntry("Stop",0);
	glutAddMenuEntry("Exit",2);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();
}