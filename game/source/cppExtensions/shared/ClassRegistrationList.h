#pragma once

#include "IRegisterClass.h"

#include <vector>

// Stores deferred Godot class registrations so feature code can opt in without touching module init.
class ClassRegistrationList
{
private:
    // Owns the registrar helpers created by static registration macros.
    std::vector<IRegisterClass *> m_classList;

    ClassRegistrationList();

public:
    static ClassRegistrationList *Instance();

    // Queues another registrar for scene-level module initialization.
    void Add(IRegisterClass *c);
    // Replays deferred registrations once Godot reaches the correct init level.
    void RegisterClasses();
    // Releases registrar helpers when the list is explicitly torn down.
    void Clear();
};
