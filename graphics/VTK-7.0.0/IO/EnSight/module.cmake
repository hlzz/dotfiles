vtk_module(vtkIOEnSight
  GROUPS
    StandAlone
  DEPENDS
    vtkCommonExecutionModel
  TEST_DEPENDS
    vtkRendering${VTK_RENDERING_BACKEND}
  KIT
    vtkIO
  )
