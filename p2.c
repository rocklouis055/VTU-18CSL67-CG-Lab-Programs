#include<stdio.h>
#include<GL/glut.h>
int m;
float v[4][3]={{0,0,1},{-1,-1,0},{0,1,0},{1,-1,0}};
void triangle(float v1[],float v2[],float v3[]){
	glBegin(GL_TRIANGLES);
	glVertex3fv(v1);
	glVertex3fv(v2);
	glVertex3fv(v3);
	glEnd();
}
void divtriangle(float v1[],float v2[],float v3[],int m){
	if(m>0){
		float va[3]={(v1[0]+v2[0])/2,(v1[1]+v2[1])/2,(v1[2]+v2[2])/2};
		float vb[3]={(v3[0]+v2[0])/2,(v3[1]+v2[1])/2,(v3[2]+v2[2])/2};
		float vc[3]={(v1[0]+v3[0])/2,(v1[1]+v3[1])/2,(v1[2]+v3[2])/2};
		divtriangle(v1,va,vc,m-1);
		divtriangle(va,v2,vb,m-1);
		divtriangle(vc,vb,v3,m-1);
	}
	else{
		triangle(v1,v2,v3);
	}
}
void display(){
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glColor3f(1,0,0);
	divtriangle(v[1],v[2],v[3],m);
	glColor3f(0,1,0);
	divtriangle(v[1],v[2],v[0],m);
	glColor3f(0,0,1);
	divtriangle(v[0],v[2],v[3],m);
	glColor3f(1,0,1);
	divtriangle(v[1],v[0],v[3],m);
	glFlush();
}
int main(int argc,char **argv){
	printf("Enter no of iterations : ");
	scanf("%d",&m);
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("3D Gasket");
	glOrtho(-2,2,-2,2,-2,2);
	glEnable(GL_DEPTH_TEST);
	glutDisplayFunc(display);
	glutMainLoop();
}