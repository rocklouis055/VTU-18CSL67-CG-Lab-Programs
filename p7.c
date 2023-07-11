#include<stdlib.h>
#include<GL/glut.h>
int xmin=50,ymin=50,xmax=100,ymax=100,x0=90,y0=40,y1=200,x1=40;
int left=8,right=4,bottom=2,top=1;
float m;
void draw(){
	glColor3d(1,0,0);
	glBegin(GL_LINE_LOOP);
	glVertex2d(xmin,ymin);
	glVertex2d(xmax,ymin);
	glVertex2d(xmax,ymax);
	glVertex2d(xmin,ymax);
	glEnd();
	glBegin(GL_LINES);
	glVertex2d(x0,y0);
	glVertex2d(x1,y1);
	glEnd();
}
int outcode(int x,int y){
	int o=0;
	if(y<ymin)o|=bottom;
	if(y>ymax)o|=top;
	if(x<xmin)o|=left;
	if(x>xmax)o|=right;
	return(o);
}
void lineclip(){
	int o=0,x,y,a=0,d=0;
	int o1=outcode(x0,y0);
	int o2=outcode(x1,y1);
	do{
		if((o1|o2)==0){
			a=1;
			d=1;
		}
		else if((o1&o2)!=0){
			d=1;
		}
		else{
			if(o2!=0)
				o=o2;
			else
				o=o1;
			if(o&top){
                y=ymax;
                x=x0+(ymax-y0)/m;
            }
            else if(o&bottom){
                y=ymin;
                x=x0+(ymin-y0)/m;
            }
            else if(o&right){
                x=xmax;
                y=y0+(xmax-x0)*m;
            }
            else if(o&left){
                x=xmin;
                y=y0+(xmin-x0)*m;
            }
			if(o==o1){
				x1=x;
				y1=y;
				o1=outcode(x,y);
			}
			else{
				x0=x;
				y0=y;
				o2=outcode(x,y);
			}
		}
	}while(d==0);
	if(a){
		glPushMatrix();
		glTranslated(150,150,0);
		draw();
		glPopMatrix();
	}
}
void display(){
	// xmin=50,ymin=50,xmax=100,ymax=100,x0=90,y0=40,y1=200,x1=40;
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT);
	draw();
	lineclip();
	glFlush();
}
void main(int argc,char **argv){
	m=(y0-y1)/(x0-x1);
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Cohen sutherland algo");
	glutDisplayFunc(display);
	gluOrtho2D(0,500,0,500);
	glutMainLoop();
}