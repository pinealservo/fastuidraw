/*!
 * \file painter_blend_shader_glsl.cpp
 * \brief file painter_blend_shader_glsl.cpp
 *
 * Copyright 2016 by Intel.
 *
 * Contact: kevin.rogovin@intel.com
 *
 * This Source Code Form is subject to the
 * terms of the Mozilla Public License, v. 2.0.
 * If a copy of the MPL was not distributed with
 * this file, You can obtain one at
 * http://mozilla.org/MPL/2.0/.
 *
 * \author Kevin Rogovin <kevin.rogovin@intel.com>
 *
 */

#include <fastuidraw/glsl/painter_blend_shader_glsl.hpp>

namespace
{
  class PainterBlendShaderGLSLPrivate
  {
  public:
    explicit
    PainterBlendShaderGLSLPrivate(const fastuidraw::glsl::ShaderSource &src):
      m_src(src)
    {}

    fastuidraw::glsl::ShaderSource m_src;
  };
}


///////////////////////////////////////////////
// fastuidraw::glsl::PainterBlendShaderGLSL methods
fastuidraw::glsl::PainterBlendShaderGLSL::
PainterBlendShaderGLSL(enum shader_type tp,
                       const ShaderSource &src,
                       unsigned int num_sub_shaders):
  PainterBlendShader(tp, num_sub_shaders)
{
  m_d = FASTUIDRAWnew PainterBlendShaderGLSLPrivate(src);
}

fastuidraw::glsl::PainterBlendShaderGLSL::
~PainterBlendShaderGLSL(void)
{
  PainterBlendShaderGLSLPrivate *d;
  d = reinterpret_cast<PainterBlendShaderGLSLPrivate*>(m_d);
  FASTUIDRAWdelete(d);
  m_d = NULL;
}

const fastuidraw::glsl::ShaderSource&
fastuidraw::glsl::PainterBlendShaderGLSL::
blend_src(void) const
{
  PainterBlendShaderGLSLPrivate *d;
  d = reinterpret_cast<PainterBlendShaderGLSLPrivate*>(m_d);
  return d->m_src;
}
