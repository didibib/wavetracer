set(WAVE_PCH_H "pch/wavepch.h")
set(WAVE_PCH_CPP "pch/wavepch.cpp")

set(WAVE_SOURCE_LIST
    ${WAVE_PCH_H} 
    ${WAVE_PCH_CPP} 
    "${STB}/stb_image_write.h"
    "main.cpp"
)

# Build static library
add_executable(wavetracer ${WAVE_SOURCE_LIST})

# Group sources according to the folder structure
source_group(TREE ${PROJECT_SOURCE_DIR} FILES ${WAVE_SOURCE_LIST})

# Set output directories (function found in: cmake/)    
set_target_output_directories(wavetracer)

# Set precompiled headers (function found in: cmake/)
set_target_precompiled_header(wavetracer WAVE_PCH_H WAVE_PCH_CPP)

# Specify include directories
# Make them public so that executables can inherit them
target_include_directories(wavetracer PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${WAVE_VENDOR_DIR}/stb
)

# Link libraries to wave
# Make them public so that executables can inherit them
target_link_libraries(wavetracer PUBLIC
    glm
    spdlog::spdlog
)