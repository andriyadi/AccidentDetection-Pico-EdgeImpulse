# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(PROJECT_FOLDER .)
set(EI_SDK_FOLDER edge-impulse-sdk)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# initalize pico_sdk from installed location
# (note this can come from environment, CMake cache etc)
set(PICO_SDK_PATH "/Users/andri/Projects/RaspberryPi/RP2040/sdk/pico-sdk-latest")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

include(${PROJECT_FOLDER}/edge-impulse-sdk/cmake/utils.cmake)

project(EICarStateRecog C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add executable. Default name is the project name, version 0.1

add_executable(EICarStateRecog source/main.cpp source/ei_classifier_porting.cpp source/MPU6050.cpp)

pico_set_program_name(EICarStateRecog "EICarStateRecog")
pico_set_program_version(EICarStateRecog "0.1")

pico_enable_stdio_uart(EICarStateRecog 1)
pico_enable_stdio_usb(EICarStateRecog 1)

# Add the standard library to the build
target_link_libraries(EICarStateRecog pico_stdlib)

# Add any user requested libraries
target_link_libraries(EICarStateRecog
        hardware_i2c
        )

# EI
target_include_directories(EICarStateRecog PRIVATE
    ${PROJECT_FOLDER}
    ${PROJECT_FOLDER}/classifer
    ${PROJECT_FOLDER}/tflite-model
    ${PROJECT_FOLDER}/model-parameters
)

target_include_directories(EICarStateRecog PRIVATE
    ${EI_SDK_FOLDER}
    ${EI_SDK_FOLDER}/third_party/ruy
    ${EI_SDK_FOLDER}/third_party/gemmlowp
    ${EI_SDK_FOLDER}/third_party/flatbuffers/include
    ${EI_SDK_FOLDER}/third_party
    ${EI_SDK_FOLDER}/tensorflow
    ${EI_SDK_FOLDER}/dsp
    ${EI_SDK_FOLDER}/classifier
    ${EI_SDK_FOLDER}/anomaly
    ${EI_SDK_FOLDER}/CMSIS/NN/Include
    ${EI_SDK_FOLDER}/CMSIS/DSP/PrivateInclude
    ${EI_SDK_FOLDER}/CMSIS/DSP/Include
    ${EI_SDK_FOLDER}/CMSIS/Core/Include
)

include_directories(${INCLUDES})

# find model source files
RECURSIVE_FIND_FILE(MODEL_FILES "${PROJECT_FOLDER}/tflite-model" "*.cpp")
RECURSIVE_FIND_FILE(SOURCE_FILES "${EI_SDK_FOLDER}" "*.cpp")
RECURSIVE_FIND_FILE(CC_FILES "${EI_SDK_FOLDER}" "*.cc")
RECURSIVE_FIND_FILE(S_FILES "${EI_SDK_FOLDER}" "*.s")
RECURSIVE_FIND_FILE(C_FILES "${EI_SDK_FOLDER}" "*.c")
list(APPEND SOURCE_FILES ${S_FILES})
list(APPEND SOURCE_FILES ${C_FILES})
list(APPEND SOURCE_FILES ${CC_FILES})
list(APPEND SOURCE_FILES ${MODEL_FILES})

# add all sources to the project
target_sources(EICarStateRecog PRIVATE ${SOURCE_FILES})

pico_add_extra_outputs(EICarStateRecog)

