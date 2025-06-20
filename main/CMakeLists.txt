
set(CMAKE_CXX_STANDARD 17)  
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SRC_UI ${CMAKE_SOURCE_DIR} "ui/*.c")

idf_component_register(
    SRCS 
        "waveshare_rgb_lcd_port.c" 
        "main.c" 
        "lvgl_port.c"
        "ble/ble_client.cpp" 
        ${SRC_UI}
    INCLUDE_DIRS 
        "."
        "./ui"
        "./ble")

target_compile_options(${COMPONENT_LIB} PRIVATE -Wno-error=address)
idf_component_get_property(lvgl_lib lvgl__lvgl COMPONENT_LIB)
target_compile_options(${lvgl_lib} PRIVATE -Wno-format)
