<?php

/**
 * Implementaion of Stack Data Structure in PHP
 */
interface ds
{
  public function push($data);
  public function pop();
  public function isEmpty();
  public function top();

}

class Stack implements ds{

  //properties
  private $top = -1;
  private $space = [];
  //methods
  public function push($data)
  {
    $this->top = $this->top + 1;
    $this->space[$this->top] = $data;

    return;

  }

  public function pop()
  {
    $this->top = $this->top - 1;
  }

  public function isEmpty()
  {
    if($this->top == -1){
      return true;
    }else{
      return false;
    }
  }

  public function top()
  {
    return $this->space[$this->top];
  }

}
