/** ***********************************************************************************
 *    Copyright (C) 2023, The OpenOasis Contributors. Join us in the Oasis!
 *
 *    @File      :  Operator.h
 *    @License   :  Apache-2.0
 *
 *    @Desc      :  Abstract operator to provide unified discretization interfaces.
 *
 ** ***********************************************************************************/
#pragma once
#include "ScalarField.h"
#include "VectorField.h"
#include "TensorField.h"
#include "Matrix.h"
#include <vector>
#include <memory>
#include <tuple>


namespace OpenOasis::CommImpl::Numeric
{
class Operator
{
public:
    virtual std::tuple<Matrix<double>, std::vector<double>>
    Discretize(const ScalarField<double> &field) const = 0;

    virtual std::tuple<Matrix<double>, std::vector<double>>
    Discretize(const VectorField<double> &field) const = 0;

    virtual std::tuple<Matrix<double>, std::vector<double>>
    Discretize(const TensorField<double> &field) const = 0;
};

}  // namespace OpenOasis::CommImpl::Numeric
