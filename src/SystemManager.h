//
// Created by thego on 6/30/2025.
//

#include "stdafx.h"
#include <typeindex>



#ifndef VULKAN_IMGUI_STARTER_SYSTEMMANAGER_H
#define VULKAN_IMGUI_STARTER_SYSTEMMANAGER_H

class System {

  public:
    virtual ~System() = default;

    virtual void init() {}
    virtual void update() {}
    virtual void shutdown() {}



};


class SystemManager {

  public:
    // Add a system (exactly one of each T).  Perfect-forwards constructor args.
    template<class T, class... Args>
    T& addSystem(Args&&... args) {
        static_assert(std::is_base_of_v<System, T>,
                      "T must derive from System");

        // Prevent duplicates
        if (auto* existing = get<T>())
            return *existing;

        // Create a new system, store it in the vector, and return a reference to it.
        auto  owned = std::make_unique<T>(std::forward<Args>(args)...);
        T*    raw   = owned.get();

        // Ensure the system is initialized
        _lookup[typeid(T)] = raw;
        _systems.emplace_back(std::move(owned));
        return *raw;
    }

    template<class T>
    T* get() const;

    void initAll();

    void updateAll();

    void shutdownAll();



  private:
    std::vector<std::unique_ptr<System>> _systems;        // ownership
    std::unordered_map<std::type_index, System*> _lookup; // O(1) by type
};

#endif // VULKAN_IMGUI_STARTER_SYSTEMMANAGER_H
