#pragma once

#ifndef GDEXAMPLE_REGISTER_TYPES_H
#define GDEXAMPLE_REGISTER_TYPES_H

#pragma warning(push)
#pragma warning(disable : 4244)
#include <class_db.hpp>
#pragma warning(pop)

using namespace godot;

// Registers the Godot-facing module boundary and any deferred helper registrations.
void initialize_example_module(ModuleInitializationLevel p_level);
// Reserved for Godot shutdown hooks owned by this extension boundary.
void uninitialize_example_module(ModuleInitializationLevel p_level);

#endif // GDEXAMPLE_REGISTER_TYPES_H
