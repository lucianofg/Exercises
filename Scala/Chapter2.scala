sealed trait List[+A]
case object Nil extends List[Nothing]
case class Cons[+A](head: A, tail: List[A]) extends List[A]

object List {
  def sum(ints: List[Int]): Int = ints match {
    case Nil => 0
    case Cons(x,xs) => x + sum(xs)
  }
  def product(ds: List[Double]): Double = ds match {
    case Nil => 1.0
    case Cons(0.0, _) => 0.0
    case Cons(x,xs) => x * product(xs)
  }
  def apply[A](as: A*): List[A] =
    if (as.isEmpty) Nil
    else Cons(as.head, apply(as.tail: _*))

}

object Teste {
  // Exercise 1: What will the result of the following match
  // expression be? A: x + y = 3
  def main(args: Array[String]): Unit = {
    var result = List(1, 2, 3, 4, 5) match {
      case Cons(x, Cons(2, Cons(4, _))) => x
      case Nil => 42
      case Cons(x, Cons(y, Cons(3, Cons(4, _)))) => x+y
      case Cons(h, t) => h 
      case _ => 101

    }
    println(s"Result: $result")
  }

  // Exercise 2: Implement the function tail for "removing" the 
  // first element of a List.
  def tail[A](list: List[A]): List[A] = list match {
      case Nil => list
      case Cons(_, l) => l
    }

  // Exercise 3: Generalize tail to the function drop, which removes
  // the first n elements from a list
  def drop[A](list: List[A], n: Int): List[A] =
    if (n == 0) list
    else list match {
      case Nil => list
      case Cons(_, l) => drop(l, n - 1)
    }

  // Exercise 4: Implement dropWhile which removes elements from the
  // List prefix as long as they match a predicate 
  def dropWhile[A](list: List[A])(predicate: A => Boolean): List[A] =
    list match {
      case Cons(x, y) if (predicate(x)) => y
      case _ => list
    }
  
  // Exercise 5: Using the same idea, implement the function setHead
  // for replacing the first element of a List with a different value
  def setHead[A](list: List[A], element: A): List[A] = list match {
      case Cons(x, y) => Cons(element, y)
      case Nil => List(element)
    }

  // Exercise 6: Implement a function init which returns a List
  // consisting of all but the last element of a List
  
  def init[A](list: List[A]): List[A] = {

  }
  
  // Why can't this function be implemented in constant time like
  // tail?
}
