#include<GL/glut.h>
float v[8][3]={{-1,-1,-1},{-1,1,-1},{1,1,-1},{1,-1,-1},{-1,-1,1},{-1,1,1},{1,1,1},{1,-1,1}};
int t[3]={0,0,0},a=0;

void poly(int a,int b,int c,int d){
    glBegin(GL_POLYGON);
    glVertex3fv(v[a]);
    glVertex3fv(v[b]);
    glVertex3fv(v[c]);
    glVertex3fv(v[d]);
    glEnd();
}
void cube(){
    glColor3f(1,0,0);
    poly(0,1,2,3);
    glColor3f(1,1,0);
    poly(4,5,6,7);
    glColor3f(0,1,0);
    poly(0,1,5,4);
    glColor3f(0,1,1);
    poly(2,3,7,6);
    glColor3f(1,0,1);
    poly(0,3,7,4);
    glColor3f(0,0,1);
    poly(1,2,6,5);
}
void spin(){
    t[a]+=1;
    if(t[a]>=360)
        t[a]=0;
    display();
}
void display(){
    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glRotatef(t[0],1,0,0);
    glRotatef(t[1],0,1,0);
    glRotatef(t[2],0,0,1);
    cube();
    glutSwapBuffers();
    glFlush();
}
void mouse(int b,int s,int x,int y){
    if(b==GLUT_LEFT_BUTTON && s==GLUT_DOWN)a=1;
    if(b==GLUT_RIGHT_BUTTON && s==GLUT_DOWN)a=2;
    if(b==GLUT_MIDDLE_BUTTON && s==GLUT_DOWN)a=0;

}
int main(int argc,char **argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);
    glutCreateWindow("spinning");
    glMatrixMode(GL_PROJECTION);
    glOrtho(-2,2,-2,2,-2,2);
    glMatrixMode(GL_MODELVIEW);
    glutDisplayFunc(display);
    glutIdleFunc(spin);
    glutMouseFunc(mouse);
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
    return 0;
}