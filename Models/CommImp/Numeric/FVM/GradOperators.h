/** ***********************************************************************************
 *    Copyright (C) 2024, The OpenOasis Contributors. Join us in the Oasis!
 *
 *    @File      :  GradOperators.h
 *    @License   :  Apache-2.0
 *
 *    @Desc      :  Gradient operators for FVM.
 *
 ** ***********************************************************************************/
#pragma once
#include "FvmOperator.h"
#include <functional>
#include <memory>


namespace OpenOasis::CommImp::Numeric::FVM
{
/// @brief Grad01 operator for scalar field in cell domain.
/// @details Computes the gradient of a scalar field in cell domain by compact stencil.
class Grad01 : public GradOperator
{
private:
    std::shared_ptr<Grid> mGrid;

public:
    Grad01()          = default;
    virtual ~Grad01() = default;

    ///////////////////////////////////////////////////////////////////////////////////
    // Overridden methods from GradOperator.
    //

    virtual std::string GetName() override;

    virtual void Prepare() override;

    virtual LinearEqs Discretize() override;

private:
};


}  // namespace OpenOasis::CommImp::Numeric::FVM