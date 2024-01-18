/** ***********************************************************************************
 *    Copyright (C) 2022, The OpenOasis Contributors. Join us in the Oasis!
 *
 *    @File      :  IRegulator.h
 *    @License   :  Apache-2.0
 *
 *    @Desc      :  To provide runtime interactive interface for attribute scheduling.
 *
 ** ***********************************************************************************/
#pragma once
#include "Cores/Inc/ITime.h"
#include <memory>
#include <string>
#include <any>
#include <optional>


namespace OpenOasis
{
namespace AdditionalControl
{
// Todo: abandoned(function implemented by input/output).
class IRegulator
{
public:
    /// @brief Sets the state of the specified variable for the specified ID of
    /// the specified object type.
    ///
    /// @param objType The specified object type inside the component.
    /// @param objID The id of the specified object.
    /// @param varType The id of the specified variable.
    /// @param value The state of specified variable for specified object.
    virtual void SetAttribute(
        const std::string &objType, const std::string &objID,
        const std::string &varType, const std::any &value) = 0;

    /// @brief Gets the state of the specified variable for the specified ID of
    /// the specified object type.
    ///
    /// @param objType The specified object type inside the component.
    /// @param objID The id of the specified object.
    /// @param varType The id of the specified variable.
    ///
    /// @return The states value of specified variable for the specified object.
    virtual std::optional<std::any> GetAttribute(
        const std::string &objType, const std::string &objID,
        const std::string &varType) const = 0;
};

}  // namespace AdditionalControl
}  // namespace OpenOasis