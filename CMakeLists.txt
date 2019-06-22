cmake_minimum_required(VERSION 3.12)

# Название проекта
project(Arcanoid)
set(CMAKE_CXX_STANDARD 14)

# Configuration options
#set(SFML_STATIC_LIBRARIES TRUE CACHE BOOL "Use static SFML librares")
set(SFML_STATIC_LIBRARIES TRUE)

# General compiler options
if (SFML_STATIC_LIBRARIES)
	add_definitions(-DSFML_STATIC)
endif()

#if(WIN32)
#	add_custom_command(TARGET Game POST_BUILD
#			COMMAND ${CMAKE_COMMAND} -E copy_if_different
#			"${SFML_ROOT}/bin/openal32.dll"
#			$<TARGET_FILE_DIR:Game>)
#endif()

# Specific compiler options - set C++11 flag for g++ and clang
if(CMAKE_COMPILER_IS_GNUCXX)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

	# Mac OS X: clang uses libc++ standard library
	if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
	endif()
endif()

# имя исполняемого файла
set(APP_NAME Arcanoid)

if(WIN32)
	set(SFML_PATH D:/MyProjects/SFML-2.5.1)
	include_directories(${SFML_PATH}/include)
else()
	set(SFML_PATH /usr/local/Cellar/sfml/2.5.0)
	include_directories(${SFML_PATH})
endif()

set(SRC_DIR ${PROJECT_SOURCE_DIR}/Source)
set(INCLUDE_DIR ${PROJECT_SOURCE_DIR}/Include)

# Расположение заголовочных файлов
include_directories(${INCLUDE_DIR})

link_directories(${SFML_PATH}/lib)

# Установка переменной со списком исходников
set (SRC
		Object.cpp
		ObjectBuilder.cpp
		GameField.cpp
		main.cpp)


add_executable(${APP_NAME} ${SRC})

# Линковка программы с библиотекой

if(WIN32)
	target_link_libraries(${APP_NAME}
			openal32
			sfml-graphics-d
			sfml-main-d
			sfml-system-d
			sfml-window-d
			sfml-audio-d
			freetype
			ogg
			flac)
else()
	target_link_libraries(${APP_NAME}
			libsfml-graphics.2.5.0.dylib
			libsfml-system.2.5.0.dylib
			libsfml-window.2.5.0.dylib
            libsfml-audio.2.5.0.dylib)
endif()
