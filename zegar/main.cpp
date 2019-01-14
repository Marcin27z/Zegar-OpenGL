#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <SOIL.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>

#include "shprogram.h"
#include "cube.h"
#include "group.h"
#include "ring.h"
#include "cog.h"
#include "roof.h"
#include "tower.h"
#include "face.h""

using namespace std;

const GLuint WIDTH = 800, HEIGHT = 800;

static GLfloat cameraRotationAngleX = 5.0f;
static GLfloat cameraRotationAngleY = 45.0f;
static GLfloat zoom = -5.0f;
static GLint showLight = 1;

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mode) {
	cout << key << endl;
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
	if (key == GLFW_KEY_RIGHT && action == GLFW_REPEAT)
		cameraRotationAngleX += 1.0f;
	if (key == GLFW_KEY_LEFT && action == GLFW_REPEAT)
		cameraRotationAngleX -= 1.0f;
	if (key == GLFW_KEY_UP && action == GLFW_REPEAT)
		cameraRotationAngleY -= 1.0f;
	if (key == GLFW_KEY_DOWN && action == GLFW_REPEAT)
		cameraRotationAngleY += 1.0f;

	if (key == GLFW_KEY_L && action == GLFW_PRESS)
		showLight = !showLight;
}

double mouseOldPosX, mouseOldPosY;

void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
	if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS) {
		glfwGetCursorPos(window, &mouseOldPosX, &mouseOldPosY);
	}
}

void cursorCallback(GLFWwindow* window, double mousePosX, double mousePosY) {
	int state = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT);
	if (state == GLFW_PRESS) {
		cameraRotationAngleX += mousePosX - mouseOldPosX;
		cameraRotationAngleY += mousePosY - mouseOldPosY;
		mouseOldPosX = mousePosX;
		mouseOldPosY = mousePosY;
	}
}

void scrollCallback(GLFWwindow* window, double xoffset, double yoffset) {
	if (zoom + yoffset < -0.5f && zoom + yoffset > -20.0f)
		zoom += yoffset;
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
		glfwSetMouseButtonCallback(window, mouseButtonCallback);
		glfwSetCursorPosCallback(window, cursorCallback);
		glfwSetScrollCallback(window, scrollCallback);

		glewExperimental = GL_TRUE;
		if (glewInit() != GLEW_OK)
			throw exception("GLEW Initialization failed");

		glViewport(0, 0, WIDTH, HEIGHT);
		glEnable(GL_DEPTH_TEST);

		// Build, compile and link shader program
		ShaderProgram theProgram("zegar.vert", "zegar.frag");

		Group gears;
		Cog cog(36, 1.0f);
		Cog cog2(12, 1.0f);
		Cog cog3(24, 1.0f);

		gears.add(&cog);
		gears.add(&cog2);
		gears.add(&cog3);

		cog.setAngularSpeed(20.0f);
		cog2.synchronizeSpeed(cog);
		cog3.synchronizeSpeed(cog);
		cog2.rotate(0.0f, 15.0f, 0.0f, 0.0f, 0.0f, 0.0f);
		cog3.rotate(0.0f, 7.5f, 0.0f, 0.0f, 0.0f, 0.0f);
		cog2.move(cog.getRadius() + cog2.getRadius() + 0.1f, 0.0f, 0.0f);
		cog3.move(0.0f, 0.0f, cog.getRadius() + cog3.getRadius() + 0.1f);

		// main event loop
		while (!glfwWindowShouldClose(window)) {

			static float deltaTime = 0.0f, lastFrame = 0.0f;
			float currentFrame = glfwGetTime();
			deltaTime = currentFrame - lastFrame;
			lastFrame = currentFrame;

			// Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
			glfwPollEvents();

			// Clear the colorbuffer
			glClearColor(0.1f, 0.2f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			glm::mat4 viewX, viewY, projection, transform, view;
			projection = glm::perspective(glm::radians(45.0f), GLfloat(WIDTH) / GLfloat(HEIGHT), 0.1f, 100.0f);
			viewX = glm::rotate(viewX, -glm::radians(cameraRotationAngleX), glm::vec3(0.0, 1.0, 0.0));
			viewY = glm::rotate(viewY, -glm::radians(cameraRotationAngleY), glm::vec3(1.0, 0.0, 0.0));

			GLuint projectionLoc = glGetUniformLocation(theProgram.get_programID(), "projection");
			GLuint viewLoc = glGetUniformLocation(theProgram.get_programID(), "view");
			GLuint transformLoc = glGetUniformLocation(theProgram.get_programID(), "transform");
			GLuint lightLoc = glGetUniformLocation(theProgram.get_programID(), "lightPos");
			GLuint lightColorLoc = glGetUniformLocation(theProgram.get_programID(), "lightColor");

			transform = viewX * viewY;
			view = glm::translate(view, glm::vec3(0.0f, 0.0f, zoom));
			glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));
			glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
			glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));
			glm::vec3 lightPos(0.0f, 0.0f, 15.0f);
			glUniform3fv(lightLoc, 1, glm::value_ptr(lightPos));
			glm::vec3 lightColor(1.0f, 1.0f, 1.0f); // white
			glUniform3fv(lightColorLoc, 1, glm::value_ptr(lightColor));
			glUniform1i(glGetUniformLocation(theProgram.get_programID(), "Texture0"), 0);

			// funkcja zmieniajaca stan rysowania oswietlenia, przyjmuje wartosc 0/1
			auto setLight = [&](GLint value) { 
				glUniform1i(glGetUniformLocation(theProgram.get_programID(), "showLight"), value);
			};
			setLight(showLight); // ustawiamy wartosc glowna na poczatku petli
			theProgram.Use();

			cog.draw(deltaTime);
			cog2.draw(deltaTime);
			cog3.draw(deltaTime);

			// Swap the screen buffers
			glfwSwapBuffers(window);
		}
	} catch (exception ex) {
		cout << ex.what() << endl;
	}
	glfwTerminate();

	return 0;
}