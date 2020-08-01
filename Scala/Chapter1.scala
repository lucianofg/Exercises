object Chapter1 {
  // Exercise 1:
  // Write a function to get the nth Fibonacci number, using a local
  // tail-recursive function
  def Fibonacci(n: Int): Int = {
    def go(n: Int, a1: Int, a2: Int): Int = {
      if (n <= 2) a2
      else go(n-1, a2, a1+a2)
    }
    go(n, 1, 1)
  }

  // Exercise 2:
  // Implement isSorted, which checks whether an Array[A]
  // is sorted according to a given comparison function

  def isSorted[A](array: Array[A], cmp: (A, A) => Boolean): Boolean = {
    def go(i: Int): Boolean = {
      if (array.length > i + 1) {
        if (cmp(array(i), array(i + 1))) go(i + 1)
        else false
      } else true
    }
    go(0)
  }

  // Exercise 3:
  // Implement partial1 and write down a concrete usage of it. There is
  // only one possible implementation that compiles. We don't have any
  // concrete types here, so we can only stick things together using
  // the local 'rules of the universe' established by the type
  // signature. The style of reasoning required here is very common in
  // functional programming - we are simply manipulating symbols in a
  // very abstract way, similar to how we would reason when solving an
  // algebraic equation

  def partiall[A, B, C](a: A, f: (A, B) => C): B => C =
    (b: B) => f(a, b)

  // Exercise 4:
  // Let's look at another example, currying, which converts a function
  // of N arguments into a function of one argument that returns
  // another function as its result.

  def curry[A, B, C](f: (A, B) => C): A => (B => C) = {
    // This is the same thing as:
    //(a: A) => (b: B) => f(a, b)
    a => b => f(a, b)
  }

  // Exercise 5:
  // Implement uncurry, which reverses the transformation of curry.
  // Note that since => associates to the right, A => (B => C) can be
  // written as A => B => C

  def uncurry[A, B, C](f: A => B => C): (A, B) => C = {
    // This is the same thing as:
    //(a: A, b: B) => f(a)(b)
    (a, b) => f(a)(b)
  }

  // Exercise 6
  // Implement the higher-order function that composes two functions 

  def compose[A, B, C](f: B => C, g: A => B): A => C = {
    (a: A) => f(g(a))
  }

  def main(args: Array[String]): Unit = {
    println("Testing the Fibonacci function from Exercise 1")
    println(s"The 3th Fibonacci number is ${Fibonacci(3)}")
    println(s"The 5th Fibonacci number is ${Fibonacci(5)}")
    println(s"The 8th Fibonacci number is ${Fibonacci(8)}")
    println(s"The 10th Fibonacci number is ${Fibonacci(10)}")
    println()

    println("Testing the isSorted Function from Exercise 2")
    var arr  = Array(1, 2, 5, 5, 10)
    var arr2 = Array(2, 1, 5, 5, 10)
    var issortedarr  = isSorted(arr,  (x: Int, y: Int) => x <= y)
    var issortedarr2 = isSorted(arr2, (x: Int, y: Int) => x <= y)
    println(s"Sorted array: $issortedarr")
    println(s"Sorted array: $issortedarr2")
  }
}

