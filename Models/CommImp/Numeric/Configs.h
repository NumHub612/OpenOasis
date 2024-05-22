/** ***********************************************************************************
 *    Copyright (C) 2024, The OpenOasis Contributors. Join us in the Oasis!
 *
 *    @File      :  Configs.h
 *    @License   :  Apache-2.0
 *
 *    @Desc      :  General configuration structures.
 *
 ** ***********************************************************************************/
#pragma once
#include "Models/Utils/CommConstants.h"
#include "Field.h"
#include <string>
#include <variant>
#include <optional>


namespace OpenOasis::CommImp::Numeric
{
using Utils::real;


struct Configuration
{
    std::string key;

    std::variant<std::string, real, int, bool> value;
};


struct DataField
{
    std::string name;

    std::optional<ScalarFieldFp> sField;
    std::optional<VectorFieldFp> vField;
    std::optional<TensorFieldFp> tField;
};

}  // namespace OpenOasis::CommImp::Numeric