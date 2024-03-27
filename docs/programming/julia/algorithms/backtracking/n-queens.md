# Problem n królowych

## [Opis problemu](../../../../algorithms/backtracking/n-queens.md)

## Implementacja

```julia linenums="1"
function checkNewPosition(x, y, positions)
    for i in 1:x
        if positions[i] == y || y - positions[i] == x - i
            return false
        end
    end

    return true
end

function findSolution(n, queenId, positions)
    if queenId == n + 1
        return true
    end

    for i in 1:n
        if !checkNewPosition(queenId, i, positions)
            continue
        end

        positions[queenId] = i

        if findSolution(n, queenId + 1, positions)
            return true
        end
    end

    return false
end

function printCheckboard(n, positions)
    board = zeros(Int, n, n)

    for i in 1:n
        board[positions[i], i] = 1
    end

    display(board)
end

n = 5
positions = zeros(Int, n)

result = findSolution(n, 1, positions)

if result
    printCheckboard(n, positions)
end
```
