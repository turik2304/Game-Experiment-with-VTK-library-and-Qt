
//Подключение заголовочных файлов
#include "gameWindow.h"
#include "ui_gameWindow.h"
#include <vtkTransform.h>
#include <vtkRenderWindowInteractor.h>

vtkActor * tankActor;
vtkActor * sphereActor;
vtkTransform * trans = vtkTransform::New();;
vtkSphereSource *sphere;
vtkRenderer * renderer;
vtkRenderWindow * renWin;
vtkRenderWindowInteractor * renderWindowInteractor;

float rot = 0.0f;
float up = 0.0f;
float down = 0.0f;
float right = 0.0f;
float left = 0.0f;
double posArr[3];
double posCam[3];
double step = 2;
double stepSphere = 4;
double radiusSphere = 2;
double colorRedSphere = 0;
double colorGreenSphere = 0;
double colorBlueSphere = 0;
double shotDist = 300;
bool existSphrere = false;
bool parseCoord = true;
double x = 0;
double y = 0;
double z = 0;
double correctionStep = 0.5;
double correctionX = -33.5;
double correctionY = -62;
double correctionZ = 50;


class RotateCommand : public vtkCommand
{
public:
    vtkTypeMacro(RotateCommand, vtkCommand);

    static RotateCommand * New()
    {
        return new RotateCommand;
    }

    void Execute(vtkObject * vtkNotUsed(caller),
                 unsigned long vtkNotUsed(eventId),
                 void * vtkNotUsed(callData))
    {
        tankActor->GetPosition(posArr);
      //  tankActor->SetOrientation(1,0,0);
        if (existSphrere) {
            if (parseCoord) {
                x = posArr [0] + correctionX;
                y = posArr [1] + correctionY;
                z = posArr [2] + correctionZ;
                parseCoord = false;
            }
            sphereActor->SetPosition(x, y , z = z + stepSphere);
            tankActor->GetProperty()->SetColor(colorRedSphere = colorRedSphere + 0.01, colorGreenSphere = colorGreenSphere + 0.02, colorBlueSphere = colorBlueSphere + 0.05);

            sphereActor->GetProperty()->SetColor(colorRedSphere = colorRedSphere + 0.05, colorGreenSphere = colorGreenSphere + 0.02, colorBlueSphere = colorBlueSphere + 0.01);
            if (colorRedSphere > 1) {
                colorRedSphere = 0;
            }
            if (colorGreenSphere > 1) {
                colorGreenSphere = 0;
            }
            if (colorBlueSphere > 1) {
                colorBlueSphere = 0;
            }
            std::cout << abs(posArr[2] - z) << std::endl;
            if (abs(posArr[2] - z) > shotDist) {
                std::cout << "Actor delete!!!!!!!!!!!!" << std::endl;
                renderer->RemoveActor(sphereActor);
                existSphrere = false;
                parseCoord = true;
                renderer->Render();
            }
            if (abs(posArr[2] - z) < 100) {
                tankActor->SetPosition(posArr[0], posArr[1], posArr[2]=posArr[2]-0.5);
            }
        }
        //   tankActor->RotateZ(rot++);
        renWin->Render();
    }
};

class KeyPressInteractorStyle : public vtkInteractorStyleTrackballCamera
{
public:
    static KeyPressInteractorStyle* New();
    vtkTypeMacro(KeyPressInteractorStyle, vtkInteractorStyleTrackballCamera);

