SET(VENDOR_TARGET_NAME VendorXxHash)

set(VENDOR_INCLUDE_DIR "${${PROJECT_NAME}_SOURCE_DIR}/vendor/XxHash")
set(VENDOR_SRC_DIR "${${PROJECT_MAIN_NAME}_SOURCE_DIR}/vendor/XxHash")


# Build xxHash lib
set(XXHASH_BUILD_ENABLE_INLINE_API OFF) #optional
set(XXHASH_BUILD_XXHSUM OFF) #optional
add_subdirectory("${VENDOR_SRC_DIR}/xxHash/cmake_unofficial" xxHash)

add_library(${VENDOR_TARGET_NAME} INTERFACE)
target_link_libraries(${VENDOR_TARGET_NAME} INTERFACE xxHash::xxhash)
target_include_directories(${VENDOR_TARGET_NAME} INTERFACE "${VENDOR_INCLUDE_DIR}")

add_library(CPS::vendor_xxhash ALIAS ${VENDOR_TARGET_NAME})
