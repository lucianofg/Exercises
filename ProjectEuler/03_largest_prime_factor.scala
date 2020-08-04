/* What is the largest prime factor of 600851475143 */
/* Taken from https://projecteuler.net/problem=3 */

object LargestPrimeFactor {
  @annotation.tailrec
  def largest_prime_factor(quotient: BigInt, number: BigInt, largest: BigInt): BigInt = {
    if (quotient == 1 ||  number > quotient) {
      largest
    } else if (quotient % number == 0) {
      if (number > largest) {
        largest_prime_factor(quotient / number, 2, number)
      } else {
        largest_prime_factor(quotient / number, 2, largest)
      }
    } else {
      largest_prime_factor(quotient, number + 1, largest)
    }
  }

  def main(args: Array[String]): Unit = {
    var number = BigInt("600851475143")
    //    var result = largest_prime_factor(number, 2, 0);
    var result = largest_prime_factor(123123123, 2, 0);
    println(s"Resultado: $result")
  }
}
