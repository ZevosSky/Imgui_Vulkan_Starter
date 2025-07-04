//
// Created by thego on 6/30/2025.
//



#include "SystemManager.h"




template <class T> T *SystemManager::get() const {
    auto it = _lookup.find(typeid(T));
    return (it == _lookup.end()) ? nullptr : static_cast<T*>(it->second);
}

void SystemManager::initAll() {
    for (auto &system : _systems) { system->init();}
}

void SystemManager::updateAll() {
    for (auto &system : _systems) {system->update();}
}

void SystemManager::shutdownAll() {
    for (auto &system : _systems) {system->shutdown();}

    _systems.clear();
    _lookup.clear();
}



