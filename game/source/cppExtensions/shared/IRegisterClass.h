#pragma once

// Small boundary interface for deferred Godot class registration helpers.
class IRegisterClass
{
public:
    virtual ~IRegisterClass() = default;
    virtual void Register() = 0;
};
