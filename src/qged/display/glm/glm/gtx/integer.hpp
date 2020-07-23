/*
 * OpenGL Mathematics (GLM)
 * --------------------------------------------------------------------------------
 * GLM is licensed under The Happy Bunny License or MIT License
 *
 * BRL-CAD will use glm under the standard MIT license
 *
 * ================================================================================
 * The MIT License
 * --------------------------------------------------------------------------------
 * Copyright (c) 2005 - G-Truc Creation
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

/// @ref gtx_integer
/// @file glm/gtx/integer.hpp
///
/// @see core (dependence)
///
/// @defgroup gtx_integer GLM_GTX_integer
/// @ingroup gtx
///
/// Include <glm/gtx/integer.hpp> to use the features of this extension.
///
/// Add support for integer for core functions

#pragma once

// Dependency:
#include "../glm.hpp"
#include "../gtc/integer.hpp"

#if GLM_MESSAGES == GLM_ENABLE && !defined(GLM_EXT_INCLUDED)
#	ifndef GLM_ENABLE_EXPERIMENTAL
#		pragma message("GLM: GLM_GTX_integer is an experimental extension and may change in the future. Use #define GLM_ENABLE_EXPERIMENTAL before including it, if you really want to use it.")
#	else
#		pragma message("GLM: GLM_GTX_integer extension included")
#	endif
#endif

namespace glm
{
	/// @addtogroup gtx_integer
	/// @{

	//! Returns x raised to the y power.
	//! From GLM_GTX_integer extension.
	GLM_FUNC_DECL int pow(int x, uint y);

	//! Returns the positive square root of x.
	//! From GLM_GTX_integer extension.
	GLM_FUNC_DECL int sqrt(int x);

	//! Returns the floor log2 of x.
	//! From GLM_GTX_integer extension.
	GLM_FUNC_DECL unsigned int floor_log2(unsigned int x);

	//! Modulus. Returns x - y * floor(x / y) for each component in x using the floating point value y.
	//! From GLM_GTX_integer extension.
	GLM_FUNC_DECL int mod(int x, int y);

	//! Return the factorial value of a number (!12 max, integer only)
	//! From GLM_GTX_integer extension.
	template<typename genType>
	GLM_FUNC_DECL genType factorial(genType const& x);

	//! 32bit signed integer.
	//! From GLM_GTX_integer extension.
	typedef signed int					sint;

	//! Returns x raised to the y power.
	//! From GLM_GTX_integer extension.
	GLM_FUNC_DECL uint pow(uint x, uint y);

	//! Returns the positive square root of x.
	//! From GLM_GTX_integer extension.
	GLM_FUNC_DECL uint sqrt(uint x);

	//! Modulus. Returns x - y * floor(x / y) for each component in x using the floating point value y.
	//! From GLM_GTX_integer extension.
	GLM_FUNC_DECL uint mod(uint x, uint y);

	//! Returns the number of leading zeros.
	//! From GLM_GTX_integer extension.
	GLM_FUNC_DECL uint nlz(uint x);

	/// @}
}//namespace glm

#include "integer.inl"
