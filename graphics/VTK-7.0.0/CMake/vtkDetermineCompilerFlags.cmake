SET(VTK_REQUIRED_C_FLAGS)
SET(VTK_REQUIRED_CXX_FLAGS)

# make sure Crun is linked in with the native compiler, it is
# not used by default for shared libraries and is required for
# things like java to work.
IF(CMAKE_SYSTEM MATCHES "SunOS.*")
  IF(NOT CMAKE_COMPILER_IS_GNUCXX)
    FIND_LIBRARY(VTK_SUNCC_CRUN_LIBRARY Crun /opt/SUNWspro/lib)
    IF(VTK_SUNCC_CRUN_LIBRARY)
      LINK_LIBRARIES(${VTK_SUNCC_CRUN_LIBRARY})
    ENDIF()
    FIND_LIBRARY(VTK_SUNCC_CSTD_LIBRARY Cstd /opt/SUNWspro/lib)
    IF(VTK_SUNCC_CSTD_LIBRARY)
      LINK_LIBRARIES(${VTK_SUNCC_CSTD_LIBRARY})
    ENDIF()
  ENDIF()
ENDIF()

# A GCC compiler.
IF(CMAKE_COMPILER_IS_GNUCXX)
  IF(VTK_USE_X)
    unset(WIN32)
  ENDIF()
  IF(WIN32)
# The platform is gcc on cygwin.
    SET(VTK_REQUIRED_CXX_FLAGS "${VTK_REQUIRED_CXX_FLAGS} -mwin32")
    SET(VTK_REQUIRED_C_FLAGS "${VTK_REQUIRED_C_FLAGS} -mwin32")
    LINK_LIBRARIES(-lgdi32)
  ENDIF()
  IF(MINGW)
    SET(VTK_REQUIRED_CXX_FLAGS "${VTK_REQUIRED_CXX_FLAGS} -mthreads")
    SET(VTK_REQUIRED_C_FLAGS "${VTK_REQUIRED_C_FLAGS} -mthreads")
    SET(VTK_REQUIRED_EXE_LINKER_FLAGS "${VTK_REQUIRED_EXE_LINKER_FLAGS} -mthreads")
    SET(VTK_REQUIRED_SHARED_LINKER_FLAGS "${VTK_REQUIRED_SHARED_LINKER_FLAGS} -mthreads")
    SET(VTK_REQUIRED_MODULE_LINKER_FLAGS "${VTK_REQUIRED_MODULE_LINKER_FLAGS} -mthreads")
  ENDIF()
  IF(CMAKE_SYSTEM MATCHES "SunOS.*")
# Disable warnings that occur in X11 headers.
    IF(DART_ROOT AND BUILD_TESTING)
      SET(VTK_REQUIRED_CXX_FLAGS "${VTK_REQUIRED_CXX_FLAGS} -Wno-unknown-pragmas")
      SET(VTK_REQUIRED_C_FLAGS "${VTK_REQUIRED_C_FLAGS} -Wno-unknown-pragmas")
    ENDIF()
  ENDIF()
ELSE()
  IF(CMAKE_ANSI_CFLAGS)
    SET(VTK_REQUIRED_C_FLAGS "${VTK_REQUIRED_C_FLAGS} ${CMAKE_ANSI_CFLAGS}")
  ENDIF()
  IF(CMAKE_SYSTEM MATCHES "OSF1-V.*")
     SET(VTK_REQUIRED_CXX_FLAGS
         "${VTK_REQUIRED_CXX_FLAGS} -timplicit_local -no_implicit_include")
  ENDIF()
  IF(CMAKE_SYSTEM MATCHES "AIX.*")
    # allow t-ypeid and d-ynamic_cast usage (normally off by default on xlC)
    SET(VTK_REQUIRED_CXX_FLAGS "${VTK_REQUIRED_CXX_FLAGS} -qrtti=all")
    # silence duplicate symbol warnings on AIX
    SET(VTK_REQUIRED_EXE_LINKER_FLAGS "${VTK_REQUIRED_EXE_LINKER_FLAGS} -bhalt:5")
    SET(VTK_REQUIRED_SHARED_LINKER_FLAGS "${VTK_REQUIRED_SHARED_LINKER_FLAGS} -bhalt:5")
    SET(VTK_REQUIRED_MODULE_LINKER_FLAGS "${VTK_REQUIRED_MODULE_LINKER_FLAGS} -bhalt:5")
  ENDIF()
  IF(CMAKE_SYSTEM MATCHES "HP-UX.*")
     SET(VTK_REQUIRED_C_FLAGS
         "${VTK_REQUIRED_C_FLAGS} +W2111 +W2236 +W4276")
     SET(VTK_REQUIRED_CXX_FLAGS
         "${VTK_REQUIRED_CXX_FLAGS} +W2111 +W2236 +W4276")
  ENDIF()
