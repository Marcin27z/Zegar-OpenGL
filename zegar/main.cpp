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
#include "cone.h"

using namespace std;

const GLuint WIDTH = 800, HEIGHT = 800;

static GLfloat cameraRotationAngleX = 7;
static GLfloat cameraRotationAngleY = -10;
static GLfloat zoom = -17;
static GLint showLight = 0;
static glm::vec3 debugMove(0,0,0);
static bool drawTower = true;

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mode) {
	//cout << key << endl;
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

	if (key == GLFW_KEY_T && action == GLFW_PRESS)
		drawTower = !drawTower;

	if (key == GLFW_KEY_L && action == GLFW_PRESS)
		showLight = !showLight;

	return;

	float delta = 1;
	if (key == GLFW_KEY_W && action == GLFW_PRESS)
		debugMove.y += delta;
	if (key == GLFW_KEY_A && action == GLFW_PRESS)
		debugMove.x -= delta;
	if (key == GLFW_KEY_S && action == GLFW_PRESS)
		debugMove.y -= delta;
	if (key == GLFW_KEY_D && action == GLFW_PRESS)
		debugMove.x += delta;
	if (key == GLFW_KEY_Q && action == GLFW_PRESS)
		debugMove.z += delta;
	if (key == GLFW_KEY_E && action == GLFW_PRESS)
		debugMove.z -= delta;
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
	if (zoom + yoffset < -0.25f && zoom + yoffset > -30.0f)
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

		// clock face and hands
		Face face(1.5f);

		// box
		Cube box(3.25, 2, 0.75);
		box.move(0, 0, -0.5);
		box.setColor(0, 0, 0);

		// gears
		Group gears;
		const float cogsScale = 0.7f;
		Cog cog(36, cogsScale);
		Cog cog2(12, cogsScale);
		Cog cog3(24, cogsScale);
		gears.add(&cog);
		gears.add(&cog2);
		gears.add(&cog3);

		cog.setAngularSpeed(20.0f);
		cog2.synchronizeSpeed(cog);
		cog3.synchronizeSpeed(cog);
		cog.rotate(90.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
		cog2.rotate(90.0f, 15.0f, 0.0f, 0.0f, 0.0f, 0.0f);
		cog3.rotate(90.0f, 7.5f, 0.0f, 0.0f, 0.0f, 0.0f);
		cog.move(0.0f, -0.2f, -1.0f);
		cog2.move(0.0f, -0.2f + cog.getRadius() + cog2.getRadius() + 0.1f * cogsScale, -1.0f);
		cog3.move(cog.getRadius() + cog3.getRadius() + 0.1f * cogsScale, -0.2f, -1.0f);

		// oscillators
		Cone cone1(1, 1.0f, 0);
		Cone cone2(1, 1.0f, 1);

		cone1.scale(0.3f, 0.7f, 0.3f);
		cone2.scale(0.3f, 0.7f, 0.3f);
		cone1.move(0.5f, -3.0f, -0.45f);
		cone2.move(-0.5f, -3.0f, -0.45f);

		// skybox
		Tower::Faces faces = static_cast<Tower::Faces>((int)Tower::Faces::ALL & ~(int)Tower::Faces::BOTTOM);
		Tower sky(40, 40, 40, faces);
		sky.loadTexture("Textures\\sky.png");

		// floor
		Tower brick(30, 30, 30, Tower::Faces::TOP);
		brick.move(0, -40, 0);
		brick.loadTexture("Textures\\brick.png");

		// tower
		Group tower;
		// roof
		Roof roof(4.5, 4.5, 4.5);
		roof.rotate(-90, 0, 0);
		roof.move(0, 2, -2);       
		tower.add(&roof);
		// tower level 0
		Tower towerLevel0(2, 2, 2);
		towerLevel0.rotate(90, 0, 0);
		towerLevel0.move(0,0,-2);
		tower.add(&towerLevel0);
		// tower level 1
		Tower towerLevel1(2, 2, 2); 
		towerLevel0.rotate(-90, 0, 0);
		towerLevel1.move(0, -4, -2); 
		tower.add(&towerLevel1);
		// tower level 2
		Tower towerLevel2(2, 2, 2); 
		towerLevel2.move(0, -8, -2); 
		tower.add(&towerLevel2);

		Group scene;
		scene.addAll(&tower, &cog, &cog2, &cog3, &face, &cone1, &cone2, &box);
		scene.move(0.0f, 0.0f, 2.0f);
		

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
			glm::vec3 lightPos(10.0f, 10.0f, 100.0f);
			glm::mat4 viewX, viewY, projection, transform, view;
			projection = glm::perspective(glm::radians(45.0f), GLfloat(WIDTH) / GLfloat(HEIGHT), 0.1f, 100.0f);
			viewX = glm::rotate(viewX, -glm::radians(cameraRotationAngleX), glm::vec3(0.0, 1.0, 0.0));
			viewY = glm::rotate(viewY, -glm::radians(cameraRotationAngleY), glm::vec3(1.0, 0.0, 0.0));

			GLuint projectionLoc = glGetUniformLocation(theProgram.get_programID(), "projection");
			GLuint viewLoc = glGetUniformLocation(theProgram.get_programID(), "view");
			GLuint transformLoc = glGetUniformLocation(theProgram.get_programID(), "transform");
			GLuint lightLoc = glGetUniformLocation(theProgram.get_programID(), "lightPos");
			GLuint lightColorLoc = glGetUniformLocation(theProgram.get_programID(), "lightColor");

			view = glm::translate(view, glm::vec3(0.0f, 0.0f, zoom)) * viewX * viewY;
			glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));
			glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
			glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));
			
			glUniform3fv(lightLoc, 1, glm::value_ptr(lightPos));
			glm::vec3 lightColor(1.0f, 1.0f, 1.0f); // white
			glUniform3fv(lightColorLoc, 1, glm::value_ptr(lightColor));
			glUniform1i(glGetUniformLocation(theProgram.get_programID(), "Texture0"), 0);

			// funkcja zmieniajaca stan rysowania oswietlenia, przyjmuje wartosc 0/1
			auto setLight = [&](GLint value) { 
				glUniform1i(glGetUniformLocation(theProgram.get_programID(), "showLight"), value);
			};
			auto move = [&](Node & obj) {
				if (debugMove.length() > 0.0001)
				{
					obj.move(debugMove.x, debugMove.y, debugMove.z);
					debugMove = glm::vec3(0, 0, 0);
					std::cout << "(x,y,z)=(" << obj.getX() << "," << obj.getY() << "," << obj.getZ() << ")\n";
				}
			};
			auto rot = [&](Node & obj) {
				if (debugMove.length() > 0.01)
				{
					obj.rotate(debugMove.x, debugMove.y, debugMove.z);
					std::cout << "(x,y,z)=(" << obj.getX() << "," << obj.getY() << "," << obj.getZ() << ")\n";
					std::cout << "(dx,dy,dz)=(" << debugMove.x << "," << debugMove.y << "," << debugMove.z << ")\n";
					debugMove = glm::vec3(0, 0, 0);
				}
			};

			theProgram.Use();
			setLight(showLight); // light switcher

			// gears
			cog.draw(deltaTime);
			cog2.draw(deltaTime);
			cog3.draw(deltaTime);

			// oscillators
			cone1.draw(deltaTime);
			cone2.draw(deltaTime);
			box.draw();

			// clock face and hands
			face.draw();
			face.tick(deltaTime);

			// floor
			brick.draw();

			// skybox
			setLight(0);
			sky.draw();
			setLight(showLight);

			// tower
			if(drawTower)
				tower.draw();

			// Swap the screen buffers
			glfwSwapBuffers(window);
		}
	} catch (exception ex) {
		cout << ex.what() << endl;
	}
	glfwTerminate();

	return 0;
}