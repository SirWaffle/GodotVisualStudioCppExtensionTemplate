#pragma once

#include "ClassRegistrationList.h"
#include "IRegisterClass.h"
#include "StaticRegisterClass.h"

// Declares a static registrar so helper-owned Godot classes stay out of module bootstrap code.
#define GODOT_REGISTER_CLASS(className) static StaticRegisterClass<className> gs_regClass##className;
