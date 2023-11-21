# 热力学模块。
set(ModuleName "OasisHeats") 
set(MoudelDir ${HeatDir})


# 读取模块版本信息。
file(STRINGS "${MoudelDir}/export/VERSION" HEATS_VERSION)
message(STATUS "${ModuleName}  version: ${HEATS_VERSION}")
string(REGEX REPLACE "([0-9]+)\\.[0-9]+\\.[0-9]+.*" "\\1" HEATS_VER_MAJOR ${HEATS_VERSION})
string(REGEX REPLACE "[0-9]+\\.([0-9])+\\.[0-9]+.*" "\\1" HEATS_VER_MINOR ${HEATS_VERSION})
string(REGEX REPLACE "[0-9]+\\.[0-9]+\\.([0-9]+).*" "\\1" HEATS_VER_PATCH ${HEATS_VERSION})
string(REGEX MATCH  "[0-9]+\\.[0-9]+\\.[0-9]+-.+" "\\1"  WITH_VER_SUFFIX ${HEATS_VERSION})

if (WITH_VER_SUFFIX)
    string(REGEX REPLACE "[0-9]+\\.([0-9])+\\.[0-9]+-(.*)" "\\1" HEATS_VER_SUFFIX ${HEATS_VERSION})
endif()

# 配置模块信息。
set(PropertyDir "${MoudelDir}/export")
set(VersionInfoRc "${PropertyDir}/OasisHeatsVersion.h")
configure_file("${PropertyDir}/OasisHeatsVersion.h.in" "${PropertyDir}/OasisHeatsVersion.h")
if(MSVC)
    list(APPEND VersionInfoRc "${PropertyDir}/VersionInfo.rc")
    configure_file("${PropertyDir}/VersionInfo.rc.in" "${PropertyDir}/VersionInfo.rc")
endif()


# 生成动态库。
add_library(${ModuleName} SHARED ${HeatSrc} ${VersionInfoRc})
##-- 连接库。
target_link_libraries(${ModuleName} PUBLIC ${CommLib})
if (LINUX)
    target_link_libraries(${ModuleName} PUBLIC dl)
endif()
if (OpenMP_CXX_FOUND)
    target_link_libraries(${ModuleName} 
	PUBLIC OpenMP::OpenMP_CXX
	)
endif()
##-- 增加包含目录。
target_include_directories(${ModuleName}
    PUBLIC "${PROJECT_SOURCE_DIR}"
    )
##-- 设置动态库属性。
set_target_properties(${ModuleName} PROPERTIES 
    VERSION ${HEATS_VERSION}
    PREFIX ""
    OUTPUT_NAME  ${ModuleName}
    )


# 安装。
install(TARGETS ${ModuleName}  DESTINATION ${platform})
file(GLOB exports ${HeatDir}/export/*.h)
install(FILES ${exports} DESTINATION exports)
