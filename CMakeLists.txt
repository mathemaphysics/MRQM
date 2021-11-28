cmake_minimum_required(VERSION 3.9)

# Set a name and a version number for your project:
project(MRQM VERSION 0.0.1 LANGUAGES CXX)

# Initialize some default paths
include(GNUInstallDirs)
include(CTest)
include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY  ssh://git@github.com/google/googletest.git
    GIT_TAG         release-1.11.0
)

FetchContent_Declare(
    spdlog
    GIT_REPOSITORY  ssh://git@github.com/gabime/spdlog.git
    GIT_TAG         v1.9.2
)

FetchContent_Declare(
    flatbuffers
    GIT_REPOSITORY  ssh://git@github.com/google/flatbuffers.git
    GIT_TAG         v2.0.0
)

FetchContent_Declare(
    jsoncpp
    GIT_REPOSITORY  ssh://git@github.com/open-source-parsers/jsoncpp.git
    GIT_TAG         1.9.4
)

# Define the minimum C++ standard that is required
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Compilation options
set(BUILD_PYTHON ON CACHE BOOL "Enable building of Python bindings")
set(BUILD_DOCS ON CACHE BOOL "Enable building of documentation")

FetchContent_MakeAvailable(spdlog)
FetchContent_MakeAvailable(flatbuffers)
FetchContent_MakeAvailable(jsoncpp)

# compile the library
add_subdirectory(src)

# compile the application
add_subdirectory(app)

# compile the tests
if(BUILD_TESTING)
  include(GoogleTest)
  FetchContent_MakeAvailable(googletest)
  add_subdirectory(tests)
endif()

if(BUILD_DOCS)
  # Add the documentation
  add_subdirectory(doc)
endif()
if(BUILD_PYTHON)
  # Add Python bindings
  add_subdirectory(ext/pybind11)
  
  add_subdirectory(python)
endif()

# Add an alias target for use if this project is included as a subproject in another project
add_library(MRQM::MRQM ALIAS MRQM)

# Install targets and configuration
install(
  TARGETS MRQM
  EXPORT MRQM-config
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

install(
  EXPORT MRQM-config
  NAMESPACE MRQM::
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/MRQM
)

install(
  DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/include/
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

# This prints a summary of found dependencies
include(FeatureSummary)
feature_summary(WHAT ALL)
