

#ifndef __gl12_defines_h_
#define __gl12_defines_h_

#ifdef __gl_h_
#error OpenGL header already included, remove this include, cppgl already provides it
#endif
#define __gl_h_

#if defined(_WIN32) && !defined(APIENTRY) && !defined(__CYGWIN__) && !defined(__SCITECH_SNAP__)
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN 1
#endif
#include <windows.h>
#endif

#ifndef APIENTRY
#define APIENTRY
#endif
#ifndef APIENTRYP
#define APIENTRYP APIENTRY *
#endif

#ifdef __cplusplus
extern "C" {
#endif

struct cppglGLversionStruct {
    int major;
    int minor;
};

typedef void* (* CPPGLloadproc)(const char *name);

#ifndef GLAPI
# if defined(CPPGL_GLAPI_EXPORT)
#  if defined(WIN32) || defined(__CYGWIN__)
#   if defined(CPPGL_GLAPI_EXPORT_BUILD)
#    if defined(__GNUC__)
#     define GLAPI __attribute__ ((dllexport)) extern
#    else
#     define GLAPI __declspec(dllexport) extern
#    endif
#   else
#    if defined(__GNUC__)
#     define GLAPI __attribute__ ((dllimport)) extern
#    else
#     define GLAPI __declspec(dllimport) extern
#    endif
#   endif
#  elif defined(__GNUC__) && defined(CPPGL_GLAPI_EXPORT_BUILD)
#   define GLAPI __attribute__ ((visibility ("default"))) extern
#  else
#   define GLAPI extern
#  endif
# else
#  define GLAPI extern
# endif
#endif

GLAPI struct cppglGLversionStruct GLVersion;

GLAPI int cppglLoadGL(void);

GLAPI int cppglLoadGLLoader(CPPGLloadproc);

#include <stddef.h>
#include "KHR/khrplatform.h"
#ifndef GLEXT_64_TYPES_DEFINED
/* This code block is duplicated in glxext.h, so must be protected */
#define GLEXT_64_TYPES_DEFINED
/* Define int32_t, int64_t, and uint64_t types for UST/MSC */
/* (as used in the GL_EXT_timer_query extension). */
#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
#include <inttypes.h>
#elif defined(__sun__) || defined(__digital__)
#include <inttypes.h>
#if defined(__STDC__)
#if defined(__arch64__) || defined(_LP64)
typedef long int int64_t;
typedef unsigned long int uint64_t;
#else
typedef long long int int64_t;
typedef unsigned long long int uint64_t;
#endif /* __arch64__ */
#endif /* __STDC__ */
#elif defined( __VMS ) || defined(__sgi)
#include <inttypes.h>
#elif defined(__SCO__) || defined(__USLC__)
#include <stdint.h>
#elif defined(__UNIXOS2__) || defined(__SOL64__)
typedef long int int32_t;
typedef long long int int64_t;
typedef unsigned long long int uint64_t;
#elif defined(_WIN32) && defined(__GNUC__)
#include <stdint.h>
#elif defined(_WIN32)
typedef __int32 int32_t;
typedef __int64 int64_t;
typedef unsigned __int64 uint64_t;
#else
/* Fallback if nothing above works */
#include <inttypes.h>
#endif
#endif
typedef unsigned int GLenum;
typedef unsigned char GLboolean;
typedef unsigned int GLbitfield;
typedef void GLvoid;
typedef signed char GLbyte;
typedef short GLshort;
typedef int GLint;
typedef int GLclampx;
typedef unsigned char GLubyte;
typedef unsigned short GLushort;
typedef unsigned int GLuint;
typedef int GLsizei;
typedef float GLfloat;
typedef float GLclampf;
typedef double GLdouble;
typedef double GLclampd;
typedef void *GLeglImageOES;
typedef char GLchar;
typedef char GLcharARB;
#ifdef __APPLE__
typedef void *GLhandleARB;
#else
typedef unsigned int GLhandleARB;
#endif
typedef unsigned short GLhalfARB;
typedef unsigned short GLhalf;
typedef GLint GLfixed;
#if defined(__ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__) && (__ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__ > 1060)
typedef long GLintptr;
#else
typedef ptrdiff_t GLintptr;
#endif
#if defined(__ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__) && (__ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__ > 1060)
typedef long GLsizeiptr;
#else
typedef ptrdiff_t GLsizeiptr;
#endif
typedef int64_t GLint64;
typedef uint64_t GLuint64;
#if defined(__ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__) && (__ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__ > 1060)
typedef long GLintptrARB;
#else
typedef ptrdiff_t GLintptrARB;
#endif
#if defined(__ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__) && (__ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__ > 1060)
typedef long GLsizeiptrARB;
#else
typedef ptrdiff_t GLsizeiptrARB;
#endif
typedef int64_t GLint64EXT;
typedef uint64_t GLuint64EXT;
typedef struct __GLsync *GLsync;
struct _cl_context;
struct _cl_event;
typedef void (APIENTRY *GLDEBUGPROC)(GLenum source,GLenum type,GLuint id,GLenum severity,GLsizei length,const GLchar *message,const void *userParam);
typedef void (APIENTRY *GLDEBUGPROCARB)(GLenum source,GLenum type,GLuint id,GLenum severity,GLsizei length,const GLchar *message,const void *userParam);
typedef void (APIENTRY *GLDEBUGPROCKHR)(GLenum source,GLenum type,GLuint id,GLenum severity,GLsizei length,const GLchar *message,const void *userParam);
typedef void (APIENTRY *GLDEBUGPROCAMD)(GLuint id,GLenum category,GLenum severity,GLsizei length,const GLchar *message,void *userParam);
typedef unsigned short GLhalfNV;
typedef GLintptr GLvdpauSurfaceNV;
#define GL_DEPTH_BUFFER_BIT 0x00000100
#define GL_STENCIL_BUFFER_BIT 0x00000400
#define GL_COLOR_BUFFER_BIT 0x00004000
#define GL_FALSE 0
#define GL_TRUE 1
#define GL_POINTS 0x0000
#define GL_LINES 0x0001
#define GL_LINE_LOOP 0x0002
#define GL_LINE_STRIP 0x0003
#define GL_TRIANGLES 0x0004
#define GL_TRIANGLE_STRIP 0x0005
#define GL_TRIANGLE_FAN 0x0006
#define GL_QUADS 0x0007
#define GL_NEVER 0x0200
#define GL_LESS 0x0201
#define GL_EQUAL 0x0202
#define GL_LEQUAL 0x0203
#define GL_GREATER 0x0204
#define GL_NOTEQUAL 0x0205
#define GL_GEQUAL 0x0206
#define GL_ALWAYS 0x0207
#define GL_ZERO 0
#define GL_ONE 1
#define GL_SRC_COLOR 0x0300
#define GL_ONE_MINUS_SRC_COLOR 0x0301
#define GL_SRC_ALPHA 0x0302
#define GL_ONE_MINUS_SRC_ALPHA 0x0303
#define GL_DST_ALPHA 0x0304
#define GL_ONE_MINUS_DST_ALPHA 0x0305
#define GL_DST_COLOR 0x0306
#define GL_ONE_MINUS_DST_COLOR 0x0307
#define GL_SRC_ALPHA_SATURATE 0x0308
#define GL_NONE 0
#define GL_FRONT_LEFT 0x0400
#define GL_FRONT_RIGHT 0x0401
#define GL_BACK_LEFT 0x0402
#define GL_BACK_RIGHT 0x0403
#define GL_FRONT 0x0404
#define GL_BACK 0x0405
#define GL_LEFT 0x0406
#define GL_RIGHT 0x0407
#define GL_FRONT_AND_BACK 0x0408
#define GL_NO_ERROR 0
#define GL_INVALID_ENUM 0x0500
#define GL_INVALID_VALUE 0x0501
#define GL_INVALID_OPERATION 0x0502
#define GL_OUT_OF_MEMORY 0x0505
#define GL_CW 0x0900
#define GL_CCW 0x0901
#define GL_POINT_SIZE 0x0B11
#define GL_POINT_SIZE_RANGE 0x0B12
#define GL_POINT_SIZE_GRANULARITY 0x0B13
#define GL_LINE_SMOOTH 0x0B20
#define GL_LINE_WIDTH 0x0B21
#define GL_LINE_WIDTH_RANGE 0x0B22
#define GL_LINE_WIDTH_GRANULARITY 0x0B23
#define GL_POLYGON_MODE 0x0B40
#define GL_POLYGON_SMOOTH 0x0B41
#define GL_CULL_FACE 0x0B44
#define GL_CULL_FACE_MODE 0x0B45
#define GL_FRONT_FACE 0x0B46
#define GL_DEPTH_RANGE 0x0B70
#define GL_DEPTH_TEST 0x0B71
#define GL_DEPTH_WRITEMASK 0x0B72
#define GL_DEPTH_CLEAR_VALUE 0x0B73
#define GL_DEPTH_FUNC 0x0B74
#define GL_STENCIL_TEST 0x0B90
#define GL_STENCIL_CLEAR_VALUE 0x0B91
#define GL_STENCIL_FUNC 0x0B92
#define GL_STENCIL_VALUE_MASK 0x0B93
#define GL_STENCIL_FAIL 0x0B94
#define GL_STENCIL_PASS_DEPTH_FAIL 0x0B95
#define GL_STENCIL_PASS_DEPTH_PASS 0x0B96
#define GL_STENCIL_REF 0x0B97
#define GL_STENCIL_WRITEMASK 0x0B98
#define GL_VIEWPORT 0x0BA2
#define GL_DITHER 0x0BD0
#define GL_BLEND_DST 0x0BE0
#define GL_BLEND_SRC 0x0BE1
#define GL_BLEND 0x0BE2
#define GL_LOGIC_OP_MODE 0x0BF0
#define GL_COLOR_LOGIC_OP 0x0BF2
#define GL_DRAW_BUFFER 0x0C01
#define GL_READ_BUFFER 0x0C02
#define GL_SCISSOR_BOX 0x0C10
#define GL_SCISSOR_TEST 0x0C11
#define GL_COLOR_CLEAR_VALUE 0x0C22
#define GL_COLOR_WRITEMASK 0x0C23
#define GL_DOUBLEBUFFER 0x0C32
#define GL_STEREO 0x0C33
#define GL_LINE_SMOOTH_HINT 0x0C52
#define GL_POLYGON_SMOOTH_HINT 0x0C53
#define GL_UNPACK_SWAP_BYTES 0x0CF0
#define GL_UNPACK_LSB_FIRST 0x0CF1
#define GL_UNPACK_ROW_LENGTH 0x0CF2
#define GL_UNPACK_SKIP_ROWS 0x0CF3
#define GL_UNPACK_SKIP_PIXELS 0x0CF4
#define GL_UNPACK_ALIGNMENT 0x0CF5
#define GL_PACK_SWAP_BYTES 0x0D00
#define GL_PACK_LSB_FIRST 0x0D01
#define GL_PACK_ROW_LENGTH 0x0D02
#define GL_PACK_SKIP_ROWS 0x0D03
#define GL_PACK_SKIP_PIXELS 0x0D04
#define GL_PACK_ALIGNMENT 0x0D05
#define GL_MAX_TEXTURE_SIZE 0x0D33
#define GL_MAX_VIEWPORT_DIMS 0x0D3A
#define GL_SUBPIXEL_BITS 0x0D50
#define GL_TEXTURE_1D 0x0DE0
#define GL_TEXTURE_2D 0x0DE1
#define GL_POLYGON_OFFSET_UNITS 0x2A00
#define GL_POLYGON_OFFSET_POINT 0x2A01
#define GL_POLYGON_OFFSET_LINE 0x2A02
#define GL_POLYGON_OFFSET_FILL 0x8037
#define GL_POLYGON_OFFSET_FACTOR 0x8038
#define GL_TEXTURE_BINDING_1D 0x8068
#define GL_TEXTURE_BINDING_2D 0x8069
#define GL_TEXTURE_WIDTH 0x1000
#define GL_TEXTURE_HEIGHT 0x1001
#define GL_TEXTURE_INTERNAL_FORMAT 0x1003
#define GL_TEXTURE_BORDER_COLOR 0x1004
#define GL_TEXTURE_RED_SIZE 0x805C
#define GL_TEXTURE_GREEN_SIZE 0x805D
#define GL_TEXTURE_BLUE_SIZE 0x805E
#define GL_TEXTURE_ALPHA_SIZE 0x805F
#define GL_DONT_CARE 0x1100
#define GL_FASTEST 0x1101
#define GL_NICEST 0x1102
#define GL_BYTE 0x1400
#define GL_UNSIGNED_BYTE 0x1401
#define GL_SHORT 0x1402
#define GL_UNSIGNED_SHORT 0x1403
#define GL_INT 0x1404
#define GL_UNSIGNED_INT 0x1405
#define GL_FLOAT 0x1406
#define GL_DOUBLE 0x140A
#define GL_STACK_OVERFLOW 0x0503
#define GL_STACK_UNDERFLOW 0x0504
#define GL_CLEAR 0x1500
#define GL_AND 0x1501
#define GL_AND_REVERSE 0x1502
#define GL_COPY 0x1503
#define GL_AND_INVERTED 0x1504
#define GL_NOOP 0x1505
#define GL_XOR 0x1506
#define GL_OR 0x1507
#define GL_NOR 0x1508
#define GL_EQUIV 0x1509
#define GL_INVERT 0x150A
#define GL_OR_REVERSE 0x150B
#define GL_COPY_INVERTED 0x150C
#define GL_OR_INVERTED 0x150D
#define GL_NAND 0x150E
#define GL_SET 0x150F
#define GL_TEXTURE 0x1702
#define GL_COLOR 0x1800
#define GL_DEPTH 0x1801
#define GL_STENCIL 0x1802
#define GL_STENCIL_INDEX 0x1901
#define GL_DEPTH_COMPONENT 0x1902
#define GL_RED 0x1903
#define GL_GREEN 0x1904
#define GL_BLUE 0x1905
#define GL_ALPHA 0x1906
#define GL_RGB 0x1907
#define GL_RGBA 0x1908
#define GL_POINT 0x1B00
#define GL_LINE 0x1B01
#define GL_FILL 0x1B02
#define GL_KEEP 0x1E00
#define GL_REPLACE 0x1E01
#define GL_INCR 0x1E02
#define GL_DECR 0x1E03
#define GL_VENDOR 0x1F00
#define GL_RENDERER 0x1F01
#define GL_VERSION 0x1F02
#define GL_EXTENSIONS 0x1F03
#define GL_NEAREST 0x2600
#define GL_LINEAR 0x2601
#define GL_NEAREST_MIPMAP_NEAREST 0x2700
#define GL_LINEAR_MIPMAP_NEAREST 0x2701
#define GL_NEAREST_MIPMAP_LINEAR 0x2702
#define GL_LINEAR_MIPMAP_LINEAR 0x2703
#define GL_TEXTURE_MAG_FILTER 0x2800
#define GL_TEXTURE_MIN_FILTER 0x2801
#define GL_TEXTURE_WRAP_S 0x2802
#define GL_TEXTURE_WRAP_T 0x2803
#define GL_PROXY_TEXTURE_1D 0x8063
#define GL_PROXY_TEXTURE_2D 0x8064
#define GL_REPEAT 0x2901
#define GL_R3_G3_B2 0x2A10
#define GL_RGB4 0x804F
#define GL_RGB5 0x8050
#define GL_RGB8 0x8051
#define GL_RGB10 0x8052
#define GL_RGB12 0x8053
#define GL_RGB16 0x8054
#define GL_RGBA2 0x8055
#define GL_RGBA4 0x8056
#define GL_RGB5_A1 0x8057
#define GL_RGBA8 0x8058
#define GL_RGB10_A2 0x8059
#define GL_RGBA12 0x805A
#define GL_RGBA16 0x805B
#define GL_CURRENT_BIT 0x00000001
#define GL_POINT_BIT 0x00000002
#define GL_LINE_BIT 0x00000004
#define GL_POLYGON_BIT 0x00000008
#define GL_POLYGON_STIPPLE_BIT 0x00000010
#define GL_PIXEL_MODE_BIT 0x00000020
#define GL_LIGHTING_BIT 0x00000040
#define GL_FOG_BIT 0x00000080
#define GL_ACCUM_BUFFER_BIT 0x00000200
#define GL_VIEWPORT_BIT 0x00000800
#define GL_TRANSFORM_BIT 0x00001000
#define GL_ENABLE_BIT 0x00002000
#define GL_HINT_BIT 0x00008000
#define GL_EVAL_BIT 0x00010000
#define GL_LIST_BIT 0x00020000
#define GL_TEXTURE_BIT 0x00040000
#define GL_SCISSOR_BIT 0x00080000
#define GL_ALL_ATTRIB_BITS 0xFFFFFFFF
#define GL_CLIENT_PIXEL_STORE_BIT 0x00000001
#define GL_CLIENT_VERTEX_ARRAY_BIT 0x00000002
#define GL_CLIENT_ALL_ATTRIB_BITS 0xFFFFFFFF
#define GL_QUAD_STRIP 0x0008
#define GL_POLYGON 0x0009
#define GL_ACCUM 0x0100
#define GL_LOAD 0x0101
#define GL_RETURN 0x0102
#define GL_MULT 0x0103
#define GL_ADD 0x0104
#define GL_AUX0 0x0409
#define GL_AUX1 0x040A
#define GL_AUX2 0x040B
#define GL_AUX3 0x040C
#define GL_2D 0x0600
#define GL_3D 0x0601
#define GL_3D_COLOR 0x0602
#define GL_3D_COLOR_TEXTURE 0x0603
#define GL_4D_COLOR_TEXTURE 0x0604
#define GL_PASS_THROUGH_TOKEN 0x0700
#define GL_POINT_TOKEN 0x0701
#define GL_LINE_TOKEN 0x0702
#define GL_POLYGON_TOKEN 0x0703
#define GL_BITMAP_TOKEN 0x0704
#define GL_DRAW_PIXEL_TOKEN 0x0705
#define GL_COPY_PIXEL_TOKEN 0x0706
#define GL_LINE_RESET_TOKEN 0x0707
#define GL_EXP 0x0800
#define GL_EXP2 0x0801
#define GL_COEFF 0x0A00
#define GL_ORDER 0x0A01
#define GL_DOMAIN 0x0A02
#define GL_PIXEL_MAP_I_TO_I 0x0C70
#define GL_PIXEL_MAP_S_TO_S 0x0C71
#define GL_PIXEL_MAP_I_TO_R 0x0C72
#define GL_PIXEL_MAP_I_TO_G 0x0C73
#define GL_PIXEL_MAP_I_TO_B 0x0C74
#define GL_PIXEL_MAP_I_TO_A 0x0C75
#define GL_PIXEL_MAP_R_TO_R 0x0C76
#define GL_PIXEL_MAP_G_TO_G 0x0C77
#define GL_PIXEL_MAP_B_TO_B 0x0C78
#define GL_PIXEL_MAP_A_TO_A 0x0C79
#define GL_VERTEX_ARRAY_POINTER 0x808E
#define GL_NORMAL_ARRAY_POINTER 0x808F
#define GL_COLOR_ARRAY_POINTER 0x8090
#define GL_INDEX_ARRAY_POINTER 0x8091
#define GL_TEXTURE_COORD_ARRAY_POINTER 0x8092
#define GL_EDGE_FLAG_ARRAY_POINTER 0x8093
#define GL_FEEDBACK_BUFFER_POINTER 0x0DF0
#define GL_SELECTION_BUFFER_POINTER 0x0DF3
#define GL_CURRENT_COLOR 0x0B00
#define GL_CURRENT_INDEX 0x0B01
#define GL_CURRENT_NORMAL 0x0B02
#define GL_CURRENT_TEXTURE_COORDS 0x0B03
#define GL_CURRENT_RASTER_COLOR 0x0B04
#define GL_CURRENT_RASTER_INDEX 0x0B05
#define GL_CURRENT_RASTER_TEXTURE_COORDS 0x0B06
#define GL_CURRENT_RASTER_POSITION 0x0B07
#define GL_CURRENT_RASTER_POSITION_VALID 0x0B08
#define GL_CURRENT_RASTER_DISTANCE 0x0B09
#define GL_POINT_SMOOTH 0x0B10
#define GL_LINE_STIPPLE 0x0B24
#define GL_LINE_STIPPLE_PATTERN 0x0B25
#define GL_LINE_STIPPLE_REPEAT 0x0B26
#define GL_LIST_MODE 0x0B30
#define GL_MAX_LIST_NESTING 0x0B31
#define GL_LIST_BASE 0x0B32
#define GL_LIST_INDEX 0x0B33
#define GL_POLYGON_STIPPLE 0x0B42
#define GL_EDGE_FLAG 0x0B43
#define GL_LIGHTING 0x0B50
#define GL_LIGHT_MODEL_LOCAL_VIEWER 0x0B51
#define GL_LIGHT_MODEL_TWO_SIDE 0x0B52
#define GL_LIGHT_MODEL_AMBIENT 0x0B53
#define GL_SHADE_MODEL 0x0B54
#define GL_COLOR_MATERIAL_FACE 0x0B55
#define GL_COLOR_MATERIAL_PARAMETER 0x0B56
#define GL_COLOR_MATERIAL 0x0B57
#define GL_FOG 0x0B60
#define GL_FOG_INDEX 0x0B61
#define GL_FOG_DENSITY 0x0B62
#define GL_FOG_START 0x0B63
#define GL_FOG_END 0x0B64
#define GL_FOG_MODE 0x0B65
#define GL_FOG_COLOR 0x0B66
#define GL_ACCUM_CLEAR_VALUE 0x0B80
#define GL_MATRIX_MODE 0x0BA0
#define GL_NORMALIZE 0x0BA1
#define GL_MODELVIEW_STACK_DEPTH 0x0BA3
#define GL_PROJECTION_STACK_DEPTH 0x0BA4
#define GL_TEXTURE_STACK_DEPTH 0x0BA5
#define GL_MODELVIEW_MATRIX 0x0BA6
#define GL_PROJECTION_MATRIX 0x0BA7
#define GL_TEXTURE_MATRIX 0x0BA8
#define GL_ATTRIB_STACK_DEPTH 0x0BB0
#define GL_CLIENT_ATTRIB_STACK_DEPTH 0x0BB1
#define GL_ALPHA_TEST 0x0BC0
#define GL_ALPHA_TEST_FUNC 0x0BC1
#define GL_ALPHA_TEST_REF 0x0BC2
#define GL_INDEX_LOGIC_OP 0x0BF1
#define GL_LOGIC_OP 0x0BF1
#define GL_AUX_BUFFERS 0x0C00
#define GL_INDEX_CLEAR_VALUE 0x0C20
#define GL_INDEX_WRITEMASK 0x0C21
#define GL_INDEX_MODE 0x0C30
#define GL_RGBA_MODE 0x0C31
#define GL_RENDER_MODE 0x0C40
#define GL_PERSPECTIVE_CORRECTION_HINT 0x0C50
#define GL_POINT_SMOOTH_HINT 0x0C51
#define GL_FOG_HINT 0x0C54
#define GL_TEXTURE_GEN_S 0x0C60
#define GL_TEXTURE_GEN_T 0x0C61
#define GL_TEXTURE_GEN_R 0x0C62
#define GL_TEXTURE_GEN_Q 0x0C63
#define GL_PIXEL_MAP_I_TO_I_SIZE 0x0CB0
#define GL_PIXEL_MAP_S_TO_S_SIZE 0x0CB1
#define GL_PIXEL_MAP_I_TO_R_SIZE 0x0CB2
#define GL_PIXEL_MAP_I_TO_G_SIZE 0x0CB3
#define GL_PIXEL_MAP_I_TO_B_SIZE 0x0CB4
#define GL_PIXEL_MAP_I_TO_A_SIZE 0x0CB5
#define GL_PIXEL_MAP_R_TO_R_SIZE 0x0CB6
#define GL_PIXEL_MAP_G_TO_G_SIZE 0x0CB7
#define GL_PIXEL_MAP_B_TO_B_SIZE 0x0CB8
#define GL_PIXEL_MAP_A_TO_A_SIZE 0x0CB9
#define GL_MAP_COLOR 0x0D10
#define GL_MAP_STENCIL 0x0D11
#define GL_INDEX_SHIFT 0x0D12
#define GL_INDEX_OFFSET 0x0D13
#define GL_RED_SCALE 0x0D14
#define GL_RED_BIAS 0x0D15
#define GL_ZOOM_X 0x0D16
#define GL_ZOOM_Y 0x0D17
#define GL_GREEN_SCALE 0x0D18
#define GL_GREEN_BIAS 0x0D19
#define GL_BLUE_SCALE 0x0D1A
#define GL_BLUE_BIAS 0x0D1B
#define GL_ALPHA_SCALE 0x0D1C
#define GL_ALPHA_BIAS 0x0D1D
#define GL_DEPTH_SCALE 0x0D1E
#define GL_DEPTH_BIAS 0x0D1F
#define GL_MAX_EVAL_ORDER 0x0D30
#define GL_MAX_LIGHTS 0x0D31
#define GL_MAX_CLIP_PLANES 0x0D32
#define GL_MAX_PIXEL_MAP_TABLE 0x0D34
#define GL_MAX_ATTRIB_STACK_DEPTH 0x0D35
#define GL_MAX_MODELVIEW_STACK_DEPTH 0x0D36
#define GL_MAX_NAME_STACK_DEPTH 0x0D37
#define GL_MAX_PROJECTION_STACK_DEPTH 0x0D38
#define GL_MAX_TEXTURE_STACK_DEPTH 0x0D39
#define GL_MAX_CLIENT_ATTRIB_STACK_DEPTH 0x0D3B
#define GL_INDEX_BITS 0x0D51
#define GL_RED_BITS 0x0D52
#define GL_GREEN_BITS 0x0D53
#define GL_BLUE_BITS 0x0D54
#define GL_ALPHA_BITS 0x0D55
#define GL_DEPTH_BITS 0x0D56
#define GL_STENCIL_BITS 0x0D57
#define GL_ACCUM_RED_BITS 0x0D58
#define GL_ACCUM_GREEN_BITS 0x0D59
#define GL_ACCUM_BLUE_BITS 0x0D5A
#define GL_ACCUM_ALPHA_BITS 0x0D5B
#define GL_NAME_STACK_DEPTH 0x0D70
#define GL_AUTO_NORMAL 0x0D80
#define GL_MAP1_COLOR_4 0x0D90
#define GL_MAP1_INDEX 0x0D91
#define GL_MAP1_NORMAL 0x0D92
#define GL_MAP1_TEXTURE_COORD_1 0x0D93
#define GL_MAP1_TEXTURE_COORD_2 0x0D94
#define GL_MAP1_TEXTURE_COORD_3 0x0D95
#define GL_MAP1_TEXTURE_COORD_4 0x0D96
#define GL_MAP1_VERTEX_3 0x0D97
#define GL_MAP1_VERTEX_4 0x0D98
#define GL_MAP2_COLOR_4 0x0DB0
#define GL_MAP2_INDEX 0x0DB1
#define GL_MAP2_NORMAL 0x0DB2
#define GL_MAP2_TEXTURE_COORD_1 0x0DB3
#define GL_MAP2_TEXTURE_COORD_2 0x0DB4
#define GL_MAP2_TEXTURE_COORD_3 0x0DB5
#define GL_MAP2_TEXTURE_COORD_4 0x0DB6
#define GL_MAP2_VERTEX_3 0x0DB7
#define GL_MAP2_VERTEX_4 0x0DB8
#define GL_MAP1_GRID_DOMAIN 0x0DD0
#define GL_MAP1_GRID_SEGMENTS 0x0DD1
#define GL_MAP2_GRID_DOMAIN 0x0DD2
#define GL_MAP2_GRID_SEGMENTS 0x0DD3
#define GL_FEEDBACK_BUFFER_SIZE 0x0DF1
#define GL_FEEDBACK_BUFFER_TYPE 0x0DF2
#define GL_SELECTION_BUFFER_SIZE 0x0DF4
#define GL_VERTEX_ARRAY 0x8074
#define GL_NORMAL_ARRAY 0x8075
#define GL_COLOR_ARRAY 0x8076
#define GL_INDEX_ARRAY 0x8077
#define GL_TEXTURE_COORD_ARRAY 0x8078
#define GL_EDGE_FLAG_ARRAY 0x8079
#define GL_VERTEX_ARRAY_SIZE 0x807A
#define GL_VERTEX_ARRAY_TYPE 0x807B
#define GL_VERTEX_ARRAY_STRIDE 0x807C
#define GL_NORMAL_ARRAY_TYPE 0x807E
#define GL_NORMAL_ARRAY_STRIDE 0x807F
#define GL_COLOR_ARRAY_SIZE 0x8081
#define GL_COLOR_ARRAY_TYPE 0x8082
#define GL_COLOR_ARRAY_STRIDE 0x8083
#define GL_INDEX_ARRAY_TYPE 0x8085
#define GL_INDEX_ARRAY_STRIDE 0x8086
#define GL_TEXTURE_COORD_ARRAY_SIZE 0x8088
#define GL_TEXTURE_COORD_ARRAY_TYPE 0x8089
#define GL_TEXTURE_COORD_ARRAY_STRIDE 0x808A
#define GL_EDGE_FLAG_ARRAY_STRIDE 0x808C
#define GL_TEXTURE_COMPONENTS 0x1003
#define GL_TEXTURE_BORDER 0x1005
#define GL_TEXTURE_LUMINANCE_SIZE 0x8060
#define GL_TEXTURE_INTENSITY_SIZE 0x8061
#define GL_TEXTURE_PRIORITY 0x8066
#define GL_TEXTURE_RESIDENT 0x8067
#define GL_AMBIENT 0x1200
#define GL_DIFFUSE 0x1201
#define GL_SPECULAR 0x1202
#define GL_POSITION 0x1203
#define GL_SPOT_DIRECTION 0x1204
#define GL_SPOT_EXPONENT 0x1205
#define GL_SPOT_CUTOFF 0x1206
#define GL_CONSTANT_ATTENUATION 0x1207
#define GL_LINEAR_ATTENUATION 0x1208
#define GL_QUADRATIC_ATTENUATION 0x1209
#define GL_COMPILE 0x1300
#define GL_COMPILE_AND_EXECUTE 0x1301
#define GL_2_BYTES 0x1407
#define GL_3_BYTES 0x1408
#define GL_4_BYTES 0x1409
#define GL_EMISSION 0x1600
#define GL_SHININESS 0x1601
#define GL_AMBIENT_AND_DIFFUSE 0x1602
#define GL_COLOR_INDEXES 0x1603
#define GL_MODELVIEW 0x1700
#define GL_PROJECTION 0x1701
#define GL_COLOR_INDEX 0x1900
#define GL_LUMINANCE 0x1909
#define GL_LUMINANCE_ALPHA 0x190A
#define GL_BITMAP 0x1A00
#define GL_RENDER 0x1C00
#define GL_FEEDBACK 0x1C01
#define GL_SELECT 0x1C02
#define GL_FLAT 0x1D00
#define GL_SMOOTH 0x1D01
#define GL_S 0x2000
#define GL_T 0x2001
#define GL_R 0x2002
#define GL_Q 0x2003
#define GL_MODULATE 0x2100
#define GL_DECAL 0x2101
#define GL_TEXTURE_ENV_MODE 0x2200
#define GL_TEXTURE_ENV_COLOR 0x2201
#define GL_TEXTURE_ENV 0x2300
#define GL_EYE_LINEAR 0x2400
#define GL_OBJECT_LINEAR 0x2401
#define GL_SPHERE_MAP 0x2402
#define GL_TEXTURE_GEN_MODE 0x2500
#define GL_OBJECT_PLANE 0x2501
#define GL_EYE_PLANE 0x2502
#define GL_CLAMP 0x2900
#define GL_ALPHA4 0x803B
#define GL_ALPHA8 0x803C
#define GL_ALPHA12 0x803D
#define GL_ALPHA16 0x803E
#define GL_LUMINANCE4 0x803F
#define GL_LUMINANCE8 0x8040
#define GL_LUMINANCE12 0x8041
#define GL_LUMINANCE16 0x8042
#define GL_LUMINANCE4_ALPHA4 0x8043
#define GL_LUMINANCE6_ALPHA2 0x8044
#define GL_LUMINANCE8_ALPHA8 0x8045
#define GL_LUMINANCE12_ALPHA4 0x8046
#define GL_LUMINANCE12_ALPHA12 0x8047
#define GL_LUMINANCE16_ALPHA16 0x8048
#define GL_INTENSITY 0x8049
#define GL_INTENSITY4 0x804A
#define GL_INTENSITY8 0x804B
#define GL_INTENSITY12 0x804C
#define GL_INTENSITY16 0x804D
#define GL_V2F 0x2A20
#define GL_V3F 0x2A21
#define GL_C4UB_V2F 0x2A22
#define GL_C4UB_V3F 0x2A23
#define GL_C3F_V3F 0x2A24
#define GL_N3F_V3F 0x2A25
#define GL_C4F_N3F_V3F 0x2A26
#define GL_T2F_V3F 0x2A27
#define GL_T4F_V4F 0x2A28
#define GL_T2F_C4UB_V3F 0x2A29
#define GL_T2F_C3F_V3F 0x2A2A
#define GL_T2F_N3F_V3F 0x2A2B
#define GL_T2F_C4F_N3F_V3F 0x2A2C
#define GL_T4F_C4F_N3F_V4F 0x2A2D
#define GL_CLIP_PLANE0 0x3000
#define GL_CLIP_PLANE1 0x3001
#define GL_CLIP_PLANE2 0x3002
#define GL_CLIP_PLANE3 0x3003
#define GL_CLIP_PLANE4 0x3004
#define GL_CLIP_PLANE5 0x3005
#define GL_LIGHT0 0x4000
#define GL_LIGHT1 0x4001
#define GL_LIGHT2 0x4002
#define GL_LIGHT3 0x4003
#define GL_LIGHT4 0x4004
#define GL_LIGHT5 0x4005
#define GL_LIGHT6 0x4006
#define GL_LIGHT7 0x4007
#define GL_UNSIGNED_BYTE_3_3_2 0x8032
#define GL_UNSIGNED_SHORT_4_4_4_4 0x8033
#define GL_UNSIGNED_SHORT_5_5_5_1 0x8034
#define GL_UNSIGNED_INT_8_8_8_8 0x8035
#define GL_UNSIGNED_INT_10_10_10_2 0x8036
#define GL_TEXTURE_BINDING_3D 0x806A
#define GL_PACK_SKIP_IMAGES 0x806B
#define GL_PACK_IMAGE_HEIGHT 0x806C
#define GL_UNPACK_SKIP_IMAGES 0x806D
#define GL_UNPACK_IMAGE_HEIGHT 0x806E
#define GL_TEXTURE_3D 0x806F
#define GL_PROXY_TEXTURE_3D 0x8070
#define GL_TEXTURE_DEPTH 0x8071
#define GL_TEXTURE_WRAP_R 0x8072
#define GL_MAX_3D_TEXTURE_SIZE 0x8073
#define GL_UNSIGNED_BYTE_2_3_3_REV 0x8362
#define GL_UNSIGNED_SHORT_5_6_5 0x8363
#define GL_UNSIGNED_SHORT_5_6_5_REV 0x8364
#define GL_UNSIGNED_SHORT_4_4_4_4_REV 0x8365
#define GL_UNSIGNED_SHORT_1_5_5_5_REV 0x8366
#define GL_UNSIGNED_INT_8_8_8_8_REV 0x8367
#define GL_UNSIGNED_INT_2_10_10_10_REV 0x8368
#define GL_BGR 0x80E0
#define GL_BGRA 0x80E1
#define GL_MAX_ELEMENTS_VERTICES 0x80E8
#define GL_MAX_ELEMENTS_INDICES 0x80E9
#define GL_CLAMP_TO_EDGE 0x812F
#define GL_TEXTURE_MIN_LOD 0x813A
#define GL_TEXTURE_MAX_LOD 0x813B
#define GL_TEXTURE_BASE_LEVEL 0x813C
#define GL_TEXTURE_MAX_LEVEL 0x813D
#define GL_SMOOTH_POINT_SIZE_RANGE 0x0B12
#define GL_SMOOTH_POINT_SIZE_GRANULARITY 0x0B13
#define GL_SMOOTH_LINE_WIDTH_RANGE 0x0B22
#define GL_SMOOTH_LINE_WIDTH_GRANULARITY 0x0B23
#define GL_ALIASED_LINE_WIDTH_RANGE 0x846E
#define GL_RESCALE_NORMAL 0x803A
#define GL_LIGHT_MODEL_COLOR_CONTROL 0x81F8
#define GL_SINGLE_COLOR 0x81F9
#define GL_SEPARATE_SPECULAR_COLOR 0x81FA
#define GL_ALIASED_POINT_SIZE_RANGE 0x846D
#ifndef GL_VERSION_1_0
#define GL_VERSION_1_0 1
GLAPI int CPPGL_GL_VERSION_1_0;
typedef void (APIENTRYP PFNGLCULLFACEPROC)(GLenum mode);
GLAPI PFNGLCULLFACEPROC cppgl_glCullFace;
#define glCullFace cppgl_glCullFace
typedef void (APIENTRYP PFNGLFRONTFACEPROC)(GLenum mode);
GLAPI PFNGLFRONTFACEPROC cppgl_glFrontFace;
#define glFrontFace cppgl_glFrontFace
typedef void (APIENTRYP PFNGLHINTPROC)(GLenum target, GLenum mode);
GLAPI PFNGLHINTPROC cppgl_glHint;
#define glHint cppgl_glHint
typedef void (APIENTRYP PFNGLLINEWIDTHPROC)(GLfloat width);
GLAPI PFNGLLINEWIDTHPROC cppgl_glLineWidth;
#define glLineWidth cppgl_glLineWidth
typedef void (APIENTRYP PFNGLPOINTSIZEPROC)(GLfloat size);
GLAPI PFNGLPOINTSIZEPROC cppgl_glPointSize;
#define glPointSize cppgl_glPointSize
typedef void (APIENTRYP PFNGLPOLYGONMODEPROC)(GLenum face, GLenum mode);
GLAPI PFNGLPOLYGONMODEPROC cppgl_glPolygonMode;
#define glPolygonMode cppgl_glPolygonMode
typedef void (APIENTRYP PFNGLSCISSORPROC)(GLint x, GLint y, GLsizei width, GLsizei height);
GLAPI PFNGLSCISSORPROC cppgl_glScissor;
#define glScissor cppgl_glScissor
typedef void (APIENTRYP PFNGLTEXPARAMETERFPROC)(GLenum target, GLenum pname, GLfloat param);
GLAPI PFNGLTEXPARAMETERFPROC cppgl_glTexParameterf;
#define glTexParameterf cppgl_glTexParameterf
typedef void (APIENTRYP PFNGLTEXPARAMETERFVPROC)(GLenum target, GLenum pname, const GLfloat *params);
GLAPI PFNGLTEXPARAMETERFVPROC cppgl_glTexParameterfv;
#define glTexParameterfv cppgl_glTexParameterfv
typedef void (APIENTRYP PFNGLTEXPARAMETERIPROC)(GLenum target, GLenum pname, GLint param);
GLAPI PFNGLTEXPARAMETERIPROC cppgl_glTexParameteri;
#define glTexParameteri cppgl_glTexParameteri
typedef void (APIENTRYP PFNGLTEXPARAMETERIVPROC)(GLenum target, GLenum pname, const GLint *params);
GLAPI PFNGLTEXPARAMETERIVPROC cppgl_glTexParameteriv;
#define glTexParameteriv cppgl_glTexParameteriv
typedef void (APIENTRYP PFNGLTEXIMAGE1DPROC)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void *pixels);
GLAPI PFNGLTEXIMAGE1DPROC cppgl_glTexImage1D;
#define glTexImage1D cppgl_glTexImage1D
typedef void (APIENTRYP PFNGLTEXIMAGE2DPROC)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void *pixels);
GLAPI PFNGLTEXIMAGE2DPROC cppgl_glTexImage2D;
#define glTexImage2D cppgl_glTexImage2D
typedef void (APIENTRYP PFNGLDRAWBUFFERPROC)(GLenum buf);
GLAPI PFNGLDRAWBUFFERPROC cppgl_glDrawBuffer;
#define glDrawBuffer cppgl_glDrawBuffer
typedef void (APIENTRYP PFNGLCLEARPROC)(GLbitfield mask);
GLAPI PFNGLCLEARPROC cppgl_glClear;
#define glClear cppgl_glClear
typedef void (APIENTRYP PFNGLCLEARCOLORPROC)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
GLAPI PFNGLCLEARCOLORPROC cppgl_glClearColor;
#define glClearColor cppgl_glClearColor
typedef void (APIENTRYP PFNGLCLEARSTENCILPROC)(GLint s);
GLAPI PFNGLCLEARSTENCILPROC cppgl_glClearStencil;
#define glClearStencil cppgl_glClearStencil
typedef void (APIENTRYP PFNGLCLEARDEPTHPROC)(GLdouble depth);
GLAPI PFNGLCLEARDEPTHPROC cppgl_glClearDepth;
#define glClearDepth cppgl_glClearDepth
typedef void (APIENTRYP PFNGLSTENCILMASKPROC)(GLuint mask);
GLAPI PFNGLSTENCILMASKPROC cppgl_glStencilMask;
#define glStencilMask cppgl_glStencilMask
typedef void (APIENTRYP PFNGLCOLORMASKPROC)(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
GLAPI PFNGLCOLORMASKPROC cppgl_glColorMask;
#define glColorMask cppgl_glColorMask
typedef void (APIENTRYP PFNGLDEPTHMASKPROC)(GLboolean flag);
GLAPI PFNGLDEPTHMASKPROC cppgl_glDepthMask;
#define glDepthMask cppgl_glDepthMask
typedef void (APIENTRYP PFNGLDISABLEPROC)(GLenum cap);
GLAPI PFNGLDISABLEPROC cppgl_glDisable;
#define glDisable cppgl_glDisable
typedef void (APIENTRYP PFNGLENABLEPROC)(GLenum cap);
GLAPI PFNGLENABLEPROC cppgl_glEnable;
#define glEnable cppgl_glEnable
typedef void (APIENTRYP PFNGLFINISHPROC)();
GLAPI PFNGLFINISHPROC cppgl_glFinish;
#define glFinish cppgl_glFinish
typedef void (APIENTRYP PFNGLFLUSHPROC)();
GLAPI PFNGLFLUSHPROC cppgl_glFlush;
#define glFlush cppgl_glFlush
typedef void (APIENTRYP PFNGLBLENDFUNCPROC)(GLenum sfactor, GLenum dfactor);
GLAPI PFNGLBLENDFUNCPROC cppgl_glBlendFunc;
#define glBlendFunc cppgl_glBlendFunc
typedef void (APIENTRYP PFNGLLOGICOPPROC)(GLenum opcode);
GLAPI PFNGLLOGICOPPROC cppgl_glLogicOp;
#define glLogicOp cppgl_glLogicOp
typedef void (APIENTRYP PFNGLSTENCILFUNCPROC)(GLenum func, GLint ref, GLuint mask);
GLAPI PFNGLSTENCILFUNCPROC cppgl_glStencilFunc;
#define glStencilFunc cppgl_glStencilFunc
typedef void (APIENTRYP PFNGLSTENCILOPPROC)(GLenum fail, GLenum zfail, GLenum zpass);
GLAPI PFNGLSTENCILOPPROC cppgl_glStencilOp;
#define glStencilOp cppgl_glStencilOp
typedef void (APIENTRYP PFNGLDEPTHFUNCPROC)(GLenum func);
GLAPI PFNGLDEPTHFUNCPROC cppgl_glDepthFunc;
#define glDepthFunc cppgl_glDepthFunc
typedef void (APIENTRYP PFNGLPIXELSTOREFPROC)(GLenum pname, GLfloat param);
GLAPI PFNGLPIXELSTOREFPROC cppgl_glPixelStoref;
#define glPixelStoref cppgl_glPixelStoref
typedef void (APIENTRYP PFNGLPIXELSTOREIPROC)(GLenum pname, GLint param);
GLAPI PFNGLPIXELSTOREIPROC cppgl_glPixelStorei;
#define glPixelStorei cppgl_glPixelStorei
typedef void (APIENTRYP PFNGLREADBUFFERPROC)(GLenum src);
GLAPI PFNGLREADBUFFERPROC cppgl_glReadBuffer;
#define glReadBuffer cppgl_glReadBuffer
typedef void (APIENTRYP PFNGLREADPIXELSPROC)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void *pixels);
GLAPI PFNGLREADPIXELSPROC cppgl_glReadPixels;
#define glReadPixels cppgl_glReadPixels
typedef void (APIENTRYP PFNGLGETBOOLEANVPROC)(GLenum pname, GLboolean *data);
GLAPI PFNGLGETBOOLEANVPROC cppgl_glGetBooleanv;
#define glGetBooleanv cppgl_glGetBooleanv
typedef void (APIENTRYP PFNGLGETDOUBLEVPROC)(GLenum pname, GLdouble *data);
GLAPI PFNGLGETDOUBLEVPROC cppgl_glGetDoublev;
#define glGetDoublev cppgl_glGetDoublev
typedef GLenum (APIENTRYP PFNGLGETERRORPROC)();
GLAPI PFNGLGETERRORPROC cppgl_glGetError;
#define glGetError cppgl_glGetError
typedef void (APIENTRYP PFNGLGETFLOATVPROC)(GLenum pname, GLfloat *data);
GLAPI PFNGLGETFLOATVPROC cppgl_glGetFloatv;
#define glGetFloatv cppgl_glGetFloatv
typedef void (APIENTRYP PFNGLGETINTEGERVPROC)(GLenum pname, GLint *data);
GLAPI PFNGLGETINTEGERVPROC cppgl_glGetIntegerv;
#define glGetIntegerv cppgl_glGetIntegerv
typedef const GLubyte * (APIENTRYP PFNGLGETSTRINGPROC)(GLenum name);
GLAPI PFNGLGETSTRINGPROC cppgl_glGetString;
#define glGetString cppgl_glGetString
typedef void (APIENTRYP PFNGLGETTEXIMAGEPROC)(GLenum target, GLint level, GLenum format, GLenum type, void *pixels);
GLAPI PFNGLGETTEXIMAGEPROC cppgl_glGetTexImage;
#define glGetTexImage cppgl_glGetTexImage
typedef void (APIENTRYP PFNGLGETTEXPARAMETERFVPROC)(GLenum target, GLenum pname, GLfloat *params);
GLAPI PFNGLGETTEXPARAMETERFVPROC cppgl_glGetTexParameterfv;
#define glGetTexParameterfv cppgl_glGetTexParameterfv
typedef void (APIENTRYP PFNGLGETTEXPARAMETERIVPROC)(GLenum target, GLenum pname, GLint *params);
GLAPI PFNGLGETTEXPARAMETERIVPROC cppgl_glGetTexParameteriv;
#define glGetTexParameteriv cppgl_glGetTexParameteriv
typedef void (APIENTRYP PFNGLGETTEXLEVELPARAMETERFVPROC)(GLenum target, GLint level, GLenum pname, GLfloat *params);
GLAPI PFNGLGETTEXLEVELPARAMETERFVPROC cppgl_glGetTexLevelParameterfv;
#define glGetTexLevelParameterfv cppgl_glGetTexLevelParameterfv
typedef void (APIENTRYP PFNGLGETTEXLEVELPARAMETERIVPROC)(GLenum target, GLint level, GLenum pname, GLint *params);
GLAPI PFNGLGETTEXLEVELPARAMETERIVPROC cppgl_glGetTexLevelParameteriv;
#define glGetTexLevelParameteriv cppgl_glGetTexLevelParameteriv
typedef GLboolean (APIENTRYP PFNGLISENABLEDPROC)(GLenum cap);
GLAPI PFNGLISENABLEDPROC cppgl_glIsEnabled;
#define glIsEnabled cppgl_glIsEnabled
typedef void (APIENTRYP PFNGLDEPTHRANGEPROC)(GLdouble near, GLdouble far);
GLAPI PFNGLDEPTHRANGEPROC cppgl_glDepthRange;
#define glDepthRange cppgl_glDepthRange
typedef void (APIENTRYP PFNGLVIEWPORTPROC)(GLint x, GLint y, GLsizei width, GLsizei height);
GLAPI PFNGLVIEWPORTPROC cppgl_glViewport;
#define glViewport cppgl_glViewport
typedef void (APIENTRYP PFNGLNEWLISTPROC)(GLuint list, GLenum mode);
GLAPI PFNGLNEWLISTPROC cppgl_glNewList;
#define glNewList cppgl_glNewList
typedef void (APIENTRYP PFNGLENDLISTPROC)();
GLAPI PFNGLENDLISTPROC cppgl_glEndList;
#define glEndList cppgl_glEndList
typedef void (APIENTRYP PFNGLCALLLISTPROC)(GLuint list);
GLAPI PFNGLCALLLISTPROC cppgl_glCallList;
#define glCallList cppgl_glCallList
typedef void (APIENTRYP PFNGLCALLLISTSPROC)(GLsizei n, GLenum type, const void *lists);
GLAPI PFNGLCALLLISTSPROC cppgl_glCallLists;
#define glCallLists cppgl_glCallLists
typedef void (APIENTRYP PFNGLDELETELISTSPROC)(GLuint list, GLsizei range);
GLAPI PFNGLDELETELISTSPROC cppgl_glDeleteLists;
#define glDeleteLists cppgl_glDeleteLists
typedef GLuint (APIENTRYP PFNGLGENLISTSPROC)(GLsizei range);
GLAPI PFNGLGENLISTSPROC cppgl_glGenLists;
#define glGenLists cppgl_glGenLists
typedef void (APIENTRYP PFNGLLISTBASEPROC)(GLuint base);
GLAPI PFNGLLISTBASEPROC cppgl_glListBase;
#define glListBase cppgl_glListBase
typedef void (APIENTRYP PFNGLBEGINPROC)(GLenum mode);
GLAPI PFNGLBEGINPROC cppgl_glBegin;
#define glBegin cppgl_glBegin
typedef void (APIENTRYP PFNGLBITMAPPROC)(GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig, GLfloat xmove, GLfloat ymove, const GLubyte *bitmap);
GLAPI PFNGLBITMAPPROC cppgl_glBitmap;
#define glBitmap cppgl_glBitmap
typedef void (APIENTRYP PFNGLCOLOR3BPROC)(GLbyte red, GLbyte green, GLbyte blue);
GLAPI PFNGLCOLOR3BPROC cppgl_glColor3b;
#define glColor3b cppgl_glColor3b
typedef void (APIENTRYP PFNGLCOLOR3BVPROC)(const GLbyte *v);
GLAPI PFNGLCOLOR3BVPROC cppgl_glColor3bv;
#define glColor3bv cppgl_glColor3bv
typedef void (APIENTRYP PFNGLCOLOR3DPROC)(GLdouble red, GLdouble green, GLdouble blue);
GLAPI PFNGLCOLOR3DPROC cppgl_glColor3d;
#define glColor3d cppgl_glColor3d
typedef void (APIENTRYP PFNGLCOLOR3DVPROC)(const GLdouble *v);
GLAPI PFNGLCOLOR3DVPROC cppgl_glColor3dv;
#define glColor3dv cppgl_glColor3dv
typedef void (APIENTRYP PFNGLCOLOR3FPROC)(GLfloat red, GLfloat green, GLfloat blue);
GLAPI PFNGLCOLOR3FPROC cppgl_glColor3f;
#define glColor3f cppgl_glColor3f
typedef void (APIENTRYP PFNGLCOLOR3FVPROC)(const GLfloat *v);
GLAPI PFNGLCOLOR3FVPROC cppgl_glColor3fv;
#define glColor3fv cppgl_glColor3fv
typedef void (APIENTRYP PFNGLCOLOR3IPROC)(GLint red, GLint green, GLint blue);
GLAPI PFNGLCOLOR3IPROC cppgl_glColor3i;
#define glColor3i cppgl_glColor3i
typedef void (APIENTRYP PFNGLCOLOR3IVPROC)(const GLint *v);
GLAPI PFNGLCOLOR3IVPROC cppgl_glColor3iv;
#define glColor3iv cppgl_glColor3iv
typedef void (APIENTRYP PFNGLCOLOR3SPROC)(GLshort red, GLshort green, GLshort blue);
GLAPI PFNGLCOLOR3SPROC cppgl_glColor3s;
#define glColor3s cppgl_glColor3s
typedef void (APIENTRYP PFNGLCOLOR3SVPROC)(const GLshort *v);
GLAPI PFNGLCOLOR3SVPROC cppgl_glColor3sv;
#define glColor3sv cppgl_glColor3sv
typedef void (APIENTRYP PFNGLCOLOR3UBPROC)(GLubyte red, GLubyte green, GLubyte blue);
GLAPI PFNGLCOLOR3UBPROC cppgl_glColor3ub;
#define glColor3ub cppgl_glColor3ub
typedef void (APIENTRYP PFNGLCOLOR3UBVPROC)(const GLubyte *v);
GLAPI PFNGLCOLOR3UBVPROC cppgl_glColor3ubv;
#define glColor3ubv cppgl_glColor3ubv
typedef void (APIENTRYP PFNGLCOLOR3UIPROC)(GLuint red, GLuint green, GLuint blue);
GLAPI PFNGLCOLOR3UIPROC cppgl_glColor3ui;
#define glColor3ui cppgl_glColor3ui
typedef void (APIENTRYP PFNGLCOLOR3UIVPROC)(const GLuint *v);
GLAPI PFNGLCOLOR3UIVPROC cppgl_glColor3uiv;
#define glColor3uiv cppgl_glColor3uiv
typedef void (APIENTRYP PFNGLCOLOR3USPROC)(GLushort red, GLushort green, GLushort blue);
GLAPI PFNGLCOLOR3USPROC cppgl_glColor3us;
#define glColor3us cppgl_glColor3us
typedef void (APIENTRYP PFNGLCOLOR3USVPROC)(const GLushort *v);
GLAPI PFNGLCOLOR3USVPROC cppgl_glColor3usv;
#define glColor3usv cppgl_glColor3usv
typedef void (APIENTRYP PFNGLCOLOR4BPROC)(GLbyte red, GLbyte green, GLbyte blue, GLbyte alpha);
GLAPI PFNGLCOLOR4BPROC cppgl_glColor4b;
#define glColor4b cppgl_glColor4b
typedef void (APIENTRYP PFNGLCOLOR4BVPROC)(const GLbyte *v);
GLAPI PFNGLCOLOR4BVPROC cppgl_glColor4bv;
#define glColor4bv cppgl_glColor4bv
typedef void (APIENTRYP PFNGLCOLOR4DPROC)(GLdouble red, GLdouble green, GLdouble blue, GLdouble alpha);
GLAPI PFNGLCOLOR4DPROC cppgl_glColor4d;
#define glColor4d cppgl_glColor4d
typedef void (APIENTRYP PFNGLCOLOR4DVPROC)(const GLdouble *v);
GLAPI PFNGLCOLOR4DVPROC cppgl_glColor4dv;
#define glColor4dv cppgl_glColor4dv
typedef void (APIENTRYP PFNGLCOLOR4FPROC)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
GLAPI PFNGLCOLOR4FPROC cppgl_glColor4f;
#define glColor4f cppgl_glColor4f
typedef void (APIENTRYP PFNGLCOLOR4FVPROC)(const GLfloat *v);
GLAPI PFNGLCOLOR4FVPROC cppgl_glColor4fv;
#define glColor4fv cppgl_glColor4fv
typedef void (APIENTRYP PFNGLCOLOR4IPROC)(GLint red, GLint green, GLint blue, GLint alpha);
GLAPI PFNGLCOLOR4IPROC cppgl_glColor4i;
#define glColor4i cppgl_glColor4i
typedef void (APIENTRYP PFNGLCOLOR4IVPROC)(const GLint *v);
GLAPI PFNGLCOLOR4IVPROC cppgl_glColor4iv;
#define glColor4iv cppgl_glColor4iv
typedef void (APIENTRYP PFNGLCOLOR4SPROC)(GLshort red, GLshort green, GLshort blue, GLshort alpha);
GLAPI PFNGLCOLOR4SPROC cppgl_glColor4s;
#define glColor4s cppgl_glColor4s
typedef void (APIENTRYP PFNGLCOLOR4SVPROC)(const GLshort *v);
GLAPI PFNGLCOLOR4SVPROC cppgl_glColor4sv;
#define glColor4sv cppgl_glColor4sv
typedef void (APIENTRYP PFNGLCOLOR4UBPROC)(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha);
GLAPI PFNGLCOLOR4UBPROC cppgl_glColor4ub;
#define glColor4ub cppgl_glColor4ub
typedef void (APIENTRYP PFNGLCOLOR4UBVPROC)(const GLubyte *v);
GLAPI PFNGLCOLOR4UBVPROC cppgl_glColor4ubv;
#define glColor4ubv cppgl_glColor4ubv
typedef void (APIENTRYP PFNGLCOLOR4UIPROC)(GLuint red, GLuint green, GLuint blue, GLuint alpha);
GLAPI PFNGLCOLOR4UIPROC cppgl_glColor4ui;
#define glColor4ui cppgl_glColor4ui
typedef void (APIENTRYP PFNGLCOLOR4UIVPROC)(const GLuint *v);
GLAPI PFNGLCOLOR4UIVPROC cppgl_glColor4uiv;
#define glColor4uiv cppgl_glColor4uiv
typedef void (APIENTRYP PFNGLCOLOR4USPROC)(GLushort red, GLushort green, GLushort blue, GLushort alpha);
GLAPI PFNGLCOLOR4USPROC cppgl_glColor4us;
#define glColor4us cppgl_glColor4us
typedef void (APIENTRYP PFNGLCOLOR4USVPROC)(const GLushort *v);
GLAPI PFNGLCOLOR4USVPROC cppgl_glColor4usv;
#define glColor4usv cppgl_glColor4usv
typedef void (APIENTRYP PFNGLEDGEFLAGPROC)(GLboolean flag);
GLAPI PFNGLEDGEFLAGPROC cppgl_glEdgeFlag;
#define glEdgeFlag cppgl_glEdgeFlag
typedef void (APIENTRYP PFNGLEDGEFLAGVPROC)(const GLboolean *flag);
GLAPI PFNGLEDGEFLAGVPROC cppgl_glEdgeFlagv;
#define glEdgeFlagv cppgl_glEdgeFlagv
typedef void (APIENTRYP PFNGLENDPROC)();
GLAPI PFNGLENDPROC cppgl_glEnd;
#define glEnd cppgl_glEnd
typedef void (APIENTRYP PFNGLINDEXDPROC)(GLdouble c);
GLAPI PFNGLINDEXDPROC cppgl_glIndexd;
#define glIndexd cppgl_glIndexd
typedef void (APIENTRYP PFNGLINDEXDVPROC)(const GLdouble *c);
GLAPI PFNGLINDEXDVPROC cppgl_glIndexdv;
#define glIndexdv cppgl_glIndexdv
typedef void (APIENTRYP PFNGLINDEXFPROC)(GLfloat c);
GLAPI PFNGLINDEXFPROC cppgl_glIndexf;
#define glIndexf cppgl_glIndexf
typedef void (APIENTRYP PFNGLINDEXFVPROC)(const GLfloat *c);
GLAPI PFNGLINDEXFVPROC cppgl_glIndexfv;
#define glIndexfv cppgl_glIndexfv
typedef void (APIENTRYP PFNGLINDEXIPROC)(GLint c);
GLAPI PFNGLINDEXIPROC cppgl_glIndexi;
#define glIndexi cppgl_glIndexi
typedef void (APIENTRYP PFNGLINDEXIVPROC)(const GLint *c);
GLAPI PFNGLINDEXIVPROC cppgl_glIndexiv;
#define glIndexiv cppgl_glIndexiv
typedef void (APIENTRYP PFNGLINDEXSPROC)(GLshort c);
GLAPI PFNGLINDEXSPROC cppgl_glIndexs;
#define glIndexs cppgl_glIndexs
typedef void (APIENTRYP PFNGLINDEXSVPROC)(const GLshort *c);
GLAPI PFNGLINDEXSVPROC cppgl_glIndexsv;
#define glIndexsv cppgl_glIndexsv
typedef void (APIENTRYP PFNGLNORMAL3BPROC)(GLbyte nx, GLbyte ny, GLbyte nz);
GLAPI PFNGLNORMAL3BPROC cppgl_glNormal3b;
#define glNormal3b cppgl_glNormal3b
typedef void (APIENTRYP PFNGLNORMAL3BVPROC)(const GLbyte *v);
GLAPI PFNGLNORMAL3BVPROC cppgl_glNormal3bv;
#define glNormal3bv cppgl_glNormal3bv
typedef void (APIENTRYP PFNGLNORMAL3DPROC)(GLdouble nx, GLdouble ny, GLdouble nz);
GLAPI PFNGLNORMAL3DPROC cppgl_glNormal3d;
#define glNormal3d cppgl_glNormal3d
typedef void (APIENTRYP PFNGLNORMAL3DVPROC)(const GLdouble *v);
GLAPI PFNGLNORMAL3DVPROC cppgl_glNormal3dv;
#define glNormal3dv cppgl_glNormal3dv
typedef void (APIENTRYP PFNGLNORMAL3FPROC)(GLfloat nx, GLfloat ny, GLfloat nz);
GLAPI PFNGLNORMAL3FPROC cppgl_glNormal3f;
#define glNormal3f cppgl_glNormal3f
typedef void (APIENTRYP PFNGLNORMAL3FVPROC)(const GLfloat *v);
GLAPI PFNGLNORMAL3FVPROC cppgl_glNormal3fv;
#define glNormal3fv cppgl_glNormal3fv
typedef void (APIENTRYP PFNGLNORMAL3IPROC)(GLint nx, GLint ny, GLint nz);
GLAPI PFNGLNORMAL3IPROC cppgl_glNormal3i;
#define glNormal3i cppgl_glNormal3i
typedef void (APIENTRYP PFNGLNORMAL3IVPROC)(const GLint *v);
GLAPI PFNGLNORMAL3IVPROC cppgl_glNormal3iv;
#define glNormal3iv cppgl_glNormal3iv
typedef void (APIENTRYP PFNGLNORMAL3SPROC)(GLshort nx, GLshort ny, GLshort nz);
GLAPI PFNGLNORMAL3SPROC cppgl_glNormal3s;
#define glNormal3s cppgl_glNormal3s
typedef void (APIENTRYP PFNGLNORMAL3SVPROC)(const GLshort *v);
GLAPI PFNGLNORMAL3SVPROC cppgl_glNormal3sv;
#define glNormal3sv cppgl_glNormal3sv
typedef void (APIENTRYP PFNGLRASTERPOS2DPROC)(GLdouble x, GLdouble y);
GLAPI PFNGLRASTERPOS2DPROC cppgl_glRasterPos2d;
#define glRasterPos2d cppgl_glRasterPos2d
typedef void (APIENTRYP PFNGLRASTERPOS2DVPROC)(const GLdouble *v);
GLAPI PFNGLRASTERPOS2DVPROC cppgl_glRasterPos2dv;
#define glRasterPos2dv cppgl_glRasterPos2dv
typedef void (APIENTRYP PFNGLRASTERPOS2FPROC)(GLfloat x, GLfloat y);
GLAPI PFNGLRASTERPOS2FPROC cppgl_glRasterPos2f;
#define glRasterPos2f cppgl_glRasterPos2f
typedef void (APIENTRYP PFNGLRASTERPOS2FVPROC)(const GLfloat *v);
GLAPI PFNGLRASTERPOS2FVPROC cppgl_glRasterPos2fv;
#define glRasterPos2fv cppgl_glRasterPos2fv
typedef void (APIENTRYP PFNGLRASTERPOS2IPROC)(GLint x, GLint y);
GLAPI PFNGLRASTERPOS2IPROC cppgl_glRasterPos2i;
#define glRasterPos2i cppgl_glRasterPos2i
typedef void (APIENTRYP PFNGLRASTERPOS2IVPROC)(const GLint *v);
GLAPI PFNGLRASTERPOS2IVPROC cppgl_glRasterPos2iv;
#define glRasterPos2iv cppgl_glRasterPos2iv
typedef void (APIENTRYP PFNGLRASTERPOS2SPROC)(GLshort x, GLshort y);
GLAPI PFNGLRASTERPOS2SPROC cppgl_glRasterPos2s;
#define glRasterPos2s cppgl_glRasterPos2s
typedef void (APIENTRYP PFNGLRASTERPOS2SVPROC)(const GLshort *v);
GLAPI PFNGLRASTERPOS2SVPROC cppgl_glRasterPos2sv;
#define glRasterPos2sv cppgl_glRasterPos2sv
typedef void (APIENTRYP PFNGLRASTERPOS3DPROC)(GLdouble x, GLdouble y, GLdouble z);
GLAPI PFNGLRASTERPOS3DPROC cppgl_glRasterPos3d;
#define glRasterPos3d cppgl_glRasterPos3d
typedef void (APIENTRYP PFNGLRASTERPOS3DVPROC)(const GLdouble *v);
GLAPI PFNGLRASTERPOS3DVPROC cppgl_glRasterPos3dv;
#define glRasterPos3dv cppgl_glRasterPos3dv
typedef void (APIENTRYP PFNGLRASTERPOS3FPROC)(GLfloat x, GLfloat y, GLfloat z);
GLAPI PFNGLRASTERPOS3FPROC cppgl_glRasterPos3f;
#define glRasterPos3f cppgl_glRasterPos3f
typedef void (APIENTRYP PFNGLRASTERPOS3FVPROC)(const GLfloat *v);
GLAPI PFNGLRASTERPOS3FVPROC cppgl_glRasterPos3fv;
#define glRasterPos3fv cppgl_glRasterPos3fv
typedef void (APIENTRYP PFNGLRASTERPOS3IPROC)(GLint x, GLint y, GLint z);
GLAPI PFNGLRASTERPOS3IPROC cppgl_glRasterPos3i;
#define glRasterPos3i cppgl_glRasterPos3i
typedef void (APIENTRYP PFNGLRASTERPOS3IVPROC)(const GLint *v);
GLAPI PFNGLRASTERPOS3IVPROC cppgl_glRasterPos3iv;
#define glRasterPos3iv cppgl_glRasterPos3iv
typedef void (APIENTRYP PFNGLRASTERPOS3SPROC)(GLshort x, GLshort y, GLshort z);
GLAPI PFNGLRASTERPOS3SPROC cppgl_glRasterPos3s;
#define glRasterPos3s cppgl_glRasterPos3s
typedef void (APIENTRYP PFNGLRASTERPOS3SVPROC)(const GLshort *v);
GLAPI PFNGLRASTERPOS3SVPROC cppgl_glRasterPos3sv;
#define glRasterPos3sv cppgl_glRasterPos3sv
typedef void (APIENTRYP PFNGLRASTERPOS4DPROC)(GLdouble x, GLdouble y, GLdouble z, GLdouble w);
GLAPI PFNGLRASTERPOS4DPROC cppgl_glRasterPos4d;
#define glRasterPos4d cppgl_glRasterPos4d
typedef void (APIENTRYP PFNGLRASTERPOS4DVPROC)(const GLdouble *v);
GLAPI PFNGLRASTERPOS4DVPROC cppgl_glRasterPos4dv;
#define glRasterPos4dv cppgl_glRasterPos4dv
typedef void (APIENTRYP PFNGLRASTERPOS4FPROC)(GLfloat x, GLfloat y, GLfloat z, GLfloat w);
GLAPI PFNGLRASTERPOS4FPROC cppgl_glRasterPos4f;
#define glRasterPos4f cppgl_glRasterPos4f
typedef void (APIENTRYP PFNGLRASTERPOS4FVPROC)(const GLfloat *v);
GLAPI PFNGLRASTERPOS4FVPROC cppgl_glRasterPos4fv;
#define glRasterPos4fv cppgl_glRasterPos4fv
typedef void (APIENTRYP PFNGLRASTERPOS4IPROC)(GLint x, GLint y, GLint z, GLint w);
GLAPI PFNGLRASTERPOS4IPROC cppgl_glRasterPos4i;
#define glRasterPos4i cppgl_glRasterPos4i
typedef void (APIENTRYP PFNGLRASTERPOS4IVPROC)(const GLint *v);
GLAPI PFNGLRASTERPOS4IVPROC cppgl_glRasterPos4iv;
#define glRasterPos4iv cppgl_glRasterPos4iv
typedef void (APIENTRYP PFNGLRASTERPOS4SPROC)(GLshort x, GLshort y, GLshort z, GLshort w);
GLAPI PFNGLRASTERPOS4SPROC cppgl_glRasterPos4s;
#define glRasterPos4s cppgl_glRasterPos4s
typedef void (APIENTRYP PFNGLRASTERPOS4SVPROC)(const GLshort *v);
GLAPI PFNGLRASTERPOS4SVPROC cppgl_glRasterPos4sv;
#define glRasterPos4sv cppgl_glRasterPos4sv
typedef void (APIENTRYP PFNGLRECTDPROC)(GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2);
GLAPI PFNGLRECTDPROC cppgl_glRectd;
#define glRectd cppgl_glRectd
typedef void (APIENTRYP PFNGLRECTDVPROC)(const GLdouble *v1, const GLdouble *v2);
GLAPI PFNGLRECTDVPROC cppgl_glRectdv;
#define glRectdv cppgl_glRectdv
typedef void (APIENTRYP PFNGLRECTFPROC)(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2);
GLAPI PFNGLRECTFPROC cppgl_glRectf;
#define glRectf cppgl_glRectf
typedef void (APIENTRYP PFNGLRECTFVPROC)(const GLfloat *v1, const GLfloat *v2);
GLAPI PFNGLRECTFVPROC cppgl_glRectfv;
#define glRectfv cppgl_glRectfv
typedef void (APIENTRYP PFNGLRECTIPROC)(GLint x1, GLint y1, GLint x2, GLint y2);
GLAPI PFNGLRECTIPROC cppgl_glRecti;
#define glRecti cppgl_glRecti
typedef void (APIENTRYP PFNGLRECTIVPROC)(const GLint *v1, const GLint *v2);
GLAPI PFNGLRECTIVPROC cppgl_glRectiv;
#define glRectiv cppgl_glRectiv
typedef void (APIENTRYP PFNGLRECTSPROC)(GLshort x1, GLshort y1, GLshort x2, GLshort y2);
GLAPI PFNGLRECTSPROC cppgl_glRects;
#define glRects cppgl_glRects
typedef void (APIENTRYP PFNGLRECTSVPROC)(const GLshort *v1, const GLshort *v2);
GLAPI PFNGLRECTSVPROC cppgl_glRectsv;
#define glRectsv cppgl_glRectsv
typedef void (APIENTRYP PFNGLTEXCOORD1DPROC)(GLdouble s);
GLAPI PFNGLTEXCOORD1DPROC cppgl_glTexCoord1d;
#define glTexCoord1d cppgl_glTexCoord1d
typedef void (APIENTRYP PFNGLTEXCOORD1DVPROC)(const GLdouble *v);
GLAPI PFNGLTEXCOORD1DVPROC cppgl_glTexCoord1dv;
#define glTexCoord1dv cppgl_glTexCoord1dv
typedef void (APIENTRYP PFNGLTEXCOORD1FPROC)(GLfloat s);
GLAPI PFNGLTEXCOORD1FPROC cppgl_glTexCoord1f;
#define glTexCoord1f cppgl_glTexCoord1f
typedef void (APIENTRYP PFNGLTEXCOORD1FVPROC)(const GLfloat *v);
GLAPI PFNGLTEXCOORD1FVPROC cppgl_glTexCoord1fv;
#define glTexCoord1fv cppgl_glTexCoord1fv
typedef void (APIENTRYP PFNGLTEXCOORD1IPROC)(GLint s);
GLAPI PFNGLTEXCOORD1IPROC cppgl_glTexCoord1i;
#define glTexCoord1i cppgl_glTexCoord1i
typedef void (APIENTRYP PFNGLTEXCOORD1IVPROC)(const GLint *v);
GLAPI PFNGLTEXCOORD1IVPROC cppgl_glTexCoord1iv;
#define glTexCoord1iv cppgl_glTexCoord1iv
typedef void (APIENTRYP PFNGLTEXCOORD1SPROC)(GLshort s);
GLAPI PFNGLTEXCOORD1SPROC cppgl_glTexCoord1s;
#define glTexCoord1s cppgl_glTexCoord1s
typedef void (APIENTRYP PFNGLTEXCOORD1SVPROC)(const GLshort *v);
GLAPI PFNGLTEXCOORD1SVPROC cppgl_glTexCoord1sv;
#define glTexCoord1sv cppgl_glTexCoord1sv
typedef void (APIENTRYP PFNGLTEXCOORD2DPROC)(GLdouble s, GLdouble t);
GLAPI PFNGLTEXCOORD2DPROC cppgl_glTexCoord2d;
#define glTexCoord2d cppgl_glTexCoord2d
typedef void (APIENTRYP PFNGLTEXCOORD2DVPROC)(const GLdouble *v);
GLAPI PFNGLTEXCOORD2DVPROC cppgl_glTexCoord2dv;
#define glTexCoord2dv cppgl_glTexCoord2dv
typedef void (APIENTRYP PFNGLTEXCOORD2FPROC)(GLfloat s, GLfloat t);
GLAPI PFNGLTEXCOORD2FPROC cppgl_glTexCoord2f;
#define glTexCoord2f cppgl_glTexCoord2f
typedef void (APIENTRYP PFNGLTEXCOORD2FVPROC)(const GLfloat *v);
GLAPI PFNGLTEXCOORD2FVPROC cppgl_glTexCoord2fv;
#define glTexCoord2fv cppgl_glTexCoord2fv
typedef void (APIENTRYP PFNGLTEXCOORD2IPROC)(GLint s, GLint t);
GLAPI PFNGLTEXCOORD2IPROC cppgl_glTexCoord2i;
#define glTexCoord2i cppgl_glTexCoord2i
typedef void (APIENTRYP PFNGLTEXCOORD2IVPROC)(const GLint *v);
GLAPI PFNGLTEXCOORD2IVPROC cppgl_glTexCoord2iv;
#define glTexCoord2iv cppgl_glTexCoord2iv
typedef void (APIENTRYP PFNGLTEXCOORD2SPROC)(GLshort s, GLshort t);
GLAPI PFNGLTEXCOORD2SPROC cppgl_glTexCoord2s;
#define glTexCoord2s cppgl_glTexCoord2s
typedef void (APIENTRYP PFNGLTEXCOORD2SVPROC)(const GLshort *v);
GLAPI PFNGLTEXCOORD2SVPROC cppgl_glTexCoord2sv;
#define glTexCoord2sv cppgl_glTexCoord2sv
typedef void (APIENTRYP PFNGLTEXCOORD3DPROC)(GLdouble s, GLdouble t, GLdouble r);
GLAPI PFNGLTEXCOORD3DPROC cppgl_glTexCoord3d;
#define glTexCoord3d cppgl_glTexCoord3d
typedef void (APIENTRYP PFNGLTEXCOORD3DVPROC)(const GLdouble *v);
GLAPI PFNGLTEXCOORD3DVPROC cppgl_glTexCoord3dv;
#define glTexCoord3dv cppgl_glTexCoord3dv
typedef void (APIENTRYP PFNGLTEXCOORD3FPROC)(GLfloat s, GLfloat t, GLfloat r);
GLAPI PFNGLTEXCOORD3FPROC cppgl_glTexCoord3f;
#define glTexCoord3f cppgl_glTexCoord3f
typedef void (APIENTRYP PFNGLTEXCOORD3FVPROC)(const GLfloat *v);
GLAPI PFNGLTEXCOORD3FVPROC cppgl_glTexCoord3fv;
#define glTexCoord3fv cppgl_glTexCoord3fv
typedef void (APIENTRYP PFNGLTEXCOORD3IPROC)(GLint s, GLint t, GLint r);
GLAPI PFNGLTEXCOORD3IPROC cppgl_glTexCoord3i;
#define glTexCoord3i cppgl_glTexCoord3i
typedef void (APIENTRYP PFNGLTEXCOORD3IVPROC)(const GLint *v);
GLAPI PFNGLTEXCOORD3IVPROC cppgl_glTexCoord3iv;
#define glTexCoord3iv cppgl_glTexCoord3iv
typedef void (APIENTRYP PFNGLTEXCOORD3SPROC)(GLshort s, GLshort t, GLshort r);
GLAPI PFNGLTEXCOORD3SPROC cppgl_glTexCoord3s;
#define glTexCoord3s cppgl_glTexCoord3s
typedef void (APIENTRYP PFNGLTEXCOORD3SVPROC)(const GLshort *v);
GLAPI PFNGLTEXCOORD3SVPROC cppgl_glTexCoord3sv;
#define glTexCoord3sv cppgl_glTexCoord3sv
typedef void (APIENTRYP PFNGLTEXCOORD4DPROC)(GLdouble s, GLdouble t, GLdouble r, GLdouble q);
GLAPI PFNGLTEXCOORD4DPROC cppgl_glTexCoord4d;
#define glTexCoord4d cppgl_glTexCoord4d
typedef void (APIENTRYP PFNGLTEXCOORD4DVPROC)(const GLdouble *v);
GLAPI PFNGLTEXCOORD4DVPROC cppgl_glTexCoord4dv;
#define glTexCoord4dv cppgl_glTexCoord4dv
typedef void (APIENTRYP PFNGLTEXCOORD4FPROC)(GLfloat s, GLfloat t, GLfloat r, GLfloat q);
GLAPI PFNGLTEXCOORD4FPROC cppgl_glTexCoord4f;
#define glTexCoord4f cppgl_glTexCoord4f
typedef void (APIENTRYP PFNGLTEXCOORD4FVPROC)(const GLfloat *v);
GLAPI PFNGLTEXCOORD4FVPROC cppgl_glTexCoord4fv;
#define glTexCoord4fv cppgl_glTexCoord4fv
typedef void (APIENTRYP PFNGLTEXCOORD4IPROC)(GLint s, GLint t, GLint r, GLint q);
GLAPI PFNGLTEXCOORD4IPROC cppgl_glTexCoord4i;
#define glTexCoord4i cppgl_glTexCoord4i
typedef void (APIENTRYP PFNGLTEXCOORD4IVPROC)(const GLint *v);
GLAPI PFNGLTEXCOORD4IVPROC cppgl_glTexCoord4iv;
#define glTexCoord4iv cppgl_glTexCoord4iv
typedef void (APIENTRYP PFNGLTEXCOORD4SPROC)(GLshort s, GLshort t, GLshort r, GLshort q);
GLAPI PFNGLTEXCOORD4SPROC cppgl_glTexCoord4s;
#define glTexCoord4s cppgl_glTexCoord4s
typedef void (APIENTRYP PFNGLTEXCOORD4SVPROC)(const GLshort *v);
GLAPI PFNGLTEXCOORD4SVPROC cppgl_glTexCoord4sv;
#define glTexCoord4sv cppgl_glTexCoord4sv
typedef void (APIENTRYP PFNGLVERTEX2DPROC)(GLdouble x, GLdouble y);
GLAPI PFNGLVERTEX2DPROC cppgl_glVertex2d;
#define glVertex2d cppgl_glVertex2d
typedef void (APIENTRYP PFNGLVERTEX2DVPROC)(const GLdouble *v);
GLAPI PFNGLVERTEX2DVPROC cppgl_glVertex2dv;
#define glVertex2dv cppgl_glVertex2dv
typedef void (APIENTRYP PFNGLVERTEX2FPROC)(GLfloat x, GLfloat y);
GLAPI PFNGLVERTEX2FPROC cppgl_glVertex2f;
#define glVertex2f cppgl_glVertex2f
typedef void (APIENTRYP PFNGLVERTEX2FVPROC)(const GLfloat *v);
GLAPI PFNGLVERTEX2FVPROC cppgl_glVertex2fv;
#define glVertex2fv cppgl_glVertex2fv
typedef void (APIENTRYP PFNGLVERTEX2IPROC)(GLint x, GLint y);
GLAPI PFNGLVERTEX2IPROC cppgl_glVertex2i;
#define glVertex2i cppgl_glVertex2i
typedef void (APIENTRYP PFNGLVERTEX2IVPROC)(const GLint *v);
GLAPI PFNGLVERTEX2IVPROC cppgl_glVertex2iv;
#define glVertex2iv cppgl_glVertex2iv
typedef void (APIENTRYP PFNGLVERTEX2SPROC)(GLshort x, GLshort y);
GLAPI PFNGLVERTEX2SPROC cppgl_glVertex2s;
#define glVertex2s cppgl_glVertex2s
typedef void (APIENTRYP PFNGLVERTEX2SVPROC)(const GLshort *v);
GLAPI PFNGLVERTEX2SVPROC cppgl_glVertex2sv;
#define glVertex2sv cppgl_glVertex2sv
typedef void (APIENTRYP PFNGLVERTEX3DPROC)(GLdouble x, GLdouble y, GLdouble z);
GLAPI PFNGLVERTEX3DPROC cppgl_glVertex3d;
#define glVertex3d cppgl_glVertex3d
typedef void (APIENTRYP PFNGLVERTEX3DVPROC)(const GLdouble *v);
GLAPI PFNGLVERTEX3DVPROC cppgl_glVertex3dv;
#define glVertex3dv cppgl_glVertex3dv
typedef void (APIENTRYP PFNGLVERTEX3FPROC)(GLfloat x, GLfloat y, GLfloat z);
GLAPI PFNGLVERTEX3FPROC cppgl_glVertex3f;
#define glVertex3f cppgl_glVertex3f
typedef void (APIENTRYP PFNGLVERTEX3FVPROC)(const GLfloat *v);
GLAPI PFNGLVERTEX3FVPROC cppgl_glVertex3fv;
#define glVertex3fv cppgl_glVertex3fv
typedef void (APIENTRYP PFNGLVERTEX3IPROC)(GLint x, GLint y, GLint z);
GLAPI PFNGLVERTEX3IPROC cppgl_glVertex3i;
#define glVertex3i cppgl_glVertex3i
typedef void (APIENTRYP PFNGLVERTEX3IVPROC)(const GLint *v);
GLAPI PFNGLVERTEX3IVPROC cppgl_glVertex3iv;
#define glVertex3iv cppgl_glVertex3iv
typedef void (APIENTRYP PFNGLVERTEX3SPROC)(GLshort x, GLshort y, GLshort z);
GLAPI PFNGLVERTEX3SPROC cppgl_glVertex3s;
#define glVertex3s cppgl_glVertex3s
typedef void (APIENTRYP PFNGLVERTEX3SVPROC)(const GLshort *v);
GLAPI PFNGLVERTEX3SVPROC cppgl_glVertex3sv;
#define glVertex3sv cppgl_glVertex3sv
typedef void (APIENTRYP PFNGLVERTEX4DPROC)(GLdouble x, GLdouble y, GLdouble z, GLdouble w);
GLAPI PFNGLVERTEX4DPROC cppgl_glVertex4d;
#define glVertex4d cppgl_glVertex4d
typedef void (APIENTRYP PFNGLVERTEX4DVPROC)(const GLdouble *v);
GLAPI PFNGLVERTEX4DVPROC cppgl_glVertex4dv;
#define glVertex4dv cppgl_glVertex4dv
typedef void (APIENTRYP PFNGLVERTEX4FPROC)(GLfloat x, GLfloat y, GLfloat z, GLfloat w);
GLAPI PFNGLVERTEX4FPROC cppgl_glVertex4f;
#define glVertex4f cppgl_glVertex4f
typedef void (APIENTRYP PFNGLVERTEX4FVPROC)(const GLfloat *v);
GLAPI PFNGLVERTEX4FVPROC cppgl_glVertex4fv;
#define glVertex4fv cppgl_glVertex4fv
typedef void (APIENTRYP PFNGLVERTEX4IPROC)(GLint x, GLint y, GLint z, GLint w);
GLAPI PFNGLVERTEX4IPROC cppgl_glVertex4i;
#define glVertex4i cppgl_glVertex4i
typedef void (APIENTRYP PFNGLVERTEX4IVPROC)(const GLint *v);
GLAPI PFNGLVERTEX4IVPROC cppgl_glVertex4iv;
#define glVertex4iv cppgl_glVertex4iv
typedef void (APIENTRYP PFNGLVERTEX4SPROC)(GLshort x, GLshort y, GLshort z, GLshort w);
GLAPI PFNGLVERTEX4SPROC cppgl_glVertex4s;
#define glVertex4s cppgl_glVertex4s
typedef void (APIENTRYP PFNGLVERTEX4SVPROC)(const GLshort *v);
GLAPI PFNGLVERTEX4SVPROC cppgl_glVertex4sv;
#define glVertex4sv cppgl_glVertex4sv
typedef void (APIENTRYP PFNGLCLIPPLANEPROC)(GLenum plane, const GLdouble *equation);
GLAPI PFNGLCLIPPLANEPROC cppgl_glClipPlane;
#define glClipPlane cppgl_glClipPlane
typedef void (APIENTRYP PFNGLCOLORMATERIALPROC)(GLenum face, GLenum mode);
GLAPI PFNGLCOLORMATERIALPROC cppgl_glColorMaterial;
#define glColorMaterial cppgl_glColorMaterial
typedef void (APIENTRYP PFNGLFOGFPROC)(GLenum pname, GLfloat param);
GLAPI PFNGLFOGFPROC cppgl_glFogf;
#define glFogf cppgl_glFogf
typedef void (APIENTRYP PFNGLFOGFVPROC)(GLenum pname, const GLfloat *params);
GLAPI PFNGLFOGFVPROC cppgl_glFogfv;
#define glFogfv cppgl_glFogfv
typedef void (APIENTRYP PFNGLFOGIPROC)(GLenum pname, GLint param);
GLAPI PFNGLFOGIPROC cppgl_glFogi;
#define glFogi cppgl_glFogi
typedef void (APIENTRYP PFNGLFOGIVPROC)(GLenum pname, const GLint *params);
GLAPI PFNGLFOGIVPROC cppgl_glFogiv;
#define glFogiv cppgl_glFogiv
typedef void (APIENTRYP PFNGLLIGHTFPROC)(GLenum light, GLenum pname, GLfloat param);
GLAPI PFNGLLIGHTFPROC cppgl_glLightf;
#define glLightf cppgl_glLightf
typedef void (APIENTRYP PFNGLLIGHTFVPROC)(GLenum light, GLenum pname, const GLfloat *params);
GLAPI PFNGLLIGHTFVPROC cppgl_glLightfv;
#define glLightfv cppgl_glLightfv
typedef void (APIENTRYP PFNGLLIGHTIPROC)(GLenum light, GLenum pname, GLint param);
GLAPI PFNGLLIGHTIPROC cppgl_glLighti;
#define glLighti cppgl_glLighti
typedef void (APIENTRYP PFNGLLIGHTIVPROC)(GLenum light, GLenum pname, const GLint *params);
GLAPI PFNGLLIGHTIVPROC cppgl_glLightiv;
#define glLightiv cppgl_glLightiv
typedef void (APIENTRYP PFNGLLIGHTMODELFPROC)(GLenum pname, GLfloat param);
GLAPI PFNGLLIGHTMODELFPROC cppgl_glLightModelf;
#define glLightModelf cppgl_glLightModelf
typedef void (APIENTRYP PFNGLLIGHTMODELFVPROC)(GLenum pname, const GLfloat *params);
GLAPI PFNGLLIGHTMODELFVPROC cppgl_glLightModelfv;
#define glLightModelfv cppgl_glLightModelfv
typedef void (APIENTRYP PFNGLLIGHTMODELIPROC)(GLenum pname, GLint param);
GLAPI PFNGLLIGHTMODELIPROC cppgl_glLightModeli;
#define glLightModeli cppgl_glLightModeli
typedef void (APIENTRYP PFNGLLIGHTMODELIVPROC)(GLenum pname, const GLint *params);
GLAPI PFNGLLIGHTMODELIVPROC cppgl_glLightModeliv;
#define glLightModeliv cppgl_glLightModeliv
typedef void (APIENTRYP PFNGLLINESTIPPLEPROC)(GLint factor, GLushort pattern);
GLAPI PFNGLLINESTIPPLEPROC cppgl_glLineStipple;
#define glLineStipple cppgl_glLineStipple
typedef void (APIENTRYP PFNGLMATERIALFPROC)(GLenum face, GLenum pname, GLfloat param);
GLAPI PFNGLMATERIALFPROC cppgl_glMaterialf;
#define glMaterialf cppgl_glMaterialf
typedef void (APIENTRYP PFNGLMATERIALFVPROC)(GLenum face, GLenum pname, const GLfloat *params);
GLAPI PFNGLMATERIALFVPROC cppgl_glMaterialfv;
#define glMaterialfv cppgl_glMaterialfv
typedef void (APIENTRYP PFNGLMATERIALIPROC)(GLenum face, GLenum pname, GLint param);
GLAPI PFNGLMATERIALIPROC cppgl_glMateriali;
#define glMateriali cppgl_glMateriali
typedef void (APIENTRYP PFNGLMATERIALIVPROC)(GLenum face, GLenum pname, const GLint *params);
GLAPI PFNGLMATERIALIVPROC cppgl_glMaterialiv;
#define glMaterialiv cppgl_glMaterialiv
typedef void (APIENTRYP PFNGLPOLYGONSTIPPLEPROC)(const GLubyte *mask);
GLAPI PFNGLPOLYGONSTIPPLEPROC cppgl_glPolygonStipple;
#define glPolygonStipple cppgl_glPolygonStipple
typedef void (APIENTRYP PFNGLSHADEMODELPROC)(GLenum mode);
GLAPI PFNGLSHADEMODELPROC cppgl_glShadeModel;
#define glShadeModel cppgl_glShadeModel
typedef void (APIENTRYP PFNGLTEXENVFPROC)(GLenum target, GLenum pname, GLfloat param);
GLAPI PFNGLTEXENVFPROC cppgl_glTexEnvf;
#define glTexEnvf cppgl_glTexEnvf
typedef void (APIENTRYP PFNGLTEXENVFVPROC)(GLenum target, GLenum pname, const GLfloat *params);
GLAPI PFNGLTEXENVFVPROC cppgl_glTexEnvfv;
#define glTexEnvfv cppgl_glTexEnvfv
typedef void (APIENTRYP PFNGLTEXENVIPROC)(GLenum target, GLenum pname, GLint param);
GLAPI PFNGLTEXENVIPROC cppgl_glTexEnvi;
#define glTexEnvi cppgl_glTexEnvi
typedef void (APIENTRYP PFNGLTEXENVIVPROC)(GLenum target, GLenum pname, const GLint *params);
GLAPI PFNGLTEXENVIVPROC cppgl_glTexEnviv;
#define glTexEnviv cppgl_glTexEnviv
typedef void (APIENTRYP PFNGLTEXGENDPROC)(GLenum coord, GLenum pname, GLdouble param);
GLAPI PFNGLTEXGENDPROC cppgl_glTexGend;
#define glTexGend cppgl_glTexGend
typedef void (APIENTRYP PFNGLTEXGENDVPROC)(GLenum coord, GLenum pname, const GLdouble *params);
GLAPI PFNGLTEXGENDVPROC cppgl_glTexGendv;
#define glTexGendv cppgl_glTexGendv
typedef void (APIENTRYP PFNGLTEXGENFPROC)(GLenum coord, GLenum pname, GLfloat param);
GLAPI PFNGLTEXGENFPROC cppgl_glTexGenf;
#define glTexGenf cppgl_glTexGenf
typedef void (APIENTRYP PFNGLTEXGENFVPROC)(GLenum coord, GLenum pname, const GLfloat *params);
GLAPI PFNGLTEXGENFVPROC cppgl_glTexGenfv;
#define glTexGenfv cppgl_glTexGenfv
typedef void (APIENTRYP PFNGLTEXGENIPROC)(GLenum coord, GLenum pname, GLint param);
GLAPI PFNGLTEXGENIPROC cppgl_glTexGeni;
#define glTexGeni cppgl_glTexGeni
typedef void (APIENTRYP PFNGLTEXGENIVPROC)(GLenum coord, GLenum pname, const GLint *params);
GLAPI PFNGLTEXGENIVPROC cppgl_glTexGeniv;
#define glTexGeniv cppgl_glTexGeniv
typedef void (APIENTRYP PFNGLFEEDBACKBUFFERPROC)(GLsizei size, GLenum type, GLfloat *buffer);
GLAPI PFNGLFEEDBACKBUFFERPROC cppgl_glFeedbackBuffer;
#define glFeedbackBuffer cppgl_glFeedbackBuffer
typedef void (APIENTRYP PFNGLSELECTBUFFERPROC)(GLsizei size, GLuint *buffer);
GLAPI PFNGLSELECTBUFFERPROC cppgl_glSelectBuffer;
#define glSelectBuffer cppgl_glSelectBuffer
typedef GLint (APIENTRYP PFNGLRENDERMODEPROC)(GLenum mode);
GLAPI PFNGLRENDERMODEPROC cppgl_glRenderMode;
#define glRenderMode cppgl_glRenderMode
typedef void (APIENTRYP PFNGLINITNAMESPROC)();
GLAPI PFNGLINITNAMESPROC cppgl_glInitNames;
#define glInitNames cppgl_glInitNames
typedef void (APIENTRYP PFNGLLOADNAMEPROC)(GLuint name);
GLAPI PFNGLLOADNAMEPROC cppgl_glLoadName;
#define glLoadName cppgl_glLoadName
typedef void (APIENTRYP PFNGLPASSTHROUGHPROC)(GLfloat token);
GLAPI PFNGLPASSTHROUGHPROC cppgl_glPassThrough;
#define glPassThrough cppgl_glPassThrough
typedef void (APIENTRYP PFNGLPOPNAMEPROC)();
GLAPI PFNGLPOPNAMEPROC cppgl_glPopName;
#define glPopName cppgl_glPopName
typedef void (APIENTRYP PFNGLPUSHNAMEPROC)(GLuint name);
GLAPI PFNGLPUSHNAMEPROC cppgl_glPushName;
#define glPushName cppgl_glPushName
typedef void (APIENTRYP PFNGLCLEARACCUMPROC)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
GLAPI PFNGLCLEARACCUMPROC cppgl_glClearAccum;
#define glClearAccum cppgl_glClearAccum
typedef void (APIENTRYP PFNGLCLEARINDEXPROC)(GLfloat c);
GLAPI PFNGLCLEARINDEXPROC cppgl_glClearIndex;
#define glClearIndex cppgl_glClearIndex
typedef void (APIENTRYP PFNGLINDEXMASKPROC)(GLuint mask);
GLAPI PFNGLINDEXMASKPROC cppgl_glIndexMask;
#define glIndexMask cppgl_glIndexMask
typedef void (APIENTRYP PFNGLACCUMPROC)(GLenum op, GLfloat value);
GLAPI PFNGLACCUMPROC cppgl_glAccum;
#define glAccum cppgl_glAccum
typedef void (APIENTRYP PFNGLPOPATTRIBPROC)();
GLAPI PFNGLPOPATTRIBPROC cppgl_glPopAttrib;
#define glPopAttrib cppgl_glPopAttrib
typedef void (APIENTRYP PFNGLPUSHATTRIBPROC)(GLbitfield mask);
GLAPI PFNGLPUSHATTRIBPROC cppgl_glPushAttrib;
#define glPushAttrib cppgl_glPushAttrib
typedef void (APIENTRYP PFNGLMAP1DPROC)(GLenum target, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble *points);
GLAPI PFNGLMAP1DPROC cppgl_glMap1d;
#define glMap1d cppgl_glMap1d
typedef void (APIENTRYP PFNGLMAP1FPROC)(GLenum target, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat *points);
GLAPI PFNGLMAP1FPROC cppgl_glMap1f;
#define glMap1f cppgl_glMap1f
typedef void (APIENTRYP PFNGLMAP2DPROC)(GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble *points);
GLAPI PFNGLMAP2DPROC cppgl_glMap2d;
#define glMap2d cppgl_glMap2d
typedef void (APIENTRYP PFNGLMAP2FPROC)(GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const GLfloat *points);
GLAPI PFNGLMAP2FPROC cppgl_glMap2f;
#define glMap2f cppgl_glMap2f
typedef void (APIENTRYP PFNGLMAPGRID1DPROC)(GLint un, GLdouble u1, GLdouble u2);
GLAPI PFNGLMAPGRID1DPROC cppgl_glMapGrid1d;
#define glMapGrid1d cppgl_glMapGrid1d
typedef void (APIENTRYP PFNGLMAPGRID1FPROC)(GLint un, GLfloat u1, GLfloat u2);
GLAPI PFNGLMAPGRID1FPROC cppgl_glMapGrid1f;
#define glMapGrid1f cppgl_glMapGrid1f
typedef void (APIENTRYP PFNGLMAPGRID2DPROC)(GLint un, GLdouble u1, GLdouble u2, GLint vn, GLdouble v1, GLdouble v2);
GLAPI PFNGLMAPGRID2DPROC cppgl_glMapGrid2d;
#define glMapGrid2d cppgl_glMapGrid2d
typedef void (APIENTRYP PFNGLMAPGRID2FPROC)(GLint un, GLfloat u1, GLfloat u2, GLint vn, GLfloat v1, GLfloat v2);
GLAPI PFNGLMAPGRID2FPROC cppgl_glMapGrid2f;
#define glMapGrid2f cppgl_glMapGrid2f
typedef void (APIENTRYP PFNGLEVALCOORD1DPROC)(GLdouble u);
GLAPI PFNGLEVALCOORD1DPROC cppgl_glEvalCoord1d;
#define glEvalCoord1d cppgl_glEvalCoord1d
typedef void (APIENTRYP PFNGLEVALCOORD1DVPROC)(const GLdouble *u);
GLAPI PFNGLEVALCOORD1DVPROC cppgl_glEvalCoord1dv;
#define glEvalCoord1dv cppgl_glEvalCoord1dv
typedef void (APIENTRYP PFNGLEVALCOORD1FPROC)(GLfloat u);
GLAPI PFNGLEVALCOORD1FPROC cppgl_glEvalCoord1f;
#define glEvalCoord1f cppgl_glEvalCoord1f
typedef void (APIENTRYP PFNGLEVALCOORD1FVPROC)(const GLfloat *u);
GLAPI PFNGLEVALCOORD1FVPROC cppgl_glEvalCoord1fv;
#define glEvalCoord1fv cppgl_glEvalCoord1fv
typedef void (APIENTRYP PFNGLEVALCOORD2DPROC)(GLdouble u, GLdouble v);
GLAPI PFNGLEVALCOORD2DPROC cppgl_glEvalCoord2d;
#define glEvalCoord2d cppgl_glEvalCoord2d
typedef void (APIENTRYP PFNGLEVALCOORD2DVPROC)(const GLdouble *u);
GLAPI PFNGLEVALCOORD2DVPROC cppgl_glEvalCoord2dv;
#define glEvalCoord2dv cppgl_glEvalCoord2dv
typedef void (APIENTRYP PFNGLEVALCOORD2FPROC)(GLfloat u, GLfloat v);
GLAPI PFNGLEVALCOORD2FPROC cppgl_glEvalCoord2f;
#define glEvalCoord2f cppgl_glEvalCoord2f
typedef void (APIENTRYP PFNGLEVALCOORD2FVPROC)(const GLfloat *u);
GLAPI PFNGLEVALCOORD2FVPROC cppgl_glEvalCoord2fv;
#define glEvalCoord2fv cppgl_glEvalCoord2fv
typedef void (APIENTRYP PFNGLEVALMESH1PROC)(GLenum mode, GLint i1, GLint i2);
GLAPI PFNGLEVALMESH1PROC cppgl_glEvalMesh1;
#define glEvalMesh1 cppgl_glEvalMesh1
typedef void (APIENTRYP PFNGLEVALPOINT1PROC)(GLint i);
GLAPI PFNGLEVALPOINT1PROC cppgl_glEvalPoint1;
#define glEvalPoint1 cppgl_glEvalPoint1
typedef void (APIENTRYP PFNGLEVALMESH2PROC)(GLenum mode, GLint i1, GLint i2, GLint j1, GLint j2);
GLAPI PFNGLEVALMESH2PROC cppgl_glEvalMesh2;
#define glEvalMesh2 cppgl_glEvalMesh2
typedef void (APIENTRYP PFNGLEVALPOINT2PROC)(GLint i, GLint j);
GLAPI PFNGLEVALPOINT2PROC cppgl_glEvalPoint2;
#define glEvalPoint2 cppgl_glEvalPoint2
typedef void (APIENTRYP PFNGLALPHAFUNCPROC)(GLenum func, GLfloat ref);
GLAPI PFNGLALPHAFUNCPROC cppgl_glAlphaFunc;
#define glAlphaFunc cppgl_glAlphaFunc
typedef void (APIENTRYP PFNGLPIXELZOOMPROC)(GLfloat xfactor, GLfloat yfactor);
GLAPI PFNGLPIXELZOOMPROC cppgl_glPixelZoom;
#define glPixelZoom cppgl_glPixelZoom
typedef void (APIENTRYP PFNGLPIXELTRANSFERFPROC)(GLenum pname, GLfloat param);
GLAPI PFNGLPIXELTRANSFERFPROC cppgl_glPixelTransferf;
#define glPixelTransferf cppgl_glPixelTransferf
typedef void (APIENTRYP PFNGLPIXELTRANSFERIPROC)(GLenum pname, GLint param);
GLAPI PFNGLPIXELTRANSFERIPROC cppgl_glPixelTransferi;
#define glPixelTransferi cppgl_glPixelTransferi
typedef void (APIENTRYP PFNGLPIXELMAPFVPROC)(GLenum map, GLsizei mapsize, const GLfloat *values);
GLAPI PFNGLPIXELMAPFVPROC cppgl_glPixelMapfv;
#define glPixelMapfv cppgl_glPixelMapfv
typedef void (APIENTRYP PFNGLPIXELMAPUIVPROC)(GLenum map, GLsizei mapsize, const GLuint *values);
GLAPI PFNGLPIXELMAPUIVPROC cppgl_glPixelMapuiv;
#define glPixelMapuiv cppgl_glPixelMapuiv
typedef void (APIENTRYP PFNGLPIXELMAPUSVPROC)(GLenum map, GLsizei mapsize, const GLushort *values);
GLAPI PFNGLPIXELMAPUSVPROC cppgl_glPixelMapusv;
#define glPixelMapusv cppgl_glPixelMapusv
typedef void (APIENTRYP PFNGLCOPYPIXELSPROC)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum type);
GLAPI PFNGLCOPYPIXELSPROC cppgl_glCopyPixels;
#define glCopyPixels cppgl_glCopyPixels
typedef void (APIENTRYP PFNGLDRAWPIXELSPROC)(GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
GLAPI PFNGLDRAWPIXELSPROC cppgl_glDrawPixels;
#define glDrawPixels cppgl_glDrawPixels
typedef void (APIENTRYP PFNGLGETCLIPPLANEPROC)(GLenum plane, GLdouble *equation);
GLAPI PFNGLGETCLIPPLANEPROC cppgl_glGetClipPlane;
#define glGetClipPlane cppgl_glGetClipPlane
typedef void (APIENTRYP PFNGLGETLIGHTFVPROC)(GLenum light, GLenum pname, GLfloat *params);
GLAPI PFNGLGETLIGHTFVPROC cppgl_glGetLightfv;
#define glGetLightfv cppgl_glGetLightfv
typedef void (APIENTRYP PFNGLGETLIGHTIVPROC)(GLenum light, GLenum pname, GLint *params);
GLAPI PFNGLGETLIGHTIVPROC cppgl_glGetLightiv;
#define glGetLightiv cppgl_glGetLightiv
typedef void (APIENTRYP PFNGLGETMAPDVPROC)(GLenum target, GLenum query, GLdouble *v);
GLAPI PFNGLGETMAPDVPROC cppgl_glGetMapdv;
#define glGetMapdv cppgl_glGetMapdv
typedef void (APIENTRYP PFNGLGETMAPFVPROC)(GLenum target, GLenum query, GLfloat *v);
GLAPI PFNGLGETMAPFVPROC cppgl_glGetMapfv;
#define glGetMapfv cppgl_glGetMapfv
typedef void (APIENTRYP PFNGLGETMAPIVPROC)(GLenum target, GLenum query, GLint *v);
GLAPI PFNGLGETMAPIVPROC cppgl_glGetMapiv;
#define glGetMapiv cppgl_glGetMapiv
typedef void (APIENTRYP PFNGLGETMATERIALFVPROC)(GLenum face, GLenum pname, GLfloat *params);
GLAPI PFNGLGETMATERIALFVPROC cppgl_glGetMaterialfv;
#define glGetMaterialfv cppgl_glGetMaterialfv
typedef void (APIENTRYP PFNGLGETMATERIALIVPROC)(GLenum face, GLenum pname, GLint *params);
GLAPI PFNGLGETMATERIALIVPROC cppgl_glGetMaterialiv;
#define glGetMaterialiv cppgl_glGetMaterialiv
typedef void (APIENTRYP PFNGLGETPIXELMAPFVPROC)(GLenum map, GLfloat *values);
GLAPI PFNGLGETPIXELMAPFVPROC cppgl_glGetPixelMapfv;
#define glGetPixelMapfv cppgl_glGetPixelMapfv
typedef void (APIENTRYP PFNGLGETPIXELMAPUIVPROC)(GLenum map, GLuint *values);
GLAPI PFNGLGETPIXELMAPUIVPROC cppgl_glGetPixelMapuiv;
#define glGetPixelMapuiv cppgl_glGetPixelMapuiv
typedef void (APIENTRYP PFNGLGETPIXELMAPUSVPROC)(GLenum map, GLushort *values);
GLAPI PFNGLGETPIXELMAPUSVPROC cppgl_glGetPixelMapusv;
#define glGetPixelMapusv cppgl_glGetPixelMapusv
typedef void (APIENTRYP PFNGLGETPOLYGONSTIPPLEPROC)(GLubyte *mask);
GLAPI PFNGLGETPOLYGONSTIPPLEPROC cppgl_glGetPolygonStipple;
#define glGetPolygonStipple cppgl_glGetPolygonStipple
typedef void (APIENTRYP PFNGLGETTEXENVFVPROC)(GLenum target, GLenum pname, GLfloat *params);
GLAPI PFNGLGETTEXENVFVPROC cppgl_glGetTexEnvfv;
#define glGetTexEnvfv cppgl_glGetTexEnvfv
typedef void (APIENTRYP PFNGLGETTEXENVIVPROC)(GLenum target, GLenum pname, GLint *params);
GLAPI PFNGLGETTEXENVIVPROC cppgl_glGetTexEnviv;
#define glGetTexEnviv cppgl_glGetTexEnviv
typedef void (APIENTRYP PFNGLGETTEXGENDVPROC)(GLenum coord, GLenum pname, GLdouble *params);
GLAPI PFNGLGETTEXGENDVPROC cppgl_glGetTexGendv;
#define glGetTexGendv cppgl_glGetTexGendv
typedef void (APIENTRYP PFNGLGETTEXGENFVPROC)(GLenum coord, GLenum pname, GLfloat *params);
GLAPI PFNGLGETTEXGENFVPROC cppgl_glGetTexGenfv;
#define glGetTexGenfv cppgl_glGetTexGenfv
typedef void (APIENTRYP PFNGLGETTEXGENIVPROC)(GLenum coord, GLenum pname, GLint *params);
GLAPI PFNGLGETTEXGENIVPROC cppgl_glGetTexGeniv;
#define glGetTexGeniv cppgl_glGetTexGeniv
typedef GLboolean (APIENTRYP PFNGLISLISTPROC)(GLuint list);
GLAPI PFNGLISLISTPROC cppgl_glIsList;
#define glIsList cppgl_glIsList
typedef void (APIENTRYP PFNGLFRUSTUMPROC)(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
GLAPI PFNGLFRUSTUMPROC cppgl_glFrustum;
#define glFrustum cppgl_glFrustum
typedef void (APIENTRYP PFNGLLOADIDENTITYPROC)();
GLAPI PFNGLLOADIDENTITYPROC cppgl_glLoadIdentity;
#define glLoadIdentity cppgl_glLoadIdentity
typedef void (APIENTRYP PFNGLLOADMATRIXFPROC)(const GLfloat *m);
GLAPI PFNGLLOADMATRIXFPROC cppgl_glLoadMatrixf;
#define glLoadMatrixf cppgl_glLoadMatrixf
typedef void (APIENTRYP PFNGLLOADMATRIXDPROC)(const GLdouble *m);
GLAPI PFNGLLOADMATRIXDPROC cppgl_glLoadMatrixd;
#define glLoadMatrixd cppgl_glLoadMatrixd
typedef void (APIENTRYP PFNGLMATRIXMODEPROC)(GLenum mode);
GLAPI PFNGLMATRIXMODEPROC cppgl_glMatrixMode;
#define glMatrixMode cppgl_glMatrixMode
typedef void (APIENTRYP PFNGLMULTMATRIXFPROC)(const GLfloat *m);
GLAPI PFNGLMULTMATRIXFPROC cppgl_glMultMatrixf;
#define glMultMatrixf cppgl_glMultMatrixf
typedef void (APIENTRYP PFNGLMULTMATRIXDPROC)(const GLdouble *m);
GLAPI PFNGLMULTMATRIXDPROC cppgl_glMultMatrixd;
#define glMultMatrixd cppgl_glMultMatrixd
typedef void (APIENTRYP PFNGLORTHOPROC)(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
GLAPI PFNGLORTHOPROC cppgl_glOrtho;
#define glOrtho cppgl_glOrtho
typedef void (APIENTRYP PFNGLPOPMATRIXPROC)();
GLAPI PFNGLPOPMATRIXPROC cppgl_glPopMatrix;
#define glPopMatrix cppgl_glPopMatrix
typedef void (APIENTRYP PFNGLPUSHMATRIXPROC)();
GLAPI PFNGLPUSHMATRIXPROC cppgl_glPushMatrix;
#define glPushMatrix cppgl_glPushMatrix
typedef void (APIENTRYP PFNGLROTATEDPROC)(GLdouble angle, GLdouble x, GLdouble y, GLdouble z);
GLAPI PFNGLROTATEDPROC cppgl_glRotated;
#define glRotated cppgl_glRotated
typedef void (APIENTRYP PFNGLROTATEFPROC)(GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
GLAPI PFNGLROTATEFPROC cppgl_glRotatef;
#define glRotatef cppgl_glRotatef
typedef void (APIENTRYP PFNGLSCALEDPROC)(GLdouble x, GLdouble y, GLdouble z);
GLAPI PFNGLSCALEDPROC cppgl_glScaled;
#define glScaled cppgl_glScaled
typedef void (APIENTRYP PFNGLSCALEFPROC)(GLfloat x, GLfloat y, GLfloat z);
GLAPI PFNGLSCALEFPROC cppgl_glScalef;
#define glScalef cppgl_glScalef
typedef void (APIENTRYP PFNGLTRANSLATEDPROC)(GLdouble x, GLdouble y, GLdouble z);
GLAPI PFNGLTRANSLATEDPROC cppgl_glTranslated;
#define glTranslated cppgl_glTranslated
typedef void (APIENTRYP PFNGLTRANSLATEFPROC)(GLfloat x, GLfloat y, GLfloat z);
GLAPI PFNGLTRANSLATEFPROC cppgl_glTranslatef;
#define glTranslatef cppgl_glTranslatef
#endif
#ifndef GL_VERSION_1_1
#define GL_VERSION_1_1 1
GLAPI int CPPGL_GL_VERSION_1_1;
typedef void (APIENTRYP PFNGLDRAWARRAYSPROC)(GLenum mode, GLint first, GLsizei count);
GLAPI PFNGLDRAWARRAYSPROC cppgl_glDrawArrays;
#define glDrawArrays cppgl_glDrawArrays
typedef void (APIENTRYP PFNGLDRAWELEMENTSPROC)(GLenum mode, GLsizei count, GLenum type, const void *indices);
GLAPI PFNGLDRAWELEMENTSPROC cppgl_glDrawElements;
#define glDrawElements cppgl_glDrawElements
typedef void (APIENTRYP PFNGLGETPOINTERVPROC)(GLenum pname, void **params);
GLAPI PFNGLGETPOINTERVPROC cppgl_glGetPointerv;
#define glGetPointerv cppgl_glGetPointerv
typedef void (APIENTRYP PFNGLPOLYGONOFFSETPROC)(GLfloat factor, GLfloat units);
GLAPI PFNGLPOLYGONOFFSETPROC cppgl_glPolygonOffset;
#define glPolygonOffset cppgl_glPolygonOffset
typedef void (APIENTRYP PFNGLCOPYTEXIMAGE1DPROC)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
GLAPI PFNGLCOPYTEXIMAGE1DPROC cppgl_glCopyTexImage1D;
#define glCopyTexImage1D cppgl_glCopyTexImage1D
typedef void (APIENTRYP PFNGLCOPYTEXIMAGE2DPROC)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
GLAPI PFNGLCOPYTEXIMAGE2DPROC cppgl_glCopyTexImage2D;
#define glCopyTexImage2D cppgl_glCopyTexImage2D
typedef void (APIENTRYP PFNGLCOPYTEXSUBIMAGE1DPROC)(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
GLAPI PFNGLCOPYTEXSUBIMAGE1DPROC cppgl_glCopyTexSubImage1D;
#define glCopyTexSubImage1D cppgl_glCopyTexSubImage1D
typedef void (APIENTRYP PFNGLCOPYTEXSUBIMAGE2DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
GLAPI PFNGLCOPYTEXSUBIMAGE2DPROC cppgl_glCopyTexSubImage2D;
#define glCopyTexSubImage2D cppgl_glCopyTexSubImage2D
typedef void (APIENTRYP PFNGLTEXSUBIMAGE1DPROC)(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels);
GLAPI PFNGLTEXSUBIMAGE1DPROC cppgl_glTexSubImage1D;
#define glTexSubImage1D cppgl_glTexSubImage1D
typedef void (APIENTRYP PFNGLTEXSUBIMAGE2DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
GLAPI PFNGLTEXSUBIMAGE2DPROC cppgl_glTexSubImage2D;
#define glTexSubImage2D cppgl_glTexSubImage2D
typedef void (APIENTRYP PFNGLBINDTEXTUREPROC)(GLenum target, GLuint texture);
GLAPI PFNGLBINDTEXTUREPROC cppgl_glBindTexture;
#define glBindTexture cppgl_glBindTexture
typedef void (APIENTRYP PFNGLDELETETEXTURESPROC)(GLsizei n, const GLuint *textures);
GLAPI PFNGLDELETETEXTURESPROC cppgl_glDeleteTextures;
#define glDeleteTextures cppgl_glDeleteTextures
typedef void (APIENTRYP PFNGLGENTEXTURESPROC)(GLsizei n, GLuint *textures);
GLAPI PFNGLGENTEXTURESPROC cppgl_glGenTextures;
#define glGenTextures cppgl_glGenTextures
typedef GLboolean (APIENTRYP PFNGLISTEXTUREPROC)(GLuint texture);
GLAPI PFNGLISTEXTUREPROC cppgl_glIsTexture;
#define glIsTexture cppgl_glIsTexture
typedef void (APIENTRYP PFNGLARRAYELEMENTPROC)(GLint i);
GLAPI PFNGLARRAYELEMENTPROC cppgl_glArrayElement;
#define glArrayElement cppgl_glArrayElement
typedef void (APIENTRYP PFNGLCOLORPOINTERPROC)(GLint size, GLenum type, GLsizei stride, const void *pointer);
GLAPI PFNGLCOLORPOINTERPROC cppgl_glColorPointer;
#define glColorPointer cppgl_glColorPointer
typedef void (APIENTRYP PFNGLDISABLECLIENTSTATEPROC)(GLenum array);
GLAPI PFNGLDISABLECLIENTSTATEPROC cppgl_glDisableClientState;
#define glDisableClientState cppgl_glDisableClientState
typedef void (APIENTRYP PFNGLEDGEFLAGPOINTERPROC)(GLsizei stride, const void *pointer);
GLAPI PFNGLEDGEFLAGPOINTERPROC cppgl_glEdgeFlagPointer;
#define glEdgeFlagPointer cppgl_glEdgeFlagPointer
typedef void (APIENTRYP PFNGLENABLECLIENTSTATEPROC)(GLenum array);
GLAPI PFNGLENABLECLIENTSTATEPROC cppgl_glEnableClientState;
#define glEnableClientState cppgl_glEnableClientState
typedef void (APIENTRYP PFNGLINDEXPOINTERPROC)(GLenum type, GLsizei stride, const void *pointer);
GLAPI PFNGLINDEXPOINTERPROC cppgl_glIndexPointer;
#define glIndexPointer cppgl_glIndexPointer
typedef void (APIENTRYP PFNGLINTERLEAVEDARRAYSPROC)(GLenum format, GLsizei stride, const void *pointer);
GLAPI PFNGLINTERLEAVEDARRAYSPROC cppgl_glInterleavedArrays;
#define glInterleavedArrays cppgl_glInterleavedArrays
typedef void (APIENTRYP PFNGLNORMALPOINTERPROC)(GLenum type, GLsizei stride, const void *pointer);
GLAPI PFNGLNORMALPOINTERPROC cppgl_glNormalPointer;
#define glNormalPointer cppgl_glNormalPointer
typedef void (APIENTRYP PFNGLTEXCOORDPOINTERPROC)(GLint size, GLenum type, GLsizei stride, const void *pointer);
GLAPI PFNGLTEXCOORDPOINTERPROC cppgl_glTexCoordPointer;
#define glTexCoordPointer cppgl_glTexCoordPointer
typedef void (APIENTRYP PFNGLVERTEXPOINTERPROC)(GLint size, GLenum type, GLsizei stride, const void *pointer);
GLAPI PFNGLVERTEXPOINTERPROC cppgl_glVertexPointer;
#define glVertexPointer cppgl_glVertexPointer
typedef GLboolean (APIENTRYP PFNGLARETEXTURESRESIDENTPROC)(GLsizei n, const GLuint *textures, GLboolean *residences);
GLAPI PFNGLARETEXTURESRESIDENTPROC cppgl_glAreTexturesResident;
#define glAreTexturesResident cppgl_glAreTexturesResident
typedef void (APIENTRYP PFNGLPRIORITIZETEXTURESPROC)(GLsizei n, const GLuint *textures, const GLfloat *priorities);
GLAPI PFNGLPRIORITIZETEXTURESPROC cppgl_glPrioritizeTextures;
#define glPrioritizeTextures cppgl_glPrioritizeTextures
typedef void (APIENTRYP PFNGLINDEXUBPROC)(GLubyte c);
GLAPI PFNGLINDEXUBPROC cppgl_glIndexub;
#define glIndexub cppgl_glIndexub
typedef void (APIENTRYP PFNGLINDEXUBVPROC)(const GLubyte *c);
GLAPI PFNGLINDEXUBVPROC cppgl_glIndexubv;
#define glIndexubv cppgl_glIndexubv
typedef void (APIENTRYP PFNGLPOPCLIENTATTRIBPROC)();
GLAPI PFNGLPOPCLIENTATTRIBPROC cppgl_glPopClientAttrib;
#define glPopClientAttrib cppgl_glPopClientAttrib
typedef void (APIENTRYP PFNGLPUSHCLIENTATTRIBPROC)(GLbitfield mask);
GLAPI PFNGLPUSHCLIENTATTRIBPROC cppgl_glPushClientAttrib;
#define glPushClientAttrib cppgl_glPushClientAttrib
#endif
#ifndef GL_VERSION_1_2
#define GL_VERSION_1_2 1
GLAPI int CPPGL_GL_VERSION_1_2;
typedef void (APIENTRYP PFNGLDRAWRANGEELEMENTSPROC)(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices);
GLAPI PFNGLDRAWRANGEELEMENTSPROC cppgl_glDrawRangeElements;
#define glDrawRangeElements cppgl_glDrawRangeElements
typedef void (APIENTRYP PFNGLTEXIMAGE3DPROC)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels);
GLAPI PFNGLTEXIMAGE3DPROC cppgl_glTexImage3D;
#define glTexImage3D cppgl_glTexImage3D
typedef void (APIENTRYP PFNGLTEXSUBIMAGE3DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels);
GLAPI PFNGLTEXSUBIMAGE3DPROC cppgl_glTexSubImage3D;
#define glTexSubImage3D cppgl_glTexSubImage3D
typedef void (APIENTRYP PFNGLCOPYTEXSUBIMAGE3DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
GLAPI PFNGLCOPYTEXSUBIMAGE3DPROC cppgl_glCopyTexSubImage3D;
#define glCopyTexSubImage3D cppgl_glCopyTexSubImage3D
#endif
#define GL_MULTISAMPLE_3DFX 0x86B2
#define GL_SAMPLE_BUFFERS_3DFX 0x86B3
#define GL_SAMPLES_3DFX 0x86B4
#define GL_MULTISAMPLE_BIT_3DFX 0x20000000
#define GL_COMPRESSED_RGB_FXT1_3DFX 0x86B0
#define GL_COMPRESSED_RGBA_FXT1_3DFX 0x86B1
#define GL_FACTOR_MIN_AMD 0x901C
#define GL_FACTOR_MAX_AMD 0x901D
#define GL_MAX_DEBUG_MESSAGE_LENGTH_AMD 0x9143
#define GL_MAX_DEBUG_LOGGED_MESSAGES_AMD 0x9144
#define GL_DEBUG_LOGGED_MESSAGES_AMD 0x9145
#define GL_DEBUG_SEVERITY_HIGH_AMD 0x9146
#define GL_DEBUG_SEVERITY_MEDIUM_AMD 0x9147
#define GL_DEBUG_SEVERITY_LOW_AMD 0x9148
#define GL_DEBUG_CATEGORY_API_ERROR_AMD 0x9149
#define GL_DEBUG_CATEGORY_WINDOW_SYSTEM_AMD 0x914A
#define GL_DEBUG_CATEGORY_DEPRECATION_AMD 0x914B
#define GL_DEBUG_CATEGORY_UNDEFINED_BEHAVIOR_AMD 0x914C
#define GL_DEBUG_CATEGORY_PERFORMANCE_AMD 0x914D
#define GL_DEBUG_CATEGORY_SHADER_COMPILER_AMD 0x914E
#define GL_DEBUG_CATEGORY_APPLICATION_AMD 0x914F
#define GL_DEBUG_CATEGORY_OTHER_AMD 0x9150
#define GL_DEPTH_CLAMP_NEAR_AMD 0x901E
#define GL_DEPTH_CLAMP_FAR_AMD 0x901F
#define GL_FLOAT16_NV 0x8FF8
#define GL_FLOAT16_VEC2_NV 0x8FF9
#define GL_FLOAT16_VEC3_NV 0x8FFA
#define GL_FLOAT16_VEC4_NV 0x8FFB
#define GL_FLOAT16_MAT2_AMD 0x91C5
#define GL_FLOAT16_MAT3_AMD 0x91C6
#define GL_FLOAT16_MAT4_AMD 0x91C7
#define GL_FLOAT16_MAT2x3_AMD 0x91C8
#define GL_FLOAT16_MAT2x4_AMD 0x91C9
#define GL_FLOAT16_MAT3x2_AMD 0x91CA
#define GL_FLOAT16_MAT3x4_AMD 0x91CB
#define GL_FLOAT16_MAT4x2_AMD 0x91CC
#define GL_FLOAT16_MAT4x3_AMD 0x91CD
#define GL_INT64_NV 0x140E
#define GL_UNSIGNED_INT64_NV 0x140F
#define GL_INT8_NV 0x8FE0
#define GL_INT8_VEC2_NV 0x8FE1
#define GL_INT8_VEC3_NV 0x8FE2
#define GL_INT8_VEC4_NV 0x8FE3
#define GL_INT16_NV 0x8FE4
#define GL_INT16_VEC2_NV 0x8FE5
#define GL_INT16_VEC3_NV 0x8FE6
#define GL_INT16_VEC4_NV 0x8FE7
#define GL_INT64_VEC2_NV 0x8FE9
#define GL_INT64_VEC3_NV 0x8FEA
#define GL_INT64_VEC4_NV 0x8FEB
#define GL_UNSIGNED_INT8_NV 0x8FEC
#define GL_UNSIGNED_INT8_VEC2_NV 0x8FED
#define GL_UNSIGNED_INT8_VEC3_NV 0x8FEE
#define GL_UNSIGNED_INT8_VEC4_NV 0x8FEF
#define GL_UNSIGNED_INT16_NV 0x8FF0
#define GL_UNSIGNED_INT16_VEC2_NV 0x8FF1
#define GL_UNSIGNED_INT16_VEC3_NV 0x8FF2
#define GL_UNSIGNED_INT16_VEC4_NV 0x8FF3
#define GL_UNSIGNED_INT64_VEC2_NV 0x8FF5
#define GL_UNSIGNED_INT64_VEC3_NV 0x8FF6
#define GL_UNSIGNED_INT64_VEC4_NV 0x8FF7
#define GL_VERTEX_ELEMENT_SWIZZLE_AMD 0x91A4
#define GL_VERTEX_ID_SWIZZLE_AMD 0x91A5
#define GL_RG8UI 0x8238
#define GL_RG16UI 0x823A
#define GL_RGBA8UI 0x8D7C
#define GL_DATA_BUFFER_AMD 0x9151
#define GL_PERFORMANCE_MONITOR_AMD 0x9152
#define GL_QUERY_OBJECT_AMD 0x9153
#define GL_VERTEX_ARRAY_OBJECT_AMD 0x9154
#define GL_SAMPLER_OBJECT_AMD 0x9155
#define GL_OCCLUSION_QUERY_EVENT_MASK_AMD 0x874F
#define GL_QUERY_DEPTH_PASS_EVENT_BIT_AMD 0x00000001
#define GL_QUERY_DEPTH_FAIL_EVENT_BIT_AMD 0x00000002
#define GL_QUERY_STENCIL_FAIL_EVENT_BIT_AMD 0x00000004
#define GL_QUERY_DEPTH_BOUNDS_FAIL_EVENT_BIT_AMD 0x00000008
#define GL_QUERY_ALL_EVENT_BITS_AMD 0xFFFFFFFF
#define GL_COUNTER_TYPE_AMD 0x8BC0
#define GL_COUNTER_RANGE_AMD 0x8BC1
#define GL_UNSIGNED_INT64_AMD 0x8BC2
#define GL_PERCENTAGE_AMD 0x8BC3
#define GL_PERFMON_RESULT_AVAILABLE_AMD 0x8BC4
#define GL_PERFMON_RESULT_SIZE_AMD 0x8BC5
#define GL_PERFMON_RESULT_AMD 0x8BC6
#define GL_EXTERNAL_VIRTUAL_MEMORY_BUFFER_AMD 0x9160
#define GL_QUERY_BUFFER_AMD 0x9192
#define GL_QUERY_BUFFER_BINDING_AMD 0x9193
#define GL_QUERY_RESULT_NO_WAIT_AMD 0x9194
#define GL_SUBSAMPLE_DISTANCE_AMD 0x883F
#define GL_TEXTURE_CUBE_MAP_SEAMLESS 0x884F
#define GL_VIRTUAL_PAGE_SIZE_X_AMD 0x9195
#define GL_VIRTUAL_PAGE_SIZE_Y_AMD 0x9196
#define GL_VIRTUAL_PAGE_SIZE_Z_AMD 0x9197
#define GL_MAX_SPARSE_TEXTURE_SIZE_AMD 0x9198
#define GL_MAX_SPARSE_3D_TEXTURE_SIZE_AMD 0x9199
#define GL_MAX_SPARSE_ARRAY_TEXTURE_LAYERS 0x919A
#define GL_MIN_SPARSE_LEVEL_AMD 0x919B
#define GL_MIN_LOD_WARNING_AMD 0x919C
#define GL_TEXTURE_STORAGE_SPARSE_BIT_AMD 0x00000001
#define GL_SET_AMD 0x874A
#define GL_REPLACE_VALUE_AMD 0x874B
#define GL_STENCIL_OP_VALUE_AMD 0x874C
#define GL_STENCIL_BACK_OP_VALUE_AMD 0x874D
#define GL_STREAM_RASTERIZATION_AMD 0x91A0
#define GL_SAMPLER_BUFFER_AMD 0x9001
#define GL_INT_SAMPLER_BUFFER_AMD 0x9002
#define GL_UNSIGNED_INT_SAMPLER_BUFFER_AMD 0x9003
#define GL_TESSELLATION_MODE_AMD 0x9004
#define GL_TESSELLATION_FACTOR_AMD 0x9005
#define GL_DISCRETE_AMD 0x9006
#define GL_CONTINUOUS_AMD 0x9007
#define GL_AUX_DEPTH_STENCIL_APPLE 0x8A14
#define GL_UNPACK_CLIENT_STORAGE_APPLE 0x85B2
#define GL_ELEMENT_ARRAY_APPLE 0x8A0C
#define GL_ELEMENT_ARRAY_TYPE_APPLE 0x8A0D
#define GL_ELEMENT_ARRAY_POINTER_APPLE 0x8A0E
#define GL_DRAW_PIXELS_APPLE 0x8A0A
#define GL_FENCE_APPLE 0x8A0B
#define GL_HALF_APPLE 0x140B
#define GL_RGBA_FLOAT32_APPLE 0x8814
#define GL_RGB_FLOAT32_APPLE 0x8815
#define GL_ALPHA_FLOAT32_APPLE 0x8816
#define GL_INTENSITY_FLOAT32_APPLE 0x8817
#define GL_LUMINANCE_FLOAT32_APPLE 0x8818
#define GL_LUMINANCE_ALPHA_FLOAT32_APPLE 0x8819
#define GL_RGBA_FLOAT16_APPLE 0x881A
#define GL_RGB_FLOAT16_APPLE 0x881B
#define GL_ALPHA_FLOAT16_APPLE 0x881C
#define GL_INTENSITY_FLOAT16_APPLE 0x881D
#define GL_LUMINANCE_FLOAT16_APPLE 0x881E
#define GL_LUMINANCE_ALPHA_FLOAT16_APPLE 0x881F
#define GL_COLOR_FLOAT_APPLE 0x8A0F
#define GL_BUFFER_SERIALIZED_MODIFY_APPLE 0x8A12
#define GL_BUFFER_FLUSHING_UNMAP_APPLE 0x8A13
#define GL_BUFFER_OBJECT_APPLE 0x85B3
#define GL_RELEASED_APPLE 0x8A19
#define GL_VOLATILE_APPLE 0x8A1A
#define GL_RETAINED_APPLE 0x8A1B
#define GL_UNDEFINED_APPLE 0x8A1C
#define GL_PURGEABLE_APPLE 0x8A1D
#define GL_RGB_422_APPLE 0x8A1F
#define GL_UNSIGNED_SHORT_8_8_APPLE 0x85BA
#define GL_UNSIGNED_SHORT_8_8_REV_APPLE 0x85BB
#define GL_RGB_RAW_422_APPLE 0x8A51
#define GL_PACK_ROW_BYTES_APPLE 0x8A15
#define GL_UNPACK_ROW_BYTES_APPLE 0x8A16
#define GL_LIGHT_MODEL_SPECULAR_VECTOR_APPLE 0x85B0
#define GL_TEXTURE_RANGE_LENGTH_APPLE 0x85B7
#define GL_TEXTURE_RANGE_POINTER_APPLE 0x85B8
#define GL_TEXTURE_STORAGE_HINT_APPLE 0x85BC
#define GL_STORAGE_PRIVATE_APPLE 0x85BD
#define GL_STORAGE_CACHED_APPLE 0x85BE
#define GL_STORAGE_SHARED_APPLE 0x85BF
#define GL_TRANSFORM_HINT_APPLE 0x85B1
#define GL_VERTEX_ARRAY_BINDING_APPLE 0x85B5
#define GL_VERTEX_ARRAY_RANGE_APPLE 0x851D
#define GL_VERTEX_ARRAY_RANGE_LENGTH_APPLE 0x851E
#define GL_VERTEX_ARRAY_STORAGE_HINT_APPLE 0x851F
#define GL_VERTEX_ARRAY_RANGE_POINTER_APPLE 0x8521
#define GL_STORAGE_CLIENT_APPLE 0x85B4
#define GL_VERTEX_ATTRIB_MAP1_APPLE 0x8A00
#define GL_VERTEX_ATTRIB_MAP2_APPLE 0x8A01
#define GL_VERTEX_ATTRIB_MAP1_SIZE_APPLE 0x8A02
#define GL_VERTEX_ATTRIB_MAP1_COEFF_APPLE 0x8A03
#define GL_VERTEX_ATTRIB_MAP1_ORDER_APPLE 0x8A04
#define GL_VERTEX_ATTRIB_MAP1_DOMAIN_APPLE 0x8A05
#define GL_VERTEX_ATTRIB_MAP2_SIZE_APPLE 0x8A06
#define GL_VERTEX_ATTRIB_MAP2_COEFF_APPLE 0x8A07
#define GL_VERTEX_ATTRIB_MAP2_ORDER_APPLE 0x8A08
#define GL_VERTEX_ATTRIB_MAP2_DOMAIN_APPLE 0x8A09
#define GL_YCBCR_422_APPLE 0x85B9
#define GL_FIXED 0x140C
#define GL_IMPLEMENTATION_COLOR_READ_TYPE 0x8B9A
#define GL_IMPLEMENTATION_COLOR_READ_FORMAT 0x8B9B
#define GL_LOW_FLOAT 0x8DF0
#define GL_MEDIUM_FLOAT 0x8DF1
#define GL_HIGH_FLOAT 0x8DF2
#define GL_LOW_INT 0x8DF3
#define GL_MEDIUM_INT 0x8DF4
#define GL_HIGH_INT 0x8DF5
#define GL_SHADER_COMPILER 0x8DFA
#define GL_SHADER_BINARY_FORMATS 0x8DF8
#define GL_NUM_SHADER_BINARY_FORMATS 0x8DF9
#define GL_MAX_VERTEX_UNIFORM_VECTORS 0x8DFB
#define GL_MAX_VARYING_VECTORS 0x8DFC
#define GL_MAX_FRAGMENT_UNIFORM_VECTORS 0x8DFD
#define GL_RGB565 0x8D62
#define GL_PRIMITIVE_BOUNDING_BOX_ARB 0x92BE
#define GL_MULTISAMPLE_LINE_WIDTH_RANGE_ARB 0x9381
#define GL_MULTISAMPLE_LINE_WIDTH_GRANULARITY_ARB 0x9382
#define GL_COMPRESSED_RGB8_ETC2 0x9274
#define GL_COMPRESSED_SRGB8_ETC2 0x9275
#define GL_COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2 0x9276
#define GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2 0x9277
#define GL_COMPRESSED_RGBA8_ETC2_EAC 0x9278
#define GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC 0x9279
#define GL_COMPRESSED_R11_EAC 0x9270
#define GL_COMPRESSED_SIGNED_R11_EAC 0x9271
#define GL_COMPRESSED_RG11_EAC 0x9272
#define GL_COMPRESSED_SIGNED_RG11_EAC 0x9273
#define GL_PRIMITIVE_RESTART_FIXED_INDEX 0x8D69
#define GL_ANY_SAMPLES_PASSED_CONSERVATIVE 0x8D6A
#define GL_MAX_ELEMENT_INDEX 0x8D6B
#define GL_UNSIGNED_INT64_ARB 0x140F
#define GL_SRC1_COLOR 0x88F9
#define GL_SRC1_ALPHA 0x8589
#define GL_ONE_MINUS_SRC1_COLOR 0x88FA
#define GL_ONE_MINUS_SRC1_ALPHA 0x88FB
#define GL_MAX_DUAL_SOURCE_DRAW_BUFFERS 0x88FC
#define GL_MAP_READ_BIT 0x0001
#define GL_MAP_WRITE_BIT 0x0002
#define GL_MAP_PERSISTENT_BIT 0x0040
#define GL_MAP_COHERENT_BIT 0x0080
#define GL_DYNAMIC_STORAGE_BIT 0x0100
#define GL_CLIENT_STORAGE_BIT 0x0200
#define GL_CLIENT_MAPPED_BUFFER_BARRIER_BIT 0x00004000
#define GL_BUFFER_IMMUTABLE_STORAGE 0x821F
#define GL_BUFFER_STORAGE_FLAGS 0x8220
#define GL_SYNC_CL_EVENT_ARB 0x8240
#define GL_SYNC_CL_EVENT_COMPLETE_ARB 0x8241
#define GL_CLEAR_TEXTURE 0x9365
#define GL_LOWER_LEFT 0x8CA1
#define GL_UPPER_LEFT 0x8CA2
#define GL_NEGATIVE_ONE_TO_ONE 0x935E
#define GL_ZERO_TO_ONE 0x935F
#define GL_CLIP_ORIGIN 0x935C
#define GL_CLIP_DEPTH_MODE 0x935D
#define GL_RGBA_FLOAT_MODE_ARB 0x8820
#define GL_CLAMP_VERTEX_COLOR_ARB 0x891A
#define GL_CLAMP_FRAGMENT_COLOR_ARB 0x891B
#define GL_CLAMP_READ_COLOR_ARB 0x891C
#define GL_FIXED_ONLY_ARB 0x891D
#define GL_UNPACK_COMPRESSED_BLOCK_WIDTH 0x9127
#define GL_UNPACK_COMPRESSED_BLOCK_HEIGHT 0x9128
#define GL_UNPACK_COMPRESSED_BLOCK_DEPTH 0x9129
#define GL_UNPACK_COMPRESSED_BLOCK_SIZE 0x912A
#define GL_PACK_COMPRESSED_BLOCK_WIDTH 0x912B
#define GL_PACK_COMPRESSED_BLOCK_HEIGHT 0x912C
#define GL_PACK_COMPRESSED_BLOCK_DEPTH 0x912D
#define GL_PACK_COMPRESSED_BLOCK_SIZE 0x912E
#define GL_COMPUTE_SHADER 0x91B9
#define GL_MAX_COMPUTE_UNIFORM_BLOCKS 0x91BB
#define GL_MAX_COMPUTE_TEXTURE_IMAGE_UNITS 0x91BC
#define GL_MAX_COMPUTE_IMAGE_UNIFORMS 0x91BD
#define GL_MAX_COMPUTE_SHARED_MEMORY_SIZE 0x8262
#define GL_MAX_COMPUTE_UNIFORM_COMPONENTS 0x8263
#define GL_MAX_COMPUTE_ATOMIC_COUNTER_BUFFERS 0x8264
#define GL_MAX_COMPUTE_ATOMIC_COUNTERS 0x8265
#define GL_MAX_COMBINED_COMPUTE_UNIFORM_COMPONENTS 0x8266
#define GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS 0x90EB
#define GL_MAX_COMPUTE_WORK_GROUP_COUNT 0x91BE
#define GL_MAX_COMPUTE_WORK_GROUP_SIZE 0x91BF
#define GL_COMPUTE_WORK_GROUP_SIZE 0x8267
#define GL_UNIFORM_BLOCK_REFERENCED_BY_COMPUTE_SHADER 0x90EC
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_COMPUTE_SHADER 0x90ED
#define GL_DISPATCH_INDIRECT_BUFFER 0x90EE
#define GL_DISPATCH_INDIRECT_BUFFER_BINDING 0x90EF
#define GL_COMPUTE_SHADER_BIT 0x00000020
#define GL_MAX_COMPUTE_VARIABLE_GROUP_INVOCATIONS_ARB 0x9344
#define GL_MAX_COMPUTE_FIXED_GROUP_INVOCATIONS_ARB 0x90EB
#define GL_MAX_COMPUTE_VARIABLE_GROUP_SIZE_ARB 0x9345
#define GL_MAX_COMPUTE_FIXED_GROUP_SIZE_ARB 0x91BF
#define GL_QUERY_WAIT_INVERTED 0x8E17
#define GL_QUERY_NO_WAIT_INVERTED 0x8E18
#define GL_QUERY_BY_REGION_WAIT_INVERTED 0x8E19
#define GL_QUERY_BY_REGION_NO_WAIT_INVERTED 0x8E1A
#define GL_COPY_READ_BUFFER 0x8F36
#define GL_COPY_WRITE_BUFFER 0x8F37
#define GL_MAX_CULL_DISTANCES 0x82F9
#define GL_MAX_COMBINED_CLIP_AND_CULL_DISTANCES 0x82FA
#define GL_DEBUG_OUTPUT_SYNCHRONOUS_ARB 0x8242
#define GL_DEBUG_NEXT_LOGGED_MESSAGE_LENGTH_ARB 0x8243
#define GL_DEBUG_CALLBACK_FUNCTION_ARB 0x8244
#define GL_DEBUG_CALLBACK_USER_PARAM_ARB 0x8245
#define GL_DEBUG_SOURCE_API_ARB 0x8246
#define GL_DEBUG_SOURCE_WINDOW_SYSTEM_ARB 0x8247
#define GL_DEBUG_SOURCE_SHADER_COMPILER_ARB 0x8248
#define GL_DEBUG_SOURCE_THIRD_PARTY_ARB 0x8249
#define GL_DEBUG_SOURCE_APPLICATION_ARB 0x824A
#define GL_DEBUG_SOURCE_OTHER_ARB 0x824B
#define GL_DEBUG_TYPE_ERROR_ARB 0x824C
#define GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR_ARB 0x824D
#define GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR_ARB 0x824E
#define GL_DEBUG_TYPE_PORTABILITY_ARB 0x824F
#define GL_DEBUG_TYPE_PERFORMANCE_ARB 0x8250
#define GL_DEBUG_TYPE_OTHER_ARB 0x8251
#define GL_MAX_DEBUG_MESSAGE_LENGTH_ARB 0x9143
#define GL_MAX_DEBUG_LOGGED_MESSAGES_ARB 0x9144
#define GL_DEBUG_LOGGED_MESSAGES_ARB 0x9145
#define GL_DEBUG_SEVERITY_HIGH_ARB 0x9146
#define GL_DEBUG_SEVERITY_MEDIUM_ARB 0x9147
#define GL_DEBUG_SEVERITY_LOW_ARB 0x9148
#define GL_DEPTH_COMPONENT32F 0x8CAC
#define GL_DEPTH32F_STENCIL8 0x8CAD
#define GL_FLOAT_32_UNSIGNED_INT_24_8_REV 0x8DAD
#define GL_DEPTH_CLAMP 0x864F
#define GL_DEPTH_COMPONENT16_ARB 0x81A5
#define GL_DEPTH_COMPONENT24_ARB 0x81A6
#define GL_DEPTH_COMPONENT32_ARB 0x81A7
#define GL_TEXTURE_DEPTH_SIZE_ARB 0x884A
#define GL_DEPTH_TEXTURE_MODE_ARB 0x884B
#define GL_TEXTURE_TARGET 0x1006
#define GL_QUERY_TARGET 0x82EA
#define GL_TEXTURE_BINDING_1D_ARRAY 0x8C1C
#define GL_TEXTURE_BINDING_2D_ARRAY 0x8C1D
#define GL_TEXTURE_BINDING_2D_MULTISAMPLE 0x9104
#define GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY 0x9105
#define GL_TEXTURE_BINDING_BUFFER 0x8C2C
#define GL_TEXTURE_BINDING_CUBE_MAP 0x8514
#define GL_TEXTURE_BINDING_CUBE_MAP_ARRAY 0x900A
#define GL_TEXTURE_BINDING_RECTANGLE 0x84F6
#define GL_MAX_DRAW_BUFFERS_ARB 0x8824
#define GL_DRAW_BUFFER0_ARB 0x8825
#define GL_DRAW_BUFFER1_ARB 0x8826
#define GL_DRAW_BUFFER2_ARB 0x8827
#define GL_DRAW_BUFFER3_ARB 0x8828
#define GL_DRAW_BUFFER4_ARB 0x8829
#define GL_DRAW_BUFFER5_ARB 0x882A
#define GL_DRAW_BUFFER6_ARB 0x882B
#define GL_DRAW_BUFFER7_ARB 0x882C
#define GL_DRAW_BUFFER8_ARB 0x882D
#define GL_DRAW_BUFFER9_ARB 0x882E
#define GL_DRAW_BUFFER10_ARB 0x882F
#define GL_DRAW_BUFFER11_ARB 0x8830
#define GL_DRAW_BUFFER12_ARB 0x8831
#define GL_DRAW_BUFFER13_ARB 0x8832
#define GL_DRAW_BUFFER14_ARB 0x8833
#define GL_DRAW_BUFFER15_ARB 0x8834
#define GL_DRAW_INDIRECT_BUFFER 0x8F3F
#define GL_DRAW_INDIRECT_BUFFER_BINDING 0x8F43
#define GL_LOCATION_COMPONENT 0x934A
#define GL_TRANSFORM_FEEDBACK_BUFFER 0x8C8E
#define GL_TRANSFORM_FEEDBACK_BUFFER_INDEX 0x934B
#define GL_TRANSFORM_FEEDBACK_BUFFER_STRIDE 0x934C
#define GL_MAX_UNIFORM_LOCATIONS 0x826E
#define GL_FRAGMENT_PROGRAM_ARB 0x8804
#define GL_PROGRAM_FORMAT_ASCII_ARB 0x8875
#define GL_PROGRAM_LENGTH_ARB 0x8627
#define GL_PROGRAM_FORMAT_ARB 0x8876
#define GL_PROGRAM_BINDING_ARB 0x8677
#define GL_PROGRAM_INSTRUCTIONS_ARB 0x88A0
#define GL_MAX_PROGRAM_INSTRUCTIONS_ARB 0x88A1
#define GL_PROGRAM_NATIVE_INSTRUCTIONS_ARB 0x88A2
#define GL_MAX_PROGRAM_NATIVE_INSTRUCTIONS_ARB 0x88A3
#define GL_PROGRAM_TEMPORARIES_ARB 0x88A4
#define GL_MAX_PROGRAM_TEMPORARIES_ARB 0x88A5
#define GL_PROGRAM_NATIVE_TEMPORARIES_ARB 0x88A6
#define GL_MAX_PROGRAM_NATIVE_TEMPORARIES_ARB 0x88A7
#define GL_PROGRAM_PARAMETERS_ARB 0x88A8
#define GL_MAX_PROGRAM_PARAMETERS_ARB 0x88A9
#define GL_PROGRAM_NATIVE_PARAMETERS_ARB 0x88AA
#define GL_MAX_PROGRAM_NATIVE_PARAMETERS_ARB 0x88AB
#define GL_PROGRAM_ATTRIBS_ARB 0x88AC
#define GL_MAX_PROGRAM_ATTRIBS_ARB 0x88AD
#define GL_PROGRAM_NATIVE_ATTRIBS_ARB 0x88AE
#define GL_MAX_PROGRAM_NATIVE_ATTRIBS_ARB 0x88AF
#define GL_MAX_PROGRAM_LOCAL_PARAMETERS_ARB 0x88B4
#define GL_MAX_PROGRAM_ENV_PARAMETERS_ARB 0x88B5
#define GL_PROGRAM_UNDER_NATIVE_LIMITS_ARB 0x88B6
#define GL_PROGRAM_ALU_INSTRUCTIONS_ARB 0x8805
#define GL_PROGRAM_TEX_INSTRUCTIONS_ARB 0x8806
#define GL_PROGRAM_TEX_INDIRECTIONS_ARB 0x8807
#define GL_PROGRAM_NATIVE_ALU_INSTRUCTIONS_ARB 0x8808
#define GL_PROGRAM_NATIVE_TEX_INSTRUCTIONS_ARB 0x8809
#define GL_PROGRAM_NATIVE_TEX_INDIRECTIONS_ARB 0x880A
#define GL_MAX_PROGRAM_ALU_INSTRUCTIONS_ARB 0x880B
#define GL_MAX_PROGRAM_TEX_INSTRUCTIONS_ARB 0x880C
#define GL_MAX_PROGRAM_TEX_INDIRECTIONS_ARB 0x880D
#define GL_MAX_PROGRAM_NATIVE_ALU_INSTRUCTIONS_ARB 0x880E
#define GL_MAX_PROGRAM_NATIVE_TEX_INSTRUCTIONS_ARB 0x880F
#define GL_MAX_PROGRAM_NATIVE_TEX_INDIRECTIONS_ARB 0x8810
#define GL_PROGRAM_STRING_ARB 0x8628
#define GL_PROGRAM_ERROR_POSITION_ARB 0x864B
#define GL_CURRENT_MATRIX_ARB 0x8641
#define GL_TRANSPOSE_CURRENT_MATRIX_ARB 0x88B7
#define GL_CURRENT_MATRIX_STACK_DEPTH_ARB 0x8640
#define GL_MAX_PROGRAM_MATRICES_ARB 0x862F
#define GL_MAX_PROGRAM_MATRIX_STACK_DEPTH_ARB 0x862E
#define GL_MAX_TEXTURE_COORDS_ARB 0x8871
#define GL_MAX_TEXTURE_IMAGE_UNITS_ARB 0x8872
#define GL_PROGRAM_ERROR_STRING_ARB 0x8874
#define GL_MATRIX0_ARB 0x88C0
#define GL_MATRIX1_ARB 0x88C1
#define GL_MATRIX2_ARB 0x88C2
#define GL_MATRIX3_ARB 0x88C3
#define GL_MATRIX4_ARB 0x88C4
#define GL_MATRIX5_ARB 0x88C5
#define GL_MATRIX6_ARB 0x88C6
#define GL_MATRIX7_ARB 0x88C7
#define GL_MATRIX8_ARB 0x88C8
#define GL_MATRIX9_ARB 0x88C9
#define GL_MATRIX10_ARB 0x88CA
#define GL_MATRIX11_ARB 0x88CB
#define GL_MATRIX12_ARB 0x88CC
#define GL_MATRIX13_ARB 0x88CD
#define GL_MATRIX14_ARB 0x88CE
#define GL_MATRIX15_ARB 0x88CF
#define GL_MATRIX16_ARB 0x88D0
#define GL_MATRIX17_ARB 0x88D1
#define GL_MATRIX18_ARB 0x88D2
#define GL_MATRIX19_ARB 0x88D3
#define GL_MATRIX20_ARB 0x88D4
#define GL_MATRIX21_ARB 0x88D5
#define GL_MATRIX22_ARB 0x88D6
#define GL_MATRIX23_ARB 0x88D7
#define GL_MATRIX24_ARB 0x88D8
#define GL_MATRIX25_ARB 0x88D9
#define GL_MATRIX26_ARB 0x88DA
#define GL_MATRIX27_ARB 0x88DB
#define GL_MATRIX28_ARB 0x88DC
#define GL_MATRIX29_ARB 0x88DD
#define GL_MATRIX30_ARB 0x88DE
#define GL_MATRIX31_ARB 0x88DF
#define GL_FRAGMENT_SHADER_ARB 0x8B30
#define GL_MAX_FRAGMENT_UNIFORM_COMPONENTS_ARB 0x8B49
#define GL_FRAGMENT_SHADER_DERIVATIVE_HINT_ARB 0x8B8B
#define GL_FRAMEBUFFER_DEFAULT_WIDTH 0x9310
#define GL_FRAMEBUFFER_DEFAULT_HEIGHT 0x9311
#define GL_FRAMEBUFFER_DEFAULT_LAYERS 0x9312
#define GL_FRAMEBUFFER_DEFAULT_SAMPLES 0x9313
#define GL_FRAMEBUFFER_DEFAULT_FIXED_SAMPLE_LOCATIONS 0x9314
#define GL_MAX_FRAMEBUFFER_WIDTH 0x9315
#define GL_MAX_FRAMEBUFFER_HEIGHT 0x9316
#define GL_MAX_FRAMEBUFFER_LAYERS 0x9317
#define GL_MAX_FRAMEBUFFER_SAMPLES 0x9318
#define GL_INVALID_FRAMEBUFFER_OPERATION 0x0506
#define GL_FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING 0x8210
#define GL_FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE 0x8211
#define GL_FRAMEBUFFER_ATTACHMENT_RED_SIZE 0x8212
#define GL_FRAMEBUFFER_ATTACHMENT_GREEN_SIZE 0x8213
#define GL_FRAMEBUFFER_ATTACHMENT_BLUE_SIZE 0x8214
#define GL_FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE 0x8215
#define GL_FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE 0x8216
#define GL_FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE 0x8217
#define GL_FRAMEBUFFER_DEFAULT 0x8218
#define GL_FRAMEBUFFER_UNDEFINED 0x8219
#define GL_DEPTH_STENCIL_ATTACHMENT 0x821A
#define GL_MAX_RENDERBUFFER_SIZE 0x84E8
#define GL_DEPTH_STENCIL 0x84F9
#define GL_UNSIGNED_INT_24_8 0x84FA
#define GL_DEPTH24_STENCIL8 0x88F0
#define GL_TEXTURE_STENCIL_SIZE 0x88F1
#define GL_UNSIGNED_NORMALIZED 0x8C17
#define GL_FRAMEBUFFER_BINDING 0x8CA6
#define GL_DRAW_FRAMEBUFFER_BINDING 0x8CA6
#define GL_RENDERBUFFER_BINDING 0x8CA7
#define GL_READ_FRAMEBUFFER 0x8CA8
#define GL_DRAW_FRAMEBUFFER 0x8CA9
#define GL_READ_FRAMEBUFFER_BINDING 0x8CAA
#define GL_RENDERBUFFER_SAMPLES 0x8CAB
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE 0x8CD0
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME 0x8CD1
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL 0x8CD2
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE 0x8CD3
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER 0x8CD4
#define GL_FRAMEBUFFER_COMPLETE 0x8CD5
#define GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT 0x8CD6
#define GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT 0x8CD7
#define GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER 0x8CDB
#define GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER 0x8CDC
#define GL_FRAMEBUFFER_UNSUPPORTED 0x8CDD
#define GL_MAX_COLOR_ATTACHMENTS 0x8CDF
#define GL_COLOR_ATTACHMENT0 0x8CE0
#define GL_COLOR_ATTACHMENT1 0x8CE1
#define GL_COLOR_ATTACHMENT2 0x8CE2
#define GL_COLOR_ATTACHMENT3 0x8CE3
#define GL_COLOR_ATTACHMENT4 0x8CE4
#define GL_COLOR_ATTACHMENT5 0x8CE5
#define GL_COLOR_ATTACHMENT6 0x8CE6
#define GL_COLOR_ATTACHMENT7 0x8CE7
#define GL_COLOR_ATTACHMENT8 0x8CE8
#define GL_COLOR_ATTACHMENT9 0x8CE9
#define GL_COLOR_ATTACHMENT10 0x8CEA
#define GL_COLOR_ATTACHMENT11 0x8CEB
#define GL_COLOR_ATTACHMENT12 0x8CEC
#define GL_COLOR_ATTACHMENT13 0x8CED
#define GL_COLOR_ATTACHMENT14 0x8CEE
#define GL_COLOR_ATTACHMENT15 0x8CEF
#define GL_DEPTH_ATTACHMENT 0x8D00
#define GL_STENCIL_ATTACHMENT 0x8D20
#define GL_FRAMEBUFFER 0x8D40
#define GL_RENDERBUFFER 0x8D41
#define GL_RENDERBUFFER_WIDTH 0x8D42
#define GL_RENDERBUFFER_HEIGHT 0x8D43
#define GL_RENDERBUFFER_INTERNAL_FORMAT 0x8D44
#define GL_STENCIL_INDEX1 0x8D46
#define GL_STENCIL_INDEX4 0x8D47
#define GL_STENCIL_INDEX8 0x8D48
#define GL_STENCIL_INDEX16 0x8D49
#define GL_RENDERBUFFER_RED_SIZE 0x8D50
#define GL_RENDERBUFFER_GREEN_SIZE 0x8D51
#define GL_RENDERBUFFER_BLUE_SIZE 0x8D52
#define GL_RENDERBUFFER_ALPHA_SIZE 0x8D53
#define GL_RENDERBUFFER_DEPTH_SIZE 0x8D54
#define GL_RENDERBUFFER_STENCIL_SIZE 0x8D55
#define GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE 0x8D56
#define GL_MAX_SAMPLES 0x8D57
#define GL_INDEX 0x8222
#define GL_FRAMEBUFFER_SRGB 0x8DB9
#define GL_LINES_ADJACENCY_ARB 0x000A
#define GL_LINE_STRIP_ADJACENCY_ARB 0x000B
#define GL_TRIANGLES_ADJACENCY_ARB 0x000C
#define GL_TRIANGLE_STRIP_ADJACENCY_ARB 0x000D
#define GL_PROGRAM_POINT_SIZE_ARB 0x8642
#define GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS_ARB 0x8C29
#define GL_FRAMEBUFFER_ATTACHMENT_LAYERED_ARB 0x8DA7
#define GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS_ARB 0x8DA8
#define GL_FRAMEBUFFER_INCOMPLETE_LAYER_COUNT_ARB 0x8DA9
#define GL_GEOMETRY_SHADER_ARB 0x8DD9
#define GL_GEOMETRY_VERTICES_OUT_ARB 0x8DDA
#define GL_GEOMETRY_INPUT_TYPE_ARB 0x8DDB
#define GL_GEOMETRY_OUTPUT_TYPE_ARB 0x8DDC
#define GL_MAX_GEOMETRY_VARYING_COMPONENTS_ARB 0x8DDD
#define GL_MAX_VERTEX_VARYING_COMPONENTS_ARB 0x8DDE
#define GL_MAX_GEOMETRY_UNIFORM_COMPONENTS_ARB 0x8DDF
#define GL_MAX_GEOMETRY_OUTPUT_VERTICES_ARB 0x8DE0
#define GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS_ARB 0x8DE1
#define GL_MAX_VARYING_COMPONENTS 0x8B4B
#define GL_PROGRAM_BINARY_RETRIEVABLE_HINT 0x8257
#define GL_PROGRAM_BINARY_LENGTH 0x8741
#define GL_NUM_PROGRAM_BINARY_FORMATS 0x87FE
#define GL_PROGRAM_BINARY_FORMATS 0x87FF
#define GL_GEOMETRY_SHADER_INVOCATIONS 0x887F
#define GL_MAX_GEOMETRY_SHADER_INVOCATIONS 0x8E5A
#define GL_MIN_FRAGMENT_INTERPOLATION_OFFSET 0x8E5B
#define GL_MAX_FRAGMENT_INTERPOLATION_OFFSET 0x8E5C
#define GL_FRAGMENT_INTERPOLATION_OFFSET_BITS 0x8E5D
#define GL_MAX_VERTEX_STREAMS 0x8E71
#define GL_DOUBLE_VEC2 0x8FFC
#define GL_DOUBLE_VEC3 0x8FFD
#define GL_DOUBLE_VEC4 0x8FFE
#define GL_DOUBLE_MAT2 0x8F46
#define GL_DOUBLE_MAT3 0x8F47
#define GL_DOUBLE_MAT4 0x8F48
#define GL_DOUBLE_MAT2x3 0x8F49
#define GL_DOUBLE_MAT2x4 0x8F4A
#define GL_DOUBLE_MAT3x2 0x8F4B
#define GL_DOUBLE_MAT3x4 0x8F4C
#define GL_DOUBLE_MAT4x2 0x8F4D
#define GL_DOUBLE_MAT4x3 0x8F4E
#define GL_INT64_ARB 0x140E
#define GL_INT64_VEC2_ARB 0x8FE9
#define GL_INT64_VEC3_ARB 0x8FEA
#define GL_INT64_VEC4_ARB 0x8FEB
#define GL_UNSIGNED_INT64_VEC2_ARB 0x8FF5
#define GL_UNSIGNED_INT64_VEC3_ARB 0x8FF6
#define GL_UNSIGNED_INT64_VEC4_ARB 0x8FF7
#define GL_HALF_FLOAT_ARB 0x140B
#define GL_HALF_FLOAT 0x140B
#define GL_CONSTANT_COLOR 0x8001
#define GL_ONE_MINUS_CONSTANT_COLOR 0x8002
#define GL_CONSTANT_ALPHA 0x8003
#define GL_ONE_MINUS_CONSTANT_ALPHA 0x8004
#define GL_BLEND_COLOR 0x8005
#define GL_FUNC_ADD 0x8006
#define GL_MIN 0x8007
#define GL_MAX 0x8008
#define GL_BLEND_EQUATION 0x8009
#define GL_FUNC_SUBTRACT 0x800A
#define GL_FUNC_REVERSE_SUBTRACT 0x800B
#define GL_CONVOLUTION_1D 0x8010
#define GL_CONVOLUTION_2D 0x8011
#define GL_SEPARABLE_2D 0x8012
#define GL_CONVOLUTION_BORDER_MODE 0x8013
#define GL_CONVOLUTION_FILTER_SCALE 0x8014
#define GL_CONVOLUTION_FILTER_BIAS 0x8015
#define GL_REDUCE 0x8016
#define GL_CONVOLUTION_FORMAT 0x8017
#define GL_CONVOLUTION_WIDTH 0x8018
#define GL_CONVOLUTION_HEIGHT 0x8019
#define GL_MAX_CONVOLUTION_WIDTH 0x801A
#define GL_MAX_CONVOLUTION_HEIGHT 0x801B
#define GL_POST_CONVOLUTION_RED_SCALE 0x801C
#define GL_POST_CONVOLUTION_GREEN_SCALE 0x801D
#define GL_POST_CONVOLUTION_BLUE_SCALE 0x801E
#define GL_POST_CONVOLUTION_ALPHA_SCALE 0x801F
#define GL_POST_CONVOLUTION_RED_BIAS 0x8020
#define GL_POST_CONVOLUTION_GREEN_BIAS 0x8021
#define GL_POST_CONVOLUTION_BLUE_BIAS 0x8022
#define GL_POST_CONVOLUTION_ALPHA_BIAS 0x8023
#define GL_HISTOGRAM 0x8024
#define GL_PROXY_HISTOGRAM 0x8025
#define GL_HISTOGRAM_WIDTH 0x8026
#define GL_HISTOGRAM_FORMAT 0x8027
#define GL_HISTOGRAM_RED_SIZE 0x8028
#define GL_HISTOGRAM_GREEN_SIZE 0x8029
#define GL_HISTOGRAM_BLUE_SIZE 0x802A
#define GL_HISTOGRAM_ALPHA_SIZE 0x802B
#define GL_HISTOGRAM_LUMINANCE_SIZE 0x802C
#define GL_HISTOGRAM_SINK 0x802D
#define GL_MINMAX 0x802E
#define GL_MINMAX_FORMAT 0x802F
#define GL_MINMAX_SINK 0x8030
#define GL_TABLE_TOO_LARGE 0x8031
#define GL_COLOR_MATRIX 0x80B1
#define GL_COLOR_MATRIX_STACK_DEPTH 0x80B2
#define GL_MAX_COLOR_MATRIX_STACK_DEPTH 0x80B3
#define GL_POST_COLOR_MATRIX_RED_SCALE 0x80B4
#define GL_POST_COLOR_MATRIX_GREEN_SCALE 0x80B5
#define GL_POST_COLOR_MATRIX_BLUE_SCALE 0x80B6
#define GL_POST_COLOR_MATRIX_ALPHA_SCALE 0x80B7
#define GL_POST_COLOR_MATRIX_RED_BIAS 0x80B8
#define GL_POST_COLOR_MATRIX_GREEN_BIAS 0x80B9
#define GL_POST_COLOR_MATRIX_BLUE_BIAS 0x80BA
#define GL_POST_COLOR_MATRIX_ALPHA_BIAS 0x80BB
#define GL_COLOR_TABLE 0x80D0
#define GL_POST_CONVOLUTION_COLOR_TABLE 0x80D1
#define GL_POST_COLOR_MATRIX_COLOR_TABLE 0x80D2
#define GL_PROXY_COLOR_TABLE 0x80D3
#define GL_PROXY_POST_CONVOLUTION_COLOR_TABLE 0x80D4
#define GL_PROXY_POST_COLOR_MATRIX_COLOR_TABLE 0x80D5
#define GL_COLOR_TABLE_SCALE 0x80D6
#define GL_COLOR_TABLE_BIAS 0x80D7
#define GL_COLOR_TABLE_FORMAT 0x80D8
#define GL_COLOR_TABLE_WIDTH 0x80D9
#define GL_COLOR_TABLE_RED_SIZE 0x80DA
#define GL_COLOR_TABLE_GREEN_SIZE 0x80DB
#define GL_COLOR_TABLE_BLUE_SIZE 0x80DC
#define GL_COLOR_TABLE_ALPHA_SIZE 0x80DD
#define GL_COLOR_TABLE_LUMINANCE_SIZE 0x80DE
#define GL_COLOR_TABLE_INTENSITY_SIZE 0x80DF
#define GL_CONSTANT_BORDER 0x8151
#define GL_REPLICATE_BORDER 0x8153
#define GL_CONVOLUTION_BORDER_COLOR 0x8154
#define GL_PARAMETER_BUFFER_ARB 0x80EE
#define GL_PARAMETER_BUFFER_BINDING_ARB 0x80EF
#define GL_VERTEX_ATTRIB_ARRAY_DIVISOR_ARB 0x88FE
#define GL_NUM_SAMPLE_COUNTS 0x9380
#define GL_IMAGE_FORMAT_COMPATIBILITY_TYPE 0x90C7
#define GL_SAMPLES 0x80A9
#define GL_TEXTURE_1D_ARRAY 0x8C18
#define GL_TEXTURE_2D_ARRAY 0x8C1A
#define GL_TEXTURE_CUBE_MAP 0x8513
#define GL_TEXTURE_CUBE_MAP_ARRAY 0x9009
#define GL_TEXTURE_RECTANGLE 0x84F5
#define GL_TEXTURE_BUFFER 0x8C2A
#define GL_TEXTURE_2D_MULTISAMPLE 0x9100
#define GL_TEXTURE_2D_MULTISAMPLE_ARRAY 0x9102
#define GL_TEXTURE_COMPRESSED 0x86A1
#define GL_INTERNALFORMAT_SUPPORTED 0x826F
#define GL_INTERNALFORMAT_PREFERRED 0x8270
#define GL_INTERNALFORMAT_RED_SIZE 0x8271
#define GL_INTERNALFORMAT_GREEN_SIZE 0x8272
#define GL_INTERNALFORMAT_BLUE_SIZE 0x8273
#define GL_INTERNALFORMAT_ALPHA_SIZE 0x8274
#define GL_INTERNALFORMAT_DEPTH_SIZE 0x8275
#define GL_INTERNALFORMAT_STENCIL_SIZE 0x8276
#define GL_INTERNALFORMAT_SHARED_SIZE 0x8277
#define GL_INTERNALFORMAT_RED_TYPE 0x8278
#define GL_INTERNALFORMAT_GREEN_TYPE 0x8279
#define GL_INTERNALFORMAT_BLUE_TYPE 0x827A
#define GL_INTERNALFORMAT_ALPHA_TYPE 0x827B
#define GL_INTERNALFORMAT_DEPTH_TYPE 0x827C
#define GL_INTERNALFORMAT_STENCIL_TYPE 0x827D
#define GL_MAX_WIDTH 0x827E
#define GL_MAX_HEIGHT 0x827F
#define GL_MAX_DEPTH 0x8280
#define GL_MAX_LAYERS 0x8281
#define GL_MAX_COMBINED_DIMENSIONS 0x8282
#define GL_COLOR_COMPONENTS 0x8283
#define GL_DEPTH_COMPONENTS 0x8284
#define GL_STENCIL_COMPONENTS 0x8285
#define GL_COLOR_RENDERABLE 0x8286
#define GL_DEPTH_RENDERABLE 0x8287
#define GL_STENCIL_RENDERABLE 0x8288
#define GL_FRAMEBUFFER_RENDERABLE 0x8289
#define GL_FRAMEBUFFER_RENDERABLE_LAYERED 0x828A
#define GL_FRAMEBUFFER_BLEND 0x828B
#define GL_READ_PIXELS 0x828C
#define GL_READ_PIXELS_FORMAT 0x828D
#define GL_READ_PIXELS_TYPE 0x828E
#define GL_TEXTURE_IMAGE_FORMAT 0x828F
#define GL_TEXTURE_IMAGE_TYPE 0x8290
#define GL_GET_TEXTURE_IMAGE_FORMAT 0x8291
#define GL_GET_TEXTURE_IMAGE_TYPE 0x8292
#define GL_MIPMAP 0x8293
#define GL_MANUAL_GENERATE_MIPMAP 0x8294
#define GL_AUTO_GENERATE_MIPMAP 0x8295
#define GL_COLOR_ENCODING 0x8296
#define GL_SRGB_READ 0x8297
#define GL_SRGB_WRITE 0x8298
#define GL_SRGB_DECODE_ARB 0x8299
#define GL_FILTER 0x829A
#define GL_VERTEX_TEXTURE 0x829B
#define GL_TESS_CONTROL_TEXTURE 0x829C
#define GL_TESS_EVALUATION_TEXTURE 0x829D
#define GL_GEOMETRY_TEXTURE 0x829E
#define GL_FRAGMENT_TEXTURE 0x829F
#define GL_COMPUTE_TEXTURE 0x82A0
#define GL_TEXTURE_SHADOW 0x82A1
#define GL_TEXTURE_GATHER 0x82A2
#define GL_TEXTURE_GATHER_SHADOW 0x82A3
#define GL_SHADER_IMAGE_LOAD 0x82A4
#define GL_SHADER_IMAGE_STORE 0x82A5
#define GL_SHADER_IMAGE_ATOMIC 0x82A6
#define GL_IMAGE_TEXEL_SIZE 0x82A7
#define GL_IMAGE_COMPATIBILITY_CLASS 0x82A8
#define GL_IMAGE_PIXEL_FORMAT 0x82A9
#define GL_IMAGE_PIXEL_TYPE 0x82AA
#define GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST 0x82AC
#define GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST 0x82AD
#define GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE 0x82AE
#define GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE 0x82AF
#define GL_TEXTURE_COMPRESSED_BLOCK_WIDTH 0x82B1
#define GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT 0x82B2
#define GL_TEXTURE_COMPRESSED_BLOCK_SIZE 0x82B3
#define GL_CLEAR_BUFFER 0x82B4
#define GL_TEXTURE_VIEW 0x82B5
#define GL_VIEW_COMPATIBILITY_CLASS 0x82B6
#define GL_FULL_SUPPORT 0x82B7
#define GL_CAVEAT_SUPPORT 0x82B8
#define GL_IMAGE_CLASS_4_X_32 0x82B9
#define GL_IMAGE_CLASS_2_X_32 0x82BA
#define GL_IMAGE_CLASS_1_X_32 0x82BB
#define GL_IMAGE_CLASS_4_X_16 0x82BC
#define GL_IMAGE_CLASS_2_X_16 0x82BD
#define GL_IMAGE_CLASS_1_X_16 0x82BE
#define GL_IMAGE_CLASS_4_X_8 0x82BF
#define GL_IMAGE_CLASS_2_X_8 0x82C0
#define GL_IMAGE_CLASS_1_X_8 0x82C1
#define GL_IMAGE_CLASS_11_11_10 0x82C2
#define GL_IMAGE_CLASS_10_10_10_2 0x82C3
#define GL_VIEW_CLASS_128_BITS 0x82C4
#define GL_VIEW_CLASS_96_BITS 0x82C5
#define GL_VIEW_CLASS_64_BITS 0x82C6
#define GL_VIEW_CLASS_48_BITS 0x82C7
#define GL_VIEW_CLASS_32_BITS 0x82C8
#define GL_VIEW_CLASS_24_BITS 0x82C9
#define GL_VIEW_CLASS_16_BITS 0x82CA
#define GL_VIEW_CLASS_8_BITS 0x82CB
#define GL_VIEW_CLASS_S3TC_DXT1_RGB 0x82CC
#define GL_VIEW_CLASS_S3TC_DXT1_RGBA 0x82CD
#define GL_VIEW_CLASS_S3TC_DXT3_RGBA 0x82CE
#define GL_VIEW_CLASS_S3TC_DXT5_RGBA 0x82CF
#define GL_VIEW_CLASS_RGTC1_RED 0x82D0
#define GL_VIEW_CLASS_RGTC2_RG 0x82D1
#define GL_VIEW_CLASS_BPTC_UNORM 0x82D2
#define GL_VIEW_CLASS_BPTC_FLOAT 0x82D3
#define GL_MIN_MAP_BUFFER_ALIGNMENT 0x90BC
#define GL_MAP_INVALIDATE_RANGE_BIT 0x0004
#define GL_MAP_INVALIDATE_BUFFER_BIT 0x0008
#define GL_MAP_FLUSH_EXPLICIT_BIT 0x0010
#define GL_MAP_UNSYNCHRONIZED_BIT 0x0020
#define GL_MATRIX_PALETTE_ARB 0x8840
#define GL_MAX_MATRIX_PALETTE_STACK_DEPTH_ARB 0x8841
#define GL_MAX_PALETTE_MATRICES_ARB 0x8842
#define GL_CURRENT_PALETTE_MATRIX_ARB 0x8843
#define GL_MATRIX_INDEX_ARRAY_ARB 0x8844
#define GL_CURRENT_MATRIX_INDEX_ARB 0x8845
#define GL_MATRIX_INDEX_ARRAY_SIZE_ARB 0x8846
#define GL_MATRIX_INDEX_ARRAY_TYPE_ARB 0x8847
#define GL_MATRIX_INDEX_ARRAY_STRIDE_ARB 0x8848
#define GL_MATRIX_INDEX_ARRAY_POINTER_ARB 0x8849
#define GL_MULTISAMPLE_ARB 0x809D
#define GL_SAMPLE_ALPHA_TO_COVERAGE_ARB 0x809E
#define GL_SAMPLE_ALPHA_TO_ONE_ARB 0x809F
#define GL_SAMPLE_COVERAGE_ARB 0x80A0
#define GL_SAMPLE_BUFFERS_ARB 0x80A8
#define GL_SAMPLES_ARB 0x80A9
#define GL_SAMPLE_COVERAGE_VALUE_ARB 0x80AA
#define GL_SAMPLE_COVERAGE_INVERT_ARB 0x80AB
#define GL_MULTISAMPLE_BIT_ARB 0x20000000
#define GL_TEXTURE0_ARB 0x84C0
#define GL_TEXTURE1_ARB 0x84C1
#define GL_TEXTURE2_ARB 0x84C2
#define GL_TEXTURE3_ARB 0x84C3
#define GL_TEXTURE4_ARB 0x84C4
#define GL_TEXTURE5_ARB 0x84C5
#define GL_TEXTURE6_ARB 0x84C6
#define GL_TEXTURE7_ARB 0x84C7
#define GL_TEXTURE8_ARB 0x84C8
#define GL_TEXTURE9_ARB 0x84C9
#define GL_TEXTURE10_ARB 0x84CA
#define GL_TEXTURE11_ARB 0x84CB
#define GL_TEXTURE12_ARB 0x84CC
#define GL_TEXTURE13_ARB 0x84CD
#define GL_TEXTURE14_ARB 0x84CE
#define GL_TEXTURE15_ARB 0x84CF
#define GL_TEXTURE16_ARB 0x84D0
#define GL_TEXTURE17_ARB 0x84D1
#define GL_TEXTURE18_ARB 0x84D2
#define GL_TEXTURE19_ARB 0x84D3
#define GL_TEXTURE20_ARB 0x84D4
#define GL_TEXTURE21_ARB 0x84D5
#define GL_TEXTURE22_ARB 0x84D6
#define GL_TEXTURE23_ARB 0x84D7
#define GL_TEXTURE24_ARB 0x84D8
#define GL_TEXTURE25_ARB 0x84D9
#define GL_TEXTURE26_ARB 0x84DA
#define GL_TEXTURE27_ARB 0x84DB
#define GL_TEXTURE28_ARB 0x84DC
#define GL_TEXTURE29_ARB 0x84DD
#define GL_TEXTURE30_ARB 0x84DE
#define GL_TEXTURE31_ARB 0x84DF
#define GL_ACTIVE_TEXTURE_ARB 0x84E0
#define GL_CLIENT_ACTIVE_TEXTURE_ARB 0x84E1
#define GL_MAX_TEXTURE_UNITS_ARB 0x84E2
#define GL_QUERY_COUNTER_BITS_ARB 0x8864
#define GL_CURRENT_QUERY_ARB 0x8865
#define GL_QUERY_RESULT_ARB 0x8866
#define GL_QUERY_RESULT_AVAILABLE_ARB 0x8867
#define GL_SAMPLES_PASSED_ARB 0x8914
#define GL_ANY_SAMPLES_PASSED 0x8C2F
#define GL_MAX_SHADER_COMPILER_THREADS_ARB 0x91B0
#define GL_COMPLETION_STATUS_ARB 0x91B1
#define GL_VERTICES_SUBMITTED_ARB 0x82EE
#define GL_PRIMITIVES_SUBMITTED_ARB 0x82EF
#define GL_VERTEX_SHADER_INVOCATIONS_ARB 0x82F0
#define GL_TESS_CONTROL_SHADER_PATCHES_ARB 0x82F1
#define GL_TESS_EVALUATION_SHADER_INVOCATIONS_ARB 0x82F2
#define GL_GEOMETRY_SHADER_PRIMITIVES_EMITTED_ARB 0x82F3
#define GL_FRAGMENT_SHADER_INVOCATIONS_ARB 0x82F4
#define GL_COMPUTE_SHADER_INVOCATIONS_ARB 0x82F5
#define GL_CLIPPING_INPUT_PRIMITIVES_ARB 0x82F6
#define GL_CLIPPING_OUTPUT_PRIMITIVES_ARB 0x82F7
#define GL_PIXEL_PACK_BUFFER_ARB 0x88EB
#define GL_PIXEL_UNPACK_BUFFER_ARB 0x88EC
#define GL_PIXEL_PACK_BUFFER_BINDING_ARB 0x88ED
#define GL_PIXEL_UNPACK_BUFFER_BINDING_ARB 0x88EF
#define GL_POINT_SIZE_MIN_ARB 0x8126
#define GL_POINT_SIZE_MAX_ARB 0x8127
#define GL_POINT_FADE_THRESHOLD_SIZE_ARB 0x8128
#define GL_POINT_DISTANCE_ATTENUATION_ARB 0x8129
#define GL_POINT_SPRITE_ARB 0x8861
#define GL_COORD_REPLACE_ARB 0x8862
#define GL_UNIFORM 0x92E1
#define GL_UNIFORM_BLOCK 0x92E2
#define GL_PROGRAM_INPUT 0x92E3
#define GL_PROGRAM_OUTPUT 0x92E4
#define GL_BUFFER_VARIABLE 0x92E5
#define GL_SHADER_STORAGE_BLOCK 0x92E6
#define GL_ATOMIC_COUNTER_BUFFER 0x92C0
#define GL_VERTEX_SUBROUTINE 0x92E8
#define GL_TESS_CONTROL_SUBROUTINE 0x92E9
#define GL_TESS_EVALUATION_SUBROUTINE 0x92EA
#define GL_GEOMETRY_SUBROUTINE 0x92EB
#define GL_FRAGMENT_SUBROUTINE 0x92EC
#define GL_COMPUTE_SUBROUTINE 0x92ED
#define GL_VERTEX_SUBROUTINE_UNIFORM 0x92EE
#define GL_TESS_CONTROL_SUBROUTINE_UNIFORM 0x92EF
#define GL_TESS_EVALUATION_SUBROUTINE_UNIFORM 0x92F0
#define GL_GEOMETRY_SUBROUTINE_UNIFORM 0x92F1
#define GL_FRAGMENT_SUBROUTINE_UNIFORM 0x92F2
#define GL_COMPUTE_SUBROUTINE_UNIFORM 0x92F3
#define GL_TRANSFORM_FEEDBACK_VARYING 0x92F4
#define GL_ACTIVE_RESOURCES 0x92F5
#define GL_MAX_NAME_LENGTH 0x92F6
#define GL_MAX_NUM_ACTIVE_VARIABLES 0x92F7
#define GL_MAX_NUM_COMPATIBLE_SUBROUTINES 0x92F8
#define GL_NAME_LENGTH 0x92F9
#define GL_TYPE 0x92FA
#define GL_ARRAY_SIZE 0x92FB
#define GL_OFFSET 0x92FC
#define GL_BLOCK_INDEX 0x92FD
#define GL_ARRAY_STRIDE 0x92FE
#define GL_MATRIX_STRIDE 0x92FF
#define GL_IS_ROW_MAJOR 0x9300
#define GL_ATOMIC_COUNTER_BUFFER_INDEX 0x9301
#define GL_BUFFER_BINDING 0x9302
#define GL_BUFFER_DATA_SIZE 0x9303
#define GL_NUM_ACTIVE_VARIABLES 0x9304
#define GL_ACTIVE_VARIABLES 0x9305
#define GL_REFERENCED_BY_VERTEX_SHADER 0x9306
#define GL_REFERENCED_BY_TESS_CONTROL_SHADER 0x9307
#define GL_REFERENCED_BY_TESS_EVALUATION_SHADER 0x9308
#define GL_REFERENCED_BY_GEOMETRY_SHADER 0x9309
#define GL_REFERENCED_BY_FRAGMENT_SHADER 0x930A
#define GL_REFERENCED_BY_COMPUTE_SHADER 0x930B
#define GL_TOP_LEVEL_ARRAY_SIZE 0x930C
#define GL_TOP_LEVEL_ARRAY_STRIDE 0x930D
#define GL_LOCATION 0x930E
#define GL_LOCATION_INDEX 0x930F
#define GL_IS_PER_PATCH 0x92E7
#define GL_NUM_COMPATIBLE_SUBROUTINES 0x8E4A
#define GL_COMPATIBLE_SUBROUTINES 0x8E4B
#define GL_QUADS_FOLLOW_PROVOKING_VERTEX_CONVENTION 0x8E4C
#define GL_FIRST_VERTEX_CONVENTION 0x8E4D
#define GL_LAST_VERTEX_CONVENTION 0x8E4E
#define GL_PROVOKING_VERTEX 0x8E4F
#define GL_QUERY_BUFFER 0x9192
#define GL_QUERY_BUFFER_BARRIER_BIT 0x00008000
#define GL_QUERY_BUFFER_BINDING 0x9193
#define GL_QUERY_RESULT_NO_WAIT 0x9194
#define GL_CONTEXT_FLAG_ROBUST_ACCESS_BIT_ARB 0x00000004
#define GL_LOSE_CONTEXT_ON_RESET_ARB 0x8252
#define GL_GUILTY_CONTEXT_RESET_ARB 0x8253
#define GL_INNOCENT_CONTEXT_RESET_ARB 0x8254
#define GL_UNKNOWN_CONTEXT_RESET_ARB 0x8255
#define GL_RESET_NOTIFICATION_STRATEGY_ARB 0x8256
#define GL_NO_RESET_NOTIFICATION_ARB 0x8261
#define GL_SAMPLE_LOCATION_SUBPIXEL_BITS_ARB 0x933D
#define GL_SAMPLE_LOCATION_PIXEL_GRID_WIDTH_ARB 0x933E
#define GL_SAMPLE_LOCATION_PIXEL_GRID_HEIGHT_ARB 0x933F
#define GL_PROGRAMMABLE_SAMPLE_LOCATION_TABLE_SIZE_ARB 0x9340
#define GL_SAMPLE_LOCATION_ARB 0x8E50
#define GL_PROGRAMMABLE_SAMPLE_LOCATION_ARB 0x9341
#define GL_FRAMEBUFFER_PROGRAMMABLE_SAMPLE_LOCATIONS_ARB 0x9342
#define GL_FRAMEBUFFER_SAMPLE_LOCATION_PIXEL_GRID_ARB 0x9343
#define GL_SAMPLE_SHADING_ARB 0x8C36
#define GL_MIN_SAMPLE_SHADING_VALUE_ARB 0x8C37
#define GL_SAMPLER_BINDING 0x8919
#define GL_VERTEX_SHADER_BIT 0x00000001
#define GL_FRAGMENT_SHADER_BIT 0x00000002
#define GL_GEOMETRY_SHADER_BIT 0x00000004
#define GL_TESS_CONTROL_SHADER_BIT 0x00000008
#define GL_TESS_EVALUATION_SHADER_BIT 0x00000010
#define GL_ALL_SHADER_BITS 0xFFFFFFFF
#define GL_PROGRAM_SEPARABLE 0x8258
#define GL_ACTIVE_PROGRAM 0x8259
#define GL_PROGRAM_PIPELINE_BINDING 0x825A
#define GL_ATOMIC_COUNTER_BUFFER_BINDING 0x92C1
#define GL_ATOMIC_COUNTER_BUFFER_START 0x92C2
#define GL_ATOMIC_COUNTER_BUFFER_SIZE 0x92C3
#define GL_ATOMIC_COUNTER_BUFFER_DATA_SIZE 0x92C4
#define GL_ATOMIC_COUNTER_BUFFER_ACTIVE_ATOMIC_COUNTERS 0x92C5
#define GL_ATOMIC_COUNTER_BUFFER_ACTIVE_ATOMIC_COUNTER_INDICES 0x92C6
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_VERTEX_SHADER 0x92C7
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TESS_CONTROL_SHADER 0x92C8
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TESS_EVALUATION_SHADER 0x92C9
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_GEOMETRY_SHADER 0x92CA
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_FRAGMENT_SHADER 0x92CB
#define GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS 0x92CC
#define GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS 0x92CD
#define GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS 0x92CE
#define GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS 0x92CF
#define GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS 0x92D0
#define GL_MAX_COMBINED_ATOMIC_COUNTER_BUFFERS 0x92D1
#define GL_MAX_VERTEX_ATOMIC_COUNTERS 0x92D2
#define GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS 0x92D3
#define GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS 0x92D4
#define GL_MAX_GEOMETRY_ATOMIC_COUNTERS 0x92D5
#define GL_MAX_FRAGMENT_ATOMIC_COUNTERS 0x92D6
#define GL_MAX_COMBINED_ATOMIC_COUNTERS 0x92D7
#define GL_MAX_ATOMIC_COUNTER_BUFFER_SIZE 0x92D8
#define GL_MAX_ATOMIC_COUNTER_BUFFER_BINDINGS 0x92DC
#define GL_ACTIVE_ATOMIC_COUNTER_BUFFERS 0x92D9
#define GL_UNIFORM_ATOMIC_COUNTER_BUFFER_INDEX 0x92DA
#define GL_UNSIGNED_INT_ATOMIC_COUNTER 0x92DB
#define GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT 0x00000001
#define GL_ELEMENT_ARRAY_BARRIER_BIT 0x00000002
#define GL_UNIFORM_BARRIER_BIT 0x00000004
#define GL_TEXTURE_FETCH_BARRIER_BIT 0x00000008
#define GL_SHADER_IMAGE_ACCESS_BARRIER_BIT 0x00000020
#define GL_COMMAND_BARRIER_BIT 0x00000040
#define GL_PIXEL_BUFFER_BARRIER_BIT 0x00000080
#define GL_TEXTURE_UPDATE_BARRIER_BIT 0x00000100
#define GL_BUFFER_UPDATE_BARRIER_BIT 0x00000200
#define GL_FRAMEBUFFER_BARRIER_BIT 0x00000400
#define GL_TRANSFORM_FEEDBACK_BARRIER_BIT 0x00000800
#define GL_ATOMIC_COUNTER_BARRIER_BIT 0x00001000
#define GL_ALL_BARRIER_BITS 0xFFFFFFFF
#define GL_MAX_IMAGE_UNITS 0x8F38
#define GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS 0x8F39
#define GL_IMAGE_BINDING_NAME 0x8F3A
#define GL_IMAGE_BINDING_LEVEL 0x8F3B
#define GL_IMAGE_BINDING_LAYERED 0x8F3C
#define GL_IMAGE_BINDING_LAYER 0x8F3D
#define GL_IMAGE_BINDING_ACCESS 0x8F3E
#define GL_IMAGE_1D 0x904C
#define GL_IMAGE_2D 0x904D
#define GL_IMAGE_3D 0x904E
#define GL_IMAGE_2D_RECT 0x904F
#define GL_IMAGE_CUBE 0x9050
#define GL_IMAGE_BUFFER 0x9051
#define GL_IMAGE_1D_ARRAY 0x9052
#define GL_IMAGE_2D_ARRAY 0x9053
#define GL_IMAGE_CUBE_MAP_ARRAY 0x9054
#define GL_IMAGE_2D_MULTISAMPLE 0x9055
#define GL_IMAGE_2D_MULTISAMPLE_ARRAY 0x9056
#define GL_INT_IMAGE_1D 0x9057
#define GL_INT_IMAGE_2D 0x9058
#define GL_INT_IMAGE_3D 0x9059
#define GL_INT_IMAGE_2D_RECT 0x905A
#define GL_INT_IMAGE_CUBE 0x905B
#define GL_INT_IMAGE_BUFFER 0x905C
#define GL_INT_IMAGE_1D_ARRAY 0x905D
#define GL_INT_IMAGE_2D_ARRAY 0x905E
#define GL_INT_IMAGE_CUBE_MAP_ARRAY 0x905F
#define GL_INT_IMAGE_2D_MULTISAMPLE 0x9060
#define GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY 0x9061
#define GL_UNSIGNED_INT_IMAGE_1D 0x9062
#define GL_UNSIGNED_INT_IMAGE_2D 0x9063
#define GL_UNSIGNED_INT_IMAGE_3D 0x9064
#define GL_UNSIGNED_INT_IMAGE_2D_RECT 0x9065
#define GL_UNSIGNED_INT_IMAGE_CUBE 0x9066
#define GL_UNSIGNED_INT_IMAGE_BUFFER 0x9067
#define GL_UNSIGNED_INT_IMAGE_1D_ARRAY 0x9068
#define GL_UNSIGNED_INT_IMAGE_2D_ARRAY 0x9069
#define GL_UNSIGNED_INT_IMAGE_CUBE_MAP_ARRAY 0x906A
#define GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE 0x906B
#define GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY 0x906C
#define GL_MAX_IMAGE_SAMPLES 0x906D
#define GL_IMAGE_BINDING_FORMAT 0x906E
#define GL_IMAGE_FORMAT_COMPATIBILITY_BY_SIZE 0x90C8
#define GL_IMAGE_FORMAT_COMPATIBILITY_BY_CLASS 0x90C9
#define GL_MAX_VERTEX_IMAGE_UNIFORMS 0x90CA
#define GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS 0x90CB
#define GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS 0x90CC
#define GL_MAX_GEOMETRY_IMAGE_UNIFORMS 0x90CD
#define GL_MAX_FRAGMENT_IMAGE_UNIFORMS 0x90CE
#define GL_MAX_COMBINED_IMAGE_UNIFORMS 0x90CF
#define GL_PROGRAM_OBJECT_ARB 0x8B40
#define GL_SHADER_OBJECT_ARB 0x8B48
#define GL_OBJECT_TYPE_ARB 0x8B4E
#define GL_OBJECT_SUBTYPE_ARB 0x8B4F
#define GL_FLOAT_VEC2_ARB 0x8B50
#define GL_FLOAT_VEC3_ARB 0x8B51
#define GL_FLOAT_VEC4_ARB 0x8B52
#define GL_INT_VEC2_ARB 0x8B53
#define GL_INT_VEC3_ARB 0x8B54
#define GL_INT_VEC4_ARB 0x8B55
#define GL_BOOL_ARB 0x8B56
#define GL_BOOL_VEC2_ARB 0x8B57
#define GL_BOOL_VEC3_ARB 0x8B58
#define GL_BOOL_VEC4_ARB 0x8B59
#define GL_FLOAT_MAT2_ARB 0x8B5A
#define GL_FLOAT_MAT3_ARB 0x8B5B
#define GL_FLOAT_MAT4_ARB 0x8B5C
#define GL_SAMPLER_1D_ARB 0x8B5D
#define GL_SAMPLER_2D_ARB 0x8B5E
#define GL_SAMPLER_3D_ARB 0x8B5F
#define GL_SAMPLER_CUBE_ARB 0x8B60
#define GL_SAMPLER_1D_SHADOW_ARB 0x8B61
#define GL_SAMPLER_2D_SHADOW_ARB 0x8B62
#define GL_SAMPLER_2D_RECT_ARB 0x8B63
#define GL_SAMPLER_2D_RECT_SHADOW_ARB 0x8B64
#define GL_OBJECT_DELETE_STATUS_ARB 0x8B80
#define GL_OBJECT_COMPILE_STATUS_ARB 0x8B81
#define GL_OBJECT_LINK_STATUS_ARB 0x8B82
#define GL_OBJECT_VALIDATE_STATUS_ARB 0x8B83
#define GL_OBJECT_INFO_LOG_LENGTH_ARB 0x8B84
#define GL_OBJECT_ATTACHED_OBJECTS_ARB 0x8B85
#define GL_OBJECT_ACTIVE_UNIFORMS_ARB 0x8B86
#define GL_OBJECT_ACTIVE_UNIFORM_MAX_LENGTH_ARB 0x8B87
#define GL_OBJECT_SHADER_SOURCE_LENGTH_ARB 0x8B88
#define GL_SHADER_STORAGE_BUFFER 0x90D2
#define GL_SHADER_STORAGE_BUFFER_BINDING 0x90D3
#define GL_SHADER_STORAGE_BUFFER_START 0x90D4
#define GL_SHADER_STORAGE_BUFFER_SIZE 0x90D5
#define GL_MAX_VERTEX_SHADER_STORAGE_BLOCKS 0x90D6
#define GL_MAX_GEOMETRY_SHADER_STORAGE_BLOCKS 0x90D7
#define GL_MAX_TESS_CONTROL_SHADER_STORAGE_BLOCKS 0x90D8
#define GL_MAX_TESS_EVALUATION_SHADER_STORAGE_BLOCKS 0x90D9
#define GL_MAX_FRAGMENT_SHADER_STORAGE_BLOCKS 0x90DA
#define GL_MAX_COMPUTE_SHADER_STORAGE_BLOCKS 0x90DB
#define GL_MAX_COMBINED_SHADER_STORAGE_BLOCKS 0x90DC
#define GL_MAX_SHADER_STORAGE_BUFFER_BINDINGS 0x90DD
#define GL_MAX_SHADER_STORAGE_BLOCK_SIZE 0x90DE
#define GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT 0x90DF
#define GL_SHADER_STORAGE_BARRIER_BIT 0x00002000
#define GL_MAX_COMBINED_SHADER_OUTPUT_RESOURCES 0x8F39
#define GL_ACTIVE_SUBROUTINES 0x8DE5
#define GL_ACTIVE_SUBROUTINE_UNIFORMS 0x8DE6
#define GL_ACTIVE_SUBROUTINE_UNIFORM_LOCATIONS 0x8E47
#define GL_ACTIVE_SUBROUTINE_MAX_LENGTH 0x8E48
#define GL_ACTIVE_SUBROUTINE_UNIFORM_MAX_LENGTH 0x8E49
#define GL_MAX_SUBROUTINES 0x8DE7
#define GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS 0x8DE8
#define GL_UNIFORM_SIZE 0x8A38
#define GL_UNIFORM_NAME_LENGTH 0x8A39
#define GL_SHADING_LANGUAGE_VERSION_ARB 0x8B8C
#define GL_SHADER_INCLUDE_ARB 0x8DAE
#define GL_NAMED_STRING_LENGTH_ARB 0x8DE9
#define GL_NAMED_STRING_TYPE_ARB 0x8DEA
#define GL_TEXTURE_COMPARE_MODE_ARB 0x884C
#define GL_TEXTURE_COMPARE_FUNC_ARB 0x884D
#define GL_COMPARE_R_TO_TEXTURE_ARB 0x884E
#define GL_TEXTURE_COMPARE_FAIL_VALUE_ARB 0x80BF
#define GL_SPARSE_STORAGE_BIT_ARB 0x0400
#define GL_SPARSE_BUFFER_PAGE_SIZE_ARB 0x82F8
#define GL_TEXTURE_SPARSE_ARB 0x91A6
#define GL_VIRTUAL_PAGE_SIZE_INDEX_ARB 0x91A7
#define GL_NUM_SPARSE_LEVELS_ARB 0x91AA
#define GL_NUM_VIRTUAL_PAGE_SIZES_ARB 0x91A8
#define GL_VIRTUAL_PAGE_SIZE_X_ARB 0x9195
#define GL_VIRTUAL_PAGE_SIZE_Y_ARB 0x9196
#define GL_VIRTUAL_PAGE_SIZE_Z_ARB 0x9197
#define GL_MAX_SPARSE_TEXTURE_SIZE_ARB 0x9198
#define GL_MAX_SPARSE_3D_TEXTURE_SIZE_ARB 0x9199
#define GL_MAX_SPARSE_ARRAY_TEXTURE_LAYERS_ARB 0x919A
#define GL_SPARSE_TEXTURE_FULL_ARRAY_CUBE_MIPMAPS_ARB 0x91A9
#define GL_DEPTH_STENCIL_TEXTURE_MODE 0x90EA
#define GL_MAX_SERVER_WAIT_TIMEOUT 0x9111
#define GL_OBJECT_TYPE 0x9112
#define GL_SYNC_CONDITION 0x9113
#define GL_SYNC_STATUS 0x9114
#define GL_SYNC_FLAGS 0x9115
#define GL_SYNC_FENCE 0x9116
#define GL_SYNC_GPU_COMMANDS_COMPLETE 0x9117
#define GL_UNSIGNALED 0x9118
#define GL_SIGNALED 0x9119
#define GL_ALREADY_SIGNALED 0x911A
#define GL_TIMEOUT_EXPIRED 0x911B
#define GL_CONDITION_SATISFIED 0x911C
#define GL_WAIT_FAILED 0x911D
#define GL_SYNC_FLUSH_COMMANDS_BIT 0x00000001
#define GL_TIMEOUT_IGNORED 0xFFFFFFFFFFFFFFFF
#define GL_PATCHES 0x000E
#define GL_PATCH_VERTICES 0x8E72
#define GL_PATCH_DEFAULT_INNER_LEVEL 0x8E73
#define GL_PATCH_DEFAULT_OUTER_LEVEL 0x8E74
#define GL_TESS_CONTROL_OUTPUT_VERTICES 0x8E75
#define GL_TESS_GEN_MODE 0x8E76
#define GL_TESS_GEN_SPACING 0x8E77
#define GL_TESS_GEN_VERTEX_ORDER 0x8E78
#define GL_TESS_GEN_POINT_MODE 0x8E79
#define GL_ISOLINES 0x8E7A
#define GL_FRACTIONAL_ODD 0x8E7B
#define GL_FRACTIONAL_EVEN 0x8E7C
#define GL_MAX_PATCH_VERTICES 0x8E7D
#define GL_MAX_TESS_GEN_LEVEL 0x8E7E
#define GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS 0x8E7F
#define GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS 0x8E80
#define GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS 0x8E81
#define GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS 0x8E82
#define GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS 0x8E83
#define GL_MAX_TESS_PATCH_COMPONENTS 0x8E84
#define GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS 0x8E85
#define GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS 0x8E86
#define GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS 0x8E89
#define GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS 0x8E8A
#define GL_MAX_TESS_CONTROL_INPUT_COMPONENTS 0x886C
#define GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS 0x886D
#define GL_MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS 0x8E1E
#define GL_MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS 0x8E1F
#define GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_CONTROL_SHADER 0x84F0
#define GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_EVALUATION_SHADER 0x84F1
#define GL_TESS_EVALUATION_SHADER 0x8E87
#define GL_TESS_CONTROL_SHADER 0x8E88
#define GL_CLAMP_TO_BORDER_ARB 0x812D
#define GL_TEXTURE_BUFFER_ARB 0x8C2A
#define GL_MAX_TEXTURE_BUFFER_SIZE_ARB 0x8C2B
#define GL_TEXTURE_BINDING_BUFFER_ARB 0x8C2C
#define GL_TEXTURE_BUFFER_DATA_STORE_BINDING_ARB 0x8C2D
#define GL_TEXTURE_BUFFER_FORMAT_ARB 0x8C2E
#define GL_RGB32F 0x8815
#define GL_RGB32UI 0x8D71
#define GL_RGB32I 0x8D83
#define GL_TEXTURE_BUFFER_OFFSET 0x919D
#define GL_TEXTURE_BUFFER_SIZE 0x919E
#define GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT 0x919F
#define GL_COMPRESSED_ALPHA_ARB 0x84E9
#define GL_COMPRESSED_LUMINANCE_ARB 0x84EA
#define GL_COMPRESSED_LUMINANCE_ALPHA_ARB 0x84EB
#define GL_COMPRESSED_INTENSITY_ARB 0x84EC
#define GL_COMPRESSED_RGB_ARB 0x84ED
#define GL_COMPRESSED_RGBA_ARB 0x84EE
#define GL_TEXTURE_COMPRESSION_HINT_ARB 0x84EF
#define GL_TEXTURE_COMPRESSED_IMAGE_SIZE_ARB 0x86A0
#define GL_TEXTURE_COMPRESSED_ARB 0x86A1
#define GL_NUM_COMPRESSED_TEXTURE_FORMATS_ARB 0x86A2
#define GL_COMPRESSED_TEXTURE_FORMATS_ARB 0x86A3
#define GL_COMPRESSED_RGBA_BPTC_UNORM_ARB 0x8E8C
#define GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM_ARB 0x8E8D
#define GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT_ARB 0x8E8E
#define GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT_ARB 0x8E8F
#define GL_COMPRESSED_RED_RGTC1 0x8DBB
#define GL_COMPRESSED_SIGNED_RED_RGTC1 0x8DBC
#define GL_COMPRESSED_RG_RGTC2 0x8DBD
#define GL_COMPRESSED_SIGNED_RG_RGTC2 0x8DBE
#define GL_NORMAL_MAP_ARB 0x8511
#define GL_REFLECTION_MAP_ARB 0x8512
#define GL_TEXTURE_CUBE_MAP_ARB 0x8513
#define GL_TEXTURE_BINDING_CUBE_MAP_ARB 0x8514
#define GL_TEXTURE_CUBE_MAP_POSITIVE_X_ARB 0x8515
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_X_ARB 0x8516
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Y_ARB 0x8517
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Y_ARB 0x8518
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Z_ARB 0x8519
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Z_ARB 0x851A
#define GL_PROXY_TEXTURE_CUBE_MAP_ARB 0x851B
#define GL_MAX_CUBE_MAP_TEXTURE_SIZE_ARB 0x851C
#define GL_TEXTURE_CUBE_MAP_ARRAY_ARB 0x9009
#define GL_TEXTURE_BINDING_CUBE_MAP_ARRAY_ARB 0x900A
#define GL_PROXY_TEXTURE_CUBE_MAP_ARRAY_ARB 0x900B
#define GL_SAMPLER_CUBE_MAP_ARRAY_ARB 0x900C
#define GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW_ARB 0x900D
#define GL_INT_SAMPLER_CUBE_MAP_ARRAY_ARB 0x900E
#define GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY_ARB 0x900F
#define GL_COMBINE_ARB 0x8570
#define GL_COMBINE_RGB_ARB 0x8571
#define GL_COMBINE_ALPHA_ARB 0x8572
#define GL_SOURCE0_RGB_ARB 0x8580
#define GL_SOURCE1_RGB_ARB 0x8581
#define GL_SOURCE2_RGB_ARB 0x8582
#define GL_SOURCE0_ALPHA_ARB 0x8588
#define GL_SOURCE1_ALPHA_ARB 0x8589
#define GL_SOURCE2_ALPHA_ARB 0x858A
#define GL_OPERAND0_RGB_ARB 0x8590
#define GL_OPERAND1_RGB_ARB 0x8591
#define GL_OPERAND2_RGB_ARB 0x8592
#define GL_OPERAND0_ALPHA_ARB 0x8598
#define GL_OPERAND1_ALPHA_ARB 0x8599
#define GL_OPERAND2_ALPHA_ARB 0x859A
#define GL_RGB_SCALE_ARB 0x8573
#define GL_ADD_SIGNED_ARB 0x8574
#define GL_INTERPOLATE_ARB 0x8575
#define GL_SUBTRACT_ARB 0x84E7
#define GL_CONSTANT_ARB 0x8576
#define GL_PRIMARY_COLOR_ARB 0x8577
#define GL_PREVIOUS_ARB 0x8578
#define GL_DOT3_RGB_ARB 0x86AE
#define GL_DOT3_RGBA_ARB 0x86AF
#define GL_TEXTURE_REDUCTION_MODE_ARB 0x9366
#define GL_WEIGHTED_AVERAGE_ARB 0x9367
#define GL_TEXTURE_RED_TYPE_ARB 0x8C10
#define GL_TEXTURE_GREEN_TYPE_ARB 0x8C11
#define GL_TEXTURE_BLUE_TYPE_ARB 0x8C12
#define GL_TEXTURE_ALPHA_TYPE_ARB 0x8C13
#define GL_TEXTURE_LUMINANCE_TYPE_ARB 0x8C14
#define GL_TEXTURE_INTENSITY_TYPE_ARB 0x8C15
#define GL_TEXTURE_DEPTH_TYPE_ARB 0x8C16
#define GL_UNSIGNED_NORMALIZED_ARB 0x8C17
#define GL_RGBA32F_ARB 0x8814
#define GL_RGB32F_ARB 0x8815
#define GL_ALPHA32F_ARB 0x8816
#define GL_INTENSITY32F_ARB 0x8817
#define GL_LUMINANCE32F_ARB 0x8818
#define GL_LUMINANCE_ALPHA32F_ARB 0x8819
#define GL_RGBA16F_ARB 0x881A
#define GL_RGB16F_ARB 0x881B
#define GL_ALPHA16F_ARB 0x881C
#define GL_INTENSITY16F_ARB 0x881D
#define GL_LUMINANCE16F_ARB 0x881E
#define GL_LUMINANCE_ALPHA16F_ARB 0x881F
#define GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET_ARB 0x8E5E
#define GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET_ARB 0x8E5F
#define GL_MAX_PROGRAM_TEXTURE_GATHER_COMPONENTS_ARB 0x8F9F
#define GL_MIRROR_CLAMP_TO_EDGE 0x8743
#define GL_MIRRORED_REPEAT_ARB 0x8370
#define GL_SAMPLE_POSITION 0x8E50
#define GL_SAMPLE_MASK 0x8E51
#define GL_SAMPLE_MASK_VALUE 0x8E52
#define GL_MAX_SAMPLE_MASK_WORDS 0x8E59
#define GL_PROXY_TEXTURE_2D_MULTISAMPLE 0x9101
#define GL_PROXY_TEXTURE_2D_MULTISAMPLE_ARRAY 0x9103
#define GL_TEXTURE_SAMPLES 0x9106
#define GL_TEXTURE_FIXED_SAMPLE_LOCATIONS 0x9107
#define GL_SAMPLER_2D_MULTISAMPLE 0x9108
#define GL_INT_SAMPLER_2D_MULTISAMPLE 0x9109
#define GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE 0x910A
#define GL_SAMPLER_2D_MULTISAMPLE_ARRAY 0x910B
#define GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY 0x910C
#define GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY 0x910D
#define GL_MAX_COLOR_TEXTURE_SAMPLES 0x910E
#define GL_MAX_DEPTH_TEXTURE_SAMPLES 0x910F
#define GL_MAX_INTEGER_SAMPLES 0x9110
#define GL_TEXTURE_RECTANGLE_ARB 0x84F5
#define GL_TEXTURE_BINDING_RECTANGLE_ARB 0x84F6
#define GL_PROXY_TEXTURE_RECTANGLE_ARB 0x84F7
#define GL_MAX_RECTANGLE_TEXTURE_SIZE_ARB 0x84F8
#define GL_RG 0x8227
#define GL_RG_INTEGER 0x8228
#define GL_R8 0x8229
#define GL_R16 0x822A
#define GL_RG8 0x822B
#define GL_RG16 0x822C
#define GL_R16F 0x822D
#define GL_R32F 0x822E
#define GL_RG16F 0x822F
#define GL_RG32F 0x8230
#define GL_R8I 0x8231
#define GL_R8UI 0x8232
#define GL_R16I 0x8233
#define GL_R16UI 0x8234
#define GL_R32I 0x8235
#define GL_R32UI 0x8236
#define GL_RG8I 0x8237
#define GL_RG16I 0x8239
#define GL_RG32I 0x823B
#define GL_RG32UI 0x823C
#define GL_RGB10_A2UI 0x906F
#define GL_TEXTURE_IMMUTABLE_FORMAT 0x912F
#define GL_TEXTURE_SWIZZLE_R 0x8E42
#define GL_TEXTURE_SWIZZLE_G 0x8E43
#define GL_TEXTURE_SWIZZLE_B 0x8E44
#define GL_TEXTURE_SWIZZLE_A 0x8E45
#define GL_TEXTURE_SWIZZLE_RGBA 0x8E46
#define GL_TEXTURE_VIEW_MIN_LEVEL 0x82DB
#define GL_TEXTURE_VIEW_NUM_LEVELS 0x82DC
#define GL_TEXTURE_VIEW_MIN_LAYER 0x82DD
#define GL_TEXTURE_VIEW_NUM_LAYERS 0x82DE
#define GL_TEXTURE_IMMUTABLE_LEVELS 0x82DF
#define GL_TIME_ELAPSED 0x88BF
#define GL_TIMESTAMP 0x8E28
#define GL_TRANSFORM_FEEDBACK 0x8E22
#define GL_TRANSFORM_FEEDBACK_BUFFER_PAUSED 0x8E23
#define GL_TRANSFORM_FEEDBACK_BUFFER_ACTIVE 0x8E24
#define GL_TRANSFORM_FEEDBACK_BINDING 0x8E25
#define GL_MAX_TRANSFORM_FEEDBACK_BUFFERS 0x8E70
#define GL_TRANSFORM_FEEDBACK_OVERFLOW_ARB 0x82EC
#define GL_TRANSFORM_FEEDBACK_STREAM_OVERFLOW_ARB 0x82ED
#define GL_TRANSPOSE_MODELVIEW_MATRIX_ARB 0x84E3
#define GL_TRANSPOSE_PROJECTION_MATRIX_ARB 0x84E4
#define GL_TRANSPOSE_TEXTURE_MATRIX_ARB 0x84E5
#define GL_TRANSPOSE_COLOR_MATRIX_ARB 0x84E6
#define GL_UNIFORM_BUFFER 0x8A11
#define GL_UNIFORM_BUFFER_BINDING 0x8A28
#define GL_UNIFORM_BUFFER_START 0x8A29
#define GL_UNIFORM_BUFFER_SIZE 0x8A2A
#define GL_MAX_VERTEX_UNIFORM_BLOCKS 0x8A2B
#define GL_MAX_GEOMETRY_UNIFORM_BLOCKS 0x8A2C
#define GL_MAX_FRAGMENT_UNIFORM_BLOCKS 0x8A2D
#define GL_MAX_COMBINED_UNIFORM_BLOCKS 0x8A2E
#define GL_MAX_UNIFORM_BUFFER_BINDINGS 0x8A2F
#define GL_MAX_UNIFORM_BLOCK_SIZE 0x8A30
#define GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS 0x8A31
#define GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS 0x8A32
#define GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS 0x8A33
#define GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT 0x8A34
#define GL_ACTIVE_UNIFORM_BLOCK_MAX_NAME_LENGTH 0x8A35
#define GL_ACTIVE_UNIFORM_BLOCKS 0x8A36
#define GL_UNIFORM_TYPE 0x8A37
#define GL_UNIFORM_BLOCK_INDEX 0x8A3A
#define GL_UNIFORM_OFFSET 0x8A3B
#define GL_UNIFORM_ARRAY_STRIDE 0x8A3C
#define GL_UNIFORM_MATRIX_STRIDE 0x8A3D
#define GL_UNIFORM_IS_ROW_MAJOR 0x8A3E
#define GL_UNIFORM_BLOCK_BINDING 0x8A3F
#define GL_UNIFORM_BLOCK_DATA_SIZE 0x8A40
#define GL_UNIFORM_BLOCK_NAME_LENGTH 0x8A41
#define GL_UNIFORM_BLOCK_ACTIVE_UNIFORMS 0x8A42
#define GL_UNIFORM_BLOCK_ACTIVE_UNIFORM_INDICES 0x8A43
#define GL_UNIFORM_BLOCK_REFERENCED_BY_VERTEX_SHADER 0x8A44
#define GL_UNIFORM_BLOCK_REFERENCED_BY_GEOMETRY_SHADER 0x8A45
#define GL_UNIFORM_BLOCK_REFERENCED_BY_FRAGMENT_SHADER 0x8A46
#define GL_INVALID_INDEX 0xFFFFFFFF
#define GL_VERTEX_ARRAY_BINDING 0x85B5
#define GL_VERTEX_ATTRIB_BINDING 0x82D4
#define GL_VERTEX_ATTRIB_RELATIVE_OFFSET 0x82D5
#define GL_VERTEX_BINDING_DIVISOR 0x82D6
#define GL_VERTEX_BINDING_OFFSET 0x82D7
#define GL_VERTEX_BINDING_STRIDE 0x82D8
#define GL_MAX_VERTEX_ATTRIB_RELATIVE_OFFSET 0x82D9
#define GL_MAX_VERTEX_ATTRIB_BINDINGS 0x82DA
#define GL_MAX_VERTEX_UNITS_ARB 0x86A4
#define GL_ACTIVE_VERTEX_UNITS_ARB 0x86A5
#define GL_WEIGHT_SUM_UNITY_ARB 0x86A6
#define GL_VERTEX_BLEND_ARB 0x86A7
#define GL_CURRENT_WEIGHT_ARB 0x86A8
#define GL_WEIGHT_ARRAY_TYPE_ARB 0x86A9
#define GL_WEIGHT_ARRAY_STRIDE_ARB 0x86AA
#define GL_WEIGHT_ARRAY_SIZE_ARB 0x86AB
#define GL_WEIGHT_ARRAY_POINTER_ARB 0x86AC
#define GL_WEIGHT_ARRAY_ARB 0x86AD
#define GL_MODELVIEW0_ARB 0x1700
#define GL_MODELVIEW1_ARB 0x850A
#define GL_MODELVIEW2_ARB 0x8722
#define GL_MODELVIEW3_ARB 0x8723
#define GL_MODELVIEW4_ARB 0x8724
#define GL_MODELVIEW5_ARB 0x8725
#define GL_MODELVIEW6_ARB 0x8726
#define GL_MODELVIEW7_ARB 0x8727
#define GL_MODELVIEW8_ARB 0x8728
#define GL_MODELVIEW9_ARB 0x8729
#define GL_MODELVIEW10_ARB 0x872A
#define GL_MODELVIEW11_ARB 0x872B
#define GL_MODELVIEW12_ARB 0x872C
#define GL_MODELVIEW13_ARB 0x872D
#define GL_MODELVIEW14_ARB 0x872E
#define GL_MODELVIEW15_ARB 0x872F
#define GL_MODELVIEW16_ARB 0x8730
#define GL_MODELVIEW17_ARB 0x8731
#define GL_MODELVIEW18_ARB 0x8732
#define GL_MODELVIEW19_ARB 0x8733
#define GL_MODELVIEW20_ARB 0x8734
#define GL_MODELVIEW21_ARB 0x8735
#define GL_MODELVIEW22_ARB 0x8736
#define GL_MODELVIEW23_ARB 0x8737
#define GL_MODELVIEW24_ARB 0x8738
#define GL_MODELVIEW25_ARB 0x8739
#define GL_MODELVIEW26_ARB 0x873A
#define GL_MODELVIEW27_ARB 0x873B
#define GL_MODELVIEW28_ARB 0x873C
#define GL_MODELVIEW29_ARB 0x873D
#define GL_MODELVIEW30_ARB 0x873E
#define GL_MODELVIEW31_ARB 0x873F
#define GL_BUFFER_SIZE_ARB 0x8764
#define GL_BUFFER_USAGE_ARB 0x8765
#define GL_ARRAY_BUFFER_ARB 0x8892
#define GL_ELEMENT_ARRAY_BUFFER_ARB 0x8893
#define GL_ARRAY_BUFFER_BINDING_ARB 0x8894
#define GL_ELEMENT_ARRAY_BUFFER_BINDING_ARB 0x8895
#define GL_VERTEX_ARRAY_BUFFER_BINDING_ARB 0x8896
#define GL_NORMAL_ARRAY_BUFFER_BINDING_ARB 0x8897
#define GL_COLOR_ARRAY_BUFFER_BINDING_ARB 0x8898
#define GL_INDEX_ARRAY_BUFFER_BINDING_ARB 0x8899
#define GL_TEXTURE_COORD_ARRAY_BUFFER_BINDING_ARB 0x889A
#define GL_EDGE_FLAG_ARRAY_BUFFER_BINDING_ARB 0x889B
#define GL_SECONDARY_COLOR_ARRAY_BUFFER_BINDING_ARB 0x889C
#define GL_FOG_COORDINATE_ARRAY_BUFFER_BINDING_ARB 0x889D
#define GL_WEIGHT_ARRAY_BUFFER_BINDING_ARB 0x889E
#define GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING_ARB 0x889F
#define GL_READ_ONLY_ARB 0x88B8
#define GL_WRITE_ONLY_ARB 0x88B9
#define GL_READ_WRITE_ARB 0x88BA
#define GL_BUFFER_ACCESS_ARB 0x88BB
#define GL_BUFFER_MAPPED_ARB 0x88BC
#define GL_BUFFER_MAP_POINTER_ARB 0x88BD
#define GL_STREAM_DRAW_ARB 0x88E0
#define GL_STREAM_READ_ARB 0x88E1
#define GL_STREAM_COPY_ARB 0x88E2
#define GL_STATIC_DRAW_ARB 0x88E4
#define GL_STATIC_READ_ARB 0x88E5
#define GL_STATIC_COPY_ARB 0x88E6
#define GL_DYNAMIC_DRAW_ARB 0x88E8
#define GL_DYNAMIC_READ_ARB 0x88E9
#define GL_DYNAMIC_COPY_ARB 0x88EA
#define GL_COLOR_SUM_ARB 0x8458
#define GL_VERTEX_PROGRAM_ARB 0x8620
#define GL_VERTEX_ATTRIB_ARRAY_ENABLED_ARB 0x8622
#define GL_VERTEX_ATTRIB_ARRAY_SIZE_ARB 0x8623
#define GL_VERTEX_ATTRIB_ARRAY_STRIDE_ARB 0x8624
#define GL_VERTEX_ATTRIB_ARRAY_TYPE_ARB 0x8625
#define GL_CURRENT_VERTEX_ATTRIB_ARB 0x8626
#define GL_VERTEX_PROGRAM_POINT_SIZE_ARB 0x8642
#define GL_VERTEX_PROGRAM_TWO_SIDE_ARB 0x8643
#define GL_VERTEX_ATTRIB_ARRAY_POINTER_ARB 0x8645
#define GL_MAX_VERTEX_ATTRIBS_ARB 0x8869
#define GL_VERTEX_ATTRIB_ARRAY_NORMALIZED_ARB 0x886A
#define GL_PROGRAM_ADDRESS_REGISTERS_ARB 0x88B0
#define GL_MAX_PROGRAM_ADDRESS_REGISTERS_ARB 0x88B1
#define GL_PROGRAM_NATIVE_ADDRESS_REGISTERS_ARB 0x88B2
#define GL_MAX_PROGRAM_NATIVE_ADDRESS_REGISTERS_ARB 0x88B3
#define GL_VERTEX_SHADER_ARB 0x8B31
#define GL_MAX_VERTEX_UNIFORM_COMPONENTS_ARB 0x8B4A
#define GL_MAX_VARYING_FLOATS_ARB 0x8B4B
#define GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS_ARB 0x8B4C
#define GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS_ARB 0x8B4D
#define GL_OBJECT_ACTIVE_ATTRIBUTES_ARB 0x8B89
#define GL_OBJECT_ACTIVE_ATTRIBUTE_MAX_LENGTH_ARB 0x8B8A
#define GL_UNSIGNED_INT_10F_11F_11F_REV 0x8C3B
#define GL_INT_2_10_10_10_REV 0x8D9F
#define GL_MAX_VIEWPORTS 0x825B
#define GL_VIEWPORT_SUBPIXEL_BITS 0x825C
#define GL_VIEWPORT_BOUNDS_RANGE 0x825D
#define GL_LAYER_PROVOKING_VERTEX 0x825E
#define GL_VIEWPORT_INDEX_PROVOKING_VERTEX 0x825F
#define GL_UNDEFINED_VERTEX 0x8260
#define GL_MAX_DRAW_BUFFERS_ATI 0x8824
#define GL_DRAW_BUFFER0_ATI 0x8825
#define GL_DRAW_BUFFER1_ATI 0x8826
#define GL_DRAW_BUFFER2_ATI 0x8827
#define GL_DRAW_BUFFER3_ATI 0x8828
#define GL_DRAW_BUFFER4_ATI 0x8829
#define GL_DRAW_BUFFER5_ATI 0x882A
#define GL_DRAW_BUFFER6_ATI 0x882B
#define GL_DRAW_BUFFER7_ATI 0x882C
#define GL_DRAW_BUFFER8_ATI 0x882D
#define GL_DRAW_BUFFER9_ATI 0x882E
#define GL_DRAW_BUFFER10_ATI 0x882F
#define GL_DRAW_BUFFER11_ATI 0x8830
#define GL_DRAW_BUFFER12_ATI 0x8831
#define GL_DRAW_BUFFER13_ATI 0x8832
#define GL_DRAW_BUFFER14_ATI 0x8833
#define GL_DRAW_BUFFER15_ATI 0x8834
#define GL_ELEMENT_ARRAY_ATI 0x8768
#define GL_ELEMENT_ARRAY_TYPE_ATI 0x8769
#define GL_ELEMENT_ARRAY_POINTER_ATI 0x876A
#define GL_BUMP_ROT_MATRIX_ATI 0x8775
#define GL_BUMP_ROT_MATRIX_SIZE_ATI 0x8776
#define GL_BUMP_NUM_TEX_UNITS_ATI 0x8777
#define GL_BUMP_TEX_UNITS_ATI 0x8778
#define GL_DUDV_ATI 0x8779
#define GL_DU8DV8_ATI 0x877A
#define GL_BUMP_ENVMAP_ATI 0x877B
#define GL_BUMP_TARGET_ATI 0x877C
#define GL_FRAGMENT_SHADER_ATI 0x8920
#define GL_REG_0_ATI 0x8921
#define GL_REG_1_ATI 0x8922
#define GL_REG_2_ATI 0x8923
#define GL_REG_3_ATI 0x8924
#define GL_REG_4_ATI 0x8925
#define GL_REG_5_ATI 0x8926
#define GL_REG_6_ATI 0x8927
#define GL_REG_7_ATI 0x8928
#define GL_REG_8_ATI 0x8929
#define GL_REG_9_ATI 0x892A
#define GL_REG_10_ATI 0x892B
#define GL_REG_11_ATI 0x892C
#define GL_REG_12_ATI 0x892D
#define GL_REG_13_ATI 0x892E
#define GL_REG_14_ATI 0x892F
#define GL_REG_15_ATI 0x8930
#define GL_REG_16_ATI 0x8931
#define GL_REG_17_ATI 0x8932
#define GL_REG_18_ATI 0x8933
#define GL_REG_19_ATI 0x8934
#define GL_REG_20_ATI 0x8935
#define GL_REG_21_ATI 0x8936
#define GL_REG_22_ATI 0x8937
#define GL_REG_23_ATI 0x8938
#define GL_REG_24_ATI 0x8939
#define GL_REG_25_ATI 0x893A
#define GL_REG_26_ATI 0x893B
#define GL_REG_27_ATI 0x893C
#define GL_REG_28_ATI 0x893D
#define GL_REG_29_ATI 0x893E
#define GL_REG_30_ATI 0x893F
#define GL_REG_31_ATI 0x8940
#define GL_CON_0_ATI 0x8941
#define GL_CON_1_ATI 0x8942
#define GL_CON_2_ATI 0x8943
#define GL_CON_3_ATI 0x8944
#define GL_CON_4_ATI 0x8945
#define GL_CON_5_ATI 0x8946
#define GL_CON_6_ATI 0x8947
#define GL_CON_7_ATI 0x8948
#define GL_CON_8_ATI 0x8949
#define GL_CON_9_ATI 0x894A
#define GL_CON_10_ATI 0x894B
#define GL_CON_11_ATI 0x894C
#define GL_CON_12_ATI 0x894D
#define GL_CON_13_ATI 0x894E
#define GL_CON_14_ATI 0x894F
#define GL_CON_15_ATI 0x8950
#define GL_CON_16_ATI 0x8951
#define GL_CON_17_ATI 0x8952
#define GL_CON_18_ATI 0x8953
#define GL_CON_19_ATI 0x8954
#define GL_CON_20_ATI 0x8955
#define GL_CON_21_ATI 0x8956
#define GL_CON_22_ATI 0x8957
#define GL_CON_23_ATI 0x8958
#define GL_CON_24_ATI 0x8959
#define GL_CON_25_ATI 0x895A
#define GL_CON_26_ATI 0x895B
#define GL_CON_27_ATI 0x895C
#define GL_CON_28_ATI 0x895D
#define GL_CON_29_ATI 0x895E
#define GL_CON_30_ATI 0x895F
#define GL_CON_31_ATI 0x8960
#define GL_MOV_ATI 0x8961
#define GL_ADD_ATI 0x8963
#define GL_MUL_ATI 0x8964
#define GL_SUB_ATI 0x8965
#define GL_DOT3_ATI 0x8966
#define GL_DOT4_ATI 0x8967
#define GL_MAD_ATI 0x8968
#define GL_LERP_ATI 0x8969
#define GL_CND_ATI 0x896A
#define GL_CND0_ATI 0x896B
#define GL_DOT2_ADD_ATI 0x896C
#define GL_SECONDARY_INTERPOLATOR_ATI 0x896D
#define GL_NUM_FRAGMENT_REGISTERS_ATI 0x896E
#define GL_NUM_FRAGMENT_CONSTANTS_ATI 0x896F
#define GL_NUM_PASSES_ATI 0x8970
#define GL_NUM_INSTRUCTIONS_PER_PASS_ATI 0x8971
#define GL_NUM_INSTRUCTIONS_TOTAL_ATI 0x8972
#define GL_NUM_INPUT_INTERPOLATOR_COMPONENTS_ATI 0x8973
#define GL_NUM_LOOPBACK_COMPONENTS_ATI 0x8974
#define GL_COLOR_ALPHA_PAIRING_ATI 0x8975
#define GL_SWIZZLE_STR_ATI 0x8976
#define GL_SWIZZLE_STQ_ATI 0x8977
#define GL_SWIZZLE_STR_DR_ATI 0x8978
#define GL_SWIZZLE_STQ_DQ_ATI 0x8979
#define GL_SWIZZLE_STRQ_ATI 0x897A
#define GL_SWIZZLE_STRQ_DQ_ATI 0x897B
#define GL_RED_BIT_ATI 0x00000001
#define GL_GREEN_BIT_ATI 0x00000002
#define GL_BLUE_BIT_ATI 0x00000004
#define GL_2X_BIT_ATI 0x00000001
#define GL_4X_BIT_ATI 0x00000002
#define GL_8X_BIT_ATI 0x00000004
#define GL_HALF_BIT_ATI 0x00000008
#define GL_QUARTER_BIT_ATI 0x00000010
#define GL_EIGHTH_BIT_ATI 0x00000020
#define GL_SATURATE_BIT_ATI 0x00000040
#define GL_COMP_BIT_ATI 0x00000002
#define GL_NEGATE_BIT_ATI 0x00000004
#define GL_BIAS_BIT_ATI 0x00000008
#define GL_VBO_FREE_MEMORY_ATI 0x87FB
#define GL_TEXTURE_FREE_MEMORY_ATI 0x87FC
#define GL_RENDERBUFFER_FREE_MEMORY_ATI 0x87FD
#define GL_RGBA_FLOAT_MODE_ATI 0x8820
#define GL_COLOR_CLEAR_UNCLAMPED_VALUE_ATI 0x8835
#define GL_PN_TRIANGLES_ATI 0x87F0
#define GL_MAX_PN_TRIANGLES_TESSELATION_LEVEL_ATI 0x87F1
#define GL_PN_TRIANGLES_POINT_MODE_ATI 0x87F2
#define GL_PN_TRIANGLES_NORMAL_MODE_ATI 0x87F3
#define GL_PN_TRIANGLES_TESSELATION_LEVEL_ATI 0x87F4
#define GL_PN_TRIANGLES_POINT_MODE_LINEAR_ATI 0x87F5
#define GL_PN_TRIANGLES_POINT_MODE_CUBIC_ATI 0x87F6
#define GL_PN_TRIANGLES_NORMAL_MODE_LINEAR_ATI 0x87F7
#define GL_PN_TRIANGLES_NORMAL_MODE_QUADRATIC_ATI 0x87F8
#define GL_STENCIL_BACK_FUNC_ATI 0x8800
#define GL_STENCIL_BACK_FAIL_ATI 0x8801
#define GL_STENCIL_BACK_PASS_DEPTH_FAIL_ATI 0x8802
#define GL_STENCIL_BACK_PASS_DEPTH_PASS_ATI 0x8803
#define GL_TEXT_FRAGMENT_SHADER_ATI 0x8200
#define GL_MODULATE_ADD_ATI 0x8744
#define GL_MODULATE_SIGNED_ADD_ATI 0x8745
#define GL_MODULATE_SUBTRACT_ATI 0x8746
#define GL_RGBA_FLOAT32_ATI 0x8814
#define GL_RGB_FLOAT32_ATI 0x8815
#define GL_ALPHA_FLOAT32_ATI 0x8816
#define GL_INTENSITY_FLOAT32_ATI 0x8817
#define GL_LUMINANCE_FLOAT32_ATI 0x8818
#define GL_LUMINANCE_ALPHA_FLOAT32_ATI 0x8819
#define GL_RGBA_FLOAT16_ATI 0x881A
#define GL_RGB_FLOAT16_ATI 0x881B
#define GL_ALPHA_FLOAT16_ATI 0x881C
#define GL_INTENSITY_FLOAT16_ATI 0x881D
#define GL_LUMINANCE_FLOAT16_ATI 0x881E
#define GL_LUMINANCE_ALPHA_FLOAT16_ATI 0x881F
#define GL_MIRROR_CLAMP_ATI 0x8742
#define GL_MIRROR_CLAMP_TO_EDGE_ATI 0x8743
#define GL_STATIC_ATI 0x8760
#define GL_DYNAMIC_ATI 0x8761
#define GL_PRESERVE_ATI 0x8762
#define GL_DISCARD_ATI 0x8763
#define GL_OBJECT_BUFFER_SIZE_ATI 0x8764
#define GL_OBJECT_BUFFER_USAGE_ATI 0x8765
#define GL_ARRAY_OBJECT_BUFFER_ATI 0x8766
#define GL_ARRAY_OBJECT_OFFSET_ATI 0x8767
#define GL_MAX_VERTEX_STREAMS_ATI 0x876B
#define GL_VERTEX_STREAM0_ATI 0x876C
#define GL_VERTEX_STREAM1_ATI 0x876D
#define GL_VERTEX_STREAM2_ATI 0x876E
#define GL_VERTEX_STREAM3_ATI 0x876F
#define GL_VERTEX_STREAM4_ATI 0x8770
#define GL_VERTEX_STREAM5_ATI 0x8771
#define GL_VERTEX_STREAM6_ATI 0x8772
#define GL_VERTEX_STREAM7_ATI 0x8773
#define GL_VERTEX_SOURCE_ATI 0x8774
#define GL_422_EXT 0x80CC
#define GL_422_REV_EXT 0x80CD
#define GL_422_AVERAGE_EXT 0x80CE
#define GL_422_REV_AVERAGE_EXT 0x80CF
#define GL_ABGR_EXT 0x8000
#define GL_BGR_EXT 0x80E0
#define GL_BGRA_EXT 0x80E1
#define GL_MAX_VERTEX_BINDABLE_UNIFORMS_EXT 0x8DE2
#define GL_MAX_FRAGMENT_BINDABLE_UNIFORMS_EXT 0x8DE3
#define GL_MAX_GEOMETRY_BINDABLE_UNIFORMS_EXT 0x8DE4
#define GL_MAX_BINDABLE_UNIFORM_SIZE_EXT 0x8DED
#define GL_UNIFORM_BUFFER_EXT 0x8DEE
#define GL_UNIFORM_BUFFER_BINDING_EXT 0x8DEF
#define GL_CONSTANT_COLOR_EXT 0x8001
#define GL_ONE_MINUS_CONSTANT_COLOR_EXT 0x8002
#define GL_CONSTANT_ALPHA_EXT 0x8003
#define GL_ONE_MINUS_CONSTANT_ALPHA_EXT 0x8004
#define GL_BLEND_COLOR_EXT 0x8005
#define GL_BLEND_EQUATION_RGB_EXT 0x8009
#define GL_BLEND_EQUATION_ALPHA_EXT 0x883D
#define GL_BLEND_DST_RGB_EXT 0x80C8
#define GL_BLEND_SRC_RGB_EXT 0x80C9
#define GL_BLEND_DST_ALPHA_EXT 0x80CA
#define GL_BLEND_SRC_ALPHA_EXT 0x80CB
#define GL_MIN_EXT 0x8007
#define GL_MAX_EXT 0x8008
#define GL_FUNC_ADD_EXT 0x8006
#define GL_BLEND_EQUATION_EXT 0x8009
#define GL_FUNC_SUBTRACT_EXT 0x800A
#define GL_FUNC_REVERSE_SUBTRACT_EXT 0x800B
#define GL_CLIP_VOLUME_CLIPPING_HINT_EXT 0x80F0
#define GL_CMYK_EXT 0x800C
#define GL_CMYKA_EXT 0x800D
#define GL_PACK_CMYK_HINT_EXT 0x800E
#define GL_UNPACK_CMYK_HINT_EXT 0x800F
#define GL_ARRAY_ELEMENT_LOCK_FIRST_EXT 0x81A8
#define GL_ARRAY_ELEMENT_LOCK_COUNT_EXT 0x81A9
#define GL_CONVOLUTION_1D_EXT 0x8010
#define GL_CONVOLUTION_2D_EXT 0x8011
#define GL_SEPARABLE_2D_EXT 0x8012
#define GL_CONVOLUTION_BORDER_MODE_EXT 0x8013
#define GL_CONVOLUTION_FILTER_SCALE_EXT 0x8014
#define GL_CONVOLUTION_FILTER_BIAS_EXT 0x8015
#define GL_REDUCE_EXT 0x8016
#define GL_CONVOLUTION_FORMAT_EXT 0x8017
#define GL_CONVOLUTION_WIDTH_EXT 0x8018
#define GL_CONVOLUTION_HEIGHT_EXT 0x8019
#define GL_MAX_CONVOLUTION_WIDTH_EXT 0x801A
#define GL_MAX_CONVOLUTION_HEIGHT_EXT 0x801B
#define GL_POST_CONVOLUTION_RED_SCALE_EXT 0x801C
#define GL_POST_CONVOLUTION_GREEN_SCALE_EXT 0x801D
#define GL_POST_CONVOLUTION_BLUE_SCALE_EXT 0x801E
#define GL_POST_CONVOLUTION_ALPHA_SCALE_EXT 0x801F
#define GL_POST_CONVOLUTION_RED_BIAS_EXT 0x8020
#define GL_POST_CONVOLUTION_GREEN_BIAS_EXT 0x8021
#define GL_POST_CONVOLUTION_BLUE_BIAS_EXT 0x8022
#define GL_POST_CONVOLUTION_ALPHA_BIAS_EXT 0x8023
#define GL_TANGENT_ARRAY_EXT 0x8439
#define GL_BINORMAL_ARRAY_EXT 0x843A
#define GL_CURRENT_TANGENT_EXT 0x843B
#define GL_CURRENT_BINORMAL_EXT 0x843C
#define GL_TANGENT_ARRAY_TYPE_EXT 0x843E
#define GL_TANGENT_ARRAY_STRIDE_EXT 0x843F
#define GL_BINORMAL_ARRAY_TYPE_EXT 0x8440
#define GL_BINORMAL_ARRAY_STRIDE_EXT 0x8441
#define GL_TANGENT_ARRAY_POINTER_EXT 0x8442
#define GL_BINORMAL_ARRAY_POINTER_EXT 0x8443
#define GL_MAP1_TANGENT_EXT 0x8444
#define GL_MAP2_TANGENT_EXT 0x8445
#define GL_MAP1_BINORMAL_EXT 0x8446
#define GL_MAP2_BINORMAL_EXT 0x8447
#define GL_CULL_VERTEX_EXT 0x81AA
#define GL_CULL_VERTEX_EYE_POSITION_EXT 0x81AB
#define GL_CULL_VERTEX_OBJECT_POSITION_EXT 0x81AC
#define GL_PROGRAM_PIPELINE_OBJECT_EXT 0x8A4F
#define GL_PROGRAM_OBJECT_EXT 0x8B40
#define GL_SHADER_OBJECT_EXT 0x8B48
#define GL_BUFFER_OBJECT_EXT 0x9151
#define GL_QUERY_OBJECT_EXT 0x9153
#define GL_VERTEX_ARRAY_OBJECT_EXT 0x9154
#define GL_SAMPLER 0x82E6
#define GL_DEPTH_BOUNDS_TEST_EXT 0x8890
#define GL_DEPTH_BOUNDS_EXT 0x8891
#define GL_PROGRAM_MATRIX_EXT 0x8E2D
#define GL_TRANSPOSE_PROGRAM_MATRIX_EXT 0x8E2E
#define GL_PROGRAM_MATRIX_STACK_DEPTH_EXT 0x8E2F
#define GL_MAX_ELEMENTS_VERTICES_EXT 0x80E8
#define GL_MAX_ELEMENTS_INDICES_EXT 0x80E9
#define GL_FOG_COORDINATE_SOURCE_EXT 0x8450
#define GL_FOG_COORDINATE_EXT 0x8451
#define GL_FRAGMENT_DEPTH_EXT 0x8452
#define GL_CURRENT_FOG_COORDINATE_EXT 0x8453
#define GL_FOG_COORDINATE_ARRAY_TYPE_EXT 0x8454
#define GL_FOG_COORDINATE_ARRAY_STRIDE_EXT 0x8455
#define GL_FOG_COORDINATE_ARRAY_POINTER_EXT 0x8456
#define GL_FOG_COORDINATE_ARRAY_EXT 0x8457
#define GL_READ_FRAMEBUFFER_EXT 0x8CA8
#define GL_DRAW_FRAMEBUFFER_EXT 0x8CA9
#define GL_DRAW_FRAMEBUFFER_BINDING_EXT 0x8CA6
#define GL_READ_FRAMEBUFFER_BINDING_EXT 0x8CAA
#define GL_RENDERBUFFER_SAMPLES_EXT 0x8CAB
#define GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE_EXT 0x8D56
#define GL_MAX_SAMPLES_EXT 0x8D57
#define GL_SCALED_RESOLVE_FASTEST_EXT 0x90BA
#define GL_SCALED_RESOLVE_NICEST_EXT 0x90BB
#define GL_INVALID_FRAMEBUFFER_OPERATION_EXT 0x0506
#define GL_MAX_RENDERBUFFER_SIZE_EXT 0x84E8
#define GL_FRAMEBUFFER_BINDING_EXT 0x8CA6
#define GL_RENDERBUFFER_BINDING_EXT 0x8CA7
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE_EXT 0x8CD0
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME_EXT 0x8CD1
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL_EXT 0x8CD2
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE_EXT 0x8CD3
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_3D_ZOFFSET_EXT 0x8CD4
#define GL_FRAMEBUFFER_COMPLETE_EXT 0x8CD5
#define GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT_EXT 0x8CD6
#define GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT_EXT 0x8CD7
#define GL_FRAMEBUFFER_INCOMPLETE_DIMENSIONS_EXT 0x8CD9
#define GL_FRAMEBUFFER_INCOMPLETE_FORMATS_EXT 0x8CDA
#define GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER_EXT 0x8CDB
#define GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER_EXT 0x8CDC
#define GL_FRAMEBUFFER_UNSUPPORTED_EXT 0x8CDD
#define GL_MAX_COLOR_ATTACHMENTS_EXT 0x8CDF
#define GL_COLOR_ATTACHMENT0_EXT 0x8CE0
#define GL_COLOR_ATTACHMENT1_EXT 0x8CE1
#define GL_COLOR_ATTACHMENT2_EXT 0x8CE2
#define GL_COLOR_ATTACHMENT3_EXT 0x8CE3
#define GL_COLOR_ATTACHMENT4_EXT 0x8CE4
#define GL_COLOR_ATTACHMENT5_EXT 0x8CE5
#define GL_COLOR_ATTACHMENT6_EXT 0x8CE6
#define GL_COLOR_ATTACHMENT7_EXT 0x8CE7
#define GL_COLOR_ATTACHMENT8_EXT 0x8CE8
#define GL_COLOR_ATTACHMENT9_EXT 0x8CE9
#define GL_COLOR_ATTACHMENT10_EXT 0x8CEA
#define GL_COLOR_ATTACHMENT11_EXT 0x8CEB
#define GL_COLOR_ATTACHMENT12_EXT 0x8CEC
#define GL_COLOR_ATTACHMENT13_EXT 0x8CED
#define GL_COLOR_ATTACHMENT14_EXT 0x8CEE
#define GL_COLOR_ATTACHMENT15_EXT 0x8CEF
#define GL_DEPTH_ATTACHMENT_EXT 0x8D00
#define GL_STENCIL_ATTACHMENT_EXT 0x8D20
#define GL_FRAMEBUFFER_EXT 0x8D40
#define GL_RENDERBUFFER_EXT 0x8D41
#define GL_RENDERBUFFER_WIDTH_EXT 0x8D42
#define GL_RENDERBUFFER_HEIGHT_EXT 0x8D43
#define GL_RENDERBUFFER_INTERNAL_FORMAT_EXT 0x8D44
#define GL_STENCIL_INDEX1_EXT 0x8D46
#define GL_STENCIL_INDEX4_EXT 0x8D47
#define GL_STENCIL_INDEX8_EXT 0x8D48
#define GL_STENCIL_INDEX16_EXT 0x8D49
#define GL_RENDERBUFFER_RED_SIZE_EXT 0x8D50
#define GL_RENDERBUFFER_GREEN_SIZE_EXT 0x8D51
#define GL_RENDERBUFFER_BLUE_SIZE_EXT 0x8D52
#define GL_RENDERBUFFER_ALPHA_SIZE_EXT 0x8D53
#define GL_RENDERBUFFER_DEPTH_SIZE_EXT 0x8D54
#define GL_RENDERBUFFER_STENCIL_SIZE_EXT 0x8D55
#define GL_FRAMEBUFFER_SRGB_EXT 0x8DB9
#define GL_FRAMEBUFFER_SRGB_CAPABLE_EXT 0x8DBA
#define GL_GEOMETRY_SHADER_EXT 0x8DD9
#define GL_GEOMETRY_VERTICES_OUT_EXT 0x8DDA
#define GL_GEOMETRY_INPUT_TYPE_EXT 0x8DDB
#define GL_GEOMETRY_OUTPUT_TYPE_EXT 0x8DDC
#define GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS_EXT 0x8C29
#define GL_MAX_GEOMETRY_VARYING_COMPONENTS_EXT 0x8DDD
#define GL_MAX_VERTEX_VARYING_COMPONENTS_EXT 0x8DDE
#define GL_MAX_VARYING_COMPONENTS_EXT 0x8B4B
#define GL_MAX_GEOMETRY_UNIFORM_COMPONENTS_EXT 0x8DDF
#define GL_MAX_GEOMETRY_OUTPUT_VERTICES_EXT 0x8DE0
#define GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS_EXT 0x8DE1
#define GL_LINES_ADJACENCY_EXT 0x000A
#define GL_LINE_STRIP_ADJACENCY_EXT 0x000B
#define GL_TRIANGLES_ADJACENCY_EXT 0x000C
#define GL_TRIANGLE_STRIP_ADJACENCY_EXT 0x000D
#define GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS_EXT 0x8DA8
#define GL_FRAMEBUFFER_INCOMPLETE_LAYER_COUNT_EXT 0x8DA9
#define GL_FRAMEBUFFER_ATTACHMENT_LAYERED_EXT 0x8DA7
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER_EXT 0x8CD4
#define GL_PROGRAM_POINT_SIZE_EXT 0x8642
#define GL_VERTEX_ATTRIB_ARRAY_INTEGER_EXT 0x88FD
#define GL_SAMPLER_1D_ARRAY_EXT 0x8DC0
#define GL_SAMPLER_2D_ARRAY_EXT 0x8DC1
#define GL_SAMPLER_BUFFER_EXT 0x8DC2
#define GL_SAMPLER_1D_ARRAY_SHADOW_EXT 0x8DC3
#define GL_SAMPLER_2D_ARRAY_SHADOW_EXT 0x8DC4
#define GL_SAMPLER_CUBE_SHADOW_EXT 0x8DC5
#define GL_UNSIGNED_INT_VEC2_EXT 0x8DC6
#define GL_UNSIGNED_INT_VEC3_EXT 0x8DC7
#define GL_UNSIGNED_INT_VEC4_EXT 0x8DC8
#define GL_INT_SAMPLER_1D_EXT 0x8DC9
#define GL_INT_SAMPLER_2D_EXT 0x8DCA
#define GL_INT_SAMPLER_3D_EXT 0x8DCB
#define GL_INT_SAMPLER_CUBE_EXT 0x8DCC
#define GL_INT_SAMPLER_2D_RECT_EXT 0x8DCD
#define GL_INT_SAMPLER_1D_ARRAY_EXT 0x8DCE
#define GL_INT_SAMPLER_2D_ARRAY_EXT 0x8DCF
#define GL_INT_SAMPLER_BUFFER_EXT 0x8DD0
#define GL_UNSIGNED_INT_SAMPLER_1D_EXT 0x8DD1
#define GL_UNSIGNED_INT_SAMPLER_2D_EXT 0x8DD2
#define GL_UNSIGNED_INT_SAMPLER_3D_EXT 0x8DD3
#define GL_UNSIGNED_INT_SAMPLER_CUBE_EXT 0x8DD4
#define GL_UNSIGNED_INT_SAMPLER_2D_RECT_EXT 0x8DD5
#define GL_UNSIGNED_INT_SAMPLER_1D_ARRAY_EXT 0x8DD6
#define GL_UNSIGNED_INT_SAMPLER_2D_ARRAY_EXT 0x8DD7
#define GL_UNSIGNED_INT_SAMPLER_BUFFER_EXT 0x8DD8
#define GL_MIN_PROGRAM_TEXEL_OFFSET_EXT 0x8904
#define GL_MAX_PROGRAM_TEXEL_OFFSET_EXT 0x8905
#define GL_HISTOGRAM_EXT 0x8024
#define GL_PROXY_HISTOGRAM_EXT 0x8025
#define GL_HISTOGRAM_WIDTH_EXT 0x8026
#define GL_HISTOGRAM_FORMAT_EXT 0x8027
#define GL_HISTOGRAM_RED_SIZE_EXT 0x8028
#define GL_HISTOGRAM_GREEN_SIZE_EXT 0x8029
#define GL_HISTOGRAM_BLUE_SIZE_EXT 0x802A
#define GL_HISTOGRAM_ALPHA_SIZE_EXT 0x802B
#define GL_HISTOGRAM_LUMINANCE_SIZE_EXT 0x802C
#define GL_HISTOGRAM_SINK_EXT 0x802D
#define GL_MINMAX_EXT 0x802E
#define GL_MINMAX_FORMAT_EXT 0x802F
#define GL_MINMAX_SINK_EXT 0x8030
#define GL_TABLE_TOO_LARGE_EXT 0x8031
#define GL_IUI_V2F_EXT 0x81AD
#define GL_IUI_V3F_EXT 0x81AE
#define GL_IUI_N3F_V2F_EXT 0x81AF
#define GL_IUI_N3F_V3F_EXT 0x81B0
#define GL_T2F_IUI_V2F_EXT 0x81B1
#define GL_T2F_IUI_V3F_EXT 0x81B2
#define GL_T2F_IUI_N3F_V2F_EXT 0x81B3
#define GL_T2F_IUI_N3F_V3F_EXT 0x81B4
#define GL_INDEX_TEST_EXT 0x81B5
#define GL_INDEX_TEST_FUNC_EXT 0x81B6
#define GL_INDEX_TEST_REF_EXT 0x81B7
#define GL_INDEX_MATERIAL_EXT 0x81B8
#define GL_INDEX_MATERIAL_PARAMETER_EXT 0x81B9
#define GL_INDEX_MATERIAL_FACE_EXT 0x81BA
#define GL_FRAGMENT_MATERIAL_EXT 0x8349
#define GL_FRAGMENT_NORMAL_EXT 0x834A
#define GL_FRAGMENT_COLOR_EXT 0x834C
#define GL_ATTENUATION_EXT 0x834D
#define GL_SHADOW_ATTENUATION_EXT 0x834E
#define GL_TEXTURE_APPLICATION_MODE_EXT 0x834F
#define GL_TEXTURE_LIGHT_EXT 0x8350
#define GL_TEXTURE_MATERIAL_FACE_EXT 0x8351
#define GL_TEXTURE_MATERIAL_PARAMETER_EXT 0x8352
#define GL_MULTISAMPLE_EXT 0x809D
#define GL_SAMPLE_ALPHA_TO_MASK_EXT 0x809E
#define GL_SAMPLE_ALPHA_TO_ONE_EXT 0x809F
#define GL_SAMPLE_MASK_EXT 0x80A0
#define GL_1PASS_EXT 0x80A1
#define GL_2PASS_0_EXT 0x80A2
#define GL_2PASS_1_EXT 0x80A3
#define GL_4PASS_0_EXT 0x80A4
#define GL_4PASS_1_EXT 0x80A5
#define GL_4PASS_2_EXT 0x80A6
#define GL_4PASS_3_EXT 0x80A7
#define GL_SAMPLE_BUFFERS_EXT 0x80A8
#define GL_SAMPLES_EXT 0x80A9
#define GL_SAMPLE_MASK_VALUE_EXT 0x80AA
#define GL_SAMPLE_MASK_INVERT_EXT 0x80AB
#define GL_SAMPLE_PATTERN_EXT 0x80AC
#define GL_MULTISAMPLE_BIT_EXT 0x20000000
#define GL_DEPTH_STENCIL_EXT 0x84F9
#define GL_UNSIGNED_INT_24_8_EXT 0x84FA
#define GL_DEPTH24_STENCIL8_EXT 0x88F0
#define GL_TEXTURE_STENCIL_SIZE_EXT 0x88F1
#define GL_R11F_G11F_B10F_EXT 0x8C3A
#define GL_UNSIGNED_INT_10F_11F_11F_REV_EXT 0x8C3B
#define GL_RGBA_SIGNED_COMPONENTS_EXT 0x8C3C
#define GL_UNSIGNED_BYTE_3_3_2_EXT 0x8032
#define GL_UNSIGNED_SHORT_4_4_4_4_EXT 0x8033
#define GL_UNSIGNED_SHORT_5_5_5_1_EXT 0x8034
#define GL_UNSIGNED_INT_8_8_8_8_EXT 0x8035
#define GL_UNSIGNED_INT_10_10_10_2_EXT 0x8036
#define GL_COLOR_INDEX1_EXT 0x80E2
#define GL_COLOR_INDEX2_EXT 0x80E3
#define GL_COLOR_INDEX4_EXT 0x80E4
#define GL_COLOR_INDEX8_EXT 0x80E5
#define GL_COLOR_INDEX12_EXT 0x80E6
#define GL_COLOR_INDEX16_EXT 0x80E7
#define GL_TEXTURE_INDEX_SIZE_EXT 0x80ED
#define GL_PIXEL_PACK_BUFFER_EXT 0x88EB
#define GL_PIXEL_UNPACK_BUFFER_EXT 0x88EC
#define GL_PIXEL_PACK_BUFFER_BINDING_EXT 0x88ED
#define GL_PIXEL_UNPACK_BUFFER_BINDING_EXT 0x88EF
#define GL_PIXEL_TRANSFORM_2D_EXT 0x8330
#define GL_PIXEL_MAG_FILTER_EXT 0x8331
#define GL_PIXEL_MIN_FILTER_EXT 0x8332
#define GL_PIXEL_CUBIC_WEIGHT_EXT 0x8333
#define GL_CUBIC_EXT 0x8334
#define GL_AVERAGE_EXT 0x8335
#define GL_PIXEL_TRANSFORM_2D_STACK_DEPTH_EXT 0x8336
#define GL_MAX_PIXEL_TRANSFORM_2D_STACK_DEPTH_EXT 0x8337
#define GL_PIXEL_TRANSFORM_2D_MATRIX_EXT 0x8338
#define GL_POINT_SIZE_MIN_EXT 0x8126
#define GL_POINT_SIZE_MAX_EXT 0x8127
#define GL_POINT_FADE_THRESHOLD_SIZE_EXT 0x8128
#define GL_DISTANCE_ATTENUATION_EXT 0x8129
#define GL_POLYGON_OFFSET_EXT 0x8037
#define GL_POLYGON_OFFSET_FACTOR_EXT 0x8038
#define GL_POLYGON_OFFSET_BIAS_EXT 0x8039
#define GL_POLYGON_OFFSET_CLAMP_EXT 0x8E1B
#define GL_QUADS_FOLLOW_PROVOKING_VERTEX_CONVENTION_EXT 0x8E4C
#define GL_FIRST_VERTEX_CONVENTION_EXT 0x8E4D
#define GL_LAST_VERTEX_CONVENTION_EXT 0x8E4E
#define GL_PROVOKING_VERTEX_EXT 0x8E4F
#define GL_RASTER_MULTISAMPLE_EXT 0x9327
#define GL_RASTER_SAMPLES_EXT 0x9328
#define GL_MAX_RASTER_SAMPLES_EXT 0x9329
#define GL_RASTER_FIXED_SAMPLE_LOCATIONS_EXT 0x932A
#define GL_MULTISAMPLE_RASTERIZATION_ALLOWED_EXT 0x932B
#define GL_EFFECTIVE_RASTER_SAMPLES_EXT 0x932C
#define GL_RESCALE_NORMAL_EXT 0x803A
#define GL_COLOR_SUM_EXT 0x8458
#define GL_CURRENT_SECONDARY_COLOR_EXT 0x8459
#define GL_SECONDARY_COLOR_ARRAY_SIZE_EXT 0x845A
#define GL_SECONDARY_COLOR_ARRAY_TYPE_EXT 0x845B
#define GL_SECONDARY_COLOR_ARRAY_STRIDE_EXT 0x845C
#define GL_SECONDARY_COLOR_ARRAY_POINTER_EXT 0x845D
#define GL_SECONDARY_COLOR_ARRAY_EXT 0x845E
#define GL_ACTIVE_PROGRAM_EXT 0x8B8D
#define GL_VERTEX_SHADER_BIT_EXT 0x00000001
#define GL_FRAGMENT_SHADER_BIT_EXT 0x00000002
#define GL_ALL_SHADER_BITS_EXT 0xFFFFFFFF
#define GL_PROGRAM_SEPARABLE_EXT 0x8258
#define GL_PROGRAM_PIPELINE_BINDING_EXT 0x825A
#define GL_LIGHT_MODEL_COLOR_CONTROL_EXT 0x81F8
#define GL_SINGLE_COLOR_EXT 0x81F9
#define GL_SEPARATE_SPECULAR_COLOR_EXT 0x81FA
#define GL_MAX_IMAGE_UNITS_EXT 0x8F38
#define GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS_EXT 0x8F39
#define GL_IMAGE_BINDING_NAME_EXT 0x8F3A
#define GL_IMAGE_BINDING_LEVEL_EXT 0x8F3B
#define GL_IMAGE_BINDING_LAYERED_EXT 0x8F3C
#define GL_IMAGE_BINDING_LAYER_EXT 0x8F3D
#define GL_IMAGE_BINDING_ACCESS_EXT 0x8F3E
#define GL_IMAGE_1D_EXT 0x904C
#define GL_IMAGE_2D_EXT 0x904D
#define GL_IMAGE_3D_EXT 0x904E
#define GL_IMAGE_2D_RECT_EXT 0x904F
#define GL_IMAGE_CUBE_EXT 0x9050
#define GL_IMAGE_BUFFER_EXT 0x9051
#define GL_IMAGE_1D_ARRAY_EXT 0x9052
#define GL_IMAGE_2D_ARRAY_EXT 0x9053
#define GL_IMAGE_CUBE_MAP_ARRAY_EXT 0x9054
#define GL_IMAGE_2D_MULTISAMPLE_EXT 0x9055
#define GL_IMAGE_2D_MULTISAMPLE_ARRAY_EXT 0x9056
#define GL_INT_IMAGE_1D_EXT 0x9057
#define GL_INT_IMAGE_2D_EXT 0x9058
#define GL_INT_IMAGE_3D_EXT 0x9059
#define GL_INT_IMAGE_2D_RECT_EXT 0x905A
#define GL_INT_IMAGE_CUBE_EXT 0x905B
#define GL_INT_IMAGE_BUFFER_EXT 0x905C
#define GL_INT_IMAGE_1D_ARRAY_EXT 0x905D
#define GL_INT_IMAGE_2D_ARRAY_EXT 0x905E
#define GL_INT_IMAGE_CUBE_MAP_ARRAY_EXT 0x905F
#define GL_INT_IMAGE_2D_MULTISAMPLE_EXT 0x9060
#define GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY_EXT 0x9061
#define GL_UNSIGNED_INT_IMAGE_1D_EXT 0x9062
#define GL_UNSIGNED_INT_IMAGE_2D_EXT 0x9063
#define GL_UNSIGNED_INT_IMAGE_3D_EXT 0x9064
#define GL_UNSIGNED_INT_IMAGE_2D_RECT_EXT 0x9065
#define GL_UNSIGNED_INT_IMAGE_CUBE_EXT 0x9066
#define GL_UNSIGNED_INT_IMAGE_BUFFER_EXT 0x9067
#define GL_UNSIGNED_INT_IMAGE_1D_ARRAY_EXT 0x9068
#define GL_UNSIGNED_INT_IMAGE_2D_ARRAY_EXT 0x9069
#define GL_UNSIGNED_INT_IMAGE_CUBE_MAP_ARRAY_EXT 0x906A
#define GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_EXT 0x906B
#define GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY_EXT 0x906C
#define GL_MAX_IMAGE_SAMPLES_EXT 0x906D
#define GL_IMAGE_BINDING_FORMAT_EXT 0x906E
#define GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT_EXT 0x00000001
#define GL_ELEMENT_ARRAY_BARRIER_BIT_EXT 0x00000002
#define GL_UNIFORM_BARRIER_BIT_EXT 0x00000004
#define GL_TEXTURE_FETCH_BARRIER_BIT_EXT 0x00000008
#define GL_SHADER_IMAGE_ACCESS_BARRIER_BIT_EXT 0x00000020
#define GL_COMMAND_BARRIER_BIT_EXT 0x00000040
#define GL_PIXEL_BUFFER_BARRIER_BIT_EXT 0x00000080
#define GL_TEXTURE_UPDATE_BARRIER_BIT_EXT 0x00000100
#define GL_BUFFER_UPDATE_BARRIER_BIT_EXT 0x00000200
#define GL_FRAMEBUFFER_BARRIER_BIT_EXT 0x00000400
#define GL_TRANSFORM_FEEDBACK_BARRIER_BIT_EXT 0x00000800
#define GL_ATOMIC_COUNTER_BARRIER_BIT_EXT 0x00001000
#define GL_ALL_BARRIER_BITS_EXT 0xFFFFFFFF
#define GL_SHARED_TEXTURE_PALETTE_EXT 0x81FB
#define GL_STENCIL_TAG_BITS_EXT 0x88F2
#define GL_STENCIL_CLEAR_TAG_VALUE_EXT 0x88F3
#define GL_STENCIL_TEST_TWO_SIDE_EXT 0x8910
#define GL_ACTIVE_STENCIL_FACE_EXT 0x8911
#define GL_INCR_WRAP_EXT 0x8507
#define GL_DECR_WRAP_EXT 0x8508
#define GL_ALPHA4_EXT 0x803B
#define GL_ALPHA8_EXT 0x803C
#define GL_ALPHA12_EXT 0x803D
#define GL_ALPHA16_EXT 0x803E
#define GL_LUMINANCE4_EXT 0x803F
#define GL_LUMINANCE8_EXT 0x8040
#define GL_LUMINANCE12_EXT 0x8041
#define GL_LUMINANCE16_EXT 0x8042
#define GL_LUMINANCE4_ALPHA4_EXT 0x8043
#define GL_LUMINANCE6_ALPHA2_EXT 0x8044
#define GL_LUMINANCE8_ALPHA8_EXT 0x8045
#define GL_LUMINANCE12_ALPHA4_EXT 0x8046
#define GL_LUMINANCE12_ALPHA12_EXT 0x8047
#define GL_LUMINANCE16_ALPHA16_EXT 0x8048
#define GL_INTENSITY_EXT 0x8049
#define GL_INTENSITY4_EXT 0x804A
#define GL_INTENSITY8_EXT 0x804B
#define GL_INTENSITY12_EXT 0x804C
#define GL_INTENSITY16_EXT 0x804D
#define GL_RGB2_EXT 0x804E
#define GL_RGB4_EXT 0x804F
#define GL_RGB5_EXT 0x8050
#define GL_RGB8_EXT 0x8051
#define GL_RGB10_EXT 0x8052
#define GL_RGB12_EXT 0x8053
#define GL_RGB16_EXT 0x8054
#define GL_RGBA2_EXT 0x8055
#define GL_RGBA4_EXT 0x8056
#define GL_RGB5_A1_EXT 0x8057
#define GL_RGBA8_EXT 0x8058
#define GL_RGB10_A2_EXT 0x8059
#define GL_RGBA12_EXT 0x805A
#define GL_RGBA16_EXT 0x805B
#define GL_TEXTURE_RED_SIZE_EXT 0x805C
#define GL_TEXTURE_GREEN_SIZE_EXT 0x805D
#define GL_TEXTURE_BLUE_SIZE_EXT 0x805E
#define GL_TEXTURE_ALPHA_SIZE_EXT 0x805F
#define GL_TEXTURE_LUMINANCE_SIZE_EXT 0x8060
#define GL_TEXTURE_INTENSITY_SIZE_EXT 0x8061
#define GL_REPLACE_EXT 0x8062
#define GL_PROXY_TEXTURE_1D_EXT 0x8063
#define GL_PROXY_TEXTURE_2D_EXT 0x8064
#define GL_TEXTURE_TOO_LARGE_EXT 0x8065
#define GL_PACK_SKIP_IMAGES_EXT 0x806B
#define GL_PACK_IMAGE_HEIGHT_EXT 0x806C
#define GL_UNPACK_SKIP_IMAGES_EXT 0x806D
#define GL_UNPACK_IMAGE_HEIGHT_EXT 0x806E
#define GL_TEXTURE_3D_EXT 0x806F
#define GL_PROXY_TEXTURE_3D_EXT 0x8070
#define GL_TEXTURE_DEPTH_EXT 0x8071
#define GL_TEXTURE_WRAP_R_EXT 0x8072
#define GL_MAX_3D_TEXTURE_SIZE_EXT 0x8073
#define GL_TEXTURE_1D_ARRAY_EXT 0x8C18
#define GL_PROXY_TEXTURE_1D_ARRAY_EXT 0x8C19
#define GL_TEXTURE_2D_ARRAY_EXT 0x8C1A
#define GL_PROXY_TEXTURE_2D_ARRAY_EXT 0x8C1B
#define GL_TEXTURE_BINDING_1D_ARRAY_EXT 0x8C1C
#define GL_TEXTURE_BINDING_2D_ARRAY_EXT 0x8C1D
#define GL_MAX_ARRAY_TEXTURE_LAYERS_EXT 0x88FF
#define GL_COMPARE_REF_DEPTH_TO_TEXTURE_EXT 0x884E
#define GL_TEXTURE_BUFFER_EXT 0x8C2A
#define GL_MAX_TEXTURE_BUFFER_SIZE_EXT 0x8C2B
#define GL_TEXTURE_BINDING_BUFFER_EXT 0x8C2C
#define GL_TEXTURE_BUFFER_DATA_STORE_BINDING_EXT 0x8C2D
#define GL_TEXTURE_BUFFER_FORMAT_EXT 0x8C2E
#define GL_COMPRESSED_LUMINANCE_LATC1_EXT 0x8C70
#define GL_COMPRESSED_SIGNED_LUMINANCE_LATC1_EXT 0x8C71
#define GL_COMPRESSED_LUMINANCE_ALPHA_LATC2_EXT 0x8C72
#define GL_COMPRESSED_SIGNED_LUMINANCE_ALPHA_LATC2_EXT 0x8C73
#define GL_COMPRESSED_RED_RGTC1_EXT 0x8DBB
#define GL_COMPRESSED_SIGNED_RED_RGTC1_EXT 0x8DBC
#define GL_COMPRESSED_RED_GREEN_RGTC2_EXT 0x8DBD
#define GL_COMPRESSED_SIGNED_RED_GREEN_RGTC2_EXT 0x8DBE
#define GL_COMPRESSED_RGB_S3TC_DXT1_EXT 0x83F0
#define GL_COMPRESSED_RGBA_S3TC_DXT1_EXT 0x83F1
#define GL_COMPRESSED_RGBA_S3TC_DXT3_EXT 0x83F2
#define GL_COMPRESSED_RGBA_S3TC_DXT5_EXT 0x83F3
#define GL_NORMAL_MAP_EXT 0x8511
#define GL_REFLECTION_MAP_EXT 0x8512
#define GL_TEXTURE_CUBE_MAP_EXT 0x8513
#define GL_TEXTURE_BINDING_CUBE_MAP_EXT 0x8514
#define GL_TEXTURE_CUBE_MAP_POSITIVE_X_EXT 0x8515
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_X_EXT 0x8516
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Y_EXT 0x8517
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Y_EXT 0x8518
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Z_EXT 0x8519
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Z_EXT 0x851A
#define GL_PROXY_TEXTURE_CUBE_MAP_EXT 0x851B
#define GL_MAX_CUBE_MAP_TEXTURE_SIZE_EXT 0x851C
#define GL_COMBINE_EXT 0x8570
#define GL_COMBINE_RGB_EXT 0x8571
#define GL_COMBINE_ALPHA_EXT 0x8572
#define GL_RGB_SCALE_EXT 0x8573
#define GL_ADD_SIGNED_EXT 0x8574
#define GL_INTERPOLATE_EXT 0x8575
#define GL_CONSTANT_EXT 0x8576
#define GL_PRIMARY_COLOR_EXT 0x8577
#define GL_PREVIOUS_EXT 0x8578
#define GL_SOURCE0_RGB_EXT 0x8580
#define GL_SOURCE1_RGB_EXT 0x8581
#define GL_SOURCE2_RGB_EXT 0x8582
#define GL_SOURCE0_ALPHA_EXT 0x8588
#define GL_SOURCE1_ALPHA_EXT 0x8589
#define GL_SOURCE2_ALPHA_EXT 0x858A
#define GL_OPERAND0_RGB_EXT 0x8590
#define GL_OPERAND1_RGB_EXT 0x8591
#define GL_OPERAND2_RGB_EXT 0x8592
#define GL_OPERAND0_ALPHA_EXT 0x8598
#define GL_OPERAND1_ALPHA_EXT 0x8599
#define GL_OPERAND2_ALPHA_EXT 0x859A
#define GL_DOT3_RGB_EXT 0x8740
#define GL_DOT3_RGBA_EXT 0x8741
#define GL_TEXTURE_MAX_ANISOTROPY_EXT 0x84FE
#define GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT 0x84FF
#define GL_RGBA32UI_EXT 0x8D70
#define GL_RGB32UI_EXT 0x8D71
#define GL_ALPHA32UI_EXT 0x8D72
#define GL_INTENSITY32UI_EXT 0x8D73
#define GL_LUMINANCE32UI_EXT 0x8D74
#define GL_LUMINANCE_ALPHA32UI_EXT 0x8D75
#define GL_RGBA16UI_EXT 0x8D76
#define GL_RGB16UI_EXT 0x8D77
#define GL_ALPHA16UI_EXT 0x8D78
#define GL_INTENSITY16UI_EXT 0x8D79
#define GL_LUMINANCE16UI_EXT 0x8D7A
#define GL_LUMINANCE_ALPHA16UI_EXT 0x8D7B
#define GL_RGBA8UI_EXT 0x8D7C
#define GL_RGB8UI_EXT 0x8D7D
#define GL_ALPHA8UI_EXT 0x8D7E
#define GL_INTENSITY8UI_EXT 0x8D7F
#define GL_LUMINANCE8UI_EXT 0x8D80
#define GL_LUMINANCE_ALPHA8UI_EXT 0x8D81
#define GL_RGBA32I_EXT 0x8D82
#define GL_RGB32I_EXT 0x8D83
#define GL_ALPHA32I_EXT 0x8D84
#define GL_INTENSITY32I_EXT 0x8D85
#define GL_LUMINANCE32I_EXT 0x8D86
#define GL_LUMINANCE_ALPHA32I_EXT 0x8D87
#define GL_RGBA16I_EXT 0x8D88
#define GL_RGB16I_EXT 0x8D89
#define GL_ALPHA16I_EXT 0x8D8A
#define GL_INTENSITY16I_EXT 0x8D8B
#define GL_LUMINANCE16I_EXT 0x8D8C
#define GL_LUMINANCE_ALPHA16I_EXT 0x8D8D
#define GL_RGBA8I_EXT 0x8D8E
#define GL_RGB8I_EXT 0x8D8F
#define GL_ALPHA8I_EXT 0x8D90
#define GL_INTENSITY8I_EXT 0x8D91
#define GL_LUMINANCE8I_EXT 0x8D92
#define GL_LUMINANCE_ALPHA8I_EXT 0x8D93
#define GL_RED_INTEGER_EXT 0x8D94
#define GL_GREEN_INTEGER_EXT 0x8D95
#define GL_BLUE_INTEGER_EXT 0x8D96
#define GL_ALPHA_INTEGER_EXT 0x8D97
#define GL_RGB_INTEGER_EXT 0x8D98
#define GL_RGBA_INTEGER_EXT 0x8D99
#define GL_BGR_INTEGER_EXT 0x8D9A
#define GL_BGRA_INTEGER_EXT 0x8D9B
#define GL_LUMINANCE_INTEGER_EXT 0x8D9C
#define GL_LUMINANCE_ALPHA_INTEGER_EXT 0x8D9D
#define GL_RGBA_INTEGER_MODE_EXT 0x8D9E
#define GL_MAX_TEXTURE_LOD_BIAS_EXT 0x84FD
#define GL_TEXTURE_FILTER_CONTROL_EXT 0x8500
#define GL_TEXTURE_LOD_BIAS_EXT 0x8501
#define GL_MIRROR_CLAMP_EXT 0x8742
#define GL_MIRROR_CLAMP_TO_EDGE_EXT 0x8743
#define GL_MIRROR_CLAMP_TO_BORDER_EXT 0x8912
#define GL_TEXTURE_PRIORITY_EXT 0x8066
#define GL_TEXTURE_RESIDENT_EXT 0x8067
#define GL_TEXTURE_1D_BINDING_EXT 0x8068
#define GL_TEXTURE_2D_BINDING_EXT 0x8069
#define GL_TEXTURE_3D_BINDING_EXT 0x806A
#define GL_PERTURB_EXT 0x85AE
#define GL_TEXTURE_NORMAL_EXT 0x85AF
#define GL_SRGB_EXT 0x8C40
#define GL_SRGB8_EXT 0x8C41
#define GL_SRGB_ALPHA_EXT 0x8C42
#define GL_SRGB8_ALPHA8_EXT 0x8C43
#define GL_SLUMINANCE_ALPHA_EXT 0x8C44
#define GL_SLUMINANCE8_ALPHA8_EXT 0x8C45
#define GL_SLUMINANCE_EXT 0x8C46
#define GL_SLUMINANCE8_EXT 0x8C47
#define GL_COMPRESSED_SRGB_EXT 0x8C48
#define GL_COMPRESSED_SRGB_ALPHA_EXT 0x8C49
#define GL_COMPRESSED_SLUMINANCE_EXT 0x8C4A
#define GL_COMPRESSED_SLUMINANCE_ALPHA_EXT 0x8C4B
#define GL_COMPRESSED_SRGB_S3TC_DXT1_EXT 0x8C4C
#define GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT1_EXT 0x8C4D
#define GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT3_EXT 0x8C4E
#define GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT5_EXT 0x8C4F
#define GL_TEXTURE_SRGB_DECODE_EXT 0x8A48
#define GL_DECODE_EXT 0x8A49
#define GL_SKIP_DECODE_EXT 0x8A4A
#define GL_RGB9_E5_EXT 0x8C3D
#define GL_UNSIGNED_INT_5_9_9_9_REV_EXT 0x8C3E
#define GL_TEXTURE_SHARED_SIZE_EXT 0x8C3F
#define GL_ALPHA_SNORM 0x9010
#define GL_LUMINANCE_SNORM 0x9011
#define GL_LUMINANCE_ALPHA_SNORM 0x9012
#define GL_INTENSITY_SNORM 0x9013
#define GL_ALPHA8_SNORM 0x9014
#define GL_LUMINANCE8_SNORM 0x9015
#define GL_LUMINANCE8_ALPHA8_SNORM 0x9016
#define GL_INTENSITY8_SNORM 0x9017
#define GL_ALPHA16_SNORM 0x9018
#define GL_LUMINANCE16_SNORM 0x9019
#define GL_LUMINANCE16_ALPHA16_SNORM 0x901A
#define GL_INTENSITY16_SNORM 0x901B
#define GL_RED_SNORM 0x8F90
#define GL_RG_SNORM 0x8F91
#define GL_RGB_SNORM 0x8F92
#define GL_RGBA_SNORM 0x8F93
#define GL_R8_SNORM 0x8F94
#define GL_RG8_SNORM 0x8F95
#define GL_RGB8_SNORM 0x8F96
#define GL_RGBA8_SNORM 0x8F97
#define GL_R16_SNORM 0x8F98
#define GL_RG16_SNORM 0x8F99
#define GL_RGB16_SNORM 0x8F9A
#define GL_RGBA16_SNORM 0x8F9B
#define GL_SIGNED_NORMALIZED 0x8F9C
#define GL_TEXTURE_SWIZZLE_R_EXT 0x8E42
#define GL_TEXTURE_SWIZZLE_G_EXT 0x8E43
#define GL_TEXTURE_SWIZZLE_B_EXT 0x8E44
#define GL_TEXTURE_SWIZZLE_A_EXT 0x8E45
#define GL_TEXTURE_SWIZZLE_RGBA_EXT 0x8E46
#define GL_TIME_ELAPSED_EXT 0x88BF
#define GL_TRANSFORM_FEEDBACK_BUFFER_EXT 0x8C8E
#define GL_TRANSFORM_FEEDBACK_BUFFER_START_EXT 0x8C84
#define GL_TRANSFORM_FEEDBACK_BUFFER_SIZE_EXT 0x8C85
#define GL_TRANSFORM_FEEDBACK_BUFFER_BINDING_EXT 0x8C8F
#define GL_INTERLEAVED_ATTRIBS_EXT 0x8C8C
#define GL_SEPARATE_ATTRIBS_EXT 0x8C8D
#define GL_PRIMITIVES_GENERATED_EXT 0x8C87
#define GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN_EXT 0x8C88
#define GL_RASTERIZER_DISCARD_EXT 0x8C89
#define GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS_EXT 0x8C8A
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS_EXT 0x8C8B
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS_EXT 0x8C80
#define GL_TRANSFORM_FEEDBACK_VARYINGS_EXT 0x8C83
#define GL_TRANSFORM_FEEDBACK_BUFFER_MODE_EXT 0x8C7F
#define GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH_EXT 0x8C76
#define GL_VERTEX_ARRAY_EXT 0x8074
#define GL_NORMAL_ARRAY_EXT 0x8075
#define GL_COLOR_ARRAY_EXT 0x8076
#define GL_INDEX_ARRAY_EXT 0x8077
#define GL_TEXTURE_COORD_ARRAY_EXT 0x8078
#define GL_EDGE_FLAG_ARRAY_EXT 0x8079
#define GL_VERTEX_ARRAY_SIZE_EXT 0x807A
#define GL_VERTEX_ARRAY_TYPE_EXT 0x807B
#define GL_VERTEX_ARRAY_STRIDE_EXT 0x807C
#define GL_VERTEX_ARRAY_COUNT_EXT 0x807D
#define GL_NORMAL_ARRAY_TYPE_EXT 0x807E
#define GL_NORMAL_ARRAY_STRIDE_EXT 0x807F
#define GL_NORMAL_ARRAY_COUNT_EXT 0x8080
#define GL_COLOR_ARRAY_SIZE_EXT 0x8081
#define GL_COLOR_ARRAY_TYPE_EXT 0x8082
#define GL_COLOR_ARRAY_STRIDE_EXT 0x8083
#define GL_COLOR_ARRAY_COUNT_EXT 0x8084
#define GL_INDEX_ARRAY_TYPE_EXT 0x8085
#define GL_INDEX_ARRAY_STRIDE_EXT 0x8086
#define GL_INDEX_ARRAY_COUNT_EXT 0x8087
#define GL_TEXTURE_COORD_ARRAY_SIZE_EXT 0x8088
#define GL_TEXTURE_COORD_ARRAY_TYPE_EXT 0x8089
#define GL_TEXTURE_COORD_ARRAY_STRIDE_EXT 0x808A
#define GL_TEXTURE_COORD_ARRAY_COUNT_EXT 0x808B
#define GL_EDGE_FLAG_ARRAY_STRIDE_EXT 0x808C
#define GL_EDGE_FLAG_ARRAY_COUNT_EXT 0x808D
#define GL_VERTEX_ARRAY_POINTER_EXT 0x808E
#define GL_NORMAL_ARRAY_POINTER_EXT 0x808F
#define GL_COLOR_ARRAY_POINTER_EXT 0x8090
#define GL_INDEX_ARRAY_POINTER_EXT 0x8091
#define GL_TEXTURE_COORD_ARRAY_POINTER_EXT 0x8092
#define GL_EDGE_FLAG_ARRAY_POINTER_EXT 0x8093
#define GL_DOUBLE_VEC2_EXT 0x8FFC
#define GL_DOUBLE_VEC3_EXT 0x8FFD
#define GL_DOUBLE_VEC4_EXT 0x8FFE
#define GL_DOUBLE_MAT2_EXT 0x8F46
#define GL_DOUBLE_MAT3_EXT 0x8F47
#define GL_DOUBLE_MAT4_EXT 0x8F48
#define GL_DOUBLE_MAT2x3_EXT 0x8F49
#define GL_DOUBLE_MAT2x4_EXT 0x8F4A
#define GL_DOUBLE_MAT3x2_EXT 0x8F4B
#define GL_DOUBLE_MAT3x4_EXT 0x8F4C
#define GL_DOUBLE_MAT4x2_EXT 0x8F4D
#define GL_DOUBLE_MAT4x3_EXT 0x8F4E
#define GL_VERTEX_SHADER_EXT 0x8780
#define GL_VERTEX_SHADER_BINDING_EXT 0x8781
#define GL_OP_INDEX_EXT 0x8782
#define GL_OP_NEGATE_EXT 0x8783
#define GL_OP_DOT3_EXT 0x8784
#define GL_OP_DOT4_EXT 0x8785
#define GL_OP_MUL_EXT 0x8786
#define GL_OP_ADD_EXT 0x8787
#define GL_OP_MADD_EXT 0x8788
#define GL_OP_FRAC_EXT 0x8789
#define GL_OP_MAX_EXT 0x878A
#define GL_OP_MIN_EXT 0x878B
#define GL_OP_SET_GE_EXT 0x878C
#define GL_OP_SET_LT_EXT 0x878D
#define GL_OP_CLAMP_EXT 0x878E
#define GL_OP_FLOOR_EXT 0x878F
#define GL_OP_ROUND_EXT 0x8790
#define GL_OP_EXP_BASE_2_EXT 0x8791
#define GL_OP_LOG_BASE_2_EXT 0x8792
#define GL_OP_POWER_EXT 0x8793
#define GL_OP_RECIP_EXT 0x8794
#define GL_OP_RECIP_SQRT_EXT 0x8795
#define GL_OP_SUB_EXT 0x8796
#define GL_OP_CROSS_PRODUCT_EXT 0x8797
#define GL_OP_MULTIPLY_MATRIX_EXT 0x8798
#define GL_OP_MOV_EXT 0x8799
#define GL_OUTPUT_VERTEX_EXT 0x879A
#define GL_OUTPUT_COLOR0_EXT 0x879B
#define GL_OUTPUT_COLOR1_EXT 0x879C
#define GL_OUTPUT_TEXTURE_COORD0_EXT 0x879D
#define GL_OUTPUT_TEXTURE_COORD1_EXT 0x879E
#define GL_OUTPUT_TEXTURE_COORD2_EXT 0x879F
#define GL_OUTPUT_TEXTURE_COORD3_EXT 0x87A0
#define GL_OUTPUT_TEXTURE_COORD4_EXT 0x87A1
#define GL_OUTPUT_TEXTURE_COORD5_EXT 0x87A2
#define GL_OUTPUT_TEXTURE_COORD6_EXT 0x87A3
#define GL_OUTPUT_TEXTURE_COORD7_EXT 0x87A4
#define GL_OUTPUT_TEXTURE_COORD8_EXT 0x87A5
#define GL_OUTPUT_TEXTURE_COORD9_EXT 0x87A6
#define GL_OUTPUT_TEXTURE_COORD10_EXT 0x87A7
#define GL_OUTPUT_TEXTURE_COORD11_EXT 0x87A8
#define GL_OUTPUT_TEXTURE_COORD12_EXT 0x87A9
#define GL_OUTPUT_TEXTURE_COORD13_EXT 0x87AA
#define GL_OUTPUT_TEXTURE_COORD14_EXT 0x87AB
#define GL_OUTPUT_TEXTURE_COORD15_EXT 0x87AC
#define GL_OUTPUT_TEXTURE_COORD16_EXT 0x87AD
#define GL_OUTPUT_TEXTURE_COORD17_EXT 0x87AE
#define GL_OUTPUT_TEXTURE_COORD18_EXT 0x87AF
#define GL_OUTPUT_TEXTURE_COORD19_EXT 0x87B0
#define GL_OUTPUT_TEXTURE_COORD20_EXT 0x87B1
#define GL_OUTPUT_TEXTURE_COORD21_EXT 0x87B2
#define GL_OUTPUT_TEXTURE_COORD22_EXT 0x87B3
#define GL_OUTPUT_TEXTURE_COORD23_EXT 0x87B4
#define GL_OUTPUT_TEXTURE_COORD24_EXT 0x87B5
#define GL_OUTPUT_TEXTURE_COORD25_EXT 0x87B6
#define GL_OUTPUT_TEXTURE_COORD26_EXT 0x87B7
#define GL_OUTPUT_TEXTURE_COORD27_EXT 0x87B8
#define GL_OUTPUT_TEXTURE_COORD28_EXT 0x87B9
#define GL_OUTPUT_TEXTURE_COORD29_EXT 0x87BA
#define GL_OUTPUT_TEXTURE_COORD30_EXT 0x87BB
#define GL_OUTPUT_TEXTURE_COORD31_EXT 0x87BC
#define GL_OUTPUT_FOG_EXT 0x87BD
#define GL_SCALAR_EXT 0x87BE
#define GL_VECTOR_EXT 0x87BF
#define GL_MATRIX_EXT 0x87C0
#define GL_VARIANT_EXT 0x87C1
#define GL_INVARIANT_EXT 0x87C2
#define GL_LOCAL_CONSTANT_EXT 0x87C3
#define GL_LOCAL_EXT 0x87C4
#define GL_MAX_VERTEX_SHADER_INSTRUCTIONS_EXT 0x87C5
#define GL_MAX_VERTEX_SHADER_VARIANTS_EXT 0x87C6
#define GL_MAX_VERTEX_SHADER_INVARIANTS_EXT 0x87C7
#define GL_MAX_VERTEX_SHADER_LOCAL_CONSTANTS_EXT 0x87C8
#define GL_MAX_VERTEX_SHADER_LOCALS_EXT 0x87C9
#define GL_MAX_OPTIMIZED_VERTEX_SHADER_INSTRUCTIONS_EXT 0x87CA
#define GL_MAX_OPTIMIZED_VERTEX_SHADER_VARIANTS_EXT 0x87CB
#define GL_MAX_OPTIMIZED_VERTEX_SHADER_LOCAL_CONSTANTS_EXT 0x87CC
#define GL_MAX_OPTIMIZED_VERTEX_SHADER_INVARIANTS_EXT 0x87CD
#define GL_MAX_OPTIMIZED_VERTEX_SHADER_LOCALS_EXT 0x87CE
#define GL_VERTEX_SHADER_INSTRUCTIONS_EXT 0x87CF
#define GL_VERTEX_SHADER_VARIANTS_EXT 0x87D0
#define GL_VERTEX_SHADER_INVARIANTS_EXT 0x87D1
#define GL_VERTEX_SHADER_LOCAL_CONSTANTS_EXT 0x87D2
#define GL_VERTEX_SHADER_LOCALS_EXT 0x87D3
#define GL_VERTEX_SHADER_OPTIMIZED_EXT 0x87D4
#define GL_X_EXT 0x87D5
#define GL_Y_EXT 0x87D6
#define GL_Z_EXT 0x87D7
#define GL_W_EXT 0x87D8
#define GL_NEGATIVE_X_EXT 0x87D9
#define GL_NEGATIVE_Y_EXT 0x87DA
#define GL_NEGATIVE_Z_EXT 0x87DB
#define GL_NEGATIVE_W_EXT 0x87DC
#define GL_ZERO_EXT 0x87DD
#define GL_ONE_EXT 0x87DE
#define GL_NEGATIVE_ONE_EXT 0x87DF
#define GL_NORMALIZED_RANGE_EXT 0x87E0
#define GL_FULL_RANGE_EXT 0x87E1
#define GL_CURRENT_VERTEX_EXT 0x87E2
#define GL_MVP_MATRIX_EXT 0x87E3
#define GL_VARIANT_VALUE_EXT 0x87E4
#define GL_VARIANT_DATATYPE_EXT 0x87E5
#define GL_VARIANT_ARRAY_STRIDE_EXT 0x87E6
#define GL_VARIANT_ARRAY_TYPE_EXT 0x87E7
#define GL_VARIANT_ARRAY_EXT 0x87E8
#define GL_VARIANT_ARRAY_POINTER_EXT 0x87E9
#define GL_INVARIANT_VALUE_EXT 0x87EA
#define GL_INVARIANT_DATATYPE_EXT 0x87EB
#define GL_LOCAL_CONSTANT_VALUE_EXT 0x87EC
#define GL_LOCAL_CONSTANT_DATATYPE_EXT 0x87ED
#define GL_MODELVIEW0_STACK_DEPTH_EXT 0x0BA3
#define GL_MODELVIEW1_STACK_DEPTH_EXT 0x8502
#define GL_MODELVIEW0_MATRIX_EXT 0x0BA6
#define GL_MODELVIEW1_MATRIX_EXT 0x8506
#define GL_VERTEX_WEIGHTING_EXT 0x8509
#define GL_MODELVIEW0_EXT 0x1700
#define GL_MODELVIEW1_EXT 0x850A
#define GL_CURRENT_VERTEX_WEIGHT_EXT 0x850B
#define GL_VERTEX_WEIGHT_ARRAY_EXT 0x850C
#define GL_VERTEX_WEIGHT_ARRAY_SIZE_EXT 0x850D
#define GL_VERTEX_WEIGHT_ARRAY_TYPE_EXT 0x850E
#define GL_VERTEX_WEIGHT_ARRAY_STRIDE_EXT 0x850F
#define GL_VERTEX_WEIGHT_ARRAY_POINTER_EXT 0x8510
#define GL_INCLUSIVE_EXT 0x8F10
#define GL_EXCLUSIVE_EXT 0x8F11
#define GL_WINDOW_RECTANGLE_EXT 0x8F12
#define GL_WINDOW_RECTANGLE_MODE_EXT 0x8F13
#define GL_MAX_WINDOW_RECTANGLES_EXT 0x8F14
#define GL_NUM_WINDOW_RECTANGLES_EXT 0x8F15
#define GL_SYNC_X11_FENCE_EXT 0x90E1
#define GL_IGNORE_BORDER_HP 0x8150
#define GL_CONSTANT_BORDER_HP 0x8151
#define GL_REPLICATE_BORDER_HP 0x8153
#define GL_CONVOLUTION_BORDER_COLOR_HP 0x8154
#define GL_IMAGE_SCALE_X_HP 0x8155
#define GL_IMAGE_SCALE_Y_HP 0x8156
#define GL_IMAGE_TRANSLATE_X_HP 0x8157
#define GL_IMAGE_TRANSLATE_Y_HP 0x8158
#define GL_IMAGE_ROTATE_ANGLE_HP 0x8159
#define GL_IMAGE_ROTATE_ORIGIN_X_HP 0x815A
#define GL_IMAGE_ROTATE_ORIGIN_Y_HP 0x815B
#define GL_IMAGE_MAG_FILTER_HP 0x815C
#define GL_IMAGE_MIN_FILTER_HP 0x815D
#define GL_IMAGE_CUBIC_WEIGHT_HP 0x815E
#define GL_CUBIC_HP 0x815F
#define GL_AVERAGE_HP 0x8160
#define GL_IMAGE_TRANSFORM_2D_HP 0x8161
#define GL_POST_IMAGE_TRANSFORM_COLOR_TABLE_HP 0x8162
#define GL_PROXY_POST_IMAGE_TRANSFORM_COLOR_TABLE_HP 0x8163
#define GL_OCCLUSION_TEST_HP 0x8165
#define GL_OCCLUSION_TEST_RESULT_HP 0x8166
#define GL_TEXTURE_LIGHTING_MODE_HP 0x8167
#define GL_TEXTURE_POST_SPECULAR_HP 0x8168
#define GL_TEXTURE_PRE_SPECULAR_HP 0x8169
#define GL_CULL_VERTEX_IBM 103050
#define GL_RASTER_POSITION_UNCLIPPED_IBM 0x19262
#define GL_ALL_STATIC_DATA_IBM 103060
#define GL_STATIC_VERTEX_ARRAY_IBM 103061
#define GL_MIRRORED_REPEAT_IBM 0x8370
#define GL_VERTEX_ARRAY_LIST_IBM 103070
#define GL_NORMAL_ARRAY_LIST_IBM 103071
#define GL_COLOR_ARRAY_LIST_IBM 103072
#define GL_INDEX_ARRAY_LIST_IBM 103073
#define GL_TEXTURE_COORD_ARRAY_LIST_IBM 103074
#define GL_EDGE_FLAG_ARRAY_LIST_IBM 103075
#define GL_FOG_COORDINATE_ARRAY_LIST_IBM 103076
#define GL_SECONDARY_COLOR_ARRAY_LIST_IBM 103077
#define GL_VERTEX_ARRAY_LIST_STRIDE_IBM 103080
#define GL_NORMAL_ARRAY_LIST_STRIDE_IBM 103081
#define GL_COLOR_ARRAY_LIST_STRIDE_IBM 103082
#define GL_INDEX_ARRAY_LIST_STRIDE_IBM 103083
#define GL_TEXTURE_COORD_ARRAY_LIST_STRIDE_IBM 103084
#define GL_EDGE_FLAG_ARRAY_LIST_STRIDE_IBM 103085
#define GL_FOG_COORDINATE_ARRAY_LIST_STRIDE_IBM 103086
#define GL_SECONDARY_COLOR_ARRAY_LIST_STRIDE_IBM 103087
#define GL_RED_MIN_CLAMP_INGR 0x8560
#define GL_GREEN_MIN_CLAMP_INGR 0x8561
#define GL_BLUE_MIN_CLAMP_INGR 0x8562
#define GL_ALPHA_MIN_CLAMP_INGR 0x8563
#define GL_RED_MAX_CLAMP_INGR 0x8564
#define GL_GREEN_MAX_CLAMP_INGR 0x8565
#define GL_BLUE_MAX_CLAMP_INGR 0x8566
#define GL_ALPHA_MAX_CLAMP_INGR 0x8567
#define GL_INTERLACE_READ_INGR 0x8568
#define GL_CONSERVATIVE_RASTERIZATION_INTEL 0x83FE
#define GL_TEXTURE_MEMORY_LAYOUT_INTEL 0x83FF
#define GL_LAYOUT_DEFAULT_INTEL 0
#define GL_LAYOUT_LINEAR_INTEL 1
#define GL_LAYOUT_LINEAR_CPU_CACHED_INTEL 2
#define GL_PARALLEL_ARRAYS_INTEL 0x83F4
#define GL_VERTEX_ARRAY_PARALLEL_POINTERS_INTEL 0x83F5
#define GL_NORMAL_ARRAY_PARALLEL_POINTERS_INTEL 0x83F6
#define GL_COLOR_ARRAY_PARALLEL_POINTERS_INTEL 0x83F7
#define GL_TEXTURE_COORD_ARRAY_PARALLEL_POINTERS_INTEL 0x83F8
#define GL_PERFQUERY_SINGLE_CONTEXT_INTEL 0x00000000
#define GL_PERFQUERY_GLOBAL_CONTEXT_INTEL 0x00000001
#define GL_PERFQUERY_WAIT_INTEL 0x83FB
#define GL_PERFQUERY_FLUSH_INTEL 0x83FA
#define GL_PERFQUERY_DONOT_FLUSH_INTEL 0x83F9
#define GL_PERFQUERY_COUNTER_EVENT_INTEL 0x94F0
#define GL_PERFQUERY_COUNTER_DURATION_NORM_INTEL 0x94F1
#define GL_PERFQUERY_COUNTER_DURATION_RAW_INTEL 0x94F2
#define GL_PERFQUERY_COUNTER_THROUGHPUT_INTEL 0x94F3
#define GL_PERFQUERY_COUNTER_RAW_INTEL 0x94F4
#define GL_PERFQUERY_COUNTER_TIMESTAMP_INTEL 0x94F5
#define GL_PERFQUERY_COUNTER_DATA_UINT32_INTEL 0x94F8
#define GL_PERFQUERY_COUNTER_DATA_UINT64_INTEL 0x94F9
#define GL_PERFQUERY_COUNTER_DATA_FLOAT_INTEL 0x94FA
#define GL_PERFQUERY_COUNTER_DATA_DOUBLE_INTEL 0x94FB
#define GL_PERFQUERY_COUNTER_DATA_BOOL32_INTEL 0x94FC
#define GL_PERFQUERY_QUERY_NAME_LENGTH_MAX_INTEL 0x94FD
#define GL_PERFQUERY_COUNTER_NAME_LENGTH_MAX_INTEL 0x94FE
#define GL_PERFQUERY_COUNTER_DESC_LENGTH_MAX_INTEL 0x94FF
#define GL_PERFQUERY_GPA_EXTENDED_COUNTERS_INTEL 0x9500
#define GL_MULTIPLY_KHR 0x9294
#define GL_SCREEN_KHR 0x9295
#define GL_OVERLAY_KHR 0x9296
#define GL_DARKEN_KHR 0x9297
#define GL_LIGHTEN_KHR 0x9298
#define GL_COLORDODGE_KHR 0x9299
#define GL_COLORBURN_KHR 0x929A
#define GL_HARDLIGHT_KHR 0x929B
#define GL_SOFTLIGHT_KHR 0x929C
#define GL_DIFFERENCE_KHR 0x929E
#define GL_EXCLUSION_KHR 0x92A0
#define GL_HSL_HUE_KHR 0x92AD
#define GL_HSL_SATURATION_KHR 0x92AE
#define GL_HSL_COLOR_KHR 0x92AF
#define GL_HSL_LUMINOSITY_KHR 0x92B0
#define GL_BLEND_ADVANCED_COHERENT_KHR 0x9285
#define GL_CONTEXT_RELEASE_BEHAVIOR 0x82FB
#define GL_CONTEXT_RELEASE_BEHAVIOR_FLUSH 0x82FC
#define GL_CONTEXT_RELEASE_BEHAVIOR_KHR 0x82FB
#define GL_CONTEXT_RELEASE_BEHAVIOR_FLUSH_KHR 0x82FC
#define GL_DEBUG_OUTPUT_SYNCHRONOUS 0x8242
#define GL_DEBUG_NEXT_LOGGED_MESSAGE_LENGTH 0x8243
#define GL_DEBUG_CALLBACK_FUNCTION 0x8244
#define GL_DEBUG_CALLBACK_USER_PARAM 0x8245
#define GL_DEBUG_SOURCE_API 0x8246
#define GL_DEBUG_SOURCE_WINDOW_SYSTEM 0x8247
#define GL_DEBUG_SOURCE_SHADER_COMPILER 0x8248
#define GL_DEBUG_SOURCE_THIRD_PARTY 0x8249
#define GL_DEBUG_SOURCE_APPLICATION 0x824A
#define GL_DEBUG_SOURCE_OTHER 0x824B
#define GL_DEBUG_TYPE_ERROR 0x824C
#define GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR 0x824D
#define GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR 0x824E
#define GL_DEBUG_TYPE_PORTABILITY 0x824F
#define GL_DEBUG_TYPE_PERFORMANCE 0x8250
#define GL_DEBUG_TYPE_OTHER 0x8251
#define GL_DEBUG_TYPE_MARKER 0x8268
#define GL_DEBUG_TYPE_PUSH_GROUP 0x8269
#define GL_DEBUG_TYPE_POP_GROUP 0x826A
#define GL_DEBUG_SEVERITY_NOTIFICATION 0x826B
#define GL_MAX_DEBUG_GROUP_STACK_DEPTH 0x826C
#define GL_DEBUG_GROUP_STACK_DEPTH 0x826D
#define GL_BUFFER 0x82E0
#define GL_SHADER 0x82E1
#define GL_PROGRAM 0x82E2
#define GL_QUERY 0x82E3
#define GL_PROGRAM_PIPELINE 0x82E4
#define GL_MAX_LABEL_LENGTH 0x82E8
#define GL_MAX_DEBUG_MESSAGE_LENGTH 0x9143
#define GL_MAX_DEBUG_LOGGED_MESSAGES 0x9144
#define GL_DEBUG_LOGGED_MESSAGES 0x9145
#define GL_DEBUG_SEVERITY_HIGH 0x9146
#define GL_DEBUG_SEVERITY_MEDIUM 0x9147
#define GL_DEBUG_SEVERITY_LOW 0x9148
#define GL_DEBUG_OUTPUT 0x92E0
#define GL_CONTEXT_FLAG_DEBUG_BIT 0x00000002
#define GL_DEBUG_OUTPUT_SYNCHRONOUS_KHR 0x8242
#define GL_DEBUG_NEXT_LOGGED_MESSAGE_LENGTH_KHR 0x8243
#define GL_DEBUG_CALLBACK_FUNCTION_KHR 0x8244
#define GL_DEBUG_CALLBACK_USER_PARAM_KHR 0x8245
#define GL_DEBUG_SOURCE_API_KHR 0x8246
#define GL_DEBUG_SOURCE_WINDOW_SYSTEM_KHR 0x8247
#define GL_DEBUG_SOURCE_SHADER_COMPILER_KHR 0x8248
#define GL_DEBUG_SOURCE_THIRD_PARTY_KHR 0x8249
#define GL_DEBUG_SOURCE_APPLICATION_KHR 0x824A
#define GL_DEBUG_SOURCE_OTHER_KHR 0x824B
#define GL_DEBUG_TYPE_ERROR_KHR 0x824C
#define GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR_KHR 0x824D
#define GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR_KHR 0x824E
#define GL_DEBUG_TYPE_PORTABILITY_KHR 0x824F
#define GL_DEBUG_TYPE_PERFORMANCE_KHR 0x8250
#define GL_DEBUG_TYPE_OTHER_KHR 0x8251
#define GL_DEBUG_TYPE_MARKER_KHR 0x8268
#define GL_DEBUG_TYPE_PUSH_GROUP_KHR 0x8269
#define GL_DEBUG_TYPE_POP_GROUP_KHR 0x826A
#define GL_DEBUG_SEVERITY_NOTIFICATION_KHR 0x826B
#define GL_MAX_DEBUG_GROUP_STACK_DEPTH_KHR 0x826C
#define GL_DEBUG_GROUP_STACK_DEPTH_KHR 0x826D
#define GL_BUFFER_KHR 0x82E0
#define GL_SHADER_KHR 0x82E1
#define GL_PROGRAM_KHR 0x82E2
#define GL_VERTEX_ARRAY_KHR 0x8074
#define GL_QUERY_KHR 0x82E3
#define GL_PROGRAM_PIPELINE_KHR 0x82E4
#define GL_SAMPLER_KHR 0x82E6
#define GL_MAX_LABEL_LENGTH_KHR 0x82E8
#define GL_MAX_DEBUG_MESSAGE_LENGTH_KHR 0x9143
#define GL_MAX_DEBUG_LOGGED_MESSAGES_KHR 0x9144
#define GL_DEBUG_LOGGED_MESSAGES_KHR 0x9145
#define GL_DEBUG_SEVERITY_HIGH_KHR 0x9146
#define GL_DEBUG_SEVERITY_MEDIUM_KHR 0x9147
#define GL_DEBUG_SEVERITY_LOW_KHR 0x9148
#define GL_DEBUG_OUTPUT_KHR 0x92E0
#define GL_CONTEXT_FLAG_DEBUG_BIT_KHR 0x00000002
#define GL_STACK_OVERFLOW_KHR 0x0503
#define GL_STACK_UNDERFLOW_KHR 0x0504
#define GL_DISPLAY_LIST 0x82E7
#define GL_CONTEXT_FLAG_NO_ERROR_BIT_KHR 0x00000008
#define GL_CONTEXT_ROBUST_ACCESS 0x90F3
#define GL_LOSE_CONTEXT_ON_RESET 0x8252
#define GL_GUILTY_CONTEXT_RESET 0x8253
#define GL_INNOCENT_CONTEXT_RESET 0x8254
#define GL_UNKNOWN_CONTEXT_RESET 0x8255
#define GL_RESET_NOTIFICATION_STRATEGY 0x8256
#define GL_NO_RESET_NOTIFICATION 0x8261
#define GL_CONTEXT_LOST 0x0507
#define GL_CONTEXT_ROBUST_ACCESS_KHR 0x90F3
#define GL_LOSE_CONTEXT_ON_RESET_KHR 0x8252
#define GL_GUILTY_CONTEXT_RESET_KHR 0x8253
#define GL_INNOCENT_CONTEXT_RESET_KHR 0x8254
#define GL_UNKNOWN_CONTEXT_RESET_KHR 0x8255
#define GL_RESET_NOTIFICATION_STRATEGY_KHR 0x8256
#define GL_NO_RESET_NOTIFICATION_KHR 0x8261
#define GL_CONTEXT_LOST_KHR 0x0507
#define GL_COMPRESSED_RGBA_ASTC_4x4_KHR 0x93B0
#define GL_COMPRESSED_RGBA_ASTC_5x4_KHR 0x93B1
#define GL_COMPRESSED_RGBA_ASTC_5x5_KHR 0x93B2
#define GL_COMPRESSED_RGBA_ASTC_6x5_KHR 0x93B3
#define GL_COMPRESSED_RGBA_ASTC_6x6_KHR 0x93B4
#define GL_COMPRESSED_RGBA_ASTC_8x5_KHR 0x93B5
#define GL_COMPRESSED_RGBA_ASTC_8x6_KHR 0x93B6
#define GL_COMPRESSED_RGBA_ASTC_8x8_KHR 0x93B7
#define GL_COMPRESSED_RGBA_ASTC_10x5_KHR 0x93B8
#define GL_COMPRESSED_RGBA_ASTC_10x6_KHR 0x93B9
#define GL_COMPRESSED_RGBA_ASTC_10x8_KHR 0x93BA
#define GL_COMPRESSED_RGBA_ASTC_10x10_KHR 0x93BB
#define GL_COMPRESSED_RGBA_ASTC_12x10_KHR 0x93BC
#define GL_COMPRESSED_RGBA_ASTC_12x12_KHR 0x93BD
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_4x4_KHR 0x93D0
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_5x4_KHR 0x93D1
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_5x5_KHR 0x93D2
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_6x5_KHR 0x93D3
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_6x6_KHR 0x93D4
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x5_KHR 0x93D5
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x6_KHR 0x93D6
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x8_KHR 0x93D7
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x5_KHR 0x93D8
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x6_KHR 0x93D9
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x8_KHR 0x93DA
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x10_KHR 0x93DB
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_12x10_KHR 0x93DC
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_12x12_KHR 0x93DD
#define GL_TEXTURE_1D_STACK_MESAX 0x8759
#define GL_TEXTURE_2D_STACK_MESAX 0x875A
#define GL_PROXY_TEXTURE_1D_STACK_MESAX 0x875B
#define GL_PROXY_TEXTURE_2D_STACK_MESAX 0x875C
#define GL_TEXTURE_1D_STACK_BINDING_MESAX 0x875D
#define GL_TEXTURE_2D_STACK_BINDING_MESAX 0x875E
#define GL_PACK_INVERT_MESA 0x8758
#define GL_UNSIGNED_SHORT_8_8_MESA 0x85BA
#define GL_UNSIGNED_SHORT_8_8_REV_MESA 0x85BB
#define GL_YCBCR_MESA 0x8757
#define GL_GPU_MEMORY_INFO_DEDICATED_VIDMEM_NVX 0x9047
#define GL_GPU_MEMORY_INFO_TOTAL_AVAILABLE_MEMORY_NVX 0x9048
#define GL_GPU_MEMORY_INFO_CURRENT_AVAILABLE_VIDMEM_NVX 0x9049
#define GL_GPU_MEMORY_INFO_EVICTION_COUNT_NVX 0x904A
#define GL_GPU_MEMORY_INFO_EVICTED_MEMORY_NVX 0x904B
#define GL_BLEND_OVERLAP_NV 0x9281
#define GL_BLEND_PREMULTIPLIED_SRC_NV 0x9280
#define GL_BLUE_NV 0x1905
#define GL_COLORBURN_NV 0x929A
#define GL_COLORDODGE_NV 0x9299
#define GL_CONJOINT_NV 0x9284
#define GL_CONTRAST_NV 0x92A1
#define GL_DARKEN_NV 0x9297
#define GL_DIFFERENCE_NV 0x929E
#define GL_DISJOINT_NV 0x9283
#define GL_DST_ATOP_NV 0x928F
#define GL_DST_IN_NV 0x928B
#define GL_DST_NV 0x9287
#define GL_DST_OUT_NV 0x928D
#define GL_DST_OVER_NV 0x9289
#define GL_EXCLUSION_NV 0x92A0
#define GL_GREEN_NV 0x1904
#define GL_HARDLIGHT_NV 0x929B
#define GL_HARDMIX_NV 0x92A9
#define GL_HSL_COLOR_NV 0x92AF
#define GL_HSL_HUE_NV 0x92AD
#define GL_HSL_LUMINOSITY_NV 0x92B0
#define GL_HSL_SATURATION_NV 0x92AE
#define GL_INVERT_OVG_NV 0x92B4
#define GL_INVERT_RGB_NV 0x92A3
#define GL_LIGHTEN_NV 0x9298
#define GL_LINEARBURN_NV 0x92A5
#define GL_LINEARDODGE_NV 0x92A4
#define GL_LINEARLIGHT_NV 0x92A7
#define GL_MINUS_CLAMPED_NV 0x92B3
#define GL_MINUS_NV 0x929F
#define GL_MULTIPLY_NV 0x9294
#define GL_OVERLAY_NV 0x9296
#define GL_PINLIGHT_NV 0x92A8
#define GL_PLUS_CLAMPED_ALPHA_NV 0x92B2
#define GL_PLUS_CLAMPED_NV 0x92B1
#define GL_PLUS_DARKER_NV 0x9292
#define GL_PLUS_NV 0x9291
#define GL_RED_NV 0x1903
#define GL_SCREEN_NV 0x9295
#define GL_SOFTLIGHT_NV 0x929C
#define GL_SRC_ATOP_NV 0x928E
#define GL_SRC_IN_NV 0x928A
#define GL_SRC_NV 0x9286
#define GL_SRC_OUT_NV 0x928C
#define GL_SRC_OVER_NV 0x9288
#define GL_UNCORRELATED_NV 0x9282
#define GL_VIVIDLIGHT_NV 0x92A6
#define GL_XOR_NV 0x1506
#define GL_BLEND_ADVANCED_COHERENT_NV 0x9285
#define GL_VIEWPORT_POSITION_W_SCALE_NV 0x937C
#define GL_VIEWPORT_POSITION_W_SCALE_X_COEFF_NV 0x937D
#define GL_VIEWPORT_POSITION_W_SCALE_Y_COEFF_NV 0x937E
#define GL_TERMINATE_SEQUENCE_COMMAND_NV 0x0000
#define GL_NOP_COMMAND_NV 0x0001
#define GL_DRAW_ELEMENTS_COMMAND_NV 0x0002
#define GL_DRAW_ARRAYS_COMMAND_NV 0x0003
#define GL_DRAW_ELEMENTS_STRIP_COMMAND_NV 0x0004
#define GL_DRAW_ARRAYS_STRIP_COMMAND_NV 0x0005
#define GL_DRAW_ELEMENTS_INSTANCED_COMMAND_NV 0x0006
#define GL_DRAW_ARRAYS_INSTANCED_COMMAND_NV 0x0007
#define GL_ELEMENT_ADDRESS_COMMAND_NV 0x0008
#define GL_ATTRIBUTE_ADDRESS_COMMAND_NV 0x0009
#define GL_UNIFORM_ADDRESS_COMMAND_NV 0x000A
#define GL_BLEND_COLOR_COMMAND_NV 0x000B
#define GL_STENCIL_REF_COMMAND_NV 0x000C
#define GL_LINE_WIDTH_COMMAND_NV 0x000D
#define GL_POLYGON_OFFSET_COMMAND_NV 0x000E
#define GL_ALPHA_REF_COMMAND_NV 0x000F
#define GL_VIEWPORT_COMMAND_NV 0x0010
#define GL_SCISSOR_COMMAND_NV 0x0011
#define GL_FRONT_FACE_COMMAND_NV 0x0012
#define GL_COMPUTE_PROGRAM_NV 0x90FB
#define GL_COMPUTE_PROGRAM_PARAMETER_BUFFER_NV 0x90FC
#define GL_QUERY_WAIT_NV 0x8E13
#define GL_QUERY_NO_WAIT_NV 0x8E14
#define GL_QUERY_BY_REGION_WAIT_NV 0x8E15
#define GL_QUERY_BY_REGION_NO_WAIT_NV 0x8E16
#define GL_CONSERVATIVE_RASTERIZATION_NV 0x9346
#define GL_SUBPIXEL_PRECISION_BIAS_X_BITS_NV 0x9347
#define GL_SUBPIXEL_PRECISION_BIAS_Y_BITS_NV 0x9348
#define GL_MAX_SUBPIXEL_PRECISION_BIAS_BITS_NV 0x9349
#define GL_CONSERVATIVE_RASTER_DILATE_NV 0x9379
#define GL_CONSERVATIVE_RASTER_DILATE_RANGE_NV 0x937A
#define GL_CONSERVATIVE_RASTER_DILATE_GRANULARITY_NV 0x937B
#define GL_CONSERVATIVE_RASTER_MODE_NV 0x954D
#define GL_CONSERVATIVE_RASTER_MODE_POST_SNAP_NV 0x954E
#define GL_CONSERVATIVE_RASTER_MODE_PRE_SNAP_TRIANGLES_NV 0x954F
#define GL_DEPTH_STENCIL_TO_RGBA_NV 0x886E
#define GL_DEPTH_STENCIL_TO_BGRA_NV 0x886F
#define GL_MAX_DEEP_3D_TEXTURE_WIDTH_HEIGHT_NV 0x90D0
#define GL_MAX_DEEP_3D_TEXTURE_DEPTH_NV 0x90D1
#define GL_DEPTH_COMPONENT32F_NV 0x8DAB
#define GL_DEPTH32F_STENCIL8_NV 0x8DAC
#define GL_FLOAT_32_UNSIGNED_INT_24_8_REV_NV 0x8DAD
#define GL_DEPTH_BUFFER_FLOAT_MODE_NV 0x8DAF
#define GL_DEPTH_CLAMP_NV 0x864F
#define GL_EVAL_2D_NV 0x86C0
#define GL_EVAL_TRIANGULAR_2D_NV 0x86C1
#define GL_MAP_TESSELLATION_NV 0x86C2
#define GL_MAP_ATTRIB_U_ORDER_NV 0x86C3
#define GL_MAP_ATTRIB_V_ORDER_NV 0x86C4
#define GL_EVAL_FRACTIONAL_TESSELLATION_NV 0x86C5
#define GL_EVAL_VERTEX_ATTRIB0_NV 0x86C6
#define GL_EVAL_VERTEX_ATTRIB1_NV 0x86C7
#define GL_EVAL_VERTEX_ATTRIB2_NV 0x86C8
#define GL_EVAL_VERTEX_ATTRIB3_NV 0x86C9
#define GL_EVAL_VERTEX_ATTRIB4_NV 0x86CA
#define GL_EVAL_VERTEX_ATTRIB5_NV 0x86CB
#define GL_EVAL_VERTEX_ATTRIB6_NV 0x86CC
#define GL_EVAL_VERTEX_ATTRIB7_NV 0x86CD
#define GL_EVAL_VERTEX_ATTRIB8_NV 0x86CE
#define GL_EVAL_VERTEX_ATTRIB9_NV 0x86CF
#define GL_EVAL_VERTEX_ATTRIB10_NV 0x86D0
#define GL_EVAL_VERTEX_ATTRIB11_NV 0x86D1
#define GL_EVAL_VERTEX_ATTRIB12_NV 0x86D2
#define GL_EVAL_VERTEX_ATTRIB13_NV 0x86D3
#define GL_EVAL_VERTEX_ATTRIB14_NV 0x86D4
#define GL_EVAL_VERTEX_ATTRIB15_NV 0x86D5
#define GL_MAX_MAP_TESSELLATION_NV 0x86D6
#define GL_MAX_RATIONAL_EVAL_ORDER_NV 0x86D7
#define GL_SAMPLE_POSITION_NV 0x8E50
#define GL_SAMPLE_MASK_NV 0x8E51
#define GL_SAMPLE_MASK_VALUE_NV 0x8E52
#define GL_TEXTURE_BINDING_RENDERBUFFER_NV 0x8E53
#define GL_TEXTURE_RENDERBUFFER_DATA_STORE_BINDING_NV 0x8E54
#define GL_TEXTURE_RENDERBUFFER_NV 0x8E55
#define GL_SAMPLER_RENDERBUFFER_NV 0x8E56
#define GL_INT_SAMPLER_RENDERBUFFER_NV 0x8E57
#define GL_UNSIGNED_INT_SAMPLER_RENDERBUFFER_NV 0x8E58
#define GL_MAX_SAMPLE_MASK_WORDS_NV 0x8E59
#define GL_ALL_COMPLETED_NV 0x84F2
#define GL_FENCE_STATUS_NV 0x84F3
#define GL_FENCE_CONDITION_NV 0x84F4
#define GL_FILL_RECTANGLE_NV 0x933C
#define GL_FLOAT_R_NV 0x8880
#define GL_FLOAT_RG_NV 0x8881
#define GL_FLOAT_RGB_NV 0x8882
#define GL_FLOAT_RGBA_NV 0x8883
#define GL_FLOAT_R16_NV 0x8884
#define GL_FLOAT_R32_NV 0x8885
#define GL_FLOAT_RG16_NV 0x8886
#define GL_FLOAT_RG32_NV 0x8887
#define GL_FLOAT_RGB16_NV 0x8888
#define GL_FLOAT_RGB32_NV 0x8889
#define GL_FLOAT_RGBA16_NV 0x888A
#define GL_FLOAT_RGBA32_NV 0x888B
#define GL_TEXTURE_FLOAT_COMPONENTS_NV 0x888C
#define GL_FLOAT_CLEAR_COLOR_VALUE_NV 0x888D
#define GL_FLOAT_RGBA_MODE_NV 0x888E
#define GL_FOG_DISTANCE_MODE_NV 0x855A
#define GL_EYE_RADIAL_NV 0x855B
#define GL_EYE_PLANE_ABSOLUTE_NV 0x855C
#define GL_FRAGMENT_COVERAGE_TO_COLOR_NV 0x92DD
#define GL_FRAGMENT_COVERAGE_COLOR_NV 0x92DE
#define GL_MAX_FRAGMENT_PROGRAM_LOCAL_PARAMETERS_NV 0x8868
#define GL_FRAGMENT_PROGRAM_NV 0x8870
#define GL_MAX_TEXTURE_COORDS_NV 0x8871
#define GL_MAX_TEXTURE_IMAGE_UNITS_NV 0x8872
#define GL_FRAGMENT_PROGRAM_BINDING_NV 0x8873
#define GL_PROGRAM_ERROR_STRING_NV 0x8874
#define GL_MAX_PROGRAM_EXEC_INSTRUCTIONS_NV 0x88F4
#define GL_MAX_PROGRAM_CALL_DEPTH_NV 0x88F5
#define GL_MAX_PROGRAM_IF_DEPTH_NV 0x88F6
#define GL_MAX_PROGRAM_LOOP_DEPTH_NV 0x88F7
#define GL_MAX_PROGRAM_LOOP_COUNT_NV 0x88F8
#define GL_COVERAGE_MODULATION_TABLE_NV 0x9331
#define GL_COLOR_SAMPLES_NV 0x8E20
#define GL_DEPTH_SAMPLES_NV 0x932D
#define GL_STENCIL_SAMPLES_NV 0x932E
#define GL_MIXED_DEPTH_SAMPLES_SUPPORTED_NV 0x932F
#define GL_MIXED_STENCIL_SAMPLES_SUPPORTED_NV 0x9330
#define GL_COVERAGE_MODULATION_NV 0x9332
#define GL_COVERAGE_MODULATION_TABLE_SIZE_NV 0x9333
#define GL_RENDERBUFFER_COVERAGE_SAMPLES_NV 0x8CAB
#define GL_RENDERBUFFER_COLOR_SAMPLES_NV 0x8E10
#define GL_MAX_MULTISAMPLE_COVERAGE_MODES_NV 0x8E11
#define GL_MULTISAMPLE_COVERAGE_MODES_NV 0x8E12
#define GL_GEOMETRY_PROGRAM_NV 0x8C26
#define GL_MAX_PROGRAM_OUTPUT_VERTICES_NV 0x8C27
#define GL_MAX_PROGRAM_TOTAL_OUTPUT_COMPONENTS_NV 0x8C28
#define GL_MIN_PROGRAM_TEXEL_OFFSET_NV 0x8904
#define GL_MAX_PROGRAM_TEXEL_OFFSET_NV 0x8905
#define GL_PROGRAM_ATTRIB_COMPONENTS_NV 0x8906
#define GL_PROGRAM_RESULT_COMPONENTS_NV 0x8907
#define GL_MAX_PROGRAM_ATTRIB_COMPONENTS_NV 0x8908
#define GL_MAX_PROGRAM_RESULT_COMPONENTS_NV 0x8909
#define GL_MAX_PROGRAM_GENERIC_ATTRIBS_NV 0x8DA5
#define GL_MAX_PROGRAM_GENERIC_RESULTS_NV 0x8DA6
#define GL_MAX_GEOMETRY_PROGRAM_INVOCATIONS_NV 0x8E5A
#define GL_MIN_FRAGMENT_INTERPOLATION_OFFSET_NV 0x8E5B
#define GL_MAX_FRAGMENT_INTERPOLATION_OFFSET_NV 0x8E5C
#define GL_FRAGMENT_PROGRAM_INTERPOLATION_OFFSET_BITS_NV 0x8E5D
#define GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET_NV 0x8E5E
#define GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET_NV 0x8E5F
#define GL_MAX_PROGRAM_SUBROUTINE_PARAMETERS_NV 0x8F44
#define GL_MAX_PROGRAM_SUBROUTINE_NUM_NV 0x8F45
#define GL_HALF_FLOAT_NV 0x140B
#define GL_MULTISAMPLES_NV 0x9371
#define GL_SUPERSAMPLE_SCALE_X_NV 0x9372
#define GL_SUPERSAMPLE_SCALE_Y_NV 0x9373
#define GL_CONFORMANT_NV 0x9374
#define GL_MAX_SHININESS_NV 0x8504
#define GL_MAX_SPOT_EXPONENT_NV 0x8505
#define GL_MULTISAMPLE_FILTER_HINT_NV 0x8534
#define GL_PIXEL_COUNTER_BITS_NV 0x8864
#define GL_CURRENT_OCCLUSION_QUERY_ID_NV 0x8865
#define GL_PIXEL_COUNT_NV 0x8866
#define GL_PIXEL_COUNT_AVAILABLE_NV 0x8867
#define GL_DEPTH_STENCIL_NV 0x84F9
#define GL_UNSIGNED_INT_24_8_NV 0x84FA
#define GL_MAX_PROGRAM_PARAMETER_BUFFER_BINDINGS_NV 0x8DA0
#define GL_MAX_PROGRAM_PARAMETER_BUFFER_SIZE_NV 0x8DA1
#define GL_VERTEX_PROGRAM_PARAMETER_BUFFER_NV 0x8DA2
#define GL_GEOMETRY_PROGRAM_PARAMETER_BUFFER_NV 0x8DA3
#define GL_FRAGMENT_PROGRAM_PARAMETER_BUFFER_NV 0x8DA4
#define GL_PATH_FORMAT_SVG_NV 0x9070
#define GL_PATH_FORMAT_PS_NV 0x9071
#define GL_STANDARD_FONT_NAME_NV 0x9072
#define GL_SYSTEM_FONT_NAME_NV 0x9073
#define GL_FILE_NAME_NV 0x9074
#define GL_PATH_STROKE_WIDTH_NV 0x9075
#define GL_PATH_END_CAPS_NV 0x9076
#define GL_PATH_INITIAL_END_CAP_NV 0x9077
#define GL_PATH_TERMINAL_END_CAP_NV 0x9078
#define GL_PATH_JOIN_STYLE_NV 0x9079
#define GL_PATH_MITER_LIMIT_NV 0x907A
#define GL_PATH_DASH_CAPS_NV 0x907B
#define GL_PATH_INITIAL_DASH_CAP_NV 0x907C
#define GL_PATH_TERMINAL_DASH_CAP_NV 0x907D
#define GL_PATH_DASH_OFFSET_NV 0x907E
#define GL_PATH_CLIENT_LENGTH_NV 0x907F
#define GL_PATH_FILL_MODE_NV 0x9080
#define GL_PATH_FILL_MASK_NV 0x9081
#define GL_PATH_FILL_COVER_MODE_NV 0x9082
#define GL_PATH_STROKE_COVER_MODE_NV 0x9083
#define GL_PATH_STROKE_MASK_NV 0x9084
#define GL_COUNT_UP_NV 0x9088
#define GL_COUNT_DOWN_NV 0x9089
#define GL_PATH_OBJECT_BOUNDING_BOX_NV 0x908A
#define GL_CONVEX_HULL_NV 0x908B
#define GL_BOUNDING_BOX_NV 0x908D
#define GL_TRANSLATE_X_NV 0x908E
#define GL_TRANSLATE_Y_NV 0x908F
#define GL_TRANSLATE_2D_NV 0x9090
#define GL_TRANSLATE_3D_NV 0x9091
#define GL_AFFINE_2D_NV 0x9092
#define GL_AFFINE_3D_NV 0x9094
#define GL_TRANSPOSE_AFFINE_2D_NV 0x9096
#define GL_TRANSPOSE_AFFINE_3D_NV 0x9098
#define GL_UTF8_NV 0x909A
#define GL_UTF16_NV 0x909B
#define GL_BOUNDING_BOX_OF_BOUNDING_BOXES_NV 0x909C
#define GL_PATH_COMMAND_COUNT_NV 0x909D
#define GL_PATH_COORD_COUNT_NV 0x909E
#define GL_PATH_DASH_ARRAY_COUNT_NV 0x909F
#define GL_PATH_COMPUTED_LENGTH_NV 0x90A0
#define GL_PATH_FILL_BOUNDING_BOX_NV 0x90A1
#define GL_PATH_STROKE_BOUNDING_BOX_NV 0x90A2
#define GL_SQUARE_NV 0x90A3
#define GL_ROUND_NV 0x90A4
#define GL_TRIANGULAR_NV 0x90A5
#define GL_BEVEL_NV 0x90A6
#define GL_MITER_REVERT_NV 0x90A7
#define GL_MITER_TRUNCATE_NV 0x90A8
#define GL_SKIP_MISSING_GLYPH_NV 0x90A9
#define GL_USE_MISSING_GLYPH_NV 0x90AA
#define GL_PATH_ERROR_POSITION_NV 0x90AB
#define GL_ACCUM_ADJACENT_PAIRS_NV 0x90AD
#define GL_ADJACENT_PAIRS_NV 0x90AE
#define GL_FIRST_TO_REST_NV 0x90AF
#define GL_PATH_GEN_MODE_NV 0x90B0
#define GL_PATH_GEN_COEFF_NV 0x90B1
#define GL_PATH_GEN_COMPONENTS_NV 0x90B3
#define GL_PATH_STENCIL_FUNC_NV 0x90B7
#define GL_PATH_STENCIL_REF_NV 0x90B8
#define GL_PATH_STENCIL_VALUE_MASK_NV 0x90B9
#define GL_PATH_STENCIL_DEPTH_OFFSET_FACTOR_NV 0x90BD
#define GL_PATH_STENCIL_DEPTH_OFFSET_UNITS_NV 0x90BE
#define GL_PATH_COVER_DEPTH_FUNC_NV 0x90BF
#define GL_PATH_DASH_OFFSET_RESET_NV 0x90B4
#define GL_MOVE_TO_RESETS_NV 0x90B5
#define GL_MOVE_TO_CONTINUES_NV 0x90B6
#define GL_CLOSE_PATH_NV 0x00
#define GL_MOVE_TO_NV 0x02
#define GL_RELATIVE_MOVE_TO_NV 0x03
#define GL_LINE_TO_NV 0x04
#define GL_RELATIVE_LINE_TO_NV 0x05
#define GL_HORIZONTAL_LINE_TO_NV 0x06
#define GL_RELATIVE_HORIZONTAL_LINE_TO_NV 0x07
#define GL_VERTICAL_LINE_TO_NV 0x08
#define GL_RELATIVE_VERTICAL_LINE_TO_NV 0x09
#define GL_QUADRATIC_CURVE_TO_NV 0x0A
#define GL_RELATIVE_QUADRATIC_CURVE_TO_NV 0x0B
#define GL_CUBIC_CURVE_TO_NV 0x0C
#define GL_RELATIVE_CUBIC_CURVE_TO_NV 0x0D
#define GL_SMOOTH_QUADRATIC_CURVE_TO_NV 0x0E
#define GL_RELATIVE_SMOOTH_QUADRATIC_CURVE_TO_NV 0x0F
#define GL_SMOOTH_CUBIC_CURVE_TO_NV 0x10
#define GL_RELATIVE_SMOOTH_CUBIC_CURVE_TO_NV 0x11
#define GL_SMALL_CCW_ARC_TO_NV 0x12
#define GL_RELATIVE_SMALL_CCW_ARC_TO_NV 0x13
#define GL_SMALL_CW_ARC_TO_NV 0x14
#define GL_RELATIVE_SMALL_CW_ARC_TO_NV 0x15
#define GL_LARGE_CCW_ARC_TO_NV 0x16
#define GL_RELATIVE_LARGE_CCW_ARC_TO_NV 0x17
#define GL_LARGE_CW_ARC_TO_NV 0x18
#define GL_RELATIVE_LARGE_CW_ARC_TO_NV 0x19
#define GL_RESTART_PATH_NV 0xF0
#define GL_DUP_FIRST_CUBIC_CURVE_TO_NV 0xF2
#define GL_DUP_LAST_CUBIC_CURVE_TO_NV 0xF4
#define GL_RECT_NV 0xF6
#define GL_CIRCULAR_CCW_ARC_TO_NV 0xF8
#define GL_CIRCULAR_CW_ARC_TO_NV 0xFA
#define GL_CIRCULAR_TANGENT_ARC_TO_NV 0xFC
#define GL_ARC_TO_NV 0xFE
#define GL_RELATIVE_ARC_TO_NV 0xFF
#define GL_BOLD_BIT_NV 0x01
#define GL_ITALIC_BIT_NV 0x02
#define GL_GLYPH_WIDTH_BIT_NV 0x01
#define GL_GLYPH_HEIGHT_BIT_NV 0x02
#define GL_GLYPH_HORIZONTAL_BEARING_X_BIT_NV 0x04
#define GL_GLYPH_HORIZONTAL_BEARING_Y_BIT_NV 0x08
#define GL_GLYPH_HORIZONTAL_BEARING_ADVANCE_BIT_NV 0x10
#define GL_GLYPH_VERTICAL_BEARING_X_BIT_NV 0x20
#define GL_GLYPH_VERTICAL_BEARING_Y_BIT_NV 0x40
#define GL_GLYPH_VERTICAL_BEARING_ADVANCE_BIT_NV 0x80
#define GL_GLYPH_HAS_KERNING_BIT_NV 0x100
#define GL_FONT_X_MIN_BOUNDS_BIT_NV 0x00010000
#define GL_FONT_Y_MIN_BOUNDS_BIT_NV 0x00020000
#define GL_FONT_X_MAX_BOUNDS_BIT_NV 0x00040000
#define GL_FONT_Y_MAX_BOUNDS_BIT_NV 0x00080000
#define GL_FONT_UNITS_PER_EM_BIT_NV 0x00100000
#define GL_FONT_ASCENDER_BIT_NV 0x00200000
#define GL_FONT_DESCENDER_BIT_NV 0x00400000
#define GL_FONT_HEIGHT_BIT_NV 0x00800000
#define GL_FONT_MAX_ADVANCE_WIDTH_BIT_NV 0x01000000
#define GL_FONT_MAX_ADVANCE_HEIGHT_BIT_NV 0x02000000
#define GL_FONT_UNDERLINE_POSITION_BIT_NV 0x04000000
#define GL_FONT_UNDERLINE_THICKNESS_BIT_NV 0x08000000
#define GL_FONT_HAS_KERNING_BIT_NV 0x10000000
#define GL_ROUNDED_RECT_NV 0xE8
#define GL_RELATIVE_ROUNDED_RECT_NV 0xE9
#define GL_ROUNDED_RECT2_NV 0xEA
#define GL_RELATIVE_ROUNDED_RECT2_NV 0xEB
#define GL_ROUNDED_RECT4_NV 0xEC
#define GL_RELATIVE_ROUNDED_RECT4_NV 0xED
#define GL_ROUNDED_RECT8_NV 0xEE
#define GL_RELATIVE_ROUNDED_RECT8_NV 0xEF
#define GL_RELATIVE_RECT_NV 0xF7
#define GL_FONT_GLYPHS_AVAILABLE_NV 0x9368
#define GL_FONT_TARGET_UNAVAILABLE_NV 0x9369
#define GL_FONT_UNAVAILABLE_NV 0x936A
#define GL_FONT_UNINTELLIGIBLE_NV 0x936B
#define GL_CONIC_CURVE_TO_NV 0x1A
#define GL_RELATIVE_CONIC_CURVE_TO_NV 0x1B
#define GL_FONT_NUM_GLYPH_INDICES_BIT_NV 0x20000000
#define GL_STANDARD_FONT_FORMAT_NV 0x936C
#define GL_2_BYTES_NV 0x1407
#define GL_3_BYTES_NV 0x1408
#define GL_4_BYTES_NV 0x1409
#define GL_EYE_LINEAR_NV 0x2400
#define GL_OBJECT_LINEAR_NV 0x2401
#define GL_CONSTANT_NV 0x8576
#define GL_PATH_FOG_GEN_MODE_NV 0x90AC
#define GL_PRIMARY_COLOR 0x8577
#define GL_PRIMARY_COLOR_NV 0x852C
#define GL_SECONDARY_COLOR_NV 0x852D
#define GL_PATH_GEN_COLOR_FORMAT_NV 0x90B2
#define GL_PATH_PROJECTION_NV 0x1701
#define GL_PATH_MODELVIEW_NV 0x1700
#define GL_PATH_MODELVIEW_STACK_DEPTH_NV 0x0BA3
#define GL_PATH_MODELVIEW_MATRIX_NV 0x0BA6
#define GL_PATH_MAX_MODELVIEW_STACK_DEPTH_NV 0x0D36
#define GL_PATH_TRANSPOSE_MODELVIEW_MATRIX_NV 0x84E3
#define GL_PATH_PROJECTION_STACK_DEPTH_NV 0x0BA4
#define GL_PATH_PROJECTION_MATRIX_NV 0x0BA7
#define GL_PATH_MAX_PROJECTION_STACK_DEPTH_NV 0x0D38
#define GL_PATH_TRANSPOSE_PROJECTION_MATRIX_NV 0x84E4
#define GL_FRAGMENT_INPUT_NV 0x936D
#define GL_SHARED_EDGE_NV 0xC0
#define GL_WRITE_PIXEL_DATA_RANGE_NV 0x8878
#define GL_READ_PIXEL_DATA_RANGE_NV 0x8879
#define GL_WRITE_PIXEL_DATA_RANGE_LENGTH_NV 0x887A
#define GL_READ_PIXEL_DATA_RANGE_LENGTH_NV 0x887B
#define GL_WRITE_PIXEL_DATA_RANGE_POINTER_NV 0x887C
#define GL_READ_PIXEL_DATA_RANGE_POINTER_NV 0x887D
#define GL_POINT_SPRITE_NV 0x8861
#define GL_COORD_REPLACE_NV 0x8862
#define GL_POINT_SPRITE_R_MODE_NV 0x8863
#define GL_FRAME_NV 0x8E26
#define GL_FIELDS_NV 0x8E27
#define GL_CURRENT_TIME_NV 0x8E28
#define GL_NUM_FILL_STREAMS_NV 0x8E29
#define GL_PRESENT_TIME_NV 0x8E2A
#define GL_PRESENT_DURATION_NV 0x8E2B
#define GL_PRIMITIVE_RESTART_NV 0x8558
#define GL_PRIMITIVE_RESTART_INDEX_NV 0x8559
#define GL_REGISTER_COMBINERS_NV 0x8522
#define GL_VARIABLE_A_NV 0x8523
#define GL_VARIABLE_B_NV 0x8524
#define GL_VARIABLE_C_NV 0x8525
#define GL_VARIABLE_D_NV 0x8526
#define GL_VARIABLE_E_NV 0x8527
#define GL_VARIABLE_F_NV 0x8528
#define GL_VARIABLE_G_NV 0x8529
#define GL_CONSTANT_COLOR0_NV 0x852A
#define GL_CONSTANT_COLOR1_NV 0x852B
#define GL_SPARE0_NV 0x852E
#define GL_SPARE1_NV 0x852F
#define GL_DISCARD_NV 0x8530
#define GL_E_TIMES_F_NV 0x8531
#define GL_SPARE0_PLUS_SECONDARY_COLOR_NV 0x8532
#define GL_UNSIGNED_IDENTITY_NV 0x8536
#define GL_UNSIGNED_INVERT_NV 0x8537
#define GL_EXPAND_NORMAL_NV 0x8538
#define GL_EXPAND_NEGATE_NV 0x8539
#define GL_HALF_BIAS_NORMAL_NV 0x853A
#define GL_HALF_BIAS_NEGATE_NV 0x853B
#define GL_SIGNED_IDENTITY_NV 0x853C
#define GL_SIGNED_NEGATE_NV 0x853D
#define GL_SCALE_BY_TWO_NV 0x853E
#define GL_SCALE_BY_FOUR_NV 0x853F
#define GL_SCALE_BY_ONE_HALF_NV 0x8540
#define GL_BIAS_BY_NEGATIVE_ONE_HALF_NV 0x8541
#define GL_COMBINER_INPUT_NV 0x8542
#define GL_COMBINER_MAPPING_NV 0x8543
#define GL_COMBINER_COMPONENT_USAGE_NV 0x8544
#define GL_COMBINER_AB_DOT_PRODUCT_NV 0x8545
#define GL_COMBINER_CD_DOT_PRODUCT_NV 0x8546
#define GL_COMBINER_MUX_SUM_NV 0x8547
#define GL_COMBINER_SCALE_NV 0x8548
#define GL_COMBINER_BIAS_NV 0x8549
#define GL_COMBINER_AB_OUTPUT_NV 0x854A
#define GL_COMBINER_CD_OUTPUT_NV 0x854B
#define GL_COMBINER_SUM_OUTPUT_NV 0x854C
#define GL_MAX_GENERAL_COMBINERS_NV 0x854D
#define GL_NUM_GENERAL_COMBINERS_NV 0x854E
#define GL_COLOR_SUM_CLAMP_NV 0x854F
#define GL_COMBINER0_NV 0x8550
#define GL_COMBINER1_NV 0x8551
#define GL_COMBINER2_NV 0x8552
#define GL_COMBINER3_NV 0x8553
#define GL_COMBINER4_NV 0x8554
#define GL_COMBINER5_NV 0x8555
#define GL_COMBINER6_NV 0x8556
#define GL_COMBINER7_NV 0x8557
#define GL_PER_STAGE_CONSTANTS_NV 0x8535
#define GL_PURGED_CONTEXT_RESET_NV 0x92BB
#define GL_SAMPLE_LOCATION_SUBPIXEL_BITS_NV 0x933D
#define GL_SAMPLE_LOCATION_PIXEL_GRID_WIDTH_NV 0x933E
#define GL_SAMPLE_LOCATION_PIXEL_GRID_HEIGHT_NV 0x933F
#define GL_PROGRAMMABLE_SAMPLE_LOCATION_TABLE_SIZE_NV 0x9340
#define GL_SAMPLE_LOCATION_NV 0x8E50
#define GL_PROGRAMMABLE_SAMPLE_LOCATION_NV 0x9341
#define GL_FRAMEBUFFER_PROGRAMMABLE_SAMPLE_LOCATIONS_NV 0x9342
#define GL_FRAMEBUFFER_SAMPLE_LOCATION_PIXEL_GRID_NV 0x9343
#define GL_BUFFER_GPU_ADDRESS_NV 0x8F1D
#define GL_GPU_ADDRESS_NV 0x8F34
#define GL_MAX_SHADER_BUFFER_ADDRESS_NV 0x8F35
#define GL_SHADER_GLOBAL_ACCESS_BARRIER_BIT_NV 0x00000010
#define GL_READ_WRITE 0x88BA
#define GL_WRITE_ONLY 0x88B9
#define GL_WARP_SIZE_NV 0x9339
#define GL_WARPS_PER_SM_NV 0x933A
#define GL_SM_COUNT_NV 0x933B
#define GL_MAX_PROGRAM_PATCH_ATTRIBS_NV 0x86D8
#define GL_TESS_CONTROL_PROGRAM_NV 0x891E
#define GL_TESS_EVALUATION_PROGRAM_NV 0x891F
#define GL_TESS_CONTROL_PROGRAM_PARAMETER_BUFFER_NV 0x8C74
#define GL_TESS_EVALUATION_PROGRAM_PARAMETER_BUFFER_NV 0x8C75
#define GL_EMBOSS_LIGHT_NV 0x855D
#define GL_EMBOSS_CONSTANT_NV 0x855E
#define GL_EMBOSS_MAP_NV 0x855F
#define GL_NORMAL_MAP_NV 0x8511
#define GL_REFLECTION_MAP_NV 0x8512
#define GL_COMBINE4_NV 0x8503
#define GL_SOURCE3_RGB_NV 0x8583
#define GL_SOURCE3_ALPHA_NV 0x858B
#define GL_OPERAND3_RGB_NV 0x8593
#define GL_OPERAND3_ALPHA_NV 0x859B
#define GL_TEXTURE_UNSIGNED_REMAP_MODE_NV 0x888F
#define GL_TEXTURE_COVERAGE_SAMPLES_NV 0x9045
#define GL_TEXTURE_COLOR_SAMPLES_NV 0x9046
#define GL_TEXTURE_RECTANGLE_NV 0x84F5
#define GL_TEXTURE_BINDING_RECTANGLE_NV 0x84F6
#define GL_PROXY_TEXTURE_RECTANGLE_NV 0x84F7
#define GL_MAX_RECTANGLE_TEXTURE_SIZE_NV 0x84F8
#define GL_OFFSET_TEXTURE_RECTANGLE_NV 0x864C
#define GL_OFFSET_TEXTURE_RECTANGLE_SCALE_NV 0x864D
#define GL_DOT_PRODUCT_TEXTURE_RECTANGLE_NV 0x864E
#define GL_RGBA_UNSIGNED_DOT_PRODUCT_MAPPING_NV 0x86D9
#define GL_UNSIGNED_INT_S8_S8_8_8_NV 0x86DA
#define GL_UNSIGNED_INT_8_8_S8_S8_REV_NV 0x86DB
#define GL_DSDT_MAG_INTENSITY_NV 0x86DC
#define GL_SHADER_CONSISTENT_NV 0x86DD
#define GL_TEXTURE_SHADER_NV 0x86DE
#define GL_SHADER_OPERATION_NV 0x86DF
#define GL_CULL_MODES_NV 0x86E0
#define GL_OFFSET_TEXTURE_MATRIX_NV 0x86E1
#define GL_OFFSET_TEXTURE_SCALE_NV 0x86E2
#define GL_OFFSET_TEXTURE_BIAS_NV 0x86E3
#define GL_OFFSET_TEXTURE_2D_MATRIX_NV 0x86E1
#define GL_OFFSET_TEXTURE_2D_SCALE_NV 0x86E2
#define GL_OFFSET_TEXTURE_2D_BIAS_NV 0x86E3
#define GL_PREVIOUS_TEXTURE_INPUT_NV 0x86E4
#define GL_CONST_EYE_NV 0x86E5
#define GL_PASS_THROUGH_NV 0x86E6
#define GL_CULL_FRAGMENT_NV 0x86E7
#define GL_OFFSET_TEXTURE_2D_NV 0x86E8
#define GL_DEPENDENT_AR_TEXTURE_2D_NV 0x86E9
#define GL_DEPENDENT_GB_TEXTURE_2D_NV 0x86EA
#define GL_DOT_PRODUCT_NV 0x86EC
#define GL_DOT_PRODUCT_DEPTH_REPLACE_NV 0x86ED
#define GL_DOT_PRODUCT_TEXTURE_2D_NV 0x86EE
#define GL_DOT_PRODUCT_TEXTURE_CUBE_MAP_NV 0x86F0
#define GL_DOT_PRODUCT_DIFFUSE_CUBE_MAP_NV 0x86F1
#define GL_DOT_PRODUCT_REFLECT_CUBE_MAP_NV 0x86F2
#define GL_DOT_PRODUCT_CONST_EYE_REFLECT_CUBE_MAP_NV 0x86F3
#define GL_HILO_NV 0x86F4
#define GL_DSDT_NV 0x86F5
#define GL_DSDT_MAG_NV 0x86F6
#define GL_DSDT_MAG_VIB_NV 0x86F7
#define GL_HILO16_NV 0x86F8
#define GL_SIGNED_HILO_NV 0x86F9
#define GL_SIGNED_HILO16_NV 0x86FA
#define GL_SIGNED_RGBA_NV 0x86FB
#define GL_SIGNED_RGBA8_NV 0x86FC
#define GL_SIGNED_RGB_NV 0x86FE
#define GL_SIGNED_RGB8_NV 0x86FF
#define GL_SIGNED_LUMINANCE_NV 0x8701
#define GL_SIGNED_LUMINANCE8_NV 0x8702
#define GL_SIGNED_LUMINANCE_ALPHA_NV 0x8703
#define GL_SIGNED_LUMINANCE8_ALPHA8_NV 0x8704
#define GL_SIGNED_ALPHA_NV 0x8705
#define GL_SIGNED_ALPHA8_NV 0x8706
#define GL_SIGNED_INTENSITY_NV 0x8707
#define GL_SIGNED_INTENSITY8_NV 0x8708
#define GL_DSDT8_NV 0x8709
#define GL_DSDT8_MAG8_NV 0x870A
#define GL_DSDT8_MAG8_INTENSITY8_NV 0x870B
#define GL_SIGNED_RGB_UNSIGNED_ALPHA_NV 0x870C
#define GL_SIGNED_RGB8_UNSIGNED_ALPHA8_NV 0x870D
#define GL_HI_SCALE_NV 0x870E
#define GL_LO_SCALE_NV 0x870F
#define GL_DS_SCALE_NV 0x8710
#define GL_DT_SCALE_NV 0x8711
#define GL_MAGNITUDE_SCALE_NV 0x8712
#define GL_VIBRANCE_SCALE_NV 0x8713
#define GL_HI_BIAS_NV 0x8714
#define GL_LO_BIAS_NV 0x8715
#define GL_DS_BIAS_NV 0x8716
#define GL_DT_BIAS_NV 0x8717
#define GL_MAGNITUDE_BIAS_NV 0x8718
#define GL_VIBRANCE_BIAS_NV 0x8719
#define GL_TEXTURE_BORDER_VALUES_NV 0x871A
#define GL_TEXTURE_HI_SIZE_NV 0x871B
#define GL_TEXTURE_LO_SIZE_NV 0x871C
#define GL_TEXTURE_DS_SIZE_NV 0x871D
#define GL_TEXTURE_DT_SIZE_NV 0x871E
#define GL_TEXTURE_MAG_SIZE_NV 0x871F
#define GL_DOT_PRODUCT_TEXTURE_3D_NV 0x86EF
#define GL_OFFSET_PROJECTIVE_TEXTURE_2D_NV 0x8850
#define GL_OFFSET_PROJECTIVE_TEXTURE_2D_SCALE_NV 0x8851
#define GL_OFFSET_PROJECTIVE_TEXTURE_RECTANGLE_NV 0x8852
#define GL_OFFSET_PROJECTIVE_TEXTURE_RECTANGLE_SCALE_NV 0x8853
#define GL_OFFSET_HILO_TEXTURE_2D_NV 0x8854
#define GL_OFFSET_HILO_TEXTURE_RECTANGLE_NV 0x8855
#define GL_OFFSET_HILO_PROJECTIVE_TEXTURE_2D_NV 0x8856
#define GL_OFFSET_HILO_PROJECTIVE_TEXTURE_RECTANGLE_NV 0x8857
#define GL_DEPENDENT_HILO_TEXTURE_2D_NV 0x8858
#define GL_DEPENDENT_RGB_TEXTURE_3D_NV 0x8859
#define GL_DEPENDENT_RGB_TEXTURE_CUBE_MAP_NV 0x885A
#define GL_DOT_PRODUCT_PASS_THROUGH_NV 0x885B
#define GL_DOT_PRODUCT_TEXTURE_1D_NV 0x885C
#define GL_DOT_PRODUCT_AFFINE_DEPTH_REPLACE_NV 0x885D
#define GL_HILO8_NV 0x885E
#define GL_SIGNED_HILO8_NV 0x885F
#define GL_FORCE_BLUE_TO_ONE_NV 0x8860
#define GL_BACK_PRIMARY_COLOR_NV 0x8C77
#define GL_BACK_SECONDARY_COLOR_NV 0x8C78
#define GL_TEXTURE_COORD_NV 0x8C79
#define GL_CLIP_DISTANCE_NV 0x8C7A
#define GL_VERTEX_ID_NV 0x8C7B
#define GL_PRIMITIVE_ID_NV 0x8C7C
#define GL_GENERIC_ATTRIB_NV 0x8C7D
#define GL_TRANSFORM_FEEDBACK_ATTRIBS_NV 0x8C7E
#define GL_TRANSFORM_FEEDBACK_BUFFER_MODE_NV 0x8C7F
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS_NV 0x8C80
#define GL_ACTIVE_VARYINGS_NV 0x8C81
#define GL_ACTIVE_VARYING_MAX_LENGTH_NV 0x8C82
#define GL_TRANSFORM_FEEDBACK_VARYINGS_NV 0x8C83
#define GL_TRANSFORM_FEEDBACK_BUFFER_START_NV 0x8C84
#define GL_TRANSFORM_FEEDBACK_BUFFER_SIZE_NV 0x8C85
#define GL_TRANSFORM_FEEDBACK_RECORD_NV 0x8C86
#define GL_PRIMITIVES_GENERATED_NV 0x8C87
#define GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN_NV 0x8C88
#define GL_RASTERIZER_DISCARD_NV 0x8C89
#define GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS_NV 0x8C8A
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS_NV 0x8C8B
#define GL_INTERLEAVED_ATTRIBS_NV 0x8C8C
#define GL_SEPARATE_ATTRIBS_NV 0x8C8D
#define GL_TRANSFORM_FEEDBACK_BUFFER_NV 0x8C8E
#define GL_TRANSFORM_FEEDBACK_BUFFER_BINDING_NV 0x8C8F
#define GL_LAYER_NV 0x8DAA
#define GL_NEXT_BUFFER_NV -2
#define GL_SKIP_COMPONENTS4_NV -3
#define GL_SKIP_COMPONENTS3_NV -4
#define GL_SKIP_COMPONENTS2_NV -5
#define GL_SKIP_COMPONENTS1_NV -6
#define GL_TRANSFORM_FEEDBACK_NV 0x8E22
#define GL_TRANSFORM_FEEDBACK_BUFFER_PAUSED_NV 0x8E23
#define GL_TRANSFORM_FEEDBACK_BUFFER_ACTIVE_NV 0x8E24
#define GL_TRANSFORM_FEEDBACK_BINDING_NV 0x8E25
#define GL_UNIFORM_BUFFER_UNIFIED_NV 0x936E
#define GL_UNIFORM_BUFFER_ADDRESS_NV 0x936F
#define GL_UNIFORM_BUFFER_LENGTH_NV 0x9370
#define GL_SURFACE_STATE_NV 0x86EB
#define GL_SURFACE_REGISTERED_NV 0x86FD
#define GL_SURFACE_MAPPED_NV 0x8700
#define GL_WRITE_DISCARD_NV 0x88BE
#define GL_VERTEX_ARRAY_RANGE_NV 0x851D
#define GL_VERTEX_ARRAY_RANGE_LENGTH_NV 0x851E
#define GL_VERTEX_ARRAY_RANGE_VALID_NV 0x851F
#define GL_MAX_VERTEX_ARRAY_RANGE_ELEMENT_NV 0x8520
#define GL_VERTEX_ARRAY_RANGE_POINTER_NV 0x8521
#define GL_VERTEX_ARRAY_RANGE_WITHOUT_FLUSH_NV 0x8533
#define GL_VERTEX_ATTRIB_ARRAY_UNIFIED_NV 0x8F1E
#define GL_ELEMENT_ARRAY_UNIFIED_NV 0x8F1F
#define GL_VERTEX_ATTRIB_ARRAY_ADDRESS_NV 0x8F20
#define GL_VERTEX_ARRAY_ADDRESS_NV 0x8F21
#define GL_NORMAL_ARRAY_ADDRESS_NV 0x8F22
#define GL_COLOR_ARRAY_ADDRESS_NV 0x8F23
#define GL_INDEX_ARRAY_ADDRESS_NV 0x8F24
#define GL_TEXTURE_COORD_ARRAY_ADDRESS_NV 0x8F25
#define GL_EDGE_FLAG_ARRAY_ADDRESS_NV 0x8F26
#define GL_SECONDARY_COLOR_ARRAY_ADDRESS_NV 0x8F27
#define GL_FOG_COORD_ARRAY_ADDRESS_NV 0x8F28
#define GL_ELEMENT_ARRAY_ADDRESS_NV 0x8F29
#define GL_VERTEX_ATTRIB_ARRAY_LENGTH_NV 0x8F2A
#define GL_VERTEX_ARRAY_LENGTH_NV 0x8F2B
#define GL_NORMAL_ARRAY_LENGTH_NV 0x8F2C
#define GL_COLOR_ARRAY_LENGTH_NV 0x8F2D
#define GL_INDEX_ARRAY_LENGTH_NV 0x8F2E
#define GL_TEXTURE_COORD_ARRAY_LENGTH_NV 0x8F2F
#define GL_EDGE_FLAG_ARRAY_LENGTH_NV 0x8F30
#define GL_SECONDARY_COLOR_ARRAY_LENGTH_NV 0x8F31
#define GL_FOG_COORD_ARRAY_LENGTH_NV 0x8F32
#define GL_ELEMENT_ARRAY_LENGTH_NV 0x8F33
#define GL_DRAW_INDIRECT_UNIFIED_NV 0x8F40
#define GL_DRAW_INDIRECT_ADDRESS_NV 0x8F41
#define GL_DRAW_INDIRECT_LENGTH_NV 0x8F42
#define GL_VERTEX_PROGRAM_NV 0x8620
#define GL_VERTEX_STATE_PROGRAM_NV 0x8621
#define GL_ATTRIB_ARRAY_SIZE_NV 0x8623
#define GL_ATTRIB_ARRAY_STRIDE_NV 0x8624
#define GL_ATTRIB_ARRAY_TYPE_NV 0x8625
#define GL_CURRENT_ATTRIB_NV 0x8626
#define GL_PROGRAM_LENGTH_NV 0x8627
#define GL_PROGRAM_STRING_NV 0x8628
#define GL_MODELVIEW_PROJECTION_NV 0x8629
#define GL_IDENTITY_NV 0x862A
#define GL_INVERSE_NV 0x862B
#define GL_TRANSPOSE_NV 0x862C
#define GL_INVERSE_TRANSPOSE_NV 0x862D
#define GL_MAX_TRACK_MATRIX_STACK_DEPTH_NV 0x862E
#define GL_MAX_TRACK_MATRICES_NV 0x862F
#define GL_MATRIX0_NV 0x8630
#define GL_MATRIX1_NV 0x8631
#define GL_MATRIX2_NV 0x8632
#define GL_MATRIX3_NV 0x8633
#define GL_MATRIX4_NV 0x8634
#define GL_MATRIX5_NV 0x8635
#define GL_MATRIX6_NV 0x8636
#define GL_MATRIX7_NV 0x8637
#define GL_CURRENT_MATRIX_STACK_DEPTH_NV 0x8640
#define GL_CURRENT_MATRIX_NV 0x8641
#define GL_VERTEX_PROGRAM_POINT_SIZE_NV 0x8642
#define GL_VERTEX_PROGRAM_TWO_SIDE_NV 0x8643
#define GL_PROGRAM_PARAMETER_NV 0x8644
#define GL_ATTRIB_ARRAY_POINTER_NV 0x8645
#define GL_PROGRAM_TARGET_NV 0x8646
#define GL_PROGRAM_RESIDENT_NV 0x8647
#define GL_TRACK_MATRIX_NV 0x8648
#define GL_TRACK_MATRIX_TRANSFORM_NV 0x8649
#define GL_VERTEX_PROGRAM_BINDING_NV 0x864A
#define GL_PROGRAM_ERROR_POSITION_NV 0x864B
#define GL_VERTEX_ATTRIB_ARRAY0_NV 0x8650
#define GL_VERTEX_ATTRIB_ARRAY1_NV 0x8651
#define GL_VERTEX_ATTRIB_ARRAY2_NV 0x8652
#define GL_VERTEX_ATTRIB_ARRAY3_NV 0x8653
#define GL_VERTEX_ATTRIB_ARRAY4_NV 0x8654
#define GL_VERTEX_ATTRIB_ARRAY5_NV 0x8655
#define GL_VERTEX_ATTRIB_ARRAY6_NV 0x8656
#define GL_VERTEX_ATTRIB_ARRAY7_NV 0x8657
#define GL_VERTEX_ATTRIB_ARRAY8_NV 0x8658
#define GL_VERTEX_ATTRIB_ARRAY9_NV 0x8659
#define GL_VERTEX_ATTRIB_ARRAY10_NV 0x865A
#define GL_VERTEX_ATTRIB_ARRAY11_NV 0x865B
#define GL_VERTEX_ATTRIB_ARRAY12_NV 0x865C
#define GL_VERTEX_ATTRIB_ARRAY13_NV 0x865D
#define GL_VERTEX_ATTRIB_ARRAY14_NV 0x865E
#define GL_VERTEX_ATTRIB_ARRAY15_NV 0x865F
#define GL_MAP1_VERTEX_ATTRIB0_4_NV 0x8660
#define GL_MAP1_VERTEX_ATTRIB1_4_NV 0x8661
#define GL_MAP1_VERTEX_ATTRIB2_4_NV 0x8662
#define GL_MAP1_VERTEX_ATTRIB3_4_NV 0x8663
#define GL_MAP1_VERTEX_ATTRIB4_4_NV 0x8664
#define GL_MAP1_VERTEX_ATTRIB5_4_NV 0x8665
#define GL_MAP1_VERTEX_ATTRIB6_4_NV 0x8666
#define GL_MAP1_VERTEX_ATTRIB7_4_NV 0x8667
#define GL_MAP1_VERTEX_ATTRIB8_4_NV 0x8668
#define GL_MAP1_VERTEX_ATTRIB9_4_NV 0x8669
#define GL_MAP1_VERTEX_ATTRIB10_4_NV 0x866A
#define GL_MAP1_VERTEX_ATTRIB11_4_NV 0x866B
#define GL_MAP1_VERTEX_ATTRIB12_4_NV 0x866C
#define GL_MAP1_VERTEX_ATTRIB13_4_NV 0x866D
#define GL_MAP1_VERTEX_ATTRIB14_4_NV 0x866E
#define GL_MAP1_VERTEX_ATTRIB15_4_NV 0x866F
#define GL_MAP2_VERTEX_ATTRIB0_4_NV 0x8670
#define GL_MAP2_VERTEX_ATTRIB1_4_NV 0x8671
#define GL_MAP2_VERTEX_ATTRIB2_4_NV 0x8672
#define GL_MAP2_VERTEX_ATTRIB3_4_NV 0x8673
#define GL_MAP2_VERTEX_ATTRIB4_4_NV 0x8674
#define GL_MAP2_VERTEX_ATTRIB5_4_NV 0x8675
#define GL_MAP2_VERTEX_ATTRIB6_4_NV 0x8676
#define GL_MAP2_VERTEX_ATTRIB7_4_NV 0x8677
#define GL_MAP2_VERTEX_ATTRIB8_4_NV 0x8678
#define GL_MAP2_VERTEX_ATTRIB9_4_NV 0x8679
#define GL_MAP2_VERTEX_ATTRIB10_4_NV 0x867A
#define GL_MAP2_VERTEX_ATTRIB11_4_NV 0x867B
#define GL_MAP2_VERTEX_ATTRIB12_4_NV 0x867C
#define GL_MAP2_VERTEX_ATTRIB13_4_NV 0x867D
#define GL_MAP2_VERTEX_ATTRIB14_4_NV 0x867E
#define GL_MAP2_VERTEX_ATTRIB15_4_NV 0x867F
#define GL_VERTEX_ATTRIB_ARRAY_INTEGER_NV 0x88FD
#define GL_VIDEO_BUFFER_NV 0x9020
#define GL_VIDEO_BUFFER_BINDING_NV 0x9021
#define GL_FIELD_UPPER_NV 0x9022
#define GL_FIELD_LOWER_NV 0x9023
#define GL_NUM_VIDEO_CAPTURE_STREAMS_NV 0x9024
#define GL_NEXT_VIDEO_CAPTURE_BUFFER_STATUS_NV 0x9025
#define GL_VIDEO_CAPTURE_TO_422_SUPPORTED_NV 0x9026
#define GL_LAST_VIDEO_CAPTURE_STATUS_NV 0x9027
#define GL_VIDEO_BUFFER_PITCH_NV 0x9028
#define GL_VIDEO_COLOR_CONVERSION_MATRIX_NV 0x9029
#define GL_VIDEO_COLOR_CONVERSION_MAX_NV 0x902A
#define GL_VIDEO_COLOR_CONVERSION_MIN_NV 0x902B
#define GL_VIDEO_COLOR_CONVERSION_OFFSET_NV 0x902C
#define GL_VIDEO_BUFFER_INTERNAL_FORMAT_NV 0x902D
#define GL_PARTIAL_SUCCESS_NV 0x902E
#define GL_SUCCESS_NV 0x902F
#define GL_FAILURE_NV 0x9030
#define GL_YCBYCR8_422_NV 0x9031
#define GL_YCBAYCR8A_4224_NV 0x9032
#define GL_Z6Y10Z6CB10Z6Y10Z6CR10_422_NV 0x9033
#define GL_Z6Y10Z6CB10Z6A10Z6Y10Z6CR10Z6A10_4224_NV 0x9034
#define GL_Z4Y12Z4CB12Z4Y12Z4CR12_422_NV 0x9035
#define GL_Z4Y12Z4CB12Z4A12Z4Y12Z4CR12Z4A12_4224_NV 0x9036
#define GL_Z4Y12Z4CB12Z4CR12_444_NV 0x9037
#define GL_VIDEO_CAPTURE_FRAME_WIDTH_NV 0x9038
#define GL_VIDEO_CAPTURE_FRAME_HEIGHT_NV 0x9039
#define GL_VIDEO_CAPTURE_FIELD_UPPER_HEIGHT_NV 0x903A
#define GL_VIDEO_CAPTURE_FIELD_LOWER_HEIGHT_NV 0x903B
#define GL_VIDEO_CAPTURE_SURFACE_ORIGIN_NV 0x903C
#define GL_VIEWPORT_SWIZZLE_POSITIVE_X_NV 0x9350
#define GL_VIEWPORT_SWIZZLE_NEGATIVE_X_NV 0x9351
#define GL_VIEWPORT_SWIZZLE_POSITIVE_Y_NV 0x9352
#define GL_VIEWPORT_SWIZZLE_NEGATIVE_Y_NV 0x9353
#define GL_VIEWPORT_SWIZZLE_POSITIVE_Z_NV 0x9354
#define GL_VIEWPORT_SWIZZLE_NEGATIVE_Z_NV 0x9355
#define GL_VIEWPORT_SWIZZLE_POSITIVE_W_NV 0x9356
#define GL_VIEWPORT_SWIZZLE_NEGATIVE_W_NV 0x9357
#define GL_VIEWPORT_SWIZZLE_X_NV 0x9358
#define GL_VIEWPORT_SWIZZLE_Y_NV 0x9359
#define GL_VIEWPORT_SWIZZLE_Z_NV 0x935A
#define GL_VIEWPORT_SWIZZLE_W_NV 0x935B
#define GL_PALETTE4_RGB8_OES 0x8B90
#define GL_PALETTE4_RGBA8_OES 0x8B91
#define GL_PALETTE4_R5_G6_B5_OES 0x8B92
#define GL_PALETTE4_RGBA4_OES 0x8B93
#define GL_PALETTE4_RGB5_A1_OES 0x8B94
#define GL_PALETTE8_RGB8_OES 0x8B95
#define GL_PALETTE8_RGBA8_OES 0x8B96
#define GL_PALETTE8_R5_G6_B5_OES 0x8B97
#define GL_PALETTE8_RGBA4_OES 0x8B98
#define GL_PALETTE8_RGB5_A1_OES 0x8B99
#define GL_FIXED_OES 0x140C
#define GL_IMPLEMENTATION_COLOR_READ_TYPE_OES 0x8B9A
#define GL_IMPLEMENTATION_COLOR_READ_FORMAT_OES 0x8B9B
#define GL_INTERLACE_OML 0x8980
#define GL_INTERLACE_READ_OML 0x8981
#define GL_PACK_RESAMPLE_OML 0x8984
#define GL_UNPACK_RESAMPLE_OML 0x8985
#define GL_RESAMPLE_REPLICATE_OML 0x8986
#define GL_RESAMPLE_ZERO_FILL_OML 0x8987
#define GL_RESAMPLE_AVERAGE_OML 0x8988
#define GL_RESAMPLE_DECIMATE_OML 0x8989
#define GL_FORMAT_SUBSAMPLE_24_24_OML 0x8982
#define GL_FORMAT_SUBSAMPLE_244_244_OML 0x8983
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_NUM_VIEWS_OVR 0x9630
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_BASE_VIEW_INDEX_OVR 0x9632
#define GL_MAX_VIEWS_OVR 0x9631
#define GL_FRAMEBUFFER_INCOMPLETE_VIEW_TARGETS_OVR 0x9633
#define GL_PREFER_DOUBLEBUFFER_HINT_PGI 0x1A1F8
#define GL_CONSERVE_MEMORY_HINT_PGI 0x1A1FD
#define GL_RECLAIM_MEMORY_HINT_PGI 0x1A1FE
#define GL_NATIVE_GRAPHICS_HANDLE_PGI 0x1A202
#define GL_NATIVE_GRAPHICS_BEGIN_HINT_PGI 0x1A203
#define GL_NATIVE_GRAPHICS_END_HINT_PGI 0x1A204
#define GL_ALWAYS_FAST_HINT_PGI 0x1A20C
#define GL_ALWAYS_SOFT_HINT_PGI 0x1A20D
#define GL_ALLOW_DRAW_OBJ_HINT_PGI 0x1A20E
#define GL_ALLOW_DRAW_WIN_HINT_PGI 0x1A20F
#define GL_ALLOW_DRAW_FRG_HINT_PGI 0x1A210
#define GL_ALLOW_DRAW_MEM_HINT_PGI 0x1A211
#define GL_STRICT_DEPTHFUNC_HINT_PGI 0x1A216
#define GL_STRICT_LIGHTING_HINT_PGI 0x1A217
#define GL_STRICT_SCISSOR_HINT_PGI 0x1A218
#define GL_FULL_STIPPLE_HINT_PGI 0x1A219
#define GL_CLIP_NEAR_HINT_PGI 0x1A220
#define GL_CLIP_FAR_HINT_PGI 0x1A221
#define GL_WIDE_LINE_HINT_PGI 0x1A222
#define GL_BACK_NORMALS_HINT_PGI 0x1A223
#define GL_VERTEX_DATA_HINT_PGI 0x1A22A
#define GL_VERTEX_CONSISTENT_HINT_PGI 0x1A22B
#define GL_MATERIAL_SIDE_HINT_PGI 0x1A22C
#define GL_MAX_VERTEX_HINT_PGI 0x1A22D
#define GL_COLOR3_BIT_PGI 0x00010000
#define GL_COLOR4_BIT_PGI 0x00020000
#define GL_EDGEFLAG_BIT_PGI 0x00040000
#define GL_INDEX_BIT_PGI 0x00080000
#define GL_MAT_AMBIENT_BIT_PGI 0x00100000
#define GL_MAT_AMBIENT_AND_DIFFUSE_BIT_PGI 0x00200000
#define GL_MAT_DIFFUSE_BIT_PGI 0x00400000
#define GL_MAT_EMISSION_BIT_PGI 0x00800000
#define GL_MAT_COLOR_INDEXES_BIT_PGI 0x01000000
#define GL_MAT_SHININESS_BIT_PGI 0x02000000
#define GL_MAT_SPECULAR_BIT_PGI 0x04000000
#define GL_NORMAL_BIT_PGI 0x08000000
#define GL_TEXCOORD1_BIT_PGI 0x10000000
#define GL_TEXCOORD2_BIT_PGI 0x20000000
#define GL_TEXCOORD3_BIT_PGI 0x40000000
#define GL_TEXCOORD4_BIT_PGI 0x80000000
#define GL_VERTEX23_BIT_PGI 0x00000004
#define GL_VERTEX4_BIT_PGI 0x00000008
#define GL_SCREEN_COORDINATES_REND 0x8490
#define GL_INVERTED_SCREEN_W_REND 0x8491
#define GL_RGB_S3TC 0x83A0
#define GL_RGB4_S3TC 0x83A1
#define GL_RGBA_S3TC 0x83A2
#define GL_RGBA4_S3TC 0x83A3
#define GL_RGBA_DXT5_S3TC 0x83A4
#define GL_RGBA4_DXT5_S3TC 0x83A5
#define GL_DETAIL_TEXTURE_2D_SGIS 0x8095
#define GL_DETAIL_TEXTURE_2D_BINDING_SGIS 0x8096
#define GL_LINEAR_DETAIL_SGIS 0x8097
#define GL_LINEAR_DETAIL_ALPHA_SGIS 0x8098
#define GL_LINEAR_DETAIL_COLOR_SGIS 0x8099
#define GL_DETAIL_TEXTURE_LEVEL_SGIS 0x809A
#define GL_DETAIL_TEXTURE_MODE_SGIS 0x809B
#define GL_DETAIL_TEXTURE_FUNC_POINTS_SGIS 0x809C
#define GL_FOG_FUNC_SGIS 0x812A
#define GL_FOG_FUNC_POINTS_SGIS 0x812B
#define GL_MAX_FOG_FUNC_POINTS_SGIS 0x812C
#define GL_GENERATE_MIPMAP_SGIS 0x8191
#define GL_GENERATE_MIPMAP_HINT_SGIS 0x8192
#define GL_MULTISAMPLE_SGIS 0x809D
#define GL_SAMPLE_ALPHA_TO_MASK_SGIS 0x809E
#define GL_SAMPLE_ALPHA_TO_ONE_SGIS 0x809F
#define GL_SAMPLE_MASK_SGIS 0x80A0
#define GL_1PASS_SGIS 0x80A1
#define GL_2PASS_0_SGIS 0x80A2
#define GL_2PASS_1_SGIS 0x80A3
#define GL_4PASS_0_SGIS 0x80A4
#define GL_4PASS_1_SGIS 0x80A5
#define GL_4PASS_2_SGIS 0x80A6
#define GL_4PASS_3_SGIS 0x80A7
#define GL_SAMPLE_BUFFERS_SGIS 0x80A8
#define GL_SAMPLES_SGIS 0x80A9
#define GL_SAMPLE_MASK_VALUE_SGIS 0x80AA
#define GL_SAMPLE_MASK_INVERT_SGIS 0x80AB
#define GL_SAMPLE_PATTERN_SGIS 0x80AC
#define GL_PIXEL_TEXTURE_SGIS 0x8353
#define GL_PIXEL_FRAGMENT_RGB_SOURCE_SGIS 0x8354
#define GL_PIXEL_FRAGMENT_ALPHA_SOURCE_SGIS 0x8355
#define GL_PIXEL_GROUP_COLOR_SGIS 0x8356
#define GL_EYE_DISTANCE_TO_POINT_SGIS 0x81F0
#define GL_OBJECT_DISTANCE_TO_POINT_SGIS 0x81F1
#define GL_EYE_DISTANCE_TO_LINE_SGIS 0x81F2
#define GL_OBJECT_DISTANCE_TO_LINE_SGIS 0x81F3
#define GL_EYE_POINT_SGIS 0x81F4
#define GL_OBJECT_POINT_SGIS 0x81F5
#define GL_EYE_LINE_SGIS 0x81F6
#define GL_OBJECT_LINE_SGIS 0x81F7
#define GL_POINT_SIZE_MIN_SGIS 0x8126
#define GL_POINT_SIZE_MAX_SGIS 0x8127
#define GL_POINT_FADE_THRESHOLD_SIZE_SGIS 0x8128
#define GL_DISTANCE_ATTENUATION_SGIS 0x8129
#define GL_LINEAR_SHARPEN_SGIS 0x80AD
#define GL_LINEAR_SHARPEN_ALPHA_SGIS 0x80AE
#define GL_LINEAR_SHARPEN_COLOR_SGIS 0x80AF
#define GL_SHARPEN_TEXTURE_FUNC_POINTS_SGIS 0x80B0
#define GL_PACK_SKIP_VOLUMES_SGIS 0x8130
#define GL_PACK_IMAGE_DEPTH_SGIS 0x8131
#define GL_UNPACK_SKIP_VOLUMES_SGIS 0x8132
#define GL_UNPACK_IMAGE_DEPTH_SGIS 0x8133
#define GL_TEXTURE_4D_SGIS 0x8134
#define GL_PROXY_TEXTURE_4D_SGIS 0x8135
#define GL_TEXTURE_4DSIZE_SGIS 0x8136
#define GL_TEXTURE_WRAP_Q_SGIS 0x8137
#define GL_MAX_4D_TEXTURE_SIZE_SGIS 0x8138
#define GL_TEXTURE_4D_BINDING_SGIS 0x814F
#define GL_CLAMP_TO_BORDER_SGIS 0x812D
#define GL_TEXTURE_COLOR_WRITEMASK_SGIS 0x81EF
#define GL_CLAMP_TO_EDGE_SGIS 0x812F
#define GL_FILTER4_SGIS 0x8146
#define GL_TEXTURE_FILTER4_SIZE_SGIS 0x8147
#define GL_TEXTURE_MIN_LOD_SGIS 0x813A
#define GL_TEXTURE_MAX_LOD_SGIS 0x813B
#define GL_TEXTURE_BASE_LEVEL_SGIS 0x813C
#define GL_TEXTURE_MAX_LEVEL_SGIS 0x813D
#define GL_DUAL_ALPHA4_SGIS 0x8110
#define GL_DUAL_ALPHA8_SGIS 0x8111
#define GL_DUAL_ALPHA12_SGIS 0x8112
#define GL_DUAL_ALPHA16_SGIS 0x8113
#define GL_DUAL_LUMINANCE4_SGIS 0x8114
#define GL_DUAL_LUMINANCE8_SGIS 0x8115
#define GL_DUAL_LUMINANCE12_SGIS 0x8116
#define GL_DUAL_LUMINANCE16_SGIS 0x8117
#define GL_DUAL_INTENSITY4_SGIS 0x8118
#define GL_DUAL_INTENSITY8_SGIS 0x8119
#define GL_DUAL_INTENSITY12_SGIS 0x811A
#define GL_DUAL_INTENSITY16_SGIS 0x811B
#define GL_DUAL_LUMINANCE_ALPHA4_SGIS 0x811C
#define GL_DUAL_LUMINANCE_ALPHA8_SGIS 0x811D
#define GL_QUAD_ALPHA4_SGIS 0x811E
#define GL_QUAD_ALPHA8_SGIS 0x811F
#define GL_QUAD_LUMINANCE4_SGIS 0x8120
#define GL_QUAD_LUMINANCE8_SGIS 0x8121
#define GL_QUAD_INTENSITY4_SGIS 0x8122
#define GL_QUAD_INTENSITY8_SGIS 0x8123
#define GL_DUAL_TEXTURE_SELECT_SGIS 0x8124
#define GL_QUAD_TEXTURE_SELECT_SGIS 0x8125
#define GL_ASYNC_MARKER_SGIX 0x8329
#define GL_ASYNC_HISTOGRAM_SGIX 0x832C
#define GL_MAX_ASYNC_HISTOGRAM_SGIX 0x832D
#define GL_ASYNC_TEX_IMAGE_SGIX 0x835C
#define GL_ASYNC_DRAW_PIXELS_SGIX 0x835D
#define GL_ASYNC_READ_PIXELS_SGIX 0x835E
#define GL_MAX_ASYNC_TEX_IMAGE_SGIX 0x835F
#define GL_MAX_ASYNC_DRAW_PIXELS_SGIX 0x8360
#define GL_MAX_ASYNC_READ_PIXELS_SGIX 0x8361
#define GL_ALPHA_MIN_SGIX 0x8320
#define GL_ALPHA_MAX_SGIX 0x8321
#define GL_CALLIGRAPHIC_FRAGMENT_SGIX 0x8183
#define GL_LINEAR_CLIPMAP_LINEAR_SGIX 0x8170
#define GL_TEXTURE_CLIPMAP_CENTER_SGIX 0x8171
#define GL_TEXTURE_CLIPMAP_FRAME_SGIX 0x8172
#define GL_TEXTURE_CLIPMAP_OFFSET_SGIX 0x8173
#define GL_TEXTURE_CLIPMAP_VIRTUAL_DEPTH_SGIX 0x8174
#define GL_TEXTURE_CLIPMAP_LOD_OFFSET_SGIX 0x8175
#define GL_TEXTURE_CLIPMAP_DEPTH_SGIX 0x8176
#define GL_MAX_CLIPMAP_DEPTH_SGIX 0x8177
#define GL_MAX_CLIPMAP_VIRTUAL_DEPTH_SGIX 0x8178
#define GL_NEAREST_CLIPMAP_NEAREST_SGIX 0x844D
#define GL_NEAREST_CLIPMAP_LINEAR_SGIX 0x844E
#define GL_LINEAR_CLIPMAP_NEAREST_SGIX 0x844F
#define GL_CONVOLUTION_HINT_SGIX 0x8316
#define GL_DEPTH_COMPONENT16_SGIX 0x81A5
#define GL_DEPTH_COMPONENT24_SGIX 0x81A6
#define GL_DEPTH_COMPONENT32_SGIX 0x81A7
#define GL_FOG_OFFSET_SGIX 0x8198
#define GL_FOG_OFFSET_VALUE_SGIX 0x8199
#define GL_FRAGMENT_LIGHTING_SGIX 0x8400
#define GL_FRAGMENT_COLOR_MATERIAL_SGIX 0x8401
#define GL_FRAGMENT_COLOR_MATERIAL_FACE_SGIX 0x8402
#define GL_FRAGMENT_COLOR_MATERIAL_PARAMETER_SGIX 0x8403
#define GL_MAX_FRAGMENT_LIGHTS_SGIX 0x8404
#define GL_MAX_ACTIVE_LIGHTS_SGIX 0x8405
#define GL_CURRENT_RASTER_NORMAL_SGIX 0x8406
#define GL_LIGHT_ENV_MODE_SGIX 0x8407
#define GL_FRAGMENT_LIGHT_MODEL_LOCAL_VIEWER_SGIX 0x8408
#define GL_FRAGMENT_LIGHT_MODEL_TWO_SIDE_SGIX 0x8409
#define GL_FRAGMENT_LIGHT_MODEL_AMBIENT_SGIX 0x840A
#define GL_FRAGMENT_LIGHT_MODEL_NORMAL_INTERPOLATION_SGIX 0x840B
#define GL_FRAGMENT_LIGHT0_SGIX 0x840C
#define GL_FRAGMENT_LIGHT1_SGIX 0x840D
#define GL_FRAGMENT_LIGHT2_SGIX 0x840E
#define GL_FRAGMENT_LIGHT3_SGIX 0x840F
#define GL_FRAGMENT_LIGHT4_SGIX 0x8410
#define GL_FRAGMENT_LIGHT5_SGIX 0x8411
#define GL_FRAGMENT_LIGHT6_SGIX 0x8412
#define GL_FRAGMENT_LIGHT7_SGIX 0x8413
#define GL_FRAMEZOOM_SGIX 0x818B
#define GL_FRAMEZOOM_FACTOR_SGIX 0x818C
#define GL_MAX_FRAMEZOOM_FACTOR_SGIX 0x818D
#define GL_INSTRUMENT_BUFFER_POINTER_SGIX 0x8180
#define GL_INSTRUMENT_MEASUREMENTS_SGIX 0x8181
#define GL_INTERLACE_SGIX 0x8094
#define GL_IR_INSTRUMENT1_SGIX 0x817F
#define GL_LIST_PRIORITY_SGIX 0x8182
#define GL_PIXEL_TEX_GEN_SGIX 0x8139
#define GL_PIXEL_TEX_GEN_MODE_SGIX 0x832B
#define GL_PIXEL_TILE_BEST_ALIGNMENT_SGIX 0x813E
#define GL_PIXEL_TILE_CACHE_INCREMENT_SGIX 0x813F
#define GL_PIXEL_TILE_WIDTH_SGIX 0x8140
#define GL_PIXEL_TILE_HEIGHT_SGIX 0x8141
#define GL_PIXEL_TILE_GRID_WIDTH_SGIX 0x8142
#define GL_PIXEL_TILE_GRID_HEIGHT_SGIX 0x8143
#define GL_PIXEL_TILE_GRID_DEPTH_SGIX 0x8144
#define GL_PIXEL_TILE_CACHE_SIZE_SGIX 0x8145
#define GL_TEXTURE_DEFORMATION_BIT_SGIX 0x00000001
#define GL_GEOMETRY_DEFORMATION_BIT_SGIX 0x00000002
#define GL_GEOMETRY_DEFORMATION_SGIX 0x8194
#define GL_TEXTURE_DEFORMATION_SGIX 0x8195
#define GL_DEFORMATIONS_MASK_SGIX 0x8196
#define GL_MAX_DEFORMATION_ORDER_SGIX 0x8197
#define GL_REFERENCE_PLANE_SGIX 0x817D
#define GL_REFERENCE_PLANE_EQUATION_SGIX 0x817E
#define GL_PACK_RESAMPLE_SGIX 0x842E
#define GL_UNPACK_RESAMPLE_SGIX 0x842F
#define GL_RESAMPLE_REPLICATE_SGIX 0x8433
#define GL_RESAMPLE_ZERO_FILL_SGIX 0x8434
#define GL_RESAMPLE_DECIMATE_SGIX 0x8430
#define GL_SCALEBIAS_HINT_SGIX 0x8322
#define GL_TEXTURE_COMPARE_SGIX 0x819A
#define GL_TEXTURE_COMPARE_OPERATOR_SGIX 0x819B
#define GL_TEXTURE_LEQUAL_R_SGIX 0x819C
#define GL_TEXTURE_GEQUAL_R_SGIX 0x819D
#define GL_SHADOW_AMBIENT_SGIX 0x80BF
#define GL_SPRITE_SGIX 0x8148
#define GL_SPRITE_MODE_SGIX 0x8149
#define GL_SPRITE_AXIS_SGIX 0x814A
#define GL_SPRITE_TRANSLATION_SGIX 0x814B
#define GL_SPRITE_AXIAL_SGIX 0x814C
#define GL_SPRITE_OBJECT_ALIGNED_SGIX 0x814D
#define GL_SPRITE_EYE_ALIGNED_SGIX 0x814E
#define GL_PACK_SUBSAMPLE_RATE_SGIX 0x85A0
#define GL_UNPACK_SUBSAMPLE_RATE_SGIX 0x85A1
#define GL_PIXEL_SUBSAMPLE_4444_SGIX 0x85A2
#define GL_PIXEL_SUBSAMPLE_2424_SGIX 0x85A3
#define GL_PIXEL_SUBSAMPLE_4242_SGIX 0x85A4
#define GL_TEXTURE_ENV_BIAS_SGIX 0x80BE
#define GL_TEXTURE_MAX_CLAMP_S_SGIX 0x8369
#define GL_TEXTURE_MAX_CLAMP_T_SGIX 0x836A
#define GL_TEXTURE_MAX_CLAMP_R_SGIX 0x836B
#define GL_TEXTURE_LOD_BIAS_S_SGIX 0x818E
#define GL_TEXTURE_LOD_BIAS_T_SGIX 0x818F
#define GL_TEXTURE_LOD_BIAS_R_SGIX 0x8190
#define GL_TEXTURE_MULTI_BUFFER_HINT_SGIX 0x812E
#define GL_POST_TEXTURE_FILTER_BIAS_SGIX 0x8179
#define GL_POST_TEXTURE_FILTER_SCALE_SGIX 0x817A
#define GL_POST_TEXTURE_FILTER_BIAS_RANGE_SGIX 0x817B
#define GL_POST_TEXTURE_FILTER_SCALE_RANGE_SGIX 0x817C
#define GL_VERTEX_PRECLIP_SGIX 0x83EE
#define GL_VERTEX_PRECLIP_HINT_SGIX 0x83EF
#define GL_YCRCB_422_SGIX 0x81BB
#define GL_YCRCB_444_SGIX 0x81BC
#define GL_YCRCB_SGIX 0x8318
#define GL_YCRCBA_SGIX 0x8319
#define GL_COLOR_MATRIX_SGI 0x80B1
#define GL_COLOR_MATRIX_STACK_DEPTH_SGI 0x80B2
#define GL_MAX_COLOR_MATRIX_STACK_DEPTH_SGI 0x80B3
#define GL_POST_COLOR_MATRIX_RED_SCALE_SGI 0x80B4
#define GL_POST_COLOR_MATRIX_GREEN_SCALE_SGI 0x80B5
#define GL_POST_COLOR_MATRIX_BLUE_SCALE_SGI 0x80B6
#define GL_POST_COLOR_MATRIX_ALPHA_SCALE_SGI 0x80B7
#define GL_POST_COLOR_MATRIX_RED_BIAS_SGI 0x80B8
#define GL_POST_COLOR_MATRIX_GREEN_BIAS_SGI 0x80B9
#define GL_POST_COLOR_MATRIX_BLUE_BIAS_SGI 0x80BA
#define GL_POST_COLOR_MATRIX_ALPHA_BIAS_SGI 0x80BB
#define GL_COLOR_TABLE_SGI 0x80D0
#define GL_POST_CONVOLUTION_COLOR_TABLE_SGI 0x80D1
#define GL_POST_COLOR_MATRIX_COLOR_TABLE_SGI 0x80D2
#define GL_PROXY_COLOR_TABLE_SGI 0x80D3
#define GL_PROXY_POST_CONVOLUTION_COLOR_TABLE_SGI 0x80D4
#define GL_PROXY_POST_COLOR_MATRIX_COLOR_TABLE_SGI 0x80D5
#define GL_COLOR_TABLE_SCALE_SGI 0x80D6
#define GL_COLOR_TABLE_BIAS_SGI 0x80D7
#define GL_COLOR_TABLE_FORMAT_SGI 0x80D8
#define GL_COLOR_TABLE_WIDTH_SGI 0x80D9
#define GL_COLOR_TABLE_RED_SIZE_SGI 0x80DA
#define GL_COLOR_TABLE_GREEN_SIZE_SGI 0x80DB
#define GL_COLOR_TABLE_BLUE_SIZE_SGI 0x80DC
#define GL_COLOR_TABLE_ALPHA_SIZE_SGI 0x80DD
#define GL_COLOR_TABLE_LUMINANCE_SIZE_SGI 0x80DE
#define GL_COLOR_TABLE_INTENSITY_SIZE_SGI 0x80DF
#define GL_TEXTURE_COLOR_TABLE_SGI 0x80BC
#define GL_PROXY_TEXTURE_COLOR_TABLE_SGI 0x80BD
#define GL_UNPACK_CONSTANT_DATA_SUNX 0x81D5
#define GL_TEXTURE_CONSTANT_DATA_SUNX 0x81D6
#define GL_WRAP_BORDER_SUN 0x81D4
#define GL_GLOBAL_ALPHA_SUN 0x81D9
#define GL_GLOBAL_ALPHA_FACTOR_SUN 0x81DA
#define GL_QUAD_MESH_SUN 0x8614
#define GL_TRIANGLE_MESH_SUN 0x8615
#define GL_SLICE_ACCUM_SUN 0x85CC
#define GL_RESTART_SUN 0x0001
#define GL_REPLACE_MIDDLE_SUN 0x0002
#define GL_REPLACE_OLDEST_SUN 0x0003
#define GL_TRIANGLE_LIST_SUN 0x81D7
#define GL_REPLACEMENT_CODE_SUN 0x81D8
#define GL_REPLACEMENT_CODE_ARRAY_SUN 0x85C0
#define GL_REPLACEMENT_CODE_ARRAY_TYPE_SUN 0x85C1
#define GL_REPLACEMENT_CODE_ARRAY_STRIDE_SUN 0x85C2
#define GL_REPLACEMENT_CODE_ARRAY_POINTER_SUN 0x85C3
#define GL_R1UI_V3F_SUN 0x85C4
#define GL_R1UI_C4UB_V3F_SUN 0x85C5
#define GL_R1UI_C3F_V3F_SUN 0x85C6
#define GL_R1UI_N3F_V3F_SUN 0x85C7
#define GL_R1UI_C4F_N3F_V3F_SUN 0x85C8
#define GL_R1UI_T2F_V3F_SUN 0x85C9
#define GL_R1UI_T2F_N3F_V3F_SUN 0x85CA
#define GL_R1UI_T2F_C4F_N3F_V3F_SUN 0x85CB
#define GL_PHONG_WIN 0x80EA
#define GL_PHONG_HINT_WIN 0x80EB
#define GL_FOG_SPECULAR_TEXTURE_WIN 0x80EC
#ifndef GL_3DFX_multisample
#define GL_3DFX_multisample 1
GLAPI int CPPGL_GL_3DFX_multisample;
#endif
#ifndef GL_3DFX_tbuffer
#define GL_3DFX_tbuffer 1
GLAPI int CPPGL_GL_3DFX_tbuffer;
typedef void (APIENTRYP PFNGLTBUFFERMASK3DFXPROC)(GLuint mask);
GLAPI PFNGLTBUFFERMASK3DFXPROC cppgl_glTbufferMask3DFX;
#define glTbufferMask3DFX cppgl_glTbufferMask3DFX
#endif
#ifndef GL_3DFX_texture_compression_FXT1
#define GL_3DFX_texture_compression_FXT1 1
GLAPI int CPPGL_GL_3DFX_texture_compression_FXT1;
#endif
#ifndef GL_AMD_blend_minmax_factor
#define GL_AMD_blend_minmax_factor 1
GLAPI int CPPGL_GL_AMD_blend_minmax_factor;
#endif
#ifndef GL_AMD_conservative_depth
#define GL_AMD_conservative_depth 1
GLAPI int CPPGL_GL_AMD_conservative_depth;
#endif
#ifndef GL_AMD_debug_output
#define GL_AMD_debug_output 1
GLAPI int CPPGL_GL_AMD_debug_output;
typedef void (APIENTRYP PFNGLDEBUGMESSAGEENABLEAMDPROC)(GLenum category, GLenum severity, GLsizei count, const GLuint *ids, GLboolean enabled);
GLAPI PFNGLDEBUGMESSAGEENABLEAMDPROC cppgl_glDebugMessageEnableAMD;
#define glDebugMessageEnableAMD cppgl_glDebugMessageEnableAMD
typedef void (APIENTRYP PFNGLDEBUGMESSAGEINSERTAMDPROC)(GLenum category, GLenum severity, GLuint id, GLsizei length, const GLchar *buf);
GLAPI PFNGLDEBUGMESSAGEINSERTAMDPROC cppgl_glDebugMessageInsertAMD;
#define glDebugMessageInsertAMD cppgl_glDebugMessageInsertAMD
typedef void (APIENTRYP PFNGLDEBUGMESSAGECALLBACKAMDPROC)(GLDEBUGPROCAMD callback, void *userParam);
GLAPI PFNGLDEBUGMESSAGECALLBACKAMDPROC cppgl_glDebugMessageCallbackAMD;
#define glDebugMessageCallbackAMD cppgl_glDebugMessageCallbackAMD
typedef GLuint (APIENTRYP PFNGLGETDEBUGMESSAGELOGAMDPROC)(GLuint count, GLsizei bufsize, GLenum *categories, GLuint *severities, GLuint *ids, GLsizei *lengths, GLchar *message);
GLAPI PFNGLGETDEBUGMESSAGELOGAMDPROC cppgl_glGetDebugMessageLogAMD;
#define glGetDebugMessageLogAMD cppgl_glGetDebugMessageLogAMD
#endif
#ifndef GL_AMD_depth_clamp_separate
#define GL_AMD_depth_clamp_separate 1
GLAPI int CPPGL_GL_AMD_depth_clamp_separate;
#endif
#ifndef GL_AMD_draw_buffers_blend
#define GL_AMD_draw_buffers_blend 1
GLAPI int CPPGL_GL_AMD_draw_buffers_blend;
typedef void (APIENTRYP PFNGLBLENDFUNCINDEXEDAMDPROC)(GLuint buf, GLenum src, GLenum dst);
GLAPI PFNGLBLENDFUNCINDEXEDAMDPROC cppgl_glBlendFuncIndexedAMD;
#define glBlendFuncIndexedAMD cppgl_glBlendFuncIndexedAMD
typedef void (APIENTRYP PFNGLBLENDFUNCSEPARATEINDEXEDAMDPROC)(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
GLAPI PFNGLBLENDFUNCSEPARATEINDEXEDAMDPROC cppgl_glBlendFuncSeparateIndexedAMD;
#define glBlendFuncSeparateIndexedAMD cppgl_glBlendFuncSeparateIndexedAMD
typedef void (APIENTRYP PFNGLBLENDEQUATIONINDEXEDAMDPROC)(GLuint buf, GLenum mode);
GLAPI PFNGLBLENDEQUATIONINDEXEDAMDPROC cppgl_glBlendEquationIndexedAMD;
#define glBlendEquationIndexedAMD cppgl_glBlendEquationIndexedAMD
typedef void (APIENTRYP PFNGLBLENDEQUATIONSEPARATEINDEXEDAMDPROC)(GLuint buf, GLenum modeRGB, GLenum modeAlpha);
GLAPI PFNGLBLENDEQUATIONSEPARATEINDEXEDAMDPROC cppgl_glBlendEquationSeparateIndexedAMD;
#define glBlendEquationSeparateIndexedAMD cppgl_glBlendEquationSeparateIndexedAMD
#endif
#ifndef GL_AMD_gcn_shader
#define GL_AMD_gcn_shader 1
GLAPI int CPPGL_GL_AMD_gcn_shader;
#endif
#ifndef GL_AMD_gpu_shader_half_float
#define GL_AMD_gpu_shader_half_float 1
GLAPI int CPPGL_GL_AMD_gpu_shader_half_float;
#endif
#ifndef GL_AMD_gpu_shader_int64
#define GL_AMD_gpu_shader_int64 1
GLAPI int CPPGL_GL_AMD_gpu_shader_int64;
typedef void (APIENTRYP PFNGLUNIFORM1I64NVPROC)(GLint location, GLint64EXT x);
GLAPI PFNGLUNIFORM1I64NVPROC cppgl_glUniform1i64NV;
#define glUniform1i64NV cppgl_glUniform1i64NV
typedef void (APIENTRYP PFNGLUNIFORM2I64NVPROC)(GLint location, GLint64EXT x, GLint64EXT y);
GLAPI PFNGLUNIFORM2I64NVPROC cppgl_glUniform2i64NV;
#define glUniform2i64NV cppgl_glUniform2i64NV
typedef void (APIENTRYP PFNGLUNIFORM3I64NVPROC)(GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z);
GLAPI PFNGLUNIFORM3I64NVPROC cppgl_glUniform3i64NV;
#define glUniform3i64NV cppgl_glUniform3i64NV
typedef void (APIENTRYP PFNGLUNIFORM4I64NVPROC)(GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w);
GLAPI PFNGLUNIFORM4I64NVPROC cppgl_glUniform4i64NV;
#define glUniform4i64NV cppgl_glUniform4i64NV
typedef void (APIENTRYP PFNGLUNIFORM1I64VNVPROC)(GLint location, GLsizei count, const GLint64EXT *value);
GLAPI PFNGLUNIFORM1I64VNVPROC cppgl_glUniform1i64vNV;
#define glUniform1i64vNV cppgl_glUniform1i64vNV
typedef void (APIENTRYP PFNGLUNIFORM2I64VNVPROC)(GLint location, GLsizei count, const GLint64EXT *value);
GLAPI PFNGLUNIFORM2I64VNVPROC cppgl_glUniform2i64vNV;
#define glUniform2i64vNV cppgl_glUniform2i64vNV
typedef void (APIENTRYP PFNGLUNIFORM3I64VNVPROC)(GLint location, GLsizei count, const GLint64EXT *value);
GLAPI PFNGLUNIFORM3I64VNVPROC cppgl_glUniform3i64vNV;
#define glUniform3i64vNV cppgl_glUniform3i64vNV
typedef void (APIENTRYP PFNGLUNIFORM4I64VNVPROC)(GLint location, GLsizei count, const GLint64EXT *value);
GLAPI PFNGLUNIFORM4I64VNVPROC cppgl_glUniform4i64vNV;
#define glUniform4i64vNV cppgl_glUniform4i64vNV
typedef void (APIENTRYP PFNGLUNIFORM1UI64NVPROC)(GLint location, GLuint64EXT x);
GLAPI PFNGLUNIFORM1UI64NVPROC cppgl_glUniform1ui64NV;
#define glUniform1ui64NV cppgl_glUniform1ui64NV
typedef void (APIENTRYP PFNGLUNIFORM2UI64NVPROC)(GLint location, GLuint64EXT x, GLuint64EXT y);
GLAPI PFNGLUNIFORM2UI64NVPROC cppgl_glUniform2ui64NV;
#define glUniform2ui64NV cppgl_glUniform2ui64NV
typedef void (APIENTRYP PFNGLUNIFORM3UI64NVPROC)(GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z);
GLAPI PFNGLUNIFORM3UI64NVPROC cppgl_glUniform3ui64NV;
#define glUniform3ui64NV cppgl_glUniform3ui64NV
typedef void (APIENTRYP PFNGLUNIFORM4UI64NVPROC)(GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w);
GLAPI PFNGLUNIFORM4UI64NVPROC cppgl_glUniform4ui64NV;
#define glUniform4ui64NV cppgl_glUniform4ui64NV
typedef void (APIENTRYP PFNGLUNIFORM1UI64VNVPROC)(GLint location, GLsizei count, const GLuint64EXT *value);
GLAPI PFNGLUNIFORM1UI64VNVPROC cppgl_glUniform1ui64vNV;
#define glUniform1ui64vNV cppgl_glUniform1ui64vNV
typedef void (APIENTRYP PFNGLUNIFORM2UI64VNVPROC)(GLint location, GLsizei count, const GLuint64EXT *value);
GLAPI PFNGLUNIFORM2UI64VNVPROC cppgl_glUniform2ui64vNV;
#define glUniform2ui64vNV cppgl_glUniform2ui64vNV
typedef void (APIENTRYP PFNGLUNIFORM3UI64VNVPROC)(GLint location, GLsizei count, const GLuint64EXT *value);
GLAPI PFNGLUNIFORM3UI64VNVPROC cppgl_glUniform3ui64vNV;
#define glUniform3ui64vNV cppgl_glUniform3ui64vNV
typedef void (APIENTRYP PFNGLUNIFORM4UI64VNVPROC)(GLint location, GLsizei count, const GLuint64EXT *value);
GLAPI PFNGLUNIFORM4UI64VNVPROC cppgl_glUniform4ui64vNV;
#define glUniform4ui64vNV cppgl_glUniform4ui64vNV
typedef void (APIENTRYP PFNGLGETUNIFORMI64VNVPROC)(GLuint program, GLint location, GLint64EXT *params);
GLAPI PFNGLGETUNIFORMI64VNVPROC cppgl_glGetUniformi64vNV;
#define glGetUniformi64vNV cppgl_glGetUniformi64vNV
typedef void (APIENTRYP PFNGLGETUNIFORMUI64VNVPROC)(GLuint program, GLint location, GLuint64EXT *params);
GLAPI PFNGLGETUNIFORMUI64VNVPROC cppgl_glGetUniformui64vNV;
#define glGetUniformui64vNV cppgl_glGetUniformui64vNV
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1I64NVPROC)(GLuint program, GLint location, GLint64EXT x);
GLAPI PFNGLPROGRAMUNIFORM1I64NVPROC cppgl_glProgramUniform1i64NV;
#define glProgramUniform1i64NV cppgl_glProgramUniform1i64NV
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2I64NVPROC)(GLuint program, GLint location, GLint64EXT x, GLint64EXT y);
GLAPI PFNGLPROGRAMUNIFORM2I64NVPROC cppgl_glProgramUniform2i64NV;
#define glProgramUniform2i64NV cppgl_glProgramUniform2i64NV
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3I64NVPROC)(GLuint program, GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z);
GLAPI PFNGLPROGRAMUNIFORM3I64NVPROC cppgl_glProgramUniform3i64NV;
#define glProgramUniform3i64NV cppgl_glProgramUniform3i64NV
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4I64NVPROC)(GLuint program, GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w);
GLAPI PFNGLPROGRAMUNIFORM4I64NVPROC cppgl_glProgramUniform4i64NV;
#define glProgramUniform4i64NV cppgl_glProgramUniform4i64NV
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1I64VNVPROC)(GLuint program, GLint location, GLsizei count, const GLint64EXT *value);
GLAPI PFNGLPROGRAMUNIFORM1I64VNVPROC cppgl_glProgramUniform1i64vNV;
#define glProgramUniform1i64vNV cppgl_glProgramUniform1i64vNV
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2I64VNVPROC)(GLuint program, GLint location, GLsizei count, const GLint64EXT *value);
GLAPI PFNGLPROGRAMUNIFORM2I64VNVPROC cppgl_glProgramUniform2i64vNV;
#define glProgramUniform2i64vNV cppgl_glProgramUniform2i64vNV
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3I64VNVPROC)(GLuint program, GLint location, GLsizei count, const GLint64EXT *value);
GLAPI PFNGLPROGRAMUNIFORM3I64VNVPROC cppgl_glProgramUniform3i64vNV;
#define glProgramUniform3i64vNV cppgl_glProgramUniform3i64vNV
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4I64VNVPROC)(GLuint program, GLint location, GLsizei count, const GLint64EXT *value);
GLAPI PFNGLPROGRAMUNIFORM4I64VNVPROC cppgl_glProgramUniform4i64vNV;
#define glProgramUniform4i64vNV cppgl_glProgramUniform4i64vNV
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1UI64NVPROC)(GLuint program, GLint location, GLuint64EXT x);
GLAPI PFNGLPROGRAMUNIFORM1UI64NVPROC cppgl_glProgramUniform1ui64NV;
#define glProgramUniform1ui64NV cppgl_glProgramUniform1ui64NV
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2UI64NVPROC)(GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y);
GLAPI PFNGLPROGRAMUNIFORM2UI64NVPROC cppgl_glProgramUniform2ui64NV;
#define glProgramUniform2ui64NV cppgl_glProgramUniform2ui64NV
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3UI64NVPROC)(GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z);
GLAPI PFNGLPROGRAMUNIFORM3UI64NVPROC cppgl_glProgramUniform3ui64NV;
#define glProgramUniform3ui64NV cppgl_glProgramUniform3ui64NV
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4UI64NVPROC)(GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w);
GLAPI PFNGLPROGRAMUNIFORM4UI64NVPROC cppgl_glProgramUniform4ui64NV;
#define glProgramUniform4ui64NV cppgl_glProgramUniform4ui64NV
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1UI64VNVPROC)(GLuint program, GLint location, GLsizei count, const GLuint64EXT *value);
GLAPI PFNGLPROGRAMUNIFORM1UI64VNVPROC cppgl_glProgramUniform1ui64vNV;
#define glProgramUniform1ui64vNV cppgl_glProgramUniform1ui64vNV
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2UI64VNVPROC)(GLuint program, GLint location, GLsizei count, const GLuint64EXT *value);
GLAPI PFNGLPROGRAMUNIFORM2UI64VNVPROC cppgl_glProgramUniform2ui64vNV;
#define glProgramUniform2ui64vNV cppgl_glProgramUniform2ui64vNV
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3UI64VNVPROC)(GLuint program, GLint location, GLsizei count, const GLuint64EXT *value);
GLAPI PFNGLPROGRAMUNIFORM3UI64VNVPROC cppgl_glProgramUniform3ui64vNV;
#define glProgramUniform3ui64vNV cppgl_glProgramUniform3ui64vNV
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4UI64VNVPROC)(GLuint program, GLint location, GLsizei count, const GLuint64EXT *value);
GLAPI PFNGLPROGRAMUNIFORM4UI64VNVPROC cppgl_glProgramUniform4ui64vNV;
#define glProgramUniform4ui64vNV cppgl_glProgramUniform4ui64vNV
#endif
#ifndef GL_AMD_interleaved_elements
#define GL_AMD_interleaved_elements 1
GLAPI int CPPGL_GL_AMD_interleaved_elements;
typedef void (APIENTRYP PFNGLVERTEXATTRIBPARAMETERIAMDPROC)(GLuint index, GLenum pname, GLint param);
GLAPI PFNGLVERTEXATTRIBPARAMETERIAMDPROC cppgl_glVertexAttribParameteriAMD;
#define glVertexAttribParameteriAMD cppgl_glVertexAttribParameteriAMD
#endif
#ifndef GL_AMD_multi_draw_indirect
#define GL_AMD_multi_draw_indirect 1
GLAPI int CPPGL_GL_AMD_multi_draw_indirect;
typedef void (APIENTRYP PFNGLMULTIDRAWARRAYSINDIRECTAMDPROC)(GLenum mode, const void *indirect, GLsizei primcount, GLsizei stride);
GLAPI PFNGLMULTIDRAWARRAYSINDIRECTAMDPROC cppgl_glMultiDrawArraysIndirectAMD;
#define glMultiDrawArraysIndirectAMD cppgl_glMultiDrawArraysIndirectAMD
typedef void (APIENTRYP PFNGLMULTIDRAWELEMENTSINDIRECTAMDPROC)(GLenum mode, GLenum type, const void *indirect, GLsizei primcount, GLsizei stride);
GLAPI PFNGLMULTIDRAWELEMENTSINDIRECTAMDPROC cppgl_glMultiDrawElementsIndirectAMD;
#define glMultiDrawElementsIndirectAMD cppgl_glMultiDrawElementsIndirectAMD
#endif
#ifndef GL_AMD_name_gen_delete
#define GL_AMD_name_gen_delete 1
GLAPI int CPPGL_GL_AMD_name_gen_delete;
typedef void (APIENTRYP PFNGLGENNAMESAMDPROC)(GLenum identifier, GLuint num, GLuint *names);
GLAPI PFNGLGENNAMESAMDPROC cppgl_glGenNamesAMD;
#define glGenNamesAMD cppgl_glGenNamesAMD
typedef void (APIENTRYP PFNGLDELETENAMESAMDPROC)(GLenum identifier, GLuint num, const GLuint *names);
GLAPI PFNGLDELETENAMESAMDPROC cppgl_glDeleteNamesAMD;
#define glDeleteNamesAMD cppgl_glDeleteNamesAMD
typedef GLboolean (APIENTRYP PFNGLISNAMEAMDPROC)(GLenum identifier, GLuint name);
GLAPI PFNGLISNAMEAMDPROC cppgl_glIsNameAMD;
#define glIsNameAMD cppgl_glIsNameAMD
#endif
#ifndef GL_AMD_occlusion_query_event
#define GL_AMD_occlusion_query_event 1
GLAPI int CPPGL_GL_AMD_occlusion_query_event;
typedef void (APIENTRYP PFNGLQUERYOBJECTPARAMETERUIAMDPROC)(GLenum target, GLuint id, GLenum pname, GLuint param);
GLAPI PFNGLQUERYOBJECTPARAMETERUIAMDPROC cppgl_glQueryObjectParameteruiAMD;
#define glQueryObjectParameteruiAMD cppgl_glQueryObjectParameteruiAMD
#endif
#ifndef GL_AMD_performance_monitor
#define GL_AMD_performance_monitor 1
GLAPI int CPPGL_GL_AMD_performance_monitor;
typedef void (APIENTRYP PFNGLGETPERFMONITORGROUPSAMDPROC)(GLint *numGroups, GLsizei groupsSize, GLuint *groups);
GLAPI PFNGLGETPERFMONITORGROUPSAMDPROC cppgl_glGetPerfMonitorGroupsAMD;
#define glGetPerfMonitorGroupsAMD cppgl_glGetPerfMonitorGroupsAMD
typedef void (APIENTRYP PFNGLGETPERFMONITORCOUNTERSAMDPROC)(GLuint group, GLint *numCounters, GLint *maxActiveCounters, GLsizei counterSize, GLuint *counters);
GLAPI PFNGLGETPERFMONITORCOUNTERSAMDPROC cppgl_glGetPerfMonitorCountersAMD;
#define glGetPerfMonitorCountersAMD cppgl_glGetPerfMonitorCountersAMD
typedef void (APIENTRYP PFNGLGETPERFMONITORGROUPSTRINGAMDPROC)(GLuint group, GLsizei bufSize, GLsizei *length, GLchar *groupString);
GLAPI PFNGLGETPERFMONITORGROUPSTRINGAMDPROC cppgl_glGetPerfMonitorGroupStringAMD;
#define glGetPerfMonitorGroupStringAMD cppgl_glGetPerfMonitorGroupStringAMD
typedef void (APIENTRYP PFNGLGETPERFMONITORCOUNTERSTRINGAMDPROC)(GLuint group, GLuint counter, GLsizei bufSize, GLsizei *length, GLchar *counterString);
GLAPI PFNGLGETPERFMONITORCOUNTERSTRINGAMDPROC cppgl_glGetPerfMonitorCounterStringAMD;
#define glGetPerfMonitorCounterStringAMD cppgl_glGetPerfMonitorCounterStringAMD
typedef void (APIENTRYP PFNGLGETPERFMONITORCOUNTERINFOAMDPROC)(GLuint group, GLuint counter, GLenum pname, void *data);
GLAPI PFNGLGETPERFMONITORCOUNTERINFOAMDPROC cppgl_glGetPerfMonitorCounterInfoAMD;
#define glGetPerfMonitorCounterInfoAMD cppgl_glGetPerfMonitorCounterInfoAMD
typedef void (APIENTRYP PFNGLGENPERFMONITORSAMDPROC)(GLsizei n, GLuint *monitors);
GLAPI PFNGLGENPERFMONITORSAMDPROC cppgl_glGenPerfMonitorsAMD;
#define glGenPerfMonitorsAMD cppgl_glGenPerfMonitorsAMD
typedef void (APIENTRYP PFNGLDELETEPERFMONITORSAMDPROC)(GLsizei n, GLuint *monitors);
GLAPI PFNGLDELETEPERFMONITORSAMDPROC cppgl_glDeletePerfMonitorsAMD;
#define glDeletePerfMonitorsAMD cppgl_glDeletePerfMonitorsAMD
typedef void (APIENTRYP PFNGLSELECTPERFMONITORCOUNTERSAMDPROC)(GLuint monitor, GLboolean enable, GLuint group, GLint numCounters, GLuint *counterList);
GLAPI PFNGLSELECTPERFMONITORCOUNTERSAMDPROC cppgl_glSelectPerfMonitorCountersAMD;
#define glSelectPerfMonitorCountersAMD cppgl_glSelectPerfMonitorCountersAMD
typedef void (APIENTRYP PFNGLBEGINPERFMONITORAMDPROC)(GLuint monitor);
GLAPI PFNGLBEGINPERFMONITORAMDPROC cppgl_glBeginPerfMonitorAMD;
#define glBeginPerfMonitorAMD cppgl_glBeginPerfMonitorAMD
typedef void (APIENTRYP PFNGLENDPERFMONITORAMDPROC)(GLuint monitor);
GLAPI PFNGLENDPERFMONITORAMDPROC cppgl_glEndPerfMonitorAMD;
#define glEndPerfMonitorAMD cppgl_glEndPerfMonitorAMD
typedef void (APIENTRYP PFNGLGETPERFMONITORCOUNTERDATAAMDPROC)(GLuint monitor, GLenum pname, GLsizei dataSize, GLuint *data, GLint *bytesWritten);
GLAPI PFNGLGETPERFMONITORCOUNTERDATAAMDPROC cppgl_glGetPerfMonitorCounterDataAMD;
#define glGetPerfMonitorCounterDataAMD cppgl_glGetPerfMonitorCounterDataAMD
#endif
#ifndef GL_AMD_pinned_memory
#define GL_AMD_pinned_memory 1
GLAPI int CPPGL_GL_AMD_pinned_memory;
#endif
#ifndef GL_AMD_query_buffer_object
#define GL_AMD_query_buffer_object 1
GLAPI int CPPGL_GL_AMD_query_buffer_object;
#endif
#ifndef GL_AMD_sample_positions
#define GL_AMD_sample_positions 1
GLAPI int CPPGL_GL_AMD_sample_positions;
typedef void (APIENTRYP PFNGLSETMULTISAMPLEFVAMDPROC)(GLenum pname, GLuint index, const GLfloat *val);
GLAPI PFNGLSETMULTISAMPLEFVAMDPROC cppgl_glSetMultisamplefvAMD;
#define glSetMultisamplefvAMD cppgl_glSetMultisamplefvAMD
#endif
#ifndef GL_AMD_seamless_cubemap_per_texture
#define GL_AMD_seamless_cubemap_per_texture 1
GLAPI int CPPGL_GL_AMD_seamless_cubemap_per_texture;
#endif
#ifndef GL_AMD_shader_atomic_counter_ops
#define GL_AMD_shader_atomic_counter_ops 1
GLAPI int CPPGL_GL_AMD_shader_atomic_counter_ops;
#endif
#ifndef GL_AMD_shader_ballot
#define GL_AMD_shader_ballot 1
GLAPI int CPPGL_GL_AMD_shader_ballot;
#endif
#ifndef GL_AMD_shader_explicit_vertex_parameter
#define GL_AMD_shader_explicit_vertex_parameter 1
GLAPI int CPPGL_GL_AMD_shader_explicit_vertex_parameter;
#endif
#ifndef GL_AMD_shader_stencil_export
#define GL_AMD_shader_stencil_export 1
GLAPI int CPPGL_GL_AMD_shader_stencil_export;
#endif
#ifndef GL_AMD_shader_trinary_minmax
#define GL_AMD_shader_trinary_minmax 1
GLAPI int CPPGL_GL_AMD_shader_trinary_minmax;
#endif
#ifndef GL_AMD_sparse_texture
#define GL_AMD_sparse_texture 1
GLAPI int CPPGL_GL_AMD_sparse_texture;
typedef void (APIENTRYP PFNGLTEXSTORAGESPARSEAMDPROC)(GLenum target, GLenum internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLsizei layers, GLbitfield flags);
GLAPI PFNGLTEXSTORAGESPARSEAMDPROC cppgl_glTexStorageSparseAMD;
#define glTexStorageSparseAMD cppgl_glTexStorageSparseAMD
typedef void (APIENTRYP PFNGLTEXTURESTORAGESPARSEAMDPROC)(GLuint texture, GLenum target, GLenum internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLsizei layers, GLbitfield flags);
GLAPI PFNGLTEXTURESTORAGESPARSEAMDPROC cppgl_glTextureStorageSparseAMD;
#define glTextureStorageSparseAMD cppgl_glTextureStorageSparseAMD
#endif
#ifndef GL_AMD_stencil_operation_extended
#define GL_AMD_stencil_operation_extended 1
GLAPI int CPPGL_GL_AMD_stencil_operation_extended;
typedef void (APIENTRYP PFNGLSTENCILOPVALUEAMDPROC)(GLenum face, GLuint value);
GLAPI PFNGLSTENCILOPVALUEAMDPROC cppgl_glStencilOpValueAMD;
#define glStencilOpValueAMD cppgl_glStencilOpValueAMD
#endif
#ifndef GL_AMD_texture_texture4
#define GL_AMD_texture_texture4 1
GLAPI int CPPGL_GL_AMD_texture_texture4;
#endif
#ifndef GL_AMD_transform_feedback3_lines_triangles
#define GL_AMD_transform_feedback3_lines_triangles 1
GLAPI int CPPGL_GL_AMD_transform_feedback3_lines_triangles;
#endif
#ifndef GL_AMD_transform_feedback4
#define GL_AMD_transform_feedback4 1
GLAPI int CPPGL_GL_AMD_transform_feedback4;
#endif
#ifndef GL_AMD_vertex_shader_layer
#define GL_AMD_vertex_shader_layer 1
GLAPI int CPPGL_GL_AMD_vertex_shader_layer;
#endif
#ifndef GL_AMD_vertex_shader_tessellator
#define GL_AMD_vertex_shader_tessellator 1
GLAPI int CPPGL_GL_AMD_vertex_shader_tessellator;
typedef void (APIENTRYP PFNGLTESSELLATIONFACTORAMDPROC)(GLfloat factor);
GLAPI PFNGLTESSELLATIONFACTORAMDPROC cppgl_glTessellationFactorAMD;
#define glTessellationFactorAMD cppgl_glTessellationFactorAMD
typedef void (APIENTRYP PFNGLTESSELLATIONMODEAMDPROC)(GLenum mode);
GLAPI PFNGLTESSELLATIONMODEAMDPROC cppgl_glTessellationModeAMD;
#define glTessellationModeAMD cppgl_glTessellationModeAMD
#endif
#ifndef GL_AMD_vertex_shader_viewport_index
#define GL_AMD_vertex_shader_viewport_index 1
GLAPI int CPPGL_GL_AMD_vertex_shader_viewport_index;
#endif
#ifndef GL_APPLE_aux_depth_stencil
#define GL_APPLE_aux_depth_stencil 1
GLAPI int CPPGL_GL_APPLE_aux_depth_stencil;
#endif
#ifndef GL_APPLE_client_storage
#define GL_APPLE_client_storage 1
GLAPI int CPPGL_GL_APPLE_client_storage;
#endif
#ifndef GL_APPLE_element_array
#define GL_APPLE_element_array 1
GLAPI int CPPGL_GL_APPLE_element_array;
typedef void (APIENTRYP PFNGLELEMENTPOINTERAPPLEPROC)(GLenum type, const void *pointer);
GLAPI PFNGLELEMENTPOINTERAPPLEPROC cppgl_glElementPointerAPPLE;
#define glElementPointerAPPLE cppgl_glElementPointerAPPLE
typedef void (APIENTRYP PFNGLDRAWELEMENTARRAYAPPLEPROC)(GLenum mode, GLint first, GLsizei count);
GLAPI PFNGLDRAWELEMENTARRAYAPPLEPROC cppgl_glDrawElementArrayAPPLE;
#define glDrawElementArrayAPPLE cppgl_glDrawElementArrayAPPLE
typedef void (APIENTRYP PFNGLDRAWRANGEELEMENTARRAYAPPLEPROC)(GLenum mode, GLuint start, GLuint end, GLint first, GLsizei count);
GLAPI PFNGLDRAWRANGEELEMENTARRAYAPPLEPROC cppgl_glDrawRangeElementArrayAPPLE;
#define glDrawRangeElementArrayAPPLE cppgl_glDrawRangeElementArrayAPPLE
typedef void (APIENTRYP PFNGLMULTIDRAWELEMENTARRAYAPPLEPROC)(GLenum mode, const GLint *first, const GLsizei *count, GLsizei primcount);
GLAPI PFNGLMULTIDRAWELEMENTARRAYAPPLEPROC cppgl_glMultiDrawElementArrayAPPLE;
#define glMultiDrawElementArrayAPPLE cppgl_glMultiDrawElementArrayAPPLE
typedef void (APIENTRYP PFNGLMULTIDRAWRANGEELEMENTARRAYAPPLEPROC)(GLenum mode, GLuint start, GLuint end, const GLint *first, const GLsizei *count, GLsizei primcount);
GLAPI PFNGLMULTIDRAWRANGEELEMENTARRAYAPPLEPROC cppgl_glMultiDrawRangeElementArrayAPPLE;
#define glMultiDrawRangeElementArrayAPPLE cppgl_glMultiDrawRangeElementArrayAPPLE
#endif
#ifndef GL_APPLE_fence
#define GL_APPLE_fence 1
GLAPI int CPPGL_GL_APPLE_fence;
typedef void (APIENTRYP PFNGLGENFENCESAPPLEPROC)(GLsizei n, GLuint *fences);
GLAPI PFNGLGENFENCESAPPLEPROC cppgl_glGenFencesAPPLE;
#define glGenFencesAPPLE cppgl_glGenFencesAPPLE
typedef void (APIENTRYP PFNGLDELETEFENCESAPPLEPROC)(GLsizei n, const GLuint *fences);
GLAPI PFNGLDELETEFENCESAPPLEPROC cppgl_glDeleteFencesAPPLE;
#define glDeleteFencesAPPLE cppgl_glDeleteFencesAPPLE
typedef void (APIENTRYP PFNGLSETFENCEAPPLEPROC)(GLuint fence);
GLAPI PFNGLSETFENCEAPPLEPROC cppgl_glSetFenceAPPLE;
#define glSetFenceAPPLE cppgl_glSetFenceAPPLE
typedef GLboolean (APIENTRYP PFNGLISFENCEAPPLEPROC)(GLuint fence);
GLAPI PFNGLISFENCEAPPLEPROC cppgl_glIsFenceAPPLE;
#define glIsFenceAPPLE cppgl_glIsFenceAPPLE
typedef GLboolean (APIENTRYP PFNGLTESTFENCEAPPLEPROC)(GLuint fence);
GLAPI PFNGLTESTFENCEAPPLEPROC cppgl_glTestFenceAPPLE;
#define glTestFenceAPPLE cppgl_glTestFenceAPPLE
typedef void (APIENTRYP PFNGLFINISHFENCEAPPLEPROC)(GLuint fence);
GLAPI PFNGLFINISHFENCEAPPLEPROC cppgl_glFinishFenceAPPLE;
#define glFinishFenceAPPLE cppgl_glFinishFenceAPPLE
typedef GLboolean (APIENTRYP PFNGLTESTOBJECTAPPLEPROC)(GLenum object, GLuint name);
GLAPI PFNGLTESTOBJECTAPPLEPROC cppgl_glTestObjectAPPLE;
#define glTestObjectAPPLE cppgl_glTestObjectAPPLE
typedef void (APIENTRYP PFNGLFINISHOBJECTAPPLEPROC)(GLenum object, GLint name);
GLAPI PFNGLFINISHOBJECTAPPLEPROC cppgl_glFinishObjectAPPLE;
#define glFinishObjectAPPLE cppgl_glFinishObjectAPPLE
#endif
#ifndef GL_APPLE_float_pixels
#define GL_APPLE_float_pixels 1
GLAPI int CPPGL_GL_APPLE_float_pixels;
#endif
#ifndef GL_APPLE_flush_buffer_range
#define GL_APPLE_flush_buffer_range 1
GLAPI int CPPGL_GL_APPLE_flush_buffer_range;
typedef void (APIENTRYP PFNGLBUFFERPARAMETERIAPPLEPROC)(GLenum target, GLenum pname, GLint param);
GLAPI PFNGLBUFFERPARAMETERIAPPLEPROC cppgl_glBufferParameteriAPPLE;
#define glBufferParameteriAPPLE cppgl_glBufferParameteriAPPLE
typedef void (APIENTRYP PFNGLFLUSHMAPPEDBUFFERRANGEAPPLEPROC)(GLenum target, GLintptr offset, GLsizeiptr size);
GLAPI PFNGLFLUSHMAPPEDBUFFERRANGEAPPLEPROC cppgl_glFlushMappedBufferRangeAPPLE;
#define glFlushMappedBufferRangeAPPLE cppgl_glFlushMappedBufferRangeAPPLE
#endif
#ifndef GL_APPLE_object_purgeable
#define GL_APPLE_object_purgeable 1
GLAPI int CPPGL_GL_APPLE_object_purgeable;
typedef GLenum (APIENTRYP PFNGLOBJECTPURGEABLEAPPLEPROC)(GLenum objectType, GLuint name, GLenum option);
GLAPI PFNGLOBJECTPURGEABLEAPPLEPROC cppgl_glObjectPurgeableAPPLE;
#define glObjectPurgeableAPPLE cppgl_glObjectPurgeableAPPLE
typedef GLenum (APIENTRYP PFNGLOBJECTUNPURGEABLEAPPLEPROC)(GLenum objectType, GLuint name, GLenum option);
GLAPI PFNGLOBJECTUNPURGEABLEAPPLEPROC cppgl_glObjectUnpurgeableAPPLE;
#define glObjectUnpurgeableAPPLE cppgl_glObjectUnpurgeableAPPLE
typedef void (APIENTRYP PFNGLGETOBJECTPARAMETERIVAPPLEPROC)(GLenum objectType, GLuint name, GLenum pname, GLint *params);
GLAPI PFNGLGETOBJECTPARAMETERIVAPPLEPROC cppgl_glGetObjectParameterivAPPLE;
#define glGetObjectParameterivAPPLE cppgl_glGetObjectParameterivAPPLE
#endif
#ifndef GL_APPLE_rgb_422
#define GL_APPLE_rgb_422 1
GLAPI int CPPGL_GL_APPLE_rgb_422;
#endif
#ifndef GL_APPLE_row_bytes
#define GL_APPLE_row_bytes 1
GLAPI int CPPGL_GL_APPLE_row_bytes;
#endif
#ifndef GL_APPLE_specular_vector
#define GL_APPLE_specular_vector 1
GLAPI int CPPGL_GL_APPLE_specular_vector;
#endif
#ifndef GL_APPLE_texture_range
#define GL_APPLE_texture_range 1
GLAPI int CPPGL_GL_APPLE_texture_range;
typedef void (APIENTRYP PFNGLTEXTURERANGEAPPLEPROC)(GLenum target, GLsizei length, const void *pointer);
GLAPI PFNGLTEXTURERANGEAPPLEPROC cppgl_glTextureRangeAPPLE;
#define glTextureRangeAPPLE cppgl_glTextureRangeAPPLE
typedef void (APIENTRYP PFNGLGETTEXPARAMETERPOINTERVAPPLEPROC)(GLenum target, GLenum pname, void **params);
GLAPI PFNGLGETTEXPARAMETERPOINTERVAPPLEPROC cppgl_glGetTexParameterPointervAPPLE;
#define glGetTexParameterPointervAPPLE cppgl_glGetTexParameterPointervAPPLE
#endif
#ifndef GL_APPLE_transform_hint
#define GL_APPLE_transform_hint 1
GLAPI int CPPGL_GL_APPLE_transform_hint;
#endif
#ifndef GL_APPLE_vertex_array_object
#define GL_APPLE_vertex_array_object 1
GLAPI int CPPGL_GL_APPLE_vertex_array_object;
typedef void (APIENTRYP PFNGLBINDVERTEXARRAYAPPLEPROC)(GLuint array);
GLAPI PFNGLBINDVERTEXARRAYAPPLEPROC cppgl_glBindVertexArrayAPPLE;
#define glBindVertexArrayAPPLE cppgl_glBindVertexArrayAPPLE
typedef void (APIENTRYP PFNGLDELETEVERTEXARRAYSAPPLEPROC)(GLsizei n, const GLuint *arrays);
GLAPI PFNGLDELETEVERTEXARRAYSAPPLEPROC cppgl_glDeleteVertexArraysAPPLE;
#define glDeleteVertexArraysAPPLE cppgl_glDeleteVertexArraysAPPLE
typedef void (APIENTRYP PFNGLGENVERTEXARRAYSAPPLEPROC)(GLsizei n, GLuint *arrays);
GLAPI PFNGLGENVERTEXARRAYSAPPLEPROC cppgl_glGenVertexArraysAPPLE;
#define glGenVertexArraysAPPLE cppgl_glGenVertexArraysAPPLE
typedef GLboolean (APIENTRYP PFNGLISVERTEXARRAYAPPLEPROC)(GLuint array);
GLAPI PFNGLISVERTEXARRAYAPPLEPROC cppgl_glIsVertexArrayAPPLE;
#define glIsVertexArrayAPPLE cppgl_glIsVertexArrayAPPLE
#endif
#ifndef GL_APPLE_vertex_array_range
#define GL_APPLE_vertex_array_range 1
GLAPI int CPPGL_GL_APPLE_vertex_array_range;
typedef void (APIENTRYP PFNGLVERTEXARRAYRANGEAPPLEPROC)(GLsizei length, void *pointer);
GLAPI PFNGLVERTEXARRAYRANGEAPPLEPROC cppgl_glVertexArrayRangeAPPLE;
#define glVertexArrayRangeAPPLE cppgl_glVertexArrayRangeAPPLE
typedef void (APIENTRYP PFNGLFLUSHVERTEXARRAYRANGEAPPLEPROC)(GLsizei length, void *pointer);
GLAPI PFNGLFLUSHVERTEXARRAYRANGEAPPLEPROC cppgl_glFlushVertexArrayRangeAPPLE;
#define glFlushVertexArrayRangeAPPLE cppgl_glFlushVertexArrayRangeAPPLE
typedef void (APIENTRYP PFNGLVERTEXARRAYPARAMETERIAPPLEPROC)(GLenum pname, GLint param);
GLAPI PFNGLVERTEXARRAYPARAMETERIAPPLEPROC cppgl_glVertexArrayParameteriAPPLE;
#define glVertexArrayParameteriAPPLE cppgl_glVertexArrayParameteriAPPLE
#endif
#ifndef GL_APPLE_vertex_program_evaluators
#define GL_APPLE_vertex_program_evaluators 1
GLAPI int CPPGL_GL_APPLE_vertex_program_evaluators;
typedef void (APIENTRYP PFNGLENABLEVERTEXATTRIBAPPLEPROC)(GLuint index, GLenum pname);
GLAPI PFNGLENABLEVERTEXATTRIBAPPLEPROC cppgl_glEnableVertexAttribAPPLE;
#define glEnableVertexAttribAPPLE cppgl_glEnableVertexAttribAPPLE
typedef void (APIENTRYP PFNGLDISABLEVERTEXATTRIBAPPLEPROC)(GLuint index, GLenum pname);
GLAPI PFNGLDISABLEVERTEXATTRIBAPPLEPROC cppgl_glDisableVertexAttribAPPLE;
#define glDisableVertexAttribAPPLE cppgl_glDisableVertexAttribAPPLE
typedef GLboolean (APIENTRYP PFNGLISVERTEXATTRIBENABLEDAPPLEPROC)(GLuint index, GLenum pname);
GLAPI PFNGLISVERTEXATTRIBENABLEDAPPLEPROC cppgl_glIsVertexAttribEnabledAPPLE;
#define glIsVertexAttribEnabledAPPLE cppgl_glIsVertexAttribEnabledAPPLE
typedef void (APIENTRYP PFNGLMAPVERTEXATTRIB1DAPPLEPROC)(GLuint index, GLuint size, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble *points);
GLAPI PFNGLMAPVERTEXATTRIB1DAPPLEPROC cppgl_glMapVertexAttrib1dAPPLE;
#define glMapVertexAttrib1dAPPLE cppgl_glMapVertexAttrib1dAPPLE
typedef void (APIENTRYP PFNGLMAPVERTEXATTRIB1FAPPLEPROC)(GLuint index, GLuint size, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat *points);
GLAPI PFNGLMAPVERTEXATTRIB1FAPPLEPROC cppgl_glMapVertexAttrib1fAPPLE;
#define glMapVertexAttrib1fAPPLE cppgl_glMapVertexAttrib1fAPPLE
typedef void (APIENTRYP PFNGLMAPVERTEXATTRIB2DAPPLEPROC)(GLuint index, GLuint size, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble *points);
GLAPI PFNGLMAPVERTEXATTRIB2DAPPLEPROC cppgl_glMapVertexAttrib2dAPPLE;
#define glMapVertexAttrib2dAPPLE cppgl_glMapVertexAttrib2dAPPLE
typedef void (APIENTRYP PFNGLMAPVERTEXATTRIB2FAPPLEPROC)(GLuint index, GLuint size, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const GLfloat *points);
GLAPI PFNGLMAPVERTEXATTRIB2FAPPLEPROC cppgl_glMapVertexAttrib2fAPPLE;
#define glMapVertexAttrib2fAPPLE cppgl_glMapVertexAttrib2fAPPLE
#endif
#ifndef GL_APPLE_ycbcr_422
#define GL_APPLE_ycbcr_422 1
GLAPI int CPPGL_GL_APPLE_ycbcr_422;
#endif
#ifndef GL_ARB_ES2_compatibility
#define GL_ARB_ES2_compatibility 1
GLAPI int CPPGL_GL_ARB_ES2_compatibility;
typedef void (APIENTRYP PFNGLRELEASESHADERCOMPILERPROC)();
GLAPI PFNGLRELEASESHADERCOMPILERPROC cppgl_glReleaseShaderCompiler;
#define glReleaseShaderCompiler cppgl_glReleaseShaderCompiler
typedef void (APIENTRYP PFNGLSHADERBINARYPROC)(GLsizei count, const GLuint *shaders, GLenum binaryformat, const void *binary, GLsizei length);
GLAPI PFNGLSHADERBINARYPROC cppgl_glShaderBinary;
#define glShaderBinary cppgl_glShaderBinary
typedef void (APIENTRYP PFNGLGETSHADERPRECISIONFORMATPROC)(GLenum shadertype, GLenum precisiontype, GLint *range, GLint *precision);
GLAPI PFNGLGETSHADERPRECISIONFORMATPROC cppgl_glGetShaderPrecisionFormat;
#define glGetShaderPrecisionFormat cppgl_glGetShaderPrecisionFormat
typedef void (APIENTRYP PFNGLDEPTHRANGEFPROC)(GLfloat n, GLfloat f);
GLAPI PFNGLDEPTHRANGEFPROC cppgl_glDepthRangef;
#define glDepthRangef cppgl_glDepthRangef
typedef void (APIENTRYP PFNGLCLEARDEPTHFPROC)(GLfloat d);
GLAPI PFNGLCLEARDEPTHFPROC cppgl_glClearDepthf;
#define glClearDepthf cppgl_glClearDepthf
#endif
#ifndef GL_ARB_ES3_1_compatibility
#define GL_ARB_ES3_1_compatibility 1
GLAPI int CPPGL_GL_ARB_ES3_1_compatibility;
typedef void (APIENTRYP PFNGLMEMORYBARRIERBYREGIONPROC)(GLbitfield barriers);
GLAPI PFNGLMEMORYBARRIERBYREGIONPROC cppgl_glMemoryBarrierByRegion;
#define glMemoryBarrierByRegion cppgl_glMemoryBarrierByRegion
#endif
#ifndef GL_ARB_ES3_2_compatibility
#define GL_ARB_ES3_2_compatibility 1
GLAPI int CPPGL_GL_ARB_ES3_2_compatibility;
typedef void (APIENTRYP PFNGLPRIMITIVEBOUNDINGBOXARBPROC)(GLfloat minX, GLfloat minY, GLfloat minZ, GLfloat minW, GLfloat maxX, GLfloat maxY, GLfloat maxZ, GLfloat maxW);
GLAPI PFNGLPRIMITIVEBOUNDINGBOXARBPROC cppgl_glPrimitiveBoundingBoxARB;
#define glPrimitiveBoundingBoxARB cppgl_glPrimitiveBoundingBoxARB
#endif
#ifndef GL_ARB_ES3_compatibility
#define GL_ARB_ES3_compatibility 1
GLAPI int CPPGL_GL_ARB_ES3_compatibility;
#endif
#ifndef GL_ARB_arrays_of_arrays
#define GL_ARB_arrays_of_arrays 1
GLAPI int CPPGL_GL_ARB_arrays_of_arrays;
#endif
#ifndef GL_ARB_base_instance
#define GL_ARB_base_instance 1
GLAPI int CPPGL_GL_ARB_base_instance;
typedef void (APIENTRYP PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC)(GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance);
GLAPI PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC cppgl_glDrawArraysInstancedBaseInstance;
#define glDrawArraysInstancedBaseInstance cppgl_glDrawArraysInstancedBaseInstance
typedef void (APIENTRYP PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC)(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLuint baseinstance);
GLAPI PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC cppgl_glDrawElementsInstancedBaseInstance;
#define glDrawElementsInstancedBaseInstance cppgl_glDrawElementsInstancedBaseInstance
typedef void (APIENTRYP PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC)(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance);
GLAPI PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC cppgl_glDrawElementsInstancedBaseVertexBaseInstance;
#define glDrawElementsInstancedBaseVertexBaseInstance cppgl_glDrawElementsInstancedBaseVertexBaseInstance
#endif
#ifndef GL_ARB_bindless_texture
#define GL_ARB_bindless_texture 1
GLAPI int CPPGL_GL_ARB_bindless_texture;
typedef GLuint64 (APIENTRYP PFNGLGETTEXTUREHANDLEARBPROC)(GLuint texture);
GLAPI PFNGLGETTEXTUREHANDLEARBPROC cppgl_glGetTextureHandleARB;
#define glGetTextureHandleARB cppgl_glGetTextureHandleARB
typedef GLuint64 (APIENTRYP PFNGLGETTEXTURESAMPLERHANDLEARBPROC)(GLuint texture, GLuint sampler);
GLAPI PFNGLGETTEXTURESAMPLERHANDLEARBPROC cppgl_glGetTextureSamplerHandleARB;
#define glGetTextureSamplerHandleARB cppgl_glGetTextureSamplerHandleARB
typedef void (APIENTRYP PFNGLMAKETEXTUREHANDLERESIDENTARBPROC)(GLuint64 handle);
GLAPI PFNGLMAKETEXTUREHANDLERESIDENTARBPROC cppgl_glMakeTextureHandleResidentARB;
#define glMakeTextureHandleResidentARB cppgl_glMakeTextureHandleResidentARB
typedef void (APIENTRYP PFNGLMAKETEXTUREHANDLENONRESIDENTARBPROC)(GLuint64 handle);
GLAPI PFNGLMAKETEXTUREHANDLENONRESIDENTARBPROC cppgl_glMakeTextureHandleNonResidentARB;
#define glMakeTextureHandleNonResidentARB cppgl_glMakeTextureHandleNonResidentARB
typedef GLuint64 (APIENTRYP PFNGLGETIMAGEHANDLEARBPROC)(GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum format);
GLAPI PFNGLGETIMAGEHANDLEARBPROC cppgl_glGetImageHandleARB;
#define glGetImageHandleARB cppgl_glGetImageHandleARB
typedef void (APIENTRYP PFNGLMAKEIMAGEHANDLERESIDENTARBPROC)(GLuint64 handle, GLenum access);
GLAPI PFNGLMAKEIMAGEHANDLERESIDENTARBPROC cppgl_glMakeImageHandleResidentARB;
#define glMakeImageHandleResidentARB cppgl_glMakeImageHandleResidentARB
typedef void (APIENTRYP PFNGLMAKEIMAGEHANDLENONRESIDENTARBPROC)(GLuint64 handle);
GLAPI PFNGLMAKEIMAGEHANDLENONRESIDENTARBPROC cppgl_glMakeImageHandleNonResidentARB;
#define glMakeImageHandleNonResidentARB cppgl_glMakeImageHandleNonResidentARB
typedef void (APIENTRYP PFNGLUNIFORMHANDLEUI64ARBPROC)(GLint location, GLuint64 value);
GLAPI PFNGLUNIFORMHANDLEUI64ARBPROC cppgl_glUniformHandleui64ARB;
#define glUniformHandleui64ARB cppgl_glUniformHandleui64ARB
typedef void (APIENTRYP PFNGLUNIFORMHANDLEUI64VARBPROC)(GLint location, GLsizei count, const GLuint64 *value);
GLAPI PFNGLUNIFORMHANDLEUI64VARBPROC cppgl_glUniformHandleui64vARB;
#define glUniformHandleui64vARB cppgl_glUniformHandleui64vARB
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMHANDLEUI64ARBPROC)(GLuint program, GLint location, GLuint64 value);
GLAPI PFNGLPROGRAMUNIFORMHANDLEUI64ARBPROC cppgl_glProgramUniformHandleui64ARB;
#define glProgramUniformHandleui64ARB cppgl_glProgramUniformHandleui64ARB
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMHANDLEUI64VARBPROC)(GLuint program, GLint location, GLsizei count, const GLuint64 *values);
GLAPI PFNGLPROGRAMUNIFORMHANDLEUI64VARBPROC cppgl_glProgramUniformHandleui64vARB;
#define glProgramUniformHandleui64vARB cppgl_glProgramUniformHandleui64vARB
typedef GLboolean (APIENTRYP PFNGLISTEXTUREHANDLERESIDENTARBPROC)(GLuint64 handle);
GLAPI PFNGLISTEXTUREHANDLERESIDENTARBPROC cppgl_glIsTextureHandleResidentARB;
#define glIsTextureHandleResidentARB cppgl_glIsTextureHandleResidentARB
typedef GLboolean (APIENTRYP PFNGLISIMAGEHANDLERESIDENTARBPROC)(GLuint64 handle);
GLAPI PFNGLISIMAGEHANDLERESIDENTARBPROC cppgl_glIsImageHandleResidentARB;
#define glIsImageHandleResidentARB cppgl_glIsImageHandleResidentARB
typedef void (APIENTRYP PFNGLVERTEXATTRIBL1UI64ARBPROC)(GLuint index, GLuint64EXT x);
GLAPI PFNGLVERTEXATTRIBL1UI64ARBPROC cppgl_glVertexAttribL1ui64ARB;
#define glVertexAttribL1ui64ARB cppgl_glVertexAttribL1ui64ARB
typedef void (APIENTRYP PFNGLVERTEXATTRIBL1UI64VARBPROC)(GLuint index, const GLuint64EXT *v);
GLAPI PFNGLVERTEXATTRIBL1UI64VARBPROC cppgl_glVertexAttribL1ui64vARB;
#define glVertexAttribL1ui64vARB cppgl_glVertexAttribL1ui64vARB
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBLUI64VARBPROC)(GLuint index, GLenum pname, GLuint64EXT *params);
GLAPI PFNGLGETVERTEXATTRIBLUI64VARBPROC cppgl_glGetVertexAttribLui64vARB;
#define glGetVertexAttribLui64vARB cppgl_glGetVertexAttribLui64vARB
#endif
#ifndef GL_ARB_blend_func_extended
#define GL_ARB_blend_func_extended 1
GLAPI int CPPGL_GL_ARB_blend_func_extended;
typedef void (APIENTRYP PFNGLBINDFRAGDATALOCATIONINDEXEDPROC)(GLuint program, GLuint colorNumber, GLuint index, const GLchar *name);
GLAPI PFNGLBINDFRAGDATALOCATIONINDEXEDPROC cppgl_glBindFragDataLocationIndexed;
#define glBindFragDataLocationIndexed cppgl_glBindFragDataLocationIndexed
typedef GLint (APIENTRYP PFNGLGETFRAGDATAINDEXPROC)(GLuint program, const GLchar *name);
GLAPI PFNGLGETFRAGDATAINDEXPROC cppgl_glGetFragDataIndex;
#define glGetFragDataIndex cppgl_glGetFragDataIndex
#endif
#ifndef GL_ARB_buffer_storage
#define GL_ARB_buffer_storage 1
GLAPI int CPPGL_GL_ARB_buffer_storage;
typedef void (APIENTRYP PFNGLBUFFERSTORAGEPROC)(GLenum target, GLsizeiptr size, const void *data, GLbitfield flags);
GLAPI PFNGLBUFFERSTORAGEPROC cppgl_glBufferStorage;
#define glBufferStorage cppgl_glBufferStorage
#endif
#ifndef GL_ARB_cl_event
#define GL_ARB_cl_event 1
GLAPI int CPPGL_GL_ARB_cl_event;
typedef GLsync (APIENTRYP PFNGLCREATESYNCFROMCLEVENTARBPROC)(struct _cl_context *context, struct _cl_event *event, GLbitfield flags);
GLAPI PFNGLCREATESYNCFROMCLEVENTARBPROC cppgl_glCreateSyncFromCLeventARB;
#define glCreateSyncFromCLeventARB cppgl_glCreateSyncFromCLeventARB
#endif
#ifndef GL_ARB_clear_buffer_object
#define GL_ARB_clear_buffer_object 1
GLAPI int CPPGL_GL_ARB_clear_buffer_object;
typedef void (APIENTRYP PFNGLCLEARBUFFERDATAPROC)(GLenum target, GLenum internalformat, GLenum format, GLenum type, const void *data);
GLAPI PFNGLCLEARBUFFERDATAPROC cppgl_glClearBufferData;
#define glClearBufferData cppgl_glClearBufferData
typedef void (APIENTRYP PFNGLCLEARBUFFERSUBDATAPROC)(GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void *data);
GLAPI PFNGLCLEARBUFFERSUBDATAPROC cppgl_glClearBufferSubData;
#define glClearBufferSubData cppgl_glClearBufferSubData
#endif
#ifndef GL_ARB_clear_texture
#define GL_ARB_clear_texture 1
GLAPI int CPPGL_GL_ARB_clear_texture;
typedef void (APIENTRYP PFNGLCLEARTEXIMAGEPROC)(GLuint texture, GLint level, GLenum format, GLenum type, const void *data);
GLAPI PFNGLCLEARTEXIMAGEPROC cppgl_glClearTexImage;
#define glClearTexImage cppgl_glClearTexImage
typedef void (APIENTRYP PFNGLCLEARTEXSUBIMAGEPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *data);
GLAPI PFNGLCLEARTEXSUBIMAGEPROC cppgl_glClearTexSubImage;
#define glClearTexSubImage cppgl_glClearTexSubImage
#endif
#ifndef GL_ARB_clip_control
#define GL_ARB_clip_control 1
GLAPI int CPPGL_GL_ARB_clip_control;
typedef void (APIENTRYP PFNGLCLIPCONTROLPROC)(GLenum origin, GLenum depth);
GLAPI PFNGLCLIPCONTROLPROC cppgl_glClipControl;
#define glClipControl cppgl_glClipControl
#endif
#ifndef GL_ARB_color_buffer_float
#define GL_ARB_color_buffer_float 1
GLAPI int CPPGL_GL_ARB_color_buffer_float;
typedef void (APIENTRYP PFNGLCLAMPCOLORARBPROC)(GLenum target, GLenum clamp);
GLAPI PFNGLCLAMPCOLORARBPROC cppgl_glClampColorARB;
#define glClampColorARB cppgl_glClampColorARB
#endif
#ifndef GL_ARB_compatibility
#define GL_ARB_compatibility 1
GLAPI int CPPGL_GL_ARB_compatibility;
#endif
#ifndef GL_ARB_compressed_texture_pixel_storage
#define GL_ARB_compressed_texture_pixel_storage 1
GLAPI int CPPGL_GL_ARB_compressed_texture_pixel_storage;
#endif
#ifndef GL_ARB_compute_shader
#define GL_ARB_compute_shader 1
GLAPI int CPPGL_GL_ARB_compute_shader;
typedef void (APIENTRYP PFNGLDISPATCHCOMPUTEPROC)(GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z);
GLAPI PFNGLDISPATCHCOMPUTEPROC cppgl_glDispatchCompute;
#define glDispatchCompute cppgl_glDispatchCompute
typedef void (APIENTRYP PFNGLDISPATCHCOMPUTEINDIRECTPROC)(GLintptr indirect);
GLAPI PFNGLDISPATCHCOMPUTEINDIRECTPROC cppgl_glDispatchComputeIndirect;
#define glDispatchComputeIndirect cppgl_glDispatchComputeIndirect
#endif
#ifndef GL_ARB_compute_variable_group_size
#define GL_ARB_compute_variable_group_size 1
GLAPI int CPPGL_GL_ARB_compute_variable_group_size;
typedef void (APIENTRYP PFNGLDISPATCHCOMPUTEGROUPSIZEARBPROC)(GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z, GLuint group_size_x, GLuint group_size_y, GLuint group_size_z);
GLAPI PFNGLDISPATCHCOMPUTEGROUPSIZEARBPROC cppgl_glDispatchComputeGroupSizeARB;
#define glDispatchComputeGroupSizeARB cppgl_glDispatchComputeGroupSizeARB
#endif
#ifndef GL_ARB_conditional_render_inverted
#define GL_ARB_conditional_render_inverted 1
GLAPI int CPPGL_GL_ARB_conditional_render_inverted;
#endif
#ifndef GL_ARB_conservative_depth
#define GL_ARB_conservative_depth 1
GLAPI int CPPGL_GL_ARB_conservative_depth;
#endif
#ifndef GL_ARB_copy_buffer
#define GL_ARB_copy_buffer 1
GLAPI int CPPGL_GL_ARB_copy_buffer;
typedef void (APIENTRYP PFNGLCOPYBUFFERSUBDATAPROC)(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
GLAPI PFNGLCOPYBUFFERSUBDATAPROC cppgl_glCopyBufferSubData;
#define glCopyBufferSubData cppgl_glCopyBufferSubData
#endif
#ifndef GL_ARB_copy_image
#define GL_ARB_copy_image 1
GLAPI int CPPGL_GL_ARB_copy_image;
typedef void (APIENTRYP PFNGLCOPYIMAGESUBDATAPROC)(GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth);
GLAPI PFNGLCOPYIMAGESUBDATAPROC cppgl_glCopyImageSubData;
#define glCopyImageSubData cppgl_glCopyImageSubData
#endif
#ifndef GL_ARB_cull_distance
#define GL_ARB_cull_distance 1
GLAPI int CPPGL_GL_ARB_cull_distance;
#endif
#ifndef GL_ARB_debug_output
#define GL_ARB_debug_output 1
GLAPI int CPPGL_GL_ARB_debug_output;
typedef void (APIENTRYP PFNGLDEBUGMESSAGECONTROLARBPROC)(GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint *ids, GLboolean enabled);
GLAPI PFNGLDEBUGMESSAGECONTROLARBPROC cppgl_glDebugMessageControlARB;
#define glDebugMessageControlARB cppgl_glDebugMessageControlARB
typedef void (APIENTRYP PFNGLDEBUGMESSAGEINSERTARBPROC)(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *buf);
GLAPI PFNGLDEBUGMESSAGEINSERTARBPROC cppgl_glDebugMessageInsertARB;
#define glDebugMessageInsertARB cppgl_glDebugMessageInsertARB
typedef void (APIENTRYP PFNGLDEBUGMESSAGECALLBACKARBPROC)(GLDEBUGPROCARB callback, const void *userParam);
GLAPI PFNGLDEBUGMESSAGECALLBACKARBPROC cppgl_glDebugMessageCallbackARB;
#define glDebugMessageCallbackARB cppgl_glDebugMessageCallbackARB
typedef GLuint (APIENTRYP PFNGLGETDEBUGMESSAGELOGARBPROC)(GLuint count, GLsizei bufSize, GLenum *sources, GLenum *types, GLuint *ids, GLenum *severities, GLsizei *lengths, GLchar *messageLog);
GLAPI PFNGLGETDEBUGMESSAGELOGARBPROC cppgl_glGetDebugMessageLogARB;
#define glGetDebugMessageLogARB cppgl_glGetDebugMessageLogARB
#endif
#ifndef GL_ARB_depth_buffer_float
#define GL_ARB_depth_buffer_float 1
GLAPI int CPPGL_GL_ARB_depth_buffer_float;
#endif
#ifndef GL_ARB_depth_clamp
#define GL_ARB_depth_clamp 1
GLAPI int CPPGL_GL_ARB_depth_clamp;
#endif
#ifndef GL_ARB_depth_texture
#define GL_ARB_depth_texture 1
GLAPI int CPPGL_GL_ARB_depth_texture;
#endif
#ifndef GL_ARB_derivative_control
#define GL_ARB_derivative_control 1
GLAPI int CPPGL_GL_ARB_derivative_control;
#endif
#ifndef GL_ARB_direct_state_access
#define GL_ARB_direct_state_access 1
GLAPI int CPPGL_GL_ARB_direct_state_access;
typedef void (APIENTRYP PFNGLCREATETRANSFORMFEEDBACKSPROC)(GLsizei n, GLuint *ids);
GLAPI PFNGLCREATETRANSFORMFEEDBACKSPROC cppgl_glCreateTransformFeedbacks;
#define glCreateTransformFeedbacks cppgl_glCreateTransformFeedbacks
typedef void (APIENTRYP PFNGLTRANSFORMFEEDBACKBUFFERBASEPROC)(GLuint xfb, GLuint index, GLuint buffer);
GLAPI PFNGLTRANSFORMFEEDBACKBUFFERBASEPROC cppgl_glTransformFeedbackBufferBase;
#define glTransformFeedbackBufferBase cppgl_glTransformFeedbackBufferBase
typedef void (APIENTRYP PFNGLTRANSFORMFEEDBACKBUFFERRANGEPROC)(GLuint xfb, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
GLAPI PFNGLTRANSFORMFEEDBACKBUFFERRANGEPROC cppgl_glTransformFeedbackBufferRange;
#define glTransformFeedbackBufferRange cppgl_glTransformFeedbackBufferRange
typedef void (APIENTRYP PFNGLGETTRANSFORMFEEDBACKIVPROC)(GLuint xfb, GLenum pname, GLint *param);
GLAPI PFNGLGETTRANSFORMFEEDBACKIVPROC cppgl_glGetTransformFeedbackiv;
#define glGetTransformFeedbackiv cppgl_glGetTransformFeedbackiv
typedef void (APIENTRYP PFNGLGETTRANSFORMFEEDBACKI_VPROC)(GLuint xfb, GLenum pname, GLuint index, GLint *param);
GLAPI PFNGLGETTRANSFORMFEEDBACKI_VPROC cppgl_glGetTransformFeedbacki_v;
#define glGetTransformFeedbacki_v cppgl_glGetTransformFeedbacki_v
typedef void (APIENTRYP PFNGLGETTRANSFORMFEEDBACKI64_VPROC)(GLuint xfb, GLenum pname, GLuint index, GLint64 *param);
GLAPI PFNGLGETTRANSFORMFEEDBACKI64_VPROC cppgl_glGetTransformFeedbacki64_v;
#define glGetTransformFeedbacki64_v cppgl_glGetTransformFeedbacki64_v
typedef void (APIENTRYP PFNGLCREATEBUFFERSPROC)(GLsizei n, GLuint *buffers);
GLAPI PFNGLCREATEBUFFERSPROC cppgl_glCreateBuffers;
#define glCreateBuffers cppgl_glCreateBuffers
typedef void (APIENTRYP PFNGLNAMEDBUFFERSTORAGEPROC)(GLuint buffer, GLsizeiptr size, const void *data, GLbitfield flags);
GLAPI PFNGLNAMEDBUFFERSTORAGEPROC cppgl_glNamedBufferStorage;
#define glNamedBufferStorage cppgl_glNamedBufferStorage
typedef void (APIENTRYP PFNGLNAMEDBUFFERDATAPROC)(GLuint buffer, GLsizeiptr size, const void *data, GLenum usage);
GLAPI PFNGLNAMEDBUFFERDATAPROC cppgl_glNamedBufferData;
#define glNamedBufferData cppgl_glNamedBufferData
typedef void (APIENTRYP PFNGLNAMEDBUFFERSUBDATAPROC)(GLuint buffer, GLintptr offset, GLsizeiptr size, const void *data);
GLAPI PFNGLNAMEDBUFFERSUBDATAPROC cppgl_glNamedBufferSubData;
#define glNamedBufferSubData cppgl_glNamedBufferSubData
typedef void (APIENTRYP PFNGLCOPYNAMEDBUFFERSUBDATAPROC)(GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
GLAPI PFNGLCOPYNAMEDBUFFERSUBDATAPROC cppgl_glCopyNamedBufferSubData;
#define glCopyNamedBufferSubData cppgl_glCopyNamedBufferSubData
typedef void (APIENTRYP PFNGLCLEARNAMEDBUFFERDATAPROC)(GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const void *data);
GLAPI PFNGLCLEARNAMEDBUFFERDATAPROC cppgl_glClearNamedBufferData;
#define glClearNamedBufferData cppgl_glClearNamedBufferData
typedef void (APIENTRYP PFNGLCLEARNAMEDBUFFERSUBDATAPROC)(GLuint buffer, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void *data);
GLAPI PFNGLCLEARNAMEDBUFFERSUBDATAPROC cppgl_glClearNamedBufferSubData;
#define glClearNamedBufferSubData cppgl_glClearNamedBufferSubData
typedef void * (APIENTRYP PFNGLMAPNAMEDBUFFERPROC)(GLuint buffer, GLenum access);
GLAPI PFNGLMAPNAMEDBUFFERPROC cppgl_glMapNamedBuffer;
#define glMapNamedBuffer cppgl_glMapNamedBuffer
typedef void * (APIENTRYP PFNGLMAPNAMEDBUFFERRANGEPROC)(GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access);
GLAPI PFNGLMAPNAMEDBUFFERRANGEPROC cppgl_glMapNamedBufferRange;
#define glMapNamedBufferRange cppgl_glMapNamedBufferRange
typedef GLboolean (APIENTRYP PFNGLUNMAPNAMEDBUFFERPROC)(GLuint buffer);
GLAPI PFNGLUNMAPNAMEDBUFFERPROC cppgl_glUnmapNamedBuffer;
#define glUnmapNamedBuffer cppgl_glUnmapNamedBuffer
typedef void (APIENTRYP PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEPROC)(GLuint buffer, GLintptr offset, GLsizeiptr length);
GLAPI PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEPROC cppgl_glFlushMappedNamedBufferRange;
#define glFlushMappedNamedBufferRange cppgl_glFlushMappedNamedBufferRange
typedef void (APIENTRYP PFNGLGETNAMEDBUFFERPARAMETERIVPROC)(GLuint buffer, GLenum pname, GLint *params);
GLAPI PFNGLGETNAMEDBUFFERPARAMETERIVPROC cppgl_glGetNamedBufferParameteriv;
#define glGetNamedBufferParameteriv cppgl_glGetNamedBufferParameteriv
typedef void (APIENTRYP PFNGLGETNAMEDBUFFERPARAMETERI64VPROC)(GLuint buffer, GLenum pname, GLint64 *params);
GLAPI PFNGLGETNAMEDBUFFERPARAMETERI64VPROC cppgl_glGetNamedBufferParameteri64v;
#define glGetNamedBufferParameteri64v cppgl_glGetNamedBufferParameteri64v
typedef void (APIENTRYP PFNGLGETNAMEDBUFFERPOINTERVPROC)(GLuint buffer, GLenum pname, void **params);
GLAPI PFNGLGETNAMEDBUFFERPOINTERVPROC cppgl_glGetNamedBufferPointerv;
#define glGetNamedBufferPointerv cppgl_glGetNamedBufferPointerv
typedef void (APIENTRYP PFNGLGETNAMEDBUFFERSUBDATAPROC)(GLuint buffer, GLintptr offset, GLsizeiptr size, void *data);
GLAPI PFNGLGETNAMEDBUFFERSUBDATAPROC cppgl_glGetNamedBufferSubData;
#define glGetNamedBufferSubData cppgl_glGetNamedBufferSubData
typedef void (APIENTRYP PFNGLCREATEFRAMEBUFFERSPROC)(GLsizei n, GLuint *framebuffers);
GLAPI PFNGLCREATEFRAMEBUFFERSPROC cppgl_glCreateFramebuffers;
#define glCreateFramebuffers cppgl_glCreateFramebuffers
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERRENDERBUFFERPROC)(GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
GLAPI PFNGLNAMEDFRAMEBUFFERRENDERBUFFERPROC cppgl_glNamedFramebufferRenderbuffer;
#define glNamedFramebufferRenderbuffer cppgl_glNamedFramebufferRenderbuffer
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERPARAMETERIPROC)(GLuint framebuffer, GLenum pname, GLint param);
GLAPI PFNGLNAMEDFRAMEBUFFERPARAMETERIPROC cppgl_glNamedFramebufferParameteri;
#define glNamedFramebufferParameteri cppgl_glNamedFramebufferParameteri
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERTEXTUREPROC)(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level);
GLAPI PFNGLNAMEDFRAMEBUFFERTEXTUREPROC cppgl_glNamedFramebufferTexture;
#define glNamedFramebufferTexture cppgl_glNamedFramebufferTexture
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERTEXTURELAYERPROC)(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer);
GLAPI PFNGLNAMEDFRAMEBUFFERTEXTURELAYERPROC cppgl_glNamedFramebufferTextureLayer;
#define glNamedFramebufferTextureLayer cppgl_glNamedFramebufferTextureLayer
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERDRAWBUFFERPROC)(GLuint framebuffer, GLenum buf);
GLAPI PFNGLNAMEDFRAMEBUFFERDRAWBUFFERPROC cppgl_glNamedFramebufferDrawBuffer;
#define glNamedFramebufferDrawBuffer cppgl_glNamedFramebufferDrawBuffer
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERDRAWBUFFERSPROC)(GLuint framebuffer, GLsizei n, const GLenum *bufs);
GLAPI PFNGLNAMEDFRAMEBUFFERDRAWBUFFERSPROC cppgl_glNamedFramebufferDrawBuffers;
#define glNamedFramebufferDrawBuffers cppgl_glNamedFramebufferDrawBuffers
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERREADBUFFERPROC)(GLuint framebuffer, GLenum src);
GLAPI PFNGLNAMEDFRAMEBUFFERREADBUFFERPROC cppgl_glNamedFramebufferReadBuffer;
#define glNamedFramebufferReadBuffer cppgl_glNamedFramebufferReadBuffer
typedef void (APIENTRYP PFNGLINVALIDATENAMEDFRAMEBUFFERDATAPROC)(GLuint framebuffer, GLsizei numAttachments, const GLenum *attachments);
GLAPI PFNGLINVALIDATENAMEDFRAMEBUFFERDATAPROC cppgl_glInvalidateNamedFramebufferData;
#define glInvalidateNamedFramebufferData cppgl_glInvalidateNamedFramebufferData
typedef void (APIENTRYP PFNGLINVALIDATENAMEDFRAMEBUFFERSUBDATAPROC)(GLuint framebuffer, GLsizei numAttachments, const GLenum *attachments, GLint x, GLint y, GLsizei width, GLsizei height);
GLAPI PFNGLINVALIDATENAMEDFRAMEBUFFERSUBDATAPROC cppgl_glInvalidateNamedFramebufferSubData;
#define glInvalidateNamedFramebufferSubData cppgl_glInvalidateNamedFramebufferSubData
typedef void (APIENTRYP PFNGLCLEARNAMEDFRAMEBUFFERIVPROC)(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLint *value);
GLAPI PFNGLCLEARNAMEDFRAMEBUFFERIVPROC cppgl_glClearNamedFramebufferiv;
#define glClearNamedFramebufferiv cppgl_glClearNamedFramebufferiv
typedef void (APIENTRYP PFNGLCLEARNAMEDFRAMEBUFFERUIVPROC)(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLuint *value);
GLAPI PFNGLCLEARNAMEDFRAMEBUFFERUIVPROC cppgl_glClearNamedFramebufferuiv;
#define glClearNamedFramebufferuiv cppgl_glClearNamedFramebufferuiv
typedef void (APIENTRYP PFNGLCLEARNAMEDFRAMEBUFFERFVPROC)(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLfloat *value);
GLAPI PFNGLCLEARNAMEDFRAMEBUFFERFVPROC cppgl_glClearNamedFramebufferfv;
#define glClearNamedFramebufferfv cppgl_glClearNamedFramebufferfv
typedef void (APIENTRYP PFNGLCLEARNAMEDFRAMEBUFFERFIPROC)(GLuint framebuffer, GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
GLAPI PFNGLCLEARNAMEDFRAMEBUFFERFIPROC cppgl_glClearNamedFramebufferfi;
#define glClearNamedFramebufferfi cppgl_glClearNamedFramebufferfi
typedef void (APIENTRYP PFNGLBLITNAMEDFRAMEBUFFERPROC)(GLuint readFramebuffer, GLuint drawFramebuffer, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
GLAPI PFNGLBLITNAMEDFRAMEBUFFERPROC cppgl_glBlitNamedFramebuffer;
#define glBlitNamedFramebuffer cppgl_glBlitNamedFramebuffer
typedef GLenum (APIENTRYP PFNGLCHECKNAMEDFRAMEBUFFERSTATUSPROC)(GLuint framebuffer, GLenum target);
GLAPI PFNGLCHECKNAMEDFRAMEBUFFERSTATUSPROC cppgl_glCheckNamedFramebufferStatus;
#define glCheckNamedFramebufferStatus cppgl_glCheckNamedFramebufferStatus
typedef void (APIENTRYP PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVPROC)(GLuint framebuffer, GLenum pname, GLint *param);
GLAPI PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVPROC cppgl_glGetNamedFramebufferParameteriv;
#define glGetNamedFramebufferParameteriv cppgl_glGetNamedFramebufferParameteriv
typedef void (APIENTRYP PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVPROC)(GLuint framebuffer, GLenum attachment, GLenum pname, GLint *params);
GLAPI PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVPROC cppgl_glGetNamedFramebufferAttachmentParameteriv;
#define glGetNamedFramebufferAttachmentParameteriv cppgl_glGetNamedFramebufferAttachmentParameteriv
typedef void (APIENTRYP PFNGLCREATERENDERBUFFERSPROC)(GLsizei n, GLuint *renderbuffers);
GLAPI PFNGLCREATERENDERBUFFERSPROC cppgl_glCreateRenderbuffers;
#define glCreateRenderbuffers cppgl_glCreateRenderbuffers
typedef void (APIENTRYP PFNGLNAMEDRENDERBUFFERSTORAGEPROC)(GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height);
GLAPI PFNGLNAMEDRENDERBUFFERSTORAGEPROC cppgl_glNamedRenderbufferStorage;
#define glNamedRenderbufferStorage cppgl_glNamedRenderbufferStorage
typedef void (APIENTRYP PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEPROC)(GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
GLAPI PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEPROC cppgl_glNamedRenderbufferStorageMultisample;
#define glNamedRenderbufferStorageMultisample cppgl_glNamedRenderbufferStorageMultisample
typedef void (APIENTRYP PFNGLGETNAMEDRENDERBUFFERPARAMETERIVPROC)(GLuint renderbuffer, GLenum pname, GLint *params);
GLAPI PFNGLGETNAMEDRENDERBUFFERPARAMETERIVPROC cppgl_glGetNamedRenderbufferParameteriv;
#define glGetNamedRenderbufferParameteriv cppgl_glGetNamedRenderbufferParameteriv
typedef void (APIENTRYP PFNGLCREATETEXTURESPROC)(GLenum target, GLsizei n, GLuint *textures);
GLAPI PFNGLCREATETEXTURESPROC cppgl_glCreateTextures;
#define glCreateTextures cppgl_glCreateTextures
typedef void (APIENTRYP PFNGLTEXTUREBUFFERPROC)(GLuint texture, GLenum internalformat, GLuint buffer);
GLAPI PFNGLTEXTUREBUFFERPROC cppgl_glTextureBuffer;
#define glTextureBuffer cppgl_glTextureBuffer
typedef void (APIENTRYP PFNGLTEXTUREBUFFERRANGEPROC)(GLuint texture, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
GLAPI PFNGLTEXTUREBUFFERRANGEPROC cppgl_glTextureBufferRange;
#define glTextureBufferRange cppgl_glTextureBufferRange
typedef void (APIENTRYP PFNGLTEXTURESTORAGE1DPROC)(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width);
GLAPI PFNGLTEXTURESTORAGE1DPROC cppgl_glTextureStorage1D;
#define glTextureStorage1D cppgl_glTextureStorage1D
typedef void (APIENTRYP PFNGLTEXTURESTORAGE2DPROC)(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
GLAPI PFNGLTEXTURESTORAGE2DPROC cppgl_glTextureStorage2D;
#define glTextureStorage2D cppgl_glTextureStorage2D
typedef void (APIENTRYP PFNGLTEXTURESTORAGE3DPROC)(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
GLAPI PFNGLTEXTURESTORAGE3DPROC cppgl_glTextureStorage3D;
#define glTextureStorage3D cppgl_glTextureStorage3D
typedef void (APIENTRYP PFNGLTEXTURESTORAGE2DMULTISAMPLEPROC)(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
GLAPI PFNGLTEXTURESTORAGE2DMULTISAMPLEPROC cppgl_glTextureStorage2DMultisample;
#define glTextureStorage2DMultisample cppgl_glTextureStorage2DMultisample
typedef void (APIENTRYP PFNGLTEXTURESTORAGE3DMULTISAMPLEPROC)(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
GLAPI PFNGLTEXTURESTORAGE3DMULTISAMPLEPROC cppgl_glTextureStorage3DMultisample;
#define glTextureStorage3DMultisample cppgl_glTextureStorage3DMultisample
typedef void (APIENTRYP PFNGLTEXTURESUBIMAGE1DPROC)(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels);
GLAPI PFNGLTEXTURESUBIMAGE1DPROC cppgl_glTextureSubImage1D;
#define glTextureSubImage1D cppgl_glTextureSubImage1D
typedef void (APIENTRYP PFNGLTEXTURESUBIMAGE2DPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
GLAPI PFNGLTEXTURESUBIMAGE2DPROC cppgl_glTextureSubImage2D;
#define glTextureSubImage2D cppgl_glTextureSubImage2D
typedef void (APIENTRYP PFNGLTEXTURESUBIMAGE3DPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels);
GLAPI PFNGLTEXTURESUBIMAGE3DPROC cppgl_glTextureSubImage3D;
#define glTextureSubImage3D cppgl_glTextureSubImage3D
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXTURESUBIMAGE1DPROC)(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data);
GLAPI PFNGLCOMPRESSEDTEXTURESUBIMAGE1DPROC cppgl_glCompressedTextureSubImage1D;
#define glCompressedTextureSubImage1D cppgl_glCompressedTextureSubImage1D
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXTURESUBIMAGE2DPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data);
GLAPI PFNGLCOMPRESSEDTEXTURESUBIMAGE2DPROC cppgl_glCompressedTextureSubImage2D;
#define glCompressedTextureSubImage2D cppgl_glCompressedTextureSubImage2D
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXTURESUBIMAGE3DPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data);
GLAPI PFNGLCOMPRESSEDTEXTURESUBIMAGE3DPROC cppgl_glCompressedTextureSubImage3D;
#define glCompressedTextureSubImage3D cppgl_glCompressedTextureSubImage3D
typedef void (APIENTRYP PFNGLCOPYTEXTURESUBIMAGE1DPROC)(GLuint texture, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
GLAPI PFNGLCOPYTEXTURESUBIMAGE1DPROC cppgl_glCopyTextureSubImage1D;
#define glCopyTextureSubImage1D cppgl_glCopyTextureSubImage1D
typedef void (APIENTRYP PFNGLCOPYTEXTURESUBIMAGE2DPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
GLAPI PFNGLCOPYTEXTURESUBIMAGE2DPROC cppgl_glCopyTextureSubImage2D;
#define glCopyTextureSubImage2D cppgl_glCopyTextureSubImage2D
typedef void (APIENTRYP PFNGLCOPYTEXTURESUBIMAGE3DPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
GLAPI PFNGLCOPYTEXTURESUBIMAGE3DPROC cppgl_glCopyTextureSubImage3D;
#define glCopyTextureSubImage3D cppgl_glCopyTextureSubImage3D
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERFPROC)(GLuint texture, GLenum pname, GLfloat param);
GLAPI PFNGLTEXTUREPARAMETERFPROC cppgl_glTextureParameterf;
#define glTextureParameterf cppgl_glTextureParameterf
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERFVPROC)(GLuint texture, GLenum pname, const GLfloat *param);
GLAPI PFNGLTEXTUREPARAMETERFVPROC cppgl_glTextureParameterfv;
#define glTextureParameterfv cppgl_glTextureParameterfv
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERIPROC)(GLuint texture, GLenum pname, GLint param);
GLAPI PFNGLTEXTUREPARAMETERIPROC cppgl_glTextureParameteri;
#define glTextureParameteri cppgl_glTextureParameteri
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERIIVPROC)(GLuint texture, GLenum pname, const GLint *params);
GLAPI PFNGLTEXTUREPARAMETERIIVPROC cppgl_glTextureParameterIiv;
#define glTextureParameterIiv cppgl_glTextureParameterIiv
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERIUIVPROC)(GLuint texture, GLenum pname, const GLuint *params);
GLAPI PFNGLTEXTUREPARAMETERIUIVPROC cppgl_glTextureParameterIuiv;
#define glTextureParameterIuiv cppgl_glTextureParameterIuiv
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERIVPROC)(GLuint texture, GLenum pname, const GLint *param);
GLAPI PFNGLTEXTUREPARAMETERIVPROC cppgl_glTextureParameteriv;
#define glTextureParameteriv cppgl_glTextureParameteriv
typedef void (APIENTRYP PFNGLGENERATETEXTUREMIPMAPPROC)(GLuint texture);
GLAPI PFNGLGENERATETEXTUREMIPMAPPROC cppgl_glGenerateTextureMipmap;
#define glGenerateTextureMipmap cppgl_glGenerateTextureMipmap
typedef void (APIENTRYP PFNGLBINDTEXTUREUNITPROC)(GLuint unit, GLuint texture);
GLAPI PFNGLBINDTEXTUREUNITPROC cppgl_glBindTextureUnit;
#define glBindTextureUnit cppgl_glBindTextureUnit
typedef void (APIENTRYP PFNGLGETTEXTUREIMAGEPROC)(GLuint texture, GLint level, GLenum format, GLenum type, GLsizei bufSize, void *pixels);
GLAPI PFNGLGETTEXTUREIMAGEPROC cppgl_glGetTextureImage;
#define glGetTextureImage cppgl_glGetTextureImage
typedef void (APIENTRYP PFNGLGETCOMPRESSEDTEXTUREIMAGEPROC)(GLuint texture, GLint level, GLsizei bufSize, void *pixels);
GLAPI PFNGLGETCOMPRESSEDTEXTUREIMAGEPROC cppgl_glGetCompressedTextureImage;
#define glGetCompressedTextureImage cppgl_glGetCompressedTextureImage
typedef void (APIENTRYP PFNGLGETTEXTURELEVELPARAMETERFVPROC)(GLuint texture, GLint level, GLenum pname, GLfloat *params);
GLAPI PFNGLGETTEXTURELEVELPARAMETERFVPROC cppgl_glGetTextureLevelParameterfv;
#define glGetTextureLevelParameterfv cppgl_glGetTextureLevelParameterfv
typedef void (APIENTRYP PFNGLGETTEXTURELEVELPARAMETERIVPROC)(GLuint texture, GLint level, GLenum pname, GLint *params);
GLAPI PFNGLGETTEXTURELEVELPARAMETERIVPROC cppgl_glGetTextureLevelParameteriv;
#define glGetTextureLevelParameteriv cppgl_glGetTextureLevelParameteriv
typedef void (APIENTRYP PFNGLGETTEXTUREPARAMETERFVPROC)(GLuint texture, GLenum pname, GLfloat *params);
GLAPI PFNGLGETTEXTUREPARAMETERFVPROC cppgl_glGetTextureParameterfv;
#define glGetTextureParameterfv cppgl_glGetTextureParameterfv
typedef void (APIENTRYP PFNGLGETTEXTUREPARAMETERIIVPROC)(GLuint texture, GLenum pname, GLint *params);
GLAPI PFNGLGETTEXTUREPARAMETERIIVPROC cppgl_glGetTextureParameterIiv;
#define glGetTextureParameterIiv cppgl_glGetTextureParameterIiv
typedef void (APIENTRYP PFNGLGETTEXTUREPARAMETERIUIVPROC)(GLuint texture, GLenum pname, GLuint *params);
GLAPI PFNGLGETTEXTUREPARAMETERIUIVPROC cppgl_glGetTextureParameterIuiv;
#define glGetTextureParameterIuiv cppgl_glGetTextureParameterIuiv
typedef void (APIENTRYP PFNGLGETTEXTUREPARAMETERIVPROC)(GLuint texture, GLenum pname, GLint *params);
GLAPI PFNGLGETTEXTUREPARAMETERIVPROC cppgl_glGetTextureParameteriv;
#define glGetTextureParameteriv cppgl_glGetTextureParameteriv
typedef void (APIENTRYP PFNGLCREATEVERTEXARRAYSPROC)(GLsizei n, GLuint *arrays);
GLAPI PFNGLCREATEVERTEXARRAYSPROC cppgl_glCreateVertexArrays;
#define glCreateVertexArrays cppgl_glCreateVertexArrays
typedef void (APIENTRYP PFNGLDISABLEVERTEXARRAYATTRIBPROC)(GLuint vaobj, GLuint index);
GLAPI PFNGLDISABLEVERTEXARRAYATTRIBPROC cppgl_glDisableVertexArrayAttrib;
#define glDisableVertexArrayAttrib cppgl_glDisableVertexArrayAttrib
typedef void (APIENTRYP PFNGLENABLEVERTEXARRAYATTRIBPROC)(GLuint vaobj, GLuint index);
GLAPI PFNGLENABLEVERTEXARRAYATTRIBPROC cppgl_glEnableVertexArrayAttrib;
#define glEnableVertexArrayAttrib cppgl_glEnableVertexArrayAttrib
typedef void (APIENTRYP PFNGLVERTEXARRAYELEMENTBUFFERPROC)(GLuint vaobj, GLuint buffer);
GLAPI PFNGLVERTEXARRAYELEMENTBUFFERPROC cppgl_glVertexArrayElementBuffer;
#define glVertexArrayElementBuffer cppgl_glVertexArrayElementBuffer
typedef void (APIENTRYP PFNGLVERTEXARRAYVERTEXBUFFERPROC)(GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
GLAPI PFNGLVERTEXARRAYVERTEXBUFFERPROC cppgl_glVertexArrayVertexBuffer;
#define glVertexArrayVertexBuffer cppgl_glVertexArrayVertexBuffer
typedef void (APIENTRYP PFNGLVERTEXARRAYVERTEXBUFFERSPROC)(GLuint vaobj, GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizei *strides);
GLAPI PFNGLVERTEXARRAYVERTEXBUFFERSPROC cppgl_glVertexArrayVertexBuffers;
#define glVertexArrayVertexBuffers cppgl_glVertexArrayVertexBuffers
typedef void (APIENTRYP PFNGLVERTEXARRAYATTRIBBINDINGPROC)(GLuint vaobj, GLuint attribindex, GLuint bindingindex);
GLAPI PFNGLVERTEXARRAYATTRIBBINDINGPROC cppgl_glVertexArrayAttribBinding;
#define glVertexArrayAttribBinding cppgl_glVertexArrayAttribBinding
typedef void (APIENTRYP PFNGLVERTEXARRAYATTRIBFORMATPROC)(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
GLAPI PFNGLVERTEXARRAYATTRIBFORMATPROC cppgl_glVertexArrayAttribFormat;
#define glVertexArrayAttribFormat cppgl_glVertexArrayAttribFormat
typedef void (APIENTRYP PFNGLVERTEXARRAYATTRIBIFORMATPROC)(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
GLAPI PFNGLVERTEXARRAYATTRIBIFORMATPROC cppgl_glVertexArrayAttribIFormat;
#define glVertexArrayAttribIFormat cppgl_glVertexArrayAttribIFormat
typedef void (APIENTRYP PFNGLVERTEXARRAYATTRIBLFORMATPROC)(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
GLAPI PFNGLVERTEXARRAYATTRIBLFORMATPROC cppgl_glVertexArrayAttribLFormat;
#define glVertexArrayAttribLFormat cppgl_glVertexArrayAttribLFormat
typedef void (APIENTRYP PFNGLVERTEXARRAYBINDINGDIVISORPROC)(GLuint vaobj, GLuint bindingindex, GLuint divisor);
GLAPI PFNGLVERTEXARRAYBINDINGDIVISORPROC cppgl_glVertexArrayBindingDivisor;
#define glVertexArrayBindingDivisor cppgl_glVertexArrayBindingDivisor
typedef void (APIENTRYP PFNGLGETVERTEXARRAYIVPROC)(GLuint vaobj, GLenum pname, GLint *param);
GLAPI PFNGLGETVERTEXARRAYIVPROC cppgl_glGetVertexArrayiv;
#define glGetVertexArrayiv cppgl_glGetVertexArrayiv
typedef void (APIENTRYP PFNGLGETVERTEXARRAYINDEXEDIVPROC)(GLuint vaobj, GLuint index, GLenum pname, GLint *param);
GLAPI PFNGLGETVERTEXARRAYINDEXEDIVPROC cppgl_glGetVertexArrayIndexediv;
#define glGetVertexArrayIndexediv cppgl_glGetVertexArrayIndexediv
typedef void (APIENTRYP PFNGLGETVERTEXARRAYINDEXED64IVPROC)(GLuint vaobj, GLuint index, GLenum pname, GLint64 *param);
GLAPI PFNGLGETVERTEXARRAYINDEXED64IVPROC cppgl_glGetVertexArrayIndexed64iv;
#define glGetVertexArrayIndexed64iv cppgl_glGetVertexArrayIndexed64iv
typedef void (APIENTRYP PFNGLCREATESAMPLERSPROC)(GLsizei n, GLuint *samplers);
GLAPI PFNGLCREATESAMPLERSPROC cppgl_glCreateSamplers;
#define glCreateSamplers cppgl_glCreateSamplers
typedef void (APIENTRYP PFNGLCREATEPROGRAMPIPELINESPROC)(GLsizei n, GLuint *pipelines);
GLAPI PFNGLCREATEPROGRAMPIPELINESPROC cppgl_glCreateProgramPipelines;
#define glCreateProgramPipelines cppgl_glCreateProgramPipelines
typedef void (APIENTRYP PFNGLCREATEQUERIESPROC)(GLenum target, GLsizei n, GLuint *ids);
GLAPI PFNGLCREATEQUERIESPROC cppgl_glCreateQueries;
#define glCreateQueries cppgl_glCreateQueries
typedef void (APIENTRYP PFNGLGETQUERYBUFFEROBJECTI64VPROC)(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
GLAPI PFNGLGETQUERYBUFFEROBJECTI64VPROC cppgl_glGetQueryBufferObjecti64v;
#define glGetQueryBufferObjecti64v cppgl_glGetQueryBufferObjecti64v
typedef void (APIENTRYP PFNGLGETQUERYBUFFEROBJECTIVPROC)(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
GLAPI PFNGLGETQUERYBUFFEROBJECTIVPROC cppgl_glGetQueryBufferObjectiv;
#define glGetQueryBufferObjectiv cppgl_glGetQueryBufferObjectiv
typedef void (APIENTRYP PFNGLGETQUERYBUFFEROBJECTUI64VPROC)(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
GLAPI PFNGLGETQUERYBUFFEROBJECTUI64VPROC cppgl_glGetQueryBufferObjectui64v;
#define glGetQueryBufferObjectui64v cppgl_glGetQueryBufferObjectui64v
typedef void (APIENTRYP PFNGLGETQUERYBUFFEROBJECTUIVPROC)(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
GLAPI PFNGLGETQUERYBUFFEROBJECTUIVPROC cppgl_glGetQueryBufferObjectuiv;
#define glGetQueryBufferObjectuiv cppgl_glGetQueryBufferObjectuiv
#endif
#ifndef GL_ARB_draw_buffers
#define GL_ARB_draw_buffers 1
GLAPI int CPPGL_GL_ARB_draw_buffers;
typedef void (APIENTRYP PFNGLDRAWBUFFERSARBPROC)(GLsizei n, const GLenum *bufs);
GLAPI PFNGLDRAWBUFFERSARBPROC cppgl_glDrawBuffersARB;
#define glDrawBuffersARB cppgl_glDrawBuffersARB
#endif
#ifndef GL_ARB_draw_buffers_blend
#define GL_ARB_draw_buffers_blend 1
GLAPI int CPPGL_GL_ARB_draw_buffers_blend;
typedef void (APIENTRYP PFNGLBLENDEQUATIONIARBPROC)(GLuint buf, GLenum mode);
GLAPI PFNGLBLENDEQUATIONIARBPROC cppgl_glBlendEquationiARB;
#define glBlendEquationiARB cppgl_glBlendEquationiARB
typedef void (APIENTRYP PFNGLBLENDEQUATIONSEPARATEIARBPROC)(GLuint buf, GLenum modeRGB, GLenum modeAlpha);
GLAPI PFNGLBLENDEQUATIONSEPARATEIARBPROC cppgl_glBlendEquationSeparateiARB;
#define glBlendEquationSeparateiARB cppgl_glBlendEquationSeparateiARB
typedef void (APIENTRYP PFNGLBLENDFUNCIARBPROC)(GLuint buf, GLenum src, GLenum dst);
GLAPI PFNGLBLENDFUNCIARBPROC cppgl_glBlendFunciARB;
#define glBlendFunciARB cppgl_glBlendFunciARB
typedef void (APIENTRYP PFNGLBLENDFUNCSEPARATEIARBPROC)(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
GLAPI PFNGLBLENDFUNCSEPARATEIARBPROC cppgl_glBlendFuncSeparateiARB;
#define glBlendFuncSeparateiARB cppgl_glBlendFuncSeparateiARB
#endif
#ifndef GL_ARB_draw_elements_base_vertex
#define GL_ARB_draw_elements_base_vertex 1
GLAPI int CPPGL_GL_ARB_draw_elements_base_vertex;
typedef void (APIENTRYP PFNGLDRAWELEMENTSBASEVERTEXPROC)(GLenum mode, GLsizei count, GLenum type, const void *indices, GLint basevertex);
GLAPI PFNGLDRAWELEMENTSBASEVERTEXPROC cppgl_glDrawElementsBaseVertex;
#define glDrawElementsBaseVertex cppgl_glDrawElementsBaseVertex
typedef void (APIENTRYP PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC)(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices, GLint basevertex);
GLAPI PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC cppgl_glDrawRangeElementsBaseVertex;
#define glDrawRangeElementsBaseVertex cppgl_glDrawRangeElementsBaseVertex
typedef void (APIENTRYP PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC)(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex);
GLAPI PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC cppgl_glDrawElementsInstancedBaseVertex;
#define glDrawElementsInstancedBaseVertex cppgl_glDrawElementsInstancedBaseVertex
typedef void (APIENTRYP PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC)(GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei drawcount, const GLint *basevertex);
GLAPI PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC cppgl_glMultiDrawElementsBaseVertex;
#define glMultiDrawElementsBaseVertex cppgl_glMultiDrawElementsBaseVertex
#endif
#ifndef GL_ARB_draw_indirect
#define GL_ARB_draw_indirect 1
GLAPI int CPPGL_GL_ARB_draw_indirect;
typedef void (APIENTRYP PFNGLDRAWARRAYSINDIRECTPROC)(GLenum mode, const void *indirect);
GLAPI PFNGLDRAWARRAYSINDIRECTPROC cppgl_glDrawArraysIndirect;
#define glDrawArraysIndirect cppgl_glDrawArraysIndirect
typedef void (APIENTRYP PFNGLDRAWELEMENTSINDIRECTPROC)(GLenum mode, GLenum type, const void *indirect);
GLAPI PFNGLDRAWELEMENTSINDIRECTPROC cppgl_glDrawElementsIndirect;
#define glDrawElementsIndirect cppgl_glDrawElementsIndirect
#endif
#ifndef GL_ARB_draw_instanced
#define GL_ARB_draw_instanced 1
GLAPI int CPPGL_GL_ARB_draw_instanced;
typedef void (APIENTRYP PFNGLDRAWARRAYSINSTANCEDARBPROC)(GLenum mode, GLint first, GLsizei count, GLsizei primcount);
GLAPI PFNGLDRAWARRAYSINSTANCEDARBPROC cppgl_glDrawArraysInstancedARB;
#define glDrawArraysInstancedARB cppgl_glDrawArraysInstancedARB
typedef void (APIENTRYP PFNGLDRAWELEMENTSINSTANCEDARBPROC)(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei primcount);
GLAPI PFNGLDRAWELEMENTSINSTANCEDARBPROC cppgl_glDrawElementsInstancedARB;
#define glDrawElementsInstancedARB cppgl_glDrawElementsInstancedARB
#endif
#ifndef GL_ARB_enhanced_layouts
#define GL_ARB_enhanced_layouts 1
GLAPI int CPPGL_GL_ARB_enhanced_layouts;
#endif
#ifndef GL_ARB_explicit_attrib_location
#define GL_ARB_explicit_attrib_location 1
GLAPI int CPPGL_GL_ARB_explicit_attrib_location;
#endif
#ifndef GL_ARB_explicit_uniform_location
#define GL_ARB_explicit_uniform_location 1
GLAPI int CPPGL_GL_ARB_explicit_uniform_location;
#endif
#ifndef GL_ARB_fragment_coord_conventions
#define GL_ARB_fragment_coord_conventions 1
GLAPI int CPPGL_GL_ARB_fragment_coord_conventions;
#endif
#ifndef GL_ARB_fragment_layer_viewport
#define GL_ARB_fragment_layer_viewport 1
GLAPI int CPPGL_GL_ARB_fragment_layer_viewport;
#endif
#ifndef GL_ARB_fragment_program
#define GL_ARB_fragment_program 1
GLAPI int CPPGL_GL_ARB_fragment_program;
typedef void (APIENTRYP PFNGLPROGRAMSTRINGARBPROC)(GLenum target, GLenum format, GLsizei len, const void *string);
GLAPI PFNGLPROGRAMSTRINGARBPROC cppgl_glProgramStringARB;
#define glProgramStringARB cppgl_glProgramStringARB
typedef void (APIENTRYP PFNGLBINDPROGRAMARBPROC)(GLenum target, GLuint program);
GLAPI PFNGLBINDPROGRAMARBPROC cppgl_glBindProgramARB;
#define glBindProgramARB cppgl_glBindProgramARB
typedef void (APIENTRYP PFNGLDELETEPROGRAMSARBPROC)(GLsizei n, const GLuint *programs);
GLAPI PFNGLDELETEPROGRAMSARBPROC cppgl_glDeleteProgramsARB;
#define glDeleteProgramsARB cppgl_glDeleteProgramsARB
typedef void (APIENTRYP PFNGLGENPROGRAMSARBPROC)(GLsizei n, GLuint *programs);
GLAPI PFNGLGENPROGRAMSARBPROC cppgl_glGenProgramsARB;
#define glGenProgramsARB cppgl_glGenProgramsARB
typedef void (APIENTRYP PFNGLPROGRAMENVPARAMETER4DARBPROC)(GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
GLAPI PFNGLPROGRAMENVPARAMETER4DARBPROC cppgl_glProgramEnvParameter4dARB;
#define glProgramEnvParameter4dARB cppgl_glProgramEnvParameter4dARB
typedef void (APIENTRYP PFNGLPROGRAMENVPARAMETER4DVARBPROC)(GLenum target, GLuint index, const GLdouble *params);
GLAPI PFNGLPROGRAMENVPARAMETER4DVARBPROC cppgl_glProgramEnvParameter4dvARB;
#define glProgramEnvParameter4dvARB cppgl_glProgramEnvParameter4dvARB
typedef void (APIENTRYP PFNGLPROGRAMENVPARAMETER4FARBPROC)(GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
GLAPI PFNGLPROGRAMENVPARAMETER4FARBPROC cppgl_glProgramEnvParameter4fARB;
#define glProgramEnvParameter4fARB cppgl_glProgramEnvParameter4fARB
typedef void (APIENTRYP PFNGLPROGRAMENVPARAMETER4FVARBPROC)(GLenum target, GLuint index, const GLfloat *params);
GLAPI PFNGLPROGRAMENVPARAMETER4FVARBPROC cppgl_glProgramEnvParameter4fvARB;
#define glProgramEnvParameter4fvARB cppgl_glProgramEnvParameter4fvARB
typedef void (APIENTRYP PFNGLPROGRAMLOCALPARAMETER4DARBPROC)(GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
GLAPI PFNGLPROGRAMLOCALPARAMETER4DARBPROC cppgl_glProgramLocalParameter4dARB;
#define glProgramLocalParameter4dARB cppgl_glProgramLocalParameter4dARB
typedef void (APIENTRYP PFNGLPROGRAMLOCALPARAMETER4DVARBPROC)(GLenum target, GLuint index, const GLdouble *params);
GLAPI PFNGLPROGRAMLOCALPARAMETER4DVARBPROC cppgl_glProgramLocalParameter4dvARB;
#define glProgramLocalParameter4dvARB cppgl_glProgramLocalParameter4dvARB
typedef void (APIENTRYP PFNGLPROGRAMLOCALPARAMETER4FARBPROC)(GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
GLAPI PFNGLPROGRAMLOCALPARAMETER4FARBPROC cppgl_glProgramLocalParameter4fARB;
#define glProgramLocalParameter4fARB cppgl_glProgramLocalParameter4fARB
typedef void (APIENTRYP PFNGLPROGRAMLOCALPARAMETER4FVARBPROC)(GLenum target, GLuint index, const GLfloat *params);
GLAPI PFNGLPROGRAMLOCALPARAMETER4FVARBPROC cppgl_glProgramLocalParameter4fvARB;
#define glProgramLocalParameter4fvARB cppgl_glProgramLocalParameter4fvARB
typedef void (APIENTRYP PFNGLGETPROGRAMENVPARAMETERDVARBPROC)(GLenum target, GLuint index, GLdouble *params);
GLAPI PFNGLGETPROGRAMENVPARAMETERDVARBPROC cppgl_glGetProgramEnvParameterdvARB;
#define glGetProgramEnvParameterdvARB cppgl_glGetProgramEnvParameterdvARB
typedef void (APIENTRYP PFNGLGETPROGRAMENVPARAMETERFVARBPROC)(GLenum target, GLuint index, GLfloat *params);
GLAPI PFNGLGETPROGRAMENVPARAMETERFVARBPROC cppgl_glGetProgramEnvParameterfvARB;
#define glGetProgramEnvParameterfvARB cppgl_glGetProgramEnvParameterfvARB
typedef void (APIENTRYP PFNGLGETPROGRAMLOCALPARAMETERDVARBPROC)(GLenum target, GLuint index, GLdouble *params);
GLAPI PFNGLGETPROGRAMLOCALPARAMETERDVARBPROC cppgl_glGetProgramLocalParameterdvARB;
#define glGetProgramLocalParameterdvARB cppgl_glGetProgramLocalParameterdvARB
typedef void (APIENTRYP PFNGLGETPROGRAMLOCALPARAMETERFVARBPROC)(GLenum target, GLuint index, GLfloat *params);
GLAPI PFNGLGETPROGRAMLOCALPARAMETERFVARBPROC cppgl_glGetProgramLocalParameterfvARB;
#define glGetProgramLocalParameterfvARB cppgl_glGetProgramLocalParameterfvARB
typedef void (APIENTRYP PFNGLGETPROGRAMIVARBPROC)(GLenum target, GLenum pname, GLint *params);
GLAPI PFNGLGETPROGRAMIVARBPROC cppgl_glGetProgramivARB;
#define glGetProgramivARB cppgl_glGetProgramivARB
typedef void (APIENTRYP PFNGLGETPROGRAMSTRINGARBPROC)(GLenum target, GLenum pname, void *string);
GLAPI PFNGLGETPROGRAMSTRINGARBPROC cppgl_glGetProgramStringARB;
#define glGetProgramStringARB cppgl_glGetProgramStringARB
typedef GLboolean (APIENTRYP PFNGLISPROGRAMARBPROC)(GLuint program);
GLAPI PFNGLISPROGRAMARBPROC cppgl_glIsProgramARB;
#define glIsProgramARB cppgl_glIsProgramARB
#endif
#ifndef GL_ARB_fragment_program_shadow
#define GL_ARB_fragment_program_shadow 1
GLAPI int CPPGL_GL_ARB_fragment_program_shadow;
#endif
#ifndef GL_ARB_fragment_shader
#define GL_ARB_fragment_shader 1
GLAPI int CPPGL_GL_ARB_fragment_shader;
#endif
#ifndef GL_ARB_fragment_shader_interlock
#define GL_ARB_fragment_shader_interlock 1
GLAPI int CPPGL_GL_ARB_fragment_shader_interlock;
#endif
#ifndef GL_ARB_framebuffer_no_attachments
#define GL_ARB_framebuffer_no_attachments 1
GLAPI int CPPGL_GL_ARB_framebuffer_no_attachments;
typedef void (APIENTRYP PFNGLFRAMEBUFFERPARAMETERIPROC)(GLenum target, GLenum pname, GLint param);
GLAPI PFNGLFRAMEBUFFERPARAMETERIPROC cppgl_glFramebufferParameteri;
#define glFramebufferParameteri cppgl_glFramebufferParameteri
typedef void (APIENTRYP PFNGLGETFRAMEBUFFERPARAMETERIVPROC)(GLenum target, GLenum pname, GLint *params);
GLAPI PFNGLGETFRAMEBUFFERPARAMETERIVPROC cppgl_glGetFramebufferParameteriv;
#define glGetFramebufferParameteriv cppgl_glGetFramebufferParameteriv
#endif
#ifndef GL_ARB_framebuffer_object
#define GL_ARB_framebuffer_object 1
GLAPI int CPPGL_GL_ARB_framebuffer_object;
typedef GLboolean (APIENTRYP PFNGLISRENDERBUFFERPROC)(GLuint renderbuffer);
GLAPI PFNGLISRENDERBUFFERPROC cppgl_glIsRenderbuffer;
#define glIsRenderbuffer cppgl_glIsRenderbuffer
typedef void (APIENTRYP PFNGLBINDRENDERBUFFERPROC)(GLenum target, GLuint renderbuffer);
GLAPI PFNGLBINDRENDERBUFFERPROC cppgl_glBindRenderbuffer;
#define glBindRenderbuffer cppgl_glBindRenderbuffer
typedef void (APIENTRYP PFNGLDELETERENDERBUFFERSPROC)(GLsizei n, const GLuint *renderbuffers);
GLAPI PFNGLDELETERENDERBUFFERSPROC cppgl_glDeleteRenderbuffers;
#define glDeleteRenderbuffers cppgl_glDeleteRenderbuffers
typedef void (APIENTRYP PFNGLGENRENDERBUFFERSPROC)(GLsizei n, GLuint *renderbuffers);
GLAPI PFNGLGENRENDERBUFFERSPROC cppgl_glGenRenderbuffers;
#define glGenRenderbuffers cppgl_glGenRenderbuffers
typedef void (APIENTRYP PFNGLRENDERBUFFERSTORAGEPROC)(GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
GLAPI PFNGLRENDERBUFFERSTORAGEPROC cppgl_glRenderbufferStorage;
#define glRenderbufferStorage cppgl_glRenderbufferStorage
typedef void (APIENTRYP PFNGLGETRENDERBUFFERPARAMETERIVPROC)(GLenum target, GLenum pname, GLint *params);
GLAPI PFNGLGETRENDERBUFFERPARAMETERIVPROC cppgl_glGetRenderbufferParameteriv;
#define glGetRenderbufferParameteriv cppgl_glGetRenderbufferParameteriv
typedef GLboolean (APIENTRYP PFNGLISFRAMEBUFFERPROC)(GLuint framebuffer);
GLAPI PFNGLISFRAMEBUFFERPROC cppgl_glIsFramebuffer;
#define glIsFramebuffer cppgl_glIsFramebuffer
typedef void (APIENTRYP PFNGLBINDFRAMEBUFFERPROC)(GLenum target, GLuint framebuffer);
GLAPI PFNGLBINDFRAMEBUFFERPROC cppgl_glBindFramebuffer;
#define glBindFramebuffer cppgl_glBindFramebuffer
typedef void (APIENTRYP PFNGLDELETEFRAMEBUFFERSPROC)(GLsizei n, const GLuint *framebuffers);
GLAPI PFNGLDELETEFRAMEBUFFERSPROC cppgl_glDeleteFramebuffers;
#define glDeleteFramebuffers cppgl_glDeleteFramebuffers
typedef void (APIENTRYP PFNGLGENFRAMEBUFFERSPROC)(GLsizei n, GLuint *framebuffers);
GLAPI PFNGLGENFRAMEBUFFERSPROC cppgl_glGenFramebuffers;
#define glGenFramebuffers cppgl_glGenFramebuffers
typedef GLenum (APIENTRYP PFNGLCHECKFRAMEBUFFERSTATUSPROC)(GLenum target);
GLAPI PFNGLCHECKFRAMEBUFFERSTATUSPROC cppgl_glCheckFramebufferStatus;
#define glCheckFramebufferStatus cppgl_glCheckFramebufferStatus
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTURE1DPROC)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
GLAPI PFNGLFRAMEBUFFERTEXTURE1DPROC cppgl_glFramebufferTexture1D;
#define glFramebufferTexture1D cppgl_glFramebufferTexture1D
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTURE2DPROC)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
GLAPI PFNGLFRAMEBUFFERTEXTURE2DPROC cppgl_glFramebufferTexture2D;
#define glFramebufferTexture2D cppgl_glFramebufferTexture2D
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTURE3DPROC)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
GLAPI PFNGLFRAMEBUFFERTEXTURE3DPROC cppgl_glFramebufferTexture3D;
#define glFramebufferTexture3D cppgl_glFramebufferTexture3D
typedef void (APIENTRYP PFNGLFRAMEBUFFERRENDERBUFFERPROC)(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
GLAPI PFNGLFRAMEBUFFERRENDERBUFFERPROC cppgl_glFramebufferRenderbuffer;
#define glFramebufferRenderbuffer cppgl_glFramebufferRenderbuffer
typedef void (APIENTRYP PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC)(GLenum target, GLenum attachment, GLenum pname, GLint *params);
GLAPI PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC cppgl_glGetFramebufferAttachmentParameteriv;
#define glGetFramebufferAttachmentParameteriv cppgl_glGetFramebufferAttachmentParameteriv
typedef void (APIENTRYP PFNGLGENERATEMIPMAPPROC)(GLenum target);
GLAPI PFNGLGENERATEMIPMAPPROC cppgl_glGenerateMipmap;
#define glGenerateMipmap cppgl_glGenerateMipmap
typedef void (APIENTRYP PFNGLBLITFRAMEBUFFERPROC)(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
GLAPI PFNGLBLITFRAMEBUFFERPROC cppgl_glBlitFramebuffer;
#define glBlitFramebuffer cppgl_glBlitFramebuffer
typedef void (APIENTRYP PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
GLAPI PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC cppgl_glRenderbufferStorageMultisample;
#define glRenderbufferStorageMultisample cppgl_glRenderbufferStorageMultisample
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTURELAYERPROC)(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
GLAPI PFNGLFRAMEBUFFERTEXTURELAYERPROC cppgl_glFramebufferTextureLayer;
#define glFramebufferTextureLayer cppgl_glFramebufferTextureLayer
#endif
#ifndef GL_ARB_framebuffer_sRGB
#define GL_ARB_framebuffer_sRGB 1
GLAPI int CPPGL_GL_ARB_framebuffer_sRGB;
#endif
#ifndef GL_ARB_geometry_shader4
#define GL_ARB_geometry_shader4 1
GLAPI int CPPGL_GL_ARB_geometry_shader4;
typedef void (APIENTRYP PFNGLPROGRAMPARAMETERIARBPROC)(GLuint program, GLenum pname, GLint value);
GLAPI PFNGLPROGRAMPARAMETERIARBPROC cppgl_glProgramParameteriARB;
#define glProgramParameteriARB cppgl_glProgramParameteriARB
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTUREARBPROC)(GLenum target, GLenum attachment, GLuint texture, GLint level);
GLAPI PFNGLFRAMEBUFFERTEXTUREARBPROC cppgl_glFramebufferTextureARB;
#define glFramebufferTextureARB cppgl_glFramebufferTextureARB
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTURELAYERARBPROC)(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
GLAPI PFNGLFRAMEBUFFERTEXTURELAYERARBPROC cppgl_glFramebufferTextureLayerARB;
#define glFramebufferTextureLayerARB cppgl_glFramebufferTextureLayerARB
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTUREFACEARBPROC)(GLenum target, GLenum attachment, GLuint texture, GLint level, GLenum face);
GLAPI PFNGLFRAMEBUFFERTEXTUREFACEARBPROC cppgl_glFramebufferTextureFaceARB;
#define glFramebufferTextureFaceARB cppgl_glFramebufferTextureFaceARB
#endif
#ifndef GL_ARB_get_program_binary
#define GL_ARB_get_program_binary 1
GLAPI int CPPGL_GL_ARB_get_program_binary;
typedef void (APIENTRYP PFNGLGETPROGRAMBINARYPROC)(GLuint program, GLsizei bufSize, GLsizei *length, GLenum *binaryFormat, void *binary);
GLAPI PFNGLGETPROGRAMBINARYPROC cppgl_glGetProgramBinary;
#define glGetProgramBinary cppgl_glGetProgramBinary
typedef void (APIENTRYP PFNGLPROGRAMBINARYPROC)(GLuint program, GLenum binaryFormat, const void *binary, GLsizei length);
GLAPI PFNGLPROGRAMBINARYPROC cppgl_glProgramBinary;
#define glProgramBinary cppgl_glProgramBinary
typedef void (APIENTRYP PFNGLPROGRAMPARAMETERIPROC)(GLuint program, GLenum pname, GLint value);
GLAPI PFNGLPROGRAMPARAMETERIPROC cppgl_glProgramParameteri;
#define glProgramParameteri cppgl_glProgramParameteri
#endif
#ifndef GL_ARB_get_texture_sub_image
#define GL_ARB_get_texture_sub_image 1
GLAPI int CPPGL_GL_ARB_get_texture_sub_image;
typedef void (APIENTRYP PFNGLGETTEXTURESUBIMAGEPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLsizei bufSize, void *pixels);
GLAPI PFNGLGETTEXTURESUBIMAGEPROC cppgl_glGetTextureSubImage;
#define glGetTextureSubImage cppgl_glGetTextureSubImage
typedef void (APIENTRYP PFNGLGETCOMPRESSEDTEXTURESUBIMAGEPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLsizei bufSize, void *pixels);
GLAPI PFNGLGETCOMPRESSEDTEXTURESUBIMAGEPROC cppgl_glGetCompressedTextureSubImage;
#define glGetCompressedTextureSubImage cppgl_glGetCompressedTextureSubImage
#endif
#ifndef GL_ARB_gpu_shader5
#define GL_ARB_gpu_shader5 1
GLAPI int CPPGL_GL_ARB_gpu_shader5;
#endif
#ifndef GL_ARB_gpu_shader_fp64
#define GL_ARB_gpu_shader_fp64 1
GLAPI int CPPGL_GL_ARB_gpu_shader_fp64;
typedef void (APIENTRYP PFNGLUNIFORM1DPROC)(GLint location, GLdouble x);
GLAPI PFNGLUNIFORM1DPROC cppgl_glUniform1d;
#define glUniform1d cppgl_glUniform1d
typedef void (APIENTRYP PFNGLUNIFORM2DPROC)(GLint location, GLdouble x, GLdouble y);
GLAPI PFNGLUNIFORM2DPROC cppgl_glUniform2d;
#define glUniform2d cppgl_glUniform2d
typedef void (APIENTRYP PFNGLUNIFORM3DPROC)(GLint location, GLdouble x, GLdouble y, GLdouble z);
GLAPI PFNGLUNIFORM3DPROC cppgl_glUniform3d;
#define glUniform3d cppgl_glUniform3d
typedef void (APIENTRYP PFNGLUNIFORM4DPROC)(GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
GLAPI PFNGLUNIFORM4DPROC cppgl_glUniform4d;
#define glUniform4d cppgl_glUniform4d
typedef void (APIENTRYP PFNGLUNIFORM1DVPROC)(GLint location, GLsizei count, const GLdouble *value);
GLAPI PFNGLUNIFORM1DVPROC cppgl_glUniform1dv;
#define glUniform1dv cppgl_glUniform1dv
typedef void (APIENTRYP PFNGLUNIFORM2DVPROC)(GLint location, GLsizei count, const GLdouble *value);
GLAPI PFNGLUNIFORM2DVPROC cppgl_glUniform2dv;
#define glUniform2dv cppgl_glUniform2dv
typedef void (APIENTRYP PFNGLUNIFORM3DVPROC)(GLint location, GLsizei count, const GLdouble *value);
GLAPI PFNGLUNIFORM3DVPROC cppgl_glUniform3dv;
#define glUniform3dv cppgl_glUniform3dv
typedef void (APIENTRYP PFNGLUNIFORM4DVPROC)(GLint location, GLsizei count, const GLdouble *value);
GLAPI PFNGLUNIFORM4DVPROC cppgl_glUniform4dv;
#define glUniform4dv cppgl_glUniform4dv
typedef void (APIENTRYP PFNGLUNIFORMMATRIX2DVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI PFNGLUNIFORMMATRIX2DVPROC cppgl_glUniformMatrix2dv;
#define glUniformMatrix2dv cppgl_glUniformMatrix2dv
typedef void (APIENTRYP PFNGLUNIFORMMATRIX3DVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI PFNGLUNIFORMMATRIX3DVPROC cppgl_glUniformMatrix3dv;
#define glUniformMatrix3dv cppgl_glUniformMatrix3dv
typedef void (APIENTRYP PFNGLUNIFORMMATRIX4DVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI PFNGLUNIFORMMATRIX4DVPROC cppgl_glUniformMatrix4dv;
#define glUniformMatrix4dv cppgl_glUniformMatrix4dv
typedef void (APIENTRYP PFNGLUNIFORMMATRIX2X3DVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI PFNGLUNIFORMMATRIX2X3DVPROC cppgl_glUniformMatrix2x3dv;
#define glUniformMatrix2x3dv cppgl_glUniformMatrix2x3dv
typedef void (APIENTRYP PFNGLUNIFORMMATRIX2X4DVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI PFNGLUNIFORMMATRIX2X4DVPROC cppgl_glUniformMatrix2x4dv;
#define glUniformMatrix2x4dv cppgl_glUniformMatrix2x4dv
typedef void (APIENTRYP PFNGLUNIFORMMATRIX3X2DVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI PFNGLUNIFORMMATRIX3X2DVPROC cppgl_glUniformMatrix3x2dv;
#define glUniformMatrix3x2dv cppgl_glUniformMatrix3x2dv
typedef void (APIENTRYP PFNGLUNIFORMMATRIX3X4DVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI PFNGLUNIFORMMATRIX3X4DVPROC cppgl_glUniformMatrix3x4dv;
#define glUniformMatrix3x4dv cppgl_glUniformMatrix3x4dv
typedef void (APIENTRYP PFNGLUNIFORMMATRIX4X2DVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI PFNGLUNIFORMMATRIX4X2DVPROC cppgl_glUniformMatrix4x2dv;
#define glUniformMatrix4x2dv cppgl_glUniformMatrix4x2dv
typedef void (APIENTRYP PFNGLUNIFORMMATRIX4X3DVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI PFNGLUNIFORMMATRIX4X3DVPROC cppgl_glUniformMatrix4x3dv;
#define glUniformMatrix4x3dv cppgl_glUniformMatrix4x3dv
typedef void (APIENTRYP PFNGLGETUNIFORMDVPROC)(GLuint program, GLint location, GLdouble *params);
GLAPI PFNGLGETUNIFORMDVPROC cppgl_glGetUniformdv;
#define glGetUniformdv cppgl_glGetUniformdv
#endif
#ifndef GL_ARB_gpu_shader_int64
#define GL_ARB_gpu_shader_int64 1
GLAPI int CPPGL_GL_ARB_gpu_shader_int64;
typedef void (APIENTRYP PFNGLUNIFORM1I64ARBPROC)(GLint location, GLint64 x);
GLAPI PFNGLUNIFORM1I64ARBPROC cppgl_glUniform1i64ARB;
#define glUniform1i64ARB cppgl_glUniform1i64ARB
typedef void (APIENTRYP PFNGLUNIFORM2I64ARBPROC)(GLint location, GLint64 x, GLint64 y);
GLAPI PFNGLUNIFORM2I64ARBPROC cppgl_glUniform2i64ARB;
#define glUniform2i64ARB cppgl_glUniform2i64ARB
typedef void (APIENTRYP PFNGLUNIFORM3I64ARBPROC)(GLint location, GLint64 x, GLint64 y, GLint64 z);
GLAPI PFNGLUNIFORM3I64ARBPROC cppgl_glUniform3i64ARB;
#define glUniform3i64ARB cppgl_glUniform3i64ARB
typedef void (APIENTRYP PFNGLUNIFORM4I64ARBPROC)(GLint location, GLint64 x, GLint64 y, GLint64 z, GLint64 w);
GLAPI PFNGLUNIFORM4I64ARBPROC cppgl_glUniform4i64ARB;
#define glUniform4i64ARB cppgl_glUniform4i64ARB
typedef void (APIENTRYP PFNGLUNIFORM1I64VARBPROC)(GLint location, GLsizei count, const GLint64 *value);
GLAPI PFNGLUNIFORM1I64VARBPROC cppgl_glUniform1i64vARB;
#define glUniform1i64vARB cppgl_glUniform1i64vARB
typedef void (APIENTRYP PFNGLUNIFORM2I64VARBPROC)(GLint location, GLsizei count, const GLint64 *value);
GLAPI PFNGLUNIFORM2I64VARBPROC cppgl_glUniform2i64vARB;
#define glUniform2i64vARB cppgl_glUniform2i64vARB
typedef void (APIENTRYP PFNGLUNIFORM3I64VARBPROC)(GLint location, GLsizei count, const GLint64 *value);
GLAPI PFNGLUNIFORM3I64VARBPROC cppgl_glUniform3i64vARB;
#define glUniform3i64vARB cppgl_glUniform3i64vARB
typedef void (APIENTRYP PFNGLUNIFORM4I64VARBPROC)(GLint location, GLsizei count, const GLint64 *value);
GLAPI PFNGLUNIFORM4I64VARBPROC cppgl_glUniform4i64vARB;
#define glUniform4i64vARB cppgl_glUniform4i64vARB
typedef void (APIENTRYP PFNGLUNIFORM1UI64ARBPROC)(GLint location, GLuint64 x);
GLAPI PFNGLUNIFORM1UI64ARBPROC cppgl_glUniform1ui64ARB;
#define glUniform1ui64ARB cppgl_glUniform1ui64ARB
typedef void (APIENTRYP PFNGLUNIFORM2UI64ARBPROC)(GLint location, GLuint64 x, GLuint64 y);
GLAPI PFNGLUNIFORM2UI64ARBPROC cppgl_glUniform2ui64ARB;
#define glUniform2ui64ARB cppgl_glUniform2ui64ARB
typedef void (APIENTRYP PFNGLUNIFORM3UI64ARBPROC)(GLint location, GLuint64 x, GLuint64 y, GLuint64 z);
GLAPI PFNGLUNIFORM3UI64ARBPROC cppgl_glUniform3ui64ARB;
#define glUniform3ui64ARB cppgl_glUniform3ui64ARB
typedef void (APIENTRYP PFNGLUNIFORM4UI64ARBPROC)(GLint location, GLuint64 x, GLuint64 y, GLuint64 z, GLuint64 w);
GLAPI PFNGLUNIFORM4UI64ARBPROC cppgl_glUniform4ui64ARB;
#define glUniform4ui64ARB cppgl_glUniform4ui64ARB
typedef void (APIENTRYP PFNGLUNIFORM1UI64VARBPROC)(GLint location, GLsizei count, const GLuint64 *value);
GLAPI PFNGLUNIFORM1UI64VARBPROC cppgl_glUniform1ui64vARB;
#define glUniform1ui64vARB cppgl_glUniform1ui64vARB
typedef void (APIENTRYP PFNGLUNIFORM2UI64VARBPROC)(GLint location, GLsizei count, const GLuint64 *value);
GLAPI PFNGLUNIFORM2UI64VARBPROC cppgl_glUniform2ui64vARB;
#define glUniform2ui64vARB cppgl_glUniform2ui64vARB
typedef void (APIENTRYP PFNGLUNIFORM3UI64VARBPROC)(GLint location, GLsizei count, const GLuint64 *value);
GLAPI PFNGLUNIFORM3UI64VARBPROC cppgl_glUniform3ui64vARB;
#define glUniform3ui64vARB cppgl_glUniform3ui64vARB
typedef void (APIENTRYP PFNGLUNIFORM4UI64VARBPROC)(GLint location, GLsizei count, const GLuint64 *value);
GLAPI PFNGLUNIFORM4UI64VARBPROC cppgl_glUniform4ui64vARB;
#define glUniform4ui64vARB cppgl_glUniform4ui64vARB
typedef void (APIENTRYP PFNGLGETUNIFORMI64VARBPROC)(GLuint program, GLint location, GLint64 *params);
GLAPI PFNGLGETUNIFORMI64VARBPROC cppgl_glGetUniformi64vARB;
#define glGetUniformi64vARB cppgl_glGetUniformi64vARB
typedef void (APIENTRYP PFNGLGETUNIFORMUI64VARBPROC)(GLuint program, GLint location, GLuint64 *params);
GLAPI PFNGLGETUNIFORMUI64VARBPROC cppgl_glGetUniformui64vARB;
#define glGetUniformui64vARB cppgl_glGetUniformui64vARB
typedef void (APIENTRYP PFNGLGETNUNIFORMI64VARBPROC)(GLuint program, GLint location, GLsizei bufSize, GLint64 *params);
GLAPI PFNGLGETNUNIFORMI64VARBPROC cppgl_glGetnUniformi64vARB;
#define glGetnUniformi64vARB cppgl_glGetnUniformi64vARB
typedef void (APIENTRYP PFNGLGETNUNIFORMUI64VARBPROC)(GLuint program, GLint location, GLsizei bufSize, GLuint64 *params);
GLAPI PFNGLGETNUNIFORMUI64VARBPROC cppgl_glGetnUniformui64vARB;
#define glGetnUniformui64vARB cppgl_glGetnUniformui64vARB
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1I64ARBPROC)(GLuint program, GLint location, GLint64 x);
GLAPI PFNGLPROGRAMUNIFORM1I64ARBPROC cppgl_glProgramUniform1i64ARB;
#define glProgramUniform1i64ARB cppgl_glProgramUniform1i64ARB
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2I64ARBPROC)(GLuint program, GLint location, GLint64 x, GLint64 y);
GLAPI PFNGLPROGRAMUNIFORM2I64ARBPROC cppgl_glProgramUniform2i64ARB;
#define glProgramUniform2i64ARB cppgl_glProgramUniform2i64ARB
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3I64ARBPROC)(GLuint program, GLint location, GLint64 x, GLint64 y, GLint64 z);
GLAPI PFNGLPROGRAMUNIFORM3I64ARBPROC cppgl_glProgramUniform3i64ARB;
#define glProgramUniform3i64ARB cppgl_glProgramUniform3i64ARB
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4I64ARBPROC)(GLuint program, GLint location, GLint64 x, GLint64 y, GLint64 z, GLint64 w);
GLAPI PFNGLPROGRAMUNIFORM4I64ARBPROC cppgl_glProgramUniform4i64ARB;
#define glProgramUniform4i64ARB cppgl_glProgramUniform4i64ARB
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1I64VARBPROC)(GLuint program, GLint location, GLsizei count, const GLint64 *value);
GLAPI PFNGLPROGRAMUNIFORM1I64VARBPROC cppgl_glProgramUniform1i64vARB;
#define glProgramUniform1i64vARB cppgl_glProgramUniform1i64vARB
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2I64VARBPROC)(GLuint program, GLint location, GLsizei count, const GLint64 *value);
GLAPI PFNGLPROGRAMUNIFORM2I64VARBPROC cppgl_glProgramUniform2i64vARB;
#define glProgramUniform2i64vARB cppgl_glProgramUniform2i64vARB
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3I64VARBPROC)(GLuint program, GLint location, GLsizei count, const GLint64 *value);
GLAPI PFNGLPROGRAMUNIFORM3I64VARBPROC cppgl_glProgramUniform3i64vARB;
#define glProgramUniform3i64vARB cppgl_glProgramUniform3i64vARB
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4I64VARBPROC)(GLuint program, GLint location, GLsizei count, const GLint64 *value);
GLAPI PFNGLPROGRAMUNIFORM4I64VARBPROC cppgl_glProgramUniform4i64vARB;
#define glProgramUniform4i64vARB cppgl_glProgramUniform4i64vARB
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1UI64ARBPROC)(GLuint program, GLint location, GLuint64 x);
GLAPI PFNGLPROGRAMUNIFORM1UI64ARBPROC cppgl_glProgramUniform1ui64ARB;
#define glProgramUniform1ui64ARB cppgl_glProgramUniform1ui64ARB
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2UI64ARBPROC)(GLuint program, GLint location, GLuint64 x, GLuint64 y);
GLAPI PFNGLPROGRAMUNIFORM2UI64ARBPROC cppgl_glProgramUniform2ui64ARB;
#define glProgramUniform2ui64ARB cppgl_glProgramUniform2ui64ARB
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3UI64ARBPROC)(GLuint program, GLint location, GLuint64 x, GLuint64 y, GLuint64 z);
GLAPI PFNGLPROGRAMUNIFORM3UI64ARBPROC cppgl_glProgramUniform3ui64ARB;
#define glProgramUniform3ui64ARB cppgl_glProgramUniform3ui64ARB
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4UI64ARBPROC)(GLuint program, GLint location, GLuint64 x, GLuint64 y, GLuint64 z, GLuint64 w);
GLAPI PFNGLPROGRAMUNIFORM4UI64ARBPROC cppgl_glProgramUniform4ui64ARB;
#define glProgramUniform4ui64ARB cppgl_glProgramUniform4ui64ARB
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1UI64VARBPROC)(GLuint program, GLint location, GLsizei count, const GLuint64 *value);
GLAPI PFNGLPROGRAMUNIFORM1UI64VARBPROC cppgl_glProgramUniform1ui64vARB;
#define glProgramUniform1ui64vARB cppgl_glProgramUniform1ui64vARB
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2UI64VARBPROC)(GLuint program, GLint location, GLsizei count, const GLuint64 *value);
GLAPI PFNGLPROGRAMUNIFORM2UI64VARBPROC cppgl_glProgramUniform2ui64vARB;
#define glProgramUniform2ui64vARB cppgl_glProgramUniform2ui64vARB
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3UI64VARBPROC)(GLuint program, GLint location, GLsizei count, const GLuint64 *value);
GLAPI PFNGLPROGRAMUNIFORM3UI64VARBPROC cppgl_glProgramUniform3ui64vARB;
#define glProgramUniform3ui64vARB cppgl_glProgramUniform3ui64vARB
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4UI64VARBPROC)(GLuint program, GLint location, GLsizei count, const GLuint64 *value);
GLAPI PFNGLPROGRAMUNIFORM4UI64VARBPROC cppgl_glProgramUniform4ui64vARB;
#define glProgramUniform4ui64vARB cppgl_glProgramUniform4ui64vARB
#endif
#ifndef GL_ARB_half_float_pixel
#define GL_ARB_half_float_pixel 1
GLAPI int CPPGL_GL_ARB_half_float_pixel;
#endif
#ifndef GL_ARB_half_float_vertex
#define GL_ARB_half_float_vertex 1
GLAPI int CPPGL_GL_ARB_half_float_vertex;
#endif
#ifndef GL_ARB_imaging
#define GL_ARB_imaging 1
GLAPI int CPPGL_GL_ARB_imaging;
typedef void (APIENTRYP PFNGLBLENDCOLORPROC)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
GLAPI PFNGLBLENDCOLORPROC cppgl_glBlendColor;
#define glBlendColor cppgl_glBlendColor
typedef void (APIENTRYP PFNGLBLENDEQUATIONPROC)(GLenum mode);
GLAPI PFNGLBLENDEQUATIONPROC cppgl_glBlendEquation;
#define glBlendEquation cppgl_glBlendEquation
typedef void (APIENTRYP PFNGLCOLORTABLEPROC)(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const void *table);
GLAPI PFNGLCOLORTABLEPROC cppgl_glColorTable;
#define glColorTable cppgl_glColorTable
typedef void (APIENTRYP PFNGLCOLORTABLEPARAMETERFVPROC)(GLenum target, GLenum pname, const GLfloat *params);
GLAPI PFNGLCOLORTABLEPARAMETERFVPROC cppgl_glColorTableParameterfv;
#define glColorTableParameterfv cppgl_glColorTableParameterfv
typedef void (APIENTRYP PFNGLCOLORTABLEPARAMETERIVPROC)(GLenum target, GLenum pname, const GLint *params);
GLAPI PFNGLCOLORTABLEPARAMETERIVPROC cppgl_glColorTableParameteriv;
#define glColorTableParameteriv cppgl_glColorTableParameteriv
typedef void (APIENTRYP PFNGLCOPYCOLORTABLEPROC)(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width);
GLAPI PFNGLCOPYCOLORTABLEPROC cppgl_glCopyColorTable;
#define glCopyColorTable cppgl_glCopyColorTable
typedef void (APIENTRYP PFNGLGETCOLORTABLEPROC)(GLenum target, GLenum format, GLenum type, void *table);
GLAPI PFNGLGETCOLORTABLEPROC cppgl_glGetColorTable;
#define glGetColorTable cppgl_glGetColorTable
typedef void (APIENTRYP PFNGLGETCOLORTABLEPARAMETERFVPROC)(GLenum target, GLenum pname, GLfloat *params);
GLAPI PFNGLGETCOLORTABLEPARAMETERFVPROC cppgl_glGetColorTableParameterfv;
#define glGetColorTableParameterfv cppgl_glGetColorTableParameterfv
typedef void (APIENTRYP PFNGLGETCOLORTABLEPARAMETERIVPROC)(GLenum target, GLenum pname, GLint *params);
GLAPI PFNGLGETCOLORTABLEPARAMETERIVPROC cppgl_glGetColorTableParameteriv;
#define glGetColorTableParameteriv cppgl_glGetColorTableParameteriv
typedef void (APIENTRYP PFNGLCOLORSUBTABLEPROC)(GLenum target, GLsizei start, GLsizei count, GLenum format, GLenum type, const void *data);
GLAPI PFNGLCOLORSUBTABLEPROC cppgl_glColorSubTable;
#define glColorSubTable cppgl_glColorSubTable
typedef void (APIENTRYP PFNGLCOPYCOLORSUBTABLEPROC)(GLenum target, GLsizei start, GLint x, GLint y, GLsizei width);
GLAPI PFNGLCOPYCOLORSUBTABLEPROC cppgl_glCopyColorSubTable;
#define glCopyColorSubTable cppgl_glCopyColorSubTable
typedef void (APIENTRYP PFNGLCONVOLUTIONFILTER1DPROC)(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const void *image);
GLAPI PFNGLCONVOLUTIONFILTER1DPROC cppgl_glConvolutionFilter1D;
#define glConvolutionFilter1D cppgl_glConvolutionFilter1D
typedef void (APIENTRYP PFNGLCONVOLUTIONFILTER2DPROC)(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *image);
GLAPI PFNGLCONVOLUTIONFILTER2DPROC cppgl_glConvolutionFilter2D;
#define glConvolutionFilter2D cppgl_glConvolutionFilter2D
typedef void (APIENTRYP PFNGLCONVOLUTIONPARAMETERFPROC)(GLenum target, GLenum pname, GLfloat params);
GLAPI PFNGLCONVOLUTIONPARAMETERFPROC cppgl_glConvolutionParameterf;
#define glConvolutionParameterf cppgl_glConvolutionParameterf
typedef void (APIENTRYP PFNGLCONVOLUTIONPARAMETERFVPROC)(GLenum target, GLenum pname, const GLfloat *params);
GLAPI PFNGLCONVOLUTIONPARAMETERFVPROC cppgl_glConvolutionParameterfv;
#define glConvolutionParameterfv cppgl_glConvolutionParameterfv
typedef void (APIENTRYP PFNGLCONVOLUTIONPARAMETERIPROC)(GLenum target, GLenum pname, GLint params);
GLAPI PFNGLCONVOLUTIONPARAMETERIPROC cppgl_glConvolutionParameteri;
#define glConvolutionParameteri cppgl_glConvolutionParameteri
typedef void (APIENTRYP PFNGLCONVOLUTIONPARAMETERIVPROC)(GLenum target, GLenum pname, const GLint *params);
GLAPI PFNGLCONVOLUTIONPARAMETERIVPROC cppgl_glConvolutionParameteriv;
#define glConvolutionParameteriv cppgl_glConvolutionParameteriv
typedef void (APIENTRYP PFNGLCOPYCONVOLUTIONFILTER1DPROC)(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width);
GLAPI PFNGLCOPYCONVOLUTIONFILTER1DPROC cppgl_glCopyConvolutionFilter1D;
#define glCopyConvolutionFilter1D cppgl_glCopyConvolutionFilter1D
typedef void (APIENTRYP PFNGLCOPYCONVOLUTIONFILTER2DPROC)(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height);
GLAPI PFNGLCOPYCONVOLUTIONFILTER2DPROC cppgl_glCopyConvolutionFilter2D;
#define glCopyConvolutionFilter2D cppgl_glCopyConvolutionFilter2D
typedef void (APIENTRYP PFNGLGETCONVOLUTIONFILTERPROC)(GLenum target, GLenum format, GLenum type, void *image);
GLAPI PFNGLGETCONVOLUTIONFILTERPROC cppgl_glGetConvolutionFilter;
#define glGetConvolutionFilter cppgl_glGetConvolutionFilter
typedef void (APIENTRYP PFNGLGETCONVOLUTIONPARAMETERFVPROC)(GLenum target, GLenum pname, GLfloat *params);
GLAPI PFNGLGETCONVOLUTIONPARAMETERFVPROC cppgl_glGetConvolutionParameterfv;
#define glGetConvolutionParameterfv cppgl_glGetConvolutionParameterfv
typedef void (APIENTRYP PFNGLGETCONVOLUTIONPARAMETERIVPROC)(GLenum target, GLenum pname, GLint *params);
GLAPI PFNGLGETCONVOLUTIONPARAMETERIVPROC cppgl_glGetConvolutionParameteriv;
#define glGetConvolutionParameteriv cppgl_glGetConvolutionParameteriv
typedef void (APIENTRYP PFNGLGETSEPARABLEFILTERPROC)(GLenum target, GLenum format, GLenum type, void *row, void *column, void *span);
GLAPI PFNGLGETSEPARABLEFILTERPROC cppgl_glGetSeparableFilter;
#define glGetSeparableFilter cppgl_glGetSeparableFilter
typedef void (APIENTRYP PFNGLSEPARABLEFILTER2DPROC)(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *row, const void *column);
GLAPI PFNGLSEPARABLEFILTER2DPROC cppgl_glSeparableFilter2D;
#define glSeparableFilter2D cppgl_glSeparableFilter2D
typedef void (APIENTRYP PFNGLGETHISTOGRAMPROC)(GLenum target, GLboolean reset, GLenum format, GLenum type, void *values);
GLAPI PFNGLGETHISTOGRAMPROC cppgl_glGetHistogram;
#define glGetHistogram cppgl_glGetHistogram
typedef void (APIENTRYP PFNGLGETHISTOGRAMPARAMETERFVPROC)(GLenum target, GLenum pname, GLfloat *params);
GLAPI PFNGLGETHISTOGRAMPARAMETERFVPROC cppgl_glGetHistogramParameterfv;
#define glGetHistogramParameterfv cppgl_glGetHistogramParameterfv
typedef void (APIENTRYP PFNGLGETHISTOGRAMPARAMETERIVPROC)(GLenum target, GLenum pname, GLint *params);
GLAPI PFNGLGETHISTOGRAMPARAMETERIVPROC cppgl_glGetHistogramParameteriv;
#define glGetHistogramParameteriv cppgl_glGetHistogramParameteriv
typedef void (APIENTRYP PFNGLGETMINMAXPROC)(GLenum target, GLboolean reset, GLenum format, GLenum type, void *values);
GLAPI PFNGLGETMINMAXPROC cppgl_glGetMinmax;
#define glGetMinmax cppgl_glGetMinmax
typedef void (APIENTRYP PFNGLGETMINMAXPARAMETERFVPROC)(GLenum target, GLenum pname, GLfloat *params);
GLAPI PFNGLGETMINMAXPARAMETERFVPROC cppgl_glGetMinmaxParameterfv;
#define glGetMinmaxParameterfv cppgl_glGetMinmaxParameterfv
typedef void (APIENTRYP PFNGLGETMINMAXPARAMETERIVPROC)(GLenum target, GLenum pname, GLint *params);
GLAPI PFNGLGETMINMAXPARAMETERIVPROC cppgl_glGetMinmaxParameteriv;
#define glGetMinmaxParameteriv cppgl_glGetMinmaxParameteriv
typedef void (APIENTRYP PFNGLHISTOGRAMPROC)(GLenum target, GLsizei width, GLenum internalformat, GLboolean sink);
GLAPI PFNGLHISTOGRAMPROC cppgl_glHistogram;
#define glHistogram cppgl_glHistogram
typedef void (APIENTRYP PFNGLMINMAXPROC)(GLenum target, GLenum internalformat, GLboolean sink);
GLAPI PFNGLMINMAXPROC cppgl_glMinmax;
#define glMinmax cppgl_glMinmax
typedef void (APIENTRYP PFNGLRESETHISTOGRAMPROC)(GLenum target);
GLAPI PFNGLRESETHISTOGRAMPROC cppgl_glResetHistogram;
#define glResetHistogram cppgl_glResetHistogram
typedef void (APIENTRYP PFNGLRESETMINMAXPROC)(GLenum target);
GLAPI PFNGLRESETMINMAXPROC cppgl_glResetMinmax;
#define glResetMinmax cppgl_glResetMinmax
#endif
#ifndef GL_ARB_indirect_parameters
#define GL_ARB_indirect_parameters 1
GLAPI int CPPGL_GL_ARB_indirect_parameters;
typedef void (APIENTRYP PFNGLMULTIDRAWARRAYSINDIRECTCOUNTARBPROC)(GLenum mode, GLintptr indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
GLAPI PFNGLMULTIDRAWARRAYSINDIRECTCOUNTARBPROC cppgl_glMultiDrawArraysIndirectCountARB;
#define glMultiDrawArraysIndirectCountARB cppgl_glMultiDrawArraysIndirectCountARB
typedef void (APIENTRYP PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTARBPROC)(GLenum mode, GLenum type, GLintptr indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
GLAPI PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTARBPROC cppgl_glMultiDrawElementsIndirectCountARB;
#define glMultiDrawElementsIndirectCountARB cppgl_glMultiDrawElementsIndirectCountARB
#endif
#ifndef GL_ARB_instanced_arrays
#define GL_ARB_instanced_arrays 1
GLAPI int CPPGL_GL_ARB_instanced_arrays;
typedef void (APIENTRYP PFNGLVERTEXATTRIBDIVISORARBPROC)(GLuint index, GLuint divisor);
GLAPI PFNGLVERTEXATTRIBDIVISORARBPROC cppgl_glVertexAttribDivisorARB;
#define glVertexAttribDivisorARB cppgl_glVertexAttribDivisorARB
#endif
#ifndef GL_ARB_internalformat_query
#define GL_ARB_internalformat_query 1
GLAPI int CPPGL_GL_ARB_internalformat_query;
typedef void (APIENTRYP PFNGLGETINTERNALFORMATIVPROC)(GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint *params);
GLAPI PFNGLGETINTERNALFORMATIVPROC cppgl_glGetInternalformativ;
#define glGetInternalformativ cppgl_glGetInternalformativ
#endif
#ifndef GL_ARB_internalformat_query2
#define GL_ARB_internalformat_query2 1
GLAPI int CPPGL_GL_ARB_internalformat_query2;
typedef void (APIENTRYP PFNGLGETINTERNALFORMATI64VPROC)(GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint64 *params);
GLAPI PFNGLGETINTERNALFORMATI64VPROC cppgl_glGetInternalformati64v;
#define glGetInternalformati64v cppgl_glGetInternalformati64v
#endif
#ifndef GL_ARB_invalidate_subdata
#define GL_ARB_invalidate_subdata 1
GLAPI int CPPGL_GL_ARB_invalidate_subdata;
typedef void (APIENTRYP PFNGLINVALIDATETEXSUBIMAGEPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth);
GLAPI PFNGLINVALIDATETEXSUBIMAGEPROC cppgl_glInvalidateTexSubImage;
#define glInvalidateTexSubImage cppgl_glInvalidateTexSubImage
typedef void (APIENTRYP PFNGLINVALIDATETEXIMAGEPROC)(GLuint texture, GLint level);
GLAPI PFNGLINVALIDATETEXIMAGEPROC cppgl_glInvalidateTexImage;
#define glInvalidateTexImage cppgl_glInvalidateTexImage
typedef void (APIENTRYP PFNGLINVALIDATEBUFFERSUBDATAPROC)(GLuint buffer, GLintptr offset, GLsizeiptr length);
GLAPI PFNGLINVALIDATEBUFFERSUBDATAPROC cppgl_glInvalidateBufferSubData;
#define glInvalidateBufferSubData cppgl_glInvalidateBufferSubData
typedef void (APIENTRYP PFNGLINVALIDATEBUFFERDATAPROC)(GLuint buffer);
GLAPI PFNGLINVALIDATEBUFFERDATAPROC cppgl_glInvalidateBufferData;
#define glInvalidateBufferData cppgl_glInvalidateBufferData
typedef void (APIENTRYP PFNGLINVALIDATEFRAMEBUFFERPROC)(GLenum target, GLsizei numAttachments, const GLenum *attachments);
GLAPI PFNGLINVALIDATEFRAMEBUFFERPROC cppgl_glInvalidateFramebuffer;
#define glInvalidateFramebuffer cppgl_glInvalidateFramebuffer
typedef void (APIENTRYP PFNGLINVALIDATESUBFRAMEBUFFERPROC)(GLenum target, GLsizei numAttachments, const GLenum *attachments, GLint x, GLint y, GLsizei width, GLsizei height);
GLAPI PFNGLINVALIDATESUBFRAMEBUFFERPROC cppgl_glInvalidateSubFramebuffer;
#define glInvalidateSubFramebuffer cppgl_glInvalidateSubFramebuffer
#endif
#ifndef GL_ARB_map_buffer_alignment
#define GL_ARB_map_buffer_alignment 1
GLAPI int CPPGL_GL_ARB_map_buffer_alignment;
#endif
#ifndef GL_ARB_map_buffer_range
#define GL_ARB_map_buffer_range 1
GLAPI int CPPGL_GL_ARB_map_buffer_range;
typedef void * (APIENTRYP PFNGLMAPBUFFERRANGEPROC)(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access);
GLAPI PFNGLMAPBUFFERRANGEPROC cppgl_glMapBufferRange;
#define glMapBufferRange cppgl_glMapBufferRange
typedef void (APIENTRYP PFNGLFLUSHMAPPEDBUFFERRANGEPROC)(GLenum target, GLintptr offset, GLsizeiptr length);
GLAPI PFNGLFLUSHMAPPEDBUFFERRANGEPROC cppgl_glFlushMappedBufferRange;
#define glFlushMappedBufferRange cppgl_glFlushMappedBufferRange
#endif
#ifndef GL_ARB_matrix_palette
#define GL_ARB_matrix_palette 1
GLAPI int CPPGL_GL_ARB_matrix_palette;
typedef void (APIENTRYP PFNGLCURRENTPALETTEMATRIXARBPROC)(GLint index);
GLAPI PFNGLCURRENTPALETTEMATRIXARBPROC cppgl_glCurrentPaletteMatrixARB;
#define glCurrentPaletteMatrixARB cppgl_glCurrentPaletteMatrixARB
typedef void (APIENTRYP PFNGLMATRIXINDEXUBVARBPROC)(GLint size, const GLubyte *indices);
GLAPI PFNGLMATRIXINDEXUBVARBPROC cppgl_glMatrixIndexubvARB;
#define glMatrixIndexubvARB cppgl_glMatrixIndexubvARB
typedef void (APIENTRYP PFNGLMATRIXINDEXUSVARBPROC)(GLint size, const GLushort *indices);
GLAPI PFNGLMATRIXINDEXUSVARBPROC cppgl_glMatrixIndexusvARB;
#define glMatrixIndexusvARB cppgl_glMatrixIndexusvARB
typedef void (APIENTRYP PFNGLMATRIXINDEXUIVARBPROC)(GLint size, const GLuint *indices);
GLAPI PFNGLMATRIXINDEXUIVARBPROC cppgl_glMatrixIndexuivARB;
#define glMatrixIndexuivARB cppgl_glMatrixIndexuivARB
typedef void (APIENTRYP PFNGLMATRIXINDEXPOINTERARBPROC)(GLint size, GLenum type, GLsizei stride, const void *pointer);
GLAPI PFNGLMATRIXINDEXPOINTERARBPROC cppgl_glMatrixIndexPointerARB;
#define glMatrixIndexPointerARB cppgl_glMatrixIndexPointerARB
#endif
#ifndef GL_ARB_multi_bind
#define GL_ARB_multi_bind 1
GLAPI int CPPGL_GL_ARB_multi_bind;
typedef void (APIENTRYP PFNGLBINDBUFFERSBASEPROC)(GLenum target, GLuint first, GLsizei count, const GLuint *buffers);
GLAPI PFNGLBINDBUFFERSBASEPROC cppgl_glBindBuffersBase;
#define glBindBuffersBase cppgl_glBindBuffersBase
typedef void (APIENTRYP PFNGLBINDBUFFERSRANGEPROC)(GLenum target, GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizeiptr *sizes);
GLAPI PFNGLBINDBUFFERSRANGEPROC cppgl_glBindBuffersRange;
#define glBindBuffersRange cppgl_glBindBuffersRange
typedef void (APIENTRYP PFNGLBINDTEXTURESPROC)(GLuint first, GLsizei count, const GLuint *textures);
GLAPI PFNGLBINDTEXTURESPROC cppgl_glBindTextures;
#define glBindTextures cppgl_glBindTextures
typedef void (APIENTRYP PFNGLBINDSAMPLERSPROC)(GLuint first, GLsizei count, const GLuint *samplers);
GLAPI PFNGLBINDSAMPLERSPROC cppgl_glBindSamplers;
#define glBindSamplers cppgl_glBindSamplers
typedef void (APIENTRYP PFNGLBINDIMAGETEXTURESPROC)(GLuint first, GLsizei count, const GLuint *textures);
GLAPI PFNGLBINDIMAGETEXTURESPROC cppgl_glBindImageTextures;
#define glBindImageTextures cppgl_glBindImageTextures
typedef void (APIENTRYP PFNGLBINDVERTEXBUFFERSPROC)(GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizei *strides);
GLAPI PFNGLBINDVERTEXBUFFERSPROC cppgl_glBindVertexBuffers;
#define glBindVertexBuffers cppgl_glBindVertexBuffers
#endif
#ifndef GL_ARB_multi_draw_indirect
#define GL_ARB_multi_draw_indirect 1
GLAPI int CPPGL_GL_ARB_multi_draw_indirect;
typedef void (APIENTRYP PFNGLMULTIDRAWARRAYSINDIRECTPROC)(GLenum mode, const void *indirect, GLsizei drawcount, GLsizei stride);
GLAPI PFNGLMULTIDRAWARRAYSINDIRECTPROC cppgl_glMultiDrawArraysIndirect;
#define glMultiDrawArraysIndirect cppgl_glMultiDrawArraysIndirect
typedef void (APIENTRYP PFNGLMULTIDRAWELEMENTSINDIRECTPROC)(GLenum mode, GLenum type, const void *indirect, GLsizei drawcount, GLsizei stride);
GLAPI PFNGLMULTIDRAWELEMENTSINDIRECTPROC cppgl_glMultiDrawElementsIndirect;
#define glMultiDrawElementsIndirect cppgl_glMultiDrawElementsIndirect
#endif
#ifndef GL_ARB_multisample
#define GL_ARB_multisample 1
GLAPI int CPPGL_GL_ARB_multisample;
typedef void (APIENTRYP PFNGLSAMPLECOVERAGEARBPROC)(GLfloat value, GLboolean invert);
GLAPI PFNGLSAMPLECOVERAGEARBPROC cppgl_glSampleCoverageARB;
#define glSampleCoverageARB cppgl_glSampleCoverageARB
#endif
#ifndef GL_ARB_multitexture
#define GL_ARB_multitexture 1
GLAPI int CPPGL_GL_ARB_multitexture;
typedef void (APIENTRYP PFNGLACTIVETEXTUREARBPROC)(GLenum texture);
GLAPI PFNGLACTIVETEXTUREARBPROC cppgl_glActiveTextureARB;
#define glActiveTextureARB cppgl_glActiveTextureARB
typedef void (APIENTRYP PFNGLCLIENTACTIVETEXTUREARBPROC)(GLenum texture);
GLAPI PFNGLCLIENTACTIVETEXTUREARBPROC cppgl_glClientActiveTextureARB;
#define glClientActiveTextureARB cppgl_glClientActiveTextureARB
typedef void (APIENTRYP PFNGLMULTITEXCOORD1DARBPROC)(GLenum target, GLdouble s);
GLAPI PFNGLMULTITEXCOORD1DARBPROC cppgl_glMultiTexCoord1dARB;
#define glMultiTexCoord1dARB cppgl_glMultiTexCoord1dARB
typedef void (APIENTRYP PFNGLMULTITEXCOORD1DVARBPROC)(GLenum target, const GLdouble *v);
GLAPI PFNGLMULTITEXCOORD1DVARBPROC cppgl_glMultiTexCoord1dvARB;
#define glMultiTexCoord1dvARB cppgl_glMultiTexCoord1dvARB
typedef void (APIENTRYP PFNGLMULTITEXCOORD1FARBPROC)(GLenum target, GLfloat s);
GLAPI PFNGLMULTITEXCOORD1FARBPROC cppgl_glMultiTexCoord1fARB;
#define glMultiTexCoord1fARB cppgl_glMultiTexCoord1fARB
typedef void (APIENTRYP PFNGLMULTITEXCOORD1FVARBPROC)(GLenum target, const GLfloat *v);
GLAPI PFNGLMULTITEXCOORD1FVARBPROC cppgl_glMultiTexCoord1fvARB;
#define glMultiTexCoord1fvARB cppgl_glMultiTexCoord1fvARB
typedef void (APIENTRYP PFNGLMULTITEXCOORD1IARBPROC)(GLenum target, GLint s);
GLAPI PFNGLMULTITEXCOORD1IARBPROC cppgl_glMultiTexCoord1iARB;
#define glMultiTexCoord1iARB cppgl_glMultiTexCoord1iARB
typedef void (APIENTRYP PFNGLMULTITEXCOORD1IVARBPROC)(GLenum target, const GLint *v);
GLAPI PFNGLMULTITEXCOORD1IVARBPROC cppgl_glMultiTexCoord1ivARB;
#define glMultiTexCoord1ivARB cppgl_glMultiTexCoord1ivARB
typedef void (APIENTRYP PFNGLMULTITEXCOORD1SARBPROC)(GLenum target, GLshort s);
GLAPI PFNGLMULTITEXCOORD1SARBPROC cppgl_glMultiTexCoord1sARB;
#define glMultiTexCoord1sARB cppgl_glMultiTexCoord1sARB
typedef void (APIENTRYP PFNGLMULTITEXCOORD1SVARBPROC)(GLenum target, const GLshort *v);
GLAPI PFNGLMULTITEXCOORD1SVARBPROC cppgl_glMultiTexCoord1svARB;
#define glMultiTexCoord1svARB cppgl_glMultiTexCoord1svARB
typedef void (APIENTRYP PFNGLMULTITEXCOORD2DARBPROC)(GLenum target, GLdouble s, GLdouble t);
GLAPI PFNGLMULTITEXCOORD2DARBPROC cppgl_glMultiTexCoord2dARB;
#define glMultiTexCoord2dARB cppgl_glMultiTexCoord2dARB
typedef void (APIENTRYP PFNGLMULTITEXCOORD2DVARBPROC)(GLenum target, const GLdouble *v);
GLAPI PFNGLMULTITEXCOORD2DVARBPROC cppgl_glMultiTexCoord2dvARB;
#define glMultiTexCoord2dvARB cppgl_glMultiTexCoord2dvARB
typedef void (APIENTRYP PFNGLMULTITEXCOORD2FARBPROC)(GLenum target, GLfloat s, GLfloat t);
GLAPI PFNGLMULTITEXCOORD2FARBPROC cppgl_glMultiTexCoord2fARB;
#define glMultiTexCoord2fARB cppgl_glMultiTexCoord2fARB
typedef void (APIENTRYP PFNGLMULTITEXCOORD2FVARBPROC)(GLenum target, const GLfloat *v);
GLAPI PFNGLMULTITEXCOORD2FVARBPROC cppgl_glMultiTexCoord2fvARB;
#define glMultiTexCoord2fvARB cppgl_glMultiTexCoord2fvARB
typedef void (APIENTRYP PFNGLMULTITEXCOORD2IARBPROC)(GLenum target, GLint s, GLint t);
GLAPI PFNGLMULTITEXCOORD2IARBPROC cppgl_glMultiTexCoord2iARB;
#define glMultiTexCoord2iARB cppgl_glMultiTexCoord2iARB
typedef void (APIENTRYP PFNGLMULTITEXCOORD2IVARBPROC)(GLenum target, const GLint *v);
GLAPI PFNGLMULTITEXCOORD2IVARBPROC cppgl_glMultiTexCoord2ivARB;
#define glMultiTexCoord2ivARB cppgl_glMultiTexCoord2ivARB
typedef void (APIENTRYP PFNGLMULTITEXCOORD2SARBPROC)(GLenum target, GLshort s, GLshort t);
GLAPI PFNGLMULTITEXCOORD2SARBPROC cppgl_glMultiTexCoord2sARB;
#define glMultiTexCoord2sARB cppgl_glMultiTexCoord2sARB
typedef void (APIENTRYP PFNGLMULTITEXCOORD2SVARBPROC)(GLenum target, const GLshort *v);
GLAPI PFNGLMULTITEXCOORD2SVARBPROC cppgl_glMultiTexCoord2svARB;
#define glMultiTexCoord2svARB cppgl_glMultiTexCoord2svARB
typedef void (APIENTRYP PFNGLMULTITEXCOORD3DARBPROC)(GLenum target, GLdouble s, GLdouble t, GLdouble r);
GLAPI PFNGLMULTITEXCOORD3DARBPROC cppgl_glMultiTexCoord3dARB;
#define glMultiTexCoord3dARB cppgl_glMultiTexCoord3dARB
typedef void (APIENTRYP PFNGLMULTITEXCOORD3DVARBPROC)(GLenum target, const GLdouble *v);
GLAPI PFNGLMULTITEXCOORD3DVARBPROC cppgl_glMultiTexCoord3dvARB;
#define glMultiTexCoord3dvARB cppgl_glMultiTexCoord3dvARB
typedef void (APIENTRYP PFNGLMULTITEXCOORD3FARBPROC)(GLenum target, GLfloat s, GLfloat t, GLfloat r);
GLAPI PFNGLMULTITEXCOORD3FARBPROC cppgl_glMultiTexCoord3fARB;
#define glMultiTexCoord3fARB cppgl_glMultiTexCoord3fARB
typedef void (APIENTRYP PFNGLMULTITEXCOORD3FVARBPROC)(GLenum target, const GLfloat *v);
GLAPI PFNGLMULTITEXCOORD3FVARBPROC cppgl_glMultiTexCoord3fvARB;
#define glMultiTexCoord3fvARB cppgl_glMultiTexCoord3fvARB
typedef void (APIENTRYP PFNGLMULTITEXCOORD3IARBPROC)(GLenum target, GLint s, GLint t, GLint r);
GLAPI PFNGLMULTITEXCOORD3IARBPROC cppgl_glMultiTexCoord3iARB;
#define glMultiTexCoord3iARB cppgl_glMultiTexCoord3iARB
typedef void (APIENTRYP PFNGLMULTITEXCOORD3IVARBPROC)(GLenum target, const GLint *v);
GLAPI PFNGLMULTITEXCOORD3IVARBPROC cppgl_glMultiTexCoord3ivARB;
#define glMultiTexCoord3ivARB cppgl_glMultiTexCoord3ivARB
typedef void (APIENTRYP PFNGLMULTITEXCOORD3SARBPROC)(GLenum target, GLshort s, GLshort t, GLshort r);
GLAPI PFNGLMULTITEXCOORD3SARBPROC cppgl_glMultiTexCoord3sARB;
#define glMultiTexCoord3sARB cppgl_glMultiTexCoord3sARB
typedef void (APIENTRYP PFNGLMULTITEXCOORD3SVARBPROC)(GLenum target, const GLshort *v);
GLAPI PFNGLMULTITEXCOORD3SVARBPROC cppgl_glMultiTexCoord3svARB;
#define glMultiTexCoord3svARB cppgl_glMultiTexCoord3svARB
typedef void (APIENTRYP PFNGLMULTITEXCOORD4DARBPROC)(GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q);
GLAPI PFNGLMULTITEXCOORD4DARBPROC cppgl_glMultiTexCoord4dARB;
#define glMultiTexCoord4dARB cppgl_glMultiTexCoord4dARB
typedef void (APIENTRYP PFNGLMULTITEXCOORD4DVARBPROC)(GLenum target, const GLdouble *v);
GLAPI PFNGLMULTITEXCOORD4DVARBPROC cppgl_glMultiTexCoord4dvARB;
#define glMultiTexCoord4dvARB cppgl_glMultiTexCoord4dvARB
typedef void (APIENTRYP PFNGLMULTITEXCOORD4FARBPROC)(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
GLAPI PFNGLMULTITEXCOORD4FARBPROC cppgl_glMultiTexCoord4fARB;
#define glMultiTexCoord4fARB cppgl_glMultiTexCoord4fARB
typedef void (APIENTRYP PFNGLMULTITEXCOORD4FVARBPROC)(GLenum target, const GLfloat *v);
GLAPI PFNGLMULTITEXCOORD4FVARBPROC cppgl_glMultiTexCoord4fvARB;
#define glMultiTexCoord4fvARB cppgl_glMultiTexCoord4fvARB
typedef void (APIENTRYP PFNGLMULTITEXCOORD4IARBPROC)(GLenum target, GLint s, GLint t, GLint r, GLint q);
GLAPI PFNGLMULTITEXCOORD4IARBPROC cppgl_glMultiTexCoord4iARB;
#define glMultiTexCoord4iARB cppgl_glMultiTexCoord4iARB
typedef void (APIENTRYP PFNGLMULTITEXCOORD4IVARBPROC)(GLenum target, const GLint *v);
GLAPI PFNGLMULTITEXCOORD4IVARBPROC cppgl_glMultiTexCoord4ivARB;
#define glMultiTexCoord4ivARB cppgl_glMultiTexCoord4ivARB
typedef void (APIENTRYP PFNGLMULTITEXCOORD4SARBPROC)(GLenum target, GLshort s, GLshort t, GLshort r, GLshort q);
GLAPI PFNGLMULTITEXCOORD4SARBPROC cppgl_glMultiTexCoord4sARB;
#define glMultiTexCoord4sARB cppgl_glMultiTexCoord4sARB
typedef void (APIENTRYP PFNGLMULTITEXCOORD4SVARBPROC)(GLenum target, const GLshort *v);
GLAPI PFNGLMULTITEXCOORD4SVARBPROC cppgl_glMultiTexCoord4svARB;
#define glMultiTexCoord4svARB cppgl_glMultiTexCoord4svARB
#endif
#ifndef GL_ARB_occlusion_query
#define GL_ARB_occlusion_query 1
GLAPI int CPPGL_GL_ARB_occlusion_query;
typedef void (APIENTRYP PFNGLGENQUERIESARBPROC)(GLsizei n, GLuint *ids);
GLAPI PFNGLGENQUERIESARBPROC cppgl_glGenQueriesARB;
#define glGenQueriesARB cppgl_glGenQueriesARB
typedef void (APIENTRYP PFNGLDELETEQUERIESARBPROC)(GLsizei n, const GLuint *ids);
GLAPI PFNGLDELETEQUERIESARBPROC cppgl_glDeleteQueriesARB;
#define glDeleteQueriesARB cppgl_glDeleteQueriesARB
typedef GLboolean (APIENTRYP PFNGLISQUERYARBPROC)(GLuint id);
GLAPI PFNGLISQUERYARBPROC cppgl_glIsQueryARB;
#define glIsQueryARB cppgl_glIsQueryARB
typedef void (APIENTRYP PFNGLBEGINQUERYARBPROC)(GLenum target, GLuint id);
GLAPI PFNGLBEGINQUERYARBPROC cppgl_glBeginQueryARB;
#define glBeginQueryARB cppgl_glBeginQueryARB
typedef void (APIENTRYP PFNGLENDQUERYARBPROC)(GLenum target);
GLAPI PFNGLENDQUERYARBPROC cppgl_glEndQueryARB;
#define glEndQueryARB cppgl_glEndQueryARB
typedef void (APIENTRYP PFNGLGETQUERYIVARBPROC)(GLenum target, GLenum pname, GLint *params);
GLAPI PFNGLGETQUERYIVARBPROC cppgl_glGetQueryivARB;
#define glGetQueryivARB cppgl_glGetQueryivARB
typedef void (APIENTRYP PFNGLGETQUERYOBJECTIVARBPROC)(GLuint id, GLenum pname, GLint *params);
GLAPI PFNGLGETQUERYOBJECTIVARBPROC cppgl_glGetQueryObjectivARB;
#define glGetQueryObjectivARB cppgl_glGetQueryObjectivARB
typedef void (APIENTRYP PFNGLGETQUERYOBJECTUIVARBPROC)(GLuint id, GLenum pname, GLuint *params);
GLAPI PFNGLGETQUERYOBJECTUIVARBPROC cppgl_glGetQueryObjectuivARB;
#define glGetQueryObjectuivARB cppgl_glGetQueryObjectuivARB
#endif
#ifndef GL_ARB_occlusion_query2
#define GL_ARB_occlusion_query2 1
GLAPI int CPPGL_GL_ARB_occlusion_query2;
#endif
#ifndef GL_ARB_parallel_shader_compile
#define GL_ARB_parallel_shader_compile 1
GLAPI int CPPGL_GL_ARB_parallel_shader_compile;
typedef void (APIENTRYP PFNGLMAXSHADERCOMPILERTHREADSARBPROC)(GLuint count);
GLAPI PFNGLMAXSHADERCOMPILERTHREADSARBPROC cppgl_glMaxShaderCompilerThreadsARB;
#define glMaxShaderCompilerThreadsARB cppgl_glMaxShaderCompilerThreadsARB
#endif
#ifndef GL_ARB_pipeline_statistics_query
#define GL_ARB_pipeline_statistics_query 1
GLAPI int CPPGL_GL_ARB_pipeline_statistics_query;
#endif
#ifndef GL_ARB_pixel_buffer_object
#define GL_ARB_pixel_buffer_object 1
GLAPI int CPPGL_GL_ARB_pixel_buffer_object;
#endif
#ifndef GL_ARB_point_parameters
#define GL_ARB_point_parameters 1
GLAPI int CPPGL_GL_ARB_point_parameters;
typedef void (APIENTRYP PFNGLPOINTPARAMETERFARBPROC)(GLenum pname, GLfloat param);
GLAPI PFNGLPOINTPARAMETERFARBPROC cppgl_glPointParameterfARB;
#define glPointParameterfARB cppgl_glPointParameterfARB
typedef void (APIENTRYP PFNGLPOINTPARAMETERFVARBPROC)(GLenum pname, const GLfloat *params);
GLAPI PFNGLPOINTPARAMETERFVARBPROC cppgl_glPointParameterfvARB;
#define glPointParameterfvARB cppgl_glPointParameterfvARB
#endif
#ifndef GL_ARB_point_sprite
#define GL_ARB_point_sprite 1
GLAPI int CPPGL_GL_ARB_point_sprite;
#endif
#ifndef GL_ARB_post_depth_coverage
#define GL_ARB_post_depth_coverage 1
GLAPI int CPPGL_GL_ARB_post_depth_coverage;
#endif
#ifndef GL_ARB_program_interface_query
#define GL_ARB_program_interface_query 1
GLAPI int CPPGL_GL_ARB_program_interface_query;
typedef void (APIENTRYP PFNGLGETPROGRAMINTERFACEIVPROC)(GLuint program, GLenum programInterface, GLenum pname, GLint *params);
GLAPI PFNGLGETPROGRAMINTERFACEIVPROC cppgl_glGetProgramInterfaceiv;
#define glGetProgramInterfaceiv cppgl_glGetProgramInterfaceiv
typedef GLuint (APIENTRYP PFNGLGETPROGRAMRESOURCEINDEXPROC)(GLuint program, GLenum programInterface, const GLchar *name);
GLAPI PFNGLGETPROGRAMRESOURCEINDEXPROC cppgl_glGetProgramResourceIndex;
#define glGetProgramResourceIndex cppgl_glGetProgramResourceIndex
typedef void (APIENTRYP PFNGLGETPROGRAMRESOURCENAMEPROC)(GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei *length, GLchar *name);
GLAPI PFNGLGETPROGRAMRESOURCENAMEPROC cppgl_glGetProgramResourceName;
#define glGetProgramResourceName cppgl_glGetProgramResourceName
typedef void (APIENTRYP PFNGLGETPROGRAMRESOURCEIVPROC)(GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum *props, GLsizei bufSize, GLsizei *length, GLint *params);
GLAPI PFNGLGETPROGRAMRESOURCEIVPROC cppgl_glGetProgramResourceiv;
#define glGetProgramResourceiv cppgl_glGetProgramResourceiv
typedef GLint (APIENTRYP PFNGLGETPROGRAMRESOURCELOCATIONPROC)(GLuint program, GLenum programInterface, const GLchar *name);
GLAPI PFNGLGETPROGRAMRESOURCELOCATIONPROC cppgl_glGetProgramResourceLocation;
#define glGetProgramResourceLocation cppgl_glGetProgramResourceLocation
typedef GLint (APIENTRYP PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC)(GLuint program, GLenum programInterface, const GLchar *name);
GLAPI PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC cppgl_glGetProgramResourceLocationIndex;
#define glGetProgramResourceLocationIndex cppgl_glGetProgramResourceLocationIndex
#endif
#ifndef GL_ARB_provoking_vertex
#define GL_ARB_provoking_vertex 1
GLAPI int CPPGL_GL_ARB_provoking_vertex;
typedef void (APIENTRYP PFNGLPROVOKINGVERTEXPROC)(GLenum mode);
GLAPI PFNGLPROVOKINGVERTEXPROC cppgl_glProvokingVertex;
#define glProvokingVertex cppgl_glProvokingVertex
#endif
#ifndef GL_ARB_query_buffer_object
#define GL_ARB_query_buffer_object 1
GLAPI int CPPGL_GL_ARB_query_buffer_object;
#endif
#ifndef GL_ARB_robust_buffer_access_behavior
#define GL_ARB_robust_buffer_access_behavior 1
GLAPI int CPPGL_GL_ARB_robust_buffer_access_behavior;
#endif
#ifndef GL_ARB_robustness
#define GL_ARB_robustness 1
GLAPI int CPPGL_GL_ARB_robustness;
typedef GLenum (APIENTRYP PFNGLGETGRAPHICSRESETSTATUSARBPROC)();
GLAPI PFNGLGETGRAPHICSRESETSTATUSARBPROC cppgl_glGetGraphicsResetStatusARB;
#define glGetGraphicsResetStatusARB cppgl_glGetGraphicsResetStatusARB
typedef void (APIENTRYP PFNGLGETNTEXIMAGEARBPROC)(GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void *img);
GLAPI PFNGLGETNTEXIMAGEARBPROC cppgl_glGetnTexImageARB;
#define glGetnTexImageARB cppgl_glGetnTexImageARB
typedef void (APIENTRYP PFNGLREADNPIXELSARBPROC)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void *data);
GLAPI PFNGLREADNPIXELSARBPROC cppgl_glReadnPixelsARB;
#define glReadnPixelsARB cppgl_glReadnPixelsARB
typedef void (APIENTRYP PFNGLGETNCOMPRESSEDTEXIMAGEARBPROC)(GLenum target, GLint lod, GLsizei bufSize, void *img);
GLAPI PFNGLGETNCOMPRESSEDTEXIMAGEARBPROC cppgl_glGetnCompressedTexImageARB;
#define glGetnCompressedTexImageARB cppgl_glGetnCompressedTexImageARB
typedef void (APIENTRYP PFNGLGETNUNIFORMFVARBPROC)(GLuint program, GLint location, GLsizei bufSize, GLfloat *params);
GLAPI PFNGLGETNUNIFORMFVARBPROC cppgl_glGetnUniformfvARB;
#define glGetnUniformfvARB cppgl_glGetnUniformfvARB
typedef void (APIENTRYP PFNGLGETNUNIFORMIVARBPROC)(GLuint program, GLint location, GLsizei bufSize, GLint *params);
GLAPI PFNGLGETNUNIFORMIVARBPROC cppgl_glGetnUniformivARB;
#define glGetnUniformivARB cppgl_glGetnUniformivARB
typedef void (APIENTRYP PFNGLGETNUNIFORMUIVARBPROC)(GLuint program, GLint location, GLsizei bufSize, GLuint *params);
GLAPI PFNGLGETNUNIFORMUIVARBPROC cppgl_glGetnUniformuivARB;
#define glGetnUniformuivARB cppgl_glGetnUniformuivARB
typedef void (APIENTRYP PFNGLGETNUNIFORMDVARBPROC)(GLuint program, GLint location, GLsizei bufSize, GLdouble *params);
GLAPI PFNGLGETNUNIFORMDVARBPROC cppgl_glGetnUniformdvARB;
#define glGetnUniformdvARB cppgl_glGetnUniformdvARB
typedef void (APIENTRYP PFNGLGETNMAPDVARBPROC)(GLenum target, GLenum query, GLsizei bufSize, GLdouble *v);
GLAPI PFNGLGETNMAPDVARBPROC cppgl_glGetnMapdvARB;
#define glGetnMapdvARB cppgl_glGetnMapdvARB
typedef void (APIENTRYP PFNGLGETNMAPFVARBPROC)(GLenum target, GLenum query, GLsizei bufSize, GLfloat *v);
GLAPI PFNGLGETNMAPFVARBPROC cppgl_glGetnMapfvARB;
#define glGetnMapfvARB cppgl_glGetnMapfvARB
typedef void (APIENTRYP PFNGLGETNMAPIVARBPROC)(GLenum target, GLenum query, GLsizei bufSize, GLint *v);
GLAPI PFNGLGETNMAPIVARBPROC cppgl_glGetnMapivARB;
#define glGetnMapivARB cppgl_glGetnMapivARB
typedef void (APIENTRYP PFNGLGETNPIXELMAPFVARBPROC)(GLenum map, GLsizei bufSize, GLfloat *values);
GLAPI PFNGLGETNPIXELMAPFVARBPROC cppgl_glGetnPixelMapfvARB;
#define glGetnPixelMapfvARB cppgl_glGetnPixelMapfvARB
typedef void (APIENTRYP PFNGLGETNPIXELMAPUIVARBPROC)(GLenum map, GLsizei bufSize, GLuint *values);
GLAPI PFNGLGETNPIXELMAPUIVARBPROC cppgl_glGetnPixelMapuivARB;
#define glGetnPixelMapuivARB cppgl_glGetnPixelMapuivARB
typedef void (APIENTRYP PFNGLGETNPIXELMAPUSVARBPROC)(GLenum map, GLsizei bufSize, GLushort *values);
GLAPI PFNGLGETNPIXELMAPUSVARBPROC cppgl_glGetnPixelMapusvARB;
#define glGetnPixelMapusvARB cppgl_glGetnPixelMapusvARB
typedef void (APIENTRYP PFNGLGETNPOLYGONSTIPPLEARBPROC)(GLsizei bufSize, GLubyte *pattern);
GLAPI PFNGLGETNPOLYGONSTIPPLEARBPROC cppgl_glGetnPolygonStippleARB;
#define glGetnPolygonStippleARB cppgl_glGetnPolygonStippleARB
typedef void (APIENTRYP PFNGLGETNCOLORTABLEARBPROC)(GLenum target, GLenum format, GLenum type, GLsizei bufSize, void *table);
GLAPI PFNGLGETNCOLORTABLEARBPROC cppgl_glGetnColorTableARB;
#define glGetnColorTableARB cppgl_glGetnColorTableARB
typedef void (APIENTRYP PFNGLGETNCONVOLUTIONFILTERARBPROC)(GLenum target, GLenum format, GLenum type, GLsizei bufSize, void *image);
GLAPI PFNGLGETNCONVOLUTIONFILTERARBPROC cppgl_glGetnConvolutionFilterARB;
#define glGetnConvolutionFilterARB cppgl_glGetnConvolutionFilterARB
typedef void (APIENTRYP PFNGLGETNSEPARABLEFILTERARBPROC)(GLenum target, GLenum format, GLenum type, GLsizei rowBufSize, void *row, GLsizei columnBufSize, void *column, void *span);
GLAPI PFNGLGETNSEPARABLEFILTERARBPROC cppgl_glGetnSeparableFilterARB;
#define glGetnSeparableFilterARB cppgl_glGetnSeparableFilterARB
typedef void (APIENTRYP PFNGLGETNHISTOGRAMARBPROC)(GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, void *values);
GLAPI PFNGLGETNHISTOGRAMARBPROC cppgl_glGetnHistogramARB;
#define glGetnHistogramARB cppgl_glGetnHistogramARB
typedef void (APIENTRYP PFNGLGETNMINMAXARBPROC)(GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, void *values);
GLAPI PFNGLGETNMINMAXARBPROC cppgl_glGetnMinmaxARB;
#define glGetnMinmaxARB cppgl_glGetnMinmaxARB
#endif
#ifndef GL_ARB_robustness_isolation
#define GL_ARB_robustness_isolation 1
GLAPI int CPPGL_GL_ARB_robustness_isolation;
#endif
#ifndef GL_ARB_sample_locations
#define GL_ARB_sample_locations 1
GLAPI int CPPGL_GL_ARB_sample_locations;
typedef void (APIENTRYP PFNGLFRAMEBUFFERSAMPLELOCATIONSFVARBPROC)(GLenum target, GLuint start, GLsizei count, const GLfloat *v);
GLAPI PFNGLFRAMEBUFFERSAMPLELOCATIONSFVARBPROC cppgl_glFramebufferSampleLocationsfvARB;
#define glFramebufferSampleLocationsfvARB cppgl_glFramebufferSampleLocationsfvARB
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERSAMPLELOCATIONSFVARBPROC)(GLuint framebuffer, GLuint start, GLsizei count, const GLfloat *v);
GLAPI PFNGLNAMEDFRAMEBUFFERSAMPLELOCATIONSFVARBPROC cppgl_glNamedFramebufferSampleLocationsfvARB;
#define glNamedFramebufferSampleLocationsfvARB cppgl_glNamedFramebufferSampleLocationsfvARB
typedef void (APIENTRYP PFNGLEVALUATEDEPTHVALUESARBPROC)();
GLAPI PFNGLEVALUATEDEPTHVALUESARBPROC cppgl_glEvaluateDepthValuesARB;
#define glEvaluateDepthValuesARB cppgl_glEvaluateDepthValuesARB
#endif
#ifndef GL_ARB_sample_shading
#define GL_ARB_sample_shading 1
GLAPI int CPPGL_GL_ARB_sample_shading;
typedef void (APIENTRYP PFNGLMINSAMPLESHADINGARBPROC)(GLfloat value);
GLAPI PFNGLMINSAMPLESHADINGARBPROC cppgl_glMinSampleShadingARB;
#define glMinSampleShadingARB cppgl_glMinSampleShadingARB
#endif
#ifndef GL_ARB_sampler_objects
#define GL_ARB_sampler_objects 1
GLAPI int CPPGL_GL_ARB_sampler_objects;
typedef void (APIENTRYP PFNGLGENSAMPLERSPROC)(GLsizei count, GLuint *samplers);
GLAPI PFNGLGENSAMPLERSPROC cppgl_glGenSamplers;
#define glGenSamplers cppgl_glGenSamplers
typedef void (APIENTRYP PFNGLDELETESAMPLERSPROC)(GLsizei count, const GLuint *samplers);
GLAPI PFNGLDELETESAMPLERSPROC cppgl_glDeleteSamplers;
#define glDeleteSamplers cppgl_glDeleteSamplers
typedef GLboolean (APIENTRYP PFNGLISSAMPLERPROC)(GLuint sampler);
GLAPI PFNGLISSAMPLERPROC cppgl_glIsSampler;
#define glIsSampler cppgl_glIsSampler
typedef void (APIENTRYP PFNGLBINDSAMPLERPROC)(GLuint unit, GLuint sampler);
GLAPI PFNGLBINDSAMPLERPROC cppgl_glBindSampler;
#define glBindSampler cppgl_glBindSampler
typedef void (APIENTRYP PFNGLSAMPLERPARAMETERIPROC)(GLuint sampler, GLenum pname, GLint param);
GLAPI PFNGLSAMPLERPARAMETERIPROC cppgl_glSamplerParameteri;
#define glSamplerParameteri cppgl_glSamplerParameteri
typedef void (APIENTRYP PFNGLSAMPLERPARAMETERIVPROC)(GLuint sampler, GLenum pname, const GLint *param);
GLAPI PFNGLSAMPLERPARAMETERIVPROC cppgl_glSamplerParameteriv;
#define glSamplerParameteriv cppgl_glSamplerParameteriv
typedef void (APIENTRYP PFNGLSAMPLERPARAMETERFPROC)(GLuint sampler, GLenum pname, GLfloat param);
GLAPI PFNGLSAMPLERPARAMETERFPROC cppgl_glSamplerParameterf;
#define glSamplerParameterf cppgl_glSamplerParameterf
typedef void (APIENTRYP PFNGLSAMPLERPARAMETERFVPROC)(GLuint sampler, GLenum pname, const GLfloat *param);
GLAPI PFNGLSAMPLERPARAMETERFVPROC cppgl_glSamplerParameterfv;
#define glSamplerParameterfv cppgl_glSamplerParameterfv
typedef void (APIENTRYP PFNGLSAMPLERPARAMETERIIVPROC)(GLuint sampler, GLenum pname, const GLint *param);
GLAPI PFNGLSAMPLERPARAMETERIIVPROC cppgl_glSamplerParameterIiv;
#define glSamplerParameterIiv cppgl_glSamplerParameterIiv
typedef void (APIENTRYP PFNGLSAMPLERPARAMETERIUIVPROC)(GLuint sampler, GLenum pname, const GLuint *param);
GLAPI PFNGLSAMPLERPARAMETERIUIVPROC cppgl_glSamplerParameterIuiv;
#define glSamplerParameterIuiv cppgl_glSamplerParameterIuiv
typedef void (APIENTRYP PFNGLGETSAMPLERPARAMETERIVPROC)(GLuint sampler, GLenum pname, GLint *params);
GLAPI PFNGLGETSAMPLERPARAMETERIVPROC cppgl_glGetSamplerParameteriv;
#define glGetSamplerParameteriv cppgl_glGetSamplerParameteriv
typedef void (APIENTRYP PFNGLGETSAMPLERPARAMETERIIVPROC)(GLuint sampler, GLenum pname, GLint *params);
GLAPI PFNGLGETSAMPLERPARAMETERIIVPROC cppgl_glGetSamplerParameterIiv;
#define glGetSamplerParameterIiv cppgl_glGetSamplerParameterIiv
typedef void (APIENTRYP PFNGLGETSAMPLERPARAMETERFVPROC)(GLuint sampler, GLenum pname, GLfloat *params);
GLAPI PFNGLGETSAMPLERPARAMETERFVPROC cppgl_glGetSamplerParameterfv;
#define glGetSamplerParameterfv cppgl_glGetSamplerParameterfv
typedef void (APIENTRYP PFNGLGETSAMPLERPARAMETERIUIVPROC)(GLuint sampler, GLenum pname, GLuint *params);
GLAPI PFNGLGETSAMPLERPARAMETERIUIVPROC cppgl_glGetSamplerParameterIuiv;
#define glGetSamplerParameterIuiv cppgl_glGetSamplerParameterIuiv
#endif
#ifndef GL_ARB_seamless_cube_map
#define GL_ARB_seamless_cube_map 1
GLAPI int CPPGL_GL_ARB_seamless_cube_map;
#endif
#ifndef GL_ARB_seamless_cubemap_per_texture
#define GL_ARB_seamless_cubemap_per_texture 1
GLAPI int CPPGL_GL_ARB_seamless_cubemap_per_texture;
#endif
#ifndef GL_ARB_separate_shader_objects
#define GL_ARB_separate_shader_objects 1
GLAPI int CPPGL_GL_ARB_separate_shader_objects;
typedef void (APIENTRYP PFNGLUSEPROGRAMSTAGESPROC)(GLuint pipeline, GLbitfield stages, GLuint program);
GLAPI PFNGLUSEPROGRAMSTAGESPROC cppgl_glUseProgramStages;
#define glUseProgramStages cppgl_glUseProgramStages
typedef void (APIENTRYP PFNGLACTIVESHADERPROGRAMPROC)(GLuint pipeline, GLuint program);
GLAPI PFNGLACTIVESHADERPROGRAMPROC cppgl_glActiveShaderProgram;
#define glActiveShaderProgram cppgl_glActiveShaderProgram
typedef GLuint (APIENTRYP PFNGLCREATESHADERPROGRAMVPROC)(GLenum type, GLsizei count, const GLchar *const*strings);
GLAPI PFNGLCREATESHADERPROGRAMVPROC cppgl_glCreateShaderProgramv;
#define glCreateShaderProgramv cppgl_glCreateShaderProgramv
typedef void (APIENTRYP PFNGLBINDPROGRAMPIPELINEPROC)(GLuint pipeline);
GLAPI PFNGLBINDPROGRAMPIPELINEPROC cppgl_glBindProgramPipeline;
#define glBindProgramPipeline cppgl_glBindProgramPipeline
typedef void (APIENTRYP PFNGLDELETEPROGRAMPIPELINESPROC)(GLsizei n, const GLuint *pipelines);
GLAPI PFNGLDELETEPROGRAMPIPELINESPROC cppgl_glDeleteProgramPipelines;
#define glDeleteProgramPipelines cppgl_glDeleteProgramPipelines
typedef void (APIENTRYP PFNGLGENPROGRAMPIPELINESPROC)(GLsizei n, GLuint *pipelines);
GLAPI PFNGLGENPROGRAMPIPELINESPROC cppgl_glGenProgramPipelines;
#define glGenProgramPipelines cppgl_glGenProgramPipelines
typedef GLboolean (APIENTRYP PFNGLISPROGRAMPIPELINEPROC)(GLuint pipeline);
GLAPI PFNGLISPROGRAMPIPELINEPROC cppgl_glIsProgramPipeline;
#define glIsProgramPipeline cppgl_glIsProgramPipeline
typedef void (APIENTRYP PFNGLGETPROGRAMPIPELINEIVPROC)(GLuint pipeline, GLenum pname, GLint *params);
GLAPI PFNGLGETPROGRAMPIPELINEIVPROC cppgl_glGetProgramPipelineiv;
#define glGetProgramPipelineiv cppgl_glGetProgramPipelineiv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1IPROC)(GLuint program, GLint location, GLint v0);
GLAPI PFNGLPROGRAMUNIFORM1IPROC cppgl_glProgramUniform1i;
#define glProgramUniform1i cppgl_glProgramUniform1i
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1IVPROC)(GLuint program, GLint location, GLsizei count, const GLint *value);
GLAPI PFNGLPROGRAMUNIFORM1IVPROC cppgl_glProgramUniform1iv;
#define glProgramUniform1iv cppgl_glProgramUniform1iv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1FPROC)(GLuint program, GLint location, GLfloat v0);
GLAPI PFNGLPROGRAMUNIFORM1FPROC cppgl_glProgramUniform1f;
#define glProgramUniform1f cppgl_glProgramUniform1f
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1FVPROC)(GLuint program, GLint location, GLsizei count, const GLfloat *value);
GLAPI PFNGLPROGRAMUNIFORM1FVPROC cppgl_glProgramUniform1fv;
#define glProgramUniform1fv cppgl_glProgramUniform1fv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1DPROC)(GLuint program, GLint location, GLdouble v0);
GLAPI PFNGLPROGRAMUNIFORM1DPROC cppgl_glProgramUniform1d;
#define glProgramUniform1d cppgl_glProgramUniform1d
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1DVPROC)(GLuint program, GLint location, GLsizei count, const GLdouble *value);
GLAPI PFNGLPROGRAMUNIFORM1DVPROC cppgl_glProgramUniform1dv;
#define glProgramUniform1dv cppgl_glProgramUniform1dv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1UIPROC)(GLuint program, GLint location, GLuint v0);
GLAPI PFNGLPROGRAMUNIFORM1UIPROC cppgl_glProgramUniform1ui;
#define glProgramUniform1ui cppgl_glProgramUniform1ui
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1UIVPROC)(GLuint program, GLint location, GLsizei count, const GLuint *value);
GLAPI PFNGLPROGRAMUNIFORM1UIVPROC cppgl_glProgramUniform1uiv;
#define glProgramUniform1uiv cppgl_glProgramUniform1uiv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2IPROC)(GLuint program, GLint location, GLint v0, GLint v1);
GLAPI PFNGLPROGRAMUNIFORM2IPROC cppgl_glProgramUniform2i;
#define glProgramUniform2i cppgl_glProgramUniform2i
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2IVPROC)(GLuint program, GLint location, GLsizei count, const GLint *value);
GLAPI PFNGLPROGRAMUNIFORM2IVPROC cppgl_glProgramUniform2iv;
#define glProgramUniform2iv cppgl_glProgramUniform2iv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2FPROC)(GLuint program, GLint location, GLfloat v0, GLfloat v1);
GLAPI PFNGLPROGRAMUNIFORM2FPROC cppgl_glProgramUniform2f;
#define glProgramUniform2f cppgl_glProgramUniform2f
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2FVPROC)(GLuint program, GLint location, GLsizei count, const GLfloat *value);
GLAPI PFNGLPROGRAMUNIFORM2FVPROC cppgl_glProgramUniform2fv;
#define glProgramUniform2fv cppgl_glProgramUniform2fv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2DPROC)(GLuint program, GLint location, GLdouble v0, GLdouble v1);
GLAPI PFNGLPROGRAMUNIFORM2DPROC cppgl_glProgramUniform2d;
#define glProgramUniform2d cppgl_glProgramUniform2d
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2DVPROC)(GLuint program, GLint location, GLsizei count, const GLdouble *value);
GLAPI PFNGLPROGRAMUNIFORM2DVPROC cppgl_glProgramUniform2dv;
#define glProgramUniform2dv cppgl_glProgramUniform2dv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2UIPROC)(GLuint program, GLint location, GLuint v0, GLuint v1);
GLAPI PFNGLPROGRAMUNIFORM2UIPROC cppgl_glProgramUniform2ui;
#define glProgramUniform2ui cppgl_glProgramUniform2ui
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2UIVPROC)(GLuint program, GLint location, GLsizei count, const GLuint *value);
GLAPI PFNGLPROGRAMUNIFORM2UIVPROC cppgl_glProgramUniform2uiv;
#define glProgramUniform2uiv cppgl_glProgramUniform2uiv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3IPROC)(GLuint program, GLint location, GLint v0, GLint v1, GLint v2);
GLAPI PFNGLPROGRAMUNIFORM3IPROC cppgl_glProgramUniform3i;
#define glProgramUniform3i cppgl_glProgramUniform3i
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3IVPROC)(GLuint program, GLint location, GLsizei count, const GLint *value);
GLAPI PFNGLPROGRAMUNIFORM3IVPROC cppgl_glProgramUniform3iv;
#define glProgramUniform3iv cppgl_glProgramUniform3iv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3FPROC)(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
GLAPI PFNGLPROGRAMUNIFORM3FPROC cppgl_glProgramUniform3f;
#define glProgramUniform3f cppgl_glProgramUniform3f
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3FVPROC)(GLuint program, GLint location, GLsizei count, const GLfloat *value);
GLAPI PFNGLPROGRAMUNIFORM3FVPROC cppgl_glProgramUniform3fv;
#define glProgramUniform3fv cppgl_glProgramUniform3fv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3DPROC)(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2);
GLAPI PFNGLPROGRAMUNIFORM3DPROC cppgl_glProgramUniform3d;
#define glProgramUniform3d cppgl_glProgramUniform3d
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3DVPROC)(GLuint program, GLint location, GLsizei count, const GLdouble *value);
GLAPI PFNGLPROGRAMUNIFORM3DVPROC cppgl_glProgramUniform3dv;
#define glProgramUniform3dv cppgl_glProgramUniform3dv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3UIPROC)(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2);
GLAPI PFNGLPROGRAMUNIFORM3UIPROC cppgl_glProgramUniform3ui;
#define glProgramUniform3ui cppgl_glProgramUniform3ui
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3UIVPROC)(GLuint program, GLint location, GLsizei count, const GLuint *value);
GLAPI PFNGLPROGRAMUNIFORM3UIVPROC cppgl_glProgramUniform3uiv;
#define glProgramUniform3uiv cppgl_glProgramUniform3uiv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4IPROC)(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
GLAPI PFNGLPROGRAMUNIFORM4IPROC cppgl_glProgramUniform4i;
#define glProgramUniform4i cppgl_glProgramUniform4i
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4IVPROC)(GLuint program, GLint location, GLsizei count, const GLint *value);
GLAPI PFNGLPROGRAMUNIFORM4IVPROC cppgl_glProgramUniform4iv;
#define glProgramUniform4iv cppgl_glProgramUniform4iv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4FPROC)(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
GLAPI PFNGLPROGRAMUNIFORM4FPROC cppgl_glProgramUniform4f;
#define glProgramUniform4f cppgl_glProgramUniform4f
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4FVPROC)(GLuint program, GLint location, GLsizei count, const GLfloat *value);
GLAPI PFNGLPROGRAMUNIFORM4FVPROC cppgl_glProgramUniform4fv;
#define glProgramUniform4fv cppgl_glProgramUniform4fv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4DPROC)(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3);
GLAPI PFNGLPROGRAMUNIFORM4DPROC cppgl_glProgramUniform4d;
#define glProgramUniform4d cppgl_glProgramUniform4d
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4DVPROC)(GLuint program, GLint location, GLsizei count, const GLdouble *value);
GLAPI PFNGLPROGRAMUNIFORM4DVPROC cppgl_glProgramUniform4dv;
#define glProgramUniform4dv cppgl_glProgramUniform4dv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4UIPROC)(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
GLAPI PFNGLPROGRAMUNIFORM4UIPROC cppgl_glProgramUniform4ui;
#define glProgramUniform4ui cppgl_glProgramUniform4ui
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4UIVPROC)(GLuint program, GLint location, GLsizei count, const GLuint *value);
GLAPI PFNGLPROGRAMUNIFORM4UIVPROC cppgl_glProgramUniform4uiv;
#define glProgramUniform4uiv cppgl_glProgramUniform4uiv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2FVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI PFNGLPROGRAMUNIFORMMATRIX2FVPROC cppgl_glProgramUniformMatrix2fv;
#define glProgramUniformMatrix2fv cppgl_glProgramUniformMatrix2fv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3FVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI PFNGLPROGRAMUNIFORMMATRIX3FVPROC cppgl_glProgramUniformMatrix3fv;
#define glProgramUniformMatrix3fv cppgl_glProgramUniformMatrix3fv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4FVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI PFNGLPROGRAMUNIFORMMATRIX4FVPROC cppgl_glProgramUniformMatrix4fv;
#define glProgramUniformMatrix4fv cppgl_glProgramUniformMatrix4fv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2DVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI PFNGLPROGRAMUNIFORMMATRIX2DVPROC cppgl_glProgramUniformMatrix2dv;
#define glProgramUniformMatrix2dv cppgl_glProgramUniformMatrix2dv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3DVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI PFNGLPROGRAMUNIFORMMATRIX3DVPROC cppgl_glProgramUniformMatrix3dv;
#define glProgramUniformMatrix3dv cppgl_glProgramUniformMatrix3dv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4DVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI PFNGLPROGRAMUNIFORMMATRIX4DVPROC cppgl_glProgramUniformMatrix4dv;
#define glProgramUniformMatrix4dv cppgl_glProgramUniformMatrix4dv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC cppgl_glProgramUniformMatrix2x3fv;
#define glProgramUniformMatrix2x3fv cppgl_glProgramUniformMatrix2x3fv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC cppgl_glProgramUniformMatrix3x2fv;
#define glProgramUniformMatrix3x2fv cppgl_glProgramUniformMatrix3x2fv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC cppgl_glProgramUniformMatrix2x4fv;
#define glProgramUniformMatrix2x4fv cppgl_glProgramUniformMatrix2x4fv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC cppgl_glProgramUniformMatrix4x2fv;
#define glProgramUniformMatrix4x2fv cppgl_glProgramUniformMatrix4x2fv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC cppgl_glProgramUniformMatrix3x4fv;
#define glProgramUniformMatrix3x4fv cppgl_glProgramUniformMatrix3x4fv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC cppgl_glProgramUniformMatrix4x3fv;
#define glProgramUniformMatrix4x3fv cppgl_glProgramUniformMatrix4x3fv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC cppgl_glProgramUniformMatrix2x3dv;
#define glProgramUniformMatrix2x3dv cppgl_glProgramUniformMatrix2x3dv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC cppgl_glProgramUniformMatrix3x2dv;
#define glProgramUniformMatrix3x2dv cppgl_glProgramUniformMatrix3x2dv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC cppgl_glProgramUniformMatrix2x4dv;
#define glProgramUniformMatrix2x4dv cppgl_glProgramUniformMatrix2x4dv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC cppgl_glProgramUniformMatrix4x2dv;
#define glProgramUniformMatrix4x2dv cppgl_glProgramUniformMatrix4x2dv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC cppgl_glProgramUniformMatrix3x4dv;
#define glProgramUniformMatrix3x4dv cppgl_glProgramUniformMatrix3x4dv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC cppgl_glProgramUniformMatrix4x3dv;
#define glProgramUniformMatrix4x3dv cppgl_glProgramUniformMatrix4x3dv
typedef void (APIENTRYP PFNGLVALIDATEPROGRAMPIPELINEPROC)(GLuint pipeline);
GLAPI PFNGLVALIDATEPROGRAMPIPELINEPROC cppgl_glValidateProgramPipeline;
#define glValidateProgramPipeline cppgl_glValidateProgramPipeline
typedef void (APIENTRYP PFNGLGETPROGRAMPIPELINEINFOLOGPROC)(GLuint pipeline, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
GLAPI PFNGLGETPROGRAMPIPELINEINFOLOGPROC cppgl_glGetProgramPipelineInfoLog;
#define glGetProgramPipelineInfoLog cppgl_glGetProgramPipelineInfoLog
#endif
#ifndef GL_ARB_shader_atomic_counter_ops
#define GL_ARB_shader_atomic_counter_ops 1
GLAPI int CPPGL_GL_ARB_shader_atomic_counter_ops;
#endif
#ifndef GL_ARB_shader_atomic_counters
#define GL_ARB_shader_atomic_counters 1
GLAPI int CPPGL_GL_ARB_shader_atomic_counters;
typedef void (APIENTRYP PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC)(GLuint program, GLuint bufferIndex, GLenum pname, GLint *params);
GLAPI PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC cppgl_glGetActiveAtomicCounterBufferiv;
#define glGetActiveAtomicCounterBufferiv cppgl_glGetActiveAtomicCounterBufferiv
#endif
#ifndef GL_ARB_shader_ballot
#define GL_ARB_shader_ballot 1
GLAPI int CPPGL_GL_ARB_shader_ballot;
#endif
#ifndef GL_ARB_shader_bit_encoding
#define GL_ARB_shader_bit_encoding 1
GLAPI int CPPGL_GL_ARB_shader_bit_encoding;
#endif
#ifndef GL_ARB_shader_clock
#define GL_ARB_shader_clock 1
GLAPI int CPPGL_GL_ARB_shader_clock;
#endif
#ifndef GL_ARB_shader_draw_parameters
#define GL_ARB_shader_draw_parameters 1
GLAPI int CPPGL_GL_ARB_shader_draw_parameters;
#endif
#ifndef GL_ARB_shader_group_vote
#define GL_ARB_shader_group_vote 1
GLAPI int CPPGL_GL_ARB_shader_group_vote;
#endif
#ifndef GL_ARB_shader_image_load_store
#define GL_ARB_shader_image_load_store 1
GLAPI int CPPGL_GL_ARB_shader_image_load_store;
typedef void (APIENTRYP PFNGLBINDIMAGETEXTUREPROC)(GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format);
GLAPI PFNGLBINDIMAGETEXTUREPROC cppgl_glBindImageTexture;
#define glBindImageTexture cppgl_glBindImageTexture
typedef void (APIENTRYP PFNGLMEMORYBARRIERPROC)(GLbitfield barriers);
GLAPI PFNGLMEMORYBARRIERPROC cppgl_glMemoryBarrier;
#define glMemoryBarrier cppgl_glMemoryBarrier
#endif
#ifndef GL_ARB_shader_image_size
#define GL_ARB_shader_image_size 1
GLAPI int CPPGL_GL_ARB_shader_image_size;
#endif
#ifndef GL_ARB_shader_objects
#define GL_ARB_shader_objects 1
GLAPI int CPPGL_GL_ARB_shader_objects;
typedef void (APIENTRYP PFNGLDELETEOBJECTARBPROC)(GLhandleARB obj);
GLAPI PFNGLDELETEOBJECTARBPROC cppgl_glDeleteObjectARB;
#define glDeleteObjectARB cppgl_glDeleteObjectARB
typedef GLhandleARB (APIENTRYP PFNGLGETHANDLEARBPROC)(GLenum pname);
GLAPI PFNGLGETHANDLEARBPROC cppgl_glGetHandleARB;
#define glGetHandleARB cppgl_glGetHandleARB
typedef void (APIENTRYP PFNGLDETACHOBJECTARBPROC)(GLhandleARB containerObj, GLhandleARB attachedObj);
GLAPI PFNGLDETACHOBJECTARBPROC cppgl_glDetachObjectARB;
#define glDetachObjectARB cppgl_glDetachObjectARB
typedef GLhandleARB (APIENTRYP PFNGLCREATESHADEROBJECTARBPROC)(GLenum shaderType);
GLAPI PFNGLCREATESHADEROBJECTARBPROC cppgl_glCreateShaderObjectARB;
#define glCreateShaderObjectARB cppgl_glCreateShaderObjectARB
typedef void (APIENTRYP PFNGLSHADERSOURCEARBPROC)(GLhandleARB shaderObj, GLsizei count, const GLcharARB **string, const GLint *length);
GLAPI PFNGLSHADERSOURCEARBPROC cppgl_glShaderSourceARB;
#define glShaderSourceARB cppgl_glShaderSourceARB
typedef void (APIENTRYP PFNGLCOMPILESHADERARBPROC)(GLhandleARB shaderObj);
GLAPI PFNGLCOMPILESHADERARBPROC cppgl_glCompileShaderARB;
#define glCompileShaderARB cppgl_glCompileShaderARB
typedef GLhandleARB (APIENTRYP PFNGLCREATEPROGRAMOBJECTARBPROC)();
GLAPI PFNGLCREATEPROGRAMOBJECTARBPROC cppgl_glCreateProgramObjectARB;
#define glCreateProgramObjectARB cppgl_glCreateProgramObjectARB
typedef void (APIENTRYP PFNGLATTACHOBJECTARBPROC)(GLhandleARB containerObj, GLhandleARB obj);
GLAPI PFNGLATTACHOBJECTARBPROC cppgl_glAttachObjectARB;
#define glAttachObjectARB cppgl_glAttachObjectARB
typedef void (APIENTRYP PFNGLLINKPROGRAMARBPROC)(GLhandleARB programObj);
GLAPI PFNGLLINKPROGRAMARBPROC cppgl_glLinkProgramARB;
#define glLinkProgramARB cppgl_glLinkProgramARB
typedef void (APIENTRYP PFNGLUSEPROGRAMOBJECTARBPROC)(GLhandleARB programObj);
GLAPI PFNGLUSEPROGRAMOBJECTARBPROC cppgl_glUseProgramObjectARB;
#define glUseProgramObjectARB cppgl_glUseProgramObjectARB
typedef void (APIENTRYP PFNGLVALIDATEPROGRAMARBPROC)(GLhandleARB programObj);
GLAPI PFNGLVALIDATEPROGRAMARBPROC cppgl_glValidateProgramARB;
#define glValidateProgramARB cppgl_glValidateProgramARB
typedef void (APIENTRYP PFNGLUNIFORM1FARBPROC)(GLint location, GLfloat v0);
GLAPI PFNGLUNIFORM1FARBPROC cppgl_glUniform1fARB;
#define glUniform1fARB cppgl_glUniform1fARB
typedef void (APIENTRYP PFNGLUNIFORM2FARBPROC)(GLint location, GLfloat v0, GLfloat v1);
GLAPI PFNGLUNIFORM2FARBPROC cppgl_glUniform2fARB;
#define glUniform2fARB cppgl_glUniform2fARB
typedef void (APIENTRYP PFNGLUNIFORM3FARBPROC)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
GLAPI PFNGLUNIFORM3FARBPROC cppgl_glUniform3fARB;
#define glUniform3fARB cppgl_glUniform3fARB
typedef void (APIENTRYP PFNGLUNIFORM4FARBPROC)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
GLAPI PFNGLUNIFORM4FARBPROC cppgl_glUniform4fARB;
#define glUniform4fARB cppgl_glUniform4fARB
typedef void (APIENTRYP PFNGLUNIFORM1IARBPROC)(GLint location, GLint v0);
GLAPI PFNGLUNIFORM1IARBPROC cppgl_glUniform1iARB;
#define glUniform1iARB cppgl_glUniform1iARB
typedef void (APIENTRYP PFNGLUNIFORM2IARBPROC)(GLint location, GLint v0, GLint v1);
GLAPI PFNGLUNIFORM2IARBPROC cppgl_glUniform2iARB;
#define glUniform2iARB cppgl_glUniform2iARB
typedef void (APIENTRYP PFNGLUNIFORM3IARBPROC)(GLint location, GLint v0, GLint v1, GLint v2);
GLAPI PFNGLUNIFORM3IARBPROC cppgl_glUniform3iARB;
#define glUniform3iARB cppgl_glUniform3iARB
typedef void (APIENTRYP PFNGLUNIFORM4IARBPROC)(GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
GLAPI PFNGLUNIFORM4IARBPROC cppgl_glUniform4iARB;
#define glUniform4iARB cppgl_glUniform4iARB
typedef void (APIENTRYP PFNGLUNIFORM1FVARBPROC)(GLint location, GLsizei count, const GLfloat *value);
GLAPI PFNGLUNIFORM1FVARBPROC cppgl_glUniform1fvARB;
#define glUniform1fvARB cppgl_glUniform1fvARB
typedef void (APIENTRYP PFNGLUNIFORM2FVARBPROC)(GLint location, GLsizei count, const GLfloat *value);
GLAPI PFNGLUNIFORM2FVARBPROC cppgl_glUniform2fvARB;
#define glUniform2fvARB cppgl_glUniform2fvARB
typedef void (APIENTRYP PFNGLUNIFORM3FVARBPROC)(GLint location, GLsizei count, const GLfloat *value);
GLAPI PFNGLUNIFORM3FVARBPROC cppgl_glUniform3fvARB;
#define glUniform3fvARB cppgl_glUniform3fvARB
typedef void (APIENTRYP PFNGLUNIFORM4FVARBPROC)(GLint location, GLsizei count, const GLfloat *value);
GLAPI PFNGLUNIFORM4FVARBPROC cppgl_glUniform4fvARB;
#define glUniform4fvARB cppgl_glUniform4fvARB
typedef void (APIENTRYP PFNGLUNIFORM1IVARBPROC)(GLint location, GLsizei count, const GLint *value);
GLAPI PFNGLUNIFORM1IVARBPROC cppgl_glUniform1ivARB;
#define glUniform1ivARB cppgl_glUniform1ivARB
typedef void (APIENTRYP PFNGLUNIFORM2IVARBPROC)(GLint location, GLsizei count, const GLint *value);
GLAPI PFNGLUNIFORM2IVARBPROC cppgl_glUniform2ivARB;
#define glUniform2ivARB cppgl_glUniform2ivARB
typedef void (APIENTRYP PFNGLUNIFORM3IVARBPROC)(GLint location, GLsizei count, const GLint *value);
GLAPI PFNGLUNIFORM3IVARBPROC cppgl_glUniform3ivARB;
#define glUniform3ivARB cppgl_glUniform3ivARB
typedef void (APIENTRYP PFNGLUNIFORM4IVARBPROC)(GLint location, GLsizei count, const GLint *value);
GLAPI PFNGLUNIFORM4IVARBPROC cppgl_glUniform4ivARB;
#define glUniform4ivARB cppgl_glUniform4ivARB
typedef void (APIENTRYP PFNGLUNIFORMMATRIX2FVARBPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI PFNGLUNIFORMMATRIX2FVARBPROC cppgl_glUniformMatrix2fvARB;
#define glUniformMatrix2fvARB cppgl_glUniformMatrix2fvARB
typedef void (APIENTRYP PFNGLUNIFORMMATRIX3FVARBPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI PFNGLUNIFORMMATRIX3FVARBPROC cppgl_glUniformMatrix3fvARB;
#define glUniformMatrix3fvARB cppgl_glUniformMatrix3fvARB
typedef void (APIENTRYP PFNGLUNIFORMMATRIX4FVARBPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI PFNGLUNIFORMMATRIX4FVARBPROC cppgl_glUniformMatrix4fvARB;
#define glUniformMatrix4fvARB cppgl_glUniformMatrix4fvARB
typedef void (APIENTRYP PFNGLGETOBJECTPARAMETERFVARBPROC)(GLhandleARB obj, GLenum pname, GLfloat *params);
GLAPI PFNGLGETOBJECTPARAMETERFVARBPROC cppgl_glGetObjectParameterfvARB;
#define glGetObjectParameterfvARB cppgl_glGetObjectParameterfvARB
typedef void (APIENTRYP PFNGLGETOBJECTPARAMETERIVARBPROC)(GLhandleARB obj, GLenum pname, GLint *params);
GLAPI PFNGLGETOBJECTPARAMETERIVARBPROC cppgl_glGetObjectParameterivARB;
#define glGetObjectParameterivARB cppgl_glGetObjectParameterivARB
typedef void (APIENTRYP PFNGLGETINFOLOGARBPROC)(GLhandleARB obj, GLsizei maxLength, GLsizei *length, GLcharARB *infoLog);
GLAPI PFNGLGETINFOLOGARBPROC cppgl_glGetInfoLogARB;
#define glGetInfoLogARB cppgl_glGetInfoLogARB
typedef void (APIENTRYP PFNGLGETATTACHEDOBJECTSARBPROC)(GLhandleARB containerObj, GLsizei maxCount, GLsizei *count, GLhandleARB *obj);
GLAPI PFNGLGETATTACHEDOBJECTSARBPROC cppgl_glGetAttachedObjectsARB;
#define glGetAttachedObjectsARB cppgl_glGetAttachedObjectsARB
typedef GLint (APIENTRYP PFNGLGETUNIFORMLOCATIONARBPROC)(GLhandleARB programObj, const GLcharARB *name);
GLAPI PFNGLGETUNIFORMLOCATIONARBPROC cppgl_glGetUniformLocationARB;
#define glGetUniformLocationARB cppgl_glGetUniformLocationARB
typedef void (APIENTRYP PFNGLGETACTIVEUNIFORMARBPROC)(GLhandleARB programObj, GLuint index, GLsizei maxLength, GLsizei *length, GLint *size, GLenum *type, GLcharARB *name);
GLAPI PFNGLGETACTIVEUNIFORMARBPROC cppgl_glGetActiveUniformARB;
#define glGetActiveUniformARB cppgl_glGetActiveUniformARB
typedef void (APIENTRYP PFNGLGETUNIFORMFVARBPROC)(GLhandleARB programObj, GLint location, GLfloat *params);
GLAPI PFNGLGETUNIFORMFVARBPROC cppgl_glGetUniformfvARB;
#define glGetUniformfvARB cppgl_glGetUniformfvARB
typedef void (APIENTRYP PFNGLGETUNIFORMIVARBPROC)(GLhandleARB programObj, GLint location, GLint *params);
GLAPI PFNGLGETUNIFORMIVARBPROC cppgl_glGetUniformivARB;
#define glGetUniformivARB cppgl_glGetUniformivARB
typedef void (APIENTRYP PFNGLGETSHADERSOURCEARBPROC)(GLhandleARB obj, GLsizei maxLength, GLsizei *length, GLcharARB *source);
GLAPI PFNGLGETSHADERSOURCEARBPROC cppgl_glGetShaderSourceARB;
#define glGetShaderSourceARB cppgl_glGetShaderSourceARB
#endif
#ifndef GL_ARB_shader_precision
#define GL_ARB_shader_precision 1
GLAPI int CPPGL_GL_ARB_shader_precision;
#endif
#ifndef GL_ARB_shader_stencil_export
#define GL_ARB_shader_stencil_export 1
GLAPI int CPPGL_GL_ARB_shader_stencil_export;
#endif
#ifndef GL_ARB_shader_storage_buffer_object
#define GL_ARB_shader_storage_buffer_object 1
GLAPI int CPPGL_GL_ARB_shader_storage_buffer_object;
typedef void (APIENTRYP PFNGLSHADERSTORAGEBLOCKBINDINGPROC)(GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding);
GLAPI PFNGLSHADERSTORAGEBLOCKBINDINGPROC cppgl_glShaderStorageBlockBinding;
#define glShaderStorageBlockBinding cppgl_glShaderStorageBlockBinding
#endif
#ifndef GL_ARB_shader_subroutine
#define GL_ARB_shader_subroutine 1
GLAPI int CPPGL_GL_ARB_shader_subroutine;
typedef GLint (APIENTRYP PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC)(GLuint program, GLenum shadertype, const GLchar *name);
GLAPI PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC cppgl_glGetSubroutineUniformLocation;
#define glGetSubroutineUniformLocation cppgl_glGetSubroutineUniformLocation
typedef GLuint (APIENTRYP PFNGLGETSUBROUTINEINDEXPROC)(GLuint program, GLenum shadertype, const GLchar *name);
GLAPI PFNGLGETSUBROUTINEINDEXPROC cppgl_glGetSubroutineIndex;
#define glGetSubroutineIndex cppgl_glGetSubroutineIndex
typedef void (APIENTRYP PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC)(GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint *values);
GLAPI PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC cppgl_glGetActiveSubroutineUniformiv;
#define glGetActiveSubroutineUniformiv cppgl_glGetActiveSubroutineUniformiv
typedef void (APIENTRYP PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC)(GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei *length, GLchar *name);
GLAPI PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC cppgl_glGetActiveSubroutineUniformName;
#define glGetActiveSubroutineUniformName cppgl_glGetActiveSubroutineUniformName
typedef void (APIENTRYP PFNGLGETACTIVESUBROUTINENAMEPROC)(GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei *length, GLchar *name);
GLAPI PFNGLGETACTIVESUBROUTINENAMEPROC cppgl_glGetActiveSubroutineName;
#define glGetActiveSubroutineName cppgl_glGetActiveSubroutineName
typedef void (APIENTRYP PFNGLUNIFORMSUBROUTINESUIVPROC)(GLenum shadertype, GLsizei count, const GLuint *indices);
GLAPI PFNGLUNIFORMSUBROUTINESUIVPROC cppgl_glUniformSubroutinesuiv;
#define glUniformSubroutinesuiv cppgl_glUniformSubroutinesuiv
typedef void (APIENTRYP PFNGLGETUNIFORMSUBROUTINEUIVPROC)(GLenum shadertype, GLint location, GLuint *params);
GLAPI PFNGLGETUNIFORMSUBROUTINEUIVPROC cppgl_glGetUniformSubroutineuiv;
#define glGetUniformSubroutineuiv cppgl_glGetUniformSubroutineuiv
typedef void (APIENTRYP PFNGLGETPROGRAMSTAGEIVPROC)(GLuint program, GLenum shadertype, GLenum pname, GLint *values);
GLAPI PFNGLGETPROGRAMSTAGEIVPROC cppgl_glGetProgramStageiv;
#define glGetProgramStageiv cppgl_glGetProgramStageiv
#endif
#ifndef GL_ARB_shader_texture_image_samples
#define GL_ARB_shader_texture_image_samples 1
GLAPI int CPPGL_GL_ARB_shader_texture_image_samples;
#endif
#ifndef GL_ARB_shader_texture_lod
#define GL_ARB_shader_texture_lod 1
GLAPI int CPPGL_GL_ARB_shader_texture_lod;
#endif
#ifndef GL_ARB_shader_viewport_layer_array
#define GL_ARB_shader_viewport_layer_array 1
GLAPI int CPPGL_GL_ARB_shader_viewport_layer_array;
#endif
#ifndef GL_ARB_shading_language_100
#define GL_ARB_shading_language_100 1
GLAPI int CPPGL_GL_ARB_shading_language_100;
#endif
#ifndef GL_ARB_shading_language_420pack
#define GL_ARB_shading_language_420pack 1
GLAPI int CPPGL_GL_ARB_shading_language_420pack;
#endif
#ifndef GL_ARB_shading_language_include
#define GL_ARB_shading_language_include 1
GLAPI int CPPGL_GL_ARB_shading_language_include;
typedef void (APIENTRYP PFNGLNAMEDSTRINGARBPROC)(GLenum type, GLint namelen, const GLchar *name, GLint stringlen, const GLchar *string);
GLAPI PFNGLNAMEDSTRINGARBPROC cppgl_glNamedStringARB;
#define glNamedStringARB cppgl_glNamedStringARB
typedef void (APIENTRYP PFNGLDELETENAMEDSTRINGARBPROC)(GLint namelen, const GLchar *name);
GLAPI PFNGLDELETENAMEDSTRINGARBPROC cppgl_glDeleteNamedStringARB;
#define glDeleteNamedStringARB cppgl_glDeleteNamedStringARB
typedef void (APIENTRYP PFNGLCOMPILESHADERINCLUDEARBPROC)(GLuint shader, GLsizei count, const GLchar *const*path, const GLint *length);
GLAPI PFNGLCOMPILESHADERINCLUDEARBPROC cppgl_glCompileShaderIncludeARB;
#define glCompileShaderIncludeARB cppgl_glCompileShaderIncludeARB
typedef GLboolean (APIENTRYP PFNGLISNAMEDSTRINGARBPROC)(GLint namelen, const GLchar *name);
GLAPI PFNGLISNAMEDSTRINGARBPROC cppgl_glIsNamedStringARB;
#define glIsNamedStringARB cppgl_glIsNamedStringARB
typedef void (APIENTRYP PFNGLGETNAMEDSTRINGARBPROC)(GLint namelen, const GLchar *name, GLsizei bufSize, GLint *stringlen, GLchar *string);
GLAPI PFNGLGETNAMEDSTRINGARBPROC cppgl_glGetNamedStringARB;
#define glGetNamedStringARB cppgl_glGetNamedStringARB
typedef void (APIENTRYP PFNGLGETNAMEDSTRINGIVARBPROC)(GLint namelen, const GLchar *name, GLenum pname, GLint *params);
GLAPI PFNGLGETNAMEDSTRINGIVARBPROC cppgl_glGetNamedStringivARB;
#define glGetNamedStringivARB cppgl_glGetNamedStringivARB
#endif
#ifndef GL_ARB_shading_language_packing
#define GL_ARB_shading_language_packing 1
GLAPI int CPPGL_GL_ARB_shading_language_packing;
#endif
#ifndef GL_ARB_shadow
#define GL_ARB_shadow 1
GLAPI int CPPGL_GL_ARB_shadow;
#endif
#ifndef GL_ARB_shadow_ambient
#define GL_ARB_shadow_ambient 1
GLAPI int CPPGL_GL_ARB_shadow_ambient;
#endif
#ifndef GL_ARB_sparse_buffer
#define GL_ARB_sparse_buffer 1
GLAPI int CPPGL_GL_ARB_sparse_buffer;
typedef void (APIENTRYP PFNGLBUFFERPAGECOMMITMENTARBPROC)(GLenum target, GLintptr offset, GLsizeiptr size, GLboolean commit);
GLAPI PFNGLBUFFERPAGECOMMITMENTARBPROC cppgl_glBufferPageCommitmentARB;
#define glBufferPageCommitmentARB cppgl_glBufferPageCommitmentARB
typedef void (APIENTRYP PFNGLNAMEDBUFFERPAGECOMMITMENTEXTPROC)(GLuint buffer, GLintptr offset, GLsizeiptr size, GLboolean commit);
GLAPI PFNGLNAMEDBUFFERPAGECOMMITMENTEXTPROC cppgl_glNamedBufferPageCommitmentEXT;
#define glNamedBufferPageCommitmentEXT cppgl_glNamedBufferPageCommitmentEXT
typedef void (APIENTRYP PFNGLNAMEDBUFFERPAGECOMMITMENTARBPROC)(GLuint buffer, GLintptr offset, GLsizeiptr size, GLboolean commit);
GLAPI PFNGLNAMEDBUFFERPAGECOMMITMENTARBPROC cppgl_glNamedBufferPageCommitmentARB;
#define glNamedBufferPageCommitmentARB cppgl_glNamedBufferPageCommitmentARB
#endif
#ifndef GL_ARB_sparse_texture
#define GL_ARB_sparse_texture 1
GLAPI int CPPGL_GL_ARB_sparse_texture;
typedef void (APIENTRYP PFNGLTEXPAGECOMMITMENTARBPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLboolean commit);
GLAPI PFNGLTEXPAGECOMMITMENTARBPROC cppgl_glTexPageCommitmentARB;
#define glTexPageCommitmentARB cppgl_glTexPageCommitmentARB
#endif
#ifndef GL_ARB_sparse_texture2
#define GL_ARB_sparse_texture2 1
GLAPI int CPPGL_GL_ARB_sparse_texture2;
#endif
#ifndef GL_ARB_sparse_texture_clamp
#define GL_ARB_sparse_texture_clamp 1
GLAPI int CPPGL_GL_ARB_sparse_texture_clamp;
#endif
#ifndef GL_ARB_stencil_texturing
#define GL_ARB_stencil_texturing 1
GLAPI int CPPGL_GL_ARB_stencil_texturing;
#endif
#ifndef GL_ARB_sync
#define GL_ARB_sync 1
GLAPI int CPPGL_GL_ARB_sync;
typedef GLsync (APIENTRYP PFNGLFENCESYNCPROC)(GLenum condition, GLbitfield flags);
GLAPI PFNGLFENCESYNCPROC cppgl_glFenceSync;
#define glFenceSync cppgl_glFenceSync
typedef GLboolean (APIENTRYP PFNGLISSYNCPROC)(GLsync sync);
GLAPI PFNGLISSYNCPROC cppgl_glIsSync;
#define glIsSync cppgl_glIsSync
typedef void (APIENTRYP PFNGLDELETESYNCPROC)(GLsync sync);
GLAPI PFNGLDELETESYNCPROC cppgl_glDeleteSync;
#define glDeleteSync cppgl_glDeleteSync
typedef GLenum (APIENTRYP PFNGLCLIENTWAITSYNCPROC)(GLsync sync, GLbitfield flags, GLuint64 timeout);
GLAPI PFNGLCLIENTWAITSYNCPROC cppgl_glClientWaitSync;
#define glClientWaitSync cppgl_glClientWaitSync
typedef void (APIENTRYP PFNGLWAITSYNCPROC)(GLsync sync, GLbitfield flags, GLuint64 timeout);
GLAPI PFNGLWAITSYNCPROC cppgl_glWaitSync;
#define glWaitSync cppgl_glWaitSync
typedef void (APIENTRYP PFNGLGETINTEGER64VPROC)(GLenum pname, GLint64 *data);
GLAPI PFNGLGETINTEGER64VPROC cppgl_glGetInteger64v;
#define glGetInteger64v cppgl_glGetInteger64v
typedef void (APIENTRYP PFNGLGETSYNCIVPROC)(GLsync sync, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *values);
GLAPI PFNGLGETSYNCIVPROC cppgl_glGetSynciv;
#define glGetSynciv cppgl_glGetSynciv
#endif
#ifndef GL_ARB_tessellation_shader
#define GL_ARB_tessellation_shader 1
GLAPI int CPPGL_GL_ARB_tessellation_shader;
typedef void (APIENTRYP PFNGLPATCHPARAMETERIPROC)(GLenum pname, GLint value);
GLAPI PFNGLPATCHPARAMETERIPROC cppgl_glPatchParameteri;
#define glPatchParameteri cppgl_glPatchParameteri
typedef void (APIENTRYP PFNGLPATCHPARAMETERFVPROC)(GLenum pname, const GLfloat *values);
GLAPI PFNGLPATCHPARAMETERFVPROC cppgl_glPatchParameterfv;
#define glPatchParameterfv cppgl_glPatchParameterfv
#endif
#ifndef GL_ARB_texture_barrier
#define GL_ARB_texture_barrier 1
GLAPI int CPPGL_GL_ARB_texture_barrier;
typedef void (APIENTRYP PFNGLTEXTUREBARRIERPROC)();
GLAPI PFNGLTEXTUREBARRIERPROC cppgl_glTextureBarrier;
#define glTextureBarrier cppgl_glTextureBarrier
#endif
#ifndef GL_ARB_texture_border_clamp
#define GL_ARB_texture_border_clamp 1
GLAPI int CPPGL_GL_ARB_texture_border_clamp;
#endif
#ifndef GL_ARB_texture_buffer_object
#define GL_ARB_texture_buffer_object 1
GLAPI int CPPGL_GL_ARB_texture_buffer_object;
typedef void (APIENTRYP PFNGLTEXBUFFERARBPROC)(GLenum target, GLenum internalformat, GLuint buffer);
GLAPI PFNGLTEXBUFFERARBPROC cppgl_glTexBufferARB;
#define glTexBufferARB cppgl_glTexBufferARB
#endif
#ifndef GL_ARB_texture_buffer_object_rgb32
#define GL_ARB_texture_buffer_object_rgb32 1
GLAPI int CPPGL_GL_ARB_texture_buffer_object_rgb32;
#endif
#ifndef GL_ARB_texture_buffer_range
#define GL_ARB_texture_buffer_range 1
GLAPI int CPPGL_GL_ARB_texture_buffer_range;
typedef void (APIENTRYP PFNGLTEXBUFFERRANGEPROC)(GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
GLAPI PFNGLTEXBUFFERRANGEPROC cppgl_glTexBufferRange;
#define glTexBufferRange cppgl_glTexBufferRange
#endif
#ifndef GL_ARB_texture_compression
#define GL_ARB_texture_compression 1
GLAPI int CPPGL_GL_ARB_texture_compression;
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXIMAGE3DARBPROC)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *data);
GLAPI PFNGLCOMPRESSEDTEXIMAGE3DARBPROC cppgl_glCompressedTexImage3DARB;
#define glCompressedTexImage3DARB cppgl_glCompressedTexImage3DARB
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXIMAGE2DARBPROC)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *data);
GLAPI PFNGLCOMPRESSEDTEXIMAGE2DARBPROC cppgl_glCompressedTexImage2DARB;
#define glCompressedTexImage2DARB cppgl_glCompressedTexImage2DARB
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXIMAGE1DARBPROC)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void *data);
GLAPI PFNGLCOMPRESSEDTEXIMAGE1DARBPROC cppgl_glCompressedTexImage1DARB;
#define glCompressedTexImage1DARB cppgl_glCompressedTexImage1DARB
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXSUBIMAGE3DARBPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data);
GLAPI PFNGLCOMPRESSEDTEXSUBIMAGE3DARBPROC cppgl_glCompressedTexSubImage3DARB;
#define glCompressedTexSubImage3DARB cppgl_glCompressedTexSubImage3DARB
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXSUBIMAGE2DARBPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data);
GLAPI PFNGLCOMPRESSEDTEXSUBIMAGE2DARBPROC cppgl_glCompressedTexSubImage2DARB;
#define glCompressedTexSubImage2DARB cppgl_glCompressedTexSubImage2DARB
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXSUBIMAGE1DARBPROC)(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data);
GLAPI PFNGLCOMPRESSEDTEXSUBIMAGE1DARBPROC cppgl_glCompressedTexSubImage1DARB;
#define glCompressedTexSubImage1DARB cppgl_glCompressedTexSubImage1DARB
typedef void (APIENTRYP PFNGLGETCOMPRESSEDTEXIMAGEARBPROC)(GLenum target, GLint level, void *img);
GLAPI PFNGLGETCOMPRESSEDTEXIMAGEARBPROC cppgl_glGetCompressedTexImageARB;
#define glGetCompressedTexImageARB cppgl_glGetCompressedTexImageARB
#endif
#ifndef GL_ARB_texture_compression_bptc
#define GL_ARB_texture_compression_bptc 1
GLAPI int CPPGL_GL_ARB_texture_compression_bptc;
#endif
#ifndef GL_ARB_texture_compression_rgtc
#define GL_ARB_texture_compression_rgtc 1
GLAPI int CPPGL_GL_ARB_texture_compression_rgtc;
#endif
#ifndef GL_ARB_texture_cube_map
#define GL_ARB_texture_cube_map 1
GLAPI int CPPGL_GL_ARB_texture_cube_map;
#endif
#ifndef GL_ARB_texture_cube_map_array
#define GL_ARB_texture_cube_map_array 1
GLAPI int CPPGL_GL_ARB_texture_cube_map_array;
#endif
#ifndef GL_ARB_texture_env_add
#define GL_ARB_texture_env_add 1
GLAPI int CPPGL_GL_ARB_texture_env_add;
#endif
#ifndef GL_ARB_texture_env_combine
#define GL_ARB_texture_env_combine 1
GLAPI int CPPGL_GL_ARB_texture_env_combine;
#endif
#ifndef GL_ARB_texture_env_crossbar
#define GL_ARB_texture_env_crossbar 1
GLAPI int CPPGL_GL_ARB_texture_env_crossbar;
#endif
#ifndef GL_ARB_texture_env_dot3
#define GL_ARB_texture_env_dot3 1
GLAPI int CPPGL_GL_ARB_texture_env_dot3;
#endif
#ifndef GL_ARB_texture_filter_minmax
#define GL_ARB_texture_filter_minmax 1
GLAPI int CPPGL_GL_ARB_texture_filter_minmax;
#endif
#ifndef GL_ARB_texture_float
#define GL_ARB_texture_float 1
GLAPI int CPPGL_GL_ARB_texture_float;
#endif
#ifndef GL_ARB_texture_gather
#define GL_ARB_texture_gather 1
GLAPI int CPPGL_GL_ARB_texture_gather;
#endif
#ifndef GL_ARB_texture_mirror_clamp_to_edge
#define GL_ARB_texture_mirror_clamp_to_edge 1
GLAPI int CPPGL_GL_ARB_texture_mirror_clamp_to_edge;
#endif
#ifndef GL_ARB_texture_mirrored_repeat
#define GL_ARB_texture_mirrored_repeat 1
GLAPI int CPPGL_GL_ARB_texture_mirrored_repeat;
#endif
#ifndef GL_ARB_texture_multisample
#define GL_ARB_texture_multisample 1
GLAPI int CPPGL_GL_ARB_texture_multisample;
typedef void (APIENTRYP PFNGLTEXIMAGE2DMULTISAMPLEPROC)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
GLAPI PFNGLTEXIMAGE2DMULTISAMPLEPROC cppgl_glTexImage2DMultisample;
#define glTexImage2DMultisample cppgl_glTexImage2DMultisample
typedef void (APIENTRYP PFNGLTEXIMAGE3DMULTISAMPLEPROC)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
GLAPI PFNGLTEXIMAGE3DMULTISAMPLEPROC cppgl_glTexImage3DMultisample;
#define glTexImage3DMultisample cppgl_glTexImage3DMultisample
typedef void (APIENTRYP PFNGLGETMULTISAMPLEFVPROC)(GLenum pname, GLuint index, GLfloat *val);
GLAPI PFNGLGETMULTISAMPLEFVPROC cppgl_glGetMultisamplefv;
#define glGetMultisamplefv cppgl_glGetMultisamplefv
typedef void (APIENTRYP PFNGLSAMPLEMASKIPROC)(GLuint maskNumber, GLbitfield mask);
GLAPI PFNGLSAMPLEMASKIPROC cppgl_glSampleMaski;
#define glSampleMaski cppgl_glSampleMaski
#endif
#ifndef GL_ARB_texture_non_power_of_two
#define GL_ARB_texture_non_power_of_two 1
GLAPI int CPPGL_GL_ARB_texture_non_power_of_two;
#endif
#ifndef GL_ARB_texture_query_levels
#define GL_ARB_texture_query_levels 1
GLAPI int CPPGL_GL_ARB_texture_query_levels;
#endif
#ifndef GL_ARB_texture_query_lod
#define GL_ARB_texture_query_lod 1
GLAPI int CPPGL_GL_ARB_texture_query_lod;
#endif
#ifndef GL_ARB_texture_rectangle
#define GL_ARB_texture_rectangle 1
GLAPI int CPPGL_GL_ARB_texture_rectangle;
#endif
#ifndef GL_ARB_texture_rg
#define GL_ARB_texture_rg 1
GLAPI int CPPGL_GL_ARB_texture_rg;
#endif
#ifndef GL_ARB_texture_rgb10_a2ui
#define GL_ARB_texture_rgb10_a2ui 1
GLAPI int CPPGL_GL_ARB_texture_rgb10_a2ui;
#endif
#ifndef GL_ARB_texture_stencil8
#define GL_ARB_texture_stencil8 1
GLAPI int CPPGL_GL_ARB_texture_stencil8;
#endif
#ifndef GL_ARB_texture_storage
#define GL_ARB_texture_storage 1
GLAPI int CPPGL_GL_ARB_texture_storage;
typedef void (APIENTRYP PFNGLTEXSTORAGE1DPROC)(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
GLAPI PFNGLTEXSTORAGE1DPROC cppgl_glTexStorage1D;
#define glTexStorage1D cppgl_glTexStorage1D
typedef void (APIENTRYP PFNGLTEXSTORAGE2DPROC)(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
GLAPI PFNGLTEXSTORAGE2DPROC cppgl_glTexStorage2D;
#define glTexStorage2D cppgl_glTexStorage2D
typedef void (APIENTRYP PFNGLTEXSTORAGE3DPROC)(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
GLAPI PFNGLTEXSTORAGE3DPROC cppgl_glTexStorage3D;
#define glTexStorage3D cppgl_glTexStorage3D
#endif
#ifndef GL_ARB_texture_storage_multisample
#define GL_ARB_texture_storage_multisample 1
GLAPI int CPPGL_GL_ARB_texture_storage_multisample;
typedef void (APIENTRYP PFNGLTEXSTORAGE2DMULTISAMPLEPROC)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
GLAPI PFNGLTEXSTORAGE2DMULTISAMPLEPROC cppgl_glTexStorage2DMultisample;
#define glTexStorage2DMultisample cppgl_glTexStorage2DMultisample
typedef void (APIENTRYP PFNGLTEXSTORAGE3DMULTISAMPLEPROC)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
GLAPI PFNGLTEXSTORAGE3DMULTISAMPLEPROC cppgl_glTexStorage3DMultisample;
#define glTexStorage3DMultisample cppgl_glTexStorage3DMultisample
#endif
#ifndef GL_ARB_texture_swizzle
#define GL_ARB_texture_swizzle 1
GLAPI int CPPGL_GL_ARB_texture_swizzle;
#endif
#ifndef GL_ARB_texture_view
#define GL_ARB_texture_view 1
GLAPI int CPPGL_GL_ARB_texture_view;
typedef void (APIENTRYP PFNGLTEXTUREVIEWPROC)(GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers);
GLAPI PFNGLTEXTUREVIEWPROC cppgl_glTextureView;
#define glTextureView cppgl_glTextureView
#endif
#ifndef GL_ARB_timer_query
#define GL_ARB_timer_query 1
GLAPI int CPPGL_GL_ARB_timer_query;
typedef void (APIENTRYP PFNGLQUERYCOUNTERPROC)(GLuint id, GLenum target);
GLAPI PFNGLQUERYCOUNTERPROC cppgl_glQueryCounter;
#define glQueryCounter cppgl_glQueryCounter
typedef void (APIENTRYP PFNGLGETQUERYOBJECTI64VPROC)(GLuint id, GLenum pname, GLint64 *params);
GLAPI PFNGLGETQUERYOBJECTI64VPROC cppgl_glGetQueryObjecti64v;
#define glGetQueryObjecti64v cppgl_glGetQueryObjecti64v
typedef void (APIENTRYP PFNGLGETQUERYOBJECTUI64VPROC)(GLuint id, GLenum pname, GLuint64 *params);
GLAPI PFNGLGETQUERYOBJECTUI64VPROC cppgl_glGetQueryObjectui64v;
#define glGetQueryObjectui64v cppgl_glGetQueryObjectui64v
#endif
#ifndef GL_ARB_transform_feedback2
#define GL_ARB_transform_feedback2 1
GLAPI int CPPGL_GL_ARB_transform_feedback2;
typedef void (APIENTRYP PFNGLBINDTRANSFORMFEEDBACKPROC)(GLenum target, GLuint id);
GLAPI PFNGLBINDTRANSFORMFEEDBACKPROC cppgl_glBindTransformFeedback;
#define glBindTransformFeedback cppgl_glBindTransformFeedback
typedef void (APIENTRYP PFNGLDELETETRANSFORMFEEDBACKSPROC)(GLsizei n, const GLuint *ids);
GLAPI PFNGLDELETETRANSFORMFEEDBACKSPROC cppgl_glDeleteTransformFeedbacks;
#define glDeleteTransformFeedbacks cppgl_glDeleteTransformFeedbacks
typedef void (APIENTRYP PFNGLGENTRANSFORMFEEDBACKSPROC)(GLsizei n, GLuint *ids);
GLAPI PFNGLGENTRANSFORMFEEDBACKSPROC cppgl_glGenTransformFeedbacks;
#define glGenTransformFeedbacks cppgl_glGenTransformFeedbacks
typedef GLboolean (APIENTRYP PFNGLISTRANSFORMFEEDBACKPROC)(GLuint id);
GLAPI PFNGLISTRANSFORMFEEDBACKPROC cppgl_glIsTransformFeedback;
#define glIsTransformFeedback cppgl_glIsTransformFeedback
typedef void (APIENTRYP PFNGLPAUSETRANSFORMFEEDBACKPROC)();
GLAPI PFNGLPAUSETRANSFORMFEEDBACKPROC cppgl_glPauseTransformFeedback;
#define glPauseTransformFeedback cppgl_glPauseTransformFeedback
typedef void (APIENTRYP PFNGLRESUMETRANSFORMFEEDBACKPROC)();
GLAPI PFNGLRESUMETRANSFORMFEEDBACKPROC cppgl_glResumeTransformFeedback;
#define glResumeTransformFeedback cppgl_glResumeTransformFeedback
typedef void (APIENTRYP PFNGLDRAWTRANSFORMFEEDBACKPROC)(GLenum mode, GLuint id);
GLAPI PFNGLDRAWTRANSFORMFEEDBACKPROC cppgl_glDrawTransformFeedback;
#define glDrawTransformFeedback cppgl_glDrawTransformFeedback
#endif
#ifndef GL_ARB_transform_feedback3
#define GL_ARB_transform_feedback3 1
GLAPI int CPPGL_GL_ARB_transform_feedback3;
typedef void (APIENTRYP PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC)(GLenum mode, GLuint id, GLuint stream);
GLAPI PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC cppgl_glDrawTransformFeedbackStream;
#define glDrawTransformFeedbackStream cppgl_glDrawTransformFeedbackStream
typedef void (APIENTRYP PFNGLBEGINQUERYINDEXEDPROC)(GLenum target, GLuint index, GLuint id);
GLAPI PFNGLBEGINQUERYINDEXEDPROC cppgl_glBeginQueryIndexed;
#define glBeginQueryIndexed cppgl_glBeginQueryIndexed
typedef void (APIENTRYP PFNGLENDQUERYINDEXEDPROC)(GLenum target, GLuint index);
GLAPI PFNGLENDQUERYINDEXEDPROC cppgl_glEndQueryIndexed;
#define glEndQueryIndexed cppgl_glEndQueryIndexed
typedef void (APIENTRYP PFNGLGETQUERYINDEXEDIVPROC)(GLenum target, GLuint index, GLenum pname, GLint *params);
GLAPI PFNGLGETQUERYINDEXEDIVPROC cppgl_glGetQueryIndexediv;
#define glGetQueryIndexediv cppgl_glGetQueryIndexediv
#endif
#ifndef GL_ARB_transform_feedback_instanced
#define GL_ARB_transform_feedback_instanced 1
GLAPI int CPPGL_GL_ARB_transform_feedback_instanced;
typedef void (APIENTRYP PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC)(GLenum mode, GLuint id, GLsizei instancecount);
GLAPI PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC cppgl_glDrawTransformFeedbackInstanced;
#define glDrawTransformFeedbackInstanced cppgl_glDrawTransformFeedbackInstanced
typedef void (APIENTRYP PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC)(GLenum mode, GLuint id, GLuint stream, GLsizei instancecount);
GLAPI PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC cppgl_glDrawTransformFeedbackStreamInstanced;
#define glDrawTransformFeedbackStreamInstanced cppgl_glDrawTransformFeedbackStreamInstanced
#endif
#ifndef GL_ARB_transform_feedback_overflow_query
#define GL_ARB_transform_feedback_overflow_query 1
GLAPI int CPPGL_GL_ARB_transform_feedback_overflow_query;
#endif
#ifndef GL_ARB_transpose_matrix
#define GL_ARB_transpose_matrix 1
GLAPI int CPPGL_GL_ARB_transpose_matrix;
typedef void (APIENTRYP PFNGLLOADTRANSPOSEMATRIXFARBPROC)(const GLfloat *m);
GLAPI PFNGLLOADTRANSPOSEMATRIXFARBPROC cppgl_glLoadTransposeMatrixfARB;
#define glLoadTransposeMatrixfARB cppgl_glLoadTransposeMatrixfARB
typedef void (APIENTRYP PFNGLLOADTRANSPOSEMATRIXDARBPROC)(const GLdouble *m);
GLAPI PFNGLLOADTRANSPOSEMATRIXDARBPROC cppgl_glLoadTransposeMatrixdARB;
#define glLoadTransposeMatrixdARB cppgl_glLoadTransposeMatrixdARB
typedef void (APIENTRYP PFNGLMULTTRANSPOSEMATRIXFARBPROC)(const GLfloat *m);
GLAPI PFNGLMULTTRANSPOSEMATRIXFARBPROC cppgl_glMultTransposeMatrixfARB;
#define glMultTransposeMatrixfARB cppgl_glMultTransposeMatrixfARB
typedef void (APIENTRYP PFNGLMULTTRANSPOSEMATRIXDARBPROC)(const GLdouble *m);
GLAPI PFNGLMULTTRANSPOSEMATRIXDARBPROC cppgl_glMultTransposeMatrixdARB;
#define glMultTransposeMatrixdARB cppgl_glMultTransposeMatrixdARB
#endif
#ifndef GL_ARB_uniform_buffer_object
#define GL_ARB_uniform_buffer_object 1
GLAPI int CPPGL_GL_ARB_uniform_buffer_object;
typedef void (APIENTRYP PFNGLGETUNIFORMINDICESPROC)(GLuint program, GLsizei uniformCount, const GLchar *const*uniformNames, GLuint *uniformIndices);
GLAPI PFNGLGETUNIFORMINDICESPROC cppgl_glGetUniformIndices;
#define glGetUniformIndices cppgl_glGetUniformIndices
typedef void (APIENTRYP PFNGLGETACTIVEUNIFORMSIVPROC)(GLuint program, GLsizei uniformCount, const GLuint *uniformIndices, GLenum pname, GLint *params);
GLAPI PFNGLGETACTIVEUNIFORMSIVPROC cppgl_glGetActiveUniformsiv;
#define glGetActiveUniformsiv cppgl_glGetActiveUniformsiv
typedef void (APIENTRYP PFNGLGETACTIVEUNIFORMNAMEPROC)(GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformName);
GLAPI PFNGLGETACTIVEUNIFORMNAMEPROC cppgl_glGetActiveUniformName;
#define glGetActiveUniformName cppgl_glGetActiveUniformName
typedef GLuint (APIENTRYP PFNGLGETUNIFORMBLOCKINDEXPROC)(GLuint program, const GLchar *uniformBlockName);
GLAPI PFNGLGETUNIFORMBLOCKINDEXPROC cppgl_glGetUniformBlockIndex;
#define glGetUniformBlockIndex cppgl_glGetUniformBlockIndex
typedef void (APIENTRYP PFNGLGETACTIVEUNIFORMBLOCKIVPROC)(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint *params);
GLAPI PFNGLGETACTIVEUNIFORMBLOCKIVPROC cppgl_glGetActiveUniformBlockiv;
#define glGetActiveUniformBlockiv cppgl_glGetActiveUniformBlockiv
typedef void (APIENTRYP PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC)(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformBlockName);
GLAPI PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC cppgl_glGetActiveUniformBlockName;
#define glGetActiveUniformBlockName cppgl_glGetActiveUniformBlockName
typedef void (APIENTRYP PFNGLUNIFORMBLOCKBINDINGPROC)(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding);
GLAPI PFNGLUNIFORMBLOCKBINDINGPROC cppgl_glUniformBlockBinding;
#define glUniformBlockBinding cppgl_glUniformBlockBinding
typedef void (APIENTRYP PFNGLBINDBUFFERRANGEPROC)(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
GLAPI PFNGLBINDBUFFERRANGEPROC cppgl_glBindBufferRange;
#define glBindBufferRange cppgl_glBindBufferRange
typedef void (APIENTRYP PFNGLBINDBUFFERBASEPROC)(GLenum target, GLuint index, GLuint buffer);
GLAPI PFNGLBINDBUFFERBASEPROC cppgl_glBindBufferBase;
#define glBindBufferBase cppgl_glBindBufferBase
typedef void (APIENTRYP PFNGLGETINTEGERI_VPROC)(GLenum target, GLuint index, GLint *data);
GLAPI PFNGLGETINTEGERI_VPROC cppgl_glGetIntegeri_v;
#define glGetIntegeri_v cppgl_glGetIntegeri_v
#endif
#ifndef GL_ARB_vertex_array_bgra
#define GL_ARB_vertex_array_bgra 1
GLAPI int CPPGL_GL_ARB_vertex_array_bgra;
#endif
#ifndef GL_ARB_vertex_array_object
#define GL_ARB_vertex_array_object 1
GLAPI int CPPGL_GL_ARB_vertex_array_object;
typedef void (APIENTRYP PFNGLBINDVERTEXARRAYPROC)(GLuint array);
GLAPI PFNGLBINDVERTEXARRAYPROC cppgl_glBindVertexArray;
#define glBindVertexArray cppgl_glBindVertexArray
typedef void (APIENTRYP PFNGLDELETEVERTEXARRAYSPROC)(GLsizei n, const GLuint *arrays);
GLAPI PFNGLDELETEVERTEXARRAYSPROC cppgl_glDeleteVertexArrays;
#define glDeleteVertexArrays cppgl_glDeleteVertexArrays
typedef void (APIENTRYP PFNGLGENVERTEXARRAYSPROC)(GLsizei n, GLuint *arrays);
GLAPI PFNGLGENVERTEXARRAYSPROC cppgl_glGenVertexArrays;
#define glGenVertexArrays cppgl_glGenVertexArrays
typedef GLboolean (APIENTRYP PFNGLISVERTEXARRAYPROC)(GLuint array);
GLAPI PFNGLISVERTEXARRAYPROC cppgl_glIsVertexArray;
#define glIsVertexArray cppgl_glIsVertexArray
#endif
#ifndef GL_ARB_vertex_attrib_64bit
#define GL_ARB_vertex_attrib_64bit 1
GLAPI int CPPGL_GL_ARB_vertex_attrib_64bit;
typedef void (APIENTRYP PFNGLVERTEXATTRIBL1DPROC)(GLuint index, GLdouble x);
GLAPI PFNGLVERTEXATTRIBL1DPROC cppgl_glVertexAttribL1d;
#define glVertexAttribL1d cppgl_glVertexAttribL1d
typedef void (APIENTRYP PFNGLVERTEXATTRIBL2DPROC)(GLuint index, GLdouble x, GLdouble y);
GLAPI PFNGLVERTEXATTRIBL2DPROC cppgl_glVertexAttribL2d;
#define glVertexAttribL2d cppgl_glVertexAttribL2d
typedef void (APIENTRYP PFNGLVERTEXATTRIBL3DPROC)(GLuint index, GLdouble x, GLdouble y, GLdouble z);
GLAPI PFNGLVERTEXATTRIBL3DPROC cppgl_glVertexAttribL3d;
#define glVertexAttribL3d cppgl_glVertexAttribL3d
typedef void (APIENTRYP PFNGLVERTEXATTRIBL4DPROC)(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
GLAPI PFNGLVERTEXATTRIBL4DPROC cppgl_glVertexAttribL4d;
#define glVertexAttribL4d cppgl_glVertexAttribL4d
typedef void (APIENTRYP PFNGLVERTEXATTRIBL1DVPROC)(GLuint index, const GLdouble *v);
GLAPI PFNGLVERTEXATTRIBL1DVPROC cppgl_glVertexAttribL1dv;
#define glVertexAttribL1dv cppgl_glVertexAttribL1dv
typedef void (APIENTRYP PFNGLVERTEXATTRIBL2DVPROC)(GLuint index, const GLdouble *v);
GLAPI PFNGLVERTEXATTRIBL2DVPROC cppgl_glVertexAttribL2dv;
#define glVertexAttribL2dv cppgl_glVertexAttribL2dv
typedef void (APIENTRYP PFNGLVERTEXATTRIBL3DVPROC)(GLuint index, const GLdouble *v);
GLAPI PFNGLVERTEXATTRIBL3DVPROC cppgl_glVertexAttribL3dv;
#define glVertexAttribL3dv cppgl_glVertexAttribL3dv
typedef void (APIENTRYP PFNGLVERTEXATTRIBL4DVPROC)(GLuint index, const GLdouble *v);
GLAPI PFNGLVERTEXATTRIBL4DVPROC cppgl_glVertexAttribL4dv;
#define glVertexAttribL4dv cppgl_glVertexAttribL4dv
typedef void (APIENTRYP PFNGLVERTEXATTRIBLPOINTERPROC)(GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer);
GLAPI PFNGLVERTEXATTRIBLPOINTERPROC cppgl_glVertexAttribLPointer;
#define glVertexAttribLPointer cppgl_glVertexAttribLPointer
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBLDVPROC)(GLuint index, GLenum pname, GLdouble *params);
GLAPI PFNGLGETVERTEXATTRIBLDVPROC cppgl_glGetVertexAttribLdv;
#define glGetVertexAttribLdv cppgl_glGetVertexAttribLdv
#endif
#ifndef GL_ARB_vertex_attrib_binding
#define GL_ARB_vertex_attrib_binding 1
GLAPI int CPPGL_GL_ARB_vertex_attrib_binding;
typedef void (APIENTRYP PFNGLBINDVERTEXBUFFERPROC)(GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
GLAPI PFNGLBINDVERTEXBUFFERPROC cppgl_glBindVertexBuffer;
#define glBindVertexBuffer cppgl_glBindVertexBuffer
typedef void (APIENTRYP PFNGLVERTEXATTRIBFORMATPROC)(GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
GLAPI PFNGLVERTEXATTRIBFORMATPROC cppgl_glVertexAttribFormat;
#define glVertexAttribFormat cppgl_glVertexAttribFormat
typedef void (APIENTRYP PFNGLVERTEXATTRIBIFORMATPROC)(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
GLAPI PFNGLVERTEXATTRIBIFORMATPROC cppgl_glVertexAttribIFormat;
#define glVertexAttribIFormat cppgl_glVertexAttribIFormat
typedef void (APIENTRYP PFNGLVERTEXATTRIBLFORMATPROC)(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
GLAPI PFNGLVERTEXATTRIBLFORMATPROC cppgl_glVertexAttribLFormat;
#define glVertexAttribLFormat cppgl_glVertexAttribLFormat
typedef void (APIENTRYP PFNGLVERTEXATTRIBBINDINGPROC)(GLuint attribindex, GLuint bindingindex);
GLAPI PFNGLVERTEXATTRIBBINDINGPROC cppgl_glVertexAttribBinding;
#define glVertexAttribBinding cppgl_glVertexAttribBinding
typedef void (APIENTRYP PFNGLVERTEXBINDINGDIVISORPROC)(GLuint bindingindex, GLuint divisor);
GLAPI PFNGLVERTEXBINDINGDIVISORPROC cppgl_glVertexBindingDivisor;
#define glVertexBindingDivisor cppgl_glVertexBindingDivisor
#endif
#ifndef GL_ARB_vertex_blend
#define GL_ARB_vertex_blend 1
GLAPI int CPPGL_GL_ARB_vertex_blend;
typedef void (APIENTRYP PFNGLWEIGHTBVARBPROC)(GLint size, const GLbyte *weights);
GLAPI PFNGLWEIGHTBVARBPROC cppgl_glWeightbvARB;
#define glWeightbvARB cppgl_glWeightbvARB
typedef void (APIENTRYP PFNGLWEIGHTSVARBPROC)(GLint size, const GLshort *weights);
GLAPI PFNGLWEIGHTSVARBPROC cppgl_glWeightsvARB;
#define glWeightsvARB cppgl_glWeightsvARB
typedef void (APIENTRYP PFNGLWEIGHTIVARBPROC)(GLint size, const GLint *weights);
GLAPI PFNGLWEIGHTIVARBPROC cppgl_glWeightivARB;
#define glWeightivARB cppgl_glWeightivARB
typedef void (APIENTRYP PFNGLWEIGHTFVARBPROC)(GLint size, const GLfloat *weights);
GLAPI PFNGLWEIGHTFVARBPROC cppgl_glWeightfvARB;
#define glWeightfvARB cppgl_glWeightfvARB
typedef void (APIENTRYP PFNGLWEIGHTDVARBPROC)(GLint size, const GLdouble *weights);
GLAPI PFNGLWEIGHTDVARBPROC cppgl_glWeightdvARB;
#define glWeightdvARB cppgl_glWeightdvARB
typedef void (APIENTRYP PFNGLWEIGHTUBVARBPROC)(GLint size, const GLubyte *weights);
GLAPI PFNGLWEIGHTUBVARBPROC cppgl_glWeightubvARB;
#define glWeightubvARB cppgl_glWeightubvARB
typedef void (APIENTRYP PFNGLWEIGHTUSVARBPROC)(GLint size, const GLushort *weights);
GLAPI PFNGLWEIGHTUSVARBPROC cppgl_glWeightusvARB;
#define glWeightusvARB cppgl_glWeightusvARB
typedef void (APIENTRYP PFNGLWEIGHTUIVARBPROC)(GLint size, const GLuint *weights);
GLAPI PFNGLWEIGHTUIVARBPROC cppgl_glWeightuivARB;
#define glWeightuivARB cppgl_glWeightuivARB
typedef void (APIENTRYP PFNGLWEIGHTPOINTERARBPROC)(GLint size, GLenum type, GLsizei stride, const void *pointer);
GLAPI PFNGLWEIGHTPOINTERARBPROC cppgl_glWeightPointerARB;
#define glWeightPointerARB cppgl_glWeightPointerARB
typedef void (APIENTRYP PFNGLVERTEXBLENDARBPROC)(GLint count);
GLAPI PFNGLVERTEXBLENDARBPROC cppgl_glVertexBlendARB;
#define glVertexBlendARB cppgl_glVertexBlendARB
#endif
#ifndef GL_ARB_vertex_buffer_object
#define GL_ARB_vertex_buffer_object 1
GLAPI int CPPGL_GL_ARB_vertex_buffer_object;
typedef void (APIENTRYP PFNGLBINDBUFFERARBPROC)(GLenum target, GLuint buffer);
GLAPI PFNGLBINDBUFFERARBPROC cppgl_glBindBufferARB;
#define glBindBufferARB cppgl_glBindBufferARB
typedef void (APIENTRYP PFNGLDELETEBUFFERSARBPROC)(GLsizei n, const GLuint *buffers);
GLAPI PFNGLDELETEBUFFERSARBPROC cppgl_glDeleteBuffersARB;
#define glDeleteBuffersARB cppgl_glDeleteBuffersARB
typedef void (APIENTRYP PFNGLGENBUFFERSARBPROC)(GLsizei n, GLuint *buffers);
GLAPI PFNGLGENBUFFERSARBPROC cppgl_glGenBuffersARB;
#define glGenBuffersARB cppgl_glGenBuffersARB
typedef GLboolean (APIENTRYP PFNGLISBUFFERARBPROC)(GLuint buffer);
GLAPI PFNGLISBUFFERARBPROC cppgl_glIsBufferARB;
#define glIsBufferARB cppgl_glIsBufferARB
typedef void (APIENTRYP PFNGLBUFFERDATAARBPROC)(GLenum target, GLsizeiptrARB size, const void *data, GLenum usage);
GLAPI PFNGLBUFFERDATAARBPROC cppgl_glBufferDataARB;
#define glBufferDataARB cppgl_glBufferDataARB
typedef void (APIENTRYP PFNGLBUFFERSUBDATAARBPROC)(GLenum target, GLintptrARB offset, GLsizeiptrARB size, const void *data);
GLAPI PFNGLBUFFERSUBDATAARBPROC cppgl_glBufferSubDataARB;
#define glBufferSubDataARB cppgl_glBufferSubDataARB
typedef void (APIENTRYP PFNGLGETBUFFERSUBDATAARBPROC)(GLenum target, GLintptrARB offset, GLsizeiptrARB size, void *data);
GLAPI PFNGLGETBUFFERSUBDATAARBPROC cppgl_glGetBufferSubDataARB;
#define glGetBufferSubDataARB cppgl_glGetBufferSubDataARB
typedef void * (APIENTRYP PFNGLMAPBUFFERARBPROC)(GLenum target, GLenum access);
GLAPI PFNGLMAPBUFFERARBPROC cppgl_glMapBufferARB;
#define glMapBufferARB cppgl_glMapBufferARB
typedef GLboolean (APIENTRYP PFNGLUNMAPBUFFERARBPROC)(GLenum target);
GLAPI PFNGLUNMAPBUFFERARBPROC cppgl_glUnmapBufferARB;
#define glUnmapBufferARB cppgl_glUnmapBufferARB
typedef void (APIENTRYP PFNGLGETBUFFERPARAMETERIVARBPROC)(GLenum target, GLenum pname, GLint *params);
GLAPI PFNGLGETBUFFERPARAMETERIVARBPROC cppgl_glGetBufferParameterivARB;
#define glGetBufferParameterivARB cppgl_glGetBufferParameterivARB
typedef void (APIENTRYP PFNGLGETBUFFERPOINTERVARBPROC)(GLenum target, GLenum pname, void **params);
GLAPI PFNGLGETBUFFERPOINTERVARBPROC cppgl_glGetBufferPointervARB;
#define glGetBufferPointervARB cppgl_glGetBufferPointervARB
#endif
#ifndef GL_ARB_vertex_program
#define GL_ARB_vertex_program 1
GLAPI int CPPGL_GL_ARB_vertex_program;
typedef void (APIENTRYP PFNGLVERTEXATTRIB1DARBPROC)(GLuint index, GLdouble x);
GLAPI PFNGLVERTEXATTRIB1DARBPROC cppgl_glVertexAttrib1dARB;
#define glVertexAttrib1dARB cppgl_glVertexAttrib1dARB
typedef void (APIENTRYP PFNGLVERTEXATTRIB1DVARBPROC)(GLuint index, const GLdouble *v);
GLAPI PFNGLVERTEXATTRIB1DVARBPROC cppgl_glVertexAttrib1dvARB;
#define glVertexAttrib1dvARB cppgl_glVertexAttrib1dvARB
typedef void (APIENTRYP PFNGLVERTEXATTRIB1FARBPROC)(GLuint index, GLfloat x);
GLAPI PFNGLVERTEXATTRIB1FARBPROC cppgl_glVertexAttrib1fARB;
#define glVertexAttrib1fARB cppgl_glVertexAttrib1fARB
typedef void (APIENTRYP PFNGLVERTEXATTRIB1FVARBPROC)(GLuint index, const GLfloat *v);
GLAPI PFNGLVERTEXATTRIB1FVARBPROC cppgl_glVertexAttrib1fvARB;
#define glVertexAttrib1fvARB cppgl_glVertexAttrib1fvARB
typedef void (APIENTRYP PFNGLVERTEXATTRIB1SARBPROC)(GLuint index, GLshort x);
GLAPI PFNGLVERTEXATTRIB1SARBPROC cppgl_glVertexAttrib1sARB;
#define glVertexAttrib1sARB cppgl_glVertexAttrib1sARB
typedef void (APIENTRYP PFNGLVERTEXATTRIB1SVARBPROC)(GLuint index, const GLshort *v);
GLAPI PFNGLVERTEXATTRIB1SVARBPROC cppgl_glVertexAttrib1svARB;
#define glVertexAttrib1svARB cppgl_glVertexAttrib1svARB
typedef void (APIENTRYP PFNGLVERTEXATTRIB2DARBPROC)(GLuint index, GLdouble x, GLdouble y);
GLAPI PFNGLVERTEXATTRIB2DARBPROC cppgl_glVertexAttrib2dARB;
#define glVertexAttrib2dARB cppgl_glVertexAttrib2dARB
typedef void (APIENTRYP PFNGLVERTEXATTRIB2DVARBPROC)(GLuint index, const GLdouble *v);
GLAPI PFNGLVERTEXATTRIB2DVARBPROC cppgl_glVertexAttrib2dvARB;
#define glVertexAttrib2dvARB cppgl_glVertexAttrib2dvARB
typedef void (APIENTRYP PFNGLVERTEXATTRIB2FARBPROC)(GLuint index, GLfloat x, GLfloat y);
GLAPI PFNGLVERTEXATTRIB2FARBPROC cppgl_glVertexAttrib2fARB;
#define glVertexAttrib2fARB cppgl_glVertexAttrib2fARB
typedef void (APIENTRYP PFNGLVERTEXATTRIB2FVARBPROC)(GLuint index, const GLfloat *v);
GLAPI PFNGLVERTEXATTRIB2FVARBPROC cppgl_glVertexAttrib2fvARB;
#define glVertexAttrib2fvARB cppgl_glVertexAttrib2fvARB
typedef void (APIENTRYP PFNGLVERTEXATTRIB2SARBPROC)(GLuint index, GLshort x, GLshort y);
GLAPI PFNGLVERTEXATTRIB2SARBPROC cppgl_glVertexAttrib2sARB;
#define glVertexAttrib2sARB cppgl_glVertexAttrib2sARB
typedef void (APIENTRYP PFNGLVERTEXATTRIB2SVARBPROC)(GLuint index, const GLshort *v);
GLAPI PFNGLVERTEXATTRIB2SVARBPROC cppgl_glVertexAttrib2svARB;
#define glVertexAttrib2svARB cppgl_glVertexAttrib2svARB
typedef void (APIENTRYP PFNGLVERTEXATTRIB3DARBPROC)(GLuint index, GLdouble x, GLdouble y, GLdouble z);
GLAPI PFNGLVERTEXATTRIB3DARBPROC cppgl_glVertexAttrib3dARB;
#define glVertexAttrib3dARB cppgl_glVertexAttrib3dARB
typedef void (APIENTRYP PFNGLVERTEXATTRIB3DVARBPROC)(GLuint index, const GLdouble *v);
GLAPI PFNGLVERTEXATTRIB3DVARBPROC cppgl_glVertexAttrib3dvARB;
#define glVertexAttrib3dvARB cppgl_glVertexAttrib3dvARB
typedef void (APIENTRYP PFNGLVERTEXATTRIB3FARBPROC)(GLuint index, GLfloat x, GLfloat y, GLfloat z);
GLAPI PFNGLVERTEXATTRIB3FARBPROC cppgl_glVertexAttrib3fARB;
#define glVertexAttrib3fARB cppgl_glVertexAttrib3fARB
typedef void (APIENTRYP PFNGLVERTEXATTRIB3FVARBPROC)(GLuint index, const GLfloat *v);
GLAPI PFNGLVERTEXATTRIB3FVARBPROC cppgl_glVertexAttrib3fvARB;
#define glVertexAttrib3fvARB cppgl_glVertexAttrib3fvARB
typedef void (APIENTRYP PFNGLVERTEXATTRIB3SARBPROC)(GLuint index, GLshort x, GLshort y, GLshort z);
GLAPI PFNGLVERTEXATTRIB3SARBPROC cppgl_glVertexAttrib3sARB;
#define glVertexAttrib3sARB cppgl_glVertexAttrib3sARB
typedef void (APIENTRYP PFNGLVERTEXATTRIB3SVARBPROC)(GLuint index, const GLshort *v);
GLAPI PFNGLVERTEXATTRIB3SVARBPROC cppgl_glVertexAttrib3svARB;
#define glVertexAttrib3svARB cppgl_glVertexAttrib3svARB
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NBVARBPROC)(GLuint index, const GLbyte *v);
GLAPI PFNGLVERTEXATTRIB4NBVARBPROC cppgl_glVertexAttrib4NbvARB;
#define glVertexAttrib4NbvARB cppgl_glVertexAttrib4NbvARB
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NIVARBPROC)(GLuint index, const GLint *v);
GLAPI PFNGLVERTEXATTRIB4NIVARBPROC cppgl_glVertexAttrib4NivARB;
#define glVertexAttrib4NivARB cppgl_glVertexAttrib4NivARB
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NSVARBPROC)(GLuint index, const GLshort *v);
GLAPI PFNGLVERTEXATTRIB4NSVARBPROC cppgl_glVertexAttrib4NsvARB;
#define glVertexAttrib4NsvARB cppgl_glVertexAttrib4NsvARB
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NUBARBPROC)(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
GLAPI PFNGLVERTEXATTRIB4NUBARBPROC cppgl_glVertexAttrib4NubARB;
#define glVertexAttrib4NubARB cppgl_glVertexAttrib4NubARB
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NUBVARBPROC)(GLuint index, const GLubyte *v);
GLAPI PFNGLVERTEXATTRIB4NUBVARBPROC cppgl_glVertexAttrib4NubvARB;
#define glVertexAttrib4NubvARB cppgl_glVertexAttrib4NubvARB
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NUIVARBPROC)(GLuint index, const GLuint *v);
GLAPI PFNGLVERTEXATTRIB4NUIVARBPROC cppgl_glVertexAttrib4NuivARB;
#define glVertexAttrib4NuivARB cppgl_glVertexAttrib4NuivARB
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NUSVARBPROC)(GLuint index, const GLushort *v);
GLAPI PFNGLVERTEXATTRIB4NUSVARBPROC cppgl_glVertexAttrib4NusvARB;
#define glVertexAttrib4NusvARB cppgl_glVertexAttrib4NusvARB
typedef void (APIENTRYP PFNGLVERTEXATTRIB4BVARBPROC)(GLuint index, const GLbyte *v);
GLAPI PFNGLVERTEXATTRIB4BVARBPROC cppgl_glVertexAttrib4bvARB;
#define glVertexAttrib4bvARB cppgl_glVertexAttrib4bvARB
typedef void (APIENTRYP PFNGLVERTEXATTRIB4DARBPROC)(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
GLAPI PFNGLVERTEXATTRIB4DARBPROC cppgl_glVertexAttrib4dARB;
#define glVertexAttrib4dARB cppgl_glVertexAttrib4dARB
typedef void (APIENTRYP PFNGLVERTEXATTRIB4DVARBPROC)(GLuint index, const GLdouble *v);
GLAPI PFNGLVERTEXATTRIB4DVARBPROC cppgl_glVertexAttrib4dvARB;
#define glVertexAttrib4dvARB cppgl_glVertexAttrib4dvARB
typedef void (APIENTRYP PFNGLVERTEXATTRIB4FARBPROC)(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
GLAPI PFNGLVERTEXATTRIB4FARBPROC cppgl_glVertexAttrib4fARB;
#define glVertexAttrib4fARB cppgl_glVertexAttrib4fARB
typedef void (APIENTRYP PFNGLVERTEXATTRIB4FVARBPROC)(GLuint index, const GLfloat *v);
GLAPI PFNGLVERTEXATTRIB4FVARBPROC cppgl_glVertexAttrib4fvARB;
#define glVertexAttrib4fvARB cppgl_glVertexAttrib4fvARB
typedef void (APIENTRYP PFNGLVERTEXATTRIB4IVARBPROC)(GLuint index, const GLint *v);
GLAPI PFNGLVERTEXATTRIB4IVARBPROC cppgl_glVertexAttrib4ivARB;
#define glVertexAttrib4ivARB cppgl_glVertexAttrib4ivARB
typedef void (APIENTRYP PFNGLVERTEXATTRIB4SARBPROC)(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
GLAPI PFNGLVERTEXATTRIB4SARBPROC cppgl_glVertexAttrib4sARB;
#define glVertexAttrib4sARB cppgl_glVertexAttrib4sARB
typedef void (APIENTRYP PFNGLVERTEXATTRIB4SVARBPROC)(GLuint index, const GLshort *v);
GLAPI PFNGLVERTEXATTRIB4SVARBPROC cppgl_glVertexAttrib4svARB;
#define glVertexAttrib4svARB cppgl_glVertexAttrib4svARB
typedef void (APIENTRYP PFNGLVERTEXATTRIB4UBVARBPROC)(GLuint index, const GLubyte *v);
GLAPI PFNGLVERTEXATTRIB4UBVARBPROC cppgl_glVertexAttrib4ubvARB;
#define glVertexAttrib4ubvARB cppgl_glVertexAttrib4ubvARB
typedef void (APIENTRYP PFNGLVERTEXATTRIB4UIVARBPROC)(GLuint index, const GLuint *v);
GLAPI PFNGLVERTEXATTRIB4UIVARBPROC cppgl_glVertexAttrib4uivARB;
#define glVertexAttrib4uivARB cppgl_glVertexAttrib4uivARB
typedef void (APIENTRYP PFNGLVERTEXATTRIB4USVARBPROC)(GLuint index, const GLushort *v);
GLAPI PFNGLVERTEXATTRIB4USVARBPROC cppgl_glVertexAttrib4usvARB;
#define glVertexAttrib4usvARB cppgl_glVertexAttrib4usvARB
typedef void (APIENTRYP PFNGLVERTEXATTRIBPOINTERARBPROC)(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer);
GLAPI PFNGLVERTEXATTRIBPOINTERARBPROC cppgl_glVertexAttribPointerARB;
#define glVertexAttribPointerARB cppgl_glVertexAttribPointerARB
typedef void (APIENTRYP PFNGLENABLEVERTEXATTRIBARRAYARBPROC)(GLuint index);
GLAPI PFNGLENABLEVERTEXATTRIBARRAYARBPROC cppgl_glEnableVertexAttribArrayARB;
#define glEnableVertexAttribArrayARB cppgl_glEnableVertexAttribArrayARB
typedef void (APIENTRYP PFNGLDISABLEVERTEXATTRIBARRAYARBPROC)(GLuint index);
GLAPI PFNGLDISABLEVERTEXATTRIBARRAYARBPROC cppgl_glDisableVertexAttribArrayARB;
#define glDisableVertexAttribArrayARB cppgl_glDisableVertexAttribArrayARB
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBDVARBPROC)(GLuint index, GLenum pname, GLdouble *params);
GLAPI PFNGLGETVERTEXATTRIBDVARBPROC cppgl_glGetVertexAttribdvARB;
#define glGetVertexAttribdvARB cppgl_glGetVertexAttribdvARB
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBFVARBPROC)(GLuint index, GLenum pname, GLfloat *params);
GLAPI PFNGLGETVERTEXATTRIBFVARBPROC cppgl_glGetVertexAttribfvARB;
#define glGetVertexAttribfvARB cppgl_glGetVertexAttribfvARB
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBIVARBPROC)(GLuint index, GLenum pname, GLint *params);
GLAPI PFNGLGETVERTEXATTRIBIVARBPROC cppgl_glGetVertexAttribivARB;
#define glGetVertexAttribivARB cppgl_glGetVertexAttribivARB
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBPOINTERVARBPROC)(GLuint index, GLenum pname, void **pointer);
GLAPI PFNGLGETVERTEXATTRIBPOINTERVARBPROC cppgl_glGetVertexAttribPointervARB;
#define glGetVertexAttribPointervARB cppgl_glGetVertexAttribPointervARB
#endif
#ifndef GL_ARB_vertex_shader
#define GL_ARB_vertex_shader 1
GLAPI int CPPGL_GL_ARB_vertex_shader;
typedef void (APIENTRYP PFNGLBINDATTRIBLOCATIONARBPROC)(GLhandleARB programObj, GLuint index, const GLcharARB *name);
GLAPI PFNGLBINDATTRIBLOCATIONARBPROC cppgl_glBindAttribLocationARB;
#define glBindAttribLocationARB cppgl_glBindAttribLocationARB
typedef void (APIENTRYP PFNGLGETACTIVEATTRIBARBPROC)(GLhandleARB programObj, GLuint index, GLsizei maxLength, GLsizei *length, GLint *size, GLenum *type, GLcharARB *name);
GLAPI PFNGLGETACTIVEATTRIBARBPROC cppgl_glGetActiveAttribARB;
#define glGetActiveAttribARB cppgl_glGetActiveAttribARB
typedef GLint (APIENTRYP PFNGLGETATTRIBLOCATIONARBPROC)(GLhandleARB programObj, const GLcharARB *name);
GLAPI PFNGLGETATTRIBLOCATIONARBPROC cppgl_glGetAttribLocationARB;
#define glGetAttribLocationARB cppgl_glGetAttribLocationARB
#endif
#ifndef GL_ARB_vertex_type_10f_11f_11f_rev
#define GL_ARB_vertex_type_10f_11f_11f_rev 1
GLAPI int CPPGL_GL_ARB_vertex_type_10f_11f_11f_rev;
#endif
#ifndef GL_ARB_vertex_type_2_10_10_10_rev
#define GL_ARB_vertex_type_2_10_10_10_rev 1
GLAPI int CPPGL_GL_ARB_vertex_type_2_10_10_10_rev;
typedef void (APIENTRYP PFNGLVERTEXATTRIBP1UIPROC)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
GLAPI PFNGLVERTEXATTRIBP1UIPROC cppgl_glVertexAttribP1ui;
#define glVertexAttribP1ui cppgl_glVertexAttribP1ui
typedef void (APIENTRYP PFNGLVERTEXATTRIBP1UIVPROC)(GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
GLAPI PFNGLVERTEXATTRIBP1UIVPROC cppgl_glVertexAttribP1uiv;
#define glVertexAttribP1uiv cppgl_glVertexAttribP1uiv
typedef void (APIENTRYP PFNGLVERTEXATTRIBP2UIPROC)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
GLAPI PFNGLVERTEXATTRIBP2UIPROC cppgl_glVertexAttribP2ui;
#define glVertexAttribP2ui cppgl_glVertexAttribP2ui
typedef void (APIENTRYP PFNGLVERTEXATTRIBP2UIVPROC)(GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
GLAPI PFNGLVERTEXATTRIBP2UIVPROC cppgl_glVertexAttribP2uiv;
#define glVertexAttribP2uiv cppgl_glVertexAttribP2uiv
typedef void (APIENTRYP PFNGLVERTEXATTRIBP3UIPROC)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
GLAPI PFNGLVERTEXATTRIBP3UIPROC cppgl_glVertexAttribP3ui;
#define glVertexAttribP3ui cppgl_glVertexAttribP3ui
typedef void (APIENTRYP PFNGLVERTEXATTRIBP3UIVPROC)(GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
GLAPI PFNGLVERTEXATTRIBP3UIVPROC cppgl_glVertexAttribP3uiv;
#define glVertexAttribP3uiv cppgl_glVertexAttribP3uiv
typedef void (APIENTRYP PFNGLVERTEXATTRIBP4UIPROC)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
GLAPI PFNGLVERTEXATTRIBP4UIPROC cppgl_glVertexAttribP4ui;
#define glVertexAttribP4ui cppgl_glVertexAttribP4ui
typedef void (APIENTRYP PFNGLVERTEXATTRIBP4UIVPROC)(GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
GLAPI PFNGLVERTEXATTRIBP4UIVPROC cppgl_glVertexAttribP4uiv;
#define glVertexAttribP4uiv cppgl_glVertexAttribP4uiv
typedef void (APIENTRYP PFNGLVERTEXP2UIPROC)(GLenum type, GLuint value);
GLAPI PFNGLVERTEXP2UIPROC cppgl_glVertexP2ui;
#define glVertexP2ui cppgl_glVertexP2ui
typedef void (APIENTRYP PFNGLVERTEXP2UIVPROC)(GLenum type, const GLuint *value);
GLAPI PFNGLVERTEXP2UIVPROC cppgl_glVertexP2uiv;
#define glVertexP2uiv cppgl_glVertexP2uiv
typedef void (APIENTRYP PFNGLVERTEXP3UIPROC)(GLenum type, GLuint value);
GLAPI PFNGLVERTEXP3UIPROC cppgl_glVertexP3ui;
#define glVertexP3ui cppgl_glVertexP3ui
typedef void (APIENTRYP PFNGLVERTEXP3UIVPROC)(GLenum type, const GLuint *value);
GLAPI PFNGLVERTEXP3UIVPROC cppgl_glVertexP3uiv;
#define glVertexP3uiv cppgl_glVertexP3uiv
typedef void (APIENTRYP PFNGLVERTEXP4UIPROC)(GLenum type, GLuint value);
GLAPI PFNGLVERTEXP4UIPROC cppgl_glVertexP4ui;
#define glVertexP4ui cppgl_glVertexP4ui
typedef void (APIENTRYP PFNGLVERTEXP4UIVPROC)(GLenum type, const GLuint *value);
GLAPI PFNGLVERTEXP4UIVPROC cppgl_glVertexP4uiv;
#define glVertexP4uiv cppgl_glVertexP4uiv
typedef void (APIENTRYP PFNGLTEXCOORDP1UIPROC)(GLenum type, GLuint coords);
GLAPI PFNGLTEXCOORDP1UIPROC cppgl_glTexCoordP1ui;
#define glTexCoordP1ui cppgl_glTexCoordP1ui
typedef void (APIENTRYP PFNGLTEXCOORDP1UIVPROC)(GLenum type, const GLuint *coords);
GLAPI PFNGLTEXCOORDP1UIVPROC cppgl_glTexCoordP1uiv;
#define glTexCoordP1uiv cppgl_glTexCoordP1uiv
typedef void (APIENTRYP PFNGLTEXCOORDP2UIPROC)(GLenum type, GLuint coords);
GLAPI PFNGLTEXCOORDP2UIPROC cppgl_glTexCoordP2ui;
#define glTexCoordP2ui cppgl_glTexCoordP2ui
typedef void (APIENTRYP PFNGLTEXCOORDP2UIVPROC)(GLenum type, const GLuint *coords);
GLAPI PFNGLTEXCOORDP2UIVPROC cppgl_glTexCoordP2uiv;
#define glTexCoordP2uiv cppgl_glTexCoordP2uiv
typedef void (APIENTRYP PFNGLTEXCOORDP3UIPROC)(GLenum type, GLuint coords);
GLAPI PFNGLTEXCOORDP3UIPROC cppgl_glTexCoordP3ui;
#define glTexCoordP3ui cppgl_glTexCoordP3ui
typedef void (APIENTRYP PFNGLTEXCOORDP3UIVPROC)(GLenum type, const GLuint *coords);
GLAPI PFNGLTEXCOORDP3UIVPROC cppgl_glTexCoordP3uiv;
#define glTexCoordP3uiv cppgl_glTexCoordP3uiv
typedef void (APIENTRYP PFNGLTEXCOORDP4UIPROC)(GLenum type, GLuint coords);
GLAPI PFNGLTEXCOORDP4UIPROC cppgl_glTexCoordP4ui;
#define glTexCoordP4ui cppgl_glTexCoordP4ui
typedef void (APIENTRYP PFNGLTEXCOORDP4UIVPROC)(GLenum type, const GLuint *coords);
GLAPI PFNGLTEXCOORDP4UIVPROC cppgl_glTexCoordP4uiv;
#define glTexCoordP4uiv cppgl_glTexCoordP4uiv
typedef void (APIENTRYP PFNGLMULTITEXCOORDP1UIPROC)(GLenum texture, GLenum type, GLuint coords);
GLAPI PFNGLMULTITEXCOORDP1UIPROC cppgl_glMultiTexCoordP1ui;
#define glMultiTexCoordP1ui cppgl_glMultiTexCoordP1ui
typedef void (APIENTRYP PFNGLMULTITEXCOORDP1UIVPROC)(GLenum texture, GLenum type, const GLuint *coords);
GLAPI PFNGLMULTITEXCOORDP1UIVPROC cppgl_glMultiTexCoordP1uiv;
#define glMultiTexCoordP1uiv cppgl_glMultiTexCoordP1uiv
typedef void (APIENTRYP PFNGLMULTITEXCOORDP2UIPROC)(GLenum texture, GLenum type, GLuint coords);
GLAPI PFNGLMULTITEXCOORDP2UIPROC cppgl_glMultiTexCoordP2ui;
#define glMultiTexCoordP2ui cppgl_glMultiTexCoordP2ui
typedef void (APIENTRYP PFNGLMULTITEXCOORDP2UIVPROC)(GLenum texture, GLenum type, const GLuint *coords);
GLAPI PFNGLMULTITEXCOORDP2UIVPROC cppgl_glMultiTexCoordP2uiv;
#define glMultiTexCoordP2uiv cppgl_glMultiTexCoordP2uiv
typedef void (APIENTRYP PFNGLMULTITEXCOORDP3UIPROC)(GLenum texture, GLenum type, GLuint coords);
GLAPI PFNGLMULTITEXCOORDP3UIPROC cppgl_glMultiTexCoordP3ui;
#define glMultiTexCoordP3ui cppgl_glMultiTexCoordP3ui
typedef void (APIENTRYP PFNGLMULTITEXCOORDP3UIVPROC)(GLenum texture, GLenum type, const GLuint *coords);
GLAPI PFNGLMULTITEXCOORDP3UIVPROC cppgl_glMultiTexCoordP3uiv;
#define glMultiTexCoordP3uiv cppgl_glMultiTexCoordP3uiv
typedef void (APIENTRYP PFNGLMULTITEXCOORDP4UIPROC)(GLenum texture, GLenum type, GLuint coords);
GLAPI PFNGLMULTITEXCOORDP4UIPROC cppgl_glMultiTexCoordP4ui;
#define glMultiTexCoordP4ui cppgl_glMultiTexCoordP4ui
typedef void (APIENTRYP PFNGLMULTITEXCOORDP4UIVPROC)(GLenum texture, GLenum type, const GLuint *coords);
GLAPI PFNGLMULTITEXCOORDP4UIVPROC cppgl_glMultiTexCoordP4uiv;
#define glMultiTexCoordP4uiv cppgl_glMultiTexCoordP4uiv
typedef void (APIENTRYP PFNGLNORMALP3UIPROC)(GLenum type, GLuint coords);
GLAPI PFNGLNORMALP3UIPROC cppgl_glNormalP3ui;
#define glNormalP3ui cppgl_glNormalP3ui
typedef void (APIENTRYP PFNGLNORMALP3UIVPROC)(GLenum type, const GLuint *coords);
GLAPI PFNGLNORMALP3UIVPROC cppgl_glNormalP3uiv;
#define glNormalP3uiv cppgl_glNormalP3uiv
typedef void (APIENTRYP PFNGLCOLORP3UIPROC)(GLenum type, GLuint color);
GLAPI PFNGLCOLORP3UIPROC cppgl_glColorP3ui;
#define glColorP3ui cppgl_glColorP3ui
typedef void (APIENTRYP PFNGLCOLORP3UIVPROC)(GLenum type, const GLuint *color);
GLAPI PFNGLCOLORP3UIVPROC cppgl_glColorP3uiv;
#define glColorP3uiv cppgl_glColorP3uiv
typedef void (APIENTRYP PFNGLCOLORP4UIPROC)(GLenum type, GLuint color);
GLAPI PFNGLCOLORP4UIPROC cppgl_glColorP4ui;
#define glColorP4ui cppgl_glColorP4ui
typedef void (APIENTRYP PFNGLCOLORP4UIVPROC)(GLenum type, const GLuint *color);
GLAPI PFNGLCOLORP4UIVPROC cppgl_glColorP4uiv;
#define glColorP4uiv cppgl_glColorP4uiv
typedef void (APIENTRYP PFNGLSECONDARYCOLORP3UIPROC)(GLenum type, GLuint color);
GLAPI PFNGLSECONDARYCOLORP3UIPROC cppgl_glSecondaryColorP3ui;
#define glSecondaryColorP3ui cppgl_glSecondaryColorP3ui
typedef void (APIENTRYP PFNGLSECONDARYCOLORP3UIVPROC)(GLenum type, const GLuint *color);
GLAPI PFNGLSECONDARYCOLORP3UIVPROC cppgl_glSecondaryColorP3uiv;
#define glSecondaryColorP3uiv cppgl_glSecondaryColorP3uiv
#endif
#ifndef GL_ARB_viewport_array
#define GL_ARB_viewport_array 1
GLAPI int CPPGL_GL_ARB_viewport_array;
typedef void (APIENTRYP PFNGLVIEWPORTARRAYVPROC)(GLuint first, GLsizei count, const GLfloat *v);
GLAPI PFNGLVIEWPORTARRAYVPROC cppgl_glViewportArrayv;
#define glViewportArrayv cppgl_glViewportArrayv
typedef void (APIENTRYP PFNGLVIEWPORTINDEXEDFPROC)(GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h);
GLAPI PFNGLVIEWPORTINDEXEDFPROC cppgl_glViewportIndexedf;
#define glViewportIndexedf cppgl_glViewportIndexedf
typedef void (APIENTRYP PFNGLVIEWPORTINDEXEDFVPROC)(GLuint index, const GLfloat *v);
GLAPI PFNGLVIEWPORTINDEXEDFVPROC cppgl_glViewportIndexedfv;
#define glViewportIndexedfv cppgl_glViewportIndexedfv
typedef void (APIENTRYP PFNGLSCISSORARRAYVPROC)(GLuint first, GLsizei count, const GLint *v);
GLAPI PFNGLSCISSORARRAYVPROC cppgl_glScissorArrayv;
#define glScissorArrayv cppgl_glScissorArrayv
typedef void (APIENTRYP PFNGLSCISSORINDEXEDPROC)(GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height);
GLAPI PFNGLSCISSORINDEXEDPROC cppgl_glScissorIndexed;
#define glScissorIndexed cppgl_glScissorIndexed
typedef void (APIENTRYP PFNGLSCISSORINDEXEDVPROC)(GLuint index, const GLint *v);
GLAPI PFNGLSCISSORINDEXEDVPROC cppgl_glScissorIndexedv;
#define glScissorIndexedv cppgl_glScissorIndexedv
typedef void (APIENTRYP PFNGLDEPTHRANGEARRAYVPROC)(GLuint first, GLsizei count, const GLdouble *v);
GLAPI PFNGLDEPTHRANGEARRAYVPROC cppgl_glDepthRangeArrayv;
#define glDepthRangeArrayv cppgl_glDepthRangeArrayv
typedef void (APIENTRYP PFNGLDEPTHRANGEINDEXEDPROC)(GLuint index, GLdouble n, GLdouble f);
GLAPI PFNGLDEPTHRANGEINDEXEDPROC cppgl_glDepthRangeIndexed;
#define glDepthRangeIndexed cppgl_glDepthRangeIndexed
typedef void (APIENTRYP PFNGLGETFLOATI_VPROC)(GLenum target, GLuint index, GLfloat *data);
GLAPI PFNGLGETFLOATI_VPROC cppgl_glGetFloati_v;
#define glGetFloati_v cppgl_glGetFloati_v
typedef void (APIENTRYP PFNGLGETDOUBLEI_VPROC)(GLenum target, GLuint index, GLdouble *data);
GLAPI PFNGLGETDOUBLEI_VPROC cppgl_glGetDoublei_v;
#define glGetDoublei_v cppgl_glGetDoublei_v
#endif
#ifndef GL_ARB_window_pos
#define GL_ARB_window_pos 1
GLAPI int CPPGL_GL_ARB_window_pos;
typedef void (APIENTRYP PFNGLWINDOWPOS2DARBPROC)(GLdouble x, GLdouble y);
GLAPI PFNGLWINDOWPOS2DARBPROC cppgl_glWindowPos2dARB;
#define glWindowPos2dARB cppgl_glWindowPos2dARB
typedef void (APIENTRYP PFNGLWINDOWPOS2DVARBPROC)(const GLdouble *v);
GLAPI PFNGLWINDOWPOS2DVARBPROC cppgl_glWindowPos2dvARB;
#define glWindowPos2dvARB cppgl_glWindowPos2dvARB
typedef void (APIENTRYP PFNGLWINDOWPOS2FARBPROC)(GLfloat x, GLfloat y);
GLAPI PFNGLWINDOWPOS2FARBPROC cppgl_glWindowPos2fARB;
#define glWindowPos2fARB cppgl_glWindowPos2fARB
typedef void (APIENTRYP PFNGLWINDOWPOS2FVARBPROC)(const GLfloat *v);
GLAPI PFNGLWINDOWPOS2FVARBPROC cppgl_glWindowPos2fvARB;
#define glWindowPos2fvARB cppgl_glWindowPos2fvARB
typedef void (APIENTRYP PFNGLWINDOWPOS2IARBPROC)(GLint x, GLint y);
GLAPI PFNGLWINDOWPOS2IARBPROC cppgl_glWindowPos2iARB;
#define glWindowPos2iARB cppgl_glWindowPos2iARB
typedef void (APIENTRYP PFNGLWINDOWPOS2IVARBPROC)(const GLint *v);
GLAPI PFNGLWINDOWPOS2IVARBPROC cppgl_glWindowPos2ivARB;
#define glWindowPos2ivARB cppgl_glWindowPos2ivARB
typedef void (APIENTRYP PFNGLWINDOWPOS2SARBPROC)(GLshort x, GLshort y);
GLAPI PFNGLWINDOWPOS2SARBPROC cppgl_glWindowPos2sARB;
#define glWindowPos2sARB cppgl_glWindowPos2sARB
typedef void (APIENTRYP PFNGLWINDOWPOS2SVARBPROC)(const GLshort *v);
GLAPI PFNGLWINDOWPOS2SVARBPROC cppgl_glWindowPos2svARB;
#define glWindowPos2svARB cppgl_glWindowPos2svARB
typedef void (APIENTRYP PFNGLWINDOWPOS3DARBPROC)(GLdouble x, GLdouble y, GLdouble z);
GLAPI PFNGLWINDOWPOS3DARBPROC cppgl_glWindowPos3dARB;
#define glWindowPos3dARB cppgl_glWindowPos3dARB
typedef void (APIENTRYP PFNGLWINDOWPOS3DVARBPROC)(const GLdouble *v);
GLAPI PFNGLWINDOWPOS3DVARBPROC cppgl_glWindowPos3dvARB;
#define glWindowPos3dvARB cppgl_glWindowPos3dvARB
typedef void (APIENTRYP PFNGLWINDOWPOS3FARBPROC)(GLfloat x, GLfloat y, GLfloat z);
GLAPI PFNGLWINDOWPOS3FARBPROC cppgl_glWindowPos3fARB;
#define glWindowPos3fARB cppgl_glWindowPos3fARB
typedef void (APIENTRYP PFNGLWINDOWPOS3FVARBPROC)(const GLfloat *v);
GLAPI PFNGLWINDOWPOS3FVARBPROC cppgl_glWindowPos3fvARB;
#define glWindowPos3fvARB cppgl_glWindowPos3fvARB
typedef void (APIENTRYP PFNGLWINDOWPOS3IARBPROC)(GLint x, GLint y, GLint z);
GLAPI PFNGLWINDOWPOS3IARBPROC cppgl_glWindowPos3iARB;
#define glWindowPos3iARB cppgl_glWindowPos3iARB
typedef void (APIENTRYP PFNGLWINDOWPOS3IVARBPROC)(const GLint *v);
GLAPI PFNGLWINDOWPOS3IVARBPROC cppgl_glWindowPos3ivARB;
#define glWindowPos3ivARB cppgl_glWindowPos3ivARB
typedef void (APIENTRYP PFNGLWINDOWPOS3SARBPROC)(GLshort x, GLshort y, GLshort z);
GLAPI PFNGLWINDOWPOS3SARBPROC cppgl_glWindowPos3sARB;
#define glWindowPos3sARB cppgl_glWindowPos3sARB
typedef void (APIENTRYP PFNGLWINDOWPOS3SVARBPROC)(const GLshort *v);
GLAPI PFNGLWINDOWPOS3SVARBPROC cppgl_glWindowPos3svARB;
#define glWindowPos3svARB cppgl_glWindowPos3svARB
#endif
#ifndef GL_ATI_draw_buffers
#define GL_ATI_draw_buffers 1
GLAPI int CPPGL_GL_ATI_draw_buffers;
typedef void (APIENTRYP PFNGLDRAWBUFFERSATIPROC)(GLsizei n, const GLenum *bufs);
GLAPI PFNGLDRAWBUFFERSATIPROC cppgl_glDrawBuffersATI;
#define glDrawBuffersATI cppgl_glDrawBuffersATI
#endif
#ifndef GL_ATI_element_array
#define GL_ATI_element_array 1
GLAPI int CPPGL_GL_ATI_element_array;
typedef void (APIENTRYP PFNGLELEMENTPOINTERATIPROC)(GLenum type, const void *pointer);
GLAPI PFNGLELEMENTPOINTERATIPROC cppgl_glElementPointerATI;
#define glElementPointerATI cppgl_glElementPointerATI
typedef void (APIENTRYP PFNGLDRAWELEMENTARRAYATIPROC)(GLenum mode, GLsizei count);
GLAPI PFNGLDRAWELEMENTARRAYATIPROC cppgl_glDrawElementArrayATI;
#define glDrawElementArrayATI cppgl_glDrawElementArrayATI
typedef void (APIENTRYP PFNGLDRAWRANGEELEMENTARRAYATIPROC)(GLenum mode, GLuint start, GLuint end, GLsizei count);
GLAPI PFNGLDRAWRANGEELEMENTARRAYATIPROC cppgl_glDrawRangeElementArrayATI;
#define glDrawRangeElementArrayATI cppgl_glDrawRangeElementArrayATI
#endif
#ifndef GL_ATI_envmap_bumpmap
#define GL_ATI_envmap_bumpmap 1
GLAPI int CPPGL_GL_ATI_envmap_bumpmap;
typedef void (APIENTRYP PFNGLTEXBUMPPARAMETERIVATIPROC)(GLenum pname, const GLint *param);
GLAPI PFNGLTEXBUMPPARAMETERIVATIPROC cppgl_glTexBumpParameterivATI;
#define glTexBumpParameterivATI cppgl_glTexBumpParameterivATI
typedef void (APIENTRYP PFNGLTEXBUMPPARAMETERFVATIPROC)(GLenum pname, const GLfloat *param);
GLAPI PFNGLTEXBUMPPARAMETERFVATIPROC cppgl_glTexBumpParameterfvATI;
#define glTexBumpParameterfvATI cppgl_glTexBumpParameterfvATI
typedef void (APIENTRYP PFNGLGETTEXBUMPPARAMETERIVATIPROC)(GLenum pname, GLint *param);
GLAPI PFNGLGETTEXBUMPPARAMETERIVATIPROC cppgl_glGetTexBumpParameterivATI;
#define glGetTexBumpParameterivATI cppgl_glGetTexBumpParameterivATI
typedef void (APIENTRYP PFNGLGETTEXBUMPPARAMETERFVATIPROC)(GLenum pname, GLfloat *param);
GLAPI PFNGLGETTEXBUMPPARAMETERFVATIPROC cppgl_glGetTexBumpParameterfvATI;
#define glGetTexBumpParameterfvATI cppgl_glGetTexBumpParameterfvATI
#endif
#ifndef GL_ATI_fragment_shader
#define GL_ATI_fragment_shader 1
GLAPI int CPPGL_GL_ATI_fragment_shader;
typedef GLuint (APIENTRYP PFNGLGENFRAGMENTSHADERSATIPROC)(GLuint range);
GLAPI PFNGLGENFRAGMENTSHADERSATIPROC cppgl_glGenFragmentShadersATI;
#define glGenFragmentShadersATI cppgl_glGenFragmentShadersATI
typedef void (APIENTRYP PFNGLBINDFRAGMENTSHADERATIPROC)(GLuint id);
GLAPI PFNGLBINDFRAGMENTSHADERATIPROC cppgl_glBindFragmentShaderATI;
#define glBindFragmentShaderATI cppgl_glBindFragmentShaderATI
typedef void (APIENTRYP PFNGLDELETEFRAGMENTSHADERATIPROC)(GLuint id);
GLAPI PFNGLDELETEFRAGMENTSHADERATIPROC cppgl_glDeleteFragmentShaderATI;
#define glDeleteFragmentShaderATI cppgl_glDeleteFragmentShaderATI
typedef void (APIENTRYP PFNGLBEGINFRAGMENTSHADERATIPROC)();
GLAPI PFNGLBEGINFRAGMENTSHADERATIPROC cppgl_glBeginFragmentShaderATI;
#define glBeginFragmentShaderATI cppgl_glBeginFragmentShaderATI
typedef void (APIENTRYP PFNGLENDFRAGMENTSHADERATIPROC)();
GLAPI PFNGLENDFRAGMENTSHADERATIPROC cppgl_glEndFragmentShaderATI;
#define glEndFragmentShaderATI cppgl_glEndFragmentShaderATI
typedef void (APIENTRYP PFNGLPASSTEXCOORDATIPROC)(GLuint dst, GLuint coord, GLenum swizzle);
GLAPI PFNGLPASSTEXCOORDATIPROC cppgl_glPassTexCoordATI;
#define glPassTexCoordATI cppgl_glPassTexCoordATI
typedef void (APIENTRYP PFNGLSAMPLEMAPATIPROC)(GLuint dst, GLuint interp, GLenum swizzle);
GLAPI PFNGLSAMPLEMAPATIPROC cppgl_glSampleMapATI;
#define glSampleMapATI cppgl_glSampleMapATI
typedef void (APIENTRYP PFNGLCOLORFRAGMENTOP1ATIPROC)(GLenum op, GLuint dst, GLuint dstMask, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod);
GLAPI PFNGLCOLORFRAGMENTOP1ATIPROC cppgl_glColorFragmentOp1ATI;
#define glColorFragmentOp1ATI cppgl_glColorFragmentOp1ATI
typedef void (APIENTRYP PFNGLCOLORFRAGMENTOP2ATIPROC)(GLenum op, GLuint dst, GLuint dstMask, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod, GLuint arg2, GLuint arg2Rep, GLuint arg2Mod);
GLAPI PFNGLCOLORFRAGMENTOP2ATIPROC cppgl_glColorFragmentOp2ATI;
#define glColorFragmentOp2ATI cppgl_glColorFragmentOp2ATI
typedef void (APIENTRYP PFNGLCOLORFRAGMENTOP3ATIPROC)(GLenum op, GLuint dst, GLuint dstMask, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod, GLuint arg2, GLuint arg2Rep, GLuint arg2Mod, GLuint arg3, GLuint arg3Rep, GLuint arg3Mod);
GLAPI PFNGLCOLORFRAGMENTOP3ATIPROC cppgl_glColorFragmentOp3ATI;
#define glColorFragmentOp3ATI cppgl_glColorFragmentOp3ATI
typedef void (APIENTRYP PFNGLALPHAFRAGMENTOP1ATIPROC)(GLenum op, GLuint dst, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod);
GLAPI PFNGLALPHAFRAGMENTOP1ATIPROC cppgl_glAlphaFragmentOp1ATI;
#define glAlphaFragmentOp1ATI cppgl_glAlphaFragmentOp1ATI
typedef void (APIENTRYP PFNGLALPHAFRAGMENTOP2ATIPROC)(GLenum op, GLuint dst, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod, GLuint arg2, GLuint arg2Rep, GLuint arg2Mod);
GLAPI PFNGLALPHAFRAGMENTOP2ATIPROC cppgl_glAlphaFragmentOp2ATI;
#define glAlphaFragmentOp2ATI cppgl_glAlphaFragmentOp2ATI
typedef void (APIENTRYP PFNGLALPHAFRAGMENTOP3ATIPROC)(GLenum op, GLuint dst, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod, GLuint arg2, GLuint arg2Rep, GLuint arg2Mod, GLuint arg3, GLuint arg3Rep, GLuint arg3Mod);
GLAPI PFNGLALPHAFRAGMENTOP3ATIPROC cppgl_glAlphaFragmentOp3ATI;
#define glAlphaFragmentOp3ATI cppgl_glAlphaFragmentOp3ATI
typedef void (APIENTRYP PFNGLSETFRAGMENTSHADERCONSTANTATIPROC)(GLuint dst, const GLfloat *value);
GLAPI PFNGLSETFRAGMENTSHADERCONSTANTATIPROC cppgl_glSetFragmentShaderConstantATI;
#define glSetFragmentShaderConstantATI cppgl_glSetFragmentShaderConstantATI
#endif
#ifndef GL_ATI_map_object_buffer
#define GL_ATI_map_object_buffer 1
GLAPI int CPPGL_GL_ATI_map_object_buffer;
typedef void * (APIENTRYP PFNGLMAPOBJECTBUFFERATIPROC)(GLuint buffer);
GLAPI PFNGLMAPOBJECTBUFFERATIPROC cppgl_glMapObjectBufferATI;
#define glMapObjectBufferATI cppgl_glMapObjectBufferATI
typedef void (APIENTRYP PFNGLUNMAPOBJECTBUFFERATIPROC)(GLuint buffer);
GLAPI PFNGLUNMAPOBJECTBUFFERATIPROC cppgl_glUnmapObjectBufferATI;
#define glUnmapObjectBufferATI cppgl_glUnmapObjectBufferATI
#endif
#ifndef GL_ATI_meminfo
#define GL_ATI_meminfo 1
GLAPI int CPPGL_GL_ATI_meminfo;
#endif
#ifndef GL_ATI_pixel_format_float
#define GL_ATI_pixel_format_float 1
GLAPI int CPPGL_GL_ATI_pixel_format_float;
#endif
#ifndef GL_ATI_pn_triangles
#define GL_ATI_pn_triangles 1
GLAPI int CPPGL_GL_ATI_pn_triangles;
typedef void (APIENTRYP PFNGLPNTRIANGLESIATIPROC)(GLenum pname, GLint param);
GLAPI PFNGLPNTRIANGLESIATIPROC cppgl_glPNTrianglesiATI;
#define glPNTrianglesiATI cppgl_glPNTrianglesiATI
typedef void (APIENTRYP PFNGLPNTRIANGLESFATIPROC)(GLenum pname, GLfloat param);
GLAPI PFNGLPNTRIANGLESFATIPROC cppgl_glPNTrianglesfATI;
#define glPNTrianglesfATI cppgl_glPNTrianglesfATI
#endif
#ifndef GL_ATI_separate_stencil
#define GL_ATI_separate_stencil 1
GLAPI int CPPGL_GL_ATI_separate_stencil;
typedef void (APIENTRYP PFNGLSTENCILOPSEPARATEATIPROC)(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
GLAPI PFNGLSTENCILOPSEPARATEATIPROC cppgl_glStencilOpSeparateATI;
#define glStencilOpSeparateATI cppgl_glStencilOpSeparateATI
typedef void (APIENTRYP PFNGLSTENCILFUNCSEPARATEATIPROC)(GLenum frontfunc, GLenum backfunc, GLint ref, GLuint mask);
GLAPI PFNGLSTENCILFUNCSEPARATEATIPROC cppgl_glStencilFuncSeparateATI;
#define glStencilFuncSeparateATI cppgl_glStencilFuncSeparateATI
#endif
#ifndef GL_ATI_text_fragment_shader
#define GL_ATI_text_fragment_shader 1
GLAPI int CPPGL_GL_ATI_text_fragment_shader;
#endif
#ifndef GL_ATI_texture_env_combine3
#define GL_ATI_texture_env_combine3 1
GLAPI int CPPGL_GL_ATI_texture_env_combine3;
#endif
#ifndef GL_ATI_texture_float
#define GL_ATI_texture_float 1
GLAPI int CPPGL_GL_ATI_texture_float;
#endif
#ifndef GL_ATI_texture_mirror_once
#define GL_ATI_texture_mirror_once 1
GLAPI int CPPGL_GL_ATI_texture_mirror_once;
#endif
#ifndef GL_ATI_vertex_array_object
#define GL_ATI_vertex_array_object 1
GLAPI int CPPGL_GL_ATI_vertex_array_object;
typedef GLuint (APIENTRYP PFNGLNEWOBJECTBUFFERATIPROC)(GLsizei size, const void *pointer, GLenum usage);
GLAPI PFNGLNEWOBJECTBUFFERATIPROC cppgl_glNewObjectBufferATI;
#define glNewObjectBufferATI cppgl_glNewObjectBufferATI
typedef GLboolean (APIENTRYP PFNGLISOBJECTBUFFERATIPROC)(GLuint buffer);
GLAPI PFNGLISOBJECTBUFFERATIPROC cppgl_glIsObjectBufferATI;
#define glIsObjectBufferATI cppgl_glIsObjectBufferATI
typedef void (APIENTRYP PFNGLUPDATEOBJECTBUFFERATIPROC)(GLuint buffer, GLuint offset, GLsizei size, const void *pointer, GLenum preserve);
GLAPI PFNGLUPDATEOBJECTBUFFERATIPROC cppgl_glUpdateObjectBufferATI;
#define glUpdateObjectBufferATI cppgl_glUpdateObjectBufferATI
typedef void (APIENTRYP PFNGLGETOBJECTBUFFERFVATIPROC)(GLuint buffer, GLenum pname, GLfloat *params);
GLAPI PFNGLGETOBJECTBUFFERFVATIPROC cppgl_glGetObjectBufferfvATI;
#define glGetObjectBufferfvATI cppgl_glGetObjectBufferfvATI
typedef void (APIENTRYP PFNGLGETOBJECTBUFFERIVATIPROC)(GLuint buffer, GLenum pname, GLint *params);
GLAPI PFNGLGETOBJECTBUFFERIVATIPROC cppgl_glGetObjectBufferivATI;
#define glGetObjectBufferivATI cppgl_glGetObjectBufferivATI
typedef void (APIENTRYP PFNGLFREEOBJECTBUFFERATIPROC)(GLuint buffer);
GLAPI PFNGLFREEOBJECTBUFFERATIPROC cppgl_glFreeObjectBufferATI;
#define glFreeObjectBufferATI cppgl_glFreeObjectBufferATI
typedef void (APIENTRYP PFNGLARRAYOBJECTATIPROC)(GLenum array, GLint size, GLenum type, GLsizei stride, GLuint buffer, GLuint offset);
GLAPI PFNGLARRAYOBJECTATIPROC cppgl_glArrayObjectATI;
#define glArrayObjectATI cppgl_glArrayObjectATI
typedef void (APIENTRYP PFNGLGETARRAYOBJECTFVATIPROC)(GLenum array, GLenum pname, GLfloat *params);
GLAPI PFNGLGETARRAYOBJECTFVATIPROC cppgl_glGetArrayObjectfvATI;
#define glGetArrayObjectfvATI cppgl_glGetArrayObjectfvATI
typedef void (APIENTRYP PFNGLGETARRAYOBJECTIVATIPROC)(GLenum array, GLenum pname, GLint *params);
GLAPI PFNGLGETARRAYOBJECTIVATIPROC cppgl_glGetArrayObjectivATI;
#define glGetArrayObjectivATI cppgl_glGetArrayObjectivATI
typedef void (APIENTRYP PFNGLVARIANTARRAYOBJECTATIPROC)(GLuint id, GLenum type, GLsizei stride, GLuint buffer, GLuint offset);
GLAPI PFNGLVARIANTARRAYOBJECTATIPROC cppgl_glVariantArrayObjectATI;
#define glVariantArrayObjectATI cppgl_glVariantArrayObjectATI
typedef void (APIENTRYP PFNGLGETVARIANTARRAYOBJECTFVATIPROC)(GLuint id, GLenum pname, GLfloat *params);
GLAPI PFNGLGETVARIANTARRAYOBJECTFVATIPROC cppgl_glGetVariantArrayObjectfvATI;
#define glGetVariantArrayObjectfvATI cppgl_glGetVariantArrayObjectfvATI
typedef void (APIENTRYP PFNGLGETVARIANTARRAYOBJECTIVATIPROC)(GLuint id, GLenum pname, GLint *params);
GLAPI PFNGLGETVARIANTARRAYOBJECTIVATIPROC cppgl_glGetVariantArrayObjectivATI;
#define glGetVariantArrayObjectivATI cppgl_glGetVariantArrayObjectivATI
#endif
#ifndef GL_ATI_vertex_attrib_array_object
#define GL_ATI_vertex_attrib_array_object 1
GLAPI int CPPGL_GL_ATI_vertex_attrib_array_object;
typedef void (APIENTRYP PFNGLVERTEXATTRIBARRAYOBJECTATIPROC)(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLuint buffer, GLuint offset);
GLAPI PFNGLVERTEXATTRIBARRAYOBJECTATIPROC cppgl_glVertexAttribArrayObjectATI;
#define glVertexAttribArrayObjectATI cppgl_glVertexAttribArrayObjectATI
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBARRAYOBJECTFVATIPROC)(GLuint index, GLenum pname, GLfloat *params);
GLAPI PFNGLGETVERTEXATTRIBARRAYOBJECTFVATIPROC cppgl_glGetVertexAttribArrayObjectfvATI;
#define glGetVertexAttribArrayObjectfvATI cppgl_glGetVertexAttribArrayObjectfvATI
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBARRAYOBJECTIVATIPROC)(GLuint index, GLenum pname, GLint *params);
GLAPI PFNGLGETVERTEXATTRIBARRAYOBJECTIVATIPROC cppgl_glGetVertexAttribArrayObjectivATI;
#define glGetVertexAttribArrayObjectivATI cppgl_glGetVertexAttribArrayObjectivATI
#endif
#ifndef GL_ATI_vertex_streams
#define GL_ATI_vertex_streams 1
GLAPI int CPPGL_GL_ATI_vertex_streams;
typedef void (APIENTRYP PFNGLVERTEXSTREAM1SATIPROC)(GLenum stream, GLshort x);
GLAPI PFNGLVERTEXSTREAM1SATIPROC cppgl_glVertexStream1sATI;
#define glVertexStream1sATI cppgl_glVertexStream1sATI
typedef void (APIENTRYP PFNGLVERTEXSTREAM1SVATIPROC)(GLenum stream, const GLshort *coords);
GLAPI PFNGLVERTEXSTREAM1SVATIPROC cppgl_glVertexStream1svATI;
#define glVertexStream1svATI cppgl_glVertexStream1svATI
typedef void (APIENTRYP PFNGLVERTEXSTREAM1IATIPROC)(GLenum stream, GLint x);
GLAPI PFNGLVERTEXSTREAM1IATIPROC cppgl_glVertexStream1iATI;
#define glVertexStream1iATI cppgl_glVertexStream1iATI
typedef void (APIENTRYP PFNGLVERTEXSTREAM1IVATIPROC)(GLenum stream, const GLint *coords);
GLAPI PFNGLVERTEXSTREAM1IVATIPROC cppgl_glVertexStream1ivATI;
#define glVertexStream1ivATI cppgl_glVertexStream1ivATI
typedef void (APIENTRYP PFNGLVERTEXSTREAM1FATIPROC)(GLenum stream, GLfloat x);
GLAPI PFNGLVERTEXSTREAM1FATIPROC cppgl_glVertexStream1fATI;
#define glVertexStream1fATI cppgl_glVertexStream1fATI
typedef void (APIENTRYP PFNGLVERTEXSTREAM1FVATIPROC)(GLenum stream, const GLfloat *coords);
GLAPI PFNGLVERTEXSTREAM1FVATIPROC cppgl_glVertexStream1fvATI;
#define glVertexStream1fvATI cppgl_glVertexStream1fvATI
typedef void (APIENTRYP PFNGLVERTEXSTREAM1DATIPROC)(GLenum stream, GLdouble x);
GLAPI PFNGLVERTEXSTREAM1DATIPROC cppgl_glVertexStream1dATI;
#define glVertexStream1dATI cppgl_glVertexStream1dATI
typedef void (APIENTRYP PFNGLVERTEXSTREAM1DVATIPROC)(GLenum stream, const GLdouble *coords);
GLAPI PFNGLVERTEXSTREAM1DVATIPROC cppgl_glVertexStream1dvATI;
#define glVertexStream1dvATI cppgl_glVertexStream1dvATI
typedef void (APIENTRYP PFNGLVERTEXSTREAM2SATIPROC)(GLenum stream, GLshort x, GLshort y);
GLAPI PFNGLVERTEXSTREAM2SATIPROC cppgl_glVertexStream2sATI;
#define glVertexStream2sATI cppgl_glVertexStream2sATI
typedef void (APIENTRYP PFNGLVERTEXSTREAM2SVATIPROC)(GLenum stream, const GLshort *coords);
GLAPI PFNGLVERTEXSTREAM2SVATIPROC cppgl_glVertexStream2svATI;
#define glVertexStream2svATI cppgl_glVertexStream2svATI
typedef void (APIENTRYP PFNGLVERTEXSTREAM2IATIPROC)(GLenum stream, GLint x, GLint y);
GLAPI PFNGLVERTEXSTREAM2IATIPROC cppgl_glVertexStream2iATI;
#define glVertexStream2iATI cppgl_glVertexStream2iATI
typedef void (APIENTRYP PFNGLVERTEXSTREAM2IVATIPROC)(GLenum stream, const GLint *coords);
GLAPI PFNGLVERTEXSTREAM2IVATIPROC cppgl_glVertexStream2ivATI;
#define glVertexStream2ivATI cppgl_glVertexStream2ivATI
typedef void (APIENTRYP PFNGLVERTEXSTREAM2FATIPROC)(GLenum stream, GLfloat x, GLfloat y);
GLAPI PFNGLVERTEXSTREAM2FATIPROC cppgl_glVertexStream2fATI;
#define glVertexStream2fATI cppgl_glVertexStream2fATI
typedef void (APIENTRYP PFNGLVERTEXSTREAM2FVATIPROC)(GLenum stream, const GLfloat *coords);
GLAPI PFNGLVERTEXSTREAM2FVATIPROC cppgl_glVertexStream2fvATI;
#define glVertexStream2fvATI cppgl_glVertexStream2fvATI
typedef void (APIENTRYP PFNGLVERTEXSTREAM2DATIPROC)(GLenum stream, GLdouble x, GLdouble y);
GLAPI PFNGLVERTEXSTREAM2DATIPROC cppgl_glVertexStream2dATI;
#define glVertexStream2dATI cppgl_glVertexStream2dATI
typedef void (APIENTRYP PFNGLVERTEXSTREAM2DVATIPROC)(GLenum stream, const GLdouble *coords);
GLAPI PFNGLVERTEXSTREAM2DVATIPROC cppgl_glVertexStream2dvATI;
#define glVertexStream2dvATI cppgl_glVertexStream2dvATI
typedef void (APIENTRYP PFNGLVERTEXSTREAM3SATIPROC)(GLenum stream, GLshort x, GLshort y, GLshort z);
GLAPI PFNGLVERTEXSTREAM3SATIPROC cppgl_glVertexStream3sATI;
#define glVertexStream3sATI cppgl_glVertexStream3sATI
typedef void (APIENTRYP PFNGLVERTEXSTREAM3SVATIPROC)(GLenum stream, const GLshort *coords);
GLAPI PFNGLVERTEXSTREAM3SVATIPROC cppgl_glVertexStream3svATI;
#define glVertexStream3svATI cppgl_glVertexStream3svATI
typedef void (APIENTRYP PFNGLVERTEXSTREAM3IATIPROC)(GLenum stream, GLint x, GLint y, GLint z);
GLAPI PFNGLVERTEXSTREAM3IATIPROC cppgl_glVertexStream3iATI;
#define glVertexStream3iATI cppgl_glVertexStream3iATI
typedef void (APIENTRYP PFNGLVERTEXSTREAM3IVATIPROC)(GLenum stream, const GLint *coords);
GLAPI PFNGLVERTEXSTREAM3IVATIPROC cppgl_glVertexStream3ivATI;
#define glVertexStream3ivATI cppgl_glVertexStream3ivATI
typedef void (APIENTRYP PFNGLVERTEXSTREAM3FATIPROC)(GLenum stream, GLfloat x, GLfloat y, GLfloat z);
GLAPI PFNGLVERTEXSTREAM3FATIPROC cppgl_glVertexStream3fATI;
#define glVertexStream3fATI cppgl_glVertexStream3fATI
typedef void (APIENTRYP PFNGLVERTEXSTREAM3FVATIPROC)(GLenum stream, const GLfloat *coords);
GLAPI PFNGLVERTEXSTREAM3FVATIPROC cppgl_glVertexStream3fvATI;
#define glVertexStream3fvATI cppgl_glVertexStream3fvATI
typedef void (APIENTRYP PFNGLVERTEXSTREAM3DATIPROC)(GLenum stream, GLdouble x, GLdouble y, GLdouble z);
GLAPI PFNGLVERTEXSTREAM3DATIPROC cppgl_glVertexStream3dATI;
#define glVertexStream3dATI cppgl_glVertexStream3dATI
typedef void (APIENTRYP PFNGLVERTEXSTREAM3DVATIPROC)(GLenum stream, const GLdouble *coords);
GLAPI PFNGLVERTEXSTREAM3DVATIPROC cppgl_glVertexStream3dvATI;
#define glVertexStream3dvATI cppgl_glVertexStream3dvATI
typedef void (APIENTRYP PFNGLVERTEXSTREAM4SATIPROC)(GLenum stream, GLshort x, GLshort y, GLshort z, GLshort w);
GLAPI PFNGLVERTEXSTREAM4SATIPROC cppgl_glVertexStream4sATI;
#define glVertexStream4sATI cppgl_glVertexStream4sATI
typedef void (APIENTRYP PFNGLVERTEXSTREAM4SVATIPROC)(GLenum stream, const GLshort *coords);
GLAPI PFNGLVERTEXSTREAM4SVATIPROC cppgl_glVertexStream4svATI;
#define glVertexStream4svATI cppgl_glVertexStream4svATI
typedef void (APIENTRYP PFNGLVERTEXSTREAM4IATIPROC)(GLenum stream, GLint x, GLint y, GLint z, GLint w);
GLAPI PFNGLVERTEXSTREAM4IATIPROC cppgl_glVertexStream4iATI;
#define glVertexStream4iATI cppgl_glVertexStream4iATI
typedef void (APIENTRYP PFNGLVERTEXSTREAM4IVATIPROC)(GLenum stream, const GLint *coords);
GLAPI PFNGLVERTEXSTREAM4IVATIPROC cppgl_glVertexStream4ivATI;
#define glVertexStream4ivATI cppgl_glVertexStream4ivATI
typedef void (APIENTRYP PFNGLVERTEXSTREAM4FATIPROC)(GLenum stream, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
GLAPI PFNGLVERTEXSTREAM4FATIPROC cppgl_glVertexStream4fATI;
#define glVertexStream4fATI cppgl_glVertexStream4fATI
typedef void (APIENTRYP PFNGLVERTEXSTREAM4FVATIPROC)(GLenum stream, const GLfloat *coords);
GLAPI PFNGLVERTEXSTREAM4FVATIPROC cppgl_glVertexStream4fvATI;
#define glVertexStream4fvATI cppgl_glVertexStream4fvATI
typedef void (APIENTRYP PFNGLVERTEXSTREAM4DATIPROC)(GLenum stream, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
GLAPI PFNGLVERTEXSTREAM4DATIPROC cppgl_glVertexStream4dATI;
#define glVertexStream4dATI cppgl_glVertexStream4dATI
typedef void (APIENTRYP PFNGLVERTEXSTREAM4DVATIPROC)(GLenum stream, const GLdouble *coords);
GLAPI PFNGLVERTEXSTREAM4DVATIPROC cppgl_glVertexStream4dvATI;
#define glVertexStream4dvATI cppgl_glVertexStream4dvATI
typedef void (APIENTRYP PFNGLNORMALSTREAM3BATIPROC)(GLenum stream, GLbyte nx, GLbyte ny, GLbyte nz);
GLAPI PFNGLNORMALSTREAM3BATIPROC cppgl_glNormalStream3bATI;
#define glNormalStream3bATI cppgl_glNormalStream3bATI
typedef void (APIENTRYP PFNGLNORMALSTREAM3BVATIPROC)(GLenum stream, const GLbyte *coords);
GLAPI PFNGLNORMALSTREAM3BVATIPROC cppgl_glNormalStream3bvATI;
#define glNormalStream3bvATI cppgl_glNormalStream3bvATI
typedef void (APIENTRYP PFNGLNORMALSTREAM3SATIPROC)(GLenum stream, GLshort nx, GLshort ny, GLshort nz);
GLAPI PFNGLNORMALSTREAM3SATIPROC cppgl_glNormalStream3sATI;
#define glNormalStream3sATI cppgl_glNormalStream3sATI
typedef void (APIENTRYP PFNGLNORMALSTREAM3SVATIPROC)(GLenum stream, const GLshort *coords);
GLAPI PFNGLNORMALSTREAM3SVATIPROC cppgl_glNormalStream3svATI;
#define glNormalStream3svATI cppgl_glNormalStream3svATI
typedef void (APIENTRYP PFNGLNORMALSTREAM3IATIPROC)(GLenum stream, GLint nx, GLint ny, GLint nz);
GLAPI PFNGLNORMALSTREAM3IATIPROC cppgl_glNormalStream3iATI;
#define glNormalStream3iATI cppgl_glNormalStream3iATI
typedef void (APIENTRYP PFNGLNORMALSTREAM3IVATIPROC)(GLenum stream, const GLint *coords);
GLAPI PFNGLNORMALSTREAM3IVATIPROC cppgl_glNormalStream3ivATI;
#define glNormalStream3ivATI cppgl_glNormalStream3ivATI
typedef void (APIENTRYP PFNGLNORMALSTREAM3FATIPROC)(GLenum stream, GLfloat nx, GLfloat ny, GLfloat nz);
GLAPI PFNGLNORMALSTREAM3FATIPROC cppgl_glNormalStream3fATI;
#define glNormalStream3fATI cppgl_glNormalStream3fATI
typedef void (APIENTRYP PFNGLNORMALSTREAM3FVATIPROC)(GLenum stream, const GLfloat *coords);
GLAPI PFNGLNORMALSTREAM3FVATIPROC cppgl_glNormalStream3fvATI;
#define glNormalStream3fvATI cppgl_glNormalStream3fvATI
typedef void (APIENTRYP PFNGLNORMALSTREAM3DATIPROC)(GLenum stream, GLdouble nx, GLdouble ny, GLdouble nz);
GLAPI PFNGLNORMALSTREAM3DATIPROC cppgl_glNormalStream3dATI;
#define glNormalStream3dATI cppgl_glNormalStream3dATI
typedef void (APIENTRYP PFNGLNORMALSTREAM3DVATIPROC)(GLenum stream, const GLdouble *coords);
GLAPI PFNGLNORMALSTREAM3DVATIPROC cppgl_glNormalStream3dvATI;
#define glNormalStream3dvATI cppgl_glNormalStream3dvATI
typedef void (APIENTRYP PFNGLCLIENTACTIVEVERTEXSTREAMATIPROC)(GLenum stream);
GLAPI PFNGLCLIENTACTIVEVERTEXSTREAMATIPROC cppgl_glClientActiveVertexStreamATI;
#define glClientActiveVertexStreamATI cppgl_glClientActiveVertexStreamATI
typedef void (APIENTRYP PFNGLVERTEXBLENDENVIATIPROC)(GLenum pname, GLint param);
GLAPI PFNGLVERTEXBLENDENVIATIPROC cppgl_glVertexBlendEnviATI;
#define glVertexBlendEnviATI cppgl_glVertexBlendEnviATI
typedef void (APIENTRYP PFNGLVERTEXBLENDENVFATIPROC)(GLenum pname, GLfloat param);
GLAPI PFNGLVERTEXBLENDENVFATIPROC cppgl_glVertexBlendEnvfATI;
#define glVertexBlendEnvfATI cppgl_glVertexBlendEnvfATI
#endif
#ifndef GL_EXT_422_pixels
#define GL_EXT_422_pixels 1
GLAPI int CPPGL_GL_EXT_422_pixels;
#endif
#ifndef GL_EXT_abgr
#define GL_EXT_abgr 1
GLAPI int CPPGL_GL_EXT_abgr;
#endif
#ifndef GL_EXT_bgra
#define GL_EXT_bgra 1
GLAPI int CPPGL_GL_EXT_bgra;
#endif
#ifndef GL_EXT_bindable_uniform
#define GL_EXT_bindable_uniform 1
GLAPI int CPPGL_GL_EXT_bindable_uniform;
typedef void (APIENTRYP PFNGLUNIFORMBUFFEREXTPROC)(GLuint program, GLint location, GLuint buffer);
GLAPI PFNGLUNIFORMBUFFEREXTPROC cppgl_glUniformBufferEXT;
#define glUniformBufferEXT cppgl_glUniformBufferEXT
typedef GLint (APIENTRYP PFNGLGETUNIFORMBUFFERSIZEEXTPROC)(GLuint program, GLint location);
GLAPI PFNGLGETUNIFORMBUFFERSIZEEXTPROC cppgl_glGetUniformBufferSizeEXT;
#define glGetUniformBufferSizeEXT cppgl_glGetUniformBufferSizeEXT
typedef GLintptr (APIENTRYP PFNGLGETUNIFORMOFFSETEXTPROC)(GLuint program, GLint location);
GLAPI PFNGLGETUNIFORMOFFSETEXTPROC cppgl_glGetUniformOffsetEXT;
#define glGetUniformOffsetEXT cppgl_glGetUniformOffsetEXT
#endif
#ifndef GL_EXT_blend_color
#define GL_EXT_blend_color 1
GLAPI int CPPGL_GL_EXT_blend_color;
typedef void (APIENTRYP PFNGLBLENDCOLOREXTPROC)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
GLAPI PFNGLBLENDCOLOREXTPROC cppgl_glBlendColorEXT;
#define glBlendColorEXT cppgl_glBlendColorEXT
#endif
#ifndef GL_EXT_blend_equation_separate
#define GL_EXT_blend_equation_separate 1
GLAPI int CPPGL_GL_EXT_blend_equation_separate;
typedef void (APIENTRYP PFNGLBLENDEQUATIONSEPARATEEXTPROC)(GLenum modeRGB, GLenum modeAlpha);
GLAPI PFNGLBLENDEQUATIONSEPARATEEXTPROC cppgl_glBlendEquationSeparateEXT;
#define glBlendEquationSeparateEXT cppgl_glBlendEquationSeparateEXT
#endif
#ifndef GL_EXT_blend_func_separate
#define GL_EXT_blend_func_separate 1
GLAPI int CPPGL_GL_EXT_blend_func_separate;
typedef void (APIENTRYP PFNGLBLENDFUNCSEPARATEEXTPROC)(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
GLAPI PFNGLBLENDFUNCSEPARATEEXTPROC cppgl_glBlendFuncSeparateEXT;
#define glBlendFuncSeparateEXT cppgl_glBlendFuncSeparateEXT
#endif
#ifndef GL_EXT_blend_logic_op
#define GL_EXT_blend_logic_op 1
GLAPI int CPPGL_GL_EXT_blend_logic_op;
#endif
#ifndef GL_EXT_blend_minmax
#define GL_EXT_blend_minmax 1
GLAPI int CPPGL_GL_EXT_blend_minmax;
typedef void (APIENTRYP PFNGLBLENDEQUATIONEXTPROC)(GLenum mode);
GLAPI PFNGLBLENDEQUATIONEXTPROC cppgl_glBlendEquationEXT;
#define glBlendEquationEXT cppgl_glBlendEquationEXT
#endif
#ifndef GL_EXT_blend_subtract
#define GL_EXT_blend_subtract 1
GLAPI int CPPGL_GL_EXT_blend_subtract;
#endif
#ifndef GL_EXT_clip_volume_hint
#define GL_EXT_clip_volume_hint 1
GLAPI int CPPGL_GL_EXT_clip_volume_hint;
#endif
#ifndef GL_EXT_cmyka
#define GL_EXT_cmyka 1
GLAPI int CPPGL_GL_EXT_cmyka;
#endif
#ifndef GL_EXT_color_subtable
#define GL_EXT_color_subtable 1
GLAPI int CPPGL_GL_EXT_color_subtable;
typedef void (APIENTRYP PFNGLCOLORSUBTABLEEXTPROC)(GLenum target, GLsizei start, GLsizei count, GLenum format, GLenum type, const void *data);
GLAPI PFNGLCOLORSUBTABLEEXTPROC cppgl_glColorSubTableEXT;
#define glColorSubTableEXT cppgl_glColorSubTableEXT
typedef void (APIENTRYP PFNGLCOPYCOLORSUBTABLEEXTPROC)(GLenum target, GLsizei start, GLint x, GLint y, GLsizei width);
GLAPI PFNGLCOPYCOLORSUBTABLEEXTPROC cppgl_glCopyColorSubTableEXT;
#define glCopyColorSubTableEXT cppgl_glCopyColorSubTableEXT
#endif
#ifndef GL_EXT_compiled_vertex_array
#define GL_EXT_compiled_vertex_array 1
GLAPI int CPPGL_GL_EXT_compiled_vertex_array;
typedef void (APIENTRYP PFNGLLOCKARRAYSEXTPROC)(GLint first, GLsizei count);
GLAPI PFNGLLOCKARRAYSEXTPROC cppgl_glLockArraysEXT;
#define glLockArraysEXT cppgl_glLockArraysEXT
typedef void (APIENTRYP PFNGLUNLOCKARRAYSEXTPROC)();
GLAPI PFNGLUNLOCKARRAYSEXTPROC cppgl_glUnlockArraysEXT;
#define glUnlockArraysEXT cppgl_glUnlockArraysEXT
#endif
#ifndef GL_EXT_convolution
#define GL_EXT_convolution 1
GLAPI int CPPGL_GL_EXT_convolution;
typedef void (APIENTRYP PFNGLCONVOLUTIONFILTER1DEXTPROC)(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const void *image);
GLAPI PFNGLCONVOLUTIONFILTER1DEXTPROC cppgl_glConvolutionFilter1DEXT;
#define glConvolutionFilter1DEXT cppgl_glConvolutionFilter1DEXT
typedef void (APIENTRYP PFNGLCONVOLUTIONFILTER2DEXTPROC)(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *image);
GLAPI PFNGLCONVOLUTIONFILTER2DEXTPROC cppgl_glConvolutionFilter2DEXT;
#define glConvolutionFilter2DEXT cppgl_glConvolutionFilter2DEXT
typedef void (APIENTRYP PFNGLCONVOLUTIONPARAMETERFEXTPROC)(GLenum target, GLenum pname, GLfloat params);
GLAPI PFNGLCONVOLUTIONPARAMETERFEXTPROC cppgl_glConvolutionParameterfEXT;
#define glConvolutionParameterfEXT cppgl_glConvolutionParameterfEXT
typedef void (APIENTRYP PFNGLCONVOLUTIONPARAMETERFVEXTPROC)(GLenum target, GLenum pname, const GLfloat *params);
GLAPI PFNGLCONVOLUTIONPARAMETERFVEXTPROC cppgl_glConvolutionParameterfvEXT;
#define glConvolutionParameterfvEXT cppgl_glConvolutionParameterfvEXT
typedef void (APIENTRYP PFNGLCONVOLUTIONPARAMETERIEXTPROC)(GLenum target, GLenum pname, GLint params);
GLAPI PFNGLCONVOLUTIONPARAMETERIEXTPROC cppgl_glConvolutionParameteriEXT;
#define glConvolutionParameteriEXT cppgl_glConvolutionParameteriEXT
typedef void (APIENTRYP PFNGLCONVOLUTIONPARAMETERIVEXTPROC)(GLenum target, GLenum pname, const GLint *params);
GLAPI PFNGLCONVOLUTIONPARAMETERIVEXTPROC cppgl_glConvolutionParameterivEXT;
#define glConvolutionParameterivEXT cppgl_glConvolutionParameterivEXT
typedef void (APIENTRYP PFNGLCOPYCONVOLUTIONFILTER1DEXTPROC)(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width);
GLAPI PFNGLCOPYCONVOLUTIONFILTER1DEXTPROC cppgl_glCopyConvolutionFilter1DEXT;
#define glCopyConvolutionFilter1DEXT cppgl_glCopyConvolutionFilter1DEXT
typedef void (APIENTRYP PFNGLCOPYCONVOLUTIONFILTER2DEXTPROC)(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height);
GLAPI PFNGLCOPYCONVOLUTIONFILTER2DEXTPROC cppgl_glCopyConvolutionFilter2DEXT;
#define glCopyConvolutionFilter2DEXT cppgl_glCopyConvolutionFilter2DEXT
typedef void (APIENTRYP PFNGLGETCONVOLUTIONFILTEREXTPROC)(GLenum target, GLenum format, GLenum type, void *image);
GLAPI PFNGLGETCONVOLUTIONFILTEREXTPROC cppgl_glGetConvolutionFilterEXT;
#define glGetConvolutionFilterEXT cppgl_glGetConvolutionFilterEXT
typedef void (APIENTRYP PFNGLGETCONVOLUTIONPARAMETERFVEXTPROC)(GLenum target, GLenum pname, GLfloat *params);
GLAPI PFNGLGETCONVOLUTIONPARAMETERFVEXTPROC cppgl_glGetConvolutionParameterfvEXT;
#define glGetConvolutionParameterfvEXT cppgl_glGetConvolutionParameterfvEXT
typedef void (APIENTRYP PFNGLGETCONVOLUTIONPARAMETERIVEXTPROC)(GLenum target, GLenum pname, GLint *params);
GLAPI PFNGLGETCONVOLUTIONPARAMETERIVEXTPROC cppgl_glGetConvolutionParameterivEXT;
#define glGetConvolutionParameterivEXT cppgl_glGetConvolutionParameterivEXT
typedef void (APIENTRYP PFNGLGETSEPARABLEFILTEREXTPROC)(GLenum target, GLenum format, GLenum type, void *row, void *column, void *span);
GLAPI PFNGLGETSEPARABLEFILTEREXTPROC cppgl_glGetSeparableFilterEXT;
#define glGetSeparableFilterEXT cppgl_glGetSeparableFilterEXT
typedef void (APIENTRYP PFNGLSEPARABLEFILTER2DEXTPROC)(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *row, const void *column);
GLAPI PFNGLSEPARABLEFILTER2DEXTPROC cppgl_glSeparableFilter2DEXT;
#define glSeparableFilter2DEXT cppgl_glSeparableFilter2DEXT
#endif
#ifndef GL_EXT_coordinate_frame
#define GL_EXT_coordinate_frame 1
GLAPI int CPPGL_GL_EXT_coordinate_frame;
typedef void (APIENTRYP PFNGLTANGENT3BEXTPROC)(GLbyte tx, GLbyte ty, GLbyte tz);
GLAPI PFNGLTANGENT3BEXTPROC cppgl_glTangent3bEXT;
#define glTangent3bEXT cppgl_glTangent3bEXT
typedef void (APIENTRYP PFNGLTANGENT3BVEXTPROC)(const GLbyte *v);
GLAPI PFNGLTANGENT3BVEXTPROC cppgl_glTangent3bvEXT;
#define glTangent3bvEXT cppgl_glTangent3bvEXT
typedef void (APIENTRYP PFNGLTANGENT3DEXTPROC)(GLdouble tx, GLdouble ty, GLdouble tz);
GLAPI PFNGLTANGENT3DEXTPROC cppgl_glTangent3dEXT;
#define glTangent3dEXT cppgl_glTangent3dEXT
typedef void (APIENTRYP PFNGLTANGENT3DVEXTPROC)(const GLdouble *v);
GLAPI PFNGLTANGENT3DVEXTPROC cppgl_glTangent3dvEXT;
#define glTangent3dvEXT cppgl_glTangent3dvEXT
typedef void (APIENTRYP PFNGLTANGENT3FEXTPROC)(GLfloat tx, GLfloat ty, GLfloat tz);
GLAPI PFNGLTANGENT3FEXTPROC cppgl_glTangent3fEXT;
#define glTangent3fEXT cppgl_glTangent3fEXT
typedef void (APIENTRYP PFNGLTANGENT3FVEXTPROC)(const GLfloat *v);
GLAPI PFNGLTANGENT3FVEXTPROC cppgl_glTangent3fvEXT;
#define glTangent3fvEXT cppgl_glTangent3fvEXT
typedef void (APIENTRYP PFNGLTANGENT3IEXTPROC)(GLint tx, GLint ty, GLint tz);
GLAPI PFNGLTANGENT3IEXTPROC cppgl_glTangent3iEXT;
#define glTangent3iEXT cppgl_glTangent3iEXT
typedef void (APIENTRYP PFNGLTANGENT3IVEXTPROC)(const GLint *v);
GLAPI PFNGLTANGENT3IVEXTPROC cppgl_glTangent3ivEXT;
#define glTangent3ivEXT cppgl_glTangent3ivEXT
typedef void (APIENTRYP PFNGLTANGENT3SEXTPROC)(GLshort tx, GLshort ty, GLshort tz);
GLAPI PFNGLTANGENT3SEXTPROC cppgl_glTangent3sEXT;
#define glTangent3sEXT cppgl_glTangent3sEXT
typedef void (APIENTRYP PFNGLTANGENT3SVEXTPROC)(const GLshort *v);
GLAPI PFNGLTANGENT3SVEXTPROC cppgl_glTangent3svEXT;
#define glTangent3svEXT cppgl_glTangent3svEXT
typedef void (APIENTRYP PFNGLBINORMAL3BEXTPROC)(GLbyte bx, GLbyte by, GLbyte bz);
GLAPI PFNGLBINORMAL3BEXTPROC cppgl_glBinormal3bEXT;
#define glBinormal3bEXT cppgl_glBinormal3bEXT
typedef void (APIENTRYP PFNGLBINORMAL3BVEXTPROC)(const GLbyte *v);
GLAPI PFNGLBINORMAL3BVEXTPROC cppgl_glBinormal3bvEXT;
#define glBinormal3bvEXT cppgl_glBinormal3bvEXT
typedef void (APIENTRYP PFNGLBINORMAL3DEXTPROC)(GLdouble bx, GLdouble by, GLdouble bz);
GLAPI PFNGLBINORMAL3DEXTPROC cppgl_glBinormal3dEXT;
#define glBinormal3dEXT cppgl_glBinormal3dEXT
typedef void (APIENTRYP PFNGLBINORMAL3DVEXTPROC)(const GLdouble *v);
GLAPI PFNGLBINORMAL3DVEXTPROC cppgl_glBinormal3dvEXT;
#define glBinormal3dvEXT cppgl_glBinormal3dvEXT
typedef void (APIENTRYP PFNGLBINORMAL3FEXTPROC)(GLfloat bx, GLfloat by, GLfloat bz);
GLAPI PFNGLBINORMAL3FEXTPROC cppgl_glBinormal3fEXT;
#define glBinormal3fEXT cppgl_glBinormal3fEXT
typedef void (APIENTRYP PFNGLBINORMAL3FVEXTPROC)(const GLfloat *v);
GLAPI PFNGLBINORMAL3FVEXTPROC cppgl_glBinormal3fvEXT;
#define glBinormal3fvEXT cppgl_glBinormal3fvEXT
typedef void (APIENTRYP PFNGLBINORMAL3IEXTPROC)(GLint bx, GLint by, GLint bz);
GLAPI PFNGLBINORMAL3IEXTPROC cppgl_glBinormal3iEXT;
#define glBinormal3iEXT cppgl_glBinormal3iEXT
typedef void (APIENTRYP PFNGLBINORMAL3IVEXTPROC)(const GLint *v);
GLAPI PFNGLBINORMAL3IVEXTPROC cppgl_glBinormal3ivEXT;
#define glBinormal3ivEXT cppgl_glBinormal3ivEXT
typedef void (APIENTRYP PFNGLBINORMAL3SEXTPROC)(GLshort bx, GLshort by, GLshort bz);
GLAPI PFNGLBINORMAL3SEXTPROC cppgl_glBinormal3sEXT;
#define glBinormal3sEXT cppgl_glBinormal3sEXT
typedef void (APIENTRYP PFNGLBINORMAL3SVEXTPROC)(const GLshort *v);
GLAPI PFNGLBINORMAL3SVEXTPROC cppgl_glBinormal3svEXT;
#define glBinormal3svEXT cppgl_glBinormal3svEXT
typedef void (APIENTRYP PFNGLTANGENTPOINTEREXTPROC)(GLenum type, GLsizei stride, const void *pointer);
GLAPI PFNGLTANGENTPOINTEREXTPROC cppgl_glTangentPointerEXT;
#define glTangentPointerEXT cppgl_glTangentPointerEXT
typedef void (APIENTRYP PFNGLBINORMALPOINTEREXTPROC)(GLenum type, GLsizei stride, const void *pointer);
GLAPI PFNGLBINORMALPOINTEREXTPROC cppgl_glBinormalPointerEXT;
#define glBinormalPointerEXT cppgl_glBinormalPointerEXT
#endif
#ifndef GL_EXT_copy_texture
#define GL_EXT_copy_texture 1
GLAPI int CPPGL_GL_EXT_copy_texture;
typedef void (APIENTRYP PFNGLCOPYTEXIMAGE1DEXTPROC)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
GLAPI PFNGLCOPYTEXIMAGE1DEXTPROC cppgl_glCopyTexImage1DEXT;
#define glCopyTexImage1DEXT cppgl_glCopyTexImage1DEXT
typedef void (APIENTRYP PFNGLCOPYTEXIMAGE2DEXTPROC)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
GLAPI PFNGLCOPYTEXIMAGE2DEXTPROC cppgl_glCopyTexImage2DEXT;
#define glCopyTexImage2DEXT cppgl_glCopyTexImage2DEXT
typedef void (APIENTRYP PFNGLCOPYTEXSUBIMAGE1DEXTPROC)(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
GLAPI PFNGLCOPYTEXSUBIMAGE1DEXTPROC cppgl_glCopyTexSubImage1DEXT;
#define glCopyTexSubImage1DEXT cppgl_glCopyTexSubImage1DEXT
typedef void (APIENTRYP PFNGLCOPYTEXSUBIMAGE2DEXTPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
GLAPI PFNGLCOPYTEXSUBIMAGE2DEXTPROC cppgl_glCopyTexSubImage2DEXT;
#define glCopyTexSubImage2DEXT cppgl_glCopyTexSubImage2DEXT
typedef void (APIENTRYP PFNGLCOPYTEXSUBIMAGE3DEXTPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
GLAPI PFNGLCOPYTEXSUBIMAGE3DEXTPROC cppgl_glCopyTexSubImage3DEXT;
#define glCopyTexSubImage3DEXT cppgl_glCopyTexSubImage3DEXT
#endif
#ifndef GL_EXT_cull_vertex
#define GL_EXT_cull_vertex 1
GLAPI int CPPGL_GL_EXT_cull_vertex;
typedef void (APIENTRYP PFNGLCULLPARAMETERDVEXTPROC)(GLenum pname, GLdouble *params);
GLAPI PFNGLCULLPARAMETERDVEXTPROC cppgl_glCullParameterdvEXT;
#define glCullParameterdvEXT cppgl_glCullParameterdvEXT
typedef void (APIENTRYP PFNGLCULLPARAMETERFVEXTPROC)(GLenum pname, GLfloat *params);
GLAPI PFNGLCULLPARAMETERFVEXTPROC cppgl_glCullParameterfvEXT;
#define glCullParameterfvEXT cppgl_glCullParameterfvEXT
#endif
#ifndef GL_EXT_debug_label
#define GL_EXT_debug_label 1
GLAPI int CPPGL_GL_EXT_debug_label;
typedef void (APIENTRYP PFNGLLABELOBJECTEXTPROC)(GLenum type, GLuint object, GLsizei length, const GLchar *label);
GLAPI PFNGLLABELOBJECTEXTPROC cppgl_glLabelObjectEXT;
#define glLabelObjectEXT cppgl_glLabelObjectEXT
typedef void (APIENTRYP PFNGLGETOBJECTLABELEXTPROC)(GLenum type, GLuint object, GLsizei bufSize, GLsizei *length, GLchar *label);
GLAPI PFNGLGETOBJECTLABELEXTPROC cppgl_glGetObjectLabelEXT;
#define glGetObjectLabelEXT cppgl_glGetObjectLabelEXT
#endif
#ifndef GL_EXT_debug_marker
#define GL_EXT_debug_marker 1
GLAPI int CPPGL_GL_EXT_debug_marker;
typedef void (APIENTRYP PFNGLINSERTEVENTMARKEREXTPROC)(GLsizei length, const GLchar *marker);
GLAPI PFNGLINSERTEVENTMARKEREXTPROC cppgl_glInsertEventMarkerEXT;
#define glInsertEventMarkerEXT cppgl_glInsertEventMarkerEXT
typedef void (APIENTRYP PFNGLPUSHGROUPMARKEREXTPROC)(GLsizei length, const GLchar *marker);
GLAPI PFNGLPUSHGROUPMARKEREXTPROC cppgl_glPushGroupMarkerEXT;
#define glPushGroupMarkerEXT cppgl_glPushGroupMarkerEXT
typedef void (APIENTRYP PFNGLPOPGROUPMARKEREXTPROC)();
GLAPI PFNGLPOPGROUPMARKEREXTPROC cppgl_glPopGroupMarkerEXT;
#define glPopGroupMarkerEXT cppgl_glPopGroupMarkerEXT
#endif
#ifndef GL_EXT_depth_bounds_test
#define GL_EXT_depth_bounds_test 1
GLAPI int CPPGL_GL_EXT_depth_bounds_test;
typedef void (APIENTRYP PFNGLDEPTHBOUNDSEXTPROC)(GLclampd zmin, GLclampd zmax);
GLAPI PFNGLDEPTHBOUNDSEXTPROC cppgl_glDepthBoundsEXT;
#define glDepthBoundsEXT cppgl_glDepthBoundsEXT
#endif
#ifndef GL_EXT_direct_state_access
#define GL_EXT_direct_state_access 1
GLAPI int CPPGL_GL_EXT_direct_state_access;
typedef void (APIENTRYP PFNGLMATRIXLOADFEXTPROC)(GLenum mode, const GLfloat *m);
GLAPI PFNGLMATRIXLOADFEXTPROC cppgl_glMatrixLoadfEXT;
#define glMatrixLoadfEXT cppgl_glMatrixLoadfEXT
typedef void (APIENTRYP PFNGLMATRIXLOADDEXTPROC)(GLenum mode, const GLdouble *m);
GLAPI PFNGLMATRIXLOADDEXTPROC cppgl_glMatrixLoaddEXT;
#define glMatrixLoaddEXT cppgl_glMatrixLoaddEXT
typedef void (APIENTRYP PFNGLMATRIXMULTFEXTPROC)(GLenum mode, const GLfloat *m);
GLAPI PFNGLMATRIXMULTFEXTPROC cppgl_glMatrixMultfEXT;
#define glMatrixMultfEXT cppgl_glMatrixMultfEXT
typedef void (APIENTRYP PFNGLMATRIXMULTDEXTPROC)(GLenum mode, const GLdouble *m);
GLAPI PFNGLMATRIXMULTDEXTPROC cppgl_glMatrixMultdEXT;
#define glMatrixMultdEXT cppgl_glMatrixMultdEXT
typedef void (APIENTRYP PFNGLMATRIXLOADIDENTITYEXTPROC)(GLenum mode);
GLAPI PFNGLMATRIXLOADIDENTITYEXTPROC cppgl_glMatrixLoadIdentityEXT;
#define glMatrixLoadIdentityEXT cppgl_glMatrixLoadIdentityEXT
typedef void (APIENTRYP PFNGLMATRIXROTATEFEXTPROC)(GLenum mode, GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
GLAPI PFNGLMATRIXROTATEFEXTPROC cppgl_glMatrixRotatefEXT;
#define glMatrixRotatefEXT cppgl_glMatrixRotatefEXT
typedef void (APIENTRYP PFNGLMATRIXROTATEDEXTPROC)(GLenum mode, GLdouble angle, GLdouble x, GLdouble y, GLdouble z);
GLAPI PFNGLMATRIXROTATEDEXTPROC cppgl_glMatrixRotatedEXT;
#define glMatrixRotatedEXT cppgl_glMatrixRotatedEXT
typedef void (APIENTRYP PFNGLMATRIXSCALEFEXTPROC)(GLenum mode, GLfloat x, GLfloat y, GLfloat z);
GLAPI PFNGLMATRIXSCALEFEXTPROC cppgl_glMatrixScalefEXT;
#define glMatrixScalefEXT cppgl_glMatrixScalefEXT
typedef void (APIENTRYP PFNGLMATRIXSCALEDEXTPROC)(GLenum mode, GLdouble x, GLdouble y, GLdouble z);
GLAPI PFNGLMATRIXSCALEDEXTPROC cppgl_glMatrixScaledEXT;
#define glMatrixScaledEXT cppgl_glMatrixScaledEXT
typedef void (APIENTRYP PFNGLMATRIXTRANSLATEFEXTPROC)(GLenum mode, GLfloat x, GLfloat y, GLfloat z);
GLAPI PFNGLMATRIXTRANSLATEFEXTPROC cppgl_glMatrixTranslatefEXT;
#define glMatrixTranslatefEXT cppgl_glMatrixTranslatefEXT
typedef void (APIENTRYP PFNGLMATRIXTRANSLATEDEXTPROC)(GLenum mode, GLdouble x, GLdouble y, GLdouble z);
GLAPI PFNGLMATRIXTRANSLATEDEXTPROC cppgl_glMatrixTranslatedEXT;
#define glMatrixTranslatedEXT cppgl_glMatrixTranslatedEXT
typedef void (APIENTRYP PFNGLMATRIXFRUSTUMEXTPROC)(GLenum mode, GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
GLAPI PFNGLMATRIXFRUSTUMEXTPROC cppgl_glMatrixFrustumEXT;
#define glMatrixFrustumEXT cppgl_glMatrixFrustumEXT
typedef void (APIENTRYP PFNGLMATRIXORTHOEXTPROC)(GLenum mode, GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
GLAPI PFNGLMATRIXORTHOEXTPROC cppgl_glMatrixOrthoEXT;
#define glMatrixOrthoEXT cppgl_glMatrixOrthoEXT
typedef void (APIENTRYP PFNGLMATRIXPOPEXTPROC)(GLenum mode);
GLAPI PFNGLMATRIXPOPEXTPROC cppgl_glMatrixPopEXT;
#define glMatrixPopEXT cppgl_glMatrixPopEXT
typedef void (APIENTRYP PFNGLMATRIXPUSHEXTPROC)(GLenum mode);
GLAPI PFNGLMATRIXPUSHEXTPROC cppgl_glMatrixPushEXT;
#define glMatrixPushEXT cppgl_glMatrixPushEXT
typedef void (APIENTRYP PFNGLCLIENTATTRIBDEFAULTEXTPROC)(GLbitfield mask);
GLAPI PFNGLCLIENTATTRIBDEFAULTEXTPROC cppgl_glClientAttribDefaultEXT;
#define glClientAttribDefaultEXT cppgl_glClientAttribDefaultEXT
typedef void (APIENTRYP PFNGLPUSHCLIENTATTRIBDEFAULTEXTPROC)(GLbitfield mask);
GLAPI PFNGLPUSHCLIENTATTRIBDEFAULTEXTPROC cppgl_glPushClientAttribDefaultEXT;
#define glPushClientAttribDefaultEXT cppgl_glPushClientAttribDefaultEXT
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERFEXTPROC)(GLuint texture, GLenum target, GLenum pname, GLfloat param);
GLAPI PFNGLTEXTUREPARAMETERFEXTPROC cppgl_glTextureParameterfEXT;
#define glTextureParameterfEXT cppgl_glTextureParameterfEXT
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERFVEXTPROC)(GLuint texture, GLenum target, GLenum pname, const GLfloat *params);
GLAPI PFNGLTEXTUREPARAMETERFVEXTPROC cppgl_glTextureParameterfvEXT;
#define glTextureParameterfvEXT cppgl_glTextureParameterfvEXT
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERIEXTPROC)(GLuint texture, GLenum target, GLenum pname, GLint param);
GLAPI PFNGLTEXTUREPARAMETERIEXTPROC cppgl_glTextureParameteriEXT;
#define glTextureParameteriEXT cppgl_glTextureParameteriEXT
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERIVEXTPROC)(GLuint texture, GLenum target, GLenum pname, const GLint *params);
GLAPI PFNGLTEXTUREPARAMETERIVEXTPROC cppgl_glTextureParameterivEXT;
#define glTextureParameterivEXT cppgl_glTextureParameterivEXT
typedef void (APIENTRYP PFNGLTEXTUREIMAGE1DEXTPROC)(GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void *pixels);
GLAPI PFNGLTEXTUREIMAGE1DEXTPROC cppgl_glTextureImage1DEXT;
#define glTextureImage1DEXT cppgl_glTextureImage1DEXT
typedef void (APIENTRYP PFNGLTEXTUREIMAGE2DEXTPROC)(GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void *pixels);
GLAPI PFNGLTEXTUREIMAGE2DEXTPROC cppgl_glTextureImage2DEXT;
#define glTextureImage2DEXT cppgl_glTextureImage2DEXT
typedef void (APIENTRYP PFNGLTEXTURESUBIMAGE1DEXTPROC)(GLuint texture, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels);
GLAPI PFNGLTEXTURESUBIMAGE1DEXTPROC cppgl_glTextureSubImage1DEXT;
#define glTextureSubImage1DEXT cppgl_glTextureSubImage1DEXT
typedef void (APIENTRYP PFNGLTEXTURESUBIMAGE2DEXTPROC)(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
GLAPI PFNGLTEXTURESUBIMAGE2DEXTPROC cppgl_glTextureSubImage2DEXT;
#define glTextureSubImage2DEXT cppgl_glTextureSubImage2DEXT
typedef void (APIENTRYP PFNGLCOPYTEXTUREIMAGE1DEXTPROC)(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
GLAPI PFNGLCOPYTEXTUREIMAGE1DEXTPROC cppgl_glCopyTextureImage1DEXT;
#define glCopyTextureImage1DEXT cppgl_glCopyTextureImage1DEXT
typedef void (APIENTRYP PFNGLCOPYTEXTUREIMAGE2DEXTPROC)(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
GLAPI PFNGLCOPYTEXTUREIMAGE2DEXTPROC cppgl_glCopyTextureImage2DEXT;
#define glCopyTextureImage2DEXT cppgl_glCopyTextureImage2DEXT
typedef void (APIENTRYP PFNGLCOPYTEXTURESUBIMAGE1DEXTPROC)(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
GLAPI PFNGLCOPYTEXTURESUBIMAGE1DEXTPROC cppgl_glCopyTextureSubImage1DEXT;
#define glCopyTextureSubImage1DEXT cppgl_glCopyTextureSubImage1DEXT
typedef void (APIENTRYP PFNGLCOPYTEXTURESUBIMAGE2DEXTPROC)(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
GLAPI PFNGLCOPYTEXTURESUBIMAGE2DEXTPROC cppgl_glCopyTextureSubImage2DEXT;
#define glCopyTextureSubImage2DEXT cppgl_glCopyTextureSubImage2DEXT
typedef void (APIENTRYP PFNGLGETTEXTUREIMAGEEXTPROC)(GLuint texture, GLenum target, GLint level, GLenum format, GLenum type, void *pixels);
GLAPI PFNGLGETTEXTUREIMAGEEXTPROC cppgl_glGetTextureImageEXT;
#define glGetTextureImageEXT cppgl_glGetTextureImageEXT
typedef void (APIENTRYP PFNGLGETTEXTUREPARAMETERFVEXTPROC)(GLuint texture, GLenum target, GLenum pname, GLfloat *params);
GLAPI PFNGLGETTEXTUREPARAMETERFVEXTPROC cppgl_glGetTextureParameterfvEXT;
#define glGetTextureParameterfvEXT cppgl_glGetTextureParameterfvEXT
typedef void (APIENTRYP PFNGLGETTEXTUREPARAMETERIVEXTPROC)(GLuint texture, GLenum target, GLenum pname, GLint *params);
GLAPI PFNGLGETTEXTUREPARAMETERIVEXTPROC cppgl_glGetTextureParameterivEXT;
#define glGetTextureParameterivEXT cppgl_glGetTextureParameterivEXT
typedef void (APIENTRYP PFNGLGETTEXTURELEVELPARAMETERFVEXTPROC)(GLuint texture, GLenum target, GLint level, GLenum pname, GLfloat *params);
GLAPI PFNGLGETTEXTURELEVELPARAMETERFVEXTPROC cppgl_glGetTextureLevelParameterfvEXT;
#define glGetTextureLevelParameterfvEXT cppgl_glGetTextureLevelParameterfvEXT
typedef void (APIENTRYP PFNGLGETTEXTURELEVELPARAMETERIVEXTPROC)(GLuint texture, GLenum target, GLint level, GLenum pname, GLint *params);
GLAPI PFNGLGETTEXTURELEVELPARAMETERIVEXTPROC cppgl_glGetTextureLevelParameterivEXT;
#define glGetTextureLevelParameterivEXT cppgl_glGetTextureLevelParameterivEXT
typedef void (APIENTRYP PFNGLTEXTUREIMAGE3DEXTPROC)(GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels);
GLAPI PFNGLTEXTUREIMAGE3DEXTPROC cppgl_glTextureImage3DEXT;
#define glTextureImage3DEXT cppgl_glTextureImage3DEXT
typedef void (APIENTRYP PFNGLTEXTURESUBIMAGE3DEXTPROC)(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels);
GLAPI PFNGLTEXTURESUBIMAGE3DEXTPROC cppgl_glTextureSubImage3DEXT;
#define glTextureSubImage3DEXT cppgl_glTextureSubImage3DEXT
typedef void (APIENTRYP PFNGLCOPYTEXTURESUBIMAGE3DEXTPROC)(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
GLAPI PFNGLCOPYTEXTURESUBIMAGE3DEXTPROC cppgl_glCopyTextureSubImage3DEXT;
#define glCopyTextureSubImage3DEXT cppgl_glCopyTextureSubImage3DEXT
typedef void (APIENTRYP PFNGLBINDMULTITEXTUREEXTPROC)(GLenum texunit, GLenum target, GLuint texture);
GLAPI PFNGLBINDMULTITEXTUREEXTPROC cppgl_glBindMultiTextureEXT;
#define glBindMultiTextureEXT cppgl_glBindMultiTextureEXT
typedef void (APIENTRYP PFNGLMULTITEXCOORDPOINTEREXTPROC)(GLenum texunit, GLint size, GLenum type, GLsizei stride, const void *pointer);
GLAPI PFNGLMULTITEXCOORDPOINTEREXTPROC cppgl_glMultiTexCoordPointerEXT;
#define glMultiTexCoordPointerEXT cppgl_glMultiTexCoordPointerEXT
typedef void (APIENTRYP PFNGLMULTITEXENVFEXTPROC)(GLenum texunit, GLenum target, GLenum pname, GLfloat param);
GLAPI PFNGLMULTITEXENVFEXTPROC cppgl_glMultiTexEnvfEXT;
#define glMultiTexEnvfEXT cppgl_glMultiTexEnvfEXT
typedef void (APIENTRYP PFNGLMULTITEXENVFVEXTPROC)(GLenum texunit, GLenum target, GLenum pname, const GLfloat *params);
GLAPI PFNGLMULTITEXENVFVEXTPROC cppgl_glMultiTexEnvfvEXT;
#define glMultiTexEnvfvEXT cppgl_glMultiTexEnvfvEXT
typedef void (APIENTRYP PFNGLMULTITEXENVIEXTPROC)(GLenum texunit, GLenum target, GLenum pname, GLint param);
GLAPI PFNGLMULTITEXENVIEXTPROC cppgl_glMultiTexEnviEXT;
#define glMultiTexEnviEXT cppgl_glMultiTexEnviEXT
typedef void (APIENTRYP PFNGLMULTITEXENVIVEXTPROC)(GLenum texunit, GLenum target, GLenum pname, const GLint *params);
GLAPI PFNGLMULTITEXENVIVEXTPROC cppgl_glMultiTexEnvivEXT;
#define glMultiTexEnvivEXT cppgl_glMultiTexEnvivEXT
typedef void (APIENTRYP PFNGLMULTITEXGENDEXTPROC)(GLenum texunit, GLenum coord, GLenum pname, GLdouble param);
GLAPI PFNGLMULTITEXGENDEXTPROC cppgl_glMultiTexGendEXT;
#define glMultiTexGendEXT cppgl_glMultiTexGendEXT
typedef void (APIENTRYP PFNGLMULTITEXGENDVEXTPROC)(GLenum texunit, GLenum coord, GLenum pname, const GLdouble *params);
GLAPI PFNGLMULTITEXGENDVEXTPROC cppgl_glMultiTexGendvEXT;
#define glMultiTexGendvEXT cppgl_glMultiTexGendvEXT
typedef void (APIENTRYP PFNGLMULTITEXGENFEXTPROC)(GLenum texunit, GLenum coord, GLenum pname, GLfloat param);
GLAPI PFNGLMULTITEXGENFEXTPROC cppgl_glMultiTexGenfEXT;
#define glMultiTexGenfEXT cppgl_glMultiTexGenfEXT
typedef void (APIENTRYP PFNGLMULTITEXGENFVEXTPROC)(GLenum texunit, GLenum coord, GLenum pname, const GLfloat *params);
GLAPI PFNGLMULTITEXGENFVEXTPROC cppgl_glMultiTexGenfvEXT;
#define glMultiTexGenfvEXT cppgl_glMultiTexGenfvEXT
typedef void (APIENTRYP PFNGLMULTITEXGENIEXTPROC)(GLenum texunit, GLenum coord, GLenum pname, GLint param);
GLAPI PFNGLMULTITEXGENIEXTPROC cppgl_glMultiTexGeniEXT;
#define glMultiTexGeniEXT cppgl_glMultiTexGeniEXT
typedef void (APIENTRYP PFNGLMULTITEXGENIVEXTPROC)(GLenum texunit, GLenum coord, GLenum pname, const GLint *params);
GLAPI PFNGLMULTITEXGENIVEXTPROC cppgl_glMultiTexGenivEXT;
#define glMultiTexGenivEXT cppgl_glMultiTexGenivEXT
typedef void (APIENTRYP PFNGLGETMULTITEXENVFVEXTPROC)(GLenum texunit, GLenum target, GLenum pname, GLfloat *params);
GLAPI PFNGLGETMULTITEXENVFVEXTPROC cppgl_glGetMultiTexEnvfvEXT;
#define glGetMultiTexEnvfvEXT cppgl_glGetMultiTexEnvfvEXT
typedef void (APIENTRYP PFNGLGETMULTITEXENVIVEXTPROC)(GLenum texunit, GLenum target, GLenum pname, GLint *params);
GLAPI PFNGLGETMULTITEXENVIVEXTPROC cppgl_glGetMultiTexEnvivEXT;
#define glGetMultiTexEnvivEXT cppgl_glGetMultiTexEnvivEXT
typedef void (APIENTRYP PFNGLGETMULTITEXGENDVEXTPROC)(GLenum texunit, GLenum coord, GLenum pname, GLdouble *params);
GLAPI PFNGLGETMULTITEXGENDVEXTPROC cppgl_glGetMultiTexGendvEXT;
#define glGetMultiTexGendvEXT cppgl_glGetMultiTexGendvEXT
typedef void (APIENTRYP PFNGLGETMULTITEXGENFVEXTPROC)(GLenum texunit, GLenum coord, GLenum pname, GLfloat *params);
GLAPI PFNGLGETMULTITEXGENFVEXTPROC cppgl_glGetMultiTexGenfvEXT;
#define glGetMultiTexGenfvEXT cppgl_glGetMultiTexGenfvEXT
typedef void (APIENTRYP PFNGLGETMULTITEXGENIVEXTPROC)(GLenum texunit, GLenum coord, GLenum pname, GLint *params);
GLAPI PFNGLGETMULTITEXGENIVEXTPROC cppgl_glGetMultiTexGenivEXT;
#define glGetMultiTexGenivEXT cppgl_glGetMultiTexGenivEXT
typedef void (APIENTRYP PFNGLMULTITEXPARAMETERIEXTPROC)(GLenum texunit, GLenum target, GLenum pname, GLint param);
GLAPI PFNGLMULTITEXPARAMETERIEXTPROC cppgl_glMultiTexParameteriEXT;
#define glMultiTexParameteriEXT cppgl_glMultiTexParameteriEXT
typedef void (APIENTRYP PFNGLMULTITEXPARAMETERIVEXTPROC)(GLenum texunit, GLenum target, GLenum pname, const GLint *params);
GLAPI PFNGLMULTITEXPARAMETERIVEXTPROC cppgl_glMultiTexParameterivEXT;
#define glMultiTexParameterivEXT cppgl_glMultiTexParameterivEXT
typedef void (APIENTRYP PFNGLMULTITEXPARAMETERFEXTPROC)(GLenum texunit, GLenum target, GLenum pname, GLfloat param);
GLAPI PFNGLMULTITEXPARAMETERFEXTPROC cppgl_glMultiTexParameterfEXT;
#define glMultiTexParameterfEXT cppgl_glMultiTexParameterfEXT
typedef void (APIENTRYP PFNGLMULTITEXPARAMETERFVEXTPROC)(GLenum texunit, GLenum target, GLenum pname, const GLfloat *params);
GLAPI PFNGLMULTITEXPARAMETERFVEXTPROC cppgl_glMultiTexParameterfvEXT;
#define glMultiTexParameterfvEXT cppgl_glMultiTexParameterfvEXT
typedef void (APIENTRYP PFNGLMULTITEXIMAGE1DEXTPROC)(GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void *pixels);
GLAPI PFNGLMULTITEXIMAGE1DEXTPROC cppgl_glMultiTexImage1DEXT;
#define glMultiTexImage1DEXT cppgl_glMultiTexImage1DEXT
typedef void (APIENTRYP PFNGLMULTITEXIMAGE2DEXTPROC)(GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void *pixels);
GLAPI PFNGLMULTITEXIMAGE2DEXTPROC cppgl_glMultiTexImage2DEXT;
#define glMultiTexImage2DEXT cppgl_glMultiTexImage2DEXT
typedef void (APIENTRYP PFNGLMULTITEXSUBIMAGE1DEXTPROC)(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels);
GLAPI PFNGLMULTITEXSUBIMAGE1DEXTPROC cppgl_glMultiTexSubImage1DEXT;
#define glMultiTexSubImage1DEXT cppgl_glMultiTexSubImage1DEXT
typedef void (APIENTRYP PFNGLMULTITEXSUBIMAGE2DEXTPROC)(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
GLAPI PFNGLMULTITEXSUBIMAGE2DEXTPROC cppgl_glMultiTexSubImage2DEXT;
#define glMultiTexSubImage2DEXT cppgl_glMultiTexSubImage2DEXT
typedef void (APIENTRYP PFNGLCOPYMULTITEXIMAGE1DEXTPROC)(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
GLAPI PFNGLCOPYMULTITEXIMAGE1DEXTPROC cppgl_glCopyMultiTexImage1DEXT;
#define glCopyMultiTexImage1DEXT cppgl_glCopyMultiTexImage1DEXT
typedef void (APIENTRYP PFNGLCOPYMULTITEXIMAGE2DEXTPROC)(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
GLAPI PFNGLCOPYMULTITEXIMAGE2DEXTPROC cppgl_glCopyMultiTexImage2DEXT;
#define glCopyMultiTexImage2DEXT cppgl_glCopyMultiTexImage2DEXT
typedef void (APIENTRYP PFNGLCOPYMULTITEXSUBIMAGE1DEXTPROC)(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
GLAPI PFNGLCOPYMULTITEXSUBIMAGE1DEXTPROC cppgl_glCopyMultiTexSubImage1DEXT;
#define glCopyMultiTexSubImage1DEXT cppgl_glCopyMultiTexSubImage1DEXT
typedef void (APIENTRYP PFNGLCOPYMULTITEXSUBIMAGE2DEXTPROC)(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
GLAPI PFNGLCOPYMULTITEXSUBIMAGE2DEXTPROC cppgl_glCopyMultiTexSubImage2DEXT;
#define glCopyMultiTexSubImage2DEXT cppgl_glCopyMultiTexSubImage2DEXT
typedef void (APIENTRYP PFNGLGETMULTITEXIMAGEEXTPROC)(GLenum texunit, GLenum target, GLint level, GLenum format, GLenum type, void *pixels);
GLAPI PFNGLGETMULTITEXIMAGEEXTPROC cppgl_glGetMultiTexImageEXT;
#define glGetMultiTexImageEXT cppgl_glGetMultiTexImageEXT
typedef void (APIENTRYP PFNGLGETMULTITEXPARAMETERFVEXTPROC)(GLenum texunit, GLenum target, GLenum pname, GLfloat *params);
GLAPI PFNGLGETMULTITEXPARAMETERFVEXTPROC cppgl_glGetMultiTexParameterfvEXT;
#define glGetMultiTexParameterfvEXT cppgl_glGetMultiTexParameterfvEXT
typedef void (APIENTRYP PFNGLGETMULTITEXPARAMETERIVEXTPROC)(GLenum texunit, GLenum target, GLenum pname, GLint *params);
GLAPI PFNGLGETMULTITEXPARAMETERIVEXTPROC cppgl_glGetMultiTexParameterivEXT;
#define glGetMultiTexParameterivEXT cppgl_glGetMultiTexParameterivEXT
typedef void (APIENTRYP PFNGLGETMULTITEXLEVELPARAMETERFVEXTPROC)(GLenum texunit, GLenum target, GLint level, GLenum pname, GLfloat *params);
GLAPI PFNGLGETMULTITEXLEVELPARAMETERFVEXTPROC cppgl_glGetMultiTexLevelParameterfvEXT;
#define glGetMultiTexLevelParameterfvEXT cppgl_glGetMultiTexLevelParameterfvEXT
typedef void (APIENTRYP PFNGLGETMULTITEXLEVELPARAMETERIVEXTPROC)(GLenum texunit, GLenum target, GLint level, GLenum pname, GLint *params);
GLAPI PFNGLGETMULTITEXLEVELPARAMETERIVEXTPROC cppgl_glGetMultiTexLevelParameterivEXT;
#define glGetMultiTexLevelParameterivEXT cppgl_glGetMultiTexLevelParameterivEXT
typedef void (APIENTRYP PFNGLMULTITEXIMAGE3DEXTPROC)(GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels);
GLAPI PFNGLMULTITEXIMAGE3DEXTPROC cppgl_glMultiTexImage3DEXT;
#define glMultiTexImage3DEXT cppgl_glMultiTexImage3DEXT
typedef void (APIENTRYP PFNGLMULTITEXSUBIMAGE3DEXTPROC)(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels);
GLAPI PFNGLMULTITEXSUBIMAGE3DEXTPROC cppgl_glMultiTexSubImage3DEXT;
#define glMultiTexSubImage3DEXT cppgl_glMultiTexSubImage3DEXT
typedef void (APIENTRYP PFNGLCOPYMULTITEXSUBIMAGE3DEXTPROC)(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
GLAPI PFNGLCOPYMULTITEXSUBIMAGE3DEXTPROC cppgl_glCopyMultiTexSubImage3DEXT;
#define glCopyMultiTexSubImage3DEXT cppgl_glCopyMultiTexSubImage3DEXT
typedef void (APIENTRYP PFNGLENABLECLIENTSTATEINDEXEDEXTPROC)(GLenum array, GLuint index);
GLAPI PFNGLENABLECLIENTSTATEINDEXEDEXTPROC cppgl_glEnableClientStateIndexedEXT;
#define glEnableClientStateIndexedEXT cppgl_glEnableClientStateIndexedEXT
typedef void (APIENTRYP PFNGLDISABLECLIENTSTATEINDEXEDEXTPROC)(GLenum array, GLuint index);
GLAPI PFNGLDISABLECLIENTSTATEINDEXEDEXTPROC cppgl_glDisableClientStateIndexedEXT;
#define glDisableClientStateIndexedEXT cppgl_glDisableClientStateIndexedEXT
typedef void (APIENTRYP PFNGLGETFLOATINDEXEDVEXTPROC)(GLenum target, GLuint index, GLfloat *data);
GLAPI PFNGLGETFLOATINDEXEDVEXTPROC cppgl_glGetFloatIndexedvEXT;
#define glGetFloatIndexedvEXT cppgl_glGetFloatIndexedvEXT
typedef void (APIENTRYP PFNGLGETDOUBLEINDEXEDVEXTPROC)(GLenum target, GLuint index, GLdouble *data);
GLAPI PFNGLGETDOUBLEINDEXEDVEXTPROC cppgl_glGetDoubleIndexedvEXT;
#define glGetDoubleIndexedvEXT cppgl_glGetDoubleIndexedvEXT
typedef void (APIENTRYP PFNGLGETPOINTERINDEXEDVEXTPROC)(GLenum target, GLuint index, void **data);
GLAPI PFNGLGETPOINTERINDEXEDVEXTPROC cppgl_glGetPointerIndexedvEXT;
#define glGetPointerIndexedvEXT cppgl_glGetPointerIndexedvEXT
typedef void (APIENTRYP PFNGLENABLEINDEXEDEXTPROC)(GLenum target, GLuint index);
GLAPI PFNGLENABLEINDEXEDEXTPROC cppgl_glEnableIndexedEXT;
#define glEnableIndexedEXT cppgl_glEnableIndexedEXT
typedef void (APIENTRYP PFNGLDISABLEINDEXEDEXTPROC)(GLenum target, GLuint index);
GLAPI PFNGLDISABLEINDEXEDEXTPROC cppgl_glDisableIndexedEXT;
#define glDisableIndexedEXT cppgl_glDisableIndexedEXT
typedef GLboolean (APIENTRYP PFNGLISENABLEDINDEXEDEXTPROC)(GLenum target, GLuint index);
GLAPI PFNGLISENABLEDINDEXEDEXTPROC cppgl_glIsEnabledIndexedEXT;
#define glIsEnabledIndexedEXT cppgl_glIsEnabledIndexedEXT
typedef void (APIENTRYP PFNGLGETINTEGERINDEXEDVEXTPROC)(GLenum target, GLuint index, GLint *data);
GLAPI PFNGLGETINTEGERINDEXEDVEXTPROC cppgl_glGetIntegerIndexedvEXT;
#define glGetIntegerIndexedvEXT cppgl_glGetIntegerIndexedvEXT
typedef void (APIENTRYP PFNGLGETBOOLEANINDEXEDVEXTPROC)(GLenum target, GLuint index, GLboolean *data);
GLAPI PFNGLGETBOOLEANINDEXEDVEXTPROC cppgl_glGetBooleanIndexedvEXT;
#define glGetBooleanIndexedvEXT cppgl_glGetBooleanIndexedvEXT
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXTUREIMAGE3DEXTPROC)(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *bits);
GLAPI PFNGLCOMPRESSEDTEXTUREIMAGE3DEXTPROC cppgl_glCompressedTextureImage3DEXT;
#define glCompressedTextureImage3DEXT cppgl_glCompressedTextureImage3DEXT
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXTUREIMAGE2DEXTPROC)(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *bits);
GLAPI PFNGLCOMPRESSEDTEXTUREIMAGE2DEXTPROC cppgl_glCompressedTextureImage2DEXT;
#define glCompressedTextureImage2DEXT cppgl_glCompressedTextureImage2DEXT
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXTUREIMAGE1DEXTPROC)(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void *bits);
GLAPI PFNGLCOMPRESSEDTEXTUREIMAGE1DEXTPROC cppgl_glCompressedTextureImage1DEXT;
#define glCompressedTextureImage1DEXT cppgl_glCompressedTextureImage1DEXT
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXTURESUBIMAGE3DEXTPROC)(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *bits);
GLAPI PFNGLCOMPRESSEDTEXTURESUBIMAGE3DEXTPROC cppgl_glCompressedTextureSubImage3DEXT;
#define glCompressedTextureSubImage3DEXT cppgl_glCompressedTextureSubImage3DEXT
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXTURESUBIMAGE2DEXTPROC)(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *bits);
GLAPI PFNGLCOMPRESSEDTEXTURESUBIMAGE2DEXTPROC cppgl_glCompressedTextureSubImage2DEXT;
#define glCompressedTextureSubImage2DEXT cppgl_glCompressedTextureSubImage2DEXT
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXTURESUBIMAGE1DEXTPROC)(GLuint texture, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *bits);
GLAPI PFNGLCOMPRESSEDTEXTURESUBIMAGE1DEXTPROC cppgl_glCompressedTextureSubImage1DEXT;
#define glCompressedTextureSubImage1DEXT cppgl_glCompressedTextureSubImage1DEXT
typedef void (APIENTRYP PFNGLGETCOMPRESSEDTEXTUREIMAGEEXTPROC)(GLuint texture, GLenum target, GLint lod, void *img);
GLAPI PFNGLGETCOMPRESSEDTEXTUREIMAGEEXTPROC cppgl_glGetCompressedTextureImageEXT;
#define glGetCompressedTextureImageEXT cppgl_glGetCompressedTextureImageEXT
typedef void (APIENTRYP PFNGLCOMPRESSEDMULTITEXIMAGE3DEXTPROC)(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *bits);
GLAPI PFNGLCOMPRESSEDMULTITEXIMAGE3DEXTPROC cppgl_glCompressedMultiTexImage3DEXT;
#define glCompressedMultiTexImage3DEXT cppgl_glCompressedMultiTexImage3DEXT
typedef void (APIENTRYP PFNGLCOMPRESSEDMULTITEXIMAGE2DEXTPROC)(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *bits);
GLAPI PFNGLCOMPRESSEDMULTITEXIMAGE2DEXTPROC cppgl_glCompressedMultiTexImage2DEXT;
#define glCompressedMultiTexImage2DEXT cppgl_glCompressedMultiTexImage2DEXT
typedef void (APIENTRYP PFNGLCOMPRESSEDMULTITEXIMAGE1DEXTPROC)(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void *bits);
GLAPI PFNGLCOMPRESSEDMULTITEXIMAGE1DEXTPROC cppgl_glCompressedMultiTexImage1DEXT;
#define glCompressedMultiTexImage1DEXT cppgl_glCompressedMultiTexImage1DEXT
typedef void (APIENTRYP PFNGLCOMPRESSEDMULTITEXSUBIMAGE3DEXTPROC)(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *bits);
GLAPI PFNGLCOMPRESSEDMULTITEXSUBIMAGE3DEXTPROC cppgl_glCompressedMultiTexSubImage3DEXT;
#define glCompressedMultiTexSubImage3DEXT cppgl_glCompressedMultiTexSubImage3DEXT
typedef void (APIENTRYP PFNGLCOMPRESSEDMULTITEXSUBIMAGE2DEXTPROC)(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *bits);
GLAPI PFNGLCOMPRESSEDMULTITEXSUBIMAGE2DEXTPROC cppgl_glCompressedMultiTexSubImage2DEXT;
#define glCompressedMultiTexSubImage2DEXT cppgl_glCompressedMultiTexSubImage2DEXT
typedef void (APIENTRYP PFNGLCOMPRESSEDMULTITEXSUBIMAGE1DEXTPROC)(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *bits);
GLAPI PFNGLCOMPRESSEDMULTITEXSUBIMAGE1DEXTPROC cppgl_glCompressedMultiTexSubImage1DEXT;
#define glCompressedMultiTexSubImage1DEXT cppgl_glCompressedMultiTexSubImage1DEXT
typedef void (APIENTRYP PFNGLGETCOMPRESSEDMULTITEXIMAGEEXTPROC)(GLenum texunit, GLenum target, GLint lod, void *img);
GLAPI PFNGLGETCOMPRESSEDMULTITEXIMAGEEXTPROC cppgl_glGetCompressedMultiTexImageEXT;
#define glGetCompressedMultiTexImageEXT cppgl_glGetCompressedMultiTexImageEXT
typedef void (APIENTRYP PFNGLMATRIXLOADTRANSPOSEFEXTPROC)(GLenum mode, const GLfloat *m);
GLAPI PFNGLMATRIXLOADTRANSPOSEFEXTPROC cppgl_glMatrixLoadTransposefEXT;
#define glMatrixLoadTransposefEXT cppgl_glMatrixLoadTransposefEXT
typedef void (APIENTRYP PFNGLMATRIXLOADTRANSPOSEDEXTPROC)(GLenum mode, const GLdouble *m);
GLAPI PFNGLMATRIXLOADTRANSPOSEDEXTPROC cppgl_glMatrixLoadTransposedEXT;
#define glMatrixLoadTransposedEXT cppgl_glMatrixLoadTransposedEXT
typedef void (APIENTRYP PFNGLMATRIXMULTTRANSPOSEFEXTPROC)(GLenum mode, const GLfloat *m);
GLAPI PFNGLMATRIXMULTTRANSPOSEFEXTPROC cppgl_glMatrixMultTransposefEXT;
#define glMatrixMultTransposefEXT cppgl_glMatrixMultTransposefEXT
typedef void (APIENTRYP PFNGLMATRIXMULTTRANSPOSEDEXTPROC)(GLenum mode, const GLdouble *m);
GLAPI PFNGLMATRIXMULTTRANSPOSEDEXTPROC cppgl_glMatrixMultTransposedEXT;
#define glMatrixMultTransposedEXT cppgl_glMatrixMultTransposedEXT
typedef void (APIENTRYP PFNGLNAMEDBUFFERDATAEXTPROC)(GLuint buffer, GLsizeiptr size, const void *data, GLenum usage);
GLAPI PFNGLNAMEDBUFFERDATAEXTPROC cppgl_glNamedBufferDataEXT;
#define glNamedBufferDataEXT cppgl_glNamedBufferDataEXT
typedef void (APIENTRYP PFNGLNAMEDBUFFERSUBDATAEXTPROC)(GLuint buffer, GLintptr offset, GLsizeiptr size, const void *data);
GLAPI PFNGLNAMEDBUFFERSUBDATAEXTPROC cppgl_glNamedBufferSubDataEXT;
#define glNamedBufferSubDataEXT cppgl_glNamedBufferSubDataEXT
typedef void * (APIENTRYP PFNGLMAPNAMEDBUFFEREXTPROC)(GLuint buffer, GLenum access);
GLAPI PFNGLMAPNAMEDBUFFEREXTPROC cppgl_glMapNamedBufferEXT;
#define glMapNamedBufferEXT cppgl_glMapNamedBufferEXT
typedef GLboolean (APIENTRYP PFNGLUNMAPNAMEDBUFFEREXTPROC)(GLuint buffer);
GLAPI PFNGLUNMAPNAMEDBUFFEREXTPROC cppgl_glUnmapNamedBufferEXT;
#define glUnmapNamedBufferEXT cppgl_glUnmapNamedBufferEXT
typedef void (APIENTRYP PFNGLGETNAMEDBUFFERPARAMETERIVEXTPROC)(GLuint buffer, GLenum pname, GLint *params);
GLAPI PFNGLGETNAMEDBUFFERPARAMETERIVEXTPROC cppgl_glGetNamedBufferParameterivEXT;
#define glGetNamedBufferParameterivEXT cppgl_glGetNamedBufferParameterivEXT
typedef void (APIENTRYP PFNGLGETNAMEDBUFFERPOINTERVEXTPROC)(GLuint buffer, GLenum pname, void **params);
GLAPI PFNGLGETNAMEDBUFFERPOINTERVEXTPROC cppgl_glGetNamedBufferPointervEXT;
#define glGetNamedBufferPointervEXT cppgl_glGetNamedBufferPointervEXT
typedef void (APIENTRYP PFNGLGETNAMEDBUFFERSUBDATAEXTPROC)(GLuint buffer, GLintptr offset, GLsizeiptr size, void *data);
GLAPI PFNGLGETNAMEDBUFFERSUBDATAEXTPROC cppgl_glGetNamedBufferSubDataEXT;
#define glGetNamedBufferSubDataEXT cppgl_glGetNamedBufferSubDataEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1FEXTPROC)(GLuint program, GLint location, GLfloat v0);
GLAPI PFNGLPROGRAMUNIFORM1FEXTPROC cppgl_glProgramUniform1fEXT;
#define glProgramUniform1fEXT cppgl_glProgramUniform1fEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2FEXTPROC)(GLuint program, GLint location, GLfloat v0, GLfloat v1);
GLAPI PFNGLPROGRAMUNIFORM2FEXTPROC cppgl_glProgramUniform2fEXT;
#define glProgramUniform2fEXT cppgl_glProgramUniform2fEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3FEXTPROC)(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
GLAPI PFNGLPROGRAMUNIFORM3FEXTPROC cppgl_glProgramUniform3fEXT;
#define glProgramUniform3fEXT cppgl_glProgramUniform3fEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4FEXTPROC)(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
GLAPI PFNGLPROGRAMUNIFORM4FEXTPROC cppgl_glProgramUniform4fEXT;
#define glProgramUniform4fEXT cppgl_glProgramUniform4fEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1IEXTPROC)(GLuint program, GLint location, GLint v0);
GLAPI PFNGLPROGRAMUNIFORM1IEXTPROC cppgl_glProgramUniform1iEXT;
#define glProgramUniform1iEXT cppgl_glProgramUniform1iEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2IEXTPROC)(GLuint program, GLint location, GLint v0, GLint v1);
GLAPI PFNGLPROGRAMUNIFORM2IEXTPROC cppgl_glProgramUniform2iEXT;
#define glProgramUniform2iEXT cppgl_glProgramUniform2iEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3IEXTPROC)(GLuint program, GLint location, GLint v0, GLint v1, GLint v2);
GLAPI PFNGLPROGRAMUNIFORM3IEXTPROC cppgl_glProgramUniform3iEXT;
#define glProgramUniform3iEXT cppgl_glProgramUniform3iEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4IEXTPROC)(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
GLAPI PFNGLPROGRAMUNIFORM4IEXTPROC cppgl_glProgramUniform4iEXT;
#define glProgramUniform4iEXT cppgl_glProgramUniform4iEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1FVEXTPROC)(GLuint program, GLint location, GLsizei count, const GLfloat *value);
GLAPI PFNGLPROGRAMUNIFORM1FVEXTPROC cppgl_glProgramUniform1fvEXT;
#define glProgramUniform1fvEXT cppgl_glProgramUniform1fvEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2FVEXTPROC)(GLuint program, GLint location, GLsizei count, const GLfloat *value);
GLAPI PFNGLPROGRAMUNIFORM2FVEXTPROC cppgl_glProgramUniform2fvEXT;
#define glProgramUniform2fvEXT cppgl_glProgramUniform2fvEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3FVEXTPROC)(GLuint program, GLint location, GLsizei count, const GLfloat *value);
GLAPI PFNGLPROGRAMUNIFORM3FVEXTPROC cppgl_glProgramUniform3fvEXT;
#define glProgramUniform3fvEXT cppgl_glProgramUniform3fvEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4FVEXTPROC)(GLuint program, GLint location, GLsizei count, const GLfloat *value);
GLAPI PFNGLPROGRAMUNIFORM4FVEXTPROC cppgl_glProgramUniform4fvEXT;
#define glProgramUniform4fvEXT cppgl_glProgramUniform4fvEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1IVEXTPROC)(GLuint program, GLint location, GLsizei count, const GLint *value);
GLAPI PFNGLPROGRAMUNIFORM1IVEXTPROC cppgl_glProgramUniform1ivEXT;
#define glProgramUniform1ivEXT cppgl_glProgramUniform1ivEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2IVEXTPROC)(GLuint program, GLint location, GLsizei count, const GLint *value);
GLAPI PFNGLPROGRAMUNIFORM2IVEXTPROC cppgl_glProgramUniform2ivEXT;
#define glProgramUniform2ivEXT cppgl_glProgramUniform2ivEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3IVEXTPROC)(GLuint program, GLint location, GLsizei count, const GLint *value);
GLAPI PFNGLPROGRAMUNIFORM3IVEXTPROC cppgl_glProgramUniform3ivEXT;
#define glProgramUniform3ivEXT cppgl_glProgramUniform3ivEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4IVEXTPROC)(GLuint program, GLint location, GLsizei count, const GLint *value);
GLAPI PFNGLPROGRAMUNIFORM4IVEXTPROC cppgl_glProgramUniform4ivEXT;
#define glProgramUniform4ivEXT cppgl_glProgramUniform4ivEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2FVEXTPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI PFNGLPROGRAMUNIFORMMATRIX2FVEXTPROC cppgl_glProgramUniformMatrix2fvEXT;
#define glProgramUniformMatrix2fvEXT cppgl_glProgramUniformMatrix2fvEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3FVEXTPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI PFNGLPROGRAMUNIFORMMATRIX3FVEXTPROC cppgl_glProgramUniformMatrix3fvEXT;
#define glProgramUniformMatrix3fvEXT cppgl_glProgramUniformMatrix3fvEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4FVEXTPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI PFNGLPROGRAMUNIFORMMATRIX4FVEXTPROC cppgl_glProgramUniformMatrix4fvEXT;
#define glProgramUniformMatrix4fvEXT cppgl_glProgramUniformMatrix4fvEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X3FVEXTPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI PFNGLPROGRAMUNIFORMMATRIX2X3FVEXTPROC cppgl_glProgramUniformMatrix2x3fvEXT;
#define glProgramUniformMatrix2x3fvEXT cppgl_glProgramUniformMatrix2x3fvEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X2FVEXTPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI PFNGLPROGRAMUNIFORMMATRIX3X2FVEXTPROC cppgl_glProgramUniformMatrix3x2fvEXT;
#define glProgramUniformMatrix3x2fvEXT cppgl_glProgramUniformMatrix3x2fvEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X4FVEXTPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI PFNGLPROGRAMUNIFORMMATRIX2X4FVEXTPROC cppgl_glProgramUniformMatrix2x4fvEXT;
#define glProgramUniformMatrix2x4fvEXT cppgl_glProgramUniformMatrix2x4fvEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X2FVEXTPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI PFNGLPROGRAMUNIFORMMATRIX4X2FVEXTPROC cppgl_glProgramUniformMatrix4x2fvEXT;
#define glProgramUniformMatrix4x2fvEXT cppgl_glProgramUniformMatrix4x2fvEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X4FVEXTPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI PFNGLPROGRAMUNIFORMMATRIX3X4FVEXTPROC cppgl_glProgramUniformMatrix3x4fvEXT;
#define glProgramUniformMatrix3x4fvEXT cppgl_glProgramUniformMatrix3x4fvEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X3FVEXTPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI PFNGLPROGRAMUNIFORMMATRIX4X3FVEXTPROC cppgl_glProgramUniformMatrix4x3fvEXT;
#define glProgramUniformMatrix4x3fvEXT cppgl_glProgramUniformMatrix4x3fvEXT
typedef void (APIENTRYP PFNGLTEXTUREBUFFEREXTPROC)(GLuint texture, GLenum target, GLenum internalformat, GLuint buffer);
GLAPI PFNGLTEXTUREBUFFEREXTPROC cppgl_glTextureBufferEXT;
#define glTextureBufferEXT cppgl_glTextureBufferEXT
typedef void (APIENTRYP PFNGLMULTITEXBUFFEREXTPROC)(GLenum texunit, GLenum target, GLenum internalformat, GLuint buffer);
GLAPI PFNGLMULTITEXBUFFEREXTPROC cppgl_glMultiTexBufferEXT;
#define glMultiTexBufferEXT cppgl_glMultiTexBufferEXT
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERIIVEXTPROC)(GLuint texture, GLenum target, GLenum pname, const GLint *params);
GLAPI PFNGLTEXTUREPARAMETERIIVEXTPROC cppgl_glTextureParameterIivEXT;
#define glTextureParameterIivEXT cppgl_glTextureParameterIivEXT
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERIUIVEXTPROC)(GLuint texture, GLenum target, GLenum pname, const GLuint *params);
GLAPI PFNGLTEXTUREPARAMETERIUIVEXTPROC cppgl_glTextureParameterIuivEXT;
#define glTextureParameterIuivEXT cppgl_glTextureParameterIuivEXT
typedef void (APIENTRYP PFNGLGETTEXTUREPARAMETERIIVEXTPROC)(GLuint texture, GLenum target, GLenum pname, GLint *params);
GLAPI PFNGLGETTEXTUREPARAMETERIIVEXTPROC cppgl_glGetTextureParameterIivEXT;
#define glGetTextureParameterIivEXT cppgl_glGetTextureParameterIivEXT
typedef void (APIENTRYP PFNGLGETTEXTUREPARAMETERIUIVEXTPROC)(GLuint texture, GLenum target, GLenum pname, GLuint *params);
GLAPI PFNGLGETTEXTUREPARAMETERIUIVEXTPROC cppgl_glGetTextureParameterIuivEXT;
#define glGetTextureParameterIuivEXT cppgl_glGetTextureParameterIuivEXT
typedef void (APIENTRYP PFNGLMULTITEXPARAMETERIIVEXTPROC)(GLenum texunit, GLenum target, GLenum pname, const GLint *params);
GLAPI PFNGLMULTITEXPARAMETERIIVEXTPROC cppgl_glMultiTexParameterIivEXT;
#define glMultiTexParameterIivEXT cppgl_glMultiTexParameterIivEXT
typedef void (APIENTRYP PFNGLMULTITEXPARAMETERIUIVEXTPROC)(GLenum texunit, GLenum target, GLenum pname, const GLuint *params);
GLAPI PFNGLMULTITEXPARAMETERIUIVEXTPROC cppgl_glMultiTexParameterIuivEXT;
#define glMultiTexParameterIuivEXT cppgl_glMultiTexParameterIuivEXT
typedef void (APIENTRYP PFNGLGETMULTITEXPARAMETERIIVEXTPROC)(GLenum texunit, GLenum target, GLenum pname, GLint *params);
GLAPI PFNGLGETMULTITEXPARAMETERIIVEXTPROC cppgl_glGetMultiTexParameterIivEXT;
#define glGetMultiTexParameterIivEXT cppgl_glGetMultiTexParameterIivEXT
typedef void (APIENTRYP PFNGLGETMULTITEXPARAMETERIUIVEXTPROC)(GLenum texunit, GLenum target, GLenum pname, GLuint *params);
GLAPI PFNGLGETMULTITEXPARAMETERIUIVEXTPROC cppgl_glGetMultiTexParameterIuivEXT;
#define glGetMultiTexParameterIuivEXT cppgl_glGetMultiTexParameterIuivEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1UIEXTPROC)(GLuint program, GLint location, GLuint v0);
GLAPI PFNGLPROGRAMUNIFORM1UIEXTPROC cppgl_glProgramUniform1uiEXT;
#define glProgramUniform1uiEXT cppgl_glProgramUniform1uiEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2UIEXTPROC)(GLuint program, GLint location, GLuint v0, GLuint v1);
GLAPI PFNGLPROGRAMUNIFORM2UIEXTPROC cppgl_glProgramUniform2uiEXT;
#define glProgramUniform2uiEXT cppgl_glProgramUniform2uiEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3UIEXTPROC)(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2);
GLAPI PFNGLPROGRAMUNIFORM3UIEXTPROC cppgl_glProgramUniform3uiEXT;
#define glProgramUniform3uiEXT cppgl_glProgramUniform3uiEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4UIEXTPROC)(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
GLAPI PFNGLPROGRAMUNIFORM4UIEXTPROC cppgl_glProgramUniform4uiEXT;
#define glProgramUniform4uiEXT cppgl_glProgramUniform4uiEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1UIVEXTPROC)(GLuint program, GLint location, GLsizei count, const GLuint *value);
GLAPI PFNGLPROGRAMUNIFORM1UIVEXTPROC cppgl_glProgramUniform1uivEXT;
#define glProgramUniform1uivEXT cppgl_glProgramUniform1uivEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2UIVEXTPROC)(GLuint program, GLint location, GLsizei count, const GLuint *value);
GLAPI PFNGLPROGRAMUNIFORM2UIVEXTPROC cppgl_glProgramUniform2uivEXT;
#define glProgramUniform2uivEXT cppgl_glProgramUniform2uivEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3UIVEXTPROC)(GLuint program, GLint location, GLsizei count, const GLuint *value);
GLAPI PFNGLPROGRAMUNIFORM3UIVEXTPROC cppgl_glProgramUniform3uivEXT;
#define glProgramUniform3uivEXT cppgl_glProgramUniform3uivEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4UIVEXTPROC)(GLuint program, GLint location, GLsizei count, const GLuint *value);
GLAPI PFNGLPROGRAMUNIFORM4UIVEXTPROC cppgl_glProgramUniform4uivEXT;
#define glProgramUniform4uivEXT cppgl_glProgramUniform4uivEXT
typedef void (APIENTRYP PFNGLNAMEDPROGRAMLOCALPARAMETERS4FVEXTPROC)(GLuint program, GLenum target, GLuint index, GLsizei count, const GLfloat *params);
GLAPI PFNGLNAMEDPROGRAMLOCALPARAMETERS4FVEXTPROC cppgl_glNamedProgramLocalParameters4fvEXT;
#define glNamedProgramLocalParameters4fvEXT cppgl_glNamedProgramLocalParameters4fvEXT
typedef void (APIENTRYP PFNGLNAMEDPROGRAMLOCALPARAMETERI4IEXTPROC)(GLuint program, GLenum target, GLuint index, GLint x, GLint y, GLint z, GLint w);
GLAPI PFNGLNAMEDPROGRAMLOCALPARAMETERI4IEXTPROC cppgl_glNamedProgramLocalParameterI4iEXT;
#define glNamedProgramLocalParameterI4iEXT cppgl_glNamedProgramLocalParameterI4iEXT
typedef void (APIENTRYP PFNGLNAMEDPROGRAMLOCALPARAMETERI4IVEXTPROC)(GLuint program, GLenum target, GLuint index, const GLint *params);
GLAPI PFNGLNAMEDPROGRAMLOCALPARAMETERI4IVEXTPROC cppgl_glNamedProgramLocalParameterI4ivEXT;
#define glNamedProgramLocalParameterI4ivEXT cppgl_glNamedProgramLocalParameterI4ivEXT
typedef void (APIENTRYP PFNGLNAMEDPROGRAMLOCALPARAMETERSI4IVEXTPROC)(GLuint program, GLenum target, GLuint index, GLsizei count, const GLint *params);
GLAPI PFNGLNAMEDPROGRAMLOCALPARAMETERSI4IVEXTPROC cppgl_glNamedProgramLocalParametersI4ivEXT;
#define glNamedProgramLocalParametersI4ivEXT cppgl_glNamedProgramLocalParametersI4ivEXT
typedef void (APIENTRYP PFNGLNAMEDPROGRAMLOCALPARAMETERI4UIEXTPROC)(GLuint program, GLenum target, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
GLAPI PFNGLNAMEDPROGRAMLOCALPARAMETERI4UIEXTPROC cppgl_glNamedProgramLocalParameterI4uiEXT;
#define glNamedProgramLocalParameterI4uiEXT cppgl_glNamedProgramLocalParameterI4uiEXT
typedef void (APIENTRYP PFNGLNAMEDPROGRAMLOCALPARAMETERI4UIVEXTPROC)(GLuint program, GLenum target, GLuint index, const GLuint *params);
GLAPI PFNGLNAMEDPROGRAMLOCALPARAMETERI4UIVEXTPROC cppgl_glNamedProgramLocalParameterI4uivEXT;
#define glNamedProgramLocalParameterI4uivEXT cppgl_glNamedProgramLocalParameterI4uivEXT
typedef void (APIENTRYP PFNGLNAMEDPROGRAMLOCALPARAMETERSI4UIVEXTPROC)(GLuint program, GLenum target, GLuint index, GLsizei count, const GLuint *params);
GLAPI PFNGLNAMEDPROGRAMLOCALPARAMETERSI4UIVEXTPROC cppgl_glNamedProgramLocalParametersI4uivEXT;
#define glNamedProgramLocalParametersI4uivEXT cppgl_glNamedProgramLocalParametersI4uivEXT
typedef void (APIENTRYP PFNGLGETNAMEDPROGRAMLOCALPARAMETERIIVEXTPROC)(GLuint program, GLenum target, GLuint index, GLint *params);
GLAPI PFNGLGETNAMEDPROGRAMLOCALPARAMETERIIVEXTPROC cppgl_glGetNamedProgramLocalParameterIivEXT;
#define glGetNamedProgramLocalParameterIivEXT cppgl_glGetNamedProgramLocalParameterIivEXT
typedef void (APIENTRYP PFNGLGETNAMEDPROGRAMLOCALPARAMETERIUIVEXTPROC)(GLuint program, GLenum target, GLuint index, GLuint *params);
GLAPI PFNGLGETNAMEDPROGRAMLOCALPARAMETERIUIVEXTPROC cppgl_glGetNamedProgramLocalParameterIuivEXT;
#define glGetNamedProgramLocalParameterIuivEXT cppgl_glGetNamedProgramLocalParameterIuivEXT
typedef void (APIENTRYP PFNGLENABLECLIENTSTATEIEXTPROC)(GLenum array, GLuint index);
GLAPI PFNGLENABLECLIENTSTATEIEXTPROC cppgl_glEnableClientStateiEXT;
#define glEnableClientStateiEXT cppgl_glEnableClientStateiEXT
typedef void (APIENTRYP PFNGLDISABLECLIENTSTATEIEXTPROC)(GLenum array, GLuint index);
GLAPI PFNGLDISABLECLIENTSTATEIEXTPROC cppgl_glDisableClientStateiEXT;
#define glDisableClientStateiEXT cppgl_glDisableClientStateiEXT
typedef void (APIENTRYP PFNGLGETFLOATI_VEXTPROC)(GLenum pname, GLuint index, GLfloat *params);
GLAPI PFNGLGETFLOATI_VEXTPROC cppgl_glGetFloati_vEXT;
#define glGetFloati_vEXT cppgl_glGetFloati_vEXT
typedef void (APIENTRYP PFNGLGETDOUBLEI_VEXTPROC)(GLenum pname, GLuint index, GLdouble *params);
GLAPI PFNGLGETDOUBLEI_VEXTPROC cppgl_glGetDoublei_vEXT;
#define glGetDoublei_vEXT cppgl_glGetDoublei_vEXT
typedef void (APIENTRYP PFNGLGETPOINTERI_VEXTPROC)(GLenum pname, GLuint index, void **params);
GLAPI PFNGLGETPOINTERI_VEXTPROC cppgl_glGetPointeri_vEXT;
#define glGetPointeri_vEXT cppgl_glGetPointeri_vEXT
typedef void (APIENTRYP PFNGLNAMEDPROGRAMSTRINGEXTPROC)(GLuint program, GLenum target, GLenum format, GLsizei len, const void *string);
GLAPI PFNGLNAMEDPROGRAMSTRINGEXTPROC cppgl_glNamedProgramStringEXT;
#define glNamedProgramStringEXT cppgl_glNamedProgramStringEXT
typedef void (APIENTRYP PFNGLNAMEDPROGRAMLOCALPARAMETER4DEXTPROC)(GLuint program, GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
GLAPI PFNGLNAMEDPROGRAMLOCALPARAMETER4DEXTPROC cppgl_glNamedProgramLocalParameter4dEXT;
#define glNamedProgramLocalParameter4dEXT cppgl_glNamedProgramLocalParameter4dEXT
typedef void (APIENTRYP PFNGLNAMEDPROGRAMLOCALPARAMETER4DVEXTPROC)(GLuint program, GLenum target, GLuint index, const GLdouble *params);
GLAPI PFNGLNAMEDPROGRAMLOCALPARAMETER4DVEXTPROC cppgl_glNamedProgramLocalParameter4dvEXT;
#define glNamedProgramLocalParameter4dvEXT cppgl_glNamedProgramLocalParameter4dvEXT
typedef void (APIENTRYP PFNGLNAMEDPROGRAMLOCALPARAMETER4FEXTPROC)(GLuint program, GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
GLAPI PFNGLNAMEDPROGRAMLOCALPARAMETER4FEXTPROC cppgl_glNamedProgramLocalParameter4fEXT;
#define glNamedProgramLocalParameter4fEXT cppgl_glNamedProgramLocalParameter4fEXT
typedef void (APIENTRYP PFNGLNAMEDPROGRAMLOCALPARAMETER4FVEXTPROC)(GLuint program, GLenum target, GLuint index, const GLfloat *params);
GLAPI PFNGLNAMEDPROGRAMLOCALPARAMETER4FVEXTPROC cppgl_glNamedProgramLocalParameter4fvEXT;
#define glNamedProgramLocalParameter4fvEXT cppgl_glNamedProgramLocalParameter4fvEXT
typedef void (APIENTRYP PFNGLGETNAMEDPROGRAMLOCALPARAMETERDVEXTPROC)(GLuint program, GLenum target, GLuint index, GLdouble *params);
GLAPI PFNGLGETNAMEDPROGRAMLOCALPARAMETERDVEXTPROC cppgl_glGetNamedProgramLocalParameterdvEXT;
#define glGetNamedProgramLocalParameterdvEXT cppgl_glGetNamedProgramLocalParameterdvEXT
typedef void (APIENTRYP PFNGLGETNAMEDPROGRAMLOCALPARAMETERFVEXTPROC)(GLuint program, GLenum target, GLuint index, GLfloat *params);
GLAPI PFNGLGETNAMEDPROGRAMLOCALPARAMETERFVEXTPROC cppgl_glGetNamedProgramLocalParameterfvEXT;
#define glGetNamedProgramLocalParameterfvEXT cppgl_glGetNamedProgramLocalParameterfvEXT
typedef void (APIENTRYP PFNGLGETNAMEDPROGRAMIVEXTPROC)(GLuint program, GLenum target, GLenum pname, GLint *params);
GLAPI PFNGLGETNAMEDPROGRAMIVEXTPROC cppgl_glGetNamedProgramivEXT;
#define glGetNamedProgramivEXT cppgl_glGetNamedProgramivEXT
typedef void (APIENTRYP PFNGLGETNAMEDPROGRAMSTRINGEXTPROC)(GLuint program, GLenum target, GLenum pname, void *string);
GLAPI PFNGLGETNAMEDPROGRAMSTRINGEXTPROC cppgl_glGetNamedProgramStringEXT;
#define glGetNamedProgramStringEXT cppgl_glGetNamedProgramStringEXT
typedef void (APIENTRYP PFNGLNAMEDRENDERBUFFERSTORAGEEXTPROC)(GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height);
GLAPI PFNGLNAMEDRENDERBUFFERSTORAGEEXTPROC cppgl_glNamedRenderbufferStorageEXT;
#define glNamedRenderbufferStorageEXT cppgl_glNamedRenderbufferStorageEXT
typedef void (APIENTRYP PFNGLGETNAMEDRENDERBUFFERPARAMETERIVEXTPROC)(GLuint renderbuffer, GLenum pname, GLint *params);
GLAPI PFNGLGETNAMEDRENDERBUFFERPARAMETERIVEXTPROC cppgl_glGetNamedRenderbufferParameterivEXT;
#define glGetNamedRenderbufferParameterivEXT cppgl_glGetNamedRenderbufferParameterivEXT
typedef void (APIENTRYP PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEEXTPROC)(GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
GLAPI PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEEXTPROC cppgl_glNamedRenderbufferStorageMultisampleEXT;
#define glNamedRenderbufferStorageMultisampleEXT cppgl_glNamedRenderbufferStorageMultisampleEXT
typedef void (APIENTRYP PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLECOVERAGEEXTPROC)(GLuint renderbuffer, GLsizei coverageSamples, GLsizei colorSamples, GLenum internalformat, GLsizei width, GLsizei height);
GLAPI PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLECOVERAGEEXTPROC cppgl_glNamedRenderbufferStorageMultisampleCoverageEXT;
#define glNamedRenderbufferStorageMultisampleCoverageEXT cppgl_glNamedRenderbufferStorageMultisampleCoverageEXT
typedef GLenum (APIENTRYP PFNGLCHECKNAMEDFRAMEBUFFERSTATUSEXTPROC)(GLuint framebuffer, GLenum target);
GLAPI PFNGLCHECKNAMEDFRAMEBUFFERSTATUSEXTPROC cppgl_glCheckNamedFramebufferStatusEXT;
#define glCheckNamedFramebufferStatusEXT cppgl_glCheckNamedFramebufferStatusEXT
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERTEXTURE1DEXTPROC)(GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
GLAPI PFNGLNAMEDFRAMEBUFFERTEXTURE1DEXTPROC cppgl_glNamedFramebufferTexture1DEXT;
#define glNamedFramebufferTexture1DEXT cppgl_glNamedFramebufferTexture1DEXT
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERTEXTURE2DEXTPROC)(GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
GLAPI PFNGLNAMEDFRAMEBUFFERTEXTURE2DEXTPROC cppgl_glNamedFramebufferTexture2DEXT;
#define glNamedFramebufferTexture2DEXT cppgl_glNamedFramebufferTexture2DEXT
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERTEXTURE3DEXTPROC)(GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
GLAPI PFNGLNAMEDFRAMEBUFFERTEXTURE3DEXTPROC cppgl_glNamedFramebufferTexture3DEXT;
#define glNamedFramebufferTexture3DEXT cppgl_glNamedFramebufferTexture3DEXT
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERRENDERBUFFEREXTPROC)(GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
GLAPI PFNGLNAMEDFRAMEBUFFERRENDERBUFFEREXTPROC cppgl_glNamedFramebufferRenderbufferEXT;
#define glNamedFramebufferRenderbufferEXT cppgl_glNamedFramebufferRenderbufferEXT
typedef void (APIENTRYP PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVEXTPROC)(GLuint framebuffer, GLenum attachment, GLenum pname, GLint *params);
GLAPI PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVEXTPROC cppgl_glGetNamedFramebufferAttachmentParameterivEXT;
#define glGetNamedFramebufferAttachmentParameterivEXT cppgl_glGetNamedFramebufferAttachmentParameterivEXT
typedef void (APIENTRYP PFNGLGENERATETEXTUREMIPMAPEXTPROC)(GLuint texture, GLenum target);
GLAPI PFNGLGENERATETEXTUREMIPMAPEXTPROC cppgl_glGenerateTextureMipmapEXT;
#define glGenerateTextureMipmapEXT cppgl_glGenerateTextureMipmapEXT
typedef void (APIENTRYP PFNGLGENERATEMULTITEXMIPMAPEXTPROC)(GLenum texunit, GLenum target);
GLAPI PFNGLGENERATEMULTITEXMIPMAPEXTPROC cppgl_glGenerateMultiTexMipmapEXT;
#define glGenerateMultiTexMipmapEXT cppgl_glGenerateMultiTexMipmapEXT
typedef void (APIENTRYP PFNGLFRAMEBUFFERDRAWBUFFEREXTPROC)(GLuint framebuffer, GLenum mode);
GLAPI PFNGLFRAMEBUFFERDRAWBUFFEREXTPROC cppgl_glFramebufferDrawBufferEXT;
#define glFramebufferDrawBufferEXT cppgl_glFramebufferDrawBufferEXT
typedef void (APIENTRYP PFNGLFRAMEBUFFERDRAWBUFFERSEXTPROC)(GLuint framebuffer, GLsizei n, const GLenum *bufs);
GLAPI PFNGLFRAMEBUFFERDRAWBUFFERSEXTPROC cppgl_glFramebufferDrawBuffersEXT;
#define glFramebufferDrawBuffersEXT cppgl_glFramebufferDrawBuffersEXT
typedef void (APIENTRYP PFNGLFRAMEBUFFERREADBUFFEREXTPROC)(GLuint framebuffer, GLenum mode);
GLAPI PFNGLFRAMEBUFFERREADBUFFEREXTPROC cppgl_glFramebufferReadBufferEXT;
#define glFramebufferReadBufferEXT cppgl_glFramebufferReadBufferEXT
typedef void (APIENTRYP PFNGLGETFRAMEBUFFERPARAMETERIVEXTPROC)(GLuint framebuffer, GLenum pname, GLint *params);
GLAPI PFNGLGETFRAMEBUFFERPARAMETERIVEXTPROC cppgl_glGetFramebufferParameterivEXT;
#define glGetFramebufferParameterivEXT cppgl_glGetFramebufferParameterivEXT
typedef void (APIENTRYP PFNGLNAMEDCOPYBUFFERSUBDATAEXTPROC)(GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
GLAPI PFNGLNAMEDCOPYBUFFERSUBDATAEXTPROC cppgl_glNamedCopyBufferSubDataEXT;
#define glNamedCopyBufferSubDataEXT cppgl_glNamedCopyBufferSubDataEXT
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERTEXTUREEXTPROC)(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level);
GLAPI PFNGLNAMEDFRAMEBUFFERTEXTUREEXTPROC cppgl_glNamedFramebufferTextureEXT;
#define glNamedFramebufferTextureEXT cppgl_glNamedFramebufferTextureEXT
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERTEXTURELAYEREXTPROC)(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer);
GLAPI PFNGLNAMEDFRAMEBUFFERTEXTURELAYEREXTPROC cppgl_glNamedFramebufferTextureLayerEXT;
#define glNamedFramebufferTextureLayerEXT cppgl_glNamedFramebufferTextureLayerEXT
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERTEXTUREFACEEXTPROC)(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLenum face);
GLAPI PFNGLNAMEDFRAMEBUFFERTEXTUREFACEEXTPROC cppgl_glNamedFramebufferTextureFaceEXT;
#define glNamedFramebufferTextureFaceEXT cppgl_glNamedFramebufferTextureFaceEXT
typedef void (APIENTRYP PFNGLTEXTURERENDERBUFFEREXTPROC)(GLuint texture, GLenum target, GLuint renderbuffer);
GLAPI PFNGLTEXTURERENDERBUFFEREXTPROC cppgl_glTextureRenderbufferEXT;
#define glTextureRenderbufferEXT cppgl_glTextureRenderbufferEXT
typedef void (APIENTRYP PFNGLMULTITEXRENDERBUFFEREXTPROC)(GLenum texunit, GLenum target, GLuint renderbuffer);
GLAPI PFNGLMULTITEXRENDERBUFFEREXTPROC cppgl_glMultiTexRenderbufferEXT;
#define glMultiTexRenderbufferEXT cppgl_glMultiTexRenderbufferEXT
typedef void (APIENTRYP PFNGLVERTEXARRAYVERTEXOFFSETEXTPROC)(GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset);
GLAPI PFNGLVERTEXARRAYVERTEXOFFSETEXTPROC cppgl_glVertexArrayVertexOffsetEXT;
#define glVertexArrayVertexOffsetEXT cppgl_glVertexArrayVertexOffsetEXT
typedef void (APIENTRYP PFNGLVERTEXARRAYCOLOROFFSETEXTPROC)(GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset);
GLAPI PFNGLVERTEXARRAYCOLOROFFSETEXTPROC cppgl_glVertexArrayColorOffsetEXT;
#define glVertexArrayColorOffsetEXT cppgl_glVertexArrayColorOffsetEXT
typedef void (APIENTRYP PFNGLVERTEXARRAYEDGEFLAGOFFSETEXTPROC)(GLuint vaobj, GLuint buffer, GLsizei stride, GLintptr offset);
GLAPI PFNGLVERTEXARRAYEDGEFLAGOFFSETEXTPROC cppgl_glVertexArrayEdgeFlagOffsetEXT;
#define glVertexArrayEdgeFlagOffsetEXT cppgl_glVertexArrayEdgeFlagOffsetEXT
typedef void (APIENTRYP PFNGLVERTEXARRAYINDEXOFFSETEXTPROC)(GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset);
GLAPI PFNGLVERTEXARRAYINDEXOFFSETEXTPROC cppgl_glVertexArrayIndexOffsetEXT;
#define glVertexArrayIndexOffsetEXT cppgl_glVertexArrayIndexOffsetEXT
typedef void (APIENTRYP PFNGLVERTEXARRAYNORMALOFFSETEXTPROC)(GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset);
GLAPI PFNGLVERTEXARRAYNORMALOFFSETEXTPROC cppgl_glVertexArrayNormalOffsetEXT;
#define glVertexArrayNormalOffsetEXT cppgl_glVertexArrayNormalOffsetEXT
typedef void (APIENTRYP PFNGLVERTEXARRAYTEXCOORDOFFSETEXTPROC)(GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset);
GLAPI PFNGLVERTEXARRAYTEXCOORDOFFSETEXTPROC cppgl_glVertexArrayTexCoordOffsetEXT;
#define glVertexArrayTexCoordOffsetEXT cppgl_glVertexArrayTexCoordOffsetEXT
typedef void (APIENTRYP PFNGLVERTEXARRAYMULTITEXCOORDOFFSETEXTPROC)(GLuint vaobj, GLuint buffer, GLenum texunit, GLint size, GLenum type, GLsizei stride, GLintptr offset);
GLAPI PFNGLVERTEXARRAYMULTITEXCOORDOFFSETEXTPROC cppgl_glVertexArrayMultiTexCoordOffsetEXT;
#define glVertexArrayMultiTexCoordOffsetEXT cppgl_glVertexArrayMultiTexCoordOffsetEXT
typedef void (APIENTRYP PFNGLVERTEXARRAYFOGCOORDOFFSETEXTPROC)(GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset);
GLAPI PFNGLVERTEXARRAYFOGCOORDOFFSETEXTPROC cppgl_glVertexArrayFogCoordOffsetEXT;
#define glVertexArrayFogCoordOffsetEXT cppgl_glVertexArrayFogCoordOffsetEXT
typedef void (APIENTRYP PFNGLVERTEXARRAYSECONDARYCOLOROFFSETEXTPROC)(GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset);
GLAPI PFNGLVERTEXARRAYSECONDARYCOLOROFFSETEXTPROC cppgl_glVertexArraySecondaryColorOffsetEXT;
#define glVertexArraySecondaryColorOffsetEXT cppgl_glVertexArraySecondaryColorOffsetEXT
typedef void (APIENTRYP PFNGLVERTEXARRAYVERTEXATTRIBOFFSETEXTPROC)(GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLintptr offset);
GLAPI PFNGLVERTEXARRAYVERTEXATTRIBOFFSETEXTPROC cppgl_glVertexArrayVertexAttribOffsetEXT;
#define glVertexArrayVertexAttribOffsetEXT cppgl_glVertexArrayVertexAttribOffsetEXT
typedef void (APIENTRYP PFNGLVERTEXARRAYVERTEXATTRIBIOFFSETEXTPROC)(GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLsizei stride, GLintptr offset);
GLAPI PFNGLVERTEXARRAYVERTEXATTRIBIOFFSETEXTPROC cppgl_glVertexArrayVertexAttribIOffsetEXT;
#define glVertexArrayVertexAttribIOffsetEXT cppgl_glVertexArrayVertexAttribIOffsetEXT
typedef void (APIENTRYP PFNGLENABLEVERTEXARRAYEXTPROC)(GLuint vaobj, GLenum array);
GLAPI PFNGLENABLEVERTEXARRAYEXTPROC cppgl_glEnableVertexArrayEXT;
#define glEnableVertexArrayEXT cppgl_glEnableVertexArrayEXT
typedef void (APIENTRYP PFNGLDISABLEVERTEXARRAYEXTPROC)(GLuint vaobj, GLenum array);
GLAPI PFNGLDISABLEVERTEXARRAYEXTPROC cppgl_glDisableVertexArrayEXT;
#define glDisableVertexArrayEXT cppgl_glDisableVertexArrayEXT
typedef void (APIENTRYP PFNGLENABLEVERTEXARRAYATTRIBEXTPROC)(GLuint vaobj, GLuint index);
GLAPI PFNGLENABLEVERTEXARRAYATTRIBEXTPROC cppgl_glEnableVertexArrayAttribEXT;
#define glEnableVertexArrayAttribEXT cppgl_glEnableVertexArrayAttribEXT
typedef void (APIENTRYP PFNGLDISABLEVERTEXARRAYATTRIBEXTPROC)(GLuint vaobj, GLuint index);
GLAPI PFNGLDISABLEVERTEXARRAYATTRIBEXTPROC cppgl_glDisableVertexArrayAttribEXT;
#define glDisableVertexArrayAttribEXT cppgl_glDisableVertexArrayAttribEXT
typedef void (APIENTRYP PFNGLGETVERTEXARRAYINTEGERVEXTPROC)(GLuint vaobj, GLenum pname, GLint *param);
GLAPI PFNGLGETVERTEXARRAYINTEGERVEXTPROC cppgl_glGetVertexArrayIntegervEXT;
#define glGetVertexArrayIntegervEXT cppgl_glGetVertexArrayIntegervEXT
typedef void (APIENTRYP PFNGLGETVERTEXARRAYPOINTERVEXTPROC)(GLuint vaobj, GLenum pname, void **param);
GLAPI PFNGLGETVERTEXARRAYPOINTERVEXTPROC cppgl_glGetVertexArrayPointervEXT;
#define glGetVertexArrayPointervEXT cppgl_glGetVertexArrayPointervEXT
typedef void (APIENTRYP PFNGLGETVERTEXARRAYINTEGERI_VEXTPROC)(GLuint vaobj, GLuint index, GLenum pname, GLint *param);
GLAPI PFNGLGETVERTEXARRAYINTEGERI_VEXTPROC cppgl_glGetVertexArrayIntegeri_vEXT;
#define glGetVertexArrayIntegeri_vEXT cppgl_glGetVertexArrayIntegeri_vEXT
typedef void (APIENTRYP PFNGLGETVERTEXARRAYPOINTERI_VEXTPROC)(GLuint vaobj, GLuint index, GLenum pname, void **param);
GLAPI PFNGLGETVERTEXARRAYPOINTERI_VEXTPROC cppgl_glGetVertexArrayPointeri_vEXT;
#define glGetVertexArrayPointeri_vEXT cppgl_glGetVertexArrayPointeri_vEXT
typedef void * (APIENTRYP PFNGLMAPNAMEDBUFFERRANGEEXTPROC)(GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access);
GLAPI PFNGLMAPNAMEDBUFFERRANGEEXTPROC cppgl_glMapNamedBufferRangeEXT;
#define glMapNamedBufferRangeEXT cppgl_glMapNamedBufferRangeEXT
typedef void (APIENTRYP PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEEXTPROC)(GLuint buffer, GLintptr offset, GLsizeiptr length);
GLAPI PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEEXTPROC cppgl_glFlushMappedNamedBufferRangeEXT;
#define glFlushMappedNamedBufferRangeEXT cppgl_glFlushMappedNamedBufferRangeEXT
typedef void (APIENTRYP PFNGLNAMEDBUFFERSTORAGEEXTPROC)(GLuint buffer, GLsizeiptr size, const void *data, GLbitfield flags);
GLAPI PFNGLNAMEDBUFFERSTORAGEEXTPROC cppgl_glNamedBufferStorageEXT;
#define glNamedBufferStorageEXT cppgl_glNamedBufferStorageEXT
typedef void (APIENTRYP PFNGLCLEARNAMEDBUFFERDATAEXTPROC)(GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const void *data);
GLAPI PFNGLCLEARNAMEDBUFFERDATAEXTPROC cppgl_glClearNamedBufferDataEXT;
#define glClearNamedBufferDataEXT cppgl_glClearNamedBufferDataEXT
typedef void (APIENTRYP PFNGLCLEARNAMEDBUFFERSUBDATAEXTPROC)(GLuint buffer, GLenum internalformat, GLsizeiptr offset, GLsizeiptr size, GLenum format, GLenum type, const void *data);
GLAPI PFNGLCLEARNAMEDBUFFERSUBDATAEXTPROC cppgl_glClearNamedBufferSubDataEXT;
#define glClearNamedBufferSubDataEXT cppgl_glClearNamedBufferSubDataEXT
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERPARAMETERIEXTPROC)(GLuint framebuffer, GLenum pname, GLint param);
GLAPI PFNGLNAMEDFRAMEBUFFERPARAMETERIEXTPROC cppgl_glNamedFramebufferParameteriEXT;
#define glNamedFramebufferParameteriEXT cppgl_glNamedFramebufferParameteriEXT
typedef void (APIENTRYP PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVEXTPROC)(GLuint framebuffer, GLenum pname, GLint *params);
GLAPI PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVEXTPROC cppgl_glGetNamedFramebufferParameterivEXT;
#define glGetNamedFramebufferParameterivEXT cppgl_glGetNamedFramebufferParameterivEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1DEXTPROC)(GLuint program, GLint location, GLdouble x);
GLAPI PFNGLPROGRAMUNIFORM1DEXTPROC cppgl_glProgramUniform1dEXT;
#define glProgramUniform1dEXT cppgl_glProgramUniform1dEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2DEXTPROC)(GLuint program, GLint location, GLdouble x, GLdouble y);
GLAPI PFNGLPROGRAMUNIFORM2DEXTPROC cppgl_glProgramUniform2dEXT;
#define glProgramUniform2dEXT cppgl_glProgramUniform2dEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3DEXTPROC)(GLuint program, GLint location, GLdouble x, GLdouble y, GLdouble z);
GLAPI PFNGLPROGRAMUNIFORM3DEXTPROC cppgl_glProgramUniform3dEXT;
#define glProgramUniform3dEXT cppgl_glProgramUniform3dEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4DEXTPROC)(GLuint program, GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
GLAPI PFNGLPROGRAMUNIFORM4DEXTPROC cppgl_glProgramUniform4dEXT;
#define glProgramUniform4dEXT cppgl_glProgramUniform4dEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1DVEXTPROC)(GLuint program, GLint location, GLsizei count, const GLdouble *value);
GLAPI PFNGLPROGRAMUNIFORM1DVEXTPROC cppgl_glProgramUniform1dvEXT;
#define glProgramUniform1dvEXT cppgl_glProgramUniform1dvEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2DVEXTPROC)(GLuint program, GLint location, GLsizei count, const GLdouble *value);
GLAPI PFNGLPROGRAMUNIFORM2DVEXTPROC cppgl_glProgramUniform2dvEXT;
#define glProgramUniform2dvEXT cppgl_glProgramUniform2dvEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3DVEXTPROC)(GLuint program, GLint location, GLsizei count, const GLdouble *value);
GLAPI PFNGLPROGRAMUNIFORM3DVEXTPROC cppgl_glProgramUniform3dvEXT;
#define glProgramUniform3dvEXT cppgl_glProgramUniform3dvEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4DVEXTPROC)(GLuint program, GLint location, GLsizei count, const GLdouble *value);
GLAPI PFNGLPROGRAMUNIFORM4DVEXTPROC cppgl_glProgramUniform4dvEXT;
#define glProgramUniform4dvEXT cppgl_glProgramUniform4dvEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2DVEXTPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI PFNGLPROGRAMUNIFORMMATRIX2DVEXTPROC cppgl_glProgramUniformMatrix2dvEXT;
#define glProgramUniformMatrix2dvEXT cppgl_glProgramUniformMatrix2dvEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3DVEXTPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI PFNGLPROGRAMUNIFORMMATRIX3DVEXTPROC cppgl_glProgramUniformMatrix3dvEXT;
#define glProgramUniformMatrix3dvEXT cppgl_glProgramUniformMatrix3dvEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4DVEXTPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI PFNGLPROGRAMUNIFORMMATRIX4DVEXTPROC cppgl_glProgramUniformMatrix4dvEXT;
#define glProgramUniformMatrix4dvEXT cppgl_glProgramUniformMatrix4dvEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X3DVEXTPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI PFNGLPROGRAMUNIFORMMATRIX2X3DVEXTPROC cppgl_glProgramUniformMatrix2x3dvEXT;
#define glProgramUniformMatrix2x3dvEXT cppgl_glProgramUniformMatrix2x3dvEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X4DVEXTPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI PFNGLPROGRAMUNIFORMMATRIX2X4DVEXTPROC cppgl_glProgramUniformMatrix2x4dvEXT;
#define glProgramUniformMatrix2x4dvEXT cppgl_glProgramUniformMatrix2x4dvEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X2DVEXTPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI PFNGLPROGRAMUNIFORMMATRIX3X2DVEXTPROC cppgl_glProgramUniformMatrix3x2dvEXT;
#define glProgramUniformMatrix3x2dvEXT cppgl_glProgramUniformMatrix3x2dvEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X4DVEXTPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI PFNGLPROGRAMUNIFORMMATRIX3X4DVEXTPROC cppgl_glProgramUniformMatrix3x4dvEXT;
#define glProgramUniformMatrix3x4dvEXT cppgl_glProgramUniformMatrix3x4dvEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X2DVEXTPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI PFNGLPROGRAMUNIFORMMATRIX4X2DVEXTPROC cppgl_glProgramUniformMatrix4x2dvEXT;
#define glProgramUniformMatrix4x2dvEXT cppgl_glProgramUniformMatrix4x2dvEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X3DVEXTPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI PFNGLPROGRAMUNIFORMMATRIX4X3DVEXTPROC cppgl_glProgramUniformMatrix4x3dvEXT;
#define glProgramUniformMatrix4x3dvEXT cppgl_glProgramUniformMatrix4x3dvEXT
typedef void (APIENTRYP PFNGLTEXTUREBUFFERRANGEEXTPROC)(GLuint texture, GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
GLAPI PFNGLTEXTUREBUFFERRANGEEXTPROC cppgl_glTextureBufferRangeEXT;
#define glTextureBufferRangeEXT cppgl_glTextureBufferRangeEXT
typedef void (APIENTRYP PFNGLTEXTURESTORAGE1DEXTPROC)(GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
GLAPI PFNGLTEXTURESTORAGE1DEXTPROC cppgl_glTextureStorage1DEXT;
#define glTextureStorage1DEXT cppgl_glTextureStorage1DEXT
typedef void (APIENTRYP PFNGLTEXTURESTORAGE2DEXTPROC)(GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
GLAPI PFNGLTEXTURESTORAGE2DEXTPROC cppgl_glTextureStorage2DEXT;
#define glTextureStorage2DEXT cppgl_glTextureStorage2DEXT
typedef void (APIENTRYP PFNGLTEXTURESTORAGE3DEXTPROC)(GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
GLAPI PFNGLTEXTURESTORAGE3DEXTPROC cppgl_glTextureStorage3DEXT;
#define glTextureStorage3DEXT cppgl_glTextureStorage3DEXT
typedef void (APIENTRYP PFNGLTEXTURESTORAGE2DMULTISAMPLEEXTPROC)(GLuint texture, GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
GLAPI PFNGLTEXTURESTORAGE2DMULTISAMPLEEXTPROC cppgl_glTextureStorage2DMultisampleEXT;
#define glTextureStorage2DMultisampleEXT cppgl_glTextureStorage2DMultisampleEXT
typedef void (APIENTRYP PFNGLTEXTURESTORAGE3DMULTISAMPLEEXTPROC)(GLuint texture, GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
GLAPI PFNGLTEXTURESTORAGE3DMULTISAMPLEEXTPROC cppgl_glTextureStorage3DMultisampleEXT;
#define glTextureStorage3DMultisampleEXT cppgl_glTextureStorage3DMultisampleEXT
typedef void (APIENTRYP PFNGLVERTEXARRAYBINDVERTEXBUFFEREXTPROC)(GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
GLAPI PFNGLVERTEXARRAYBINDVERTEXBUFFEREXTPROC cppgl_glVertexArrayBindVertexBufferEXT;
#define glVertexArrayBindVertexBufferEXT cppgl_glVertexArrayBindVertexBufferEXT
typedef void (APIENTRYP PFNGLVERTEXARRAYVERTEXATTRIBFORMATEXTPROC)(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
GLAPI PFNGLVERTEXARRAYVERTEXATTRIBFORMATEXTPROC cppgl_glVertexArrayVertexAttribFormatEXT;
#define glVertexArrayVertexAttribFormatEXT cppgl_glVertexArrayVertexAttribFormatEXT
typedef void (APIENTRYP PFNGLVERTEXARRAYVERTEXATTRIBIFORMATEXTPROC)(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
GLAPI PFNGLVERTEXARRAYVERTEXATTRIBIFORMATEXTPROC cppgl_glVertexArrayVertexAttribIFormatEXT;
#define glVertexArrayVertexAttribIFormatEXT cppgl_glVertexArrayVertexAttribIFormatEXT
typedef void (APIENTRYP PFNGLVERTEXARRAYVERTEXATTRIBLFORMATEXTPROC)(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
GLAPI PFNGLVERTEXARRAYVERTEXATTRIBLFORMATEXTPROC cppgl_glVertexArrayVertexAttribLFormatEXT;
#define glVertexArrayVertexAttribLFormatEXT cppgl_glVertexArrayVertexAttribLFormatEXT
typedef void (APIENTRYP PFNGLVERTEXARRAYVERTEXATTRIBBINDINGEXTPROC)(GLuint vaobj, GLuint attribindex, GLuint bindingindex);
GLAPI PFNGLVERTEXARRAYVERTEXATTRIBBINDINGEXTPROC cppgl_glVertexArrayVertexAttribBindingEXT;
#define glVertexArrayVertexAttribBindingEXT cppgl_glVertexArrayVertexAttribBindingEXT
typedef void (APIENTRYP PFNGLVERTEXARRAYVERTEXBINDINGDIVISOREXTPROC)(GLuint vaobj, GLuint bindingindex, GLuint divisor);
GLAPI PFNGLVERTEXARRAYVERTEXBINDINGDIVISOREXTPROC cppgl_glVertexArrayVertexBindingDivisorEXT;
#define glVertexArrayVertexBindingDivisorEXT cppgl_glVertexArrayVertexBindingDivisorEXT
typedef void (APIENTRYP PFNGLVERTEXARRAYVERTEXATTRIBLOFFSETEXTPROC)(GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLsizei stride, GLintptr offset);
GLAPI PFNGLVERTEXARRAYVERTEXATTRIBLOFFSETEXTPROC cppgl_glVertexArrayVertexAttribLOffsetEXT;
#define glVertexArrayVertexAttribLOffsetEXT cppgl_glVertexArrayVertexAttribLOffsetEXT
typedef void (APIENTRYP PFNGLTEXTUREPAGECOMMITMENTEXTPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLboolean commit);
GLAPI PFNGLTEXTUREPAGECOMMITMENTEXTPROC cppgl_glTexturePageCommitmentEXT;
#define glTexturePageCommitmentEXT cppgl_glTexturePageCommitmentEXT
typedef void (APIENTRYP PFNGLVERTEXARRAYVERTEXATTRIBDIVISOREXTPROC)(GLuint vaobj, GLuint index, GLuint divisor);
GLAPI PFNGLVERTEXARRAYVERTEXATTRIBDIVISOREXTPROC cppgl_glVertexArrayVertexAttribDivisorEXT;
#define glVertexArrayVertexAttribDivisorEXT cppgl_glVertexArrayVertexAttribDivisorEXT
#endif
#ifndef GL_EXT_draw_buffers2
#define GL_EXT_draw_buffers2 1
GLAPI int CPPGL_GL_EXT_draw_buffers2;
typedef void (APIENTRYP PFNGLCOLORMASKINDEXEDEXTPROC)(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a);
GLAPI PFNGLCOLORMASKINDEXEDEXTPROC cppgl_glColorMaskIndexedEXT;
#define glColorMaskIndexedEXT cppgl_glColorMaskIndexedEXT
#endif
#ifndef GL_EXT_draw_instanced
#define GL_EXT_draw_instanced 1
GLAPI int CPPGL_GL_EXT_draw_instanced;
typedef void (APIENTRYP PFNGLDRAWARRAYSINSTANCEDEXTPROC)(GLenum mode, GLint start, GLsizei count, GLsizei primcount);
GLAPI PFNGLDRAWARRAYSINSTANCEDEXTPROC cppgl_glDrawArraysInstancedEXT;
#define glDrawArraysInstancedEXT cppgl_glDrawArraysInstancedEXT
typedef void (APIENTRYP PFNGLDRAWELEMENTSINSTANCEDEXTPROC)(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei primcount);
GLAPI PFNGLDRAWELEMENTSINSTANCEDEXTPROC cppgl_glDrawElementsInstancedEXT;
#define glDrawElementsInstancedEXT cppgl_glDrawElementsInstancedEXT
#endif
#ifndef GL_EXT_draw_range_elements
#define GL_EXT_draw_range_elements 1
GLAPI int CPPGL_GL_EXT_draw_range_elements;
typedef void (APIENTRYP PFNGLDRAWRANGEELEMENTSEXTPROC)(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices);
GLAPI PFNGLDRAWRANGEELEMENTSEXTPROC cppgl_glDrawRangeElementsEXT;
#define glDrawRangeElementsEXT cppgl_glDrawRangeElementsEXT
#endif
#ifndef GL_EXT_fog_coord
#define GL_EXT_fog_coord 1
GLAPI int CPPGL_GL_EXT_fog_coord;
typedef void (APIENTRYP PFNGLFOGCOORDFEXTPROC)(GLfloat coord);
GLAPI PFNGLFOGCOORDFEXTPROC cppgl_glFogCoordfEXT;
#define glFogCoordfEXT cppgl_glFogCoordfEXT
typedef void (APIENTRYP PFNGLFOGCOORDFVEXTPROC)(const GLfloat *coord);
GLAPI PFNGLFOGCOORDFVEXTPROC cppgl_glFogCoordfvEXT;
#define glFogCoordfvEXT cppgl_glFogCoordfvEXT
typedef void (APIENTRYP PFNGLFOGCOORDDEXTPROC)(GLdouble coord);
GLAPI PFNGLFOGCOORDDEXTPROC cppgl_glFogCoorddEXT;
#define glFogCoorddEXT cppgl_glFogCoorddEXT
typedef void (APIENTRYP PFNGLFOGCOORDDVEXTPROC)(const GLdouble *coord);
GLAPI PFNGLFOGCOORDDVEXTPROC cppgl_glFogCoorddvEXT;
#define glFogCoorddvEXT cppgl_glFogCoorddvEXT
typedef void (APIENTRYP PFNGLFOGCOORDPOINTEREXTPROC)(GLenum type, GLsizei stride, const void *pointer);
GLAPI PFNGLFOGCOORDPOINTEREXTPROC cppgl_glFogCoordPointerEXT;
#define glFogCoordPointerEXT cppgl_glFogCoordPointerEXT
#endif
#ifndef GL_EXT_framebuffer_blit
#define GL_EXT_framebuffer_blit 1
GLAPI int CPPGL_GL_EXT_framebuffer_blit;
typedef void (APIENTRYP PFNGLBLITFRAMEBUFFEREXTPROC)(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
GLAPI PFNGLBLITFRAMEBUFFEREXTPROC cppgl_glBlitFramebufferEXT;
#define glBlitFramebufferEXT cppgl_glBlitFramebufferEXT
#endif
#ifndef GL_EXT_framebuffer_multisample
#define GL_EXT_framebuffer_multisample 1
GLAPI int CPPGL_GL_EXT_framebuffer_multisample;
typedef void (APIENTRYP PFNGLRENDERBUFFERSTORAGEMULTISAMPLEEXTPROC)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
GLAPI PFNGLRENDERBUFFERSTORAGEMULTISAMPLEEXTPROC cppgl_glRenderbufferStorageMultisampleEXT;
#define glRenderbufferStorageMultisampleEXT cppgl_glRenderbufferStorageMultisampleEXT
#endif
#ifndef GL_EXT_framebuffer_multisample_blit_scaled
#define GL_EXT_framebuffer_multisample_blit_scaled 1
GLAPI int CPPGL_GL_EXT_framebuffer_multisample_blit_scaled;
#endif
#ifndef GL_EXT_framebuffer_object
#define GL_EXT_framebuffer_object 1
GLAPI int CPPGL_GL_EXT_framebuffer_object;
typedef GLboolean (APIENTRYP PFNGLISRENDERBUFFEREXTPROC)(GLuint renderbuffer);
GLAPI PFNGLISRENDERBUFFEREXTPROC cppgl_glIsRenderbufferEXT;
#define glIsRenderbufferEXT cppgl_glIsRenderbufferEXT
typedef void (APIENTRYP PFNGLBINDRENDERBUFFEREXTPROC)(GLenum target, GLuint renderbuffer);
GLAPI PFNGLBINDRENDERBUFFEREXTPROC cppgl_glBindRenderbufferEXT;
#define glBindRenderbufferEXT cppgl_glBindRenderbufferEXT
typedef void (APIENTRYP PFNGLDELETERENDERBUFFERSEXTPROC)(GLsizei n, const GLuint *renderbuffers);
GLAPI PFNGLDELETERENDERBUFFERSEXTPROC cppgl_glDeleteRenderbuffersEXT;
#define glDeleteRenderbuffersEXT cppgl_glDeleteRenderbuffersEXT
typedef void (APIENTRYP PFNGLGENRENDERBUFFERSEXTPROC)(GLsizei n, GLuint *renderbuffers);
GLAPI PFNGLGENRENDERBUFFERSEXTPROC cppgl_glGenRenderbuffersEXT;
#define glGenRenderbuffersEXT cppgl_glGenRenderbuffersEXT
typedef void (APIENTRYP PFNGLRENDERBUFFERSTORAGEEXTPROC)(GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
GLAPI PFNGLRENDERBUFFERSTORAGEEXTPROC cppgl_glRenderbufferStorageEXT;
#define glRenderbufferStorageEXT cppgl_glRenderbufferStorageEXT
typedef void (APIENTRYP PFNGLGETRENDERBUFFERPARAMETERIVEXTPROC)(GLenum target, GLenum pname, GLint *params);
GLAPI PFNGLGETRENDERBUFFERPARAMETERIVEXTPROC cppgl_glGetRenderbufferParameterivEXT;
#define glGetRenderbufferParameterivEXT cppgl_glGetRenderbufferParameterivEXT
typedef GLboolean (APIENTRYP PFNGLISFRAMEBUFFEREXTPROC)(GLuint framebuffer);
GLAPI PFNGLISFRAMEBUFFEREXTPROC cppgl_glIsFramebufferEXT;
#define glIsFramebufferEXT cppgl_glIsFramebufferEXT
typedef void (APIENTRYP PFNGLBINDFRAMEBUFFEREXTPROC)(GLenum target, GLuint framebuffer);
GLAPI PFNGLBINDFRAMEBUFFEREXTPROC cppgl_glBindFramebufferEXT;
#define glBindFramebufferEXT cppgl_glBindFramebufferEXT
typedef void (APIENTRYP PFNGLDELETEFRAMEBUFFERSEXTPROC)(GLsizei n, const GLuint *framebuffers);
GLAPI PFNGLDELETEFRAMEBUFFERSEXTPROC cppgl_glDeleteFramebuffersEXT;
#define glDeleteFramebuffersEXT cppgl_glDeleteFramebuffersEXT
typedef void (APIENTRYP PFNGLGENFRAMEBUFFERSEXTPROC)(GLsizei n, GLuint *framebuffers);
GLAPI PFNGLGENFRAMEBUFFERSEXTPROC cppgl_glGenFramebuffersEXT;
#define glGenFramebuffersEXT cppgl_glGenFramebuffersEXT
typedef GLenum (APIENTRYP PFNGLCHECKFRAMEBUFFERSTATUSEXTPROC)(GLenum target);
GLAPI PFNGLCHECKFRAMEBUFFERSTATUSEXTPROC cppgl_glCheckFramebufferStatusEXT;
#define glCheckFramebufferStatusEXT cppgl_glCheckFramebufferStatusEXT
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTURE1DEXTPROC)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
GLAPI PFNGLFRAMEBUFFERTEXTURE1DEXTPROC cppgl_glFramebufferTexture1DEXT;
#define glFramebufferTexture1DEXT cppgl_glFramebufferTexture1DEXT
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTURE2DEXTPROC)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
GLAPI PFNGLFRAMEBUFFERTEXTURE2DEXTPROC cppgl_glFramebufferTexture2DEXT;
#define glFramebufferTexture2DEXT cppgl_glFramebufferTexture2DEXT
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTURE3DEXTPROC)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
GLAPI PFNGLFRAMEBUFFERTEXTURE3DEXTPROC cppgl_glFramebufferTexture3DEXT;
#define glFramebufferTexture3DEXT cppgl_glFramebufferTexture3DEXT
typedef void (APIENTRYP PFNGLFRAMEBUFFERRENDERBUFFEREXTPROC)(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
GLAPI PFNGLFRAMEBUFFERRENDERBUFFEREXTPROC cppgl_glFramebufferRenderbufferEXT;
#define glFramebufferRenderbufferEXT cppgl_glFramebufferRenderbufferEXT
typedef void (APIENTRYP PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVEXTPROC)(GLenum target, GLenum attachment, GLenum pname, GLint *params);
GLAPI PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVEXTPROC cppgl_glGetFramebufferAttachmentParameterivEXT;
#define glGetFramebufferAttachmentParameterivEXT cppgl_glGetFramebufferAttachmentParameterivEXT
typedef void (APIENTRYP PFNGLGENERATEMIPMAPEXTPROC)(GLenum target);
GLAPI PFNGLGENERATEMIPMAPEXTPROC cppgl_glGenerateMipmapEXT;
#define glGenerateMipmapEXT cppgl_glGenerateMipmapEXT
#endif
#ifndef GL_EXT_framebuffer_sRGB
#define GL_EXT_framebuffer_sRGB 1
GLAPI int CPPGL_GL_EXT_framebuffer_sRGB;
#endif
#ifndef GL_EXT_geometry_shader4
#define GL_EXT_geometry_shader4 1
GLAPI int CPPGL_GL_EXT_geometry_shader4;
typedef void (APIENTRYP PFNGLPROGRAMPARAMETERIEXTPROC)(GLuint program, GLenum pname, GLint value);
GLAPI PFNGLPROGRAMPARAMETERIEXTPROC cppgl_glProgramParameteriEXT;
#define glProgramParameteriEXT cppgl_glProgramParameteriEXT
#endif
#ifndef GL_EXT_gpu_program_parameters
#define GL_EXT_gpu_program_parameters 1
GLAPI int CPPGL_GL_EXT_gpu_program_parameters;
typedef void (APIENTRYP PFNGLPROGRAMENVPARAMETERS4FVEXTPROC)(GLenum target, GLuint index, GLsizei count, const GLfloat *params);
GLAPI PFNGLPROGRAMENVPARAMETERS4FVEXTPROC cppgl_glProgramEnvParameters4fvEXT;
#define glProgramEnvParameters4fvEXT cppgl_glProgramEnvParameters4fvEXT
typedef void (APIENTRYP PFNGLPROGRAMLOCALPARAMETERS4FVEXTPROC)(GLenum target, GLuint index, GLsizei count, const GLfloat *params);
GLAPI PFNGLPROGRAMLOCALPARAMETERS4FVEXTPROC cppgl_glProgramLocalParameters4fvEXT;
#define glProgramLocalParameters4fvEXT cppgl_glProgramLocalParameters4fvEXT
#endif
#ifndef GL_EXT_gpu_shader4
#define GL_EXT_gpu_shader4 1
GLAPI int CPPGL_GL_EXT_gpu_shader4;
typedef void (APIENTRYP PFNGLGETUNIFORMUIVEXTPROC)(GLuint program, GLint location, GLuint *params);
GLAPI PFNGLGETUNIFORMUIVEXTPROC cppgl_glGetUniformuivEXT;
#define glGetUniformuivEXT cppgl_glGetUniformuivEXT
typedef void (APIENTRYP PFNGLBINDFRAGDATALOCATIONEXTPROC)(GLuint program, GLuint color, const GLchar *name);
GLAPI PFNGLBINDFRAGDATALOCATIONEXTPROC cppgl_glBindFragDataLocationEXT;
#define glBindFragDataLocationEXT cppgl_glBindFragDataLocationEXT
typedef GLint (APIENTRYP PFNGLGETFRAGDATALOCATIONEXTPROC)(GLuint program, const GLchar *name);
GLAPI PFNGLGETFRAGDATALOCATIONEXTPROC cppgl_glGetFragDataLocationEXT;
#define glGetFragDataLocationEXT cppgl_glGetFragDataLocationEXT
typedef void (APIENTRYP PFNGLUNIFORM1UIEXTPROC)(GLint location, GLuint v0);
GLAPI PFNGLUNIFORM1UIEXTPROC cppgl_glUniform1uiEXT;
#define glUniform1uiEXT cppgl_glUniform1uiEXT
typedef void (APIENTRYP PFNGLUNIFORM2UIEXTPROC)(GLint location, GLuint v0, GLuint v1);
GLAPI PFNGLUNIFORM2UIEXTPROC cppgl_glUniform2uiEXT;
#define glUniform2uiEXT cppgl_glUniform2uiEXT
typedef void (APIENTRYP PFNGLUNIFORM3UIEXTPROC)(GLint location, GLuint v0, GLuint v1, GLuint v2);
GLAPI PFNGLUNIFORM3UIEXTPROC cppgl_glUniform3uiEXT;
#define glUniform3uiEXT cppgl_glUniform3uiEXT
typedef void (APIENTRYP PFNGLUNIFORM4UIEXTPROC)(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
GLAPI PFNGLUNIFORM4UIEXTPROC cppgl_glUniform4uiEXT;
#define glUniform4uiEXT cppgl_glUniform4uiEXT
typedef void (APIENTRYP PFNGLUNIFORM1UIVEXTPROC)(GLint location, GLsizei count, const GLuint *value);
GLAPI PFNGLUNIFORM1UIVEXTPROC cppgl_glUniform1uivEXT;
#define glUniform1uivEXT cppgl_glUniform1uivEXT
typedef void (APIENTRYP PFNGLUNIFORM2UIVEXTPROC)(GLint location, GLsizei count, const GLuint *value);
GLAPI PFNGLUNIFORM2UIVEXTPROC cppgl_glUniform2uivEXT;
#define glUniform2uivEXT cppgl_glUniform2uivEXT
typedef void (APIENTRYP PFNGLUNIFORM3UIVEXTPROC)(GLint location, GLsizei count, const GLuint *value);
GLAPI PFNGLUNIFORM3UIVEXTPROC cppgl_glUniform3uivEXT;
#define glUniform3uivEXT cppgl_glUniform3uivEXT
typedef void (APIENTRYP PFNGLUNIFORM4UIVEXTPROC)(GLint location, GLsizei count, const GLuint *value);
GLAPI PFNGLUNIFORM4UIVEXTPROC cppgl_glUniform4uivEXT;
#define glUniform4uivEXT cppgl_glUniform4uivEXT
#endif
#ifndef GL_EXT_histogram
#define GL_EXT_histogram 1
GLAPI int CPPGL_GL_EXT_histogram;
typedef void (APIENTRYP PFNGLGETHISTOGRAMEXTPROC)(GLenum target, GLboolean reset, GLenum format, GLenum type, void *values);
GLAPI PFNGLGETHISTOGRAMEXTPROC cppgl_glGetHistogramEXT;
#define glGetHistogramEXT cppgl_glGetHistogramEXT
typedef void (APIENTRYP PFNGLGETHISTOGRAMPARAMETERFVEXTPROC)(GLenum target, GLenum pname, GLfloat *params);
GLAPI PFNGLGETHISTOGRAMPARAMETERFVEXTPROC cppgl_glGetHistogramParameterfvEXT;
#define glGetHistogramParameterfvEXT cppgl_glGetHistogramParameterfvEXT
typedef void (APIENTRYP PFNGLGETHISTOGRAMPARAMETERIVEXTPROC)(GLenum target, GLenum pname, GLint *params);
GLAPI PFNGLGETHISTOGRAMPARAMETERIVEXTPROC cppgl_glGetHistogramParameterivEXT;
#define glGetHistogramParameterivEXT cppgl_glGetHistogramParameterivEXT
typedef void (APIENTRYP PFNGLGETMINMAXEXTPROC)(GLenum target, GLboolean reset, GLenum format, GLenum type, void *values);
GLAPI PFNGLGETMINMAXEXTPROC cppgl_glGetMinmaxEXT;
#define glGetMinmaxEXT cppgl_glGetMinmaxEXT
typedef void (APIENTRYP PFNGLGETMINMAXPARAMETERFVEXTPROC)(GLenum target, GLenum pname, GLfloat *params);
GLAPI PFNGLGETMINMAXPARAMETERFVEXTPROC cppgl_glGetMinmaxParameterfvEXT;
#define glGetMinmaxParameterfvEXT cppgl_glGetMinmaxParameterfvEXT
typedef void (APIENTRYP PFNGLGETMINMAXPARAMETERIVEXTPROC)(GLenum target, GLenum pname, GLint *params);
GLAPI PFNGLGETMINMAXPARAMETERIVEXTPROC cppgl_glGetMinmaxParameterivEXT;
#define glGetMinmaxParameterivEXT cppgl_glGetMinmaxParameterivEXT
typedef void (APIENTRYP PFNGLHISTOGRAMEXTPROC)(GLenum target, GLsizei width, GLenum internalformat, GLboolean sink);
GLAPI PFNGLHISTOGRAMEXTPROC cppgl_glHistogramEXT;
#define glHistogramEXT cppgl_glHistogramEXT
typedef void (APIENTRYP PFNGLMINMAXEXTPROC)(GLenum target, GLenum internalformat, GLboolean sink);
GLAPI PFNGLMINMAXEXTPROC cppgl_glMinmaxEXT;
#define glMinmaxEXT cppgl_glMinmaxEXT
typedef void (APIENTRYP PFNGLRESETHISTOGRAMEXTPROC)(GLenum target);
GLAPI PFNGLRESETHISTOGRAMEXTPROC cppgl_glResetHistogramEXT;
#define glResetHistogramEXT cppgl_glResetHistogramEXT
typedef void (APIENTRYP PFNGLRESETMINMAXEXTPROC)(GLenum target);
GLAPI PFNGLRESETMINMAXEXTPROC cppgl_glResetMinmaxEXT;
#define glResetMinmaxEXT cppgl_glResetMinmaxEXT
#endif
#ifndef GL_EXT_index_array_formats
#define GL_EXT_index_array_formats 1
GLAPI int CPPGL_GL_EXT_index_array_formats;
#endif
#ifndef GL_EXT_index_func
#define GL_EXT_index_func 1
GLAPI int CPPGL_GL_EXT_index_func;
typedef void (APIENTRYP PFNGLINDEXFUNCEXTPROC)(GLenum func, GLclampf ref);
GLAPI PFNGLINDEXFUNCEXTPROC cppgl_glIndexFuncEXT;
#define glIndexFuncEXT cppgl_glIndexFuncEXT
#endif
#ifndef GL_EXT_index_material
#define GL_EXT_index_material 1
GLAPI int CPPGL_GL_EXT_index_material;
typedef void (APIENTRYP PFNGLINDEXMATERIALEXTPROC)(GLenum face, GLenum mode);
GLAPI PFNGLINDEXMATERIALEXTPROC cppgl_glIndexMaterialEXT;
#define glIndexMaterialEXT cppgl_glIndexMaterialEXT
#endif
#ifndef GL_EXT_index_texture
#define GL_EXT_index_texture 1
GLAPI int CPPGL_GL_EXT_index_texture;
#endif
#ifndef GL_EXT_light_texture
#define GL_EXT_light_texture 1
GLAPI int CPPGL_GL_EXT_light_texture;
typedef void (APIENTRYP PFNGLAPPLYTEXTUREEXTPROC)(GLenum mode);
GLAPI PFNGLAPPLYTEXTUREEXTPROC cppgl_glApplyTextureEXT;
#define glApplyTextureEXT cppgl_glApplyTextureEXT
typedef void (APIENTRYP PFNGLTEXTURELIGHTEXTPROC)(GLenum pname);
GLAPI PFNGLTEXTURELIGHTEXTPROC cppgl_glTextureLightEXT;
#define glTextureLightEXT cppgl_glTextureLightEXT
typedef void (APIENTRYP PFNGLTEXTUREMATERIALEXTPROC)(GLenum face, GLenum mode);
GLAPI PFNGLTEXTUREMATERIALEXTPROC cppgl_glTextureMaterialEXT;
#define glTextureMaterialEXT cppgl_glTextureMaterialEXT
#endif
#ifndef GL_EXT_misc_attribute
#define GL_EXT_misc_attribute 1
GLAPI int CPPGL_GL_EXT_misc_attribute;
#endif
#ifndef GL_EXT_multi_draw_arrays
#define GL_EXT_multi_draw_arrays 1
GLAPI int CPPGL_GL_EXT_multi_draw_arrays;
typedef void (APIENTRYP PFNGLMULTIDRAWARRAYSEXTPROC)(GLenum mode, const GLint *first, const GLsizei *count, GLsizei primcount);
GLAPI PFNGLMULTIDRAWARRAYSEXTPROC cppgl_glMultiDrawArraysEXT;
#define glMultiDrawArraysEXT cppgl_glMultiDrawArraysEXT
typedef void (APIENTRYP PFNGLMULTIDRAWELEMENTSEXTPROC)(GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei primcount);
GLAPI PFNGLMULTIDRAWELEMENTSEXTPROC cppgl_glMultiDrawElementsEXT;
#define glMultiDrawElementsEXT cppgl_glMultiDrawElementsEXT
#endif
#ifndef GL_EXT_multisample
#define GL_EXT_multisample 1
GLAPI int CPPGL_GL_EXT_multisample;
typedef void (APIENTRYP PFNGLSAMPLEMASKEXTPROC)(GLclampf value, GLboolean invert);
GLAPI PFNGLSAMPLEMASKEXTPROC cppgl_glSampleMaskEXT;
#define glSampleMaskEXT cppgl_glSampleMaskEXT
typedef void (APIENTRYP PFNGLSAMPLEPATTERNEXTPROC)(GLenum pattern);
GLAPI PFNGLSAMPLEPATTERNEXTPROC cppgl_glSamplePatternEXT;
#define glSamplePatternEXT cppgl_glSamplePatternEXT
#endif
#ifndef GL_EXT_packed_depth_stencil
#define GL_EXT_packed_depth_stencil 1
GLAPI int CPPGL_GL_EXT_packed_depth_stencil;
#endif
#ifndef GL_EXT_packed_float
#define GL_EXT_packed_float 1
GLAPI int CPPGL_GL_EXT_packed_float;
#endif
#ifndef GL_EXT_packed_pixels
#define GL_EXT_packed_pixels 1
GLAPI int CPPGL_GL_EXT_packed_pixels;
#endif
#ifndef GL_EXT_paletted_texture
#define GL_EXT_paletted_texture 1
GLAPI int CPPGL_GL_EXT_paletted_texture;
typedef void (APIENTRYP PFNGLCOLORTABLEEXTPROC)(GLenum target, GLenum internalFormat, GLsizei width, GLenum format, GLenum type, const void *table);
GLAPI PFNGLCOLORTABLEEXTPROC cppgl_glColorTableEXT;
#define glColorTableEXT cppgl_glColorTableEXT
typedef void (APIENTRYP PFNGLGETCOLORTABLEEXTPROC)(GLenum target, GLenum format, GLenum type, void *data);
GLAPI PFNGLGETCOLORTABLEEXTPROC cppgl_glGetColorTableEXT;
#define glGetColorTableEXT cppgl_glGetColorTableEXT
typedef void (APIENTRYP PFNGLGETCOLORTABLEPARAMETERIVEXTPROC)(GLenum target, GLenum pname, GLint *params);
GLAPI PFNGLGETCOLORTABLEPARAMETERIVEXTPROC cppgl_glGetColorTableParameterivEXT;
#define glGetColorTableParameterivEXT cppgl_glGetColorTableParameterivEXT
typedef void (APIENTRYP PFNGLGETCOLORTABLEPARAMETERFVEXTPROC)(GLenum target, GLenum pname, GLfloat *params);
GLAPI PFNGLGETCOLORTABLEPARAMETERFVEXTPROC cppgl_glGetColorTableParameterfvEXT;
#define glGetColorTableParameterfvEXT cppgl_glGetColorTableParameterfvEXT
#endif
#ifndef GL_EXT_pixel_buffer_object
#define GL_EXT_pixel_buffer_object 1
GLAPI int CPPGL_GL_EXT_pixel_buffer_object;
#endif
#ifndef GL_EXT_pixel_transform
#define GL_EXT_pixel_transform 1
GLAPI int CPPGL_GL_EXT_pixel_transform;
typedef void (APIENTRYP PFNGLPIXELTRANSFORMPARAMETERIEXTPROC)(GLenum target, GLenum pname, GLint param);
GLAPI PFNGLPIXELTRANSFORMPARAMETERIEXTPROC cppgl_glPixelTransformParameteriEXT;
#define glPixelTransformParameteriEXT cppgl_glPixelTransformParameteriEXT
typedef void (APIENTRYP PFNGLPIXELTRANSFORMPARAMETERFEXTPROC)(GLenum target, GLenum pname, GLfloat param);
GLAPI PFNGLPIXELTRANSFORMPARAMETERFEXTPROC cppgl_glPixelTransformParameterfEXT;
#define glPixelTransformParameterfEXT cppgl_glPixelTransformParameterfEXT
typedef void (APIENTRYP PFNGLPIXELTRANSFORMPARAMETERIVEXTPROC)(GLenum target, GLenum pname, const GLint *params);
GLAPI PFNGLPIXELTRANSFORMPARAMETERIVEXTPROC cppgl_glPixelTransformParameterivEXT;
#define glPixelTransformParameterivEXT cppgl_glPixelTransformParameterivEXT
typedef void (APIENTRYP PFNGLPIXELTRANSFORMPARAMETERFVEXTPROC)(GLenum target, GLenum pname, const GLfloat *params);
GLAPI PFNGLPIXELTRANSFORMPARAMETERFVEXTPROC cppgl_glPixelTransformParameterfvEXT;
#define glPixelTransformParameterfvEXT cppgl_glPixelTransformParameterfvEXT
typedef void (APIENTRYP PFNGLGETPIXELTRANSFORMPARAMETERIVEXTPROC)(GLenum target, GLenum pname, GLint *params);
GLAPI PFNGLGETPIXELTRANSFORMPARAMETERIVEXTPROC cppgl_glGetPixelTransformParameterivEXT;
#define glGetPixelTransformParameterivEXT cppgl_glGetPixelTransformParameterivEXT
typedef void (APIENTRYP PFNGLGETPIXELTRANSFORMPARAMETERFVEXTPROC)(GLenum target, GLenum pname, GLfloat *params);
GLAPI PFNGLGETPIXELTRANSFORMPARAMETERFVEXTPROC cppgl_glGetPixelTransformParameterfvEXT;
#define glGetPixelTransformParameterfvEXT cppgl_glGetPixelTransformParameterfvEXT
#endif
#ifndef GL_EXT_pixel_transform_color_table
#define GL_EXT_pixel_transform_color_table 1
GLAPI int CPPGL_GL_EXT_pixel_transform_color_table;
#endif
#ifndef GL_EXT_point_parameters
#define GL_EXT_point_parameters 1
GLAPI int CPPGL_GL_EXT_point_parameters;
typedef void (APIENTRYP PFNGLPOINTPARAMETERFEXTPROC)(GLenum pname, GLfloat param);
GLAPI PFNGLPOINTPARAMETERFEXTPROC cppgl_glPointParameterfEXT;
#define glPointParameterfEXT cppgl_glPointParameterfEXT
typedef void (APIENTRYP PFNGLPOINTPARAMETERFVEXTPROC)(GLenum pname, const GLfloat *params);
GLAPI PFNGLPOINTPARAMETERFVEXTPROC cppgl_glPointParameterfvEXT;
#define glPointParameterfvEXT cppgl_glPointParameterfvEXT
#endif
#ifndef GL_EXT_polygon_offset
#define GL_EXT_polygon_offset 1
GLAPI int CPPGL_GL_EXT_polygon_offset;
typedef void (APIENTRYP PFNGLPOLYGONOFFSETEXTPROC)(GLfloat factor, GLfloat bias);
GLAPI PFNGLPOLYGONOFFSETEXTPROC cppgl_glPolygonOffsetEXT;
#define glPolygonOffsetEXT cppgl_glPolygonOffsetEXT
#endif
#ifndef GL_EXT_polygon_offset_clamp
#define GL_EXT_polygon_offset_clamp 1
GLAPI int CPPGL_GL_EXT_polygon_offset_clamp;
typedef void (APIENTRYP PFNGLPOLYGONOFFSETCLAMPEXTPROC)(GLfloat factor, GLfloat units, GLfloat clamp);
GLAPI PFNGLPOLYGONOFFSETCLAMPEXTPROC cppgl_glPolygonOffsetClampEXT;
#define glPolygonOffsetClampEXT cppgl_glPolygonOffsetClampEXT
#endif
#ifndef GL_EXT_post_depth_coverage
#define GL_EXT_post_depth_coverage 1
GLAPI int CPPGL_GL_EXT_post_depth_coverage;
#endif
#ifndef GL_EXT_provoking_vertex
#define GL_EXT_provoking_vertex 1
GLAPI int CPPGL_GL_EXT_provoking_vertex;
typedef void (APIENTRYP PFNGLPROVOKINGVERTEXEXTPROC)(GLenum mode);
GLAPI PFNGLPROVOKINGVERTEXEXTPROC cppgl_glProvokingVertexEXT;
#define glProvokingVertexEXT cppgl_glProvokingVertexEXT
#endif
#ifndef GL_EXT_raster_multisample
#define GL_EXT_raster_multisample 1
GLAPI int CPPGL_GL_EXT_raster_multisample;
typedef void (APIENTRYP PFNGLRASTERSAMPLESEXTPROC)(GLuint samples, GLboolean fixedsamplelocations);
GLAPI PFNGLRASTERSAMPLESEXTPROC cppgl_glRasterSamplesEXT;
#define glRasterSamplesEXT cppgl_glRasterSamplesEXT
#endif
#ifndef GL_EXT_rescale_normal
#define GL_EXT_rescale_normal 1
GLAPI int CPPGL_GL_EXT_rescale_normal;
#endif
#ifndef GL_EXT_secondary_color
#define GL_EXT_secondary_color 1
GLAPI int CPPGL_GL_EXT_secondary_color;
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3BEXTPROC)(GLbyte red, GLbyte green, GLbyte blue);
GLAPI PFNGLSECONDARYCOLOR3BEXTPROC cppgl_glSecondaryColor3bEXT;
#define glSecondaryColor3bEXT cppgl_glSecondaryColor3bEXT
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3BVEXTPROC)(const GLbyte *v);
GLAPI PFNGLSECONDARYCOLOR3BVEXTPROC cppgl_glSecondaryColor3bvEXT;
#define glSecondaryColor3bvEXT cppgl_glSecondaryColor3bvEXT
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3DEXTPROC)(GLdouble red, GLdouble green, GLdouble blue);
GLAPI PFNGLSECONDARYCOLOR3DEXTPROC cppgl_glSecondaryColor3dEXT;
#define glSecondaryColor3dEXT cppgl_glSecondaryColor3dEXT
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3DVEXTPROC)(const GLdouble *v);
GLAPI PFNGLSECONDARYCOLOR3DVEXTPROC cppgl_glSecondaryColor3dvEXT;
#define glSecondaryColor3dvEXT cppgl_glSecondaryColor3dvEXT
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3FEXTPROC)(GLfloat red, GLfloat green, GLfloat blue);
GLAPI PFNGLSECONDARYCOLOR3FEXTPROC cppgl_glSecondaryColor3fEXT;
#define glSecondaryColor3fEXT cppgl_glSecondaryColor3fEXT
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3FVEXTPROC)(const GLfloat *v);
GLAPI PFNGLSECONDARYCOLOR3FVEXTPROC cppgl_glSecondaryColor3fvEXT;
#define glSecondaryColor3fvEXT cppgl_glSecondaryColor3fvEXT
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3IEXTPROC)(GLint red, GLint green, GLint blue);
GLAPI PFNGLSECONDARYCOLOR3IEXTPROC cppgl_glSecondaryColor3iEXT;
#define glSecondaryColor3iEXT cppgl_glSecondaryColor3iEXT
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3IVEXTPROC)(const GLint *v);
GLAPI PFNGLSECONDARYCOLOR3IVEXTPROC cppgl_glSecondaryColor3ivEXT;
#define glSecondaryColor3ivEXT cppgl_glSecondaryColor3ivEXT
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3SEXTPROC)(GLshort red, GLshort green, GLshort blue);
GLAPI PFNGLSECONDARYCOLOR3SEXTPROC cppgl_glSecondaryColor3sEXT;
#define glSecondaryColor3sEXT cppgl_glSecondaryColor3sEXT
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3SVEXTPROC)(const GLshort *v);
GLAPI PFNGLSECONDARYCOLOR3SVEXTPROC cppgl_glSecondaryColor3svEXT;
#define glSecondaryColor3svEXT cppgl_glSecondaryColor3svEXT
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3UBEXTPROC)(GLubyte red, GLubyte green, GLubyte blue);
GLAPI PFNGLSECONDARYCOLOR3UBEXTPROC cppgl_glSecondaryColor3ubEXT;
#define glSecondaryColor3ubEXT cppgl_glSecondaryColor3ubEXT
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3UBVEXTPROC)(const GLubyte *v);
GLAPI PFNGLSECONDARYCOLOR3UBVEXTPROC cppgl_glSecondaryColor3ubvEXT;
#define glSecondaryColor3ubvEXT cppgl_glSecondaryColor3ubvEXT
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3UIEXTPROC)(GLuint red, GLuint green, GLuint blue);
GLAPI PFNGLSECONDARYCOLOR3UIEXTPROC cppgl_glSecondaryColor3uiEXT;
#define glSecondaryColor3uiEXT cppgl_glSecondaryColor3uiEXT
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3UIVEXTPROC)(const GLuint *v);
GLAPI PFNGLSECONDARYCOLOR3UIVEXTPROC cppgl_glSecondaryColor3uivEXT;
#define glSecondaryColor3uivEXT cppgl_glSecondaryColor3uivEXT
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3USEXTPROC)(GLushort red, GLushort green, GLushort blue);
GLAPI PFNGLSECONDARYCOLOR3USEXTPROC cppgl_glSecondaryColor3usEXT;
#define glSecondaryColor3usEXT cppgl_glSecondaryColor3usEXT
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3USVEXTPROC)(const GLushort *v);
GLAPI PFNGLSECONDARYCOLOR3USVEXTPROC cppgl_glSecondaryColor3usvEXT;
#define glSecondaryColor3usvEXT cppgl_glSecondaryColor3usvEXT
typedef void (APIENTRYP PFNGLSECONDARYCOLORPOINTEREXTPROC)(GLint size, GLenum type, GLsizei stride, const void *pointer);
GLAPI PFNGLSECONDARYCOLORPOINTEREXTPROC cppgl_glSecondaryColorPointerEXT;
#define glSecondaryColorPointerEXT cppgl_glSecondaryColorPointerEXT
#endif
#ifndef GL_EXT_separate_shader_objects
#define GL_EXT_separate_shader_objects 1
GLAPI int CPPGL_GL_EXT_separate_shader_objects;
typedef void (APIENTRYP PFNGLUSESHADERPROGRAMEXTPROC)(GLenum type, GLuint program);
GLAPI PFNGLUSESHADERPROGRAMEXTPROC cppgl_glUseShaderProgramEXT;
#define glUseShaderProgramEXT cppgl_glUseShaderProgramEXT
typedef void (APIENTRYP PFNGLACTIVEPROGRAMEXTPROC)(GLuint program);
GLAPI PFNGLACTIVEPROGRAMEXTPROC cppgl_glActiveProgramEXT;
#define glActiveProgramEXT cppgl_glActiveProgramEXT
typedef GLuint (APIENTRYP PFNGLCREATESHADERPROGRAMEXTPROC)(GLenum type, const GLchar *string);
GLAPI PFNGLCREATESHADERPROGRAMEXTPROC cppgl_glCreateShaderProgramEXT;
#define glCreateShaderProgramEXT cppgl_glCreateShaderProgramEXT
typedef void (APIENTRYP PFNGLACTIVESHADERPROGRAMEXTPROC)(GLuint pipeline, GLuint program);
GLAPI PFNGLACTIVESHADERPROGRAMEXTPROC cppgl_glActiveShaderProgramEXT;
#define glActiveShaderProgramEXT cppgl_glActiveShaderProgramEXT
typedef void (APIENTRYP PFNGLBINDPROGRAMPIPELINEEXTPROC)(GLuint pipeline);
GLAPI PFNGLBINDPROGRAMPIPELINEEXTPROC cppgl_glBindProgramPipelineEXT;
#define glBindProgramPipelineEXT cppgl_glBindProgramPipelineEXT
typedef GLuint (APIENTRYP PFNGLCREATESHADERPROGRAMVEXTPROC)(GLenum type, GLsizei count, const GLchar **strings);
GLAPI PFNGLCREATESHADERPROGRAMVEXTPROC cppgl_glCreateShaderProgramvEXT;
#define glCreateShaderProgramvEXT cppgl_glCreateShaderProgramvEXT
typedef void (APIENTRYP PFNGLDELETEPROGRAMPIPELINESEXTPROC)(GLsizei n, const GLuint *pipelines);
GLAPI PFNGLDELETEPROGRAMPIPELINESEXTPROC cppgl_glDeleteProgramPipelinesEXT;
#define glDeleteProgramPipelinesEXT cppgl_glDeleteProgramPipelinesEXT
typedef void (APIENTRYP PFNGLGENPROGRAMPIPELINESEXTPROC)(GLsizei n, GLuint *pipelines);
GLAPI PFNGLGENPROGRAMPIPELINESEXTPROC cppgl_glGenProgramPipelinesEXT;
#define glGenProgramPipelinesEXT cppgl_glGenProgramPipelinesEXT
typedef void (APIENTRYP PFNGLGETPROGRAMPIPELINEINFOLOGEXTPROC)(GLuint pipeline, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
GLAPI PFNGLGETPROGRAMPIPELINEINFOLOGEXTPROC cppgl_glGetProgramPipelineInfoLogEXT;
#define glGetProgramPipelineInfoLogEXT cppgl_glGetProgramPipelineInfoLogEXT
typedef void (APIENTRYP PFNGLGETPROGRAMPIPELINEIVEXTPROC)(GLuint pipeline, GLenum pname, GLint *params);
GLAPI PFNGLGETPROGRAMPIPELINEIVEXTPROC cppgl_glGetProgramPipelineivEXT;
#define glGetProgramPipelineivEXT cppgl_glGetProgramPipelineivEXT
typedef GLboolean (APIENTRYP PFNGLISPROGRAMPIPELINEEXTPROC)(GLuint pipeline);
GLAPI PFNGLISPROGRAMPIPELINEEXTPROC cppgl_glIsProgramPipelineEXT;
#define glIsProgramPipelineEXT cppgl_glIsProgramPipelineEXT
typedef void (APIENTRYP PFNGLUSEPROGRAMSTAGESEXTPROC)(GLuint pipeline, GLbitfield stages, GLuint program);
GLAPI PFNGLUSEPROGRAMSTAGESEXTPROC cppgl_glUseProgramStagesEXT;
#define glUseProgramStagesEXT cppgl_glUseProgramStagesEXT
typedef void (APIENTRYP PFNGLVALIDATEPROGRAMPIPELINEEXTPROC)(GLuint pipeline);
GLAPI PFNGLVALIDATEPROGRAMPIPELINEEXTPROC cppgl_glValidateProgramPipelineEXT;
#define glValidateProgramPipelineEXT cppgl_glValidateProgramPipelineEXT
#endif
#ifndef GL_EXT_separate_specular_color
#define GL_EXT_separate_specular_color 1
GLAPI int CPPGL_GL_EXT_separate_specular_color;
#endif
#ifndef GL_EXT_shader_image_load_formatted
#define GL_EXT_shader_image_load_formatted 1
GLAPI int CPPGL_GL_EXT_shader_image_load_formatted;
#endif
#ifndef GL_EXT_shader_image_load_store
#define GL_EXT_shader_image_load_store 1
GLAPI int CPPGL_GL_EXT_shader_image_load_store;
typedef void (APIENTRYP PFNGLBINDIMAGETEXTUREEXTPROC)(GLuint index, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLint format);
GLAPI PFNGLBINDIMAGETEXTUREEXTPROC cppgl_glBindImageTextureEXT;
#define glBindImageTextureEXT cppgl_glBindImageTextureEXT
typedef void (APIENTRYP PFNGLMEMORYBARRIEREXTPROC)(GLbitfield barriers);
GLAPI PFNGLMEMORYBARRIEREXTPROC cppgl_glMemoryBarrierEXT;
#define glMemoryBarrierEXT cppgl_glMemoryBarrierEXT
#endif
#ifndef GL_EXT_shader_integer_mix
#define GL_EXT_shader_integer_mix 1
GLAPI int CPPGL_GL_EXT_shader_integer_mix;
#endif
#ifndef GL_EXT_shadow_funcs
#define GL_EXT_shadow_funcs 1
GLAPI int CPPGL_GL_EXT_shadow_funcs;
#endif
#ifndef GL_EXT_shared_texture_palette
#define GL_EXT_shared_texture_palette 1
GLAPI int CPPGL_GL_EXT_shared_texture_palette;
#endif
#ifndef GL_EXT_sparse_texture2
#define GL_EXT_sparse_texture2 1
GLAPI int CPPGL_GL_EXT_sparse_texture2;
#endif
#ifndef GL_EXT_stencil_clear_tag
#define GL_EXT_stencil_clear_tag 1
GLAPI int CPPGL_GL_EXT_stencil_clear_tag;
typedef void (APIENTRYP PFNGLSTENCILCLEARTAGEXTPROC)(GLsizei stencilTagBits, GLuint stencilClearTag);
GLAPI PFNGLSTENCILCLEARTAGEXTPROC cppgl_glStencilClearTagEXT;
#define glStencilClearTagEXT cppgl_glStencilClearTagEXT
#endif
#ifndef GL_EXT_stencil_two_side
#define GL_EXT_stencil_two_side 1
GLAPI int CPPGL_GL_EXT_stencil_two_side;
typedef void (APIENTRYP PFNGLACTIVESTENCILFACEEXTPROC)(GLenum face);
GLAPI PFNGLACTIVESTENCILFACEEXTPROC cppgl_glActiveStencilFaceEXT;
#define glActiveStencilFaceEXT cppgl_glActiveStencilFaceEXT
#endif
#ifndef GL_EXT_stencil_wrap
#define GL_EXT_stencil_wrap 1
GLAPI int CPPGL_GL_EXT_stencil_wrap;
#endif
#ifndef GL_EXT_subtexture
#define GL_EXT_subtexture 1
GLAPI int CPPGL_GL_EXT_subtexture;
typedef void (APIENTRYP PFNGLTEXSUBIMAGE1DEXTPROC)(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels);
GLAPI PFNGLTEXSUBIMAGE1DEXTPROC cppgl_glTexSubImage1DEXT;
#define glTexSubImage1DEXT cppgl_glTexSubImage1DEXT
typedef void (APIENTRYP PFNGLTEXSUBIMAGE2DEXTPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
GLAPI PFNGLTEXSUBIMAGE2DEXTPROC cppgl_glTexSubImage2DEXT;
#define glTexSubImage2DEXT cppgl_glTexSubImage2DEXT
#endif
#ifndef GL_EXT_texture
#define GL_EXT_texture 1
GLAPI int CPPGL_GL_EXT_texture;
#endif
#ifndef GL_EXT_texture3D
#define GL_EXT_texture3D 1
GLAPI int CPPGL_GL_EXT_texture3D;
typedef void (APIENTRYP PFNGLTEXIMAGE3DEXTPROC)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels);
GLAPI PFNGLTEXIMAGE3DEXTPROC cppgl_glTexImage3DEXT;
#define glTexImage3DEXT cppgl_glTexImage3DEXT
typedef void (APIENTRYP PFNGLTEXSUBIMAGE3DEXTPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels);
GLAPI PFNGLTEXSUBIMAGE3DEXTPROC cppgl_glTexSubImage3DEXT;
#define glTexSubImage3DEXT cppgl_glTexSubImage3DEXT
#endif
#ifndef GL_EXT_texture_array
#define GL_EXT_texture_array 1
GLAPI int CPPGL_GL_EXT_texture_array;
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTURELAYEREXTPROC)(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
GLAPI PFNGLFRAMEBUFFERTEXTURELAYEREXTPROC cppgl_glFramebufferTextureLayerEXT;
#define glFramebufferTextureLayerEXT cppgl_glFramebufferTextureLayerEXT
#endif
#ifndef GL_EXT_texture_buffer_object
#define GL_EXT_texture_buffer_object 1
GLAPI int CPPGL_GL_EXT_texture_buffer_object;
typedef void (APIENTRYP PFNGLTEXBUFFEREXTPROC)(GLenum target, GLenum internalformat, GLuint buffer);
GLAPI PFNGLTEXBUFFEREXTPROC cppgl_glTexBufferEXT;
#define glTexBufferEXT cppgl_glTexBufferEXT
#endif
#ifndef GL_EXT_texture_compression_latc
#define GL_EXT_texture_compression_latc 1
GLAPI int CPPGL_GL_EXT_texture_compression_latc;
#endif
#ifndef GL_EXT_texture_compression_rgtc
#define GL_EXT_texture_compression_rgtc 1
GLAPI int CPPGL_GL_EXT_texture_compression_rgtc;
#endif
#ifndef GL_EXT_texture_compression_s3tc
#define GL_EXT_texture_compression_s3tc 1
GLAPI int CPPGL_GL_EXT_texture_compression_s3tc;
#endif
#ifndef GL_EXT_texture_cube_map
#define GL_EXT_texture_cube_map 1
GLAPI int CPPGL_GL_EXT_texture_cube_map;
#endif
#ifndef GL_EXT_texture_env_add
#define GL_EXT_texture_env_add 1
GLAPI int CPPGL_GL_EXT_texture_env_add;
#endif
#ifndef GL_EXT_texture_env_combine
#define GL_EXT_texture_env_combine 1
GLAPI int CPPGL_GL_EXT_texture_env_combine;
#endif
#ifndef GL_EXT_texture_env_dot3
#define GL_EXT_texture_env_dot3 1
GLAPI int CPPGL_GL_EXT_texture_env_dot3;
#endif
#ifndef GL_EXT_texture_filter_anisotropic
#define GL_EXT_texture_filter_anisotropic 1
GLAPI int CPPGL_GL_EXT_texture_filter_anisotropic;
#endif
#ifndef GL_EXT_texture_filter_minmax
#define GL_EXT_texture_filter_minmax 1
GLAPI int CPPGL_GL_EXT_texture_filter_minmax;
#endif
#ifndef GL_EXT_texture_integer
#define GL_EXT_texture_integer 1
GLAPI int CPPGL_GL_EXT_texture_integer;
typedef void (APIENTRYP PFNGLTEXPARAMETERIIVEXTPROC)(GLenum target, GLenum pname, const GLint *params);
GLAPI PFNGLTEXPARAMETERIIVEXTPROC cppgl_glTexParameterIivEXT;
#define glTexParameterIivEXT cppgl_glTexParameterIivEXT
typedef void (APIENTRYP PFNGLTEXPARAMETERIUIVEXTPROC)(GLenum target, GLenum pname, const GLuint *params);
GLAPI PFNGLTEXPARAMETERIUIVEXTPROC cppgl_glTexParameterIuivEXT;
#define glTexParameterIuivEXT cppgl_glTexParameterIuivEXT
typedef void (APIENTRYP PFNGLGETTEXPARAMETERIIVEXTPROC)(GLenum target, GLenum pname, GLint *params);
GLAPI PFNGLGETTEXPARAMETERIIVEXTPROC cppgl_glGetTexParameterIivEXT;
#define glGetTexParameterIivEXT cppgl_glGetTexParameterIivEXT
typedef void (APIENTRYP PFNGLGETTEXPARAMETERIUIVEXTPROC)(GLenum target, GLenum pname, GLuint *params);
GLAPI PFNGLGETTEXPARAMETERIUIVEXTPROC cppgl_glGetTexParameterIuivEXT;
#define glGetTexParameterIuivEXT cppgl_glGetTexParameterIuivEXT
typedef void (APIENTRYP PFNGLCLEARCOLORIIEXTPROC)(GLint red, GLint green, GLint blue, GLint alpha);
GLAPI PFNGLCLEARCOLORIIEXTPROC cppgl_glClearColorIiEXT;
#define glClearColorIiEXT cppgl_glClearColorIiEXT
typedef void (APIENTRYP PFNGLCLEARCOLORIUIEXTPROC)(GLuint red, GLuint green, GLuint blue, GLuint alpha);
GLAPI PFNGLCLEARCOLORIUIEXTPROC cppgl_glClearColorIuiEXT;
#define glClearColorIuiEXT cppgl_glClearColorIuiEXT
#endif
#ifndef GL_EXT_texture_lod_bias
#define GL_EXT_texture_lod_bias 1
GLAPI int CPPGL_GL_EXT_texture_lod_bias;
#endif
#ifndef GL_EXT_texture_mirror_clamp
#define GL_EXT_texture_mirror_clamp 1
GLAPI int CPPGL_GL_EXT_texture_mirror_clamp;
#endif
#ifndef GL_EXT_texture_object
#define GL_EXT_texture_object 1
GLAPI int CPPGL_GL_EXT_texture_object;
typedef GLboolean (APIENTRYP PFNGLARETEXTURESRESIDENTEXTPROC)(GLsizei n, const GLuint *textures, GLboolean *residences);
GLAPI PFNGLARETEXTURESRESIDENTEXTPROC cppgl_glAreTexturesResidentEXT;
#define glAreTexturesResidentEXT cppgl_glAreTexturesResidentEXT
typedef void (APIENTRYP PFNGLBINDTEXTUREEXTPROC)(GLenum target, GLuint texture);
GLAPI PFNGLBINDTEXTUREEXTPROC cppgl_glBindTextureEXT;
#define glBindTextureEXT cppgl_glBindTextureEXT
typedef void (APIENTRYP PFNGLDELETETEXTURESEXTPROC)(GLsizei n, const GLuint *textures);
GLAPI PFNGLDELETETEXTURESEXTPROC cppgl_glDeleteTexturesEXT;
#define glDeleteTexturesEXT cppgl_glDeleteTexturesEXT
typedef void (APIENTRYP PFNGLGENTEXTURESEXTPROC)(GLsizei n, GLuint *textures);
GLAPI PFNGLGENTEXTURESEXTPROC cppgl_glGenTexturesEXT;
#define glGenTexturesEXT cppgl_glGenTexturesEXT
typedef GLboolean (APIENTRYP PFNGLISTEXTUREEXTPROC)(GLuint texture);
GLAPI PFNGLISTEXTUREEXTPROC cppgl_glIsTextureEXT;
#define glIsTextureEXT cppgl_glIsTextureEXT
typedef void (APIENTRYP PFNGLPRIORITIZETEXTURESEXTPROC)(GLsizei n, const GLuint *textures, const GLclampf *priorities);
GLAPI PFNGLPRIORITIZETEXTURESEXTPROC cppgl_glPrioritizeTexturesEXT;
#define glPrioritizeTexturesEXT cppgl_glPrioritizeTexturesEXT
#endif
#ifndef GL_EXT_texture_perturb_normal
#define GL_EXT_texture_perturb_normal 1
GLAPI int CPPGL_GL_EXT_texture_perturb_normal;
typedef void (APIENTRYP PFNGLTEXTURENORMALEXTPROC)(GLenum mode);
GLAPI PFNGLTEXTURENORMALEXTPROC cppgl_glTextureNormalEXT;
#define glTextureNormalEXT cppgl_glTextureNormalEXT
#endif
#ifndef GL_EXT_texture_sRGB
#define GL_EXT_texture_sRGB 1
GLAPI int CPPGL_GL_EXT_texture_sRGB;
#endif
#ifndef GL_EXT_texture_sRGB_decode
#define GL_EXT_texture_sRGB_decode 1
GLAPI int CPPGL_GL_EXT_texture_sRGB_decode;
#endif
#ifndef GL_EXT_texture_shared_exponent
#define GL_EXT_texture_shared_exponent 1
GLAPI int CPPGL_GL_EXT_texture_shared_exponent;
#endif
#ifndef GL_EXT_texture_snorm
#define GL_EXT_texture_snorm 1
GLAPI int CPPGL_GL_EXT_texture_snorm;
#endif
#ifndef GL_EXT_texture_swizzle
#define GL_EXT_texture_swizzle 1
GLAPI int CPPGL_GL_EXT_texture_swizzle;
#endif
#ifndef GL_EXT_timer_query
#define GL_EXT_timer_query 1
GLAPI int CPPGL_GL_EXT_timer_query;
typedef void (APIENTRYP PFNGLGETQUERYOBJECTI64VEXTPROC)(GLuint id, GLenum pname, GLint64 *params);
GLAPI PFNGLGETQUERYOBJECTI64VEXTPROC cppgl_glGetQueryObjecti64vEXT;
#define glGetQueryObjecti64vEXT cppgl_glGetQueryObjecti64vEXT
typedef void (APIENTRYP PFNGLGETQUERYOBJECTUI64VEXTPROC)(GLuint id, GLenum pname, GLuint64 *params);
GLAPI PFNGLGETQUERYOBJECTUI64VEXTPROC cppgl_glGetQueryObjectui64vEXT;
#define glGetQueryObjectui64vEXT cppgl_glGetQueryObjectui64vEXT
#endif
#ifndef GL_EXT_transform_feedback
#define GL_EXT_transform_feedback 1
GLAPI int CPPGL_GL_EXT_transform_feedback;
typedef void (APIENTRYP PFNGLBEGINTRANSFORMFEEDBACKEXTPROC)(GLenum primitiveMode);
GLAPI PFNGLBEGINTRANSFORMFEEDBACKEXTPROC cppgl_glBeginTransformFeedbackEXT;
#define glBeginTransformFeedbackEXT cppgl_glBeginTransformFeedbackEXT
typedef void (APIENTRYP PFNGLENDTRANSFORMFEEDBACKEXTPROC)();
GLAPI PFNGLENDTRANSFORMFEEDBACKEXTPROC cppgl_glEndTransformFeedbackEXT;
#define glEndTransformFeedbackEXT cppgl_glEndTransformFeedbackEXT
typedef void (APIENTRYP PFNGLBINDBUFFERRANGEEXTPROC)(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
GLAPI PFNGLBINDBUFFERRANGEEXTPROC cppgl_glBindBufferRangeEXT;
#define glBindBufferRangeEXT cppgl_glBindBufferRangeEXT
typedef void (APIENTRYP PFNGLBINDBUFFEROFFSETEXTPROC)(GLenum target, GLuint index, GLuint buffer, GLintptr offset);
GLAPI PFNGLBINDBUFFEROFFSETEXTPROC cppgl_glBindBufferOffsetEXT;
#define glBindBufferOffsetEXT cppgl_glBindBufferOffsetEXT
typedef void (APIENTRYP PFNGLBINDBUFFERBASEEXTPROC)(GLenum target, GLuint index, GLuint buffer);
GLAPI PFNGLBINDBUFFERBASEEXTPROC cppgl_glBindBufferBaseEXT;
#define glBindBufferBaseEXT cppgl_glBindBufferBaseEXT
typedef void (APIENTRYP PFNGLTRANSFORMFEEDBACKVARYINGSEXTPROC)(GLuint program, GLsizei count, const GLchar *const*varyings, GLenum bufferMode);
GLAPI PFNGLTRANSFORMFEEDBACKVARYINGSEXTPROC cppgl_glTransformFeedbackVaryingsEXT;
#define glTransformFeedbackVaryingsEXT cppgl_glTransformFeedbackVaryingsEXT
typedef void (APIENTRYP PFNGLGETTRANSFORMFEEDBACKVARYINGEXTPROC)(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name);
GLAPI PFNGLGETTRANSFORMFEEDBACKVARYINGEXTPROC cppgl_glGetTransformFeedbackVaryingEXT;
#define glGetTransformFeedbackVaryingEXT cppgl_glGetTransformFeedbackVaryingEXT
#endif
#ifndef GL_EXT_vertex_array
#define GL_EXT_vertex_array 1
GLAPI int CPPGL_GL_EXT_vertex_array;
typedef void (APIENTRYP PFNGLARRAYELEMENTEXTPROC)(GLint i);
GLAPI PFNGLARRAYELEMENTEXTPROC cppgl_glArrayElementEXT;
#define glArrayElementEXT cppgl_glArrayElementEXT
typedef void (APIENTRYP PFNGLCOLORPOINTEREXTPROC)(GLint size, GLenum type, GLsizei stride, GLsizei count, const void *pointer);
GLAPI PFNGLCOLORPOINTEREXTPROC cppgl_glColorPointerEXT;
#define glColorPointerEXT cppgl_glColorPointerEXT
typedef void (APIENTRYP PFNGLDRAWARRAYSEXTPROC)(GLenum mode, GLint first, GLsizei count);
GLAPI PFNGLDRAWARRAYSEXTPROC cppgl_glDrawArraysEXT;
#define glDrawArraysEXT cppgl_glDrawArraysEXT
typedef void (APIENTRYP PFNGLEDGEFLAGPOINTEREXTPROC)(GLsizei stride, GLsizei count, const GLboolean *pointer);
GLAPI PFNGLEDGEFLAGPOINTEREXTPROC cppgl_glEdgeFlagPointerEXT;
#define glEdgeFlagPointerEXT cppgl_glEdgeFlagPointerEXT
typedef void (APIENTRYP PFNGLGETPOINTERVEXTPROC)(GLenum pname, void **params);
GLAPI PFNGLGETPOINTERVEXTPROC cppgl_glGetPointervEXT;
#define glGetPointervEXT cppgl_glGetPointervEXT
typedef void (APIENTRYP PFNGLINDEXPOINTEREXTPROC)(GLenum type, GLsizei stride, GLsizei count, const void *pointer);
GLAPI PFNGLINDEXPOINTEREXTPROC cppgl_glIndexPointerEXT;
#define glIndexPointerEXT cppgl_glIndexPointerEXT
typedef void (APIENTRYP PFNGLNORMALPOINTEREXTPROC)(GLenum type, GLsizei stride, GLsizei count, const void *pointer);
GLAPI PFNGLNORMALPOINTEREXTPROC cppgl_glNormalPointerEXT;
#define glNormalPointerEXT cppgl_glNormalPointerEXT
typedef void (APIENTRYP PFNGLTEXCOORDPOINTEREXTPROC)(GLint size, GLenum type, GLsizei stride, GLsizei count, const void *pointer);
GLAPI PFNGLTEXCOORDPOINTEREXTPROC cppgl_glTexCoordPointerEXT;
#define glTexCoordPointerEXT cppgl_glTexCoordPointerEXT
typedef void (APIENTRYP PFNGLVERTEXPOINTEREXTPROC)(GLint size, GLenum type, GLsizei stride, GLsizei count, const void *pointer);
GLAPI PFNGLVERTEXPOINTEREXTPROC cppgl_glVertexPointerEXT;
#define glVertexPointerEXT cppgl_glVertexPointerEXT
#endif
#ifndef GL_EXT_vertex_array_bgra
#define GL_EXT_vertex_array_bgra 1
GLAPI int CPPGL_GL_EXT_vertex_array_bgra;
#endif
#ifndef GL_EXT_vertex_attrib_64bit
#define GL_EXT_vertex_attrib_64bit 1
GLAPI int CPPGL_GL_EXT_vertex_attrib_64bit;
typedef void (APIENTRYP PFNGLVERTEXATTRIBL1DEXTPROC)(GLuint index, GLdouble x);
GLAPI PFNGLVERTEXATTRIBL1DEXTPROC cppgl_glVertexAttribL1dEXT;
#define glVertexAttribL1dEXT cppgl_glVertexAttribL1dEXT
typedef void (APIENTRYP PFNGLVERTEXATTRIBL2DEXTPROC)(GLuint index, GLdouble x, GLdouble y);
GLAPI PFNGLVERTEXATTRIBL2DEXTPROC cppgl_glVertexAttribL2dEXT;
#define glVertexAttribL2dEXT cppgl_glVertexAttribL2dEXT
typedef void (APIENTRYP PFNGLVERTEXATTRIBL3DEXTPROC)(GLuint index, GLdouble x, GLdouble y, GLdouble z);
GLAPI PFNGLVERTEXATTRIBL3DEXTPROC cppgl_glVertexAttribL3dEXT;
#define glVertexAttribL3dEXT cppgl_glVertexAttribL3dEXT
typedef void (APIENTRYP PFNGLVERTEXATTRIBL4DEXTPROC)(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
GLAPI PFNGLVERTEXATTRIBL4DEXTPROC cppgl_glVertexAttribL4dEXT;
#define glVertexAttribL4dEXT cppgl_glVertexAttribL4dEXT
typedef void (APIENTRYP PFNGLVERTEXATTRIBL1DVEXTPROC)(GLuint index, const GLdouble *v);
GLAPI PFNGLVERTEXATTRIBL1DVEXTPROC cppgl_glVertexAttribL1dvEXT;
#define glVertexAttribL1dvEXT cppgl_glVertexAttribL1dvEXT
typedef void (APIENTRYP PFNGLVERTEXATTRIBL2DVEXTPROC)(GLuint index, const GLdouble *v);
GLAPI PFNGLVERTEXATTRIBL2DVEXTPROC cppgl_glVertexAttribL2dvEXT;
#define glVertexAttribL2dvEXT cppgl_glVertexAttribL2dvEXT
typedef void (APIENTRYP PFNGLVERTEXATTRIBL3DVEXTPROC)(GLuint index, const GLdouble *v);
GLAPI PFNGLVERTEXATTRIBL3DVEXTPROC cppgl_glVertexAttribL3dvEXT;
#define glVertexAttribL3dvEXT cppgl_glVertexAttribL3dvEXT
typedef void (APIENTRYP PFNGLVERTEXATTRIBL4DVEXTPROC)(GLuint index, const GLdouble *v);
GLAPI PFNGLVERTEXATTRIBL4DVEXTPROC cppgl_glVertexAttribL4dvEXT;
#define glVertexAttribL4dvEXT cppgl_glVertexAttribL4dvEXT
typedef void (APIENTRYP PFNGLVERTEXATTRIBLPOINTEREXTPROC)(GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer);
GLAPI PFNGLVERTEXATTRIBLPOINTEREXTPROC cppgl_glVertexAttribLPointerEXT;
#define glVertexAttribLPointerEXT cppgl_glVertexAttribLPointerEXT
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBLDVEXTPROC)(GLuint index, GLenum pname, GLdouble *params);
GLAPI PFNGLGETVERTEXATTRIBLDVEXTPROC cppgl_glGetVertexAttribLdvEXT;
#define glGetVertexAttribLdvEXT cppgl_glGetVertexAttribLdvEXT
#endif
#ifndef GL_EXT_vertex_shader
#define GL_EXT_vertex_shader 1
GLAPI int CPPGL_GL_EXT_vertex_shader;
typedef void (APIENTRYP PFNGLBEGINVERTEXSHADEREXTPROC)();
GLAPI PFNGLBEGINVERTEXSHADEREXTPROC cppgl_glBeginVertexShaderEXT;
#define glBeginVertexShaderEXT cppgl_glBeginVertexShaderEXT
typedef void (APIENTRYP PFNGLENDVERTEXSHADEREXTPROC)();
GLAPI PFNGLENDVERTEXSHADEREXTPROC cppgl_glEndVertexShaderEXT;
#define glEndVertexShaderEXT cppgl_glEndVertexShaderEXT
typedef void (APIENTRYP PFNGLBINDVERTEXSHADEREXTPROC)(GLuint id);
GLAPI PFNGLBINDVERTEXSHADEREXTPROC cppgl_glBindVertexShaderEXT;
#define glBindVertexShaderEXT cppgl_glBindVertexShaderEXT
typedef GLuint (APIENTRYP PFNGLGENVERTEXSHADERSEXTPROC)(GLuint range);
GLAPI PFNGLGENVERTEXSHADERSEXTPROC cppgl_glGenVertexShadersEXT;
#define glGenVertexShadersEXT cppgl_glGenVertexShadersEXT
typedef void (APIENTRYP PFNGLDELETEVERTEXSHADEREXTPROC)(GLuint id);
GLAPI PFNGLDELETEVERTEXSHADEREXTPROC cppgl_glDeleteVertexShaderEXT;
#define glDeleteVertexShaderEXT cppgl_glDeleteVertexShaderEXT
typedef void (APIENTRYP PFNGLSHADEROP1EXTPROC)(GLenum op, GLuint res, GLuint arg1);
GLAPI PFNGLSHADEROP1EXTPROC cppgl_glShaderOp1EXT;
#define glShaderOp1EXT cppgl_glShaderOp1EXT
typedef void (APIENTRYP PFNGLSHADEROP2EXTPROC)(GLenum op, GLuint res, GLuint arg1, GLuint arg2);
GLAPI PFNGLSHADEROP2EXTPROC cppgl_glShaderOp2EXT;
#define glShaderOp2EXT cppgl_glShaderOp2EXT
typedef void (APIENTRYP PFNGLSHADEROP3EXTPROC)(GLenum op, GLuint res, GLuint arg1, GLuint arg2, GLuint arg3);
GLAPI PFNGLSHADEROP3EXTPROC cppgl_glShaderOp3EXT;
#define glShaderOp3EXT cppgl_glShaderOp3EXT
typedef void (APIENTRYP PFNGLSWIZZLEEXTPROC)(GLuint res, GLuint in, GLenum outX, GLenum outY, GLenum outZ, GLenum outW);
GLAPI PFNGLSWIZZLEEXTPROC cppgl_glSwizzleEXT;
#define glSwizzleEXT cppgl_glSwizzleEXT
typedef void (APIENTRYP PFNGLWRITEMASKEXTPROC)(GLuint res, GLuint in, GLenum outX, GLenum outY, GLenum outZ, GLenum outW);
GLAPI PFNGLWRITEMASKEXTPROC cppgl_glWriteMaskEXT;
#define glWriteMaskEXT cppgl_glWriteMaskEXT
typedef void (APIENTRYP PFNGLINSERTCOMPONENTEXTPROC)(GLuint res, GLuint src, GLuint num);
GLAPI PFNGLINSERTCOMPONENTEXTPROC cppgl_glInsertComponentEXT;
#define glInsertComponentEXT cppgl_glInsertComponentEXT
typedef void (APIENTRYP PFNGLEXTRACTCOMPONENTEXTPROC)(GLuint res, GLuint src, GLuint num);
GLAPI PFNGLEXTRACTCOMPONENTEXTPROC cppgl_glExtractComponentEXT;
#define glExtractComponentEXT cppgl_glExtractComponentEXT
typedef GLuint (APIENTRYP PFNGLGENSYMBOLSEXTPROC)(GLenum datatype, GLenum storagetype, GLenum range, GLuint components);
GLAPI PFNGLGENSYMBOLSEXTPROC cppgl_glGenSymbolsEXT;
#define glGenSymbolsEXT cppgl_glGenSymbolsEXT
typedef void (APIENTRYP PFNGLSETINVARIANTEXTPROC)(GLuint id, GLenum type, const void *addr);
GLAPI PFNGLSETINVARIANTEXTPROC cppgl_glSetInvariantEXT;
#define glSetInvariantEXT cppgl_glSetInvariantEXT
typedef void (APIENTRYP PFNGLSETLOCALCONSTANTEXTPROC)(GLuint id, GLenum type, const void *addr);
GLAPI PFNGLSETLOCALCONSTANTEXTPROC cppgl_glSetLocalConstantEXT;
#define glSetLocalConstantEXT cppgl_glSetLocalConstantEXT
typedef void (APIENTRYP PFNGLVARIANTBVEXTPROC)(GLuint id, const GLbyte *addr);
GLAPI PFNGLVARIANTBVEXTPROC cppgl_glVariantbvEXT;
#define glVariantbvEXT cppgl_glVariantbvEXT
typedef void (APIENTRYP PFNGLVARIANTSVEXTPROC)(GLuint id, const GLshort *addr);
GLAPI PFNGLVARIANTSVEXTPROC cppgl_glVariantsvEXT;
#define glVariantsvEXT cppgl_glVariantsvEXT
typedef void (APIENTRYP PFNGLVARIANTIVEXTPROC)(GLuint id, const GLint *addr);
GLAPI PFNGLVARIANTIVEXTPROC cppgl_glVariantivEXT;
#define glVariantivEXT cppgl_glVariantivEXT
typedef void (APIENTRYP PFNGLVARIANTFVEXTPROC)(GLuint id, const GLfloat *addr);
GLAPI PFNGLVARIANTFVEXTPROC cppgl_glVariantfvEXT;
#define glVariantfvEXT cppgl_glVariantfvEXT
typedef void (APIENTRYP PFNGLVARIANTDVEXTPROC)(GLuint id, const GLdouble *addr);
GLAPI PFNGLVARIANTDVEXTPROC cppgl_glVariantdvEXT;
#define glVariantdvEXT cppgl_glVariantdvEXT
typedef void (APIENTRYP PFNGLVARIANTUBVEXTPROC)(GLuint id, const GLubyte *addr);
GLAPI PFNGLVARIANTUBVEXTPROC cppgl_glVariantubvEXT;
#define glVariantubvEXT cppgl_glVariantubvEXT
typedef void (APIENTRYP PFNGLVARIANTUSVEXTPROC)(GLuint id, const GLushort *addr);
GLAPI PFNGLVARIANTUSVEXTPROC cppgl_glVariantusvEXT;
#define glVariantusvEXT cppgl_glVariantusvEXT
typedef void (APIENTRYP PFNGLVARIANTUIVEXTPROC)(GLuint id, const GLuint *addr);
GLAPI PFNGLVARIANTUIVEXTPROC cppgl_glVariantuivEXT;
#define glVariantuivEXT cppgl_glVariantuivEXT
typedef void (APIENTRYP PFNGLVARIANTPOINTEREXTPROC)(GLuint id, GLenum type, GLuint stride, const void *addr);
GLAPI PFNGLVARIANTPOINTEREXTPROC cppgl_glVariantPointerEXT;
#define glVariantPointerEXT cppgl_glVariantPointerEXT
typedef void (APIENTRYP PFNGLENABLEVARIANTCLIENTSTATEEXTPROC)(GLuint id);
GLAPI PFNGLENABLEVARIANTCLIENTSTATEEXTPROC cppgl_glEnableVariantClientStateEXT;
#define glEnableVariantClientStateEXT cppgl_glEnableVariantClientStateEXT
typedef void (APIENTRYP PFNGLDISABLEVARIANTCLIENTSTATEEXTPROC)(GLuint id);
GLAPI PFNGLDISABLEVARIANTCLIENTSTATEEXTPROC cppgl_glDisableVariantClientStateEXT;
#define glDisableVariantClientStateEXT cppgl_glDisableVariantClientStateEXT
typedef GLuint (APIENTRYP PFNGLBINDLIGHTPARAMETEREXTPROC)(GLenum light, GLenum value);
GLAPI PFNGLBINDLIGHTPARAMETEREXTPROC cppgl_glBindLightParameterEXT;
#define glBindLightParameterEXT cppgl_glBindLightParameterEXT
typedef GLuint (APIENTRYP PFNGLBINDMATERIALPARAMETEREXTPROC)(GLenum face, GLenum value);
GLAPI PFNGLBINDMATERIALPARAMETEREXTPROC cppgl_glBindMaterialParameterEXT;
#define glBindMaterialParameterEXT cppgl_glBindMaterialParameterEXT
typedef GLuint (APIENTRYP PFNGLBINDTEXGENPARAMETEREXTPROC)(GLenum unit, GLenum coord, GLenum value);
GLAPI PFNGLBINDTEXGENPARAMETEREXTPROC cppgl_glBindTexGenParameterEXT;
#define glBindTexGenParameterEXT cppgl_glBindTexGenParameterEXT
typedef GLuint (APIENTRYP PFNGLBINDTEXTUREUNITPARAMETEREXTPROC)(GLenum unit, GLenum value);
GLAPI PFNGLBINDTEXTUREUNITPARAMETEREXTPROC cppgl_glBindTextureUnitParameterEXT;
#define glBindTextureUnitParameterEXT cppgl_glBindTextureUnitParameterEXT
typedef GLuint (APIENTRYP PFNGLBINDPARAMETEREXTPROC)(GLenum value);
GLAPI PFNGLBINDPARAMETEREXTPROC cppgl_glBindParameterEXT;
#define glBindParameterEXT cppgl_glBindParameterEXT
typedef GLboolean (APIENTRYP PFNGLISVARIANTENABLEDEXTPROC)(GLuint id, GLenum cap);
GLAPI PFNGLISVARIANTENABLEDEXTPROC cppgl_glIsVariantEnabledEXT;
#define glIsVariantEnabledEXT cppgl_glIsVariantEnabledEXT
typedef void (APIENTRYP PFNGLGETVARIANTBOOLEANVEXTPROC)(GLuint id, GLenum value, GLboolean *data);
GLAPI PFNGLGETVARIANTBOOLEANVEXTPROC cppgl_glGetVariantBooleanvEXT;
#define glGetVariantBooleanvEXT cppgl_glGetVariantBooleanvEXT
typedef void (APIENTRYP PFNGLGETVARIANTINTEGERVEXTPROC)(GLuint id, GLenum value, GLint *data);
GLAPI PFNGLGETVARIANTINTEGERVEXTPROC cppgl_glGetVariantIntegervEXT;
#define glGetVariantIntegervEXT cppgl_glGetVariantIntegervEXT
typedef void (APIENTRYP PFNGLGETVARIANTFLOATVEXTPROC)(GLuint id, GLenum value, GLfloat *data);
GLAPI PFNGLGETVARIANTFLOATVEXTPROC cppgl_glGetVariantFloatvEXT;
#define glGetVariantFloatvEXT cppgl_glGetVariantFloatvEXT
typedef void (APIENTRYP PFNGLGETVARIANTPOINTERVEXTPROC)(GLuint id, GLenum value, void **data);
GLAPI PFNGLGETVARIANTPOINTERVEXTPROC cppgl_glGetVariantPointervEXT;
#define glGetVariantPointervEXT cppgl_glGetVariantPointervEXT
typedef void (APIENTRYP PFNGLGETINVARIANTBOOLEANVEXTPROC)(GLuint id, GLenum value, GLboolean *data);
GLAPI PFNGLGETINVARIANTBOOLEANVEXTPROC cppgl_glGetInvariantBooleanvEXT;
#define glGetInvariantBooleanvEXT cppgl_glGetInvariantBooleanvEXT
typedef void (APIENTRYP PFNGLGETINVARIANTINTEGERVEXTPROC)(GLuint id, GLenum value, GLint *data);
GLAPI PFNGLGETINVARIANTINTEGERVEXTPROC cppgl_glGetInvariantIntegervEXT;
#define glGetInvariantIntegervEXT cppgl_glGetInvariantIntegervEXT
typedef void (APIENTRYP PFNGLGETINVARIANTFLOATVEXTPROC)(GLuint id, GLenum value, GLfloat *data);
GLAPI PFNGLGETINVARIANTFLOATVEXTPROC cppgl_glGetInvariantFloatvEXT;
#define glGetInvariantFloatvEXT cppgl_glGetInvariantFloatvEXT
typedef void (APIENTRYP PFNGLGETLOCALCONSTANTBOOLEANVEXTPROC)(GLuint id, GLenum value, GLboolean *data);
GLAPI PFNGLGETLOCALCONSTANTBOOLEANVEXTPROC cppgl_glGetLocalConstantBooleanvEXT;
#define glGetLocalConstantBooleanvEXT cppgl_glGetLocalConstantBooleanvEXT
typedef void (APIENTRYP PFNGLGETLOCALCONSTANTINTEGERVEXTPROC)(GLuint id, GLenum value, GLint *data);
GLAPI PFNGLGETLOCALCONSTANTINTEGERVEXTPROC cppgl_glGetLocalConstantIntegervEXT;
#define glGetLocalConstantIntegervEXT cppgl_glGetLocalConstantIntegervEXT
typedef void (APIENTRYP PFNGLGETLOCALCONSTANTFLOATVEXTPROC)(GLuint id, GLenum value, GLfloat *data);
GLAPI PFNGLGETLOCALCONSTANTFLOATVEXTPROC cppgl_glGetLocalConstantFloatvEXT;
#define glGetLocalConstantFloatvEXT cppgl_glGetLocalConstantFloatvEXT
#endif
#ifndef GL_EXT_vertex_weighting
#define GL_EXT_vertex_weighting 1
GLAPI int CPPGL_GL_EXT_vertex_weighting;
typedef void (APIENTRYP PFNGLVERTEXWEIGHTFEXTPROC)(GLfloat weight);
GLAPI PFNGLVERTEXWEIGHTFEXTPROC cppgl_glVertexWeightfEXT;
#define glVertexWeightfEXT cppgl_glVertexWeightfEXT
typedef void (APIENTRYP PFNGLVERTEXWEIGHTFVEXTPROC)(const GLfloat *weight);
GLAPI PFNGLVERTEXWEIGHTFVEXTPROC cppgl_glVertexWeightfvEXT;
#define glVertexWeightfvEXT cppgl_glVertexWeightfvEXT
typedef void (APIENTRYP PFNGLVERTEXWEIGHTPOINTEREXTPROC)(GLint size, GLenum type, GLsizei stride, const void *pointer);
GLAPI PFNGLVERTEXWEIGHTPOINTEREXTPROC cppgl_glVertexWeightPointerEXT;
#define glVertexWeightPointerEXT cppgl_glVertexWeightPointerEXT
#endif
#ifndef GL_EXT_window_rectangles
#define GL_EXT_window_rectangles 1
GLAPI int CPPGL_GL_EXT_window_rectangles;
typedef void (APIENTRYP PFNGLWINDOWRECTANGLESEXTPROC)(GLenum mode, GLsizei count, const GLint *box);
GLAPI PFNGLWINDOWRECTANGLESEXTPROC cppgl_glWindowRectanglesEXT;
#define glWindowRectanglesEXT cppgl_glWindowRectanglesEXT
#endif
#ifndef GL_EXT_x11_sync_object
#define GL_EXT_x11_sync_object 1
GLAPI int CPPGL_GL_EXT_x11_sync_object;
typedef GLsync (APIENTRYP PFNGLIMPORTSYNCEXTPROC)(GLenum external_sync_type, GLintptr external_sync, GLbitfield flags);
GLAPI PFNGLIMPORTSYNCEXTPROC cppgl_glImportSyncEXT;
#define glImportSyncEXT cppgl_glImportSyncEXT
#endif
#ifndef GL_GREMEDY_frame_terminator
#define GL_GREMEDY_frame_terminator 1
GLAPI int CPPGL_GL_GREMEDY_frame_terminator;
typedef void (APIENTRYP PFNGLFRAMETERMINATORGREMEDYPROC)();
GLAPI PFNGLFRAMETERMINATORGREMEDYPROC cppgl_glFrameTerminatorGREMEDY;
#define glFrameTerminatorGREMEDY cppgl_glFrameTerminatorGREMEDY
#endif
#ifndef GL_GREMEDY_string_marker
#define GL_GREMEDY_string_marker 1
GLAPI int CPPGL_GL_GREMEDY_string_marker;
typedef void (APIENTRYP PFNGLSTRINGMARKERGREMEDYPROC)(GLsizei len, const void *string);
GLAPI PFNGLSTRINGMARKERGREMEDYPROC cppgl_glStringMarkerGREMEDY;
#define glStringMarkerGREMEDY cppgl_glStringMarkerGREMEDY
#endif
#ifndef GL_HP_convolution_border_modes
#define GL_HP_convolution_border_modes 1
GLAPI int CPPGL_GL_HP_convolution_border_modes;
#endif
#ifndef GL_HP_image_transform
#define GL_HP_image_transform 1
GLAPI int CPPGL_GL_HP_image_transform;
typedef void (APIENTRYP PFNGLIMAGETRANSFORMPARAMETERIHPPROC)(GLenum target, GLenum pname, GLint param);
GLAPI PFNGLIMAGETRANSFORMPARAMETERIHPPROC cppgl_glImageTransformParameteriHP;
#define glImageTransformParameteriHP cppgl_glImageTransformParameteriHP
typedef void (APIENTRYP PFNGLIMAGETRANSFORMPARAMETERFHPPROC)(GLenum target, GLenum pname, GLfloat param);
GLAPI PFNGLIMAGETRANSFORMPARAMETERFHPPROC cppgl_glImageTransformParameterfHP;
#define glImageTransformParameterfHP cppgl_glImageTransformParameterfHP
typedef void (APIENTRYP PFNGLIMAGETRANSFORMPARAMETERIVHPPROC)(GLenum target, GLenum pname, const GLint *params);
GLAPI PFNGLIMAGETRANSFORMPARAMETERIVHPPROC cppgl_glImageTransformParameterivHP;
#define glImageTransformParameterivHP cppgl_glImageTransformParameterivHP
typedef void (APIENTRYP PFNGLIMAGETRANSFORMPARAMETERFVHPPROC)(GLenum target, GLenum pname, const GLfloat *params);
GLAPI PFNGLIMAGETRANSFORMPARAMETERFVHPPROC cppgl_glImageTransformParameterfvHP;
#define glImageTransformParameterfvHP cppgl_glImageTransformParameterfvHP
typedef void (APIENTRYP PFNGLGETIMAGETRANSFORMPARAMETERIVHPPROC)(GLenum target, GLenum pname, GLint *params);
GLAPI PFNGLGETIMAGETRANSFORMPARAMETERIVHPPROC cppgl_glGetImageTransformParameterivHP;
#define glGetImageTransformParameterivHP cppgl_glGetImageTransformParameterivHP
typedef void (APIENTRYP PFNGLGETIMAGETRANSFORMPARAMETERFVHPPROC)(GLenum target, GLenum pname, GLfloat *params);
GLAPI PFNGLGETIMAGETRANSFORMPARAMETERFVHPPROC cppgl_glGetImageTransformParameterfvHP;
#define glGetImageTransformParameterfvHP cppgl_glGetImageTransformParameterfvHP
#endif
#ifndef GL_HP_occlusion_test
#define GL_HP_occlusion_test 1
GLAPI int CPPGL_GL_HP_occlusion_test;
#endif
#ifndef GL_HP_texture_lighting
#define GL_HP_texture_lighting 1
GLAPI int CPPGL_GL_HP_texture_lighting;
#endif
#ifndef GL_IBM_cull_vertex
#define GL_IBM_cull_vertex 1
GLAPI int CPPGL_GL_IBM_cull_vertex;
#endif
#ifndef GL_IBM_multimode_draw_arrays
#define GL_IBM_multimode_draw_arrays 1
GLAPI int CPPGL_GL_IBM_multimode_draw_arrays;
typedef void (APIENTRYP PFNGLMULTIMODEDRAWARRAYSIBMPROC)(const GLenum *mode, const GLint *first, const GLsizei *count, GLsizei primcount, GLint modestride);
GLAPI PFNGLMULTIMODEDRAWARRAYSIBMPROC cppgl_glMultiModeDrawArraysIBM;
#define glMultiModeDrawArraysIBM cppgl_glMultiModeDrawArraysIBM
typedef void (APIENTRYP PFNGLMULTIMODEDRAWELEMENTSIBMPROC)(const GLenum *mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei primcount, GLint modestride);
GLAPI PFNGLMULTIMODEDRAWELEMENTSIBMPROC cppgl_glMultiModeDrawElementsIBM;
#define glMultiModeDrawElementsIBM cppgl_glMultiModeDrawElementsIBM
#endif
#ifndef GL_IBM_rasterpos_clip
#define GL_IBM_rasterpos_clip 1
GLAPI int CPPGL_GL_IBM_rasterpos_clip;
#endif
#ifndef GL_IBM_static_data
#define GL_IBM_static_data 1
GLAPI int CPPGL_GL_IBM_static_data;
typedef void (APIENTRYP PFNGLFLUSHSTATICDATAIBMPROC)(GLenum target);
GLAPI PFNGLFLUSHSTATICDATAIBMPROC cppgl_glFlushStaticDataIBM;
#define glFlushStaticDataIBM cppgl_glFlushStaticDataIBM
#endif
#ifndef GL_IBM_texture_mirrored_repeat
#define GL_IBM_texture_mirrored_repeat 1
GLAPI int CPPGL_GL_IBM_texture_mirrored_repeat;
#endif
#ifndef GL_IBM_vertex_array_lists
#define GL_IBM_vertex_array_lists 1
GLAPI int CPPGL_GL_IBM_vertex_array_lists;
typedef void (APIENTRYP PFNGLCOLORPOINTERLISTIBMPROC)(GLint size, GLenum type, GLint stride, const void **pointer, GLint ptrstride);
GLAPI PFNGLCOLORPOINTERLISTIBMPROC cppgl_glColorPointerListIBM;
#define glColorPointerListIBM cppgl_glColorPointerListIBM
typedef void (APIENTRYP PFNGLSECONDARYCOLORPOINTERLISTIBMPROC)(GLint size, GLenum type, GLint stride, const void **pointer, GLint ptrstride);
GLAPI PFNGLSECONDARYCOLORPOINTERLISTIBMPROC cppgl_glSecondaryColorPointerListIBM;
#define glSecondaryColorPointerListIBM cppgl_glSecondaryColorPointerListIBM
typedef void (APIENTRYP PFNGLEDGEFLAGPOINTERLISTIBMPROC)(GLint stride, const GLboolean **pointer, GLint ptrstride);
GLAPI PFNGLEDGEFLAGPOINTERLISTIBMPROC cppgl_glEdgeFlagPointerListIBM;
#define glEdgeFlagPointerListIBM cppgl_glEdgeFlagPointerListIBM
typedef void (APIENTRYP PFNGLFOGCOORDPOINTERLISTIBMPROC)(GLenum type, GLint stride, const void **pointer, GLint ptrstride);
GLAPI PFNGLFOGCOORDPOINTERLISTIBMPROC cppgl_glFogCoordPointerListIBM;
#define glFogCoordPointerListIBM cppgl_glFogCoordPointerListIBM
typedef void (APIENTRYP PFNGLINDEXPOINTERLISTIBMPROC)(GLenum type, GLint stride, const void **pointer, GLint ptrstride);
GLAPI PFNGLINDEXPOINTERLISTIBMPROC cppgl_glIndexPointerListIBM;
#define glIndexPointerListIBM cppgl_glIndexPointerListIBM
typedef void (APIENTRYP PFNGLNORMALPOINTERLISTIBMPROC)(GLenum type, GLint stride, const void **pointer, GLint ptrstride);
GLAPI PFNGLNORMALPOINTERLISTIBMPROC cppgl_glNormalPointerListIBM;
#define glNormalPointerListIBM cppgl_glNormalPointerListIBM
typedef void (APIENTRYP PFNGLTEXCOORDPOINTERLISTIBMPROC)(GLint size, GLenum type, GLint stride, const void **pointer, GLint ptrstride);
GLAPI PFNGLTEXCOORDPOINTERLISTIBMPROC cppgl_glTexCoordPointerListIBM;
#define glTexCoordPointerListIBM cppgl_glTexCoordPointerListIBM
typedef void (APIENTRYP PFNGLVERTEXPOINTERLISTIBMPROC)(GLint size, GLenum type, GLint stride, const void **pointer, GLint ptrstride);
GLAPI PFNGLVERTEXPOINTERLISTIBMPROC cppgl_glVertexPointerListIBM;
#define glVertexPointerListIBM cppgl_glVertexPointerListIBM
#endif
#ifndef GL_INGR_blend_func_separate
#define GL_INGR_blend_func_separate 1
GLAPI int CPPGL_GL_INGR_blend_func_separate;
typedef void (APIENTRYP PFNGLBLENDFUNCSEPARATEINGRPROC)(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
GLAPI PFNGLBLENDFUNCSEPARATEINGRPROC cppgl_glBlendFuncSeparateINGR;
#define glBlendFuncSeparateINGR cppgl_glBlendFuncSeparateINGR
#endif
#ifndef GL_INGR_color_clamp
#define GL_INGR_color_clamp 1
GLAPI int CPPGL_GL_INGR_color_clamp;
#endif
#ifndef GL_INGR_interlace_read
#define GL_INGR_interlace_read 1
GLAPI int CPPGL_GL_INGR_interlace_read;
#endif
#ifndef GL_INTEL_conservative_rasterization
#define GL_INTEL_conservative_rasterization 1
GLAPI int CPPGL_GL_INTEL_conservative_rasterization;
#endif
#ifndef GL_INTEL_fragment_shader_ordering
#define GL_INTEL_fragment_shader_ordering 1
GLAPI int CPPGL_GL_INTEL_fragment_shader_ordering;
#endif
#ifndef GL_INTEL_framebuffer_CMAA
#define GL_INTEL_framebuffer_CMAA 1
GLAPI int CPPGL_GL_INTEL_framebuffer_CMAA;
typedef void (APIENTRYP PFNGLAPPLYFRAMEBUFFERATTACHMENTCMAAINTELPROC)();
GLAPI PFNGLAPPLYFRAMEBUFFERATTACHMENTCMAAINTELPROC cppgl_glApplyFramebufferAttachmentCMAAINTEL;
#define glApplyFramebufferAttachmentCMAAINTEL cppgl_glApplyFramebufferAttachmentCMAAINTEL
#endif
#ifndef GL_INTEL_map_texture
#define GL_INTEL_map_texture 1
GLAPI int CPPGL_GL_INTEL_map_texture;
typedef void (APIENTRYP PFNGLSYNCTEXTUREINTELPROC)(GLuint texture);
GLAPI PFNGLSYNCTEXTUREINTELPROC cppgl_glSyncTextureINTEL;
#define glSyncTextureINTEL cppgl_glSyncTextureINTEL
typedef void (APIENTRYP PFNGLUNMAPTEXTURE2DINTELPROC)(GLuint texture, GLint level);
GLAPI PFNGLUNMAPTEXTURE2DINTELPROC cppgl_glUnmapTexture2DINTEL;
#define glUnmapTexture2DINTEL cppgl_glUnmapTexture2DINTEL
typedef void * (APIENTRYP PFNGLMAPTEXTURE2DINTELPROC)(GLuint texture, GLint level, GLbitfield access, GLint *stride, GLenum *layout);
GLAPI PFNGLMAPTEXTURE2DINTELPROC cppgl_glMapTexture2DINTEL;
#define glMapTexture2DINTEL cppgl_glMapTexture2DINTEL
#endif
#ifndef GL_INTEL_parallel_arrays
#define GL_INTEL_parallel_arrays 1
GLAPI int CPPGL_GL_INTEL_parallel_arrays;
typedef void (APIENTRYP PFNGLVERTEXPOINTERVINTELPROC)(GLint size, GLenum type, const void **pointer);
GLAPI PFNGLVERTEXPOINTERVINTELPROC cppgl_glVertexPointervINTEL;
#define glVertexPointervINTEL cppgl_glVertexPointervINTEL
typedef void (APIENTRYP PFNGLNORMALPOINTERVINTELPROC)(GLenum type, const void **pointer);
GLAPI PFNGLNORMALPOINTERVINTELPROC cppgl_glNormalPointervINTEL;
#define glNormalPointervINTEL cppgl_glNormalPointervINTEL
typedef void (APIENTRYP PFNGLCOLORPOINTERVINTELPROC)(GLint size, GLenum type, const void **pointer);
GLAPI PFNGLCOLORPOINTERVINTELPROC cppgl_glColorPointervINTEL;
#define glColorPointervINTEL cppgl_glColorPointervINTEL
typedef void (APIENTRYP PFNGLTEXCOORDPOINTERVINTELPROC)(GLint size, GLenum type, const void **pointer);
GLAPI PFNGLTEXCOORDPOINTERVINTELPROC cppgl_glTexCoordPointervINTEL;
#define glTexCoordPointervINTEL cppgl_glTexCoordPointervINTEL
#endif
#ifndef GL_INTEL_performance_query
#define GL_INTEL_performance_query 1
GLAPI int CPPGL_GL_INTEL_performance_query;
typedef void (APIENTRYP PFNGLBEGINPERFQUERYINTELPROC)(GLuint queryHandle);
GLAPI PFNGLBEGINPERFQUERYINTELPROC cppgl_glBeginPerfQueryINTEL;
#define glBeginPerfQueryINTEL cppgl_glBeginPerfQueryINTEL
typedef void (APIENTRYP PFNGLCREATEPERFQUERYINTELPROC)(GLuint queryId, GLuint *queryHandle);
GLAPI PFNGLCREATEPERFQUERYINTELPROC cppgl_glCreatePerfQueryINTEL;
#define glCreatePerfQueryINTEL cppgl_glCreatePerfQueryINTEL
typedef void (APIENTRYP PFNGLDELETEPERFQUERYINTELPROC)(GLuint queryHandle);
GLAPI PFNGLDELETEPERFQUERYINTELPROC cppgl_glDeletePerfQueryINTEL;
#define glDeletePerfQueryINTEL cppgl_glDeletePerfQueryINTEL
typedef void (APIENTRYP PFNGLENDPERFQUERYINTELPROC)(GLuint queryHandle);
GLAPI PFNGLENDPERFQUERYINTELPROC cppgl_glEndPerfQueryINTEL;
#define glEndPerfQueryINTEL cppgl_glEndPerfQueryINTEL
typedef void (APIENTRYP PFNGLGETFIRSTPERFQUERYIDINTELPROC)(GLuint *queryId);
GLAPI PFNGLGETFIRSTPERFQUERYIDINTELPROC cppgl_glGetFirstPerfQueryIdINTEL;
#define glGetFirstPerfQueryIdINTEL cppgl_glGetFirstPerfQueryIdINTEL
typedef void (APIENTRYP PFNGLGETNEXTPERFQUERYIDINTELPROC)(GLuint queryId, GLuint *nextQueryId);
GLAPI PFNGLGETNEXTPERFQUERYIDINTELPROC cppgl_glGetNextPerfQueryIdINTEL;
#define glGetNextPerfQueryIdINTEL cppgl_glGetNextPerfQueryIdINTEL
typedef void (APIENTRYP PFNGLGETPERFCOUNTERINFOINTELPROC)(GLuint queryId, GLuint counterId, GLuint counterNameLength, GLchar *counterName, GLuint counterDescLength, GLchar *counterDesc, GLuint *counterOffset, GLuint *counterDataSize, GLuint *counterTypeEnum, GLuint *counterDataTypeEnum, GLuint64 *rawCounterMaxValue);
GLAPI PFNGLGETPERFCOUNTERINFOINTELPROC cppgl_glGetPerfCounterInfoINTEL;
#define glGetPerfCounterInfoINTEL cppgl_glGetPerfCounterInfoINTEL
typedef void (APIENTRYP PFNGLGETPERFQUERYDATAINTELPROC)(GLuint queryHandle, GLuint flags, GLsizei dataSize, GLvoid *data, GLuint *bytesWritten);
GLAPI PFNGLGETPERFQUERYDATAINTELPROC cppgl_glGetPerfQueryDataINTEL;
#define glGetPerfQueryDataINTEL cppgl_glGetPerfQueryDataINTEL
typedef void (APIENTRYP PFNGLGETPERFQUERYIDBYNAMEINTELPROC)(GLchar *queryName, GLuint *queryId);
GLAPI PFNGLGETPERFQUERYIDBYNAMEINTELPROC cppgl_glGetPerfQueryIdByNameINTEL;
#define glGetPerfQueryIdByNameINTEL cppgl_glGetPerfQueryIdByNameINTEL
typedef void (APIENTRYP PFNGLGETPERFQUERYINFOINTELPROC)(GLuint queryId, GLuint queryNameLength, GLchar *queryName, GLuint *dataSize, GLuint *noCounters, GLuint *noInstances, GLuint *capsMask);
GLAPI PFNGLGETPERFQUERYINFOINTELPROC cppgl_glGetPerfQueryInfoINTEL;
#define glGetPerfQueryInfoINTEL cppgl_glGetPerfQueryInfoINTEL
#endif
#ifndef GL_KHR_blend_equation_advanced
#define GL_KHR_blend_equation_advanced 1
GLAPI int CPPGL_GL_KHR_blend_equation_advanced;
typedef void (APIENTRYP PFNGLBLENDBARRIERKHRPROC)();
GLAPI PFNGLBLENDBARRIERKHRPROC cppgl_glBlendBarrierKHR;
#define glBlendBarrierKHR cppgl_glBlendBarrierKHR
#endif
#ifndef GL_KHR_blend_equation_advanced_coherent
#define GL_KHR_blend_equation_advanced_coherent 1
GLAPI int CPPGL_GL_KHR_blend_equation_advanced_coherent;
#endif
#ifndef GL_KHR_context_flush_control
#define GL_KHR_context_flush_control 1
GLAPI int CPPGL_GL_KHR_context_flush_control;
#endif
#ifndef GL_KHR_debug
#define GL_KHR_debug 1
GLAPI int CPPGL_GL_KHR_debug;
typedef void (APIENTRYP PFNGLDEBUGMESSAGECONTROLPROC)(GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint *ids, GLboolean enabled);
GLAPI PFNGLDEBUGMESSAGECONTROLPROC cppgl_glDebugMessageControl;
#define glDebugMessageControl cppgl_glDebugMessageControl
typedef void (APIENTRYP PFNGLDEBUGMESSAGEINSERTPROC)(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *buf);
GLAPI PFNGLDEBUGMESSAGEINSERTPROC cppgl_glDebugMessageInsert;
#define glDebugMessageInsert cppgl_glDebugMessageInsert
typedef void (APIENTRYP PFNGLDEBUGMESSAGECALLBACKPROC)(GLDEBUGPROC callback, const void *userParam);
GLAPI PFNGLDEBUGMESSAGECALLBACKPROC cppgl_glDebugMessageCallback;
#define glDebugMessageCallback cppgl_glDebugMessageCallback
typedef GLuint (APIENTRYP PFNGLGETDEBUGMESSAGELOGPROC)(GLuint count, GLsizei bufSize, GLenum *sources, GLenum *types, GLuint *ids, GLenum *severities, GLsizei *lengths, GLchar *messageLog);
GLAPI PFNGLGETDEBUGMESSAGELOGPROC cppgl_glGetDebugMessageLog;
#define glGetDebugMessageLog cppgl_glGetDebugMessageLog
typedef void (APIENTRYP PFNGLPUSHDEBUGGROUPPROC)(GLenum source, GLuint id, GLsizei length, const GLchar *message);
GLAPI PFNGLPUSHDEBUGGROUPPROC cppgl_glPushDebugGroup;
#define glPushDebugGroup cppgl_glPushDebugGroup
typedef void (APIENTRYP PFNGLPOPDEBUGGROUPPROC)();
GLAPI PFNGLPOPDEBUGGROUPPROC cppgl_glPopDebugGroup;
#define glPopDebugGroup cppgl_glPopDebugGroup
typedef void (APIENTRYP PFNGLOBJECTLABELPROC)(GLenum identifier, GLuint name, GLsizei length, const GLchar *label);
GLAPI PFNGLOBJECTLABELPROC cppgl_glObjectLabel;
#define glObjectLabel cppgl_glObjectLabel
typedef void (APIENTRYP PFNGLGETOBJECTLABELPROC)(GLenum identifier, GLuint name, GLsizei bufSize, GLsizei *length, GLchar *label);
GLAPI PFNGLGETOBJECTLABELPROC cppgl_glGetObjectLabel;
#define glGetObjectLabel cppgl_glGetObjectLabel
typedef void (APIENTRYP PFNGLOBJECTPTRLABELPROC)(const void *ptr, GLsizei length, const GLchar *label);
GLAPI PFNGLOBJECTPTRLABELPROC cppgl_glObjectPtrLabel;
#define glObjectPtrLabel cppgl_glObjectPtrLabel
typedef void (APIENTRYP PFNGLGETOBJECTPTRLABELPROC)(const void *ptr, GLsizei bufSize, GLsizei *length, GLchar *label);
GLAPI PFNGLGETOBJECTPTRLABELPROC cppgl_glGetObjectPtrLabel;
#define glGetObjectPtrLabel cppgl_glGetObjectPtrLabel
typedef void (APIENTRYP PFNGLDEBUGMESSAGECONTROLKHRPROC)(GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint *ids, GLboolean enabled);
GLAPI PFNGLDEBUGMESSAGECONTROLKHRPROC cppgl_glDebugMessageControlKHR;
#define glDebugMessageControlKHR cppgl_glDebugMessageControlKHR
typedef void (APIENTRYP PFNGLDEBUGMESSAGEINSERTKHRPROC)(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *buf);
GLAPI PFNGLDEBUGMESSAGEINSERTKHRPROC cppgl_glDebugMessageInsertKHR;
#define glDebugMessageInsertKHR cppgl_glDebugMessageInsertKHR
typedef void (APIENTRYP PFNGLDEBUGMESSAGECALLBACKKHRPROC)(GLDEBUGPROCKHR callback, const void *userParam);
GLAPI PFNGLDEBUGMESSAGECALLBACKKHRPROC cppgl_glDebugMessageCallbackKHR;
#define glDebugMessageCallbackKHR cppgl_glDebugMessageCallbackKHR
typedef GLuint (APIENTRYP PFNGLGETDEBUGMESSAGELOGKHRPROC)(GLuint count, GLsizei bufSize, GLenum *sources, GLenum *types, GLuint *ids, GLenum *severities, GLsizei *lengths, GLchar *messageLog);
GLAPI PFNGLGETDEBUGMESSAGELOGKHRPROC cppgl_glGetDebugMessageLogKHR;
#define glGetDebugMessageLogKHR cppgl_glGetDebugMessageLogKHR
typedef void (APIENTRYP PFNGLPUSHDEBUGGROUPKHRPROC)(GLenum source, GLuint id, GLsizei length, const GLchar *message);
GLAPI PFNGLPUSHDEBUGGROUPKHRPROC cppgl_glPushDebugGroupKHR;
#define glPushDebugGroupKHR cppgl_glPushDebugGroupKHR
typedef void (APIENTRYP PFNGLPOPDEBUGGROUPKHRPROC)();
GLAPI PFNGLPOPDEBUGGROUPKHRPROC cppgl_glPopDebugGroupKHR;
#define glPopDebugGroupKHR cppgl_glPopDebugGroupKHR
typedef void (APIENTRYP PFNGLOBJECTLABELKHRPROC)(GLenum identifier, GLuint name, GLsizei length, const GLchar *label);
GLAPI PFNGLOBJECTLABELKHRPROC cppgl_glObjectLabelKHR;
#define glObjectLabelKHR cppgl_glObjectLabelKHR
typedef void (APIENTRYP PFNGLGETOBJECTLABELKHRPROC)(GLenum identifier, GLuint name, GLsizei bufSize, GLsizei *length, GLchar *label);
GLAPI PFNGLGETOBJECTLABELKHRPROC cppgl_glGetObjectLabelKHR;
#define glGetObjectLabelKHR cppgl_glGetObjectLabelKHR
typedef void (APIENTRYP PFNGLOBJECTPTRLABELKHRPROC)(const void *ptr, GLsizei length, const GLchar *label);
GLAPI PFNGLOBJECTPTRLABELKHRPROC cppgl_glObjectPtrLabelKHR;
#define glObjectPtrLabelKHR cppgl_glObjectPtrLabelKHR
typedef void (APIENTRYP PFNGLGETOBJECTPTRLABELKHRPROC)(const void *ptr, GLsizei bufSize, GLsizei *length, GLchar *label);
GLAPI PFNGLGETOBJECTPTRLABELKHRPROC cppgl_glGetObjectPtrLabelKHR;
#define glGetObjectPtrLabelKHR cppgl_glGetObjectPtrLabelKHR
typedef void (APIENTRYP PFNGLGETPOINTERVKHRPROC)(GLenum pname, void **params);
GLAPI PFNGLGETPOINTERVKHRPROC cppgl_glGetPointervKHR;
#define glGetPointervKHR cppgl_glGetPointervKHR
#endif
#ifndef GL_KHR_no_error
#define GL_KHR_no_error 1
GLAPI int CPPGL_GL_KHR_no_error;
#endif
#ifndef GL_KHR_robust_buffer_access_behavior
#define GL_KHR_robust_buffer_access_behavior 1
GLAPI int CPPGL_GL_KHR_robust_buffer_access_behavior;
#endif
#ifndef GL_KHR_robustness
#define GL_KHR_robustness 1
GLAPI int CPPGL_GL_KHR_robustness;
typedef GLenum (APIENTRYP PFNGLGETGRAPHICSRESETSTATUSPROC)();
GLAPI PFNGLGETGRAPHICSRESETSTATUSPROC cppgl_glGetGraphicsResetStatus;
#define glGetGraphicsResetStatus cppgl_glGetGraphicsResetStatus
typedef void (APIENTRYP PFNGLREADNPIXELSPROC)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void *data);
GLAPI PFNGLREADNPIXELSPROC cppgl_glReadnPixels;
#define glReadnPixels cppgl_glReadnPixels
typedef void (APIENTRYP PFNGLGETNUNIFORMFVPROC)(GLuint program, GLint location, GLsizei bufSize, GLfloat *params);
GLAPI PFNGLGETNUNIFORMFVPROC cppgl_glGetnUniformfv;
#define glGetnUniformfv cppgl_glGetnUniformfv
typedef void (APIENTRYP PFNGLGETNUNIFORMIVPROC)(GLuint program, GLint location, GLsizei bufSize, GLint *params);
GLAPI PFNGLGETNUNIFORMIVPROC cppgl_glGetnUniformiv;
#define glGetnUniformiv cppgl_glGetnUniformiv
typedef void (APIENTRYP PFNGLGETNUNIFORMUIVPROC)(GLuint program, GLint location, GLsizei bufSize, GLuint *params);
GLAPI PFNGLGETNUNIFORMUIVPROC cppgl_glGetnUniformuiv;
#define glGetnUniformuiv cppgl_glGetnUniformuiv
typedef GLenum (APIENTRYP PFNGLGETGRAPHICSRESETSTATUSKHRPROC)();
GLAPI PFNGLGETGRAPHICSRESETSTATUSKHRPROC cppgl_glGetGraphicsResetStatusKHR;
#define glGetGraphicsResetStatusKHR cppgl_glGetGraphicsResetStatusKHR
typedef void (APIENTRYP PFNGLREADNPIXELSKHRPROC)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void *data);
GLAPI PFNGLREADNPIXELSKHRPROC cppgl_glReadnPixelsKHR;
#define glReadnPixelsKHR cppgl_glReadnPixelsKHR
typedef void (APIENTRYP PFNGLGETNUNIFORMFVKHRPROC)(GLuint program, GLint location, GLsizei bufSize, GLfloat *params);
GLAPI PFNGLGETNUNIFORMFVKHRPROC cppgl_glGetnUniformfvKHR;
#define glGetnUniformfvKHR cppgl_glGetnUniformfvKHR
typedef void (APIENTRYP PFNGLGETNUNIFORMIVKHRPROC)(GLuint program, GLint location, GLsizei bufSize, GLint *params);
GLAPI PFNGLGETNUNIFORMIVKHRPROC cppgl_glGetnUniformivKHR;
#define glGetnUniformivKHR cppgl_glGetnUniformivKHR
typedef void (APIENTRYP PFNGLGETNUNIFORMUIVKHRPROC)(GLuint program, GLint location, GLsizei bufSize, GLuint *params);
GLAPI PFNGLGETNUNIFORMUIVKHRPROC cppgl_glGetnUniformuivKHR;
#define glGetnUniformuivKHR cppgl_glGetnUniformuivKHR
#endif
#ifndef GL_KHR_texture_compression_astc_hdr
#define GL_KHR_texture_compression_astc_hdr 1
GLAPI int CPPGL_GL_KHR_texture_compression_astc_hdr;
#endif
#ifndef GL_KHR_texture_compression_astc_ldr
#define GL_KHR_texture_compression_astc_ldr 1
GLAPI int CPPGL_GL_KHR_texture_compression_astc_ldr;
#endif
#ifndef GL_KHR_texture_compression_astc_sliced_3d
#define GL_KHR_texture_compression_astc_sliced_3d 1
GLAPI int CPPGL_GL_KHR_texture_compression_astc_sliced_3d;
#endif
#ifndef GL_MESAX_texture_stack
#define GL_MESAX_texture_stack 1
GLAPI int CPPGL_GL_MESAX_texture_stack;
#endif
#ifndef GL_MESA_pack_invert
#define GL_MESA_pack_invert 1
GLAPI int CPPGL_GL_MESA_pack_invert;
#endif
#ifndef GL_MESA_resize_buffers
#define GL_MESA_resize_buffers 1
GLAPI int CPPGL_GL_MESA_resize_buffers;
typedef void (APIENTRYP PFNGLRESIZEBUFFERSMESAPROC)();
GLAPI PFNGLRESIZEBUFFERSMESAPROC cppgl_glResizeBuffersMESA;
#define glResizeBuffersMESA cppgl_glResizeBuffersMESA
#endif
#ifndef GL_MESA_window_pos
#define GL_MESA_window_pos 1
GLAPI int CPPGL_GL_MESA_window_pos;
typedef void (APIENTRYP PFNGLWINDOWPOS2DMESAPROC)(GLdouble x, GLdouble y);
GLAPI PFNGLWINDOWPOS2DMESAPROC cppgl_glWindowPos2dMESA;
#define glWindowPos2dMESA cppgl_glWindowPos2dMESA
typedef void (APIENTRYP PFNGLWINDOWPOS2DVMESAPROC)(const GLdouble *v);
GLAPI PFNGLWINDOWPOS2DVMESAPROC cppgl_glWindowPos2dvMESA;
#define glWindowPos2dvMESA cppgl_glWindowPos2dvMESA
typedef void (APIENTRYP PFNGLWINDOWPOS2FMESAPROC)(GLfloat x, GLfloat y);
GLAPI PFNGLWINDOWPOS2FMESAPROC cppgl_glWindowPos2fMESA;
#define glWindowPos2fMESA cppgl_glWindowPos2fMESA
typedef void (APIENTRYP PFNGLWINDOWPOS2FVMESAPROC)(const GLfloat *v);
GLAPI PFNGLWINDOWPOS2FVMESAPROC cppgl_glWindowPos2fvMESA;
#define glWindowPos2fvMESA cppgl_glWindowPos2fvMESA
typedef void (APIENTRYP PFNGLWINDOWPOS2IMESAPROC)(GLint x, GLint y);
GLAPI PFNGLWINDOWPOS2IMESAPROC cppgl_glWindowPos2iMESA;
#define glWindowPos2iMESA cppgl_glWindowPos2iMESA
typedef void (APIENTRYP PFNGLWINDOWPOS2IVMESAPROC)(const GLint *v);
GLAPI PFNGLWINDOWPOS2IVMESAPROC cppgl_glWindowPos2ivMESA;
#define glWindowPos2ivMESA cppgl_glWindowPos2ivMESA
typedef void (APIENTRYP PFNGLWINDOWPOS2SMESAPROC)(GLshort x, GLshort y);
GLAPI PFNGLWINDOWPOS2SMESAPROC cppgl_glWindowPos2sMESA;
#define glWindowPos2sMESA cppgl_glWindowPos2sMESA
typedef void (APIENTRYP PFNGLWINDOWPOS2SVMESAPROC)(const GLshort *v);
GLAPI PFNGLWINDOWPOS2SVMESAPROC cppgl_glWindowPos2svMESA;
#define glWindowPos2svMESA cppgl_glWindowPos2svMESA
typedef void (APIENTRYP PFNGLWINDOWPOS3DMESAPROC)(GLdouble x, GLdouble y, GLdouble z);
GLAPI PFNGLWINDOWPOS3DMESAPROC cppgl_glWindowPos3dMESA;
#define glWindowPos3dMESA cppgl_glWindowPos3dMESA
typedef void (APIENTRYP PFNGLWINDOWPOS3DVMESAPROC)(const GLdouble *v);
GLAPI PFNGLWINDOWPOS3DVMESAPROC cppgl_glWindowPos3dvMESA;
#define glWindowPos3dvMESA cppgl_glWindowPos3dvMESA
typedef void (APIENTRYP PFNGLWINDOWPOS3FMESAPROC)(GLfloat x, GLfloat y, GLfloat z);
GLAPI PFNGLWINDOWPOS3FMESAPROC cppgl_glWindowPos3fMESA;
#define glWindowPos3fMESA cppgl_glWindowPos3fMESA
typedef void (APIENTRYP PFNGLWINDOWPOS3FVMESAPROC)(const GLfloat *v);
GLAPI PFNGLWINDOWPOS3FVMESAPROC cppgl_glWindowPos3fvMESA;
#define glWindowPos3fvMESA cppgl_glWindowPos3fvMESA
typedef void (APIENTRYP PFNGLWINDOWPOS3IMESAPROC)(GLint x, GLint y, GLint z);
GLAPI PFNGLWINDOWPOS3IMESAPROC cppgl_glWindowPos3iMESA;
#define glWindowPos3iMESA cppgl_glWindowPos3iMESA
typedef void (APIENTRYP PFNGLWINDOWPOS3IVMESAPROC)(const GLint *v);
GLAPI PFNGLWINDOWPOS3IVMESAPROC cppgl_glWindowPos3ivMESA;
#define glWindowPos3ivMESA cppgl_glWindowPos3ivMESA
typedef void (APIENTRYP PFNGLWINDOWPOS3SMESAPROC)(GLshort x, GLshort y, GLshort z);
GLAPI PFNGLWINDOWPOS3SMESAPROC cppgl_glWindowPos3sMESA;
#define glWindowPos3sMESA cppgl_glWindowPos3sMESA
typedef void (APIENTRYP PFNGLWINDOWPOS3SVMESAPROC)(const GLshort *v);
GLAPI PFNGLWINDOWPOS3SVMESAPROC cppgl_glWindowPos3svMESA;
#define glWindowPos3svMESA cppgl_glWindowPos3svMESA
typedef void (APIENTRYP PFNGLWINDOWPOS4DMESAPROC)(GLdouble x, GLdouble y, GLdouble z, GLdouble w);
GLAPI PFNGLWINDOWPOS4DMESAPROC cppgl_glWindowPos4dMESA;
#define glWindowPos4dMESA cppgl_glWindowPos4dMESA
typedef void (APIENTRYP PFNGLWINDOWPOS4DVMESAPROC)(const GLdouble *v);
GLAPI PFNGLWINDOWPOS4DVMESAPROC cppgl_glWindowPos4dvMESA;
#define glWindowPos4dvMESA cppgl_glWindowPos4dvMESA
typedef void (APIENTRYP PFNGLWINDOWPOS4FMESAPROC)(GLfloat x, GLfloat y, GLfloat z, GLfloat w);
GLAPI PFNGLWINDOWPOS4FMESAPROC cppgl_glWindowPos4fMESA;
#define glWindowPos4fMESA cppgl_glWindowPos4fMESA
typedef void (APIENTRYP PFNGLWINDOWPOS4FVMESAPROC)(const GLfloat *v);
GLAPI PFNGLWINDOWPOS4FVMESAPROC cppgl_glWindowPos4fvMESA;
#define glWindowPos4fvMESA cppgl_glWindowPos4fvMESA
typedef void (APIENTRYP PFNGLWINDOWPOS4IMESAPROC)(GLint x, GLint y, GLint z, GLint w);
GLAPI PFNGLWINDOWPOS4IMESAPROC cppgl_glWindowPos4iMESA;
#define glWindowPos4iMESA cppgl_glWindowPos4iMESA
typedef void (APIENTRYP PFNGLWINDOWPOS4IVMESAPROC)(const GLint *v);
GLAPI PFNGLWINDOWPOS4IVMESAPROC cppgl_glWindowPos4ivMESA;
#define glWindowPos4ivMESA cppgl_glWindowPos4ivMESA
typedef void (APIENTRYP PFNGLWINDOWPOS4SMESAPROC)(GLshort x, GLshort y, GLshort z, GLshort w);
GLAPI PFNGLWINDOWPOS4SMESAPROC cppgl_glWindowPos4sMESA;
#define glWindowPos4sMESA cppgl_glWindowPos4sMESA
typedef void (APIENTRYP PFNGLWINDOWPOS4SVMESAPROC)(const GLshort *v);
GLAPI PFNGLWINDOWPOS4SVMESAPROC cppgl_glWindowPos4svMESA;
#define glWindowPos4svMESA cppgl_glWindowPos4svMESA
#endif
#ifndef GL_MESA_ycbcr_texture
#define GL_MESA_ycbcr_texture 1
GLAPI int CPPGL_GL_MESA_ycbcr_texture;
#endif
#ifndef GL_NVX_conditional_render
#define GL_NVX_conditional_render 1
GLAPI int CPPGL_GL_NVX_conditional_render;
typedef void (APIENTRYP PFNGLBEGINCONDITIONALRENDERNVXPROC)(GLuint id);
GLAPI PFNGLBEGINCONDITIONALRENDERNVXPROC cppgl_glBeginConditionalRenderNVX;
#define glBeginConditionalRenderNVX cppgl_glBeginConditionalRenderNVX
typedef void (APIENTRYP PFNGLENDCONDITIONALRENDERNVXPROC)();
GLAPI PFNGLENDCONDITIONALRENDERNVXPROC cppgl_glEndConditionalRenderNVX;
#define glEndConditionalRenderNVX cppgl_glEndConditionalRenderNVX
#endif
#ifndef GL_NVX_gpu_memory_info
#define GL_NVX_gpu_memory_info 1
GLAPI int CPPGL_GL_NVX_gpu_memory_info;
#endif
#ifndef GL_NV_bindless_multi_draw_indirect
#define GL_NV_bindless_multi_draw_indirect 1
GLAPI int CPPGL_GL_NV_bindless_multi_draw_indirect;
typedef void (APIENTRYP PFNGLMULTIDRAWARRAYSINDIRECTBINDLESSNVPROC)(GLenum mode, const void *indirect, GLsizei drawCount, GLsizei stride, GLint vertexBufferCount);
GLAPI PFNGLMULTIDRAWARRAYSINDIRECTBINDLESSNVPROC cppgl_glMultiDrawArraysIndirectBindlessNV;
#define glMultiDrawArraysIndirectBindlessNV cppgl_glMultiDrawArraysIndirectBindlessNV
typedef void (APIENTRYP PFNGLMULTIDRAWELEMENTSINDIRECTBINDLESSNVPROC)(GLenum mode, GLenum type, const void *indirect, GLsizei drawCount, GLsizei stride, GLint vertexBufferCount);
GLAPI PFNGLMULTIDRAWELEMENTSINDIRECTBINDLESSNVPROC cppgl_glMultiDrawElementsIndirectBindlessNV;
#define glMultiDrawElementsIndirectBindlessNV cppgl_glMultiDrawElementsIndirectBindlessNV
#endif
#ifndef GL_NV_bindless_multi_draw_indirect_count
#define GL_NV_bindless_multi_draw_indirect_count 1
GLAPI int CPPGL_GL_NV_bindless_multi_draw_indirect_count;
typedef void (APIENTRYP PFNGLMULTIDRAWARRAYSINDIRECTBINDLESSCOUNTNVPROC)(GLenum mode, const void *indirect, GLsizei drawCount, GLsizei maxDrawCount, GLsizei stride, GLint vertexBufferCount);
GLAPI PFNGLMULTIDRAWARRAYSINDIRECTBINDLESSCOUNTNVPROC cppgl_glMultiDrawArraysIndirectBindlessCountNV;
#define glMultiDrawArraysIndirectBindlessCountNV cppgl_glMultiDrawArraysIndirectBindlessCountNV
typedef void (APIENTRYP PFNGLMULTIDRAWELEMENTSINDIRECTBINDLESSCOUNTNVPROC)(GLenum mode, GLenum type, const void *indirect, GLsizei drawCount, GLsizei maxDrawCount, GLsizei stride, GLint vertexBufferCount);
GLAPI PFNGLMULTIDRAWELEMENTSINDIRECTBINDLESSCOUNTNVPROC cppgl_glMultiDrawElementsIndirectBindlessCountNV;
#define glMultiDrawElementsIndirectBindlessCountNV cppgl_glMultiDrawElementsIndirectBindlessCountNV
#endif
#ifndef GL_NV_bindless_texture
#define GL_NV_bindless_texture 1
GLAPI int CPPGL_GL_NV_bindless_texture;
typedef GLuint64 (APIENTRYP PFNGLGETTEXTUREHANDLENVPROC)(GLuint texture);
GLAPI PFNGLGETTEXTUREHANDLENVPROC cppgl_glGetTextureHandleNV;
#define glGetTextureHandleNV cppgl_glGetTextureHandleNV
typedef GLuint64 (APIENTRYP PFNGLGETTEXTURESAMPLERHANDLENVPROC)(GLuint texture, GLuint sampler);
GLAPI PFNGLGETTEXTURESAMPLERHANDLENVPROC cppgl_glGetTextureSamplerHandleNV;
#define glGetTextureSamplerHandleNV cppgl_glGetTextureSamplerHandleNV
typedef void (APIENTRYP PFNGLMAKETEXTUREHANDLERESIDENTNVPROC)(GLuint64 handle);
GLAPI PFNGLMAKETEXTUREHANDLERESIDENTNVPROC cppgl_glMakeTextureHandleResidentNV;
#define glMakeTextureHandleResidentNV cppgl_glMakeTextureHandleResidentNV
typedef void (APIENTRYP PFNGLMAKETEXTUREHANDLENONRESIDENTNVPROC)(GLuint64 handle);
GLAPI PFNGLMAKETEXTUREHANDLENONRESIDENTNVPROC cppgl_glMakeTextureHandleNonResidentNV;
#define glMakeTextureHandleNonResidentNV cppgl_glMakeTextureHandleNonResidentNV
typedef GLuint64 (APIENTRYP PFNGLGETIMAGEHANDLENVPROC)(GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum format);
GLAPI PFNGLGETIMAGEHANDLENVPROC cppgl_glGetImageHandleNV;
#define glGetImageHandleNV cppgl_glGetImageHandleNV
typedef void (APIENTRYP PFNGLMAKEIMAGEHANDLERESIDENTNVPROC)(GLuint64 handle, GLenum access);
GLAPI PFNGLMAKEIMAGEHANDLERESIDENTNVPROC cppgl_glMakeImageHandleResidentNV;
#define glMakeImageHandleResidentNV cppgl_glMakeImageHandleResidentNV
typedef void (APIENTRYP PFNGLMAKEIMAGEHANDLENONRESIDENTNVPROC)(GLuint64 handle);
GLAPI PFNGLMAKEIMAGEHANDLENONRESIDENTNVPROC cppgl_glMakeImageHandleNonResidentNV;
#define glMakeImageHandleNonResidentNV cppgl_glMakeImageHandleNonResidentNV
typedef void (APIENTRYP PFNGLUNIFORMHANDLEUI64NVPROC)(GLint location, GLuint64 value);
GLAPI PFNGLUNIFORMHANDLEUI64NVPROC cppgl_glUniformHandleui64NV;
#define glUniformHandleui64NV cppgl_glUniformHandleui64NV
typedef void (APIENTRYP PFNGLUNIFORMHANDLEUI64VNVPROC)(GLint location, GLsizei count, const GLuint64 *value);
GLAPI PFNGLUNIFORMHANDLEUI64VNVPROC cppgl_glUniformHandleui64vNV;
#define glUniformHandleui64vNV cppgl_glUniformHandleui64vNV
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMHANDLEUI64NVPROC)(GLuint program, GLint location, GLuint64 value);
GLAPI PFNGLPROGRAMUNIFORMHANDLEUI64NVPROC cppgl_glProgramUniformHandleui64NV;
#define glProgramUniformHandleui64NV cppgl_glProgramUniformHandleui64NV
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMHANDLEUI64VNVPROC)(GLuint program, GLint location, GLsizei count, const GLuint64 *values);
GLAPI PFNGLPROGRAMUNIFORMHANDLEUI64VNVPROC cppgl_glProgramUniformHandleui64vNV;
#define glProgramUniformHandleui64vNV cppgl_glProgramUniformHandleui64vNV
typedef GLboolean (APIENTRYP PFNGLISTEXTUREHANDLERESIDENTNVPROC)(GLuint64 handle);
GLAPI PFNGLISTEXTUREHANDLERESIDENTNVPROC cppgl_glIsTextureHandleResidentNV;
#define glIsTextureHandleResidentNV cppgl_glIsTextureHandleResidentNV
typedef GLboolean (APIENTRYP PFNGLISIMAGEHANDLERESIDENTNVPROC)(GLuint64 handle);
GLAPI PFNGLISIMAGEHANDLERESIDENTNVPROC cppgl_glIsImageHandleResidentNV;
#define glIsImageHandleResidentNV cppgl_glIsImageHandleResidentNV
#endif
#ifndef GL_NV_blend_equation_advanced
#define GL_NV_blend_equation_advanced 1
GLAPI int CPPGL_GL_NV_blend_equation_advanced;
typedef void (APIENTRYP PFNGLBLENDPARAMETERINVPROC)(GLenum pname, GLint value);
GLAPI PFNGLBLENDPARAMETERINVPROC cppgl_glBlendParameteriNV;
#define glBlendParameteriNV cppgl_glBlendParameteriNV
typedef void (APIENTRYP PFNGLBLENDBARRIERNVPROC)();
GLAPI PFNGLBLENDBARRIERNVPROC cppgl_glBlendBarrierNV;
#define glBlendBarrierNV cppgl_glBlendBarrierNV
#endif
#ifndef GL_NV_blend_equation_advanced_coherent
#define GL_NV_blend_equation_advanced_coherent 1
GLAPI int CPPGL_GL_NV_blend_equation_advanced_coherent;
#endif
#ifndef GL_NV_blend_square
#define GL_NV_blend_square 1
GLAPI int CPPGL_GL_NV_blend_square;
#endif
#ifndef GL_NV_clip_space_w_scaling
#define GL_NV_clip_space_w_scaling 1
GLAPI int CPPGL_GL_NV_clip_space_w_scaling;
typedef void (APIENTRYP PFNGLVIEWPORTPOSITIONWSCALENVPROC)(GLuint index, GLfloat xcoeff, GLfloat ycoeff);
GLAPI PFNGLVIEWPORTPOSITIONWSCALENVPROC cppgl_glViewportPositionWScaleNV;
#define glViewportPositionWScaleNV cppgl_glViewportPositionWScaleNV
#endif
#ifndef GL_NV_command_list
#define GL_NV_command_list 1
GLAPI int CPPGL_GL_NV_command_list;
typedef void (APIENTRYP PFNGLCREATESTATESNVPROC)(GLsizei n, GLuint *states);
GLAPI PFNGLCREATESTATESNVPROC cppgl_glCreateStatesNV;
#define glCreateStatesNV cppgl_glCreateStatesNV
typedef void (APIENTRYP PFNGLDELETESTATESNVPROC)(GLsizei n, const GLuint *states);
GLAPI PFNGLDELETESTATESNVPROC cppgl_glDeleteStatesNV;
#define glDeleteStatesNV cppgl_glDeleteStatesNV
typedef GLboolean (APIENTRYP PFNGLISSTATENVPROC)(GLuint state);
GLAPI PFNGLISSTATENVPROC cppgl_glIsStateNV;
#define glIsStateNV cppgl_glIsStateNV
typedef void (APIENTRYP PFNGLSTATECAPTURENVPROC)(GLuint state, GLenum mode);
GLAPI PFNGLSTATECAPTURENVPROC cppgl_glStateCaptureNV;
#define glStateCaptureNV cppgl_glStateCaptureNV
typedef GLuint (APIENTRYP PFNGLGETCOMMANDHEADERNVPROC)(GLenum tokenID, GLuint size);
GLAPI PFNGLGETCOMMANDHEADERNVPROC cppgl_glGetCommandHeaderNV;
#define glGetCommandHeaderNV cppgl_glGetCommandHeaderNV
typedef GLushort (APIENTRYP PFNGLGETSTAGEINDEXNVPROC)(GLenum shadertype);
GLAPI PFNGLGETSTAGEINDEXNVPROC cppgl_glGetStageIndexNV;
#define glGetStageIndexNV cppgl_glGetStageIndexNV
typedef void (APIENTRYP PFNGLDRAWCOMMANDSNVPROC)(GLenum primitiveMode, GLuint buffer, const GLintptr *indirects, const GLsizei *sizes, GLuint count);
GLAPI PFNGLDRAWCOMMANDSNVPROC cppgl_glDrawCommandsNV;
#define glDrawCommandsNV cppgl_glDrawCommandsNV
typedef void (APIENTRYP PFNGLDRAWCOMMANDSADDRESSNVPROC)(GLenum primitiveMode, const GLuint64 *indirects, const GLsizei *sizes, GLuint count);
GLAPI PFNGLDRAWCOMMANDSADDRESSNVPROC cppgl_glDrawCommandsAddressNV;
#define glDrawCommandsAddressNV cppgl_glDrawCommandsAddressNV
typedef void (APIENTRYP PFNGLDRAWCOMMANDSSTATESNVPROC)(GLuint buffer, const GLintptr *indirects, const GLsizei *sizes, const GLuint *states, const GLuint *fbos, GLuint count);
GLAPI PFNGLDRAWCOMMANDSSTATESNVPROC cppgl_glDrawCommandsStatesNV;
#define glDrawCommandsStatesNV cppgl_glDrawCommandsStatesNV
typedef void (APIENTRYP PFNGLDRAWCOMMANDSSTATESADDRESSNVPROC)(const GLuint64 *indirects, const GLsizei *sizes, const GLuint *states, const GLuint *fbos, GLuint count);
GLAPI PFNGLDRAWCOMMANDSSTATESADDRESSNVPROC cppgl_glDrawCommandsStatesAddressNV;
#define glDrawCommandsStatesAddressNV cppgl_glDrawCommandsStatesAddressNV
typedef void (APIENTRYP PFNGLCREATECOMMANDLISTSNVPROC)(GLsizei n, GLuint *lists);
GLAPI PFNGLCREATECOMMANDLISTSNVPROC cppgl_glCreateCommandListsNV;
#define glCreateCommandListsNV cppgl_glCreateCommandListsNV
typedef void (APIENTRYP PFNGLDELETECOMMANDLISTSNVPROC)(GLsizei n, const GLuint *lists);
GLAPI PFNGLDELETECOMMANDLISTSNVPROC cppgl_glDeleteCommandListsNV;
#define glDeleteCommandListsNV cppgl_glDeleteCommandListsNV
typedef GLboolean (APIENTRYP PFNGLISCOMMANDLISTNVPROC)(GLuint list);
GLAPI PFNGLISCOMMANDLISTNVPROC cppgl_glIsCommandListNV;
#define glIsCommandListNV cppgl_glIsCommandListNV
typedef void (APIENTRYP PFNGLLISTDRAWCOMMANDSSTATESCLIENTNVPROC)(GLuint list, GLuint segment, const void **indirects, const GLsizei *sizes, const GLuint *states, const GLuint *fbos, GLuint count);
GLAPI PFNGLLISTDRAWCOMMANDSSTATESCLIENTNVPROC cppgl_glListDrawCommandsStatesClientNV;
#define glListDrawCommandsStatesClientNV cppgl_glListDrawCommandsStatesClientNV
typedef void (APIENTRYP PFNGLCOMMANDLISTSEGMENTSNVPROC)(GLuint list, GLuint segments);
GLAPI PFNGLCOMMANDLISTSEGMENTSNVPROC cppgl_glCommandListSegmentsNV;
#define glCommandListSegmentsNV cppgl_glCommandListSegmentsNV
typedef void (APIENTRYP PFNGLCOMPILECOMMANDLISTNVPROC)(GLuint list);
GLAPI PFNGLCOMPILECOMMANDLISTNVPROC cppgl_glCompileCommandListNV;
#define glCompileCommandListNV cppgl_glCompileCommandListNV
typedef void (APIENTRYP PFNGLCALLCOMMANDLISTNVPROC)(GLuint list);
GLAPI PFNGLCALLCOMMANDLISTNVPROC cppgl_glCallCommandListNV;
#define glCallCommandListNV cppgl_glCallCommandListNV
#endif
#ifndef GL_NV_compute_program5
#define GL_NV_compute_program5 1
GLAPI int CPPGL_GL_NV_compute_program5;
#endif
#ifndef GL_NV_conditional_render
#define GL_NV_conditional_render 1
GLAPI int CPPGL_GL_NV_conditional_render;
typedef void (APIENTRYP PFNGLBEGINCONDITIONALRENDERNVPROC)(GLuint id, GLenum mode);
GLAPI PFNGLBEGINCONDITIONALRENDERNVPROC cppgl_glBeginConditionalRenderNV;
#define glBeginConditionalRenderNV cppgl_glBeginConditionalRenderNV
typedef void (APIENTRYP PFNGLENDCONDITIONALRENDERNVPROC)();
GLAPI PFNGLENDCONDITIONALRENDERNVPROC cppgl_glEndConditionalRenderNV;
#define glEndConditionalRenderNV cppgl_glEndConditionalRenderNV
#endif
#ifndef GL_NV_conservative_raster
#define GL_NV_conservative_raster 1
GLAPI int CPPGL_GL_NV_conservative_raster;
typedef void (APIENTRYP PFNGLSUBPIXELPRECISIONBIASNVPROC)(GLuint xbits, GLuint ybits);
GLAPI PFNGLSUBPIXELPRECISIONBIASNVPROC cppgl_glSubpixelPrecisionBiasNV;
#define glSubpixelPrecisionBiasNV cppgl_glSubpixelPrecisionBiasNV
#endif
#ifndef GL_NV_conservative_raster_dilate
#define GL_NV_conservative_raster_dilate 1
GLAPI int CPPGL_GL_NV_conservative_raster_dilate;
typedef void (APIENTRYP PFNGLCONSERVATIVERASTERPARAMETERFNVPROC)(GLenum pname, GLfloat value);
GLAPI PFNGLCONSERVATIVERASTERPARAMETERFNVPROC cppgl_glConservativeRasterParameterfNV;
#define glConservativeRasterParameterfNV cppgl_glConservativeRasterParameterfNV
#endif
#ifndef GL_NV_conservative_raster_pre_snap_triangles
#define GL_NV_conservative_raster_pre_snap_triangles 1
GLAPI int CPPGL_GL_NV_conservative_raster_pre_snap_triangles;
typedef void (APIENTRYP PFNGLCONSERVATIVERASTERPARAMETERINVPROC)(GLenum pname, GLint param);
GLAPI PFNGLCONSERVATIVERASTERPARAMETERINVPROC cppgl_glConservativeRasterParameteriNV;
#define glConservativeRasterParameteriNV cppgl_glConservativeRasterParameteriNV
#endif
#ifndef GL_NV_copy_depth_to_color
#define GL_NV_copy_depth_to_color 1
GLAPI int CPPGL_GL_NV_copy_depth_to_color;
#endif
#ifndef GL_NV_copy_image
#define GL_NV_copy_image 1
GLAPI int CPPGL_GL_NV_copy_image;
typedef void (APIENTRYP PFNGLCOPYIMAGESUBDATANVPROC)(GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei width, GLsizei height, GLsizei depth);
GLAPI PFNGLCOPYIMAGESUBDATANVPROC cppgl_glCopyImageSubDataNV;
#define glCopyImageSubDataNV cppgl_glCopyImageSubDataNV
#endif
#ifndef GL_NV_deep_texture3D
#define GL_NV_deep_texture3D 1
GLAPI int CPPGL_GL_NV_deep_texture3D;
#endif
#ifndef GL_NV_depth_buffer_float
#define GL_NV_depth_buffer_float 1
GLAPI int CPPGL_GL_NV_depth_buffer_float;
typedef void (APIENTRYP PFNGLDEPTHRANGEDNVPROC)(GLdouble zNear, GLdouble zFar);
GLAPI PFNGLDEPTHRANGEDNVPROC cppgl_glDepthRangedNV;
#define glDepthRangedNV cppgl_glDepthRangedNV
typedef void (APIENTRYP PFNGLCLEARDEPTHDNVPROC)(GLdouble depth);
GLAPI PFNGLCLEARDEPTHDNVPROC cppgl_glClearDepthdNV;
#define glClearDepthdNV cppgl_glClearDepthdNV
typedef void (APIENTRYP PFNGLDEPTHBOUNDSDNVPROC)(GLdouble zmin, GLdouble zmax);
GLAPI PFNGLDEPTHBOUNDSDNVPROC cppgl_glDepthBoundsdNV;
#define glDepthBoundsdNV cppgl_glDepthBoundsdNV
#endif
#ifndef GL_NV_depth_clamp
#define GL_NV_depth_clamp 1
GLAPI int CPPGL_GL_NV_depth_clamp;
#endif
#ifndef GL_NV_draw_texture
#define GL_NV_draw_texture 1
GLAPI int CPPGL_GL_NV_draw_texture;
typedef void (APIENTRYP PFNGLDRAWTEXTURENVPROC)(GLuint texture, GLuint sampler, GLfloat x0, GLfloat y0, GLfloat x1, GLfloat y1, GLfloat z, GLfloat s0, GLfloat t0, GLfloat s1, GLfloat t1);
GLAPI PFNGLDRAWTEXTURENVPROC cppgl_glDrawTextureNV;
#define glDrawTextureNV cppgl_glDrawTextureNV
#endif
#ifndef GL_NV_evaluators
#define GL_NV_evaluators 1
GLAPI int CPPGL_GL_NV_evaluators;
typedef void (APIENTRYP PFNGLMAPCONTROLPOINTSNVPROC)(GLenum target, GLuint index, GLenum type, GLsizei ustride, GLsizei vstride, GLint uorder, GLint vorder, GLboolean packed, const void *points);
GLAPI PFNGLMAPCONTROLPOINTSNVPROC cppgl_glMapControlPointsNV;
#define glMapControlPointsNV cppgl_glMapControlPointsNV
typedef void (APIENTRYP PFNGLMAPPARAMETERIVNVPROC)(GLenum target, GLenum pname, const GLint *params);
GLAPI PFNGLMAPPARAMETERIVNVPROC cppgl_glMapParameterivNV;
#define glMapParameterivNV cppgl_glMapParameterivNV
typedef void (APIENTRYP PFNGLMAPPARAMETERFVNVPROC)(GLenum target, GLenum pname, const GLfloat *params);
GLAPI PFNGLMAPPARAMETERFVNVPROC cppgl_glMapParameterfvNV;
#define glMapParameterfvNV cppgl_glMapParameterfvNV
typedef void (APIENTRYP PFNGLGETMAPCONTROLPOINTSNVPROC)(GLenum target, GLuint index, GLenum type, GLsizei ustride, GLsizei vstride, GLboolean packed, void *points);
GLAPI PFNGLGETMAPCONTROLPOINTSNVPROC cppgl_glGetMapControlPointsNV;
#define glGetMapControlPointsNV cppgl_glGetMapControlPointsNV
typedef void (APIENTRYP PFNGLGETMAPPARAMETERIVNVPROC)(GLenum target, GLenum pname, GLint *params);
GLAPI PFNGLGETMAPPARAMETERIVNVPROC cppgl_glGetMapParameterivNV;
#define glGetMapParameterivNV cppgl_glGetMapParameterivNV
typedef void (APIENTRYP PFNGLGETMAPPARAMETERFVNVPROC)(GLenum target, GLenum pname, GLfloat *params);
GLAPI PFNGLGETMAPPARAMETERFVNVPROC cppgl_glGetMapParameterfvNV;
#define glGetMapParameterfvNV cppgl_glGetMapParameterfvNV
typedef void (APIENTRYP PFNGLGETMAPATTRIBPARAMETERIVNVPROC)(GLenum target, GLuint index, GLenum pname, GLint *params);
GLAPI PFNGLGETMAPATTRIBPARAMETERIVNVPROC cppgl_glGetMapAttribParameterivNV;
#define glGetMapAttribParameterivNV cppgl_glGetMapAttribParameterivNV
typedef void (APIENTRYP PFNGLGETMAPATTRIBPARAMETERFVNVPROC)(GLenum target, GLuint index, GLenum pname, GLfloat *params);
GLAPI PFNGLGETMAPATTRIBPARAMETERFVNVPROC cppgl_glGetMapAttribParameterfvNV;
#define glGetMapAttribParameterfvNV cppgl_glGetMapAttribParameterfvNV
typedef void (APIENTRYP PFNGLEVALMAPSNVPROC)(GLenum target, GLenum mode);
GLAPI PFNGLEVALMAPSNVPROC cppgl_glEvalMapsNV;
#define glEvalMapsNV cppgl_glEvalMapsNV
#endif
#ifndef GL_NV_explicit_multisample
#define GL_NV_explicit_multisample 1
GLAPI int CPPGL_GL_NV_explicit_multisample;
typedef void (APIENTRYP PFNGLGETMULTISAMPLEFVNVPROC)(GLenum pname, GLuint index, GLfloat *val);
GLAPI PFNGLGETMULTISAMPLEFVNVPROC cppgl_glGetMultisamplefvNV;
#define glGetMultisamplefvNV cppgl_glGetMultisamplefvNV
typedef void (APIENTRYP PFNGLSAMPLEMASKINDEXEDNVPROC)(GLuint index, GLbitfield mask);
GLAPI PFNGLSAMPLEMASKINDEXEDNVPROC cppgl_glSampleMaskIndexedNV;
#define glSampleMaskIndexedNV cppgl_glSampleMaskIndexedNV
typedef void (APIENTRYP PFNGLTEXRENDERBUFFERNVPROC)(GLenum target, GLuint renderbuffer);
GLAPI PFNGLTEXRENDERBUFFERNVPROC cppgl_glTexRenderbufferNV;
#define glTexRenderbufferNV cppgl_glTexRenderbufferNV
#endif
#ifndef GL_NV_fence
#define GL_NV_fence 1
GLAPI int CPPGL_GL_NV_fence;
typedef void (APIENTRYP PFNGLDELETEFENCESNVPROC)(GLsizei n, const GLuint *fences);
GLAPI PFNGLDELETEFENCESNVPROC cppgl_glDeleteFencesNV;
#define glDeleteFencesNV cppgl_glDeleteFencesNV
typedef void (APIENTRYP PFNGLGENFENCESNVPROC)(GLsizei n, GLuint *fences);
GLAPI PFNGLGENFENCESNVPROC cppgl_glGenFencesNV;
#define glGenFencesNV cppgl_glGenFencesNV
typedef GLboolean (APIENTRYP PFNGLISFENCENVPROC)(GLuint fence);
GLAPI PFNGLISFENCENVPROC cppgl_glIsFenceNV;
#define glIsFenceNV cppgl_glIsFenceNV
typedef GLboolean (APIENTRYP PFNGLTESTFENCENVPROC)(GLuint fence);
GLAPI PFNGLTESTFENCENVPROC cppgl_glTestFenceNV;
#define glTestFenceNV cppgl_glTestFenceNV
typedef void (APIENTRYP PFNGLGETFENCEIVNVPROC)(GLuint fence, GLenum pname, GLint *params);
GLAPI PFNGLGETFENCEIVNVPROC cppgl_glGetFenceivNV;
#define glGetFenceivNV cppgl_glGetFenceivNV
typedef void (APIENTRYP PFNGLFINISHFENCENVPROC)(GLuint fence);
GLAPI PFNGLFINISHFENCENVPROC cppgl_glFinishFenceNV;
#define glFinishFenceNV cppgl_glFinishFenceNV
typedef void (APIENTRYP PFNGLSETFENCENVPROC)(GLuint fence, GLenum condition);
GLAPI PFNGLSETFENCENVPROC cppgl_glSetFenceNV;
#define glSetFenceNV cppgl_glSetFenceNV
#endif
#ifndef GL_NV_fill_rectangle
#define GL_NV_fill_rectangle 1
GLAPI int CPPGL_GL_NV_fill_rectangle;
#endif
#ifndef GL_NV_float_buffer
#define GL_NV_float_buffer 1
GLAPI int CPPGL_GL_NV_float_buffer;
#endif
#ifndef GL_NV_fog_distance
#define GL_NV_fog_distance 1
GLAPI int CPPGL_GL_NV_fog_distance;
#endif
#ifndef GL_NV_fragment_coverage_to_color
#define GL_NV_fragment_coverage_to_color 1
GLAPI int CPPGL_GL_NV_fragment_coverage_to_color;
typedef void (APIENTRYP PFNGLFRAGMENTCOVERAGECOLORNVPROC)(GLuint color);
GLAPI PFNGLFRAGMENTCOVERAGECOLORNVPROC cppgl_glFragmentCoverageColorNV;
#define glFragmentCoverageColorNV cppgl_glFragmentCoverageColorNV
#endif
#ifndef GL_NV_fragment_program
#define GL_NV_fragment_program 1
GLAPI int CPPGL_GL_NV_fragment_program;
typedef void (APIENTRYP PFNGLPROGRAMNAMEDPARAMETER4FNVPROC)(GLuint id, GLsizei len, const GLubyte *name, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
GLAPI PFNGLPROGRAMNAMEDPARAMETER4FNVPROC cppgl_glProgramNamedParameter4fNV;
#define glProgramNamedParameter4fNV cppgl_glProgramNamedParameter4fNV
typedef void (APIENTRYP PFNGLPROGRAMNAMEDPARAMETER4FVNVPROC)(GLuint id, GLsizei len, const GLubyte *name, const GLfloat *v);
GLAPI PFNGLPROGRAMNAMEDPARAMETER4FVNVPROC cppgl_glProgramNamedParameter4fvNV;
#define glProgramNamedParameter4fvNV cppgl_glProgramNamedParameter4fvNV
typedef void (APIENTRYP PFNGLPROGRAMNAMEDPARAMETER4DNVPROC)(GLuint id, GLsizei len, const GLubyte *name, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
GLAPI PFNGLPROGRAMNAMEDPARAMETER4DNVPROC cppgl_glProgramNamedParameter4dNV;
#define glProgramNamedParameter4dNV cppgl_glProgramNamedParameter4dNV
typedef void (APIENTRYP PFNGLPROGRAMNAMEDPARAMETER4DVNVPROC)(GLuint id, GLsizei len, const GLubyte *name, const GLdouble *v);
GLAPI PFNGLPROGRAMNAMEDPARAMETER4DVNVPROC cppgl_glProgramNamedParameter4dvNV;
#define glProgramNamedParameter4dvNV cppgl_glProgramNamedParameter4dvNV
typedef void (APIENTRYP PFNGLGETPROGRAMNAMEDPARAMETERFVNVPROC)(GLuint id, GLsizei len, const GLubyte *name, GLfloat *params);
GLAPI PFNGLGETPROGRAMNAMEDPARAMETERFVNVPROC cppgl_glGetProgramNamedParameterfvNV;
#define glGetProgramNamedParameterfvNV cppgl_glGetProgramNamedParameterfvNV
typedef void (APIENTRYP PFNGLGETPROGRAMNAMEDPARAMETERDVNVPROC)(GLuint id, GLsizei len, const GLubyte *name, GLdouble *params);
GLAPI PFNGLGETPROGRAMNAMEDPARAMETERDVNVPROC cppgl_glGetProgramNamedParameterdvNV;
#define glGetProgramNamedParameterdvNV cppgl_glGetProgramNamedParameterdvNV
#endif
#ifndef GL_NV_fragment_program2
#define GL_NV_fragment_program2 1
GLAPI int CPPGL_GL_NV_fragment_program2;
#endif
#ifndef GL_NV_fragment_program4
#define GL_NV_fragment_program4 1
GLAPI int CPPGL_GL_NV_fragment_program4;
#endif
#ifndef GL_NV_fragment_program_option
#define GL_NV_fragment_program_option 1
GLAPI int CPPGL_GL_NV_fragment_program_option;
#endif
#ifndef GL_NV_fragment_shader_interlock
#define GL_NV_fragment_shader_interlock 1
GLAPI int CPPGL_GL_NV_fragment_shader_interlock;
#endif
#ifndef GL_NV_framebuffer_mixed_samples
#define GL_NV_framebuffer_mixed_samples 1
GLAPI int CPPGL_GL_NV_framebuffer_mixed_samples;
typedef void (APIENTRYP PFNGLCOVERAGEMODULATIONTABLENVPROC)(GLsizei n, const GLfloat *v);
GLAPI PFNGLCOVERAGEMODULATIONTABLENVPROC cppgl_glCoverageModulationTableNV;
#define glCoverageModulationTableNV cppgl_glCoverageModulationTableNV
typedef void (APIENTRYP PFNGLGETCOVERAGEMODULATIONTABLENVPROC)(GLsizei bufsize, GLfloat *v);
GLAPI PFNGLGETCOVERAGEMODULATIONTABLENVPROC cppgl_glGetCoverageModulationTableNV;
#define glGetCoverageModulationTableNV cppgl_glGetCoverageModulationTableNV
typedef void (APIENTRYP PFNGLCOVERAGEMODULATIONNVPROC)(GLenum components);
GLAPI PFNGLCOVERAGEMODULATIONNVPROC cppgl_glCoverageModulationNV;
#define glCoverageModulationNV cppgl_glCoverageModulationNV
#endif
#ifndef GL_NV_framebuffer_multisample_coverage
#define GL_NV_framebuffer_multisample_coverage 1
GLAPI int CPPGL_GL_NV_framebuffer_multisample_coverage;
typedef void (APIENTRYP PFNGLRENDERBUFFERSTORAGEMULTISAMPLECOVERAGENVPROC)(GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLenum internalformat, GLsizei width, GLsizei height);
GLAPI PFNGLRENDERBUFFERSTORAGEMULTISAMPLECOVERAGENVPROC cppgl_glRenderbufferStorageMultisampleCoverageNV;
#define glRenderbufferStorageMultisampleCoverageNV cppgl_glRenderbufferStorageMultisampleCoverageNV
#endif
#ifndef GL_NV_geometry_program4
#define GL_NV_geometry_program4 1
GLAPI int CPPGL_GL_NV_geometry_program4;
typedef void (APIENTRYP PFNGLPROGRAMVERTEXLIMITNVPROC)(GLenum target, GLint limit);
GLAPI PFNGLPROGRAMVERTEXLIMITNVPROC cppgl_glProgramVertexLimitNV;
#define glProgramVertexLimitNV cppgl_glProgramVertexLimitNV
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTUREEXTPROC)(GLenum target, GLenum attachment, GLuint texture, GLint level);
GLAPI PFNGLFRAMEBUFFERTEXTUREEXTPROC cppgl_glFramebufferTextureEXT;
#define glFramebufferTextureEXT cppgl_glFramebufferTextureEXT
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTUREFACEEXTPROC)(GLenum target, GLenum attachment, GLuint texture, GLint level, GLenum face);
GLAPI PFNGLFRAMEBUFFERTEXTUREFACEEXTPROC cppgl_glFramebufferTextureFaceEXT;
#define glFramebufferTextureFaceEXT cppgl_glFramebufferTextureFaceEXT
#endif
#ifndef GL_NV_geometry_shader4
#define GL_NV_geometry_shader4 1
GLAPI int CPPGL_GL_NV_geometry_shader4;
#endif
#ifndef GL_NV_geometry_shader_passthrough
#define GL_NV_geometry_shader_passthrough 1
GLAPI int CPPGL_GL_NV_geometry_shader_passthrough;
#endif
#ifndef GL_NV_gpu_program4
#define GL_NV_gpu_program4 1
GLAPI int CPPGL_GL_NV_gpu_program4;
typedef void (APIENTRYP PFNGLPROGRAMLOCALPARAMETERI4INVPROC)(GLenum target, GLuint index, GLint x, GLint y, GLint z, GLint w);
GLAPI PFNGLPROGRAMLOCALPARAMETERI4INVPROC cppgl_glProgramLocalParameterI4iNV;
#define glProgramLocalParameterI4iNV cppgl_glProgramLocalParameterI4iNV
typedef void (APIENTRYP PFNGLPROGRAMLOCALPARAMETERI4IVNVPROC)(GLenum target, GLuint index, const GLint *params);
GLAPI PFNGLPROGRAMLOCALPARAMETERI4IVNVPROC cppgl_glProgramLocalParameterI4ivNV;
#define glProgramLocalParameterI4ivNV cppgl_glProgramLocalParameterI4ivNV
typedef void (APIENTRYP PFNGLPROGRAMLOCALPARAMETERSI4IVNVPROC)(GLenum target, GLuint index, GLsizei count, const GLint *params);
GLAPI PFNGLPROGRAMLOCALPARAMETERSI4IVNVPROC cppgl_glProgramLocalParametersI4ivNV;
#define glProgramLocalParametersI4ivNV cppgl_glProgramLocalParametersI4ivNV
typedef void (APIENTRYP PFNGLPROGRAMLOCALPARAMETERI4UINVPROC)(GLenum target, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
GLAPI PFNGLPROGRAMLOCALPARAMETERI4UINVPROC cppgl_glProgramLocalParameterI4uiNV;
#define glProgramLocalParameterI4uiNV cppgl_glProgramLocalParameterI4uiNV
typedef void (APIENTRYP PFNGLPROGRAMLOCALPARAMETERI4UIVNVPROC)(GLenum target, GLuint index, const GLuint *params);
GLAPI PFNGLPROGRAMLOCALPARAMETERI4UIVNVPROC cppgl_glProgramLocalParameterI4uivNV;
#define glProgramLocalParameterI4uivNV cppgl_glProgramLocalParameterI4uivNV
typedef void (APIENTRYP PFNGLPROGRAMLOCALPARAMETERSI4UIVNVPROC)(GLenum target, GLuint index, GLsizei count, const GLuint *params);
GLAPI PFNGLPROGRAMLOCALPARAMETERSI4UIVNVPROC cppgl_glProgramLocalParametersI4uivNV;
#define glProgramLocalParametersI4uivNV cppgl_glProgramLocalParametersI4uivNV
typedef void (APIENTRYP PFNGLPROGRAMENVPARAMETERI4INVPROC)(GLenum target, GLuint index, GLint x, GLint y, GLint z, GLint w);
GLAPI PFNGLPROGRAMENVPARAMETERI4INVPROC cppgl_glProgramEnvParameterI4iNV;
#define glProgramEnvParameterI4iNV cppgl_glProgramEnvParameterI4iNV
typedef void (APIENTRYP PFNGLPROGRAMENVPARAMETERI4IVNVPROC)(GLenum target, GLuint index, const GLint *params);
GLAPI PFNGLPROGRAMENVPARAMETERI4IVNVPROC cppgl_glProgramEnvParameterI4ivNV;
#define glProgramEnvParameterI4ivNV cppgl_glProgramEnvParameterI4ivNV
typedef void (APIENTRYP PFNGLPROGRAMENVPARAMETERSI4IVNVPROC)(GLenum target, GLuint index, GLsizei count, const GLint *params);
GLAPI PFNGLPROGRAMENVPARAMETERSI4IVNVPROC cppgl_glProgramEnvParametersI4ivNV;
#define glProgramEnvParametersI4ivNV cppgl_glProgramEnvParametersI4ivNV
typedef void (APIENTRYP PFNGLPROGRAMENVPARAMETERI4UINVPROC)(GLenum target, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
GLAPI PFNGLPROGRAMENVPARAMETERI4UINVPROC cppgl_glProgramEnvParameterI4uiNV;
#define glProgramEnvParameterI4uiNV cppgl_glProgramEnvParameterI4uiNV
typedef void (APIENTRYP PFNGLPROGRAMENVPARAMETERI4UIVNVPROC)(GLenum target, GLuint index, const GLuint *params);
GLAPI PFNGLPROGRAMENVPARAMETERI4UIVNVPROC cppgl_glProgramEnvParameterI4uivNV;
#define glProgramEnvParameterI4uivNV cppgl_glProgramEnvParameterI4uivNV
typedef void (APIENTRYP PFNGLPROGRAMENVPARAMETERSI4UIVNVPROC)(GLenum target, GLuint index, GLsizei count, const GLuint *params);
GLAPI PFNGLPROGRAMENVPARAMETERSI4UIVNVPROC cppgl_glProgramEnvParametersI4uivNV;
#define glProgramEnvParametersI4uivNV cppgl_glProgramEnvParametersI4uivNV
typedef void (APIENTRYP PFNGLGETPROGRAMLOCALPARAMETERIIVNVPROC)(GLenum target, GLuint index, GLint *params);
GLAPI PFNGLGETPROGRAMLOCALPARAMETERIIVNVPROC cppgl_glGetProgramLocalParameterIivNV;
#define glGetProgramLocalParameterIivNV cppgl_glGetProgramLocalParameterIivNV
typedef void (APIENTRYP PFNGLGETPROGRAMLOCALPARAMETERIUIVNVPROC)(GLenum target, GLuint index, GLuint *params);
GLAPI PFNGLGETPROGRAMLOCALPARAMETERIUIVNVPROC cppgl_glGetProgramLocalParameterIuivNV;
#define glGetProgramLocalParameterIuivNV cppgl_glGetProgramLocalParameterIuivNV
typedef void (APIENTRYP PFNGLGETPROGRAMENVPARAMETERIIVNVPROC)(GLenum target, GLuint index, GLint *params);
GLAPI PFNGLGETPROGRAMENVPARAMETERIIVNVPROC cppgl_glGetProgramEnvParameterIivNV;
#define glGetProgramEnvParameterIivNV cppgl_glGetProgramEnvParameterIivNV
typedef void (APIENTRYP PFNGLGETPROGRAMENVPARAMETERIUIVNVPROC)(GLenum target, GLuint index, GLuint *params);
GLAPI PFNGLGETPROGRAMENVPARAMETERIUIVNVPROC cppgl_glGetProgramEnvParameterIuivNV;
#define glGetProgramEnvParameterIuivNV cppgl_glGetProgramEnvParameterIuivNV
#endif
#ifndef GL_NV_gpu_program5
#define GL_NV_gpu_program5 1
GLAPI int CPPGL_GL_NV_gpu_program5;
typedef void (APIENTRYP PFNGLPROGRAMSUBROUTINEPARAMETERSUIVNVPROC)(GLenum target, GLsizei count, const GLuint *params);
GLAPI PFNGLPROGRAMSUBROUTINEPARAMETERSUIVNVPROC cppgl_glProgramSubroutineParametersuivNV;
#define glProgramSubroutineParametersuivNV cppgl_glProgramSubroutineParametersuivNV
typedef void (APIENTRYP PFNGLGETPROGRAMSUBROUTINEPARAMETERUIVNVPROC)(GLenum target, GLuint index, GLuint *param);
GLAPI PFNGLGETPROGRAMSUBROUTINEPARAMETERUIVNVPROC cppgl_glGetProgramSubroutineParameteruivNV;
#define glGetProgramSubroutineParameteruivNV cppgl_glGetProgramSubroutineParameteruivNV
#endif
#ifndef GL_NV_gpu_program5_mem_extended
#define GL_NV_gpu_program5_mem_extended 1
GLAPI int CPPGL_GL_NV_gpu_program5_mem_extended;
#endif
#ifndef GL_NV_gpu_shader5
#define GL_NV_gpu_shader5 1
GLAPI int CPPGL_GL_NV_gpu_shader5;
#endif
#ifndef GL_NV_half_float
#define GL_NV_half_float 1
GLAPI int CPPGL_GL_NV_half_float;
typedef void (APIENTRYP PFNGLVERTEX2HNVPROC)(GLhalfNV x, GLhalfNV y);
GLAPI PFNGLVERTEX2HNVPROC cppgl_glVertex2hNV;
#define glVertex2hNV cppgl_glVertex2hNV
typedef void (APIENTRYP PFNGLVERTEX2HVNVPROC)(const GLhalfNV *v);
GLAPI PFNGLVERTEX2HVNVPROC cppgl_glVertex2hvNV;
#define glVertex2hvNV cppgl_glVertex2hvNV
typedef void (APIENTRYP PFNGLVERTEX3HNVPROC)(GLhalfNV x, GLhalfNV y, GLhalfNV z);
GLAPI PFNGLVERTEX3HNVPROC cppgl_glVertex3hNV;
#define glVertex3hNV cppgl_glVertex3hNV
typedef void (APIENTRYP PFNGLVERTEX3HVNVPROC)(const GLhalfNV *v);
GLAPI PFNGLVERTEX3HVNVPROC cppgl_glVertex3hvNV;
#define glVertex3hvNV cppgl_glVertex3hvNV
typedef void (APIENTRYP PFNGLVERTEX4HNVPROC)(GLhalfNV x, GLhalfNV y, GLhalfNV z, GLhalfNV w);
GLAPI PFNGLVERTEX4HNVPROC cppgl_glVertex4hNV;
#define glVertex4hNV cppgl_glVertex4hNV
typedef void (APIENTRYP PFNGLVERTEX4HVNVPROC)(const GLhalfNV *v);
GLAPI PFNGLVERTEX4HVNVPROC cppgl_glVertex4hvNV;
#define glVertex4hvNV cppgl_glVertex4hvNV
typedef void (APIENTRYP PFNGLNORMAL3HNVPROC)(GLhalfNV nx, GLhalfNV ny, GLhalfNV nz);
GLAPI PFNGLNORMAL3HNVPROC cppgl_glNormal3hNV;
#define glNormal3hNV cppgl_glNormal3hNV
typedef void (APIENTRYP PFNGLNORMAL3HVNVPROC)(const GLhalfNV *v);
GLAPI PFNGLNORMAL3HVNVPROC cppgl_glNormal3hvNV;
#define glNormal3hvNV cppgl_glNormal3hvNV
typedef void (APIENTRYP PFNGLCOLOR3HNVPROC)(GLhalfNV red, GLhalfNV green, GLhalfNV blue);
GLAPI PFNGLCOLOR3HNVPROC cppgl_glColor3hNV;
#define glColor3hNV cppgl_glColor3hNV
typedef void (APIENTRYP PFNGLCOLOR3HVNVPROC)(const GLhalfNV *v);
GLAPI PFNGLCOLOR3HVNVPROC cppgl_glColor3hvNV;
#define glColor3hvNV cppgl_glColor3hvNV
typedef void (APIENTRYP PFNGLCOLOR4HNVPROC)(GLhalfNV red, GLhalfNV green, GLhalfNV blue, GLhalfNV alpha);
GLAPI PFNGLCOLOR4HNVPROC cppgl_glColor4hNV;
#define glColor4hNV cppgl_glColor4hNV
typedef void (APIENTRYP PFNGLCOLOR4HVNVPROC)(const GLhalfNV *v);
GLAPI PFNGLCOLOR4HVNVPROC cppgl_glColor4hvNV;
#define glColor4hvNV cppgl_glColor4hvNV
typedef void (APIENTRYP PFNGLTEXCOORD1HNVPROC)(GLhalfNV s);
GLAPI PFNGLTEXCOORD1HNVPROC cppgl_glTexCoord1hNV;
#define glTexCoord1hNV cppgl_glTexCoord1hNV
typedef void (APIENTRYP PFNGLTEXCOORD1HVNVPROC)(const GLhalfNV *v);
GLAPI PFNGLTEXCOORD1HVNVPROC cppgl_glTexCoord1hvNV;
#define glTexCoord1hvNV cppgl_glTexCoord1hvNV
typedef void (APIENTRYP PFNGLTEXCOORD2HNVPROC)(GLhalfNV s, GLhalfNV t);
GLAPI PFNGLTEXCOORD2HNVPROC cppgl_glTexCoord2hNV;
#define glTexCoord2hNV cppgl_glTexCoord2hNV
typedef void (APIENTRYP PFNGLTEXCOORD2HVNVPROC)(const GLhalfNV *v);
GLAPI PFNGLTEXCOORD2HVNVPROC cppgl_glTexCoord2hvNV;
#define glTexCoord2hvNV cppgl_glTexCoord2hvNV
typedef void (APIENTRYP PFNGLTEXCOORD3HNVPROC)(GLhalfNV s, GLhalfNV t, GLhalfNV r);
GLAPI PFNGLTEXCOORD3HNVPROC cppgl_glTexCoord3hNV;
#define glTexCoord3hNV cppgl_glTexCoord3hNV
typedef void (APIENTRYP PFNGLTEXCOORD3HVNVPROC)(const GLhalfNV *v);
GLAPI PFNGLTEXCOORD3HVNVPROC cppgl_glTexCoord3hvNV;
#define glTexCoord3hvNV cppgl_glTexCoord3hvNV
typedef void (APIENTRYP PFNGLTEXCOORD4HNVPROC)(GLhalfNV s, GLhalfNV t, GLhalfNV r, GLhalfNV q);
GLAPI PFNGLTEXCOORD4HNVPROC cppgl_glTexCoord4hNV;
#define glTexCoord4hNV cppgl_glTexCoord4hNV
typedef void (APIENTRYP PFNGLTEXCOORD4HVNVPROC)(const GLhalfNV *v);
GLAPI PFNGLTEXCOORD4HVNVPROC cppgl_glTexCoord4hvNV;
#define glTexCoord4hvNV cppgl_glTexCoord4hvNV
typedef void (APIENTRYP PFNGLMULTITEXCOORD1HNVPROC)(GLenum target, GLhalfNV s);
GLAPI PFNGLMULTITEXCOORD1HNVPROC cppgl_glMultiTexCoord1hNV;
#define glMultiTexCoord1hNV cppgl_glMultiTexCoord1hNV
typedef void (APIENTRYP PFNGLMULTITEXCOORD1HVNVPROC)(GLenum target, const GLhalfNV *v);
GLAPI PFNGLMULTITEXCOORD1HVNVPROC cppgl_glMultiTexCoord1hvNV;
#define glMultiTexCoord1hvNV cppgl_glMultiTexCoord1hvNV
typedef void (APIENTRYP PFNGLMULTITEXCOORD2HNVPROC)(GLenum target, GLhalfNV s, GLhalfNV t);
GLAPI PFNGLMULTITEXCOORD2HNVPROC cppgl_glMultiTexCoord2hNV;
#define glMultiTexCoord2hNV cppgl_glMultiTexCoord2hNV
typedef void (APIENTRYP PFNGLMULTITEXCOORD2HVNVPROC)(GLenum target, const GLhalfNV *v);
GLAPI PFNGLMULTITEXCOORD2HVNVPROC cppgl_glMultiTexCoord2hvNV;
#define glMultiTexCoord2hvNV cppgl_glMultiTexCoord2hvNV
typedef void (APIENTRYP PFNGLMULTITEXCOORD3HNVPROC)(GLenum target, GLhalfNV s, GLhalfNV t, GLhalfNV r);
GLAPI PFNGLMULTITEXCOORD3HNVPROC cppgl_glMultiTexCoord3hNV;
#define glMultiTexCoord3hNV cppgl_glMultiTexCoord3hNV
typedef void (APIENTRYP PFNGLMULTITEXCOORD3HVNVPROC)(GLenum target, const GLhalfNV *v);
GLAPI PFNGLMULTITEXCOORD3HVNVPROC cppgl_glMultiTexCoord3hvNV;
#define glMultiTexCoord3hvNV cppgl_glMultiTexCoord3hvNV
typedef void (APIENTRYP PFNGLMULTITEXCOORD4HNVPROC)(GLenum target, GLhalfNV s, GLhalfNV t, GLhalfNV r, GLhalfNV q);
GLAPI PFNGLMULTITEXCOORD4HNVPROC cppgl_glMultiTexCoord4hNV;
#define glMultiTexCoord4hNV cppgl_glMultiTexCoord4hNV
typedef void (APIENTRYP PFNGLMULTITEXCOORD4HVNVPROC)(GLenum target, const GLhalfNV *v);
GLAPI PFNGLMULTITEXCOORD4HVNVPROC cppgl_glMultiTexCoord4hvNV;
#define glMultiTexCoord4hvNV cppgl_glMultiTexCoord4hvNV
typedef void (APIENTRYP PFNGLFOGCOORDHNVPROC)(GLhalfNV fog);
GLAPI PFNGLFOGCOORDHNVPROC cppgl_glFogCoordhNV;
#define glFogCoordhNV cppgl_glFogCoordhNV
typedef void (APIENTRYP PFNGLFOGCOORDHVNVPROC)(const GLhalfNV *fog);
GLAPI PFNGLFOGCOORDHVNVPROC cppgl_glFogCoordhvNV;
#define glFogCoordhvNV cppgl_glFogCoordhvNV
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3HNVPROC)(GLhalfNV red, GLhalfNV green, GLhalfNV blue);
GLAPI PFNGLSECONDARYCOLOR3HNVPROC cppgl_glSecondaryColor3hNV;
#define glSecondaryColor3hNV cppgl_glSecondaryColor3hNV
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3HVNVPROC)(const GLhalfNV *v);
GLAPI PFNGLSECONDARYCOLOR3HVNVPROC cppgl_glSecondaryColor3hvNV;
#define glSecondaryColor3hvNV cppgl_glSecondaryColor3hvNV
typedef void (APIENTRYP PFNGLVERTEXWEIGHTHNVPROC)(GLhalfNV weight);
GLAPI PFNGLVERTEXWEIGHTHNVPROC cppgl_glVertexWeighthNV;
#define glVertexWeighthNV cppgl_glVertexWeighthNV
typedef void (APIENTRYP PFNGLVERTEXWEIGHTHVNVPROC)(const GLhalfNV *weight);
GLAPI PFNGLVERTEXWEIGHTHVNVPROC cppgl_glVertexWeighthvNV;
#define glVertexWeighthvNV cppgl_glVertexWeighthvNV
typedef void (APIENTRYP PFNGLVERTEXATTRIB1HNVPROC)(GLuint index, GLhalfNV x);
GLAPI PFNGLVERTEXATTRIB1HNVPROC cppgl_glVertexAttrib1hNV;
#define glVertexAttrib1hNV cppgl_glVertexAttrib1hNV
typedef void (APIENTRYP PFNGLVERTEXATTRIB1HVNVPROC)(GLuint index, const GLhalfNV *v);
GLAPI PFNGLVERTEXATTRIB1HVNVPROC cppgl_glVertexAttrib1hvNV;
#define glVertexAttrib1hvNV cppgl_glVertexAttrib1hvNV
typedef void (APIENTRYP PFNGLVERTEXATTRIB2HNVPROC)(GLuint index, GLhalfNV x, GLhalfNV y);
GLAPI PFNGLVERTEXATTRIB2HNVPROC cppgl_glVertexAttrib2hNV;
#define glVertexAttrib2hNV cppgl_glVertexAttrib2hNV
typedef void (APIENTRYP PFNGLVERTEXATTRIB2HVNVPROC)(GLuint index, const GLhalfNV *v);
GLAPI PFNGLVERTEXATTRIB2HVNVPROC cppgl_glVertexAttrib2hvNV;
#define glVertexAttrib2hvNV cppgl_glVertexAttrib2hvNV
typedef void (APIENTRYP PFNGLVERTEXATTRIB3HNVPROC)(GLuint index, GLhalfNV x, GLhalfNV y, GLhalfNV z);
GLAPI PFNGLVERTEXATTRIB3HNVPROC cppgl_glVertexAttrib3hNV;
#define glVertexAttrib3hNV cppgl_glVertexAttrib3hNV
typedef void (APIENTRYP PFNGLVERTEXATTRIB3HVNVPROC)(GLuint index, const GLhalfNV *v);
GLAPI PFNGLVERTEXATTRIB3HVNVPROC cppgl_glVertexAttrib3hvNV;
#define glVertexAttrib3hvNV cppgl_glVertexAttrib3hvNV
typedef void (APIENTRYP PFNGLVERTEXATTRIB4HNVPROC)(GLuint index, GLhalfNV x, GLhalfNV y, GLhalfNV z, GLhalfNV w);
GLAPI PFNGLVERTEXATTRIB4HNVPROC cppgl_glVertexAttrib4hNV;
#define glVertexAttrib4hNV cppgl_glVertexAttrib4hNV
typedef void (APIENTRYP PFNGLVERTEXATTRIB4HVNVPROC)(GLuint index, const GLhalfNV *v);
GLAPI PFNGLVERTEXATTRIB4HVNVPROC cppgl_glVertexAttrib4hvNV;
#define glVertexAttrib4hvNV cppgl_glVertexAttrib4hvNV
typedef void (APIENTRYP PFNGLVERTEXATTRIBS1HVNVPROC)(GLuint index, GLsizei n, const GLhalfNV *v);
GLAPI PFNGLVERTEXATTRIBS1HVNVPROC cppgl_glVertexAttribs1hvNV;
#define glVertexAttribs1hvNV cppgl_glVertexAttribs1hvNV
typedef void (APIENTRYP PFNGLVERTEXATTRIBS2HVNVPROC)(GLuint index, GLsizei n, const GLhalfNV *v);
GLAPI PFNGLVERTEXATTRIBS2HVNVPROC cppgl_glVertexAttribs2hvNV;
#define glVertexAttribs2hvNV cppgl_glVertexAttribs2hvNV
typedef void (APIENTRYP PFNGLVERTEXATTRIBS3HVNVPROC)(GLuint index, GLsizei n, const GLhalfNV *v);
GLAPI PFNGLVERTEXATTRIBS3HVNVPROC cppgl_glVertexAttribs3hvNV;
#define glVertexAttribs3hvNV cppgl_glVertexAttribs3hvNV
typedef void (APIENTRYP PFNGLVERTEXATTRIBS4HVNVPROC)(GLuint index, GLsizei n, const GLhalfNV *v);
GLAPI PFNGLVERTEXATTRIBS4HVNVPROC cppgl_glVertexAttribs4hvNV;
#define glVertexAttribs4hvNV cppgl_glVertexAttribs4hvNV
#endif
#ifndef GL_NV_internalformat_sample_query
#define GL_NV_internalformat_sample_query 1
GLAPI int CPPGL_GL_NV_internalformat_sample_query;
typedef void (APIENTRYP PFNGLGETINTERNALFORMATSAMPLEIVNVPROC)(GLenum target, GLenum internalformat, GLsizei samples, GLenum pname, GLsizei bufSize, GLint *params);
GLAPI PFNGLGETINTERNALFORMATSAMPLEIVNVPROC cppgl_glGetInternalformatSampleivNV;
#define glGetInternalformatSampleivNV cppgl_glGetInternalformatSampleivNV
#endif
#ifndef GL_NV_light_max_exponent
#define GL_NV_light_max_exponent 1
GLAPI int CPPGL_GL_NV_light_max_exponent;
#endif
#ifndef GL_NV_multisample_coverage
#define GL_NV_multisample_coverage 1
GLAPI int CPPGL_GL_NV_multisample_coverage;
#endif
#ifndef GL_NV_multisample_filter_hint
#define GL_NV_multisample_filter_hint 1
GLAPI int CPPGL_GL_NV_multisample_filter_hint;
#endif
#ifndef GL_NV_occlusion_query
#define GL_NV_occlusion_query 1
GLAPI int CPPGL_GL_NV_occlusion_query;
typedef void (APIENTRYP PFNGLGENOCCLUSIONQUERIESNVPROC)(GLsizei n, GLuint *ids);
GLAPI PFNGLGENOCCLUSIONQUERIESNVPROC cppgl_glGenOcclusionQueriesNV;
#define glGenOcclusionQueriesNV cppgl_glGenOcclusionQueriesNV
typedef void (APIENTRYP PFNGLDELETEOCCLUSIONQUERIESNVPROC)(GLsizei n, const GLuint *ids);
GLAPI PFNGLDELETEOCCLUSIONQUERIESNVPROC cppgl_glDeleteOcclusionQueriesNV;
#define glDeleteOcclusionQueriesNV cppgl_glDeleteOcclusionQueriesNV
typedef GLboolean (APIENTRYP PFNGLISOCCLUSIONQUERYNVPROC)(GLuint id);
GLAPI PFNGLISOCCLUSIONQUERYNVPROC cppgl_glIsOcclusionQueryNV;
#define glIsOcclusionQueryNV cppgl_glIsOcclusionQueryNV
typedef void (APIENTRYP PFNGLBEGINOCCLUSIONQUERYNVPROC)(GLuint id);
GLAPI PFNGLBEGINOCCLUSIONQUERYNVPROC cppgl_glBeginOcclusionQueryNV;
#define glBeginOcclusionQueryNV cppgl_glBeginOcclusionQueryNV
typedef void (APIENTRYP PFNGLENDOCCLUSIONQUERYNVPROC)();
GLAPI PFNGLENDOCCLUSIONQUERYNVPROC cppgl_glEndOcclusionQueryNV;
#define glEndOcclusionQueryNV cppgl_glEndOcclusionQueryNV
typedef void (APIENTRYP PFNGLGETOCCLUSIONQUERYIVNVPROC)(GLuint id, GLenum pname, GLint *params);
GLAPI PFNGLGETOCCLUSIONQUERYIVNVPROC cppgl_glGetOcclusionQueryivNV;
#define glGetOcclusionQueryivNV cppgl_glGetOcclusionQueryivNV
typedef void (APIENTRYP PFNGLGETOCCLUSIONQUERYUIVNVPROC)(GLuint id, GLenum pname, GLuint *params);
GLAPI PFNGLGETOCCLUSIONQUERYUIVNVPROC cppgl_glGetOcclusionQueryuivNV;
#define glGetOcclusionQueryuivNV cppgl_glGetOcclusionQueryuivNV
#endif
#ifndef GL_NV_packed_depth_stencil
#define GL_NV_packed_depth_stencil 1
GLAPI int CPPGL_GL_NV_packed_depth_stencil;
#endif
#ifndef GL_NV_parameter_buffer_object
#define GL_NV_parameter_buffer_object 1
GLAPI int CPPGL_GL_NV_parameter_buffer_object;
typedef void (APIENTRYP PFNGLPROGRAMBUFFERPARAMETERSFVNVPROC)(GLenum target, GLuint bindingIndex, GLuint wordIndex, GLsizei count, const GLfloat *params);
GLAPI PFNGLPROGRAMBUFFERPARAMETERSFVNVPROC cppgl_glProgramBufferParametersfvNV;
#define glProgramBufferParametersfvNV cppgl_glProgramBufferParametersfvNV
typedef void (APIENTRYP PFNGLPROGRAMBUFFERPARAMETERSIIVNVPROC)(GLenum target, GLuint bindingIndex, GLuint wordIndex, GLsizei count, const GLint *params);
GLAPI PFNGLPROGRAMBUFFERPARAMETERSIIVNVPROC cppgl_glProgramBufferParametersIivNV;
#define glProgramBufferParametersIivNV cppgl_glProgramBufferParametersIivNV
typedef void (APIENTRYP PFNGLPROGRAMBUFFERPARAMETERSIUIVNVPROC)(GLenum target, GLuint bindingIndex, GLuint wordIndex, GLsizei count, const GLuint *params);
GLAPI PFNGLPROGRAMBUFFERPARAMETERSIUIVNVPROC cppgl_glProgramBufferParametersIuivNV;
#define glProgramBufferParametersIuivNV cppgl_glProgramBufferParametersIuivNV
#endif
#ifndef GL_NV_parameter_buffer_object2
#define GL_NV_parameter_buffer_object2 1
GLAPI int CPPGL_GL_NV_parameter_buffer_object2;
#endif
#ifndef GL_NV_path_rendering
#define GL_NV_path_rendering 1
GLAPI int CPPGL_GL_NV_path_rendering;
typedef GLuint (APIENTRYP PFNGLGENPATHSNVPROC)(GLsizei range);
GLAPI PFNGLGENPATHSNVPROC cppgl_glGenPathsNV;
#define glGenPathsNV cppgl_glGenPathsNV
typedef void (APIENTRYP PFNGLDELETEPATHSNVPROC)(GLuint path, GLsizei range);
GLAPI PFNGLDELETEPATHSNVPROC cppgl_glDeletePathsNV;
#define glDeletePathsNV cppgl_glDeletePathsNV
typedef GLboolean (APIENTRYP PFNGLISPATHNVPROC)(GLuint path);
GLAPI PFNGLISPATHNVPROC cppgl_glIsPathNV;
#define glIsPathNV cppgl_glIsPathNV
typedef void (APIENTRYP PFNGLPATHCOMMANDSNVPROC)(GLuint path, GLsizei numCommands, const GLubyte *commands, GLsizei numCoords, GLenum coordType, const void *coords);
GLAPI PFNGLPATHCOMMANDSNVPROC cppgl_glPathCommandsNV;
#define glPathCommandsNV cppgl_glPathCommandsNV
typedef void (APIENTRYP PFNGLPATHCOORDSNVPROC)(GLuint path, GLsizei numCoords, GLenum coordType, const void *coords);
GLAPI PFNGLPATHCOORDSNVPROC cppgl_glPathCoordsNV;
#define glPathCoordsNV cppgl_glPathCoordsNV
typedef void (APIENTRYP PFNGLPATHSUBCOMMANDSNVPROC)(GLuint path, GLsizei commandStart, GLsizei commandsToDelete, GLsizei numCommands, const GLubyte *commands, GLsizei numCoords, GLenum coordType, const void *coords);
GLAPI PFNGLPATHSUBCOMMANDSNVPROC cppgl_glPathSubCommandsNV;
#define glPathSubCommandsNV cppgl_glPathSubCommandsNV
typedef void (APIENTRYP PFNGLPATHSUBCOORDSNVPROC)(GLuint path, GLsizei coordStart, GLsizei numCoords, GLenum coordType, const void *coords);
GLAPI PFNGLPATHSUBCOORDSNVPROC cppgl_glPathSubCoordsNV;
#define glPathSubCoordsNV cppgl_glPathSubCoordsNV
typedef void (APIENTRYP PFNGLPATHSTRINGNVPROC)(GLuint path, GLenum format, GLsizei length, const void *pathString);
GLAPI PFNGLPATHSTRINGNVPROC cppgl_glPathStringNV;
#define glPathStringNV cppgl_glPathStringNV
typedef void (APIENTRYP PFNGLPATHGLYPHSNVPROC)(GLuint firstPathName, GLenum fontTarget, const void *fontName, GLbitfield fontStyle, GLsizei numGlyphs, GLenum type, const void *charcodes, GLenum handleMissingGlyphs, GLuint pathParameterTemplate, GLfloat emScale);
GLAPI PFNGLPATHGLYPHSNVPROC cppgl_glPathGlyphsNV;
#define glPathGlyphsNV cppgl_glPathGlyphsNV
typedef void (APIENTRYP PFNGLPATHGLYPHRANGENVPROC)(GLuint firstPathName, GLenum fontTarget, const void *fontName, GLbitfield fontStyle, GLuint firstGlyph, GLsizei numGlyphs, GLenum handleMissingGlyphs, GLuint pathParameterTemplate, GLfloat emScale);
GLAPI PFNGLPATHGLYPHRANGENVPROC cppgl_glPathGlyphRangeNV;
#define glPathGlyphRangeNV cppgl_glPathGlyphRangeNV
typedef void (APIENTRYP PFNGLWEIGHTPATHSNVPROC)(GLuint resultPath, GLsizei numPaths, const GLuint *paths, const GLfloat *weights);
GLAPI PFNGLWEIGHTPATHSNVPROC cppgl_glWeightPathsNV;
#define glWeightPathsNV cppgl_glWeightPathsNV
typedef void (APIENTRYP PFNGLCOPYPATHNVPROC)(GLuint resultPath, GLuint srcPath);
GLAPI PFNGLCOPYPATHNVPROC cppgl_glCopyPathNV;
#define glCopyPathNV cppgl_glCopyPathNV
typedef void (APIENTRYP PFNGLINTERPOLATEPATHSNVPROC)(GLuint resultPath, GLuint pathA, GLuint pathB, GLfloat weight);
GLAPI PFNGLINTERPOLATEPATHSNVPROC cppgl_glInterpolatePathsNV;
#define glInterpolatePathsNV cppgl_glInterpolatePathsNV
typedef void (APIENTRYP PFNGLTRANSFORMPATHNVPROC)(GLuint resultPath, GLuint srcPath, GLenum transformType, const GLfloat *transformValues);
GLAPI PFNGLTRANSFORMPATHNVPROC cppgl_glTransformPathNV;
#define glTransformPathNV cppgl_glTransformPathNV
typedef void (APIENTRYP PFNGLPATHPARAMETERIVNVPROC)(GLuint path, GLenum pname, const GLint *value);
GLAPI PFNGLPATHPARAMETERIVNVPROC cppgl_glPathParameterivNV;
#define glPathParameterivNV cppgl_glPathParameterivNV
typedef void (APIENTRYP PFNGLPATHPARAMETERINVPROC)(GLuint path, GLenum pname, GLint value);
GLAPI PFNGLPATHPARAMETERINVPROC cppgl_glPathParameteriNV;
#define glPathParameteriNV cppgl_glPathParameteriNV
typedef void (APIENTRYP PFNGLPATHPARAMETERFVNVPROC)(GLuint path, GLenum pname, const GLfloat *value);
GLAPI PFNGLPATHPARAMETERFVNVPROC cppgl_glPathParameterfvNV;
#define glPathParameterfvNV cppgl_glPathParameterfvNV
typedef void (APIENTRYP PFNGLPATHPARAMETERFNVPROC)(GLuint path, GLenum pname, GLfloat value);
GLAPI PFNGLPATHPARAMETERFNVPROC cppgl_glPathParameterfNV;
#define glPathParameterfNV cppgl_glPathParameterfNV
typedef void (APIENTRYP PFNGLPATHDASHARRAYNVPROC)(GLuint path, GLsizei dashCount, const GLfloat *dashArray);
GLAPI PFNGLPATHDASHARRAYNVPROC cppgl_glPathDashArrayNV;
#define glPathDashArrayNV cppgl_glPathDashArrayNV
typedef void (APIENTRYP PFNGLPATHSTENCILFUNCNVPROC)(GLenum func, GLint ref, GLuint mask);
GLAPI PFNGLPATHSTENCILFUNCNVPROC cppgl_glPathStencilFuncNV;
#define glPathStencilFuncNV cppgl_glPathStencilFuncNV
typedef void (APIENTRYP PFNGLPATHSTENCILDEPTHOFFSETNVPROC)(GLfloat factor, GLfloat units);
GLAPI PFNGLPATHSTENCILDEPTHOFFSETNVPROC cppgl_glPathStencilDepthOffsetNV;
#define glPathStencilDepthOffsetNV cppgl_glPathStencilDepthOffsetNV
typedef void (APIENTRYP PFNGLSTENCILFILLPATHNVPROC)(GLuint path, GLenum fillMode, GLuint mask);
GLAPI PFNGLSTENCILFILLPATHNVPROC cppgl_glStencilFillPathNV;
#define glStencilFillPathNV cppgl_glStencilFillPathNV
typedef void (APIENTRYP PFNGLSTENCILSTROKEPATHNVPROC)(GLuint path, GLint reference, GLuint mask);
GLAPI PFNGLSTENCILSTROKEPATHNVPROC cppgl_glStencilStrokePathNV;
#define glStencilStrokePathNV cppgl_glStencilStrokePathNV
typedef void (APIENTRYP PFNGLSTENCILFILLPATHINSTANCEDNVPROC)(GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLenum fillMode, GLuint mask, GLenum transformType, const GLfloat *transformValues);
GLAPI PFNGLSTENCILFILLPATHINSTANCEDNVPROC cppgl_glStencilFillPathInstancedNV;
#define glStencilFillPathInstancedNV cppgl_glStencilFillPathInstancedNV
typedef void (APIENTRYP PFNGLSTENCILSTROKEPATHINSTANCEDNVPROC)(GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLint reference, GLuint mask, GLenum transformType, const GLfloat *transformValues);
GLAPI PFNGLSTENCILSTROKEPATHINSTANCEDNVPROC cppgl_glStencilStrokePathInstancedNV;
#define glStencilStrokePathInstancedNV cppgl_glStencilStrokePathInstancedNV
typedef void (APIENTRYP PFNGLPATHCOVERDEPTHFUNCNVPROC)(GLenum func);
GLAPI PFNGLPATHCOVERDEPTHFUNCNVPROC cppgl_glPathCoverDepthFuncNV;
#define glPathCoverDepthFuncNV cppgl_glPathCoverDepthFuncNV
typedef void (APIENTRYP PFNGLCOVERFILLPATHNVPROC)(GLuint path, GLenum coverMode);
GLAPI PFNGLCOVERFILLPATHNVPROC cppgl_glCoverFillPathNV;
#define glCoverFillPathNV cppgl_glCoverFillPathNV
typedef void (APIENTRYP PFNGLCOVERSTROKEPATHNVPROC)(GLuint path, GLenum coverMode);
GLAPI PFNGLCOVERSTROKEPATHNVPROC cppgl_glCoverStrokePathNV;
#define glCoverStrokePathNV cppgl_glCoverStrokePathNV
typedef void (APIENTRYP PFNGLCOVERFILLPATHINSTANCEDNVPROC)(GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLenum coverMode, GLenum transformType, const GLfloat *transformValues);
GLAPI PFNGLCOVERFILLPATHINSTANCEDNVPROC cppgl_glCoverFillPathInstancedNV;
#define glCoverFillPathInstancedNV cppgl_glCoverFillPathInstancedNV
typedef void (APIENTRYP PFNGLCOVERSTROKEPATHINSTANCEDNVPROC)(GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLenum coverMode, GLenum transformType, const GLfloat *transformValues);
GLAPI PFNGLCOVERSTROKEPATHINSTANCEDNVPROC cppgl_glCoverStrokePathInstancedNV;
#define glCoverStrokePathInstancedNV cppgl_glCoverStrokePathInstancedNV
typedef void (APIENTRYP PFNGLGETPATHPARAMETERIVNVPROC)(GLuint path, GLenum pname, GLint *value);
GLAPI PFNGLGETPATHPARAMETERIVNVPROC cppgl_glGetPathParameterivNV;
#define glGetPathParameterivNV cppgl_glGetPathParameterivNV
typedef void (APIENTRYP PFNGLGETPATHPARAMETERFVNVPROC)(GLuint path, GLenum pname, GLfloat *value);
GLAPI PFNGLGETPATHPARAMETERFVNVPROC cppgl_glGetPathParameterfvNV;
#define glGetPathParameterfvNV cppgl_glGetPathParameterfvNV
typedef void (APIENTRYP PFNGLGETPATHCOMMANDSNVPROC)(GLuint path, GLubyte *commands);
GLAPI PFNGLGETPATHCOMMANDSNVPROC cppgl_glGetPathCommandsNV;
#define glGetPathCommandsNV cppgl_glGetPathCommandsNV
typedef void (APIENTRYP PFNGLGETPATHCOORDSNVPROC)(GLuint path, GLfloat *coords);
GLAPI PFNGLGETPATHCOORDSNVPROC cppgl_glGetPathCoordsNV;
#define glGetPathCoordsNV cppgl_glGetPathCoordsNV
typedef void (APIENTRYP PFNGLGETPATHDASHARRAYNVPROC)(GLuint path, GLfloat *dashArray);
GLAPI PFNGLGETPATHDASHARRAYNVPROC cppgl_glGetPathDashArrayNV;
#define glGetPathDashArrayNV cppgl_glGetPathDashArrayNV
typedef void (APIENTRYP PFNGLGETPATHMETRICSNVPROC)(GLbitfield metricQueryMask, GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLsizei stride, GLfloat *metrics);
GLAPI PFNGLGETPATHMETRICSNVPROC cppgl_glGetPathMetricsNV;
#define glGetPathMetricsNV cppgl_glGetPathMetricsNV
typedef void (APIENTRYP PFNGLGETPATHMETRICRANGENVPROC)(GLbitfield metricQueryMask, GLuint firstPathName, GLsizei numPaths, GLsizei stride, GLfloat *metrics);
GLAPI PFNGLGETPATHMETRICRANGENVPROC cppgl_glGetPathMetricRangeNV;
#define glGetPathMetricRangeNV cppgl_glGetPathMetricRangeNV
typedef void (APIENTRYP PFNGLGETPATHSPACINGNVPROC)(GLenum pathListMode, GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLfloat advanceScale, GLfloat kerningScale, GLenum transformType, GLfloat *returnedSpacing);
GLAPI PFNGLGETPATHSPACINGNVPROC cppgl_glGetPathSpacingNV;
#define glGetPathSpacingNV cppgl_glGetPathSpacingNV
typedef GLboolean (APIENTRYP PFNGLISPOINTINFILLPATHNVPROC)(GLuint path, GLuint mask, GLfloat x, GLfloat y);
GLAPI PFNGLISPOINTINFILLPATHNVPROC cppgl_glIsPointInFillPathNV;
#define glIsPointInFillPathNV cppgl_glIsPointInFillPathNV
typedef GLboolean (APIENTRYP PFNGLISPOINTINSTROKEPATHNVPROC)(GLuint path, GLfloat x, GLfloat y);
GLAPI PFNGLISPOINTINSTROKEPATHNVPROC cppgl_glIsPointInStrokePathNV;
#define glIsPointInStrokePathNV cppgl_glIsPointInStrokePathNV
typedef GLfloat (APIENTRYP PFNGLGETPATHLENGTHNVPROC)(GLuint path, GLsizei startSegment, GLsizei numSegments);
GLAPI PFNGLGETPATHLENGTHNVPROC cppgl_glGetPathLengthNV;
#define glGetPathLengthNV cppgl_glGetPathLengthNV
typedef GLboolean (APIENTRYP PFNGLPOINTALONGPATHNVPROC)(GLuint path, GLsizei startSegment, GLsizei numSegments, GLfloat distance, GLfloat *x, GLfloat *y, GLfloat *tangentX, GLfloat *tangentY);
GLAPI PFNGLPOINTALONGPATHNVPROC cppgl_glPointAlongPathNV;
#define glPointAlongPathNV cppgl_glPointAlongPathNV
typedef void (APIENTRYP PFNGLMATRIXLOAD3X2FNVPROC)(GLenum matrixMode, const GLfloat *m);
GLAPI PFNGLMATRIXLOAD3X2FNVPROC cppgl_glMatrixLoad3x2fNV;
#define glMatrixLoad3x2fNV cppgl_glMatrixLoad3x2fNV
typedef void (APIENTRYP PFNGLMATRIXLOAD3X3FNVPROC)(GLenum matrixMode, const GLfloat *m);
GLAPI PFNGLMATRIXLOAD3X3FNVPROC cppgl_glMatrixLoad3x3fNV;
#define glMatrixLoad3x3fNV cppgl_glMatrixLoad3x3fNV
typedef void (APIENTRYP PFNGLMATRIXLOADTRANSPOSE3X3FNVPROC)(GLenum matrixMode, const GLfloat *m);
GLAPI PFNGLMATRIXLOADTRANSPOSE3X3FNVPROC cppgl_glMatrixLoadTranspose3x3fNV;
#define glMatrixLoadTranspose3x3fNV cppgl_glMatrixLoadTranspose3x3fNV
typedef void (APIENTRYP PFNGLMATRIXMULT3X2FNVPROC)(GLenum matrixMode, const GLfloat *m);
GLAPI PFNGLMATRIXMULT3X2FNVPROC cppgl_glMatrixMult3x2fNV;
#define glMatrixMult3x2fNV cppgl_glMatrixMult3x2fNV
typedef void (APIENTRYP PFNGLMATRIXMULT3X3FNVPROC)(GLenum matrixMode, const GLfloat *m);
GLAPI PFNGLMATRIXMULT3X3FNVPROC cppgl_glMatrixMult3x3fNV;
#define glMatrixMult3x3fNV cppgl_glMatrixMult3x3fNV
typedef void (APIENTRYP PFNGLMATRIXMULTTRANSPOSE3X3FNVPROC)(GLenum matrixMode, const GLfloat *m);
GLAPI PFNGLMATRIXMULTTRANSPOSE3X3FNVPROC cppgl_glMatrixMultTranspose3x3fNV;
#define glMatrixMultTranspose3x3fNV cppgl_glMatrixMultTranspose3x3fNV
typedef void (APIENTRYP PFNGLSTENCILTHENCOVERFILLPATHNVPROC)(GLuint path, GLenum fillMode, GLuint mask, GLenum coverMode);
GLAPI PFNGLSTENCILTHENCOVERFILLPATHNVPROC cppgl_glStencilThenCoverFillPathNV;
#define glStencilThenCoverFillPathNV cppgl_glStencilThenCoverFillPathNV
typedef void (APIENTRYP PFNGLSTENCILTHENCOVERSTROKEPATHNVPROC)(GLuint path, GLint reference, GLuint mask, GLenum coverMode);
GLAPI PFNGLSTENCILTHENCOVERSTROKEPATHNVPROC cppgl_glStencilThenCoverStrokePathNV;
#define glStencilThenCoverStrokePathNV cppgl_glStencilThenCoverStrokePathNV
typedef void (APIENTRYP PFNGLSTENCILTHENCOVERFILLPATHINSTANCEDNVPROC)(GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLenum fillMode, GLuint mask, GLenum coverMode, GLenum transformType, const GLfloat *transformValues);
GLAPI PFNGLSTENCILTHENCOVERFILLPATHINSTANCEDNVPROC cppgl_glStencilThenCoverFillPathInstancedNV;
#define glStencilThenCoverFillPathInstancedNV cppgl_glStencilThenCoverFillPathInstancedNV
typedef void (APIENTRYP PFNGLSTENCILTHENCOVERSTROKEPATHINSTANCEDNVPROC)(GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLint reference, GLuint mask, GLenum coverMode, GLenum transformType, const GLfloat *transformValues);
GLAPI PFNGLSTENCILTHENCOVERSTROKEPATHINSTANCEDNVPROC cppgl_glStencilThenCoverStrokePathInstancedNV;
#define glStencilThenCoverStrokePathInstancedNV cppgl_glStencilThenCoverStrokePathInstancedNV
typedef GLenum (APIENTRYP PFNGLPATHGLYPHINDEXRANGENVPROC)(GLenum fontTarget, const void *fontName, GLbitfield fontStyle, GLuint pathParameterTemplate, GLfloat emScale, GLuint baseAndCount[2]);
GLAPI PFNGLPATHGLYPHINDEXRANGENVPROC cppgl_glPathGlyphIndexRangeNV;
#define glPathGlyphIndexRangeNV cppgl_glPathGlyphIndexRangeNV
typedef GLenum (APIENTRYP PFNGLPATHGLYPHINDEXARRAYNVPROC)(GLuint firstPathName, GLenum fontTarget, const void *fontName, GLbitfield fontStyle, GLuint firstGlyphIndex, GLsizei numGlyphs, GLuint pathParameterTemplate, GLfloat emScale);
GLAPI PFNGLPATHGLYPHINDEXARRAYNVPROC cppgl_glPathGlyphIndexArrayNV;
#define glPathGlyphIndexArrayNV cppgl_glPathGlyphIndexArrayNV
typedef GLenum (APIENTRYP PFNGLPATHMEMORYGLYPHINDEXARRAYNVPROC)(GLuint firstPathName, GLenum fontTarget, GLsizeiptr fontSize, const void *fontData, GLsizei faceIndex, GLuint firstGlyphIndex, GLsizei numGlyphs, GLuint pathParameterTemplate, GLfloat emScale);
GLAPI PFNGLPATHMEMORYGLYPHINDEXARRAYNVPROC cppgl_glPathMemoryGlyphIndexArrayNV;
#define glPathMemoryGlyphIndexArrayNV cppgl_glPathMemoryGlyphIndexArrayNV
typedef void (APIENTRYP PFNGLPROGRAMPATHFRAGMENTINPUTGENNVPROC)(GLuint program, GLint location, GLenum genMode, GLint components, const GLfloat *coeffs);
GLAPI PFNGLPROGRAMPATHFRAGMENTINPUTGENNVPROC cppgl_glProgramPathFragmentInputGenNV;
#define glProgramPathFragmentInputGenNV cppgl_glProgramPathFragmentInputGenNV
typedef void (APIENTRYP PFNGLGETPROGRAMRESOURCEFVNVPROC)(GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum *props, GLsizei bufSize, GLsizei *length, GLfloat *params);
GLAPI PFNGLGETPROGRAMRESOURCEFVNVPROC cppgl_glGetProgramResourcefvNV;
#define glGetProgramResourcefvNV cppgl_glGetProgramResourcefvNV
typedef void (APIENTRYP PFNGLPATHCOLORGENNVPROC)(GLenum color, GLenum genMode, GLenum colorFormat, const GLfloat *coeffs);
GLAPI PFNGLPATHCOLORGENNVPROC cppgl_glPathColorGenNV;
#define glPathColorGenNV cppgl_glPathColorGenNV
typedef void (APIENTRYP PFNGLPATHTEXGENNVPROC)(GLenum texCoordSet, GLenum genMode, GLint components, const GLfloat *coeffs);
GLAPI PFNGLPATHTEXGENNVPROC cppgl_glPathTexGenNV;
#define glPathTexGenNV cppgl_glPathTexGenNV
typedef void (APIENTRYP PFNGLPATHFOGGENNVPROC)(GLenum genMode);
GLAPI PFNGLPATHFOGGENNVPROC cppgl_glPathFogGenNV;
#define glPathFogGenNV cppgl_glPathFogGenNV
typedef void (APIENTRYP PFNGLGETPATHCOLORGENIVNVPROC)(GLenum color, GLenum pname, GLint *value);
GLAPI PFNGLGETPATHCOLORGENIVNVPROC cppgl_glGetPathColorGenivNV;
#define glGetPathColorGenivNV cppgl_glGetPathColorGenivNV
typedef void (APIENTRYP PFNGLGETPATHCOLORGENFVNVPROC)(GLenum color, GLenum pname, GLfloat *value);
GLAPI PFNGLGETPATHCOLORGENFVNVPROC cppgl_glGetPathColorGenfvNV;
#define glGetPathColorGenfvNV cppgl_glGetPathColorGenfvNV
typedef void (APIENTRYP PFNGLGETPATHTEXGENIVNVPROC)(GLenum texCoordSet, GLenum pname, GLint *value);
GLAPI PFNGLGETPATHTEXGENIVNVPROC cppgl_glGetPathTexGenivNV;
#define glGetPathTexGenivNV cppgl_glGetPathTexGenivNV
typedef void (APIENTRYP PFNGLGETPATHTEXGENFVNVPROC)(GLenum texCoordSet, GLenum pname, GLfloat *value);
GLAPI PFNGLGETPATHTEXGENFVNVPROC cppgl_glGetPathTexGenfvNV;
#define glGetPathTexGenfvNV cppgl_glGetPathTexGenfvNV
#endif
#ifndef GL_NV_path_rendering_shared_edge
#define GL_NV_path_rendering_shared_edge 1
GLAPI int CPPGL_GL_NV_path_rendering_shared_edge;
#endif
#ifndef GL_NV_pixel_data_range
#define GL_NV_pixel_data_range 1
GLAPI int CPPGL_GL_NV_pixel_data_range;
typedef void (APIENTRYP PFNGLPIXELDATARANGENVPROC)(GLenum target, GLsizei length, const void *pointer);
GLAPI PFNGLPIXELDATARANGENVPROC cppgl_glPixelDataRangeNV;
#define glPixelDataRangeNV cppgl_glPixelDataRangeNV
typedef void (APIENTRYP PFNGLFLUSHPIXELDATARANGENVPROC)(GLenum target);
GLAPI PFNGLFLUSHPIXELDATARANGENVPROC cppgl_glFlushPixelDataRangeNV;
#define glFlushPixelDataRangeNV cppgl_glFlushPixelDataRangeNV
#endif
#ifndef GL_NV_point_sprite
#define GL_NV_point_sprite 1
GLAPI int CPPGL_GL_NV_point_sprite;
typedef void (APIENTRYP PFNGLPOINTPARAMETERINVPROC)(GLenum pname, GLint param);
GLAPI PFNGLPOINTPARAMETERINVPROC cppgl_glPointParameteriNV;
#define glPointParameteriNV cppgl_glPointParameteriNV
typedef void (APIENTRYP PFNGLPOINTPARAMETERIVNVPROC)(GLenum pname, const GLint *params);
GLAPI PFNGLPOINTPARAMETERIVNVPROC cppgl_glPointParameterivNV;
#define glPointParameterivNV cppgl_glPointParameterivNV
#endif
#ifndef GL_NV_present_video
#define GL_NV_present_video 1
GLAPI int CPPGL_GL_NV_present_video;
typedef void (APIENTRYP PFNGLPRESENTFRAMEKEYEDNVPROC)(GLuint video_slot, GLuint64EXT minPresentTime, GLuint beginPresentTimeId, GLuint presentDurationId, GLenum type, GLenum target0, GLuint fill0, GLuint key0, GLenum target1, GLuint fill1, GLuint key1);
GLAPI PFNGLPRESENTFRAMEKEYEDNVPROC cppgl_glPresentFrameKeyedNV;
#define glPresentFrameKeyedNV cppgl_glPresentFrameKeyedNV
typedef void (APIENTRYP PFNGLPRESENTFRAMEDUALFILLNVPROC)(GLuint video_slot, GLuint64EXT minPresentTime, GLuint beginPresentTimeId, GLuint presentDurationId, GLenum type, GLenum target0, GLuint fill0, GLenum target1, GLuint fill1, GLenum target2, GLuint fill2, GLenum target3, GLuint fill3);
GLAPI PFNGLPRESENTFRAMEDUALFILLNVPROC cppgl_glPresentFrameDualFillNV;
#define glPresentFrameDualFillNV cppgl_glPresentFrameDualFillNV
typedef void (APIENTRYP PFNGLGETVIDEOIVNVPROC)(GLuint video_slot, GLenum pname, GLint *params);
GLAPI PFNGLGETVIDEOIVNVPROC cppgl_glGetVideoivNV;
#define glGetVideoivNV cppgl_glGetVideoivNV
typedef void (APIENTRYP PFNGLGETVIDEOUIVNVPROC)(GLuint video_slot, GLenum pname, GLuint *params);
GLAPI PFNGLGETVIDEOUIVNVPROC cppgl_glGetVideouivNV;
#define glGetVideouivNV cppgl_glGetVideouivNV
typedef void (APIENTRYP PFNGLGETVIDEOI64VNVPROC)(GLuint video_slot, GLenum pname, GLint64EXT *params);
GLAPI PFNGLGETVIDEOI64VNVPROC cppgl_glGetVideoi64vNV;
#define glGetVideoi64vNV cppgl_glGetVideoi64vNV
typedef void (APIENTRYP PFNGLGETVIDEOUI64VNVPROC)(GLuint video_slot, GLenum pname, GLuint64EXT *params);
GLAPI PFNGLGETVIDEOUI64VNVPROC cppgl_glGetVideoui64vNV;
#define glGetVideoui64vNV cppgl_glGetVideoui64vNV
#endif
#ifndef GL_NV_primitive_restart
#define GL_NV_primitive_restart 1
GLAPI int CPPGL_GL_NV_primitive_restart;
typedef void (APIENTRYP PFNGLPRIMITIVERESTARTNVPROC)();
GLAPI PFNGLPRIMITIVERESTARTNVPROC cppgl_glPrimitiveRestartNV;
#define glPrimitiveRestartNV cppgl_glPrimitiveRestartNV
typedef void (APIENTRYP PFNGLPRIMITIVERESTARTINDEXNVPROC)(GLuint index);
GLAPI PFNGLPRIMITIVERESTARTINDEXNVPROC cppgl_glPrimitiveRestartIndexNV;
#define glPrimitiveRestartIndexNV cppgl_glPrimitiveRestartIndexNV
#endif
#ifndef GL_NV_register_combiners
#define GL_NV_register_combiners 1
GLAPI int CPPGL_GL_NV_register_combiners;
typedef void (APIENTRYP PFNGLCOMBINERPARAMETERFVNVPROC)(GLenum pname, const GLfloat *params);
GLAPI PFNGLCOMBINERPARAMETERFVNVPROC cppgl_glCombinerParameterfvNV;
#define glCombinerParameterfvNV cppgl_glCombinerParameterfvNV
typedef void (APIENTRYP PFNGLCOMBINERPARAMETERFNVPROC)(GLenum pname, GLfloat param);
GLAPI PFNGLCOMBINERPARAMETERFNVPROC cppgl_glCombinerParameterfNV;
#define glCombinerParameterfNV cppgl_glCombinerParameterfNV
typedef void (APIENTRYP PFNGLCOMBINERPARAMETERIVNVPROC)(GLenum pname, const GLint *params);
GLAPI PFNGLCOMBINERPARAMETERIVNVPROC cppgl_glCombinerParameterivNV;
#define glCombinerParameterivNV cppgl_glCombinerParameterivNV
typedef void (APIENTRYP PFNGLCOMBINERPARAMETERINVPROC)(GLenum pname, GLint param);
GLAPI PFNGLCOMBINERPARAMETERINVPROC cppgl_glCombinerParameteriNV;
#define glCombinerParameteriNV cppgl_glCombinerParameteriNV
typedef void (APIENTRYP PFNGLCOMBINERINPUTNVPROC)(GLenum stage, GLenum portion, GLenum variable, GLenum input, GLenum mapping, GLenum componentUsage);
GLAPI PFNGLCOMBINERINPUTNVPROC cppgl_glCombinerInputNV;
#define glCombinerInputNV cppgl_glCombinerInputNV
typedef void (APIENTRYP PFNGLCOMBINEROUTPUTNVPROC)(GLenum stage, GLenum portion, GLenum abOutput, GLenum cdOutput, GLenum sumOutput, GLenum scale, GLenum bias, GLboolean abDotProduct, GLboolean cdDotProduct, GLboolean muxSum);
GLAPI PFNGLCOMBINEROUTPUTNVPROC cppgl_glCombinerOutputNV;
#define glCombinerOutputNV cppgl_glCombinerOutputNV
typedef void (APIENTRYP PFNGLFINALCOMBINERINPUTNVPROC)(GLenum variable, GLenum input, GLenum mapping, GLenum componentUsage);
GLAPI PFNGLFINALCOMBINERINPUTNVPROC cppgl_glFinalCombinerInputNV;
#define glFinalCombinerInputNV cppgl_glFinalCombinerInputNV
typedef void (APIENTRYP PFNGLGETCOMBINERINPUTPARAMETERFVNVPROC)(GLenum stage, GLenum portion, GLenum variable, GLenum pname, GLfloat *params);
GLAPI PFNGLGETCOMBINERINPUTPARAMETERFVNVPROC cppgl_glGetCombinerInputParameterfvNV;
#define glGetCombinerInputParameterfvNV cppgl_glGetCombinerInputParameterfvNV
typedef void (APIENTRYP PFNGLGETCOMBINERINPUTPARAMETERIVNVPROC)(GLenum stage, GLenum portion, GLenum variable, GLenum pname, GLint *params);
GLAPI PFNGLGETCOMBINERINPUTPARAMETERIVNVPROC cppgl_glGetCombinerInputParameterivNV;
#define glGetCombinerInputParameterivNV cppgl_glGetCombinerInputParameterivNV
typedef void (APIENTRYP PFNGLGETCOMBINEROUTPUTPARAMETERFVNVPROC)(GLenum stage, GLenum portion, GLenum pname, GLfloat *params);
GLAPI PFNGLGETCOMBINEROUTPUTPARAMETERFVNVPROC cppgl_glGetCombinerOutputParameterfvNV;
#define glGetCombinerOutputParameterfvNV cppgl_glGetCombinerOutputParameterfvNV
typedef void (APIENTRYP PFNGLGETCOMBINEROUTPUTPARAMETERIVNVPROC)(GLenum stage, GLenum portion, GLenum pname, GLint *params);
GLAPI PFNGLGETCOMBINEROUTPUTPARAMETERIVNVPROC cppgl_glGetCombinerOutputParameterivNV;
#define glGetCombinerOutputParameterivNV cppgl_glGetCombinerOutputParameterivNV
typedef void (APIENTRYP PFNGLGETFINALCOMBINERINPUTPARAMETERFVNVPROC)(GLenum variable, GLenum pname, GLfloat *params);
GLAPI PFNGLGETFINALCOMBINERINPUTPARAMETERFVNVPROC cppgl_glGetFinalCombinerInputParameterfvNV;
#define glGetFinalCombinerInputParameterfvNV cppgl_glGetFinalCombinerInputParameterfvNV
typedef void (APIENTRYP PFNGLGETFINALCOMBINERINPUTPARAMETERIVNVPROC)(GLenum variable, GLenum pname, GLint *params);
GLAPI PFNGLGETFINALCOMBINERINPUTPARAMETERIVNVPROC cppgl_glGetFinalCombinerInputParameterivNV;
#define glGetFinalCombinerInputParameterivNV cppgl_glGetFinalCombinerInputParameterivNV
#endif
#ifndef GL_NV_register_combiners2
#define GL_NV_register_combiners2 1
GLAPI int CPPGL_GL_NV_register_combiners2;
typedef void (APIENTRYP PFNGLCOMBINERSTAGEPARAMETERFVNVPROC)(GLenum stage, GLenum pname, const GLfloat *params);
GLAPI PFNGLCOMBINERSTAGEPARAMETERFVNVPROC cppgl_glCombinerStageParameterfvNV;
#define glCombinerStageParameterfvNV cppgl_glCombinerStageParameterfvNV
typedef void (APIENTRYP PFNGLGETCOMBINERSTAGEPARAMETERFVNVPROC)(GLenum stage, GLenum pname, GLfloat *params);
GLAPI PFNGLGETCOMBINERSTAGEPARAMETERFVNVPROC cppgl_glGetCombinerStageParameterfvNV;
#define glGetCombinerStageParameterfvNV cppgl_glGetCombinerStageParameterfvNV
#endif
#ifndef GL_NV_robustness_video_memory_purge
#define GL_NV_robustness_video_memory_purge 1
GLAPI int CPPGL_GL_NV_robustness_video_memory_purge;
#endif
#ifndef GL_NV_sample_locations
#define GL_NV_sample_locations 1
GLAPI int CPPGL_GL_NV_sample_locations;
typedef void (APIENTRYP PFNGLFRAMEBUFFERSAMPLELOCATIONSFVNVPROC)(GLenum target, GLuint start, GLsizei count, const GLfloat *v);
GLAPI PFNGLFRAMEBUFFERSAMPLELOCATIONSFVNVPROC cppgl_glFramebufferSampleLocationsfvNV;
#define glFramebufferSampleLocationsfvNV cppgl_glFramebufferSampleLocationsfvNV
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERSAMPLELOCATIONSFVNVPROC)(GLuint framebuffer, GLuint start, GLsizei count, const GLfloat *v);
GLAPI PFNGLNAMEDFRAMEBUFFERSAMPLELOCATIONSFVNVPROC cppgl_glNamedFramebufferSampleLocationsfvNV;
#define glNamedFramebufferSampleLocationsfvNV cppgl_glNamedFramebufferSampleLocationsfvNV
typedef void (APIENTRYP PFNGLRESOLVEDEPTHVALUESNVPROC)();
GLAPI PFNGLRESOLVEDEPTHVALUESNVPROC cppgl_glResolveDepthValuesNV;
#define glResolveDepthValuesNV cppgl_glResolveDepthValuesNV
#endif
#ifndef GL_NV_sample_mask_override_coverage
#define GL_NV_sample_mask_override_coverage 1
GLAPI int CPPGL_GL_NV_sample_mask_override_coverage;
#endif
#ifndef GL_NV_shader_atomic_counters
#define GL_NV_shader_atomic_counters 1
GLAPI int CPPGL_GL_NV_shader_atomic_counters;
#endif
#ifndef GL_NV_shader_atomic_float
#define GL_NV_shader_atomic_float 1
GLAPI int CPPGL_GL_NV_shader_atomic_float;
#endif
#ifndef GL_NV_shader_atomic_float64
#define GL_NV_shader_atomic_float64 1
GLAPI int CPPGL_GL_NV_shader_atomic_float64;
#endif
#ifndef GL_NV_shader_atomic_fp16_vector
#define GL_NV_shader_atomic_fp16_vector 1
GLAPI int CPPGL_GL_NV_shader_atomic_fp16_vector;
#endif
#ifndef GL_NV_shader_atomic_int64
#define GL_NV_shader_atomic_int64 1
GLAPI int CPPGL_GL_NV_shader_atomic_int64;
#endif
#ifndef GL_NV_shader_buffer_load
#define GL_NV_shader_buffer_load 1
GLAPI int CPPGL_GL_NV_shader_buffer_load;
typedef void (APIENTRYP PFNGLMAKEBUFFERRESIDENTNVPROC)(GLenum target, GLenum access);
GLAPI PFNGLMAKEBUFFERRESIDENTNVPROC cppgl_glMakeBufferResidentNV;
#define glMakeBufferResidentNV cppgl_glMakeBufferResidentNV
typedef void (APIENTRYP PFNGLMAKEBUFFERNONRESIDENTNVPROC)(GLenum target);
GLAPI PFNGLMAKEBUFFERNONRESIDENTNVPROC cppgl_glMakeBufferNonResidentNV;
#define glMakeBufferNonResidentNV cppgl_glMakeBufferNonResidentNV
typedef GLboolean (APIENTRYP PFNGLISBUFFERRESIDENTNVPROC)(GLenum target);
GLAPI PFNGLISBUFFERRESIDENTNVPROC cppgl_glIsBufferResidentNV;
#define glIsBufferResidentNV cppgl_glIsBufferResidentNV
typedef void (APIENTRYP PFNGLMAKENAMEDBUFFERRESIDENTNVPROC)(GLuint buffer, GLenum access);
GLAPI PFNGLMAKENAMEDBUFFERRESIDENTNVPROC cppgl_glMakeNamedBufferResidentNV;
#define glMakeNamedBufferResidentNV cppgl_glMakeNamedBufferResidentNV
typedef void (APIENTRYP PFNGLMAKENAMEDBUFFERNONRESIDENTNVPROC)(GLuint buffer);
GLAPI PFNGLMAKENAMEDBUFFERNONRESIDENTNVPROC cppgl_glMakeNamedBufferNonResidentNV;
#define glMakeNamedBufferNonResidentNV cppgl_glMakeNamedBufferNonResidentNV
typedef GLboolean (APIENTRYP PFNGLISNAMEDBUFFERRESIDENTNVPROC)(GLuint buffer);
GLAPI PFNGLISNAMEDBUFFERRESIDENTNVPROC cppgl_glIsNamedBufferResidentNV;
#define glIsNamedBufferResidentNV cppgl_glIsNamedBufferResidentNV
typedef void (APIENTRYP PFNGLGETBUFFERPARAMETERUI64VNVPROC)(GLenum target, GLenum pname, GLuint64EXT *params);
GLAPI PFNGLGETBUFFERPARAMETERUI64VNVPROC cppgl_glGetBufferParameterui64vNV;
#define glGetBufferParameterui64vNV cppgl_glGetBufferParameterui64vNV
typedef void (APIENTRYP PFNGLGETNAMEDBUFFERPARAMETERUI64VNVPROC)(GLuint buffer, GLenum pname, GLuint64EXT *params);
GLAPI PFNGLGETNAMEDBUFFERPARAMETERUI64VNVPROC cppgl_glGetNamedBufferParameterui64vNV;
#define glGetNamedBufferParameterui64vNV cppgl_glGetNamedBufferParameterui64vNV
typedef void (APIENTRYP PFNGLGETINTEGERUI64VNVPROC)(GLenum value, GLuint64EXT *result);
GLAPI PFNGLGETINTEGERUI64VNVPROC cppgl_glGetIntegerui64vNV;
#define glGetIntegerui64vNV cppgl_glGetIntegerui64vNV
typedef void (APIENTRYP PFNGLUNIFORMUI64NVPROC)(GLint location, GLuint64EXT value);
GLAPI PFNGLUNIFORMUI64NVPROC cppgl_glUniformui64NV;
#define glUniformui64NV cppgl_glUniformui64NV
typedef void (APIENTRYP PFNGLUNIFORMUI64VNVPROC)(GLint location, GLsizei count, const GLuint64EXT *value);
GLAPI PFNGLUNIFORMUI64VNVPROC cppgl_glUniformui64vNV;
#define glUniformui64vNV cppgl_glUniformui64vNV
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMUI64NVPROC)(GLuint program, GLint location, GLuint64EXT value);
GLAPI PFNGLPROGRAMUNIFORMUI64NVPROC cppgl_glProgramUniformui64NV;
#define glProgramUniformui64NV cppgl_glProgramUniformui64NV
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMUI64VNVPROC)(GLuint program, GLint location, GLsizei count, const GLuint64EXT *value);
GLAPI PFNGLPROGRAMUNIFORMUI64VNVPROC cppgl_glProgramUniformui64vNV;
#define glProgramUniformui64vNV cppgl_glProgramUniformui64vNV
#endif
#ifndef GL_NV_shader_buffer_store
#define GL_NV_shader_buffer_store 1
GLAPI int CPPGL_GL_NV_shader_buffer_store;
#endif
#ifndef GL_NV_shader_storage_buffer_object
#define GL_NV_shader_storage_buffer_object 1
GLAPI int CPPGL_GL_NV_shader_storage_buffer_object;
#endif
#ifndef GL_NV_shader_thread_group
#define GL_NV_shader_thread_group 1
GLAPI int CPPGL_GL_NV_shader_thread_group;
#endif
#ifndef GL_NV_shader_thread_shuffle
#define GL_NV_shader_thread_shuffle 1
GLAPI int CPPGL_GL_NV_shader_thread_shuffle;
#endif
#ifndef GL_NV_stereo_view_rendering
#define GL_NV_stereo_view_rendering 1
GLAPI int CPPGL_GL_NV_stereo_view_rendering;
#endif
#ifndef GL_NV_tessellation_program5
#define GL_NV_tessellation_program5 1
GLAPI int CPPGL_GL_NV_tessellation_program5;
#endif
#ifndef GL_NV_texgen_emboss
#define GL_NV_texgen_emboss 1
GLAPI int CPPGL_GL_NV_texgen_emboss;
#endif
#ifndef GL_NV_texgen_reflection
#define GL_NV_texgen_reflection 1
GLAPI int CPPGL_GL_NV_texgen_reflection;
#endif
#ifndef GL_NV_texture_barrier
#define GL_NV_texture_barrier 1
GLAPI int CPPGL_GL_NV_texture_barrier;
typedef void (APIENTRYP PFNGLTEXTUREBARRIERNVPROC)();
GLAPI PFNGLTEXTUREBARRIERNVPROC cppgl_glTextureBarrierNV;
#define glTextureBarrierNV cppgl_glTextureBarrierNV
#endif
#ifndef GL_NV_texture_compression_vtc
#define GL_NV_texture_compression_vtc 1
GLAPI int CPPGL_GL_NV_texture_compression_vtc;
#endif
#ifndef GL_NV_texture_env_combine4
#define GL_NV_texture_env_combine4 1
GLAPI int CPPGL_GL_NV_texture_env_combine4;
#endif
#ifndef GL_NV_texture_expand_normal
#define GL_NV_texture_expand_normal 1
GLAPI int CPPGL_GL_NV_texture_expand_normal;
#endif
#ifndef GL_NV_texture_multisample
#define GL_NV_texture_multisample 1
GLAPI int CPPGL_GL_NV_texture_multisample;
typedef void (APIENTRYP PFNGLTEXIMAGE2DMULTISAMPLECOVERAGENVPROC)(GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLint internalFormat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations);
GLAPI PFNGLTEXIMAGE2DMULTISAMPLECOVERAGENVPROC cppgl_glTexImage2DMultisampleCoverageNV;
#define glTexImage2DMultisampleCoverageNV cppgl_glTexImage2DMultisampleCoverageNV
typedef void (APIENTRYP PFNGLTEXIMAGE3DMULTISAMPLECOVERAGENVPROC)(GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations);
GLAPI PFNGLTEXIMAGE3DMULTISAMPLECOVERAGENVPROC cppgl_glTexImage3DMultisampleCoverageNV;
#define glTexImage3DMultisampleCoverageNV cppgl_glTexImage3DMultisampleCoverageNV
typedef void (APIENTRYP PFNGLTEXTUREIMAGE2DMULTISAMPLENVPROC)(GLuint texture, GLenum target, GLsizei samples, GLint internalFormat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations);
GLAPI PFNGLTEXTUREIMAGE2DMULTISAMPLENVPROC cppgl_glTextureImage2DMultisampleNV;
#define glTextureImage2DMultisampleNV cppgl_glTextureImage2DMultisampleNV
typedef void (APIENTRYP PFNGLTEXTUREIMAGE3DMULTISAMPLENVPROC)(GLuint texture, GLenum target, GLsizei samples, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations);
GLAPI PFNGLTEXTUREIMAGE3DMULTISAMPLENVPROC cppgl_glTextureImage3DMultisampleNV;
#define glTextureImage3DMultisampleNV cppgl_glTextureImage3DMultisampleNV
typedef void (APIENTRYP PFNGLTEXTUREIMAGE2DMULTISAMPLECOVERAGENVPROC)(GLuint texture, GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLint internalFormat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations);
GLAPI PFNGLTEXTUREIMAGE2DMULTISAMPLECOVERAGENVPROC cppgl_glTextureImage2DMultisampleCoverageNV;
#define glTextureImage2DMultisampleCoverageNV cppgl_glTextureImage2DMultisampleCoverageNV
typedef void (APIENTRYP PFNGLTEXTUREIMAGE3DMULTISAMPLECOVERAGENVPROC)(GLuint texture, GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations);
GLAPI PFNGLTEXTUREIMAGE3DMULTISAMPLECOVERAGENVPROC cppgl_glTextureImage3DMultisampleCoverageNV;
#define glTextureImage3DMultisampleCoverageNV cppgl_glTextureImage3DMultisampleCoverageNV
#endif
#ifndef GL_NV_texture_rectangle
#define GL_NV_texture_rectangle 1
GLAPI int CPPGL_GL_NV_texture_rectangle;
#endif
#ifndef GL_NV_texture_shader
#define GL_NV_texture_shader 1
GLAPI int CPPGL_GL_NV_texture_shader;
#endif
#ifndef GL_NV_texture_shader2
#define GL_NV_texture_shader2 1
GLAPI int CPPGL_GL_NV_texture_shader2;
#endif
#ifndef GL_NV_texture_shader3
#define GL_NV_texture_shader3 1
GLAPI int CPPGL_GL_NV_texture_shader3;
#endif
#ifndef GL_NV_transform_feedback
#define GL_NV_transform_feedback 1
GLAPI int CPPGL_GL_NV_transform_feedback;
typedef void (APIENTRYP PFNGLBEGINTRANSFORMFEEDBACKNVPROC)(GLenum primitiveMode);
GLAPI PFNGLBEGINTRANSFORMFEEDBACKNVPROC cppgl_glBeginTransformFeedbackNV;
#define glBeginTransformFeedbackNV cppgl_glBeginTransformFeedbackNV
typedef void (APIENTRYP PFNGLENDTRANSFORMFEEDBACKNVPROC)();
GLAPI PFNGLENDTRANSFORMFEEDBACKNVPROC cppgl_glEndTransformFeedbackNV;
#define glEndTransformFeedbackNV cppgl_glEndTransformFeedbackNV
typedef void (APIENTRYP PFNGLTRANSFORMFEEDBACKATTRIBSNVPROC)(GLsizei count, const GLint *attribs, GLenum bufferMode);
GLAPI PFNGLTRANSFORMFEEDBACKATTRIBSNVPROC cppgl_glTransformFeedbackAttribsNV;
#define glTransformFeedbackAttribsNV cppgl_glTransformFeedbackAttribsNV
typedef void (APIENTRYP PFNGLBINDBUFFERRANGENVPROC)(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
GLAPI PFNGLBINDBUFFERRANGENVPROC cppgl_glBindBufferRangeNV;
#define glBindBufferRangeNV cppgl_glBindBufferRangeNV
typedef void (APIENTRYP PFNGLBINDBUFFEROFFSETNVPROC)(GLenum target, GLuint index, GLuint buffer, GLintptr offset);
GLAPI PFNGLBINDBUFFEROFFSETNVPROC cppgl_glBindBufferOffsetNV;
#define glBindBufferOffsetNV cppgl_glBindBufferOffsetNV
typedef void (APIENTRYP PFNGLBINDBUFFERBASENVPROC)(GLenum target, GLuint index, GLuint buffer);
GLAPI PFNGLBINDBUFFERBASENVPROC cppgl_glBindBufferBaseNV;
#define glBindBufferBaseNV cppgl_glBindBufferBaseNV
typedef void (APIENTRYP PFNGLTRANSFORMFEEDBACKVARYINGSNVPROC)(GLuint program, GLsizei count, const GLint *locations, GLenum bufferMode);
GLAPI PFNGLTRANSFORMFEEDBACKVARYINGSNVPROC cppgl_glTransformFeedbackVaryingsNV;
#define glTransformFeedbackVaryingsNV cppgl_glTransformFeedbackVaryingsNV
typedef void (APIENTRYP PFNGLACTIVEVARYINGNVPROC)(GLuint program, const GLchar *name);
GLAPI PFNGLACTIVEVARYINGNVPROC cppgl_glActiveVaryingNV;
#define glActiveVaryingNV cppgl_glActiveVaryingNV
typedef GLint (APIENTRYP PFNGLGETVARYINGLOCATIONNVPROC)(GLuint program, const GLchar *name);
GLAPI PFNGLGETVARYINGLOCATIONNVPROC cppgl_glGetVaryingLocationNV;
#define glGetVaryingLocationNV cppgl_glGetVaryingLocationNV
typedef void (APIENTRYP PFNGLGETACTIVEVARYINGNVPROC)(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name);
GLAPI PFNGLGETACTIVEVARYINGNVPROC cppgl_glGetActiveVaryingNV;
#define glGetActiveVaryingNV cppgl_glGetActiveVaryingNV
typedef void (APIENTRYP PFNGLGETTRANSFORMFEEDBACKVARYINGNVPROC)(GLuint program, GLuint index, GLint *location);
GLAPI PFNGLGETTRANSFORMFEEDBACKVARYINGNVPROC cppgl_glGetTransformFeedbackVaryingNV;
#define glGetTransformFeedbackVaryingNV cppgl_glGetTransformFeedbackVaryingNV
typedef void (APIENTRYP PFNGLTRANSFORMFEEDBACKSTREAMATTRIBSNVPROC)(GLsizei count, const GLint *attribs, GLsizei nbuffers, const GLint *bufstreams, GLenum bufferMode);
GLAPI PFNGLTRANSFORMFEEDBACKSTREAMATTRIBSNVPROC cppgl_glTransformFeedbackStreamAttribsNV;
#define glTransformFeedbackStreamAttribsNV cppgl_glTransformFeedbackStreamAttribsNV
#endif
#ifndef GL_NV_transform_feedback2
#define GL_NV_transform_feedback2 1
GLAPI int CPPGL_GL_NV_transform_feedback2;
typedef void (APIENTRYP PFNGLBINDTRANSFORMFEEDBACKNVPROC)(GLenum target, GLuint id);
GLAPI PFNGLBINDTRANSFORMFEEDBACKNVPROC cppgl_glBindTransformFeedbackNV;
#define glBindTransformFeedbackNV cppgl_glBindTransformFeedbackNV
typedef void (APIENTRYP PFNGLDELETETRANSFORMFEEDBACKSNVPROC)(GLsizei n, const GLuint *ids);
GLAPI PFNGLDELETETRANSFORMFEEDBACKSNVPROC cppgl_glDeleteTransformFeedbacksNV;
#define glDeleteTransformFeedbacksNV cppgl_glDeleteTransformFeedbacksNV
typedef void (APIENTRYP PFNGLGENTRANSFORMFEEDBACKSNVPROC)(GLsizei n, GLuint *ids);
GLAPI PFNGLGENTRANSFORMFEEDBACKSNVPROC cppgl_glGenTransformFeedbacksNV;
#define glGenTransformFeedbacksNV cppgl_glGenTransformFeedbacksNV
typedef GLboolean (APIENTRYP PFNGLISTRANSFORMFEEDBACKNVPROC)(GLuint id);
GLAPI PFNGLISTRANSFORMFEEDBACKNVPROC cppgl_glIsTransformFeedbackNV;
#define glIsTransformFeedbackNV cppgl_glIsTransformFeedbackNV
typedef void (APIENTRYP PFNGLPAUSETRANSFORMFEEDBACKNVPROC)();
GLAPI PFNGLPAUSETRANSFORMFEEDBACKNVPROC cppgl_glPauseTransformFeedbackNV;
#define glPauseTransformFeedbackNV cppgl_glPauseTransformFeedbackNV
typedef void (APIENTRYP PFNGLRESUMETRANSFORMFEEDBACKNVPROC)();
GLAPI PFNGLRESUMETRANSFORMFEEDBACKNVPROC cppgl_glResumeTransformFeedbackNV;
#define glResumeTransformFeedbackNV cppgl_glResumeTransformFeedbackNV
typedef void (APIENTRYP PFNGLDRAWTRANSFORMFEEDBACKNVPROC)(GLenum mode, GLuint id);
GLAPI PFNGLDRAWTRANSFORMFEEDBACKNVPROC cppgl_glDrawTransformFeedbackNV;
#define glDrawTransformFeedbackNV cppgl_glDrawTransformFeedbackNV
#endif
#ifndef GL_NV_uniform_buffer_unified_memory
#define GL_NV_uniform_buffer_unified_memory 1
GLAPI int CPPGL_GL_NV_uniform_buffer_unified_memory;
#endif
#ifndef GL_NV_vdpau_interop
#define GL_NV_vdpau_interop 1
GLAPI int CPPGL_GL_NV_vdpau_interop;
typedef void (APIENTRYP PFNGLVDPAUINITNVPROC)(const void *vdpDevice, const void *getProcAddress);
GLAPI PFNGLVDPAUINITNVPROC cppgl_glVDPAUInitNV;
#define glVDPAUInitNV cppgl_glVDPAUInitNV
typedef void (APIENTRYP PFNGLVDPAUFININVPROC)();
GLAPI PFNGLVDPAUFININVPROC cppgl_glVDPAUFiniNV;
#define glVDPAUFiniNV cppgl_glVDPAUFiniNV
typedef GLvdpauSurfaceNV (APIENTRYP PFNGLVDPAUREGISTERVIDEOSURFACENVPROC)(const void *vdpSurface, GLenum target, GLsizei numTextureNames, const GLuint *textureNames);
GLAPI PFNGLVDPAUREGISTERVIDEOSURFACENVPROC cppgl_glVDPAURegisterVideoSurfaceNV;
#define glVDPAURegisterVideoSurfaceNV cppgl_glVDPAURegisterVideoSurfaceNV
typedef GLvdpauSurfaceNV (APIENTRYP PFNGLVDPAUREGISTEROUTPUTSURFACENVPROC)(const void *vdpSurface, GLenum target, GLsizei numTextureNames, const GLuint *textureNames);
GLAPI PFNGLVDPAUREGISTEROUTPUTSURFACENVPROC cppgl_glVDPAURegisterOutputSurfaceNV;
#define glVDPAURegisterOutputSurfaceNV cppgl_glVDPAURegisterOutputSurfaceNV
typedef GLboolean (APIENTRYP PFNGLVDPAUISSURFACENVPROC)(GLvdpauSurfaceNV surface);
GLAPI PFNGLVDPAUISSURFACENVPROC cppgl_glVDPAUIsSurfaceNV;
#define glVDPAUIsSurfaceNV cppgl_glVDPAUIsSurfaceNV
typedef void (APIENTRYP PFNGLVDPAUUNREGISTERSURFACENVPROC)(GLvdpauSurfaceNV surface);
GLAPI PFNGLVDPAUUNREGISTERSURFACENVPROC cppgl_glVDPAUUnregisterSurfaceNV;
#define glVDPAUUnregisterSurfaceNV cppgl_glVDPAUUnregisterSurfaceNV
typedef void (APIENTRYP PFNGLVDPAUGETSURFACEIVNVPROC)(GLvdpauSurfaceNV surface, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *values);
GLAPI PFNGLVDPAUGETSURFACEIVNVPROC cppgl_glVDPAUGetSurfaceivNV;
#define glVDPAUGetSurfaceivNV cppgl_glVDPAUGetSurfaceivNV
typedef void (APIENTRYP PFNGLVDPAUSURFACEACCESSNVPROC)(GLvdpauSurfaceNV surface, GLenum access);
GLAPI PFNGLVDPAUSURFACEACCESSNVPROC cppgl_glVDPAUSurfaceAccessNV;
#define glVDPAUSurfaceAccessNV cppgl_glVDPAUSurfaceAccessNV
typedef void (APIENTRYP PFNGLVDPAUMAPSURFACESNVPROC)(GLsizei numSurfaces, const GLvdpauSurfaceNV *surfaces);
GLAPI PFNGLVDPAUMAPSURFACESNVPROC cppgl_glVDPAUMapSurfacesNV;
#define glVDPAUMapSurfacesNV cppgl_glVDPAUMapSurfacesNV
typedef void (APIENTRYP PFNGLVDPAUUNMAPSURFACESNVPROC)(GLsizei numSurface, const GLvdpauSurfaceNV *surfaces);
GLAPI PFNGLVDPAUUNMAPSURFACESNVPROC cppgl_glVDPAUUnmapSurfacesNV;
#define glVDPAUUnmapSurfacesNV cppgl_glVDPAUUnmapSurfacesNV
#endif
#ifndef GL_NV_vertex_array_range
#define GL_NV_vertex_array_range 1
GLAPI int CPPGL_GL_NV_vertex_array_range;
typedef void (APIENTRYP PFNGLFLUSHVERTEXARRAYRANGENVPROC)();
GLAPI PFNGLFLUSHVERTEXARRAYRANGENVPROC cppgl_glFlushVertexArrayRangeNV;
#define glFlushVertexArrayRangeNV cppgl_glFlushVertexArrayRangeNV
typedef void (APIENTRYP PFNGLVERTEXARRAYRANGENVPROC)(GLsizei length, const void *pointer);
GLAPI PFNGLVERTEXARRAYRANGENVPROC cppgl_glVertexArrayRangeNV;
#define glVertexArrayRangeNV cppgl_glVertexArrayRangeNV
#endif
#ifndef GL_NV_vertex_array_range2
#define GL_NV_vertex_array_range2 1
GLAPI int CPPGL_GL_NV_vertex_array_range2;
#endif
#ifndef GL_NV_vertex_attrib_integer_64bit
#define GL_NV_vertex_attrib_integer_64bit 1
GLAPI int CPPGL_GL_NV_vertex_attrib_integer_64bit;
typedef void (APIENTRYP PFNGLVERTEXATTRIBL1I64NVPROC)(GLuint index, GLint64EXT x);
GLAPI PFNGLVERTEXATTRIBL1I64NVPROC cppgl_glVertexAttribL1i64NV;
#define glVertexAttribL1i64NV cppgl_glVertexAttribL1i64NV
typedef void (APIENTRYP PFNGLVERTEXATTRIBL2I64NVPROC)(GLuint index, GLint64EXT x, GLint64EXT y);
GLAPI PFNGLVERTEXATTRIBL2I64NVPROC cppgl_glVertexAttribL2i64NV;
#define glVertexAttribL2i64NV cppgl_glVertexAttribL2i64NV
typedef void (APIENTRYP PFNGLVERTEXATTRIBL3I64NVPROC)(GLuint index, GLint64EXT x, GLint64EXT y, GLint64EXT z);
GLAPI PFNGLVERTEXATTRIBL3I64NVPROC cppgl_glVertexAttribL3i64NV;
#define glVertexAttribL3i64NV cppgl_glVertexAttribL3i64NV
typedef void (APIENTRYP PFNGLVERTEXATTRIBL4I64NVPROC)(GLuint index, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w);
GLAPI PFNGLVERTEXATTRIBL4I64NVPROC cppgl_glVertexAttribL4i64NV;
#define glVertexAttribL4i64NV cppgl_glVertexAttribL4i64NV
typedef void (APIENTRYP PFNGLVERTEXATTRIBL1I64VNVPROC)(GLuint index, const GLint64EXT *v);
GLAPI PFNGLVERTEXATTRIBL1I64VNVPROC cppgl_glVertexAttribL1i64vNV;
#define glVertexAttribL1i64vNV cppgl_glVertexAttribL1i64vNV
typedef void (APIENTRYP PFNGLVERTEXATTRIBL2I64VNVPROC)(GLuint index, const GLint64EXT *v);
GLAPI PFNGLVERTEXATTRIBL2I64VNVPROC cppgl_glVertexAttribL2i64vNV;
#define glVertexAttribL2i64vNV cppgl_glVertexAttribL2i64vNV
typedef void (APIENTRYP PFNGLVERTEXATTRIBL3I64VNVPROC)(GLuint index, const GLint64EXT *v);
GLAPI PFNGLVERTEXATTRIBL3I64VNVPROC cppgl_glVertexAttribL3i64vNV;
#define glVertexAttribL3i64vNV cppgl_glVertexAttribL3i64vNV
typedef void (APIENTRYP PFNGLVERTEXATTRIBL4I64VNVPROC)(GLuint index, const GLint64EXT *v);
GLAPI PFNGLVERTEXATTRIBL4I64VNVPROC cppgl_glVertexAttribL4i64vNV;
#define glVertexAttribL4i64vNV cppgl_glVertexAttribL4i64vNV
typedef void (APIENTRYP PFNGLVERTEXATTRIBL1UI64NVPROC)(GLuint index, GLuint64EXT x);
GLAPI PFNGLVERTEXATTRIBL1UI64NVPROC cppgl_glVertexAttribL1ui64NV;
#define glVertexAttribL1ui64NV cppgl_glVertexAttribL1ui64NV
typedef void (APIENTRYP PFNGLVERTEXATTRIBL2UI64NVPROC)(GLuint index, GLuint64EXT x, GLuint64EXT y);
GLAPI PFNGLVERTEXATTRIBL2UI64NVPROC cppgl_glVertexAttribL2ui64NV;
#define glVertexAttribL2ui64NV cppgl_glVertexAttribL2ui64NV
typedef void (APIENTRYP PFNGLVERTEXATTRIBL3UI64NVPROC)(GLuint index, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z);
GLAPI PFNGLVERTEXATTRIBL3UI64NVPROC cppgl_glVertexAttribL3ui64NV;
#define glVertexAttribL3ui64NV cppgl_glVertexAttribL3ui64NV
typedef void (APIENTRYP PFNGLVERTEXATTRIBL4UI64NVPROC)(GLuint index, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w);
GLAPI PFNGLVERTEXATTRIBL4UI64NVPROC cppgl_glVertexAttribL4ui64NV;
#define glVertexAttribL4ui64NV cppgl_glVertexAttribL4ui64NV
typedef void (APIENTRYP PFNGLVERTEXATTRIBL1UI64VNVPROC)(GLuint index, const GLuint64EXT *v);
GLAPI PFNGLVERTEXATTRIBL1UI64VNVPROC cppgl_glVertexAttribL1ui64vNV;
#define glVertexAttribL1ui64vNV cppgl_glVertexAttribL1ui64vNV
typedef void (APIENTRYP PFNGLVERTEXATTRIBL2UI64VNVPROC)(GLuint index, const GLuint64EXT *v);
GLAPI PFNGLVERTEXATTRIBL2UI64VNVPROC cppgl_glVertexAttribL2ui64vNV;
#define glVertexAttribL2ui64vNV cppgl_glVertexAttribL2ui64vNV
typedef void (APIENTRYP PFNGLVERTEXATTRIBL3UI64VNVPROC)(GLuint index, const GLuint64EXT *v);
GLAPI PFNGLVERTEXATTRIBL3UI64VNVPROC cppgl_glVertexAttribL3ui64vNV;
#define glVertexAttribL3ui64vNV cppgl_glVertexAttribL3ui64vNV
typedef void (APIENTRYP PFNGLVERTEXATTRIBL4UI64VNVPROC)(GLuint index, const GLuint64EXT *v);
GLAPI PFNGLVERTEXATTRIBL4UI64VNVPROC cppgl_glVertexAttribL4ui64vNV;
#define glVertexAttribL4ui64vNV cppgl_glVertexAttribL4ui64vNV
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBLI64VNVPROC)(GLuint index, GLenum pname, GLint64EXT *params);
GLAPI PFNGLGETVERTEXATTRIBLI64VNVPROC cppgl_glGetVertexAttribLi64vNV;
#define glGetVertexAttribLi64vNV cppgl_glGetVertexAttribLi64vNV
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBLUI64VNVPROC)(GLuint index, GLenum pname, GLuint64EXT *params);
GLAPI PFNGLGETVERTEXATTRIBLUI64VNVPROC cppgl_glGetVertexAttribLui64vNV;
#define glGetVertexAttribLui64vNV cppgl_glGetVertexAttribLui64vNV
typedef void (APIENTRYP PFNGLVERTEXATTRIBLFORMATNVPROC)(GLuint index, GLint size, GLenum type, GLsizei stride);
GLAPI PFNGLVERTEXATTRIBLFORMATNVPROC cppgl_glVertexAttribLFormatNV;
#define glVertexAttribLFormatNV cppgl_glVertexAttribLFormatNV
#endif
#ifndef GL_NV_vertex_buffer_unified_memory
#define GL_NV_vertex_buffer_unified_memory 1
GLAPI int CPPGL_GL_NV_vertex_buffer_unified_memory;
typedef void (APIENTRYP PFNGLBUFFERADDRESSRANGENVPROC)(GLenum pname, GLuint index, GLuint64EXT address, GLsizeiptr length);
GLAPI PFNGLBUFFERADDRESSRANGENVPROC cppgl_glBufferAddressRangeNV;
#define glBufferAddressRangeNV cppgl_glBufferAddressRangeNV
typedef void (APIENTRYP PFNGLVERTEXFORMATNVPROC)(GLint size, GLenum type, GLsizei stride);
GLAPI PFNGLVERTEXFORMATNVPROC cppgl_glVertexFormatNV;
#define glVertexFormatNV cppgl_glVertexFormatNV
typedef void (APIENTRYP PFNGLNORMALFORMATNVPROC)(GLenum type, GLsizei stride);
GLAPI PFNGLNORMALFORMATNVPROC cppgl_glNormalFormatNV;
#define glNormalFormatNV cppgl_glNormalFormatNV
typedef void (APIENTRYP PFNGLCOLORFORMATNVPROC)(GLint size, GLenum type, GLsizei stride);
GLAPI PFNGLCOLORFORMATNVPROC cppgl_glColorFormatNV;
#define glColorFormatNV cppgl_glColorFormatNV
typedef void (APIENTRYP PFNGLINDEXFORMATNVPROC)(GLenum type, GLsizei stride);
GLAPI PFNGLINDEXFORMATNVPROC cppgl_glIndexFormatNV;
#define glIndexFormatNV cppgl_glIndexFormatNV
typedef void (APIENTRYP PFNGLTEXCOORDFORMATNVPROC)(GLint size, GLenum type, GLsizei stride);
GLAPI PFNGLTEXCOORDFORMATNVPROC cppgl_glTexCoordFormatNV;
#define glTexCoordFormatNV cppgl_glTexCoordFormatNV
typedef void (APIENTRYP PFNGLEDGEFLAGFORMATNVPROC)(GLsizei stride);
GLAPI PFNGLEDGEFLAGFORMATNVPROC cppgl_glEdgeFlagFormatNV;
#define glEdgeFlagFormatNV cppgl_glEdgeFlagFormatNV
typedef void (APIENTRYP PFNGLSECONDARYCOLORFORMATNVPROC)(GLint size, GLenum type, GLsizei stride);
GLAPI PFNGLSECONDARYCOLORFORMATNVPROC cppgl_glSecondaryColorFormatNV;
#define glSecondaryColorFormatNV cppgl_glSecondaryColorFormatNV
typedef void (APIENTRYP PFNGLFOGCOORDFORMATNVPROC)(GLenum type, GLsizei stride);
GLAPI PFNGLFOGCOORDFORMATNVPROC cppgl_glFogCoordFormatNV;
#define glFogCoordFormatNV cppgl_glFogCoordFormatNV
typedef void (APIENTRYP PFNGLVERTEXATTRIBFORMATNVPROC)(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride);
GLAPI PFNGLVERTEXATTRIBFORMATNVPROC cppgl_glVertexAttribFormatNV;
#define glVertexAttribFormatNV cppgl_glVertexAttribFormatNV
typedef void (APIENTRYP PFNGLVERTEXATTRIBIFORMATNVPROC)(GLuint index, GLint size, GLenum type, GLsizei stride);
GLAPI PFNGLVERTEXATTRIBIFORMATNVPROC cppgl_glVertexAttribIFormatNV;
#define glVertexAttribIFormatNV cppgl_glVertexAttribIFormatNV
typedef void (APIENTRYP PFNGLGETINTEGERUI64I_VNVPROC)(GLenum value, GLuint index, GLuint64EXT *result);
GLAPI PFNGLGETINTEGERUI64I_VNVPROC cppgl_glGetIntegerui64i_vNV;
#define glGetIntegerui64i_vNV cppgl_glGetIntegerui64i_vNV
#endif
#ifndef GL_NV_vertex_program
#define GL_NV_vertex_program 1
GLAPI int CPPGL_GL_NV_vertex_program;
typedef GLboolean (APIENTRYP PFNGLAREPROGRAMSRESIDENTNVPROC)(GLsizei n, const GLuint *programs, GLboolean *residences);
GLAPI PFNGLAREPROGRAMSRESIDENTNVPROC cppgl_glAreProgramsResidentNV;
#define glAreProgramsResidentNV cppgl_glAreProgramsResidentNV
typedef void (APIENTRYP PFNGLBINDPROGRAMNVPROC)(GLenum target, GLuint id);
GLAPI PFNGLBINDPROGRAMNVPROC cppgl_glBindProgramNV;
#define glBindProgramNV cppgl_glBindProgramNV
typedef void (APIENTRYP PFNGLDELETEPROGRAMSNVPROC)(GLsizei n, const GLuint *programs);
GLAPI PFNGLDELETEPROGRAMSNVPROC cppgl_glDeleteProgramsNV;
#define glDeleteProgramsNV cppgl_glDeleteProgramsNV
typedef void (APIENTRYP PFNGLEXECUTEPROGRAMNVPROC)(GLenum target, GLuint id, const GLfloat *params);
GLAPI PFNGLEXECUTEPROGRAMNVPROC cppgl_glExecuteProgramNV;
#define glExecuteProgramNV cppgl_glExecuteProgramNV
typedef void (APIENTRYP PFNGLGENPROGRAMSNVPROC)(GLsizei n, GLuint *programs);
GLAPI PFNGLGENPROGRAMSNVPROC cppgl_glGenProgramsNV;
#define glGenProgramsNV cppgl_glGenProgramsNV
typedef void (APIENTRYP PFNGLGETPROGRAMPARAMETERDVNVPROC)(GLenum target, GLuint index, GLenum pname, GLdouble *params);
GLAPI PFNGLGETPROGRAMPARAMETERDVNVPROC cppgl_glGetProgramParameterdvNV;
#define glGetProgramParameterdvNV cppgl_glGetProgramParameterdvNV
typedef void (APIENTRYP PFNGLGETPROGRAMPARAMETERFVNVPROC)(GLenum target, GLuint index, GLenum pname, GLfloat *params);
GLAPI PFNGLGETPROGRAMPARAMETERFVNVPROC cppgl_glGetProgramParameterfvNV;
#define glGetProgramParameterfvNV cppgl_glGetProgramParameterfvNV
typedef void (APIENTRYP PFNGLGETPROGRAMIVNVPROC)(GLuint id, GLenum pname, GLint *params);
GLAPI PFNGLGETPROGRAMIVNVPROC cppgl_glGetProgramivNV;
#define glGetProgramivNV cppgl_glGetProgramivNV
typedef void (APIENTRYP PFNGLGETPROGRAMSTRINGNVPROC)(GLuint id, GLenum pname, GLubyte *program);
GLAPI PFNGLGETPROGRAMSTRINGNVPROC cppgl_glGetProgramStringNV;
#define glGetProgramStringNV cppgl_glGetProgramStringNV
typedef void (APIENTRYP PFNGLGETTRACKMATRIXIVNVPROC)(GLenum target, GLuint address, GLenum pname, GLint *params);
GLAPI PFNGLGETTRACKMATRIXIVNVPROC cppgl_glGetTrackMatrixivNV;
#define glGetTrackMatrixivNV cppgl_glGetTrackMatrixivNV
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBDVNVPROC)(GLuint index, GLenum pname, GLdouble *params);
GLAPI PFNGLGETVERTEXATTRIBDVNVPROC cppgl_glGetVertexAttribdvNV;
#define glGetVertexAttribdvNV cppgl_glGetVertexAttribdvNV
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBFVNVPROC)(GLuint index, GLenum pname, GLfloat *params);
GLAPI PFNGLGETVERTEXATTRIBFVNVPROC cppgl_glGetVertexAttribfvNV;
#define glGetVertexAttribfvNV cppgl_glGetVertexAttribfvNV
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBIVNVPROC)(GLuint index, GLenum pname, GLint *params);
GLAPI PFNGLGETVERTEXATTRIBIVNVPROC cppgl_glGetVertexAttribivNV;
#define glGetVertexAttribivNV cppgl_glGetVertexAttribivNV
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBPOINTERVNVPROC)(GLuint index, GLenum pname, void **pointer);
GLAPI PFNGLGETVERTEXATTRIBPOINTERVNVPROC cppgl_glGetVertexAttribPointervNV;
#define glGetVertexAttribPointervNV cppgl_glGetVertexAttribPointervNV
typedef GLboolean (APIENTRYP PFNGLISPROGRAMNVPROC)(GLuint id);
GLAPI PFNGLISPROGRAMNVPROC cppgl_glIsProgramNV;
#define glIsProgramNV cppgl_glIsProgramNV
typedef void (APIENTRYP PFNGLLOADPROGRAMNVPROC)(GLenum target, GLuint id, GLsizei len, const GLubyte *program);
GLAPI PFNGLLOADPROGRAMNVPROC cppgl_glLoadProgramNV;
#define glLoadProgramNV cppgl_glLoadProgramNV
typedef void (APIENTRYP PFNGLPROGRAMPARAMETER4DNVPROC)(GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
GLAPI PFNGLPROGRAMPARAMETER4DNVPROC cppgl_glProgramParameter4dNV;
#define glProgramParameter4dNV cppgl_glProgramParameter4dNV
typedef void (APIENTRYP PFNGLPROGRAMPARAMETER4DVNVPROC)(GLenum target, GLuint index, const GLdouble *v);
GLAPI PFNGLPROGRAMPARAMETER4DVNVPROC cppgl_glProgramParameter4dvNV;
#define glProgramParameter4dvNV cppgl_glProgramParameter4dvNV
typedef void (APIENTRYP PFNGLPROGRAMPARAMETER4FNVPROC)(GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
GLAPI PFNGLPROGRAMPARAMETER4FNVPROC cppgl_glProgramParameter4fNV;
#define glProgramParameter4fNV cppgl_glProgramParameter4fNV
typedef void (APIENTRYP PFNGLPROGRAMPARAMETER4FVNVPROC)(GLenum target, GLuint index, const GLfloat *v);
GLAPI PFNGLPROGRAMPARAMETER4FVNVPROC cppgl_glProgramParameter4fvNV;
#define glProgramParameter4fvNV cppgl_glProgramParameter4fvNV
typedef void (APIENTRYP PFNGLPROGRAMPARAMETERS4DVNVPROC)(GLenum target, GLuint index, GLsizei count, const GLdouble *v);
GLAPI PFNGLPROGRAMPARAMETERS4DVNVPROC cppgl_glProgramParameters4dvNV;
#define glProgramParameters4dvNV cppgl_glProgramParameters4dvNV
typedef void (APIENTRYP PFNGLPROGRAMPARAMETERS4FVNVPROC)(GLenum target, GLuint index, GLsizei count, const GLfloat *v);
GLAPI PFNGLPROGRAMPARAMETERS4FVNVPROC cppgl_glProgramParameters4fvNV;
#define glProgramParameters4fvNV cppgl_glProgramParameters4fvNV
typedef void (APIENTRYP PFNGLREQUESTRESIDENTPROGRAMSNVPROC)(GLsizei n, const GLuint *programs);
GLAPI PFNGLREQUESTRESIDENTPROGRAMSNVPROC cppgl_glRequestResidentProgramsNV;
#define glRequestResidentProgramsNV cppgl_glRequestResidentProgramsNV
typedef void (APIENTRYP PFNGLTRACKMATRIXNVPROC)(GLenum target, GLuint address, GLenum matrix, GLenum transform);
GLAPI PFNGLTRACKMATRIXNVPROC cppgl_glTrackMatrixNV;
#define glTrackMatrixNV cppgl_glTrackMatrixNV
typedef void (APIENTRYP PFNGLVERTEXATTRIBPOINTERNVPROC)(GLuint index, GLint fsize, GLenum type, GLsizei stride, const void *pointer);
GLAPI PFNGLVERTEXATTRIBPOINTERNVPROC cppgl_glVertexAttribPointerNV;
#define glVertexAttribPointerNV cppgl_glVertexAttribPointerNV
typedef void (APIENTRYP PFNGLVERTEXATTRIB1DNVPROC)(GLuint index, GLdouble x);
GLAPI PFNGLVERTEXATTRIB1DNVPROC cppgl_glVertexAttrib1dNV;
#define glVertexAttrib1dNV cppgl_glVertexAttrib1dNV
typedef void (APIENTRYP PFNGLVERTEXATTRIB1DVNVPROC)(GLuint index, const GLdouble *v);
GLAPI PFNGLVERTEXATTRIB1DVNVPROC cppgl_glVertexAttrib1dvNV;
#define glVertexAttrib1dvNV cppgl_glVertexAttrib1dvNV
typedef void (APIENTRYP PFNGLVERTEXATTRIB1FNVPROC)(GLuint index, GLfloat x);
GLAPI PFNGLVERTEXATTRIB1FNVPROC cppgl_glVertexAttrib1fNV;
#define glVertexAttrib1fNV cppgl_glVertexAttrib1fNV
typedef void (APIENTRYP PFNGLVERTEXATTRIB1FVNVPROC)(GLuint index, const GLfloat *v);
GLAPI PFNGLVERTEXATTRIB1FVNVPROC cppgl_glVertexAttrib1fvNV;
#define glVertexAttrib1fvNV cppgl_glVertexAttrib1fvNV
typedef void (APIENTRYP PFNGLVERTEXATTRIB1SNVPROC)(GLuint index, GLshort x);
GLAPI PFNGLVERTEXATTRIB1SNVPROC cppgl_glVertexAttrib1sNV;
#define glVertexAttrib1sNV cppgl_glVertexAttrib1sNV
typedef void (APIENTRYP PFNGLVERTEXATTRIB1SVNVPROC)(GLuint index, const GLshort *v);
GLAPI PFNGLVERTEXATTRIB1SVNVPROC cppgl_glVertexAttrib1svNV;
#define glVertexAttrib1svNV cppgl_glVertexAttrib1svNV
typedef void (APIENTRYP PFNGLVERTEXATTRIB2DNVPROC)(GLuint index, GLdouble x, GLdouble y);
GLAPI PFNGLVERTEXATTRIB2DNVPROC cppgl_glVertexAttrib2dNV;
#define glVertexAttrib2dNV cppgl_glVertexAttrib2dNV
typedef void (APIENTRYP PFNGLVERTEXATTRIB2DVNVPROC)(GLuint index, const GLdouble *v);
GLAPI PFNGLVERTEXATTRIB2DVNVPROC cppgl_glVertexAttrib2dvNV;
#define glVertexAttrib2dvNV cppgl_glVertexAttrib2dvNV
typedef void (APIENTRYP PFNGLVERTEXATTRIB2FNVPROC)(GLuint index, GLfloat x, GLfloat y);
GLAPI PFNGLVERTEXATTRIB2FNVPROC cppgl_glVertexAttrib2fNV;
#define glVertexAttrib2fNV cppgl_glVertexAttrib2fNV
typedef void (APIENTRYP PFNGLVERTEXATTRIB2FVNVPROC)(GLuint index, const GLfloat *v);
GLAPI PFNGLVERTEXATTRIB2FVNVPROC cppgl_glVertexAttrib2fvNV;
#define glVertexAttrib2fvNV cppgl_glVertexAttrib2fvNV
typedef void (APIENTRYP PFNGLVERTEXATTRIB2SNVPROC)(GLuint index, GLshort x, GLshort y);
GLAPI PFNGLVERTEXATTRIB2SNVPROC cppgl_glVertexAttrib2sNV;
#define glVertexAttrib2sNV cppgl_glVertexAttrib2sNV
typedef void (APIENTRYP PFNGLVERTEXATTRIB2SVNVPROC)(GLuint index, const GLshort *v);
GLAPI PFNGLVERTEXATTRIB2SVNVPROC cppgl_glVertexAttrib2svNV;
#define glVertexAttrib2svNV cppgl_glVertexAttrib2svNV
typedef void (APIENTRYP PFNGLVERTEXATTRIB3DNVPROC)(GLuint index, GLdouble x, GLdouble y, GLdouble z);
GLAPI PFNGLVERTEXATTRIB3DNVPROC cppgl_glVertexAttrib3dNV;
#define glVertexAttrib3dNV cppgl_glVertexAttrib3dNV
typedef void (APIENTRYP PFNGLVERTEXATTRIB3DVNVPROC)(GLuint index, const GLdouble *v);
GLAPI PFNGLVERTEXATTRIB3DVNVPROC cppgl_glVertexAttrib3dvNV;
#define glVertexAttrib3dvNV cppgl_glVertexAttrib3dvNV
typedef void (APIENTRYP PFNGLVERTEXATTRIB3FNVPROC)(GLuint index, GLfloat x, GLfloat y, GLfloat z);
GLAPI PFNGLVERTEXATTRIB3FNVPROC cppgl_glVertexAttrib3fNV;
#define glVertexAttrib3fNV cppgl_glVertexAttrib3fNV
typedef void (APIENTRYP PFNGLVERTEXATTRIB3FVNVPROC)(GLuint index, const GLfloat *v);
GLAPI PFNGLVERTEXATTRIB3FVNVPROC cppgl_glVertexAttrib3fvNV;
#define glVertexAttrib3fvNV cppgl_glVertexAttrib3fvNV
typedef void (APIENTRYP PFNGLVERTEXATTRIB3SNVPROC)(GLuint index, GLshort x, GLshort y, GLshort z);
GLAPI PFNGLVERTEXATTRIB3SNVPROC cppgl_glVertexAttrib3sNV;
#define glVertexAttrib3sNV cppgl_glVertexAttrib3sNV
typedef void (APIENTRYP PFNGLVERTEXATTRIB3SVNVPROC)(GLuint index, const GLshort *v);
GLAPI PFNGLVERTEXATTRIB3SVNVPROC cppgl_glVertexAttrib3svNV;
#define glVertexAttrib3svNV cppgl_glVertexAttrib3svNV
typedef void (APIENTRYP PFNGLVERTEXATTRIB4DNVPROC)(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
GLAPI PFNGLVERTEXATTRIB4DNVPROC cppgl_glVertexAttrib4dNV;
#define glVertexAttrib4dNV cppgl_glVertexAttrib4dNV
typedef void (APIENTRYP PFNGLVERTEXATTRIB4DVNVPROC)(GLuint index, const GLdouble *v);
GLAPI PFNGLVERTEXATTRIB4DVNVPROC cppgl_glVertexAttrib4dvNV;
#define glVertexAttrib4dvNV cppgl_glVertexAttrib4dvNV
typedef void (APIENTRYP PFNGLVERTEXATTRIB4FNVPROC)(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
GLAPI PFNGLVERTEXATTRIB4FNVPROC cppgl_glVertexAttrib4fNV;
#define glVertexAttrib4fNV cppgl_glVertexAttrib4fNV
typedef void (APIENTRYP PFNGLVERTEXATTRIB4FVNVPROC)(GLuint index, const GLfloat *v);
GLAPI PFNGLVERTEXATTRIB4FVNVPROC cppgl_glVertexAttrib4fvNV;
#define glVertexAttrib4fvNV cppgl_glVertexAttrib4fvNV
typedef void (APIENTRYP PFNGLVERTEXATTRIB4SNVPROC)(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
GLAPI PFNGLVERTEXATTRIB4SNVPROC cppgl_glVertexAttrib4sNV;
#define glVertexAttrib4sNV cppgl_glVertexAttrib4sNV
typedef void (APIENTRYP PFNGLVERTEXATTRIB4SVNVPROC)(GLuint index, const GLshort *v);
GLAPI PFNGLVERTEXATTRIB4SVNVPROC cppgl_glVertexAttrib4svNV;
#define glVertexAttrib4svNV cppgl_glVertexAttrib4svNV
typedef void (APIENTRYP PFNGLVERTEXATTRIB4UBNVPROC)(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
GLAPI PFNGLVERTEXATTRIB4UBNVPROC cppgl_glVertexAttrib4ubNV;
#define glVertexAttrib4ubNV cppgl_glVertexAttrib4ubNV
typedef void (APIENTRYP PFNGLVERTEXATTRIB4UBVNVPROC)(GLuint index, const GLubyte *v);
GLAPI PFNGLVERTEXATTRIB4UBVNVPROC cppgl_glVertexAttrib4ubvNV;
#define glVertexAttrib4ubvNV cppgl_glVertexAttrib4ubvNV
typedef void (APIENTRYP PFNGLVERTEXATTRIBS1DVNVPROC)(GLuint index, GLsizei count, const GLdouble *v);
GLAPI PFNGLVERTEXATTRIBS1DVNVPROC cppgl_glVertexAttribs1dvNV;
#define glVertexAttribs1dvNV cppgl_glVertexAttribs1dvNV
typedef void (APIENTRYP PFNGLVERTEXATTRIBS1FVNVPROC)(GLuint index, GLsizei count, const GLfloat *v);
GLAPI PFNGLVERTEXATTRIBS1FVNVPROC cppgl_glVertexAttribs1fvNV;
#define glVertexAttribs1fvNV cppgl_glVertexAttribs1fvNV
typedef void (APIENTRYP PFNGLVERTEXATTRIBS1SVNVPROC)(GLuint index, GLsizei count, const GLshort *v);
GLAPI PFNGLVERTEXATTRIBS1SVNVPROC cppgl_glVertexAttribs1svNV;
#define glVertexAttribs1svNV cppgl_glVertexAttribs1svNV
typedef void (APIENTRYP PFNGLVERTEXATTRIBS2DVNVPROC)(GLuint index, GLsizei count, const GLdouble *v);
GLAPI PFNGLVERTEXATTRIBS2DVNVPROC cppgl_glVertexAttribs2dvNV;
#define glVertexAttribs2dvNV cppgl_glVertexAttribs2dvNV
typedef void (APIENTRYP PFNGLVERTEXATTRIBS2FVNVPROC)(GLuint index, GLsizei count, const GLfloat *v);
GLAPI PFNGLVERTEXATTRIBS2FVNVPROC cppgl_glVertexAttribs2fvNV;
#define glVertexAttribs2fvNV cppgl_glVertexAttribs2fvNV
typedef void (APIENTRYP PFNGLVERTEXATTRIBS2SVNVPROC)(GLuint index, GLsizei count, const GLshort *v);
GLAPI PFNGLVERTEXATTRIBS2SVNVPROC cppgl_glVertexAttribs2svNV;
#define glVertexAttribs2svNV cppgl_glVertexAttribs2svNV
typedef void (APIENTRYP PFNGLVERTEXATTRIBS3DVNVPROC)(GLuint index, GLsizei count, const GLdouble *v);
GLAPI PFNGLVERTEXATTRIBS3DVNVPROC cppgl_glVertexAttribs3dvNV;
#define glVertexAttribs3dvNV cppgl_glVertexAttribs3dvNV
typedef void (APIENTRYP PFNGLVERTEXATTRIBS3FVNVPROC)(GLuint index, GLsizei count, const GLfloat *v);
GLAPI PFNGLVERTEXATTRIBS3FVNVPROC cppgl_glVertexAttribs3fvNV;
#define glVertexAttribs3fvNV cppgl_glVertexAttribs3fvNV
typedef void (APIENTRYP PFNGLVERTEXATTRIBS3SVNVPROC)(GLuint index, GLsizei count, const GLshort *v);
GLAPI PFNGLVERTEXATTRIBS3SVNVPROC cppgl_glVertexAttribs3svNV;
#define glVertexAttribs3svNV cppgl_glVertexAttribs3svNV
typedef void (APIENTRYP PFNGLVERTEXATTRIBS4DVNVPROC)(GLuint index, GLsizei count, const GLdouble *v);
GLAPI PFNGLVERTEXATTRIBS4DVNVPROC cppgl_glVertexAttribs4dvNV;
#define glVertexAttribs4dvNV cppgl_glVertexAttribs4dvNV
typedef void (APIENTRYP PFNGLVERTEXATTRIBS4FVNVPROC)(GLuint index, GLsizei count, const GLfloat *v);
GLAPI PFNGLVERTEXATTRIBS4FVNVPROC cppgl_glVertexAttribs4fvNV;
#define glVertexAttribs4fvNV cppgl_glVertexAttribs4fvNV
typedef void (APIENTRYP PFNGLVERTEXATTRIBS4SVNVPROC)(GLuint index, GLsizei count, const GLshort *v);
GLAPI PFNGLVERTEXATTRIBS4SVNVPROC cppgl_glVertexAttribs4svNV;
#define glVertexAttribs4svNV cppgl_glVertexAttribs4svNV
typedef void (APIENTRYP PFNGLVERTEXATTRIBS4UBVNVPROC)(GLuint index, GLsizei count, const GLubyte *v);
GLAPI PFNGLVERTEXATTRIBS4UBVNVPROC cppgl_glVertexAttribs4ubvNV;
#define glVertexAttribs4ubvNV cppgl_glVertexAttribs4ubvNV
#endif
#ifndef GL_NV_vertex_program1_1
#define GL_NV_vertex_program1_1 1
GLAPI int CPPGL_GL_NV_vertex_program1_1;
#endif
#ifndef GL_NV_vertex_program2
#define GL_NV_vertex_program2 1
GLAPI int CPPGL_GL_NV_vertex_program2;
#endif
#ifndef GL_NV_vertex_program2_option
#define GL_NV_vertex_program2_option 1
GLAPI int CPPGL_GL_NV_vertex_program2_option;
#endif
#ifndef GL_NV_vertex_program3
#define GL_NV_vertex_program3 1
GLAPI int CPPGL_GL_NV_vertex_program3;
#endif
#ifndef GL_NV_vertex_program4
#define GL_NV_vertex_program4 1
GLAPI int CPPGL_GL_NV_vertex_program4;
typedef void (APIENTRYP PFNGLVERTEXATTRIBI1IEXTPROC)(GLuint index, GLint x);
GLAPI PFNGLVERTEXATTRIBI1IEXTPROC cppgl_glVertexAttribI1iEXT;
#define glVertexAttribI1iEXT cppgl_glVertexAttribI1iEXT
typedef void (APIENTRYP PFNGLVERTEXATTRIBI2IEXTPROC)(GLuint index, GLint x, GLint y);
GLAPI PFNGLVERTEXATTRIBI2IEXTPROC cppgl_glVertexAttribI2iEXT;
#define glVertexAttribI2iEXT cppgl_glVertexAttribI2iEXT
typedef void (APIENTRYP PFNGLVERTEXATTRIBI3IEXTPROC)(GLuint index, GLint x, GLint y, GLint z);
GLAPI PFNGLVERTEXATTRIBI3IEXTPROC cppgl_glVertexAttribI3iEXT;
#define glVertexAttribI3iEXT cppgl_glVertexAttribI3iEXT
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4IEXTPROC)(GLuint index, GLint x, GLint y, GLint z, GLint w);
GLAPI PFNGLVERTEXATTRIBI4IEXTPROC cppgl_glVertexAttribI4iEXT;
#define glVertexAttribI4iEXT cppgl_glVertexAttribI4iEXT
typedef void (APIENTRYP PFNGLVERTEXATTRIBI1UIEXTPROC)(GLuint index, GLuint x);
GLAPI PFNGLVERTEXATTRIBI1UIEXTPROC cppgl_glVertexAttribI1uiEXT;
#define glVertexAttribI1uiEXT cppgl_glVertexAttribI1uiEXT
typedef void (APIENTRYP PFNGLVERTEXATTRIBI2UIEXTPROC)(GLuint index, GLuint x, GLuint y);
GLAPI PFNGLVERTEXATTRIBI2UIEXTPROC cppgl_glVertexAttribI2uiEXT;
#define glVertexAttribI2uiEXT cppgl_glVertexAttribI2uiEXT
typedef void (APIENTRYP PFNGLVERTEXATTRIBI3UIEXTPROC)(GLuint index, GLuint x, GLuint y, GLuint z);
GLAPI PFNGLVERTEXATTRIBI3UIEXTPROC cppgl_glVertexAttribI3uiEXT;
#define glVertexAttribI3uiEXT cppgl_glVertexAttribI3uiEXT
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4UIEXTPROC)(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
GLAPI PFNGLVERTEXATTRIBI4UIEXTPROC cppgl_glVertexAttribI4uiEXT;
#define glVertexAttribI4uiEXT cppgl_glVertexAttribI4uiEXT
typedef void (APIENTRYP PFNGLVERTEXATTRIBI1IVEXTPROC)(GLuint index, const GLint *v);
GLAPI PFNGLVERTEXATTRIBI1IVEXTPROC cppgl_glVertexAttribI1ivEXT;
#define glVertexAttribI1ivEXT cppgl_glVertexAttribI1ivEXT
typedef void (APIENTRYP PFNGLVERTEXATTRIBI2IVEXTPROC)(GLuint index, const GLint *v);
GLAPI PFNGLVERTEXATTRIBI2IVEXTPROC cppgl_glVertexAttribI2ivEXT;
#define glVertexAttribI2ivEXT cppgl_glVertexAttribI2ivEXT
typedef void (APIENTRYP PFNGLVERTEXATTRIBI3IVEXTPROC)(GLuint index, const GLint *v);
GLAPI PFNGLVERTEXATTRIBI3IVEXTPROC cppgl_glVertexAttribI3ivEXT;
#define glVertexAttribI3ivEXT cppgl_glVertexAttribI3ivEXT
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4IVEXTPROC)(GLuint index, const GLint *v);
GLAPI PFNGLVERTEXATTRIBI4IVEXTPROC cppgl_glVertexAttribI4ivEXT;
#define glVertexAttribI4ivEXT cppgl_glVertexAttribI4ivEXT
typedef void (APIENTRYP PFNGLVERTEXATTRIBI1UIVEXTPROC)(GLuint index, const GLuint *v);
GLAPI PFNGLVERTEXATTRIBI1UIVEXTPROC cppgl_glVertexAttribI1uivEXT;
#define glVertexAttribI1uivEXT cppgl_glVertexAttribI1uivEXT
typedef void (APIENTRYP PFNGLVERTEXATTRIBI2UIVEXTPROC)(GLuint index, const GLuint *v);
GLAPI PFNGLVERTEXATTRIBI2UIVEXTPROC cppgl_glVertexAttribI2uivEXT;
#define glVertexAttribI2uivEXT cppgl_glVertexAttribI2uivEXT
typedef void (APIENTRYP PFNGLVERTEXATTRIBI3UIVEXTPROC)(GLuint index, const GLuint *v);
GLAPI PFNGLVERTEXATTRIBI3UIVEXTPROC cppgl_glVertexAttribI3uivEXT;
#define glVertexAttribI3uivEXT cppgl_glVertexAttribI3uivEXT
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4UIVEXTPROC)(GLuint index, const GLuint *v);
GLAPI PFNGLVERTEXATTRIBI4UIVEXTPROC cppgl_glVertexAttribI4uivEXT;
#define glVertexAttribI4uivEXT cppgl_glVertexAttribI4uivEXT
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4BVEXTPROC)(GLuint index, const GLbyte *v);
GLAPI PFNGLVERTEXATTRIBI4BVEXTPROC cppgl_glVertexAttribI4bvEXT;
#define glVertexAttribI4bvEXT cppgl_glVertexAttribI4bvEXT
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4SVEXTPROC)(GLuint index, const GLshort *v);
GLAPI PFNGLVERTEXATTRIBI4SVEXTPROC cppgl_glVertexAttribI4svEXT;
#define glVertexAttribI4svEXT cppgl_glVertexAttribI4svEXT
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4UBVEXTPROC)(GLuint index, const GLubyte *v);
GLAPI PFNGLVERTEXATTRIBI4UBVEXTPROC cppgl_glVertexAttribI4ubvEXT;
#define glVertexAttribI4ubvEXT cppgl_glVertexAttribI4ubvEXT
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4USVEXTPROC)(GLuint index, const GLushort *v);
GLAPI PFNGLVERTEXATTRIBI4USVEXTPROC cppgl_glVertexAttribI4usvEXT;
#define glVertexAttribI4usvEXT cppgl_glVertexAttribI4usvEXT
typedef void (APIENTRYP PFNGLVERTEXATTRIBIPOINTEREXTPROC)(GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer);
GLAPI PFNGLVERTEXATTRIBIPOINTEREXTPROC cppgl_glVertexAttribIPointerEXT;
#define glVertexAttribIPointerEXT cppgl_glVertexAttribIPointerEXT
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBIIVEXTPROC)(GLuint index, GLenum pname, GLint *params);
GLAPI PFNGLGETVERTEXATTRIBIIVEXTPROC cppgl_glGetVertexAttribIivEXT;
#define glGetVertexAttribIivEXT cppgl_glGetVertexAttribIivEXT
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBIUIVEXTPROC)(GLuint index, GLenum pname, GLuint *params);
GLAPI PFNGLGETVERTEXATTRIBIUIVEXTPROC cppgl_glGetVertexAttribIuivEXT;
#define glGetVertexAttribIuivEXT cppgl_glGetVertexAttribIuivEXT
#endif
#ifndef GL_NV_video_capture
#define GL_NV_video_capture 1
GLAPI int CPPGL_GL_NV_video_capture;
typedef void (APIENTRYP PFNGLBEGINVIDEOCAPTURENVPROC)(GLuint video_capture_slot);
GLAPI PFNGLBEGINVIDEOCAPTURENVPROC cppgl_glBeginVideoCaptureNV;
#define glBeginVideoCaptureNV cppgl_glBeginVideoCaptureNV
typedef void (APIENTRYP PFNGLBINDVIDEOCAPTURESTREAMBUFFERNVPROC)(GLuint video_capture_slot, GLuint stream, GLenum frame_region, GLintptrARB offset);
GLAPI PFNGLBINDVIDEOCAPTURESTREAMBUFFERNVPROC cppgl_glBindVideoCaptureStreamBufferNV;
#define glBindVideoCaptureStreamBufferNV cppgl_glBindVideoCaptureStreamBufferNV
typedef void (APIENTRYP PFNGLBINDVIDEOCAPTURESTREAMTEXTURENVPROC)(GLuint video_capture_slot, GLuint stream, GLenum frame_region, GLenum target, GLuint texture);
GLAPI PFNGLBINDVIDEOCAPTURESTREAMTEXTURENVPROC cppgl_glBindVideoCaptureStreamTextureNV;
#define glBindVideoCaptureStreamTextureNV cppgl_glBindVideoCaptureStreamTextureNV
typedef void (APIENTRYP PFNGLENDVIDEOCAPTURENVPROC)(GLuint video_capture_slot);
GLAPI PFNGLENDVIDEOCAPTURENVPROC cppgl_glEndVideoCaptureNV;
#define glEndVideoCaptureNV cppgl_glEndVideoCaptureNV
typedef void (APIENTRYP PFNGLGETVIDEOCAPTUREIVNVPROC)(GLuint video_capture_slot, GLenum pname, GLint *params);
GLAPI PFNGLGETVIDEOCAPTUREIVNVPROC cppgl_glGetVideoCaptureivNV;
#define glGetVideoCaptureivNV cppgl_glGetVideoCaptureivNV
typedef void (APIENTRYP PFNGLGETVIDEOCAPTURESTREAMIVNVPROC)(GLuint video_capture_slot, GLuint stream, GLenum pname, GLint *params);
GLAPI PFNGLGETVIDEOCAPTURESTREAMIVNVPROC cppgl_glGetVideoCaptureStreamivNV;
#define glGetVideoCaptureStreamivNV cppgl_glGetVideoCaptureStreamivNV
typedef void (APIENTRYP PFNGLGETVIDEOCAPTURESTREAMFVNVPROC)(GLuint video_capture_slot, GLuint stream, GLenum pname, GLfloat *params);
GLAPI PFNGLGETVIDEOCAPTURESTREAMFVNVPROC cppgl_glGetVideoCaptureStreamfvNV;
#define glGetVideoCaptureStreamfvNV cppgl_glGetVideoCaptureStreamfvNV
typedef void (APIENTRYP PFNGLGETVIDEOCAPTURESTREAMDVNVPROC)(GLuint video_capture_slot, GLuint stream, GLenum pname, GLdouble *params);
GLAPI PFNGLGETVIDEOCAPTURESTREAMDVNVPROC cppgl_glGetVideoCaptureStreamdvNV;
#define glGetVideoCaptureStreamdvNV cppgl_glGetVideoCaptureStreamdvNV
typedef GLenum (APIENTRYP PFNGLVIDEOCAPTURENVPROC)(GLuint video_capture_slot, GLuint *sequence_num, GLuint64EXT *capture_time);
GLAPI PFNGLVIDEOCAPTURENVPROC cppgl_glVideoCaptureNV;
#define glVideoCaptureNV cppgl_glVideoCaptureNV
typedef void (APIENTRYP PFNGLVIDEOCAPTURESTREAMPARAMETERIVNVPROC)(GLuint video_capture_slot, GLuint stream, GLenum pname, const GLint *params);
GLAPI PFNGLVIDEOCAPTURESTREAMPARAMETERIVNVPROC cppgl_glVideoCaptureStreamParameterivNV;
#define glVideoCaptureStreamParameterivNV cppgl_glVideoCaptureStreamParameterivNV
typedef void (APIENTRYP PFNGLVIDEOCAPTURESTREAMPARAMETERFVNVPROC)(GLuint video_capture_slot, GLuint stream, GLenum pname, const GLfloat *params);
GLAPI PFNGLVIDEOCAPTURESTREAMPARAMETERFVNVPROC cppgl_glVideoCaptureStreamParameterfvNV;
#define glVideoCaptureStreamParameterfvNV cppgl_glVideoCaptureStreamParameterfvNV
typedef void (APIENTRYP PFNGLVIDEOCAPTURESTREAMPARAMETERDVNVPROC)(GLuint video_capture_slot, GLuint stream, GLenum pname, const GLdouble *params);
GLAPI PFNGLVIDEOCAPTURESTREAMPARAMETERDVNVPROC cppgl_glVideoCaptureStreamParameterdvNV;
#define glVideoCaptureStreamParameterdvNV cppgl_glVideoCaptureStreamParameterdvNV
#endif
#ifndef GL_NV_viewport_array2
#define GL_NV_viewport_array2 1
GLAPI int CPPGL_GL_NV_viewport_array2;
#endif
#ifndef GL_NV_viewport_swizzle
#define GL_NV_viewport_swizzle 1
GLAPI int CPPGL_GL_NV_viewport_swizzle;
typedef void (APIENTRYP PFNGLVIEWPORTSWIZZLENVPROC)(GLuint index, GLenum swizzlex, GLenum swizzley, GLenum swizzlez, GLenum swizzlew);
GLAPI PFNGLVIEWPORTSWIZZLENVPROC cppgl_glViewportSwizzleNV;
#define glViewportSwizzleNV cppgl_glViewportSwizzleNV
#endif
#ifndef GL_OES_byte_coordinates
#define GL_OES_byte_coordinates 1
GLAPI int CPPGL_GL_OES_byte_coordinates;
typedef void (APIENTRYP PFNGLMULTITEXCOORD1BOESPROC)(GLenum texture, GLbyte s);
GLAPI PFNGLMULTITEXCOORD1BOESPROC cppgl_glMultiTexCoord1bOES;
#define glMultiTexCoord1bOES cppgl_glMultiTexCoord1bOES
typedef void (APIENTRYP PFNGLMULTITEXCOORD1BVOESPROC)(GLenum texture, const GLbyte *coords);
GLAPI PFNGLMULTITEXCOORD1BVOESPROC cppgl_glMultiTexCoord1bvOES;
#define glMultiTexCoord1bvOES cppgl_glMultiTexCoord1bvOES
typedef void (APIENTRYP PFNGLMULTITEXCOORD2BOESPROC)(GLenum texture, GLbyte s, GLbyte t);
GLAPI PFNGLMULTITEXCOORD2BOESPROC cppgl_glMultiTexCoord2bOES;
#define glMultiTexCoord2bOES cppgl_glMultiTexCoord2bOES
typedef void (APIENTRYP PFNGLMULTITEXCOORD2BVOESPROC)(GLenum texture, const GLbyte *coords);
GLAPI PFNGLMULTITEXCOORD2BVOESPROC cppgl_glMultiTexCoord2bvOES;
#define glMultiTexCoord2bvOES cppgl_glMultiTexCoord2bvOES
typedef void (APIENTRYP PFNGLMULTITEXCOORD3BOESPROC)(GLenum texture, GLbyte s, GLbyte t, GLbyte r);
GLAPI PFNGLMULTITEXCOORD3BOESPROC cppgl_glMultiTexCoord3bOES;
#define glMultiTexCoord3bOES cppgl_glMultiTexCoord3bOES
typedef void (APIENTRYP PFNGLMULTITEXCOORD3BVOESPROC)(GLenum texture, const GLbyte *coords);
GLAPI PFNGLMULTITEXCOORD3BVOESPROC cppgl_glMultiTexCoord3bvOES;
#define glMultiTexCoord3bvOES cppgl_glMultiTexCoord3bvOES
typedef void (APIENTRYP PFNGLMULTITEXCOORD4BOESPROC)(GLenum texture, GLbyte s, GLbyte t, GLbyte r, GLbyte q);
GLAPI PFNGLMULTITEXCOORD4BOESPROC cppgl_glMultiTexCoord4bOES;
#define glMultiTexCoord4bOES cppgl_glMultiTexCoord4bOES
typedef void (APIENTRYP PFNGLMULTITEXCOORD4BVOESPROC)(GLenum texture, const GLbyte *coords);
GLAPI PFNGLMULTITEXCOORD4BVOESPROC cppgl_glMultiTexCoord4bvOES;
#define glMultiTexCoord4bvOES cppgl_glMultiTexCoord4bvOES
typedef void (APIENTRYP PFNGLTEXCOORD1BOESPROC)(GLbyte s);
GLAPI PFNGLTEXCOORD1BOESPROC cppgl_glTexCoord1bOES;
#define glTexCoord1bOES cppgl_glTexCoord1bOES
typedef void (APIENTRYP PFNGLTEXCOORD1BVOESPROC)(const GLbyte *coords);
GLAPI PFNGLTEXCOORD1BVOESPROC cppgl_glTexCoord1bvOES;
#define glTexCoord1bvOES cppgl_glTexCoord1bvOES
typedef void (APIENTRYP PFNGLTEXCOORD2BOESPROC)(GLbyte s, GLbyte t);
GLAPI PFNGLTEXCOORD2BOESPROC cppgl_glTexCoord2bOES;
#define glTexCoord2bOES cppgl_glTexCoord2bOES
typedef void (APIENTRYP PFNGLTEXCOORD2BVOESPROC)(const GLbyte *coords);
GLAPI PFNGLTEXCOORD2BVOESPROC cppgl_glTexCoord2bvOES;
#define glTexCoord2bvOES cppgl_glTexCoord2bvOES
typedef void (APIENTRYP PFNGLTEXCOORD3BOESPROC)(GLbyte s, GLbyte t, GLbyte r);
GLAPI PFNGLTEXCOORD3BOESPROC cppgl_glTexCoord3bOES;
#define glTexCoord3bOES cppgl_glTexCoord3bOES
typedef void (APIENTRYP PFNGLTEXCOORD3BVOESPROC)(const GLbyte *coords);
GLAPI PFNGLTEXCOORD3BVOESPROC cppgl_glTexCoord3bvOES;
#define glTexCoord3bvOES cppgl_glTexCoord3bvOES
typedef void (APIENTRYP PFNGLTEXCOORD4BOESPROC)(GLbyte s, GLbyte t, GLbyte r, GLbyte q);
GLAPI PFNGLTEXCOORD4BOESPROC cppgl_glTexCoord4bOES;
#define glTexCoord4bOES cppgl_glTexCoord4bOES
typedef void (APIENTRYP PFNGLTEXCOORD4BVOESPROC)(const GLbyte *coords);
GLAPI PFNGLTEXCOORD4BVOESPROC cppgl_glTexCoord4bvOES;
#define glTexCoord4bvOES cppgl_glTexCoord4bvOES
typedef void (APIENTRYP PFNGLVERTEX2BOESPROC)(GLbyte x, GLbyte y);
GLAPI PFNGLVERTEX2BOESPROC cppgl_glVertex2bOES;
#define glVertex2bOES cppgl_glVertex2bOES
typedef void (APIENTRYP PFNGLVERTEX2BVOESPROC)(const GLbyte *coords);
GLAPI PFNGLVERTEX2BVOESPROC cppgl_glVertex2bvOES;
#define glVertex2bvOES cppgl_glVertex2bvOES
typedef void (APIENTRYP PFNGLVERTEX3BOESPROC)(GLbyte x, GLbyte y, GLbyte z);
GLAPI PFNGLVERTEX3BOESPROC cppgl_glVertex3bOES;
#define glVertex3bOES cppgl_glVertex3bOES
typedef void (APIENTRYP PFNGLVERTEX3BVOESPROC)(const GLbyte *coords);
GLAPI PFNGLVERTEX3BVOESPROC cppgl_glVertex3bvOES;
#define glVertex3bvOES cppgl_glVertex3bvOES
typedef void (APIENTRYP PFNGLVERTEX4BOESPROC)(GLbyte x, GLbyte y, GLbyte z, GLbyte w);
GLAPI PFNGLVERTEX4BOESPROC cppgl_glVertex4bOES;
#define glVertex4bOES cppgl_glVertex4bOES
typedef void (APIENTRYP PFNGLVERTEX4BVOESPROC)(const GLbyte *coords);
GLAPI PFNGLVERTEX4BVOESPROC cppgl_glVertex4bvOES;
#define glVertex4bvOES cppgl_glVertex4bvOES
#endif
#ifndef GL_OES_compressed_paletted_texture
#define GL_OES_compressed_paletted_texture 1
GLAPI int CPPGL_GL_OES_compressed_paletted_texture;
#endif
#ifndef GL_OES_fixed_point
#define GL_OES_fixed_point 1
GLAPI int CPPGL_GL_OES_fixed_point;
typedef void (APIENTRYP PFNGLALPHAFUNCXOESPROC)(GLenum func, GLfixed ref);
GLAPI PFNGLALPHAFUNCXOESPROC cppgl_glAlphaFuncxOES;
#define glAlphaFuncxOES cppgl_glAlphaFuncxOES
typedef void (APIENTRYP PFNGLCLEARCOLORXOESPROC)(GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha);
GLAPI PFNGLCLEARCOLORXOESPROC cppgl_glClearColorxOES;
#define glClearColorxOES cppgl_glClearColorxOES
typedef void (APIENTRYP PFNGLCLEARDEPTHXOESPROC)(GLfixed depth);
GLAPI PFNGLCLEARDEPTHXOESPROC cppgl_glClearDepthxOES;
#define glClearDepthxOES cppgl_glClearDepthxOES
typedef void (APIENTRYP PFNGLCLIPPLANEXOESPROC)(GLenum plane, const GLfixed *equation);
GLAPI PFNGLCLIPPLANEXOESPROC cppgl_glClipPlanexOES;
#define glClipPlanexOES cppgl_glClipPlanexOES
typedef void (APIENTRYP PFNGLCOLOR4XOESPROC)(GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha);
GLAPI PFNGLCOLOR4XOESPROC cppgl_glColor4xOES;
#define glColor4xOES cppgl_glColor4xOES
typedef void (APIENTRYP PFNGLDEPTHRANGEXOESPROC)(GLfixed n, GLfixed f);
GLAPI PFNGLDEPTHRANGEXOESPROC cppgl_glDepthRangexOES;
#define glDepthRangexOES cppgl_glDepthRangexOES
typedef void (APIENTRYP PFNGLFOGXOESPROC)(GLenum pname, GLfixed param);
GLAPI PFNGLFOGXOESPROC cppgl_glFogxOES;
#define glFogxOES cppgl_glFogxOES
typedef void (APIENTRYP PFNGLFOGXVOESPROC)(GLenum pname, const GLfixed *param);
GLAPI PFNGLFOGXVOESPROC cppgl_glFogxvOES;
#define glFogxvOES cppgl_glFogxvOES
typedef void (APIENTRYP PFNGLFRUSTUMXOESPROC)(GLfixed l, GLfixed r, GLfixed b, GLfixed t, GLfixed n, GLfixed f);
GLAPI PFNGLFRUSTUMXOESPROC cppgl_glFrustumxOES;
#define glFrustumxOES cppgl_glFrustumxOES
typedef void (APIENTRYP PFNGLGETCLIPPLANEXOESPROC)(GLenum plane, GLfixed *equation);
GLAPI PFNGLGETCLIPPLANEXOESPROC cppgl_glGetClipPlanexOES;
#define glGetClipPlanexOES cppgl_glGetClipPlanexOES
typedef void (APIENTRYP PFNGLGETFIXEDVOESPROC)(GLenum pname, GLfixed *params);
GLAPI PFNGLGETFIXEDVOESPROC cppgl_glGetFixedvOES;
#define glGetFixedvOES cppgl_glGetFixedvOES
typedef void (APIENTRYP PFNGLGETTEXENVXVOESPROC)(GLenum target, GLenum pname, GLfixed *params);
GLAPI PFNGLGETTEXENVXVOESPROC cppgl_glGetTexEnvxvOES;
#define glGetTexEnvxvOES cppgl_glGetTexEnvxvOES
typedef void (APIENTRYP PFNGLGETTEXPARAMETERXVOESPROC)(GLenum target, GLenum pname, GLfixed *params);
GLAPI PFNGLGETTEXPARAMETERXVOESPROC cppgl_glGetTexParameterxvOES;
#define glGetTexParameterxvOES cppgl_glGetTexParameterxvOES
typedef void (APIENTRYP PFNGLLIGHTMODELXOESPROC)(GLenum pname, GLfixed param);
GLAPI PFNGLLIGHTMODELXOESPROC cppgl_glLightModelxOES;
#define glLightModelxOES cppgl_glLightModelxOES
typedef void (APIENTRYP PFNGLLIGHTMODELXVOESPROC)(GLenum pname, const GLfixed *param);
GLAPI PFNGLLIGHTMODELXVOESPROC cppgl_glLightModelxvOES;
#define glLightModelxvOES cppgl_glLightModelxvOES
typedef void (APIENTRYP PFNGLLIGHTXOESPROC)(GLenum light, GLenum pname, GLfixed param);
GLAPI PFNGLLIGHTXOESPROC cppgl_glLightxOES;
#define glLightxOES cppgl_glLightxOES
typedef void (APIENTRYP PFNGLLIGHTXVOESPROC)(GLenum light, GLenum pname, const GLfixed *params);
GLAPI PFNGLLIGHTXVOESPROC cppgl_glLightxvOES;
#define glLightxvOES cppgl_glLightxvOES
typedef void (APIENTRYP PFNGLLINEWIDTHXOESPROC)(GLfixed width);
GLAPI PFNGLLINEWIDTHXOESPROC cppgl_glLineWidthxOES;
#define glLineWidthxOES cppgl_glLineWidthxOES
typedef void (APIENTRYP PFNGLLOADMATRIXXOESPROC)(const GLfixed *m);
GLAPI PFNGLLOADMATRIXXOESPROC cppgl_glLoadMatrixxOES;
#define glLoadMatrixxOES cppgl_glLoadMatrixxOES
typedef void (APIENTRYP PFNGLMATERIALXOESPROC)(GLenum face, GLenum pname, GLfixed param);
GLAPI PFNGLMATERIALXOESPROC cppgl_glMaterialxOES;
#define glMaterialxOES cppgl_glMaterialxOES
typedef void (APIENTRYP PFNGLMATERIALXVOESPROC)(GLenum face, GLenum pname, const GLfixed *param);
GLAPI PFNGLMATERIALXVOESPROC cppgl_glMaterialxvOES;
#define glMaterialxvOES cppgl_glMaterialxvOES
typedef void (APIENTRYP PFNGLMULTMATRIXXOESPROC)(const GLfixed *m);
GLAPI PFNGLMULTMATRIXXOESPROC cppgl_glMultMatrixxOES;
#define glMultMatrixxOES cppgl_glMultMatrixxOES
typedef void (APIENTRYP PFNGLMULTITEXCOORD4XOESPROC)(GLenum texture, GLfixed s, GLfixed t, GLfixed r, GLfixed q);
GLAPI PFNGLMULTITEXCOORD4XOESPROC cppgl_glMultiTexCoord4xOES;
#define glMultiTexCoord4xOES cppgl_glMultiTexCoord4xOES
typedef void (APIENTRYP PFNGLNORMAL3XOESPROC)(GLfixed nx, GLfixed ny, GLfixed nz);
GLAPI PFNGLNORMAL3XOESPROC cppgl_glNormal3xOES;
#define glNormal3xOES cppgl_glNormal3xOES
typedef void (APIENTRYP PFNGLORTHOXOESPROC)(GLfixed l, GLfixed r, GLfixed b, GLfixed t, GLfixed n, GLfixed f);
GLAPI PFNGLORTHOXOESPROC cppgl_glOrthoxOES;
#define glOrthoxOES cppgl_glOrthoxOES
typedef void (APIENTRYP PFNGLPOINTPARAMETERXVOESPROC)(GLenum pname, const GLfixed *params);
GLAPI PFNGLPOINTPARAMETERXVOESPROC cppgl_glPointParameterxvOES;
#define glPointParameterxvOES cppgl_glPointParameterxvOES
typedef void (APIENTRYP PFNGLPOINTSIZEXOESPROC)(GLfixed size);
GLAPI PFNGLPOINTSIZEXOESPROC cppgl_glPointSizexOES;
#define glPointSizexOES cppgl_glPointSizexOES
typedef void (APIENTRYP PFNGLPOLYGONOFFSETXOESPROC)(GLfixed factor, GLfixed units);
GLAPI PFNGLPOLYGONOFFSETXOESPROC cppgl_glPolygonOffsetxOES;
#define glPolygonOffsetxOES cppgl_glPolygonOffsetxOES
typedef void (APIENTRYP PFNGLROTATEXOESPROC)(GLfixed angle, GLfixed x, GLfixed y, GLfixed z);
GLAPI PFNGLROTATEXOESPROC cppgl_glRotatexOES;
#define glRotatexOES cppgl_glRotatexOES
typedef void (APIENTRYP PFNGLSCALEXOESPROC)(GLfixed x, GLfixed y, GLfixed z);
GLAPI PFNGLSCALEXOESPROC cppgl_glScalexOES;
#define glScalexOES cppgl_glScalexOES
typedef void (APIENTRYP PFNGLTEXENVXOESPROC)(GLenum target, GLenum pname, GLfixed param);
GLAPI PFNGLTEXENVXOESPROC cppgl_glTexEnvxOES;
#define glTexEnvxOES cppgl_glTexEnvxOES
typedef void (APIENTRYP PFNGLTEXENVXVOESPROC)(GLenum target, GLenum pname, const GLfixed *params);
GLAPI PFNGLTEXENVXVOESPROC cppgl_glTexEnvxvOES;
#define glTexEnvxvOES cppgl_glTexEnvxvOES
typedef void (APIENTRYP PFNGLTEXPARAMETERXOESPROC)(GLenum target, GLenum pname, GLfixed param);
GLAPI PFNGLTEXPARAMETERXOESPROC cppgl_glTexParameterxOES;
#define glTexParameterxOES cppgl_glTexParameterxOES
typedef void (APIENTRYP PFNGLTEXPARAMETERXVOESPROC)(GLenum target, GLenum pname, const GLfixed *params);
GLAPI PFNGLTEXPARAMETERXVOESPROC cppgl_glTexParameterxvOES;
#define glTexParameterxvOES cppgl_glTexParameterxvOES
typedef void (APIENTRYP PFNGLTRANSLATEXOESPROC)(GLfixed x, GLfixed y, GLfixed z);
GLAPI PFNGLTRANSLATEXOESPROC cppgl_glTranslatexOES;
#define glTranslatexOES cppgl_glTranslatexOES
typedef void (APIENTRYP PFNGLGETLIGHTXVOESPROC)(GLenum light, GLenum pname, GLfixed *params);
GLAPI PFNGLGETLIGHTXVOESPROC cppgl_glGetLightxvOES;
#define glGetLightxvOES cppgl_glGetLightxvOES
typedef void (APIENTRYP PFNGLGETMATERIALXVOESPROC)(GLenum face, GLenum pname, GLfixed *params);
GLAPI PFNGLGETMATERIALXVOESPROC cppgl_glGetMaterialxvOES;
#define glGetMaterialxvOES cppgl_glGetMaterialxvOES
typedef void (APIENTRYP PFNGLPOINTPARAMETERXOESPROC)(GLenum pname, GLfixed param);
GLAPI PFNGLPOINTPARAMETERXOESPROC cppgl_glPointParameterxOES;
#define glPointParameterxOES cppgl_glPointParameterxOES
typedef void (APIENTRYP PFNGLSAMPLECOVERAGEXOESPROC)(GLclampx value, GLboolean invert);
GLAPI PFNGLSAMPLECOVERAGEXOESPROC cppgl_glSampleCoveragexOES;
#define glSampleCoveragexOES cppgl_glSampleCoveragexOES
typedef void (APIENTRYP PFNGLACCUMXOESPROC)(GLenum op, GLfixed value);
GLAPI PFNGLACCUMXOESPROC cppgl_glAccumxOES;
#define glAccumxOES cppgl_glAccumxOES
typedef void (APIENTRYP PFNGLBITMAPXOESPROC)(GLsizei width, GLsizei height, GLfixed xorig, GLfixed yorig, GLfixed xmove, GLfixed ymove, const GLubyte *bitmap);
GLAPI PFNGLBITMAPXOESPROC cppgl_glBitmapxOES;
#define glBitmapxOES cppgl_glBitmapxOES
typedef void (APIENTRYP PFNGLBLENDCOLORXOESPROC)(GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha);
GLAPI PFNGLBLENDCOLORXOESPROC cppgl_glBlendColorxOES;
#define glBlendColorxOES cppgl_glBlendColorxOES
typedef void (APIENTRYP PFNGLCLEARACCUMXOESPROC)(GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha);
GLAPI PFNGLCLEARACCUMXOESPROC cppgl_glClearAccumxOES;
#define glClearAccumxOES cppgl_glClearAccumxOES
typedef void (APIENTRYP PFNGLCOLOR3XOESPROC)(GLfixed red, GLfixed green, GLfixed blue);
GLAPI PFNGLCOLOR3XOESPROC cppgl_glColor3xOES;
#define glColor3xOES cppgl_glColor3xOES
typedef void (APIENTRYP PFNGLCOLOR3XVOESPROC)(const GLfixed *components);
GLAPI PFNGLCOLOR3XVOESPROC cppgl_glColor3xvOES;
#define glColor3xvOES cppgl_glColor3xvOES
typedef void (APIENTRYP PFNGLCOLOR4XVOESPROC)(const GLfixed *components);
GLAPI PFNGLCOLOR4XVOESPROC cppgl_glColor4xvOES;
#define glColor4xvOES cppgl_glColor4xvOES
typedef void (APIENTRYP PFNGLCONVOLUTIONPARAMETERXOESPROC)(GLenum target, GLenum pname, GLfixed param);
GLAPI PFNGLCONVOLUTIONPARAMETERXOESPROC cppgl_glConvolutionParameterxOES;
#define glConvolutionParameterxOES cppgl_glConvolutionParameterxOES
typedef void (APIENTRYP PFNGLCONVOLUTIONPARAMETERXVOESPROC)(GLenum target, GLenum pname, const GLfixed *params);
GLAPI PFNGLCONVOLUTIONPARAMETERXVOESPROC cppgl_glConvolutionParameterxvOES;
#define glConvolutionParameterxvOES cppgl_glConvolutionParameterxvOES
typedef void (APIENTRYP PFNGLEVALCOORD1XOESPROC)(GLfixed u);
GLAPI PFNGLEVALCOORD1XOESPROC cppgl_glEvalCoord1xOES;
#define glEvalCoord1xOES cppgl_glEvalCoord1xOES
typedef void (APIENTRYP PFNGLEVALCOORD1XVOESPROC)(const GLfixed *coords);
GLAPI PFNGLEVALCOORD1XVOESPROC cppgl_glEvalCoord1xvOES;
#define glEvalCoord1xvOES cppgl_glEvalCoord1xvOES
typedef void (APIENTRYP PFNGLEVALCOORD2XOESPROC)(GLfixed u, GLfixed v);
GLAPI PFNGLEVALCOORD2XOESPROC cppgl_glEvalCoord2xOES;
#define glEvalCoord2xOES cppgl_glEvalCoord2xOES
typedef void (APIENTRYP PFNGLEVALCOORD2XVOESPROC)(const GLfixed *coords);
GLAPI PFNGLEVALCOORD2XVOESPROC cppgl_glEvalCoord2xvOES;
#define glEvalCoord2xvOES cppgl_glEvalCoord2xvOES
typedef void (APIENTRYP PFNGLFEEDBACKBUFFERXOESPROC)(GLsizei n, GLenum type, const GLfixed *buffer);
GLAPI PFNGLFEEDBACKBUFFERXOESPROC cppgl_glFeedbackBufferxOES;
#define glFeedbackBufferxOES cppgl_glFeedbackBufferxOES
typedef void (APIENTRYP PFNGLGETCONVOLUTIONPARAMETERXVOESPROC)(GLenum target, GLenum pname, GLfixed *params);
GLAPI PFNGLGETCONVOLUTIONPARAMETERXVOESPROC cppgl_glGetConvolutionParameterxvOES;
#define glGetConvolutionParameterxvOES cppgl_glGetConvolutionParameterxvOES
typedef void (APIENTRYP PFNGLGETHISTOGRAMPARAMETERXVOESPROC)(GLenum target, GLenum pname, GLfixed *params);
GLAPI PFNGLGETHISTOGRAMPARAMETERXVOESPROC cppgl_glGetHistogramParameterxvOES;
#define glGetHistogramParameterxvOES cppgl_glGetHistogramParameterxvOES
typedef void (APIENTRYP PFNGLGETLIGHTXOESPROC)(GLenum light, GLenum pname, GLfixed *params);
GLAPI PFNGLGETLIGHTXOESPROC cppgl_glGetLightxOES;
#define glGetLightxOES cppgl_glGetLightxOES
typedef void (APIENTRYP PFNGLGETMAPXVOESPROC)(GLenum target, GLenum query, GLfixed *v);
GLAPI PFNGLGETMAPXVOESPROC cppgl_glGetMapxvOES;
#define glGetMapxvOES cppgl_glGetMapxvOES
typedef void (APIENTRYP PFNGLGETMATERIALXOESPROC)(GLenum face, GLenum pname, GLfixed param);
GLAPI PFNGLGETMATERIALXOESPROC cppgl_glGetMaterialxOES;
#define glGetMaterialxOES cppgl_glGetMaterialxOES
typedef void (APIENTRYP PFNGLGETPIXELMAPXVPROC)(GLenum map, GLint size, GLfixed *values);
GLAPI PFNGLGETPIXELMAPXVPROC cppgl_glGetPixelMapxv;
#define glGetPixelMapxv cppgl_glGetPixelMapxv
typedef void (APIENTRYP PFNGLGETTEXGENXVOESPROC)(GLenum coord, GLenum pname, GLfixed *params);
GLAPI PFNGLGETTEXGENXVOESPROC cppgl_glGetTexGenxvOES;
#define glGetTexGenxvOES cppgl_glGetTexGenxvOES
typedef void (APIENTRYP PFNGLGETTEXLEVELPARAMETERXVOESPROC)(GLenum target, GLint level, GLenum pname, GLfixed *params);
GLAPI PFNGLGETTEXLEVELPARAMETERXVOESPROC cppgl_glGetTexLevelParameterxvOES;
#define glGetTexLevelParameterxvOES cppgl_glGetTexLevelParameterxvOES
typedef void (APIENTRYP PFNGLINDEXXOESPROC)(GLfixed component);
GLAPI PFNGLINDEXXOESPROC cppgl_glIndexxOES;
#define glIndexxOES cppgl_glIndexxOES
typedef void (APIENTRYP PFNGLINDEXXVOESPROC)(const GLfixed *component);
GLAPI PFNGLINDEXXVOESPROC cppgl_glIndexxvOES;
#define glIndexxvOES cppgl_glIndexxvOES
typedef void (APIENTRYP PFNGLLOADTRANSPOSEMATRIXXOESPROC)(const GLfixed *m);
GLAPI PFNGLLOADTRANSPOSEMATRIXXOESPROC cppgl_glLoadTransposeMatrixxOES;
#define glLoadTransposeMatrixxOES cppgl_glLoadTransposeMatrixxOES
typedef void (APIENTRYP PFNGLMAP1XOESPROC)(GLenum target, GLfixed u1, GLfixed u2, GLint stride, GLint order, GLfixed points);
GLAPI PFNGLMAP1XOESPROC cppgl_glMap1xOES;
#define glMap1xOES cppgl_glMap1xOES
typedef void (APIENTRYP PFNGLMAP2XOESPROC)(GLenum target, GLfixed u1, GLfixed u2, GLint ustride, GLint uorder, GLfixed v1, GLfixed v2, GLint vstride, GLint vorder, GLfixed points);
GLAPI PFNGLMAP2XOESPROC cppgl_glMap2xOES;
#define glMap2xOES cppgl_glMap2xOES
typedef void (APIENTRYP PFNGLMAPGRID1XOESPROC)(GLint n, GLfixed u1, GLfixed u2);
GLAPI PFNGLMAPGRID1XOESPROC cppgl_glMapGrid1xOES;
#define glMapGrid1xOES cppgl_glMapGrid1xOES
typedef void (APIENTRYP PFNGLMAPGRID2XOESPROC)(GLint n, GLfixed u1, GLfixed u2, GLfixed v1, GLfixed v2);
GLAPI PFNGLMAPGRID2XOESPROC cppgl_glMapGrid2xOES;
#define glMapGrid2xOES cppgl_glMapGrid2xOES
typedef void (APIENTRYP PFNGLMULTTRANSPOSEMATRIXXOESPROC)(const GLfixed *m);
GLAPI PFNGLMULTTRANSPOSEMATRIXXOESPROC cppgl_glMultTransposeMatrixxOES;
#define glMultTransposeMatrixxOES cppgl_glMultTransposeMatrixxOES
typedef void (APIENTRYP PFNGLMULTITEXCOORD1XOESPROC)(GLenum texture, GLfixed s);
GLAPI PFNGLMULTITEXCOORD1XOESPROC cppgl_glMultiTexCoord1xOES;
#define glMultiTexCoord1xOES cppgl_glMultiTexCoord1xOES
typedef void (APIENTRYP PFNGLMULTITEXCOORD1XVOESPROC)(GLenum texture, const GLfixed *coords);
GLAPI PFNGLMULTITEXCOORD1XVOESPROC cppgl_glMultiTexCoord1xvOES;
#define glMultiTexCoord1xvOES cppgl_glMultiTexCoord1xvOES
typedef void (APIENTRYP PFNGLMULTITEXCOORD2XOESPROC)(GLenum texture, GLfixed s, GLfixed t);
GLAPI PFNGLMULTITEXCOORD2XOESPROC cppgl_glMultiTexCoord2xOES;
#define glMultiTexCoord2xOES cppgl_glMultiTexCoord2xOES
typedef void (APIENTRYP PFNGLMULTITEXCOORD2XVOESPROC)(GLenum texture, const GLfixed *coords);
GLAPI PFNGLMULTITEXCOORD2XVOESPROC cppgl_glMultiTexCoord2xvOES;
#define glMultiTexCoord2xvOES cppgl_glMultiTexCoord2xvOES
typedef void (APIENTRYP PFNGLMULTITEXCOORD3XOESPROC)(GLenum texture, GLfixed s, GLfixed t, GLfixed r);
GLAPI PFNGLMULTITEXCOORD3XOESPROC cppgl_glMultiTexCoord3xOES;
#define glMultiTexCoord3xOES cppgl_glMultiTexCoord3xOES
typedef void (APIENTRYP PFNGLMULTITEXCOORD3XVOESPROC)(GLenum texture, const GLfixed *coords);
GLAPI PFNGLMULTITEXCOORD3XVOESPROC cppgl_glMultiTexCoord3xvOES;
#define glMultiTexCoord3xvOES cppgl_glMultiTexCoord3xvOES
typedef void (APIENTRYP PFNGLMULTITEXCOORD4XVOESPROC)(GLenum texture, const GLfixed *coords);
GLAPI PFNGLMULTITEXCOORD4XVOESPROC cppgl_glMultiTexCoord4xvOES;
#define glMultiTexCoord4xvOES cppgl_glMultiTexCoord4xvOES
typedef void (APIENTRYP PFNGLNORMAL3XVOESPROC)(const GLfixed *coords);
GLAPI PFNGLNORMAL3XVOESPROC cppgl_glNormal3xvOES;
#define glNormal3xvOES cppgl_glNormal3xvOES
typedef void (APIENTRYP PFNGLPASSTHROUGHXOESPROC)(GLfixed token);
GLAPI PFNGLPASSTHROUGHXOESPROC cppgl_glPassThroughxOES;
#define glPassThroughxOES cppgl_glPassThroughxOES
typedef void (APIENTRYP PFNGLPIXELMAPXPROC)(GLenum map, GLint size, const GLfixed *values);
GLAPI PFNGLPIXELMAPXPROC cppgl_glPixelMapx;
#define glPixelMapx cppgl_glPixelMapx
typedef void (APIENTRYP PFNGLPIXELSTOREXPROC)(GLenum pname, GLfixed param);
GLAPI PFNGLPIXELSTOREXPROC cppgl_glPixelStorex;
#define glPixelStorex cppgl_glPixelStorex
typedef void (APIENTRYP PFNGLPIXELTRANSFERXOESPROC)(GLenum pname, GLfixed param);
GLAPI PFNGLPIXELTRANSFERXOESPROC cppgl_glPixelTransferxOES;
#define glPixelTransferxOES cppgl_glPixelTransferxOES
typedef void (APIENTRYP PFNGLPIXELZOOMXOESPROC)(GLfixed xfactor, GLfixed yfactor);
GLAPI PFNGLPIXELZOOMXOESPROC cppgl_glPixelZoomxOES;
#define glPixelZoomxOES cppgl_glPixelZoomxOES
typedef void (APIENTRYP PFNGLPRIORITIZETEXTURESXOESPROC)(GLsizei n, const GLuint *textures, const GLfixed *priorities);
GLAPI PFNGLPRIORITIZETEXTURESXOESPROC cppgl_glPrioritizeTexturesxOES;
#define glPrioritizeTexturesxOES cppgl_glPrioritizeTexturesxOES
typedef void (APIENTRYP PFNGLRASTERPOS2XOESPROC)(GLfixed x, GLfixed y);
GLAPI PFNGLRASTERPOS2XOESPROC cppgl_glRasterPos2xOES;
#define glRasterPos2xOES cppgl_glRasterPos2xOES
typedef void (APIENTRYP PFNGLRASTERPOS2XVOESPROC)(const GLfixed *coords);
GLAPI PFNGLRASTERPOS2XVOESPROC cppgl_glRasterPos2xvOES;
#define glRasterPos2xvOES cppgl_glRasterPos2xvOES
typedef void (APIENTRYP PFNGLRASTERPOS3XOESPROC)(GLfixed x, GLfixed y, GLfixed z);
GLAPI PFNGLRASTERPOS3XOESPROC cppgl_glRasterPos3xOES;
#define glRasterPos3xOES cppgl_glRasterPos3xOES
typedef void (APIENTRYP PFNGLRASTERPOS3XVOESPROC)(const GLfixed *coords);
GLAPI PFNGLRASTERPOS3XVOESPROC cppgl_glRasterPos3xvOES;
#define glRasterPos3xvOES cppgl_glRasterPos3xvOES
typedef void (APIENTRYP PFNGLRASTERPOS4XOESPROC)(GLfixed x, GLfixed y, GLfixed z, GLfixed w);
GLAPI PFNGLRASTERPOS4XOESPROC cppgl_glRasterPos4xOES;
#define glRasterPos4xOES cppgl_glRasterPos4xOES
typedef void (APIENTRYP PFNGLRASTERPOS4XVOESPROC)(const GLfixed *coords);
GLAPI PFNGLRASTERPOS4XVOESPROC cppgl_glRasterPos4xvOES;
#define glRasterPos4xvOES cppgl_glRasterPos4xvOES
typedef void (APIENTRYP PFNGLRECTXOESPROC)(GLfixed x1, GLfixed y1, GLfixed x2, GLfixed y2);
GLAPI PFNGLRECTXOESPROC cppgl_glRectxOES;
#define glRectxOES cppgl_glRectxOES
typedef void (APIENTRYP PFNGLRECTXVOESPROC)(const GLfixed *v1, const GLfixed *v2);
GLAPI PFNGLRECTXVOESPROC cppgl_glRectxvOES;
#define glRectxvOES cppgl_glRectxvOES
typedef void (APIENTRYP PFNGLTEXCOORD1XOESPROC)(GLfixed s);
GLAPI PFNGLTEXCOORD1XOESPROC cppgl_glTexCoord1xOES;
#define glTexCoord1xOES cppgl_glTexCoord1xOES
typedef void (APIENTRYP PFNGLTEXCOORD1XVOESPROC)(const GLfixed *coords);
GLAPI PFNGLTEXCOORD1XVOESPROC cppgl_glTexCoord1xvOES;
#define glTexCoord1xvOES cppgl_glTexCoord1xvOES
typedef void (APIENTRYP PFNGLTEXCOORD2XOESPROC)(GLfixed s, GLfixed t);
GLAPI PFNGLTEXCOORD2XOESPROC cppgl_glTexCoord2xOES;
#define glTexCoord2xOES cppgl_glTexCoord2xOES
typedef void (APIENTRYP PFNGLTEXCOORD2XVOESPROC)(const GLfixed *coords);
GLAPI PFNGLTEXCOORD2XVOESPROC cppgl_glTexCoord2xvOES;
#define glTexCoord2xvOES cppgl_glTexCoord2xvOES
typedef void (APIENTRYP PFNGLTEXCOORD3XOESPROC)(GLfixed s, GLfixed t, GLfixed r);
GLAPI PFNGLTEXCOORD3XOESPROC cppgl_glTexCoord3xOES;
#define glTexCoord3xOES cppgl_glTexCoord3xOES
typedef void (APIENTRYP PFNGLTEXCOORD3XVOESPROC)(const GLfixed *coords);
GLAPI PFNGLTEXCOORD3XVOESPROC cppgl_glTexCoord3xvOES;
#define glTexCoord3xvOES cppgl_glTexCoord3xvOES
typedef void (APIENTRYP PFNGLTEXCOORD4XOESPROC)(GLfixed s, GLfixed t, GLfixed r, GLfixed q);
GLAPI PFNGLTEXCOORD4XOESPROC cppgl_glTexCoord4xOES;
#define glTexCoord4xOES cppgl_glTexCoord4xOES
typedef void (APIENTRYP PFNGLTEXCOORD4XVOESPROC)(const GLfixed *coords);
GLAPI PFNGLTEXCOORD4XVOESPROC cppgl_glTexCoord4xvOES;
#define glTexCoord4xvOES cppgl_glTexCoord4xvOES
typedef void (APIENTRYP PFNGLTEXGENXOESPROC)(GLenum coord, GLenum pname, GLfixed param);
GLAPI PFNGLTEXGENXOESPROC cppgl_glTexGenxOES;
#define glTexGenxOES cppgl_glTexGenxOES
typedef void (APIENTRYP PFNGLTEXGENXVOESPROC)(GLenum coord, GLenum pname, const GLfixed *params);
GLAPI PFNGLTEXGENXVOESPROC cppgl_glTexGenxvOES;
#define glTexGenxvOES cppgl_glTexGenxvOES
typedef void (APIENTRYP PFNGLVERTEX2XOESPROC)(GLfixed x);
GLAPI PFNGLVERTEX2XOESPROC cppgl_glVertex2xOES;
#define glVertex2xOES cppgl_glVertex2xOES
typedef void (APIENTRYP PFNGLVERTEX2XVOESPROC)(const GLfixed *coords);
GLAPI PFNGLVERTEX2XVOESPROC cppgl_glVertex2xvOES;
#define glVertex2xvOES cppgl_glVertex2xvOES
typedef void (APIENTRYP PFNGLVERTEX3XOESPROC)(GLfixed x, GLfixed y);
GLAPI PFNGLVERTEX3XOESPROC cppgl_glVertex3xOES;
#define glVertex3xOES cppgl_glVertex3xOES
typedef void (APIENTRYP PFNGLVERTEX3XVOESPROC)(const GLfixed *coords);
GLAPI PFNGLVERTEX3XVOESPROC cppgl_glVertex3xvOES;
#define glVertex3xvOES cppgl_glVertex3xvOES
typedef void (APIENTRYP PFNGLVERTEX4XOESPROC)(GLfixed x, GLfixed y, GLfixed z);
GLAPI PFNGLVERTEX4XOESPROC cppgl_glVertex4xOES;
#define glVertex4xOES cppgl_glVertex4xOES
typedef void (APIENTRYP PFNGLVERTEX4XVOESPROC)(const GLfixed *coords);
GLAPI PFNGLVERTEX4XVOESPROC cppgl_glVertex4xvOES;
#define glVertex4xvOES cppgl_glVertex4xvOES
#endif
#ifndef GL_OES_query_matrix
#define GL_OES_query_matrix 1
GLAPI int CPPGL_GL_OES_query_matrix;
typedef GLbitfield (APIENTRYP PFNGLQUERYMATRIXXOESPROC)(GLfixed *mantissa, GLint *exponent);
GLAPI PFNGLQUERYMATRIXXOESPROC cppgl_glQueryMatrixxOES;
#define glQueryMatrixxOES cppgl_glQueryMatrixxOES
#endif
#ifndef GL_OES_read_format
#define GL_OES_read_format 1
GLAPI int CPPGL_GL_OES_read_format;
#endif
#ifndef GL_OES_single_precision
#define GL_OES_single_precision 1
GLAPI int CPPGL_GL_OES_single_precision;
typedef void (APIENTRYP PFNGLCLEARDEPTHFOESPROC)(GLclampf depth);
GLAPI PFNGLCLEARDEPTHFOESPROC cppgl_glClearDepthfOES;
#define glClearDepthfOES cppgl_glClearDepthfOES
typedef void (APIENTRYP PFNGLCLIPPLANEFOESPROC)(GLenum plane, const GLfloat *equation);
GLAPI PFNGLCLIPPLANEFOESPROC cppgl_glClipPlanefOES;
#define glClipPlanefOES cppgl_glClipPlanefOES
typedef void (APIENTRYP PFNGLDEPTHRANGEFOESPROC)(GLclampf n, GLclampf f);
GLAPI PFNGLDEPTHRANGEFOESPROC cppgl_glDepthRangefOES;
#define glDepthRangefOES cppgl_glDepthRangefOES
typedef void (APIENTRYP PFNGLFRUSTUMFOESPROC)(GLfloat l, GLfloat r, GLfloat b, GLfloat t, GLfloat n, GLfloat f);
GLAPI PFNGLFRUSTUMFOESPROC cppgl_glFrustumfOES;
#define glFrustumfOES cppgl_glFrustumfOES
typedef void (APIENTRYP PFNGLGETCLIPPLANEFOESPROC)(GLenum plane, GLfloat *equation);
GLAPI PFNGLGETCLIPPLANEFOESPROC cppgl_glGetClipPlanefOES;
#define glGetClipPlanefOES cppgl_glGetClipPlanefOES
typedef void (APIENTRYP PFNGLORTHOFOESPROC)(GLfloat l, GLfloat r, GLfloat b, GLfloat t, GLfloat n, GLfloat f);
GLAPI PFNGLORTHOFOESPROC cppgl_glOrthofOES;
#define glOrthofOES cppgl_glOrthofOES
#endif
#ifndef GL_OML_interlace
#define GL_OML_interlace 1
GLAPI int CPPGL_GL_OML_interlace;
#endif
#ifndef GL_OML_resample
#define GL_OML_resample 1
GLAPI int CPPGL_GL_OML_resample;
#endif
#ifndef GL_OML_subsample
#define GL_OML_subsample 1
GLAPI int CPPGL_GL_OML_subsample;
#endif
#ifndef GL_OVR_multiview
#define GL_OVR_multiview 1
GLAPI int CPPGL_GL_OVR_multiview;
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTUREMULTIVIEWOVRPROC)(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint baseViewIndex, GLsizei numViews);
GLAPI PFNGLFRAMEBUFFERTEXTUREMULTIVIEWOVRPROC cppgl_glFramebufferTextureMultiviewOVR;
#define glFramebufferTextureMultiviewOVR cppgl_glFramebufferTextureMultiviewOVR
#endif
#ifndef GL_OVR_multiview2
#define GL_OVR_multiview2 1
GLAPI int CPPGL_GL_OVR_multiview2;
#endif
#ifndef GL_PGI_misc_hints
#define GL_PGI_misc_hints 1
GLAPI int CPPGL_GL_PGI_misc_hints;
typedef void (APIENTRYP PFNGLHINTPGIPROC)(GLenum target, GLint mode);
GLAPI PFNGLHINTPGIPROC cppgl_glHintPGI;
#define glHintPGI cppgl_glHintPGI
#endif
#ifndef GL_PGI_vertex_hints
#define GL_PGI_vertex_hints 1
GLAPI int CPPGL_GL_PGI_vertex_hints;
#endif
#ifndef GL_REND_screen_coordinates
#define GL_REND_screen_coordinates 1
GLAPI int CPPGL_GL_REND_screen_coordinates;
#endif
#ifndef GL_S3_s3tc
#define GL_S3_s3tc 1
GLAPI int CPPGL_GL_S3_s3tc;
#endif
#ifndef GL_SGIS_detail_texture
#define GL_SGIS_detail_texture 1
GLAPI int CPPGL_GL_SGIS_detail_texture;
typedef void (APIENTRYP PFNGLDETAILTEXFUNCSGISPROC)(GLenum target, GLsizei n, const GLfloat *points);
GLAPI PFNGLDETAILTEXFUNCSGISPROC cppgl_glDetailTexFuncSGIS;
#define glDetailTexFuncSGIS cppgl_glDetailTexFuncSGIS
typedef void (APIENTRYP PFNGLGETDETAILTEXFUNCSGISPROC)(GLenum target, GLfloat *points);
GLAPI PFNGLGETDETAILTEXFUNCSGISPROC cppgl_glGetDetailTexFuncSGIS;
#define glGetDetailTexFuncSGIS cppgl_glGetDetailTexFuncSGIS
#endif
#ifndef GL_SGIS_fog_function
#define GL_SGIS_fog_function 1
GLAPI int CPPGL_GL_SGIS_fog_function;
typedef void (APIENTRYP PFNGLFOGFUNCSGISPROC)(GLsizei n, const GLfloat *points);
GLAPI PFNGLFOGFUNCSGISPROC cppgl_glFogFuncSGIS;
#define glFogFuncSGIS cppgl_glFogFuncSGIS
typedef void (APIENTRYP PFNGLGETFOGFUNCSGISPROC)(GLfloat *points);
GLAPI PFNGLGETFOGFUNCSGISPROC cppgl_glGetFogFuncSGIS;
#define glGetFogFuncSGIS cppgl_glGetFogFuncSGIS
#endif
#ifndef GL_SGIS_generate_mipmap
#define GL_SGIS_generate_mipmap 1
GLAPI int CPPGL_GL_SGIS_generate_mipmap;
#endif
#ifndef GL_SGIS_multisample
#define GL_SGIS_multisample 1
GLAPI int CPPGL_GL_SGIS_multisample;
typedef void (APIENTRYP PFNGLSAMPLEMASKSGISPROC)(GLclampf value, GLboolean invert);
GLAPI PFNGLSAMPLEMASKSGISPROC cppgl_glSampleMaskSGIS;
#define glSampleMaskSGIS cppgl_glSampleMaskSGIS
typedef void (APIENTRYP PFNGLSAMPLEPATTERNSGISPROC)(GLenum pattern);
GLAPI PFNGLSAMPLEPATTERNSGISPROC cppgl_glSamplePatternSGIS;
#define glSamplePatternSGIS cppgl_glSamplePatternSGIS
#endif
#ifndef GL_SGIS_pixel_texture
#define GL_SGIS_pixel_texture 1
GLAPI int CPPGL_GL_SGIS_pixel_texture;
typedef void (APIENTRYP PFNGLPIXELTEXGENPARAMETERISGISPROC)(GLenum pname, GLint param);
GLAPI PFNGLPIXELTEXGENPARAMETERISGISPROC cppgl_glPixelTexGenParameteriSGIS;
#define glPixelTexGenParameteriSGIS cppgl_glPixelTexGenParameteriSGIS
typedef void (APIENTRYP PFNGLPIXELTEXGENPARAMETERIVSGISPROC)(GLenum pname, const GLint *params);
GLAPI PFNGLPIXELTEXGENPARAMETERIVSGISPROC cppgl_glPixelTexGenParameterivSGIS;
#define glPixelTexGenParameterivSGIS cppgl_glPixelTexGenParameterivSGIS
typedef void (APIENTRYP PFNGLPIXELTEXGENPARAMETERFSGISPROC)(GLenum pname, GLfloat param);
GLAPI PFNGLPIXELTEXGENPARAMETERFSGISPROC cppgl_glPixelTexGenParameterfSGIS;
#define glPixelTexGenParameterfSGIS cppgl_glPixelTexGenParameterfSGIS
typedef void (APIENTRYP PFNGLPIXELTEXGENPARAMETERFVSGISPROC)(GLenum pname, const GLfloat *params);
GLAPI PFNGLPIXELTEXGENPARAMETERFVSGISPROC cppgl_glPixelTexGenParameterfvSGIS;
#define glPixelTexGenParameterfvSGIS cppgl_glPixelTexGenParameterfvSGIS
typedef void (APIENTRYP PFNGLGETPIXELTEXGENPARAMETERIVSGISPROC)(GLenum pname, GLint *params);
GLAPI PFNGLGETPIXELTEXGENPARAMETERIVSGISPROC cppgl_glGetPixelTexGenParameterivSGIS;
#define glGetPixelTexGenParameterivSGIS cppgl_glGetPixelTexGenParameterivSGIS
typedef void (APIENTRYP PFNGLGETPIXELTEXGENPARAMETERFVSGISPROC)(GLenum pname, GLfloat *params);
GLAPI PFNGLGETPIXELTEXGENPARAMETERFVSGISPROC cppgl_glGetPixelTexGenParameterfvSGIS;
#define glGetPixelTexGenParameterfvSGIS cppgl_glGetPixelTexGenParameterfvSGIS
#endif
#ifndef GL_SGIS_point_line_texgen
#define GL_SGIS_point_line_texgen 1
GLAPI int CPPGL_GL_SGIS_point_line_texgen;
#endif
#ifndef GL_SGIS_point_parameters
#define GL_SGIS_point_parameters 1
GLAPI int CPPGL_GL_SGIS_point_parameters;
typedef void (APIENTRYP PFNGLPOINTPARAMETERFSGISPROC)(GLenum pname, GLfloat param);
GLAPI PFNGLPOINTPARAMETERFSGISPROC cppgl_glPointParameterfSGIS;
#define glPointParameterfSGIS cppgl_glPointParameterfSGIS
typedef void (APIENTRYP PFNGLPOINTPARAMETERFVSGISPROC)(GLenum pname, const GLfloat *params);
GLAPI PFNGLPOINTPARAMETERFVSGISPROC cppgl_glPointParameterfvSGIS;
#define glPointParameterfvSGIS cppgl_glPointParameterfvSGIS
#endif
#ifndef GL_SGIS_sharpen_texture
#define GL_SGIS_sharpen_texture 1
GLAPI int CPPGL_GL_SGIS_sharpen_texture;
typedef void (APIENTRYP PFNGLSHARPENTEXFUNCSGISPROC)(GLenum target, GLsizei n, const GLfloat *points);
GLAPI PFNGLSHARPENTEXFUNCSGISPROC cppgl_glSharpenTexFuncSGIS;
#define glSharpenTexFuncSGIS cppgl_glSharpenTexFuncSGIS
typedef void (APIENTRYP PFNGLGETSHARPENTEXFUNCSGISPROC)(GLenum target, GLfloat *points);
GLAPI PFNGLGETSHARPENTEXFUNCSGISPROC cppgl_glGetSharpenTexFuncSGIS;
#define glGetSharpenTexFuncSGIS cppgl_glGetSharpenTexFuncSGIS
#endif
#ifndef GL_SGIS_texture4D
#define GL_SGIS_texture4D 1
GLAPI int CPPGL_GL_SGIS_texture4D;
typedef void (APIENTRYP PFNGLTEXIMAGE4DSGISPROC)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLsizei size4d, GLint border, GLenum format, GLenum type, const void *pixels);
GLAPI PFNGLTEXIMAGE4DSGISPROC cppgl_glTexImage4DSGIS;
#define glTexImage4DSGIS cppgl_glTexImage4DSGIS
typedef void (APIENTRYP PFNGLTEXSUBIMAGE4DSGISPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint woffset, GLsizei width, GLsizei height, GLsizei depth, GLsizei size4d, GLenum format, GLenum type, const void *pixels);
GLAPI PFNGLTEXSUBIMAGE4DSGISPROC cppgl_glTexSubImage4DSGIS;
#define glTexSubImage4DSGIS cppgl_glTexSubImage4DSGIS
#endif
#ifndef GL_SGIS_texture_border_clamp
#define GL_SGIS_texture_border_clamp 1
GLAPI int CPPGL_GL_SGIS_texture_border_clamp;
#endif
#ifndef GL_SGIS_texture_color_mask
#define GL_SGIS_texture_color_mask 1
GLAPI int CPPGL_GL_SGIS_texture_color_mask;
typedef void (APIENTRYP PFNGLTEXTURECOLORMASKSGISPROC)(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
GLAPI PFNGLTEXTURECOLORMASKSGISPROC cppgl_glTextureColorMaskSGIS;
#define glTextureColorMaskSGIS cppgl_glTextureColorMaskSGIS
#endif
#ifndef GL_SGIS_texture_edge_clamp
#define GL_SGIS_texture_edge_clamp 1
GLAPI int CPPGL_GL_SGIS_texture_edge_clamp;
#endif
#ifndef GL_SGIS_texture_filter4
#define GL_SGIS_texture_filter4 1
GLAPI int CPPGL_GL_SGIS_texture_filter4;
typedef void (APIENTRYP PFNGLGETTEXFILTERFUNCSGISPROC)(GLenum target, GLenum filter, GLfloat *weights);
GLAPI PFNGLGETTEXFILTERFUNCSGISPROC cppgl_glGetTexFilterFuncSGIS;
#define glGetTexFilterFuncSGIS cppgl_glGetTexFilterFuncSGIS
typedef void (APIENTRYP PFNGLTEXFILTERFUNCSGISPROC)(GLenum target, GLenum filter, GLsizei n, const GLfloat *weights);
GLAPI PFNGLTEXFILTERFUNCSGISPROC cppgl_glTexFilterFuncSGIS;
#define glTexFilterFuncSGIS cppgl_glTexFilterFuncSGIS
#endif
#ifndef GL_SGIS_texture_lod
#define GL_SGIS_texture_lod 1
GLAPI int CPPGL_GL_SGIS_texture_lod;
#endif
#ifndef GL_SGIS_texture_select
#define GL_SGIS_texture_select 1
GLAPI int CPPGL_GL_SGIS_texture_select;
#endif
#ifndef GL_SGIX_async
#define GL_SGIX_async 1
GLAPI int CPPGL_GL_SGIX_async;
typedef void (APIENTRYP PFNGLASYNCMARKERSGIXPROC)(GLuint marker);
GLAPI PFNGLASYNCMARKERSGIXPROC cppgl_glAsyncMarkerSGIX;
#define glAsyncMarkerSGIX cppgl_glAsyncMarkerSGIX
typedef GLint (APIENTRYP PFNGLFINISHASYNCSGIXPROC)(GLuint *markerp);
GLAPI PFNGLFINISHASYNCSGIXPROC cppgl_glFinishAsyncSGIX;
#define glFinishAsyncSGIX cppgl_glFinishAsyncSGIX
typedef GLint (APIENTRYP PFNGLPOLLASYNCSGIXPROC)(GLuint *markerp);
GLAPI PFNGLPOLLASYNCSGIXPROC cppgl_glPollAsyncSGIX;
#define glPollAsyncSGIX cppgl_glPollAsyncSGIX
typedef GLuint (APIENTRYP PFNGLGENASYNCMARKERSSGIXPROC)(GLsizei range);
GLAPI PFNGLGENASYNCMARKERSSGIXPROC cppgl_glGenAsyncMarkersSGIX;
#define glGenAsyncMarkersSGIX cppgl_glGenAsyncMarkersSGIX
typedef void (APIENTRYP PFNGLDELETEASYNCMARKERSSGIXPROC)(GLuint marker, GLsizei range);
GLAPI PFNGLDELETEASYNCMARKERSSGIXPROC cppgl_glDeleteAsyncMarkersSGIX;
#define glDeleteAsyncMarkersSGIX cppgl_glDeleteAsyncMarkersSGIX
typedef GLboolean (APIENTRYP PFNGLISASYNCMARKERSGIXPROC)(GLuint marker);
GLAPI PFNGLISASYNCMARKERSGIXPROC cppgl_glIsAsyncMarkerSGIX;
#define glIsAsyncMarkerSGIX cppgl_glIsAsyncMarkerSGIX
#endif
#ifndef GL_SGIX_async_histogram
#define GL_SGIX_async_histogram 1
GLAPI int CPPGL_GL_SGIX_async_histogram;
#endif
#ifndef GL_SGIX_async_pixel
#define GL_SGIX_async_pixel 1
GLAPI int CPPGL_GL_SGIX_async_pixel;
#endif
#ifndef GL_SGIX_blend_alpha_minmax
#define GL_SGIX_blend_alpha_minmax 1
GLAPI int CPPGL_GL_SGIX_blend_alpha_minmax;
#endif
#ifndef GL_SGIX_calligraphic_fragment
#define GL_SGIX_calligraphic_fragment 1
GLAPI int CPPGL_GL_SGIX_calligraphic_fragment;
#endif
#ifndef GL_SGIX_clipmap
#define GL_SGIX_clipmap 1
GLAPI int CPPGL_GL_SGIX_clipmap;
#endif
#ifndef GL_SGIX_convolution_accuracy
#define GL_SGIX_convolution_accuracy 1
GLAPI int CPPGL_GL_SGIX_convolution_accuracy;
#endif
#ifndef GL_SGIX_depth_pass_instrument
#define GL_SGIX_depth_pass_instrument 1
GLAPI int CPPGL_GL_SGIX_depth_pass_instrument;
#endif
#ifndef GL_SGIX_depth_texture
#define GL_SGIX_depth_texture 1
GLAPI int CPPGL_GL_SGIX_depth_texture;
#endif
#ifndef GL_SGIX_flush_raster
#define GL_SGIX_flush_raster 1
GLAPI int CPPGL_GL_SGIX_flush_raster;
typedef void (APIENTRYP PFNGLFLUSHRASTERSGIXPROC)();
GLAPI PFNGLFLUSHRASTERSGIXPROC cppgl_glFlushRasterSGIX;
#define glFlushRasterSGIX cppgl_glFlushRasterSGIX
#endif
#ifndef GL_SGIX_fog_offset
#define GL_SGIX_fog_offset 1
GLAPI int CPPGL_GL_SGIX_fog_offset;
#endif
#ifndef GL_SGIX_fragment_lighting
#define GL_SGIX_fragment_lighting 1
GLAPI int CPPGL_GL_SGIX_fragment_lighting;
typedef void (APIENTRYP PFNGLFRAGMENTCOLORMATERIALSGIXPROC)(GLenum face, GLenum mode);
GLAPI PFNGLFRAGMENTCOLORMATERIALSGIXPROC cppgl_glFragmentColorMaterialSGIX;
#define glFragmentColorMaterialSGIX cppgl_glFragmentColorMaterialSGIX
typedef void (APIENTRYP PFNGLFRAGMENTLIGHTFSGIXPROC)(GLenum light, GLenum pname, GLfloat param);
GLAPI PFNGLFRAGMENTLIGHTFSGIXPROC cppgl_glFragmentLightfSGIX;
#define glFragmentLightfSGIX cppgl_glFragmentLightfSGIX
typedef void (APIENTRYP PFNGLFRAGMENTLIGHTFVSGIXPROC)(GLenum light, GLenum pname, const GLfloat *params);
GLAPI PFNGLFRAGMENTLIGHTFVSGIXPROC cppgl_glFragmentLightfvSGIX;
#define glFragmentLightfvSGIX cppgl_glFragmentLightfvSGIX
typedef void (APIENTRYP PFNGLFRAGMENTLIGHTISGIXPROC)(GLenum light, GLenum pname, GLint param);
GLAPI PFNGLFRAGMENTLIGHTISGIXPROC cppgl_glFragmentLightiSGIX;
#define glFragmentLightiSGIX cppgl_glFragmentLightiSGIX
typedef void (APIENTRYP PFNGLFRAGMENTLIGHTIVSGIXPROC)(GLenum light, GLenum pname, const GLint *params);
GLAPI PFNGLFRAGMENTLIGHTIVSGIXPROC cppgl_glFragmentLightivSGIX;
#define glFragmentLightivSGIX cppgl_glFragmentLightivSGIX
typedef void (APIENTRYP PFNGLFRAGMENTLIGHTMODELFSGIXPROC)(GLenum pname, GLfloat param);
GLAPI PFNGLFRAGMENTLIGHTMODELFSGIXPROC cppgl_glFragmentLightModelfSGIX;
#define glFragmentLightModelfSGIX cppgl_glFragmentLightModelfSGIX
typedef void (APIENTRYP PFNGLFRAGMENTLIGHTMODELFVSGIXPROC)(GLenum pname, const GLfloat *params);
GLAPI PFNGLFRAGMENTLIGHTMODELFVSGIXPROC cppgl_glFragmentLightModelfvSGIX;
#define glFragmentLightModelfvSGIX cppgl_glFragmentLightModelfvSGIX
typedef void (APIENTRYP PFNGLFRAGMENTLIGHTMODELISGIXPROC)(GLenum pname, GLint param);
GLAPI PFNGLFRAGMENTLIGHTMODELISGIXPROC cppgl_glFragmentLightModeliSGIX;
#define glFragmentLightModeliSGIX cppgl_glFragmentLightModeliSGIX
typedef void (APIENTRYP PFNGLFRAGMENTLIGHTMODELIVSGIXPROC)(GLenum pname, const GLint *params);
GLAPI PFNGLFRAGMENTLIGHTMODELIVSGIXPROC cppgl_glFragmentLightModelivSGIX;
#define glFragmentLightModelivSGIX cppgl_glFragmentLightModelivSGIX
typedef void (APIENTRYP PFNGLFRAGMENTMATERIALFSGIXPROC)(GLenum face, GLenum pname, GLfloat param);
GLAPI PFNGLFRAGMENTMATERIALFSGIXPROC cppgl_glFragmentMaterialfSGIX;
#define glFragmentMaterialfSGIX cppgl_glFragmentMaterialfSGIX
typedef void (APIENTRYP PFNGLFRAGMENTMATERIALFVSGIXPROC)(GLenum face, GLenum pname, const GLfloat *params);
GLAPI PFNGLFRAGMENTMATERIALFVSGIXPROC cppgl_glFragmentMaterialfvSGIX;
#define glFragmentMaterialfvSGIX cppgl_glFragmentMaterialfvSGIX
typedef void (APIENTRYP PFNGLFRAGMENTMATERIALISGIXPROC)(GLenum face, GLenum pname, GLint param);
GLAPI PFNGLFRAGMENTMATERIALISGIXPROC cppgl_glFragmentMaterialiSGIX;
#define glFragmentMaterialiSGIX cppgl_glFragmentMaterialiSGIX
typedef void (APIENTRYP PFNGLFRAGMENTMATERIALIVSGIXPROC)(GLenum face, GLenum pname, const GLint *params);
GLAPI PFNGLFRAGMENTMATERIALIVSGIXPROC cppgl_glFragmentMaterialivSGIX;
#define glFragmentMaterialivSGIX cppgl_glFragmentMaterialivSGIX
typedef void (APIENTRYP PFNGLGETFRAGMENTLIGHTFVSGIXPROC)(GLenum light, GLenum pname, GLfloat *params);
GLAPI PFNGLGETFRAGMENTLIGHTFVSGIXPROC cppgl_glGetFragmentLightfvSGIX;
#define glGetFragmentLightfvSGIX cppgl_glGetFragmentLightfvSGIX
typedef void (APIENTRYP PFNGLGETFRAGMENTLIGHTIVSGIXPROC)(GLenum light, GLenum pname, GLint *params);
GLAPI PFNGLGETFRAGMENTLIGHTIVSGIXPROC cppgl_glGetFragmentLightivSGIX;
#define glGetFragmentLightivSGIX cppgl_glGetFragmentLightivSGIX
typedef void (APIENTRYP PFNGLGETFRAGMENTMATERIALFVSGIXPROC)(GLenum face, GLenum pname, GLfloat *params);
GLAPI PFNGLGETFRAGMENTMATERIALFVSGIXPROC cppgl_glGetFragmentMaterialfvSGIX;
#define glGetFragmentMaterialfvSGIX cppgl_glGetFragmentMaterialfvSGIX
typedef void (APIENTRYP PFNGLGETFRAGMENTMATERIALIVSGIXPROC)(GLenum face, GLenum pname, GLint *params);
GLAPI PFNGLGETFRAGMENTMATERIALIVSGIXPROC cppgl_glGetFragmentMaterialivSGIX;
#define glGetFragmentMaterialivSGIX cppgl_glGetFragmentMaterialivSGIX
typedef void (APIENTRYP PFNGLLIGHTENVISGIXPROC)(GLenum pname, GLint param);
GLAPI PFNGLLIGHTENVISGIXPROC cppgl_glLightEnviSGIX;
#define glLightEnviSGIX cppgl_glLightEnviSGIX
#endif
#ifndef GL_SGIX_framezoom
#define GL_SGIX_framezoom 1
GLAPI int CPPGL_GL_SGIX_framezoom;
typedef void (APIENTRYP PFNGLFRAMEZOOMSGIXPROC)(GLint factor);
GLAPI PFNGLFRAMEZOOMSGIXPROC cppgl_glFrameZoomSGIX;
#define glFrameZoomSGIX cppgl_glFrameZoomSGIX
#endif
#ifndef GL_SGIX_igloo_interface
#define GL_SGIX_igloo_interface 1
GLAPI int CPPGL_GL_SGIX_igloo_interface;
typedef void (APIENTRYP PFNGLIGLOOINTERFACESGIXPROC)(GLenum pname, const void *params);
GLAPI PFNGLIGLOOINTERFACESGIXPROC cppgl_glIglooInterfaceSGIX;
#define glIglooInterfaceSGIX cppgl_glIglooInterfaceSGIX
#endif
#ifndef GL_SGIX_instruments
#define GL_SGIX_instruments 1
GLAPI int CPPGL_GL_SGIX_instruments;
typedef GLint (APIENTRYP PFNGLGETINSTRUMENTSSGIXPROC)();
GLAPI PFNGLGETINSTRUMENTSSGIXPROC cppgl_glGetInstrumentsSGIX;
#define glGetInstrumentsSGIX cppgl_glGetInstrumentsSGIX
typedef void (APIENTRYP PFNGLINSTRUMENTSBUFFERSGIXPROC)(GLsizei size, GLint *buffer);
GLAPI PFNGLINSTRUMENTSBUFFERSGIXPROC cppgl_glInstrumentsBufferSGIX;
#define glInstrumentsBufferSGIX cppgl_glInstrumentsBufferSGIX
typedef GLint (APIENTRYP PFNGLPOLLINSTRUMENTSSGIXPROC)(GLint *marker_p);
GLAPI PFNGLPOLLINSTRUMENTSSGIXPROC cppgl_glPollInstrumentsSGIX;
#define glPollInstrumentsSGIX cppgl_glPollInstrumentsSGIX
typedef void (APIENTRYP PFNGLREADINSTRUMENTSSGIXPROC)(GLint marker);
GLAPI PFNGLREADINSTRUMENTSSGIXPROC cppgl_glReadInstrumentsSGIX;
#define glReadInstrumentsSGIX cppgl_glReadInstrumentsSGIX
typedef void (APIENTRYP PFNGLSTARTINSTRUMENTSSGIXPROC)();
GLAPI PFNGLSTARTINSTRUMENTSSGIXPROC cppgl_glStartInstrumentsSGIX;
#define glStartInstrumentsSGIX cppgl_glStartInstrumentsSGIX
typedef void (APIENTRYP PFNGLSTOPINSTRUMENTSSGIXPROC)(GLint marker);
GLAPI PFNGLSTOPINSTRUMENTSSGIXPROC cppgl_glStopInstrumentsSGIX;
#define glStopInstrumentsSGIX cppgl_glStopInstrumentsSGIX
#endif
#ifndef GL_SGIX_interlace
#define GL_SGIX_interlace 1
GLAPI int CPPGL_GL_SGIX_interlace;
#endif
#ifndef GL_SGIX_ir_instrument1
#define GL_SGIX_ir_instrument1 1
GLAPI int CPPGL_GL_SGIX_ir_instrument1;
#endif
#ifndef GL_SGIX_list_priority
#define GL_SGIX_list_priority 1
GLAPI int CPPGL_GL_SGIX_list_priority;
typedef void (APIENTRYP PFNGLGETLISTPARAMETERFVSGIXPROC)(GLuint list, GLenum pname, GLfloat *params);
GLAPI PFNGLGETLISTPARAMETERFVSGIXPROC cppgl_glGetListParameterfvSGIX;
#define glGetListParameterfvSGIX cppgl_glGetListParameterfvSGIX
typedef void (APIENTRYP PFNGLGETLISTPARAMETERIVSGIXPROC)(GLuint list, GLenum pname, GLint *params);
GLAPI PFNGLGETLISTPARAMETERIVSGIXPROC cppgl_glGetListParameterivSGIX;
#define glGetListParameterivSGIX cppgl_glGetListParameterivSGIX
typedef void (APIENTRYP PFNGLLISTPARAMETERFSGIXPROC)(GLuint list, GLenum pname, GLfloat param);
GLAPI PFNGLLISTPARAMETERFSGIXPROC cppgl_glListParameterfSGIX;
#define glListParameterfSGIX cppgl_glListParameterfSGIX
typedef void (APIENTRYP PFNGLLISTPARAMETERFVSGIXPROC)(GLuint list, GLenum pname, const GLfloat *params);
GLAPI PFNGLLISTPARAMETERFVSGIXPROC cppgl_glListParameterfvSGIX;
#define glListParameterfvSGIX cppgl_glListParameterfvSGIX
typedef void (APIENTRYP PFNGLLISTPARAMETERISGIXPROC)(GLuint list, GLenum pname, GLint param);
GLAPI PFNGLLISTPARAMETERISGIXPROC cppgl_glListParameteriSGIX;
#define glListParameteriSGIX cppgl_glListParameteriSGIX
typedef void (APIENTRYP PFNGLLISTPARAMETERIVSGIXPROC)(GLuint list, GLenum pname, const GLint *params);
GLAPI PFNGLLISTPARAMETERIVSGIXPROC cppgl_glListParameterivSGIX;
#define glListParameterivSGIX cppgl_glListParameterivSGIX
#endif
#ifndef GL_SGIX_pixel_texture
#define GL_SGIX_pixel_texture 1
GLAPI int CPPGL_GL_SGIX_pixel_texture;
typedef void (APIENTRYP PFNGLPIXELTEXGENSGIXPROC)(GLenum mode);
GLAPI PFNGLPIXELTEXGENSGIXPROC cppgl_glPixelTexGenSGIX;
#define glPixelTexGenSGIX cppgl_glPixelTexGenSGIX
#endif
#ifndef GL_SGIX_pixel_tiles
#define GL_SGIX_pixel_tiles 1
GLAPI int CPPGL_GL_SGIX_pixel_tiles;
#endif
#ifndef GL_SGIX_polynomial_ffd
#define GL_SGIX_polynomial_ffd 1
GLAPI int CPPGL_GL_SGIX_polynomial_ffd;
typedef void (APIENTRYP PFNGLDEFORMATIONMAP3DSGIXPROC)(GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, GLdouble w1, GLdouble w2, GLint wstride, GLint worder, const GLdouble *points);
GLAPI PFNGLDEFORMATIONMAP3DSGIXPROC cppgl_glDeformationMap3dSGIX;
#define glDeformationMap3dSGIX cppgl_glDeformationMap3dSGIX
typedef void (APIENTRYP PFNGLDEFORMATIONMAP3FSGIXPROC)(GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, GLfloat w1, GLfloat w2, GLint wstride, GLint worder, const GLfloat *points);
GLAPI PFNGLDEFORMATIONMAP3FSGIXPROC cppgl_glDeformationMap3fSGIX;
#define glDeformationMap3fSGIX cppgl_glDeformationMap3fSGIX
typedef void (APIENTRYP PFNGLDEFORMSGIXPROC)(GLbitfield mask);
GLAPI PFNGLDEFORMSGIXPROC cppgl_glDeformSGIX;
#define glDeformSGIX cppgl_glDeformSGIX
typedef void (APIENTRYP PFNGLLOADIDENTITYDEFORMATIONMAPSGIXPROC)(GLbitfield mask);
GLAPI PFNGLLOADIDENTITYDEFORMATIONMAPSGIXPROC cppgl_glLoadIdentityDeformationMapSGIX;
#define glLoadIdentityDeformationMapSGIX cppgl_glLoadIdentityDeformationMapSGIX
#endif
#ifndef GL_SGIX_reference_plane
#define GL_SGIX_reference_plane 1
GLAPI int CPPGL_GL_SGIX_reference_plane;
typedef void (APIENTRYP PFNGLREFERENCEPLANESGIXPROC)(const GLdouble *equation);
GLAPI PFNGLREFERENCEPLANESGIXPROC cppgl_glReferencePlaneSGIX;
#define glReferencePlaneSGIX cppgl_glReferencePlaneSGIX
#endif
#ifndef GL_SGIX_resample
#define GL_SGIX_resample 1
GLAPI int CPPGL_GL_SGIX_resample;
#endif
#ifndef GL_SGIX_scalebias_hint
#define GL_SGIX_scalebias_hint 1
GLAPI int CPPGL_GL_SGIX_scalebias_hint;
#endif
#ifndef GL_SGIX_shadow
#define GL_SGIX_shadow 1
GLAPI int CPPGL_GL_SGIX_shadow;
#endif
#ifndef GL_SGIX_shadow_ambient
#define GL_SGIX_shadow_ambient 1
GLAPI int CPPGL_GL_SGIX_shadow_ambient;
#endif
#ifndef GL_SGIX_sprite
#define GL_SGIX_sprite 1
GLAPI int CPPGL_GL_SGIX_sprite;
typedef void (APIENTRYP PFNGLSPRITEPARAMETERFSGIXPROC)(GLenum pname, GLfloat param);
GLAPI PFNGLSPRITEPARAMETERFSGIXPROC cppgl_glSpriteParameterfSGIX;
#define glSpriteParameterfSGIX cppgl_glSpriteParameterfSGIX
typedef void (APIENTRYP PFNGLSPRITEPARAMETERFVSGIXPROC)(GLenum pname, const GLfloat *params);
GLAPI PFNGLSPRITEPARAMETERFVSGIXPROC cppgl_glSpriteParameterfvSGIX;
#define glSpriteParameterfvSGIX cppgl_glSpriteParameterfvSGIX
typedef void (APIENTRYP PFNGLSPRITEPARAMETERISGIXPROC)(GLenum pname, GLint param);
GLAPI PFNGLSPRITEPARAMETERISGIXPROC cppgl_glSpriteParameteriSGIX;
#define glSpriteParameteriSGIX cppgl_glSpriteParameteriSGIX
typedef void (APIENTRYP PFNGLSPRITEPARAMETERIVSGIXPROC)(GLenum pname, const GLint *params);
GLAPI PFNGLSPRITEPARAMETERIVSGIXPROC cppgl_glSpriteParameterivSGIX;
#define glSpriteParameterivSGIX cppgl_glSpriteParameterivSGIX
#endif
#ifndef GL_SGIX_subsample
#define GL_SGIX_subsample 1
GLAPI int CPPGL_GL_SGIX_subsample;
#endif
#ifndef GL_SGIX_tag_sample_buffer
#define GL_SGIX_tag_sample_buffer 1
GLAPI int CPPGL_GL_SGIX_tag_sample_buffer;
typedef void (APIENTRYP PFNGLTAGSAMPLEBUFFERSGIXPROC)();
GLAPI PFNGLTAGSAMPLEBUFFERSGIXPROC cppgl_glTagSampleBufferSGIX;
#define glTagSampleBufferSGIX cppgl_glTagSampleBufferSGIX
#endif
#ifndef GL_SGIX_texture_add_env
#define GL_SGIX_texture_add_env 1
GLAPI int CPPGL_GL_SGIX_texture_add_env;
#endif
#ifndef GL_SGIX_texture_coordinate_clamp
#define GL_SGIX_texture_coordinate_clamp 1
GLAPI int CPPGL_GL_SGIX_texture_coordinate_clamp;
#endif
#ifndef GL_SGIX_texture_lod_bias
#define GL_SGIX_texture_lod_bias 1
GLAPI int CPPGL_GL_SGIX_texture_lod_bias;
#endif
#ifndef GL_SGIX_texture_multi_buffer
#define GL_SGIX_texture_multi_buffer 1
GLAPI int CPPGL_GL_SGIX_texture_multi_buffer;
#endif
#ifndef GL_SGIX_texture_scale_bias
#define GL_SGIX_texture_scale_bias 1
GLAPI int CPPGL_GL_SGIX_texture_scale_bias;
#endif
#ifndef GL_SGIX_vertex_preclip
#define GL_SGIX_vertex_preclip 1
GLAPI int CPPGL_GL_SGIX_vertex_preclip;
#endif
#ifndef GL_SGIX_ycrcb
#define GL_SGIX_ycrcb 1
GLAPI int CPPGL_GL_SGIX_ycrcb;
#endif
#ifndef GL_SGIX_ycrcb_subsample
#define GL_SGIX_ycrcb_subsample 1
GLAPI int CPPGL_GL_SGIX_ycrcb_subsample;
#endif
#ifndef GL_SGIX_ycrcba
#define GL_SGIX_ycrcba 1
GLAPI int CPPGL_GL_SGIX_ycrcba;
#endif
#ifndef GL_SGI_color_matrix
#define GL_SGI_color_matrix 1
GLAPI int CPPGL_GL_SGI_color_matrix;
#endif
#ifndef GL_SGI_color_table
#define GL_SGI_color_table 1
GLAPI int CPPGL_GL_SGI_color_table;
typedef void (APIENTRYP PFNGLCOLORTABLESGIPROC)(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const void *table);
GLAPI PFNGLCOLORTABLESGIPROC cppgl_glColorTableSGI;
#define glColorTableSGI cppgl_glColorTableSGI
typedef void (APIENTRYP PFNGLCOLORTABLEPARAMETERFVSGIPROC)(GLenum target, GLenum pname, const GLfloat *params);
GLAPI PFNGLCOLORTABLEPARAMETERFVSGIPROC cppgl_glColorTableParameterfvSGI;
#define glColorTableParameterfvSGI cppgl_glColorTableParameterfvSGI
typedef void (APIENTRYP PFNGLCOLORTABLEPARAMETERIVSGIPROC)(GLenum target, GLenum pname, const GLint *params);
GLAPI PFNGLCOLORTABLEPARAMETERIVSGIPROC cppgl_glColorTableParameterivSGI;
#define glColorTableParameterivSGI cppgl_glColorTableParameterivSGI
typedef void (APIENTRYP PFNGLCOPYCOLORTABLESGIPROC)(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width);
GLAPI PFNGLCOPYCOLORTABLESGIPROC cppgl_glCopyColorTableSGI;
#define glCopyColorTableSGI cppgl_glCopyColorTableSGI
typedef void (APIENTRYP PFNGLGETCOLORTABLESGIPROC)(GLenum target, GLenum format, GLenum type, void *table);
GLAPI PFNGLGETCOLORTABLESGIPROC cppgl_glGetColorTableSGI;
#define glGetColorTableSGI cppgl_glGetColorTableSGI
typedef void (APIENTRYP PFNGLGETCOLORTABLEPARAMETERFVSGIPROC)(GLenum target, GLenum pname, GLfloat *params);
GLAPI PFNGLGETCOLORTABLEPARAMETERFVSGIPROC cppgl_glGetColorTableParameterfvSGI;
#define glGetColorTableParameterfvSGI cppgl_glGetColorTableParameterfvSGI
typedef void (APIENTRYP PFNGLGETCOLORTABLEPARAMETERIVSGIPROC)(GLenum target, GLenum pname, GLint *params);
GLAPI PFNGLGETCOLORTABLEPARAMETERIVSGIPROC cppgl_glGetColorTableParameterivSGI;
#define glGetColorTableParameterivSGI cppgl_glGetColorTableParameterivSGI
#endif
#ifndef GL_SGI_texture_color_table
#define GL_SGI_texture_color_table 1
GLAPI int CPPGL_GL_SGI_texture_color_table;
#endif
#ifndef GL_SUNX_constant_data
#define GL_SUNX_constant_data 1
GLAPI int CPPGL_GL_SUNX_constant_data;
typedef void (APIENTRYP PFNGLFINISHTEXTURESUNXPROC)();
GLAPI PFNGLFINISHTEXTURESUNXPROC cppgl_glFinishTextureSUNX;
#define glFinishTextureSUNX cppgl_glFinishTextureSUNX
#endif
#ifndef GL_SUN_convolution_border_modes
#define GL_SUN_convolution_border_modes 1
GLAPI int CPPGL_GL_SUN_convolution_border_modes;
#endif
#ifndef GL_SUN_global_alpha
#define GL_SUN_global_alpha 1
GLAPI int CPPGL_GL_SUN_global_alpha;
typedef void (APIENTRYP PFNGLGLOBALALPHAFACTORBSUNPROC)(GLbyte factor);
GLAPI PFNGLGLOBALALPHAFACTORBSUNPROC cppgl_glGlobalAlphaFactorbSUN;
#define glGlobalAlphaFactorbSUN cppgl_glGlobalAlphaFactorbSUN
typedef void (APIENTRYP PFNGLGLOBALALPHAFACTORSSUNPROC)(GLshort factor);
GLAPI PFNGLGLOBALALPHAFACTORSSUNPROC cppgl_glGlobalAlphaFactorsSUN;
#define glGlobalAlphaFactorsSUN cppgl_glGlobalAlphaFactorsSUN
typedef void (APIENTRYP PFNGLGLOBALALPHAFACTORISUNPROC)(GLint factor);
GLAPI PFNGLGLOBALALPHAFACTORISUNPROC cppgl_glGlobalAlphaFactoriSUN;
#define glGlobalAlphaFactoriSUN cppgl_glGlobalAlphaFactoriSUN
typedef void (APIENTRYP PFNGLGLOBALALPHAFACTORFSUNPROC)(GLfloat factor);
GLAPI PFNGLGLOBALALPHAFACTORFSUNPROC cppgl_glGlobalAlphaFactorfSUN;
#define glGlobalAlphaFactorfSUN cppgl_glGlobalAlphaFactorfSUN
typedef void (APIENTRYP PFNGLGLOBALALPHAFACTORDSUNPROC)(GLdouble factor);
GLAPI PFNGLGLOBALALPHAFACTORDSUNPROC cppgl_glGlobalAlphaFactordSUN;
#define glGlobalAlphaFactordSUN cppgl_glGlobalAlphaFactordSUN
typedef void (APIENTRYP PFNGLGLOBALALPHAFACTORUBSUNPROC)(GLubyte factor);
GLAPI PFNGLGLOBALALPHAFACTORUBSUNPROC cppgl_glGlobalAlphaFactorubSUN;
#define glGlobalAlphaFactorubSUN cppgl_glGlobalAlphaFactorubSUN
typedef void (APIENTRYP PFNGLGLOBALALPHAFACTORUSSUNPROC)(GLushort factor);
GLAPI PFNGLGLOBALALPHAFACTORUSSUNPROC cppgl_glGlobalAlphaFactorusSUN;
#define glGlobalAlphaFactorusSUN cppgl_glGlobalAlphaFactorusSUN
typedef void (APIENTRYP PFNGLGLOBALALPHAFACTORUISUNPROC)(GLuint factor);
GLAPI PFNGLGLOBALALPHAFACTORUISUNPROC cppgl_glGlobalAlphaFactoruiSUN;
#define glGlobalAlphaFactoruiSUN cppgl_glGlobalAlphaFactoruiSUN
#endif
#ifndef GL_SUN_mesh_array
#define GL_SUN_mesh_array 1
GLAPI int CPPGL_GL_SUN_mesh_array;
typedef void (APIENTRYP PFNGLDRAWMESHARRAYSSUNPROC)(GLenum mode, GLint first, GLsizei count, GLsizei width);
GLAPI PFNGLDRAWMESHARRAYSSUNPROC cppgl_glDrawMeshArraysSUN;
#define glDrawMeshArraysSUN cppgl_glDrawMeshArraysSUN
#endif
#ifndef GL_SUN_slice_accum
#define GL_SUN_slice_accum 1
GLAPI int CPPGL_GL_SUN_slice_accum;
#endif
#ifndef GL_SUN_triangle_list
#define GL_SUN_triangle_list 1
GLAPI int CPPGL_GL_SUN_triangle_list;
typedef void (APIENTRYP PFNGLREPLACEMENTCODEUISUNPROC)(GLuint code);
GLAPI PFNGLREPLACEMENTCODEUISUNPROC cppgl_glReplacementCodeuiSUN;
#define glReplacementCodeuiSUN cppgl_glReplacementCodeuiSUN
typedef void (APIENTRYP PFNGLREPLACEMENTCODEUSSUNPROC)(GLushort code);
GLAPI PFNGLREPLACEMENTCODEUSSUNPROC cppgl_glReplacementCodeusSUN;
#define glReplacementCodeusSUN cppgl_glReplacementCodeusSUN
typedef void (APIENTRYP PFNGLREPLACEMENTCODEUBSUNPROC)(GLubyte code);
GLAPI PFNGLREPLACEMENTCODEUBSUNPROC cppgl_glReplacementCodeubSUN;
#define glReplacementCodeubSUN cppgl_glReplacementCodeubSUN
typedef void (APIENTRYP PFNGLREPLACEMENTCODEUIVSUNPROC)(const GLuint *code);
GLAPI PFNGLREPLACEMENTCODEUIVSUNPROC cppgl_glReplacementCodeuivSUN;
#define glReplacementCodeuivSUN cppgl_glReplacementCodeuivSUN
typedef void (APIENTRYP PFNGLREPLACEMENTCODEUSVSUNPROC)(const GLushort *code);
GLAPI PFNGLREPLACEMENTCODEUSVSUNPROC cppgl_glReplacementCodeusvSUN;
#define glReplacementCodeusvSUN cppgl_glReplacementCodeusvSUN
typedef void (APIENTRYP PFNGLREPLACEMENTCODEUBVSUNPROC)(const GLubyte *code);
GLAPI PFNGLREPLACEMENTCODEUBVSUNPROC cppgl_glReplacementCodeubvSUN;
#define glReplacementCodeubvSUN cppgl_glReplacementCodeubvSUN
typedef void (APIENTRYP PFNGLREPLACEMENTCODEPOINTERSUNPROC)(GLenum type, GLsizei stride, const void **pointer);
GLAPI PFNGLREPLACEMENTCODEPOINTERSUNPROC cppgl_glReplacementCodePointerSUN;
#define glReplacementCodePointerSUN cppgl_glReplacementCodePointerSUN
#endif
#ifndef GL_SUN_vertex
#define GL_SUN_vertex 1
GLAPI int CPPGL_GL_SUN_vertex;
typedef void (APIENTRYP PFNGLCOLOR4UBVERTEX2FSUNPROC)(GLubyte r, GLubyte g, GLubyte b, GLubyte a, GLfloat x, GLfloat y);
GLAPI PFNGLCOLOR4UBVERTEX2FSUNPROC cppgl_glColor4ubVertex2fSUN;
#define glColor4ubVertex2fSUN cppgl_glColor4ubVertex2fSUN
typedef void (APIENTRYP PFNGLCOLOR4UBVERTEX2FVSUNPROC)(const GLubyte *c, const GLfloat *v);
GLAPI PFNGLCOLOR4UBVERTEX2FVSUNPROC cppgl_glColor4ubVertex2fvSUN;
#define glColor4ubVertex2fvSUN cppgl_glColor4ubVertex2fvSUN
typedef void (APIENTRYP PFNGLCOLOR4UBVERTEX3FSUNPROC)(GLubyte r, GLubyte g, GLubyte b, GLubyte a, GLfloat x, GLfloat y, GLfloat z);
GLAPI PFNGLCOLOR4UBVERTEX3FSUNPROC cppgl_glColor4ubVertex3fSUN;
#define glColor4ubVertex3fSUN cppgl_glColor4ubVertex3fSUN
typedef void (APIENTRYP PFNGLCOLOR4UBVERTEX3FVSUNPROC)(const GLubyte *c, const GLfloat *v);
GLAPI PFNGLCOLOR4UBVERTEX3FVSUNPROC cppgl_glColor4ubVertex3fvSUN;
#define glColor4ubVertex3fvSUN cppgl_glColor4ubVertex3fvSUN
typedef void (APIENTRYP PFNGLCOLOR3FVERTEX3FSUNPROC)(GLfloat r, GLfloat g, GLfloat b, GLfloat x, GLfloat y, GLfloat z);
GLAPI PFNGLCOLOR3FVERTEX3FSUNPROC cppgl_glColor3fVertex3fSUN;
#define glColor3fVertex3fSUN cppgl_glColor3fVertex3fSUN
typedef void (APIENTRYP PFNGLCOLOR3FVERTEX3FVSUNPROC)(const GLfloat *c, const GLfloat *v);
GLAPI PFNGLCOLOR3FVERTEX3FVSUNPROC cppgl_glColor3fVertex3fvSUN;
#define glColor3fVertex3fvSUN cppgl_glColor3fVertex3fvSUN
typedef void (APIENTRYP PFNGLNORMAL3FVERTEX3FSUNPROC)(GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
GLAPI PFNGLNORMAL3FVERTEX3FSUNPROC cppgl_glNormal3fVertex3fSUN;
#define glNormal3fVertex3fSUN cppgl_glNormal3fVertex3fSUN
typedef void (APIENTRYP PFNGLNORMAL3FVERTEX3FVSUNPROC)(const GLfloat *n, const GLfloat *v);
GLAPI PFNGLNORMAL3FVERTEX3FVSUNPROC cppgl_glNormal3fVertex3fvSUN;
#define glNormal3fVertex3fvSUN cppgl_glNormal3fVertex3fvSUN
typedef void (APIENTRYP PFNGLCOLOR4FNORMAL3FVERTEX3FSUNPROC)(GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
GLAPI PFNGLCOLOR4FNORMAL3FVERTEX3FSUNPROC cppgl_glColor4fNormal3fVertex3fSUN;
#define glColor4fNormal3fVertex3fSUN cppgl_glColor4fNormal3fVertex3fSUN
typedef void (APIENTRYP PFNGLCOLOR4FNORMAL3FVERTEX3FVSUNPROC)(const GLfloat *c, const GLfloat *n, const GLfloat *v);
GLAPI PFNGLCOLOR4FNORMAL3FVERTEX3FVSUNPROC cppgl_glColor4fNormal3fVertex3fvSUN;
#define glColor4fNormal3fVertex3fvSUN cppgl_glColor4fNormal3fVertex3fvSUN
typedef void (APIENTRYP PFNGLTEXCOORD2FVERTEX3FSUNPROC)(GLfloat s, GLfloat t, GLfloat x, GLfloat y, GLfloat z);
GLAPI PFNGLTEXCOORD2FVERTEX3FSUNPROC cppgl_glTexCoord2fVertex3fSUN;
#define glTexCoord2fVertex3fSUN cppgl_glTexCoord2fVertex3fSUN
typedef void (APIENTRYP PFNGLTEXCOORD2FVERTEX3FVSUNPROC)(const GLfloat *tc, const GLfloat *v);
GLAPI PFNGLTEXCOORD2FVERTEX3FVSUNPROC cppgl_glTexCoord2fVertex3fvSUN;
#define glTexCoord2fVertex3fvSUN cppgl_glTexCoord2fVertex3fvSUN
typedef void (APIENTRYP PFNGLTEXCOORD4FVERTEX4FSUNPROC)(GLfloat s, GLfloat t, GLfloat p, GLfloat q, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
GLAPI PFNGLTEXCOORD4FVERTEX4FSUNPROC cppgl_glTexCoord4fVertex4fSUN;
#define glTexCoord4fVertex4fSUN cppgl_glTexCoord4fVertex4fSUN
typedef void (APIENTRYP PFNGLTEXCOORD4FVERTEX4FVSUNPROC)(const GLfloat *tc, const GLfloat *v);
GLAPI PFNGLTEXCOORD4FVERTEX4FVSUNPROC cppgl_glTexCoord4fVertex4fvSUN;
#define glTexCoord4fVertex4fvSUN cppgl_glTexCoord4fVertex4fvSUN
typedef void (APIENTRYP PFNGLTEXCOORD2FCOLOR4UBVERTEX3FSUNPROC)(GLfloat s, GLfloat t, GLubyte r, GLubyte g, GLubyte b, GLubyte a, GLfloat x, GLfloat y, GLfloat z);
GLAPI PFNGLTEXCOORD2FCOLOR4UBVERTEX3FSUNPROC cppgl_glTexCoord2fColor4ubVertex3fSUN;
#define glTexCoord2fColor4ubVertex3fSUN cppgl_glTexCoord2fColor4ubVertex3fSUN
typedef void (APIENTRYP PFNGLTEXCOORD2FCOLOR4UBVERTEX3FVSUNPROC)(const GLfloat *tc, const GLubyte *c, const GLfloat *v);
GLAPI PFNGLTEXCOORD2FCOLOR4UBVERTEX3FVSUNPROC cppgl_glTexCoord2fColor4ubVertex3fvSUN;
#define glTexCoord2fColor4ubVertex3fvSUN cppgl_glTexCoord2fColor4ubVertex3fvSUN
typedef void (APIENTRYP PFNGLTEXCOORD2FCOLOR3FVERTEX3FSUNPROC)(GLfloat s, GLfloat t, GLfloat r, GLfloat g, GLfloat b, GLfloat x, GLfloat y, GLfloat z);
GLAPI PFNGLTEXCOORD2FCOLOR3FVERTEX3FSUNPROC cppgl_glTexCoord2fColor3fVertex3fSUN;
#define glTexCoord2fColor3fVertex3fSUN cppgl_glTexCoord2fColor3fVertex3fSUN
typedef void (APIENTRYP PFNGLTEXCOORD2FCOLOR3FVERTEX3FVSUNPROC)(const GLfloat *tc, const GLfloat *c, const GLfloat *v);
GLAPI PFNGLTEXCOORD2FCOLOR3FVERTEX3FVSUNPROC cppgl_glTexCoord2fColor3fVertex3fvSUN;
#define glTexCoord2fColor3fVertex3fvSUN cppgl_glTexCoord2fColor3fVertex3fvSUN
typedef void (APIENTRYP PFNGLTEXCOORD2FNORMAL3FVERTEX3FSUNPROC)(GLfloat s, GLfloat t, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
GLAPI PFNGLTEXCOORD2FNORMAL3FVERTEX3FSUNPROC cppgl_glTexCoord2fNormal3fVertex3fSUN;
#define glTexCoord2fNormal3fVertex3fSUN cppgl_glTexCoord2fNormal3fVertex3fSUN
typedef void (APIENTRYP PFNGLTEXCOORD2FNORMAL3FVERTEX3FVSUNPROC)(const GLfloat *tc, const GLfloat *n, const GLfloat *v);
GLAPI PFNGLTEXCOORD2FNORMAL3FVERTEX3FVSUNPROC cppgl_glTexCoord2fNormal3fVertex3fvSUN;
#define glTexCoord2fNormal3fVertex3fvSUN cppgl_glTexCoord2fNormal3fVertex3fvSUN
typedef void (APIENTRYP PFNGLTEXCOORD2FCOLOR4FNORMAL3FVERTEX3FSUNPROC)(GLfloat s, GLfloat t, GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
GLAPI PFNGLTEXCOORD2FCOLOR4FNORMAL3FVERTEX3FSUNPROC cppgl_glTexCoord2fColor4fNormal3fVertex3fSUN;
#define glTexCoord2fColor4fNormal3fVertex3fSUN cppgl_glTexCoord2fColor4fNormal3fVertex3fSUN
typedef void (APIENTRYP PFNGLTEXCOORD2FCOLOR4FNORMAL3FVERTEX3FVSUNPROC)(const GLfloat *tc, const GLfloat *c, const GLfloat *n, const GLfloat *v);
GLAPI PFNGLTEXCOORD2FCOLOR4FNORMAL3FVERTEX3FVSUNPROC cppgl_glTexCoord2fColor4fNormal3fVertex3fvSUN;
#define glTexCoord2fColor4fNormal3fVertex3fvSUN cppgl_glTexCoord2fColor4fNormal3fVertex3fvSUN
typedef void (APIENTRYP PFNGLTEXCOORD4FCOLOR4FNORMAL3FVERTEX4FSUNPROC)(GLfloat s, GLfloat t, GLfloat p, GLfloat q, GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
GLAPI PFNGLTEXCOORD4FCOLOR4FNORMAL3FVERTEX4FSUNPROC cppgl_glTexCoord4fColor4fNormal3fVertex4fSUN;
#define glTexCoord4fColor4fNormal3fVertex4fSUN cppgl_glTexCoord4fColor4fNormal3fVertex4fSUN
typedef void (APIENTRYP PFNGLTEXCOORD4FCOLOR4FNORMAL3FVERTEX4FVSUNPROC)(const GLfloat *tc, const GLfloat *c, const GLfloat *n, const GLfloat *v);
GLAPI PFNGLTEXCOORD4FCOLOR4FNORMAL3FVERTEX4FVSUNPROC cppgl_glTexCoord4fColor4fNormal3fVertex4fvSUN;
#define glTexCoord4fColor4fNormal3fVertex4fvSUN cppgl_glTexCoord4fColor4fNormal3fVertex4fvSUN
typedef void (APIENTRYP PFNGLREPLACEMENTCODEUIVERTEX3FSUNPROC)(GLuint rc, GLfloat x, GLfloat y, GLfloat z);
GLAPI PFNGLREPLACEMENTCODEUIVERTEX3FSUNPROC cppgl_glReplacementCodeuiVertex3fSUN;
#define glReplacementCodeuiVertex3fSUN cppgl_glReplacementCodeuiVertex3fSUN
typedef void (APIENTRYP PFNGLREPLACEMENTCODEUIVERTEX3FVSUNPROC)(const GLuint *rc, const GLfloat *v);
GLAPI PFNGLREPLACEMENTCODEUIVERTEX3FVSUNPROC cppgl_glReplacementCodeuiVertex3fvSUN;
#define glReplacementCodeuiVertex3fvSUN cppgl_glReplacementCodeuiVertex3fvSUN
typedef void (APIENTRYP PFNGLREPLACEMENTCODEUICOLOR4UBVERTEX3FSUNPROC)(GLuint rc, GLubyte r, GLubyte g, GLubyte b, GLubyte a, GLfloat x, GLfloat y, GLfloat z);
GLAPI PFNGLREPLACEMENTCODEUICOLOR4UBVERTEX3FSUNPROC cppgl_glReplacementCodeuiColor4ubVertex3fSUN;
#define glReplacementCodeuiColor4ubVertex3fSUN cppgl_glReplacementCodeuiColor4ubVertex3fSUN
typedef void (APIENTRYP PFNGLREPLACEMENTCODEUICOLOR4UBVERTEX3FVSUNPROC)(const GLuint *rc, const GLubyte *c, const GLfloat *v);
GLAPI PFNGLREPLACEMENTCODEUICOLOR4UBVERTEX3FVSUNPROC cppgl_glReplacementCodeuiColor4ubVertex3fvSUN;
#define glReplacementCodeuiColor4ubVertex3fvSUN cppgl_glReplacementCodeuiColor4ubVertex3fvSUN
typedef void (APIENTRYP PFNGLREPLACEMENTCODEUICOLOR3FVERTEX3FSUNPROC)(GLuint rc, GLfloat r, GLfloat g, GLfloat b, GLfloat x, GLfloat y, GLfloat z);
GLAPI PFNGLREPLACEMENTCODEUICOLOR3FVERTEX3FSUNPROC cppgl_glReplacementCodeuiColor3fVertex3fSUN;
#define glReplacementCodeuiColor3fVertex3fSUN cppgl_glReplacementCodeuiColor3fVertex3fSUN
typedef void (APIENTRYP PFNGLREPLACEMENTCODEUICOLOR3FVERTEX3FVSUNPROC)(const GLuint *rc, const GLfloat *c, const GLfloat *v);
GLAPI PFNGLREPLACEMENTCODEUICOLOR3FVERTEX3FVSUNPROC cppgl_glReplacementCodeuiColor3fVertex3fvSUN;
#define glReplacementCodeuiColor3fVertex3fvSUN cppgl_glReplacementCodeuiColor3fVertex3fvSUN
typedef void (APIENTRYP PFNGLREPLACEMENTCODEUINORMAL3FVERTEX3FSUNPROC)(GLuint rc, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
GLAPI PFNGLREPLACEMENTCODEUINORMAL3FVERTEX3FSUNPROC cppgl_glReplacementCodeuiNormal3fVertex3fSUN;
#define glReplacementCodeuiNormal3fVertex3fSUN cppgl_glReplacementCodeuiNormal3fVertex3fSUN
typedef void (APIENTRYP PFNGLREPLACEMENTCODEUINORMAL3FVERTEX3FVSUNPROC)(const GLuint *rc, const GLfloat *n, const GLfloat *v);
GLAPI PFNGLREPLACEMENTCODEUINORMAL3FVERTEX3FVSUNPROC cppgl_glReplacementCodeuiNormal3fVertex3fvSUN;
#define glReplacementCodeuiNormal3fVertex3fvSUN cppgl_glReplacementCodeuiNormal3fVertex3fvSUN
typedef void (APIENTRYP PFNGLREPLACEMENTCODEUICOLOR4FNORMAL3FVERTEX3FSUNPROC)(GLuint rc, GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
GLAPI PFNGLREPLACEMENTCODEUICOLOR4FNORMAL3FVERTEX3FSUNPROC cppgl_glReplacementCodeuiColor4fNormal3fVertex3fSUN;
#define glReplacementCodeuiColor4fNormal3fVertex3fSUN cppgl_glReplacementCodeuiColor4fNormal3fVertex3fSUN
typedef void (APIENTRYP PFNGLREPLACEMENTCODEUICOLOR4FNORMAL3FVERTEX3FVSUNPROC)(const GLuint *rc, const GLfloat *c, const GLfloat *n, const GLfloat *v);
GLAPI PFNGLREPLACEMENTCODEUICOLOR4FNORMAL3FVERTEX3FVSUNPROC cppgl_glReplacementCodeuiColor4fNormal3fVertex3fvSUN;
#define glReplacementCodeuiColor4fNormal3fVertex3fvSUN cppgl_glReplacementCodeuiColor4fNormal3fVertex3fvSUN
typedef void (APIENTRYP PFNGLREPLACEMENTCODEUITEXCOORD2FVERTEX3FSUNPROC)(GLuint rc, GLfloat s, GLfloat t, GLfloat x, GLfloat y, GLfloat z);
GLAPI PFNGLREPLACEMENTCODEUITEXCOORD2FVERTEX3FSUNPROC cppgl_glReplacementCodeuiTexCoord2fVertex3fSUN;
#define glReplacementCodeuiTexCoord2fVertex3fSUN cppgl_glReplacementCodeuiTexCoord2fVertex3fSUN
typedef void (APIENTRYP PFNGLREPLACEMENTCODEUITEXCOORD2FVERTEX3FVSUNPROC)(const GLuint *rc, const GLfloat *tc, const GLfloat *v);
GLAPI PFNGLREPLACEMENTCODEUITEXCOORD2FVERTEX3FVSUNPROC cppgl_glReplacementCodeuiTexCoord2fVertex3fvSUN;
#define glReplacementCodeuiTexCoord2fVertex3fvSUN cppgl_glReplacementCodeuiTexCoord2fVertex3fvSUN
typedef void (APIENTRYP PFNGLREPLACEMENTCODEUITEXCOORD2FNORMAL3FVERTEX3FSUNPROC)(GLuint rc, GLfloat s, GLfloat t, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
GLAPI PFNGLREPLACEMENTCODEUITEXCOORD2FNORMAL3FVERTEX3FSUNPROC cppgl_glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN;
#define glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN cppgl_glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN
typedef void (APIENTRYP PFNGLREPLACEMENTCODEUITEXCOORD2FNORMAL3FVERTEX3FVSUNPROC)(const GLuint *rc, const GLfloat *tc, const GLfloat *n, const GLfloat *v);
GLAPI PFNGLREPLACEMENTCODEUITEXCOORD2FNORMAL3FVERTEX3FVSUNPROC cppgl_glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN;
#define glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN cppgl_glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN
typedef void (APIENTRYP PFNGLREPLACEMENTCODEUITEXCOORD2FCOLOR4FNORMAL3FVERTEX3FSUNPROC)(GLuint rc, GLfloat s, GLfloat t, GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
GLAPI PFNGLREPLACEMENTCODEUITEXCOORD2FCOLOR4FNORMAL3FVERTEX3FSUNPROC cppgl_glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN;
#define glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN cppgl_glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN
typedef void (APIENTRYP PFNGLREPLACEMENTCODEUITEXCOORD2FCOLOR4FNORMAL3FVERTEX3FVSUNPROC)(const GLuint *rc, const GLfloat *tc, const GLfloat *c, const GLfloat *n, const GLfloat *v);
GLAPI PFNGLREPLACEMENTCODEUITEXCOORD2FCOLOR4FNORMAL3FVERTEX3FVSUNPROC cppgl_glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN;
#define glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN cppgl_glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN
#endif
#ifndef GL_WIN_phong_shading
#define GL_WIN_phong_shading 1
GLAPI int CPPGL_GL_WIN_phong_shading;
#endif
#ifndef GL_WIN_specular_fog
#define GL_WIN_specular_fog 1
GLAPI int CPPGL_GL_WIN_specular_fog;
#endif

#ifdef __cplusplus
}
#endif

#endif
