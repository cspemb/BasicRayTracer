#pragma once
#include <map>
#include <string_view>

#include "Scene.h"

// Scenes are just hard coded for now - could add a parser if desired
Scene& getScene1();
Scene& getScene2();
Scene& getScene3();

const std::map<std::string_view, Scene>& getScenes();