/** ***********************************************************************************
 *    Copyright (C) 2023, The OpenOasis Contributors. Join us in the Oasis!
 *
 *    @File      :  FvmBoundary.h
 *    @License   :  Apache-2.0
 *
 ** ***********************************************************************************/
#pragma once
#include "Models/CommImp/Numeric/Boundary.h"
#include "Models/Utils/RegisterFactory.h"


namespace OpenOasis::CommImp::Numeric::FVM
{
using namespace OpenOasis::Utils;

/// @brief FVM boundary class.
class FvmBoundary : public Boundary
{};


// Commonly used boundaries.

using DirichletBoundary = FvmBoundary;
using NeumannBoundary   = FvmBoundary;
using RobinBoundary     = FvmBoundary;


// Register FVM boundary factory.

class FvmBoundaryRegister;
RegisterFactory(FvmBoundary);


}  // namespace OpenOasis::CommImp::Numeric::FVM