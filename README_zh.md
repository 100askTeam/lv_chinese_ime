



<h1 align="center"> lv_chinese_ime</h1>

<p align="center">
<img src="src/chinese_ime_demo.gif">
</p>
<p align="center">
lv_chinese_ime 是在 lv_keyboard 的基础上编写的一个自定义部件，它和 lv_keyboard没有什么区别，只是增加了支持中文输入法(拼音)的功能。
</p>


[English](README.md) | **中文** |


# 前言
`lv_chinese_ime` 是在 lv_keyboard 的基础上编写的一个自定义部件（创建接口为：  `lv_chinese_ime_create(lv_obj_t *parent));` ），它和 [lv_keyboard](https://docs.lvgl.io/master/widgets/extra/keyboard.html) 没有什么区别，只是增加了支持中文输入法(拼音)的功能。

所以我们将其称为：**支持中文输入法的LVGL键盘(lv_keyboard)部件增强插件**。

正常来说，只要是lvgl能运行的环境 `lv_chinese_ime` 也能够运行！影响因素主要有两点：使用的字库文件大小和使用的词库大小。

`lv_chinese_ime` 使用起来非常简单，后续自定义拓展功能也很方便，更多功能敬请期待。

![](/src/chinese_ime_demo.gif)


# 使用方法

1. 克隆本仓库到你的项目下： `https://github.com/100askTeam/lv_chinese_ime.git`
2. `lv_chinese_ime` 目录应该和项目的lvgl目录同级(建议)。与 `lv_conf.h`类似，本项目也有一个配置文件，名称为 `lv_chinese_ime_conf.h`
3. 复制 `lv_chinese_ime/lv_chinese_ime_conf_template.h` 到 `lv_chinese_ime` 同级的目录上
4. 将 `lv_chinese_ime_conf.h` 重命名为 `` 。(上面两步操作即： "cp lv_chinese_ime/lv_chinese_ime_conf_template.h ./lv_chinese_ime_conf.h")
5. 将第一个 #if 0 更改为 #if 1 以启用文件的内容
6. 启用或禁用功能
7. 准备字库文件或词库文件，请深入阅读：[lv_chinese_ime/test/README.md](./test/README.md)
8. 使用示例：

```c
/*声明字库*/
LV_FONT_DECLARE(lv_font_source_han_sans_bold_14);

static void ta_event_cb(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    lv_obj_t * kb = lv_event_get_user_data(e);

    if(code == LV_EVENT_FOCUSED) {
        if(lv_indev_get_type(lv_indev_get_act()) != LV_INDEV_TYPE_KEYPAD) {
            lv_keyboard_set_textarea(kb, ta);
            lv_obj_set_style_max_height(kb, LV_HOR_RES * 2 / 3, 0);
            lv_obj_clear_flag(kb, LV_OBJ_FLAG_HIDDEN);
            lv_obj_scroll_to_view_recursive(ta, LV_ANIM_OFF);
        }
    }
    else if(code == LV_EVENT_READY || code == LV_EVENT_CANCEL) {
        lv_obj_add_flag(kb, LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_state(ta, LV_STATE_FOCUSED);
        lv_indev_reset(NULL, ta);   /*To forget the last clicked object to make it focusable again*/
    }
}

void your_test_function(void)
{
    lv_obj_t * kb = lv_chinese_ime_create(lv_scr_act());
    lv_chinese_ime_set_text_font(&lv_font_source_han_sans_bold_14, 0);   // 使用自定义的字库
    //lv_chinese_ime_set_dict(your_dict); // 使用自定义的词库，如果不设置将使用内置词库


    /* ta1 */
    lv_obj_t * ta1 = lv_textarea_create(lv_scr_act());
    lv_obj_set_style_text_font(ta1, &lv_font_source_han_sans_bold_14, 0);   // 使用自定义的字库
    lv_obj_align(ta1, LV_ALIGN_TOP_LEFT, 10, 10);

    lv_keyboard_set_textarea(kb, ta1);

    lv_obj_add_event_cb(ta1, ta_event_cb, LV_EVENT_ALL, kb);

    /* ta2 */
    lv_obj_t * ta2 = lv_textarea_create(lv_scr_act());
    lv_obj_set_style_text_font(ta2, &lv_font_source_han_sans_bold_14, 0);   // 使用自定义的字库
    lv_obj_align_to(ta2, ta1,LV_ALIGN_OUT_RIGHT_MID, 10, 0);

    lv_obj_add_event_cb(ta2, ta_event_cb, LV_EVENT_ALL, kb);
}
```

# 注意事项
- 在项目中只能同时存在一个 `lv_chinese_ime` 。
- 不需要 `lv_chinese_ime` 的时候，请使用 `lv_chinese_ime_del` 将其删除。
- 在正常删除 `lv_chinese_ime` 之后可以通过[上面](#使用方法)的使用示例重新创建使用。


# 关于我们
这是一个开源的项目，非常欢迎大家参与改进lv_chinese_ime项目！
作者联系邮箱: smilezyb@163.com