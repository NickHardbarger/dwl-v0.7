/* Taken from https://github.com/djpohly/dwl/issues/466 */
#define COLOR(hex)                                                             \
  {((hex >> 24) & 0xFF) / 255.0f, ((hex >> 16) & 0xFF) / 255.0f,               \
   ((hex >> 8) & 0xFF) / 255.0f, (hex & 0xFF) / 255.0f}
/* appearance */
static const int sloppyfocus = 1; /* focus follows mouse */
static const int bypass_surface_visibility =
    0; /* 1 means idle inhibitors will disable idle tracking even if it's
          surface isn't visible  */
static const int smartgaps =
    0; /* 1 means no outer gap when there is only one window */
static const int monoclegaps = 0; /* 1 means outer gaps in monocle layout */
static const unsigned int borderpx = 3; /* border pixel of windows & bar */
static const unsigned int gappih = 10;  /* horiz inner gap between windows */
static const unsigned int gappiv = 10;  /* vert inner gap between windows */
static const unsigned int gappoh =
    10; /* horiz outer gap between windows and screen edge */
static const unsigned int gappov =
    10; /* vert outer gap between windows and screen edge */
static const int showbar = 1;  /* 0 means no bar */
static const int topbar = 1;   /* 0 means bottom bar */
static const int vertpad = 10; /* vertical padding of bar */
static const int sidepad = 10; /* horizontal padding of bar */
static const char *fonts[] = {"JetBrainsMonoNF:size=12",
                              "Noto Sans Mono CJK SC:size=12"};
/* Colorscheme: gruvbox */
static const uint32_t colwe = 0xebdbb2ff;  /* White */
static const uint32_t colwe2 = 0xd5c4a1ff; /* White 2 */
static const uint32_t colbk = 0x282828ff;  /* Black */
static const uint32_t colgy = 0x928374ff;  /* Grey */
static const uint32_t coloe = 0xd65d0eff;  /* Orange */
static const uint32_t coloe2 = 0xfe8019ff; /* Orange 2 */
static const uint32_t colbe = 0x458588ff;  /* Blue */
static const uint32_t colbe2 = 0x83a598ff; /* Blue 2 */
static const uint32_t colaa2 = 0x8ec07cff; /* Aqua 2 */
static const uint32_t colrd = 0xcc241dff;  /* Red */
static const uint32_t colgn = 0x98971aff;  /* Green */
static const uint32_t colgn2 = 0xb8bb26ff; /* Green 2 */
static const uint32_t colpe2 = 0xd3869bff; /* Purple 2 */

static const float rootcolor[] = COLOR(colbk);
/* This conforms to the xdg-protocol. Set the alpha to zero to restore the old
 * behavior */
static const float fullscreen_bg[] = {0.1f, 0.1f, 0.1f,
                                      1.0f}; /* You can also use glsl colors */
static uint32_t colors[][3] = {
    /*              fg     bg     border    */
    [SchemeNorm] = {colpe2, colbk, colgy},
    [SchemeSel] = {colbk, colaa2, coloe},
    [SchemeUrg] = {0, 0, colrd},
    [SchemeBar] = {0, 0, coloe},
};
/* tagging - TAGCOUNT must be no greater than 31 */
/* Tags: emacs, terminal, browser, media, misc */
static char *tags[] = {"", "", "󰖟", "󰕼", ""};
/* static char *tags[] = {"一", "二", "三", "四", "五", "六", "七", "八", "九"};
 */

/* logging */
static int log_level = WLR_ERROR;

/* volume */
static const char *volumeup[] = {"pactl", "set-sink-volume", "@DEFAULT_SINK@",
                                 "+5%", NULL};
static const char *volumedown[] = {"pactl", "set-sink-volume", "@DEFAULT_SINK@",
                                   "-5%", NULL};
static const char *mutevolume[] = {"pactl", "set-sink-mute", "@DEFAULT_SINK@",
                                   "toggle", NULL};
static const char *mutemic[] = {"pactl", "set-source-mute", "@DEFAULT_SOURCE@",
                                "toggle", NULL};

/* Autostart */
static const char *const autostart[] = {
    "swaybg", "-i", "/home/nh/nix/system/wallpapers/columbus.jpg", NULL,
    /* "mako", NULL, */ /* Redundant? */
    NULL                /* terminate */
};
/* NOTE: ALWAYS keep a rule declared even if you don't use rules (e.g leave at
   least one example) */
