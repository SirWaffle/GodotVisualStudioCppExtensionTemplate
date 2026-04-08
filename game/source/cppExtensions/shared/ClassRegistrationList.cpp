#include "ClassRegistrationList.h"

ClassRegistrationList::ClassRegistrationList()
{
}

ClassRegistrationList *ClassRegistrationList::Instance()
{
    // Keeps deferred registration state local to the extension bootstrap boundary.
    static ClassRegistrationList m_singleton;
    return &m_singleton;
}

void ClassRegistrationList::Add(IRegisterClass *c)
{
    m_classList.push_back(c);
}

void ClassRegistrationList::RegisterClasses()
{
    // Replay queued helpers once Godot is ready to accept class registrations.
    for (IRegisterClass *reg : m_classList)
    {
        reg->Register();
    }
}

void ClassRegistrationList::Clear()
{
    // The list owns the registrar helpers that were allocated during static setup.
    for (IRegisterClass *reg : m_classList)
    {
        delete reg;
    }

    m_classList.clear();
}
