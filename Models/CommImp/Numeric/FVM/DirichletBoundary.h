/** ***********************************************************************************
 *    Copyright (C) 2023, The OpenOasis Contributors. Join us in the Oasis!
 *
 *    @File      :  DirichletBoundary.h
 *    @License   :  Apache-2.0
 *
 *    @Desc      :  Dirichlet boundary.
 *
 ** ***********************************************************************************/
#pragma once
#include "Models/CommImp/Numeric/Boundary.h"


namespace OpenOasis::CommImp::Numeric::FVM
{
using Utils::real;

/// @brief Dirichlet boundary.
class DirichletBoundary : public Boundary
{
private:
    BoundaryCondition mData;

public:
    DirichletBoundary();
    DirichletBoundary(real value);
    DirichletBoundary(const DirichletBoundary &other);

    void SetBoundaryValue(real value) override;

    void SetBoundaryFlux(real flux) override;

    std::string GetType() const override;

    BoundaryCondition GetBoundaryCondition() override;
};

}  // namespace OpenOasis::CommImp::Numeric::FVM