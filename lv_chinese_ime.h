/**
 * @file lv_chinese_ime.h
 *
 */

#ifndef LV_CHINESE_IME_H
#define LV_CHINESE_IME_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/
#if defined(LV_LVGL_H_INCLUDE_SIMPLE)
#include "lvgl.h"
#else
#include "../lvgl/lvgl.h"
#endif

#if defined(LV_CHINESE_IME_CONF_PATH)
#define __LV_TO_STR_AUX(x) #x
#define __LV_TO_STR(x) __LV_TO_STR_AUX(x)
#include __LV_TO_STR(LV_CHINESE_IME_CONF_PATH)
#undef __LV_TO_STR_AUX
#undef __LV_TO_STR
#elif defined(LV_CHINESE_IME_CONF_INCLUDE_SIMPLE)
#include "lv_chinese_ime_conf.h"
#else
#include "../lv_chinese_ime_conf.h"
#endif

#include "src/chinese_ime.h"



/*********************
 *      DEFINES
 *********************/
/*Test  lvgl version*/
#if LV_VERSION_CHECK(8, 1, 0) == 0
#error "lv_chinese_ime: Wrong lvgl version"
#endif

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/


/**********************
 *      MACROS
 **********************/


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /*LV_CHINESE_IME_H*/
