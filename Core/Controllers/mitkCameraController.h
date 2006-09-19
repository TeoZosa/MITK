/*=========================================================================

Program:   Medical Imaging & Interaction Toolkit
Module:    $RCSfile$
Language:  C++
Date:      $Date$
Version:   $Revision$

Copyright (c) German Cancer Research Center, Division of Medical and
Biological Informatics. All rights reserved.
See MITKCopyright.txt or http://www.mitk.org/copyright.html for details.

This software is distributed WITHOUT ANY WARRANTY; without even
the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
PURPOSE.  See the above copyright notices for more information.

=========================================================================*/


#ifndef CAMERACONTROLLER_H_HEADER_INCLUDED_C1C53722
#define CAMERACONTROLLER_H_HEADER_INCLUDED_C1C53722



#include "mitkCommon.h"
#include "mitkBaseController.h"
#include "mitkEventTypedefs.h"
#include "QString.h"
class mitk::BaseRenderer;

namespace mitk {

//##ModelId=3DF8BCFD014C
//##Documentation
//## @brief controls the camera used by the associated BaseRenderer
//##
//## Subclass of BaseController. Controls the camera used by the associated
//## BaseRenderer.
//## @ingroup NavigationControl
class CameraController : public BaseController
{
public:
    enum StandardView { ANTERIOR,POSTERIOR,SINISTER,DEXTER,CRANIAL,CAUDAL };

    //##ModelId=3E6D5DD4008F
    mitkClassMacro(CameraController, BaseController);
    itkSetMacro(Renderer,BaseRenderer*);
    itkGetConstMacro(Renderer,const BaseRenderer*);

    /** Method for creation through the object factory. */
    //itkNewMacro(Self);
    CameraController(const char * type = NULL);

    /*!
    \brief method returning the name of the current camera controller
    */
    QString GetCameraControllerName();

    //##ModelId=3E6D5DD400A3
    //##Documentation
    //## @brief Implemented in sub-classes.
    virtual void Resize(int w, int h);

    //##ModelId=3E6D5DD400C1
    //##Documentation
    //## @brief Implemented in sub-classes.
    virtual void MousePressEvent(mitk::MouseEvent*);
    //##ModelId=3E6D5DD400D5
    //##Documentation
    //## @brief Implemented in sub-classes.
    virtual void MouseReleaseEvent(mitk::MouseEvent*);
    //##ModelId=3E6D5DD400F3
    //##Documentation
    //## @brief Implemented in sub-classes.
    virtual void MouseMoveEvent(mitk::MouseEvent*);
    //##ModelId=3E6D5DD40107
    //##Documentation
    //## @brief Implemented in sub-classes.
    virtual void KeyPressEvent(mitk::KeyEvent*);

   virtual void SetViewToAnterior();
   virtual void SetViewToPosterior();
   virtual void SetViewToSinister();
   virtual void SetViewToDexter();
   virtual void SetViewToCranial();
   virtual void SetViewToCaudal();
   virtual void SetStandardView(StandardView view);
  
protected:
    //CameraController();

    //##ModelId=3E3AE75803CF
    virtual ~CameraController();
    const BaseRenderer* m_Renderer;

    /*!
    \brief name of the current camera controller ("VTKInteraktorCameraController" and "TrackingCameraController" respectively)
    */
    QString m_CameraControllerName; 
};

} // namespace mitk



#endif /* CAMERACONTROLLER_H_HEADER_INCLUDED_C1C53722 */
