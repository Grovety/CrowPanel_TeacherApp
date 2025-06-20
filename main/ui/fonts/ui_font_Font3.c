/*******************************************************************************
 * Size: 15 px
 * Bpp: 1
 * Opts: --bpp 1 --size 15 --font C:/Users/badjo/SquareLine/assets/Montserrat-SemiBold.ttf -o C:/Users/badjo/SquareLine/assets\ui_font_Font3.c --format lvgl --symbols 1234567890mmHgHpa --no-compress --no-prefilter
 ******************************************************************************/

#include "../ui.h"

#ifndef UI_FONT_FONT3
#define UI_FONT_FONT3 1
#endif

#if UI_FONT_FONT3

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0030 "0" */
    0x3e, 0x31, 0xb0, 0x58, 0x3c, 0x1e, 0xf, 0x7,
    0x83, 0x63, 0x1f, 0x0,

    /* U+0031 "1" */
    0xf3, 0x33, 0x33, 0x33, 0x33,

    /* U+0032 "2" */
    0x7c, 0xc6, 0x6, 0x6, 0xe, 0x1c, 0x38, 0x30,
    0x60, 0xff,

    /* U+0033 "3" */
    0x7f, 0x1, 0x81, 0x81, 0x80, 0xf0, 0x7c, 0x6,
    0x3, 0x43, 0x3f, 0x0,

    /* U+0034 "4" */
    0x6, 0x3, 0x1, 0x80, 0xe0, 0x73, 0x18, 0xcf,
    0xfc, 0xc, 0x3, 0x0, 0xc0,

    /* U+0035 "5" */
    0x7e, 0x60, 0x60, 0x60, 0x7c, 0x7, 0x3, 0x3,
    0xc7, 0xfc,

    /* U+0036 "6" */
    0x1e, 0x60, 0x40, 0xc0, 0xfe, 0xe7, 0xc3, 0xc3,
    0x67, 0x3c,

    /* U+0037 "7" */
    0xff, 0xc3, 0xc6, 0x6, 0xc, 0xc, 0xc, 0x18,
    0x18, 0x30,

    /* U+0038 "8" */
    0x7e, 0x61, 0xb0, 0xd8, 0x63, 0xe7, 0x1f, 0x7,
    0x83, 0x63, 0x1f, 0x0,

    /* U+0039 "9" */
    0x3c, 0xe2, 0xc3, 0xc3, 0xe7, 0x7f, 0x3, 0x2,
    0x6, 0x78,

    /* U+0048 "H" */
    0xc1, 0xe0, 0xf0, 0x78, 0x3f, 0xfe, 0xf, 0x7,
    0x83, 0xc1, 0xe0, 0xc0,

    /* U+0061 "a" */
    0x7c, 0x46, 0x2, 0x7f, 0xc3, 0xc7, 0xc7, 0x7b,

    /* U+0067 "g" */
    0x3f, 0xb1, 0xf0, 0x78, 0x3c, 0x1e, 0xd, 0x8e,
    0x7f, 0x1, 0xa1, 0x9f, 0x80,

    /* U+006D "m" */
    0xfe, 0xfb, 0x9e, 0x7c, 0x30, 0xf0, 0xc3, 0xc3,
    0xf, 0xc, 0x3c, 0x30, 0xf0, 0xc3,

    /* U+0070 "p" */
    0xfe, 0x71, 0xb0, 0x78, 0x3c, 0x1e, 0xf, 0x8d,
    0xfc, 0xc0, 0x60, 0x30, 0x0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 162, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 12, .adv_w = 91, .box_w = 4, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 17, .adv_w = 140, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 27, .adv_w = 140, .box_w = 9, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 39, .adv_w = 163, .box_w = 10, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 52, .adv_w = 140, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 62, .adv_w = 150, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 72, .adv_w = 146, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 82, .adv_w = 156, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 94, .adv_w = 150, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 104, .adv_w = 194, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 116, .adv_w = 146, .box_w = 8, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 124, .adv_w = 167, .box_w = 9, .box_h = 11, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 137, .adv_w = 253, .box_w = 14, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 151, .adv_w = 165, .box_w = 9, .box_h = 11, .ofs_x = 1, .ofs_y = -3}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint16_t unicode_list_1[] = {
    0x0, 0x19, 0x1f, 0x25, 0x28
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 48, .range_length = 10, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 72, .range_length = 41, .glyph_id_start = 11,
        .unicode_list = unicode_list_1, .glyph_id_ofs_list = NULL, .list_length = 5, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
    }
};

/*-----------------
 *    KERNING
 *----------------*/


/*Map glyph_ids to kern left classes*/
static const uint8_t kern_left_class_mapping[] =
{
    0, 1, 0, 2, 3, 4, 5, 6,
    7, 0, 1, 0, 8, 9, 8, 10
};

/*Map glyph_ids to kern right classes*/
static const uint8_t kern_right_class_mapping[] =
{
    0, 1, 2, 3, 4, 5, 6, 1,
    7, 8, 9, 0, 10, 11, 12, 12
};

/*Kern values between classes*/
static const int8_t kern_class_values[] =
{
    0, -1, -1, -2, 0, 0, -1, 0,
    0, 0, 0, 0, -1, 0, 0, 0,
    -4, 0, -1, 0, 0, 0, -2, 0,
    0, 0, -1, -1, 0, -2, -2, 0,
    0, 0, 0, 0, 0, -6, -1, -2,
    0, -1, -11, 2, -1, 7, 4, 0,
    0, 0, -1, -1, 0, -1, -3, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -1, 0, 0, 0, 2, 0,
    -5, 2, 0, -2, -16, -4, 0, -4,
    0, -9, -12, -5, 0, -5, -1, 0,
    0, 0, -5, 0, -2, 0, 1, 0,
    0, -1, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -6, -2, -6,
    0, 0, -6, 0, -2, -2, 0, 0
};


/*Collect the kern class' data in one place*/
static const lv_font_fmt_txt_kern_classes_t kern_classes =
{
    .class_pair_values   = kern_class_values,
    .left_class_mapping  = kern_left_class_mapping,
    .right_class_mapping = kern_right_class_mapping,
    .left_class_cnt      = 10,
    .right_class_cnt     = 12,
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
    .cmap_num = 2,
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
const lv_font_t ui_font_Font3 = {
#else
lv_font_t ui_font_Font3 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 13,          /*The maximum line height required by the font*/
    .base_line = 3,             /*Baseline measured from the bottom of the line*/
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



#endif /*#if UI_FONT_FONT3*/

