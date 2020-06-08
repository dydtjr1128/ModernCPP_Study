#pragma once

#include <functional>
#include <unordered_map>

std::unordered_map<std::string, void*> classMap;

template <class F, class... Args>
std::unordered_map<std::string, std::function<Args...>> controllerMap;

#define CONTROLLER NAME CLASS classMap.emplace(NAME, CLASS)

#define REQUEST_MAPPING (URL, FUNC) \
 if(controllerMap.find(URL) != controllerMap.end()){ \
	controllerMap.get(URL)(); \	
}



