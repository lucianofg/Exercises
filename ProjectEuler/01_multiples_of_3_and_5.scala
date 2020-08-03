// Find the sum of all the multiples of 3 or 5 below 1000
// Taken from https://projecteuler.net/problem=1

object MultiplesOf3And5 {
  def calc (max: Int, sum: Int): Int = {
    if (max == 1) sum
    else {
      if (max % 3 == 0 || max % 5 == 0) calc(max - 1, sum + max)
      else calc(max - 1, sum)
    }
  }

  def main(args: Array[String]): Unit = {
    var result = calc(1000, 0)
    println(s"Result: $result")
  }
}
