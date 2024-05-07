/** ***********************************************************************************
 *    Copyright (C) 2024, The OpenOasis Contributors. Join us in the Oasis!
 *
 *    @File      :  FvmOperator.h
 *    @License   :  Apache-2.0
 *
 ** ***********************************************************************************/
#pragma once
#include "Models/CommImp/Numeric/Operator.h"
#include "Models/Utils/RegisterFactory.h"


namespace OpenOasis::CommImp::Numeric::FVM
{
using namespace OpenOasis::Utils;

/// @brief Register FVM operator factory.
class RegisterFactoryOperator;
RegisterFactory(Operator);

}  // namespace OpenOasis::CommImp::Numeric::FVM