vtk_module(vtkWebGLExporter
  GROUPS
    Web
  DEPENDS
    vtkIOExport
  PRIVATE_DEPENDS
    vtksys
    vtkFiltersGeometry
    vtkInteractionWidgets
    vtkRenderingCore
  COMPILE_DEPENDS
    vtkUtilitiesEncodeString
  EXCLUDE_FROM_ALL
)