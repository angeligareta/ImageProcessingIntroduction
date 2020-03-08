cmake_minimum_required(VERSION 3.15)
project(IPAC_Excercises)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(OpenCV_DIR "C:\\OpenCV\\mingw-build\\install")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

# If the package has been found, several variables will
# be set, you can find the full list with descriptions
# in the OpenCVConfig.cmake file.
# Print some message showing some of them
message(STATUS "OpenCV library status:")
message(STATUS "    config: ${OpenCV_DIR}")
message(STATUS "    version: ${OpenCV_VERSION}")
message(STATUS "    libraries: ${OpenCV_LIBS}")
message(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")

# add libs you need
set(OpenCV_LIBS opencv_core opencv_imgproc opencv_highgui opencv_imgcodecs)

add_executable(display_image main.cpp)
add_executable(exercise_02a_thresh exercises/exercise_02a_thresh.cpp)
add_executable(exercise_02b_compare exercises/exercise_02b_compare.cpp)
add_executable(exercise_02c exercises/exercise_02c.cpp utils/utils.hpp)
add_executable(exercise_02d_inf exercises/exercise_02d_inf.cpp)
add_executable(exercise_02d_sup exercises/exercise_02d_sup.cpp)
add_executable(exercise_03a_erosion exercises/exercise_03a_erosion.cpp utils/utils.hpp)
add_executable(exercise_03b_dilation exercises/exercise_03b_dilation.cpp utils/utils.hpp)
add_executable(exercise_04a_opening exercises/exercise_04a_opening.cpp utils/utils.hpp)
add_executable(exercise_04b_closing exercises/exercise_04b_closing.cpp utils/utils.hpp)
add_executable(exercise_06a_closing_opening exercises/exercise_06a_closing_opening.cpp utils/utils.hpp)
add_executable(exercise_06b_opening_closing exercises/exercise_06b_opening_closing.cpp utils/utils.hpp)

# linking
target_link_libraries(display_image ${OpenCV_LIBS})
target_link_libraries(exercise_02a_thresh ${OpenCV_LIBS})
target_link_libraries(exercise_02b_compare ${OpenCV_LIBS})
target_link_libraries(exercise_02c ${OpenCV_LIBS})
target_link_libraries(exercise_02d_inf ${OpenCV_LIBS})
target_link_libraries(exercise_02d_sup ${OpenCV_LIBS})
target_link_libraries(exercise_03a_dilation ${OpenCV_LIBS})
target_link_libraries(exercise_03b_erosion ${OpenCV_LIBS})
target_link_libraries(exercise_04a_opening ${OpenCV_LIBS})
target_link_libraries(exercise_04b_closing ${OpenCV_LIBS})
target_link_libraries(exercise_06a_closing_opening ${OpenCV_LIBS})
target_link_libraries(exercise_06b_opening_closing ${OpenCV_LIBS})