/*******************************************************************************
 * Size: 20 px
 * Bpp: 1
 * Opts: --bpp 1 --size 20 --font C:/Users/badjo/SquareLine/assets/Montserrat-SemiBold.ttf -o C:/Users/badjo/SquareLine/assets\ui_font_CO2Font.c --format lvgl -r 32 --symbols ₂COVIAQ°CmmHg%phtfFPha --no-compress --no-prefilter
 ******************************************************************************/

#include "../ui.h"

#ifndef UI_FONT_CO2FONT
#define UI_FONT_CO2FONT 1
#endif

#if UI_FONT_CO2FONT

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0025 "%" */
    0x38, 0x18, 0x7c, 0x18, 0xc6, 0x30, 0xc6, 0x60,
    0xc6, 0x60, 0xc6, 0xc0, 0x7d, 0x9c, 0x39, 0xbe,
    0x3, 0x63, 0x6, 0x63, 0x6, 0x63, 0xc, 0x63,
    0x18, 0x3e, 0x18, 0x1c,

    /* U+0041 "A" */
    0x3, 0x80, 0x7, 0x0, 0x1f, 0x0, 0x36, 0x0,
    0xee, 0x1, 0x8c, 0x7, 0x1c, 0xc, 0x38, 0x38,
    0x38, 0x7f, 0xf1, 0xff, 0xe3, 0x80, 0xe6, 0x0,
    0xdc, 0x1, 0xc0,

    /* U+0043 "C" */
    0x7, 0xe0, 0xff, 0xcf, 0xe, 0xe0, 0xf, 0x0,
    0x70, 0x3, 0x80, 0x1c, 0x0, 0xe0, 0x7, 0x80,
    0x1c, 0x0, 0x78, 0x71, 0xff, 0x83, 0xf0,

    /* U+0046 "F" */
    0xff, 0xff, 0xfe, 0x3, 0x80, 0xe0, 0x38, 0xf,
    0xff, 0xff, 0xe0, 0x38, 0xe, 0x3, 0x80, 0xe0,
    0x38, 0x0,

    /* U+0048 "H" */
    0xe0, 0x3f, 0x1, 0xf8, 0xf, 0xc0, 0x7e, 0x3,
    0xf0, 0x1f, 0xff, 0xff, 0xff, 0xe0, 0x3f, 0x1,
    0xf8, 0xf, 0xc0, 0x7e, 0x3, 0xf0, 0x1c,

    /* U+0049 "I" */
    0xff, 0xff, 0xff, 0xff, 0xff, 0xc0,

    /* U+004F "O" */
    0x7, 0xc0, 0x3f, 0xe0, 0xf1, 0xe3, 0x80, 0xef,
    0x1, 0xfc, 0x1, 0xf8, 0x3, 0xf0, 0x7, 0xe0,
    0xf, 0xe0, 0x3d, 0xc0, 0x71, 0xe3, 0xc1, 0xff,
    0x1, 0xfc, 0x0,

    /* U+0050 "P" */
    0xff, 0x8f, 0xfe, 0xe0, 0xee, 0x7, 0xe0, 0x7e,
    0x7, 0xe0, 0x7e, 0xe, 0xff, 0xef, 0xf8, 0xe0,
    0xe, 0x0, 0xe0, 0xe, 0x0,

    /* U+0051 "Q" */
    0x7, 0xc0, 0x1f, 0xf0, 0x3c, 0x78, 0x70, 0x1c,
    0xf0, 0x1e, 0xe0, 0xe, 0xe0, 0xe, 0xe0, 0xe,
    0xe0, 0xe, 0xf0, 0x1e, 0x70, 0x1c, 0x7c, 0x78,
    0x3f, 0xf0, 0xf, 0xe0, 0x1, 0xc2, 0x0, 0xfe,
    0x0, 0x3c,

    /* U+0056 "V" */
    0xe0, 0xc, 0xc0, 0x39, 0xc0, 0x73, 0x80, 0xc3,
    0x83, 0x87, 0x6, 0x7, 0x1c, 0xe, 0x30, 0xc,
    0xe0, 0x1d, 0xc0, 0x3f, 0x0, 0x3e, 0x0, 0x78,
    0x0, 0x70, 0x0,

    /* U+0061 "a" */
    0x3f, 0x1f, 0xe4, 0x3c, 0x7, 0x3f, 0xdf, 0xfe,
    0x1f, 0x87, 0xe3, 0xdf, 0xf3, 0xdc,

    /* U+0066 "f" */
    0x1f, 0x3e, 0x70, 0x70, 0xfe, 0xfe, 0x70, 0x70,
    0x70, 0x70, 0x70, 0x70, 0x70, 0x70, 0x70,

    /* U+0067 "g" */
    0x1f, 0x73, 0xff, 0x70, 0xfe, 0x7, 0xe0, 0x7e,
    0x7, 0xe0, 0x7e, 0x7, 0x70, 0xf3, 0xff, 0x1f,
    0x70, 0x7, 0x60, 0xe7, 0xfe, 0x3f, 0x80,

    /* U+0068 "h" */
    0xe0, 0x1c, 0x3, 0x80, 0x70, 0xe, 0xf9, 0xff,
    0xbc, 0x7f, 0x7, 0xe0, 0xfc, 0x1f, 0x83, 0xf0,
    0x7e, 0xf, 0xc1, 0xf8, 0x38,

    /* U+006D "m" */
    0xef, 0x1e, 0x7f, 0xff, 0xbc, 0xf9, 0xfc, 0x38,
    0x7e, 0x1c, 0x3f, 0xe, 0x1f, 0x87, 0xf, 0xc3,
    0x87, 0xe1, 0xc3, 0xf0, 0xe1, 0xf8, 0x70, 0xe0,

    /* U+0070 "p" */
    0xef, 0x8f, 0xfc, 0xf0, 0xee, 0x7, 0xe0, 0x7e,
    0x7, 0xe0, 0x7f, 0x7, 0xf0, 0xef, 0xfc, 0xef,
    0x8e, 0x0, 0xe0, 0xe, 0x0, 0xe0, 0x0,

    /* U+0074 "t" */
    0x38, 0x38, 0x38, 0xfe, 0xfe, 0x38, 0x38, 0x38,
    0x38, 0x38, 0x38, 0x38, 0x3e, 0x1e,

    /* U+00B0 "°" */
    0x38, 0xfb, 0x1c, 0x1c, 0x6f, 0x8e, 0x0,

    /* U+2082 "₂" */
    0xfd, 0xc, 0x18, 0x71, 0xc7, 0x18, 0x7f
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 88, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 275, .box_w = 16, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 29, .adv_w = 240, .box_w = 15, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 56, .adv_w = 233, .box_w = 13, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 79, .adv_w = 204, .box_w = 10, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 97, .adv_w = 259, .box_w = 13, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 120, .adv_w = 102, .box_w = 3, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 126, .adv_w = 269, .box_w = 15, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 153, .adv_w = 232, .box_w = 12, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 174, .adv_w = 269, .box_w = 16, .box_h = 17, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 208, .adv_w = 233, .box_w = 15, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 235, .adv_w = 194, .box_w = 10, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 249, .adv_w = 118, .box_w = 8, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 264, .adv_w = 222, .box_w = 12, .box_h = 15, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 287, .adv_w = 219, .box_w = 11, .box_h = 15, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 308, .adv_w = 337, .box_w = 17, .box_h = 11, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 332, .adv_w = 220, .box_w = 12, .box_h = 15, .ofs_x = 2, .ofs_y = -4},
    {.bitmap_index = 355, .adv_w = 136, .box_w = 8, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 369, .adv_w = 134, .box_w = 7, .box_h = 7, .ofs_x = 1, .ofs_y = 8},
    {.bitmap_index = 376, .adv_w = 138, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = -2}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint16_t unicode_list_0[] = {
    0x0, 0x5, 0x21, 0x23, 0x26, 0x28, 0x29, 0x2f,
    0x30, 0x31, 0x36, 0x41, 0x46, 0x47, 0x48, 0x4d,
    0x50, 0x54, 0x90, 0x2062
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 8291, .glyph_id_start = 1,
        .unicode_list = unicode_list_0, .glyph_id_ofs_list = NULL, .list_length = 20, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
    }
};

