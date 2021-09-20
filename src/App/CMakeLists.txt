SET(APP_TARGET_NAME App)

set(APP_INCLUDE_DIR "${${PROJECT_MAIN_NAME}_SOURCE_DIR}/include")
set(APP_SRC_DIR "${${PROJECT_MAIN_NAME}_SOURCE_DIR}/src")

set(APP_HEADERS_PREFIX "${APP_INCLUDE_DIR}/${APP_TARGET_NAME}/")
set(APP_SRC_PREFIX "${APP_SRC_DIR}/${APP_TARGET_NAME}/")


set(APP_HEADERS_LIST
)
set(APP_SRC_LIST
	"Main.cpp"
)

list(TRANSFORM APP_SRC_LIST PREPEND ${APP_SRC_PREFIX})
list(TRANSFORM APP_HEADERS_LIST PREPEND ${APP_HEADERS_PREFIX})

add_executable(${APP_TARGET_NAME} "${APP_SRC_LIST}" "${APP_HEADERS_LIST}")
target_include_directories(${APP_TARGET_NAME} PRIVATE "${APP_INCLUDE_DIR}")
target_compile_features(${APP_TARGET_NAME} PRIVATE cxx_std_17)

target_link_libraries(
	${APP_TARGET_NAME}
	PRIVATE
		CPS::lib
		CPS::vendor_xxhash
)

set_compiler_options(${APP_TARGET_NAME})

# Group files into proper folders - for IDE
group_files("${APP_HEADERS_LIST}" "${APP_INCLUDE_DIR}")
group_files("${APP_SRC_LIST}" "${APP_SRC_DIR}")

add_executable(CPS::app ALIAS ${APP_TARGET_NAME})