    virtual void OnKeyPress() override
    {
        // Get the keypress
        vtkRenderWindowInteractor *rwi = this->Interactor;
        std::string key = rwi->GetKeySym();

        // Output the key that was pressed
        std::cout << "Pressed " << key << std::endl;

        // Handle an arrow key
        if(key == "Down")
        {
            std::cout << "The Down arrow was pressed." << std::endl;
            tankActor->SetPosition(posArr[0], posArr[1], posArr[2]=posArr[2]-step);
        }
        if(key == "Up")
        {
            std::cout << "The Up arrow was pressed." << std::endl;
            std::cout << abs(-10) << std::endl;
            tankActor->SetPosition(posArr[0], posArr[1], posArr[2]=posArr[2]+step);
        }

        if(key == "Left")
        {
            std::cout << "The Left arrow was pressed." << std::endl;
            tankActor->SetPosition(posArr[0]=posArr[0]+step, posArr[1], posArr[2]);
        }

        if(key == "Right")
        {
            std::cout << "The Right arrow was pressed." << std::endl;
            tankActor->SetPosition(posArr[0]=posArr[0]-step, posArr[1], posArr[2]);
        }

        if(key == "Control_R")
        {
            std::cout << "Actor delete" << std::endl;
            renderer->RemoveActor(sphereActor);
            renderer->Render();

        }
        if(key == "1")
        {
            correctionX = correctionX + correctionStep;
            std::cout << "correctionX = " << correctionX << std::endl;
            std::cout << "correctionY = " << correctionY << std::endl;
            std::cout << "correctionZ = " << correctionZ << std::endl;
        }
        if(key == "2")
        {
            correctionY = correctionY + correctionStep;
            std::cout << "correctionX = " << correctionX << std::endl;
            std::cout << "correctionY = " << correctionY << std::endl;
            std::cout << "correctionZ = " << correctionZ << std::endl;

        }
        if(key == "4")
        {
            correctionZ = correctionZ + correctionStep;
            std::cout << "correctionX = " << correctionX << std::endl;
            std::cout << "correctionY = " << correctionY << std::endl;
            std::cout << "correctionZ = " << correctionZ << std::endl;

        }
        if(key == "5")
        {
            correctionX = correctionX - correctionStep;
            std::cout << "correctionX = " << correctionX << std::endl;
            std::cout << "correctionY = " << correctionY << std::endl;
            std::cout << "correctionZ = " << correctionZ << std::endl;

        }
        if(key == "6")
        {
            correctionY = correctionY - correctionStep;
            std::cout << "correctionX = " << correctionX << std::endl;
            std::cout << "correctionY = " << correctionY << std::endl;
            std::cout << "correctionZ = " << correctionZ << std::endl;

        }
        if(key == "7")
        {
            correctionZ = correctionZ - correctionStep;
            std::cout << "correctionX = " << correctionX << std::endl;
            std::cout << "correctionY = " << correctionY << std::endl;
            std::cout << "correctionZ = " << correctionZ << std::endl;

        }

        if(key == "z")
        {
            shotDist = shotDist - 30;
            std::cout << "shotDist = " << shotDist << std::endl;
        }
        if(key == "x")
        {
            shotDist = shotDist + 30;
            std::cout << "shotDist = " << shotDist << std::endl;
        }
        if(key == "c")
        {
            stepSphere = stepSphere - 1;
            std::cout << "speedShot = " << stepSphere << std::endl;
        }
        if(key == "v")
        {
            stepSphere = stepSphere + 1;
            std::cout << "speedShot = " << stepSphere << std::endl;
        }
        if(key == "b")
        {
            radiusSphere = radiusSphere - 0.5;
            std::cout << "radiusSphere = " << radiusSphere << std::endl;
        }
        if(key == "n")
        {
            radiusSphere = radiusSphere + 0.5;
            std::cout << "radiusSphere = " << radiusSphere << std::endl;
        }
        if(key == "Shift_R")
        {
            std::cout << "Add sphereActor" << std::endl;
            sphere = vtkSphereSource::New();
            sphere->SetRadius(radiusSphere);
            sphere->SetThetaResolution(100);
            sphere->SetPhiResolution(100);
            sphereActor = vtkActor::New();
            sphereActor->GetProperty()->SetColor(0,0,0);
            auto sphereMapper = vtkPolyDataMapper::New();
            sphereMapper->SetInputConnection(sphere->GetOutputPort());
            sphereActor->SetPosition(posArr[0], posArr[1], posArr[2]);
            sphereActor->SetMapper(sphereMapper);
            renderer->AddActor(sphereActor);
            existSphrere = true;

        }

        // Forward events
        vtkInteractorStyleTrackballCamera::OnKeyPress();
    }
};
vtkStandardNewMacro(KeyPressInteractorStyle);

