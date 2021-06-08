#include "functions.h"




void Mainloop(GLFWwindow * wnd){

	GLuint vao;
	GLuint vbo;

	GLfloat points[] = { 0.0f, 0.5f, 0.0f, 0.5f, -0.5f, 0.0f, -0.5f, -0.5f, 0.0f };

	const char *vertex_shader = "#version 410\n"
								"in vec3 vp;"
								"void main () {"
								"	gl_Position = vec4 (vp, 1.0);"
								"}";

	const char *fragment_shader	  = "#version 410\n"
									"out vec4 frag_colour;"
									"void main () {"
									"	frag_colour = vec4 (0.5, 0.0, 0.5, 1.0);"
									"}";


	GLuint		vShader[3];

	glGenBuffers( 1, &vbo);
	glBindBuffer( GL_ARRAY_BUFFER, vbo);
	glBufferData( GL_ARRAY_BUFFER, 9 * sizeof(GLfloat), points, GL_STATIC_DRAW);

	glGenVertexArrays( 1, &vao);
	glBindVertexArray(vao);
	glEnableVertexAttribArray(0);

	glBindBuffer( GL_ARRAY_BUFFER, vbo);
	glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

	vShader[1] = glCreateShader( GL_VERTEX_SHADER );
	glShaderSource( vShader[1], 1, &vertex_shader, NULL);
	glCompileShader( vShader[1]);

	vShader[2] = glCreateShader( GL_FRAGMENT_SHADER );
	glShaderSource( vShader[2], 1, &fragment_shader, NULL);
	glCompileShader( vShader[2]);

	vShader[0]		= glCreateProgram();
	glAttachShader( vShader[0], vShader[2]);
	glAttachShader( vShader[0], vShader[1]);
	glLinkProgram( vShader[0]);

	while(!glfwWindowShouldClose(wnd)){

		if(glfwGetKey( wnd, GLFW_KEY_ESCAPE) == GLFW_PRESS){
			glfwSetWindowShouldClose( wnd, 1);
		}
		
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	
		glUseProgram(vShader[0]);
		glBindVertexArray(vao);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glfwPollEvents();
		glfwSwapBuffers(wnd);

	}

}
