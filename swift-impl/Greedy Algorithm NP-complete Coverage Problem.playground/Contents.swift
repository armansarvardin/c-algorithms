import UIKit

// setup

var statesNeeded: Set<String> = ["mt", "wa", "or", "id", "nv", "ut", "ca", "az"]

var stations: [String: Set<String>] = [:]

stations["kone"] = ["id", "nv", "ut"]
stations["ktwo"] = ["wa", "id", "mt"]
stations["kthree"] = ["or", "nv", "ca"]
stations["kfour"] = ["nv", "ut"]
stations["kfive"] = ["ca", "az"]

var finalStations: Set<String> = []

while !statesNeeded.isEmpty {
    
    var bestStation: String?
    var statesCovered: Set<String> = []

    for (station, statesForStation) in stations {
        var covered: Set<String> = []
        covered = statesNeeded.intersection(statesForStation)
        
        if covered.count > statesCovered.count {
            bestStation = station
            statesCovered = covered
        }
    }
    
    if let bestStation = bestStation {
        statesNeeded.subtract(statesCovered)
        finalStations.insert(bestStation)
    }
}

print(finalStations)


