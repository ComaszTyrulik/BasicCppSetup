include("${PROJECT_CONFIG_PATH}/Lib/config.cmake")

set(
	LIB_HEADERS_LIST
	"Lib.h"
)
set(
	LIB_SRC_LIST
	"Lib.cpp"
)

list(TRANSFORM LIB_HEADERS_LIST PREPEND ${LIB_HEADERS_PREFIX})
list(TRANSFORM LIB_SRC_LIST PREPEND ${LIB_SRC_PREFIX})

add_library(${LIB_TARGET_NAME} STATIC "${LIB_SRC_LIST}" "${LIB_HEADERS_LIST}")
target_include_directories(${LIB_TARGET_NAME} PUBLIC "${LIB_INCLUDE_DIR}")
target_compile_features(${LIB_TARGET_NAME} PUBLIC cxx_std_17)

target_link_libraries(
	${LIB_TARGET_NAME}
	PRIVATE
		CONAN_PKG::spdlog
        CONAN_PKG::stduuid
		CPS::vendor_xxhash
)

set_compiler_options(${LIB_TARGET_NAME})

target_precompile_headers(
	${LIB_TARGET_NAME}
	PUBLIC
		<string>
		<vector>
		<memory>
		<unordered_map>
)

# Group files into proper folders - for IDE
group_files("${LIB_HEADERS_LIST}" "${LIB_INCLUDE_DIR}")
group_files("${LIB_SRC_LIST}" "${LIB_SRC_DIR}")

add_library(CPS::lib ALIAS ${LIB_TARGET_NAME})