ENDIF()

# figure out whether the compiler might be the Intel compiler
SET(_MAY_BE_INTEL_COMPILER FALSE)
IF(UNIX)
  IF(CMAKE_CXX_COMPILER_ID)
    IF(CMAKE_CXX_COMPILER_ID MATCHES "Intel")
      SET(_MAY_BE_INTEL_COMPILER TRUE)
    ENDIF()
  ELSE()
    IF(NOT CMAKE_COMPILER_IS_GNUCXX)
      SET(_MAY_BE_INTEL_COMPILER TRUE)
    ENDIF()
  ENDIF()
ENDIF()

#if so, test whether -i_dynamic is needed
IF(_MAY_BE_INTEL_COMPILER)
  INCLUDE(${VTK_CMAKE_DIR}/TestNO_ICC_IDYNAMIC_NEEDED.cmake)
  TESTNO_ICC_IDYNAMIC_NEEDED(NO_ICC_IDYNAMIC_NEEDED ${VTK_CMAKE_DIR})
  IF(NO_ICC_IDYNAMIC_NEEDED)
    SET(VTK_REQUIRED_CXX_FLAGS "${VTK_REQUIRED_CXX_FLAGS}")
  ELSE()
    SET(VTK_REQUIRED_CXX_FLAGS "${VTK_REQUIRED_CXX_FLAGS} -i_dynamic")
  ENDIF()
ENDIF()

IF(CMAKE_CXX_COMPILER_ID STREQUAL "PGI")
  # --diag_suppress=236 is for constant value asserts used for error handling
  # This can be restricted to the implementation and doesn't need to propogate
  SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --diag_suppress=236")

  # --diag_suppress=381 is for redundant semi-colons used in macros
  # This needs to propogate to anything that includes VTK headers
  SET(VTK_REQUIRED_CXX_FLAGS "${VTK_REQUIRED_CXX_FLAGS} --diag_suppress=381")
ENDIF()

IF(MSVC)
# Use the highest warning level for visual c++ compiler.
  SET(CMAKE_CXX_WARNING_LEVEL 4)
  IF(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
    STRING(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
  ELSE()
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
  ENDIF()
ENDIF()

# Disable deprecation warnings for standard C and STL functions in VS2005
# and later
IF(MSVC_VERSION EQUAL 1400 OR MSVC_VERSION GREATER 1400 OR MSVC10)
  ADD_DEFINITIONS(-D_CRT_SECURE_NO_DEPRECATE -D_CRT_NONSTDC_NO_DEPRECATE -D_CRT_SECURE_NO_WARNINGS)
  ADD_DEFINITIONS(-D_SCL_SECURE_NO_DEPRECATE -D_SCL_SECURE_NO_WARNINGS)
ENDIF()

# Enable /MP flag for Visual Studio 2008 and greator
IF(MSVC_VERSION GREATER 1400)
  SET(CMAKE_CXX_MP_FLAG OFF CACHE BOOL "Build with /MP flag enabled")
  SET(PROCESSOR_COUNT "$ENV{NUMBER_OF_PROCESSORS}")
  SET(CMAKE_CXX_MP_NUM_PROCESSORS CACHE ${PROCESSOR_COUNT} "The maximum number of processes for the /MP flag")
  IF (CMAKE_CXX_MP_FLAG)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MP${CMAKE_CXX_MP_NUM_PROCESSORS}")
    SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /MP${CMAKE_CXX_MP_NUM_PROCESSORS}")
  ENDIF ()
ENDIF()
#-----------------------------------------------------------------------------
# Add compiler flags VTK needs to work on this platform.  This must be
# done after the call to CMAKE_EXPORT_BUILD_SETTINGS, but before any
# try-compiles are done.
SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${VTK_REQUIRED_C_FLAGS}")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${VTK_REQUIRED_CXX_FLAGS}")
SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${VTK_REQUIRED_EXE_LINKER_FLAGS}")
SET(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} ${VTK_REQUIRED_SHARED_LINKER_FLAGS}")
SET(CMAKE_MODULE_LINKER_FLAGS "${CMAKE_MODULE_LINKER_FLAGS} ${VTK_REQUIRED_MODULE_LINKER_FLAGS}")
