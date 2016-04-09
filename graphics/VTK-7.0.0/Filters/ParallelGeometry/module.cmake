vtk_module(vtkFiltersParallelGeometry
  GROUPS
    MPI
  DEPENDS
    vtkFiltersExtraction
    vtkFiltersGeometry
    vtkParallelMPI
  TEST_DEPENDS
    vtkIOXML
    vtkIOParallel
    vtkIOParallelXML
    vtkCommonDataModel
    vtkParallelMPI
    vtkTestingCore
    vtkImagingCore
  KIT
    vtkParallel
  )