static const Rule rules[] = {
    /* app_id             title       tags mask     isfloating  isterm noswallow
       monitor */
    /* examples: */
    {"Gimp_EXAMPLE", NULL, 0, 1, 0, 0,
     -1}, /* Start on currently visible tags floating, not tiled */
    {"firefox_EXAMPLE", NULL, 1 << 8, 0, 0, 0, -1}, /* Start on ONLY tag "9" */
    {"catty", NULL, 0, 0, 1, 1, -1},
    {"foot", NULL, 0, 0, 1, 1, -1},
    /* make terminals swallow clients that are not themselves */
};

/* layout(s) */
static const Layout layouts[] = {
    /* symbol     arrange function */
    {"[]=", tile},
    {"><>", NULL}, /* no layout function means floating behavior */
    {"[M]", monocle},
};

/* monitors */
/* (x=-1, y=-1) is reserved as an "autoconfigure" monitor position indicator
 * WARNING: negative values other than (-1, -1) cause problems with Xwayland
 * clients https://gitlab.freedesktop.org/xorg/xserver/-/issues/899
 */
/* NOTE: ALWAYS add a fallback rule, even if you are completely sure it won't be
 * used */
static const MonitorRule monrules[] = {
    /* name       mfact  nmaster scale layout       rotate/reflect x    y */
    /* example of a HiDPI laptop monitor:
    { "eDP-1",    0.5f,  1,      2,    &layouts[0], WL_OUTPUT_TRANSFORM_NORMAL,
    -1,  -1 },
    */
    /* defaults */
    {NULL, 0.55f, 1, 1, &layouts[0], WL_OUTPUT_TRANSFORM_NORMAL, -1, -1},
};

/* keyboard */
static const struct xkb_rule_names xkb_rules = {
    /* can specify fields: rules, model, layout, variant, options */
    .options = "ctrl:nocaps",
};

static const int repeat_rate = 25;
static const int repeat_delay = 600;

/* Trackpad */
static const int tap_to_click = 1;
static const int tap_and_drag = 1;
static const int drag_lock = 1;
static const int natural_scrolling = 0;
static const int disable_while_typing = 1;
static const int left_handed = 0;
static const int middle_button_emulation = 0;
/* You can choose between:
LIBINPUT_CONFIG_SCROLL_NO_SCROLL
LIBINPUT_CONFIG_SCROLL_2FG
LIBINPUT_CONFIG_SCROLL_EDGE
LIBINPUT_CONFIG_SCROLL_ON_BUTTON_DOWN
*/
static const enum libinput_config_scroll_method scroll_method =
    LIBINPUT_CONFIG_SCROLL_2FG;

/* You can choose between:
LIBINPUT_CONFIG_CLICK_METHOD_NONE
LIBINPUT_CONFIG_CLICK_METHOD_BUTTON_AREAS
LIBINPUT_CONFIG_CLICK_METHOD_CLICKFINGER
*/
static const enum libinput_config_click_method click_method =
    LIBINPUT_CONFIG_CLICK_METHOD_BUTTON_AREAS;

/* You can choose between:
LIBINPUT_CONFIG_SEND_EVENTS_ENABLED
LIBINPUT_CONFIG_SEND_EVENTS_DISABLED
LIBINPUT_CONFIG_SEND_EVENTS_DISABLED_ON_EXTERNAL_MOUSE
*/
static const uint32_t send_events_mode = LIBINPUT_CONFIG_SEND_EVENTS_ENABLED;

/* You can choose between:
LIBINPUT_CONFIG_ACCEL_PROFILE_FLAT
LIBINPUT_CONFIG_ACCEL_PROFILE_ADAPTIVE
*/
static const enum libinput_config_accel_profile accel_profile =
    LIBINPUT_CONFIG_ACCEL_PROFILE_ADAPTIVE;
static const double accel_speed = 0.0;

/* You can choose between:
LIBINPUT_CONFIG_TAP_MAP_LRM -- 1/2/3 finger tap maps to left/right/middle
LIBINPUT_CONFIG_TAP_MAP_LMR -- 1/2/3 finger tap maps to left/middle/right
*/
static const enum libinput_config_tap_button_map button_map =
    LIBINPUT_CONFIG_TAP_MAP_LRM;

/* If you want to use the win key for MODKEY, use WLR_MODIFIER_LOGO */
#define MODKEY WLR_MODIFIER_ALT

