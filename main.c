#include "functions.h"


int main(int arg, char * argv[]) {

	GLFWwindow *window = NULL;
	const GLubyte *renderer;
	const GLubyte *version;

	if(!glfwInit()){
		fprintf( stderr,"ERROR: could not start GLFW3\n");
		return 1;
	}

	window = glfwCreateWindow( 800, 600, "Hello Triangle", NULL, NULL);
	if(!window){
		fprintf( stderr,"ERROR: could not open window with GLFW3\n");
		glfwTerminate();
		return 1;
	}
	glfwMakeContextCurrent( window );
	glewExperimental = GL_TRUE;
	glewInit();

	renderer	= glGetString(GL_RENDERER);
	version		= glGetString(GL_VERSION);
	printf("Renderer: %s\n", renderer);
	printf("OpenGL version supported %s\n", version);

	glEnable( GL_DEPTH_TEST);
	glDepthFunc( GL_LESS);

	Mainloop(window);

	glfwTerminate();
	return 0;
}
