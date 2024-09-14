cmake_minimum_required(VERSION 3.9.1)
project(pdfmerge)

add_executable(pdfmerge main.cpp)

include(FetchContent)

FetchContent_Declare(
  PDFHummus
  GIT_REPOSITORY https://github.com/galkahana/PDF-Writer.git
  GIT_TAG        v4.6.2
  FIND_PACKAGE_ARGS
)
FetchContent_MakeAvailable(PDFHummus)
target_link_libraries(pdfmerge PDFHummus::PDFWriter)

set(CMAKE_MAKE_PROGRAM mingw32)