# -------------------------------------------------------------
# 水力学模块
# -------------------------------------------------------------
set(ModuleName "OasisFluids") 
set(MoudelDir ${FluidDir})


# -------------------------------------------------------------
# 读取模块版本信息
# -------------------------------------------------------------
file(STRINGS "${MoudelDir}/export/VERSION" FLUIDS_VERSION)
message(STATUS "${ModuleName} version: ${FLUIDS_VERSION}")
string(REGEX REPLACE "([0-9]+)\\.[0-9]+\\.[0-9]+.*" "\\1" FLUIDS_VER_MAJOR ${FLUIDS_VERSION})
string(REGEX REPLACE "[0-9]+\\.([0-9])+\\.[0-9]+.*" "\\1" FLUIDS_VER_MINOR ${FLUIDS_VERSION})
string(REGEX REPLACE "[0-9]+\\.[0-9]+\\.([0-9]+).*" "\\1" FLUIDS_VER_PATCH ${FLUIDS_VERSION})
string(REGEX MATCH   "[0-9]+\\.[0-9]+\\.[0-9]+-.+" "\\1"  WITH_VER_SUFFIX  ${FLUIDS_VERSION})

if (WITH_VER_SUFFIX)
    string(REGEX REPLACE "[0-9]+\\.([0-9])+\\.[0-9]+-(.*)" "\\1" FLUIDS_VER_SUFFIX ${FLUIDS_VERSION})
endif()


# -------------------------------------------------------------
# 配置模块信息
# -------------------------------------------------------------
set(PropertyDir "${MoudelDir}/export")
set(VersionInfoRc "${PropertyDir}/OasisFluidsVersion.h")
configure_file("${PropertyDir}/OasisFluidsVersion.h.in" "${PropertyDir}/OasisFluidsVersion.h")
if(MSVC)
    list(APPEND VersionInfoRc "${PropertyDir}/VersionInfo.rc")
    configure_file("${PropertyDir}/VersionInfo.rc.in" "${PropertyDir}/VersionInfo.rc")
endif()


# -------------------------------------------------------------
# 生成动态库
# -------------------------------------------------------------
add_library(${ModuleName} SHARED ${FluidSrc} ${VersionInfoRc})

#-- 连接库
target_link_libraries(${ModuleName} 
    PUBLIC ${CommLib}
    PUBLIC OpenMP::OpenMP_CXX
    )
if (LINUX)
    target_link_libraries(${ModuleName} PUBLIC dl)
endif()

##-- 增加包含目录
target_include_directories(${ModuleName}
    PUBLIC "${PROJECT_SOURCE_DIR}/"
    )

##-- 设置动态库属性
set_target_properties(${ModuleName} PROPERTIES 
    VERSION ${FLUIDS_VERSION}
    PREFIX ""
    OUTPUT_NAME  ${ModuleName}
    )


# -------------------------------------------------------------
# 安装
# -------------------------------------------------------------
install(TARGETS ${ModuleName}  DESTINATION ${platform})
file(GLOB exports ${FluidDir}/export/*.h)
install(FILES ${exports} DESTINATION exports)