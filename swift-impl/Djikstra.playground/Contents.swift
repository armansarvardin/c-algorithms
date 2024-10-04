import Foundation

var graph: [String : [String : Int]] = [:]

graph["start"] = [:]
graph["start"]?["a"] = 6
graph["start"]?["b"] = 2

graph["a"] = [:]
graph["a"]?["fin"] = 1

graph["b"] = [:]
graph["b"]?["a"] = 3
graph["b"]?["fin"] = 5

graph["fin"] = [:]


let infinity = Int.max
var costs: [String : Int] = [:]

costs["a"] = 6
costs["b"] = 2
costs["fin"] = infinity


var parents: [String : String] = [:]

parents["a"] = "start"
parents["b"] = "start"
parents["fin"] = nil

var processed: Set<String> = []

@MainActor
func findLowestCostNode(costs: [String: Int]) -> String? {
    var lowestCost = infinity
    var lowestCostNode: String?
    
    for node in costs {
        if let cost = costs[node.key] {
            if cost < lowestCost && !processed.contains(node.key) {
                lowestCost = cost
                lowestCostNode = node.key
            }
        }
        
    }
    return lowestCostNode
}

@MainActor
func djiksstra() {
    var node = findLowestCostNode(costs: costs)
    
    while node != nil {
        let cost = costs[node!]!
        let neighbors = graph[node!]!
        
        for neighbor in neighbors.keys {
            var newCost = cost + neighbors[neighbor]!
            
            if newCost < costs[neighbor]! {
                costs[neighbor] = newCost
                parents[neighbor] = node!
            }
        }
        
        processed.insert(node!)
        node = findLowestCostNode(costs: costs)
    }
    
    print(costs["fin"])
    print(parents)
}

djiksstra()

