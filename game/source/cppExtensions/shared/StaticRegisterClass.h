#pragma once

#include "ClassRegistrationList.h"

#include <class_db.hpp>

template<class TYPE>
// Registers one Godot class through the shared deferred-registration list.
class StaticRegisterClass : public IRegisterClass
{
public:
    StaticRegisterClass()
    {
        // Static instances enqueue themselves so feature code stays separate from module init.
        ClassRegistrationList::Instance()->Add(static_cast<IRegisterClass *>(this));
    }

    virtual void Register()
    {
        // Godot registration is delayed until the extension reaches scene initialization.
        godot::ClassDB::register_class<TYPE>();
    }
};
