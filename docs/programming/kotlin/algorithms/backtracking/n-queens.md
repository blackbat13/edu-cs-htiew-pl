# Problem n królowych

## [:link: Opis problemu](../../../../algorithms/backtracking/n-queens.md)

## Implementacja

```kotlin linenums="1"
fun findSolution(n: Int, queenId: Int, positions: Array<Int>): Boolean {
    if (queenId == n) {
        return true
    }

    for (i in 0 until n) {
        if (!checkNewPosition(queenId, i, positions)) {
            continue
        }

        positions[queenId] = i

        if (findSolution(n, queenId + 1, positions)) {
            return true
        }
    }

    return false
}

fun checkNewPosition(x: Int, y: Int, positions: Array<Int>): Boolean {
    for (i in 0 until x) {
        if (positions[i] == y) {
            return false
        }

        if ((y - positions[i]) == (x - i) or (y - positions[i]) == (i - x)) {
            return false
        }
    }

    return true
}

fun printCheckboard(n: Int, positions: Array<Int>) {
    val board = Array(n) { IntArray(n) }

    for (i in 0 until n) {
        board[positions[i]][i] = 1
    }

    for (i in 0 until n) {
        println(board[i].contentToString())
    }
}

fun main() {
  val n = 5
  val positions = Array(n) {0}

  val result = findSolution(n, 0, positions)

  if (result) {
      println("Pozycje:")
      println(positions.contentToString())
      println("Szachownica:")
      printCheckboard(n, positions)
  } else {
      println("Brak rozwiazania")
  }
}
```
