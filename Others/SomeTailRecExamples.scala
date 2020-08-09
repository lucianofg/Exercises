object SomeTailRecExamples {
  @annotation.tailrec
  def gdc(x: Int, y: Int): Int = {
    if (y == 0) x
    else gdc(y, x % y);
  }

  def fat(num: Int): Int = {
    @annotation.tailrec
    def go(number: Int, result: Int): Int = {
      if (number <= 1) result
      else go(number - 1, result * number)
    }
    go(num, 1)
  }

//  This will get a warning in Scala >= 2.8
//  @annotation.tailrec
//  def fat(number: Int): Int = {
//    if (number <= 1) 1
//    else number * fat(number - 1)
//  }

  def main(args: Array[String]): Unit = {
    println(s"GCD(180, 48) is ${gdc(48, 180)}");
    println(s"fat(5) is ${fat(5)}");
    println(s"fat(6) is ${fat(6)}");
    println(s"fat(10) is ${fat(10)}");
  }
}
