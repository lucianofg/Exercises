// Implement isSorted, which checks whether an Array[A]
// is sorted according to a given comparison function

object Exercise2 {
  def isSorted[A](array: Array[A], cmp: (A, A) => Boolean): Boolean = {
    def go(i: Int): Boolean = {
      if (array.length > i + 1) {
        if (cmp(array(i), array(i + 1))) go(i + 1)
        else false
      } else true
    }

    go(0)
  }

  def main(args: Array[String]): Unit = {
    var arr = Array(1, 2, 5, 5, 10)
    var arr2 = Array(2, 1, 5, 5, 10)
    var issortedarr = isSorted(arr, (x: Int, y: Int) => x <= y)
    var issortedarr2 = isSorted(arr2, (x: Int, y: Int) => x <= y)
    println(s"Sorted array: $issortedarr")
    println(s"Sorted array: $issortedarr2")
  }
}
