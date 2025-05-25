#ifndef INCLUDEAGGREGATOR_H
#define INCLUDEAGGREGATOR_H

#include "Enemy.h"
#include "Ent.h"
#include "Entity.h"
#include "Eyesore.h"
#include "Icepicker.h"
#include "IcepickerPhase1.h"
#include "IcepickerPhase2.h"
#include "Lifestealer.h"
#include "Player.h"
#include "StatusEffect.h"
#include "StatusEffectManager.h"

// interfejs

// Windows
#if defined(_WIN32) || defined(_WIN64)
#include <conio.h>
#endif

// System Unixowy
#if defined(__linux__) || defined(__APPLE__)
#include <ncurses.h>
#endif

#endif