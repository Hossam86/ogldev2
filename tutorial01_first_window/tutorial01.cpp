#include <stdio.h>
#include <stdlib.h>

#define USE_GLAD

#ifdef USE_GLAD
#include <glad/glad.h>
#endif

#include <GLFW/glfw3.h>

int
main()
{
	if (!glfwInit())
	{
		fprintf(stderr, "Failed to initialize GLFW\n");
		getchar();
		return -1;
	}

	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

	GLFWwindow* window = glfwCreateWindow(1024, 768, "Tutorial01", NULL, NULL);

	if (window == NULL)
	{
		fprintf(stderr, "Failed to open GLFW window");
		getchar();
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	// glad: load all opengl function pointers (We should initialize GLAD before
	// we call any OpenGL function)
	//-------------------------------------------------------
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		fprintf(stderr, "Failed to initialize GLAD\n");
		getchar();
		glfwTerminate();
		return -1;
	}

	// ensure we can capture the excape key being passs below;
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	// Dark Blue Background
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

	do
	{
		// Clear the screen. It's not mentioned before Tutorial 02, but it can cause flickering, so it's there
		// nonetheless.
		glClear(GL_COLOR_BUFFER_BIT);

		// draw nothing, see you in tutorial 2!

		// swap buffers
		glfwSwapBuffers(window);
		glfwPollEvents();
	} while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window) == 0);

	// Close OpenGL window and terminate GLFW
	glfwTerminate();

	return 0;
}
