//------------------------------- -*- C++ -*- -------------------------------//
// Copyright Celeritas contributors: see top-level COPYRIGHT file for details
// SPDX-License-Identifier: (Apache-2.0 OR MIT)
//---------------------------------------------------------------------------//
//! \file orange/surf/SchwartzP.test.cc
//---------------------------------------------------------------------------//
#include "orange/surf/SchwartzP.hh"

#include "celeritas_test.hh"
// #include "SchwartzP.test.hh"

#include "celeritas_test.hh"

namespace celeritas
{
namespace test
{
//---------------------------------------------------------------------------//

class SchwartzPTest : public ::celeritas::test::Test
{
  protected:
    void SetUp() override {}
};

TEST_F(SchwartzPTest, construction)
{
    SchwartzP s(2.54, 2.53, 2.55);
}

// TEST_F(SchwartzPTest, TEST_IF_CELER_DEVICE(device))
// {
//     SPTestInput input;
//     sp_test(input);
// }

//---------------------------------------------------------------------------//
}  // namespace test
}  // namespace celeritas
