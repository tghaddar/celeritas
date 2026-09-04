//------------------------------- -*- C++ -*- -------------------------------//
// Copyright Celeritas contributors: see top-level COPYRIGHT file for details
// SPDX-License-Identifier: (Apache-2.0 OR MIT)
//---------------------------------------------------------------------------//
//! \file orange/surf/SchwartzP.hh
//---------------------------------------------------------------------------//
#pragma once

#include "corecel/Types.hh"

namespace celeritas
{
//---------------------------------------------------------------------------//
/*!
 * Brief Schwartz P triply periodic minimal surface.
 *
 * \f[
 * cos(2*\pi*x/ L_x) + cos(2*\pi*y / L_y) + cos(2 * \pi * z / L_z) = 0
 * \f]
 * Optional detailed class description, and possibly example usage:
 * \code
    SchwartzP ...;
   \endcode
 */
class SchwartzP
{
  public:
    //!@{
    //!@}

  public:
    // Construct with defaults
    inline SchwartzP(real_type lx, real_type ly, real_type lz);

  private:
    // Unit cell length in x
    real_type lx_;
    // Unit cell length in y
    real_type ly_;
    // Unit cell length in z
    real_type lz_;
};

//---------------------------------------------------------------------------//
// INLINE DEFINITIONS
//---------------------------------------------------------------------------//
/*!
 * Construct with defaults.
 */
SchwartzP::SchwartzP(real_type lx, real_type ly, real_type lz)
    : lx_(lx)
    , ly_(ly)
    , lz_(lz)
{
}

//---------------------------------------------------------------------------//
}  // namespace celeritas
