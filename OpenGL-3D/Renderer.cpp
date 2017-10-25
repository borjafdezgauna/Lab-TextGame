#include "stdafx.h"
#include "Renderer.h"
#include "GraphicObject3D.h"
#include "Camera.h"
#include "../3rd-party/freeglut3/include/GL/freeglut.h"

Renderer* Renderer::m_pRenderer = nullptr;

Renderer::Renderer()
{
	m_pRenderer = this;
}


Renderer::~Renderer()
{
}

void Renderer::initialize(int argc, char** argv)
{

	//INIT GLUT/////////////////////
	////////////////////////////////
	//init window and OpenGL context
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1024, 768);
	glutCreateWindow(argv[0]);
	//glutFullScreen();
	GLfloat light_ambient[] = { 0.0,0.0,0.0,1.0 }; 
	GLfloat light_diffuse[] = { 1.0,1.0,1.0,1.0 }; 
	GLfloat light_specular[] = { 1.0,1.0,1.0,1.0 }; 
	GLfloat light_position[] = { 1.0,1.0,1.0,0.0 }; 
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient); 
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse); 
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular); 
	glLightfv(GL_LIGHT0, GL_POSITION, light_position); 

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	//callback functions
	glutDisplayFunc(__drawScene);
	glutReshapeFunc(__reshapeWindow);
	glEnable(GL_DEPTH_TEST);
}



void Renderer::reshapeWindow(int w, int h)
{
	//Reshape callback function
	m_windowHeight = h;
	m_windowWidth = w;
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
}

void Renderer::addObject(GraphicObject3D* pObj)
{
	m_objects3D.push_back(pObj);
}

void Renderer::addCamera(Camera* pCamera)
{
	m_cameras.push_back(pCamera);
	m_pActiveCamera = pCamera;
}

Camera* Renderer::getActiveCamera()
{
	return m_pActiveCamera;
}

void Renderer::drawScene()
{
	//clean the backbuffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//set the 2d modelview matrix
	if (m_pActiveCamera!=nullptr)
		m_pActiveCamera->applyMatrix();

	for (auto it = m_objects3D.begin(); it != m_objects3D.end(); ++it)
	{
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		(*it)->applyMatrix();
		(*it)->draw();
		glPopMatrix();
	}
}


//Nevermind these static functions: auxiliary stuff to fit openGL's callbacks
void Renderer::__drawScene()
{
	if (m_pRenderer)
		m_pRenderer->drawScene();
}
void Renderer::__reshapeWindow(int x, int y)
{
	if (m_pRenderer)
		m_pRenderer->reshapeWindow(x, y);
}