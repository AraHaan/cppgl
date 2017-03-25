/*
	cppgl.hpp

	Header only OpenGL implementation that can be
	used for any version of OpenGL up to OpenGL 4.5.

	This allows it to be standalone and not require
	any source files to link to (as there are none).

	This means all you have to do is define a macro
	for the version of OpenGL you need before you
	include this file and your compile should be
	able to do the rest.
*/

#ifndef __cppgl_hpp
#define __cppgl_hpp

/*
	Macros to determine which versions of OpenGL the
	end user needs.
*/
#if defined(USE_OPENGL45)
#include "code/gl45.h"
#elif defined(USE_OPENGL44)
#include "code/gl44.h"
#elif defined(USE_OPENGL43)
#include "code/gl43.h"
#elif defined(USE_OPENGL42)
#include "code/gl42.h"
#elif defined(USE_OPENGL41)
#include "code/gl41.h"
#elif defined(USE_OPENGL40)
#include "code/gl40.h"
#elif defined(USE_OPENGL33)
#include "code/gl33.h"
#elif defined(USE_OPENGL32)
#include "code/gl32.h"
#elif defined(USE_OPENGL31)
#include "code/gl31.h"
#elif defined(USE_OPENGL30)
#include "code/gl30.h"
#elif defined(USE_OPENGL21)
#include "code/gl21.h"
#elif defined(USE_OPENGL20)
#include "code/gl20.h"
#elif defined(USE_OPENGL15)
#include "code/gl15.h"
#elif defined(USE_OPENGL14)
#include "code/gl14.h"
#elif defined(USE_OPENGL13)
#include "code/gl13.h"
#elif defined(USE_OPENGL12)
#include "code/gl12.h"
#elif defined(USE_OPENGL11)
#include "code/gl11.h"
#elif defined(USE_OPENGL10)
#include "code/gl10.h"
#endif

#else /* __cppgl_hpp already defined */
#endif /* __cppgl_hpp */
