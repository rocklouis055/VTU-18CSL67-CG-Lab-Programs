#include<stdio.h>
#include<GL/glut.h>

void display(){
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT);
	printf("Enter x0,y0,x1,y1 : ");
	int x0,x1,y0,y1;
	scanf("%d %d %d %d",&x0,&y0,&x1,&y1);
	float dx,dy,p;
	dx=x1-x0;
	dy=y1-y0;
	p=2*dy-dx;
	glColor3f(1,0,0);
	glBegin(GL_POINTS);
	while(x0<x1){
		if(p<0){
			p=p+2*dy;
			x0+=1;
		}
		else{
			p=p+2*dy-2*dx;
			x0+=1;
			y0+=1;
		}
		printf("Points are : %d,%d\n",x0,y0);
		glVertex2d(x0,y0);
	}
	glEnd();
	glFlush();
}
void init(){
	
}
int main(int argc,char **argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Brehensam line drawing algo");
	gluOrtho2D(0,500,0,500);
	glutDisplayFunc(display);
	glutMainLoop();

}