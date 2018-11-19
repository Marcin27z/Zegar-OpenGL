#define GLEW_STATIC
#include <GL/glew.h>
#include "shprogram.h"
#include <GLFW/glfw3.h>
#include <SOIL.h>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "cube.h"
#include "group.h"

using namespace std;

const GLuint WIDTH = 800, HEIGHT = 800;

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mode) {
	cout << key << endl;
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}

int main() {
	if (glfwInit() != GL_TRUE) {
		cout << "GLFW initialization failed" << endl;
		return -1;
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	try {
		GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Zegar", nullptr, nullptr);
		if (window == nullptr)
			throw exception("GLFW window not created");
		glfwMakeContextCurrent(window);
		glfwSetKeyCallback(window, keyCallback);

		glewExperimental = GL_TRUE;
		if (glewInit() != GLEW_OK)
			throw exception("GLEW Initialization failed");

		glViewport(0, 0, WIDTH, HEIGHT);
		glEnable(GL_DEPTH_TEST);

		// Build, compile and link shader program
		ShaderProgram theProgram("zegar.vert", "zegar.frag");

		Group group;
		Cube cube(0.5f, 0.5f, 0.5f);
		group.add(&cube);

		// main event loop
		while (!glfwWindowShouldClose(window)) {
			// Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
			glfwPollEvents();

			// Clear the colorbuffer
			glClearColor(0.1f, 0.2f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			theProgram.Use();
			group.draw();
			// Swap the screen buffers
			glfwSwapBuffers(window);
		}
	} catch (exception ex) {
		cout << ex.what() << endl;
	}
	glfwTerminate();

	return 0;
}