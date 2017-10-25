#include "stdafx.h"
#include "InputHandler.h"
#include "Renderer.h"
#include "Sphere.h"
#include "../3rd-party/freeglut3/include/GL/freeglut.h"
#include "Camera.h"


int main(int argc, char** argv)
{
	Renderer renderer;
	InputHandler inputHandler(renderer);
	
	renderer.initialize(argc, argv);
	inputHandler.initialize();


	//init objects
	Sphere sphere1;
	sphere1.setColor(255, 0, 0);
	
	sphere1.setPosition(0, 0, 3);
	Sphere sphere2;
	sphere2.setColor(0, 255, 0);
	sphere2.setPosition(0, 0, 1);

	renderer.addObject(&sphere2);
	renderer.addObject(&sphere1);

	Camera camera;
	camera.setPosition(0, 0, 5);
	renderer.addCamera(&camera);


	while (1)
	{
		//UPDATE////////////////////
		////////////////////////////
		//process queued events
		glutMainLoopEvent();


		//RENDER////////////////////
		////////////////////////////
		glutPostRedisplay();
		glutSwapBuffers();
	}
   return 0;
   

}