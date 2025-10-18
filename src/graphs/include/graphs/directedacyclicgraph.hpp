#pragma once

#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <ranges>



template <class T>
class DirectedAcyclicGraph {
public:
    typedef unsigned int id;


public:

private:
    std::map<id, T> nodes;
    std::set<std::pair<id, id>> connections;


public:
    DirectedAcyclicGraph() : nodes{}, connections{} {};
    ~DirectedAcyclicGraph() = default;

    id addNode(const T&& item) { return (*(nodes.insert({lowestAveilableId(), item}).first)).first; }
    id addNode(const T& item) { return (*(nodes.insert({lowestAveilableId(), item}).first)).first; }

    template<typename... Args>
    void emplace(Args&&... args) {
        nodes.try_emplace(lowestAveilableId(), std::forward<Args>(args)...);
    }

    void removeNode(const id& nodeId) {
        nodes.erase(nodeId);

        for (auto i = connections.begin(); i != connections.end();) {
            if (i->first == nodeId || i->second == nodeId) {
                i = connections.erase(i);
            }
            else ++i;
        }
    }

    inline void clear() {
        nodes.clear();
        connections.clear();
    }

    id findNode(const T& item) const {
        for (const auto& [nodeId, node] : nodes) {
            if (item == node) return nodeId;
        }

        return (id)-1;
    }
    id findNode(bool (*const filter)(const T&)) const {
        for (const auto& [nodeId, node] : nodes) {
            if (filter(node)) return nodeId;
        }

        return (id)-1;
    }

    inline void connect(const id& from, const id& to) { connections.insert({from, to}); }
    inline void disconnect(const id& from, const id& to) {
        connections.erase(std::find(connections.begin(), connections.end(), std::pair<id, id>{from, to}));
    };

    auto nodeView() { return nodes | std::views::values; }

private:
    id lowestAveilableId() const {
        id lowestId = 0;
        for (const auto& [nodeId, node] : nodes) {
            if (lowestId != nodeId) break;
            lowestId++;
        }

        return lowestId;
    }
};
