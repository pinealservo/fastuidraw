#########################################
## System specifics related to GL headers

###################################################
## Location in file system of GL (or GLES3) headers
ifeq ($(MINGW_BUILD),0)
  GL_INCLUDEPATH=/usr/include
  ifeq ($(DARWIN_BUILD),1)
    BASE_GL_INC=$(shell clang -x c -v -E /dev/null 2>&1 | grep "System/Library/Frameworks" | cut -f2 -d' ')
    GL_INCLUDEPATH=$(BASE_GL_INC)/OpenGL.framework/Headers
  endif
else ifeq ($(MINGW_MODE),MINGW64)
  GL_INCLUDEPATH=/mingw64/include
else ifeq ($(MINGW_MODE),MINGW32)
  GL_INCLUDEPATH=/mingw32/include
else
  GL_INCLUDEPATH=/mingw/include
endif

############################
## headers for GL and GLES
ifeq ($(DARWIN_BUILD),1)
GL_RAW_HEADER_FILES=OpenGL/gl3.h OpenGL/gl3ext.h
GL_INC_HEADER_FILES=gl3.h gl3ext.h
else
GL_RAW_HEADER_FILES=GL/glcorearb.h
endif
GLES_RAW_HEADER_FILES=GLES3/gl3platform.h GLES3/gl3.h GLES3/gl31.h GLES3/gl32.h GLES2/gl2ext.h
