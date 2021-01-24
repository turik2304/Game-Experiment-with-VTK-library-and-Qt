#ifndef WIDGET_H
#define WIDGET_H

#include <QApplication>
#include <QWidget>

#include <vtkAutoInit.h>

#define vtkRenderingCore_AUTOINIT 2(vtkRenderingOpenGL2, vtkInteractionStyle)

VTK_MODULE_INIT(vtkRenderingVolumeOpenGL2)
VTK_MODULE_INIT(vtkRenderingFreeType)
VTK_MODULE_INIT(vtkRenderingOpenGL2);

#include <vtkBMPReader.h>
#include <vtkCylinderSource.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkGenericOpenGLRenderWindow.h>
#include <vtkProperty.h>
#include <vtkCamera.h>
#include <vtkSmartPointer.h>
#include <vtkSphereSource.h>
#include <vtkConeSource.h>
#include <vtkNew.h>
#include <vtkTIFFReader.h>
#include <vtkImageData.h>

#include <vtkSmartPointer.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkMetaImageReader.h>
#include <vtkVolume.h>
#include <vtkFixedPointVolumeRayCastMapper.h>
#include <vtkVolumeProperty.h>
#include <vtkColorTransferFunction.h>
#include <vtkPiecewiseFunction.h>
#include <vtkCamera.h>
#include <vtkBMPReader.h>
#include <vtkGPUVolumeRayCastMapper.h>
#include <vtkCutter.h>
#include <vtkOpenGLRayCastImageDisplayHelper.h>
#include <vtkRenderingOpenGL2Module.h>
#include <vtkRenderingOpenGL2ObjectFactory.h>
#include <vtkRenderingOpenGLConfigure.h>
#include <vtkRenderingVolumeOpenGL2Module.h>
#include <vtkRenderingVolumeOpenGL2ObjectFactory.h>
#include <vtkRenderingVolumeModule.h>
#include <vtkRayCastImageDisplayHelper.h>
#include <vtkImageViewer2.h>
#include <vtkDataSetMapper.h>
#include <vtkVolumeMapper.h>
#include <vtkImageData.h>
#include <vtkUnsignedShortArray.h>
#include <vtkPointData.h>
#include <vtkVolumeProperty.h>
#include <vtkCubeSource.h>
#include <vtkPlaneSource.h>
#include <vtkFileOutputWindow.h>

#include <vtkImageMapper3D.h>
#include <vtkAbstractMapper3D.h>
#include <vtkVolumeMapper.h>

#include "vtkBoxWidget.h"
#include "vtkCamera.h"
#include "vtkCommand.h"
#include "vtkColorTransferFunction.h"
#include "vtkDICOMImageReader.h"
#include "vtkImageData.h"
#include "vtkImageResample.h"
#include "vtkMetaImageReader.h"
#include "vtkPiecewiseFunction.h"
#include "vtkPlanes.h"
#include "vtkProperty.h"
#include <vtkProperty2D.h>
#include "vtkRenderer.h"
#include "vtkRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkVolume.h"
#include "vtkVolumeProperty.h"
#include "vtkXMLImageDataReader.h"
#include "vtkSmartVolumeMapper.h"
#include <vtkLight.h>

#include <vtkImageMagnitude.h>
#include <vtkBarChartActor.h>
#include "vtkImageAlgorithm.h"
#include "vtkImageAccumulate.h"
#include "vtkImageGaussianSmooth.h"
#include "vtkNamedColors.h"
#include "vtkBarChartActor.h"

#include <vtkCornerAnnotation.h>
#include <vtkTextProperty.h>
#include <vtkTextActor.h>
#include "vtkTextRenderer.h"

#include <vtkImageCanvasSource2D.h>
#include <vtkAVIWriter.h>
#include <vtkWindowToImageFilter.h>

#include "vtkDataArray.h"
#include "vtkAbstractArray.h"
#include "vtkRenderingVolumeOpenGL2Module.h"
#include "vtkGPUInfoList.h"
#include "vtkGPUInfo.h"
#include "vtkContourFilter.h"
#include "vtkMarchingCubes.h"
#include "vtkMarchingCubesTriangleCases.h"
#include "vtkPolyDataMapper.h"

#include <vtkActor2D.h>
#include <vtkTextActor.h>
#include <vtkTextProperty.h>
#include <vtkPNGReader.h>
#include <vtkImageMapper.h>
#include <vtkImageActor.h>
#include <vtkEarthSource.h>
#include <vtkDiskSource.h>

#include <QVTKOpenGLWidget.h>

#include <vtkInteractorStyleTrackballActor.h>
#include <vtkInteractorStyleTrackballCamera.h>
#include <vtkInteractionStyleModule.h>
#include <QPushButton>
#include <vtkTransform.h>
#include <vtkTransformFilter.h>
#include <vtkTransformPolyDataFilter.h>
#include <vtkSelectEnclosedPoints.h>
#include <vtkRendererCollection.h>
#include <vtkPropPicker.h>
#include <vtk3DSImporter.h>
#include <vtkOBJImporter.h>
#include <vtkSTLReader.h>


namespace Ui {
class Widget;
}

class GameWindow : public QWidget
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = 0);
    ~GameWindow();

private:
    Ui::Widget *ui;


};

#endif // WIDGET_H