//Основной конструктор класса
GameWindow::GameWindow(QWidget *parent) : QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this); //Установка виджета визуализации QVTKWidget
    //Основной алгоритм

    // Create render window

    auto colors = vtkSmartPointer<vtkNamedColors>::New();
    renderer = vtkRenderer::New();
    renderer->SetBackground2(colors->GetColor3d("Gold").GetData());
    renderer->SetBackground(colors->GetColor3d("Wheat").GetData());
    renderer->GradientBackgroundOn();

    auto camera = vtkSmartPointer<vtkCamera>::New();
    camera->SetPosition(-416.814, 120.711, -815.989);
    camera->SetFocalPoint(-385, -169.4, 219);
    camera->SetViewUp(0, 1, 0);
    camera->Elevation(2);
    camera->Zoom(0.9);
    camera->SetClippingRange(0.1, 5000);

    renderer->SetActiveCamera(camera);

    renWin = vtkRenderWindow::New();
    renWin->AddRenderer(renderer);
    renWin->SetSize(1200,600);

    // Create a plane
    //-------------------------------------------------------------------
    vtkSmartPointer<vtkSTLReader> reader =
            vtkSmartPointer<vtkSTLReader>::New();
    reader->SetFileName("/home/artur/Qt_projects/Models/IS7/IS7 v3.3.stl");

    vtkSmartPointer<vtkTransform> transform =
            vtkSmartPointer<vtkTransform>::New();
    transform->Scale(20,20,20);

    vtkSmartPointer<vtkTransformFilter> transformFilter =
            vtkSmartPointer<vtkTransformFilter>::New();
    transformFilter->SetInputConnection(reader->GetOutputPort());
    transformFilter->SetTransform(transform);

    vtkSmartPointer<vtkPolyDataMapper> mapperTank =
            vtkSmartPointer<vtkPolyDataMapper>::New();
    mapperTank->SetInputConnection(transformFilter->GetOutputPort());

    tankActor = vtkActor::New();
    tankActor->RotateX(-90);
    tankActor->SetPosition(-376,-16,34);

    tankActor->SetMapper(mapperTank);

    auto importer = vtkSmartPointer<vtkOBJImporter>::New();
    importer->SetFileName("/home/artur/Qt_projects/Models/HousesOBJ/awp_india/awp_india.obj");
    importer->SetFileNameMTL("/home/artur/Qt_projects/Models/HousesOBJ/awp_india/awp_india.mtl");
    importer->SetTexturePath("/home/artur/Qt_projects/Models/HousesOBJ/awp_india/textures/");
    importer->SetRenderWindow(renWin);
    importer->Update();


    //--------------------------------------------------------------------

    //  renderer->AddActor(texturedPlane);
    renderer->AddActor(tankActor);

    // Create a RenderWindowInteractor
    renderWindowInteractor = vtkRenderWindowInteractor::New();
    renderWindowInteractor->SetRenderWindow(renWin);
    renderWindowInteractor->Initialize();
    renderWindowInteractor->CreateRepeatingTimer(5);
    RotateCommand * rotateCallback =  RotateCommand::New();
    renderWindowInteractor->AddObserver(vtkCommand::TimerEvent, rotateCallback );

    vtkSmartPointer<KeyPressInteractorStyle> style =
            vtkSmartPointer<KeyPressInteractorStyle>::New();
    renderWindowInteractor->SetInteractorStyle(style);
    style->SetCurrentRenderer(renderer);
    renderer->Render();
    renderWindowInteractor->Start();

    //------------------------------------------------------------------------------------

    //
    //Add RenderWindow to QVTKWigdet
    //
    // ui->qvtkWidget->SetRenderWindow( renderWindow );
}


//Деструктор класса
GameWindow::~GameWindow()
{
    delete ui;
}

