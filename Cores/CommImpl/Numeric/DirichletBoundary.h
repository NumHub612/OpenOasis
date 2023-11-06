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
#include "Boundary.h"


namespace OpenOasis::CommImpl::Numeric
{
/// @brief Dirichlet boundary.
class DirichletBoundary : public Boundary
{
private:
    BoundaryCondition mData;

public:
    DirichletBoundary();
    DirichletBoundary(double value);
    DirichletBoundary(const DirichletBoundary &other);

    void SetBoundaryValue(double value) override;

    void SetBoundaryFlux(double flux) override;

    std::string GetType() const override;

    BoundaryCondition GetBoundaryCondition() override;
};

}  // namespace OpenOasis::CommImpl::Numeric