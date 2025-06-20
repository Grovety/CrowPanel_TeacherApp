SET(SOURCES screens/ui_Screen1.c
    ui.c
    components/ui_comp_hook.c
    ui_helpers.c
    ui_events.c
    images/ui_img_1070636958.c
    fonts/ui_font_CO2Font.c
    fonts/ui_font_Font1.c
    fonts/ui_font_Font2.c
    fonts/ui_font_Font3.c
    fonts/ui_font_Font4.c
    fonts/ui_font_Rus1.c
    fonts/ui_font_FontBig.c)

add_library(ui ${SOURCES})
