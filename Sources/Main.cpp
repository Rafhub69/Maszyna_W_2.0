#include "Shader.h"
#include "Main.h"

using std::cout;
using std::filesystem::exists;

int windowWidth = 1920, windowHeight = 1080;

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if ((GLFW_KEY_F1 <= key && GLFW_KEY_F12 >= key) || (GLFW_KEY_A <= key && GLFW_KEY_Z >= key) || GLFW_KEY_RIGHT_SHIFT == key && action == GLFW_PRESS)
    {
        if (GLFW_KEY_F2 == key)
        {

        } else if (GLFW_KEY_F3 == key)
        {

        }
        else if (GLFW_KEY_F4 == key)
        {

        }
        else if (GLFW_KEY_F5 == key)
        {

        }
        else if (GLFW_KEY_F6 == key)
        {

        }
        else if (GLFW_KEY_F7 == key)
        {

        }
        else if (GLFW_KEY_F8 == key)
        {

        }
        else if (GLFW_KEY_F9 == key)
        {

        }
        else if (GLFW_KEY_F10 == key)
        {

        }
        else if (GLFW_KEY_F11 == key)
        {

        }
        else if (GLFW_KEY_F12 == key)
        {

        }
    }
}

static void glfw_error_callback(int error, const char* description)
{
    fprintf(stderr, "Glfw Error %d: %s\n", error, description);
}

bool fileReading(string fileName, string& fileContent)
{
    std::ifstream file;
    string temporary = "";
    file.open(fileName);

    if (file.is_open())
    {
        while (getline(file, temporary))
        {
            fileContent += temporary;
        }
    }
    else
    {
        return false;
    }

    file.close();

    return true;
}

bool loadIconImage(GLFWwindow* window)
{
    const char* path = "C:/Miniatury/MaszynaW_Transparent_512X512.png";//MaszynaW_Transparent_512X512.png MaszynaW_MAINICON.png MaszynaW_icon_3.png

    if (exists(path))
    {
        int width = 0, height = 0, channels = 0;
        unsigned char* pixels = stbi_load(path, &width, &height, &channels, 4);

        GLFWimage image[1];
        image[0].width = width;
        image[0].height = height;
        image[0].pixels = pixels;

        glfwSetWindowIcon(window, 1, image);

        return true;
    }

    return false;
}

void newProgram()
{

}

void newOrder()
{

}


void draw(GLFWwindow* window)
{
    color white(0.99, 0.99, 0.99, 1.0), black(0.0, 0.0, 0.0, 1.0);
    color backgroundColor = black;

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {

        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        glClearColor(backgroundColor.r, backgroundColor.g, backgroundColor.b, backgroundColor.a);

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        if (ImGui::BeginMainMenuBar())
        {

            if (ImGui::BeginMenu("Plik"))
            {
                if (ImGui::BeginMenu("Nowy"))
                {
                    if (ImGui::MenuItem("Program"))
                    {
                        newProgram();
                    }

                    if (ImGui::MenuItem("Rozkaz"))
                    {
                        newOrder();
                    }

                    ImGui::EndMenu();
                }

                if (ImGui::MenuItem("Otwórz...  F3"))
                {
                    //Do something
                }

                if (ImGui::MenuItem("Zapisz      F2"))
                {
                    //Do something
                }

                if (ImGui::MenuItem("Zapisz jako..."))
                {
                    //Do something
                }

                if (ImGui::MenuItem("Wyjście"))
                {
                    break;
                }

                ImGui::EndMenu();
            }

            if (ImGui::BeginMenu("Widok"))
            {
                if (ImGui::MenuItem("Lista okien                        F5"))
                {
                    //Do something
                }

                if (ImGui::MenuItem("Okno edycyjne"))
                {
                    //Do something
                }

                if (ImGui::MenuItem("Lista rozkazów                 F10"))
                {
                    //Do something
                }

                if (ImGui::MenuItem("Obserwowane zmienne"))
                {
                    //Do something
                }

                if (ImGui::MenuItem("Jednostka centralna         F11"))
                {
                    //Do something
                }

                if (ImGui::MenuItem("Konsola we/wy                 F12"))
                {
                    //Do something
                }
                ImGui::EndMenu();
            }

            if (ImGui::BeginMenu("Projekt"))
            {
                if (ImGui::MenuItem("Zapisz listę rozkazów"))
                {
                    //Do something
                }

                if (ImGui::MenuItem("Ładuj listę rozkazów"))
                {
                    //Do something
                }

                if (ImGui::MenuItem("Opcje.."))
                {
                    //Do something
                }

                ImGui::EndMenu();
            }

            if (ImGui::BeginMenu("Wykonaj"))
            {
                if (ImGui::MenuItem("Program      F9"))
                {
                    //Do something
                }

                if (ImGui::MenuItem("Rozkaz        F8"))
                {
                    //Do something
                }

                if (ImGui::MenuItem("Takt             F7"))
                {
                    //Do something
                }

                if (ImGui::MenuItem("Do kursora  F4"))
                {
                    //Do something
                }

                if (ImGui::MenuItem("Reset"))
                {
                    //Do something
                }

                if (ImGui::MenuItem("Przerwij"))
                {
                    //Do something
                }

                ImGui::EndMenu();
            }

            if (ImGui::BeginMenu("Pomoc"))
            {
                if (ImGui::MenuItem("Zawartość"))
                {
                    
                }

                if (ImGui::MenuItem("Szukaj tematu"))
                {
                    //Do something
                }

                if (ImGui::BeginMenu("Zmień wygląd"))
                {
                    if (ImGui::MenuItem("Ciemny schemat"))
                    {
                        backgroundColor = black;
                        ImGui::StyleColorsDark();
                    }

                    if (ImGui::MenuItem("Jasny schemat"))
                    {
                        backgroundColor = white;
                        ImGui::StyleColorsLight();
                    }

                    ImGui::EndMenu();
                }
                ImGui::EndMenu();
            }

            ImGui::Text("%.1f FPS", ImGui::GetIO().Framerate);

            ImGui::EndMainMenuBar();
        }

        static char name[128] = "";
        ImGui::Text("Nome: "); ImGui::SameLine(); ImGui::InputText("##", name, IM_ARRAYSIZE(name));



        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }
}

GLFWwindow* mainInicjalisation()
{
    GLFWwindow* window = NULL;

    return window;
}

int main()
{
    glfwSetErrorCallback(glfw_error_callback);

     /* Initialize the library */
    if (!glfwInit())
    {
        return NULL;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);

    /* Create a windowed mode window and its OpenGL context */
    GLFWwindow* window = glfwCreateWindow(windowWidth, windowHeight, "Maszyna W", NULL, NULL);

    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    if (!loadIconImage(window))
    {
        cout << "Icon image doesn't exist.\n";
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);


    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;

    static const ImWchar range[] = { 0x0020,0x00FF, 0x0100, 0x017F };

    io.Fonts->AddFontFromFileTTF("C:/Windows/Fonts/Arial.ttf", 16.0f, 0, range);

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 440");

    if (glewInit() != GLEW_OK)
    {
        return -1;
    }

    Shader shader("Sources/Basic.shader");
    shader.Bind();

    draw(window);

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}

