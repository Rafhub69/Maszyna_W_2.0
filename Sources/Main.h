#pragma once
#include "imgui/imgui_impl_opengl3.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui.h"
#include <string>
#include <fstream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "stb_image.h"
#include <filesystem>
#include <iostream>
#include <fstream>

using std::string;

bool fileReading(string fileName, string& fileContent);

bool loadIconImage(GLFWwindow* window);

GLFWwindow* mainInicjalisation();

void draw(GLFWwindow* window);

int main();

class color
{
public:
    float r;
    float g;
    float b;
    float a;

    color(float r_, float g_, float b_, float a_)
    {
        r = r_;
        g = g_;
        b = b_;
        a = a_;
    }
};