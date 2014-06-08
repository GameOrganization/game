#include <resource.h>   //this might not be necessary after all
#define GLEW_STATIC //use static library instead of dynamically-linked-libary (.dll)
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
static void error_callback(int error, const char* description) {
    //called if an error occurs
    std::cout << "Error " << error << ": " << description << std::endl;
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    //called when a key is pressed
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) //if escape key is pressed
        glfwSetWindowShouldClose(window, GL_TRUE);  //close the window, exiting the loop
}
int main(void) {
    glfwSetErrorCallback(error_callback); //tell GLFW to use the error_callback function
    if (!glfwInit())    //init GLFW and exit if there was an error
        exit(EXIT_FAILURE);
    GLFWwindow* window = glfwCreateWindow(640, 480, "Simple example", NULL, NULL);  //create basic window
    if (!window) {  //if window==NULL, exit
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window); //make it the current opengl context (where things are rendered to i guess)
    glfwSetKeyCallback(window, key_callback);   //set the key_callback
    if (glewInit() != GLEW_OK) {    //initialize GLEW and exit if there was a problem
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    std::cout << glewGetString(GLEW_VERSION) << std::endl;  //print the current version of GLEW

    while (!glfwWindowShouldClose(window)) { //while the window isnt closed...
        /* MOST OF THIS IS REALLY OLD OPENGL, WILL BE USING NEWER VERSION */
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);    //get the width and height of the buffer we're rendering to
        float ratio = width / (float) height;   //aspect ratio
        glViewport(0, 0, width, height);    //set the viewport dimensions
        glClear(GL_COLOR_BUFFER_BIT);   //clear the screen
        glMatrixMode(GL_PROJECTION);    //select the projection matrix
        glLoadIdentity();               //load the identity
        glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);   //orthogonal view (2d)
        //projection matrix now transforms a 3d point into a 2d coordinate on screen
        glMatrixMode(GL_MODELVIEW);     //select the model*view matrix
        glLoadIdentity();               //load identity
        glRotatef((float) glfwGetTime() * 50.f, 0.f, 0.f, 1.f); //rotate
        //modelview matrix now rotates a 3d point by the current time*50 degrees
        glBegin(GL_TRIANGLES);  //start drawing trangles, each call before glEnd() is used
        //3 colored vertices, it will interpolate colors between the vertices
        glColor3f(1.f, 0.f, 0.f);
        glVertex3f(-0.6f, -0.4f, 0.f);
        glColor3f(0.f, 1.f, 0.f);
        glVertex3f(0.6f, -0.4f, 0.f);
        glColor3f(0.f, 0.f, 1.f);
        glVertex3f(0.f, 0.6f, 0.f);
        glEnd();    //draw triangles based on the previous input
        glfwSwapBuffers(window);    //show what we rendered
        glfwPollEvents();   //check for keys pressed and other events
    }
    glfwDestroyWindow(window);  //close the window
    glfwTerminate();    //exit
    exit(EXIT_SUCCESS);
}
