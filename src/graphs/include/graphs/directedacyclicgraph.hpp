#pragma once

#include <set>
#include <map>
#include <utility>
#include <algorithm>



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

    void removeNode(const id& nodeId) {
        nodes.erase(nodeId);

        for (auto i = connections.begin(); i != connections.end();) {
            if (i->first == nodeId || i->second == nodeId) {
                i = connections.erase(i);
            }
            else ++i;
        }
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
