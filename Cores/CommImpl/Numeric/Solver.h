/** ***********************************************************************************
 *    Copyright (C) 2023, The OpenOasis Contributors. Join us in the Oasis!
 *
 *    @File      :  Solver.h
 *    @License   :  Apache-2.0
 *
 *    @Desc      :  Abstract solver class to provide unified interfaces.
 *
 ** ***********************************************************************************/
#pragma once
#include "ScalarField.h"
#include "VectorField.h"
#include "TensorField.h"
#include "Matrix.h"


namespace OpenOasis::CommImpl::Numeric
{
class Solver
{
public:
    virtual ~Solver() = default;

    ///////////////////////////////////////////////////////////////////////////////////
    // Time derivative operator.
    //

    ///////////////////////////////////////////////////////////////////////////////////
    // Gradient operator.
    //

    ///////////////////////////////////////////////////////////////////////////////////
    // Divergence operator.
    //

    ///////////////////////////////////////////////////////////////////////////////////
    // Curl operator.
    //

    ///////////////////////////////////////////////////////////////////////////////////
    // Laplacian operator.
    //
};

}  // namespace OpenOasis::CommImpl::Numeric