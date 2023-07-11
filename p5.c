#include<stdio.h>
#include<GL/glut.h>

int x1=200,y1=200,x2=100,y2=300,x3=200,y3=400,x4=300,y4=300;
float m;
int re[500],le[500],i,f=0,k=0;
void edgedetect(float x1,float y1,float x2,float y2){
    float x;
    if((y2-y1)!=0)
        m=(x2-x1)/(y2-y1);
    x=x1;
    printf("\n%d %f %f %f\n",x1,y1,x2,y2);
    for(i=y1;i<=y2;i++){
        printf("%f\n",x);
        if(x<le[i])
            le[i]=(int)x;
        if(x>re[i])
            re[i]=(int)x;
        x=x+m;
    }
    for(i=y1;i<y2;i++){
        printf("%d %d\n",le[i],re[i]);
    }
}
void scanfill(){
    int x,y;
    for(i=0;i<500;i++){
        le[i]=500;
        re[i]=0;
    }
    edgedetect(x1,y1,x2,y2);
    edgedetect(x1,y1,x4,y4);
    edgedetect(x2,y2,x3,y3);
    edgedetect(x4,y4,x3,y3);
    for(y=0;y<=500;y++){
        for(x=le[y];x<re[y];x++){
            glBegin(GL_POINTS);
            glVertex2d(x,y);
            glEnd();
            if(k==1)
                glFlush();
        }
    }
}
void display(){

    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0,0,1);
    glBegin(GL_LINE_LOOP);
    glVertex2f(x1,y1);
    glVertex2f(x2,y2);
    glVertex2f(x3,y3);
    glVertex2f(x4,y4);
    glEnd();
    glFlush();
    if (f==1)
        scanfill();
}
void init(){
    gluOrtho2D(0,500,0,500);
}
void menu(int i){
    k=0;
    if(i==2){
        f=0;
    }
    else if(i==1){
        f=1;
    }
    else if(i==3){
        f=1;
        k=1;
    }
    else
        exit(0);
    display();
}
int main(int argc,char **argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Polygon");

    glutCreateMenu(menu);
    display();
    glutAddMenuEntry("Fill",1);
    glutAddMenuEntry("NOT Fill",2);
    glutAddMenuEntry("Fill Animation",3);
    glutAddMenuEntry("Exit",4);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    init();
    glutMainLoop();
    return(0);
}