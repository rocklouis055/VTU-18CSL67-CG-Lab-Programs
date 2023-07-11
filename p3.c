#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
float k[3][3]={{200,250,300},{200,300,200},{1,1,1}},res[3][3],rot[3][3],x,y,t;
int f=0,f2=0;
void triangle(float v[3][3]){
	glBegin(GL_TRIANGLES);
	glVertex3f(v[0][0],v[1][0],v[2][0]);
	glVertex3f(v[0][1],v[1][1],v[2][1]);
	glVertex3f(v[0][2],v[1][2],v[2][2]);
	glEnd();
}
void multiply(){
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			res[i][j]=0;
			for(int a=0;a<3;a++){
				res[i][j]+=rot[i][a]*k[a][j];
			}
		}
	}
}
void rotfn(int m,int n){
	rot[0][0]=cos(t);
	rot[0][1]=-sin(t);
	rot[0][2]=m;
	rot[1][0]=sin(t);
	rot[1][1]=cos(t);
	rot[1][2]=n;
	rot[2][0]=0;
	rot[2][1]=0;
	rot[2][2]=1;
	multiply();
}

void display(){
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1,0,0);
	triangle(k);
	if (f==1){
		glColor3f(0,1,0);
		rotfn(0,0);
		triangle(res);
	}
	if(f2==1){
		glColor3f(0,0,1);
		rotfn(x*(1-cos(t))+y*sin(t),y*(1-sin(t))-x*cos(t));
		triangle(res);
	}
	glFlush();
}
void menu(int n){
	if (n==1){
		f=1;
		f2=0;
	}
	else if(n==2){
		f2=1;
		f=0;
	}
	else if(n==3){
		f=1;
		f2=1;
	}
	else if(n==4)
		exit(0);
	display();
}
int main(int argc,char **argv){
	printf("Enter the angle : ");
	scanf("%f",&t);
	t*=3.14/180;
	x=k[0][0];
	y=k[1][0];
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Triangle Rotation");
	glutCreateMenu(menu);
	glutAddMenuEntry("Rot about origin",1);
	glutAddMenuEntry("Rot about fixed point",2);
	glutAddMenuEntry("Rot about both",3);
	glutAddMenuEntry("Exit",4);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	gluOrtho2D(0,500,0,500);
	glutDisplayFunc(display);
	glutMainLoop();
}