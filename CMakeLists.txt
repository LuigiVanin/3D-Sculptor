cmake_minimum_required(VERSION 3.22)
project(3D_Sculptor)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(3D_Sculptor
        include/CutBox.h
        include/CutDisc.h
        include/CutEllipsoid.h
        include/CutSphere.h
        include/CutVoxel.h
        include/GeometricFigure.h
        include/Interpreter.h
        include/PutBox.h
        include/PutDisc.h
        include/PutEllipsoid.h
        include/PutSphere.h
        include/PutVoxel.h
        include/Sculptor.h
        include/voxel.h
        src/CutBox.cpp
        src/CutDisc.cpp
        src/CutEllipsoid.cpp
        src/CutSphere.cpp
        src/CutVoxel.cpp
        src/Interpreter.cpp
        src/PutBox.cpp
        src/PutDisc.cpp
        src/PutEllipsoid.cpp
        src/PutSphere.cpp
        src/PutVoxel.cpp
        src/Sculptor.cpp
        main.cpp)
