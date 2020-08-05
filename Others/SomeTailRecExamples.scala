object SomeTailRecExamples {
  @annotation.tailrec
  def gdc(x: Int, y: Int): Int = {
    if (y == 0) x
    else gdc(y, x % y);
  }

  @annotation.tailrec
  def fat(number: Int, result: Int): Int = {
    if (number <= 1) result
    else fat(number - 1, result * number)
  }

//  This will get a warning in Scala >= 2.8
//  @annotation.tailrec
//  def fat(number: Int): Int = {
//    if (number <= 1) 1
//    else number * fat(number - 1)
//  }

  def main(args: Array[String]): Unit = {
    println(s"GCD(180, 48) is ${gdc(48, 180)}");
    println(s"fat(5) is ${fat(5, 1)}");
    println(s"fat(6) is ${fat(6, 1)}");
    println(s"fat(7) is ${fat(7, 1)}");
  }
}