#define TAGKEYS(KEY, SKEY, TAG)                                                \
  {MODKEY, KEY, view, {.ui = 1 << TAG}},                                       \
      {MODKEY | WLR_MODIFIER_CTRL, KEY, toggleview, {.ui = 1 << TAG}},         \
      {MODKEY | WLR_MODIFIER_SHIFT, SKEY, tag, {.ui = 1 << TAG}}, {            \
    MODKEY | WLR_MODIFIER_CTRL | WLR_MODIFIER_SHIFT, SKEY, toggletag, {        \
      .ui = 1 << TAG                                                           \
    }                                                                          \
  }

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd)                                                             \
  {                                                                            \
    .v = (const char *[]) { "/bin/sh", "-c", cmd, NULL }                       \
  }

/* commands */
static const char *termcmd[] = {"foot", NULL};
static const char *menucmd[] = {"run-wmenu", NULL};

static const Key keys[] = {
    /* Note that Shift changes certain key codes: c -> C, 2 -> at, etc. */
    /* modifier                  key                 function        argument */
    {MODKEY, XKB_KEY_r, spawn, {.v = menucmd}},
    {MODKEY, XKB_KEY_Return, spawn, {.v = termcmd}},
    {MODKEY, XKB_KEY_b, togglebar, {0}},
    {MODKEY, XKB_KEY_j, focusstack, {.i = +1}},
    {MODKEY, XKB_KEY_k, focusstack, {.i = -1}},
    {MODKEY, XKB_KEY_i, incnmaster, {.i = +1}},
    {MODKEY, XKB_KEY_d, incnmaster, {.i = -1}},
    {MODKEY, XKB_KEY_h, setmfact, {.f = -0.05f}},
    {MODKEY, XKB_KEY_l, setmfact, {.f = +0.05f}},
    {MODKEY | WLR_MODIFIER_LOGO, XKB_KEY_h, incgaps, {.i = +1}},
    {MODKEY | WLR_MODIFIER_LOGO, XKB_KEY_l, incgaps, {.i = -1}},
    {MODKEY | WLR_MODIFIER_LOGO | WLR_MODIFIER_SHIFT,
     XKB_KEY_H,
     incogaps,
     {.i = +1}},
    {MODKEY | WLR_MODIFIER_LOGO | WLR_MODIFIER_SHIFT,
     XKB_KEY_L,
     incogaps,
     {.i = -1}},
    {MODKEY | WLR_MODIFIER_LOGO | WLR_MODIFIER_CTRL,
     XKB_KEY_h,
     incigaps,
     {.i = +1}},
    {MODKEY | WLR_MODIFIER_LOGO | WLR_MODIFIER_CTRL,
     XKB_KEY_l,
     incigaps,
     {.i = -1}},
    {MODKEY | WLR_MODIFIER_LOGO, XKB_KEY_0, togglegaps, {0}},
    {MODKEY | WLR_MODIFIER_LOGO | WLR_MODIFIER_SHIFT,
     XKB_KEY_parenright,
     defaultgaps,
     {0}},
    {MODKEY, XKB_KEY_y, incihgaps, {.i = +1}},
    {MODKEY, XKB_KEY_o, incihgaps, {.i = -1}},
    {MODKEY | WLR_MODIFIER_CTRL, XKB_KEY_y, incivgaps, {.i = +1}},
    {MODKEY | WLR_MODIFIER_CTRL, XKB_KEY_o, incivgaps, {.i = -1}},
    {MODKEY | WLR_MODIFIER_LOGO, XKB_KEY_y, incohgaps, {.i = +1}},
    {MODKEY | WLR_MODIFIER_LOGO, XKB_KEY_o, incohgaps, {.i = -1}},
    {MODKEY | WLR_MODIFIER_SHIFT, XKB_KEY_Y, incovgaps, {.i = +1}},
    {MODKEY | WLR_MODIFIER_SHIFT, XKB_KEY_O, incovgaps, {.i = -1}},
    {MODKEY, XKB_KEY_Tab, zoom, {0}},
    {MODKEY | WLR_MODIFIER_SHIFT, XKB_KEY_Return, view, {0}},
    {MODKEY | WLR_MODIFIER_SHIFT, XKB_KEY_C, killclient, {0}},
    {MODKEY, XKB_KEY_t, setlayout, {.v = &layouts[0]}},
    {MODKEY, XKB_KEY_f, setlayout, {.v = &layouts[1]}},
    {MODKEY, XKB_KEY_m, setlayout, {.v = &layouts[2]}},
    {MODKEY, XKB_KEY_space, setlayout, {0}},
    {MODKEY | WLR_MODIFIER_SHIFT, XKB_KEY_space, togglefloating, {0}},
    {MODKEY, XKB_KEY_e, togglefullscreen, {0}},
    {MODKEY, XKB_KEY_0, view, {.ui = ~0}},
    {MODKEY | WLR_MODIFIER_SHIFT, XKB_KEY_parenright, tag, {.ui = ~0}},
    {MODKEY, XKB_KEY_comma, focusmon, {.i = WLR_DIRECTION_LEFT}},
    {MODKEY, XKB_KEY_period, focusmon, {.i = WLR_DIRECTION_RIGHT}},
    {MODKEY | WLR_MODIFIER_SHIFT,
     XKB_KEY_less,
     tagmon,
     {.i = WLR_DIRECTION_LEFT}},
    {MODKEY | WLR_MODIFIER_SHIFT,
     XKB_KEY_greater,
     tagmon,
     {.i = WLR_DIRECTION_RIGHT}},
    TAGKEYS(XKB_KEY_1, XKB_KEY_exclam, 0),
    TAGKEYS(XKB_KEY_2, XKB_KEY_at, 1),
    TAGKEYS(XKB_KEY_3, XKB_KEY_numbersign, 2),
    TAGKEYS(XKB_KEY_4, XKB_KEY_dollar, 3),
    TAGKEYS(XKB_KEY_5, XKB_KEY_percent, 4),
    TAGKEYS(XKB_KEY_6, XKB_KEY_asciicircum, 5),
    TAGKEYS(XKB_KEY_7, XKB_KEY_ampersand, 6),
    TAGKEYS(XKB_KEY_8, XKB_KEY_asterisk, 7),
    TAGKEYS(XKB_KEY_9, XKB_KEY_parenleft, 8),
    {MODKEY | WLR_MODIFIER_SHIFT, XKB_KEY_Q, quit, {0}},
    {0, XKB_KEY_XF86AudioRaiseVolume, spawn, {.v = volumeup}},
    {0, XKB_KEY_XF86AudioLowerVolume, spawn, {.v = volumedown}},
    {0, XKB_KEY_XF86AudioMute, spawn, {.v = mutevolume}},
    {0, XKB_KEY_XF86AudioMicMute, spawn, {.v = mutemic}},

    /* Ctrl-Alt-Backspace and Ctrl-Alt-Fx used to be handled by X server */
    {WLR_MODIFIER_CTRL | WLR_MODIFIER_ALT, XKB_KEY_Terminate_Server, quit, {0}},
/* Ctrl-Alt-Fx is used to switch to another VT, if you don't know what a VT is
 * do not remove them.
 */
#define CHVT(n)                                                                \
  {                                                                            \
    WLR_MODIFIER_CTRL | WLR_MODIFIER_ALT, XKB_KEY_XF86Switch_VT_##n, chvt, {   \
      .ui = (n)                                                                \
    }                                                                          \
  }
    CHVT(1),
    CHVT(2),
    CHVT(3),
    CHVT(4),
    CHVT(5),
    CHVT(6),
    CHVT(7),
    CHVT(8),
    CHVT(9),
    CHVT(10),
    CHVT(11),
    CHVT(12),
};

static const Button buttons[] = {
    {ClkLtSymbol, 0, BTN_LEFT, setlayout, {.v = &layouts[0]}},
    {ClkLtSymbol, 0, BTN_RIGHT, setlayout, {.v = &layouts[2]}},
    {ClkTitle, 0, BTN_MIDDLE, zoom, {0}},
    {ClkStatus, 0, BTN_MIDDLE, spawn, {.v = termcmd}},
    {ClkClient, MODKEY, BTN_LEFT, moveresize, {.ui = CurMove}},
    {ClkClient, MODKEY, BTN_MIDDLE, togglefloating, {0}},
    {ClkClient, MODKEY, BTN_RIGHT, moveresize, {.ui = CurResize}},
    {ClkTagBar, 0, BTN_LEFT, view, {0}},
    {ClkTagBar, 0, BTN_RIGHT, toggleview, {0}},
    {ClkTagBar, MODKEY, BTN_LEFT, tag, {0}},
    {ClkTagBar, MODKEY, BTN_RIGHT, toggletag, {0}},
};
