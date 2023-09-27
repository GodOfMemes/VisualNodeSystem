cmake_minimum_required(VERSION 3.10)

set(BUILD_TYPE "Debug and Release" CACHE STRING "Choose Build type")
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CONFIGURATION_TYPES Debug Release)

# set the project name
project(VisualNodeSystem LANGUAGES CXX)

# Turn on the ability to create folders to organize projects (.vcproj)
# It creates "CMakePredefinedTargets" folder by default and adds CMake
# defined projects like INSTALL.vcproj and ZERO_CHECK.vcproj
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

file(GLOB VisualNodeArea_SRC
	"SubSystems/VisualNodeArea/VisualNodeArea.cpp"
	"SubSystems/VisualNodeArea/VisualNodeArea.h"
	"SubSystems/VisualNodeArea/VisualNodeAreaLogic.cpp"
	"SubSystems/VisualNodeArea/VisualNodeAreaInput.cpp"
	"SubSystems/VisualNodeArea/VisualNodeAreaRendering.cpp"
)

file(GLOB VisualNodeSystem_SRC
	"VisualNodeSystem.cpp"
	"VisualNodeSystem.h"
	"GroupComment.cpp"
	"GroupComment.h"
	"VisualNodeFactory.cpp"
	"VisualNodeFactory.h"
	"VisualNode.cpp"
	"VisualNode.h"
	"VisualNodeSocket.cpp"
	"VisualNodeSocket.h"
	"VisualNodeCore.cpp"
	"VisualNodeCore.h"
)

# *************** THIRD_PARTY ***************

add_subdirectory(ThirdParty/json)
add_subdirectory(ThirdParty/glm)

# *************** THIRD_PARTY END ***************

add_library(VisualNodeSystem
			${VisualNodeSystem_SRC}
			${VisualNodeArea_SRC}
)

source_group("Source Files" FILES ${VisualNodeSystem_SRC})
source_group("Source Files/SubSystems/VisualNodeArea/" FILES ${VisualNodeArea_SRC})
# *************** THIRD_PARTY ***************

target_link_libraries(VisualNodeSystem PUBLIC nlohmann_json glm::glm)
target_include_directories(VisualNodeSystem PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

set(VISUAL_NODE_SYSTEM_THIRDPARTY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/ThirdParty)

# set the startup project
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT VisualNodeSystem)

# Promt to give Dear ImGui path
set(DEAR_IMGUI_INCLUDE_DIR "" CACHE PATH "Path to Dear ImGui directory.")

include_directories(
	${DEAR_IMGUI_INCLUDE_DIR}
	${VISUAL_NODE_SYSTEM_THIRDPARTY_DIR}
)
if (NOT CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
	set(VISUAL_NODE_SYSTEM_THIRDPARTY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/ThirdParty PARENT_SCOPE)
	set(VISUAL_NODE_SYSTEM_DIR ${CMAKE_CURRENT_SOURCE_DIR} PARENT_SCOPE)
endif()