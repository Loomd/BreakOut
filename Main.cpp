#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

int main(){

	//initialize glfw 
	glfwInit();

	//Defining the version of openGL and profile (only modern functions)
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//Create a GLFWwindow object 800 x 800 pixels. Params: width, height, name, fullscreen, ....
	GLFWwindow* window = glfwCreateWindow(800, 800, "PracticeOPENGL", NULL, NULL);
	//Error handling for failure to create a window.
	if (window == NULL) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	//adds the window object current context.
	glfwMakeContextCurrent(window);

	//Load Glad so it configures OpenGL
	gladLoadGL();

	//Specify the viewport of OpenGL in the Window x,y -> x,y
	glViewport(0, 0, 800, 800);

	//Color of the background
	glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
	//clean the back buffer and assign the new color to it
	glClear(GL_COLOR_BUFFER_BIT);
	//swap the back buffer with the front buffer.
	glfwSwapBuffers(window);

	//Main while loop
	while (!glfwWindowShouldClose(window)) {
		//Handles user interaction
		glfwPollEvents();
	}

	//Cleanup
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}