/*-----------------
 *    KERNING
 *----------------*/


/*Map glyph_ids to kern left classes*/
static const uint8_t kern_left_class_mapping[] =
{
    0, 0, 1, 2, 3, 4, 5, 5,
    6, 7, 6, 8, 9, 10, 11, 9,
    9, 12, 13, 14, 0
};

/*Map glyph_ids to kern right classes*/
static const uint8_t kern_right_class_mapping[] =
{
    0, 0, 1, 2, 3, 4, 4, 4,
    3, 4, 3, 5, 6, 0, 7, 0,
    8, 8, 9, 10, 0
};

/*Kern values between classes*/
static const int8_t kern_class_values[] =
{
    -39, 0, 0, 0, 0, 0, 0, 0,
    0, -8, 0, 6, -3, 0, -12, 0,
    -2, 0, -2, -30, 0, -5, -5, 0,
    -2, -2, -6, 0, 0, 3, 0, -10,
    -3, 0, 0, -5, -5, -3, 0, 10,
    0, 0, 0, 0, -2, 0, 0, 0,
    0, 0, 0, -3, 0, 0, -7, 0,
    0, 0, 2, 3, 0, -14, 0, -3,
    -5, -5, -4, -5, 2, 6, 0, -12,
    -7, -5, 0, -18, -18, -11, -2, 8,
    -9, 0, 0, 0, 0, 0, 2, 0,
    0, -5, 5, 0, 0, 0, 0, -3,
    -3, 26, 0, 11, 0, 0, 0, 0,
    -3, 0, 0, 0, 0, 0, -8, -5,
    0, 0, -13, -2, 0, 0, 0, -5,
    0, 0, 0, 0, 0, 0, -6, 0,
    -4, -2, 8, 0, 0, 0, 0, 0,
    0, 0, 0, 0
};


/*Collect the kern class' data in one place*/
static const lv_font_fmt_txt_kern_classes_t kern_classes =
{
    .class_pair_values   = kern_class_values,
    .left_class_mapping  = kern_left_class_mapping,
    .right_class_mapping = kern_right_class_mapping,
    .left_class_cnt      = 14,
    .right_class_cnt     = 10,
};

/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LVGL_VERSION_MAJOR == 8
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
#endif

#if LVGL_VERSION_MAJOR >= 8
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = &kern_classes,
    .kern_scale = 16,
    .cmap_num = 1,
    .bpp = 1,
    .kern_classes = 1,
    .bitmap_format = 0,
#if LVGL_VERSION_MAJOR == 8
    .cache = &cache
#endif
};



/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LVGL_VERSION_MAJOR >= 8
const lv_font_t ui_font_CO2Font = {
#else
lv_font_t ui_font_CO2Font = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 19,          /*The maximum line height required by the font*/
    .base_line = 4,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -1,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = NULL,
#endif
    .user_data = NULL,
};



#endif /*#if UI_FONT_CO2FONT*/

