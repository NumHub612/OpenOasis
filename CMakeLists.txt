# -------------------------------------------------------------
# 设置cmake版本要求
# -------------------------------------------------------------
cmake_minimum_required(VERSION 3.16)
set(ProjectName OpenOasis)


# -------------------------------------------------------------
# 设置项目
# -------------------------------------------------------------
project(${ProjectName})
set(CMAKE_INSTALL_PREFIX  ${PROJECT_SOURCE_DIR}/Dists)

string(TIMESTAMP COMPILE_TIME 20%y) 
set(PROJECT_BUILD_YEAR ${COMPILE_TIME})

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)


# -------------------------------------------------------------
# 设置平台类型
# -------------------------------------------------------------
if (CMAKE_HOST_WIN32)
    set(platform "win")
elseif (CMAKE_HOST_APPLE)
    set(platform "mac")
elseif (CMAKE_HOST_UNIX)
    set(platform "linux")
endif ()


# -------------------------------------------------------------
# 指定C++编译器版本
# -------------------------------------------------------------
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# -------------------------------------------------------------
# 设置编译属性
# -------------------------------------------------------------
if (MSVC)
    add_compile_definitions(NOMINMAX)
    add_definitions("/utf-8")
else()
    add_compile_options(-fPIC)
    add_compile_options(-pthread)
endif()

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fopenmp -Wall -g -O0") 
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fopenmp -Wall -O3")
else()
    message(FATAL_ERROR "Invalid build type: ${CMAKE_BUILD_TYPE}")
endif()

if(ENABLE_CODECOV)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fprofile-arcs -ftest-coverage")
endif()


# -------------------------------------------------------------
# 输出项目logo
# -------------------------------------------------------------
file(STRINGS "${PROJECT_SOURCE_DIR}/Rsrc/Logo/logo.txt" PROJECT_LOGO NEWLINE_CONSUME)
message(STATUS "${PROJECT_LOGO}")


# -------------------------------------------------------------
# 配置编译选项
# -------------------------------------------------------------
find_package(OpenMP REQUIRED)
option(ENABLE_PYLIB "-- If generating python3 packages" OFF)
if (ENABLE_PYLIB)
    find_package(Python3 COMPONENTS Interpreter Development REQUIRED)
    find_package(pybind11 REQUIRED)

    set(PYBIND11_PYTHON_VERSION 3)
    set(Python_ADDITIONAL_VERSIONS 3.9 3.8 3.7 3.6)
    message(STATUS "Generating python3 packages: ${ENABLE_PYLIB}")
endif ()

option(ENABLE_TESTS "-- If runing test" OFF)
if (ENABLE_TESTS)
    enable_testing()
    message(STATUS "Runing test: ${ENABLE_TESTS}")
endif()


# -------------------------------------------------------------
# 加载项目文件
# -------------------------------------------------------------
set(RootDir  ${PROJECT_SOURCE_DIR})
set(CoreDir ${RootDir}/Model)

