// x11_wrapper.h
#pragma once

// Rename conflicting X11 Font type before including headers
#define Font X11_Font
#include <X11/Xlib.h>
#include <X11/Xatom.h>
#undef Font