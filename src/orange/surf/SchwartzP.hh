//------------------------------- -*- C++ -*- -------------------------------//
// Copyright Celeritas contributors: see top-level COPYRIGHT file for details
// SPDX-License-Identifier: (Apache-2.0 OR MIT)
//---------------------------------------------------------------------------//
//! \file orange/surf/SchwartzP.hh
//---------------------------------------------------------------------------//
#pragma once

#include <cmath>

#include "corecel/Assert.hh"
#include "corecel/Constants.hh"
#include "corecel/Types.hh"
#include "corecel/cont/Array.hh"
#include "corecel/cont/Span.hh"

#include "orange/OrangeTypes.hh"
#include "orange/SenseUtils.hh"

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
    using Intersections = Array<real_type, 3>;
    // TODO: Unsure about this one
    using StorageSpan = Span<real_type const, 3>;
    //!@}
    
    //// CLASS ATTRIBUTES ////

    //! Surface type identifier
    static CELER_CONSTEXPR_FUNCTION SurfaceType surface_type()
    {
        return SurfaceType::tpms;
    }
    
    //! Safety is intersection along surface normal (TODO: Check)
    static CELER_CONSTEXPR_FUNCTION bool simple_safety() { return true; }

  public:
    // Construct with defaults
    inline CELER_FUNCTION SchwartzP(real_type lx, real_type ly, real_type lz);
    
    // Construct from raw data
    template<class R>
    explicit inline CELER_FUNCTION SchwartzP(Span<R, StorageSpan::extent>);
    
    //// ACCESSORS ////

    //! Unit cell length in x
    CELER_FUNCTION real_type const& lx() const { return lx_; }

    //! Unit cell length in y
    CELER_FUNCTION real_type const& ly() const { return ly_; }

    //! Unit cell length in z
    CELER_FUNCTION real_type const& lz() const { return lz_; }
    
    //// CALCULATION ////
    
    // Determine the sense of the position relative to this surface
    inline CELER_FUNCTION SignedSense calc_sense(Real3 const& pos) const;
    
    // Calculate all possible straight-line intersections with this surface
    inline CELER_FUNCTION Intersections calc_intersections(
        Real3 const& pos, Real3 const& dir, SurfaceState on_surface) const;

    // Calculate outward normal at a position
    inline CELER_FUNCTION Real3 calc_normal(Real3 const& pos) const;

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
 * Construct with unit cell lengths in x, y, and z.
 */
SchwartzP::SchwartzP(real_type lx, real_type ly, real_type lz)
    : lx_(lx)
    , ly_(ly)
    , lz_(lz)
{
    CELER_EXPECT(lx > 0);
    CELER_EXPECT(ly > 0);
    CELER_EXPECT(lz > 0);
}

//---------------------------------------------------------------------------//
/*!
 * Construct from raw data.
 */
template<class R>
CELER_FUNCTION SchwartzP::SchwartzP(Span<R, StorageSpan::extent> data)
    : lx_(data[0]), ly_(data[1]), lz_(data[2])
{
}

//---------------------------------------------------------------------------//
/*!
 * Determine the sense of the position relative to this surface.
 *
 */
CELER_FUNCTION SignedSense SchwartzP::calc_sense(Real3 const& pos) const
{
    using constants::twopi;
    real_type p = std::cos(twopi * pos[0] / lx_) + 
                  std::cos(twopi * pos[1] / ly_) + 
                  std::cos(twopi * pos[2] / lz_);

    return real_to_sense(p);
}

//---------------------------------------------------------------------------//
/*!
 * Calculate all possible straight-line intersections with this surface.
 */
CELER_FUNCTION auto SchwartzP::calc_intersections(
    Real3 const& pos, Real3 const& dir, SurfaceState on_surface) const
    -> Intersections
{
    CELER_NOT_IMPLEMENTED("SchwartzP intersection calculation is not implemented at this time");
}

//---------------------------------------------------------------------------//
/*!
 * Calculate outward normal at a position.
 */
CELER_FUNCTION Real3 SchwartzP::calc_normal(Real3 const& pos) const
{
    CELER_NOT_IMPLEMENTED("SchwartzP surface normal calculation is not implemented at this time");
}

//---------------------------------------------------------------------------//
}  // namespace celeritas
