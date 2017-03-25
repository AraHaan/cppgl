### cppgl

This is the very first (that I know of) independent and yet header only 
OpenGL library that ships with OpenGL 1.0 all the way up to OpenGL 4.5.

**Is there any versions missing from this library?**

No, unless a version newer than OpenGL 4.5 comes out you would be golden.
Note: In order to use any version of OpenGL from this you must 
define one of the following macros:

```
USE_OPENGL45
USE_OPENGL44
USE_OPENGL43
USE_OPENGL42
USE_OPENGL41
USE_OPENGL40
USE_OPENGL33
USE_OPENGL32
USE_OPENGL31
USE_OPENGL30
USE_OPENGL21
USE_OPENGL20
USE_OPENGL15
USE_OPENGL14
USE_OPENGL13
USE_OPENGL12
USE_OPENGL11
USE_OPENGL10
```

**I can only use up to OpenGL 2.1 without my program crashing, can I still
use this library?**

Yes, as long as you use any version before OpenGL 3.0 you should be golden.
I know of one Craphics Driver (The Intel gm45 from 2008) that is known
to cause problems with versions of OpenGL newer than 2.1.

**How can I compile this library?**

Just include cppgl.hpp into your source files and then compile like normal.

**What if a new version of OpenGL comes out?**
If a new version comes out simply tell me on discord or file an issue on this
github repository.

### Including this library

In order to include this define one of the macros above and then right after (the line right after) do this:

```cpp
#include <cppgl/cppgl.hpp>
```

And you are all set to use that version of OpenGL.
