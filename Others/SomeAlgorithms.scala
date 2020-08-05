object SomeAlgorithms {
  // Heron algorithm for square root
  def square_root(number: Float): Float = {
    def improve(guess: Float): Float =
      (guess + (number / guess)) / 2

    def is_good_enough(guess: Float): Boolean =
      (guess * guess - number).abs < 0.001

    def try_guess(guess: Float): Float =
      if (is_good_enough(guess)) guess
      else try_guess(improve(guess))

    try_guess(1)
  }

  def main(args: Array[String]): Unit  = {
    println(s"Square of 2: ${square_root(2)}")
    println(s"Square of 4: ${square_root(4)}")
    println(s"Square of 10: ${square_root(10)}")
    println(s"Square of 144: ${square_root(144)}")
  }
}
