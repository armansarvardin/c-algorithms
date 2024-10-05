import Foundation

struct Item {
    let name: String
    let importance: Int
    let weight: Int
}

class Solution {
    
    let knapsackSize: Int = 6
    
    let items: [Item] = [
        .init(name: "Water", importance: 10, weight: 3),
        .init(name: "Book", importance: 1, weight: 3),
        .init(name: "Food", importance: 9, weight: 2),
        .init(name: "Jacket", importance: 5, weight: 2),
        .init(name: "Camera", importance: 1, weight: 6)
    ]
    
    func knapsackProblem() -> [String] {
        let n = items.count
        var dp = Array(repeating: Array(repeating: 0, count: knapsackSize + 1), count: n + 1)
        
        for i in 1...n {
            let currentItem = items[i - 1]
            for w in 0...knapsackSize {
                if currentItem.weight <= w {
                    dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - currentItem.weight] + currentItem.importance)
                } else {
                    dp[i][w] = dp[i - 1][w]
                }
            }
        }
        
        var selectedItems: [String] = []
        var w = knapsackSize
        for i in stride(from: n, through: 1, by: -1) {
            if dp[i][w] != dp[i - 1][w] {
                selectedItems.append(items[i - 1].name)
                w -= items[i - 1].weight
            }
        }
        
        return selectedItems
    }
}

let solution = Solution()
let result = solution.knapsackProblem()
print("Items selected: \(result)")
