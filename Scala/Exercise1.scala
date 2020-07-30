// Write a function to get the nth Fibonacci number, using a local
// tail-recursive function

object Exercise1 {
  def Fibonacci(n: Int): Int = {
    def go(n: Int, a1: Int, a2: Int): Int = {
      if (n <= 2) a2
      else go(n-1, a2, a1+a2)
    }
    go(n, 1, 1)
  }

  def main(args: Array[String]): Unit = {
    println(s"The 8th Fibonacci number is ${Fibonacci(8)}")
    println(s"The 5th Fibonacci number is ${Fibonacci(5)}")
    println(s"The 3th Fibonacci number is ${Fibonacci(3)}")
    println(s"The 10th Fibonacci number is ${Fibonacci(10)}")
  }
}

