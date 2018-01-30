#include <GL/glut.h>

float angle = 0.0f;

void ChangeSize(int w, int h)
{
	//防止被除数等于0
	if (h == 0)
		h == 1;
	float ratio = w*1.0 / h;

	//使用投影矩阵
	glMatrixMode(GL_PROJECTION);

	//初始化矩阵
	glLoadIdentity();

	//设置观察区域
	glViewport(0, 0, w, h);

	//设置正确的投影方式
	gluPerspective(45.0f, ratio, 0.01f, 100.0f);

	//回到模型观察矩阵
	glMatrixMode(GL_MODELVIEW);
}

void RenderScene(void)
{
	//清除颜色和深度缓冲
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//重新设置矩阵
	glLoadIdentity();
	//设置相机
	gluLookAt( 0.0f, 0.0f, 10.0f,
			   0.0f, 0.0f,  0.0f,
			   0.0f, 1.0f,  0.0f);
	glRotatef(angle, 0.0f, 1.0f, 0.0f);

	glBegin(GL_TRIANGLES);
	glVertex3f(-2.0f, -2.0f, 0.0f);
	glVertex3f( 2.0f,  0.0f, 0.0f);
	glVertex3f( 0.0f,  2.0f, 0.0f);
	glEnd();

	angle += 0.1f;

	glutSwapBuffers();
}



int main(int argc, char* argv[])
{
	//初始化GLUT并建立窗口
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(320, 320);
	glutCreateWindow("GLUT-Tutorial 3D-By Yvan");

	//呼叫回调函数
	glutDisplayFunc(RenderScene);
	glutReshapeFunc(ChangeSize);
	glutIdleFunc(RenderScene);
	glutMainLoop();
	return 1;
}