file(GLOB_RECURSE ToolsSrc ${CoreDir}/ThirdPart/*.cpp ${CoreDir}/ThirdPart/*.cc ${CoreDir}/ThirdPart/*.c) 
file(GLOB driver "${PROJECT_SOURCE_DIR}/Model/Launcher.cpp")

if (NOT ENABLE_TESTS)
    list(FILTER ToolsSrc EXCLUDE REGEX ".*/Catch2/.*")
endif()

file(GLOB_RECURSE CommSrc ${CoreDir}/CommImpl/*.cpp ${CoreDir}/CommImpl/*.c)
file(GLOB_RECURSE UtilSrc ${CoreDir}/Utils/*.cpp ${CoreDir}/Utils/CommImpl/*.c)
file(GLOB_RECURSE TestSrc ${CoreDir}/tests/*.cpp ${CoreDir}/tests/*.c)
file(GLOB_RECURSE PyBindSrc "${CoreDir}/wrappers/PyOasisFlows.cpp")
file(GLOB_RECURSE ExportSrc "${CoreDir}/wrappers/OasisFlows.cpp")

set(FluidDir ${CoreDir}/SystFluids)
file(GLOB_RECURSE FluidSrc ${FluidDir}/*.cpp ${FluidDir}/*.c)

set(HeatDir ${CoreDir}/SystHeats)
file(GLOB_RECURSE HeatSrc ${HeatDir}/*.cpp ${HeatDir}/*.c)


# -------------------------------------------------------------
# 公共模块静态库编译
# -------------------------------------------------------------
set(CommLib "CommLib")
add_library(${CommLib}  STATIC  ${ToolsSrc} ${CommSrc} ${UtilSrc})
target_include_directories(${CommLib}  
    PUBLIC  ${PROJECT_SOURCE_DIR}
    PUBLIC  ${PROJECT_SOURCE_DIR}/Model
    PUBLIC  ${PROJECT_SOURCE_DIR}/Model/ThirdPart
    )
set_target_properties(${CommLib} PROPERTIES PREFIX "")


# -------------------------------------------------------------
# 生成 PYTHON 包
# -------------------------------------------------------------
if(ENABLE_PYLIB)       
    set(PackageName "PyOasisFlows")  
    pybind11_add_module(${PackageName} ${FluidSrc} ${HeatSrc} ${PyBindSrc})
    target_include_directories(${PackageName} 
        PUBLIC ${PROJECT_SOURCE_DIR}
        )
    target_link_libraries(${PackageName} PUBLIC ${CommLib})
endif()


# -------------------------------------------------------------
# 子模块动态库编译
# -------------------------------------------------------------
set(ModuleName "OasisFlows") 
add_library(${ModuleName} SHARED ${FluidSrc} ${HeatSrc} ${ExportSrc})

##-- 连接库
target_link_libraries(${ModuleName} 
    PUBLIC ${CommLib}
    PUBLIC OpenMP::OpenMP_CXX
    )
if (LINUX)
    target_link_libraries(${ModuleName} PUBLIC dl)
endif()

##-- 增加包含目录
target_include_directories(${ModuleName}
    PUBLIC ${PROJECT_SOURCE_DIR}
    )

##-- 设置动态库属性
set_target_properties(${ModuleName} PROPERTIES 
    PREFIX ""
    OUTPUT_NAME  ${ModuleName}
    )


# -------------------------------------------------------------
# 生成可执行文件
# -------------------------------------------------------------
add_executable(${ProjectName} ${driver})

##-- 链接库
target_link_libraries(${ProjectName} 
    PUBLIC ${CommLib}
    PUBLIC OpenMP::OpenMP_CXX
    )
if (LINUX)
    target_link_libraries(${ProjectName} PUBLIC dl)
endif()

##-- 添加附加包含目录
target_include_directories(${ProjectName}  
    PUBLIC  ${PROJECT_SOURCE_DIR}   
    PUBLIC  ${PROJECT_SOURCE_DIR}/Model/ThirdPart
    # PUBLIC  "${PROJECT_SOURCE_DIR}\\Tools\\Eigen\\"    
    )
    

# -------------------------------------------------------------
# 执行测试
# -------------------------------------------------------------
if (ENABLE_TESTS)
    set(ProjectTestName "OasisTests")

    configure_file("${CoreDir}/tests/FolderConfig.h.in" "${CoreDir}/tests/FolderConfig.h")

    add_executable(${ProjectTestName} ${TestSrc} ${FluidSrc} ${HeatSrc})
    target_link_libraries(${ProjectTestName} 
        PUBLIC ${CommLib}
        )    
    target_include_directories(${ProjectTestName}
        PUBLIC ${PROJECT_SOURCE_DIR}
        ) 
    add_test(  
        NAME ${ProjectTestName}
        COMMAND ${ProjectTestName} --reporter compact
        )
endif()


# -------------------------------------------------------------
# 安装文件
# -------------------------------------------------------------
##-- 安装动态库
install(TARGETS ${ModuleName}  DESTINATION exports/${platform})
file(GLOB apis ${CoreDir}/wrappers/*.h)
install(FILES ${apis} DESTINATION exports/${platform})

##-- 安装项目
install(TARGETS ${PROJECT_NAME} DESTINATION exports/${platform})
install(FILES "${PROJECT_SOURCE_DIR}/LICENSE"
    DESTINATION ${CMAKE_INSTALL_PREFIX}
    )
install(FILES "${PROJECT_SOURCE_DIR}/README.md"
    DESTINATION ${CMAKE_INSTALL_PREFIX}
    )    

file(GLOB CommInc ${RootDir}/Cores/Inc/*.h)
install(FILES ${CommInc} DESTINATION inc)
install(DIRECTORY ${RootDir}/Cores/Inc/AdditionalControl
    DESTINATION inc
    FILES_MATCHING 
    PATTERN  "*.h"
    )

##-- 安装ptyhon包
if(ENABLE_PYLIB)
    install(TARGETS ${PackageName} DESTINATION exports/${platform})
endif()
